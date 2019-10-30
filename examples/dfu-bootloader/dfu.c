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
#include <stddef.h>

#include "gd32vf103/info.h"

#include "dfu.h"
#include "flash.h"

#ifdef NDEBUG
#define debug(...)
#else
#include <stdio.h>
#define debug(...) printf(__VA_ARGS__)
#endif

enum dfu_status {
	DFU_OK,
	DFU_errTARGET,
	DFU_errFILE,
	DFU_errWRITE,
	DFU_errERASE,
	DFU_errCHECK_ERASED,
	DFU_errPROG,
	DFU_errVERIFY,
	DFU_errADDRESS,
	DFU_errNOTDONE,
	DFU_errFIRMWARE,
	DFU_errVENDOR,
	DFU_errUSBR,
	DFU_errPOR,
	DFU_errUNKNOWN,
	DFU_errSTALLEDPKT,
};

enum dfu_state {
	DFU_appIDLE,
	DFU_appDETACH,
	DFU_dfuIDLE,
	DFU_dfuDNLOAD_SYNC,
	DFU_dfuDNBUSY,
	DFU_dfuDNLOAD_IDLE,
	DFU_dfuMANIFEST_SYNC,
	DFU_dfuMANIFEST,
	DFU_dfuMANIFEST_WAIT_RESET,
	DFU_dfuUPLOAD_IDLE,
	DFU_dfuERROR,
};

static struct {
	uint8_t bStatus;
	uint8_t bwPollTimeout[3];
	uint8_t bState;
	uint8_t iString;
} dfu_status;

int
dfu_detach(const struct usb_setup_packet *p, const void **data)
{
	debug("DFU_DETACH\n");

	usbfs_reboot_on_ack = true;

	return 0;
}

int
dfu_dnload(const struct usb_setup_packet *p, const void **data)
{
	static uint32_t addr;
	static union {
		uint8_t bytes[PAGE_SIZE];
		uint32_t words[PAGE_SIZE/4];
	} buf;
	static uint8_t *bp;
	const uint8_t *sp;

	debug("DFU_DNLOAD: wValue = %hu, wLength = %hu\n",
			p->wValue, p->wLength);

	switch (dfu_status.bState) {
	case DFU_dfuIDLE:
#ifdef NDEBUG
		addr = FLASH_BASE + 4*PAGE_SIZE;
#else
		addr = FLASH_BASE + 32*PAGE_SIZE;
#endif
		bp = &buf.bytes[0];
		break;
	case DFU_dfuDNLOAD_IDLE:
		break;
	default:
		return -1;
	}

	if (p->wLength == 0) {
		if (bp != &buf.bytes[0]) {
			while (bp < ARRAY_END(buf.bytes))
				*bp++ = 0xFFU;
			if (addr >= FLASH_BASE + INFO->FLASH * PAGE_SIZE)
				goto err_addr;
			if (flash_page(addr, buf.words))
				goto err_write;
		}
		dfu_status.bState = DFU_dfuMANIFEST_SYNC;
		return 0;
	}

	sp = *data;
	for (unsigned int len = p->wLength; len > 0; len--) {
		*bp++ = *sp++;
		if (bp < ARRAY_END(buf.bytes))
			continue;

		if (addr >= FLASH_BASE + INFO->FLASH * PAGE_SIZE)
			goto err_addr;
		if (flash_page(addr, buf.words))
			goto err_write;

		addr += ARRAY_SIZE(buf.bytes);
		bp = &buf.bytes[0];
	}

	dfu_status.bState = DFU_dfuDNLOAD_SYNC;
	return 0;
err_addr:
	dfu_status.bStatus = DFU_errADDRESS;
	dfu_status.bState = DFU_dfuERROR;
	return 0;
err_write:
	dfu_status.bStatus = DFU_errWRITE;
	dfu_status.bState = DFU_dfuERROR;
	return 0;
}

int
dfu_upload(const struct usb_setup_packet *p, const void **data)
{
	static uint32_t offset;
	int ret;

	debug("DFU_UPLOAD: wValue = %hu, wIndex = %hu, wLength = %hu\n",
			p->wValue, p->wIndex, p->wLength);

	switch (dfu_status.bState) {
	case DFU_dfuIDLE:
#ifdef NDEBUG
		offset = 4*PAGE_SIZE;
#else
		offset = 32*PAGE_SIZE;
#endif
		break;
	case DFU_dfuUPLOAD_IDLE:
		break;
	default:
		return -1;
	}

	if (offset + p->wLength > INFO->FLASH * PAGE_SIZE) {
		dfu_status.bState = DFU_dfuIDLE;
		ret = INFO->FLASH * PAGE_SIZE - offset;
	} else {
		dfu_status.bState = DFU_dfuUPLOAD_IDLE;
		ret = p->wLength;
	}
	*data = (const void *)(FLASH_BASE + offset);
	offset += ret;
	debug("  returning %d\n", ret);
	return ret;
}

int
dfu_getstatus(const struct usb_setup_packet *p, const void **data)
{
	debug("DFU_GETSTATUS\n");

	switch (dfu_status.bState) {
	case DFU_dfuDNLOAD_SYNC:
		dfu_status.bState = DFU_dfuDNLOAD_IDLE;
		break;
	case DFU_dfuMANIFEST_SYNC:
		dfu_status.bState = DFU_dfuIDLE;
		break;
	}

	*data = &dfu_status;
	return sizeof(dfu_status);
}

int
dfu_clrstatus(const struct usb_setup_packet *p, const void **data)
{
	debug("DFU_CLRSTATUS\n");

	if (dfu_status.bState != DFU_dfuERROR)
		return -1;

	dfu_status.bStatus = DFU_OK;
	dfu_status.bState = DFU_dfuIDLE;
	return 0;
}

int
dfu_getstate(const struct usb_setup_packet *p, const void **data)
{
	debug("DFU_GETSTATE\n");

	*data = &dfu_status.bState;
	return 1;
}

int
dfu_abort(const struct usb_setup_packet *p, const void **data)
{
	debug("DFU_ABORT\n");

	switch (dfu_status.bState) {
	case DFU_dfuIDLE:
	case DFU_dfuDNLOAD_IDLE:
	case DFU_dfuUPLOAD_IDLE:
		dfu_status.bStatus = DFU_OK;
		dfu_status.bState = DFU_dfuIDLE;
		return 0;
	}

	return -1;
}

void
dfu_init(void)
{
	dfu_status.bState = DFU_dfuIDLE;
}
