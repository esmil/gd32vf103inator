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
#include "riscv/bits.h"
#include "gd32vf103/csr.h"
#include "gd32vf103/rcu.h"

/* define sizes for the linkerscript */
.global __bootloader
__bootloader = BOOTLOADER
.global __flash_size
__flash_size = FLASH_SIZE
.global __ram_size
__ram_size = RAM_SIZE

.macro interrupt name
	.word \name\()_IRQHandler
	.weak \name\()_IRQHandler
	.set \name\()_IRQHandler, default_handler
.endm

.section .vectors, "a", %progbits
.global vector_base
.type vector_base, %object
/* this chip has 87 interrupts and hence need 512-byte alignment
 * for the vector table */
.align 9
vector_base:
	/* save some power by disabling these counters */
	csrs	CSR_MCOUNTINHIBIT, CSR_MCOUNTINHIBIT_IR | CSR_MCOUNTINHIBIT_CY
	/* the gd32vf103 has its flash at 0x08000000, but also mapped to 0,
	 * but if the pc is in a different range from where the code is linked
	 * things break, so jump to the absolute address of _start */
	lui	a0, %hi(_start)
	jalr	zero, a0, %lo(_start)
	/* make sure we use exactly 3 words of space for the above instructions
	 * so that the software interrupt handler is the 4th entry in the table */
	. = vector_base + 12

	interrupt MSOFTWARE
	.word	0
	.word	0
	.word	0
	interrupt MTIMER
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	interrupt MEMACCESS
	interrupt PMON
	interrupt WWDGT
	interrupt LVD
	interrupt TAMPER
	interrupt RTC
	interrupt FMC
	interrupt RCU
	interrupt EXTI0
	interrupt EXTI1
	interrupt EXTI2
	interrupt EXTI3
	interrupt EXTI4
	interrupt DMA0_Channel0
	interrupt DMA0_Channel1
	interrupt DMA0_Channel2
	interrupt DMA0_Channel3
	interrupt DMA0_Channel4
	interrupt DMA0_Channel5
	interrupt DMA0_Channel6
	interrupt ADC0_1
	interrupt CAN0_TX
	interrupt CAN0_RX0
	interrupt CAN0_RX1
	interrupt CAN0_EWMC
	interrupt EXTI5_9
	interrupt TIMER0_BRK
	interrupt TIMER0_UP
	interrupt TIMER0_TRG_CMT
	interrupt TIMER0_Channel
	interrupt TIMER1
	interrupt TIMER2
	interrupt TIMER3
	interrupt I2C0_EV
	interrupt I2C0_ER
	interrupt I2C1_EV
	interrupt I2C1_ER
	interrupt SPI0
	interrupt SPI1
	interrupt USART0
	interrupt USART1
	interrupt USART2
	interrupt EXTI10_15
	interrupt RTC_Alarm
	interrupt USBFS_WKUP
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	interrupt EXMC
	.word	0
	interrupt TIMER4
	interrupt SPI2
	interrupt UART3
	interrupt UART4
	interrupt TIMER5
	interrupt TIMER6
	interrupt DMA1_Channel0
	interrupt DMA1_Channel1
	interrupt DMA1_Channel2
	interrupt DMA1_Channel3
	interrupt DMA1_Channel4
	.word	0
	.word	0
	interrupt CAN1_TX
	interrupt CAN1_RX0
	interrupt CAN1_RX1
	interrupt CAN1_EWMC
	interrupt USBFS
.size vector_base, . - vector_base

