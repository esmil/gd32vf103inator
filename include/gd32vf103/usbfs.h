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
#ifndef GD32VF103_USBFS_H
#define GD32VF103_USBFS_H

#include "gd32vf103.h"

#define USBFS_BASE _AC(0x50000000,UL)  /*!< USBFS base address */

/* limits */
#define USBFS_MAX_TX_FIFOS               15          /*!< FIFO number */
#define USBFS_MAX_PACKET_SIZE            _AC(64,U)   /*!< USBFS max packet size */
#define USBFS_MAX_CHANNEL_COUNT          _AC(8,U)    /*!< USBFS host channel count */
#define USBFS_MAX_EP_COUNT               _AC(4,U)    /*!< USBFS device endpoint count */
#define USBFS_MAX_FIFO_WORDLEN           _AC(320,U)  /*!< USBFS max fifo size in words */

/* register definitions */
#define USBFS_GOTGCS                     _AC(0x000,UL)  /*!< USBFS global OTG control and status register */
#define USBFS_GOTGINTF                   _AC(0x004,UL)  /*!< USBFS global OTG interrupt flag register */
#define USBFS_GAHBCS                     _AC(0x008,UL)  /*!< USBFS global AHB control and status register */
#define USBFS_GUSBCS                     _AC(0x00C,UL)  /*!< USBFS global USB control and status register */
#define USBFS_GRSTCTL                    _AC(0x010,UL)  /*!< USBFS global reset control register */
#define USBFS_GINTF                      _AC(0x014,UL)  /*!< USBFS global interrupt flag register */
#define USBFS_GINTEN                     _AC(0x018,UL)  /*!< USBFS global interrupt enable register */
#define USBFS_GRSTATR                    _AC(0x01C,UL)  /*!< USBFS receive status debug read register */
#define USBFS_GRSTATP                    _AC(0x020,UL)  /*!< USBFS receive status and pop register */
#define USBFS_GRFLEN                     _AC(0x024,UL)  /*!< USBFS global receive FIFO length register */
#define USBFS_DIEP0TFLEN_HNPTFLEN        _AC(0x028,UL)  /*!< USBFS device IN endpoint 0/host non-periodic transmit FIFO length register */
#define USBFS_HNPTFLEN                   _AC(0x028,UL)
#define USBFS_DIEP0TFLEN                 _AC(0x028,UL)
#define USBFS_HNPTFQSTAT                 _AC(0x02C,UL)  /*!< USBFS host non-periodic FIFO/queue status register */
#define USBFS_GCCFG                      _AC(0x038,UL)  /*!< USBFS global core configuration register */
#define USBFS_CID                        _AC(0x03C,UL)  /*!< USBFS core ID register */
#define USBFS_HPTFLEN                    _AC(0x100,UL)  /*!< USBFS host periodic transmit FIFO length register */
#define USBFS_DIEP1TFLEN                 _AC(0x104,UL)  /*!< USBFS device IN endpoint 1 transmit FIFO length register */
#define USBFS_DIEP2TFLEN                 _AC(0x108,UL)  /*!< USBFS device IN endpoint 2 transmit FIFO length register */
#define USBFS_DIEP3TFLEN                 _AC(0x10C,UL)  /*!< USBFS device IN endpoint 3 transmit FIFO length register */
#define USBFS_DIEPTFLEN(x)               (_AC(0x104,UL) + (4*((x) - 1)))  /*!< USBFS device IN endpoint transmit FIFO length register */

#define USBFS_HCTL                       _AC(0x400,UL)  /*!< USB host control register                             */
#define USBFS_HFT                        _AC(0x404,UL)  /*!< USB host frame interval register                      */
#define USBFS_HFINFR                     _AC(0x408,UL)  /*!< USB host frame information remaining register         */
#define USBFS_HPTFQSTAT                  _AC(0x410,UL)  /*!< USB host periodic transmit FIFO/queue status register */
#define USBFS_HACHINT                    _AC(0x414,UL)  /*!< USB host all channels interrupt register              */
#define USBFS_HACHINTEN                  _AC(0x418,UL)  /*!< USB host all channels interrupt enable register       */

#define USBFS_HPCS                       _AC(0x440,UL)  /*!< USB host port control and status register */

#define USBFS_HCHCTL(x)                  (_AC(0x500,UL) + ((x) * _AC(20,UL)))  /*!< USB host channel control register          */
#define USBFS_HCHINTF(x)                 (_AC(0x508,UL) + ((x) + _AC(20,UL)))  /*!< USB host channel interrupt flag register   */
#define USBFS_HCHINTEN(x)                (_AC(0x50C,UL) + ((x) + _AC(20,UL)))  /*!< USB host channel interrupt enable register */
#define USBFS_HCHLEN(x)                  (_AC(0x510,UL) + ((x) + _AC(20,UL)))  /*!< USB host channel transfer length register  */

#define USBFS_DCFG                       _AC(0x800,UL)  /*!< USB device configuration register                           */
#define USBFS_DCTL                       _AC(0x804,UL)  /*!< USB device control register                                 */
#define USBFS_DSTAT                      _AC(0x808,UL)  /*!< USB device status register                                  */
#define USBFS_DIEPINTEN                  _AC(0x810,UL)  /*!< USB device IN endpoint common interrupt enable register     */
#define USBFS_DOEPINTEN                  _AC(0x814,UL)  /*!< USB device OUT endpoint common interrupt enable register    */
#define USBFS_DAEPINT                    _AC(0x818,UL)  /*!< USB device all endpoints interrupt register                 */
#define USBFS_DAEPINTEN                  _AC(0x81C,UL)  /*!< USB device all endpoints interrupt enable register          */
#define USBFS_DVBUSDT                    _AC(0x828,UL)  /*!< USB device VBUS discharge time register                     */
#define USBFS_DVBUSPT                    _AC(0x82C,UL)  /*!< USB device VBUS pulsing time register                       */
#define USBFS_DIEPFEINTEN                _AC(0x834,UL)  /*!< USB device IN endpoint FIFO empty interrupt enable register */

#define USBFS_DIEPCTL(x)                 (_AC(0x900,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint control register              */
#define USBFS_DIEPINTF(x)                (_AC(0x908,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint interrupt flag register       */
#define USBFS_DIEPLEN(x)                 (_AC(0x910,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint transfer length register      */
#define USBFS_DIEPTFSTAT(x)              (_AC(0x918,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint transmit FIFO status register */
#define USBFS_DIEP0CTL                   _AC(0x900,UL)  /*!< USB device IN endpoint 0 control register              */
#define USBFS_DIEP0INTF                  _AC(0x908,UL)  /*!< USB device IN endpoint 0 interrupt flag register       */
#define USBFS_DIEP0LEN                   _AC(0x910,UL)  /*!< USB device IN endpoint 0 transfer length register      */
#define USBFS_DIEP0TFSTAT                _AC(0x918,UL)  /*!< USB device IN endpoint 0 transmit FIFO status register */
#define USBFS_DIEP1CTL                   _AC(0x920,UL)  /*!< USB device IN endpoint 1 control register              */
#define USBFS_DIEP1INTF                  _AC(0x928,UL)  /*!< USB device IN endpoint 1 interrupt flag register       */
#define USBFS_DIEP1LEN                   _AC(0x930,UL)  /*!< USB device IN endpoint 1 transfer length register      */
#define USBFS_DIEP1TFSTAT                _AC(0x938,UL)  /*!< USB device IN endpoint 1 transmit FIFO status register */
#define USBFS_DIEP2CTL                   _AC(0x940,UL)  /*!< USB device IN endpoint 2 control register              */
#define USBFS_DIEP2INTF                  _AC(0x948,UL)  /*!< USB device IN endpoint 2 interrupt flag register       */
#define USBFS_DIEP2LEN                   _AC(0x950,UL)  /*!< USB device IN endpoint 2 transfer length register      */
#define USBFS_DIEP2TFSTAT                _AC(0x958,UL)  /*!< USB device IN endpoint 2 transmit FIFO status register */
#define USBFS_DIEP3CTL                   _AC(0x960,UL)  /*!< USB device IN endpoint 3 control register              */
#define USBFS_DIEP3INTF                  _AC(0x968,UL)  /*!< USB device IN endpoint 3 interrupt flag register       */
#define USBFS_DIEP3LEN                   _AC(0x970,UL)  /*!< USB device IN endpoint 3 transfer length register      */
#define USBFS_DIEP3TFSTAT                _AC(0x978,UL)  /*!< USB device IN endpoint 3 transmit FIFO status register */

