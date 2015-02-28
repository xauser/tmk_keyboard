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

#include <avr/io.h>
#include "backlight.h"

void backlight_init_ports()
{
    DDRB |= 0b00011111;  // PB0 (caps), PB1 (alpha), PB2 (extra), PB3 (modnum), PB4 (caps)
    DDRD |= 0b11010000;  // PD4, (rgb blue), PD6 (rgb red), PD7 (rgb green)
    DDRE |= 0b01000000;  // PE6 (frow)
}

void backlight_set(uint8_t level)
{
    level & BACKLIGHT_ALPHA ? (PORTB |= 0b00000010) : (PORTB &= ~0b00000010);
    level & BACKLIGHT_EXTRA ? (PORTB |= 0b00000100) : (PORTB &= ~0b00000100);
    level & BACKLIGHT_MODNUM ? (PORTB |= 0b00001000) : (PORTB &= ~0b00001000);
    level & BACKLIGHT_FROW ? (PORTE |= 0b01000000) : (PORTE &= ~0b01000000);
    level & BACKLIGHT_RGBRED ? (PORTD |= 0b01000000) : (PORTD &= ~0b01000000);
    level & BACKLIGHT_RGBGREEN ? (PORTD |= 0b10000000) : (PORTD &= ~0b10000000);
    level & BACKLIGHT_RGBBLUE ? (PORTD |= 0b00010000) : (PORTD &= ~0b00010000);
}
