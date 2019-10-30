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
#ifndef GD32VF103_DMA_H
#define GD32VF103_DMA_H

#include "gd32vf103.h"

#define DMA0_BASE _AC(0x40020000,UL)  /*!< DMA0 base address */
#define DMA1_BASE _AC(0x40020400,UL)  /*!< DMA1 base address */

/* register definitions */
#define DMA_INTF      _AC(0x00,UL)  /*!< DMA interrupt flag register */
#define DMA_INTC      _AC(0x04,UL)  /*!< DMA interrupt flag clear register */

#define DMA_CH0CTL    _AC(0x08,UL)  /*!< DMA channel 0 control register */
#define DMA_CH0CNT    _AC(0x0C,UL)  /*!< DMA channel 0 counter register */
#define DMA_CH0PADDR  _AC(0x10,UL)  /*!< DMA channel 0 peripheral base address register */
#define DMA_CH0MADDR  _AC(0x14,UL)  /*!< DMA channel 0 memory base address register */

#define DMA_CH1CTL    _AC(0x1C,UL)  /*!< DMA channel 1 control register */
#define DMA_CH1CNT    _AC(0x20,UL)  /*!< DMA channel 1 counter register */
#define DMA_CH1PADDR  _AC(0x24,UL)  /*!< DMA channel 1 peripheral base address register */
#define DMA_CH1MADDR  _AC(0x28,UL)  /*!< DMA channel 1 memory base address register */

#define DMA_CH2CTL    _AC(0x30,UL)  /*!< DMA channel 2 control register */
#define DMA_CH2CNT    _AC(0x34,UL)  /*!< DMA channel 2 counter register */
#define DMA_CH2PADDR  _AC(0x38,UL)  /*!< DMA channel 2 peripheral base address register */
#define DMA_CH2MADDR  _AC(0x3C,UL)  /*!< DMA channel 2 memory base address register */

#define DMA_CH3CTL    _AC(0x44,UL)  /*!< DMA channel 3 control register */
#define DMA_CH3CNT    _AC(0x48,UL)  /*!< DMA channel 3 counter register */
#define DMA_CH3PADDR  _AC(0x4C,UL)  /*!< DMA channel 3 peripheral base address register */
#define DMA_CH3MADDR  _AC(0x50,UL)  /*!< DMA channel 3 memory base address register */

#define DMA_CH4CTL    _AC(0x58,UL)  /*!< DMA channel 4 control register */
#define DMA_CH4CNT    _AC(0x5C,UL)  /*!< DMA channel 4 counter register */
#define DMA_CH4PADDR  _AC(0x60,UL)  /*!< DMA channel 4 peripheral base address register */
#define DMA_CH4MADDR  _AC(0x64,UL)  /*!< DMA channel 4 memory base address register */

#define DMA_CH5CTL    _AC(0x6C,UL)  /*!< DMA channel 5 control register */
#define DMA_CH5CNT    _AC(0x70,UL)  /*!< DMA channel 5 counter register */
#define DMA_CH5PADDR  _AC(0x74,UL)  /*!< DMA channel 5 peripheral base address register */
#define DMA_CH5MADDR  _AC(0x78,UL)  /*!< DMA channel 5 memory base address register */

#define DMA_CH6CTL    _AC(0x80,UL)  /*!< DMA channel 6 control register */
#define DMA_CH6CNT    _AC(0x84,UL)  /*!< DMA channel 6 counter register */
#define DMA_CH6PADDR  _AC(0x88,UL)  /*!< DMA channel 6 peripheral base address register */
#define DMA_CH6MADDR  _AC(0x8C,UL)  /*!< DMA channel 6 memory base address register */

