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
#ifndef GD32VF103_SPI_H
#define GD32VF103_SPI_H

#include "gd32vf103.h"

#define SPI0_BASE _AC(0x40013000,UL)  /*!< SPI0 base address */
#define SPI1_BASE _AC(0x40003800,UL)  /*!< SPI1 base address */
#define SPI2_BASE _AC(0x40003C00,UL)  /*!< SPI2 base address */

/* register definitions */
#define SPI_CTL0     _AC(0x00,UL)  /*!< SPI control register 0 */
#define SPI_CTL1     _AC(0x04,UL)  /*!< SPI control register 1*/
#define SPI_STAT     _AC(0x08,UL)  /*!< SPI status register */
#define SPI_DATA     _AC(0x0C,UL)  /*!< SPI data register */
#define SPI_CRCPOLY  _AC(0x10,UL)  /*!< SPI CRC polynomial register */
#define SPI_RCRC     _AC(0x14,UL)  /*!< SPI receive CRC register */
#define SPI_TCRC     _AC(0x18,UL)  /*!< SPI transmit CRC register */
#define SPI_I2SCTL   _AC(0x1C,UL)  /*!< SPI I2S control register */
#define SPI_I2SPSC   _AC(0x20,UL)  /*!< SPI I2S clock prescaler register */

/* SPI_CTL0 */
#define SPI_CTL0_BDEN                 _BIT(15,U)              /*!< bidirectional enable */
#define SPI_CTL0_BDOEN                _BIT(14,U)              /*!< bidirectional transmit output enable*/
#define SPI_CTL0_CRCEN                _BIT(13,U)              /*!< CRC calculation enable */
#define SPI_CTL0_CRCNT                _BIT(12,U)              /*!< CRC next transfer */
#define SPI_CTL0_FF16                 _BIT(11,U)              /*!< data frame size */
#define SPI_CTL0_RO                   _BIT(10,U)              /*!< receive only */
#define SPI_CTL0_SWNSSEN              _BIT(9,U)               /*!< NSS software mode selection */
#define SPI_CTL0_SWNSS                _BIT(8,U)               /*!< NSS pin selection in NSS software mode */
#define SPI_CTL0_LF                   _BIT(7,U)               /*!< LSB first mode */
#define SPI_CTL0_SPIEN                _BIT(6,U)               /*!< SPI enable*/
#define SPI_CTL0_PSC_Pos              3
#define SPI_CTL0_PSC_Msk              _AC(0x00000038,U)       /*!< master clock prescaler selection */
#define SPI_CTL0_PSC(x)               ((x) << SPI_CTL0_PSC_Pos)
#define SPI_CTL0_PSC_DIV2             SPI_CTL0_PSC(0)         /*!< SPI clock prescale factor is 2 */
#define SPI_CTL0_PSC_DIV4             SPI_CTL0_PSC(1)         /*!< SPI clock prescale factor is 4 */
#define SPI_CTL0_PSC_DIV8             SPI_CTL0_PSC(2)         /*!< SPI clock prescale factor is 8 */
#define SPI_CTL0_PSC_DIV16            SPI_CTL0_PSC(3)         /*!< SPI clock prescale factor is 16 */
#define SPI_CTL0_PSC_DIV32            SPI_CTL0_PSC(4)         /*!< SPI clock prescale factor is 32 */
#define SPI_CTL0_PSC_DIV64            SPI_CTL0_PSC(5)         /*!< SPI clock prescale factor is 64 */
#define SPI_CTL0_PSC_DIV128           SPI_CTL0_PSC(6)         /*!< SPI clock prescale factor is 128 */
#define SPI_CTL0_PSC_DIV256           SPI_CTL0_PSC(7)         /*!< SPI clock prescale factor is 256 */
#define SPI_CTL0_MSTMOD               _BIT(2,U)               /*!< master mode enable */
#define SPI_CTL0_CKPL                 _BIT(1,U)               /*!< clock polarity selection */
#define SPI_CTL0_CKPH                 _BIT(0,U)               /*!< clock phase selection*/