#define USBFS_DOEPCTL(x)                 (_AC(0xB00,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint control register         */
#define USBFS_DOEPINTF(x)                (_AC(0xB08,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint interrupt flag register  */
#define USBFS_DOEPLEN(x)                 (_AC(0xB10,UL) + (_AC(20,UL) * (x)))  /*!< USB device IN endpoint transfer length register */
#define USBFS_DOEP0CTL                   _AC(0xB00,UL)  /*!< USB device IN endpoint 0 control register         */
#define USBFS_DOEP0INTF                  _AC(0xB08,UL)  /*!< USB device IN endpoint 0 interrupt flag register  */
#define USBFS_DOEP0LEN                   _AC(0xB10,UL)  /*!< USB device IN endpoint 0 transfer length register */
#define USBFS_DOEP1CTL                   _AC(0xB20,UL)  /*!< USB device IN endpoint 1 control register         */
#define USBFS_DOEP1INTF                  _AC(0xB28,UL)  /*!< USB device IN endpoint 1 interrupt flag register  */
#define USBFS_DOEP1LEN                   _AC(0xB30,UL)  /*!< USB device IN endpoint 1 transfer length register */
#define USBFS_DOEP2CTL                   _AC(0xB40,UL)  /*!< USB device IN endpoint 2 control register         */
#define USBFS_DOEP2INTF                  _AC(0xB48,UL)  /*!< USB device IN endpoint 2 interrupt flag register  */
#define USBFS_DOEP2LEN                   _AC(0xB50,UL)  /*!< USB device IN endpoint 2 transfer length register */
#define USBFS_DOEP3CTL                   _AC(0xB60,UL)  /*!< USB device IN endpoint 3 control register         */
#define USBFS_DOEP3INTF                  _AC(0xB68,UL)  /*!< USB device IN endpoint 3 interrupt flag register  */
#define USBFS_DOEP3LEN                   _AC(0xB70,UL)  /*!< USB device IN endpoint 3 transfer length register */

#define USBFS_PWRCLKCTL                  _AC(0xE00,UL)  /*!< USB power and clock control register */

#define USBFS_DATA_FIFO_OFFSET           _AC(0x1000,UL)  /*!< USB data fifo offset */
#define USBFS_DATA_FIFO_SIZE             _AC(0x1000,UL)  /*!< USB data fifo size */

/* USBFS_GOTGCS */
#define USBFS_GOTGCS_BSV                 _BIT(19,U)           /*!< B-Session Valid */
#define USBFS_GOTGCS_ASV                 _BIT(18,U)           /*!< A-session valid */
#define USBFS_GOTGCS_DI                  _BIT(17,U)           /*!< debounce interval */
#define USBFS_GOTGCS_CIDPS               _BIT(16,U)           /*!< id pin status */
#define USBFS_GOTGCS_DHNPEN              _BIT(11,U)           /*!< device HNP enable */
#define USBFS_GOTGCS_HHNPEN              _BIT(10,U)           /*!< host HNP enable */
#define USBFS_GOTGCS_HNPREQ              _BIT(9,U)            /*!< HNP request */
#define USBFS_GOTGCS_HNPS                _BIT(8,U)            /*!< HNP successes */
#define USBFS_GOTGCS_SRPREQ              _BIT(1,U)            /*!< SRP request */
#define USBFS_GOTGCS_SRPS                _BIT(0,U)            /*!< SRP successes */

/* USBFS_GOTGINTF */
#define USBFS_GOTGINTF_DF                _BIT(19,U)           /*!< debounce finish */
#define USBFS_GOTGINTF_ADTO              _BIT(18,U)           /*!< A-device timeout */
#define USBFS_GOTGINTF_HNPDET            _BIT(17,U)           /*!< host negotiation request detected */
#define USBFS_GOTGINTF_HNPEND            _BIT(9,U)            /*!< HNP end */
#define USBFS_GOTGINTF_SRPEND            _BIT(8,U)            /*!< SRP end */
#define USBFS_GOTGINTF_SESEND            _BIT(2,U)            /*!< session end */

/* USBFS_GAHBCS */
#define USBFS_GAHBCS_PTXFTH              _BIT(8,U)            /*!< periodic Tx FIFO threshold */
#define USBFS_GAHBCS_TXFTH               _BIT(7,U)            /*!< tx FIFO threshold */
#if 0
#define USBFS_GAHBCS_DMAEN               _BIT(5,U)            /*!< DMA function Enable */
#define USBFS_GAHBCS_BURST_Pos           1
#define USBFS_GAHBCS_BURST_Msk           _AC(0x0000001e,U)    /*!< the AHB burst type used by DMA */
#define USBFS_GAHBCS_BURST(x)            ((x) << USBFS_GAHBCS_BURST_Pos)
#endif
#define USBFS_GAHBCS_GINTEN              _BIT(0,U)            /*!< global interrupt enable */

/* USBFS_GUSBCS */
#define USBFS_GUSBCS_FDM                 _BIT(30,U)           /*!< force device mode */
#define USBFS_GUSBCS_FHM                 _BIT(29,U)           /*!< force host mode */
#if 0
#define USBFS_GUSBCS_ULPIEOI             _BIT(21,U)           /*!< ULPI external over-current indicator */
#define USBFS_GUSBCS_ULPIEVD             _BIT(20,U)           /*!< ULPI external VBUS driver */
#endif
#define USBFS_GUSBCS_UTT_Pos             10
#define USBFS_GUSBCS_UTT_Msk             _AC(0x00003c00,U)    /*!< USB turnaround time */
#define USBFS_GUSBCS_UTT(x)              ((x) << USBFS_GUSBCS_UTT_Pos)
#define USBFS_GUSBCS_HNPCEN              _BIT(9,U)            /*!< HNP capability enable */
#define USBFS_GUSBCS_SRPCEN              _BIT(8,U)            /*!< SRP capability enable */
#if 0
#define USBFS_GUSBCS_EMBPHY              _BIT(6,U)            /*!< embedded PHY selected */
#endif
#define USBFS_GUSBCS_TOC_Pos             0
#define USBFS_GUSBCS_TOC_Msk             _AC(0x00000007,U)    /*!< timeout calibration */
#define USBFS_GUSBCS_TOC(x)              ((x) << USBFS_GUSBCS_TOC_Pos)

/* USBFS_GRSTCTL */
#define USBFS_GRSTCTL_DMAIDL             _BIT(31,U)           /*!< DMA idle state */
#define USBFS_GRSTCTL_DMABSY             _BIT(30,U)           /*!< DMA busy */
#define USBFS_GRSTCTL_TXFNUM_Pos         6
#define USBFS_GRSTCTL_TXFNUM_Msk         _AC(0x000007c0,U)    /*!< tx FIFO number */
#define USBFS_GRSTCTL_TXFNUM(x)          ((x) << USBFS_GRSTCTL_TXFNUM_Pos)
#define USBFS_GRSTCTL_TXFF               _BIT(5,U)            /*!< tx FIFO flush */
#define USBFS_GRSTCTL_RXFF               _BIT(4,U)            /*!< rx FIFO flush */
#define USBFS_GRSTCTL_HFCRST             _BIT(2,U)            /*!< host frame counter reset */
#define USBFS_GRSTCTL_HCSRST             _BIT(1,U)            /*!< HCLK soft reset */
#define USBFS_GRSTCTL_CSRST              _BIT(0,U)            /*!< core soft reset */

/* USBFS_GINTF */
#define USBFS_GINTF_WKUPIF               _BIT(31,U)           /*!< wakeup interrupt flag */
#define USBFS_GINTF_SESIF                _BIT(30,U)           /*!< session interrupt flag */
#define USBFS_GINTF_DISCIF               _BIT(29,U)           /*!< disconnect interrupt flag */
#define USBFS_GINTF_IDPSC                _BIT(28,U)           /*!< id pin status change */
#define USBFS_GINTF_PTXFEIF              _BIT(26,U)           /*!< periodic tx FIFO empty interrupt flag */
#define USBFS_GINTF_HCIF                 _BIT(25,U)           /*!< host channels interrupt flag */
#define USBFS_GINTF_HPIF                 _BIT(24,U)           /*!< host port interrupt flag */
#define USBFS_GINTF_PXNCIF               _BIT(21,U)           /*!< periodic transfer not complete interrupt flag */
#define USBFS_GINTF_ISOONCIF             _BIT(21,U)           /*!< isochronous OUT transfer not complete interrupt flag */
#define USBFS_GINTF_ISOINCIF             _BIT(20,U)           /*!< isochronous IN transfer not complete interrupt flag */
#define USBFS_GINTF_OEPIF                _BIT(19,U)           /*!< OUT endpoint interrupt flag */
#define USBFS_GINTF_IEPIF                _BIT(18,U)           /*!< IN endpoint interrupt flag */
#define USBFS_GINTF_EOPFIF               _BIT(15,U)           /*!< end of periodic frame interrupt flag */
#define USBFS_GINTF_ISOOPDIF             _BIT(14,U)           /*!< isochronous OUT packet dropped interrupt flag */
#define USBFS_GINTF_ENUMF                _BIT(13,U)           /*!< enumeration finished */
#define USBFS_GINTF_RST                  _BIT(12,U)           /*!< USB reset */
#define USBFS_GINTF_SP                   _BIT(11,U)           /*!< USB suspend */
#define USBFS_GINTF_ESP                  _BIT(10,U)           /*!< early suspend */
#define USBFS_GINTF_GONAK                _BIT(7,U)            /*!< global OUT NAK effective */
#define USBFS_GINTF_GNPINAK              _BIT(6,U)            /*!< global IN non-periodic NAK effective */
#define USBFS_GINTF_NPTXFEIF             _BIT(5,U)            /*!< non-periodic tx FIFO empty interrupt flag */
#define USBFS_GINTF_RXFNEIF              _BIT(4,U)            /*!< rx FIFO non-empty interrupt flag */
#define USBFS_GINTF_SOF                  _BIT(3,U)            /*!< start of frame */
#define USBFS_GINTF_OTGIF                _BIT(2,U)            /*!< OTG interrupt flag */
#define USBFS_GINTF_MFIF                 _BIT(1,U)            /*!< mode fault interrupt flag */
#define USBFS_GINTF_COPM                 _BIT(0,U)            /*!< current operation mode */

