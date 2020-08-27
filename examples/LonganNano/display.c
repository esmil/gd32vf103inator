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
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "gd32vf103/rcu.h"
#include "gd32vf103/spi.h"

#include "lib/mtimer.h"
#include "lib/gpio.h"

#include "display.h"

static inline uint32_t
spi_transmitting(void)
{
	return SPI0->STAT & SPI_STAT_TRANS;
}

static inline uint32_t
spi_transmit_buffer_empty(void)
{
	return SPI0->STAT & SPI_STAT_TBE;
}

static inline uint32_t
spi_receive_buffer_nonempty(void)
{
	return SPI0->STAT & SPI_STAT_RBNE;
}

#ifdef DP_CS
static void dp__select(void)
{
	while (spi_transmitting())
		/* wait */;
	gpio_pin_clear(DP_CS);
}
static void dp__deselect(void)
{
	while (spi_transmitting())
		/* wait */;
	gpio_pin_set(DP_CS);
}
#else
static inline void dp__select(void) {}
static inline void dp__deselect(void) {}
#endif

void
dp_reset(void)
{
	gpio_pin_clear(DP_RST);
	mtimer_udelay(10);
	gpio_pin_set(DP_RST);
	mtimer_udelay(120000);
}

static void
dp__cmd(uint8_t cmd)
{
	while (spi_transmitting())
		/* wait */;
	gpio_pin_clear(DP_DC);
	SPI0->DATA = cmd;
	while (spi_transmitting())
		/* wait */;
	gpio_pin_set(DP_DC);
}

static void
dp__write(uint8_t data)
{
	while (!spi_transmit_buffer_empty())
		/* wait */;
	SPI0->DATA = data;
}

uint8_t
dp_read1(uint8_t cmd)
{
	uint32_t ctl0 = (SPI0->CTL0 & ~(SPI_CTL0_PSC_Msk | SPI_CTL0_SPIEN)) | DP_CLOCKDIV_READ;
	uint8_t data;

	SPI0->CTL0 = ctl0;
	SPI0->CTL0 = ctl0 | SPI_CTL0_SPIEN;

	dp__select();
	dp__cmd(cmd);
	SPI0->CTL0 &= ~SPI_CTL0_BDOEN;
	ctl0 = (ctl0 & ~SPI_CTL0_PSC_Msk) | DP_CLOCKDIV_WRITE;
	while (!spi_receive_buffer_nonempty())
		/* wait */;
	SPI0->CTL0 = ctl0;
	data = SPI0->DATA;
	dp__deselect();

	SPI0->CTL0 = ctl0 | SPI_CTL0_SPIEN;

	return data;
}

#if 0
void
dp_read(uint8_t cmd, uint8_t *buf, size_t len)
{
	spi_prescale(DP_CLOCKDIV_READ);
	dp__select();
	usart1_frame_bits(9);
	usart1_txdatax((((uint16_t)cmd) << 1)
			| USART_TXDATAX_RXENAT
			| USART_TXDATAX_TXTRIAT);
	gpio_pin_clear(DP_DC);
	while (spi_transmitting())
		/* wait */;
	gpio_pin_set(DP_DC);
	usart1_frame_bits(8);
	SPI0->DATA = 0x00;
	while (--len) {
		SPI0->DATA = 0x00;
		while (!usart1_rx_valid())
			/* wait */;
		*buf++ = usart1_rxdata();
	}
	while (!usart1_rx_valid())
		/* wait */;
	usart1_rx_disable();
	usart1_tx_tristate_disable();
	spi_prescale(DP_CLOCKDIV_WRITE);
	*buf++ = usart1_rxdata();
}
#endif

void
dp_cmd(uint8_t cmd)
{
	dp__select();
	dp__cmd(cmd);
	dp__deselect();
}

void
dp_madctl(uint8_t v)
{
	dp__select();
	dp__cmd(0x36);
	dp__write(v);
	dp__deselect();
}

static void
dp__colmod(uint8_t v)
{
	dp__cmd(0x3a);
	dp__write(v);
}

static void
dp__mode444(void)
{
	dp__colmod(0x03);
}

static void
dp__mode565(void)
{
	dp__colmod(0x05);
}

static void
dp__mode666(void)
{
	dp__colmod(0x06);
}

static void
dp_cmdseq(const uint8_t *p)
{
	unsigned int n;

	dp__select();
	for (n = *p++; n; n = *p++) {
		n--;
		dp__cmd(*p++);
		for (; n; n--)
			dp__write(*p++);
	}
	dp__deselect();
}

