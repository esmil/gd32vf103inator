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
#ifndef GD32VF103_EXTI_H
#define GD32VF103_EXTI_H

#include "gd32vf103.h"

#define EXTI_BASE _AC(0x40010400,UL)  /*!< EXTI base address */

/* register definitions */
#define EXTI_INTEN  _AC(0x00,UL)  /*!< interrupt enable register */
#define EXTI_EVEN   _AC(0x04,UL)  /*!< event enable register */
#define EXTI_RTEN   _AC(0x08,UL)  /*!< rising edge trigger enable register */
#define EXTI_FTEN   _AC(0x0C,UL)  /*!< falling trigger enable register */
#define EXTI_SWIEV  _AC(0x10,UL)  /*!< software interrupt event register */
#define EXTI_PD     _AC(0x14,UL)  /*!< pending register */

/* EXTI_INTEN */
#define EXTI_INTEN_INTEN18   _BIT(18,U)         /*!< interrupt from line 18 */
#define EXTI_INTEN_INTEN17   _BIT(17,U)         /*!< interrupt from line 17 */
#define EXTI_INTEN_INTEN16   _BIT(16,U)         /*!< interrupt from line 16 */
#define EXTI_INTEN_INTEN15   _BIT(15,U)         /*!< interrupt from line 15 */
#define EXTI_INTEN_INTEN14   _BIT(14,U)         /*!< interrupt from line 14 */
#define EXTI_INTEN_INTEN13   _BIT(13,U)         /*!< interrupt from line 13 */
#define EXTI_INTEN_INTEN12   _BIT(12,U)         /*!< interrupt from line 12 */
#define EXTI_INTEN_INTEN11   _BIT(11,U)         /*!< interrupt from line 11 */
#define EXTI_INTEN_INTEN10   _BIT(10,U)         /*!< interrupt from line 10 */
#define EXTI_INTEN_INTEN9    _BIT(9,U)          /*!< interrupt from line 9 */
#define EXTI_INTEN_INTEN8    _BIT(8,U)          /*!< interrupt from line 8 */
#define EXTI_INTEN_INTEN7    _BIT(7,U)          /*!< interrupt from line 7 */
#define EXTI_INTEN_INTEN6    _BIT(6,U)          /*!< interrupt from line 6 */
#define EXTI_INTEN_INTEN5    _BIT(5,U)          /*!< interrupt from line 5 */
#define EXTI_INTEN_INTEN4    _BIT(4,U)          /*!< interrupt from line 4 */
#define EXTI_INTEN_INTEN3    _BIT(3,U)          /*!< interrupt from line 3 */
#define EXTI_INTEN_INTEN2    _BIT(2,U)          /*!< interrupt from line 2 */
#define EXTI_INTEN_INTEN1    _BIT(1,U)          /*!< interrupt from line 1 */
#define EXTI_INTEN_INTEN0    _BIT(0,U)          /*!< interrupt from line 0 */
#define EXTI_INTEN_INTEN(x)  _BIT(x,U)

/* EXTI_EVEN */
#define EXTI_EVEN_EVEN18     _BIT(18,U)         /*!< event from line 18 */
#define EXTI_EVEN_EVEN17     _BIT(17,U)         /*!< event from line 17 */
#define EXTI_EVEN_EVEN16     _BIT(16,U)         /*!< event from line 16 */
#define EXTI_EVEN_EVEN15     _BIT(15,U)         /*!< event from line 15 */
#define EXTI_EVEN_EVEN14     _BIT(14,U)         /*!< event from line 14 */
#define EXTI_EVEN_EVEN13     _BIT(13,U)         /*!< event from line 13 */
#define EXTI_EVEN_EVEN12     _BIT(12,U)         /*!< event from line 12 */
#define EXTI_EVEN_EVEN11     _BIT(11,U)         /*!< event from line 11 */
#define EXTI_EVEN_EVEN10     _BIT(10,U)         /*!< event from line 10 */
#define EXTI_EVEN_EVEN9      _BIT(9,U)          /*!< event from line 9 */
#define EXTI_EVEN_EVEN8      _BIT(8,U)          /*!< event from line 8 */
#define EXTI_EVEN_EVEN7      _BIT(7,U)          /*!< event from line 7 */
#define EXTI_EVEN_EVEN6      _BIT(6,U)          /*!< event from line 6 */
#define EXTI_EVEN_EVEN5      _BIT(5,U)          /*!< event from line 5 */
#define EXTI_EVEN_EVEN4      _BIT(4,U)          /*!< event from line 4 */
#define EXTI_EVEN_EVEN3      _BIT(3,U)          /*!< event from line 3 */
#define EXTI_EVEN_EVEN2      _BIT(2,U)          /*!< event from line 2 */
#define EXTI_EVEN_EVEN1      _BIT(1,U)          /*!< event from line 1 */
#define EXTI_EVEN_EVEN0      _BIT(0,U)          /*!< event from line 0 */
#define EXTI_EVEN_EVEN(x)    _BIT(x,U)

