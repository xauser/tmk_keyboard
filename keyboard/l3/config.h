/*
Copyright 2015 Ralf Schmitt <ralf@bunkertor.net>

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
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6050
#define DEVICE_VER      0x0100
#define MANUFACTURER    LeeKu
#define PRODUCT         L3
#define DESCRIPTION     t.m.k. keyboard firmware for L3

/* matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 20

/* number of backlight levels */
#define BACKLIGHT_LEVELS 1

/* Set 0 if need no debouncing */
#define DEBOUNCE 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* Let firmware know that rgb leds are not soldered */
#define RGB_LEDS_NOT_SOLDERED

/* Mouse movement tuning */
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    10

/* I2C parameters */
#define I2C_BITRATE_KHZ 400
#define I2C_TARGET_ADDR 0xB0

#endif
