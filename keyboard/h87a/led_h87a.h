/*
Copyright 2022 Ralf Schmitt <ralf@bunkertor.net>

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
#ifndef LED_H87A_H
#define LED_H87A_H

#include <stdint.h>

enum backlight_step {
    BACKLIGHT_STEP_RED,
    BACKLIGHT_STEP_GREEN,
    BACKLIGHT_STEP_BLUE,
    BACKLIGHT_STEP_RESET
};

void backlight_rgb_set(uint8_t red, uint8_t green, uint8_t blue);
void backlight_set_step(uint8_t step);

#endif // LED_H87A_H
