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
#ifndef LIB_GPIO_H
#define LIB_GPIO_H

#include <stdint.h>

#include "gd32vf103/gpio.h"

enum gpio_mode {
	GPIO_MODE_IN_ANALOG   = 0x0, /*!< analog input */
	GPIO_MODE_PP_10MHZ    = 0x1, /*!< push-pull output, max speed 10MHz */
	GPIO_MODE_PP_2MHZ     = 0x2, /*!< push-pull output, max speed 2MHz */
	GPIO_MODE_PP_50MHZ    = 0x3, /*!< push-pull output, max speed 50MHz */
	GPIO_MODE_IN_FLOAT    = 0x4, /*!< floating input */
	GPIO_MODE_OD_10MHZ    = 0x5, /*!< open-drain output, max speed 10MHz */
	GPIO_MODE_OD_2MHZ     = 0x6, /*!< open-drain output, max speed 2MHz */
	GPIO_MODE_OD_50MHZ    = 0x7, /*!< open-drain output, max speed 50MHz */
	GPIO_MODE_IN_PULL     = 0x8, /*!< input with pull up/down */
	GPIO_MODE_AF_PP_10MHZ = 0x9, /*!< alternate function push-pull, max speed 10MHz */
	GPIO_MODE_AF_PP_2MHZ  = 0xa, /*!< alternate function push-pull, max speed 2MHz */
	GPIO_MODE_AF_PP_50MHZ = 0xb, /*!< alternate function push-pull, max speed 50MHz */
	/* reserved */
	GPIO_MODE_AF_OD_10MHZ = 0xd, /*!< alternate function open-drain, max speed 10MHz */
	GPIO_MODE_AF_OD_2MHZ  = 0xe, /*!< alternate function open-drain, max speed 2MHz */
	GPIO_MODE_AF_OD_50MHZ = 0xf, /*!< alternate function open-drain, max speed 50MHz */
};


/*
 * port-based "fast" api
 */

/* GPIO pin definitions */
#define GPIO_PINMASK(x) _BIT(x,U)
#define GPIO_PIN_0                       _BIT(0,U)             /*!< GPIO pin 0 */
#define GPIO_PIN_1                       _BIT(1,U)             /*!< GPIO pin 1 */
#define GPIO_PIN_2                       _BIT(2,U)             /*!< GPIO pin 2 */
#define GPIO_PIN_3                       _BIT(3,U)             /*!< GPIO pin 3 */
#define GPIO_PIN_4                       _BIT(4,U)             /*!< GPIO pin 4 */
#define GPIO_PIN_5                       _BIT(5,U)             /*!< GPIO pin 5 */
#define GPIO_PIN_6                       _BIT(6,U)             /*!< GPIO pin 6 */
#define GPIO_PIN_7                       _BIT(7,U)             /*!< GPIO pin 7 */
#define GPIO_PIN_8                       _BIT(8,U)             /*!< GPIO pin 8 */
#define GPIO_PIN_9                       _BIT(9,U)             /*!< GPIO pin 9 */
#define GPIO_PIN_10                      _BIT(10,U)            /*!< GPIO pin 10 */
#define GPIO_PIN_11                      _BIT(11,U)            /*!< GPIO pin 11 */
#define GPIO_PIN_12                      _BIT(12,U)            /*!< GPIO pin 12 */
#define GPIO_PIN_13                      _BIT(13,U)            /*!< GPIO pin 13 */
#define GPIO_PIN_14                      _BIT(14,U)            /*!< GPIO pin 14 */
#define GPIO_PIN_15                      _BIT(15,U)            /*!< GPIO pin 15 */
#define GPIO_PIN_ALL                     _AC(0x0000ffff,U)     /*!< GPIO pin all */

static inline uint32_t
gpio_read(struct gd32vf103_gpio *port)
{
	return port->ISTAT;
}

static inline uint32_t
gpio_high(struct gd32vf103_gpio *port, uint32_t pins)
{
	return port->ISTAT & pins;
}

