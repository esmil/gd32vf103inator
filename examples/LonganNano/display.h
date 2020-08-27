/*
 * Copyright (c) 2019-2020, Emil Renner Berthing
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
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*
 * Connection and display configuration
 */

/* there is no pin for the backlight on the Longan Nano */
//#define DP_BLK GPIO_PA1 /* backlight */
#define DP_DC  GPIO_PB0 /* D/CX */
#define DP_RST GPIO_PB1 /* reset */
#define DP_CS  GPIO_PB2 /* chip-select */
#define DP_SDA GPIO_PA7 /* data */
#define DP_SCL GPIO_PA5 /* clock */

/* spi max write clock rate 1/(66ns) = 15 MHz */
#define DP_CLOCKDIV_WRITE SPI_CTL0_PSC_DIV8  /* 96MHz / 8  = 12MHz */
/* spi max read clock rate 1/(150ns) = 6.6 MHz */
#define DP_CLOCKDIV_READ  SPI_CTL0_PSC_DIV32 /* 96MHz / 32 =  3MHz */

#define DP_MADCTL 0x68
#define DP_OFFSET_X 1
#define DP_OFFSET_Y 26

#define DP_WIDTH  160
#define DP_HEIGHT  80

/*
 * Display API
 */

typedef uint8_t dp_font_data_t;
struct dp_font {
	uint8_t width;
	uint8_t height;
	dp_font_data_t data[];
};

#ifdef DP_BLK
static inline void dp_backlight_on(void)
{
	gpio_pin_set(DP_BLK);
}

static inline void dp_backlight_off(void)
{
	gpio_pin_clear(DP_BLK);
}

static inline void dp_backlight_toggle(void)
{
	gpio_pin_toggle(DP_BLK);
}
#else
static inline void dp_backlight_on(void) {}
static inline void dp_backlight_off(void) {}
static inline void dp_backlight_toggle(void) {}
#endif

void dp_reset(void);
uint8_t dp_read1(uint8_t cmd);
void dp_madctl(uint8_t v);
void dp_cmd(uint8_t cmd);
static inline void dp_sleep_in(void)  { dp_cmd(0x10); }
static inline void dp_sleep_out(void) { dp_cmd(0x11); }
static inline void dp_off(void)       { dp_cmd(0x28); }
static inline void dp_on(void)        { dp_cmd(0x29); }

void dp_init(void);
void dp_uninit(void);

void dp_fill(unsigned int x, unsigned int y, unsigned int w, unsigned int h,
		unsigned int rgb444);
void dp_fill666(unsigned int x, unsigned int y, unsigned int w, unsigned int h,
		unsigned int rgb888);

void dp_line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
		unsigned int rgb444);

void dp_putchar(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, int ch);
void dp_puts(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, const char *str);
#endif
