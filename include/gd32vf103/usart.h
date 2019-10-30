/*
 * Copyright (c) 2018, GigaDevice Semiconductor Inc.
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
#ifndef GD32VF103_USART_H
#define GD32VF103_USART_H

#include "gd32vf103.h"

#define USART0_BASE _AC(0x40013800,UL)  /*!< USART0 base address */
#define USART1_BASE _AC(0x40004400,UL)  /*!< USART1 base address */
#define USART2_BASE _AC(0x40004800,UL)  /*!< USART2 base address */
#define UART3_BASE  _AC(0x40004C00,UL)  /*!< UART3 base address  */
#define UART4_BASE  _AC(0x40005000,UL)  /*!< UART4 base address  */

/* register definitions */
#define USART_STAT  _AC(0x00,UL)  /*!< USART status register */
#define USART_DATA  _AC(0x04,UL)  /*!< USART data register */
#define USART_BAUD  _AC(0x08,UL)  /*!< USART baud rate register */
#define USART_CTL0  _AC(0x0C,UL)  /*!< USART control register 0 */
#define USART_CTL1  _AC(0x10,UL)  /*!< USART control register 1 */
#define USART_CTL2  _AC(0x14,UL)  /*!< USART control register 2 */
#define USART_GP    _AC(0x18,UL)  /*!< USART guard time and prescaler register */

/* USARTx_STAT */
#define USART_STAT_CTSF        _BIT(9,U)          /*!< CTS change flag */
#define USART_STAT_LBDF        _BIT(8,U)          /*!< LIN break detected flag */
#define USART_STAT_TBE         _BIT(7,U)          /*!< transmit data buffer empty */
#define USART_STAT_TC          _BIT(6,U)          /*!< transmission complete */
#define USART_STAT_RBNE        _BIT(5,U)          /*!< read data buffer not empty */
#define USART_STAT_IDLEF       _BIT(4,U)          /*!< IDLE frame detected flag */
#define USART_STAT_ORERR       _BIT(3,U)          /*!< overrun error */
#define USART_STAT_NERR        _BIT(2,U)          /*!< noise error flag */
#define USART_STAT_FERR        _BIT(1,U)          /*!< frame error flag */
#define USART_STAT_PERR        _BIT(0,U)          /*!< parity error flag */

/* USARTx_DATA */
#define USART_DATA_DATA_Pos    0
#define USART_DATA_DATA_Msk    _AC(0x000000ff,U)  /*!< transmit or read data value */
#define USART_DATA_DATA(x)     ((x) << USART_DATA_DATA_Pos)

/* USARTx_BAUD */
#define USART_BAUD_INTDIV_Pos  4
#define USART_BAUD_INTDIV_Msk  _AC(0x0000fff0,U)  /*!< integer part of baud-rate divider */
#define USART_BAUD_INTDIV(x)   ((x) << USART_BAUD_INTDIV_Pos)
#define USART_BAUD_FRADIV_Pos  0
#define USART_BAUD_FRADIV_Msk  _AC(0x0000000f,U)  /*!< fraction part of baud-rate divider */
#define USART_BAUD_FRADIV(x)   ((x) << USART_BAUD_FRADIV_Pos)

/* USARTx_CTL0 */
#define USART_CTL0_UEN         _BIT(13,U)         /*!< USART enable */
#define USART_CTL0_WL          _BIT(12,U)         /*!< word length */
#define USART_CTL0_WM          _BIT(11,U)         /*!< wakeup method in mute mode */
#define USART_CTL0_PCEN        _BIT(10,U)         /*!< parity check function enable */
#define USART_CTL0_PM          _BIT(9,U)          /*!< parity mode */
#define USART_CTL0_PERRIE      _BIT(8,U)          /*!< parity error interrupt enable */
#define USART_CTL0_TBEIE       _BIT(7,U)          /*!< transmitter buffer empty interrupt enable */
#define USART_CTL0_TCIE        _BIT(6,U)          /*!< transmission complete interrupt enable */
#define USART_CTL0_RBNEIE      _BIT(5,U)          /*!< read data buffer not empty interrupt and overrun error interrupt enable */
#define USART_CTL0_IDLEIE      _BIT(4,U)          /*!< idle line detected interrupt enable */
#define USART_CTL0_TEN         _BIT(3,U)          /*!< transmitter enable */
#define USART_CTL0_REN         _BIT(2,U)          /*!< receiver enable */
#define USART_CTL0_RWU         _BIT(1,U)          /*!< receiver wakeup from mute mode */
#define USART_CTL0_SBKCMD      _BIT(0,U)          /*!< send break command */

