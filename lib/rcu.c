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

#include "lib/rcu.h"

/* reset the RCC clock configuration to the default reset state */
void rcu_sysclk_reset(void)
{
	/* enable IRC8M */
	RCU->CTL |= RCU_CTL_IRC8MEN;

	/* reset SCS, AHBPSC, APB1PSC, APB2PSC, ADCPSC, CKOUT0SEL bits */
	RCU->CFG0 &= ~(RCU_CFG0_SCS_Msk |
			RCU_CFG0_AHBPSC_Msk |
			RCU_CFG0_APB1PSC_Msk |
			RCU_CFG0_APB2PSC_Msk |
			RCU_CFG0_ADCPSC_Msk |
			RCU_CFG0_CKOUT0SEL_Msk);

	/* reset HXTALEN, CKMEN, PLLEN bits */
	RCU->CTL &= ~(RCU_CTL_HXTALEN | RCU_CTL_CKMEN | RCU_CTL_PLLEN);

	/* reset HXTALBPS bit */
	RCU->CTL &= ~RCU_CTL_HXTALBPS;

	/* reset PLLSEL, PREDV0_LSB, PLLMF, USBFSPSC bits */
	RCU->CFG0 &= ~(RCU_CFG0_USBFSPSC_Msk |
			RCU_CFG0_PLLMF_Msk |
			RCU_CFG0_PREDV0_LSB |
			RCU_CFG0_PLLSEL);
	RCU->CFG1 = 0x00000000U;

	/* reset HXTALEN, CKMEN, PLLEN, PLL1EN and PLL2EN bits */
	RCU->CTL &= ~(RCU_CTL_PLLEN |
			RCU_CTL_PLL1EN |
			RCU_CTL_PLL2EN |
			RCU_CTL_CKMEN |
			RCU_CTL_HXTALEN);

	/* disable and clear all interrupts */
	RCU->INT = 0x00ff0000U;

}

void rcu_sysclk_pll_irc8m(uint32_t cfg0)
{
	RCU->CFG0 = (RCU->CFG0 & ~(
			RCU_CFG0_PLLMF_Msk |
			RCU_CFG0_PLLSEL |
			RCU_CFG0_AHBPSC_Msk |
			RCU_CFG0_APB2PSC_Msk |
			RCU_CFG0_APB1PSC_Msk)) | cfg0;

	/* enable PLL */
	RCU->CTL |= RCU_CTL_PLLEN;
	/* wait until PLL is stable */
	while (!(RCU->CTL & RCU_CTL_PLLSTB))
		/* wait */;

	/* select PLL as system clock */
	RCU->CFG0 = (RCU->CFG0 & ~RCU_CFG0_SCS_Msk) | RCU_CFG0_SCS_PLL;
	/* wait until PLL is selected as system clock */
	while ((RCU->CFG0 & RCU_CFG0_SCSS_Msk) != RCU_CFG0_SCSS_PLL)
		/* wait */;
}

void rcu_sysclk_hxtal(uint32_t cfg0, uint32_t cfg1)
{
	/* enable HXTAL */
	RCU->CTL |= RCU_CTL_HXTALEN;
	RCU->CFG0 |= cfg0;
	RCU->CFG1 |= cfg1;

	/* wait until HXTAL is stable */
	while (!(RCU->CTL & RCU_CTL_HXTALSTB))
		/* wait */;

	if (cfg1 & RCU_CFG1_PREDV0SEL) {
		/* enable PLL1 */
		RCU->CTL |= RCU_CTL_PLL1EN;
		/* wait till PLL1 is ready */
		while (!(RCU->CTL & RCU_CTL_PLL1STB))
			/* wait */;
	}

	if (cfg0 & RCU_CFG0_PLLSEL) {
		/* enable PLL */
		RCU->CTL |= RCU_CTL_PLLEN;
		/* wait until PLL is stable */
		while (!(RCU->CTL & RCU_CTL_PLLSTB))
			/* wait */;

		/* select PLL as system clock */
		RCU->CFG0 = (RCU->CFG0 & ~RCU_CFG0_SCS_Msk) | RCU_CFG0_SCS_PLL;
		/* wait until PLL is selected as system clock */
		while ((RCU->CFG0 & RCU_CFG0_SCSS_Msk) != RCU_CFG0_SCSS_PLL)
			/* wait */;
	} else {
		/* select HXTAL as system clock */
		RCU->CFG0 = (RCU->CFG0 & ~RCU_CFG0_SCS_Msk) | RCU_CFG0_SCS_HXTAL;
		/* wait until HXTAL is selected as system clock */
		while ((RCU->CFG0 & RCU_CFG0_SCSS_Msk) != RCU_CFG0_SCSS_HXTAL)
			/* wait */;
	}
}

void rcu_sysclk_init(void)
{
#if BOOTLOADER == 0
	rcu_sysclk_reset();
#endif
#ifndef HXTAL
#if CORECLOCK == 108000000
	rcu_sysclk_pll_irc8m(RCU_CFG0_PLLMF_MUL27 | RCU_CFG0_APB1PSC_DIV2);
#elif CORECLOCK == 96000000
	rcu_sysclk_pll_irc8m(RCU_CFG0_PLLMF_MUL24 | RCU_CFG0_APB1PSC_DIV2);
#else
#error "Unsupported CORECLOCK value, please call rcu_sysclk_pll_irc8m() manually."
#endif
#elif HXTAL == 25000000
#if CORECLOCK == 108000000
	rcu_sysclk_hxtal(RCU_CFG0_PLLMF_MUL27 |
			RCU_CFG0_PLLSEL |
			RCU_CFG0_APB1PSC_DIV2,
			RCU_CFG1_PLL1MF_MUL8 |
			RCU_CFG1_PREDV0SEL |
			RCU_CFG1_PREDV1_DIV5 |
			RCU_CFG1_PREDV0_DIV10);
#elif CORECLOCK == 96000000
	rcu_sysclk_hxtal(RCU_CFG0_PLLMF_MUL24 |
			RCU_CFG0_USBFSPSC_DIV2 |
			RCU_CFG0_PLLSEL |
			RCU_CFG0_APB1PSC_DIV2,
			RCU_CFG1_PLL1MF_MUL8 |
			RCU_CFG1_PREDV0SEL |
			RCU_CFG1_PREDV1_DIV5 |
			RCU_CFG1_PREDV0_DIV10);
#else
#error "Unsupported CORECLOCK value, please call rcu_sysclk_hxtal() manually."
#endif
#elif HXTAL == 8000000
#if CORECLOCK == 108000000
	rcu_sysclk_hxtal(RCU_CFG0_PLLMF_MUL27 |
			RCU_CFG0_PLLSEL |
			RCU_CFG0_APB1PSC_DIV2,
			RCU_CFG1_PREDV0_DIV2);
#elif CORECLOCK == 96000000
	rcu_sysclk_hxtal(RCU_CFG0_PLLMF_MUL24 |
			RCU_CFG0_USBFSPSC_DIV2 |
			RCU_CFG0_PLLSEL |
			RCU_CFG0_APB1PSC_DIV2,
			RCU_CFG1_PREDV0_DIV2);
#else
#error "Unsupported CORECLOCK value, please call rcu_sysclk_hxtal() manually."
#endif
#else
#error "Unsupported HXTAL value, please call rcu_sysclk_hxtal() manually."
#endif
}
