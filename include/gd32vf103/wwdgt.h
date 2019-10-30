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
#ifndef GD32VF103_WWDGT_H
#define GD32VF103_WWDGT_H

#include "gd32vf103.h"

#define WWDGT_BASE _AC(0x40002C00,UL)  /*!< WWDGT base address */

/* register definitions */
#define WWDGT_CTL   _AC(0x00,UL)  /*!< WWDGT control register */
#define WWDGT_CFG   _AC(0x04,UL)  /*!< WWDGT configuration register */
#define WWDGT_STAT  _AC(0x08,UL)  /*!< WWDGT status register */

/* WWDGT_CTL */
#define WWDGT_CTL_WDGTEN    _BIT(7,U)          /*!< WWDGT counter enable */
#define WWDGT_CTL_CNT_Pos   0
#define WWDGT_CTL_CNT_Msk   _AC(0x0000007f,U)  /*!< WWDGT counter value */
#define WWDGT_CTL_CNT(x)    ((x) << WWDGT_CTL_CNT_Pos)

/* WWDGT_CFG */
#define WWDGT_CFG_EWIE      _BIT(9,U)          /*!< early wakeup interrupt enable */
#define WWDGT_CFG_PSC_Pos   7
#define WWDGT_CFG_PSC_Msk   _AC(0x00000180,U)  /*!< WWDGT prescaler divider value */
#define WWDGT_CFG_PSC(x)    ((x) << WWDGT_CFG_PSC_Pos)
#define WWDGT_CFG_PSC_DIV1  WWDGT_CFG_PSC(0)   /*!< the time base of WWDGT = (PCLK1/4096)/1 */
#define WWDGT_CFG_PSC_DIV2  WWDGT_CFG_PSC(1)   /*!< the time base of WWDGT = (PCLK1/4096)/2 */
#define WWDGT_CFG_PSC_DIV4  WWDGT_CFG_PSC(2)   /*!< the time base of WWDGT = (PCLK1/4096)/4 */
#define WWDGT_CFG_PSC_DIV8  WWDGT_CFG_PSC(3)   /*!< the time base of WWDGT = (PCLK1/4096)/8 */
#define WWDGT_CFG_WIN_Pos   0
#define WWDGT_CFG_WIN_Msk   _AC(0x0000007f,U)  /*!< WWDGT counter window value */
#define WWDGT_CFG_WIN(x)    ((x) << WWDGT_CFG_WIN_Pos)

/* WWDGT_STAT */
#define WWDGT_STAT_EWIF     _BIT(0,U)          /*!< early wakeup interrupt flag */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_wwdgt {
	volatile uint32_t CTL;
	volatile uint32_t CFG;
	volatile uint32_t STAT;
};

static struct gd32vf103_wwdgt *const WWDGT = (struct gd32vf103_wwdgt *)WWDGT_BASE;

#endif
#endif
