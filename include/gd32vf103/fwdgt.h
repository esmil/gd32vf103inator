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
#ifndef GD32VF103_FWDGT_H
#define GD32VF103_FWDGT_H

#include "gd32vf103.h"

#define FWDGT_BASE _AC(0x40003000,UL)  /*!< FWDGT base address */

/* register definitions */
#define FWDGT_CTL   _AC(0x00,UL)  /*!< FWDGT control register */
#define FWDGT_PSC   _AC(0x04,UL)  /*!< FWDGT prescaler register */
#define FWDGT_RLD   _AC(0x08,UL)  /*!< FWDGT reload register */
#define FWDGT_STAT  _AC(0x0C,UL)  /*!< FWDGT status register */

/* FWDGT_CTL */
#define FWDGT_CTL_CMD_Pos         0
#define FWDGT_CTL_CMD_Msk         _AC(0x0000ffff,U)  /*!< FWDGT command value */
#define FWDGT_CTL_CMD(x)          ((x) << FWDGT_CTL_CMD_Pos)
#define FWDGT_CTL_CMD_WP_DISABLE  _AC(0x00005555,U)  /*!< disable FWDGT_PSC and FWDGT_RLD write protection */
#define FWDGT_CTL_CMD_WP_ENABLE   _AC(0x00000000,U)  /*!< enable FWDGT_PSC and FWDGT_RLD write protection */
#define FWDGT_CTL_CMD_RELOAD      _AC(0x0000aaaa,U)  /*!< reload watchdog counter */
#define FWDGT_CTL_CMD_START       _AC(0x0000cccc,U)  /*!< start watchdog counter */

/* FWDGT_PSC */
#define FWDGT_PSC_PSC_Pos         0
#define FWDGT_PSC_PSC_Msk         _AC(0x00000003,U)  /*!< FWDGT prescaler divider value */
#define FWDGT_PSC_PSC(x)          ((x) << FWDGT_PSC_PSC_Pos)
#define FWDGT_PSC_PSC_DIV4        FWDGT_PSC_PSC(0)   /*!< FWDGT prescaler set to 4 */
#define FWDGT_PSC_PSC_DIV8        FWDGT_PSC_PSC(1)   /*!< FWDGT prescaler set to 8 */
#define FWDGT_PSC_PSC_DIV16       FWDGT_PSC_PSC(2)   /*!< FWDGT prescaler set to 16 */
#define FWDGT_PSC_PSC_DIV32       FWDGT_PSC_PSC(3)   /*!< FWDGT prescaler set to 32 */
#define FWDGT_PSC_PSC_DIV64       FWDGT_PSC_PSC(4)   /*!< FWDGT prescaler set to 64 */
#define FWDGT_PSC_PSC_DIV128      FWDGT_PSC_PSC(5)   /*!< FWDGT prescaler set to 128 */
#define FWDGT_PSC_PSC_DIV256      FWDGT_PSC_PSC(6)   /*!< FWDGT prescaler set to 256 */

/* FWDGT_RLD */
#define FWDGT_RLD_RLD_Pos         0
#define FWDGT_RLD_RLD_Msk         _AC(0x00000fff,U)  /*!< FWDGT counter reload value */
#define FWDGT_RLD_RLD(x)          ((x) << FWDGT_RLD_RLD_Pos)

/* FWDGT_STAT */
#define FWDGT_STAT_RUD            _BIT(1,U)          /*!< FWDGT counter reload value update */
#define FWDGT_STAT_PUD            _BIT(0,U)          /*!< FWDGT prescaler divider value update */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_fwdgt {
	volatile uint32_t CTL;
	volatile uint32_t PSC;
	volatile uint32_t RLD;
	volatile uint32_t STAT;
};

static struct gd32vf103_fwdgt *const FWDGT = (struct gd32vf103_fwdgt *)FWDGT_BASE;

#endif
#endif
