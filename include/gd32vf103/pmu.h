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
#ifndef GD32VF103_PMU_H
#define GD32VF103_PMU_H

#include "gd32vf103.h"

#define PMU_BASE _AC(0x40007000,UL)  /*!< PMU base address */

/* register definitions */
#define PMU_CTL  _AC(0x00,UL)  /*!< PMU control register */
#define PMU_CS   _AC(0x04,UL)  /*!< PMU control and status register */

/* PMU_CTL */
#define PMU_CTL_BKPWEN     _BIT(8,U)          /*!< backup domain write enable */
#define PMU_CTL_LVDT_Pos   5
#define PMU_CTL_LVDT_Msk   _AC(0x000000e0,U)  /*!< low voltage detector threshold */
#define PMU_CTL_LVDT(x)    ((x) << PMU_CTL_LVDT_Pos)
#define PMU_CTL_LVDT_2_2V  PMU_CTL_LVDT(0)    /*!< voltage threshold is 2.2V */
#define PMU_CTL_LVDT_2_3V  PMU_CTL_LVDT(1)    /*!< voltage threshold is 2.3V */
#define PMU_CTL_LVDT_2_4V  PMU_CTL_LVDT(2)    /*!< voltage threshold is 2.4V */
#define PMU_CTL_LVDT_2_5V  PMU_CTL_LVDT(3)    /*!< voltage threshold is 2.5V */
#define PMU_CTL_LVDT_2_6V  PMU_CTL_LVDT(4)    /*!< voltage threshold is 2.6V */
#define PMU_CTL_LVDT_2_7V  PMU_CTL_LVDT(5)    /*!< voltage threshold is 2.7V */
#define PMU_CTL_LVDT_2_8V  PMU_CTL_LVDT(6)    /*!< voltage threshold is 2.8V */
#define PMU_CTL_LVDT_2_9V  PMU_CTL_LVDT(7)    /*!< voltage threshold is 2.9V */
#define PMU_CTL_LVDEN      _BIT(4,U)          /*!< low voltage detector enable */
#define PMU_CTL_STBRST     _BIT(3,U)          /*!< standby flag reset */
#define PMU_CTL_WURST      _BIT(2,U)          /*!< wakeup flag reset */
#define PMU_CTL_STBMOD     _BIT(1,U)          /*!< standby mode */
#define PMU_CTL_LDOLP      _BIT(0,U)          /*!< LDO low power mode */

/* PMU_CS */
#define PMU_CS_WUPEN       _BIT(8,U)          /*!< wakeup pin enable */
#define PMU_CS_LVDF        _BIT(2,U)          /*!< low voltage detector status flag */
#define PMU_CS_STBF        _BIT(1,U)          /*!< standby flag */
#define PMU_CS_WUF         _BIT(0,U)          /*!< wakeup flag */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_pmu {
	volatile uint32_t CTL;
	volatile uint32_t CS;
};

static struct gd32vf103_pmu *const PMU = (struct gd32vf103_pmu *)PMU_BASE;

#endif
#endif
