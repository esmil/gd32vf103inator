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
#ifndef GD32VF103_GPIO_H
#define GD32VF103_GPIO_H

#include "gd32vf103.h"

#define AFIO_BASE  _AC(0x40010000,UL)  /*!< AFIO base address  */
#define GPIOA_BASE _AC(0x40010800,UL)  /*!< GPIOA base address */
#define GPIOB_BASE _AC(0x40010C00,UL)  /*!< GPIOB base address */
#define GPIOC_BASE _AC(0x40011000,UL)  /*!< GPIOC base address */
#define GPIOD_BASE _AC(0x40011400,UL)  /*!< GPIOD base address */
#define GPIOE_BASE _AC(0x40011800,UL)  /*!< GPIOE base address */

/* register definitions */
#define GPIO_CTL0     _AC(0x00,UL)  /*!< GPIO port control register 0 */
#define GPIO_CTL1     _AC(0x04,UL)  /*!< GPIO port control register 1 */
#define GPIO_ISTAT    _AC(0x08,UL)  /*!< GPIO port input status register */
#define GPIO_OCTL     _AC(0x0C,UL)  /*!< GPIO port output control register */
#define GPIO_BOP      _AC(0x10,UL)  /*!< GPIO port bit operation register */
#define GPIO_BC       _AC(0x14,UL)  /*!< GPIO bit clear register */
#define GPIO_LOCK     _AC(0x18,UL)  /*!< GPIO port configuration lock register */

#define AFIO_EC       _AC(0x00,UL)  /*!< AFIO event control register */
#define AFIO_PCF0     _AC(0x04,UL)  /*!< AFIO port configuration register 0 */
#define AFIO_EXTISS0  _AC(0x08,UL)  /*!< AFIO port EXTI sources selection register 0 */
#define AFIO_EXTISS1  _AC(0x0C,UL)  /*!< AFIO port EXTI sources selection register 1 */
#define AFIO_EXTISS2  _AC(0x10,UL)  /*!< AFIO port EXTI sources selection register 2 */
#define AFIO_EXTISS3  _AC(0x14,UL)  /*!< AFIO port EXTI sources selection register 3 */
#define AFIO_PCF1     _AC(0x1C,UL)  /*!< AFIO port configuration register 1 */