static inline uint32_t
gpio_get(struct gd32vf103_gpio *port, uint32_t pins)
{
	return port->OCTL & pins;
}

static inline void
gpio_write(struct gd32vf103_gpio *port, uint32_t data)
{
	port->OCTL = data;
}

static inline void
gpio_set(struct gd32vf103_gpio *port, uint32_t pins)
{
	port->BOP = pins;
}

static inline void
gpio_clear(struct gd32vf103_gpio *port, uint32_t pins)
{
	port->BC = pins;
}

void gpio_toggle(struct gd32vf103_gpio *port, uint32_t pins);
void gpio_config(struct gd32vf103_gpio *port, uint32_t pins,
		enum gpio_mode mode);

/*
 * pin-based api
 */

#ifdef GPIO_TYPE_STRUCT

typedef struct {
#ifdef GPIO_TYPE_16BIT
	uint8_t port;
	uint8_t nr;
#else
	unsigned port : 4;
	unsigned nr   : 4;
#endif
} gpio_pin_t;
#define GPIO_PIN(p, n) ((gpio_pin_t){ p, n })

static inline struct gd32vf103_gpio *
gpio_pin_port(gpio_pin_t pin)
{
	return (struct gd32vf103_gpio *)(GPIOA_BASE + pin.port*0x400UL);
}
static inline unsigned int
gpio_pin_nr(gpio_pin_t pin)
{
	return pin.nr;
}
static inline unsigned int
gpio_pin_eq(gpio_pin_t a, gpio_pin_t b)
{
	return (a.port == b.port) && (a.nr == b.nr);
}

#else
#ifdef GPIO_TYPE_16BIT

typedef uint16_t gpio_pin_t;
#define GPIO_PIN(p,n) (((gpio_pin_t)(p)<<8)|(gpio_pin_t)(n))

static inline struct gd32vf103_gpio *
gpio_pin_port(gpio_pin_t pin)
{
	return (struct gd32vf103_gpio *)(GPIOA_BASE + (pin >> 8)*0x400UL);
}
static inline unsigned int
gpio_pin_nr(gpio_pin_t pin)
{
	return pin & 0xFFU;
}

#else

typedef uint8_t gpio_pin_t;
#define GPIO_PIN(p,n) (((gpio_pin_t)(p)<<4)|(gpio_pin_t)(n))

static inline struct gd32vf103_gpio *
gpio_pin_port(gpio_pin_t pin)
{
	return (struct gd32vf103_gpio *)(GPIOA_BASE + (pin >> 4)*0x400UL);
}
static inline unsigned int
gpio_pin_nr(gpio_pin_t pin)
{
	return pin & 0xFU;
}

#endif
#endif

/* GPIO pin definitions */
#define GPIO_PA0   GPIO_PIN(0, 0)  /*!< GPIO pin A0 */
#define GPIO_PA1   GPIO_PIN(0, 1)  /*!< GPIO pin A1 */
#define GPIO_PA2   GPIO_PIN(0, 2)  /*!< GPIO pin A2 */
#define GPIO_PA3   GPIO_PIN(0, 3)  /*!< GPIO pin A3 */
#define GPIO_PA4   GPIO_PIN(0, 4)  /*!< GPIO pin A4 */
#define GPIO_PA5   GPIO_PIN(0, 5)  /*!< GPIO pin A5 */
#define GPIO_PA6   GPIO_PIN(0, 6)  /*!< GPIO pin A6 */
#define GPIO_PA7   GPIO_PIN(0, 7)  /*!< GPIO pin A7 */
#define GPIO_PA8   GPIO_PIN(0, 8)  /*!< GPIO pin A8 */
#define GPIO_PA9   GPIO_PIN(0, 9)  /*!< GPIO pin A9 */
#define GPIO_PA10  GPIO_PIN(0,10)  /*!< GPIO pin A10 */
#define GPIO_PA11  GPIO_PIN(0,11)  /*!< GPIO pin A11 */
#define GPIO_PA12  GPIO_PIN(0,12)  /*!< GPIO pin A12 */
#define GPIO_PA13  GPIO_PIN(0,13)  /*!< GPIO pin A13 */
#define GPIO_PA14  GPIO_PIN(0,14)  /*!< GPIO pin A14 */
#define GPIO_PA15  GPIO_PIN(0,15)  /*!< GPIO pin A15 */