void
dp_init(void)
{
	static const uint8_t initdata[] = {
		1, 0x21, /* inverse on */
		/* cargo-culted values, not strictly needed */
		4, 0xb1, 0x05, 0x3a, 0x3a,
		4, 0xb2, 0x05, 0x3a, 0x3a,
		7, 0xb3, 0x05, 0x3a, 0x3a, 0x05, 0x3a, 0x3a,
		2, 0xb4, 0x03,
		4, 0xc0, 0x62, 0x02, 0x04,
		2, 0xc1, 0xc0,
		3, 0xc2, 0x0d, 0x00,
		3, 0xc3, 0x8d, 0x6a,
		3, 0xc4, 0x8d, 0xee,
		2, 0xc5, 0x0e,
		17, 0xe0, 0x10, 0x0e, 0x02, 0x03,
		          0x0e, 0x07, 0x02, 0x07,
		          0x0a, 0x12, 0x27, 0x37,
		          0x00, 0x0d, 0x0e, 0x10,
		17, 0xe1, 0x10, 0x0e, 0x03, 0x03,
		          0x0f, 0x06, 0x02, 0x08,
		          0x0a, 0x13, 0x26, 0x36,
		          0x00, 0x0d, 0x0e, 0x10,
		/* end of cargo-culted values */
#ifdef DP_MADCTL
		2, 0x36, DP_MADCTL,
#endif
		2, 0x3a, 0x03, /* dp__mode444() */
		0, /* terminator */
	};
	uint32_t ctl0;

	/* power up GPIOA and GPIOB */
	RCU->APB2EN |= RCU_APB2EN_PAEN | RCU_APB2EN_PBEN;
	/* power up SPI0 */
	RCU->APB2EN |= RCU_APB2EN_AFEN | RCU_APB2EN_SPI0EN;

#ifdef DP_BLK
	/* turn off backlight */
	gpio_pin_clear(DP_BLK);
	gpio_pin_config(DP_BLK, GPIO_MODE_PP_50MHZ);
#endif
#ifdef DP_CS
	/* disable chip-select */
	gpio_pin_set(DP_CS);
	gpio_pin_config(DP_CS, GPIO_MODE_PP_50MHZ);
#endif
	/* activate reset */
	gpio_pin_clear(DP_RST);
	gpio_pin_config(DP_RST, GPIO_MODE_PP_50MHZ);
	gpio_pin_set(DP_DC);
	gpio_pin_config(DP_DC,  GPIO_MODE_PP_50MHZ);
	gpio_pin_set(DP_SCL);
	gpio_pin_config(DP_SCL, GPIO_MODE_AF_PP_50MHZ);
	gpio_pin_clear(DP_SDA);
	gpio_pin_config(DP_SDA, GPIO_MODE_AF_PP_50MHZ);

	/* reset SPI0 */
	RCU->APB2RST |= RCU_APB2RST_SPI0RST;
	RCU->APB2RST &= ~RCU_APB2RST_SPI0RST;

	/* configure SPI0 */
	ctl0 = DP_CLOCKDIV_WRITE |
		SPI_CTL0_BDEN |
		SPI_CTL0_BDOEN |
		SPI_CTL0_SWNSSEN |
		SPI_CTL0_SWNSS |
		SPI_CTL0_MSTMOD |
		SPI_CTL0_CKPL |
		SPI_CTL0_CKPH;
	SPI0->CTL0 = ctl0;
	SPI0->CTL1 = 0;

	/* enable SPI0 */
	SPI0->CTL0 = ctl0 | SPI_CTL0_SPIEN;

	/* release reset */
	mtimer_udelay(15);
	gpio_pin_set(DP_RST);
	mtimer_udelay(120000);

	dp_sleep_out();
	mtimer_udelay(120000);

	dp_cmdseq(initdata);
}

void
dp_uninit(void)
{
	dp_backlight_off();

	SPI0->CTL0 = 0;
	gpio_pin_config(DP_DC,  GPIO_MODE_IN_FLOAT);
	gpio_pin_config(DP_SCL, GPIO_MODE_IN_FLOAT);
	gpio_pin_config(DP_SDA, GPIO_MODE_IN_FLOAT);
	RCU->APB2EN &= ~RCU_APB2EN_SPI0EN;
}