/* USBFS_GINTEN */
#define USBFS_GINTEN_WKUPIE              _BIT(31,U)           /*!< wakeup interrupt enable */
#define USBFS_GINTEN_SESIE               _BIT(30,U)           /*!< session interrupt enable */
#define USBFS_GINTEN_DISCIE              _BIT(29,U)           /*!< disconnect interrupt enable */
#define USBFS_GINTEN_IDPSCIE             _BIT(28,U)           /*!< id pin status change interrupt enable */
#define USBFS_GINTEN_PTXFEIE             _BIT(26,U)           /*!< periodic tx FIFO empty interrupt enable */
#define USBFS_GINTEN_HCIE                _BIT(25,U)           /*!< host channels interrupt enable */
#define USBFS_GINTEN_HPIE                _BIT(24,U)           /*!< host port interrupt enable */
#define USBFS_GINTEN_IPXIE               _BIT(21,U)           /*!< periodic transfer not complete interrupt enable */
#define USBFS_GINTEN_ISOONCIE            _BIT(21,U)           /*!< isochronous OUT transfer not complete interrupt enable */
#define USBFS_GINTEN_ISOINCIE            _BIT(20,U)           /*!< isochronous IN transfer not complete interrupt enable */
#define USBFS_GINTEN_OEPIE               _BIT(19,U)           /*!< OUT endpoints interrupt enable */
#define USBFS_GINTEN_IEPIE               _BIT(18,U)           /*!< IN endpoints interrupt enable */
#define USBFS_GINTEN_EOPFIE              _BIT(15,U)           /*!< end of periodic frame interrupt enable */
#define USBFS_GINTEN_ISOOPDIE            _BIT(14,U)           /*!< isochronous OUT packet dropped interrupt enable */
#define USBFS_GINTEN_ENUMFIE             _BIT(13,U)           /*!< enumeration finish enable */
#define USBFS_GINTEN_RSTIE               _BIT(12,U)           /*!< USB reset interrupt enable */
#define USBFS_GINTEN_SPIE                _BIT(11,U)           /*!< USB suspend interrupt enable */
#define USBFS_GINTEN_ESPIE               _BIT(10,U)           /*!< early suspend interrupt enable */
#define USBFS_GINTEN_GONAKIE             _BIT(7,U)            /*!< global OUT NAK effective interrupt enable */
#define USBFS_GINTEN_GNPINAKIE           _BIT(6,U)            /*!< global non-periodic IN NAK effective interrupt enable */
#define USBFS_GINTEN_NPTXFEIE            _BIT(5,U)            /*!< non-periodic Tx FIFO empty interrupt enable */
#define USBFS_GINTEN_RXFNEIE             _BIT(4,U)            /*!< receive FIFO non-empty interrupt enable */
#define USBFS_GINTEN_SOFIE               _BIT(3,U)            /*!< start of frame interrupt enable */
#define USBFS_GINTEN_OTGIE               _BIT(2,U)            /*!< OTG interrupt enable */
#define USBFS_GINTEN_MFIE                _BIT(1,U)            /*!< mode fault interrupt enable */

/* USBFS_GRSTATx, x=R,P */
#define USBFS_GRSTAT_RPCKST_Pos          17
#define USBFS_GRSTAT_RPCKST_Msk          _AC(0x001e0000,U)    /*!< received packet status */
#define USBFS_GRSTAT_RPCKST(x)           ((x) << USBFS_GRSTAT_RPCKST_Pos)
#define USBFS_GRSTAT_RPCKST_GONAK        USBFS_GRSTAT_RPCKST(1)
#define USBFS_GRSTAT_RPCKST_PKT          USBFS_GRSTAT_RPCKST(2)
#define USBFS_GRSTAT_RPCKST_TF           USBFS_GRSTAT_RPCKST(3)
#define USBFS_GRSTAT_RPCKST_STPF         USBFS_GRSTAT_RPCKST(4)
#define USBFS_GRSTAT_RPCKST_STP          USBFS_GRSTAT_RPCKST(6)
#define USBFS_GRSTAT_DPID_Pos            15
#define USBFS_GRSTAT_DPID_Msk            _AC(0x00018000,U)    /*!< data PID */
#define USBFS_GRSTAT_DPID(x)             ((x) << USBFS_GRSTAT_DPID_Pos)
#define USBFS_GRSTAT_BCOUNT_Pos          4
#define USBFS_GRSTAT_BCOUNT_Msk          _AC(0x00007ff0,U)    /*!< byte count */
#define USBFS_GRSTAT_BCOUNT(x)           ((x) << USBFS_GRSTAT_BCOUNT_Pos)
#define USBFS_GRSTAT_CNUM_Pos            0
#define USBFS_GRSTAT_CNUM_Msk            _AC(0x0000000f,U)    /*!< channel number */
#define USBFS_GRSTAT_CNUM(x)             ((x) << USBFS_GRSTAT_CNUM_Pos)
#define USBFS_GRSTAT_EPNUM_Pos           0
#define USBFS_GRSTAT_EPNUM_Msk           _AC(0x0000000f,U)    /*!< endpoint number */
#define USBFS_GRSTAT_EPNUM(x)            ((x) << USBFS_GRSTAT_EPNUM_Pos)

/* USBFS_GRFLEN */
#define USBFS_GRFLEN_RXFD_Pos            0
#define USBFS_GRFLEN_RXFD_Msk            _AC(0x0000ffff,U)    /*!< rx FIFO depth */
#define USBFS_GRFLEN_RXFD(x)             ((x) << USBFS_GRFLEN_RXFD_Pos)

/* USBFS_HNPTFLEN */
#define USBFS_HNPTFLEN_HNPTXFD_Pos       16
#define USBFS_HNPTFLEN_HNPTXFD_Msk       _AC(0xffff0000,U)    /*!< non-periodic Tx FIFO depth */
#define USBFS_HNPTFLEN_HNPTXFD(x)        ((x) << USBFS_HNPTFLEN_HNPTXFD_Pos)
#define USBFS_HNPTFLEN_HNPTXRSAR_Pos     0
#define USBFS_HNPTFLEN_HNPTXRSAR_Msk     _AC(0x0000ffff,U)    /*!< non-periodic Tx RAM start address */
#define USBFS_HNPTFLEN_HNPTXRSAR(x)      ((x) << USBFS_HNPTFLEN_HNPTXRSAR_Pos)

/* USBFS_DIEP0TFLEN */
#define USBFS_DIEP0TFLEN_IEP0TXFD_Pos    16
#define USBFS_DIEP0TFLEN_IEP0TXFD_Msk    _AC(0xffff0000,U)    /*!< IN Endpoint 0 Tx FIFO depth */
#define USBFS_DIEP0TFLEN_IEP0TXFD(x)     ((x) << USBFS_DIEP0TFLEN_IEP0TXFD_Pos)
#define USBFS_DIEP0TFLEN_IEP0TXRSAR_Pos  0
#define USBFS_DIEP0TFLEN_IEP0TXRSAR_Msk  _AC(0x0000ffff,U)    /*!< IN Endpoint 0 TX RAM start address */
#define USBFS_DIEP0TFLEN_IEP0TXRSAR(x)   ((x) << USBFS_DIEP0TFLEN_IEP0TXRSAR_Pos)

