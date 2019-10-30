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
#ifndef GD32VF103_TIMER_H
#define GD32VF103_TIMER_H

#include "gd32vf103.h"

#define TIMER0_BASE _AC(0x40012C00,UL)  /*!< TIMER0 base address */
#define TIMER1_BASE _AC(0x40000000,UL)  /*!< TIMER1 base address */
#define TIMER2_BASE _AC(0x40000400,UL)  /*!< TIMER2 base address */
#define TIMER3_BASE _AC(0x40000800,UL)  /*!< TIMER3 base address */
#define TIMER4_BASE _AC(0x40000C00,UL)  /*!< TIMER4 base address */
#define TIMER5_BASE _AC(0x40001000,UL)  /*!< TIMER5 base address */
#define TIMER6_BASE _AC(0x40001400,UL)  /*!< TIMER6 base address */

/* register definitions */
#define TIMER_CTL0      _AC(0x00,UL)  /*!< TIMER control register 0 */
#define TIMER_CTL1      _AC(0x04,UL)  /*!< TIMER control register 1 */
#define TIMER_SMCFG     _AC(0x08,UL)  /*!< TIMER slave mode configuration register */
#define TIMER_DMAINTEN  _AC(0x0C,UL)  /*!< TIMER DMA and interrupt enable register */
#define TIMER_INTF      _AC(0x10,UL)  /*!< TIMER interrupt flag register */
#define TIMER_SWEVG     _AC(0x14,UL)  /*!< TIMER software event generation register */
#define TIMER_CHCTL0    _AC(0x18,UL)  /*!< TIMER channel control register 0 */
#define TIMER_CHCTL1    _AC(0x1C,UL)  /*!< TIMER channel control register 1 */
#define TIMER_CHCTL2    _AC(0x20,UL)  /*!< TIMER channel control register 2 */
#define TIMER_CNT       _AC(0x24,UL)  /*!< TIMER counter register */
#define TIMER_PSC       _AC(0x28,UL)  /*!< TIMER prescaler register */
#define TIMER_CAR       _AC(0x2C,UL)  /*!< TIMER counter auto reload register */
#define TIMER_CREP      _AC(0x30,UL)  /*!< TIMER counter repetition register */
#define TIMER_CH0CV     _AC(0x34,UL)  /*!< TIMER channel 0 capture/compare value register */
#define TIMER_CH1CV     _AC(0x38,UL)  /*!< TIMER channel 1 capture/compare value register */
#define TIMER_CH2CV     _AC(0x3C,UL)  /*!< TIMER channel 2 capture/compare value register */
#define TIMER_CH3CV     _AC(0x40,UL)  /*!< TIMER channel 3 capture/compare value register */
#define TIMER_CCHP      _AC(0x44,UL)  /*!< TIMER channel complementary protection register */
#define TIMER_DMACFG    _AC(0x48,UL)  /*!< TIMER DMA configuration register */
#define TIMER_DMATB     _AC(0x4C,UL)  /*!< TIMER DMA transfer buffer register */

/* TIMER_CTL0 */
#define TIMER_CTL0_CKDIV_Pos           8
#define TIMER_CTL0_CKDIV_Msk           _AC(0x00000300,U)       /*!< clock division */
#define TIMER_CTL0_CKDIV(x)            ((x) << TIMER_CTL0_CKDIV_Pos)
#define TIMER_CTL0_CKDIV_DIV1          TIMER_CTL0_CKDIV(0)     /*!< clock division value is 1, fDTS=fTIMER_CK   */
#define TIMER_CTL0_CKDIV_DIV2          TIMER_CTL0_CKDIV(1)     /*!< clock division value is 2, fDTS=fTIMER_CK/2 */
#define TIMER_CTL0_CKDIV_DIV4          TIMER_CTL0_CKDIV(2)     /*!< clock division value is 4, fDTS=fTIMER_CK/4 */
#define TIMER_CTL0_ARSE                _BIT(7,U)               /*!< auto-reload shadow enable */
#define TIMER_CTL0_CAM_Pos             5
#define TIMER_CTL0_CAM_Msk             _AC(0x00000060,U)       /*!< center-aligned mode selection */
#define TIMER_CTL0_CAM(x)              ((x) << TIMER_CTL0_CAM_Pos)
#define TIMER_CTL0_CAM_EDGE            TIMER_CTL0_CAM(0)       /*!< edge-aligned mode */
#define TIMER_CTL0_CAM_CENTER_DOWN     TIMER_CTL0_CAM(1)       /*!< center-aligned and counting down assert mode */
#define TIMER_CTL0_CAM_CENTER_UP       TIMER_CTL0_CAM(2)       /*!< center-aligned and counting up assert mode */
#define TIMER_CTL0_CAM_CENTER_BOTH     TIMER_CTL0_CAM(3)       /*!< center-aligned and counting up/down assert mode */
#define TIMER_CTL0_DIR                 _BIT(4,U)               /*!< timer counter direction */
#define TIMER_CTL0_SPM                 _BIT(3,U)               /*!< single pulse mode */
#define TIMER_CTL0_UPS                 _BIT(2,U)               /*!< update source */
#define TIMER_CTL0_UPDIS               _BIT(1,U)               /*!< update disable */
#define TIMER_CTL0_CEN                 _BIT(0,U)               /*!< TIMER counter enable */

