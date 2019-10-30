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
#ifndef GD32VF103_RCU_H
#define GD32VF103_RCU_H

#include "gd32vf103.h"

#define RCU_BASE _AC(0x40021000,UL)  /*!< RCU base address */

/* register definitions */
#define RCU_CTL     _AC(0x00,UL) /*!< control register */
#define RCU_CFG0    _AC(0x04,UL) /*!< clock configuration register 0 */
#define RCU_INT     _AC(0x08,UL) /*!< clock interrupt register */
#define RCU_APB2RST _AC(0x0C,UL) /*!< APB2 reset register */
#define RCU_APB1RST _AC(0x10,UL) /*!< APB1 reset register */
#define RCU_AHBEN   _AC(0x14,UL) /*!< AHB1 enable register */
#define RCU_APB2EN  _AC(0x18,UL) /*!< APB2 enable register */
#define RCU_APB1EN  _AC(0x1C,UL) /*!< APB1 enable register */
#define RCU_BDCTL   _AC(0x20,UL) /*!< backup domain control register */
#define RCU_RSTSCK  _AC(0x24,UL) /*!< reset source / clock register */
#define RCU_AHBRST  _AC(0x28,UL) /*!< AHB reset register */
#define RCU_CFG1    _AC(0x2C,UL) /*!< clock configuration register 1 */
#define RCU_DSV     _AC(0x34,UL) /*!< deep-sleep mode voltage register */

/* RCU_CTL */
#define RCU_CTL_PLL2STB                _BIT(29,U)              /*!< PLL2 clock stabilization flag */
#define RCU_CTL_PLL2EN                 _BIT(28,U)              /*!< PLL2 enable */
#define RCU_CTL_PLL1STB                _BIT(27,U)              /*!< PLL1 clock stabilization flag */
#define RCU_CTL_PLL1EN                 _BIT(26,U)              /*!< PLL1 enable */
#define RCU_CTL_PLLSTB                 _BIT(25,U)              /*!< PLL clock stabilization flag */
#define RCU_CTL_PLLEN                  _BIT(24,U)              /*!< PLL enable */
#define RCU_CTL_CKMEN                  _BIT(19,U)              /*!< HXTAL clock monitor enable */
#define RCU_CTL_HXTALBPS               _BIT(18,U)              /*!< external crystal oscillator clock bypass mode enable */
#define RCU_CTL_HXTALSTB               _BIT(17,U)              /*!< external crystal oscillator clock stabilization flag */
#define RCU_CTL_HXTALEN                _BIT(16,U)              /*!< external high speed oscillator enable */
#define RCU_CTL_IRC8MCALIB_Pos         8
#define RCU_CTL_IRC8MCALIB_Msk         _AC(0x0000ff00,U)       /*!< high speed internal oscillator calibration value register */
#define RCU_CTL_IRC8MCALIB(x)          ((x) << RCU_CTL_IRC8MCALIB_Pos)
#define RCU_CTL_IRC8MADJ_Pos           3
#define RCU_CTL_IRC8MADJ_Msk           _AC(0x000000f80,U)      /*!< high speed internal oscillator clock trim adjust value */
#define RCU_CTL_IRC8MADJ(x)            ((x) << RCU_CTL_IRC8MADJ_Pos)
#define RCU_CTL_IRC8MSTB               _BIT(1,U)               /*!< IRC8M high speed internal oscillator stabilization flag */
#define RCU_CTL_IRC8MEN                _BIT(0,U)               /*!< internal high speed oscillator enable */

