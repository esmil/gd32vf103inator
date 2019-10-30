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
#ifndef RISCV_CSR_H
#define RISCV_CSR_H

#include "const.h"

/* user trap setup */
#define CSR_USTATUS        0x000
#define CSR_UIE            0x004
#define CSR_UTVEC          0x005
/* user trap handling */
#define CSR_USCRATCH       0x040
#define CSR_UEPC           0x041
#define CSR_UCAUSE         0x042
#define CSR_UTVAL          0x043
#define CSR_UIP            0x044
/* user floating-point csrs */
#define CSR_FFLAGS         0x001
#define CSR_FRM            0x002
#define CSR_FCSR           0x003
/* user counter/timers */
#define CSR_CYCLE          0xC00
#define CSR_TIME           0xC01
#define CSR_INSTRET        0xC02
#define CSR_HPMCOUNTER3    0xC03
#define CSR_HPMCOUNTER4    0xC04
#define CSR_HPMCOUNTER31   0xC31
#define CSR_CYCLEH         0xC80
#define CSR_TIMEH          0xC81
#define CSR_INSTRETH       0xC82
#define CSR_HPMCOUNTER3H   0xC83
#define CSR_HPMCOUNTER4H   0xC84
#define CSR_HPMCOUNTER31H  0xCB1

/* supervisor trap setup */
#define CSR_SSTATUS        0x100
#define CSR_SEDELEG        0x102
#define CSR_SIDELEG        0x103
#define CSR_SIE            0x104
#define CSR_STVEC          0x105
#define CSR_SCOUNTEREN     0x106
/* supervisor trap handling */
#define CSR_SSCRATCH       0x140
#define CSR_SEPC           0x141
#define CSR_SCAUSE         0x142
#define CSR_STVAL          0x143
#define CSR_SIP            0x144
/* supervisor protection and translation */
#define CSR_SATP           0x180

/* machine information registers */
#define CSR_MVENDORID      0xF11
#define CSR_MARCHID        0xF12
#define CSR_MIMPID         0xF13
#define CSR_MHARTID        0xF14
/* machine trap setup */
#define CSR_MSTATUS        0x300
#define CSR_MISA           0x301
#define CSR_MEDELEG        0x302
#define CSR_MIDELEG        0x303
#define CSR_MIE            0x304
#define CSR_MTVEC          0x305
#define CSR_MCOUNTEREN     0x306
/* machine trap handling */
#define CSR_MSCRATCH       0x340
#define CSR_MEPC           0x341
#define CSR_MCAUSE         0x342
#define CSR_MTVAL          0x343
#define CSR_MIP            0x344
/* machine memory protection */
#define CSR_PMPCFG0        0x3A0
#define CSR_PMPCFG1        0x3A1
#define CSR_PMPCFG2        0x3A2
#define CSR_PMPCFG3        0x3A3
#define CSR_PMPADDR0       0x3B0
#define CSR_PMPADDR1       0x3B1
#define CSR_PMPADDR2       0x3B2
#define CSR_PMPADDR3       0x3B3
#define CSR_PMPADDR4       0x3B4
#define CSR_PMPADDR5       0x3B5
#define CSR_PMPADDR6       0x3B6
#define CSR_PMPADDR7       0x3B7
#define CSR_PMPADDR8       0x3B8
#define CSR_PMPADDR9       0x3B9
#define CSR_PMPADDR10      0x3BA
#define CSR_PMPADDR11      0x3BB
#define CSR_PMPADDR12      0x3BC
#define CSR_PMPADDR13      0x3BD
#define CSR_PMPADDR14      0x3BE
#define CSR_PMPADDR15      0x3BF
/* machine counter/timers */
#define CSR_MCYCLE         0xB00
#define CSR_MINSTRET       0xB02
#define CSR_MHPMCOUNTER3   0xB03
#define CSR_MHPMCOUNTER4   0xB04
#define CSR_MHPMCOUNTER31  0xB31
#define CSR_MCYCLEH        0xB80
#define CSR_MINSTRETH      0xB82
#define CSR_MHPMCOUNTER3H  0xB83
#define CSR_MHPMCOUNTER4H  0xB84
#define CSR_MHPMCOUNTER31H 0xBB1
/* machine counter setup */
#define CSR_MCOUNTINHIBIT  0x320
#define CSR_MHPMEVENT3     0x323
#define CSR_MHPMEVENT4     0x324
#define CSR_MHPMEVENT31    0x33F

/* debug/trace registers */
#define CSR_TSELECT        0x7A0
#define CSR_TDATA1         0x7A1
#define CSR_TDATA2         0x7A2
#define CSR_TDATA3         0x7A3
/* debug mode registers */
#define CSR_DCSR           0x7B0
#define CSR_DPC            0x7B1
#define CSR_DSCRATCH0      0x7B2
#define CSR_DSCRATCH1      0x7B3