/* USBFS_HNPTFQSTAT */
#define USBFS_HNPTFQSTAT_NPTXRQTOP_Pos   24
#define USBFS_HNPTFQSTAT_NPTXRQTOP_Msk   _AC(0x7f000000,U)    /*!< top entry of the non-periodic Tx request queue */
#define USBFS_HNPTFQSTAT_NPTXRQTOP(x)    ((x) << USBFS_HNPTFQSTAT_NPTXRQTOP_Pos)
#define USBFS_HNPTFQSTAT_NPTXRQS_Pos     16
#define USBFS_HNPTFQSTAT_NPTXRQS_Msk     _AC(0x00ff0000,U)    /*!< non-periodic Tx request queue space */
#define USBFS_HNPTFQSTAT_NPTXRQS(x)      ((x) << USBFS_HNPTFQSTAT_NPTXRQS_Pos)
#define USBFS_HNPTFQSTAT_NPTXFS_Pos      0
#define USBFS_HNPTFQSTAT_NPTXFS_Msk      _AC(0x0000ffff,U)    /*!< non-periodic Tx FIFO space */
#define USBFS_HNPTFQSTAT_NPTXFS(x)       ((x) << USBFS_HNPTFQSTAT_NPTXFS_Pos)
#if 0
#define USBFS_HNPTFQSTAT_CNUM            BITS(27, 30)         /*!< channel number*/
#define USBFS_HNPTFQSTAT_EPNUM           BITS(27, 30)         /*!< endpoint number */
#define USBFS_HNPTFQSTAT_TYPE            BITS(25, 26)         /*!< token type */
#define USBFS_HNPTFQSTAT_TMF             _BIT(24,U)           /*!< terminate flag */
#endif

/* USBFS_GCCFG */
#define USBFS_GCCFG_VBUSIG               _BIT(21,U)           /*!< vbus ignored */
#define USBFS_GCCFG_SOFOEN               _BIT(20,U)           /*!< SOF output enable */
#define USBFS_GCCFG_VBUSBCEN             _BIT(19,U)           /*!< the VBUS B-device comparer enable */
#define USBFS_GCCFG_VBUSACEN             _BIT(18,U)           /*!< the VBUS A-device comparer enable */
#define USBFS_GCCFG_PWRON                _BIT(16,U)           /*!< power on */

/* USBFS_CID */
#define USBFS_CID_CID_Pos                0
#define USBFS_CID_CID_Msk                _AC(0xffffffff,U)    /*!< core ID */
#define USBFS_CID_CID(x)                 ((x) << USBFS_CID_CID_Pos)

/* USBFS_HPTFLEN */
#define USBFS_HPTFLEN_HPTXFD_Pos         16
#define USBFS_HPTFLEN_HPTXFD_Msk         _AC(0xffff0000,U)    /*!< host periodic Tx FIFO depth */
#define USBFS_HPTFLEN_HPTXFD(x)          ((x) << USBFS_HPTFLEN_HPTXFD_Pos)
#define USBFS_HPTFLEN_HPTXFSAR_Pos       0
#define USBFS_HPTFLEN_HPTXFSAR_Msk       _AC(0x0000ffff,U)    /*!< host periodic Tx RAM start address */
#define USBFS_HPTFLEN_HPTXFSAR(x)        ((x) << USBFS_HPTFLEN_HPTXFSAR_Pos)

/* USBFS_DIEPxTFLEN, x = 1..3 */
#define USBFS_DIEPTFLEN_IEPTXFD_Pos      16
#define USBFS_DIEPTFLEN_IEPTXFD_Msk      _AC(0xffff0000,U)    /*!< IN endpoint Tx FIFO x depth */
#define USBFS_DIEPTFLEN_IEPTXFD(x)       ((x) << USBFS_DIEPTFLEN_IEP0TXFD_Pos)
#define USBFS_DIEPTFLEN_IEPTXRSAR_Pos    0
#define USBFS_DIEPTFLEN_IEPTXRSAR_Msk    _AC(0x0000ffff,U)    /*!< IN endpoint FIFOx Tx x RAM start address */
#define USBFS_DIEPTFLEN_IEPTXRSAR(x)     ((x) << USBFS_DIEPTFLEN_IEPTXRSAR_Pos)

/* USBFS_HCTL */
#if 0
#define USBFS_HCTL_SPDFSLS               _BIT(2,U)            /*!< speed limited to FS and LS */
#endif
#define USBFS_HCTL_CLKSEL_Pos            0
#define USBFS_HCTL_CLKSEL_Msk            _AC(0x00000003,U)    /*!< clock select for USB clock */
#define USBFS_HCTL_CLKSEL(x)             ((x) << USBFS_HCTL_CLKSEL_Pos)
#define USBFS_HCTL_CLKSEL_48MHZ          USBFS_HCTL_CLKSEL(1)

/* USBFS_HFT */
#define USBFS_HFT_FRI_Pos                0
#define USBFS_HFT_FRI_Msk                _AC(0x0000ffff,U)    /*!< frame interval */

/* USBFS_HFINFR */
#define USBFS_HFINFR_FRT_Pos             16
#define USBFS_HFINFR_FRT_Msk             _AC(0xffff0000,U)    /*!< frame remaining time */
#define USBFS_HFINFR_FRT(x)              ((x) << USBFS_HFINFR_FRT_Pos)
#define USBFS_HFINFR_FRNUM_Pos           0
#define USBFS_HFINFR_FRNUM_Msk           _AC(0x0000ffff,U)    /*!< frame number */
#define USBFS_HFINFR_FRNUM(x)            ((x) << USBFS_HFINFR_FRNUM_Pos)

/* USBFS_HPTFQSTAT */
#define USBFS_HPTFQSTAT_PTXREQT_Pos      24
#define USBFS_HPTFQSTAT_PTXREQT_Msk      _AC(0xff000000,U)    /*!< top entry of the periodic Tx request queue */
#define USBFS_HPTFQSTAT_PTXREQT(x)       ((x) << USBFS_HPTFQSTAT_PTXREQT_Pos)
#define USBFS_HPTFQSTAT_PTXREQS_Pos      16
#define USBFS_HPTFQSTAT_PTXREQS_Msk      _AC(0x00ff0000,U)    /*!< periodic Tx request queue space */
#define USBFS_HPTFQSTAT_PTXREQS(x)       ((x) << USBFS_HPTFQSTAT_PTXREQS_Pos)
#define USBFS_HPTFQSTAT_PTXFS_Pos        0
#define USBFS_HPTFQSTAT_PTXFS_Msk        _AC(0x0000ffff,U)    /*!< periodic Tx FIFO space */
#define USBFS_HPTFQSTAT_PTXFS(x)         ((x) << USBFS_HPTFQSTAT_PTXFS_Pos)
#if 0
#define USBFS_HPTFQSTAT_OEFRM            _BIT(31,U)           /*!< odd/eveb frame */
#define USBFS_HPTFQSTAT_CNUM             BITS(27, 30)         /*!< channel number */
#define USBFS_HPTFQSTAT_EPNUM            BITS(27, 30)         /*!< endpoint number */
#define USBFS_HPTFQSTAT_TYPE             BITS(25, 26)         /*!< token type */
#define USBFS_HPTFQSTAT_TMF              _BIT(24,U)           /*!< terminate flag */
#endif

/* USBFS_HACHINT */
#define USBFS_HACHINT_HACHINT_Pos        0
#define USBFS_HACHINT_HACHINT_Msk        _AC(0x000000ff,U)    /*!< host all channel interrupts */
#define USBFS_HACHINT_HACHINT(x)         ((x) << USBFS_HACHINT_HACHINT_Pos)

/* USBFS_HACHINTEN */
#define USBFS_HACHINTEN_CINTEN_Pos       0
#define USBFS_HACHINTEN_CINTEN_Msk       _AC(0x000000ff,U)    /*!< channel interrupt enable */
#define USBFS_HACHINTEN_CINTEN(x)        ((x) << USBFS_HACHINTEN_CINTEN_Pos)

/* USBFS_HPCS */
#define USBFS_HPCS_PS_Pos                17
#define USBFS_HPCS_PS_Msk                _AC(0x00060000,U)    /*!< port speed */
#define USBFS_HPCS_PS(x)                 ((x) << USBFS_HPCS_PS_Pos)
#define USBFS_HPCS_PS_FULL               USBFS_HPCS_PS(1)     /*!< full speed */
#define USBFS_HPCS_PS_LOW                USBFS_HPCS_PS(2)     /*!< low speed */
#define USBFS_HPCS_PP                    _BIT(12,U)           /*!< port power */
#define USBFS_HPCS_PLST_Pos              10
#define USBFS_HPCS_PLST_Msk              _AC(0x00000c00,U)    /*!< port line status */
#define USBFS_HPCS_PLST(x)               ((x) << USBFS_HPCS_PLST_Pos)
#define USBFS_HPCS_PRST                  _BIT(8,U)            /*!< port reset */
#define USBFS_HPCS_PSP                   _BIT(7,U)            /*!< port suspend */
#define USBFS_HPCS_PREM                  _BIT(6,U)            /*!< port resume */
#define USBFS_HPCS_PEDC                  _BIT(3,U)            /*!< port enable/disable change */
#define USBFS_HPCS_PE                    _BIT(2,U)            /*!< port enable */
#define USBFS_HPCS_PCD                   _BIT(1,U)            /*!< port connect detected */
#define USBFS_HPCS_PCST                  _BIT(0,U)            /*!< port connect status */