/* DMA_INTF */
#define DMA_INTF_ERRIF6             _BIT(27,U)                 /*!< error flag of channel 6 */
#define DMA_INTF_HTFIF6             _BIT(26,U)                 /*!< half transfer finish flag of channel 6 */
#define DMA_INTF_FTFIF6             _BIT(25,U)                 /*!< full transfer finish flag of channel 6 */
#define DMA_INTF_GIF6               _BIT(24,U)                 /*!< global interrupt flag of channel 6 */
#define DMA_INTF_ERRIF5             _BIT(23,U)                 /*!< error flag of channel 5 */
#define DMA_INTF_HTFIF5             _BIT(22,U)                 /*!< half transfer finish flag of channel 5 */
#define DMA_INTF_FTFIF5             _BIT(21,U)                 /*!< full transfer finish flag of channel 5 */
#define DMA_INTF_GIF5               _BIT(20,U)                 /*!< global interrupt flag of channel 5 */
#define DMA_INTF_ERRIF4             _BIT(19,U)                 /*!< error flag of channel 4 */
#define DMA_INTF_HTFIF4             _BIT(18,U)                 /*!< half transfer finish flag of channel 4 */
#define DMA_INTF_FTFIF4             _BIT(17,U)                 /*!< full transfer finish flag of channel 4 */
#define DMA_INTF_GIF4               _BIT(16,U)                 /*!< global interrupt flag of channel 4 */
#define DMA_INTF_ERRIF3             _BIT(15,U)                 /*!< error flag of channel 3 */
#define DMA_INTF_HTFIF3             _BIT(14,U)                 /*!< half transfer finish flag of channel 3 */
#define DMA_INTF_FTFIF3             _BIT(13,U)                 /*!< full transfer finish flag of channel 3 */
#define DMA_INTF_GIF3               _BIT(12,U)                 /*!< global interrupt flag of channel 3 */
#define DMA_INTF_ERRIF2             _BIT(11,U)                 /*!< error flag of channel 2 */
#define DMA_INTF_HTFIF2             _BIT(10,U)                 /*!< half transfer finish flag of channel 2 */
#define DMA_INTF_FTFIF2             _BIT(9,U)                  /*!< full transfer finish flag of channel 2 */
#define DMA_INTF_GIF2               _BIT(8,U)                  /*!< global interrupt flag of channel 2 */
#define DMA_INTF_ERRIF1             _BIT(7,U)                  /*!< error flag of channel 1 */
#define DMA_INTF_HTFIF1             _BIT(6,U)                  /*!< half transfer finish flag of channel 1 */
#define DMA_INTF_FTFIF1             _BIT(5,U)                  /*!< full transfer finish flag of channel 1 */
#define DMA_INTF_GIF1               _BIT(4,U)                  /*!< global interrupt flag of channel 1 */
#define DMA_INTF_ERRIF0             _BIT(3,U)                  /*!< error flag of channel 0 */
#define DMA_INTF_HTFIF0             _BIT(2,U)                  /*!< half transfer finish flag of channel 0 */
#define DMA_INTF_FTFIF0             _BIT(1,U)                  /*!< full transfer finish flag of channel 0 */
#define DMA_INTF_GIF0               _BIT(0,U)                  /*!< global interrupt flag of channel 0 */
#define DMA_INTF_ERRIF(x)           (_AC(1,U) << (4*(x) + 3))  /*!< error flag of channel x */
#define DMA_INTF_HTFIF(x)           (_AC(1,U) << (4*(x) + 2))  /*!< half transfer finish flag of channel x */
#define DMA_INTF_FTFIF(x)           (_AC(1,U) << (4*(x) + 1))  /*!< full transfer finish flag of channel x */
#define DMA_INTF_GIF(x)             (_AC(1,U) << (4*(x) + 0))  /*!< global interrupt flag of channel x */

