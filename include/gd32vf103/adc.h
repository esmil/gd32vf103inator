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
#ifndef GD32VF103_ADC_H
#define GD32VF103_ADC_H

#include "gd32vf103.h"

#define ADC0_BASE _AC(0x40012400,UL)  /*!< ADC0 base address */
#define ADC1_BASE _AC(0x40012800,UL)  /*!< ADC1 base address */

/* register definitions */
#define ADC_STAT       _AC(0x00,UL)  /*!< ADC status register */
#define ADC_CTL0       _AC(0x04,UL)  /*!< ADC control register 0 */
#define ADC_CTL1       _AC(0x08,UL)  /*!< ADC control register 1 */
#define ADC_SAMPT0     _AC(0x0C,UL)  /*!< ADC sampling time register 0 */
#define ADC_SAMPT1     _AC(0x10,UL)  /*!< ADC sampling time register 1 */
#define ADC_IOFF0      _AC(0x14,UL)  /*!< ADC inserted channel data offset register 0 */
#define ADC_IOFF1      _AC(0x18,UL)  /*!< ADC inserted channel data offset register 1 */
#define ADC_IOFF2      _AC(0x1C,UL)  /*!< ADC inserted channel data offset register 2 */
#define ADC_IOFF3      _AC(0x20,UL)  /*!< ADC inserted channel data offset register 3 */
#define ADC_WDHT       _AC(0x24,UL)  /*!< ADC watchdog high threshold register */
#define ADC_WDLT       _AC(0x28,UL)  /*!< ADC watchdog low threshold register */
#define ADC_RSQ0       _AC(0x2C,UL)  /*!< ADC regular sequence register 0 */
#define ADC_RSQ1       _AC(0x30,UL)  /*!< ADC regular sequence register 1 */
#define ADC_RSQ2       _AC(0x34,UL)  /*!< ADC regular sequence register 2 */
#define ADC_ISQ        _AC(0x38,UL)  /*!< ADC inserted sequence register */
#define ADC_IDATA0     _AC(0x3C,UL)  /*!< ADC inserted data register 0 */
#define ADC_IDATA1     _AC(0x40,UL)  /*!< ADC inserted data register 1 */
#define ADC_IDATA2     _AC(0x44,UL)  /*!< ADC inserted data register 2 */
#define ADC_IDATA3     _AC(0x48,UL)  /*!< ADC inserted data register 3 */
#define ADC_RDATA      _AC(0x4C,UL)  /*!< ADC regular data register */
#define ADC_OVSAMPCTL  _AC(0x80,UL)  /*!< ADC oversample control register */

/* ADC_STAT */
#define ADC_STAT_STRC                  _BIT(4,U)              /*!< regular channel start flag */
#define ADC_STAT_STIC                  _BIT(3,U)              /*!< inserted channel start flag */
#define ADC_STAT_EOIC                  _BIT(2,U)              /*!< inserted channel end of conversion */
#define ADC_STAT_EOC                   _BIT(1,U)              /*!< end of conversion */
#define ADC_STAT_WDE                   _BIT(0,U)              /*!< analog watchdog event flag */