.section .text.init.irq
.global irq_entry
.weak irq_entry
.type irq_entry, %function
.func irq_entry
.align 2
irq_entry:
	addi	sp, sp, -20*REGBYTES
	STORE	ra, 0*REGBYTES(sp)
	STORE	tp, 1*REGBYTES(sp)
	STORE	t0, 2*REGBYTES(sp)
	STORE	t1, 3*REGBYTES(sp)
	STORE	t2, 4*REGBYTES(sp)
	STORE	a0, 5*REGBYTES(sp)
	STORE	a1, 6*REGBYTES(sp)
	STORE	a2, 7*REGBYTES(sp)
	STORE	a3, 8*REGBYTES(sp)
	STORE	a4, 9*REGBYTES(sp)
	STORE	a5, 10*REGBYTES(sp)
	STORE	a6, 11*REGBYTES(sp)
	STORE	a7, 12*REGBYTES(sp)
	STORE	t3, 13*REGBYTES(sp)
	STORE	t4, 14*REGBYTES(sp)
	STORE	t5, 15*REGBYTES(sp)
	STORE	t6, 16*REGBYTES(sp)

	/* use special CSR to push mcause to the stack */
	csrwi	CSR_PUSHMCAUSE, 17
	/* use special CSR to push mepc to the stack */
	csrwi	CSR_PUSHMEPC, 18
	/* use special CSR to push msubm to the stack */
	csrwi	CSR_PUSHMSUBM, 19

	/* use special CSR to repeatedly jump to handlers in
	 * the vector table until there are no more pending requests.
	 * this also enable the global interrupt flag, so higher level
	 * interrupts can preempt us */
	csrrw	ra, CSR_JALMNXTI, ra

	/* disable interrupts before restoring CSRs */
	csrc	CSR_MSTATUS, CSR_MSTATUS_MIE

	LOAD	t0, 19*REGBYTES(sp)
	csrw	CSR_MSUBM, t0
	LOAD	t0, 18*REGBYTES(sp)
	csrw	CSR_MEPC, t0
	LOAD	t0, 17*REGBYTES(sp)
	csrw	CSR_MCAUSE, t0

	LOAD	ra, 0*REGBYTES(sp)
	LOAD	tp, 1*REGBYTES(sp)
	LOAD	t0, 2*REGBYTES(sp)
	LOAD	t1, 3*REGBYTES(sp)
	LOAD	t2, 4*REGBYTES(sp)
	LOAD	a0, 5*REGBYTES(sp)
	LOAD	a1, 6*REGBYTES(sp)
	LOAD	a2, 7*REGBYTES(sp)
	LOAD	a3, 8*REGBYTES(sp)
	LOAD	a4, 9*REGBYTES(sp)
	LOAD	a5, 10*REGBYTES(sp)
	LOAD	a6, 11*REGBYTES(sp)
	LOAD	a7, 12*REGBYTES(sp)
	LOAD	t3, 13*REGBYTES(sp)
	LOAD	t4, 14*REGBYTES(sp)
	LOAD	t5, 15*REGBYTES(sp)
	LOAD	t6, 16*REGBYTES(sp)
	addi	sp, sp, 20*REGBYTES
	mret
.size irq_entry, . - irq_entry
.endfunc

.section .text.init.trap
.global trap_entry
.weak trap_entry
.type trap_entry, %function
.func trap_entry
.align 6
trap_entry:
	j	trap_entry
.size trap_entry, . - trap_entry
.endfunc


.macro laa rd, addr
	lui	\rd, %hi(\addr)
	addi	\rd, \rd, %lo(\addr)
.endm

.section .text.init.enter
.global _start
.weak _start
.type _start, %function
.func _start
_start:
.cfi_startproc
.cfi_undefined ra
#ifdef NDEBUG
	/* load reset flags */
	lui	a0, RCU_BASE >> 12
	lw	a1, RCU_RSTSCK(a0)
	/* store reset flags in mcause */
	srli	a1, a1, 26
	csrw	CSR_MCAUSE, a1
	/* clear reset flags and power-on-reset in particular
	 * or we would never enter the bootloader if a broken
	 * program leaves the power-on-reset flag set */
	lui	a2, RCU_RSTSCK_RSTFC >> 12
	sw	a2, RCU_RSTSCK(a0)
	sw	zero, RCU_RSTSCK(a0)
	/* enter bootloader when the external (reset) pin flag is set,
	 * but not when the power-on-reset flag is also set */
	andi	a1, a1, 3
	addi	a1, a1, -1
	beqz	a1, 0f
	/* jump to regular program */
	lui	a0, (FLASH_BASE + 4*1024) >> 12
	jr	a0
0:
#endif
#if BOOTLOADER == 0
	/* the gd32vf103 bootloader in rom exits in the middle of an
	 * interrupt, so reset msubm and mstatus and mret to exit
	 * properly and reset mintstatus */
	li	a0, 3
	slli	a0, a0, 11
	csrw	CSR_MSTATUS, a0
	csrw	CSR_MSUBM, 0
	la	a0, 0f
	csrw	CSR_MEPC, a0
	mret
0:
#endif
.option push
.option norelax
	laa	gp, __global_pointer$
.option pop
	laa	sp, __stack

	/* load data with *a3++ = *a4++ while a3 < a5 */
	la	a4, __data_source
	laa	a3, __data_start
	laa	a5, __data_end
	bgeu	a3, a5, 2f
1:
	lw	a0, 0(a4)
	addi	a4, a4, 4
	sw	a0, 0(a3)
	addi	a3, a3, 4
	bltu	a3, a5, 1b
2:
	/* clear bss with *a3++ = a0 (== 0) while a3 < a5 */
	li	a0, 0
	/* just clear all memory from __data_end up until __bss_end
	laa	a3, __bss_start
	*/
	laa	a5, __bss_end
	/*
	 * if .bss is empty we clear the first word of
	 * whatever follows. that should be the bottom
	 * of stack or start of heap which is fine
	bgeu	a3, a5, 4f
	 */
3:
	sw	a0, 0(a3)
	addi	a3, a3, 4
	bltu	a3, a5, 3b
4:
	call	main
.cfi_endproc
.size _start, . - _start
.endfunc

.global default_handler
.weak default_handler
.type default_handler, %function
.func default_handler
default_handler:
	csrc	CSR_MSTATUS, 0xf
	j	default_handler
.size default_handler, . - default_handler
.endfunc

/* vim: set ft=asm: */