/* GPIO_CTL0 */
#define GPIO_CTL0_MD_Pos(x)              (2*(x))
#define GPIO_CTL0_MD_Msk(x)              (_AC(0x3,U) << GPIO_CTL0_MD_Pos(x))
#define GPIO_CTL0_CTL_Pos(x)             (2*(x) + 2)
#define GPIO_CTL0_CTL_Msk(x)             (_AC(0x3,U) << GPIO_CTL0_CTL_Pos(x))
#define GPIO_CTL0_MD0_Pos                GPIO_CTL0_MD_Pos(0)
#define GPIO_CTL0_MD0_Msk                GPIO_CTL0_MD_Msk(0)   /*!< port 0 mode bits */
#define GPIO_CTL0_CTL0_Pos               GPIO_CTL0_CTL_Pos(0)
#define GPIO_CTL0_CTL0_Msk               GPIO_CTL0_CTL_Msk(0)  /*!< pin 0 configuration bits */
#define GPIO_CTL0_MD1_Pos                GPIO_CTL0_MD_Pos(1)
#define GPIO_CTL0_MD1_Msk                GPIO_CTL0_MD_Msk(1)   /*!< port 1 mode bits */
#define GPIO_CTL0_CTL1_Pos               GPIO_CTL0_CTL_Pos(1)
#define GPIO_CTL0_CTL1_Msk               GPIO_CTL0_CTL_Msk(1)  /*!< pin 1 configuration bits */
#define GPIO_CTL0_MD2_Pos                GPIO_CTL0_MD_Pos(2)
#define GPIO_CTL0_MD2_Msk                GPIO_CTL0_MD_Msk(2)   /*!< port 2 mode bits */
#define GPIO_CTL0_CTL2_Pos               GPIO_CTL0_CTL_Pos(2)
#define GPIO_CTL0_CTL2_Msk               GPIO_CTL0_CTL_Msk(2)  /*!< pin 2 configuration bits */
#define GPIO_CTL0_MD3_Pos                GPIO_CTL0_MD_Pos(3)
#define GPIO_CTL0_MD3_Msk                GPIO_CTL0_MD_Msk(3)   /*!< port 3 mode bits */
#define GPIO_CTL0_CTL3_Pos               GPIO_CTL0_CTL_Pos(3)
#define GPIO_CTL0_CTL3_Msk               GPIO_CTL0_CTL_Msk(3)  /*!< pin 3 configuration bits */
#define GPIO_CTL0_MD4_Pos                GPIO_CTL0_MD_Pos(4)
#define GPIO_CTL0_MD4_Msk                GPIO_CTL0_MD_Msk(4)   /*!< port 4 mode bits */
#define GPIO_CTL0_CTL4_Pos               GPIO_CTL0_CTL_Pos(4)
#define GPIO_CTL0_CTL4_Msk               GPIO_CTL0_CTL_Msk(4)  /*!< pin 4 configuration bits */
#define GPIO_CTL0_MD5_Pos                GPIO_CTL0_MD_Pos(5)
#define GPIO_CTL0_MD5_Msk                GPIO_CTL0_MD_Msk(5)   /*!< port 5 mode bits */
#define GPIO_CTL0_CTL5_Pos               GPIO_CTL0_CTL_Pos(5)
#define GPIO_CTL0_CTL5_Msk               GPIO_CTL0_CTL_Msk(5)  /*!< pin 5 configuration bits */
#define GPIO_CTL0_MD6_Pos                GPIO_CTL0_MD_Pos(6)
#define GPIO_CTL0_MD6_Msk                GPIO_CTL0_MD_Msk(6)   /*!< port 6 mode bits */
#define GPIO_CTL0_CTL6_Pos               GPIO_CTL0_CTL_Pos(6)
#define GPIO_CTL0_CTL6_Msk               GPIO_CTL0_CTL_Msk(6)  /*!< pin 6 configuration bits */
#define GPIO_CTL0_MD7_Pos                GPIO_CTL0_MD_Pos(7)
#define GPIO_CTL0_MD7_Msk                GPIO_CTL0_MD_Msk(7)   /*!< port 7 mode bits */
#define GPIO_CTL0_CTL7_Pos               GPIO_CTL0_CTL_Pos(7)
#define GPIO_CTL0_CTL7_Msk               GPIO_CTL0_CTL_Msk(7)  /*!< pin 7 configuration bits */

