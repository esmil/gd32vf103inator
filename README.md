# gd32vf103inator

## What is this?

This is a collection of headers, some code, linkerscript and Makefile to make it
easy to program the [GD32VF103][gigadevice] RISC-V microcontroller from GigaDevice.
It is already supported in [PlatformIO][platformio] and ArduinoIDE is underway,
but sometimes it's nice to just use your favourite editor and make.
This is exactly where this project will help you do.

The [user manual][usermanual] and [datasheet][datasheet] for the chip as available
from [here][datasheets].

[gigadevice]: https://www.gigadevice.com/products/microcontrollers/gd32/risc-v/
[platformio]: https://github.com/sipeed/platform-gd32v/
[usermanual]: https://github.com/riscv-mcu/GD32VF103_DataSheets/raw/master/GD32VF103_User_Manual_EN_V1.0.pdf
[datasheet]: https://github.com/riscv-mcu/GD32VF103_DataSheets/raw/master/GD32VF103_Datasheet_Rev_1.0.pdf
[datasheets]: https://github.com/riscv-mcu/GD32VF103_DataSheets


## Using gd32vf103inator

#### The quick and dirty way

```sh
git clone https://github.com/esmil/gd32vf103inator.git
mkdir myproject
cd myproject
echo include ../gd32vf103inator/Makefile > Makefile
cp ../gd32vf103inator/main.c .
make
```

#### The sophisticated way
```sh
mkdir myproject
cd myproject
git init
git submodule add https://github.com/esmil/gd32vf103inator.git
echo include gd32vf103inator/Makefile > Makefile
echo build/ > .gitignore
cp gd32vf103inator/main.c .
git add .
git commit -m 'initial commit'
```


## Bootloader

The chip has a built-in DFU bootloader in ROM but unfortunately it has some
~~bugs~~ quirks: it only works with a [patched version][gd32-dfu-utils]
of dfu-utils and some [workarounds][bootloader-workaround].

That's a bit annoying so this project includes another DFU bootlader
that can be programmed into the first 4k flash. This bootloader does work with
the regular dfu-util and is much faster. The bootloader will activate when
the chip is reset by the external reset pin (aka. the reset button is pressed).
On any other reset (power on, watchdogs etc.) the bootloader will immediately
jump 4k into the flash and run the regular program.

You can use the built-in bootloader in ROM to flash this bootloader. First
make sure to reboot the chip into the ROM bootloader and then run:
```sh
cd gd32vf103inator/examples/dfu-bootloader
make clean
make release
make DFU_UTIL=/path/to/gd32-dfu-utils/src/dfu-util romdfu
```
This will show errors even when the chip is succesfully flashed.
Apparently that's just how the built-in bootloader works :/

Once the bootloader is flashed the chip can be programmed by just
pressing the reset button and run:
```
make dfu
```
This will use the dfu-util in your path, flash the chip and reset it to run
your program.

For this to work regular programs must be compiled run from an offset
of 4k into the flash. That happens automatically, but if you're happy with
the built-in bootloader or you have some other means of flashing the chip
you can disable it by adding this line to your Makefile:
```
BOOTLOADER = 0
```

[gd32-dfu-utils]: https://github.com/riscv-mcu/gd32-dfu-utils
[bootloader-workaround]: https://github.com/esmil/gd32vf103inator/blob/master/start.S#L245


## Getting a RISC-V toolchain

Ideally you want a toolchain for embedded use. For RISC-V it will typically be called
something containing `riscv64-unknown-elf`.
This is similar to `arm-none-eabi` toolchains in ARM land.
Don't worry that it's called "riscv64" even though the core in the chip is only 32bit.
The toolchain will still be able to produce 32bit code, floating point/non-floating point
code and many other valid RISC-V combinations.

Unfortunately RISC-V toolchains for embedded use are not yet available in most distributions,
but cross compilers for Linux seem to be. They are usually called something containing
`riscv64-linux-gnu`, and gd32vf103inator has been made to work with such toolchains too.
This is not ideal but with enough options to gcc it can be persuaded to not use any libc bits.

If your chosen toolchain is not prefixed with `riscv64-unknown-elf-` you can overwrite the
`CROSS_COMPILE` variable in your local Makefile. Eg. append this to your Makefile:
```
CROSS_COMPILE = riscv64-linux-gnu-
```

Below are some suggestions for specific operating systems. Please make a pull request
to add your favourite OS.


##### Archlinux

There are packages [riscv64-unknown-elf-binutils][aur-binutils] and
[riscv64-unknown-elf-gcc][aur-gcc] available in AUR.

Alternatively there are prebuilt riscv64-linux-gnu packages in community repo. Eq.
```sh
pacman -S riscv64-linux-gnu-gcc make
```

[aur-binutils]: https://aur.archlinux.org/packages/riscv64-unknown-elf-binutils/
[aur-gcc]: https://aur.archlinux.org/packages/riscv64-unknown-elf-gcc/


##### Debian/Ubuntu

If you're running Debian unstable aka. sid you should use the riscv64-unknown-elf toolchain:

```sh
apt-get install gcc-riscv64-unknown-elf make
```

On Ubuntu you might want to try the
[embedded toolchain from SiFive](#prebuilt-toolchains-from-sifive) below.

Otherwise it should also work with the cross compiler for Linux. Eg.:

```sh
apt-get install gcc-riscv64-linux-gnu make
```


##### Fedora

Unfortunately I don't know of any prebuilt riscv64-unknown-elf toolchains for
Fedora, but again the cross-compiler for Linux should work:

```sh
dnf install gcc-riscv64-linux-gnu make
```


##### OSX

See [SiFive's toolchain](#prebuilt-toolchains-from-sifive) below.


##### Windows
###### Option 1

See [SiFive's toolchain](#prebuilt-toolchains-from-sifive) below for the toolchain.
You'll also need GNU Make to build your code.

###### Option 2

Use Windows Subsystem for Linux and proceed as on Ubuntu above.


##### Prebuilt toolchains from SiFive

Go to [SiFive's software page][sifive-boards] and search for "GNU Embedded Toolchain".
Download the relevant tarball/zip-file and unpack it. Now you can either update your path
to include the `bin` folder inside, or add the following line to your Makefile:
```
CROSS_COMPILE = /full/path/to/the/extracted/folder/bin/riscv64-unknown-elf-
```

[sifive-boards]: https://www.sifive.com/boards


## License

This project is licensed under the [BSD 3-Clause][bsd-3] license just like
the [firmware library][firmware] released by GigaDevice.
Register and bit definitions are copied from there and modified to be usable
without including the rest of the library.

[bsd-3]: https://opensource.org/licenses/BSD-3-Clause
[firmware]: https://github.com/riscv-mcu/GD32VF103_Firmware_Library/
