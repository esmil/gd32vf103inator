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
#ifndef GD32VF103_EXMC_H
#define GD32VF103_EXMC_H

#include "gd32vf103.h"

#define EXMC_BASE _AC(0xA0000000,UL)  /*!< EXMC register base address */

/* register definitions */
#define EXMC_SNCTL0    _AC(0x000,UL)  /*!< EXMC SRAM/NOR flash control register 0 */
#define EXMC_SNTCFG0   _AC(0x004,UL)  /*!< EXMC SRAM/NOR flash timing configuration register 0 */
#define EXMC_SNWTCFG0  _AC(0x104,UL)  /*!< EXMC SRAM/NOR flash write timing configuration register 0 */

/* EXMC_SNCTLx, x=0 */
#define EXMC_SNCTL_ASYNCWAIT   _BIT(15,U)          /*!< asynchronous wait */
#define EXMC_SNCTL_NRWTEN      _BIT(13,U)          /*!< NWAIT signal enable */
#define EXMC_SNCTL_WREN        _BIT(12,U)          /*!< write enable */
#define EXMC_SNCTL_NRWTPOL     _BIT(9,U)           /*!< NWAIT signal polarity */
#define EXMC_SNCTL_NREN        _BIT(6,U)           /*!< NOR flash access enable */
#define EXMC_SNCTL_NRW_Pos     4
#define EXMC_SNCTL_NRW_Msk     _AC(0x00000030,U)   /*!< NOR bank memory data bus width */
#define EXMC_SNCTL_NRW(x)      ((x) << EXMC_SNCTL_NRW_Pos)
#define EXMC_SNCTL_NRW_8B      EXMC_SNCTL_NRW(0)   /*!< NOR data width 8 bits */
#define EXMC_SNCTL_NRW_16B     EXMC_SNCTL_NRW(1)   /*!< NOR data width 16 bits */
#define EXMC_SNCTL_NRTP_Pos    2
#define EXMC_SNCTL_NRTP_Msk    _AC(0x0000000c,U)   /*!< NOR bank memory type */
#define EXMC_SNCTL_NRTP(x)     ((x) << EXMC_SNCTL_NRTP_Pos)
#define EXMC_SNCTL_NRTP_SRAM   EXMC_SNCTL_NRTP(0)  /*!< SRAM,ROM */
#define EXMC_SNCTL_NRTP_PSRAM  EXMC_SNCTL_NRTP(1)  /*!< PSRAM,CRAM */
#define EXMC_SNCTL_NRTP_NOR    EXMC_SNCTL_NRTP(2)  /*!< NOR flash */
#define EXMC_SNCTL_NRMUX       _BIT(1,U)           /*!< NOR bank memory address/data multiplexing */
#define EXMC_SNCTL_NRBKEN      _BIT(0,U)           /*!< NOR bank enable */

/* EXMC_SNTCFGx, x=0 */
#define EXMC_SNTCFG_BUSLAT_Pos 16
#define EXMC_SNTCFG_BUSLAT_Msk _AC(0x000f0000,U)   /*!< bus latency */
#define EXMC_SNTCFG_BUSLAT(x)  ((x) << EXMC_SNTCFG_BUSLAT_Pos)
#define EXMC_SNTCFG_DSET_Pos   8
#define EXMC_SNTCFG_DSET_Msk   _AC(0x0000ff00,U)   /*!< data setup time */
#define EXMC_SNTCFG_DSET(x)    ((x) << EXMC_SNTCFG_DSET_Pos)
#define EXMC_SNTCFG_AHLD_Pos   4
#define EXMC_SNTCFG_AHLD_Msk   _AC(0x000000f0,U)   /*!< address hold time */
#define EXMC_SNTCFG_AHLD(x)    ((x) << EXMC_SNTCFG_AHLD_Pos)
#define EXMC_SNTCFG_ASET_Pos   0
#define EXMC_SNTCFG_ASET_Msk   _AC(0x0000000f,U)   /*!< address setup time */
#define EXMC_SNTCFG_ASET(x)    ((x) << EXMC_SNTCFG_ASET_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_exmc {
	volatile uint32_t SNCTL0;
	volatile uint32_t SNTCFG0;
	uint32_t reserved1[63];
	volatile uint32_t SNWTCFG0;
};

static struct gd32vf103_exmc *const EXMC = (struct gd32vf103_exmc *)EXMC_BASE;

#endif
#endif