/* GPIO_CTL1 */
#define GPIO_CTL1_MD_Pos(x)              (2*((x) & 7))
#define GPIO_CTL1_MD_Msk(x)              (_AC(0x3,U) << GPIO_CTL0_MD_Pos(x))
#define GPIO_CTL1_CTL_Pos(x)             (2*((x) & 7) + 2)
#define GPIO_CTL1_CTL_Msk(x)             (_AC(0x3,U) << GPIO_CTL0_CTL_Pos(x))
#define GPIO_CTL1_MD8_Pos                GPIO_CTL1_MD_Pos(8)
#define GPIO_CTL1_MD8_Msk                GPIO_CTL1_MD_Msk(8)   /*!< port 8 mode bits */
#define GPIO_CTL1_CTL8_Pos               GPIO_CTL1_CTL_Pos(8)
#define GPIO_CTL1_CTL8_Msk               GPIO_CTL1_CTL_Msk(8)  /*!< pin 8 configuration bits */
#define GPIO_CTL1_MD9_Pos                GPIO_CTL1_MD_Pos(9)
#define GPIO_CTL1_MD9_Msk                GPIO_CTL1_MD_Msk(9)   /*!< port 9 mode bits */
#define GPIO_CTL1_CTL9_Pos               GPIO_CTL1_CTL_Pos(9)
#define GPIO_CTL1_CTL9_Msk               GPIO_CTL1_CTL_Msk(9)  /*!< pin 9 configuration bits */
#define GPIO_CTL1_MD10_Pos               GPIO_CTL1_MD_Pos(10)
#define GPIO_CTL1_MD10_Msk               GPIO_CTL1_MD_Msk(10)  /*!< port 10 mode bits */
#define GPIO_CTL1_CTL10_Pos              GPIO_CTL1_CTL_Pos(10)
#define GPIO_CTL1_CTL10_Msk              GPIO_CTL1_CTL_Msk(10) /*!< pin 10 configuration bits */
#define GPIO_CTL1_MD11_Pos               GPIO_CTL1_MD_Pos(11)
#define GPIO_CTL1_MD11_Msk               GPIO_CTL1_MD_Msk(11)  /*!< port 11 mode bits */
#define GPIO_CTL1_CTL11_Pos              GPIO_CTL1_CTL_Pos(11)
#define GPIO_CTL1_CTL11_Msk              GPIO_CTL1_CTL_Msk(11) /*!< pin 11 configuration bits */
#define GPIO_CTL1_MD12_Pos               GPIO_CTL1_MD_Pos(12)
#define GPIO_CTL1_MD12_Msk               GPIO_CTL1_MD_Msk(12)  /*!< port 12 mode bits */
#define GPIO_CTL1_CTL12_Pos              GPIO_CTL1_CTL_Pos(12)
#define GPIO_CTL1_CTL12_Msk              GPIO_CTL1_CTL_Msk(12) /*!< pin 12 configuration bits */
#define GPIO_CTL1_MD13_Pos               GPIO_CTL1_MD_Pos(13)
#define GPIO_CTL1_MD13_Msk               GPIO_CTL1_MD_Msk(13)  /*!< port 13 mode bits */
#define GPIO_CTL1_CTL13_Pos              GPIO_CTL1_CTL_Pos(13)
#define GPIO_CTL1_CTL13_Msk              GPIO_CTL1_CTL_Msk(13) /*!< pin 13 configuration bits */
#define GPIO_CTL1_MD14_Pos               GPIO_CTL1_MD_Pos(14)
#define GPIO_CTL1_MD14_Msk               GPIO_CTL1_MD_Msk(14)  /*!< port 14 mode bits */
#define GPIO_CTL1_CTL14_Pos              GPIO_CTL1_CTL_Pos(14)
#define GPIO_CTL1_CTL14_Msk              GPIO_CTL1_CTL_Msk(14) /*!< pin 14 configuration bits */
#define GPIO_CTL1_MD15_Pos               GPIO_CTL1_MD_Pos(15)
#define GPIO_CTL1_MD15_Msk               GPIO_CTL1_MD_Msk(15)  /*!< port 15 mode bits */
#define GPIO_CTL1_CTL15_Pos              GPIO_CTL1_CTL_Pos(15)
#define GPIO_CTL1_CTL15_Msk              GPIO_CTL1_CTL_Msk(15) /*!< pin 15 configuration bits */

/* GPIO_ISTAT */
#define GPIO_ISTAT_ISTAT0                _BIT(0,U)             /*!< pin 0 input status */
#define GPIO_ISTAT_ISTAT1                _BIT(1,U)             /*!< pin 1 input status */
#define GPIO_ISTAT_ISTAT2                _BIT(2,U)             /*!< pin 2 input status */
#define GPIO_ISTAT_ISTAT3                _BIT(3,U)             /*!< pin 3 input status */
#define GPIO_ISTAT_ISTAT4                _BIT(4,U)             /*!< pin 4 input status */
#define GPIO_ISTAT_ISTAT5                _BIT(5,U)             /*!< pin 5 input status */
#define GPIO_ISTAT_ISTAT6                _BIT(6,U)             /*!< pin 6 input status */
#define GPIO_ISTAT_ISTAT7                _BIT(7,U)             /*!< pin 7 input status */
#define GPIO_ISTAT_ISTAT8                _BIT(8,U)             /*!< pin 8 input status */
#define GPIO_ISTAT_ISTAT9                _BIT(9,U)             /*!< pin 9 input status */
#define GPIO_ISTAT_ISTAT10               _BIT(10,U)            /*!< pin 10 input status */
#define GPIO_ISTAT_ISTAT11               _BIT(11,U)            /*!< pin 11 input status */
#define GPIO_ISTAT_ISTAT12               _BIT(12,U)            /*!< pin 12 input status */
#define GPIO_ISTAT_ISTAT13               _BIT(13,U)            /*!< pin 13 input status */
#define GPIO_ISTAT_ISTAT14               _BIT(14,U)            /*!< pin 14 input status */
#define GPIO_ISTAT_ISTAT15               _BIT(15,U)            /*!< pin 15 input status */

