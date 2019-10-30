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
#ifndef GD32VF103_MTIMER_H
#define GD32VF103_MTIMER_H

#include "gd32vf103.h"

#define MTIMER_BASE _AC(0xD1000000,UL)  /*!< MTIMER base address */

/* register definitions */
#define MTIMER_MTIME        _AC(0x000,UL)
#define MTIMER_MTIME_LO     _AC(0x000,UL)
#define MTIMER_MTIME_HI     _AC(0x004,UL)
#define MTIMER_MTIMECMP     _AC(0x008,UL)
#define MTIMER_MTIMECMP_LO  _AC(0x008,UL)
#define MTIMER_MTIMECMP_HO  _AC(0x00c,UL)
#define MTIMER_MSTOP        _AC(0xff8,UL)
#define MTIMER_MSIP         _AC(0xffc,UL)

/* mstop bits */
#define MTIMER_MSTOP_TIMESTOP _BIT(0,U)

/* msip bits */
#define MTIMER_MSIP_MSIP      _BIT(0,U)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_mtimer {
	volatile uint32_t mtime_lo;
	volatile uint32_t mtime_hi;
	volatile uint32_t mtimecmp_lo;
	volatile uint32_t mtimecmp_hi;
	uint32_t reserved1[1018];
	volatile uint32_t mstop;
	volatile uint32_t msip;
};

static struct gd32vf103_mtimer *const MTIMER = (struct gd32vf103_mtimer *)MTIMER_BASE;

#endif
#endif