#define GPIO_PB0   GPIO_PIN(1, 0)  /*!< GPIO pin B0 */
#define GPIO_PB1   GPIO_PIN(1, 1)  /*!< GPIO pin B1 */
#define GPIO_PB2   GPIO_PIN(1, 2)  /*!< GPIO pin B2 */
#define GPIO_PB3   GPIO_PIN(1, 3)  /*!< GPIO pin B3 */
#define GPIO_PB4   GPIO_PIN(1, 4)  /*!< GPIO pin B4 */
#define GPIO_PB5   GPIO_PIN(1, 5)  /*!< GPIO pin B5 */
#define GPIO_PB6   GPIO_PIN(1, 6)  /*!< GPIO pin B6 */
#define GPIO_PB7   GPIO_PIN(1, 7)  /*!< GPIO pin B7 */
#define GPIO_PB8   GPIO_PIN(1, 8)  /*!< GPIO pin B8 */
#define GPIO_PB9   GPIO_PIN(1, 9)  /*!< GPIO pin B9 */
#define GPIO_PB10  GPIO_PIN(1,10)  /*!< GPIO pin B10 */
#define GPIO_PB11  GPIO_PIN(1,11)  /*!< GPIO pin B11 */
#define GPIO_PB12  GPIO_PIN(1,12)  /*!< GPIO pin B12 */
#define GPIO_PB13  GPIO_PIN(1,13)  /*!< GPIO pin B13 */
#define GPIO_PB14  GPIO_PIN(1,14)  /*!< GPIO pin B14 */
#define GPIO_PB15  GPIO_PIN(1,15)  /*!< GPIO pin B15 */

#define GPIO_PC0   GPIO_PIN(2, 0)  /*!< GPIO pin C0 */
#define GPIO_PC1   GPIO_PIN(2, 1)  /*!< GPIO pin C1 */
#define GPIO_PC2   GPIO_PIN(2, 2)  /*!< GPIO pin C2 */
#define GPIO_PC3   GPIO_PIN(2, 3)  /*!< GPIO pin C3 */
#define GPIO_PC4   GPIO_PIN(2, 4)  /*!< GPIO pin C4 */
#define GPIO_PC5   GPIO_PIN(2, 5)  /*!< GPIO pin C5 */
#define GPIO_PC6   GPIO_PIN(2, 6)  /*!< GPIO pin C6 */
#define GPIO_PC7   GPIO_PIN(2, 7)  /*!< GPIO pin C7 */
#define GPIO_PC8   GPIO_PIN(2, 8)  /*!< GPIO pin C8 */
#define GPIO_PC9   GPIO_PIN(2, 9)  /*!< GPIO pin C9 */
#define GPIO_PC10  GPIO_PIN(2,10)  /*!< GPIO pin C10 */
#define GPIO_PC11  GPIO_PIN(2,11)  /*!< GPIO pin C11 */
#define GPIO_PC12  GPIO_PIN(2,12)  /*!< GPIO pin C12 */
#define GPIO_PC13  GPIO_PIN(2,13)  /*!< GPIO pin C13 */
#define GPIO_PC14  GPIO_PIN(2,14)  /*!< GPIO pin C14 */
#define GPIO_PC15  GPIO_PIN(2,15)  /*!< GPIO pin C15 */

