Jetfire keyboard firmware
=========================
Korean custom keyboard designed by Duck.

*Note that this is not the official firmware*


Supported models
----------------
All pcb options are supported.


Build
-----
Move to this directory then just run `make` like:

    $ make

This will create a firmware with default "winkey" keymap. To compile a different keymap
run make like this:

    $ make KEYMAP=other

Bootloader
---------
The PCB is hardwired to run the bootloader if the key at the `top right` position is held down when connecting the keyboard.

It is still possible to use Boot Magic and Command to access the bootloader though.
