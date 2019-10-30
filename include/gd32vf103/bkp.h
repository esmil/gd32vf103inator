/*
 * Copyright (c) 2019, GigaDevice Semiconductor Inc.
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
#ifndef GD32VF103_BKP_H
#define GD32VF103_BKP_H

#include "gd32vf103.h"

#define BKP_BASE _AC(0x40006C00,UL)  /*!< BKP base address */

/* register definitions */
#define BKP_DATA0   _AC(0x04,UL)  /*!< BKP data register 0 */
#define BKP_DATA1   _AC(0x08,UL)  /*!< BKP data register 1 */
#define BKP_DATA2   _AC(0x0C,UL)  /*!< BKP data register 2 */
#define BKP_DATA3   _AC(0x10,UL)  /*!< BKP data register 3 */
#define BKP_DATA4   _AC(0x14,UL)  /*!< BKP data register 4 */
#define BKP_DATA5   _AC(0x18,UL)  /*!< BKP data register 5 */
#define BKP_DATA6   _AC(0x1C,UL)  /*!< BKP data register 6 */
#define BKP_DATA7   _AC(0x20,UL)  /*!< BKP data register 7 */
#define BKP_DATA8   _AC(0x24,UL)  /*!< BKP data register 8 */
#define BKP_DATA9   _AC(0x28,UL)  /*!< BKP data register 9 */
#define BKP_OCTL    _AC(0x2C,UL)  /*!< RTC signal output control register */
#define BKP_TPCTL   _AC(0x30,UL)  /*!< tamper pin control register */
#define BKP_TPCS    _AC(0x34,UL)  /*!< tamper control and status register */
#define BKP_DATA10  _AC(0x40,UL)  /*!< BKP data register 10 */
#define BKP_DATA11  _AC(0x44,UL)  /*!< BKP data register 11 */
#define BKP_DATA12  _AC(0x48,UL)  /*!< BKP data register 12 */
#define BKP_DATA13  _AC(0x4C,UL)  /*!< BKP data register 13 */
#define BKP_DATA14  _AC(0x50,UL)  /*!< BKP data register 14 */
#define BKP_DATA15  _AC(0x54,UL)  /*!< BKP data register 15 */
#define BKP_DATA16  _AC(0x58,UL)  /*!< BKP data register 16 */
#define BKP_DATA17  _AC(0x5C,UL)  /*!< BKP data register 17 */
#define BKP_DATA18  _AC(0x60,UL)  /*!< BKP data register 18 */
#define BKP_DATA19  _AC(0x64,UL)  /*!< BKP data register 19 */
#define BKP_DATA20  _AC(0x68,UL)  /*!< BKP data register 20 */
#define BKP_DATA21  _AC(0x6C,UL)  /*!< BKP data register 21 */
#define BKP_DATA22  _AC(0x70,UL)  /*!< BKP data register 22 */
#define BKP_DATA23  _AC(0x74,UL)  /*!< BKP data register 23 */
#define BKP_DATA24  _AC(0x78,UL)  /*!< BKP data register 24 */
#define BKP_DATA25  _AC(0x7C,UL)  /*!< BKP data register 25 */
#define BKP_DATA26  _AC(0x80,UL)  /*!< BKP data register 26 */
#define BKP_DATA27  _AC(0x84,UL)  /*!< BKP data register 27 */
#define BKP_DATA28  _AC(0x88,UL)  /*!< BKP data register 28 */
#define BKP_DATA29  _AC(0x8C,UL)  /*!< BKP data register 29 */
#define BKP_DATA30  _AC(0x90,UL)  /*!< BKP data register 30 */
#define BKP_DATA31  _AC(0x94,UL)  /*!< BKP data register 31 */
#define BKP_DATA32  _AC(0x98,UL)  /*!< BKP data register 32 */
#define BKP_DATA33  _AC(0x9C,UL)  /*!< BKP data register 33 */
#define BKP_DATA34  _AC(0xA0,UL)  /*!< BKP data register 34 */
#define BKP_DATA35  _AC(0xA4,UL)  /*!< BKP data register 35 */
#define BKP_DATA36  _AC(0xA8,UL)  /*!< BKP data register 36 */
#define BKP_DATA37  _AC(0xAC,UL)  /*!< BKP data register 37 */
#define BKP_DATA38  _AC(0xB0,UL)  /*!< BKP data register 38 */
#define BKP_DATA39  _AC(0xB4,UL)  /*!< BKP data register 39 */
#define BKP_DATA40  _AC(0xB8,UL)  /*!< BKP data register 40 */
#define BKP_DATA41  _AC(0xBC,UL)  /*!< BKP data register 41 */

/* BKP_DATA */
#define BKP_DATA_Pos       0
#define BKP_DATA_Msk       _AC(0x0000ffff,U)  /*!< backup data */
#define BKP_DATA(x)        ((x) << BKP_DATA_Pos)

/* BKP_OCTL */
#define BKP_OCTL_ROSEL     _BIT(9,U)          /*!< RTC output selection */
#define BKP_OCTL_ASOEN     _BIT(8,U)          /*!< RTC alarm or second signal output enable */
#define BKP_OCTL_COEN      _BIT(7,U)          /*!< RTC clock calibration output enable */
#define BKP_OCTL_RCCV_Pos  0
#define BKP_OCTL_RCCV_Msk  _AC(0x0000007f,U)  /*!< RTC clock calibration value */
#define BKP_OCTL_RCCV(x)   ((x) << BKP_OCTL_RCCV_Pos)

/* BKP_TPCTL */
#define BKP_TPCTL_TPAL     _BIT(1,U)          /*!< tamper pin active level */
#define BKP_TPCTL_TPEN     _BIT(0,U)          /*!< tamper detection enable */

/* BKP_TPCS */
#define BKP_TPCS_TIF       _BIT(9,U)          /*!< tamper interrupt flag */
#define BKP_TPCS_TEF       _BIT(8,U)          /*!< tamper event flag */
#define BKP_TPCS_TPIE      _BIT(2,U)          /*!< tamper interrupt enable */
#define BKP_TPCS_TIR       _BIT(1,U)          /*!< tamper interrupt reset */
#define BKP_TPCS_TER       _BIT(0,U)          /*!< tamper event reset */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_bkp_data {
	uint16_t reserved;
	volatile uint16_t DATA;
};

struct gd32vf103_bkp {
	uint32_t reserved1;
	struct gd32vf103_bkp_data DATA0_9[10];
	volatile uint32_t OCTL;
	volatile uint32_t TPCTL;
	volatile uint32_t TPCS;
	uint32_t reserved2;
	uint32_t reserved3;
	struct gd32vf103_bkp_data DATA10_41[32];
};

static struct gd32vf103_bkp *const BKP = (struct gd32vf103_bkp *)BKP_BASE;

#endif
#endif