/* RCU_CFG0 */
#define RCU_CFG0_PLLMF_4_Pos           29
#define RCU_CFG0_PLLMF_4               _BIT(29,U)              /*!< bit 4 of PLLMF */
#define RCU_CFG0_ADCPSC_2_Pos          28
#define RCU_CFG0_ADCPSC_2              _BIT(28,U)              /*!< bit 2 of ADCPSC */
#define RCU_CFG0_CKOUT0SEL_Pos         24
#define RCU_CFG0_CKOUT0SEL_Msk         _AC(0x0f000000,U)       /*!< CKOUT0 clock source selection */
#define RCU_CFG0_CKOUT0SEL(x)          ((x) << RCU_CFG0_CKOUT0SEL_Pos)
#define RCU_CFG0_CKOUT0SEL_NONE        RCU_CFG0_CKOUT0SEL(0)   /*!< no clock selected */
#define RCU_CFG0_CKOUT0SEL_CKSYS       RCU_CFG0_CKOUT0SEL(4)   /*!< system clock selected */
#define RCU_CFG0_CKOUT0SEL_IRC8M       RCU_CFG0_CKOUT0SEL(5)   /*!< internal 8M RC oscillator clock selected */
#define RCU_CFG0_CKOUT0SEL_HXTAL       RCU_CFG0_CKOUT0SEL(6)   /*!< high speed crystal oscillator clock (HXTAL) selected */
#define RCU_CFG0_CKOUT0SEL_CKPLL_DIV2  RCU_CFG0_CKOUT0SEL(7)   /*!< CK_PLL/2 clock selected */
#define RCU_CFG0_CKOUT0SEL_CKPLL1      RCU_CFG0_CKOUT0SEL(8)   /*!< CK_PLL1 clock selected */
#define RCU_CFG0_CKOUT0SEL_CKPLL2_DIV2 RCU_CFG0_CKOUT0SEL(9)   /*!< CK_PLL2/2 clock selected */
#define RCU_CFG0_CKOUT0SEL_EXT1        RCU_CFG0_CKOUT0SEL(10)  /*!< EXT1 selected */
#define RCU_CFG0_CKOUT0SEL_CKPLL2      RCU_CFG0_CKOUT0SEL(11)  /*!< CK_PLL2 clock selected */
#define RCU_CFG0_USBFSPSC_Pos          22
#define RCU_CFG0_USBFSPSC_Msk          _AC(0x00c00000,U)       /*!< USBFS clock prescaler selection */
#define RCU_CFG0_USBFSPSC(x)           ((x) << RCU_CFG0_USBFSPSC_Pos)
#define RCU_CFG0_USBFSPSC_DIV1_5       RCU_CFG0_USBFSPSC(0)    /*!< USBFS prescaler select CK_PLL/1.5 */
#define RCU_CFG0_USBFSPSC_DIV1         RCU_CFG0_USBFSPSC(1)    /*!< USBFS prescaler select CK_PLL/1 */
#define RCU_CFG0_USBFSPSC_DIV2_5       RCU_CFG0_USBFSPSC(2)    /*!< USBFS prescaler select CK_PLL/2.5 */
#define RCU_CFG0_USBFSPSC_DIV2         RCU_CFG0_USBFSPSC(3)    /*!< USBFS prescaler select CK_PLL/2 */
#define RCU_CFG0_PLLMF_Pos             18
#define RCU_CFG0_PLLMF_Msk             _AC(0x203c0000,U)       /*!< PLL clock multiplication factor */
#define RCU_CFG0_PLLMF(x)              ((((x) & _AC(0xf,U)) << RCU_CFG0_PLLMF_Pos) | (((x) >> 4) << RCU_CFG0_PLLMF_4_Pos))
#define RCU_CFG0_PLLMF_MUL2            RCU_CFG0_PLLMF(0)       /*!< PLL source clock multiply by 2 */
#define RCU_CFG0_PLLMF_MUL3            RCU_CFG0_PLLMF(1)       /*!< PLL source clock multiply by 3 */
#define RCU_CFG0_PLLMF_MUL4            RCU_CFG0_PLLMF(2)       /*!< PLL source clock multiply by 4 */
#define RCU_CFG0_PLLMF_MUL5            RCU_CFG0_PLLMF(3)       /*!< PLL source clock multiply by 5 */
#define RCU_CFG0_PLLMF_MUL6            RCU_CFG0_PLLMF(4)       /*!< PLL source clock multiply by 6 */
#define RCU_CFG0_PLLMF_MUL7            RCU_CFG0_PLLMF(5)       /*!< PLL source clock multiply by 7 */
#define RCU_CFG0_PLLMF_MUL8            RCU_CFG0_PLLMF(6)       /*!< PLL source clock multiply by 8 */
#define RCU_CFG0_PLLMF_MUL9            RCU_CFG0_PLLMF(7)       /*!< PLL source clock multiply by 9 */
#define RCU_CFG0_PLLMF_MUL10           RCU_CFG0_PLLMF(8)       /*!< PLL source clock multiply by 10 */
#define RCU_CFG0_PLLMF_MUL11           RCU_CFG0_PLLMF(9)       /*!< PLL source clock multiply by 11 */
#define RCU_CFG0_PLLMF_MUL12           RCU_CFG0_PLLMF(10)      /*!< PLL source clock multiply by 12 */
#define RCU_CFG0_PLLMF_MUL13           RCU_CFG0_PLLMF(11)      /*!< PLL source clock multiply by 13 */
#define RCU_CFG0_PLLMF_MUL14           RCU_CFG0_PLLMF(12)      /*!< PLL source clock multiply by 14 */
#define RCU_CFG0_PLLMF_MUL6_5          RCU_CFG0_PLLMF(13)      /*!< PLL source clock multiply by 6.5 */
#define RCU_CFG0_PLLMF_MUL16           RCU_CFG0_PLLMF(14)      /*!< PLL source clock multiply by 16 */
#define RCU_CFG0_PLLMF_MUL17           RCU_CFG0_PLLMF(16)      /*!< PLL source clock multiply by 17 */
#define RCU_CFG0_PLLMF_MUL18           RCU_CFG0_PLLMF(17)      /*!< PLL source clock multiply by 18 */
#define RCU_CFG0_PLLMF_MUL19           RCU_CFG0_PLLMF(18)      /*!< PLL source clock multiply by 19 */
#define RCU_CFG0_PLLMF_MUL20           RCU_CFG0_PLLMF(19)      /*!< PLL source clock multiply by 20 */
#define RCU_CFG0_PLLMF_MUL21           RCU_CFG0_PLLMF(20)      /*!< PLL source clock multiply by 21 */
#define RCU_CFG0_PLLMF_MUL22           RCU_CFG0_PLLMF(21)      /*!< PLL source clock multiply by 22 */
#define RCU_CFG0_PLLMF_MUL23           RCU_CFG0_PLLMF(22)      /*!< PLL source clock multiply by 23 */
#define RCU_CFG0_PLLMF_MUL24           RCU_CFG0_PLLMF(23)      /*!< PLL source clock multiply by 24 */
#define RCU_CFG0_PLLMF_MUL25           RCU_CFG0_PLLMF(24)      /*!< PLL source clock multiply by 25 */
#define RCU_CFG0_PLLMF_MUL26           RCU_CFG0_PLLMF(25)      /*!< PLL source clock multiply by 26 */
#define RCU_CFG0_PLLMF_MUL27           RCU_CFG0_PLLMF(26)      /*!< PLL source clock multiply by 27 */
#define RCU_CFG0_PLLMF_MUL28           RCU_CFG0_PLLMF(27)      /*!< PLL source clock multiply by 28 */
#define RCU_CFG0_PLLMF_MUL29           RCU_CFG0_PLLMF(28)      /*!< PLL source clock multiply by 29 */
#define RCU_CFG0_PLLMF_MUL30           RCU_CFG0_PLLMF(29)      /*!< PLL source clock multiply by 30 */
#define RCU_CFG0_PLLMF_MUL31           RCU_CFG0_PLLMF(30)      /*!< PLL source clock multiply by 31 */
#define RCU_CFG0_PLLMF_MUL32           RCU_CFG0_PLLMF(31)      /*!< PLL source clock multiply by 32 */
#define RCU_CFG0_PREDV0_LSB            _BIT(17,U)              /*!< the LSB of PREDV0 division factor */
#define RCU_CFG0_PLLSEL                _BIT(16,U)              /*!< PLL clock source selection */
#define RCU_CFG0_ADCPSC_Pos            14
#define RCU_CFG0_ADCPSC_Msk            _AC(0x1000c000,U)       /*!< ADC prescaler selection */
#define RCU_CFG0_ADCPSC(x)             ((((x) & _AC(0x3,U)) << RCU_CFG0_ADCPSC_Pos) | (((x) >> 2) << RCU_CFG0_ADCPSC_2_Pos))
#define RCU_CFG0_ADCPSC_DIV2           RCU_CFG0_ADCPSC(0)      /*!< ADC prescaler select CK_APB2/2 */
#define RCU_CFG0_ADCPSC_DIV4           RCU_CFG0_ADCPSC(1)      /*!< ADC prescaler select CK_APB2/4 */
#define RCU_CFG0_ADCPSC_DIV6           RCU_CFG0_ADCPSC(2)      /*!< ADC prescaler select CK_APB2/6 */
#define RCU_CFG0_ADCPSC_DIV8           RCU_CFG0_ADCPSC(3)      /*!< ADC prescaler select CK_APB2/8 */
#define RCU_CFG0_ADCPSC_DIV12          RCU_CFG0_ADCPSC(5)      /*!< ADC prescaler select CK_APB2/12 */
#define RCU_CFG0_ADCPSC_DIV16          RCU_CFG0_ADCPSC(7)      /*!< ADC prescaler select CK_APB2/16 */
#define RCU_CFG0_APB2PSC_Pos           11
#define RCU_CFG0_APB2PSC_Msk           _AC(0x00003800,U)       /*!< APB2 prescaler selection */
#define RCU_CFG0_APB2PSC(x)            ((x) << RCU_CFG0_APB2PSC_Pos)
#define RCU_CFG0_APB2PSC_DIV1          RCU_CFG0_APB2PSC(0)     /*!< APB2 prescaler select CK_AHB */
#define RCU_CFG0_APB2PSC_DIV2          RCU_CFG0_APB2PSC(4)     /*!< APB2 prescaler select CK_AHB/2 */
#define RCU_CFG0_APB2PSC_DIV4          RCU_CFG0_APB2PSC(5)     /*!< APB2 prescaler select CK_AHB/4 */
#define RCU_CFG0_APB2PSC_DIV8          RCU_CFG0_APB2PSC(6)     /*!< APB2 prescaler select CK_AHB/8 */
#define RCU_CFG0_APB2PSC_DIV16         RCU_CFG0_APB2PSC(7)     /*!< APB2 prescaler select CK_AHB/16 */
#define RCU_CFG0_APB1PSC_Pos           8
#define RCU_CFG0_APB1PSC_Msk           _AC(0x00000700,U)       /*!< APB1 prescaler selection */
#define RCU_CFG0_APB1PSC(x)            ((x) << RCU_CFG0_APB1PSC_Pos)
#define RCU_CFG0_APB1PSC_DIV1          RCU_CFG0_APB1PSC(0)     /*!< APB1 prescaler select CK_AHB */
#define RCU_CFG0_APB1PSC_DIV2          RCU_CFG0_APB1PSC(4)     /*!< APB1 prescaler select CK_AHB/2 */
#define RCU_CFG0_APB1PSC_DIV4          RCU_CFG0_APB1PSC(5)     /*!< APB1 prescaler select CK_AHB/4 */
#define RCU_CFG0_APB1PSC_DIV8          RCU_CFG0_APB1PSC(6)     /*!< APB1 prescaler select CK_AHB/8 */
#define RCU_CFG0_APB1PSC_DIV16         RCU_CFG0_APB1PSC(7)     /*!< APB1 prescaler select CK_AHB/16 */
#define RCU_CFG0_AHBPSC_Pos            4
#define RCU_CFG0_AHBPSC_Msk            _AC(0x000000f0,U)       /*!< AHB prescaler selection */
#define RCU_CFG0_AHBPSC(x)             ((x) << RCU_CFG0_AHBPSC_Pos)
#define RCU_CFG0_AHBPSC_DIV1           RCU_CFG0_AHBPSC(0)      /*!< AHB prescaler select CK_SYS */
#define RCU_CFG0_AHBPSC_DIV2           RCU_CFG0_AHBPSC(8)      /*!< AHB prescaler select CK_SYS/2 */
#define RCU_CFG0_AHBPSC_DIV4           RCU_CFG0_AHBPSC(9)      /*!< AHB prescaler select CK_SYS/4 */
#define RCU_CFG0_AHBPSC_DIV8           RCU_CFG0_AHBPSC(10)     /*!< AHB prescaler select CK_SYS/8 */
#define RCU_CFG0_AHBPSC_DIV16          RCU_CFG0_AHBPSC(11)     /*!< AHB prescaler select CK_SYS/16 */
#define RCU_CFG0_AHBPSC_DIV64          RCU_CFG0_AHBPSC(12)     /*!< AHB prescaler select CK_SYS/64 */
#define RCU_CFG0_AHBPSC_DIV128         RCU_CFG0_AHBPSC(13)     /*!< AHB prescaler select CK_SYS/128 */
#define RCU_CFG0_AHBPSC_DIV256         RCU_CFG0_AHBPSC(14)     /*!< AHB prescaler select CK_SYS/256 */
#define RCU_CFG0_AHBPSC_DIV512         RCU_CFG0_AHBPSC(15)     /*!< AHB prescaler select CK_SYS/512 */
#define RCU_CFG0_SCSS_Pos              2
#define RCU_CFG0_SCSS_Msk              _AC(0x0000000c,U)       /*!< system clock switch status */
#define RCU_CFG0_SCSS(x)               ((x) << RCU_CFG0_SCSS_Pos)
#define RCU_CFG0_SCSS_IRC8M            RCU_CFG0_SCSS(0)        /*!< system clock source select IRC8M */
#define RCU_CFG0_SCSS_HXTAL            RCU_CFG0_SCSS(1)        /*!< system clock source select HXTAL */
#define RCU_CFG0_SCSS_PLL              RCU_CFG0_SCSS(2)        /*!< system clock source select PLLP */
#define RCU_CFG0_SCS_Pos               0
#define RCU_CFG0_SCS_Msk               _AC(0x00000003,U)       /*!< system clock switch */
#define RCU_CFG0_SCS(x)                ((x) << RCU_CFG0_SCS_Pos)
#define RCU_CFG0_SCS_IRC8M             RCU_CFG0_SCS(0)         /*!< system clock source select IRC8M */
#define RCU_CFG0_SCS_HXTAL             RCU_CFG0_SCS(1)         /*!< system clock source select HXTAL */
#define RCU_CFG0_SCS_PLL               RCU_CFG0_SCS(2)         /*!< system clock source select PLL */