/* TIMER_CTL1 */
#define TIMER_CTL1_ISO3                _BIT(14,U)              /*!< idle state of channel 3 output */
#define TIMER_CTL1_ISO2N               _BIT(13,U)              /*!< idle state of channel 2 complementary output */
#define TIMER_CTL1_ISO2                _BIT(12,U)              /*!< idle state of channel 2 output */
#define TIMER_CTL1_ISO1N               _BIT(11,U)              /*!< idle state of channel 1 complementary output */
#define TIMER_CTL1_ISO1                _BIT(10,U)              /*!< idle state of channel 1 output */
#define TIMER_CTL1_ISO0N               _BIT(9,U)               /*!< idle state of channel 0 complementary output */
#define TIMER_CTL1_ISO0                _BIT(8,U)               /*!< idle state of channel 0 output */
#define TIMER_CTL1_TI0S                _BIT(7,U)               /*!< channel 0 trigger input selection(hall mode selection) */
#define TIMER_CTL1_MMC_Pos             4
#define TIMER_CTL1_MMC_Msk             _AC(0x00000070,U)       /*!< master mode control */
#define TIMER_CTL1_MMC(x)              ((x) << TIMER_CTL1_MMC_Pos)
#define TIMER_CTL1_MMC_RESET           TIMER_CTL1_MMC(0)       /*!< the UPG bit as trigger output */
#define TIMER_CTL1_MMC_ENABLE          TIMER_CTL1_MMC(1)       /*!< the counter enable signal TIMER_CTL0_CEN as trigger output */
#define TIMER_CTL1_MMC_UPDATE          TIMER_CTL1_MMC(2)       /*!< update event as trigger output */
#define TIMER_CTL1_MMC_CH0             TIMER_CTL1_MMC(3)       /*!< a capture or a compare match occurred in channel 0 as trigger output TRGO */
#define TIMER_CTL1_MMC_O0CPRE          TIMER_CTL1_MMC(4)       /*!< O0CPRE as trigger output */
#define TIMER_CTL1_MMC_O1CPRE          TIMER_CTL1_MMC(5)       /*!< O1CPRE as trigger output */
#define TIMER_CTL1_MMC_O2CPRE          TIMER_CTL1_MMC(6)       /*!< O2CPRE as trigger output */
#define TIMER_CTL1_MMC_O3CPRE          TIMER_CTL1_MMC(7)       /*!< O3CPRE as trigger output */
#define TIMER_CTL1_DMAS                _BIT(3,U)               /*!< DMA request source selection */
#define TIMER_CTL1_CCUC                _BIT(2,U)               /*!< commutation control shadow register update control */
#define TIMER_CTL1_CCSE                _BIT(0,U)               /*!< commutation control shadow enable */

