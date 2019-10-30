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
#include <stdbool.h>
#include <stdarg.h>

#include "gd32vf103/rcu.h"
#include "gd32vf103/usart.h"

#include "lib/gpio.h"
#include "lib/xprintf.h"

#include "uart0.h"

int uart0_getchar(void)
{
	while (!(USART0->STAT & USART_STAT_RBNE))
		/* wait */;

	return USART0->DATA;
}

static void
uart0__putc(const struct xo *xo, char c)
{
	static bool seenr;

	if (c == '\n' && !seenr) {
		while (!(USART0->STAT & USART_STAT_TBE))
			/* wait */;
		USART0->DATA = '\r';
	}

	seenr = (c == '\r');

	while (!(USART0->STAT & USART_STAT_TBE))
		/* wait */;
	USART0->DATA = c;
}

static void
uart0__done(const struct xo *xo)
{
}

void
uart0_init(uint32_t pclk, uint32_t target)
{
	/* enable GPIO clock */
	RCU->APB2EN |= RCU_APB2EN_PAEN;
	/* enable USART clock */
	RCU->APB2EN |= RCU_APB2EN_USART0EN;

	gpio_pin_config(GPIO_PA9,  GPIO_MODE_AF_PP_50MHZ);
	gpio_pin_config(GPIO_PA10, GPIO_MODE_IN_FLOAT);

	/* reset usart0 */
	RCU->APB2RST |= RCU_APB2RST_USART0RST;
	RCU->APB2RST &= ~RCU_APB2RST_USART0RST;

	/* set baudrate */
	USART0->BAUD = (2*pclk + target) / (2*target);
	/* set 1 stop bit */
	USART0->CTL1 = USART_CTL1_STB_1;
	/* enable rx and tx */
	USART0->CTL0 = USART_CTL0_TEN | USART_CTL0_REN;
	/* enable usart0 */
	USART0->CTL0 |= USART_CTL0_UEN;
}

const struct xo uart0_xo = {
	.putc = uart0__putc,
	.done = uart0__done,
};

void uart0_puts(const char *s)
{
	xo_puts(&uart0_xo, s);
}

void uart0_printf(const char *restrict fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	xo_vprintf(&uart0_xo, fmt, ap);
	va_end(ap);
}
