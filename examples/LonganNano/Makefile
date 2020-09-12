include ../../Makefile

libs += stdio-usbacm stdio-uart0

# some LonganNano boards comes with the biggest
# GD32VF103CB chip with 32k SRAM and 128k FLASH,
# but some also ship with the smaller C8-chip,
# which only has 20k SRAM and 64k FLASH
# let's error on the safe side by default,
# but remove this if you have the CB version
RAM_SIZE=20*1024
FLASH_SIZE=64*1024