/* USBFS_HCHCTL */
#define USBFS_HCHCTL_CEN                 _BIT(31,U)           /*!< channel enable */
#define USBFS_HCHCTL_CDIS                _BIT(30,U)           /*!< channel disable */
#define USBFS_HCHCTL_ODDFRM              _BIT(29,U)           /*!< odd frame */
#define USBFS_HCHCTL_DAR_Pos             22
#define USBFS_HCHCTL_DAR_Msk             _AC(0x1fc00000,U)    /*!< device address */
#define USBFS_HCHCTL_DAR(x)              ((x) << USBFS_HCHCTL_DAR_Pos)
#define USBFS_HCHCTL_MPC_Pos             20
#define USBFS_HCHCTL_MPC_Msk             _AC(0x00300000,U)    /*!< multiple packet count */
#define USBFS_HCHCTL_MPC(x)              ((x) << USBFS_HCHCTL_MPC_Pos)
#define USBFS_HCHCTL_EPTYPE_Pos          18
#define USBFS_HCHCTL_EPTYPE_Msk          _AC(0x000c0000,U)    /*!< endpoint type */
#define USBFS_HCHCTL_EPTYPE(x)           ((x) << USBFS_HCHCTL_EPTYPE_Pos)
#define USBFS_HCHCTL_LSD                 _BIT(17,U)           /*!< low-speed device */
#define USBFS_HCHCTL_EPDIR               _BIT(15,U)           /*!< endpoint direction */
#define USBFS_HCHCTL_EPNUM_Pos           11
#define USBFS_HCHCTL_EPNUM_Msk           _AC(0x00007800,U)    /*!< endpoint number */
#define USBFS_HCHCTL_EPNUM(x)            ((x) << USBFS_HCHCTL_EPNUM_Pos)
#define USBFS_HCHCTL_MPL_Pos             0
#define USBFS_HCHCTL_MPL_Msk             _AC(0x000007ff,U)    /*!< maximum packet length */
#define USBFS_HCHCTL_MPL(x)              ((x) << USBFS_HCHCTL_MPL_Pos)

#if 0
/* USBFS_HCHSTCTL */
#define USBFS_HCHSTCTL_SPLEN             _BIT(31,U)           /*!< enable high-speed split transaction */
#define USBFS_HCHSTCTL_CSPLT             _BIT(16,U)           /*!< complete-split enable */
#define USBFS_HCHSTCTL_ISOPCE            BITS(14, 15)         /*!< isochronous OUT payload continuation encoding */
#define USBFS_HCHSTCTL_HADDR             BITS(7, 13)          /*!< HUB address */
#define USBFS_HCHSTCTL_PADDR             BITS(0, 6)           /*!< port address */
#endif

/* USBFS_HCHINTF */
#define USBFS_HCHINTF_DTER               _BIT(10,U)           /*!< data toggle error */
#define USBFS_HCHINTF_REQOVR             _BIT(9,U)            /*!< request queue overrun */
#define USBFS_HCHINTF_BBER               _BIT(8,U)            /*!< babble error */
#define USBFS_HCHINTF_USBER              _BIT(7,U)            /*!< USB bus Error */
#if 0
#define USBFS_HCHINTF_NYET               _BIT(6,U)            /*!< NYET */
#endif
#define USBFS_HCHINTF_ACK                _BIT(5,U)            /*!< ACK */
#define USBFS_HCHINTF_NAK                _BIT(4,U)            /*!< NAK */
#define USBFS_HCHINTF_STALL              _BIT(3,U)            /*!< STALL */
#if 0
#define USBFS_HCHINTF_DMAER              _BIT(2,U)            /*!< DMA error */
#endif
#define USBFS_HCHINTF_CH                 _BIT(1,U)            /*!< channel halted */
#define USBFS_HCHINTF_TF                 _BIT(0,U)            /*!< transfer finished */

/* USBFS_HCHINTEN */
#define USBFS_HCHINTEN_DTERIE            _BIT(10,U)           /*!< data toggle error interrupt enable */
#define USBFS_HCHINTEN_REQOVRIE          _BIT(9,U)            /*!< request queue overrun interrupt enable */
#define USBFS_HCHINTEN_BBERIE            _BIT(8,U)            /*!< babble error interrupt enable */
#define USBFS_HCHINTEN_USBERIE           _BIT(7,U)            /*!< USB bus error interrupt enable */
#if 0
#define USBFS_HCHINTEN_NYETIE            _BIT(6,U)            /*!< NYET interrupt enable */
#endif
#define USBFS_HCHINTEN_ACKIE             _BIT(5,U)            /*!< ACK interrupt enable */
#define USBFS_HCHINTEN_NAKIE             _BIT(4,U)            /*!< NAK interrupt enable */
#define USBFS_HCHINTEN_STALLIE           _BIT(3,U)            /*!< STALL interrupt enable */
#if 0
#define USBFS_HCHINTEN_DMAERIE           _BIT(2,U)            /*!< DMA error interrupt enable */
#endif
#define USBFS_HCHINTEN_CHIE              _BIT(1,U)            /*!< channel halted interrupt enable */
#define USBFS_HCHINTEN_TFIE              _BIT(0,U)            /*!< transfer finished interrupt enable */

/* USBFS_HCHLEN */
#if 0
#define USBFS_HCHLEN_PING                _BIT(31,U)           /*!< PING token request */
#endif
#define USBFS_HCHLEN_DPID_Pos            29
#define USBFS_HCHLEN_DPID_Msk            _AC(0x60000000,U)    /*!< data PID */
#define USBFS_HCHLEN_DPID(x)             ((x) << USBFS_HCHLEN_DPID_Pos)
#define USBFS_HCHLEN_PCNT_Pos            19
#define USBFS_HCHLEN_PCNT_Msk            _AC(0x1ff80000,U)    /*!< packet count */
#define USBFS_HCHLEN_PCNT(x)             ((x) << USBFS_HCHLEN_PCNT_Pos)
#define USBFS_HCHLEN_TLEN_Pos            0
#define USBFS_HCHLEN_TLEN_Msk            _AC(0x0007ffff,U)    /*!< transfer length */
#define USBFS_HCHLEN_TLEN(x)             ((x) << USBFS_HCHLEN_TLEN_Pos)

/* USBFS_DCFG */
#define USBFS_DCFG_EOPFT_Pos             11
#define USBFS_DCFG_EOPFT_Msk             _AC(0x00001800,U)    /*!< end of periodic frame time */
#define USBFS_DCFG_EOPFT(x)              ((x) << USBFS_DCFG_EOPFT_Pos)
#define USBFS_DCFG_EOPFT_80PCT           USBFS_DCFG_EOPFT(0)  /*!< 80% of the frame time */
#define USBFS_DCFG_EOPFT_85PCT           USBFS_DCFG_EOPFT(1)  /*!< 85% of the frame time */
#define USBFS_DCFG_EOPFT_90PCT           USBFS_DCFG_EOPFT(2)  /*!< 90% of the frame time */
#define USBFS_DCFG_EOPFT_95PCT           USBFS_DCFG_EOPFT(3)  /*!< 95% of the frame time */
#define USBFS_DCFG_DAR_Pos               4
#define USBFS_DCFG_DAR_Msk               _AC(0x000007f0,U)    /*!< device address */
#define USBFS_DCFG_DAR(x)                ((x) << USBFS_DCFG_DAR_Pos)
#define USBFS_DCFG_NZLSOH                _BIT(2,U)            /*!< non-zero-length status OUT handshake */
#define USBFS_DCFG_DS_Pos                0
#define USBFS_DCFG_DS_Msk                _AC(0x00000003,U)    /*!< device speed */
#define USBFS_DCFG_DS(x)                 ((x) << USBFS_DCFG_DS_Pos)
#define USBFS_DCFG_DS_FULL               USBFS_DCFG_DS(3)

/* USBFS_DCTL */
#define USBFS_DCTL_POIF                  _BIT(11,U)           /*!< power-on initialization finished */
#define USBFS_DCTL_CGONAK                _BIT(10,U)           /*!< clear global OUT NAK */
#define USBFS_DCTL_SGONAK                _BIT(9,U)            /*!< set global OUT NAK */
#define USBFS_DCTL_CGINAK                _BIT(8,U)            /*!< clear global IN NAK */
#define USBFS_DCTL_SGINAK                _BIT(7,U)            /*!< set global IN NAK */
#define USBFS_DCTL_GONS                  _BIT(3,U)            /*!< global OUT NAK status */
#define USBFS_DCTL_GINS                  _BIT(2,U)            /*!< global IN NAK status */
#define USBFS_DCTL_SD                    _BIT(1,U)            /*!< soft disconnect */
#define USBFS_DCTL_RWKUP                 _BIT(0,U)            /*!< remote wakeup */

