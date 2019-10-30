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
#ifndef GD32VF103_CAN_H
#define GD32VF103_CAN_H

#include "gd32vf103.h"

#define CAN0_BASE _AC(0x40006400,UL)  /*!< CAN0 base address */
#define CAN1_BASE _AC(0x40006800,UL)  /*!< CAN1 base address */

/* register definitions */
#define CAN_CTL           _AC(0x000,UL)  /*!< CAN control register */
#define CAN_STAT          _AC(0x004,UL)  /*!< CAN status register */
#define CAN_TSTAT         _AC(0x008,UL)  /*!< CAN transmit status register*/
#define CAN_RFIFO0        _AC(0x00C,UL)  /*!< CAN receive FIFO0 register */
#define CAN_RFIFO1        _AC(0x010,UL)  /*!< CAN receive FIFO1 register */
#define CAN_INTEN         _AC(0x014,UL)  /*!< CAN interrupt enable register */
#define CAN_ERR           _AC(0x018,UL)  /*!< CAN error register */
#define CAN_BT            _AC(0x01C,UL)  /*!< CAN bit timing register */
#define CAN_TMI0          _AC(0x180,UL)  /*!< CAN transmit mailbox0 identifier register */
#define CAN_TMP0          _AC(0x184,UL)  /*!< CAN transmit mailbox0 property register */
#define CAN_TMDATA00      _AC(0x188,UL)  /*!< CAN transmit mailbox0 data0 register */
#define CAN_TMDATA10      _AC(0x18C,UL)  /*!< CAN transmit mailbox0 data1 register */
#define CAN_TMI1          _AC(0x190,UL)  /*!< CAN transmit mailbox1 identifier register */
#define CAN_TMP1          _AC(0x194,UL)  /*!< CAN transmit mailbox1 property register */
#define CAN_TMDATA01      _AC(0x198,UL)  /*!< CAN transmit mailbox1 data0 register */
#define CAN_TMDATA11      _AC(0x19C,UL)  /*!< CAN transmit mailbox1 data1 register */
#define CAN_TMI2          _AC(0x1A0,UL)  /*!< CAN transmit mailbox2 identifier register */
#define CAN_TMP2          _AC(0x1A4,UL)  /*!< CAN transmit mailbox2 property register */
#define CAN_TMDATA02      _AC(0x1A8,UL)  /*!< CAN transmit mailbox2 data0 register */
#define CAN_TMDATA12      _AC(0x1AC,UL)  /*!< CAN transmit mailbox2 data1 register */
#define CAN_RFIFOMI0      _AC(0x1B0,UL)  /*!< CAN receive FIFO0 mailbox identifier register */
#define CAN_RFIFOMP0      _AC(0x1B4,UL)  /*!< CAN receive FIFO0 mailbox property register */
#define CAN_RFIFOMDATA00  _AC(0x1B8,UL)  /*!< CAN receive FIFO0 mailbox data0 register */
#define CAN_RFIFOMDATA10  _AC(0x1BC,UL)  /*!< CAN receive FIFO0 mailbox data1 register */
#define CAN_RFIFOMI1      _AC(0x1C0,UL)  /*!< CAN receive FIFO1 mailbox identifier register */
#define CAN_RFIFOMP1      _AC(0x1C4,UL)  /*!< CAN receive FIFO1 mailbox property register */
#define CAN_RFIFOMDATA01  _AC(0x1C8,UL)  /*!< CAN receive FIFO1 mailbox data0 register */
#define CAN_RFIFOMDATA11  _AC(0x1CC,UL)  /*!< CAN receive FIFO1 mailbox data1 register */
#define CAN_FCTL          _AC(0x200,UL)  /*!< CAN filter control register */
#define CAN_FMCFG         _AC(0x204,UL)  /*!< CAN filter mode register */
#define CAN_FSCFG         _AC(0x20C,UL)  /*!< CAN filter scale register */
#define CAN_FAFIFO        _AC(0x214,UL)  /*!< CAN filter associated FIFO register */
#define CAN_FW            _AC(0x21C,UL)  /*!< CAN filter working register */
#define CAN_F0DATA0       _AC(0x240,UL)  /*!< CAN filter 0 data 0 register */
#define CAN_F0DATA1       _AC(0x244,UL)  /*!< CAN filter 0 data 1 register */
#define CAN_F1DATA0       _AC(0x248,UL)  /*!< CAN filter 1 data 0 register */
#define CAN_F1DATA1       _AC(0x24C,UL)  /*!< CAN filter 1 data 1 register */
#define CAN_F2DATA0       _AC(0x250,UL)  /*!< CAN filter 2 data 0 register */
#define CAN_F2DATA1       _AC(0x254,UL)  /*!< CAN filter 2 data 1 register */
#define CAN_F3DATA0       _AC(0x258,UL)  /*!< CAN filter 3 data 0 register */
#define CAN_F3DATA1       _AC(0x25C,UL)  /*!< CAN filter 3 data 1 register */
#define CAN_F4DATA0       _AC(0x260,UL)  /*!< CAN filter 4 data 0 register */
#define CAN_F4DATA1       _AC(0x264,UL)  /*!< CAN filter 4 data 1 register */
#define CAN_F5DATA0       _AC(0x268,UL)  /*!< CAN filter 5 data 0 register */
#define CAN_F5DATA1       _AC(0x26C,UL)  /*!< CAN filter 5 data 1 register */
#define CAN_F6DATA0       _AC(0x270,UL)  /*!< CAN filter 6 data 0 register */
#define CAN_F6DATA1       _AC(0x274,UL)  /*!< CAN filter 6 data 1 register */
#define CAN_F7DATA0       _AC(0x278,UL)  /*!< CAN filter 7 data 0 register */
#define CAN_F7DATA1       _AC(0x27C,UL)  /*!< CAN filter 7 data 1 register */
#define CAN_F8DATA0       _AC(0x280,UL)  /*!< CAN filter 8 data 0 register */
#define CAN_F8DATA1       _AC(0x284,UL)  /*!< CAN filter 8 data 1 register */
#define CAN_F9DATA0       _AC(0x288,UL)  /*!< CAN filter 9 data 0 register */
#define CAN_F9DATA1       _AC(0x28C,UL)  /*!< CAN filter 9 data 1 register */
#define CAN_F10DATA0      _AC(0x290,UL)  /*!< CAN filter 10 data 0 register */
#define CAN_F10DATA1      _AC(0x294,UL)  /*!< CAN filter 10 data 1 register */
#define CAN_F11DATA0      _AC(0x298,UL)  /*!< CAN filter 11 data 0 register */
#define CAN_F11DATA1      _AC(0x29C,UL)  /*!< CAN filter 11 data 1 register */
#define CAN_F12DATA0      _AC(0x2A0,UL)  /*!< CAN filter 12 data 0 register */
#define CAN_F12DATA1      _AC(0x2A4,UL)  /*!< CAN filter 12 data 1 register */
#define CAN_F13DATA0      _AC(0x2A8,UL)  /*!< CAN filter 13 data 0 register */
#define CAN_F13DATA1      _AC(0x2AC,UL)  /*!< CAN filter 13 data 1 register */
#define CAN_F14DATA0      _AC(0x2B0,UL)  /*!< CAN filter 14 data 0 register */
#define CAN_F14DATA1      _AC(0x2B4,UL)  /*!< CAN filter 14 data 1 register */
#define CAN_F15DATA0      _AC(0x2B8,UL)  /*!< CAN filter 15 data 0 register */
#define CAN_F15DATA1      _AC(0x2BC,UL)  /*!< CAN filter 15 data 1 register */
#define CAN_F16DATA0      _AC(0x2C0,UL)  /*!< CAN filter 16 data 0 register */
#define CAN_F16DATA1      _AC(0x2C4,UL)  /*!< CAN filter 16 data 1 register */
#define CAN_F17DATA0      _AC(0x2C8,UL)  /*!< CAN filter 17 data 0 register */
#define CAN_F17DATA1      _AC(0x2CC,UL)  /*!< CAN filter 17 data 1 register */
#define CAN_F18DATA0      _AC(0x2D0,UL)  /*!< CAN filter 18 data 0 register */
#define CAN_F18DATA1      _AC(0x2D4,UL)  /*!< CAN filter 18 data 1 register */
#define CAN_F19DATA0      _AC(0x2D8,UL)  /*!< CAN filter 19 data 0 register */
#define CAN_F19DATA1      _AC(0x2DC,UL)  /*!< CAN filter 19 data 1 register */
#define CAN_F20DATA0      _AC(0x2E0,UL)  /*!< CAN filter 20 data 0 register */
#define CAN_F20DATA1      _AC(0x2E4,UL)  /*!< CAN filter 20 data 1 register */
#define CAN_F21DATA0      _AC(0x2E8,UL)  /*!< CAN filter 21 data 0 register */
#define CAN_F21DATA1      _AC(0x2EC,UL)  /*!< CAN filter 21 data 1 register */
#define CAN_F22DATA0      _AC(0x2F0,UL)  /*!< CAN filter 22 data 0 register */
#define CAN_F22DATA1      _AC(0x2F4,UL)  /*!< CAN filter 22 data 1 register */
#define CAN_F23DATA0      _AC(0x2F8,UL)  /*!< CAN filter 23 data 0 register */
#define CAN_F23DATA1      _AC(0x2FC,UL)  /*!< CAN filter 23 data 1 register */
#define CAN_F24DATA0      _AC(0x300,UL)  /*!< CAN filter 24 data 0 register */
#define CAN_F24DATA1      _AC(0x304,UL)  /*!< CAN filter 24 data 1 register */
#define CAN_F25DATA0      _AC(0x308,UL)  /*!< CAN filter 25 data 0 register */
#define CAN_F25DATA1      _AC(0x30C,UL)  /*!< CAN filter 25 data 1 register */
#define CAN_F26DATA0      _AC(0x310,UL)  /*!< CAN filter 26 data 0 register */
#define CAN_F26DATA1      _AC(0x314,UL)  /*!< CAN filter 26 data 1 register */
#define CAN_F27DATA0      _AC(0x318,UL)  /*!< CAN filter 27 data 0 register */
#define CAN_F27DATA1      _AC(0x31C,UL)  /*!< CAN filter 27 data 1 register */

