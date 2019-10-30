/*
 * Copyright (c) 2019, Emil Renner Berthing
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
#include <stdint.h>
#include <stddef.h>

#include "gd32vf103/fmc.h"
#include "lib/gpio.h"
#include "flash.h"

#ifdef NDEBUG
#define debug(...)
#else
#include <stdio.h>
#define debug(...) printf(__VA_ARGS__)
#endif

__attribute__((noclone))
__attribute__((noinline))
__attribute__((section(".ramtext.flash__page")))
static int flash__page(uint32_t addr, const uint32_t data[PAGE_SIZE/4])
{
	/* erase page */
	FMC->CTL = (FMC->CTL & ~0x7U) | FMC_CTL_PER;
	FMC->ADDR = addr;
	FMC->CTL |= FMC_CTL_START;
	while (FMC->STAT & FMC_STAT_BUSY)
		/* wait */;
	if (FMC->STAT != FMC_STAT_ENDF)
		return -1;
	FMC->STAT = FMC_STAT_ENDF;

	/* write data */
	for (unsigned int i = 0; i < PAGE_SIZE/4; i++, addr += 4) {
		uint32_t word = data[i];

		if (word == 0xffffffffU)
			continue;

		FMC->CTL = (FMC->CTL & ~0x7U) | FMC_CTL_PG;
		*(volatile uint32_t *)addr = word;
		while (FMC->STAT & FMC_STAT_BUSY)
			/* wait */;
		if (FMC->STAT != FMC_STAT_ENDF)
			return -2;
		FMC->STAT = FMC_STAT_ENDF;
	}

	return 0;
}

int flash_page(uint32_t addr, const uint32_t data[PAGE_SIZE/4])
{
	int ret;

	debug("  flashing at 0x%08lx\n", addr);

	while (FMC->STAT & FMC_STAT_BUSY)
		/* wait */;

	/* clear error bits */
	FMC->STAT =
		FMC_STAT_ENDF |
		FMC_STAT_WPERR |
		FMC_STAT_PGERR;

	/* unlock flash */
	debug("FMC->CTL = 0x%08lx\n", FMC->CTL);
	if (FMC->CTL & FMC_CTL_LK) {
		FMC->KEY = FMC_KEY_UNLOCK0;
		FMC->KEY = FMC_KEY_UNLOCK1;
		debug("FMC->CTL = 0x%08lx\n", FMC->CTL);
		if (FMC->CTL & FMC_CTL_LK)
			return -1;
	}

	gpio_pin_set(LED);
	ret = flash__page(addr, data);
	gpio_pin_clear(LED);

	/* lock flash again */
	FMC->CTL = FMC_CTL_LK;
	return ret;
}