/* TIMER_SMCFG */
#define TIMER_SMCFG_ETP                _BIT(15,U)              /*!< external trigger polarity */
#define TIMER_SMCFG_SMC1               _BIT(14,U)              /*!< part of SMC for enable external clock mode 1 */
#define TIMER_SMCFG_ETPSC_Pos          12
#define TIMER_SMCFG_ETPSC_Msk          _AC(0x00003000,U)       /*!< external trigger prescaler */
#define TIMER_SMCFG_ETPSC(x)           ((x) << TIMER_SMCFG_ETPSC_Pos)
#define TIMER_SMCFG_ETPSC_OFF          TIMER_SMCFG_ETPSC(0)    /*!< not divided */
#define TIMER_SMCFG_ETPSC_DIV2         TIMER_SMCFG_ETPSC(1)    /*!< divided by 2 */
#define TIMER_SMCFG_ETPSC_DIV4         TIMER_SMCFG_ETPSC(2)    /*!< divided by 4 */
#define TIMER_SMCFG_ETPSC_DIV8         TIMER_SMCFG_ETPSC(3)    /*!< divided by 8 */
#define TIMER_SMCFG_ETFC_Pos           8
#define TIMER_SMCFG_ETFC_Msk           _AC(0x00000f00,U)       /*!< external trigger filter control */
#define TIMER_SMCFG_ETFC(x)            ((x) << TIMER_SMCFG_ETFC_Pos)
#define TIMER_SMCFG_ETFC_OFF           TIMER_SMCFG_ETFC(0)
#define TIMER_SMCFG_ETFC_DIV1_N2       TIMER_SMCFG_ETFC(1)
#define TIMER_SMCFG_ETFC_DIV1_N4       TIMER_SMCFG_ETFC(2)
#define TIMER_SMCFG_ETFC_DIV1_N8       TIMER_SMCFG_ETFC(3)
#define TIMER_SMCFG_ETFC_DIV2_N6       TIMER_SMCFG_ETFC(4)
#define TIMER_SMCFG_ETFC_DIV2_N8       TIMER_SMCFG_ETFC(5)
#define TIMER_SMCFG_ETFC_DIV4_N6       TIMER_SMCFG_ETFC(6)
#define TIMER_SMCFG_ETFC_DIV4_N8       TIMER_SMCFG_ETFC(7)
#define TIMER_SMCFG_ETFC_DIV8_N6       TIMER_SMCFG_ETFC(8)
#define TIMER_SMCFG_ETFC_DIV8_N8       TIMER_SMCFG_ETFC(9)
#define TIMER_SMCFG_ETFC_DIV16_N5      TIMER_SMCFG_ETFC(10)
#define TIMER_SMCFG_ETFC_DIV16_N6      TIMER_SMCFG_ETFC(11)
#define TIMER_SMCFG_ETFC_DIV16_N8      TIMER_SMCFG_ETFC(12)
#define TIMER_SMCFG_ETFC_DIV32_N5      TIMER_SMCFG_ETFC(13)
#define TIMER_SMCFG_ETFC_DIV32_N6      TIMER_SMCFG_ETFC(14)
#define TIMER_SMCFG_ETFC_DIV32_N8      TIMER_SMCFG_ETFC(15)
#define TIMER_SMCFG_MSM                _BIT(7,U)               /*!< master-slave mode */
#define TIMER_SMCFG_TRGS_Pos           4
#define TIMER_SMCFG_TRGS_Msk           _AC(0x00000070,U)       /*!< trigger selection */
#define TIMER_SMCFG_TRGS(x)            ((x) << TIMER_SMCFG_TRGS_Pos)
#define TIMER_SMCFG_TRGS_ITI0          TIMER_SMCFG_TRGS(0)     /*!< internal trigger 0 */
#define TIMER_SMCFG_TRGS_ITI1          TIMER_SMCFG_TRGS(1)     /*!< internal trigger 1 */
#define TIMER_SMCFG_TRGS_ITI2          TIMER_SMCFG_TRGS(2)     /*!< internal trigger 2 */
#define TIMER_SMCFG_TRGS_ITI3          TIMER_SMCFG_TRGS(3)     /*!< internal trigger 3 */
#define TIMER_SMCFG_TRGS_CI0F_ED       TIMER_SMCFG_TRGS(4)     /*!< TI0 Edge Detector */
#define TIMER_SMCFG_TRGS_CI0FE0        TIMER_SMCFG_TRGS(5)     /*!< filtered TIMER input 0 */
#define TIMER_SMCFG_TRGS_CI1FE1        TIMER_SMCFG_TRGS(6)     /*!< filtered TIMER input 1 */
#define TIMER_SMCFG_TRGS_ETIFP         TIMER_SMCFG_TRGS(7)     /*!< filtered external trigger input */
#define TIMER_SMCFG_SMC_Pos            0
#define TIMER_SMCFG_SMC_Msk            _AC(0x00000007,U)       /*!< slave mode control */
#define TIMER_SMCFG_SMC(x)             ((x) << TIMER_SMCFG_SMC_Pos)
#define TIMER_SMCFG_SMC_DISABLE        TIMER_SMCFG_SMC(0)      /*!< slave mode disable */
#define TIMER_SMCFG_SMC_ENCODER0       TIMER_SMCFG_SMC(1)      /*!< encoder mode 0 */
#define TIMER_SMCFG_SMC_ENCODER1       TIMER_SMCFG_SMC(2)      /*!< encoder mode 1 */
#define TIMER_SMCFG_SMC_ENCODER2       TIMER_SMCFG_SMC(3)      /*!< encoder mode 2 */
#define TIMER_SMCFG_SMC_RESTART        TIMER_SMCFG_SMC(4)      /*!< restart mode */
#define TIMER_SMCFG_SMC_PAUSE          TIMER_SMCFG_SMC(5)      /*!< pause mode */
#define TIMER_SMCFG_SMC_EVENT          TIMER_SMCFG_SMC(6)      /*!< event mode */
#define TIMER_SMCFG_SMC_EXTERNAL0      TIMER_SMCFG_SMC(7)      /*!< external clock mode 0 */