static void
dp___setbox(unsigned int xs, unsigned int ys, unsigned int xe, unsigned int ye)
{
	dp__cmd(0x2a);
	dp__write(xs >> 8);
	dp__write(xs);
	dp__write(xe >> 8);
	dp__write(xe);

	dp__cmd(0x2b);
	dp__write(ys >> 8);
	dp__write(ys);
	dp__write(ye >> 8);
	dp__write(ye);

	dp__cmd(0x2c);
}

#ifndef DP_OFFSET_X
#define DP_OFFSET_X 0
#endif
#ifndef DP_OFFSET_Y
#define DP_OFFSET_Y 0
#endif
static void dp__setbox(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	dp___setbox(DP_OFFSET_X + x, DP_OFFSET_Y + y,
			DP_OFFSET_X + x + w - 1,
			DP_OFFSET_Y + y + h - 1);
}

void
dp_fill(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int rgb444)
{
	uint8_t v1 = rgb444 >> 4;
	uint8_t v2 = (rgb444 << 4) | (rgb444 >> 8);
	uint8_t v3 = rgb444;
	unsigned int i = (w * h + 1)/2;

	dp__select();
	dp__setbox(x, y, w, h);
	for (; i; i--) {
		dp__write(v1);
		dp__write(v2);
		dp__write(v3);
	}
	dp__deselect();
}

void
dp_fill666(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int rgb888)
{
	unsigned int i = w * h;

	dp__select();
	dp__mode666();
	dp__setbox(x, y, w, h);
	for (; i; i--) {
		dp__write(rgb888 >> 16);
		dp__write(rgb888 >> 8);
		dp__write(rgb888);
	}

	dp__mode444();
	dp__deselect();
}

void
dp_line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
		unsigned int rgb444)
{
	unsigned int sx = (x0 < x1) ? 1 : -1;
	unsigned int sy = (y0 < y1) ? 1 : -1;
	int dx = (x0 < x1) ? x1 - x0 : x0 - x1; /* abs(x1-x0) */
	int dy = (y0 < y1) ? y0 - y1 : y1 - y0; /* -abs(y1-y0) */
	int err = dx + dy; /* error value e_xy */
	uint8_t v1 = ((rgb444 >> 4) & 0xf8U) | ((rgb444 >> 1) & 0x07U);
	uint8_t v2 = ((rgb444 << 3) & 0xe0U) | ((rgb444 << 1) & 0x1fU);

	dp__select();
	dp__mode565();
	while (1) {
		int e2;

		dp__setbox(x0, y0, 1, 1);
		dp__write(v1);
		dp__write(v2);
		if (x0 == x1 && y0 == y1)
			break;

		e2 = 2*err;
		if (e2 >= dy) { /* e_xy+e_x > 0 */
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) { /* e_xy+e_y < 0 */
			err += dx;
			y0 += sy;
		}
	}
	dp__mode444();
	dp__deselect();
}

void
dp_putchar(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, int ch)
{
	unsigned int idx = 0;
	unsigned int i;
	dp_font_data_t data;

	if (ch >= 32 && ch <= 126)
		idx = ch - 31;

	idx *= font->width * font->height;
	data = font->data[idx / (8*sizeof(dp_font_data_t))];
	data >>= idx % (8*sizeof(dp_font_data_t));

	dp__select();
	dp__setbox(x, y, font->width, font->height);
	for (i = (font->width * font->height + 1)/2; i; i--) {
		unsigned int pixel;
		uint8_t v1, v2, v3;

		if ((idx % (8*sizeof(dp_font_data_t))) == 0)
			data = font->data[idx / (8*sizeof(dp_font_data_t))];
		if (data & 1)
			pixel = fg444;
		else
			pixel = bg444;
		data >>= 1;
		idx += 1;

		v1 = pixel >> 4;
		dp__write(v1);
		v2 = pixel << 4;

		if ((idx % (8*sizeof(dp_font_data_t))) == 0)
			data = font->data[idx / (8*sizeof(dp_font_data_t))];
		if (data & 1)
			pixel = fg444;
		else
			pixel = bg444;
		data >>= 1;
		idx += 1;

		v2 |= pixel >> 8;
		dp__write(v2);
		v3 = pixel;
		dp__write(v3);
	}
	dp__deselect();
}

void
dp_puts(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444,
		const char *str)
{
	char c;

	for (c = *str++; c != '\0'; c = *str++) {
		dp_putchar(font, x, y, fg444, bg444, c);
		x += font->width;
	}
}