/* USBFS_DSTAT */
#define USBFS_DSTAT_FNRSOF_Pos           8
#define USBFS_DSTAT_FNRSOF_Msk           _AC(0x003fff00,U)    /*!< the frame number of the received SOF. */
#define USBFS_DSTAT_FNRSOF(x)            ((x) << USBFS_DSTAT_FNRSOF_Pos)
#define USBFS_DSTAT_ES_Pos               1
#define USBFS_DSTAT_ES_Msk               _AC(0x00000006,U)    /*!< enumerated speed */
#define USBFS_DSTAT_ES(x)                ((x) << USBFS_DSTAT_ES_Pos)
#define USBFS_DSTAT_ES_FULL              USBFS_DSTAT_ES(3)
#define USBFS_DSTAT_SPST                 _BIT(0,U)            /*!< suspend status */

/* USBFS_DIEPINTEN */
#if 0
#define USBFS_DIEPINTEN_NAKEN            _BIT(13,U)           /*!< NAK handshake sent by USBHS interrupt enable bit */
#define USBFS_DIEPINTEN_TXFEEN           _BIT(7,U)            /*!< transmit FIFO empty interrupt enable bit */
#endif
#define USBFS_DIEPINTEN_IEPNEEN          _BIT(6,U)            /*!< IN endpoint NAK effective interrupt enable bit */
#define USBFS_DIEPINTEN_EPTXFUDEN        _BIT(4,U)            /*!< endpoint Tx FIFO underrun interrupt enable bit */
#define USBFS_DIEPINTEN_CITOEN           _BIT(3,U)            /*!< control In Timeout interrupt enable bit */
#define USBFS_DIEPINTEN_EPDISEN          _BIT(1,U)            /*!< endpoint disabled interrupt enable bit */
#define USBFS_DIEPINTEN_TFEN             _BIT(0,U)            /*!< transfer finished interrupt enable bit */ 

/* USBFS_DOEPINTEN */
#if 0
#define USBFS_DOEPINTEN_NYETEN           _BIT(14,U)           /*!< NYET handshake is sent interrupt enable bit */
#endif
#define USBFS_DOEPINTEN_BTBSTPEN         _BIT(6,U)            /*!< back-to-back SETUP packets interrupt enable bit */
#define USBFS_DOEPINTEN_EPRXFOVREN       _BIT(4,U)            /*!< endpoint Rx FIFO overrun interrupt enable bit */
#define USBFS_DOEPINTEN_STPFEN           _BIT(3,U)            /*!< SETUP phase finished interrupt enable bit */
#define USBFS_DOEPINTEN_EPDISEN          _BIT(1,U)            /*!< endpoint disabled interrupt enable bit */
#define USBFS_DOEPINTEN_TFEN             _BIT(0,U)            /*!< transfer finished interrupt enable bit */

/* USBFS_DAEPINT */
#define USBFS_DAEPINT_OEPITB_Pos         16
#define USBFS_DAEPINT_OEPITB_Msk         _AC(0x000f0000,U)    /*!< device all OUT endpoint interrupt bits */
#define USBFS_DAEPINT_OEPITB(x)          ((x) << USBFS_DAEPINT_OEPITB_Pos)
#define USBFS_DAEPINT_IEPITB_Pos         0
#define USBFS_DAEPINT_IEPITB_Msk         _AC(0x0000000f,U)    /*!< device all IN endpoint interrupt bits */
#define USBFS_DAEPINT_IEPITB(x)          ((x) << USBFS_DAEPINT_IEPITB_Pos)

/* USBFS_DAEPINTEN */
#define USBFS_DAEPINTEN_OEPIE_Pos        16
#define USBFS_DAEPINTEN_OEPIE_Msk        _AC(0x000f0000,U)    /*!< OUT endpoint interrupt enable */
#define USBFS_DAEPINTEN_OEPIE(x)         ((x) << USBFS_DAEPINTEN_OEPIE_Pos)
#define USBFS_DAEPINTEN_IEPIE_Pos        0
#define USBFS_DAEPINTEN_IEPIE_Msk        _AC(0x0000000f,U)    /*!< IN endpoint interrupt enable */
#define USBFS_DAEPINTEN_IEPIE(x)         ((x) << USBFS_DAEPINTEN_IEPIE_Pos)

/* USBFS_DVBUSDT */
#define USBFS_DVBUSDT_DVBUSDT_Pos        0
#define USBFS_DVBUSDT_DVBUSDT_Msk        _AC(0x0000ffff,U)    /*!< device VBUS discharge time */
#define USBFS_DVBUSDT_DVBUSDT(x)         ((x) << USBFS_DVBUSDT_DVBUSDT_Pos)

/* USBFS_DVBUSPT */
#define USBFS_DVBUSPT_DVBUSPT_Pos        0
#define USBFS_DVBUSPT_DVBUSPT_Msk        _AC(0x00000fff,U)    /*!< device VBUS pulsing time */
#define USBFS_DVBUSPT_DVBUSPT(x)         ((x) << USBFS_DVBUSDT_DVBUSDT_Pos)

/* USBFS_DIEPFEINTEN */
#define USBFS_DIEPFEINTEN_IEPTXFEIE_Pos  0
#define USBFS_DIEPFEINTEN_IEPTXFEIE_Msk  _AC(0x0000000f,U)    /*!< IN endpoint Tx FIFO empty interrupt enable bits */
#define USBFS_DIEPFEINTEN_IEPTXFEIE(x)   ((x) << USBFS_DIEPFEINTEN_IEPTXFEIE_Pos)

/* USBFS_DIEPxCTL, x = 0..3 */
#define USBFS_DIEPCTL_EPEN               _BIT(31,U)           /*!< IN endpoint enable */
#define USBFS_DIEPCTL_EPD                _BIT(30,U)           /*!< IN endpoint disable */
#define USBFS_DIEPCTL_SODDFRM            _BIT(29,U)           /*!< IN endpoint set odd frame */
#define USBFS_DIEPCTL_SD1PID             _BIT(29,U)           /*!< IN endpoint set DATA1 PID */
#define USBFS_DIEPCTL_SEVENFRM           _BIT(28,U)           /*!< IN endpoint set even frame */
#define USBFS_DIEPCTL_SD0PID             _BIT(28,U)           /*!< IN endpoint set DATA0 PID */
#define USBFS_DIEPCTL_SNAK               _BIT(27,U)           /*!< IN endpoint set NAK */
#define USBFS_DIEPCTL_CNAK               _BIT(26,U)           /*!< IN endpoint clear NAK */
#define USBFS_DIEPCTL_TXFNUM_Pos         22
#define USBFS_DIEPCTL_TXFNUM_Msk         _AC(0x03c00000,U)    /*!< IN tx FIFO number */
#define USBFS_DIEPCTL_TXFNUM(x)          ((x) << USBFS_DIEPCTL_TXFNUM_Pos)
#define USBFS_DIEPCTL_STALL              _BIT(21,U)           /*!< IN STALL handshake */
#define USBFS_DIEPCTL_EPTYPE_Pos         18
#define USBFS_DIEPCTL_EPTYPE_Msk         _AC(0x000c0000,U)    /*!< IN endpoint type */
#define USBFS_DIEPCTL_EPTYPE(x)          ((x) << USBFS_DIEPCTL_EPTYPE_Pos)
#define USBFS_DIEPCTL_EPTYPE_CONTROL     USBFS_DIEPCTL_EPTYPE(0)
#define USBFS_DIEPCTL_EPTYPE_ISO         USBFS_DIEPCTL_EPTYPE(1)
#define USBFS_DIEPCTL_EPTYPE_BULK        USBFS_DIEPCTL_EPTYPE(2)
#define USBFS_DIEPCTL_EPTYPE_INTERRUPT   USBFS_DIEPCTL_EPTYPE(3)
#define USBFS_DIEPCTL_NAKS               _BIT(17,U)           /*!< IN NAK status */
#define USBFS_DIEPCTL_EOFRM              _BIT(16,U)           /*!< IN even/odd frame */
#define USBFS_DIEPCTL_DPID               _BIT(16,U)           /*!< IN endpoint data PID */
#define USBFS_DIEPCTL_EPACT              _BIT(15,U)           /*!< IN endpoint active */
#define USBFS_DIEPCTL_MPL_Pos            0
#define USBFS_DIEPCTL_MPL_Msk            _AC(0x000007ff,U)    /*!< IN maximum packet length */
#define USBFS_DIEPCTL_MPL(x)             ((x) << USBFS_DIEPCTL_MPL_Pos)
/* specific to endpoint 0 */
#define USBFS_DIEP0CTL_MPL_Pos           0
#define USBFS_DIEP0CTL_MPL_Msk           _AC(0x00000003,U)    /*!< IN endpoint 0 maximum packet length */
#define USBFS_DIEP0CTL_MPL(x)            ((x) << USBFS_DIEP0CTL_MPL_Pos)
#define USBFS_DIEP0CTL_MPL_64B           USBFS_DIEP0CTL_MPL(0)
#define USBFS_DIEP0CTL_MPL_32B           USBFS_DIEP0CTL_MPL(1)
#define USBFS_DIEP0CTL_MPL_16B           USBFS_DIEP0CTL_MPL(2)
#define USBFS_DIEP0CTL_MPL_8B            USBFS_DIEP0CTL_MPL(3)