/* TIMER_DMAINTEN */
#define TIMER_DMAINTEN_TRGDEN          _BIT(14,U)              /*!< trigger DMA request enable */
#define TIMER_DMAINTEN_CMTDEN          _BIT(13,U)              /*!< commutation DMA request enable */
#define TIMER_DMAINTEN_CH3DEN          _BIT(12,U)              /*!< channel 3 capture/compare DMA request enable */
#define TIMER_DMAINTEN_CH2DEN          _BIT(11,U)              /*!< channel 2 capture/compare DMA request enable */
#define TIMER_DMAINTEN_CH1DEN          _BIT(10,U)              /*!< channel 1 capture/compare DMA request enable */
#define TIMER_DMAINTEN_CH0DEN          _BIT(9,U)               /*!< channel 0 capture/compare DMA request enable */
#define TIMER_DMAINTEN_UPDEN           _BIT(8,U)               /*!< update DMA request enable */
#define TIMER_DMAINTEN_BRKIE           _BIT(7,U)               /*!< break interrupt enable */
#define TIMER_DMAINTEN_TRGIE           _BIT(6,U)               /*!< trigger interrupt enable */
#define TIMER_DMAINTEN_CMTIE           _BIT(5,U)               /*!< commutation interrupt request enable */
#define TIMER_DMAINTEN_CH3IE           _BIT(4,U)               /*!< channel 3 capture/compare interrupt enable */
#define TIMER_DMAINTEN_CH2IE           _BIT(3,U)               /*!< channel 2 capture/compare interrupt enable */
#define TIMER_DMAINTEN_CH1IE           _BIT(2,U)               /*!< channel 1 capture/compare interrupt enable */
#define TIMER_DMAINTEN_CH0IE           _BIT(1,U)               /*!< channel 0 capture/compare interrupt enable */
#define TIMER_DMAINTEN_UPIE            _BIT(0,U)               /*!< update interrupt enable */

/* TIMER_INTF */
#define TIMER_INTF_CH3OF               _BIT(12,U)              /*!< channel 3 over capture flag */
#define TIMER_INTF_CH2OF               _BIT(11,U)              /*!< channel 2 over capture flag */
#define TIMER_INTF_CH1OF               _BIT(10,U)              /*!< channel 1 over capture flag */
#define TIMER_INTF_CH0OF               _BIT(9,U)               /*!< channel 0 over capture flag */
#define TIMER_INTF_BRKIF               _BIT(7,U)               /*!< break interrupt flag */
#define TIMER_INTF_TRGIF               _BIT(6,U)               /*!< trigger interrupt flag */
#define TIMER_INTF_CMTIF               _BIT(5,U)               /*!< channel commutation interrupt flag */
#define TIMER_INTF_CH3IF               _BIT(4,U)               /*!< channel 3 capture/compare interrupt flag */
#define TIMER_INTF_CH2IF               _BIT(3,U)               /*!< channel 2 capture/compare interrupt flag */
#define TIMER_INTF_CH1IF               _BIT(2,U)               /*!< channel 1 capture/compare interrupt flag */
#define TIMER_INTF_CH0IF               _BIT(1,U)               /*!< channel 0 capture/compare interrupt flag */
#define TIMER_INTF_UPIF                _BIT(0,U)               /*!< update interrupt flag */

/* TIMER_SWEVG */
#define TIMER_SWEVG_BRKG               _BIT(7,U)               /*!< break event generation */
#define TIMER_SWEVG_TRGG               _BIT(6,U)               /*!< trigger event generation */
#define TIMER_SWEVG_CMTG               _BIT(5,U)               /*!< channel commutation event generation */
#define TIMER_SWEVG_CH3G               _BIT(4,U)               /*!< channel 3 capture or compare event generation */
#define TIMER_SWEVG_CH2G               _BIT(3,U)               /*!< channel 2 capture or compare event generation */
#define TIMER_SWEVG_CH1G               _BIT(2,U)               /*!< channel 1 capture or compare event generation */
#define TIMER_SWEVG_CH0G               _BIT(1,U)               /*!< channel 0 capture or compare event generation */
#define TIMER_SWEVG_UPG                _BIT(0,U)               /*!< update event generate */