/* CAN transmit mailbox bank */
#define CAN_TMI(x)          (_AC(0x180,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN transmit mailbox identifier register */
#define CAN_TMP(x)          (_AC(0x184,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN transmit mailbox property register */
#define CAN_TMDATA0(x)      (_AC(0x188,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN transmit mailbox data0 register */
#define CAN_TMDATA1(x)      (_AC(0x18C,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN transmit mailbox data1 register */

/* CAN receive fifo mailbox bank */
#define CAN_RFIFOMI(x)      (_AC(0x1B0,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN receive fifo mailbox identifier register */
#define CAN_RFIFOMP(x)      (_AC(0x1B4,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN receive fifo mailbox property register */
#define CAN_RFIFOMDATA0(x)  (_AC(0x1B8,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN receive fifo mailbox data0 register */
#define CAN_RFIFOMDATA1(x)  (_AC(0x1BC,UL) + ((x) * _AC(0x10,UL)))  /*!< CAN receive fifo mailbox data1 register */

/* CAN filter bank */
#define CAN_FDATA0(x)       (_AC(0x240,UL) + ((x) * _AC(0x08,UL)))  /*!< CAN filter data 0 register */
#define CAN_FDATA1(x)       (_AC(0x244,UL) + ((x) * _AC(0x08,UL)))  /*!< CAN filter data 1 register */

