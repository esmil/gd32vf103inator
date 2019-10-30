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
#include <stddef.h>

#include "gd32vf103/mtimer.h"
#include "gd32vf103/rcu.h"
#include "gd32vf103/spi.h"

#include "lib/gpio.h"

#include "display.h"

//#define DP_BLK GPIO_PA1 /* backlight */
#define DP_DC  GPIO_PB0 /* D/CX */
#define DP_RST GPIO_PB1 /* reset */
#define DP_CS  GPIO_PB2 /* chip-select */
#define DP_SDA GPIO_PA7 /* data */
#define DP_SCL GPIO_PA5 /* clock */

/* spi max write clock rate 1/(66ns) = 15 MHz
 * spi max read clock rate 1/(150ns) = 6.6 MHz
 */
#define DP_CLOCKDIV_WRITE SPI_CTL0_PSC_DIV8  /* 96MHz / 8  = 12MHz */
#define DP_CLOCKDIV_READ  SPI_CTL0_PSC_DIV32 /* 96MHz / 32 =  3MHz */

#define DP_MADCTL 0x68
#define DP_OFFSET_X 1
#define DP_OFFSET_Y 26
#define DP_TICKS_PR_US (CORECLOCK/4000000)

#if 0
#include <stdio.h>
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef DP_BLK
void dp_backlight_on(void)
{
	gpio_pin_set(DP_BLK);
}

void dp_backlight_off(void)
{
	gpio_pin_clear(DP_BLK);
}

void dp_backlight_toggle(void)
{
	gpio_pin_toggle(DP_BLK);
}
#else
static inline void dp_backlight_on(void) {}
static inline void dp_backlight_off(void) {}
static inline void dp_backlight_toggle(void) {}
#endif

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

static void
dp_udelay(unsigned int us)
{
	uint32_t zero = MTIMER->mtime_lo;
	uint32_t end = us * (CORECLOCK/4000000) + 1;
	uint32_t now;

	do {
		now = MTIMER->mtime_lo - zero;
	} while (now < end);
}

#ifdef DP_CS
static inline void dp_cs_enable(void)
{
	gpio_pin_clear(DP_CS);
}
static void dp_cs_disable(void)
{
	while (spi_transmitting())
		/* wait */;
	gpio_pin_set(DP_CS);
}
#else
static inline void dp_cs_enable(void) {}
static inline void dp_cs_disable(void) {}
#endif

void
dp_reset(void)
{
	gpio_pin_clear(DP_RST);
	dp_udelay(10);
	gpio_pin_set(DP_RST);
	dp_udelay(120000);
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

	dp_cs_enable();
	dp__cmd(cmd);
	SPI0->CTL0 &= ~SPI_CTL0_BDOEN;
	ctl0 = (ctl0 & ~SPI_CTL0_PSC_Msk) | DP_CLOCKDIV_WRITE;
	while (!spi_receive_buffer_nonempty())
		/* wait */;
	SPI0->CTL0 = ctl0;
	data = SPI0->DATA;
	dp_cs_disable();

	SPI0->CTL0 = ctl0 | SPI_CTL0_SPIEN;

	return data;
}

