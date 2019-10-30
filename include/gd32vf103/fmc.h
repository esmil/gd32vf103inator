/*
 * Copyright (c) 2019, GigaDevice Semiconductor Inc.
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
#ifndef GD32VF103_FMC_H
#define GD32VF103_FMC_H

#include "gd32vf103.h"

#define OB_BASE  _AC(0x1FFFF800,UL)  /*!< OB base address  */
#define FMC_BASE _AC(0x40022000,UL)  /*!< FMC base address */

/* register definitions */
#define FMC_WS      _AC(0x000,UL)  /*!< FMC wait state register */
#define FMC_KEY     _AC(0x004,UL)  /*!< FMC unlock key register 0 */
#define FMC_OBKEY   _AC(0x008,UL)  /*!< FMC option bytes unlock key register */
#define FMC_STAT    _AC(0x00C,UL)  /*!< FMC status register 0 */
#define FMC_CTL     _AC(0x010,UL)  /*!< FMC control register 0 */
#define FMC_ADDR    _AC(0x014,UL)  /*!< FMC address register 0 */
#define FMC_OBSTAT  _AC(0x01C,UL)  /*!< FMC option bytes status register */
#define FMC_WP      _AC(0x020,UL)  /*!< FMC erase/program protection register */
/* Where is this register? It is mentioned, but not defined in the user manual
#define FMC_WSEN    _AC(0x024,UL)  !< FMC wait state enable register
*/
#define FMC_PID     _AC(0x100,UL)  /*!< FMC product ID register */

#define OB_SPC      _AC(0x000,UL)  /*!< option byte security protection value */
#define OB_USER     _AC(0x002,UL)  /*!< option byte user value*/
#define OB_WP0      _AC(0x008,UL)  /*!< option byte write protection 0 */
#define OB_WP1      _AC(0x00A,UL)  /*!< option byte write protection 1 */
#define OB_WP2      _AC(0x00C,UL)  /*!< option byte write protection 2 */
#define OB_WP3      _AC(0x00E,UL)  /*!< option byte write protection 3 */

/* FMC_WS */
#define FMC_WS_WSCNT_Pos     0
#define FMC_WS_WSCNT_Msk     _AC(0x00000007,U)  /*!< wait state counter */
#define FMC_WS_WSCNT(x)      ((x) << FMC_WS_WSCNT_Pos)
#define FMC_WS_WSCNT_0       FMC_WS_WSCNT(0)    /*!< FMC 0 wait */
#define FMC_WS_WSCNT_1       FMC_WS_WSCNT(1)    /*!< FMC 1 wait */
#define FMC_WS_WSCNT_2       FMC_WS_WSCNT(2)    /*!< FMC 2 wait */

/* FMC_KEY */
#define FMC_KEY_UNLOCK0      _AC(0x45670123,U)  /*!< fmc unlock key 0 */
#define FMC_KEY_UNLOCK1      _AC(0xCDEF89AB,U)  /*!< fmc unlock key 1 */

/* FMC_OBKEY */
#define FMC_OBKEY_UNLOCK0    _AC(0x45670123,U)  /*!< option bytes unlock key 0 */
#define FMC_OBKEY_UNLOCK1    _AC(0xCDEF89AB,U)  /*!< option bytes unlock key 1 */

/* FMC_STAT */
#define FMC_STAT_ENDF        _BIT(5,U)          /*!< end of operation flag bit */
#define FMC_STAT_WPERR       _BIT(4,U)          /*!< erase/program protection error flag bit */
#define FMC_STAT_PGERR       _BIT(2,U)          /*!< flash program error flag bit */
#define FMC_STAT_BUSY        _BIT(0,U)          /*!< flash busy flag bit */

/* FMC_CTL */
#define FMC_CTL_ENDIE        _BIT(12,U)         /*!< end of operation interrupt enable bit */
#define FMC_CTL_ERRIE        _BIT(10,U)         /*!< error interrupt enable bit */
#define FMC_CTL_OBWEN        _BIT(9,U)          /*!< option bytes erase/program enable bit */
#define FMC_CTL_LK           _BIT(7,U)          /*!< FMC_CTL lock bit */
#define FMC_CTL_START        _BIT(6,U)          /*!< send erase command to FMC bit */
#define FMC_CTL_OBER         _BIT(5,U)          /*!< option bytes erase command bit */
#define FMC_CTL_OBPG         _BIT(4,U)          /*!< option bytes program command bit */
#define FMC_CTL_MER          _BIT(2,U)          /*!< main flash mass erase for bank0 command bit */
#define FMC_CTL_PER          _BIT(1,U)          /*!< main flash page erase for bank0 command bit */
#define FMC_CTL_PG           _BIT(0,U)          /*!< main flash program for bank0 command bit */

/* FMC_OBSTAT */
#define FMC_OBSTAT_DATA_Pos  10
#define FMC_OBSTAT_DATA_Msk  _AC(0x03fffc00,U)  /*!< store DATA of option bytes block after system reset. */
#define FMC_OBSTAT_DATA(x)   ((x) << FMC_OBSTAT_DATA_Pos)
#define FMC_OBSTAT_USER_Pos  2
#define FMC_OBSTAT_USER_Msk  _AC(0x000003fc,U)  /*!< store USER of option bytes block after system reset */
#define FMC_OBSTAT_USER(x)   ((x) << FMC_OBSTAT_USER_Pos)
#define FMC_OBSTAT_SPC       _BIT(1,U)          /*!< option bytes security protection code */
#define FMC_OBSTAT_OBERR     _BIT(0,U)          /*!< option bytes read error bit. */

/* FMC_WSEN */
#define FMC_WSEN_WSEN        _BIT(0,U)          /*!< FMC wait state enable bit */

/* OB_SPC */
#define OB_SPC_OFF           0xA5               /*!< no security protection */

/* OB_USER */
#define OB_USER_BB           0x08               /*!< boot from bank1 */
#define OB_USER_RST_STDBY    0x04               /*!< generate a reset instead of entering standby mode */
#define OB_USER_RST_DPSLP    0x02               /*!< generate a reset instead of entering deepsleep mode */
#define OB_USER_WDG_HW       0x01               /*!< hardware free watchdog */

#ifndef __ASSEMBLER__
#include <stdint.h>

struct gd32vf103_fmc {
	volatile uint32_t WS;
	volatile uint32_t KEY;
	volatile uint32_t OBKEY;
	volatile uint32_t STAT;
	volatile uint32_t CTL;
	volatile uint32_t ADDR;
	const uint32_t OBSTAT;
	const uint32_t WP;
/* Where is this register? It is mentioned, but not defined in the user manual
#define FMC_WSEN    _AC(0x024,UL)  !< FMC wait state enable register
*/
	uint32_t reserved[56];
	const uint32_t PID;
};

struct gd32vf103_ob {
	volatile uint16_t SPC;
	volatile uint16_t USER;
	union {
		volatile uint32_t DATA;
		struct {
			volatile uint16_t DATA_LO;
			volatile uint16_t DATA_HI;
		};
	};
	volatile uint16_t WP0;
	volatile uint16_t WP1;
	volatile uint16_t WP2;
	volatile uint16_t WP3;
};

static struct gd32vf103_fmc *const FMC = (struct gd32vf103_fmc *)FMC_BASE;
static struct gd32vf103_ob *const OB = (struct gd32vf103_ob *)OB_BASE;

#endif
#endif
