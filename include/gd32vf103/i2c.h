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
#ifndef GD32VF103_I2C_H
#define GD32VF103_I2C_H

#include "gd32vf103.h"

#define I2C0_BASE _AC(0x40005400,UL)  /*!< I2C0 base address */
#define I2C1_BASE _AC(0x40005800,UL)  /*!< I2C1 base address */

/* register definitions */
#define I2C_CTL0    _AC(0x00,UL)  /*!< I2C control register 0 */
#define I2C_CTL1    _AC(0x04,UL)  /*!< I2C control register 1 */
#define I2C_SADDR0  _AC(0x08,UL)  /*!< I2C slave address register 0*/
#define I2C_SADDR1  _AC(0x0C,UL)  /*!< I2C slave address register */
#define I2C_DATA    _AC(0x10,UL)  /*!< I2C transfer buffer register */
#define I2C_STAT0   _AC(0x14,UL)  /*!< I2C transfer status register 0 */
#define I2C_STAT1   _AC(0x18,UL)  /*!< I2C transfer status register */
#define I2C_CKCFG   _AC(0x1C,UL)  /*!< I2C clock configure register */
#define I2C_RT      _AC(0x20,UL)  /*!< I2C rise time register */

/* I2C_CTL0 */
#define I2C_CTL0_SRESET             _BIT(15,U)         /*!< software reset */
#define I2C_CTL0_SALT               _BIT(13,U)         /*!< SMBus alert */
#define I2C_CTL0_PECTRANS           _BIT(12,U)         /*!< packet error checking */
#define I2C_CTL0_POAP               _BIT(11,U)         /*!< acknowledge/PEC position (for data reception) */
#define I2C_CTL0_ACKEN              _BIT(10,U)         /*!< acknowledge enable */
#define I2C_CTL0_STOP               _BIT(9,U)          /*!< stop generation */
#define I2C_CTL0_START              _BIT(8,U)          /*!< start generation */
#define I2C_CTL0_SS                 _BIT(7,U)          /*!< clock stretching disable (slave mode) */
#define I2C_CTL0_GCEN               _BIT(6,U)          /*!< general call enable */
#define I2C_CTL0_PECEN              _BIT(5,U)          /*!< PEC enable */
#define I2C_CTL0_ARPEN              _BIT(4,U)          /*!< ARP enable */
#define I2C_CTL0_SMBSEL             _BIT(3,U)          /*!< SMBus type */
#define I2C_CTL0_SMBEN              _BIT(1,U)          /*!< SMBus mode */
#define I2C_CTL0_I2CEN              _BIT(0,U)          /*!< peripheral enable */

/* I2C_CTL1 */
#define I2C_CTL1_DMALST             _BIT(12,U)         /*!< DMA last transfer */
#define I2C_CTL1_DMAON              _BIT(11,U)         /*!< DMA requests enable */
#define I2C_CTL1_BUFIE              _BIT(10,U)         /*!< buffer interrupt enable */
#define I2C_CTL1_EVIE               _BIT(9,U)          /*!< event interrupt enable */
#define I2C_CTL1_ERRIE              _BIT(8,U)          /*!< error interrupt enable */
#define I2C_CTL1_I2CCLK_Pos         0
#define I2C_CTL1_I2CCLK_Msk         _AC(0x0000003f,U)  /*!< I2CCLK[5:0] bits (peripheral clock frequency) */
#define I2C_CTL1_I2CCLK(x)          ((x) << I2C_CTL1_I2CCLK_Pos)

/* I2C_SADDR0 */
#define I2C_SADDR0_ADDFORMAT        _BIT(15,U)         /*!< address mode for the I2C slave */
#define I2C_SADDR0_ADDRESS_10B_Pos  0
#define I2C_SADDR0_ADDRESS_10B_Msk  _AC(0x000003ff,U)  /*!< 10-bit address */
#define I2C_SADDR0_ADDRESS_10B(x)   ((x) << I2C_SADDR0_ADDRESS_Pos)
#define I2C_SADDR0_ADDRESS_Pos      1
#define I2C_SADDR0_ADDRESS_Msk      _AC(0x000000fe,U)  /*!< 7-bit address */
#define I2C_SADDR0_ADDRESS(x)       ((x) << I2C_SADDR0_ADDRESS_Pos)

