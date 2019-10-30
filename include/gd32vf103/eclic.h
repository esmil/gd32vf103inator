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
#ifndef GD32VF103_ECLIC_H
#define GD32VF103_ECLIC_H

#include "gd32vf103.h"

#define ECLIC_BASE _AC(0xD2000000,UL)  /*!< ECLIC base address */

/* interrupt numbers */
#define RESERVED_IRQn         0  /*!< RISC-V reserved                           */
#define MSOFTWARE_IRQn        3  /*!< Software interrupt                        */
#define MTIMER_IRQn           7  /*!< CPU Timer interrupt                       */
#define MEMACCESS_IRQn       17  /*!< Bus Error interrupt                       */
#define PMON_IRQn            18  /*!< Performance Monitor                       */

#define WWDGT_IRQn           19  /*!< window watchDog timer interrupt           */
#define LVD_IRQn             20  /*!< LVD through EXTI line detect interrupt    */
#define TAMPER_IRQn          21  /*!< tamper through EXTI line detect           */
#define RTC_IRQn             22  /*!< RTC alarm interrupt                       */
#define FMC_IRQn             23  /*!< FMC interrupt                             */
#define RCU_CTC_IRQn         24  /*!< RCU and CTC interrupt                     */
#define EXTI0_IRQn           25  /*!< EXTI line 0 interrupts                    */
#define EXTI1_IRQn           26  /*!< EXTI line 1 interrupts                    */
#define EXTI2_IRQn           27  /*!< EXTI line 2 interrupts                    */
#define EXTI3_IRQn           28  /*!< EXTI line 3 interrupts                    */
#define EXTI4_IRQn           29  /*!< EXTI line 4 interrupts                    */
#define DMA0_Channel0_IRQn   30  /*!< DMA0 channel0 interrupt                   */
#define DMA0_Channel1_IRQn   31  /*!< DMA0 channel1 interrupt                   */
#define DMA0_Channel2_IRQn   32  /*!< DMA0 channel2 interrupt                   */
#define DMA0_Channel3_IRQn   33  /*!< DMA0 channel3 interrupt                   */
#define DMA0_Channel4_IRQn   34  /*!< DMA0 channel4 interrupt                   */
#define DMA0_Channel5_IRQn   35  /*!< DMA0 channel5 interrupt                   */
#define DMA0_Channel6_IRQn   36  /*!< DMA0 channel6 interrupt                   */
#define ADC0_1_IRQn          37  /*!< ADC0 and ADC1 interrupt                   */
#define CAN0_TX_IRQn         38  /*!< CAN0 TX interrupts                        */
#define CAN0_RX0_IRQn        39  /*!< CAN0 RX0 interrupts                       */
#define CAN0_RX1_IRQn        40  /*!< CAN0 RX1 interrupts                       */
#define CAN0_EWMC_IRQn       41  /*!< CAN0 EWMC interrupts                      */
#define EXTI5_9_IRQn         42  /*!< EXTI[9:5] interrupts                      */
#define TIMER0_BRK_IRQn      43  /*!< TIMER0 break interrupts                   */
#define TIMER0_UP_IRQn       44  /*!< TIMER0 update interrupts                  */
#define TIMER0_TRG_CMT_IRQn  45  /*!< TIMER0 trigger and commutation interrupts */
#define TIMER0_Channel_IRQn  46  /*!< TIMER0 channel capture compare interrupts */
#define TIMER1_IRQn          47  /*!< TIMER1 interrupt                          */
#define TIMER2_IRQn          48  /*!< TIMER2 interrupt                          */
#define TIMER3_IRQn          49  /*!< TIMER3 interrupts                         */
#define I2C0_EV_IRQn         50  /*!< I2C0 event interrupt                      */
#define I2C0_ER_IRQn         51  /*!< I2C0 error interrupt                      */
#define I2C1_EV_IRQn         52  /*!< I2C1 event interrupt                      */
#define I2C1_ER_IRQn         53  /*!< I2C1 error interrupt                      */
#define SPI0_IRQn            54  /*!< SPI0 interrupt                            */
#define SPI1_IRQn            55  /*!< SPI1 interrupt                            */
#define USART0_IRQn          56  /*!< USART0 interrupt                          */
#define USART1_IRQn          57  /*!< USART1 interrupt                          */
#define USART2_IRQn          58  /*!< USART2 interrupt                          */
#define EXTI10_15_IRQn       59  /*!< EXTI[15:10] interrupts                    */
#define RTC_ALARM_IRQn       60  /*!< RTC alarm interrupt EXTI                  */
#define USBFS_WKUP_IRQn      61  /*!< USBFS wakeup interrupt                    */

#define EXMC_IRQn            67  /*!< EXMC global interrupt                     */