/* DMA_INTC */
#define DMA_INTC_ERRIFC6            _BIT(27,U)                 /*!< clear error flag of channel 6 */
#define DMA_INTC_HTFIFC6            _BIT(26,U)                 /*!< clear half transfer finish flag of channel 6 */
#define DMA_INTC_FTFIFC6            _BIT(25,U)                 /*!< clear transfer finish flag of channel 6 */
#define DMA_INTC_GIFC6              _BIT(24,U)                 /*!< clear global interrupt flag of channel 6 */
#define DMA_INTC_ERRIFC5            _BIT(23,U)                 /*!< clear error flag of channel 5 */
#define DMA_INTC_HTFIFC5            _BIT(22,U)                 /*!< clear half transfer finish flag of channel 5 */
#define DMA_INTC_FTFIFC5            _BIT(21,U)                 /*!< clear transfer finish flag of channel 5 */
#define DMA_INTC_GIFC5              _BIT(20,U)                 /*!< clear global interrupt flag of channel 5 */
#define DMA_INTC_ERRIFC4            _BIT(19,U)                 /*!< clear error flag of channel 4 */
#define DMA_INTC_HTFIFC4            _BIT(18,U)                 /*!< clear half transfer finish flag of channel 4 */
#define DMA_INTC_FTFIFC4            _BIT(17,U)                 /*!< clear transfer finish flag of channel 4 */
#define DMA_INTC_GIFC4              _BIT(16,U)                 /*!< clear global interrupt flag of channel 4 */
#define DMA_INTC_ERRIFC3            _BIT(15,U)                 /*!< clear error flag of channel 3 */
#define DMA_INTC_HTFIFC3            _BIT(14,U)                 /*!< clear half transfer finish flag of channel 3 */
#define DMA_INTC_FTFIFC3            _BIT(13,U)                 /*!< clear transfer finish flag of channel 3 */
#define DMA_INTC_GIFC3              _BIT(12,U)                 /*!< clear global interrupt flag of channel 3 */
#define DMA_INTC_ERRIFC2            _BIT(11,U)                 /*!< clear error flag of channel 2 */
#define DMA_INTC_HTFIFC2            _BIT(10,U)                 /*!< clear half transfer finish flag of channel 2 */
#define DMA_INTC_FTFIFC2            _BIT(9,U)                  /*!< clear transfer finish flag of channel 2 */
#define DMA_INTC_GIFC2              _BIT(8,U)                  /*!< clear global interrupt flag of channel 2 */
#define DMA_INTC_ERRIFC1            _BIT(7,U)                  /*!< clear error flag of channel 1 */
#define DMA_INTC_HTFIFC1            _BIT(6,U)                  /*!< clear half transfer finish flag of channel 1 */
#define DMA_INTC_FTFIFC1            _BIT(5,U)                  /*!< clear transfer finish flag of channel 1 */
#define DMA_INTC_GIFC1              _BIT(4,U)                  /*!< clear global interrupt flag of channel 1 */
#define DMA_INTC_ERRIFC0            _BIT(3,U)                  /*!< clear error flag of channel 0 */
#define DMA_INTC_HTFIFC0            _BIT(2,U)                  /*!< clear half transfer finish flag of channel 0 */
#define DMA_INTC_FTFIFC0            _BIT(1,U)                  /*!< clear transfer finish flag of channel 0 */
#define DMA_INTC_GIFC0              _BIT(0,U)                  /*!< clear global interrupt flag of channel 0 */
#define DMA_INTC_ERRIFC(x)          (_AC(1,U) << (4*(x) + 3))  /*!< clear error flag of channel x */
#define DMA_INTC_HTFIFC(x)          (_AC(1,U) << (4*(x) + 2))  /*!< clear half transfer finish flag of channel x */
#define DMA_INTC_FTFIFC(x)          (_AC(1,U) << (4*(x) + 1))  /*!< clear transfer finish flag of channel x */
#define DMA_INTC_GIFC(x)            (_AC(1,U) << (4*(x) + 0))  /*!< clear global interrupt flag of channel x */

/* DMA_CHxCTL, x=0..6 */
#define DMA_CHXCTL_M2M              _BIT(14,U)                 /*!< memory to memory mode */
#define DMA_CHXCTL_PRIO_Pos         12
#define DMA_CHXCTL_PRIO_Msk         _AC(0x00003000,U)          /*!< priority level */
#define DMA_CHXCTL_PRIO(x)          ((x) << DMA_CHXCTL_PRIO_Pos)
#define DMA_CHXCTL_PRIO_LOW         DMA_CHXCTL_PRIO(0)         /*!< low priority */
#define DMA_CHXCTL_PRIO_MEDIUM      DMA_CHXCTL_PRIO(1)         /*!< medium priority */
#define DMA_CHXCTL_PRIO_HIGH        DMA_CHXCTL_PRIO(2)         /*!< high priority */
#define DMA_CHXCTL_PRIO_ULTRA_HIGH  DMA_CHXCTL_PRIO(3)         /*!< ultra high priority */
#define DMA_CHXCTL_MWIDTH_Pos       10
#define DMA_CHXCTL_MWIDTH_Msk       _AC(0x00000c00,U)          /*!< transfer data width of memory */
#define DMA_CHXCTL_MWIDTH(x)        ((x) << DMA_CHXCTL_MWIDTH_Pos)
#define DMA_CHXCTL_MWIDTH_8BIT      DMA_CHXCTL_MWIDTH(0)       /*!< transfer data size of memory is 8-bit */
#define DMA_CHXCTL_MWIDTH_16BIT     DMA_CHXCTL_MWIDTH(1)       /*!< transfer data size of memory is 16-bit */
#define DMA_CHXCTL_MWIDTH_32BIT     DMA_CHXCTL_MWIDTH(2)       /*!< transfer data size of memory is 32-bit */
#define DMA_CHXCTL_PWIDTH_Pos       8
#define DMA_CHXCTL_PWIDTH_Msk       _AC(0x00000300,U)          /*!< transfer data width of peripheral */
#define DMA_CHXCTL_PWIDTH(x)        ((x) << DMA_CHXCTL_PWIDTH_Pos)
#define DMA_CHXCTL_PWIDTH_8BIT      DMA_CHXCTL_PWIDTH(0)       /*!< transfer data size of peripheral is 8-bit */
#define DMA_CHXCTL_PWIDTH_16BIT     DMA_CHXCTL_PWIDTH(1)       /*!< transfer data size of peripheral is 16-bit */
#define DMA_CHXCTL_PWIDTH_32BIT     DMA_CHXCTL_PWIDTH(2)       /*!< transfer data size of peripheral is 32-bit */
#define DMA_CHXCTL_MNAGA            _BIT(7,U)                  /*!< next address generation algorithm of memory */
#define DMA_CHXCTL_PNAGA            _BIT(6,U)                  /*!< next address generation algorithm of peripheral */
#define DMA_CHXCTL_CMEN             _BIT(5,U)                  /*!< circular mode enable */
#define DMA_CHXCTL_DIR              _BIT(4,U)                  /*!< transfer direction */
#define DMA_CHXCTL_ERRIE            _BIT(3,U)                  /*!< enable bit for channel error interrupt */
#define DMA_CHXCTL_HTFIE            _BIT(2,U)                  /*!< enable bit for channel half transfer finish interrupt */
#define DMA_CHXCTL_FTFIE            _BIT(1,U)                  /*!< enable bit for channel full transfer finish interrupt */
#define DMA_CHXCTL_CHEN             _BIT(0,U)                  /*!< channel enable */