/* SPI_CTL1 */
#define SPI_CTL1_TBEIE                _BIT(7,U)               /*!< transmit buffer empty interrupt enable */
#define SPI_CTL1_RBNEIE               _BIT(6,U)               /*!< receive buffer not empty interrupt enable */
#define SPI_CTL1_ERRIE                _BIT(5,U)               /*!< errors interrupt enable */
#define SPI_CTL1_TMOD                 _BIT(4,U)               /*!< SPI TI mode enable */
#define SPI_CTL1_NSSP                 _BIT(3,U)               /*!< SPI NSS pulse mode enable */
#define SPI_CTL1_NSSDRV               _BIT(2,U)               /*!< drive NSS output */
#define SPI_CTL1_DMATEN               _BIT(1,U)               /*!< transmit buffer dma enable */
#define SPI_CTL1_DMAREN               _BIT(0,U)               /*!< receive buffer dma enable */

/* SPI_STAT */
#define SPI_STAT_FERR                 _BIT(8,U)               /*!< format error bit */
#define SPI_STAT_TRANS                _BIT(7,U)               /*!< transmitting on-going bit */
#define SPI_STAT_RXORERR              _BIT(6,U)               /*!< SPI reception overrun error bit */
#define SPI_STAT_CONFERR              _BIT(5,U)               /*!< SPI configuration error bit */
#define SPI_STAT_CRCERR               _BIT(4,U)               /*!< SPI CRC error bit */
#define SPI_STAT_TXURERR              _BIT(3,U)               /*!< I2S transmission underrun error bit */
#define SPI_STAT_I2SCH                _BIT(2,U)               /*!< I2S channel side */
#define SPI_STAT_TBE                  _BIT(1,U)               /*!< transmit buffer empty */
#define SPI_STAT_RBNE                 _BIT(0,U)               /*!< receive buffer not empty */

/* SPI_DATA */
#define SPI_DATA_DATA_Pos             0
#define SPI_DATA_DATA_Msk             _AC(0x0000ffff,U)       /*!< data transfer register */
#define SPI_DATA_DATA(x)              ((x) << SPI_DATA_DATA_Pos)

/* SPI_CRCPOLY */
#define SPI_CRCPOLY_CRCPOLY_Pos       0
#define SPI_CRCPOLY_CRCPOLY_Msk       _AC(0x0000ffff,U)       /*!< CRC polynomial value */
#define SPI_CRCPOLY_CRCPOLY(x)        ((x) << SPI_CRCPOLY_CRCPOLY_Pos)

/* SPI_RCRC */
#define SPI_RCRC_RCRC_Pos             0
#define SPI_RCRC_RCRC_Msk             _AC(0x0000ffff,U)       /*!< RX CRC value */
#define SPI_RCRC_RCRC(x)              ((x) << SPI_RCRC_RCRC_Pos)

/* SPI_TCRC */
#define SPI_TCRC_TCRC_Pos             0
#define SPI_TCRC_TCRC_Msk             _AC(0x0000ffff,U)       /*!< TX CRC value */
#define SPI_TCRC_TCRC(x)              ((x) << SPI_TCRC_TCRC_Pos)

