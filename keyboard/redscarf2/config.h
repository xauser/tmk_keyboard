/*
Copyright 2014 Kai Ryu <kai1103@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5253
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0002
#define MANUFACTURER    Young Pioneers
#define PRODUCT         Red Scarf II+
#define DESCRIPTION     t.m.k. keyboard firmware for Red Scarf II+

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 18

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* number of backlight levels */
#define BACKLIGHT_LEVELS 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define SUSPEND_ACTION

/* Mouse movement tuning */
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    10

#endif