/* CAN_CTL */
#define CAN_CTL_DFZ              _BIT(16,U)         /*!< CAN debug freeze */
#define CAN_CTL_SWRST            _BIT(15,U)         /*!< CAN software reset */
#define CAN_CTL_TTC              _BIT(7,U)          /*!< time triggered communication */
#define CAN_CTL_ABOR             _BIT(6,U)          /*!< automatic bus-off recovery */
#define CAN_CTL_AWU              _BIT(5,U)          /*!< automatic wakeup */
#define CAN_CTL_ARD              _BIT(4,U)          /*!< automatic retransmission disable */
#define CAN_CTL_RFOD             _BIT(3,U)          /*!< receive FIFO overwrite disable */
#define CAN_CTL_TFO              _BIT(2,U)          /*!< transmit FIFO order */
#define CAN_CTL_SLPWMOD          _BIT(1,U)          /*!< sleep working mode */
#define CAN_CTL_IWMOD            _BIT(0,U)          /*!< initial working mode */

/* CAN_STAT */
#define CAN_STAT_RXL             _BIT(11,U)         /*!< CAN rx signal */
#define CAN_STAT_LASTRX          _BIT(10,U)         /*!< last sample value of rx pin */
#define CAN_STAT_RS              _BIT(9,U)          /*!< receiving state */
#define CAN_STAT_TS              _BIT(8,U)          /*!< transmitting state */
#define CAN_STAT_SLPIF           _BIT(4,U)          /*!< status change interrupt flag of sleep working mode entering */
#define CAN_STAT_WUIF            _BIT(3,U)          /*!< status change interrupt flag of wakeup from sleep working mode */
#define CAN_STAT_ERRIF           _BIT(2,U)          /*!< error interrupt flag*/
#define CAN_STAT_SLPWS           _BIT(1,U)          /*!< sleep working state */
#define CAN_STAT_IWS             _BIT(0,U)          /*!< initial working state */