/* GPIO_OCTL */
#define GPIO_OCTL_OCTL0                  _BIT(0,U)             /*!< pin 0 output bit */
#define GPIO_OCTL_OCTL1                  _BIT(1,U)             /*!< pin 1 output bit */
#define GPIO_OCTL_OCTL2                  _BIT(2,U)             /*!< pin 2 output bit */
#define GPIO_OCTL_OCTL3                  _BIT(3,U)             /*!< pin 3 output bit */
#define GPIO_OCTL_OCTL4                  _BIT(4,U)             /*!< pin 4 output bit */
#define GPIO_OCTL_OCTL5                  _BIT(5,U)             /*!< pin 5 output bit */
#define GPIO_OCTL_OCTL6                  _BIT(6,U)             /*!< pin 6 output bit */
#define GPIO_OCTL_OCTL7                  _BIT(7,U)             /*!< pin 7 output bit */
#define GPIO_OCTL_OCTL8                  _BIT(8,U)             /*!< pin 8 output bit */
#define GPIO_OCTL_OCTL9                  _BIT(9,U)             /*!< pin 9 output bit */
#define GPIO_OCTL_OCTL10                 _BIT(10,U)            /*!< pin 10 output bit */
#define GPIO_OCTL_OCTL11                 _BIT(11,U)            /*!< pin 11 output bit */
#define GPIO_OCTL_OCTL12                 _BIT(12,U)            /*!< pin 12 output bit */
#define GPIO_OCTL_OCTL13                 _BIT(13,U)            /*!< pin 13 output bit */
#define GPIO_OCTL_OCTL14                 _BIT(14,U)            /*!< pin 14 output bit */
#define GPIO_OCTL_OCTL15                 _BIT(15,U)            /*!< pin 15 output bit */

/* GPIO_BOP */
#define GPIO_BOP_BOP0                    _BIT(0,U)             /*!< pin 0 set bit */
#define GPIO_BOP_BOP1                    _BIT(1,U)             /*!< pin 1 set bit */
#define GPIO_BOP_BOP2                    _BIT(2,U)             /*!< pin 2 set bit */
#define GPIO_BOP_BOP3                    _BIT(3,U)             /*!< pin 3 set bit */
#define GPIO_BOP_BOP4                    _BIT(4,U)             /*!< pin 4 set bit */
#define GPIO_BOP_BOP5                    _BIT(5,U)             /*!< pin 5 set bit */
#define GPIO_BOP_BOP6                    _BIT(6,U)             /*!< pin 6 set bit */
#define GPIO_BOP_BOP7                    _BIT(7,U)             /*!< pin 7 set bit */
#define GPIO_BOP_BOP8                    _BIT(8,U)             /*!< pin 8 set bit */
#define GPIO_BOP_BOP9                    _BIT(9,U)             /*!< pin 9 set bit */
#define GPIO_BOP_BOP10                   _BIT(10,U)            /*!< pin 10 set bit */
#define GPIO_BOP_BOP11                   _BIT(11,U)            /*!< pin 11 set bit */
#define GPIO_BOP_BOP12                   _BIT(12,U)            /*!< pin 12 set bit */
#define GPIO_BOP_BOP13                   _BIT(13,U)            /*!< pin 13 set bit */
#define GPIO_BOP_BOP14                   _BIT(14,U)            /*!< pin 14 set bit */
#define GPIO_BOP_BOP15                   _BIT(15,U)            /*!< pin 15 set bit */
#define GPIO_BOP_CR0                     _BIT(16,U)            /*!< pin 0 clear bit */
#define GPIO_BOP_CR1                     _BIT(17,U)            /*!< pin 1 clear bit */
#define GPIO_BOP_CR2                     _BIT(18,U)            /*!< pin 2 clear bit */
#define GPIO_BOP_CR3                     _BIT(19,U)            /*!< pin 3 clear bit */
#define GPIO_BOP_CR4                     _BIT(20,U)            /*!< pin 4 clear bit */
#define GPIO_BOP_CR5                     _BIT(21,U)            /*!< pin 5 clear bit */
#define GPIO_BOP_CR6                     _BIT(22,U)            /*!< pin 6 clear bit */
#define GPIO_BOP_CR7                     _BIT(23,U)            /*!< pin 7 clear bit */
#define GPIO_BOP_CR8                     _BIT(24,U)            /*!< pin 8 clear bit */
#define GPIO_BOP_CR9                     _BIT(25,U)            /*!< pin 9 clear bit */
#define GPIO_BOP_CR10                    _BIT(26,U)            /*!< pin 10 clear bit */
#define GPIO_BOP_CR11                    _BIT(27,U)            /*!< pin 11 clear bit */
#define GPIO_BOP_CR12                    _BIT(28,U)            /*!< pin 12 clear bit */
#define GPIO_BOP_CR13                    _BIT(29,U)            /*!< pin 13 clear bit */
#define GPIO_BOP_CR14                    _BIT(30,U)            /*!< pin 14 clear bit */
#define GPIO_BOP_CR15                    _BIT(31,U)            /*!< pin 15 clear bit */

