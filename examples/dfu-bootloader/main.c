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
#include "gd32vf103/rcu.h"

#include "lib/mtimer.h"
#include "lib/eclic.h"
#include "lib/rcu.h"
#include "lib/gpio.h"

#include "usbfs.h"
#include "dfu.h"
#include "flash.h"

#ifndef NDEBUG
#include <stdio.h>
#include "lib/stdio-uart0.h"
#endif

int main(void)
{
	/* initialize system clock */
	rcu_sysclk_init();

	/* initialize eclic */
	eclic_init();
	/* enable global interrupts */
	eclic_global_interrupt_enable();

#ifdef NDEBUG
	RCU->APB2EN |= RCU_APB2EN_PCEN;
#else
	uart0_init(CORECLOCK, 115200, 2);
	printf("\n*** DFU ***\n");

	RCU->APB2EN |= RCU_APB2EN_PAEN;
#endif
	gpio_pin_clear(LED);
	gpio_pin_config(LED, GPIO_MODE_OD_2MHZ);

	dfu_init();
	usbfs_init();

	while (1) {
#ifdef NDEBUG
		wait_for_interrupt();
#else
		char c = getchar();

		switch (c) {
		case 't':
			printf("mtime = 0x%lx%08lx\n", MTIMER->mtime_hi, MTIMER->mtime_lo);
			continue;
		case 'i':
			printf("ECLIC->clicint[%u].ie = %u\n", USBFS_IRQn,
					ECLIC->clicint[USBFS_IRQn].ie);
			printf("ECLIC->clicint[%u].ip = %u\n", USBFS_IRQn,
					ECLIC->clicint[USBFS_IRQn].ip);
			printf("GOTGCS   = 0x%08lx\n", USBFS->GOTGCS);
			printf("GOTGINTF = 0x%08lx\n", USBFS->GOTGINTF);
			printf("GAHBCS   = 0x%08lx\n", USBFS->GAHBCS);
			printf("GUSBCS   = 0x%08lx\n", USBFS->GUSBCS);
			printf("GRSTCTL  = 0x%08lx\n", USBFS->GRSTCTL);
			printf("GINTF    = 0x%08lx\n", USBFS->GINTF);
			printf("GINTEN   = 0x%08lx\n", USBFS->GINTEN);
			printf("GRSTATR  = 0x%08lx\n", USBFS->GRSTATR);
			printf("GRFLEN   = 0x%08lx\n", USBFS->GRFLEN);
			printf("GCCFG    = 0x%08lx\n", USBFS->GCCFG);
			printf("CID      = 0x%08lx\n", USBFS->CID);
			printf("DCFG     = 0x%08lx\n", USBFS->DCFG);
			printf("DCTL     = 0x%08lx\n", USBFS->DCTL);
			printf("DSTAT    = 0x%08lx\n", USBFS->DSTAT);
			continue;
		}
#endif
	}
}
