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
#ifndef LIB_ECLIB_H
#define LIB_ECLIB_H

#include <stdint.h>

#include "riscv/csr.h"
#include "gd32vf103/eclic.h"

extern __attribute__((aligned(512)))
unsigned long vector_base[ECLIC_NUM_INTERRUPTS];

#ifdef __interrupt
__interrupt
#endif
__attribute__((aligned(64)))
__attribute__((section(".text.init.trap")))
void trap_entry(void);

#ifdef __interrupt
__interrupt
#endif
__attribute__((aligned(4)))
__attribute__((section(".text.init.irq")))
void irq_entry(void);

static inline void eclic_enable(unsigned int irq)
{
	ECLIC->clicint[irq].ie = ECLIC_IE_IE;
}

static inline void eclic_disable(unsigned int irq)
{
	ECLIC->clicint[irq].ie = 0;
}

static inline void eclic_pending_set(unsigned int irq)
{
	ECLIC->clicint[irq].ip = ECLIC_IP_IP;
}

static inline void eclic_pending_clear(unsigned int irq)
{
	ECLIC->clicint[irq].ip = 0;
}

static inline void eclic_global_interrupt_enable(void)
{
	csr_set(CSR_MSTATUS, CSR_MSTATUS_MIE);
}

static inline void eclic_global_interrupt_disable(void)
{
	csr_clear(CSR_MSTATUS, CSR_MSTATUS_MIE);
}

void eclic_init(void);
void eclic_config(unsigned int irq, uint8_t type, uint8_t priority);

#endif