/* USBFS_DOEPxCTL, x = 0..3 */
#define USBFS_DOEPCTL_EPEN               _BIT(31,U)           /*!< OUT endpoint enable */
#define USBFS_DOEPCTL_EPD                _BIT(30,U)           /*!< OUT endpoint disable */
#define USBFS_DOEPCTL_SODDFRM            _BIT(29,U)           /*!< OUT endpoint set odd frame */
#define USBFS_DOEPCTL_SD1PID             _BIT(29,U)           /*!< OUT endpoint set DATA1 PID */
#define USBFS_DOEPCTL_SEVENFRM           _BIT(28,U)           /*!< OUT endpoint set even frame */
#define USBFS_DOEPCTL_SD0PID             _BIT(28,U)           /*!< OUT endpoint set DATA0 PID */
#define USBFS_DOEPCTL_SNAK               _BIT(27,U)           /*!< OUT set NAK */
#define USBFS_DOEPCTL_CNAK               _BIT(26,U)           /*!< OUT clear NAK */
#define USBFS_DOEPCTL_STALL              _BIT(21,U)           /*!< OUT STALL handshake */
#define USBFS_DOEPCTL_SNOOP              _BIT(20,U)           /*!< OUT snoop mode */
#define USBFS_DOEPCTL_EPTYPE_Pos         18
#define USBFS_DOEPCTL_EPTYPE_Msk         _AC(0x000c0000,U)    /*!< OUT endpoint type */
#define USBFS_DOEPCTL_EPTYPE(x)          ((x) << USBFS_DOEPCTL_EPTYPE_Pos)
#define USBFS_DOEPCTL_EPTYPE_CONTROL     USBFS_DOEPCTL_EPTYPE(0)
#define USBFS_DOEPCTL_EPTYPE_ISO         USBFS_DOEPCTL_EPTYPE(1)
#define USBFS_DOEPCTL_EPTYPE_BULK        USBFS_DOEPCTL_EPTYPE(2)
#define USBFS_DOEPCTL_EPTYPE_INTERRUPT   USBFS_DOEPCTL_EPTYPE(3)
#define USBFS_DOEPCTL_NAKS               _BIT(17,U)           /*!< OUT NAK status */
#define USBFS_DOEPCTL_EOFRM              _BIT(16,U)           /*!< OUT even/odd frame */
#define USBFS_DOEPCTL_DPID               _BIT(16,U)           /*!< OUT endpoint data PID */
#define USBFS_DOEPCTL_EPACT              _BIT(15,U)           /*!< OUT endpoint active */
#define USBFS_DOEPCTL_MPL_Pos            0
#define USBFS_DOEPCTL_MPL_Msk            _AC(0x000007ff,U)    /*!< OUT maximum packet length */
#define USBFS_DOEPCTL_MPL(x)             ((x) << USBFS_DOEPCTL_MPL_Pos)
/* specific to endpoint 0 */
#define USBFS_DOEP0CTL_MPL_Pos           0
#define USBFS_DOEP0CTL_MPL_Msk           _AC(0x00000003,U)    /*!< OUT endpoint 0 maximum packet length */
#define USBFS_DOEP0CTL_MPL(x)            ((x) << USBFS_DOEP0CTL_MPL_Pos)
#define USBFS_DOEP0CTL_MPL_64B           USBFS_DOEP0CTL_MPL(0)
#define USBFS_DOEP0CTL_MPL_32B           USBFS_DOEP0CTL_MPL(1)
#define USBFS_DOEP0CTL_MPL_16B           USBFS_DOEP0CTL_MPL(2)
#define USBFS_DOEP0CTL_MPL_8B            USBFS_DOEP0CTL_MPL(3)

/* USBFS_DIEPxINTF, x = 0..3 */
#if 0
#define USBFS_DIEPINTF_NAK               _BIT(13,U)           /*!< NAK handshake sent by USBHS */
#endif
#define USBFS_DIEPINTF_TXFE              _BIT(7,U)            /*!< transmit FIFO empty */
#define USBFS_DIEPINTF_IEPNE             _BIT(6,U)            /*!< IN endpoint NAK effective */
#define USBFS_DIEPINTF_EPTXFUD           _BIT(4,U)            /*!< endpoint Tx FIFO underrun */
#define USBFS_DIEPINTF_CITO              _BIT(3,U)            /*!< control In Timeout interrupt */
#define USBFS_DIEPINTF_EPDIS             _BIT(1,U)            /*!< endpoint disabled */
#define USBFS_DIEPINTF_TF                _BIT(0,U)            /*!< transfer finished */

/* USBFS_DOEPxINTF, x = 0..3 */
#if 0
#define USBFS_DOEPINTF_NYET              _BIT(14,U)           /*!< NYET handshake is sent */
#endif
#define USBFS_DOEPINTF_BTBSTP            _BIT(6,U)            /*!< back-to-back SETUP packets */
#define USBFS_DOEPINTF_EPRXFOVR          _BIT(4,U)            /*!< endpoint Rx FIFO overrun */
#define USBFS_DOEPINTF_STPF              _BIT(3,U)            /*!< SETUP phase finished */
#define USBFS_DOEPINTF_EPDIS             _BIT(1,U)            /*!< endpoint disabled */
#define USBFS_DOEPINTF_TF                _BIT(0,U)            /*!< transfer finished */

/* USBFS_DIEP0LEN */
#define USBFS_DIEP0LEN_PCNT_Pos          19
#define USBFS_DIEP0LEN_PCNT_Msk          _AC(0x00180000,U)    /*!< packet count */
#define USBFS_DIEP0LEN_PCNT(x)           ((x) << USBFS_DIEP0LEN_PCNT_Pos)
#define USBFS_DIEP0LEN_TLEN_Pos          0
#define USBFS_DIEP0LEN_TLEN_Msk          _AC(0x0000007f,U)    /*!< transfer length */
#define USBFS_DIEP0LEN_TLEN(x)           ((x) << USBFS_DIEP0LEN_TLEN_Pos)

/* USBFS_DOEP0LEN */
#define USBFS_DOEP0LEN_STPCNT_Pos        29
#define USBFS_DOEP0LEN_STPCNT_Msk        _AC(0x60000000,U)    /*!< SETUP packet count */
#define USBFS_DOEP0LEN_STPCNT(x)         ((x) << USBFS_DOEP0LEN_STPCNT_Pos)
#define USBFS_DOEP0LEN_PCNT              _BIT(19,U)           /*!< packet count */
#define USBFS_DOEP0LEN_TLEN_Pos          0
#define USBFS_DOEP0LEN_TLEN_Msk          _AC(0x0000007f,U)    /*!< transfer length */
#define USBFS_DOEP0LEN_TLEN(x)           ((x) << USBFS_DOEP0LEN_TLEN_Pos)

/* USBFS_DIEPxLEN, x = 1..3 */
#define USBFS_DIEPLEN_MCPF_Pos           29
#define USBFS_DIEPLEN_MCPF_Msk           _AC(0x60000000,U)    /*!< multi packet count per frame */
#define USBFS_DIEPLEN_MCPF(x)            ((x) << USBFS_DIEPLEN_MCPF_Pos)
#define USBFS_DIEPLEN_PCNT_Pos           19
#define USBFS_DIEPLEN_PCNT_Msk           _AC(0x1ff80000,U)    /*!< packet count */
#define USBFS_DIEPLEN_PCNT(x)            ((x) << USBFS_DIEPLEN_PCNT_Pos)
#define USBFS_DIEPLEN_TLEN_Pos           0
#define USBFS_DIEPLEN_TLEN_Msk           _AC(0x0007ffff,U)    /*!< transfer length */
#define USBFS_DIEPLEN_TLEN(x)            ((x) << USBFS_DIEPLEN_TLEN_Pos)