/* GPIO_BC */
#define GPIO_BC_CR0                      _BIT(0,U)             /*!< pin 0 clear bit */
#define GPIO_BC_CR1                      _BIT(1,U)             /*!< pin 1 clear bit */
#define GPIO_BC_CR2                      _BIT(2,U)             /*!< pin 2 clear bit */
#define GPIO_BC_CR3                      _BIT(3,U)             /*!< pin 3 clear bit */
#define GPIO_BC_CR4                      _BIT(4,U)             /*!< pin 4 clear bit */
#define GPIO_BC_CR5                      _BIT(5,U)             /*!< pin 5 clear bit */
#define GPIO_BC_CR6                      _BIT(6,U)             /*!< pin 6 clear bit */
#define GPIO_BC_CR7                      _BIT(7,U)             /*!< pin 7 clear bit */
#define GPIO_BC_CR8                      _BIT(8,U)             /*!< pin 8 clear bit */
#define GPIO_BC_CR9                      _BIT(9,U)             /*!< pin 9 clear bit */
#define GPIO_BC_CR10                     _BIT(10,U)            /*!< pin 10 clear bit */
#define GPIO_BC_CR11                     _BIT(11,U)            /*!< pin 11 clear bit */
#define GPIO_BC_CR12                     _BIT(12,U)            /*!< pin 12 clear bit */
#define GPIO_BC_CR13                     _BIT(13,U)            /*!< pin 13 clear bit */
#define GPIO_BC_CR14                     _BIT(14,U)            /*!< pin 14 clear bit */
#define GPIO_BC_CR15                     _BIT(15,U)            /*!< pin 15 clear bit */

/* GPIO_LOCK */
#define GPIO_LOCK_LK0                    _BIT(0,U)             /*!< pin 0 lock bit */
#define GPIO_LOCK_LK1                    _BIT(1,U)             /*!< pin 1 lock bit */
#define GPIO_LOCK_LK2                    _BIT(2,U)             /*!< pin 2 lock bit */
#define GPIO_LOCK_LK3                    _BIT(3,U)             /*!< pin 3 lock bit */
#define GPIO_LOCK_LK4                    _BIT(4,U)             /*!< pin 4 lock bit */
#define GPIO_LOCK_LK5                    _BIT(5,U)             /*!< pin 5 lock bit */
#define GPIO_LOCK_LK6                    _BIT(6,U)             /*!< pin 6 lock bit */
#define GPIO_LOCK_LK7                    _BIT(7,U)             /*!< pin 7 lock bit */
#define GPIO_LOCK_LK8                    _BIT(8,U)             /*!< pin 8 lock bit */
#define GPIO_LOCK_LK9                    _BIT(9,U)             /*!< pin 9 lock bit */
#define GPIO_LOCK_LK10                   _BIT(10,U)            /*!< pin 10 lock bit */
#define GPIO_LOCK_LK11                   _BIT(11,U)            /*!< pin 11 lock bit */
#define GPIO_LOCK_LK12                   _BIT(12,U)            /*!< pin 12 lock bit */
#define GPIO_LOCK_LK13                   _BIT(13,U)            /*!< pin 13 lock bit */
#define GPIO_LOCK_LK14                   _BIT(14,U)            /*!< pin 14 lock bit */
#define GPIO_LOCK_LK15                   _BIT(15,U)            /*!< pin 15 lock bit */
#define GPIO_LOCK_LKK                    _BIT(16,U)            /*!< pin sequence lock key */