/* CAN_TSTAT */
#define CAN_TSTAT_TMLS2          _BIT(31,U)         /*!< last sending priority flag for mailbox2 */
#define CAN_TSTAT_TMLS1          _BIT(30,U)         /*!< last sending priority flag for mailbox1 */
#define CAN_TSTAT_TMLS0          _BIT(29,U)         /*!< last sending priority flag for mailbox0 */
#define CAN_TSTAT_TME2           _BIT(28,U)         /*!< transmit mailbox2 empty */
#define CAN_TSTAT_TME1           _BIT(27,U)         /*!< transmit mailbox1 empty */
#define CAN_TSTAT_TME0           _BIT(26,U)         /*!< transmit mailbox0 empty */
#define CAN_TSTAT_NUM_Pos        24
#define CAN_TSTAT_NUM_Msk        _AC(0x0c000000,U)  /*!< mailbox number */
#define CAN_TSTAT_NUM(x)         ((x) << CAN_TSTAT_NUM_Pos)
#define CAN_TSTAT_MST2           _BIT(23,U)         /*!< mailbox2 stop transmitting */
#define CAN_TSTAT_MTE2           _BIT(19,U)         /*!< mailbox2 transmit error */
#define CAN_TSTAT_MAL2           _BIT(18,U)         /*!< mailbox2 arbitration lost */
#define CAN_TSTAT_MTFNERR2       _BIT(17,U)         /*!< mailbox2 transmit finished and no error */
#define CAN_TSTAT_MTF2           _BIT(16,U)         /*!< mailbox2 transmit finished */
#define CAN_TSTAT_MST1           _BIT(15,U)         /*!< mailbox1 stop transmitting */
#define CAN_TSTAT_MTE1           _BIT(11,U)         /*!< mailbox1 transmit error */
#define CAN_TSTAT_MAL1           _BIT(10,U)         /*!< mailbox1 arbitration lost */
#define CAN_TSTAT_MTFNERR1       _BIT(9,U)          /*!< mailbox1 transmit finished and no error */
#define CAN_TSTAT_MTF1           _BIT(8,U)          /*!< mailbox1 transmit finished */
#define CAN_TSTAT_MST0           _BIT(7,U)          /*!< mailbox0 stop transmitting */
#define CAN_TSTAT_MTE0           _BIT(3,U)          /*!< mailbox0 transmit error */
#define CAN_TSTAT_MAL0           _BIT(2,U)          /*!< mailbox0 arbitration lost */
#define CAN_TSTAT_MTFNERR0       _BIT(1,U)          /*!< mailbox0 transmit finished and no error */
#define CAN_TSTAT_MTF0           _BIT(0,U)          /*!< mailbox0 transmit finished */

/* CAN_RFIFO0 */
#define CAN_RFIFO0_RFD0          _BIT(5,U)          /*!< receive FIFO0 dequeue */
#define CAN_RFIFO0_RFO0          _BIT(4,U)          /*!< receive FIFO0 overfull */
#define CAN_RFIFO0_RFF0          _BIT(3,U)          /*!< receive FIFO0 full */
#define CAN_RFIFO0_RFL0_Pos      0
#define CAN_RFIFO0_RFL0_Msk      _AC(0x00000003,U)  /*!< receive FIFO0 length */
#define CAN_RFIFO0_RFL0(x)       ((x) << CAN_RFIFO0_RFL0_Pos)