/* RCU_INT */
#define RCU_INT_CKMIC                  _BIT(23,U)              /*!< HXTAL clock stuck interrupt clear */
#define RCU_INT_PLL2STBIC              _BIT(22,U)              /*!< PLL2 stabilization interrupt clear */
#define RCU_INT_PLL1STBIC              _BIT(21,U)              /*!< PLL1 stabilization interrupt clear */
#define RCU_INT_PLLSTBIC               _BIT(20,U)              /*!< PLL stabilization interrupt clear */
#define RCU_INT_HXTALSTBIC             _BIT(19,U)              /*!< HXTAL stabilization interrupt clear */
#define RCU_INT_IRC8MSTBIC             _BIT(18,U)              /*!< IRC8M stabilization interrupt clear */
#define RCU_INT_LXTALSTBIC             _BIT(17,U)              /*!< LXTAL stabilization interrupt clear */
#define RCU_INT_IRC40KSTBIC            _BIT(16,U)              /*!< IRC40K stabilization interrupt clear */
#define RCU_INT_PLL2STBIE              _BIT(14,U)              /*!< PLL2 stabilization interrupt enable */
#define RCU_INT_PLL1STBIE              _BIT(13,U)              /*!< PLL1 stabilization interrupt enable */
#define RCU_INT_PLLSTBIE               _BIT(12,U)              /*!< PLL stabilization interrupt enable */
#define RCU_INT_HXTALSTBIE             _BIT(11,U)              /*!< HXTAL stabilization interrupt enable */
#define RCU_INT_IRC8MSTBIE             _BIT(10,U)              /*!< IRC8M stabilization interrupt enable */
#define RCU_INT_LXTALSTBIE             _BIT(9,U)               /*!< LXTAL stabilization interrupt enable */
#define RCU_INT_IRC40KSTBIE            _BIT(8,U)               /*!< IRC40K stabilization interrupt enable */
#define RCU_INT_CKMIF                  _BIT(7,U)               /*!< HXTAL clock stuck interrupt flag */
#define RCU_INT_PLL2STBIF              _BIT(6,U)               /*!< PLL2 stabilization interrupt flag */
#define RCU_INT_PLL1STBIF              _BIT(5,U)               /*!< PLL1 stabilization interrupt flag */
#define RCU_INT_PLLSTBIF               _BIT(4,U)               /*!< PLL stabilization interrupt flag */
#define RCU_INT_HXTALSTBIF             _BIT(3,U)               /*!< HXTAL stabilization interrupt flag */
#define RCU_INT_IRC8MSTBIF             _BIT(2,U)               /*!< IRC8M stabilization interrupt flag */
#define RCU_INT_LXTALSTBIF             _BIT(1,U)               /*!< LXTAL stabilization interrupt flag */
#define RCU_INT_IRC40KSTBIF            _BIT(0,U)               /*!< IRC40K stabilization interrupt flag */