/* AFIO_EC */
#define AFIO_EC_EOE                      _BIT(7,U)             /*!< event output enable */
#define AFIO_EC_PORT_Pos                 4
#define AFIO_EC_PORT_Msk                 _AC(0x00000070,U)     /*!< event output port selection */
#define AFIO_EC_PORT(x)                  ((x) << AFIO_EC_PORT_Pos)
#define AFIO_EC_PORT_A                   AFIO_EC_PORT(0)
#define AFIO_EC_PORT_B                   AFIO_EC_PORT(1)
#define AFIO_EC_PORT_C                   AFIO_EC_PORT(2)
#define AFIO_EC_PORT_D                   AFIO_EC_PORT(3)
#define AFIO_EC_PORT_E                   AFIO_EC_PORT(4)
#define AFIO_EC_PIN_Pos                  0
#define AFIO_EC_PIN_Msk                  _AC(0x0000000f,U)     /*!< event output pin selection */
#define AFIO_EC_PIN(x)                   ((x) << AFIO_EC_PIN_Pos)

/* AFIO_PCF0 */
#define AFIO_PCF0_TIMER1_ITI1_REMAP      _BIT(29,U)            /*!< TIMER1 internal trigger 1 remapping */
#define AFIO_PCF0_SPI2_REMAP             _BIT(28,U)            /*!< SPI2/I2S2 remapping */
#define AFIO_PCF0_SWJ_CFG_Pos            24
#define AFIO_PCF0_SWJ_CFG_Msk            _AC(0x07000000,U)     /*!< serial wire JTAG configuration */
#define AFIO_PCF0_SWJ_CFG(x)             ((x) << AFIO_PCF0_SWJ_CFG_Pos)
#define AFIO_PCF0_SWJ_CFG_RESET          AFIO_PCF0_SWJ_CFG(0)
#define AFIO_PCF0_SWJ_CFG_NORST          AFIO_PCF0_SWJ_CFG(1)
#define AFIO_PCF0_SWJ_CFG_DISABLED       AFIO_PCF0_SWJ_CFG(2)
#define AFIO_PCF0_CAN1_REMAP             _BIT(22,U)            /*!< CAN1 remapping */
#define AFIO_PCF0_TIMER4CH3_IREMAP       _BIT(16,U)            /*!< TIMER3 channel3 internal remapping */
#define AFIO_PCF0_PD01_REMAP             _BIT(15,U)            /*!< port D0/port D1 mapping on OSC_IN/OSC_OUT */
#define AFIO_PCF0_CAN0_REMAP_Pos         13
#define AFIO_PCF0_CAN0_REMAP_Msk         _AC(0x00006000,U)     /*!< CAN remapping */
#define AFIO_PCF0_CAN0_REMAP(x)          ((x) << AFIO_PCF0_CAN_REMAP_Pos)
#define AFIO_PCF0_CAN0_REMAP_NONE        AFIO_PCF0_CAN0_REMAP(0)
#define AFIO_PCF0_CAN0_REMAP_PARTIAL     AFIO_PCF0_CAN0_REMAP(2)
#define AFIO_PCF0_CAN0_REMAP_FULL        AFIO_PCF0_CAN0_REMAP(3)
#define AFIO_PCF0_TIMER3_REMAP           _BIT(12,U)            /*!< TIMER3 remapping */
#define AFIO_PCF0_TIMER2_REMAP_Pos       10
#define AFIO_PCF0_TIMER2_REMAP_Msk       _AC(0x00000c00,U)     /*!< TIMER2 remapping */
#define AFIO_PCF0_TIMER2_REMAP(x)        ((x) << AFIO_PCF0_TIMER2_REMAP_Pos)
#define AFIO_PCF0_TIMER2_REMAP_NONE      AFIO_PCF0_TIMER2_REMAP(0)
#define AFIO_PCF0_TIMER2_REMAP_PARTIAL   AFIO_PCF0_TIMER2_REMAP(2)
#define AFIO_PCF0_TIMER2_REMAP_FULL      AFIO_PCF0_TIMER2_REMAP(3)
#define AFIO_PCF0_TIMER1_REMAP_Pos       8
#define AFIO_PCF0_TIMER1_REMAP_Msk       _AC(0x00000300,U)     /*!< TIMER1 remapping */
#define AFIO_PCF0_TIMER1_REMAP(x)        ((x) << AFIO_PCF0_TIMER2_REMAP_Pos)
#define AFIO_PCF0_TIMER1_REMAP_NONE      AFIO_PCF0_TIMER1_REMAP(0)
#define AFIO_PCF0_TIMER1_REMAP_PARTIAL0  AFIO_PCF0_TIMER1_REMAP(1)
#define AFIO_PCF0_TIMER1_REMAP_PARTIAL1  AFIO_PCF0_TIMER1_REMAP(2)
#define AFIO_PCF0_TIMER1_REMAP_FULL      AFIO_PCF0_TIMER1_REMAP(3)
#define AFIO_PCF0_TIMER0_REMAP_Pos       6
#define AFIO_PCF0_TIMER0_REMAP_Msk       _AC(0x000000c0,U)     /*!< TIMER0 remapping */
#define AFIO_PCF0_TIMER0_REMAP(x)        ((x) << AFIO_PCF0_TIMER0_REMAP_Pos)
#define AFIO_PCF0_TIMER0_REMAP_NONE      AFIO_PCF0_TIMER0_REMAP(0)
#define AFIO_PCF0_TIMER0_REMAP_PARTIAL   AFIO_PCF0_TIMER0_REMAP(1)
#define AFIO_PCF0_TIMER0_REMAP_FULL      AFIO_PCF0_TIMER0_REMAP(3)
#define AFIO_PCF0_USART2_REMAP_Pos       4
#define AFIO_PCF0_USART2_REMAP_Msk       _AC(0x00000030,U)     /*!< USART2 remapping */
#define AFIO_PCF0_USART2_REMAP(x)        ((x) << AFIO_PCF0_USART2_REMAP_Pos)
#define AFIO_PCF0_USART2_REMAP_NONE      AFIO_PCF0_USART2_REMAP(0)
#define AFIO_PCF0_USART2_REMAP_PARTIAL   AFIO_PCF0_USART2_REMAP(1)
#define AFIO_PCF0_USART2_REMAP_FULL      AFIO_PCF0_USART2_REMAP(3)
#define AFIO_PCF0_USART1_REMAP           _BIT(3,U)             /*!< USART1 remapping */
#define AFIO_PCF0_USART0_REMAP           _BIT(2,U)             /*!< USART0 remapping */
#define AFIO_PCF0_I2C0_REMAP             _BIT(1,U)             /*!< I2C0 remapping */
#define AFIO_PCF0_SPI0_REMAP             _BIT(0,U)             /*!< SPI0 remapping */

