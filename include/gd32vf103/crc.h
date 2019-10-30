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
#ifndef GD32VF103_CRC_H
#define GD32VF103_CRC_H

#include "gd32vf103.h"

#define CRC_BASE _AC(0x40023000,UL)  /*!< CRC base address */

/* register definitions */
#define CRC_DATA   _AC(0x00,UL)  /*!< CRC data register */
#define CRC_FDATA  _AC(0x04,UL)  /*!< CRC free data register */
#define CRC_CTL    _AC(0x08,UL)  /*!< CRC control register */

/* CRC_DATA */
#define CRC_DATA_DATA_Pos    0
#define CRC_DATA_DATA_Msk    _AC(0xffffffff,U)  /*!< CRC calculation result bits */
#define CRC_DATA_DATA(x)     ((x) << CRC_DATA_DATA_Pos)

/* CRC_FDATA */
#define CRC_FDATA_FDATA_Pos  0
#define CRC_FDATA_FDATA_Msk  _AC(0x000000ff,U)  /*!< CRC free data bits */
#define CRC_FDATA_FDATA(x)   ((x) << CRC_FDATA_FDATA_Pos)

/* CRC_CTL */
#define CRC_CTL_RST          _BIT(0,U)          /*!< CRC reset CRC_DATA register bit */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_crc {
	volatile uint32_t DATA;
	volatile uint32_t FDATA;
	volatile uint32_t CTL;
};

static struct gd32vf103_crc *const CRC = (struct gd32vf103_crc *)CRC_BASE;

#endif
#endif
