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

#ifndef BACKLIGHT_H
#define BACKLIGHT_H

enum backlight_level {
    BACKLIGHT_ALPHA    = 0b0000001,
};

void backlight_init_ports(void);
void backlight_set(uint8_t level);

#endif // BACKLIGHT_H