/* ADC_CTL0 */
#define ADC_CTL0_RWDEN                 _BIT(23,U)             /*!< analog watchdog enable on regular channels */
#define ADC_CTL0_IWDEN                 _BIT(22,U)             /*!< analog watchdog enable on inserted channels */
#define ADC_CTL0_SYNCM_Pos             16
#define ADC_CTL0_SYNCM_Msk             _AC(0x000f0000,U)      /*!< sync mode selection */
#define ADC_CTL0_SYNCM(x)              ((x) << ADC_CTL0_SYNCM_Pos)
#define ADC_CTL0_SYNCM_FREE            ADC_CTL0_SYNCM(0)      /*!< all the ADCs work independently */
#define ADC_CTL0_SYNCM_RPAR_IPAR       ADC_CTL0_SYNCM(1)      /*!< ADC0 and ADC1 work in combined regular parallel + inserted parallel mode */
#define ADC_CTL0_SYNCM_RPAR_IROT       ADC_CTL0_SYNCM(2)      /*!< ADC0 and ADC1 work in combined regular parallel + trigger rotation mode */
#define ADC_CTL0_SYNCM_IPAR_RFOL_FAST  ADC_CTL0_SYNCM(3)      /*!< ADC0 and ADC1 work in combined inserted parallel + follow-up fast mode */
#define ADC_CTL0_SYNCM_IPAR_RFOL_SLOW  ADC_CTL0_SYNCM(4)      /*!< ADC0 and ADC1 work in combined inserted parallel + follow-up slow mode */
#define ADC_CTL0_SYNCM_IPAR            ADC_CTL0_SYNCM(5)      /*!< ADC0 and ADC1 work in inserted parallel mode only */
#define ADC_CTL0_SYNCM_RPAR            ADC_CTL0_SYNCM(6)      /*!< ADC0 and ADC1 work in regular parallel mode only */
#define ADC_CTL0_SYNCM_RFOL_FAST       ADC_CTL0_SYNCM(7)      /*!< ADC0 and ADC1 work in follow-up fast mode only */
#define ADC_CTL0_SYNCM_RFOL_SLOW       ADC_CTL0_SYNCM(8)      /*!< ADC0 and ADC1 work in follow-up slow mode only */
#define ADC_CTL0_SYNCM_ITRIG_ROT       ADC_CTL0_SYNCM(9)      /*!< ADC0 and ADC1 work in trigger rotation mode only */
#define ADC_CTL0_DISNUM_Pos            13
#define ADC_CTL0_DISNUM_Msk            _AC(0x0000e000,U)      /*!< discontinuous mode channel count */
#define ADC_CTL0_DISNUM(x)             ((x) << ADC_CTL0_DISNUM_Pos)
#define ADC_CTL0_DISIC                 _BIT(12,U)             /*!< discontinuous mode on inserted channels */
#define ADC_CTL0_DISRC                 _BIT(11,U)             /*!< discontinuous mode on regular channels */
#define ADC_CTL0_ICA                   _BIT(10,U)             /*!< automatic inserted group conversion */
#define ADC_CTL0_WDSC                  _BIT(9,U)              /*!< when in scan mode, analog watchdog is effective on a single channel */
#define ADC_CTL0_SM                    _BIT(8,U)              /*!< scan mode */
#define ADC_CTL0_EOICIE                _BIT(7,U)              /*!< interrupt enable for inserted channels */
#define ADC_CTL0_WDEIE                 _BIT(6,U)              /*!< analog watchdog interrupt enable */
#define ADC_CTL0_EOCIE                 _BIT(5,U)              /*!< interrupt enable for EOC */
#define ADC_CTL0_WDCHSEL_Pos           0
#define ADC_CTL0_WDCHSEL_Msk           _AC(0x0000001f,U)      /*!< analog watchdog channel select bits */
#define ADC_CTL0_WDCHSEL(x)            ((x) << ADC_CTL0_WDCHSEL_Pos)