/* EXTI_RTEN */
#define EXTI_RTEN_RTEN18     _BIT(18,U)         /*!< rising edge from line 18 */
#define EXTI_RTEN_RTEN17     _BIT(17,U)         /*!< rising edge from line 17 */
#define EXTI_RTEN_RTEN16     _BIT(16,U)         /*!< rising edge from line 16 */
#define EXTI_RTEN_RTEN15     _BIT(15,U)         /*!< rising edge from line 15 */
#define EXTI_RTEN_RTEN14     _BIT(14,U)         /*!< rising edge from line 14 */
#define EXTI_RTEN_RTEN13     _BIT(13,U)         /*!< rising edge from line 13 */
#define EXTI_RTEN_RTEN12     _BIT(12,U)         /*!< rising edge from line 12 */
#define EXTI_RTEN_RTEN11     _BIT(11,U)         /*!< rising edge from line 11 */
#define EXTI_RTEN_RTEN10     _BIT(10,U)         /*!< rising edge from line 10 */
#define EXTI_RTEN_RTEN9      _BIT(9,U)          /*!< rising edge from line 9 */
#define EXTI_RTEN_RTEN8      _BIT(8,U)          /*!< rising edge from line 8 */
#define EXTI_RTEN_RTEN7      _BIT(7,U)          /*!< rising edge from line 7 */
#define EXTI_RTEN_RTEN6      _BIT(6,U)          /*!< rising edge from line 6 */
#define EXTI_RTEN_RTEN5      _BIT(5,U)          /*!< rising edge from line 5 */
#define EXTI_RTEN_RTEN4      _BIT(4,U)          /*!< rising edge from line 4 */
#define EXTI_RTEN_RTEN3      _BIT(3,U)          /*!< rising edge from line 3 */
#define EXTI_RTEN_RTEN2      _BIT(2,U)          /*!< rising edge from line 2 */
#define EXTI_RTEN_RTEN1      _BIT(1,U)          /*!< rising edge from line 1 */
#define EXTI_RTEN_RTEN0      _BIT(0,U)          /*!< rising edge from line 0 */
#define EXTI_RTEN_RTEN(x)    _BIT(x,U)

/* EXTI_FTEN */
#define EXTI_FTEN_FTEN18     _BIT(18,U)         /*!< falling edge from line 18 */
#define EXTI_FTEN_FTEN17     _BIT(17,U)         /*!< falling edge from line 17 */
#define EXTI_FTEN_FTEN16     _BIT(16,U)         /*!< falling edge from line 16 */
#define EXTI_FTEN_FTEN15     _BIT(15,U)         /*!< falling edge from line 15 */
#define EXTI_FTEN_FTEN14     _BIT(14,U)         /*!< falling edge from line 14 */
#define EXTI_FTEN_FTEN13     _BIT(13,U)         /*!< falling edge from line 13 */
#define EXTI_FTEN_FTEN12     _BIT(12,U)         /*!< falling edge from line 12 */
#define EXTI_FTEN_FTEN11     _BIT(11,U)         /*!< falling edge from line 11 */
#define EXTI_FTEN_FTEN10     _BIT(10,U)         /*!< falling edge from line 10 */
#define EXTI_FTEN_FTEN9      _BIT(9,U)          /*!< falling edge from line 9 */
#define EXTI_FTEN_FTEN8      _BIT(8,U)          /*!< falling edge from line 8 */
#define EXTI_FTEN_FTEN7      _BIT(7,U)          /*!< falling edge from line 7 */
#define EXTI_FTEN_FTEN6      _BIT(6,U)          /*!< falling edge from line 6 */
#define EXTI_FTEN_FTEN5      _BIT(5,U)          /*!< falling edge from line 5 */
#define EXTI_FTEN_FTEN4      _BIT(4,U)          /*!< falling edge from line 4 */
#define EXTI_FTEN_FTEN3      _BIT(3,U)          /*!< falling edge from line 3 */
#define EXTI_FTEN_FTEN2      _BIT(2,U)          /*!< falling edge from line 2 */
#define EXTI_FTEN_FTEN1      _BIT(1,U)          /*!< falling edge from line 1 */
#define EXTI_FTEN_FTEN0      _BIT(0,U)          /*!< falling edge from line 0 */
#define EXTI_FTEN_FTEN(x)    _BIT(x,U)

