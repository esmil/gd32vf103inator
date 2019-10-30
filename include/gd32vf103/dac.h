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
#ifndef GD32VF103_DAC_H
#define GD32VF103_DAC_H

#include "gd32vf103.h"

#define DAC_BASE _AC(0x40007400,UL)  /*!< DAC base address */

/* register definitions */
#define DAC_CTL     _AC(0x00,UL)  /*!< DAC control register */
#define DAC_SWT     _AC(0x04,UL)  /*!< DAC software trigger register */
#define DAC_R12DH0  _AC(0x08,UL)  /*!< DAC0 12-bit right-aligned data holding register */
#define DAC_L12DH0  _AC(0x0C,UL)  /*!< DAC0 12-bit left-aligned data holding register */
#define DAC_R8DH0   _AC(0x10,UL)  /*!< DAC0 8-bit right-aligned data holding register */
#define DAC_R12DH1  _AC(0x14,UL)  /*!< DAC1 12-bit right-aligned data holding register */
#define DAC_L12DH1  _AC(0x18,UL)  /*!< DAC1 12-bit left-aligned data holding register */
#define DAC_R8DH1   _AC(0x1C,UL)  /*!< DAC1 8-bit right-aligned data holding register */
#define DAC_R12DHC  _AC(0x20,UL)  /*!< DAC concurrent mode 12-bit right-aligned data holding register */
#define DAC_L12DHC  _AC(0x24,UL)  /*!< DAC concurrent mode 12-bit left-aligned data holding register */
#define DAC_R8DHC   _AC(0x28,UL)  /*!< DAC concurrent mode 8-bit right-aligned data holding register */
#define DAC_DO0     _AC(0x2C,UL)  /*!< DAC0 data output register */
#define DAC_DO1     _AC(0x30,UL)  /*!< DAC1 data output register */