/* RCU_APB2RST */
#define RCU_APB2RST_USART0RST          _BIT(14,U)              /*!< USART0 reset */
#define RCU_APB2RST_SPI0RST            _BIT(12,U)              /*!< SPI0 reset */
#define RCU_APB2RST_TIMER0RST          _BIT(11,U)              /*!< TIMER0 reset */
#define RCU_APB2RST_ADC1RST            _BIT(10,U)              /*!< ADC1 reset */
#define RCU_APB2RST_ADC0RST            _BIT(9,U)               /*!< ADC0 reset */
#define RCU_APB2RST_PERST              _BIT(6,U)               /*!< GPIO port E reset */
#define RCU_APB2RST_PDRST              _BIT(5,U)               /*!< GPIO port D reset */
#define RCU_APB2RST_PCRST              _BIT(4,U)               /*!< GPIO port C reset */
#define RCU_APB2RST_PBRST              _BIT(3,U)               /*!< GPIO port B reset */
#define RCU_APB2RST_PARST              _BIT(2,U)               /*!< GPIO port A reset */
#define RCU_APB2RST_AFRST              _BIT(0,U)               /*!< alternate function I/O reset */

/* RCU_APB1RST */
#define RCU_APB1RST_DACRST             _BIT(29,U)              /*!< DAC reset */
#define RCU_APB1RST_PMURST             _BIT(28,U)              /*!< PMU reset */
#define RCU_APB1RST_BKPIRST            _BIT(27,U)              /*!< backup interface reset */
#define RCU_APB1RST_CAN1RST            _BIT(26,U)              /*!< CAN1 reset */
#define RCU_APB1RST_CAN0RST            _BIT(25,U)              /*!< CAN0 reset */
#define RCU_APB1RST_I2C1RST            _BIT(22,U)              /*!< I2C1 reset */
#define RCU_APB1RST_I2C0RST            _BIT(21,U)              /*!< I2C0 reset */
#define RCU_APB1RST_UART4RST           _BIT(20,U)              /*!< UART4 reset */
#define RCU_APB1RST_UART3RST           _BIT(19,U)              /*!< UART3 reset */
#define RCU_APB1RST_USART2RST          _BIT(18,U)              /*!< USART2 reset */
#define RCU_APB1RST_USART1RST          _BIT(17,U)              /*!< USART1 reset */
#define RCU_APB1RST_SPI2RST            _BIT(15,U)              /*!< SPI2 reset */
#define RCU_APB1RST_SPI1RST            _BIT(14,U)              /*!< SPI1 reset */
#define RCU_APB1RST_WWDGTRST           _BIT(11,U)              /*!< WWDGT reset */
#define RCU_APB1RST_TIMER6RST          _BIT(5,U)               /*!< TIMER6 reset */
#define RCU_APB1RST_TIMER5RST          _BIT(4,U)               /*!< TIMER5 reset */
#define RCU_APB1RST_TIMER4RST          _BIT(3,U)               /*!< TIMER4 reset */
#define RCU_APB1RST_TIMER3RST          _BIT(2,U)               /*!< TIMER3 reset */
#define RCU_APB1RST_TIMER2RST          _BIT(1,U)               /*!< TIMER2 reset */
#define RCU_APB1RST_TIMER1RST          _BIT(0,U)               /*!< TIMER1 reset */

