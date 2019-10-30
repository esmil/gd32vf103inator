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
#include "display.h"
#include "term.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

extern struct dp_font ter16n;

void
term_init(struct term *t, uint16_t fg, uint16_t bg)
{
	for (unsigned int i = 0; i < ARRAY_SIZE(t->buf); i++)
		t->buf[i][0] = '\n';
	t->fg = fg;
	t->bg = bg;
	t->cursor_x = 0;
	t->cursor_y = 0;
}

void
term_render(struct term *t)
{
	for (unsigned int i = 0; i <= t->cursor_y; i++) {
		unsigned int j = 0;

		for (; j < ARRAY_SIZE(t->buf[0]); j++) {
			char c = t->buf[i][j];

			if (c == '\n')
				break;
			dp_putchar(&ter16n, 8*j, 16*i, t->fg, t->bg, c);
		}
		for (; j < ARRAY_SIZE(t->buf[0]); j++)
			dp_putchar(&ter16n, 8*j, 16*i, t->fg, t->bg, ' ');
	}
	dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, '_');
}

void
term_putchar(struct term *t, char c)
{
	t->buf[t->cursor_y][t->cursor_x] = c;
	if (c == '\n') {
		dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, ' ');
		t->cursor_x = ARRAY_SIZE(t->buf[0]);
	} else {
		dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, c);
		t->cursor_x += 1;
	}
	if (t->cursor_x == ARRAY_SIZE(t->buf[0])) {
		t->cursor_x = 0;
		if (t->cursor_y == (ARRAY_SIZE(t->buf) - 1)) {
			char *d = t->buf[0];
			char *s = t->buf[1];

			while (s < &t->buf[ARRAY_SIZE(t->buf)][0])
				*d++ = *s++;
			*d = '\n';
			term_render(t);
			return;
		}
		t->cursor_y += 1;
	}
	t->buf[t->cursor_y][t->cursor_x] = '\n';
	dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, '_');
}

void
term_delete(struct term *t)
{
	dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, ' ');
	if (t->cursor_x == 0) {
		if (t->cursor_y > 0) {
			t->cursor_y -= 1;
			for (t->cursor_x = 0; t->cursor_x < (ARRAY_SIZE(t->buf[0]) - 1); t->cursor_x++) {
				if (t->buf[t->cursor_y][t->cursor_x] == '\n')
					break;
			}
		}
	} else
		t->cursor_x -= 1;
	t->buf[t->cursor_y][t->cursor_x] = '\n';
	dp_putchar(&ter16n, 8*t->cursor_x, 16*t->cursor_y, t->fg, t->bg, '_');
}