/* CAN_RFIFO1 */
#define CAN_RFIFO1_RFD1          _BIT(5,U)          /*!< receive FIFO1 dequeue */
#define CAN_RFIFO1_RFO1          _BIT(4,U)          /*!< receive FIFO1 overfull */
#define CAN_RFIFO1_RFF1          _BIT(3,U)          /*!< receive FIFO1 full */
#define CAN_RFIFO1_RFL1_Pos      0
#define CAN_RFIFO1_RFL1_Msk      _AC(0x00000003,U)  /*!< receive FIFO1 length */
#define CAN_RFIFO1_RFL1(x)       ((x) << CAN_RFIFO1_RFL1_Pos)

/* CAN_INTEN */
#define CAN_INTEN_SLPWIE         _BIT(17,U)         /*!< sleep working interrupt enable */
#define CAN_INTEN_WIE            _BIT(16,U)         /*!< wakeup interrupt enable */
#define CAN_INTEN_ERRIE          _BIT(15,U)         /*!< error interrupt enable */
#define CAN_INTEN_ERRNIE         _BIT(11,U)         /*!< error number interrupt enable */
#define CAN_INTEN_BOIE           _BIT(10,U)         /*!< bus-off interrupt enable */
#define CAN_INTEN_PERRIE         _BIT(9,U)          /*!< passive error interrupt enable */
#define CAN_INTEN_WERRIE         _BIT(8,U)          /*!< warning error interrupt enable */
#define CAN_INTEN_RFOIE1         _BIT(6,U)          /*!< receive FIFO1 overfull interrupt enable */
#define CAN_INTEN_RFFIE1         _BIT(5,U)          /*!< receive FIFO1 full interrupt enable */
#define CAN_INTEN_RFNEIE1        _BIT(4,U)          /*!< receive FIFO1 not empty interrupt enable */
#define CAN_INTEN_RFOIE0         _BIT(3,U)          /*!< receive FIFO0 overfull interrupt enable */
#define CAN_INTEN_RFFIE0         _BIT(2,U)          /*!< receive FIFO0 full interrupt enable */
#define CAN_INTEN_RFNEIE0        _BIT(1,U)          /*!< receive FIFO0 not empty interrupt enable */
#define CAN_INTEN_TMEIE          _BIT(0,U)          /*!< transmit mailbox empty interrupt enable */

/* CAN_ERR */
#define CAN_ERR_RECNT_Pos        24
#define CAN_ERR_RECNT_Msk        _AC(0xff000000,U)  /*!< receive error count */
#define CAN_ERR_RECNT(x)         ((x) << CAN_ERR_RECNT_Pos)
#define CAN_ERR_TECNT_Pos        16
#define CAN_ERR_TECNT_Msk        _AC(0x00ff0000,U)  /*!< transmit error count */
#define CAN_ERR_TECNT(x)         ((x) << CAN_ERR_TECNT_Pos)
#define CAN_ERR_ERRN_Pos         4
#define CAN_ERR_ERRN_Msk         _AC(0x00000070,U)  /*!< error number */
#define CAN_ERR_ERRN(x)          ((x) << CAN_ERR_ERRN_Pos)
#define CAN_ERR_BOERR            _BIT(2,U)          /*!< bus-off error */
#define CAN_ERR_PERR             _BIT(1,U)          /*!< passive error */
#define CAN_ERR_WERR             _BIT(0,U)          /*!< warning error */