/* RCU_AHBEN */
#define RCU_AHBEN_USBFSEN              _BIT(12,U)              /*!< USBFS clock enable */
#define RCU_AHBEN_EXMCEN               _BIT(8,U)               /*!< EXMC clock enable */
#define RCU_AHBEN_CRCEN                _BIT(6,U)               /*!< CRC clock enable */
#define RCU_AHBEN_FMCSPEN              _BIT(4,U)               /*!< FMC clock enable when sleep mode */
#define RCU_AHBEN_SRAMSPEN             _BIT(2,U)               /*!< SRAM clock enable when sleep mode */
#define RCU_AHBEN_DMA1EN               _BIT(1,U)               /*!< DMA1 clock enable */
#define RCU_AHBEN_DMA0EN               _BIT(0,U)               /*!< DMA0 clock enable */

/* RCU_APB2EN */
#define RCU_APB2EN_USART0EN            _BIT(14,U)              /*!< USART0 clock enable */
#define RCU_APB2EN_SPI0EN              _BIT(12,U)              /*!< SPI0 clock enable */
#define RCU_APB2EN_TIMER0EN            _BIT(11,U)              /*!< TIMER0 clock enable */
#define RCU_APB2EN_ADC1EN              _BIT(10,U)              /*!< ADC1 clock enable */
#define RCU_APB2EN_ADC0EN              _BIT(9,U)               /*!< ADC0 clock enable */
#define RCU_APB2EN_PEEN                _BIT(6,U)               /*!< GPIO port E clock enable */
#define RCU_APB2EN_PDEN                _BIT(5,U)               /*!< GPIO port D clock enable */
#define RCU_APB2EN_PCEN                _BIT(4,U)               /*!< GPIO port C clock enable */
#define RCU_APB2EN_PBEN                _BIT(3,U)               /*!< GPIO port B clock enable */
#define RCU_APB2EN_PAEN                _BIT(2,U)               /*!< GPIO port A clock enable */
#define RCU_APB2EN_AFEN                _BIT(0,U)               /*!< alternate function IO clock enable */