/* mstatus bits */
#define CSR_MSTATUS_UIE          _BIT(0, UL)
#define CSR_MSTATUS_SIE          _BIT(1, UL)
#define CSR_MSTATUS_MIE          _BIT(3, UL)
#define CSR_MSTATUS_UPIE         _BIT(4, UL)
#define CSR_MSTATUS_SPIE         _BIT(5, UL)
#define CSR_MSTATUS_MPIE         _BIT(7, UL)
#define CSR_MSTATUS_SPP          _BIT(8, UL)
#define CSR_MSTATUS_MPP_Pos      11
#define CSR_MSTATUS_MPP_Msk      _AC(0x00001800, UL)
#define CSR_MSTATUS_MPP(x)       ((x) << CSR_MSTATUS_MPP_Pos)
#define CSR_MSTATUS_FS_Pos       13
#define CSR_MSTATUS_FS_Msk       _AC(0x00006000, UL)
#define CSR_MSTATUS_FS(x)        ((x) << CSR_MSTATUS_FS_Pos)
#define CSR_MSTATUS_XS_Pos       15
#define CSR_MSTATUS_XS_Msk       _AC(0x00018000, UL)
#define CSR_MSTATUS_XS(x)        ((x) << CSR_MSTATUS_XS_Pos)
#define CSR_MSTATUS_MPRV         _BIT(17, UL)
#define CSR_MSTATUS_SUM          _BIT(18, UL)
#define CSR_MSTATUS_MXR          _BIT(19, UL)
#define CSR_MSTATUS_TVM          _BIT(20, UL)
#define CSR_MSTATUS_TW           _BIT(21, UL)
#define CSR_MSTATUS_TSR          _BIT(22, UL)
#if __riscv_xlen == 64
#define CSR_MSTATUS_UXL_Pos      32
#define CSR_MSTATUS_UXL_Msk      _AC(0x300000000,UL)
#define CSR_MSTATUS_UXL(X)       ((x) << CSR_MSTATUS_UXL_Pos)
#define CSR_MSTATUS_SXL_Pos      34
#define CSR_MSTATUS_SXL_Msk      _AC(0xc00000000,UL)
#define CSR_MSTATUS_SXL(X)       ((x) << CSR_MSTATUS_SXL_Pos)
#define CSR_MSTATUS_SD           _BIT(63,UL)
#elif __riscv_xlen == 32
#define CSR_MSTATUS_SD           _BIT(31,UL)
#else
#error "Unsupported __riscv_xlen"
#endif

/* mie bits */
#define CSR_MIE_USIE             _BIT(0,UL)
#define CSR_MIE_SSIE             _BIT(1,UL)
#define CSR_MIE_MSIE             _BIT(3,UL)
#define CSR_MIE_UTIE             _BIT(4,UL)
#define CSR_MIE_STIE             _BIT(5,UL)
#define CSR_MIE_MTIE             _BIT(7,UL)
#define CSR_MIE_UEIE             _BIT(8,UL)
#define CSR_MIE_SEIE             _BIT(9,UL)
#define CSR_MIE_MEIE             _BIT(11,UL)

/* mcause bits */
#define CSR_MCAUSE_INTERRUPT     _BIT(__riscv_xlen - 1,UL)

/* mip bits */
#define CSR_MIP_USIP             _BIT(0,UL)
#define CSR_MIP_SSIP             _BIT(1,UL)
#define CSR_MIP_MSIP             _BIT(3,UL)
#define CSR_MIP_UTIP             _BIT(4,UL)
#define CSR_MIP_STIP             _BIT(5,UL)
#define CSR_MIP_MTIP             _BIT(7,UL)
#define CSR_MIP_UEIP             _BIT(8,UL)
#define CSR_MIP_SEIP             _BIT(9,UL)
#define CSR_MIP_MEIP             _BIT(11,UL)

/* mcounteren bits */
#define CSR_MCOUNTEREN_CY        _BIT(0,UL)
#define CSR_MCOUNTEREN_TM        _BIT(1,UL)
#define CSR_MCOUNTEREN_IR        _BIT(2,UL)
#define CSR_MCOUNTEREN_HPM(x)    _BIT(x,UL)

/* mcountinhibit bits */
#define CSR_MCOUNTINHIBIT_CY     _BIT(0,UL)
#define CSR_MCOUNTINHIBIT_IR     _BIT(2,UL)
#define CSR_MCOUNTINHIBIT_HPM(x) _BIT(x,UL)

#ifndef __ASSEMBLER__
static inline unsigned long
csr_swap(unsigned int csr, unsigned long val)
{
	unsigned long ret;
	__asm__ ("csrrw  %0, %1, %2" : "=r"(ret) : "n"(csr), "rK"(val) : "memory");
	return ret;
}

static inline unsigned long
csr_read(unsigned int csr)
{
	unsigned long ret;
	__asm__ ("csrr %0, %1" : "=r"(ret) : "n"(csr) : "memory");
	return ret;
}

static inline void
csr_write(unsigned int csr, unsigned long val)
{
	__asm__ ("csrw  %0, %1" :: "n"(csr), "rK"(val) : "memory");
}

static inline void
csr_set(unsigned int csr, unsigned long val)
{
	__asm__ ("csrs  %0, %1" :: "n"(csr), "rK"(val) : "memory");
}

static inline void
csr_clear(unsigned int csr, unsigned long val)
{
	__asm__ ("csrc  %0, %1" :: "n"(csr), "rK"(val) : "memory");
}
#endif

#endif