/* AFIO_EXTISS0 */
#define AFIO_EXTI_SS_Pos(x)              (4*((x) & 3))
#define AFIO_EXTI_SS_Msk(x)              (_AC(0xf,U) << GPIO_CTL0_MD_Pos(x))
#define AFIO_EXTI0_SS_Pos                AFIO_EXTI_SS_Pos(0)
#define AFIO_EXTI0_SS_Msk                AFIO_EXTI_SS_Msk(0)   /*!< EXTI 0 sources selection */
#define AFIO_EXTI1_SS_Pos                AFIO_EXTI_SS_Pos(1)
#define AFIO_EXTI1_SS_Msk                AFIO_EXTI_SS_Msk(1)   /*!< EXTI 1 sources selection */
#define AFIO_EXTI2_SS_Pos                AFIO_EXTI_SS_Pos(2)
#define AFIO_EXTI2_SS_Msk                AFIO_EXTI_SS_Msk(2)   /*!< EXTI 2 sources selection */
#define AFIO_EXTI3_SS_Pos                AFIO_EXTI_SS_Pos(3)
#define AFIO_EXTI3_SS_Msk                AFIO_EXTI_SS_Msk(3)   /*!< EXTI 3 sources selection */

/* AFIO_EXTISS1 */
#define AFIO_EXTI4_SS_Pos                AFIO_EXTI_SS_Pos(4)
#define AFIO_EXTI4_SS_Msk                AFIO_EXTI_SS_Msk(4)   /*!< EXTI 4 sources selection */
#define AFIO_EXTI5_SS_Pos                AFIO_EXTI_SS_Pos(5)
#define AFIO_EXTI5_SS_Msk                AFIO_EXTI_SS_Msk(5)   /*!< EXTI 5 sources selection */
#define AFIO_EXTI6_SS_Pos                AFIO_EXTI_SS_Pos(6)
#define AFIO_EXTI6_SS_Msk                AFIO_EXTI_SS_Msk(6)   /*!< EXTI 6 sources selection */
#define AFIO_EXTI7_SS_Pos                AFIO_EXTI_SS_Pos(7)
#define AFIO_EXTI7_SS_Msk                AFIO_EXTI_SS_Msk(7)   /*!< EXTI 7 sources selection */

