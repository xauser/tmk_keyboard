L3 keyboard firmware
====================
Custom keyboard pcbs designed by LeeKu.

*Note that this is not the official firmware. By using this firmware you won't get any
support from LeeKu.*

This firmware is under development and usage is highly experimental. The l3 pcb design is based
on an ATMEGA32 (matrix scanning, usb host protocol) with an ATTINY85 (led effects)
co mcu connected by an i2c protocol.

Currently supported l3 layouts:

* MX1800 (TX1800)
* Ergo (LZ ergo)
* Compact 1800 (LZCP, TXCP)
* St (LZ ASRH)

Limitations
-----------

This firmware will run as an USB keyboard only. PS2 protocol is currently not supported.

Only some basic led effects are supported like all leds on or off. The full l3 led api is included
in this firmware and new led effects can be implemented.

Build
-----
Move to this directory then just run `make` like:

    $ make KEYMAP=$YOUR_KEYMAP

This will create a firmware hex file for your keymap. This firmware includes example keymaps for
all supported layouts.

Bootloader
----------
This firmware was tested with 'BootloadHID' an USB boot loader for AVR microcontrollers.

   https://www.obdev.at/products/vusb/bootloadhid-de.html

To compile the bootloader use the configuration header "bootloaderconfig.h"
and the make file "Makefile.bootloader" coming with this firmware.

   $ make

To flash the custom bootloader an AVR programmer is required.

   $ make flash

Once the bootloader is flashed to your keyboard you can enter it by pressing the ` -key right after
the USB cable was attached. Your keyboard is now listed as bootHID in your device tree.

To flash tmk firmware to your keyboard you have to enter bootloader and then use
BootloadHID command line tool.

   $ ./bootloadHID -r l3.hex
