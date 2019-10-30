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
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t dp_font_data_t;
struct dp_font {
	uint8_t width;
	uint8_t height;
	dp_font_data_t data[];
};

struct dp_image565 {
	uint8_t width;
	uint8_t height;
	uint8_t data[];
};

typedef uint8_t dp_bitstream_data_t;
struct dp_cimage {
	uint8_t width;
	uint8_t height;
	dp_bitstream_data_t data[];
};

/*
void dp_backlight_on(void);
void dp_backlight_off(void);
void dp_backlight_toggle(void);
*/

void dp_reset(void);
uint8_t dp_read1(uint8_t cmd);
void dp_madctl(uint8_t v);
void dp_sleep_in(void);
void dp_sleep_out(void);
void dp_off(void);
void dp_on(void);
void dp_init(void);
void dp_uninit(void);

void dp_fill(unsigned int x, unsigned int y, unsigned int w, unsigned int h,
		unsigned int rgb444);
void dp_fill666(unsigned int x, unsigned int y, unsigned int w, unsigned int h,
		unsigned int rgb);

void dp_line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
		unsigned int rgb444);

void dp_putchar(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, int ch);
void dp_puts(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, const char *str);

void dp_image565(unsigned int x, unsigned int y,
		const struct dp_image565 *img);
void dp_cimage(unsigned int x, unsigned int y,
		const struct dp_cimage *img);

/*
FRESULT dp_showbmp(FIL *f, unsigned int x, unsigned int y);
FRESULT dp_showbmp_at(const char *path, unsigned int x, unsigned int y);
*/

#endif
