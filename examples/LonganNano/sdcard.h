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
#ifndef SDCARD_H
#define SDCARD_H

#include <stdint.h>

void sd_init(void);
void sd_uninit(void);

/* return values are overlaid on the R1 response codes:
 * bit 0: idle state, should not be returned by any function below
 * bit 1: erase reset
 * bit 2: illegal command
 * bit 3: communication crc error
 * bit 4: erase sequence error
 * bit 5: address error
 * bit 6: parameter error
 * bit 7: set by library, not by sd card
 * the special value 0xff means no reply, no card or timeout
 */
uint8_t sd_wakeup(void);
uint8_t sd_getocr(uint8_t ocr[4]);
uint8_t sd_status(uint8_t *status);
uint8_t sd_getcsd(uint8_t csd[16]);
uint8_t sd_getcid(uint8_t cid[16]);
uint8_t sd_getblocks(uint32_t *blocks);
uint8_t sd_geterasesectorsize(uint32_t *size);
uint8_t sd_readblock(uint32_t lba, uint8_t buf[512]);
uint8_t sd_writeblock(uint32_t lba, const uint8_t buf[512]);

#endif
