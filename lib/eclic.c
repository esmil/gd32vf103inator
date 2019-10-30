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
#include <stdint.h>

#include "gd32vf103/csr.h"

#include "lib/eclic.h"

#ifdef ECLIC_NUM_INTERRUPTS
static inline unsigned int eclic_num_interrupts(void) { return ECLIC_NUM_INTERRUPTS; }
#else
static unsigned int eclic_num_interrupts(void)
{
	return ECLIC->info & ECLIC_INFO_NUM_INTERRUPT_Msk;
}
#endif

void eclic_init(void)
{
	unsigned int num_irq = eclic_num_interrupts();

	/* use all available bits as level-bits. ie.
	 * all interrupts preempt lower level interrupts
	 */
	ECLIC->cfg = 4 << ECLIC_CFG_NLBITS_Pos;

	/* clear all ie and ip bits for all interrupt sources */
	for (unsigned int i = 0; i < num_irq; i++) {
		ECLIC->clicint[i].ie = 0;
		ECLIC->clicint[i].ip = 0;
	}

	/* clear mth register */
	ECLIC->mth = 0;

	/* set the NMI base to share with mtvec by setting CSR_MMISC_CTL */
	csr_set(CSR_MMISC_CTL, CSR_MMISC_CTL_NMI_CAUSE_FFF);

	/* initialize mtvt */
	csr_write(CSR_MTVT, (unsigned long)&vector_base);

	/* initialize mtvt2 and enable it */
	csr_write(CSR_MTVT2, (unsigned long)&irq_entry + CSR_MTVT2_MTVT2EN);

	/* intialize mtvec for the trap and NMI base addr and enable eclic mode */
	csr_write(CSR_MTVEC, (unsigned long)&trap_entry + CSR_MTVEC_MODE_ECLIC);
}

void eclic_config(unsigned int irq, uint8_t type, uint8_t priority)
{
	ECLIC->clicint[irq].attr = type;
	ECLIC->clicint[irq].ctl = ECLIC_CTL_BITS(priority);
}