/* RCU_APB1EN */
#define RCU_APB1EN_DACEN               _BIT(29,U)              /*!< DAC clock enable */
#define RCU_APB1EN_PMUEN               _BIT(28,U)              /*!< PMU clock enable */
#define RCU_APB1EN_BKPIEN              _BIT(27,U)              /*!< backup interface clock enable */
#define RCU_APB1EN_CAN1EN              _BIT(26,U)              /*!< CAN1 clock enable */
#define RCU_APB1EN_CAN0EN              _BIT(25,U)              /*!< CAN0 clock enable */
#define RCU_APB1EN_I2C1EN              _BIT(22,U)              /*!< I2C1 clock enable */
#define RCU_APB1EN_I2C0EN              _BIT(21,U)              /*!< I2C0 clock enable */
#define RCU_APB1EN_UART4EN             _BIT(20,U)              /*!< UART4 clock enable */
#define RCU_APB1EN_UART3EN             _BIT(19,U)              /*!< UART3 clock enable */
#define RCU_APB1EN_USART2EN            _BIT(18,U)              /*!< USART2 clock enable */
#define RCU_APB1EN_USART1EN            _BIT(17,U)              /*!< USART1 clock enable */
#define RCU_APB1EN_SPI2EN              _BIT(15,U)              /*!< SPI2 clock enable */
#define RCU_APB1EN_SPI1EN              _BIT(14,U)              /*!< SPI1 clock enable */
#define RCU_APB1EN_WWDGTEN             _BIT(11,U)              /*!< WWDGT clock enable */
#define RCU_APB1EN_TIMER6EN            _BIT(5,U)               /*!< TIMER6 clock enable */
#define RCU_APB1EN_TIMER5EN            _BIT(4,U)               /*!< TIMER5 clock enable */
#define RCU_APB1EN_TIMER4EN            _BIT(3,U)               /*!< TIMER4 clock enable */
#define RCU_APB1EN_TIMER3EN            _BIT(2,U)               /*!< TIMER3 clock enable */
#define RCU_APB1EN_TIMER2EN            _BIT(1,U)               /*!< TIMER2 clock enable */
#define RCU_APB1EN_TIMER1EN            _BIT(0,U)               /*!< TIMER1 clock enable */

/* RCU_BDCTL */
#define RCU_BDCTL_BKPRST               _BIT(16,U)              /*!< backup domain reset */
#define RCU_BDCTL_RTCEN                _BIT(15,U)              /*!< RTC clock enable */
#define RCU_BDCTL_RTCSRC_Pos           8
#define RCU_BDCTL_RTCSRC_Msk           _AC(0x00000300,U)       /*!< RTC clock entry selection */
#define RCU_BDCTL_RTCSRC(x)            ((x) << RCU_BDCTL_RTCSRC_Pos)
#define RCU_BDCTL_RTCSRC_NONE          RCU_BDCTL_RTCSRC(0)     /*!< no clock selected */
#define RCU_BDCTL_RTCSRC_LXTAL         RCU_BDCTL_RTCSRC(1)     /*!< RTC source clock select LXTAL  */
#define RCU_BDCTL_RTCSRC_IRC40K        RCU_BDCTL_RTCSRC(2)     /*!< RTC source clock select IRC40K */
#define RCU_BDCTL_RTCSRC_HXTAL_DIV_128 RCU_BDCTL_RTCSRC(3)     /*!< RTC source clock select HXTAL/128 */
#define RCU_BDCTL_LXTALBPS             _BIT(2,U)               /*!< LXTAL bypass mode enable */
#define RCU_BDCTL_LXTALSTB             _BIT(1,U)               /*!< low speed crystal oscillator stabilization flag */
#define RCU_BDCTL_LXTALEN              _BIT(0,U)               /*!< LXTAL enable */

/* RCU_RSTSCK */
#define RCU_RSTSCK_LPRSTF              _BIT(31,U)              /*!< low-power reset flag */
#define RCU_RSTSCK_WWDGTRSTF           _BIT(30,U)              /*!< window watchdog timer reset flag */
#define RCU_RSTSCK_FWDGTRSTF           _BIT(29,U)              /*!< free watchdog timer reset flag */
#define RCU_RSTSCK_SWRSTF              _BIT(28,U)              /*!< software reset flag */
#define RCU_RSTSCK_PORRSTF             _BIT(27,U)              /*!< power reset flag */
#define RCU_RSTSCK_EPRSTF              _BIT(26,U)              /*!< external pin reset flag */
#define RCU_RSTSCK_RSTFC               _BIT(24,U)              /*!< reset flag clear */
#define RCU_RSTSCK_IRC40KSTB           _BIT(1,U)               /*!< IRC40K stabilization flag */
#define RCU_RSTSCK_IRC40KEN            _BIT(0,U)               /*!< IRC40K enable */

/* RCU_AHBRST */
#define RCU_AHBRST_USBFSRST            _BIT(12,U)              /*!< USBFS reset */