/* ADC_CTL1 */
#define ADC_CTL1_TSVREN                _BIT(23,U)             /*!< channel 16 and 17 enable of ADC0 */
#define ADC_CTL1_SWRCST                _BIT(22,U)             /*!< start on regular channel */
#define ADC_CTL1_SWICST                _BIT(21,U)             /*!< start on inserted channel */
#define ADC_CTL1_ETERC                 _BIT(20,U)             /*!< external trigger conversion mode for inserted channels */
#define ADC_CTL1_ETSRC_Pos             17
#define ADC_CTL1_ETSRC_Msk             _AC(0x000e0000,U)      /*!< external trigger select for regular channel */
#define ADC_CTL1_ETSRC(x)              ((x) << ADC_CTL1_ETSRC_Pos)
#define ADC_CTL1_ETSRC_T0_CH0          ADC_CTL1_ETSRC(0)      /*!< TIMER0 CH0 event select */
#define ADC_CTL1_ETSRC_T0_CH1          ADC_CTL1_ETSRC(1)      /*!< TIMER0 CH1 event select */
#define ADC_CTL1_ETSRC_T0_CH2          ADC_CTL1_ETSRC(2)      /*!< TIMER0 CH2 event select */
#define ADC_CTL1_ETSRC_T1_CH1          ADC_CTL1_ETSRC(3)      /*!< TIMER1 CH1 event select */
#define ADC_CTL1_ETSRC_T2_TRGO         ADC_CTL1_ETSRC(4)      /*!< TIMER2 TRGO event select */
#define ADC_CTL1_ETSRC_T3_CH3          ADC_CTL1_ETSRC(5)      /*!< TIMER3 CH3 event select */
#define ADC_CTL1_ETSRC_EXTI_11         ADC_CTL1_ETSRC(6)      /*!< external interrupt line 11 */
#define ADC_CTL1_ETSRC_NONE            ADC_CTL1_ETSRC(7)      /*!< software trigger */
#define ADC_CTL1_ETEIC                 _BIT(15,U)             /*!< external trigger enable for inserted channel */
#define ADC_CTL1_ETSIC_Pos             12
#define ADC_CTL1_ETSIC_Msk             _AC(0x00007000,U)      /*!< external trigger select for inserted channel */
#define ADC_CTL1_ETSIC(x)              ((x) << ADC_CTL1_ETSIC_Pos)
#define ADC_CTL1_ETSIC_T0_TRGO         ADC_CTL1_ETSIC(0)      /*!< TIMER0 TRGO event select */
#define ADC_CTL1_ETSIC_T0_CH3          ADC_CTL1_ETSIC(1)      /*!< TIMER0 CH3 event select */
#define ADC_CTL1_ETSIC_T1_TRGO         ADC_CTL1_ETSIC(2)      /*!< TIMER1 TRGO event select */
#define ADC_CTL1_ETSIC_T1_CH0          ADC_CTL1_ETSIC(3)      /*!< TIMER1 CH0 event select */
#define ADC_CTL1_ETSIC_T2_CH3          ADC_CTL1_ETSIC(4)      /*!< TIMER2 CH3 event select */
#define ADC_CTL1_ETSIC_T3_TRGO         ADC_CTL1_ETSIC(5)      /*!< TIMER3 TRGO event select */
#define ADC_CTL1_ETSIC_EXTI_15         ADC_CTL1_ETSIC(6)      /*!< external interrupt line 15 */
#define ADC_CTL1_ETSIC_NONE            ADC_CTL1_ETSIC(7)      /*!< software trigger */
#define ADC_CTL1_DAL                   _BIT(11,U)             /*!< data alignment */
#define ADC_CTL1_DMA                   _BIT(8,U)              /*!< direct memory access mode */
#define ADC_CTL1_RSTCLB                _BIT(3,U)              /*!< reset calibration */
#define ADC_CTL1_CLB                   _BIT(2,U)              /*!< ADC calibration */
#define ADC_CTL1_CTN                   _BIT(1,U)              /*!< continuous conversion */
#define ADC_CTL1_ADCON                 _BIT(0,U)              /*!< ADC converter on */