/* USARTx_CTL1 */
#define USART_CTL1_LMEN        _BIT(14,U)         /*!< LIN mode enable */
#define USART_CTL1_STB_Pos     12
#define USART_CTL1_STB_Msk     _AC(0x00000c00,U)  /*!< STOP bits length */
#define USART_CTL1_STB(x)      ((x) << USART_CTL1_STB_Pos)
#define USART_CTL1_STB_1       USART_CTL1_STB(0)  /*!< 1 bit */
#define USART_CTL1_STB_0_5     USART_CTL1_STB(1)  /*!< 0.5 bit */
#define USART_CTL1_STB_2       USART_CTL1_STB(2)  /*!< 2 bits */
#define USART_CTL1_STB_1_5     USART_CTL1_STB(3)  /*!< 1.5 bits */
#define USART_CTL1_CKEN        _BIT(11,U)         /*!< CK pin enable */
#define USART_CTL1_CPL         _BIT(10,U)         /*!< CK polarity */
#define USART_CTL1_CPH         _BIT(9,U)          /*!< CK phase */
#define USART_CTL1_CLEN        _BIT(8,U)          /*!< CK length */
#define USART_CTL1_LBDIE       _BIT(6,U)          /*!< LIN break detected interrupt eanble */
#define USART_CTL1_LBLEN       _BIT(5,U)          /*!< LIN break frame length */
#define USART_CTL1_ADDR_Pos    0
#define USART_CTL1_ADDR_Msk    _AC(0x0000000f,U)  /*!< address of USART */
#define USART_CTL1_ADDR(x)     ((x) << USART_CTL1_ADDR_Pos)

/* USARTx_CTL2 */
#define USART_CTL2_CTSIE       _BIT(10,U)         /*!< CTS interrupt enable */
#define USART_CTL2_CTSEN       _BIT(9,U)          /*!< CTS enable */
#define USART_CTL2_RTSEN       _BIT(8,U)          /*!< RTS enable */
#define USART_CTL2_DENT        _BIT(7,U)          /*!< DMA request enable for transmission */
#define USART_CTL2_DENR        _BIT(6,U)          /*!< DMA request enable for reception */
#define USART_CTL2_SCEN        _BIT(5,U)          /*!< smartcard mode enable */
#define USART_CTL2_NKEN        _BIT(4,U)          /*!< NACK enable in smartcard mode */
#define USART_CTL2_HDEN        _BIT(3,U)          /*!< half-duplex enable */
#define USART_CTL2_IRLP        _BIT(2,U)          /*!< IrDA low-power */
#define USART_CTL2_IREN        _BIT(1,U)          /*!< IrDA mode enable */
#define USART_CTL2_ERRIE       _BIT(0,U)          /*!< error interrupt enable */

/* USARTx_GP */
#define USART_GP_GUAT_Pos      8
#define USART_GP_GUAT_Msk      _AC(0x0000ff00,U)  /*!< guard time value in smartcard mode */
#define USART_GP_GUAT(x)       ((x) << USART_GP_GUAT_Pos)
#define USART_GP_PSC_Pos       0
#define USART_GP_PSC_Msk       _AC(0x000000ff,U)  /*!< prescaler value for dividing the system clock */
#define USART_GP_PSC(x)        ((x) << USART_GP_PSC_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_usart {
	volatile uint32_t STAT;
	volatile uint32_t DATA;
	volatile uint32_t BAUD;
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t CTL2;
	volatile uint32_t GP;
};

static struct gd32vf103_usart *const USART0 = (struct gd32vf103_usart *)USART0_BASE;
static struct gd32vf103_usart *const USART1 = (struct gd32vf103_usart *)USART1_BASE;
static struct gd32vf103_usart *const USART2 = (struct gd32vf103_usart *)USART2_BASE;
static struct gd32vf103_usart *const UART3  = (struct gd32vf103_usart *)UART3_BASE;
static struct gd32vf103_usart *const UART4  = (struct gd32vf103_usart *)UART4_BASE;

#endif
#endif
