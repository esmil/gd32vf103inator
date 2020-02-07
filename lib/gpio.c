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
#include "lib/gpio.h"

void gpio_toggle(struct gd32vf103_gpio *port, uint32_t pins)
{
	uint32_t current = port->OCTL & pins;

	port->BOP = (current << 16) | (current ^ pins);
}

void gpio_config(struct gd32vf103_gpio *port, uint32_t pins, enum gpio_mode emode)
{
	uint32_t pin = 0x1U;
	uint32_t mask;
	uint32_t mode;
	uint32_t val;

	/* configure the eight low port pins with GPIO_CTL0 */
	mask = 0xfU;
	mode = emode;
	val = port->CTL0;
	for (; mask; pin <<= 1, mask <<= 4, mode <<= 4) {
		if (pin & pins)
			val = (val & ~mask) | mode;
	}
	port->CTL0 = val;

	/* configure the eight high port pins with GPIO_CTL1 */
	mask = 0xfU;
	mode = emode;
	val = port->CTL1;
	for (; mask; pin <<= 1, mask <<= 4, mode <<= 4) {
		if (pin & pins)
			val = (val & ~mask) | mode;
	}
	port->CTL1 = val;
}

void gpio_pin_toggle(gpio_pin_t pin)
{
	gpio_toggle(gpio_pin_port(pin), 1U << gpio_pin_nr(pin));
}

void gpio_pin_config(gpio_pin_t pin, enum gpio_mode emode)
{
	uint32_t mode = emode;
#if 0
	struct gd32vf103_gpio *port = gpio_pin_port(pin);
	unsigned int nr = 4*gpio_pin_nr(pin);

	if (nr < 4*8) {
		port->CTL0 = (port->CTL0 & ~(0xfU << nr)) | (mode << nr);
	} else {
		nr &= 0x1fU;
		port->CTL1 = (port->CTL1 & ~(0xfU << nr)) | (mode << nr);
	}
#else
	volatile uint32_t *reg = &gpio_pin_port(pin)->CTL0;
	unsigned int nr = gpio_pin_nr(pin);

	if (nr >= 8) {
		nr -= 8;
		reg++;
	}
	nr <<= 2;
	*reg = (*reg & ~(0xfU << nr)) | (mode << nr);
#endif
}
