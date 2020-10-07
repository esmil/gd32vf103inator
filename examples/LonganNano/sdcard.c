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
#include "lib/gpio.h"

#include "sdcard.h"

#define SD_CRC    1  /* check crcs */
#define SD_LEGACY 1  /* support old cards */

/* SD Specifications Part 1 Physical Layer Simplified Specification
 * says initialization clock must be <= 400kHz */
#define SD_CLOCKDIV_INIT SPI_CTL0_PSC_DIV256 /* 96MHz / 256 = 375kHz */
/* ..but it doesn't say anything about SPI speed after initialization.
 * The lowest regular bus speed is 25MHz, but in SPI mode at least one card
 * doesn't answer at 12MHz, so let's use 6MHz for now */
#define SD_CLOCKDIV_RUN  SPI_CTL0_PSC_DIV16  /* 96MHz / 16  = 6MHz */

#define SD_TRIES (1 << 15)

#define SD_CTL0_OFF (SPI_CTL0_SWNSSEN | SPI_CTL0_SWNSS | SPI_CTL0_MSTMOD)
#define SD_CTL0_ON  (SPI_CTL0_SWNSSEN | SPI_CTL0_MSTMOD | SPI_CTL0_SPIEN)

#define SD_CS   GPIO_PB12
#define SD_CLK  GPIO_PB13
#define SD_MISO GPIO_PB14
#define SD_MOSI GPIO_PB15

#if 0
#include <stdio.h>
#define debug(...) printf("  " __VA_ARGS__)
#else
#define debug(...)
#endif

static bool block_addressing;

static unsigned int
sd_crc7(unsigned int crc, uint8_t b)
{
     unsigned int i;

     crc ^= b;
     for (i = 8; i > 0; i--) {
	     if (crc & 0x80)
		     crc ^= 0x09;
	     crc <<= 1;
     }
     return crc;
}

#if SD_CRC
static unsigned int
sd_crc16(unsigned int crc, uint8_t b)
{
	unsigned int i;

	crc ^= (unsigned int)b << 8;
	for (i = 8; i > 0; i--) {
		if (crc & 0x8000)
			crc = (crc << 1) ^ 0x1021;
		else
			crc <<= 1;
	}

	return crc;
}
#endif

void
sd_init(void)
{
	/* enable GPIOB and AF clocks */
	RCU->APB2EN |= RCU_APB2EN_PBEN | RCU_APB2EN_AFEN;
	/* enable SPI1 clock */
	RCU->APB1EN |= RCU_APB1EN_SPI1EN;

	/* configure pins */
	gpio_pin_set(SD_CS);
	gpio_pin_clear(SD_CLK);
	gpio_pin_set(SD_MOSI);
	gpio_pin_set(SD_MISO);
	gpio_pin_config(SD_CS,   GPIO_MODE_AF_PP_50MHZ);
	gpio_pin_config(SD_CLK,  GPIO_MODE_AF_PP_50MHZ);
	gpio_pin_config(SD_MISO, GPIO_MODE_IN_FLOAT);    /* external pull-up */
	gpio_pin_config(SD_MOSI, GPIO_MODE_AF_OD_50MHZ); /* external pull-up */

	/* reset SPI1 */
	RCU->APB1RST |= RCU_APB1RST_SPI1RST;
	RCU->APB1RST &= ~RCU_APB1RST_SPI1RST;

	/* configure SPI1 */
	SPI1->CTL0 = SD_CLOCKDIV_RUN | SD_CTL0_OFF;
	SPI1->CTL1 = SPI_CTL1_NSSDRV;
}

void
sd_uninit(void)
{
	/* disable SPI1 clock */
	RCU->APB1EN &= ~RCU_APB1EN_SPI1EN;
}

static void
sd__select(void)
{
	SPI1->CTL0 = SD_CLOCKDIV_RUN | SD_CTL0_ON;
}

static void
sd__deselect(void)
{
	while (SPI1->STAT & SPI_STAT_TRANS)
		/* wait */;
	SPI1->CTL0 = SD_CLOCKDIV_RUN | SD_CTL0_OFF;
}