/* RCU_CFG1 */
#define RCU_CFG1_I2S2SEL               _BIT(18,U)              /*!< I2S2 clock source selection  */
#define RCU_CFG1_I2S1SEL               _BIT(17,U)              /*!< I2S1 clock source selection */
#define RCU_CFG1_PREDV0SEL             _BIT(16,U)              /*!< PREDV0 input clock source selection */
#define RCU_CFG1_PLL2MF_Pos            12
#define RCU_CFG1_PLL2MF_Msk            _AC(0x0000f000,U)       /*!< PLL2 clock multiplication factor */
#define RCU_CFG1_PLL2MF(x)             ((x) << RCU_CFG1_PLL2MF_Pos)
#define RCU_CFG1_PLL2MF_MUL8           RCU_CFG1_PLL2MF(6)      /*!< PLL2 source clock multiply by 8 */
#define RCU_CFG1_PLL2MF_MUL9           RCU_CFG1_PLL2MF(7)      /*!< PLL2 source clock multiply by 9 */
#define RCU_CFG1_PLL2MF_MUL10          RCU_CFG1_PLL2MF(8)      /*!< PLL2 source clock multiply by 10 */
#define RCU_CFG1_PLL2MF_MUL11          RCU_CFG1_PLL2MF(9)      /*!< PLL2 source clock multiply by 11 */
#define RCU_CFG1_PLL2MF_MUL12          RCU_CFG1_PLL2MF(10)     /*!< PLL2 source clock multiply by 12 */
#define RCU_CFG1_PLL2MF_MUL13          RCU_CFG1_PLL2MF(11)     /*!< PLL2 source clock multiply by 13 */
#define RCU_CFG1_PLL2MF_MUL14          RCU_CFG1_PLL2MF(12)     /*!< PLL2 source clock multiply by 14 */
#define RCU_CFG1_PLL2MF_MUL15          RCU_CFG1_PLL2MF(13)     /*!< PLL2 source clock multiply by 15 */
#define RCU_CFG1_PLL2MF_MUL16          RCU_CFG1_PLL2MF(14)     /*!< PLL2 source clock multiply by 16 */
#define RCU_CFG1_PLL2MF_MUL20          RCU_CFG1_PLL2MF(15)     /*!< PLL2 source clock multiply by 20 */
#define RCU_CFG1_PLL1MF_Pos            8
#define RCU_CFG1_PLL1MF_Msk            _AC(0x00000f00,U)       /*!< PLL1 clock multiplication factor */
#define RCU_CFG1_PLL1MF(x)             ((x) << RCU_CFG1_PLL1MF_Pos)
#define RCU_CFG1_PLL1MF_MUL8           RCU_CFG1_PLL1MF(6)      /*!< PLL1 source clock multiply by 8 */
#define RCU_CFG1_PLL1MF_MUL9           RCU_CFG1_PLL1MF(7)      /*!< PLL1 source clock multiply by 9 */
#define RCU_CFG1_PLL1MF_MUL10          RCU_CFG1_PLL1MF(8)      /*!< PLL1 source clock multiply by 10 */
#define RCU_CFG1_PLL1MF_MUL11          RCU_CFG1_PLL1MF(9)      /*!< PLL1 source clock multiply by 11 */
#define RCU_CFG1_PLL1MF_MUL12          RCU_CFG1_PLL1MF(10)     /*!< PLL1 source clock multiply by 12 */
#define RCU_CFG1_PLL1MF_MUL13          RCU_CFG1_PLL1MF(11)     /*!< PLL1 source clock multiply by 13 */
#define RCU_CFG1_PLL1MF_MUL14          RCU_CFG1_PLL1MF(12)     /*!< PLL1 source clock multiply by 14 */
#define RCU_CFG1_PLL1MF_MUL15          RCU_CFG1_PLL1MF(13)     /*!< PLL1 source clock multiply by 15 */
#define RCU_CFG1_PLL1MF_MUL16          RCU_CFG1_PLL1MF(14)     /*!< PLL1 source clock multiply by 16 */
#define RCU_CFG1_PLL1MF_MUL20          RCU_CFG1_PLL1MF(15)     /*!< PLL1 source clock multiply by 20 */
#define RCU_CFG1_PREDV1_Pos            4
#define RCU_CFG1_PREDV1_Msk            _AC(0x000000f0,U)       /*!< PREDV1 division factor */
#define RCU_CFG1_PREDV1(x)             ((x) << RCU_CFG1_PREDV1_Pos)
#define RCU_CFG1_PREDV1_DIV1           RCU_CFG1_PREDV1(0)      /*!< PREDV1 input source clock not divided */
#define RCU_CFG1_PREDV1_DIV2           RCU_CFG1_PREDV1(1)      /*!< PREDV1 input source clock divided by 2 */
#define RCU_CFG1_PREDV1_DIV3           RCU_CFG1_PREDV1(2)      /*!< PREDV1 input source clock divided by 3 */
#define RCU_CFG1_PREDV1_DIV4           RCU_CFG1_PREDV1(3)      /*!< PREDV1 input source clock divided by 4 */
#define RCU_CFG1_PREDV1_DIV5           RCU_CFG1_PREDV1(4)      /*!< PREDV1 input source clock divided by 5 */
#define RCU_CFG1_PREDV1_DIV6           RCU_CFG1_PREDV1(5)      /*!< PREDV1 input source clock divided by 6 */
#define RCU_CFG1_PREDV1_DIV7           RCU_CFG1_PREDV1(6)      /*!< PREDV1 input source clock divided by 7 */
#define RCU_CFG1_PREDV1_DIV8           RCU_CFG1_PREDV1(7)      /*!< PREDV1 input source clock divided by 8 */
#define RCU_CFG1_PREDV1_DIV9           RCU_CFG1_PREDV1(8)      /*!< PREDV1 input source clock divided by 9 */
#define RCU_CFG1_PREDV1_DIV10          RCU_CFG1_PREDV1(9)      /*!< PREDV1 input source clock divided by 10 */
#define RCU_CFG1_PREDV1_DIV11          RCU_CFG1_PREDV1(10)     /*!< PREDV1 input source clock divided by 11 */
#define RCU_CFG1_PREDV1_DIV12          RCU_CFG1_PREDV1(11)     /*!< PREDV1 input source clock divided by 12 */
#define RCU_CFG1_PREDV1_DIV13          RCU_CFG1_PREDV1(12)     /*!< PREDV1 input source clock divided by 13 */
#define RCU_CFG1_PREDV1_DIV14          RCU_CFG1_PREDV1(13)     /*!< PREDV1 input source clock divided by 14 */
#define RCU_CFG1_PREDV1_DIV15          RCU_CFG1_PREDV1(14)     /*!< PREDV1 input source clock divided by 15 */
#define RCU_CFG1_PREDV1_DIV16          RCU_CFG1_PREDV1(15)     /*!< PREDV1 input source clock divided by 16 */
#define RCU_CFG1_PREDV0_Pos            0
#define RCU_CFG1_PREDV0_Msk            _AC(0x0000000f,U)       /*!< PREDV0 division factor */
#define RCU_CFG1_PREDV0(x)             ((x) << RCU_CFG1_PREDV0_Pos)
#define RCU_CFG1_PREDV0_DIV1           RCU_CFG1_PREDV0(0)      /*!< PREDV0 input source clock not divided */
#define RCU_CFG1_PREDV0_DIV2           RCU_CFG1_PREDV0(1)      /*!< PREDV0 input source clock divided by 2 */
#define RCU_CFG1_PREDV0_DIV3           RCU_CFG1_PREDV0(2)      /*!< PREDV0 input source clock divided by 3 */
#define RCU_CFG1_PREDV0_DIV4           RCU_CFG1_PREDV0(3)      /*!< PREDV0 input source clock divided by 4 */
#define RCU_CFG1_PREDV0_DIV5           RCU_CFG1_PREDV0(4)      /*!< PREDV0 input source clock divided by 5 */
#define RCU_CFG1_PREDV0_DIV6           RCU_CFG1_PREDV0(5)      /*!< PREDV0 input source clock divided by 6 */
#define RCU_CFG1_PREDV0_DIV7           RCU_CFG1_PREDV0(6)      /*!< PREDV0 input source clock divided by 7 */
#define RCU_CFG1_PREDV0_DIV8           RCU_CFG1_PREDV0(7)      /*!< PREDV0 input source clock divided by 8 */
#define RCU_CFG1_PREDV0_DIV9           RCU_CFG1_PREDV0(8)      /*!< PREDV0 input source clock divided by 9 */
#define RCU_CFG1_PREDV0_DIV10          RCU_CFG1_PREDV0(9)      /*!< PREDV0 input source clock divided by 10 */
#define RCU_CFG1_PREDV0_DIV11          RCU_CFG1_PREDV0(10)     /*!< PREDV0 input source clock divided by 11 */
#define RCU_CFG1_PREDV0_DIV12          RCU_CFG1_PREDV0(11)     /*!< PREDV0 input source clock divided by 12 */
#define RCU_CFG1_PREDV0_DIV13          RCU_CFG1_PREDV0(12)     /*!< PREDV0 input source clock divided by 13 */
#define RCU_CFG1_PREDV0_DIV14          RCU_CFG1_PREDV0(13)     /*!< PREDV0 input source clock divided by 14 */
#define RCU_CFG1_PREDV0_DIV15          RCU_CFG1_PREDV0(14)     /*!< PREDV0 input source clock divided by 15 */
#define RCU_CFG1_PREDV0_DIV16          RCU_CFG1_PREDV0(15)     /*!< PREDV0 input source clock divided by 16 */

