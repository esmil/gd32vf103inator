/*
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
#ifndef GD32VF103_INFO_H
#define GD32VF103_INFO_H

#include "gd32vf103.h"

#define INFO_BASE  _AC(0x1FFFF7E0,UL)  /*!< flash size, sram size and id */

/* register definitions */
#define INFO_FLASH _AC(0x00,UL)  /*!< flash size in kilobytes */
#define INFO_SRAM  _AC(0x02,UL)  /*!< sram size in kilobytes  */
#define INFO_ID0   _AC(0x08,UL)  /*!< UNIQUE_ID bits 31:0     */
#define INFO_ID1   _AC(0x0c,UL)  /*!< UNIQUE_ID bits 63:32    */
#define INFO_ID2   _AC(0x10,UL)  /*!< UNIQUE_ID bits 95:64    */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_info {
	const uint16_t FLASH;
	const uint16_t SRAM;
	uint32_t reserved1;
	const uint32_t ID[3];
};

static struct gd32vf103_info *const INFO = (struct gd32vf103_info *)INFO_BASE;

#endif
#endif
