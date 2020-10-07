/*-----------------------------------------------------------------------*/
/* Low level disk I/O module for FatFs     (C)ChaN, 2019                 */
/* Copyright 2020 Emil Renner Berthing                                   */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"     /* Obtains integer types */
#include "diskio.h" /* Declarations of disk functions */

#include "sdcard.h"

#if 0
#include <stdio.h>
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

static DSTATUS status = STA_NOINIT;

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/
DSTATUS disk_status(BYTE pdrv)
{
	uint8_t stat;
	uint8_t ret;

	debug("disk_status(%u):\n", pdrv);

	if (pdrv != 0)
		return STA_NOINIT | STA_NODISK;

	if (status & STA_NOINIT)
		return status;

	ret = sd_status(&stat);
	debug("  sd_status() = %02x (%02x)\n", ret, stat);
	if (ret == 0xFF)
		status = STA_NOINIT | STA_NODISK;
	else if (ret != 0x00 || stat != 0x00)
		status = STA_NOINIT;

	return status;
}

/*-----------------------------------------------------------------------*/
/* Initialize a Drive                                                    */
/*-----------------------------------------------------------------------*/
DSTATUS disk_initialize(BYTE pdrv)
{
	uint8_t ret;

	debug("disk_initialize(%u):\n", pdrv);

	if (pdrv != 0)
		return STA_NOINIT | STA_NODISK;

	ret = sd_wakeup();
	debug("  sd_wakeup() = %x\n", ret);
	if (ret == 0x00)
		status = 0;

	return status;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/
DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)
{
	uint8_t ret;

	debug("disk_read(%u, buff, %lu, %u):\n",
			pdrv, sector, count);

	if (pdrv != 0)
		return RES_PARERR;
	if (status & STA_NOINIT)
		return RES_NOTRDY;

	for (; count > 0; count--) {
		ret = sd_readblock(sector, buff);
		debug("  sd_readblock(%lu, buff) = %u\n",
				sector, ret);
		if (ret != 0x00) {
			break;
		}
		sector += 1;
		buff += 512;
	}

	return (ret == 0x00) ? RES_OK : RES_ERROR;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/
#if FF_FS_READONLY == 0
DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)
{
	uint8_t ret;

	debug("disk_write(%u, buff, %lu, %u):\n",
			pdrv, sector, count);

	if (pdrv != 0)
		return RES_PARERR;
	if (status & STA_NOINIT)
		return RES_NOTRDY;

	for (; count > 0; count--) {
		ret = sd_writeblock(sector, buff);
		debug("  sd_writeblock(%lu, buff) = %u\n",
				sector, ret);
		if (ret != 0x00) {
			break;
		}
		sector += 1;
		buff += 512;
	}

	return (ret == 0x00) ? RES_OK : RES_ERROR;
}
#endif

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/
#if FF_FS_READONLY == 0 || FF_MIN_SS != FF_MAX_SS
static DRESULT translate(uint8_t ret)
{
	DRESULT res;

	switch (ret) {
		case 0x00: res = RES_OK;     break;
		case 0xFF: res = RES_NOTRDY; break;
		default:   res = RES_ERROR;  break;
	}
	return res;
}

DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
	DRESULT res = RES_PARERR;

	if (pdrv != 0)
		return res;

	switch (cmd) {
	/* Generic command (Used by FatFs) */
#if FF_FS_READONLY == 0
	case CTRL_SYNC: /* Complete pending write process */
		res = RES_OK;
		break;
#endif
#if FF_USE_MKFS == 1
	case GET_SECTOR_COUNT: { /* Get media size */
		LBA_t *count = buff;
		res = translate(sd_getblocks(count));
		break;
	}
#endif
#if FF_MIN_SS != FF_MAX_SS
	case GET_SECTOR_SIZE: { /* Get sector size */
		WORD *size = buff;
		*size = 512;
		res = RES_OK;
		break;
	}
#endif
#if FF_USE_MKFS == 1
	case GET_BLOCK_SIZE: { /* Get erase block size */
		DWORD *size = buff;
		res = translate(sd_geterasesectorsize(size));
		break;
	}
#endif
#if FF_USE_TRIM == 1
	case CTRL_TRIM: /* Inform device that the data on the block of sectors is no longer used */
		res = RES_OK;
		break;
#endif
#if 0
	case MMC_GET_CSD:
		res = translate(sd_getcsd(buff));
		break;
	case MMC_GET_CID:
		res = translate(sd_getcid(buff));
		break;
	case MMC_GET_OCR:
		res = translate(sd_getocr(buff));
		break;
#endif
	}

	return res;
}
#endif