/* ADC_SAMPT0 */
#define ADC_SAMPT0_SPT17_Pos           21
#define ADC_SAMPT0_SPT17_Msk           _AC(0x00e00000,U)      /*!< channel 17 sample time selection */
#define ADC_SAMPT0_SPT17(x)            ((x) << ADC_SAMPT0_SPT17_Pos)
#define ADC_SAMPT0_SPT16_Pos           18
#define ADC_SAMPT0_SPT16_Msk           _AC(0x001c0000,U)      /*!< channel 16 sample time selection */
#define ADC_SAMPT0_SPT16(x)            ((x) << ADC_SAMPT0_SPT16_Pos)
#define ADC_SAMPT0_SPT15_Pos           15
#define ADC_SAMPT0_SPT15_Msk           _AC(0x00038000,U)      /*!< channel 15 sample time selection */
#define ADC_SAMPT0_SPT15(x)            ((x) << ADC_SAMPT0_SPT15_Pos)
#define ADC_SAMPT0_SPT14_Pos           12
#define ADC_SAMPT0_SPT14_Msk           _AC(0x00007000,U)      /*!< channel 14 sample time selection */
#define ADC_SAMPT0_SPT14(x)            ((x) << ADC_SAMPT0_SPT14_Pos)
#define ADC_SAMPT0_SPT13_Pos           9
#define ADC_SAMPT0_SPT13_Msk           _AC(0x00000e00,U)      /*!< channel 13 sample time selection */
#define ADC_SAMPT0_SPT13(x)            ((x) << ADC_SAMPT0_SPT13_Pos)
#define ADC_SAMPT0_SPT12_Pos           6
#define ADC_SAMPT0_SPT12_Msk           _AC(0x000001c0,U)      /*!< channel 12 sample time selection */
#define ADC_SAMPT0_SPT12(x)            ((x) << ADC_SAMPT0_SPT12_Pos)
#define ADC_SAMPT0_SPT11_Pos           3
#define ADC_SAMPT0_SPT11_Msk           _AC(0x00000038,U)      /*!< channel 11 sample time selection */
#define ADC_SAMPT0_SPT11(x)            ((x) << ADC_SAMPT0_SPT11_Pos)
#define ADC_SAMPT0_SPT10_Pos           0
#define ADC_SAMPT0_SPT10_Msk           _AC(0x00000007,U)      /*!< channel 10 sample time selection */
#define ADC_SAMPT0_SPT10(x)            ((x) << ADC_SAMPT0_SPT10_Pos)

/* ADC_SAMPT1 */
#define ADC_SAMPT1_SPT9_Pos            27
#define ADC_SAMPT1_SPT9_Msk            _AC(0x38000000,U)      /*!< channel 9 sample time selection */
#define ADC_SAMPT1_SPT9(x)             ((x) << ADC_SAMPT1_SPT9_Pos)
#define ADC_SAMPT1_SPT8_Pos            24
#define ADC_SAMPT1_SPT8_Msk            _AC(0x07000000,U)      /*!< channel 8 sample time selection */
#define ADC_SAMPT1_SPT8(x)             ((x) << ADC_SAMPT1_SPT8_Pos)
#define ADC_SAMPT1_SPT7_Pos            21
#define ADC_SAMPT1_SPT7_Msk            _AC(0x00e00000,U)      /*!< channel 7 sample time selection */
#define ADC_SAMPT1_SPT7(x)             ((x) << ADC_SAMPT1_SPT7_Pos)
#define ADC_SAMPT1_SPT6_Pos            18
#define ADC_SAMPT1_SPT6_Msk            _AC(0x001c0000,U)      /*!< channel 6 sample time selection */
#define ADC_SAMPT1_SPT6(x)             ((x) << ADC_SAMPT1_SPT6_Pos)
#define ADC_SAMPT1_SPT5_Pos            15
#define ADC_SAMPT1_SPT5_Msk            _AC(0x00038000,U)      /*!< channel 5 sample time selection */
#define ADC_SAMPT1_SPT5(x)             ((x) << ADC_SAMPT1_SPT5_Pos)
#define ADC_SAMPT1_SPT4_Pos            12
#define ADC_SAMPT1_SPT4_Msk            _AC(0x00007000,U)      /*!< channel 4 sample time selection */
#define ADC_SAMPT1_SPT4(x)             ((x) << ADC_SAMPT1_SPT4_Pos)
#define ADC_SAMPT1_SPT3_Pos            9
#define ADC_SAMPT1_SPT3_Msk            _AC(0x00000e00,U)      /*!< channel 3 sample time selection */
#define ADC_SAMPT1_SPT3(x)             ((x) << ADC_SAMPT1_SPT3_Pos)
#define ADC_SAMPT1_SPT2_Pos            6
#define ADC_SAMPT1_SPT2_Msk            _AC(0x000001c0,U)      /*!< channel 2 sample time selection */
#define ADC_SAMPT1_SPT2(x)             ((x) << ADC_SAMPT1_SPT2_Pos)
#define ADC_SAMPT1_SPT1_Pos            3
#define ADC_SAMPT1_SPT1_Msk            _AC(0x00000038,U)      /*!< channel 1 sample time selection */
#define ADC_SAMPT1_SPT1(x)             ((x) << ADC_SAMPT1_SPT1_Pos)
#define ADC_SAMPT1_SPT0_Pos            0
#define ADC_SAMPT1_SPT0_Msk            _AC(0x00000007,U)      /*!< channel 0 sample time selection */
#define ADC_SAMPT1_SPT0(x)             ((x) << ADC_SAMPT1_SPT0_Pos)