/* CAN_BT */
#define CAN_BT_SCMOD             _BIT(31,U)         /*!< silent communication mode */
#define CAN_BT_LCMOD             _BIT(30,U)         /*!< loopback communication mode */
#define CAN_BT_SJW_Pos           24
#define CAN_BT_SJW_Msk           _AC(0x03000000,U)  /*!< resynchronization jump width */
#define CAN_BT_SJW(x)            ((x) << CAN_BT_SJW_Pos)
#define CAN_BT_BS2_Pos           20
#define CAN_BT_BS2_Msk           _AC(0x00700000,U)  /*!< bit segment 2 */
#define CAN_BT_BS2(x)            ((x) << CAN_BT_BS2_Pos)
#define CAN_BT_BS1_Pos           16
#define CAN_BT_BS1_Msk           _AC(0x000f0000,U)  /*!< bit segment 1 */
#define CAN_BT_BS1(x)            ((x) << CAN_BT_BS1_Pos)
#define CAN_BT_BAUDPSC_Pos       0
#define CAN_BT_BAUDPSC_Msk       _AC(0x000003ff,U)  /*!< baudrate prescaler */
#define CAN_BT_BAUDPSC(x)        ((x) << CAN_BT_BAUDPSC_Pos)

/* CAN_TMIx */
#define CAN_TMI_SFID_Pos         21
#define CAN_TMI_SFID_Msk         _AC(0xffe00000,U)  /*!< the frame identifier */
#define CAN_TMI_SFID(x)          ((x) << CAN_TMI_SFID_Pos)
#define CAN_TMI_EFID_Pos         3
#define CAN_TMI_EFID_Msk         _AC(0x001ffff8,U)  /*!< the frame identifier */
#define CAN_TMI_EFID(x)          ((x) << CAN_TMI_EFID_Pos)
#define CAN_TMI_FF               _BIT(2,U)          /*!< frame format */
#define CAN_TMI_FT               _BIT(1,U)          /*!< frame type */
#define CAN_TMI_TEN              _BIT(0,U)          /*!< transmit enable */

/* CAN_TMPx */
#define CAN_TMP_TS_Pos           16
#define CAN_TMP_TS_Msk           _AC(0xffff0000,U)  /*!< time stamp */
#define CAN_TMP_TSEN             _BIT(8,U)          /*!< time stamp enable */
#define CAN_TMP_DLENC_Pos        0
#define CAN_TMP_DLENC_Msk        _AC(0x0000000f,U)  /*!< data length code */
#define CAN_TMP_DLENC(x)         ((x) << CAN_TMP_DLENC_Pos)

/* CAN_TMDATA0x */
#define CAN_TMDATA0_DB3_Pos      24
#define CAN_TMDATA0_DB3_Msk      _AC(0xff000000,U)  /*!< transmit data byte 3 */
#define CAN_TMDATA0_DB3(x)       ((x) << CAN_TMDATA0_DB3_Pos)
#define CAN_TMDATA0_DB2_Pos      16
#define CAN_TMDATA0_DB2_Msk      _AC(0x00ff0000,U)  /*!< transmit data byte 2 */
#define CAN_TMDATA0_DB2(x)       ((x) << CAN_TMDATA0_DB2_Pos)
#define CAN_TMDATA0_DB1_Pos      8
#define CAN_TMDATA0_DB1_Msk      _AC(0x0000ff00,U)  /*!< transmit data byte 1 */
#define CAN_TMDATA0_DB1(x)       ((x) << CAN_TMDATA0_DB1_Pos)
#define CAN_TMDATA0_DB0_Pos      0
#define CAN_TMDATA0_DB0_Msk      _AC(0x000000ff,U)  /*!< transmit data byte 0 */
#define CAN_TMDATA0_DB0(x)       ((x) << CAN_TMDATA0_DB0_Pos)

/* CAN_TMDATA1x */
#define CAN_TMDATA1_DB7_Pos      24
#define CAN_TMDATA1_DB7_Msk      _AC(0xff000000,U)  /*!< transmit data byte 7 */
#define CAN_TMDATA1_DB7(x)       ((x) << CAN_TMDATA1_DB7_Pos)
#define CAN_TMDATA1_DB6_Pos      16
#define CAN_TMDATA1_DB6_Msk      _AC(0x00ff0000,U)  /*!< transmit data byte 6 */
#define CAN_TMDATA1_DB6(x)       ((x) << CAN_TMDATA1_DB6_Pos)
#define CAN_TMDATA1_DB5_Pos      8
#define CAN_TMDATA1_DB5_Msk      _AC(0x0000ff00,U)  /*!< transmit data byte 5 */
#define CAN_TMDATA1_DB5(x)       ((x) << CAN_TMDATA1_DB5_Pos)
#define CAN_TMDATA1_DB4_Pos      0
#define CAN_TMDATA1_DB4_Msk      _AC(0x000000ff,U)  /*!< transmit data byte 4 */
#define CAN_TMDATA1_DB4(x)       ((x) << CAN_TMDATA1_DB4_Pos)