#if 0
void
dp_read(uint8_t cmd, uint8_t *buf, size_t len)
{
	spi_prescale(DP_CLOCKDIV_READ);
	dp_cs_enable();
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

static void
dp_cmd(uint8_t cmd)
{
	dp_cs_enable();
	dp__cmd(cmd);
	dp_cs_disable();
}

void
dp_sleep_in(void)
{
	dp_cmd(0x10);
}

void
dp_sleep_out(void)
{
	dp_cmd(0x11);
}

void
dp_off(void)
{
	dp_cmd(0x28);
}

void
dp_on(void)
{
	dp_cmd(0x29);
}

void
dp_madctl(uint8_t v)
{
	dp_cs_enable();
	dp__cmd(0x36);
	dp__write(v);
	dp_cs_disable();
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
	dp_udelay(15);
	gpio_pin_set(DP_RST);
	dp_udelay(120000);

	dp_sleep_out();
	dp_udelay(120000);

	const uint8_t *p = initdata;
	dp_cs_enable();
	for (unsigned int n = *p++; n; n = *p++) {
		n--;
		dp__cmd(*p++);
		for (; n; n--)
			dp__write(*p++);
	}
	dp_cs_disable();
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
dp__setbox(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye)
{
#if defined(DP_OFFSET_X) && DP_OFFSET_X > 0
	xs += DP_OFFSET_X;
	xe += DP_OFFSET_X - 1;
#else
	xe -= 1;
#endif
#if defined(DP_OFFSET_Y) && DP_OFFSET_Y > 0
	ys += DP_OFFSET_Y;
	ye += DP_OFFSET_Y - 1;
#else
	ye -= 1;
#endif

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

void
dp_fill(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int rgb444)
{
	uint8_t v1 = rgb444 >> 4;
	uint8_t v2 = (rgb444 << 4) | (rgb444 >> 8);
	uint8_t v3 = rgb444;
	unsigned int i;

	dp_cs_enable();
	dp__setbox(x, x + w, y, y + h);
	for (i = (w * h + 1)/2; i; i--) {
		dp__write(v1);
		dp__write(v2);
		dp__write(v3);
	}
	dp_cs_disable();
}

void
dp_line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
		unsigned int rgb444)
{
	uint8_t v1 = ((rgb444 >> 4) & 0xf8U) | ((rgb444 >> 1) & 0x07U);
	uint8_t v2 = ((rgb444 << 3) & 0xe0U) | ((rgb444 << 1) & 0x1fU);
	int dx = (x0 < x1) ? x1 - x0 : x0 - x1; /* abs(x1-x0) */
	unsigned int sx = (x0 < x1) ? 1 : -1;
	int dy = -((y0 < y1) ? y1 - y0 : y0 - y1); /* -abs(y1-y0) */
	unsigned int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy; /* error value e_xy */

	dp_cs_enable();
	dp__mode565();
	while (1) {
		dp__setbox(x0, x0 + 1, y0, y0 + 1);
		dp__write(v1);
		dp__write(v2);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2*err;
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
	dp_cs_disable();
}

void
dp_fill666(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int rgb)
{
	unsigned int i;

	dp_cs_enable();
	dp__mode666();
	dp__setbox(x, x + w , y, y + h);
	for (i = w * h; i; i--) {
		dp__write(rgb >> 16);
		dp__write(rgb >> 8);
		dp__write(rgb);
	}

	dp__mode444();
	dp_cs_disable();
}

void
dp_putchar(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444, int ch)
{
	unsigned int idx = 0;
	dp_font_data_t data;
	unsigned int i;

	if (ch >= 32 && ch <= 126)
		idx = ch - 31;

	idx *= font->width * font->height;
	data = font->data[idx / (8*sizeof(dp_font_data_t))];
	data >>= idx % (8*sizeof(dp_font_data_t));

	dp_cs_enable();
	dp__setbox(x, x + font->width, y, y + font->height);
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
	dp_cs_disable();
}

void
dp_puts(const struct dp_font *font,
		unsigned int x, unsigned int y,
		unsigned int fg444, unsigned int bg444,
		const char *str)
{
	for (char c = *str++; c != '\0'; c = *str++) {
		dp_putchar(font, x, y, fg444, bg444, c);
		x += font->width;
	}
}

void
dp_image565(unsigned int x, unsigned int y, const struct dp_image565 *img)
{
	dp_cs_enable();
	dp__mode565();
	dp__setbox(x, x + img->width, y, y + img->height);
	{
		const uint8_t *p, *end = &img->data[2 * img->width * img->height];

		for (p = &img->data[0]; p < end; p += 2) {
			dp__write(p[1]);
			dp__write(p[0]);
		}
	}
	dp__mode444();
	dp_cs_disable();
}

struct dp_bitstream {
	const dp_bitstream_data_t *p;
	dp_bitstream_data_t mask;
};

static void
dp_bitstream_init(struct dp_bitstream *bs, const dp_bitstream_data_t *p)
{
	bs->p = p;
	bs->mask = ((dp_bitstream_data_t)1) << (8*sizeof(dp_bitstream_data_t) - 1);
}

static dp_bitstream_data_t
dp_bitstream_pop(struct dp_bitstream *bs)
{
	dp_bitstream_data_t ret = *bs->p & bs->mask;

	bs->mask >>= 1;
	if (bs->mask == 0)
		dp_bitstream_init(bs, bs->p + 1);

	return ret;
}

static unsigned int
dp_bitstream_get(struct dp_bitstream *bs)
{
	unsigned int ret;

	if (!dp_bitstream_pop(bs))
		return 0;

	ret = 1;
	while (dp_bitstream_pop(bs)) {
		ret <<= 1;
		if (dp_bitstream_pop(bs))
			ret |= 1;
	}

	return ret;
}

static int
dp_bitstream_gets(struct dp_bitstream *bs)
{
	int ret = 0;

	while (dp_bitstream_pop(bs))
		ret++;

	if (dp_bitstream_pop(bs))
		return -ret;

	return ret + 1;
}

void
dp_cimage(unsigned int x, unsigned int y, const struct dp_cimage *img)
{
	struct dp_bitstream bs;
	unsigned int len = ((unsigned int)img->width) * ((unsigned int)img->height);
	unsigned int run = 0;
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	dp_bitstream_init(&bs, img->data);

	dp_cs_enable();
	dp__mode666();
	dp__setbox(x, x + img->width, y, y + img->height);
	for (; len; len--) {
		if (run == 0)
			r = ((int)r) + 4*dp_bitstream_gets(&bs);
		dp__write(r);

		if (run == 0)
			g = ((int)g) + 4*dp_bitstream_gets(&bs);

		dp__write(g);

		if (run == 0) {
			b = ((int)b) + 4*dp_bitstream_gets(&bs);
			run = dp_bitstream_get(&bs);
		} else
			run--;
		dp__write(b);
	}
	dp__mode444();
	dp_cs_disable();
}

#if 0
FRESULT
dp_showbmp(FIL *f, unsigned int x, unsigned int y)
{
	uint8_t buf[720];
	unsigned int bfSize;
	unsigned int bfOffBits;
	unsigned int biSize;
	unsigned int biWidth;
	int biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	unsigned int biCompression;
	unsigned int read;
	int linesize;
	int pos;
	FRESULT res;

	res = f_read(f, buf, 18, &read);
	if (res != FR_OK) {
		debug("f_read(f, 18) = %u\r\n", res);
		return res;
	}
	if (read < 18) {
		debug("f_read(f, 18): short read\r\n");
		return FR_INVALID_PARAMETER;
	}

	if (buf[0] != 'B' || buf[1] != 'M') {
		debug("error reading bitmap: not a BMP file\r\n");
		return FR_INVALID_PARAMETER;
	}

	bfSize = (((unsigned int)buf[2]) <<  0)
	        | (((unsigned int)buf[3]) <<  8)
	        | (((unsigned int)buf[4]) << 16)
	        | (((unsigned int)buf[5]) << 24);

	debug("bfSize = %u\r\n", bfSize);

	bfOffBits = (((unsigned int)buf[10]) <<  0)
	        | (((unsigned int)buf[11]) <<  8)
	        | (((unsigned int)buf[12]) << 16)
	        | (((unsigned int)buf[13]) << 24);

	debug("bfOffBits = %u\r\n", bfOffBits);

	biSize = (((unsigned int)buf[14]) <<  0)
	        | (((unsigned int)buf[15]) <<  8)
	        | (((unsigned int)buf[16]) << 16)
	        | (((unsigned int)buf[17]) << 24);
	debug("biSize = %u\r\n", biSize);
	if (biSize < 40) {
		debug("error reading bitmap: old OS/2 header not supported\r\n");
		return FR_INVALID_PARAMETER;
	}
	if (12 + biSize >= bfOffBits) {
		debug("error reading bitmap: bfOffBits points into header\r\n");
		return FR_INVALID_PARAMETER;
	}

	res = f_read(f, buf, 16, &read);
	if (res != FR_OK) {
		debug("f_read(f, 16) = %u\r\n", res);
		return res;
	}
	if (read < 16) {
		debug("f_read(f, 16): short read\r\n");
		return FR_INVALID_PARAMETER;
	}

	biWidth = (((unsigned int)buf[0]) <<  0)
	        | (((unsigned int)buf[1]) <<  8)
	        | (((unsigned int)buf[2]) << 16)
	        | (((unsigned int)buf[3]) << 24);
	biHeight = (((unsigned int)buf[4]) <<  0)
	        | (((unsigned int)buf[5]) <<  8)
	        | (((unsigned int)buf[6]) << 16)
	        | (((unsigned int)buf[7]) << 24);
	debug("biWidth x biHeight = %u x %d\r\n", biWidth, biHeight);

	biPlanes = (((uint16_t)buf[8]) <<  0)
	        | (((uint16_t)buf[9]) <<  8);
	if (biPlanes != 1) {
		debug("error reading bitmap: biPlanes != 1\r\n");
		return FR_INVALID_PARAMETER;
	}

	biBitCount = (((uint16_t)buf[10]) <<  0)
	        | (((uint16_t)buf[11]) <<  8);
	debug("biBitCount = %u\r\n", biBitCount);
	if (biBitCount != 24) {
		debug("error reading bitmap: only 24bit bitmaps supported\r\n");
		return FR_INVALID_PARAMETER;
	}

	biCompression = (((unsigned int)buf[12]) <<  0)
	        | (((unsigned int)buf[13]) <<  8)
	        | (((unsigned int)buf[14]) << 16)
	        | (((unsigned int)buf[15]) << 24);
	debug("biCompression = %u\r\n", biCompression);
	if (biCompression != 0) {
		debug("error reading bitmap: only uncompressed bitmaps supported\r\n");
		return FR_INVALID_PARAMETER;
	}

	linesize = 3 * biWidth;
	if (linesize & 0x3U) {
		linesize &= ~0x3U;
		linesize += 4;
	}
	if (biHeight >= 0) {
		read = bfOffBits + linesize * biHeight;
		pos = read - linesize;
		linesize = -linesize;
	} else {
		biHeight = -biHeight;
		read = bfOffBits + linesize * biHeight;
		pos = bfOffBits;
	}
	if (read > bfSize) {
		debug("error reading bitmap: file too short\r\n");
		return FR_INVALID_PARAMETER;
	}

	dp_cs_enable();
	dp__mode666();
	dp__setbox(x, x + biWidth, y, y + biHeight);
	for (; biHeight > 0; biHeight--) {
		unsigned int bytes = 3 * biWidth;
		uint8_t *p, *end;

		res = f_lseek(f, pos);
		if (res != FR_OK) {
			debug("f_lseek(f, %d) = %u\r\n", pos, res);
			goto out;
		}

		res = f_read(f, buf, bytes, &read);
		if (res != FR_OK) {
			debug("f_read(f, %u) = %u\r\n", bytes, res);
			goto out;
		}
		if (read < bytes) {
			debug("f_read(f, %u): short read\r\n", bytes);
			res = FR_INVALID_PARAMETER;
			goto out;
		}

		p = buf;
		end = buf + bytes;
		for (; p < end; p += 3) {
			dp__write(p[2]);
			dp__write(p[1]);
			dp__write(p[0]);
		}
		pos += linesize;
	}
out:
	dp__mode444();
	dp_cs_disable();
	return res;
}

FRESULT
dp_showbmp_at(const char *path, unsigned int x, unsigned int y)
{
	FIL f;
	FRESULT res;

	res = f_open(&f, path, FA_READ);
	if (res != FR_OK) {
		debug("f_open(f, \"%s\", FA_READ) = %u\r\n", path, res);
		goto err;
	}
	res = dp_showbmp(&f, x, y);
	if (res != FR_OK)
		goto err;

	return f_close(&f);
err:
	f_close(&f);
	return res;
}
#endif