/* SPI_I2SCTL */
#define SPI_I2SCTL_I2SSEL             _BIT(11,U)              /*!< I2S mode selection */
#define SPI_I2SCTL_I2SEN              _BIT(10,U)              /*!< I2S enable */
#define SPI_I2SCTL_I2SOPMOD_Pos       8
#define SPI_I2SCTL_I2SOPMOD_Msk       _AC(0x00000300,U)       /*!< I2S operation mode */
#define SPI_I2SCTL_I2SOPMOD(x)        ((x) << SPI_I2SCTL_I2SOPMOD_Pos)
#define SPI_I2SCTL_I2SOPMOD_SLAVETX   SPI_I2SCTL_I2SOPMOD(0)  /*!< I2S slave transmit mode */
#define SPI_I2SCTL_I2SOPMOD_SLAVERX   SPI_I2SCTL_I2SOPMOD(1)  /*!< I2S slave receive mode */
#define SPI_I2SCTL_I2SOPMOD_MASTERTX  SPI_I2SCTL_I2SOPMOD(2)  /*!< I2S master transmit mode */
#define SPI_I2SCTL_I2SOPMOD_MASTERRX  SPI_I2SCTL_I2SOPMOD(3)  /*!< I2S master receive mode */
#define SPI_I2SCTL_PCMSMOD            _BIT(7,U)               /*!< PCM frame synchronization mode */
#define SPI_I2SCTL_I2SSTD_Pos         4
#define SPI_I2SCTL_I2SSTD_Msk         _AC(0x00000030,U)       /*!< I2S standard selection */
#define SPI_I2SCTL_I2SSTD(x)          ((x) << SPI_I2SCTL_I2SSTD_Pos)
#define SPI_I2SCTL_I2SSTD_PHILLIPS    SPI_I2SCTL_I2SSTD(0)    /*!< I2S phillips standard */
#define SPI_I2SCTL_I2SSTD_MSB         SPI_I2SCTL_I2SSTD(1)    /*!< I2S MSB standard */
#define SPI_I2SCTL_I2SSTD_LSB         SPI_I2SCTL_I2SSTD(2)    /*!< I2S LSB standard */
#define SPI_I2SCTL_I2SSTD_PCM         SPI_I2SCTL_I2SSTD(3)    /*!< I2S PCM standard */
#define SPI_I2SCTL_CKPL               _BIT(3,U)               /*!< idle state clock polarity */
#define SPI_I2SCTL_DTLEN_Pos          1
#define SPI_I2SCTL_DTLEN_Msk          _AC(0x00000006,U)       /*!< data length */
#define SPI_I2SCTL_DTLEN(x)           ((x) << SPI_I2SCTL_DTLEN_Pos)
#define SPI_I2SCTL_DTLEN_16B          SPI_I2SCTL_DTLEN(0)     /*!< I2S data length is 16 bit */
#define SPI_I2SCTL_DTLEN_24B          SPI_I2SCTL_DTLEN(1)     /*!< I2S data length is 24 bit */
#define SPI_I2SCTL_DTLEN_32B          SPI_I2SCTL_DTLEN(2)     /*!< I2S data length is 32 bit */
#define SPI_I2SCTL_CHLEN              _BIT(0,U)               /*!< channel length */

/* SPI_I2SPSC */
#define SPI_I2SPSC_MCKOEN             _BIT(9,U)               /*!< I2S MCK output enable */
#define SPI_I2SPSC_OF                 _BIT(8,U)               /*!< odd factor for the prescaler */
#define SPI_I2SPSC_DIV_Pos            0
#define SPI_I2SPSC_DIV_Msk            _AC(0x0000000f,U)       /*!< dividing factor for the prescaler */
#define SPI_I2SPSC_DIV(x)             ((x) << SPI_I2SPSC_DIV_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_spi {
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t STAT;
	volatile uint32_t DATA;
	volatile uint32_t CRCPOLY;
	volatile uint32_t RCRC;
	volatile uint32_t TCRC;
	volatile uint32_t I2SCTL;
	volatile uint32_t I2SPSC;
};

static struct gd32vf103_spi *const SPI0 = (struct gd32vf103_spi *)SPI0_BASE;
static struct gd32vf103_spi *const SPI1 = (struct gd32vf103_spi *)SPI1_BASE;
static struct gd32vf103_spi *const SPI2 = (struct gd32vf103_spi *)SPI2_BASE;

#endif
#endif