/* CAN_RFIFOMIx */
#define CAN_RFIFOMI_SFID_Pos     21
#define CAN_RFIFOMI_SFID_Msk     _AC(0xffe00000,U)  /*!< the frame identifier */
#define CAN_RFIFOMI_SFID(x)      ((x) << CAN_RFIFOMI_SFID_Pos)
#define CAN_RFIFOMI_EFID_Pos     3
#define CAN_RFIFOMI_EFID_Msk     _AC(0x001ffff8,U)  /*!< the frame identifier */
#define CAN_RFIFOMI_EFID(x)      ((x) << CAN_RFIFOMI_EFID_Pos)
#define CAN_RFIFOMI_FF           _BIT(2,U)          /*!< frame format */
#define CAN_RFIFOMI_FT           _BIT(1,U)          /*!< frame type */

/* CAN_RFIFOMPx */
#define CAN_RFIFOMP_TS_Pos       16
#define CAN_RFIFOMP_TS_Msk       _AC(0xffff0000,U)  /*!< time stamp */
#define CAN_RFIFOMP_TS(x)        ((x) << CAN_RFIFOMP_TS_Pos)
#define CAN_RFIFOMP_FI_Pos       8
#define CAN_RFIFOMP_FI_Msk       _AC(0x0000ff00,U)  /*!< filter index */
#define CAN_RFIFOMP_FI(x)        ((x) << CAN_RFIFOMP_FI_Pos)
#define CAN_RFIFOMP_DLENC_Pos    0
#define CAN_RFIFOMP_DLENC_Msk    _AC(0x0000000f,U)  /*!< receive data length code */
#define CAN_RFIFOMP_DLENC(x)     ((x) << CAN_RFIFOMP_DLENC_Pos)

/* CAN_RFIFOMDATA0x */
#define CAN_RFIFOMDATA0_DB3_Pos  24
#define CAN_RFIFOMDATA0_DB3_Msk  _AC(0xff000000,U)  /*!< receive data byte 3 */
#define CAN_RFIFOMDATA0_DB3(x)   ((x) << CAN_RFIFOMDATA0_DB3_Pos)
#define CAN_RFIFOMDATA0_DB2_Pos  16
#define CAN_RFIFOMDATA0_DB2_Msk  _AC(0x00ff0000,U)  /*!< receive data byte 2 */
#define CAN_RFIFOMDATA0_DB2(x)   ((x) << CAN_RFIFOMDATA0_DB2_Pos)
#define CAN_RFIFOMDATA0_DB1_Pos  8
#define CAN_RFIFOMDATA0_DB1_Msk  _AC(0x0000ff00,U)  /*!< receive data byte 1 */
#define CAN_RFIFOMDATA0_DB1(x)   ((x) << CAN_RFIFOMDATA0_DB1_Pos)
#define CAN_RFIFOMDATA0_DB0_Pos  0
#define CAN_RFIFOMDATA0_DB0_Msk  _AC(0x000000ff,U)  /*!< receive data byte 0 */
#define CAN_RFIFOMDATA0_DB0(x)   ((x) << CAN_RFIFOMDATA0_DB0_Pos)