/* ADC_IOFFx x=0..3 */
#define ADC_IOFFX_IOFF_Pos             0
#define ADC_IOFFX_IOFF_Msk             _AC(0x00000fff,U)      /*!< data offset for inserted channel x */
#define ADC_IOFFX_IOFF(x)              ((x) << ADC_IOFFX_IOFF_Pos)

/* ADC_WDHT */
#define ADC_WDHT_WDHT_Pos              0
#define ADC_WDHT_WDHT_Msk              _AC(0x00000fff,U)      /*!< analog watchdog high threshold */
#define ADC_WDHT_WDHT(x)               ((x) << ADC_WDHT_WDHT_Pos)

/* ADC_WDLT */
#define ADC_WDLT_WDLT_Pos              0
#define ADC_WDLT_WDLT_Msk              _AC(0x00000fff,U)      /*!< analog watchdog low threshold */
#define ADC_WDLT_WDLT(x)               ((x) << ADC_WDLT_WDLT_Pos)

/* ADC_RSQ0 */
#define ADC_RSQ0_RL_Pos                20
#define ADC_RSQ0_RL_Msk                _AC(0x00f00000,U)      /*!< regular channel sequence length */
#define ADC_RSQ0_RL(x)                 ((x) << ADC_RSQ0_RL_Pos)
#define ADC_RSQ0_RSQ15_Pos             15
#define ADC_RSQ0_RSQ15_Msk             _AC(0x000f8000,U)      /*!< 15th conversion in regular sequence */
#define ADC_RSQ0_RSQ15(x)              ((x) << ADC_RSQ0_RSQ15_Pos)
#define ADC_RSQ0_RSQ14_Pos             10
#define ADC_RSQ0_RSQ14_Msk             _AC(0x00007c00,U)      /*!< 14th conversion in regular sequence */
#define ADC_RSQ0_RSQ14(x)              ((x) << ADC_RSQ0_RSQ14_Pos)
#define ADC_RSQ0_RSQ13_Pos             5
#define ADC_RSQ0_RSQ13_Msk             _AC(0x000003e0,U)      /*!< 13th conversion in regular sequence */
#define ADC_RSQ0_RSQ13(x)              ((x) << ADC_RSQ0_RSQ13_Pos)
#define ADC_RSQ0_RSQ12_Pos             0
#define ADC_RSQ0_RSQ12_Msk             _AC(0x0000001f,U)      /*!< 12th conversion in regular sequence */
#define ADC_RSQ0_RSQ12(x)              ((x) << ADC_RSQ0_RSQ12_Pos)

