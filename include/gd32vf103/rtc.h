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
#ifndef GD32VF103_RTC_H
#define GD32VF103_RTC_H

#include "gd32vf103.h"

#define RTC_BASE _AC(0x40002800,UL)  /*!< RTC base address */

/* register definitions */
#define RTC_INTEN  _AC(0x00,UL)  /*!< interrupt enable register */
#define RTC_CTL    _AC(0x04,UL)  /*!< control register */
#define RTC_PSCH   _AC(0x08,UL)  /*!< prescaler high register */
#define RTC_PSCL   _AC(0x0C,UL)  /*!< prescaler low register */
#define RTC_DIVH   _AC(0x10,UL)  /*!< divider high register */
#define RTC_DIVL   _AC(0x14,UL)  /*!< divider low register */
#define RTC_CNTH   _AC(0x18,UL)  /*!< counter high register */
#define RTC_CNTL   _AC(0x1C,UL)  /*!< counter low register */
#define RTC_ALRMH  _AC(0x20,UL)  /*!< alarm high register */
#define RTC_ALRML  _AC(0x24,UL)  /*!< alarm low register */

/* RTC_INTEN */
#define RTC_INTEN_OVIE      _BIT(2,U)          /*!< overflow interrupt enable */
#define RTC_INTEN_ALRMIE    _BIT(1,U)          /*!< alarm interrupt enable */
#define RTC_INTEN_SCIE      _BIT(0,U)          /*!< second interrupt enable */

/* RTC_CTL */
#define RTC_CTL_LWOFF       _BIT(5,U)          /*!< last write operation finished flag */
#define RTC_CTL_CMF         _BIT(4,U)          /*!< configuration mode flag */
#define RTC_CTL_RSYNF       _BIT(3,U)          /*!< registers synchronized flag */
#define RTC_CTL_OVIF        _BIT(2,U)          /*!< overflow interrupt flag */
#define RTC_CTL_ALRMIF      _BIT(1,U)          /*!< alarm interrupt flag */
#define RTC_CTL_SCIF        _BIT(0,U)          /*!< second interrupt flag */

/* RTC_PSCH */
#define RTC_PSCH_PSC_Pos    0
#define RTC_PSCH_PSC_Msk    _AC(0x0000000f,U)  /*!< prescaler high value */
#define RTC_PSCH_PSC(x)     ((x) << RTC_PSCH_PSC_Pos)

/* RTC_PSCL */
#define RTC_PSCL_PSC_Pos    0
#define RTC_PSCL_PSC_Msk    _AC(0x0000ffff,U)  /*!< prescaler low value */
#define RTC_PSCL_PSC(x)     ((x) << RTC_PSCL_PSC_Pos)

/* RTC_DIVH */
#define RTC_DIVH_DIV_Pos    0
#define RTC_DIVH_DIV_Msk    _AC(0x0000000f,U)  /*!< divider high value */

/* RTC_DIVL */
#define RTC_DIVL_DIV_Pos    0
#define RTC_DIVL_DIV_Msk    _AC(0x0000ffff,U)  /*!< divider low value */
#define RTC_DIVL_DIV(x)     ((x) << RTC_DIVL_DIV_Pos)

/* RTC_CNTH */
#define RTC_CNTH_CNT_Pos    0
#define RTC_CNTH_CNT_Msk    _AC(0x0000ffff,U)  /*!< counter high value */
#define RTC_CNTH_CNT(x)     ((x) << RTC_CNTH_CNT_Pos)

/* RTC_CNTL */
#define RTC_CNTL_CNT_Pos    0
#define RTC_CNTL_CNT_Msk    _AC(0x0000ffff,U)  /*!< counter low value */
#define RTC_CNTL_CNT(x)     ((x) << RTC_CNTL_CNT_Pos)

/* RTC_ALRMH */
#define RTC_ALRMH_ALRM_Pos  0
#define RTC_ALRMH_ALRM_Msk  _AC(0x0000ffff,U)  /*!< alarm high value */
#define RTC_ALRMH_ALRM(x)   ((x) << RTC_ALRMH_ALRM_Pos)

/* RTC_ALRML */
#define RTC_ALRML_ALRM_Pos  0
#define RTC_ALRML_ALRM_Msk  _AC(0x0000ffff,U)  /*!< alarm low value */
#define RTC_ALRML_ALRM(x)   ((x) << RTC_ALRML_ALRM_Pos)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_rtc {
	volatile uint32_t INTEN;
	volatile uint32_t RTL;
	volatile uint32_t PSCH;
	volatile uint32_t PSCL;
	volatile uint32_t DIVH;
	volatile uint32_t DIVL;
	volatile uint32_t CNTH;
	volatile uint32_t CNTL;
	volatile uint32_t ALRMH;
	volatile uint32_t ALRML;
};

static struct gd32vf103_rtc *const RTC = (struct gd32vf103_rtc *)RTC_BASE;

#endif
#endif