/* CAN_RFIFOMDATA1x */
#define CAN_RFIFOMDATA1_DB7_Pos  24
#define CAN_RFIFOMDATA1_DB7_Msk  _AC(0xff000000,U)  /*!< receive data byte 7 */
#define CAN_RFIFOMDATA1_DB7(x)   ((x) << CAN_RFIFOMDATA1_DB7_Pos)
#define CAN_RFIFOMDATA1_DB6_Pos  16
#define CAN_RFIFOMDATA1_DB6_Msk  _AC(0x00ff0000,U)  /*!< receive data byte 6 */
#define CAN_RFIFOMDATA1_DB6(x)   ((x) << CAN_RFIFOMDATA1_DB6_Pos)
#define CAN_RFIFOMDATA1_DB5_Pos  8
#define CAN_RFIFOMDATA1_DB5_Msk  _AC(0x0000ff00,U)  /*!< receive data byte 5 */
#define CAN_RFIFOMDATA1_DB5(x)   ((x) << CAN_RFIFOMDATA1_DB5_Pos)
#define CAN_RFIFOMDATA1_DB4_Pos  0
#define CAN_RFIFOMDATA1_DB4_Msk  _AC(0x000000ff,U)  /*!< receive data byte 4 */
#define CAN_RFIFOMDATA1_DB4(x)   ((x) << CAN_RFIFOMDATA1_DB4_Pos)

/* CAN_FCTL */
#define CAN_FCTL_HBC1F_Pos       8
#define CAN_FCTL_HBC1F_Msk       _AC(0x00003f00,U)  /*!< header bank of CAN1 filter */
#define CAN_FCTL_HBC1F(x)        ((x) << CAN_FCTL_HBC1F_Pos)
#define CAN_FCTL_FLD             _BIT(0,U)          /*!< filter lock disable */

/* CAN_FMCFG */
#define CAN_FMCFG_FMOD(x)        _BIT(x,U)          /*!< filter mode, list or mask*/

/* CAN_FSCFG */
#define CAN_FSCFG_FS(x)          _BIT(x,U)          /*!< filter scale, 32 bits or 16 bits*/

/* CAN_FAFIFO */
#define CAN_FAFIFOR_FAF(x)       _BIT(x,U)          /*!< filter associated with FIFO */

/* CAN_FW */
#define CAN_FW_FW(x)             _BIT(x,U)          /*!< filter working */

/* CAN_FxDATAy */
#define CAN_FDATA_FD(x)          _BIT(x,U)          /*!< filter data */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_can_mailbox {
	volatile uint32_t I;
	volatile uint32_t P;
	volatile uint32_t DATA0;
	volatile uint32_t DATA1;
};

struct gd32vf103_can_filter {
	volatile uint32_t DATA0;
	volatile uint32_t DATA1;
};

struct gd32vf103_can {
	volatile uint32_t CTL;
	volatile uint32_t STAT;
	volatile uint32_t TSTAT;
	volatile uint32_t RFIFO0;
	volatile uint32_t RFIFO1;
	volatile uint32_t INTEN;
	volatile uint32_t ERR;
	volatile uint32_t BT;
	uint32_t reserved1[88];
	union {
		struct gd32vf103_can_mailbox TM[3];
		struct {
			volatile uint32_t TMI0;
			volatile uint32_t TMP0;
			volatile uint32_t TMDATA00;
			volatile uint32_t TMDATA10;
			volatile uint32_t TMI1;
			volatile uint32_t TMP1;
			volatile uint32_t TMDATA01;
			volatile uint32_t TMDATA11;
			volatile uint32_t TMI2;
			volatile uint32_t TMP2;
			volatile uint32_t TMDATA02;
			volatile uint32_t TMDATA12;
		};
	};
	union {
		struct gd32vf103_can_mailbox RFIFOM[2];
		struct {
			volatile uint32_t RFIFOMI0;
			volatile uint32_t RFIFOMP0;
			volatile uint32_t RFIFOMDATA00;
			volatile uint32_t RFIFOMDATA10;
			volatile uint32_t RFIFOMI1;
			volatile uint32_t RFIFOMP1;
			volatile uint32_t RFIFOMDATA01;
			volatile uint32_t RFIFOMDATA11;
		};
	};
	uint32_t reserved2[12];
	volatile uint32_t FCTL;
	volatile uint32_t FMCFG;
	uint32_t reserved3;
	volatile uint32_t FSCFG;
	uint32_t reserved4;
	volatile uint32_t FAFIFO;
	uint32_t reserved5;
	volatile uint32_t FW;
	uint32_t reserved6[8];
	struct gd32vf103_can_filter F[28];
};

static struct gd32vf103_can *const CAN0 = (struct gd32vf103_can *)CAN0_BASE;
static struct gd32vf103_can *const CAN1 = (struct gd32vf103_can *)CAN1_BASE;

#endif
#endif