/* DAC_CTL */
#define DAC_CTL_DDMAEN1          _BIT(28,U)         /*!< DAC1 DMA enable/disable bit */
#define DAC_CTL_DWBW1_Pos        24
#define DAC_CTL_DWBW1_Msk        _AC(0x0f000000,U)  /*!< DAC1 noise wave bit width */
#define DAC_CTL_DWBW1(x)         ((x) << DAC_CTL_DWBW1_Pos)
#define DAC_CTL_DWM1_Pos         22
#define DAC_CTL_DWM1_Msk         _AC(0x00c00000,U)  /*!< DAC1 noise wave mode */
#define DAC_CTL_DWM1(x)          ((x) << DAC_CTL_DWM1_Pos)
#define DAC_CTL_DWM1_DISABLED    DAC_CTL_DWM1(0)    /*!< DAC1 wave disable */
#define DAC_CTL_DWM1_LFSR        DAC_CTL_DWM1(1)    /*!< DAC1 LFSR noise mode */
#define DAC_CTL_DWM1_TRIANGLE    DAC_CTL_DWM1(2)    /*!< DAC1 triangle noise mode */
#define DAC_CTL_DTSEL1_Pos       19
#define DAC_CTL_DTSEL1_Msk       _AC(0x00380000,U)  /*!< DAC1 trigger source selection enable/disable bits */
#define DAC_CTL_DTSEL1(x)        ((x) << DAC_CTL_DTSEL1_Pos)
#define DAC_CTL_DTSEL1_T5_TRGO   DAC_CTL_DTSEL1(0)  /*!< DAC1 TIMER5 TRGO */
#define DAC_CTL_DTSEL1_T2_TRGO   DAC_CTL_DTSEL1(1)  /*!< DAC1 TIMER2 TRGO */
#define DAC_CTL_DTSEL1_T6_TRGO   DAC_CTL_DTSEL1(2)  /*!< DAC1 TIMER6 TRGO */
#define DAC_CTL_DTSEL1_T4_TRGO   DAC_CTL_DTSEL1(3)  /*!< DAC1 TIMER4 TRGO */
#define DAC_CTL_DTSEL1_T1_TRGO   DAC_CTL_DTSEL1(4)  /*!< DAC1 TIMER1 TRGO */
#define DAC_CTL_DTSEL1_T3_TRGO   DAC_CTL_DTSEL1(5)  /*!< DAC1 TIMER3 TRGO */
#define DAC_CTL_DTSEL1_EXTI_9    DAC_CTL_DTSEL1(6)  /*!< DAC1 EXTI interrupt line9 event */
#define DAC_CTL_DTSEL1_SOFTWARE  DAC_CTL_DTSEL1(7)  /*!< DAC1 software trigger */
#define DAC_CTL_DTEN1            _BIT(18,U)         /*!< DAC1 trigger enable/disable bit */
#define DAC_CTL_DBOFF1           _BIT(17,U)         /*!< DAC1 output buffer turn on/turn off bit */
#define DAC_CTL_DEN1             _BIT(16,U)         /*!< DAC1 enable/disable bit */
#define DAC_CTL_DDMAEN0          _BIT(12,U)         /*!< DAC0 DMA enable/disable bit */
#define DAC_CTL_DWBW0_Pos        8
#define DAC_CTL_DWBW0_Msk        _AC(0x00000f00,U)  /*!< DAC0 noise wave bit width */
#define DAC_CTL_DWBW0(x)         ((x) << DAC_CTL_DWBW0_Pos)
#define DAC_CTL_DWM0_Pos         6
#define DAC_CTL_DWM0_Msk         _AC(0x000000c0,U)  /*!< DAC0 noise wave mode */
#define DAC_CTL_DWM0(x)          ((x) << DAC_CTL_DWM0_Pos)
#define DAC_CTL_DWM0_DISABLED    DAC_CTL_DWM0(0)    /*!< DAC0 wave disable */
#define DAC_CTL_DWM0_LFSR        DAC_CTL_DWM0(1)    /*!< DAC0 LFSR noise mode */
#define DAC_CTL_DWM0_TRIANGLE    DAC_CTL_DWM0(2)    /*!< DAC0 triangle noise mode */
#define DAC_CTL_DTSEL0_Pos       3
#define DAC_CTL_DTSEL0_Msk       _AC(0x00000038,U)  /*!< DAC0 trigger source selection enable/disable bits */
#define DAC_CTL_DTSEL0(x)        ((x) << DAC_CTL_DTSEL0_Pos)
#define DAC_CTL_DTSEL0_T5_TRGO   DAC_CTL_DTSEL0(0)  /*!< DAC0 TIMER5 TRGO */
#define DAC_CTL_DTSEL0_T2_TRGO   DAC_CTL_DTSEL0(1)  /*!< DAC0 TIMER2 TRGO */
#define DAC_CTL_DTSEL0_T6_TRGO   DAC_CTL_DTSEL0(2)  /*!< DAC0 TIMER6 TRGO */
#define DAC_CTL_DTSEL0_T4_TRGO   DAC_CTL_DTSEL0(3)  /*!< DAC0 TIMER4 TRGO */
#define DAC_CTL_DTSEL0_T1_TRGO   DAC_CTL_DTSEL0(4)  /*!< DAC0 TIMER1 TRGO */
#define DAC_CTL_DTSEL0_T3_TRGO   DAC_CTL_DTSEL0(5)  /*!< DAC0 TIMER3 TRGO */
#define DAC_CTL_DTSEL0_EXTI_9    DAC_CTL_DTSEL0(6)  /*!< DAC0 EXTI interrupt line9 event */
#define DAC_CTL_DTSEL0_SOFTWARE  DAC_CTL_DTSEL0(7)  /*!< DAC0 software trigger */
#define DAC_CTL_DTEN0            _BIT(2,U)          /*!< DAC0 trigger enable/disable bit */
#define DAC_CTL_DBOFF0           _BIT(1,U)          /*!< DAC0 output buffer turn on/turn off bit */
#define DAC_CTL_DEN0             _BIT(0,U)          /*!< DAC0 enable/disable bit */

/* DAC_SWT */
#define DAC_SWT_SWTR1            _BIT(1,U)          /*!< DAC1 software trigger bit, cleared by hardware */
#define DAC_SWT_SWTR0            _BIT(0,U)          /*!< DAC0 software trigger bit, cleared by hardware */

/* DAC_R12DHx, x=0,1 */
#define DAC_R12DHX_DAC_DH_Pos    0
#define DAC_R12DHX_DAC_DH_Msk    _AC(0x00000fff,U)  /*!< DAC 12-bit right-aligned data bits */
#define DAC_R12DHX_DAC_DH(x)     ((x) << DAC_R12DHX_DAC_DH_Pos)

