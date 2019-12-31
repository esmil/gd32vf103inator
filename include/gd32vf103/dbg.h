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
#ifndef GD32VF103_DBG_H
#define GD32VF103_DBG_H

#include "gd32vf103.h"

#define DBG_BASE _AC(0xe0042000,UL)  /*!< DBG base address */

/* register definitions */
#define DBG_ID   _AC(0x00,UL)  /*!< DBG_ID code register */
#define DBG_CTL  _AC(0x04,UL)  /*!< DBG control register */
/* undocumented registers below, names guessed */
#define DBG_CMD  _AC(0x08,UL)  /*!< DBG command register */
#define DBG_KEY  _AC(0x0c,UL)  /*!< DBG unlock key register */

/* DBG_ID */
#define DBG_ID_ID_CODE_Pos   0
#define DBG_ID_ID_CODE_Msk   _AC(0xffffffff,U)  /*!< DBG ID code values */
#define DBG_ID_ID_CODE(x)    ((x) << DBG_ID_ID_CODE_Pos)

/* DBG_CTL */
#define DBG_CTL_CAN1_HOLD    _BIT(21,U)         /*!< debug CAN1 kept when core is halted */
#define DBG_CTL_TIMER6_HOLD  _BIT(20,U)         /*!< hold TIMER6 counter when core is halted */
#define DBG_CTL_TIMER5_HOLD  _BIT(19,U)         /*!< hold TIMER5 counter when core is halted */
#define DBG_CTL_TIMER4_HOLD  _BIT(18,U)         /*!< hold TIMER4 counter when core is halted */
#define DBG_CTL_I2C1_HOLD    _BIT(16,U)         /*!< hold I2C1 smbus when core is halted */
#define DBG_CTL_I2C0_HOLD    _BIT(15,U)         /*!< hold I2C0 smbus when core is halted */
#define DBG_CTL_CAN0_HOLD    _BIT(14,U)         /*!< debug CAN0 kept when core is halted */
#define DBG_CTL_TIMER3_HOLD  _BIT(13,U)         /*!< hold TIMER3 counter when core is halted */
#define DBG_CTL_TIMER2_HOLD  _BIT(12,U)         /*!< hold TIMER2 counter when core is halted */
#define DBG_CTL_TIMER1_HOLD  _BIT(11,U)         /*!< hold TIMER1 counter when core is halted */
#define DBG_CTL_TIMER0_HOLD  _BIT(10,U)         /*!< hold TIMER0 counter when core is halted */
#define DBG_CTL_WWDGT_HOLD   _BIT(9,U)          /*!< debug WWDGT kept when core is halted */
#define DBG_CTL_FWDGT_HOLD   _BIT(8,U)          /*!< debug FWDGT kept when core is halted */
#define DBG_CTL_STB_HOLD     _BIT(2,U)          /*!< keep debugger connection during standby mode */
#define DBG_CTL_DSLP_HOLD    _BIT(1,U)          /*!< keep debugger connection during deepsleep mode */
#define DBG_CTL_SLP_HOLD     _BIT(0,U)          /*!< keep debugger connection during sleep mode */

/* DBG_CMD */
#define DBG_CMD_RESET        _BIT(0,U)          /*!< software reset */

/* DBG_KEY */
#define DBG_KEY_UNLOCK       _AC(0x4b5a6978,U)  /*!< unlock key */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_dbg {
	const uint32_t ID;
	volatile uint32_t CTL;
	volatile uint32_t CMD;
	volatile uint32_t KEY;
};

static struct gd32vf103_dbg *const DBG = (struct gd32vf103_dbg *)DBG_BASE;

#endif
#endif