/* TIMER_CHCTL0 */
/* output compare mode */
#define TIMER_CHCTL0_CH1COMCEN         _BIT(15,U)              /*!< channel 1 output compare clear enable */
#define TIMER_CHCTL0_CH1COMCTL_Pos     12
#define TIMER_CHCTL0_CH1COMCTL_Msk     _AC(0x00007000,U)       /*!< channel 1 output compare control  */
#define TIMER_CHCTL0_CH1COMCTL(x)      ((x) << TIMER_CHCTL0_CH1COMCTL_Pos)
#define TIMER_CHCTL0_CH1COMSEN         _BIT(11,U)              /*!< channel 1 output compare shadow enable */
#define TIMER_CHCTL0_CH1COMFEN         _BIT(10,U)              /*!< channel 1 output compare fast enable */
#define TIMER_CHCTL0_CH1MS_Pos         8
#define TIMER_CHCTL0_CH1MS_Msk         _AC(0x00000300,U)       /*!< channel 1 mode selection */
#define TIMER_CHCTL0_CH1MS(x)          ((x) << TIMER_CHCTL0_CH1MS_Pos)
#define TIMER_CHCTL0_CH0COMCEN         _BIT(7,U)               /*!< channel 0 output compare clear enable */
#define TIMER_CHCTL0_CH0COMCTL_Pos     4
#define TIMER_CHCTL0_CH0COMCTL_Msk     _AC(0x00000070,U)       /*!< channel 0 output compare control  */
#define TIMER_CHCTL0_CH0COMCTL(x)      ((x) << TIMER_CHCTL0_CH0COMCTL_Pos)
#define TIMER_CHCTL0_CH0COMSEN         _BIT(3,U)               /*!< channel 0 output compare shadow enable */
#define TIMER_CHCTL0_CH0COMFEN         _BIT(2,U)               /*!< channel 0 output compare fast enable */
#define TIMER_CHCTL0_CH0MS_Pos         0
#define TIMER_CHCTL0_CH0MS_Msk         _AC(0x00000003,U)       /*!< channel 0 mode selection */
#define TIMER_CHCTL0_CH0MS(x)          ((x) << TIMER_CHCTL0_CH0MS_Pos)
/* input capture mode */
#define TIMER_CHCTL0_CH1CAPFLT_Pos     12
#define TIMER_CHCTL0_CH1CAPFLT_Msk     _AC(0x0000f000,U)       /*!< channel 1 input capture filter control */
#define TIMER_CHCTL0_CH1CAPFLT(x)      ((x) << TIMER_CHCTL0_CH1CAPFLT_Pos)
#define TIMER_CHCTL0_CH1CAPPSC_Pos     10
#define TIMER_CHCTL0_CH1CAPPSC_Msk     _AC(0x00000c00,U)       /*!< channel 1 input capture prescaler */
#define TIMER_CHCTL0_CH1CAPPSC(x)      ((x) << TIMER_CHCTL0_CH1CAPPSC_Pos)
#define TIMER_CHCTL0_CH0CAPFLT_Pos     4
#define TIMER_CHCTL0_CH0CAPFLT_Msk     _AC(0x000000f0,U)       /*!< channel 0 input capture filter control */
#define TIMER_CHCTL0_CH0CAPFLT(x)      ((x) << TIMER_CHCTL0_CH0CAPFLT_Pos)
#define TIMER_CHCTL0_CH0CAPPSC_Pos     2
#define TIMER_CHCTL0_CH0CAPPSC_Msk     _AC(0x0000000c,U)       /*!< channel 0 input capture prescaler */
#define TIMER_CHCTL0_CH0CAPPSC(x)      ((x) << TIMER_CHCTL0_CH0CAPPSC_Pos)

/* TIMER_CHCTL1 */
/* output compare mode */
#define TIMER_CHCTL1_CH3COMCEN         _BIT(15,U)              /*!< channel 3 output compare clear enable */
#define TIMER_CHCTL1_CH3COMCTL_Pos     12
#define TIMER_CHCTL1_CH3COMCTL_Msk     _AC(0x00007000,U)       /*!< channel 3 output compare control */
#define TIMER_CHCTL1_CH3COMCTL(x)      ((x) << TIMER_CHCTL1_CH3COMCTL_Pos)
#define TIMER_CHCTL1_CH3COMSEN         _BIT(11,U)              /*!< channel 3 output compare shadow enable */
#define TIMER_CHCTL1_CH3COMFEN         _BIT(10,U)              /*!< channel 3 output compare fast enable */
#define TIMER_CHCTL1_CH3MS_Pos         8
#define TIMER_CHCTL1_CH3MS_Msk         _AC(0x00000300,U)       /*!< channel 3 mode selection */
#define TIMER_CHCTL1_CH3MS(x)          ((x) << TIMER_CHCTL1_CH3MS_Pos)
#define TIMER_CHCTL1_CH2COMCEN         _BIT(7,U)               /*!< channel 2 output compare clear enable */
#define TIMER_CHCTL1_CH2COMCTL_Pos     4
#define TIMER_CHCTL1_CH2COMCTL_Msk     _AC(0x00000070,U)       /*!< channel 2 output compare control */
#define TIMER_CHCTL1_CH2COMCTL(x)      ((x) << TIMER_CHCTL1_CH2COMCTL_Pos)
#define TIMER_CHCTL1_CH2COMSEN         _BIT(3,U)               /*!< channel 2 output compare shadow enable */
#define TIMER_CHCTL1_CH2COMFEN         _BIT(2,U)               /*!< channel 2 output compare fast enable */
#define TIMER_CHCTL1_CH2MS_Pos         0
#define TIMER_CHCTL1_CH2MS_Msk         _AC(0x00000003,U)       /*!< channel 2 mode selection */
#define TIMER_CHCTL1_CH2MS(x)          ((x) << TIMER_CHCTL1_CH2MS_Pos)
/* input capture mode */
#define TIMER_CHCTL1_CH3CAPFLT_Pos     12
#define TIMER_CHCTL1_CH3CAPFLT_Msk     _AC(0x0000f000,U)       /*!< channel 3 input capture filter control */
#define TIMER_CHCTL1_CH3CAPFLT(x)      ((x) << TIMER_CHCTL1_CH3CAPFLT_Pos)
#define TIMER_CHCTL1_CH3CAPPSC_Pos     10
#define TIMER_CHCTL1_CH3CAPPSC_Msk     _AC(0x00000c00,U)       /*!< channel 3 input capture prescaler */
#define TIMER_CHCTL1_CH3CAPPSC(x)      ((x) << TIMER_CHCTL1_CH3CAPPSC_Pos)
#define TIMER_CHCTL1_CH2CAPFLT_Pos     4
#define TIMER_CHCTL1_CH2CAPFLT_Msk     _AC(0x000000f0,U)       /*!< channel 2 input capture filter control */
#define TIMER_CHCTL1_CH2CAPFLT(x)      ((x) << TIMER_CHCTL1_CH2CAPFLT_Pos)
#define TIMER_CHCTL1_CH2CAPPSC_Pos     2
#define TIMER_CHCTL1_CH2CAPPSC_Msk     _AC(0x0000000c,U)       /*!< channel 2 input capture prescaler */
#define TIMER_CHCTL1_CH2CAPPSC(x)      ((x) << TIMER_CHCTL1_CH2CAPPSC_Pos)