static void
sd__putbyte(uint8_t b)
{
	while (!(SPI1->STAT & SPI_STAT_TBE))
		/* wait */;
	SPI1->DATA = b;
}

static void
sd__flush(void)
{
	while (SPI1->STAT & SPI_STAT_TRANS)
		/* wait */;
	(void)SPI1->DATA;
}

static uint8_t
sd__getbyte(void)
{
	SPI1->DATA = 0xff;
	while (!(SPI1->STAT & SPI_STAT_RBNE))
		/* wait */;
	return SPI1->DATA;
}

static uint8_t
sd__cmd(uint8_t cmd, uint32_t arg, uint8_t *response, unsigned int len)
{
	unsigned int crc = 0;
	unsigned int i;
	uint8_t ret;

	sd__putbyte(0xff);
	sd__putbyte(cmd | 0x40);
	crc = sd_crc7(crc, cmd | 0x40);
	sd__putbyte(arg >> 24);
	crc = sd_crc7(crc, arg >> 24);
	sd__putbyte(arg >> 16);
	crc = sd_crc7(crc, arg >> 16);
	sd__putbyte(arg >> 8);
	crc = sd_crc7(crc, arg >> 8);
	sd__putbyte(arg);
	crc = sd_crc7(crc, arg);
	sd__putbyte(crc + 1);
	sd__flush();
	for (i = SD_TRIES; i > 0; i--) {
		ret = sd__getbyte();
		if (ret != 0xff)
			break;
	}
	if (ret & 0xfe) {
		debug("CMD%u: %02x\n", cmd, ret);
		goto out;
	}
	for (; len > 0; len--)
		*response++ = sd__getbyte();
out:
	return ret;
}

uint8_t
sd_wakeup(void)
{
	uint32_t response;
	unsigned int i;
	uint8_t ret;

	block_addressing = false;

	SPI1->CTL0 = SD_CLOCKDIV_INIT | SD_CTL0_OFF;
	SPI1->CTL0 = SD_CLOCKDIV_INIT | SD_CTL0_ON;

	debug("Sending dummy bits.. ");
	/* send 80 (at least 75) dummy bits */
	for (i = 10; i > 0; i--)
		sd__putbyte(0xff);
	debug(" done\n");
	/* software reset aka go idle */
	ret = sd__cmd(0, 0, NULL, 0);
	debug("CMD0: %02x\n", ret);
	if (ret != 0x01)
		goto out;

#if SD_CRC
	/* enable crc checking */
	ret = sd__cmd(59, 1, NULL, 0);
	debug("CMD59: %02x\n", ret);
	if (ret != 0x01)
		goto out;
#endif

	/* set voltage range or conclude it's an old card */
	ret = sd__cmd(8, 0x1aa, (uint8_t *)&response, 4);
	debug("CMD8: %02x (0x%08lx)\n", ret, __builtin_bswap32(response));
	if (ret == 0x01) {
		if (response != 0xaa010000U) {
			ret = 0xc0;
			goto out;
		}

		for (i = SD_TRIES; i > 0; i--) {
			ret = sd__cmd(55, 0, NULL, 0);
			if (ret != 0x01)
				goto out;

			ret = sd__cmd(41, 0x40000000, NULL, 0);
			if (ret == 0x00)
				break;
			if (ret != 0x01)
				goto out;
		}
		debug("ACMD41: %02x\n", ret);
		if (ret != 0x00) {
			ret = 0x81;
			goto out;
		}
		ret = sd__cmd(58, 0, (uint8_t *)&response, 4);
		debug("CMD58: %02x (0x%08lx)\n", ret, __builtin_bswap32(response));
		if (ret != 0x00)
			goto out;
		/* CCS bit means SDHC/SDXC */
		if (response & 0x40) {
			block_addressing = true;
			goto out;
		}
#if SD_LEGACY
	} else if (ret == 0x05) {
		for (i = SD_TRIES; i > 0; i--) {
			ret = sd__cmd(55, 0, NULL, 0);
			debug("CMD55: %02x\n", ret);
			if (ret & 0x04) {
				ret = 0x01;
				break;
			}
			if (ret != 0x01)
				goto out;

			ret = sd__cmd(41, 0, NULL, 0);
			debug("ACMD41: %02x\n", ret);
			if (ret == 0x00)
				break;
			if (ret & 0x04) {
				ret = 0x01;
				break;
			}
			if (ret != 0x01)
				goto out;
		}
		for (i = SD_TRIES; ret == 0x01 && i > 0; i--) {
			ret = sd__cmd(1, 0, NULL, 0);
			debug("CMD1: %02x\n", ret);
		}
		if (ret != 0x00) {
			ret = 0x82;
			goto out;
		}
#endif
	} else
		goto out;

	/* force blocksize to 512 bytes */
	ret = sd__cmd(16, 512, NULL, 0);
	debug("CMD16: %02x\n", ret);
out:
	sd__deselect();
	return ret;
}