/* ADC_RSQ1 */
#define ADC_RSQ1_RSQ11_Pos             25
#define ADC_RSQ1_RSQ11_Msk             _AC(0x3e000000,U)      /*!< 11th conversion in regular sequence */
#define ADC_RSQ1_RSQ11(x)              ((x) << ADC_RSQ1_RSQ11_Pos)
#define ADC_RSQ1_RSQ10_Pos             20
#define ADC_RSQ1_RSQ10_Msk             _AC(0x01f00000,U)      /*!< 10th conversion in regular sequence */
#define ADC_RSQ1_RSQ10(x)              ((x) << ADC_RSQ1_RSQ10_Pos)
#define ADC_RSQ1_RSQ9_Pos              15
#define ADC_RSQ1_RSQ9_Msk              _AC(0x000f8000,U)      /*!< 9th conversion in regular sequence */
#define ADC_RSQ1_RSQ9(x)               ((x) << ADC_RSQ1_RSQ9_Pos)
#define ADC_RSQ1_RSQ8_Pos              10
#define ADC_RSQ1_RSQ8_Msk              _AC(0x00007c00,U)      /*!< 8th conversion in regular sequence */
#define ADC_RSQ1_RSQ8(x)               ((x) << ADC_RSQ1_RSQ8_Pos)
#define ADC_RSQ1_RSQ7_Pos              5
#define ADC_RSQ1_RSQ7_Msk              _AC(0x000003e0,U)      /*!< 7th conversion in regular sequence */
#define ADC_RSQ1_RSQ7(x)               ((x) << ADC_RSQ1_RSQ7_Pos)
#define ADC_RSQ1_RSQ6_Pos              0
#define ADC_RSQ1_RSQ6_Msk              _AC(0x0000001f,U)      /*!< 6th conversion in regular sequence */
#define ADC_RSQ1_RSQ6(x)               ((x) << ADC_RSQ1_RSQ6_Pos)

/* ADC_RSQ2 */
#define ADC_RSQ2_RSQ5_Pos              25
#define ADC_RSQ2_RSQ5_Msk              _AC(0x3e000000,U)      /*!< 5th conversion in regular sequence */
#define ADC_RSQ2_RSQ5(x)               ((x) << ADC_RSQ2_RSQ5_Pos)
#define ADC_RSQ2_RSQ4_Pos              20
#define ADC_RSQ2_RSQ4_Msk              _AC(0x01f00000,U)      /*!< 4th conversion in regular sequence */
#define ADC_RSQ2_RSQ4(x)               ((x) << ADC_RSQ2_RSQ4_Pos)
#define ADC_RSQ2_RSQ3_Pos              15
#define ADC_RSQ2_RSQ3_Msk              _AC(0x000f8000,U)      /*!< 3rd conversion in regular sequence */
#define ADC_RSQ2_RSQ3(x)               ((x) << ADC_RSQ2_RSQ3_Pos)
#define ADC_RSQ2_RSQ2_Pos              10
#define ADC_RSQ2_RSQ2_Msk              _AC(0x00007c00,U)      /*!< 2nd conversion in regular sequence */
#define ADC_RSQ2_RSQ2(x)               ((x) << ADC_RSQ2_RSQ2_Pos)
#define ADC_RSQ2_RSQ1_Pos              5
#define ADC_RSQ2_RSQ1_Msk              _AC(0x000003e0,U)      /*!< 1st conversion in regular sequence */
#define ADC_RSQ2_RSQ1(x)               ((x) << ADC_RSQ2_RSQ1_Pos)
#define ADC_RSQ2_RSQ0_Pos              0
#define ADC_RSQ2_RSQ0_Msk              _AC(0x0000001f,U)      /*!< 0th conversion in regular sequence */
#define ADC_RSQ2_RSQ0(x)               ((x) << ADC_RSQ2_RSQ0_Pos)

