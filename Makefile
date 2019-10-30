# Copyright (c) 2019, Emil Renner Berthing
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its contributors
#    may be used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
# OF SUCH DAMAGE.

MAKEFLAGS    += rR
TARGET       ?= code

# override these settings for your board/chip
HXTAL        ?= 8000000
FLASH_SIZE   ?= 128*1024
RAM_SIZE     ?= 32*1024
# override these settings to your liking
CORECLOCK    ?= 96000000
BOOTLOADER   ?= 4*1024

O          = build
HERE      := $(dir $(lastword $(MAKEFILE_LIST)))
OS        := $(if $(ComSpec),Windows,$(shell uname -s))

ARCH       = rv32imac
ABI        = ilp32
CODEMODEL  = medlow

OPT       = -Os -flto
ARCHFLAGS = -march=$(ARCH) -mabi=$(ABI) -mcmodel=$(CODEMODEL) -fno-pie
DEPENDS   = -MMD -MP
WARNINGS  = -Wall -Wextra -Wshadow -Wpointer-arith -Wformat=2 -Wformat-truncation=2 -Wundef -Wno-unused-parameter
CFLAGS    = $(OPT) $(ARCHFLAGS) -ggdb -pipe $(DEPENDS) $(WARNINGS)
CFLAGS   += -fno-common -ffunction-sections -fdata-sections
ASFLAGS   = $(OPT) $(ARCHFLAGS) -ggdb -pipe $(DEPENDS) $(WARNINGS)
CPPFLAGS  = $(if $(HXTAL),-DHXTAL=$(HXTAL) ,)-DCORECLOCK=$(CORECLOCK)
CPPFLAGS += -DBOOTLOADER=$(BOOTLOADER) -DFLASH_SIZE=$(FLASH_SIZE) -DRAM_SIZE=$(RAM_SIZE)
LDFLAGS   = $(OPT) $(ARCHFLAGS) -static -Wl,-O1,--gc-sections,--relax,--build-id=none
LDSCRIPT  = $(HERE)gd32vf103.ld

libs = eclic rcu gpio

vpath %.S $(HERE)
vpath %.c $(HERE)

ifeq ($(SPECS),)
CFLAGS   += -ffreestanding -ftls-model=local-exec
CPPFLAGS += -I$(HERE)std -D_LIBC_LIMITS_H_
LDFLAGS  += -nostdlib
LIBS     += -lgcc
libs     += xprintf
else ifeq ($(SPECS),picolibc)
else
LDFLAGS  += -nostartfiles
endif

CPPFLAGS += -I$(HERE)include

CROSS_COMPILE = riscv64-unknown-elf-
CC      = $(CROSS_COMPILE)gcc $(if $(SPECS),-specs=$(SPECS).specs ,)-std=gnu11
AS      = $(CROSS_COMPILE)gcc $(if $(SPECS),-specs=$(SPECS).specs ,)-x assembler-with-cpp
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
HEX     = $(OBJCOPY) -O ihex
BIN     = $(OBJCOPY) -O binary -S

ifdef ComSpec
MKDIR_P    = mkdir
RM_RF      = rmdir /q /s
echo       = @echo $1
size       = cmd /c 'for %I in ($1) do @echo.  %~zI bytes'
else
MKDIR_P    = mkdir -p
RM_RF      = rm -rf
echo       = @echo '$1'
ifeq ($(filter-out Linux MSYS%,$(OS)),)
size       = stat --printf '  %s bytes\n' $1
else
size       = stat -f '  %z bytes' $1
endif
endif

OPENOCD    = openocd
STM32FLASH = stm32flash
STTY       = stty
CAT        = cat
SERIAL     = /dev/ttyUSB0

DFU_UTIL   = dfu-util
DFU_DEVICE = 1d50:613e

c-objs   := $(patsubst %.S,%.o,$(filter-out start.S,$(wildcard *.S)))
asm-objs := $(patsubst %.c,%.o,$(filter-out start.c,$(wildcard *.c)))

objs = start.o
objs += $(patsubst %,lib-%.o,$(sort $(libs)))
objs += $(asm-objs) $(c-objs)

objects = $(addprefix $O/,$(objs))$(if $(SPECS),, $O/lib-string.o)

ifdef V
echo := @:
endif
Q := $(if $V,,@)

.SECONDEXPANSION:
.PHONY: all release clean dump dfu romdfu uart cat

all: $O/$$(TARGET).bin

release: CPPFLAGS += -DNDEBUG
release: $O/$$(TARGET).bin

# compiler emitted memcpy doesn't seem to work with lto
$O/lib-string.o: $(HERE)lib/string.c $(MAKEFILE_LIST) | $O
	$(call echo,  CC    $<)
	$Q$(CC) -o $@ $(filter-out -flto,$(CFLAGS)) $(CPPFLAGS) -c $<

$O/lib-%.o: $(HERE)lib/%.c $(MAKEFILE_LIST) | $O
	$(call echo,  CC    $<)
	$Q$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) -c $<

$O/%.o: %.c $(MAKEFILE_LIST) | $O
	$(call echo,  CC    $<)
	$Q$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) -c $<

$O/%.o: %.S $(MAKEFILE_LIST) | $O
	$(call echo,  AS    $<)
	$Q$(AS) -o $@ $(ASFLAGS) $(CPPFLAGS) -c $<

$O/$(TARGET).elf: $$(objects) $$(LDSCRIPT)
	$(call echo,  CCLD  $@)
	$Q$(CC) -o $@ $(LDFLAGS) -T$(LDSCRIPT) $(objects) $(LIBS)

$O/%.hex: $O/%.elf
	$(call echo,  HEX   $@)
	$Q$(HEX) $< $@

$O/%.bin: $O/%.elf
	$(call echo,  BIN   $@)
	$Q$(BIN) $< $@
	$Q$(call size,$@)

$O:
	$(call echo,  MKDIR $@)
	$Q$(MKDIR_P) $@

clean:
	$(call echo,  RM    $O)
	$Q$(RM_RF) $O

dump: $O/$$(TARGET).elf
	$(OBJDUMP) -x -d -j .init -j .text -j .data $< | $(PAGER)

dfu: $O/$$(TARGET).bin
	$Q$(DFU_UTIL) -d $(DFU_DEVICE) -D $< -R

romdfu: $O/$$(TARGET).bin
	$Q$(DFU_UTIL) -d 28e9:0189 -a 0 --dfuse-address 0x08000000:leave -D $<

cat: | $$(SERIAL)
	$(STTY) -F$(SERIAL) raw -echo -hup cs8 -parenb -cstopb 115200
	$(CAT) $(SERIAL)

-include $O/*.d