static uint8_t
sd_cmd(uint8_t cmd, uint32_t arg, uint8_t *response, unsigned int len)
{
	uint8_t ret;

	debug("sd_cmd(%u, %lu, buf, %u):\n", cmd, arg, len);

	sd__select();
	ret = sd__cmd(cmd, arg, response, len);
	sd__deselect();
	return ret;
}

uint8_t
sd_getocr(uint8_t ocr[4])
{
	return sd_cmd(58, 0, ocr, 4);
}

uint8_t
sd_status(uint8_t *status)
{
	return sd_cmd(13, 0, status, 1);
}

static uint8_t
sd_read(uint8_t cmd, uint32_t arg, uint8_t *buf, unsigned int len)
{
	unsigned int i;
	uint8_t ret;

	debug("sd_read(%u, %lu, buf, %u):\n", cmd, arg, len);

	sd__select();
	ret = sd__cmd(cmd, arg, NULL, 0);
	if (ret != 0x00) {
		debug("CMD%u: %02x\n", cmd, ret);
		goto out;
	}
	for (i = SD_TRIES; i > 0; i--) {
		ret = sd__getbyte();
		if (ret != 0xff)
			break;
	}
	if (ret != 0xfe) {
		debug("data token: %02x\n", ret);
		goto out;
	}
#if SD_CRC
	unsigned int crc = 0;
	for (; len > 0; len--) {
		uint8_t b = sd__getbyte();

		*buf++ = b;
		crc = sd_crc16(crc, b);
	}
	crc -= (unsigned int)sd__getbyte() << 8;
	crc -= (unsigned int)sd__getbyte();
	ret = (crc & 0xffff) ? 0x88 : 0x00;
#else
	for (; len > 0; len--)
		*buf++ = sd__getbyte();
	sd__putbyte(0xff);
	sd__putbyte(0xff);
	ret = 0x00;
#endif
out:
	sd__deselect();
	return ret;
}

uint8_t
sd_getcsd(uint8_t csd[16])
{
	return sd_read(9, 0, csd, 16);
}

uint8_t
sd_getcid(uint8_t cid[16])
{
	return sd_read(10, 0, cid, 16);
}