/* TIMER_CHCTL2 */
#define TIMER_CHCTL2_CH3P              _BIT(13,U)              /*!< channel 3 capture/compare function polarity */
#define TIMER_CHCTL2_CH3EN             _BIT(12,U)              /*!< channel 3 capture/compare function enable  */
#define TIMER_CHCTL2_CH2NP             _BIT(11,U)              /*!< channel 2 complementary output polarity */
#define TIMER_CHCTL2_CH2NEN            _BIT(10,U)              /*!< channel 2 complementary output enable */
#define TIMER_CHCTL2_CH2P              _BIT(9,U)               /*!< channel 2 capture/compare function polarity */
#define TIMER_CHCTL2_CH2EN             _BIT(8,U)               /*!< channel 2 capture/compare function enable  */
#define TIMER_CHCTL2_CH1NP             _BIT(7,U)               /*!< channel 1 complementary output polarity */
#define TIMER_CHCTL2_CH1NEN            _BIT(6,U)               /*!< channel 1 complementary output enable */
#define TIMER_CHCTL2_CH1P              _BIT(5,U)               /*!< channel 1 capture/compare function polarity */
#define TIMER_CHCTL2_CH1EN             _BIT(4,U)               /*!< channel 1 capture/compare function enable  */
#define TIMER_CHCTL2_CH0NP             _BIT(3,U)               /*!< channel 0 complementary output polarity */
#define TIMER_CHCTL2_CH0NEN            _BIT(2,U)               /*!< channel 0 complementary output enable */
#define TIMER_CHCTL2_CH0P              _BIT(1,U)               /*!< channel 0 capture/compare function polarity */
#define TIMER_CHCTL2_CH0EN             _BIT(0,U)               /*!< channel 0 capture/compare function enable */

/* TIMER_CNT */
#define TIMER_CNT_CNT_Pos              0
#define TIMER_CNT_CNT_Msk              _AC(0x0000ffff,U)       /*!< 16 bit timer counter */
#define TIMER_CNT_CNT(x)               ((x) << TIMER_CNT_CNT_Pos)

/* TIMER_PSC */
#define TIMER_PSC_PSC_Pos              0
#define TIMER_PSC_PSC_Msk              _AC(0x0000ffff,U)       /*!< prescaler value of the counter clock */
#define TIMER_PSC_PSC(x)               ((x) << TIMER_PSC_PSC_Pos)

/* TIMER_CAR */
#define TIMER_CAR_CARL_Pos             0
#define TIMER_CAR_CARL_Msk             _AC(0x0000ffff,U)       /*!< 16 bit counter auto reload value */
#define TIMER_CAR_CARL(x)              ((x) << TIMER_CAR_CARL_Pos)

/* TIMER_CREP */
#define TIMER_CREP_CREP_Pos            0
#define TIMER_CREP_CREP_Msk            _AC(0x000000ff,U)       /*!< counter repetition value */
#define TIMER_CREP_CREP(x)             ((x) << TIMER_CREP_CREP_Pos)

/* TIMER_CH0CV */
#define TIMER_CH0CV_CH0VAL_Pos         0
#define TIMER_CH0CV_CH0VAL_Msk         _AC(0x0000ffff,U)       /*!< 16 bit capture/compare value of channel 0 */
#define TIMER_CH0CV_CH0VAL(x)          ((x) << TIMER_CH0CV_CH0VAL_Pos)

/* TIMER_CH1CV */
#define TIMER_CH1CV_CH1VAL_Pos         0
#define TIMER_CH1CV_CH1VAL_Msk         _AC(0x0000ffff,U)       /*!< 16 bit capture/compare value of channel 1 */
#define TIMER_CH1CV_CH1VAL(x)          ((x) << TIMER_CH1CV_CH1VAL_Pos)

/* TIMER_CH2CV */
#define TIMER_CH2CV_CH2VAL_Pos         0
#define TIMER_CH2CV_CH2VAL_Msk         _AC(0x0000ffff,U)       /*!< 16 bit capture/compare value of channel 2 */
#define TIMER_CH2CV_CH2VAL(x)          ((x) << TIMER_CH2CV_CH2VAL_Pos)

/* TIMER_CH3CV */
#define TIMER_CH3CV_CH3VAL_Pos         0
#define TIMER_CH3CV_CH3VAL_Msk         _AC(0x0000ffff,U)       /*!< 16 bit capture/compare value of channel 3 */
#define TIMER_CH3CV_CH3VAL(x)          ((x) << TIMER_CH3CV_CH3VAL_Pos)