#define GPIO_PD0   GPIO_PIN(3, 0)  /*!< GPIO pin D0 */
#define GPIO_PD1   GPIO_PIN(3, 1)  /*!< GPIO pin D1 */
#define GPIO_PD2   GPIO_PIN(3, 2)  /*!< GPIO pin D2 */
#define GPIO_PD3   GPIO_PIN(3, 3)  /*!< GPIO pin D3 */
#define GPIO_PD4   GPIO_PIN(3, 4)  /*!< GPIO pin D4 */
#define GPIO_PD5   GPIO_PIN(3, 5)  /*!< GPIO pin D5 */
#define GPIO_PD6   GPIO_PIN(3, 6)  /*!< GPIO pin D6 */
#define GPIO_PD7   GPIO_PIN(3, 7)  /*!< GPIO pin D7 */
#define GPIO_PD8   GPIO_PIN(3, 8)  /*!< GPIO pin D8 */
#define GPIO_PD9   GPIO_PIN(3, 9)  /*!< GPIO pin D9 */
#define GPIO_PD10  GPIO_PIN(3,10)  /*!< GPIO pin D10 */
#define GPIO_PD11  GPIO_PIN(3,11)  /*!< GPIO pin D11 */
#define GPIO_PD12  GPIO_PIN(3,12)  /*!< GPIO pin D12 */
#define GPIO_PD13  GPIO_PIN(3,13)  /*!< GPIO pin D13 */
#define GPIO_PD14  GPIO_PIN(3,14)  /*!< GPIO pin D14 */
#define GPIO_PD15  GPIO_PIN(3,15)  /*!< GPIO pin D15 */

#define GPIO_PE0   GPIO_PIN(4, 0)  /*!< GPIO pin E0 */
#define GPIO_PE1   GPIO_PIN(4, 1)  /*!< GPIO pin E1 */
#define GPIO_PE2   GPIO_PIN(4, 2)  /*!< GPIO pin E2 */
#define GPIO_PE3   GPIO_PIN(4, 3)  /*!< GPIO pin E3 */
#define GPIO_PE4   GPIO_PIN(4, 4)  /*!< GPIO pin E4 */
#define GPIO_PE5   GPIO_PIN(4, 5)  /*!< GPIO pin E5 */
#define GPIO_PE6   GPIO_PIN(4, 6)  /*!< GPIO pin E6 */
#define GPIO_PE7   GPIO_PIN(4, 7)  /*!< GPIO pin E7 */
#define GPIO_PE8   GPIO_PIN(4, 8)  /*!< GPIO pin E8 */
#define GPIO_PE9   GPIO_PIN(4, 9)  /*!< GPIO pin E9 */
#define GPIO_PE10  GPIO_PIN(4,10)  /*!< GPIO pin E10 */
#define GPIO_PE11  GPIO_PIN(4,11)  /*!< GPIO pin E11 */
#define GPIO_PE12  GPIO_PIN(4,12)  /*!< GPIO pin E12 */
#define GPIO_PE13  GPIO_PIN(4,13)  /*!< GPIO pin E13 */
#define GPIO_PE14  GPIO_PIN(4,14)  /*!< GPIO pin E14 */
#define GPIO_PE15  GPIO_PIN(4,15)  /*!< GPIO pin E15 */

static inline uint32_t
gpio_pin_high(gpio_pin_t pin)
{
	return gpio_pin_port(pin)->ISTAT & (1U << gpio_pin_nr(pin));
}
static inline uint32_t
gpio_pin_get(gpio_pin_t pin)
{
	return gpio_pin_port(pin)->OCTL & (1U << gpio_pin_nr(pin));
}
static inline void
gpio_pin_set(gpio_pin_t pin)
{
	gpio_pin_port(pin)->BOP = 1U << gpio_pin_nr(pin);
}
static inline void
gpio_pin_clear(gpio_pin_t pin)
{
	gpio_pin_port(pin)->BC = 1U << gpio_pin_nr(pin);
}

void gpio_pin_toggle(gpio_pin_t pin);
void gpio_pin_config(gpio_pin_t pin, enum gpio_mode mode);

#endif