/* AFIO_EXTISS2 */
#define AFIO_EXTI8_SS_Pos                AFIO_EXTI_SS_Pos(8)
#define AFIO_EXTI8_SS_Msk                AFIO_EXTI_SS_Msk(8)   /*!< EXTI 8 sources selection */
#define AFIO_EXTI9_SS_Pos                AFIO_EXTI_SS_Pos(9)
#define AFIO_EXTI9_SS_Msk                AFIO_EXTI_SS_Msk(9)   /*!< EXTI 9 sources selection */
#define AFIO_EXTI10_SS_Pos               AFIO_EXTI_SS_Pos(10)
#define AFIO_EXTI10_SS_Msk               AFIO_EXTI_SS_Msk(10)  /*!< EXTI 10 sources selection */
#define AFIO_EXTI11_SS_Pos               AFIO_EXTI_SS_Pos(11)
#define AFIO_EXTI11_SS_Msk               AFIO_EXTI_SS_Msk(11)  /*!< EXTI 11 sources selection */

/* AFIO_EXTISS3 */
#define AFIO_EXTI12_SS_Pos               AFIO_EXTI_SS_Pos(12)
#define AFIO_EXTI12_SS_Msk               AFIO_EXTI_SS_Msk(12)  /*!< EXTI 12 sources selection */
#define AFIO_EXTI13_SS_Pos               AFIO_EXTI_SS_Pos(13)
#define AFIO_EXTI13_SS_Msk               AFIO_EXTI_SS_Msk(13)  /*!< EXTI 13 sources selection */
#define AFIO_EXTI14_SS_Pos               AFIO_EXTI_SS_Pos(14)
#define AFIO_EXTI14_SS_Msk               AFIO_EXTI_SS_Msk(14)  /*!< EXTI 14 sources selection */
#define AFIO_EXTI15_SS_Pos               AFIO_EXTI_SS_Pos(15)
#define AFIO_EXTI15_SS_Msk               AFIO_EXTI_SS_Msk(15)  /*!< EXTI 15 sources selection */

/* AFIO_PCF1 */
#define AFIO_PCF1_EXMC_NADV              _BIT(10,U)            /*!< EXMC_NADV connect/disconnect */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_afio {
	volatile uint32_t EC;
	volatile uint32_t PCF0;
	union {
		volatile uint32_t EXTISS[4];
		struct {
			volatile uint32_t EXTISS0;
			volatile uint32_t EXTISS1;
			volatile uint32_t EXTISS2;
			volatile uint32_t EXTISS3;
		};
	};
	uint32_t reserved1;
	volatile uint32_t PCF1;
};

struct gd32vf103_gpio {
	volatile uint32_t CTL0;
	volatile uint32_t CTL1;
	volatile uint32_t ISTAT;
	volatile uint32_t OCTL;
	volatile uint32_t BOP;
	volatile uint32_t BC;
	volatile uint32_t LOCK;
};

static struct gd32vf103_afio *const AFIO  = (struct gd32vf103_afio *)AFIO_BASE;
static struct gd32vf103_gpio *const GPIOA = (struct gd32vf103_gpio *)GPIOA_BASE;
static struct gd32vf103_gpio *const GPIOB = (struct gd32vf103_gpio *)GPIOB_BASE;
static struct gd32vf103_gpio *const GPIOC = (struct gd32vf103_gpio *)GPIOC_BASE;
static struct gd32vf103_gpio *const GPIOD = (struct gd32vf103_gpio *)GPIOD_BASE;
static struct gd32vf103_gpio *const GPIOE = (struct gd32vf103_gpio *)GPIOE_BASE;

#endif
#endif