/* TIMER_CCHP */
#define TIMER_CCHP_POEN                _BIT(15,U)              /*!< primary output enable */
#define TIMER_CCHP_OAEN                _BIT(14,U)              /*!< output automatic enable */
#define TIMER_CCHP_BRKP                _BIT(13,U)              /*!< break polarity */
#define TIMER_CCHP_BRKEN               _BIT(12,U)              /*!< break enable */
#define TIMER_CCHP_ROS                 _BIT(11,U)              /*!< run mode off-state configure */
#define TIMER_CCHP_IOS                 _BIT(10,U)              /*!< idle mode off-state configure */
#define TIMER_CCHP_PROT_Pos            8
#define TIMER_CCHP_PROT_Msk            _AC(0x00000300,U)       /*!< complementary register protect control */
#define TIMER_CCHP_PROT(x)             ((x) << TIMER_CCHP_PROT_Pos)
#define TIMER_CCHP_PROT_OFF            TIMER_CCHP_PROT(0)      /*!< protect disable */
#define TIMER_CCHP_PROT_0              TIMER_CCHP_PROT(1)      /*!< PROT mode 0 */
#define TIMER_CCHP_PROT_1              TIMER_CCHP_PROT(2)      /*!< PROT mode 1 */
#define TIMER_CCHP_PROT_2              TIMER_CCHP_PROT(3)      /*!< PROT mode 2 */
#define TIMER_CCHP_DTCFG_Pos           0
#define TIMER_CCHP_DTCFG_Msk           _AC(0x000000ff,U)       /*!< dead time configure */
#define TIMER_CCHP_DTCFG(x)            ((x) << TIMER_CCHP_DTCFG_Pos)

/* TIMER_DMACFG */
#define TIMER_DMACFG_DMATC_Pos         8
#define TIMER_DMACFG_DMATC_Msk         _AC(0x00000f00,U)       /*!< DMA transfer count */
#define TIMER_DMACFG_DMATC(x)          ((x) << TIMER_DMACFG_DMATC_Pos)
#define TIMER_DMACFG_DMATC_1TRANSFER   TIMER_DMACFG_DMATC(0)   /*!< DMA transfer 1 time */
#define TIMER_DMACFG_DMATC_2TRANSFER   TIMER_DMACFG_DMATC(1)   /*!< DMA transfer 2 times */
#define TIMER_DMACFG_DMATC_3TRANSFER   TIMER_DMACFG_DMATC(2)   /*!< DMA transfer 3 times */
#define TIMER_DMACFG_DMATC_4TRANSFER   TIMER_DMACFG_DMATC(3)   /*!< DMA transfer 4 times */
#define TIMER_DMACFG_DMATC_5TRANSFER   TIMER_DMACFG_DMATC(4)   /*!< DMA transfer 5 times */
#define TIMER_DMACFG_DMATC_6TRANSFER   TIMER_DMACFG_DMATC(5)   /*!< DMA transfer 6 times */
#define TIMER_DMACFG_DMATC_7TRANSFER   TIMER_DMACFG_DMATC(6)   /*!< DMA transfer 7 times */
#define TIMER_DMACFG_DMATC_8TRANSFER   TIMER_DMACFG_DMATC(7)   /*!< DMA transfer 8 times */
#define TIMER_DMACFG_DMATC_9TRANSFER   TIMER_DMACFG_DMATC(8)   /*!< DMA transfer 9 times */
#define TIMER_DMACFG_DMATC_10TRANSFER  TIMER_DMACFG_DMATC(9)   /*!< DMA transfer 10 times */
#define TIMER_DMACFG_DMATC_11TRANSFER  TIMER_DMACFG_DMATC(10)  /*!< DMA transfer 11 times */
#define TIMER_DMACFG_DMATC_12TRANSFER  TIMER_DMACFG_DMATC(11)  /*!< DMA transfer 12 times */
#define TIMER_DMACFG_DMATC_13TRANSFER  TIMER_DMACFG_DMATC(12)  /*!< DMA transfer 13 times */
#define TIMER_DMACFG_DMATC_14TRANSFER  TIMER_DMACFG_DMATC(13)  /*!< DMA transfer 14 times */
#define TIMER_DMACFG_DMATC_15TRANSFER  TIMER_DMACFG_DMATC(14)  /*!< DMA transfer 15 times */
#define TIMER_DMACFG_DMATC_16TRANSFER  TIMER_DMACFG_DMATC(15)  /*!< DMA transfer 16 times */
#define TIMER_DMACFG_DMATC_17TRANSFER  TIMER_DMACFG_DMATC(16)  /*!< DMA transfer 17 times */
#define TIMER_DMACFG_DMATC_18TRANSFER  TIMER_DMACFG_DMATC(17)  /*!< DMA transfer 18 times */
#define TIMER_DMACFG_DMATA_Pos         0
#define TIMER_DMACFG_DMATA_Msk         _AC(0x0000000f,U)       /*!< DMA transfer access start address */
#define TIMER_DMACFG_DMATA(x)          ((x) << TIMER_DMACFG_DMATA_Pos)
#define TIMER_DMACFG_DMATA_CTL0        TIMER_DMACFG_DMATA(0)   /*!< DMA transfer address is TIMER_CTL0 */
#define TIMER_DMACFG_DMATA_CTL1        TIMER_DMACFG_DMATA(1)   /*!< DMA transfer address is TIMER_CTL1 */
#define TIMER_DMACFG_DMATA_SMCFG       TIMER_DMACFG_DMATA(2)   /*!< DMA transfer address is TIMER_SMCFG */
#define TIMER_DMACFG_DMATA_DMAINTEN    TIMER_DMACFG_DMATA(3)   /*!< DMA transfer address is TIMER_DMAINTEN */
#define TIMER_DMACFG_DMATA_INTF        TIMER_DMACFG_DMATA(4)   /*!< DMA transfer address is TIMER_INTF */
#define TIMER_DMACFG_DMATA_SWEVG       TIMER_DMACFG_DMATA(5)   /*!< DMA transfer address is TIMER_SWEVG */
#define TIMER_DMACFG_DMATA_CHCTL0      TIMER_DMACFG_DMATA(6)   /*!< DMA transfer address is TIMER_CHCTL0 */
#define TIMER_DMACFG_DMATA_CHCTL1      TIMER_DMACFG_DMATA(7)   /*!< DMA transfer address is TIMER_CHCTL1 */
#define TIMER_DMACFG_DMATA_CHCTL2      TIMER_DMACFG_DMATA(8)   /*!< DMA transfer address is TIMER_CHCTL2 */
#define TIMER_DMACFG_DMATA_CNT         TIMER_DMACFG_DMATA(9)   /*!< DMA transfer address is TIMER_CNT */
#define TIMER_DMACFG_DMATA_PSC         TIMER_DMACFG_DMATA(10)  /*!< DMA transfer address is TIMER_PSC */
#define TIMER_DMACFG_DMATA_CAR         TIMER_DMACFG_DMATA(11)  /*!< DMA transfer address is TIMER_CAR */
#define TIMER_DMACFG_DMATA_CREP        TIMER_DMACFG_DMATA(12)  /*!< DMA transfer address is TIMER_CREP */
#define TIMER_DMACFG_DMATA_CH0CV       TIMER_DMACFG_DMATA(13)  /*!< DMA transfer address is TIMER_CH0CV */
#define TIMER_DMACFG_DMATA_CH1CV       TIMER_DMACFG_DMATA(14)  /*!< DMA transfer address is TIMER_CH1CV */
#define TIMER_DMACFG_DMATA_CH2CV       TIMER_DMACFG_DMATA(15)  /*!< DMA transfer address is TIMER_CH2CV */
#define TIMER_DMACFG_DMATA_CH3CV       TIMER_DMACFG_DMATA(16)  /*!< DMA transfer address is TIMER_CH3CV */
#define TIMER_DMACFG_DMATA_CCHP        TIMER_DMACFG_DMATA(17)  /*!< DMA transfer address is TIMER_CCHP */
#define TIMER_DMACFG_DMATA_DMACFG      TIMER_DMACFG_DMATA(18)  /*!< DMA transfer address is TIMER_DMACFG */

