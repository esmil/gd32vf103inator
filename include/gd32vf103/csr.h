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
#ifndef GD32VF103_CSR_H
#define GD32VF103_CSR_H

#include "riscv/const.h"
#include "riscv/csr.h"

/* custom CSRs */
#define CSR_MTVT         0x307
#define CSR_MNXTI        0x345
#define CSR_MINTSTATUS   0x346
#define CSR_MSCRATCHCSW  0x348
#define CSR_MSCRATCHCSWL 0x349
#define CSR_MNVEC        0x7C3
#define CSR_MSUBM        0x7C4
#define CSR_MMISC_CTL    0x7D0
#define CSR_MSAVESTATUS  0x7D6
#define CSR_MSAVEPC1     0x7D7
#define CSR_MSAVECAUSE1  0x7D8
#define CSR_MSAVEPC2     0x7D9
#define CSR_MSAVECAUSE2  0x7DA
#define CSR_PUSHMSUBM    0x7EB
#define CSR_MTVT2        0x7EC
#define CSR_JALMNXTI     0x7ED
#define CSR_PUSHMCAUSE   0x7EE
#define CSR_PUSHMEPC     0x7EF
#define CSR_WFE          0x810
#define CSR_SLEEPVALUE   0x811
#define CSR_TXEVT        0x812

/* custom mtvec bits */
#define CSR_MTVEC_MODE_Pos           0
#define CSR_MTVEC_MODE_Msk           _AC(0x0000003f,UL)
#define CSR_MTVEC_MODE_ECLIC         _AC(0x00000003,UL)

/* custom mcause bits */
#define CSR_MCAUSE_MINHV             _BIT(30,UL)
#define CSR_MCAUSE_MPP_Pos           28
#define CSR_MCAUSE_MPP_Msk           _AC(0x30000000,UL)
#define CSR_MCAUSE_MPP(x)            ((x) << CSR_MCAUSE_MPP_Pos)
#define CSR_MCOUSE_MPIE              _BIT(27,UL)
#define CSR_MCAUSE_MPIL_Pos          16
#define CSR_MCAUSE_MPIL_Msk          _AC(0x00ff0000,UL)
#define CSR_MCAUSE_MPIL(x)           ((x) << CSR_MCAUSE_MPIL_Pos)
#define CSR_MCAUSE_EXCCODE_Pos       0
#define CSR_MCAUSE_EXCCODE_Msk       _AC(0x00000fff,UL)
#define CSR_MCAUSE_EXCCODE(x)        ((x) << CSR_MCAUSE_EXCCODE_Pos)

/* mintstatus bits */
#define CSR_MINTSTATUS_MIL_Pos       24
#define CSR_MINTSTATUS_MIL_Msk       _AC(0xff000000,UL)
#define CSR_MINTSTATUS_MIL(x)        ((x) << CSR_MINTSTATUS_MIL_Pos)
#define CSR_MINTSTATUS_UIL_Pos       0
#define CSR_MINTSTATUS_UIL_Msk       _AC(0x000000ff,UL)
#define CSR_MINTSTATUS_UIL(x)        ((x) << CSR_MINTSTATUS_UIL_Pos)

/* mmisc_ctl bits */
#define CSR_MMISC_CTL_NMI_CAUSE_FFF _BIT(9,UL)

/* mtvt2 bits */
#define CSR_MTVT2_MTVT2EN           _BIT(0,UL)

/* wfe bits */
#define CSR_WFE_WFE                 _BIT(0,UL)

/* sleepvalue bits */
#define CSR_SLEEPVALUE_SLEEPVALUE   _BIT(0,UL)

/* txevt bits */
#define CSR_TXEVT_TXEVT             _BIT(0,UL)

#endif
