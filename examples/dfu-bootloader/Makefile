include ../../Makefile

libs += stdio-uart0

# make sure we work even with the smallest
# GD32VF103x4 with only 6k SRAM
# for larger chips this just means we start
# our stack at 6k and ignore SRAM after that
RAM_SIZE=6*1024

release: BOOTLOADER=0