/* RCU_DSV */
#define RCU_DSV_DSLPVS_Pos             0
#define RCU_DSV_DSLPVS_Msk             _AC(0x00000003,U)       /*!< deep-sleep mode voltage select */
#define RCU_DSV_DSLPVS(x)              ((x) << RCU_DSV_DSLPVS_Pos)
#define RCU_DSV_DSLPVS_1_2             RCU_DSV_DSLPVS(0)       /*!< core voltage is 1.2V in deep-sleep mode */
#define RCU_DSV_DSLPVS_1_1             RCU_DSV_DSLPVS(1)       /*!< core voltage is 1.1V in deep-sleep mode */
#define RCU_DSV_DSLPVS_1_0             RCU_DSV_DSLPVS(2)       /*!< core voltage is 1.0V in deep-sleep mode */
#define RCU_DSV_DSLPVS_0_9             RCU_DSV_DSLPVS(3)       /*!< core voltage is 0.9V in deep-sleep mode */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_rcu {
	volatile uint32_t CTL;
	volatile uint32_t CFG0;
	volatile uint32_t INT;
	volatile uint32_t APB2RST;
	volatile uint32_t APB1RST;
	volatile uint32_t AHBEN;
	volatile uint32_t APB2EN;
	volatile uint32_t APB1EN;
	volatile uint32_t BDCTL;
	volatile uint32_t RSTSCK;
	volatile uint32_t AHBRST;
	volatile uint32_t CFG1;
	uint32_t reserved1;
	volatile uint32_t DSV;
};

static struct gd32vf103_rcu *const RCU = (struct gd32vf103_rcu *)RCU_BASE;

#endif
#endif