/* ADC_ISQ */
#define ADC_ISQ_IL_Pos                 20
#define ADC_ISQ_IL_Msk                 _AC(0x00300000,U)      /*!< inserted sequence length */
#define ADC_ISQ_IL(x)                  ((x) << ADC_ISQ_IL_Pos)
#define ADC_ISQ_ISQ3_Pos               15
#define ADC_ISQ_ISQ3_Msk               _AC(0x000f8000,U)      /*!< 3rd conversion in inserted sequence */
#define ADC_ISQ_ISQ3(x)                ((x) << ADC_ISQ_ISQ3_Pos)
#define ADC_ISQ_ISQ2_Pos               10
#define ADC_ISQ_ISQ2_Msk               _AC(0x00007c00,U)      /*!< 2nd conversion in inserted sequence */
#define ADC_ISQ_ISQ2(x)                ((x) << ADC_ISQ_ISQ2_Pos)
#define ADC_ISQ_ISQ1_Pos               5
#define ADC_ISQ_ISQ1_Msk               _AC(0x000003e0,U)      /*!< 1st conversion in inserted sequence */
#define ADC_ISQ_ISQ1(x)                ((x) << ADC_ISQ_ISQ1_Pos)
#define ADC_ISQ_ISQ0_Pos               0
#define ADC_ISQ_ISQ0_Msk               _AC(0x0000001f,U)      /*!< 0th conversion in inserted sequence */
#define ADC_ISQ_ISQ0(x)                ((x) << ADC_ISQ_ISQ0_Pos)

/* ADC_IDATAx x=0..3*/
#define ADC_IDATAX_IDATAN_Pos          0
#define ADC_IDATAX_IDATAN_Msk          _AC(0x0000ffff,U)      /*!< inserted data n */
#define ADC_IDATAX_IDATAN(x)           ((x) << ADC_IDATAX_IDATAN_Pos)

/* ADC_RDATA */
#define ADC_RDATA_ADC1RDTR_Pos         16
#define ADC_RDATA_ADC1RDTR_Msk         _AC(0xffff0000,U)      /*!< ADC1 regular channel data */
#define ADC_RDATA_ADC1RDTR(x)          ((x) << ADC_RDATA_ADC1RDTR_Pos)
#define ADC_RDATA_RDATA_Pos            0
#define ADC_RDATA_RDATA_Msk            _AC(0x0000ffff,U)      /*!< regular data */
#define ADC_RDATA_RDATA(x)             ((x) << ADC_RDATA_RDATA_Pos)

/* ADC_OVSAMPCTL */
#define ADC_OVSAMPCTL_DRES_Pos         12
#define ADC_OVSAMPCTL_DRES_Msk         _AC(0x00003000,U)      /*!< ADC data resolution */
#define ADC_OVSAMPCTL_DRES(x)          ((x) << ADC_OVSAMPCTL_DRES_Pos)
#define ADC_OVSAMPCTL_DRES_12B         ADC_OVSAMPCTL_DRES(0)  /*!< 12-bit ADC resolution */
#define ADC_OVSAMPCTL_DRES_10B         ADC_OVSAMPCTL_DRES(1)  /*!< 10-bit ADC resolution */
#define ADC_OVSAMPCTL_DRES_8B          ADC_OVSAMPCTL_DRES(2)  /*!< 8-bit ADC resolution */
#define ADC_OVSAMPCTL_DRES_6B          ADC_OVSAMPCTL_DRES(3)  /*!< 6-bit ADC resolution */
#define ADC_OVSAMPCTL_TOVS             _BIT(9,U)              /*!< triggered oversampling */
#define ADC_OVSAMPCTL_OVSS_Pos         5
#define ADC_OVSAMPCTL_OVSS_Msk         _AC(0x000001e0,U)      /*!< oversampling shift */
#define ADC_OVSAMPCTL_OVSS(x)          ((x) << ADC_OVSAMPCTL_OVSS_Pos)
#define ADC_OVSAMPCTL_OVSS_NONE        ADC_OVSAMPCTL_OVSS(0)  /*!< no oversampling shift */
#define ADC_OVSAMPCTL_OVSS_1B          ADC_OVSAMPCTL_OVSS(1)  /*!< 1-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_2B          ADC_OVSAMPCTL_OVSS(2)  /*!< 2-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_3B          ADC_OVSAMPCTL_OVSS(3)  /*!< 3-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_4B          ADC_OVSAMPCTL_OVSS(4)  /*!< 4-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_5B          ADC_OVSAMPCTL_OVSS(5)  /*!< 5-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_6B          ADC_OVSAMPCTL_OVSS(6)  /*!< 6-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_7B          ADC_OVSAMPCTL_OVSS(7)  /*!< 7-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSS_8B          ADC_OVSAMPCTL_OVSS(8)  /*!< 8-bit oversampling shift */
#define ADC_OVSAMPCTL_OVSR_Pos         2
#define ADC_OVSAMPCTL_OVSR_Msk         _AC(0x0000001c,U)      /*!< oversampling ratio */
#define ADC_OVSAMPCTL_OVSR(x)          ((x) << ADC_OVSAMPCTL_OVSR_Pos)
#define ADC_OVSAMPCTL_OVSR_MUL2        ADC_OVSAMPCTL_OVSR(0)  /*!< oversampling ratio X2 */
#define ADC_OVSAMPCTL_OVSR_MUL4        ADC_OVSAMPCTL_OVSR(1)  /*!< oversampling ratio X4 */
#define ADC_OVSAMPCTL_OVSR_MUL8        ADC_OVSAMPCTL_OVSR(2)  /*!< oversampling ratio X8 */
#define ADC_OVSAMPCTL_OVSR_MUL16       ADC_OVSAMPCTL_OVSR(3)  /*!< oversampling ratio X16 */
#define ADC_OVSAMPCTL_OVSR_MUL32       ADC_OVSAMPCTL_OVSR(4)  /*!< oversampling ratio X32 */
#define ADC_OVSAMPCTL_OVSR_MUL64       ADC_OVSAMPCTL_OVSR(5)  /*!< oversampling ratio X64 */
#define ADC_OVSAMPCTL_OVSR_MUL128      ADC_OVSAMPCTL_OVSR(6)  /*!< oversampling ratio X128 */
#define ADC_OVSAMPCTL_OVSR_MUL256      ADC_OVSAMPCTL_OVSR(7)  /*!< oversampling ratio X256 */
#define ADC_OVSAMPCTL_OVSEN            _BIT(0,U)              /*!< oversampling enable */