#define TIMER4_IRQn          69  /*!< TIMER4 global interrupt                   */
#define SPI2_IRQn            70  /*!< SPI2 global interrupt                     */
#define UART3_IRQn           71  /*!< UART3 global interrupt                    */
#define UART4_IRQn           72  /*!< UART4 global interrupt                    */
#define TIMER5_IRQn          73  /*!< TIMER5 global interrupt                   */
#define TIMER6_IRQn          74  /*!< TIMER6 global interrupt                   */
#define DMA1_Channel0_IRQn   75  /*!< DMA1 channel0 global interrupt            */
#define DMA1_Channel1_IRQn   76  /*!< DMA1 channel1 global interrupt            */
#define DMA1_Channel2_IRQn   77  /*!< DMA1 channel2 global interrupt            */
#define DMA1_Channel3_IRQn   78  /*!< DMA1 channel3 global interrupt            */
#define DMA1_Channel4_IRQn   79  /*!< DMA1 channel3 global interrupt            */

#define CAN1_TX_IRQn         82  /*!< CAN1 TX interrupt                         */
#define CAN1_RX0_IRQn        83  /*!< CAN1 RX0 interrupt                        */
#define CAN1_RX1_IRQn        84  /*!< CAN1 RX1 interrupt                        */
#define CAN1_EWMC_IRQn       85  /*!< CAN1 EWMC interrupt                       */
#define USBFS_IRQn           86  /*!< USBFS global interrupt                    */

/* eclic info - also available in the INFO register */
#define ECLIC_NUM_INTERRUPTS 87
#define ECLIC_INTCTLBITS 4

/* register definitions */
#define ECLIC_CFG      _AC(0x0000,UL)
#define ECLIC_INFO     _AC(0x0004,UL)
#define ECLIC_MTH      _AC(0x000b,UL)
#define ECLIC_IP(x)    (_AC(0x1000,UL) + 4*(x))
#define ECLIC_IE(x)    (_AC(0x1001,UL) + 4*(x))
#define ECLIC_ATTR(x)  (_AC(0x1002,UL) + 4*(x))
#define ECLIC_CTRL(x)  (_AC(0x1003,UL) + 4*(x))

/* cfg bits */
#define ECLIC_CFG_NLBITS_Pos           1
#define ECLIC_CFG_NLBITS_Msk           0x1e
#define ECLIC_CFG_NLBITS(x)            ((x) << ECLIC_CFG_NLBITS_Pos)

/* info bits */
#define ECLIC_INFO_CLICINTCTLBITS_Pos  21
#define ECLIC_INFO_CLICINTCTLBITS_Msk  _AC(0x01e00000,U)
#define ECLIC_INFO_VERSION_Pos         13
#define ECLIC_INFO_VERSION_Msk         _AC(0x001fe000,U)
#define ECLIC_INFO_NUM_INTERRUPT_Pos   0
#define ECLIC_INFO_NUM_INTERRUPT_Msk   _AC(0x00001fff,U)

/* mth bits */
#define ECLIC_MTH_MTH_Pos              0
#define ECLIC_MTH_MTH_Msk              0xff
#define ECLIC_MTH_MTH(x)               ((x) << ECLIC_MTH_MTH_Pos)

/* ip bits */
#define ECLIC_IP_IP                    0x01

/* ie bits */
#define ECLIC_IE_IE                    0x01

/* attr bits */
#define ECLIC_ATTR_TRIG_Pos            1
#define ECLIC_ATTR_TRIG_Msk            0x06
#define ECLIC_ATTR_TRIG(x)             ((x) << ECLIC_ATTR_TRIG_Pos)
#define ECLIC_ATTR_TRIG_LEVEL          ECLIC_ATTR_TRIG(0)
#define ECLIC_ATTR_TRIG_EDGE_POS       ECLIC_ATTR_TRIG(1)
#define ECLIC_ATTR_TRIG_EDGE_NEG       ECLIC_ATTR_TRIG(3)
#define ECLIC_ATTR_SHV                 0x01

/* ctl bits */
#ifdef ECLIC_INTCTLBITS
#define ECLIC_CTL_BITS_Pos             (8 - ECLIC_INTCTLBITS)
#define ECLIC_CTL_BITS_Msk             (0x100 - (1 << ECLIC_CTL_BITS_Pos))
#define ECLIC_CTL_BITS(x)              ((x) << ECLIC_CTL_BITS_Pos)
#endif

/* constants definitions */
#define ECLIC_PRIGROUP_LEVEL0_PRIO4    0  /*!< 0 bits for level 4 bits for priority */
#define ECLIC_PRIGROUP_LEVEL1_PRIO3    1  /*!< 1 bits for level 3 bits for priority */
#define ECLIC_PRIGROUP_LEVEL2_PRIO2    2  /*!< 2 bits for level 2 bits for priority */
#define ECLIC_PRIGROUP_LEVEL3_PRIO1    3  /*!< 3 bits for level 1 bits for priority */
#define ECLIC_PRIGROUP_LEVEL4_PRIO0    4  /*!< 4 bits for level 0 bits for priority */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_eclic {
	volatile uint8_t cfg;
	uint8_t reserved1[3];
	const uint32_t info;
	uint8_t reserved2[3];
	volatile uint8_t mth;
	uint32_t reserved3[1021];
	struct {
		volatile uint8_t ip;
		volatile uint8_t ie;
		volatile uint8_t attr;
		volatile uint8_t ctl;
	} clicint[];
};

static struct gd32vf103_eclic *const ECLIC = (struct gd32vf103_eclic *)ECLIC_BASE;

#endif
#endif
