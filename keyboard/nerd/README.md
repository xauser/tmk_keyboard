NerD keyboard firmware
========================

Korean Keyboard designed by GON.

*Note that this is not the official firmware*


Hardware revision
-----------------

This firmware was developed and tested for NerD pcb version 1.61 and 2.0.


Supported features
------------------

* All layout options are supported
* All leds are supported
* 60% and 80% (TKL) pcbs are supported


Changing Bootloader
-------------------

You can't simply just upload this firmware to a new NerD board because the original
bootloader won't accept DFU connections.

You can change the bootloader of the keyboard with an ISP programmer of your choice.
The bootloader pins are easy to access on the NerD pcb.

*Be aware that after changing the bootloader the official configuration software
won't work anymore and you'll lose your warrenty. GON won't provide any support for this firmware.*


Build
-----

Key map based layouts

```
make KEYMAP=xauser-60-150
```

Action map based layouts

```
make ACTIONMAP=xauser-60-150
```


Flash
-----

Key map based layouts

```
sudo make KEYMAP=xauser-60-150 dfu
```

Action map based layouts

```
sudo make ACTIONMAP=xauser-60-150 dfu
```


Jump to Bootloader
------------------

You can jump to bootloader by software if you have a macro defined for this in your keymap. The
default command is (LSFT+RSFT+PAUS) to access the bootloader by software jump.