uint8_t
sd_getblocks(uint32_t *blocks)
{
	uint8_t csd[16];
	uint8_t ret;
	unsigned int c_size;
#if SD_LEGACY
	unsigned int read_bl_len;
	unsigned int c_size_mult;
#endif

	ret = sd_getcsd(csd);
	debug("sd_getcsd() = %u\n", ret);
	if (ret != 0x00)
		return ret;

	switch (csd[0] >> 6) {
#if SD_LEGACY
	case 0:
		debug("CSD v1.0\n");
		read_bl_len = csd[5] & 0x0f;
		debug("read_bl_len = %u\n", read_bl_len);

		c_size = csd[6] & 0x03;
		c_size <<= 8;
		c_size |= csd[7];
		c_size <<= 8;
		c_size |= csd[8];
		c_size >>= 6;
		debug("c_size = %u\n", c_size);

		c_size_mult = csd[9] & 0x03;
		c_size_mult <<= 8;
		c_size_mult |= csd[10];
		c_size_mult >>= 7;
		debug("c_size_mult = %u\n", c_size_mult);

		c_size += 1;
		c_size <<= c_size_mult + 2;
		debug("blocknr = %u\n", c_size);

		c_size <<= read_bl_len;
		c_size >>= 9;
		debug("blocks = %u\n", c_size);
		*blocks = c_size;
		break;
#endif
	case 1:
		debug("CSD v2.0\n");
		c_size = csd[7] & 0x3f;
		c_size <<= 8;
		c_size |= csd[8];
		c_size <<= 8;
		c_size |= csd[9];
		debug("c_size = %u\n", c_size);

		c_size += 1;
		c_size <<= 10;
		debug("blocks = %u\n", c_size);
		*blocks = c_size;
		break;
	default:
		ret = 0xc0;
		break;
	}
	return ret;
}

uint8_t
sd_geterasesectorsize(uint32_t *size)
{
	uint8_t csd[16];
	uint8_t ret;
#if SD_LEGACY
	unsigned int write_bl_len;
	unsigned int erase_sector_size;
#endif

	ret = sd_getcsd(csd);
	debug("sd_getcsd() = %u\n", ret);
	if (ret != 0x00)
		return ret;

	switch (csd[0] >> 6) {
#if SD_LEGACY
	case 0:
		debug("CSD v1.0\n");
		if (csd[10] & 0x40) {
			debug("erase_blk_en = 1\n");
			*size = 512;
			break;
		}
		erase_sector_size = csd[10] & 0x3f;
		erase_sector_size <<= 8;
		erase_sector_size |= csd[11];
		erase_sector_size >>= 7;
		debug("erase_sector_size = %u\n", erase_sector_size);

		write_bl_len = csd[12] & 0x01;
		write_bl_len <<= 8;
		write_bl_len |= csd[13];
		write_bl_len >>= 6;
		debug("write_bl_len = %u\n", write_bl_len);

		erase_sector_size += 1;
		erase_sector_size <<= write_bl_len;
		debug("size = %u\n", erase_sector_size);
		*size = erase_sector_size;
		break;
#endif
	case 1:
		debug("CSD v2.0\n");
		if (csd[10] & 0x40) {
			debug("erase_blk_en = 1\n");
			*size = 512;
			break;
		}
		/* fall through */
	default:
		ret = 0xc0;
	}
	return ret;
}

uint8_t
sd_readblock(uint32_t lba, uint8_t buf[512])
{
	debug("sd_readblock(%lu, buf):\n", lba);

	if (!block_addressing)
		lba <<= 9;

	return sd_read(17, lba, buf, 512);
}

uint8_t
sd_writeblock(uint32_t lba, const uint8_t buf[512])
{
	unsigned int i;
	uint8_t ret;

	debug("sd_writeblock(%lu, buf):\n", lba);

	if (!block_addressing)
		lba <<= 9;

	sd__select();
	ret = sd__cmd(24, lba, NULL, 0);
	if (ret != 0x00) {
		debug("CMD24: %02x\n", ret);
		goto out;
	}

	sd__putbyte(0xff);
	sd__putbyte(0xfe);
#if SD_CRC
	unsigned int crc = 0;
	for (i = 0; i < 512; i++) {
		uint8_t b = buf[i];

		sd__putbyte(b);
		crc = sd_crc16(crc, b);
	}
	sd__putbyte(crc >> 8);
	sd__putbyte(crc);
#else
	for (i = 0; i < 512; i++)
		sd__putbyte(buf[i]);
	sd__putbyte(0xff);
	sd__putbyte(0xff);
#endif
	sd__flush();
	ret = sd__getbyte();
	ret |= 0xe0;
	if (ret != 0xe5) {
		debug("data response: %02x\n", ret);
		goto out;
	}
	do {
		ret = sd__getbyte();
	} while (ret != 0xff);
	ret = 0x00;
out:
	sd__deselect();
	return ret;
}