/* USBFS_DOEPxLEN, x = 1..3 */
#define USBFS_DOEPLEN_RXDPID_Pos         29
#define USBFS_DOEPLEN_RXDPID_Msk         _AC(0x60000000,U)    /*!< received data PID */
#define USBFS_DOEPLEN_RXDPID(x)          ((x) << USBFS_DOEPLEN_RXDPID_Pos)
#define USBFS_DOEPLEN_RXDPID_DATA0       USBFS_DOEPLEN_RXDPID(0)
#define USBFS_DOEPLEN_RXDPID_DATA1       USBFS_DOEPLEN_RXDPID(2)
#define USBFS_DOEPLEN_STPCNT_Pos         29
#define USBFS_DOEPLEN_STPCNT_Msk         _AC(0x60000000,U)    /*!< SETUP packet count */
#define USBFS_DOEPLEN_STPCNT(x)          ((x) << USBFS_DOEPLEN_STPCNT_Pos)
#define USBFS_DOEPLEN_PCNT_Pos           19
#define USBFS_DOEPLEN_PCNT_Msk           _AC(0x1ff80000,U)    /*!< packet count */
#define USBFS_DOEPLEN_PCNT(x)            ((x) << USBFS_DOEPLEN_PCNT_Pos)
#define USBFS_DOEPLEN_TLEN_Pos           0
#define USBFS_DOEPLEN_TLEN_Msk           _AC(0x0007ffff,U)    /*!< transfer length */
#define USBFS_DOEPLEN_TLEN(x)            ((x) << USBFS_DOEPLEN_TLEN_Pos)

/* USBFS_DIEPxTFSTAT, x = 0..3 */
#define USBFS_DIEPTFSTAT_IEPTFS_Pos      0
#define USBFS_DIEPTFSTAT_IEPTFS_Msk      _AC(0x0000ffff,U)    /*!< IN endpoint Tx FIFO space remaining */
#define USBFS_DIEPTFSTAT_IEPTFS(x)       ((x) << USBFS_DIEPTFSTAT_IEPTFS_Pos)

/* USBFS_PWRCLKCTL */
#define USBFS_PWRCLKCTL_SHCLK            _BIT(1,U)            /*!< stop HCLK */
#define USBFS_PWRCLKCTL_SUCLK            _BIT(0,U)            /*!< stop the USB clock */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_usbfs_hch {
    volatile uint32_t CTL;                          /*!< USB host channel control register          */
    uint32_t reserved1;                             /*!< reserved (STCTL)                           */
    volatile uint32_t INTF;                         /*!< USB host channel interrupt flag register   */
    volatile uint32_t INTEN;                        /*!< USB host channel interrupt enable register */
    volatile uint32_t LEN;                          /*!< USB host channel transfer length register  */
    uint32_t reserved2[3];                          /*!< reserved (DMAADDR)                         */
};

struct gd32vf103_usbfs_diep {
    volatile uint32_t CTL;                          /*!< USB device IN endpoint control register              */
    uint32_t reserved1;                             /*!< reserved                                             */
    volatile uint32_t INTF;                         /*!< USB device IN endpoint interrupt flag register       */
    uint32_t reserved2;                             /*!< reserved                                             */
    volatile uint32_t LEN;                          /*!< USB device IN endpoint transfer length register      */
    uint32_t reserved3;                             /*!< reserved (DMAADDR)                                   */
    volatile uint32_t TFSTAT;                       /*!< USB device IN endpoint transmit FIFO status register */
    uint32_t reserved4;                             /*!< reserved                                             */
};

struct gd32vf103_usbfs_doep {
    volatile uint32_t CTL;                          /*!< USB device IN endpoint control register         */
    uint32_t reserved1;                             /*!< reserved                                        */
    volatile uint32_t INTF;                         /*!< USB device IN endpoint interrupt flag register  */
    uint32_t reserved2;                             /*!< reserved                                        */
    volatile uint32_t LEN;                          /*!< USB device IN endpoint transfer length register */
    uint32_t reserved3[3];                          /*!< reserved (DMAADDR)                              */
};

struct gd32vf103_usbfs {
    volatile uint32_t GOTGCS;                       /*!< USB global OTG control and status register                  000h */
    volatile uint32_t GOTGINTF;                     /*!< USB global OTG interrupt flag register                      004h */
    volatile uint32_t GAHBCS;                       /*!< USB global AHB control and status register                  008h */
    volatile uint32_t GUSBCS;                       /*!< USB global USB control and status register                  00Ch */
    volatile uint32_t GRSTCTL;                      /*!< USB global reset control register                           010h */
    volatile uint32_t GINTF;                        /*!< USB global interrupt flag register                          014h */
    volatile uint32_t GINTEN;                       /*!< USB global interrupt enable register                        018h */
    volatile uint32_t GRSTATR;                      /*!< USB receive status debug read register                      01Ch */
    volatile uint32_t GRSTATP;                      /*!< USB receive status and pop register                         020h */
    volatile uint32_t GRFLEN;                       /*!< USB global receive FIFO length register                     024h */
    union {
	    volatile uint32_t DIEP0TFLEN_HNPTFLEN;  /*!< USB device IN endpoint 0/host non-periodic transmit FIFO length 028h */
	    volatile uint32_t HNPTFLEN;             /*!< USB host non-periodic transmit FIFO length                  028h */
	    volatile uint32_t DIEP0TFLEN;           /*!< USB device IN endpoint 0 transmit FIFO length               028h */
    };
    volatile uint32_t HNPTFQSTAT;                   /*!< USB host non-periodic FIFO/queue status register            02Ch */
    uint32_t reserved1[2];                          /*!< reserved                                               030h-037h */
    volatile uint32_t GCCFG;                        /*!< USB global core configuration register                      038h */
    volatile uint32_t CID;                          /*!< USB core ID register                                        03Ch */
    uint32_t reserved2[48];                         /*!< reserved                                               040h-0FFh */
    volatile uint32_t HPTFLEN;                      /*!< USB host periodic transmit FIFO length register             100h */
    volatile uint32_t DIEP1TFLEN;                   /*!< USB device IN endpoint 1 transmit FIFO length               104h */
    volatile uint32_t DIEP2TFLEN;                   /*!< USB device IN endpoint 2 transmit FIFO length               108h */
    volatile uint32_t DIEP3TFLEN;                   /*!< USB device IN endpoint 3 transmit FIFO length               10Ch */
    uint32_t reserved3[188];                        /*!< reserved                                               110h-3FFh */
    volatile uint32_t HCTL;                         /*!< USB host control register                                   400h */
    volatile uint32_t HFT;                          /*!< USB host frame interval register                            404h */
    volatile uint32_t HFINFR;                       /*!< USB host frame information remaining register               408h */
    uint32_t reserved4;                             /*!< reserved                                                    40Ch */
    volatile uint32_t HPTFQSTAT;                    /*!< USB host periodic transmit FIFO/queue status register       410h */
    volatile uint32_t HACHINT;                      /*!< USB host all channels interrupt register                    414h */
    volatile uint32_t HACHINTEN;                    /*!< USB host all channels interrupt enable register             418h */
    uint32_t reserved5[9];                          /*!< reserved                                               41Ch-43Fh */
    volatile uint32_t HPCS;                         /*!< USB host port control and status register                   440h */
    uint32_t reserved6[47];                         /*!< reserved                                               444h-4FFh */
    struct gd32vf103_usbfs_hch HCH[8];              /*                                                          500h-5FFh */
    uint32_t reserved7[128];                        /*!< reserved                                               600h-7FFh */
    volatile uint32_t DCFG;                         /*!< USB device configuration register                           800h */
    volatile uint32_t DCTL;                         /*!< USB device control register                                 804h */
    volatile uint32_t DSTAT;                        /*!< USB device status register                                  808h */
    uint32_t reserved8;                             /*!< reserved                                                    80Ch */
    volatile uint32_t DIEPINTEN;                    /*!< USB device IN endpoint common interrupt enable register     810h */
    volatile uint32_t DOEPINTEN;                    /*!< USB device OUT endpoint common interrupt enable register    814h */
    volatile uint32_t DAEPINT;                      /*!< USB device all endpoints interrupt register                 818h */
    volatile uint32_t DAEPINTEN;                    /*!< USB device all endpoints interrupt enable register          81Ch */
    uint32_t reserved9[2];                          /*!< reserved                                               820h-827h */
    volatile uint32_t DVBUSDT;                      /*!< USB device VBUS discharge time register                     828h */
    volatile uint32_t DVBUSPT;                      /*!< USB device VBUS pulsing time register                       82Ch */
    uint32_t reserved10;                            /*!< reserved                                                    830h */
    volatile uint32_t DIEPFEINTEN;                  /*!< USB Device IN endpoint FIFO empty interrupt enable register 834h */
    uint32_t reserved11[50];                        /*!< reserved                                               838h-8FFh */
    struct gd32vf103_usbfs_diep DIEP[4];            /*                                                          900h-97Fh */
    uint32_t reserved12[96];                        /*!< reserved                                               980h-B00h */
    struct gd32vf103_usbfs_doep DOEP[4];            /*                                                          B00h-B7Fh */
    uint32_t reserved13[160];                       /*!< reserved                                               B80h-DFFh */
    volatile uint32_t PWRCLKCTL;                    /*!< USB power and clock control register                        E00h */
    uint32_t reserved14[127];                       /*!< reserved                                               E04h-FFFh */
    volatile uint32_t DFIFO[4][1024];
};

static struct gd32vf103_usbfs *const USBFS = (struct gd32vf103_usbfs *)USBFS_BASE;

#endif
#endif