/* constants definitions */
#define ADC_SAMPLETIME_1POINT5         _AC(0,U)               /*!< 1.5 sampling cycles */
#define ADC_SAMPLETIME_7POINT5         _AC(1,U)               /*!< 7.5 sampling cycles */
#define ADC_SAMPLETIME_13POINT5        _AC(2,U)               /*!< 13.5 sampling cycles */
#define ADC_SAMPLETIME_28POINT5        _AC(3,U)               /*!< 28.5 sampling cycles */
#define ADC_SAMPLETIME_41POINT5        _AC(4,U)               /*!< 41.5 sampling cycles */
#define ADC_SAMPLETIME_55POINT5        _AC(5,U)               /*!< 55.5 sampling cycles */
#define ADC_SAMPLETIME_71POINT5        _AC(6,U)               /*!< 71.5 sampling cycles */
#define ADC_SAMPLETIME_239POINT5       _AC(7,U)               /*!< 239.5 sampling cycles */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_adc {
	volatile uint32_t STAT;
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t SAMPT0;
	volatile uint32_t SAMPT1;
	union {
		volatile uint32_t IOFF[4];
		struct {
			volatile uint32_t IOFF0;
			volatile uint32_t IOFF1;
			volatile uint32_t IOFF2;
			volatile uint32_t IOFF3;
		};
	};
	volatile uint32_t WDHT;
	volatile uint32_t WDLT;
	volatile uint32_t RSQ0;
	volatile uint32_t RSQ1;
	volatile uint32_t RSQ2;
	volatile uint32_t ISQ;
	union {
		volatile uint32_t IDATA[4];
		struct {
			volatile uint32_t IDATA0;
			volatile uint32_t IDATA1;
			volatile uint32_t IDATA2;
			volatile uint32_t IDATA3;
		};
	};
	volatile uint32_t RDATA;
	uint32_t reserved1[12];
	volatile uint32_t OVSAMPCTL;
};

static struct gd32vf103_adc *const ADC0 = (struct gd32vf103_adc *)ADC0_BASE;
static struct gd32vf103_adc *const ADC1 = (struct gd32vf103_adc *)ADC1_BASE;

#endif
#endif