/* TIMER_DMATB */
#define TIMER_DMATB_DMATB_Pos          0
#define TIMER_DMATB_DMATB_Msk          _AC(0x0000ffff,U)       /*!< DMA transfer buffer address */
#define TIMER_DMATB_DMATB(x)           ((x) << TIMER_DMATB_DMATB_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_timer {
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t SMCFG;
	volatile uint32_t DMAINTEN;
	volatile uint32_t INTF;
	volatile uint32_t SWEVG;
	volatile uint32_t CHCTL0;
	volatile uint32_t CHCTL1;
	volatile uint32_t CHCTL2;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t CAR;
	volatile uint32_t CREP;
	volatile uint32_t CH0CV;
	volatile uint32_t CH1CV;
	volatile uint32_t CH2CV;
	volatile uint32_t CH3CV;
	volatile uint32_t CCHP;
	volatile uint32_t DMACFG;
	volatile uint32_t DMATB;
};

static struct gd32vf103_timer *const TIMER0 = (struct gd32vf103_timer *)TIMER0_BASE;
static struct gd32vf103_timer *const TIMER1 = (struct gd32vf103_timer *)TIMER1_BASE;
static struct gd32vf103_timer *const TIMER2 = (struct gd32vf103_timer *)TIMER2_BASE;
static struct gd32vf103_timer *const TIMER3 = (struct gd32vf103_timer *)TIMER3_BASE;
static struct gd32vf103_timer *const TIMER4 = (struct gd32vf103_timer *)TIMER4_BASE;
static struct gd32vf103_timer *const TIMER5 = (struct gd32vf103_timer *)TIMER5_BASE;
static struct gd32vf103_timer *const TIMER6 = (struct gd32vf103_timer *)TIMER6_BASE;

#endif
#endif