/* EXTI_SWIEV */
#define EXTI_SWIEV_SWIEV18   _BIT(18,U)         /*!< software interrupt/event request from line 18 */
#define EXTI_SWIEV_SWIEV17   _BIT(17,U)         /*!< software interrupt/event request from line 17 */
#define EXTI_SWIEV_SWIEV16   _BIT(16,U)         /*!< software interrupt/event request from line 16 */
#define EXTI_SWIEV_SWIEV15   _BIT(15,U)         /*!< software interrupt/event request from line 15 */
#define EXTI_SWIEV_SWIEV14   _BIT(14,U)         /*!< software interrupt/event request from line 14 */
#define EXTI_SWIEV_SWIEV13   _BIT(13,U)         /*!< software interrupt/event request from line 13 */
#define EXTI_SWIEV_SWIEV12   _BIT(12,U)         /*!< software interrupt/event request from line 12 */
#define EXTI_SWIEV_SWIEV11   _BIT(11,U)         /*!< software interrupt/event request from line 11 */
#define EXTI_SWIEV_SWIEV10   _BIT(10,U)         /*!< software interrupt/event request from line 10 */
#define EXTI_SWIEV_SWIEV9    _BIT(9,U)          /*!< software interrupt/event request from line 9 */
#define EXTI_SWIEV_SWIEV8    _BIT(8,U)          /*!< software interrupt/event request from line 8 */
#define EXTI_SWIEV_SWIEV7    _BIT(7,U)          /*!< software interrupt/event request from line 7 */
#define EXTI_SWIEV_SWIEV6    _BIT(6,U)          /*!< software interrupt/event request from line 6 */
#define EXTI_SWIEV_SWIEV5    _BIT(5,U)          /*!< software interrupt/event request from line 5 */
#define EXTI_SWIEV_SWIEV4    _BIT(4,U)          /*!< software interrupt/event request from line 4 */
#define EXTI_SWIEV_SWIEV3    _BIT(3,U)          /*!< software interrupt/event request from line 3 */
#define EXTI_SWIEV_SWIEV2    _BIT(2,U)          /*!< software interrupt/event request from line 2 */
#define EXTI_SWIEV_SWIEV1    _BIT(1,U)          /*!< software interrupt/event request from line 1 */
#define EXTI_SWIEV_SWIEV0    _BIT(0,U)          /*!< software interrupt/event request from line 0 */
#define EXTI_SWIEV_SWIEV(x)  _BIT(x,U)

/* EXTI_PD */
#define EXTI_PD_PD18         _BIT(18,U)         /*!< interrupt/event pending status from line 18 */
#define EXTI_PD_PD17         _BIT(17,U)         /*!< interrupt/event pending status from line 17 */
#define EXTI_PD_PD16         _BIT(16,U)         /*!< interrupt/event pending status from line 16 */
#define EXTI_PD_PD15         _BIT(15,U)         /*!< interrupt/event pending status from line 15 */
#define EXTI_PD_PD14         _BIT(14,U)         /*!< interrupt/event pending status from line 14 */
#define EXTI_PD_PD13         _BIT(13,U)         /*!< interrupt/event pending status from line 13 */
#define EXTI_PD_PD12         _BIT(12,U)         /*!< interrupt/event pending status from line 12 */
#define EXTI_PD_PD11         _BIT(11,U)         /*!< interrupt/event pending status from line 11 */
#define EXTI_PD_PD10         _BIT(10,U)         /*!< interrupt/event pending status from line 10 */
#define EXTI_PD_PD9          _BIT(9,U)          /*!< interrupt/event pending status from line 9 */
#define EXTI_PD_PD8          _BIT(8,U)          /*!< interrupt/event pending status from line 8 */
#define EXTI_PD_PD7          _BIT(7,U)          /*!< interrupt/event pending status from line 7 */
#define EXTI_PD_PD6          _BIT(6,U)          /*!< interrupt/event pending status from line 6 */
#define EXTI_PD_PD5          _BIT(5,U)          /*!< interrupt/event pending status from line 5 */
#define EXTI_PD_PD4          _BIT(4,U)          /*!< interrupt/event pending status from line 4 */
#define EXTI_PD_PD3          _BIT(3,U)          /*!< interrupt/event pending status from line 3 */
#define EXTI_PD_PD2          _BIT(2,U)          /*!< interrupt/event pending status from line 2 */
#define EXTI_PD_PD1          _BIT(1,U)          /*!< interrupt/event pending status from line 1 */
#define EXTI_PD_PD0          _BIT(0,U)          /*!< interrupt/event pending status from line 0 */
#define EXTI_PD_PD(x)        _BIT(x,U)

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_exti {
	volatile uint32_t INTEN;
	volatile uint32_t EVEN;
	volatile uint32_t RTEN;
	volatile uint32_t FTEN;
	volatile uint32_t SWIEV;
	volatile uint32_t PD;
};

static struct gd32vf103_exti *const EXTI = (struct gd32vf103_exti *)EXTI_BASE;

#endif
#endif