/* DMA_CHxCNT, x=0..6 */
#define DMA_CHXCNT_CNT_Pos          0
#define DMA_CHXCNT_CNT_Msk          _AC(0x0000ffff,U)          /*!< transfer counter */
#define DMA_CHXCNT_CNT(x)           ((x) << DMA_CHXCNT_CNT_Pos)

/* DMA_CHxPADDR, x=0..6 */
#define DMA_CHXPADDR_PADDR_Pos      0
#define DMA_CHXPADDR_PADDR_Msk      _AC(0xffffffff,U)          /*!< peripheral base address */
#define DMA_CHXPADDR_PADDR(x)       ((x) << DMA_CHXPADDR_PADDR_Pos)

/* DMA_CHxMADDR, x=0..6 */
#define DMA_CHXPADDR_MADDR_Pos      0
#define DMA_CHXMADDR_MADDR_Msk      _AC(0xffffffff,U)          /*!< memory base address */
#define DMA_CHXPADDR_MADDR(x)       ((x) << DMA_CHXPADDR_MADDR_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_dma_channel {
	volatile uint32_t CTL;
	volatile uint32_t CNT;
	volatile uint32_t PADDR;
	volatile uint32_t MADDR;
	uint32_t reserved;
};

struct gd32vf103_dma {
	volatile uint32_t INTF;
	volatile uint32_t INTC;
	union {
		struct gd32vf103_dma_channel CH[7];
		struct {
			volatile uint32_t CH0CTL;
			volatile uint32_t CH0CNT;
			volatile uint32_t CH0PADDR;
			volatile uint32_t CH0MADDR;
			uint32_t reserved0;
			volatile uint32_t CH1CTL;
			volatile uint32_t CH1CNT;
			volatile uint32_t CH1PADDR;
			volatile uint32_t CH1MADDR;
			uint32_t reserved1;
			volatile uint32_t CH2CTL;
			volatile uint32_t CH2CNT;
			volatile uint32_t CH2PADDR;
			volatile uint32_t CH2MADDR;
			uint32_t reserved2;
			volatile uint32_t CH3CTL;
			volatile uint32_t CH3CNT;
			volatile uint32_t CH3PADDR;
			volatile uint32_t CH3MADDR;
			uint32_t reserved3;
			volatile uint32_t CH4CTL;
			volatile uint32_t CH4CNT;
			volatile uint32_t CH4PADDR;
			volatile uint32_t CH4MADDR;
			uint32_t reserved4;
			volatile uint32_t CH5CTL;
			volatile uint32_t CH5CNT;
			volatile uint32_t CH5PADDR;
			volatile uint32_t CH5MADDR;
			uint32_t reserved5;
			volatile uint32_t CH6CTL;
			volatile uint32_t CH6CNT;
			volatile uint32_t CH6PADDR;
			volatile uint32_t CH6MADDR;
			uint32_t reserved6;
		};
	};
};

static struct gd32vf103_dma *const DMA0 = (struct gd32vf103_dma *)DMA0_BASE;
static struct gd32vf103_dma *const DMA1 = (struct gd32vf103_dma *)DMA1_BASE;

#endif
#endif