/* I2C_SADDR1 */
#define I2C_SADDR1_ADDRESS2_Pos     1
#define I2C_SADDR1_ADDRESS2_Msk     _AC(0x000000fe,U)  /*!< second I2C address for the slave in dual-address mode */
#define I2C_SADDR1_ADDRESS2(x)      ((x) << I2C_SADDR1_ADDRESS2_Pos)
#define I2C_SADDR1_DUADEN           _BIT(0,U)          /*!< aual-address mode switch */

/* I2C_DATA */
#define I2C_DATA_TRB_Pos            0
#define I2C_DATA_TRB_Msk            _AC(0x000000ff,U)  /*!< 8-bit data register */
#define I2C_DATA_TRB(x)             ((x) << I2C_DATA_TRB_Pos)

/* I2C_STAT0 */
#define I2C_STAT0_SMBALT            _BIT(15,U)         /*!< SMBus alert status */
#define I2C_STAT0_SMBTO             _BIT(14,U)         /*!< timeout signal in SMBus mode */
#define I2C_STAT0_PECERR            _BIT(12,U)         /*!< PEC error in reception */
#define I2C_STAT0_OUERR             _BIT(11,U)         /*!< overrun/underrun */
#define I2C_STAT0_AERR              _BIT(10,U)         /*!< acknowledge failure */
#define I2C_STAT0_LOSTARB           _BIT(9,U)          /*!< arbitration lost (master mode) */
#define I2C_STAT0_BERR              _BIT(8,U)          /*!< bus error */
#define I2C_STAT0_TBE               _BIT(7,U)          /*!< data register empty (transmitters) */
#define I2C_STAT0_RBNE              _BIT(6,U)          /*!< data register not empty (receivers) */
#define I2C_STAT0_STPDET            _BIT(4,U)          /*!< stop detection (slave mode) */
#define I2C_STAT0_ADD10SEND         _BIT(3,U)          /*!< 10-bit header sent (master mode) */
#define I2C_STAT0_BTC               _BIT(2,U)          /*!< byte transfer finished */
#define I2C_STAT0_ADDSEND           _BIT(1,U)          /*!< address sent (master mode)/matched (slave mode) */
#define I2C_STAT0_SBSEND            _BIT(0,U)          /*!< start bit (master mode) */

/* I2C_STAT1 */
#define I2C_STAT1_PECV_Pos          8
#define I2C_STAT1_PECV_Msk          _AC(0x0000ff00,U)  /*!< packet error checking value */
#define I2C_STAT1_PECV(x)           ((x) << I2C_STAT1_PECV_Pos)
#define I2C_STAT1_DUMODF            _BIT(7,U)          /*!< dual flag (slave mode) */
#define I2C_STAT1_HSTSMB            _BIT(6,U)          /*!< SMBus host header (slave mode) */
#define I2C_STAT1_DEFSMB            _BIT(5,U)          /*!< SMBus device default address (slave mode) */
#define I2C_STAT1_RXGC              _BIT(4,U)          /*!< general call address (slave mode) */
#define I2C_STAT1_TR                _BIT(2,U)          /*!< transmitter/receiver */
#define I2C_STAT1_I2CBSY            _BIT(1,U)          /*!< bus busy */
#define I2C_STAT1_MASTER            _BIT(0,U)          /*!< master/slave */

/* I2C_CKCFG */
#define I2C_CKCFG_FAST              _BIT(15,U)         /*!< I2C speed selection in master mode */
#define I2C_CKCFG_DTCY              _BIT(14,U)         /*!< fast mode duty cycle */
#define I2C_CKCFG_CLKC_Pos          0
#define I2C_CKCFG_CLKC_Msk          _AC(0x00000fff,U)  /*!< clock control register in fast/standard mode (master mode) */
#define I2C_CKCFG_CLKC(x)           ((x) << I2C_CKCFG_CLKC_Pos)

/* I2C_RT */
#define I2C_RT_RISETIME_Pos         0
#define I2C_RT_RISETIME_Msk         _AC(0x0000003f,U)  /*!< maximum rise time in fast/standard mode (Master mode) */
#define I2C_RT_RISETIME(x)          ((x) << I2C_RT_RISETIME_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_i2c {
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t SADDR0;
	volatile uint32_t SADDR1;
	volatile uint32_t DATA;
	volatile uint32_t STAT0;
	volatile uint32_t STAT1;
	volatile uint32_t CKCFG;
	volatile uint32_t RT;
};

static struct gd32vf103_i2c *const I2C0 = (struct gd32vf103_i2c *)I2C0_BASE;
static struct gd32vf103_i2c *const I2C1 = (struct gd32vf103_i2c *)I2C1_BASE;

#endif
#endif