/* DAC_L12DHx, x=0,1 */
#define DAC_L12DHX_DAC_DH_Pos    4
#define DAC_L12DHX_DAC_DH_Msk    _AC(0x0000fff0,U)  /*!< DAC 12-bit left-aligned data bits */
#define DAC_L12DHX_DAC_DH(x)     ((x) << DAC_L12DHX_DAC_DH_Pos)

/* DAC_R8DHx, x=0,1 */
#define DAC_R8DHX_DAC_DH_Pos     0
#define DAC_R8DHX_DAC_DH_Msk     _AC(0x000000ff,U)  /*!< DAC 8-bit right-aligned data bits */
#define DAC_R8DHX_DAC_DH(x)      ((x) << DAC_R8DHX_DAC_DH_Pos)

/* DAC_R12DHC */
#define DAC_R12DHC_DAC1_DH_Pos   16
#define DAC_R12DHC_DAC1_DH_Msk   _AC(0x0fff0000,U)  /*!< DAC concurrent mode DAC1 12-bit right-aligned data bits */
#define DAC_R12DHC_DAC1_DH(x)    ((x) << DAC_R12DHC_DAC1_DH_Pos)
#define DAC_R12DHC_DAC0_DH_Pos   0
#define DAC_R12DHC_DAC0_DH_Msk   _AC(0x00000fff,U)  /*!< DAC concurrent mode DAC0 12-bit right-aligned data bits */
#define DAC_R12DHC_DAC0_DH(x)    ((x) << DAC_R12DHC_DAC0_DH_Pos)

/* DAC_L12DHC */
#define DAC_L12DHC_DAC1_DH_Pos   20
#define DAC_L12DHC_DAC1_DH_Msk   _AC(0xfff00000,U)  /*!< DAC concurrent mode DAC1 12-bit left-aligned data bits */
#define DAC_L12DHC_DAC1_DH(x)    ((x) << DAC_L12DHC_DAC1_DH_Pos)
#define DAC_L12DHC_DAC0_DH_Pos   4
#define DAC_L12DHC_DAC0_DH_Msk   _AC(0x0000fff0,U)  /*!< DAC concurrent mode DAC0 12-bit left-aligned data bits */
#define DAC_L12DHC_DAC0_DH(x)    ((x) << DAC_L12DHC_DAC0_DH_Pos)

/* DAC_R8DHC */
#define DAC_R8DHC_DAC1_DH_Pos    8
#define DAC_R8DHC_DAC1_DH_Msk    _AC(0x0000ff00,U)  /*!< DAC concurrent mode DAC1 8-bit right-aligned data bits */
#define DAC_R8DHC_DAC1_DH(x)     ((x) << DAC_R8DHC_DAC1_DH_Pos)
#define DAC_R8DHC_DAC0_DH_Pos    0
#define DAC_R8DHC_DAC0_DH_Msk    _AC(0x000000ff,U)  /*!< DAC concurrent mode DAC0 8-bit right-aligned data bits */
#define DAC_R8DHC_DAC0_DH(x)     ((x) << DAC_R8DHC_DAC0_DH_Pos)

/* DAC_DOX */
#define DAC_DO_DAC_DO_Pos        0
#define DAC_DO_DAC_DO_Msk        _AC(0x00000fff,U)  /*!< DAC 12-bit output data bits */
#define DAC_DO_DAC_DO(x)         ((x) << DAC_DO_DAC_DO_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_dac {
	volatile uint32_t CTL;
	volatile uint32_t SWT;
	volatile uint32_t R12DH0;
	volatile uint32_t L12DH0;
	volatile uint32_t R8DH0;
	volatile uint32_t R12DH1;
	volatile uint32_t L12DH1;
	volatile uint32_t R8DH1;
	volatile uint32_t R12DHC;
	volatile uint32_t L12DHC;
	volatile uint32_t R8DHC;
	volatile uint32_t DO0;
	volatile uint32_t DO1;
};

static struct gd32vf103_dac *const DAC = (struct gd32vf103_dac *)DAC_BASE;

#endif
#endif
