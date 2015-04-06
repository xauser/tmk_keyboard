/*
Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

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
#include "led.h"
#include "led_lightsaber.h"

/* Pin configuration
 *
 * Caps lock PB0 (high)
 * Alphas    PB1 (high)
 * Numeric   PB2 (high)
 * Mod+Num   PB3 (high)
 * Num lock  PB4 (high)
 * Pcb       PD6 (high)
 * TopRight  PD7 (low)
 * F-Row     PE6 (low)
 */
void led_init(void)
{
    DDRB |= 0b00011111;
    DDRD |= 0b11000000;
    DDRE |= 0b01000000;
}

void backlight_set(uint8_t level)
{
    level & BACKLIGHT_LEVEL_ALPHA ? (PORTB |= 0b00000010) : (PORTB &= ~0b00000010);
    level & BACKLIGHT_LEVEL_NUMERIC ? (PORTB |= 0b00000100) : (PORTB &= ~0b00000100);
    level & BACKLIGHT_LEVEL_MODNUM ? (PORTB |= 0b00001000) : (PORTB &= ~0b00001000);
    level & BACKLIGHT_LEVEL_FROW ? (PORTE &= ~0b01000000) : (PORTE |= 0b01000000);
    level & BACKLIGHT_LEVEL_TOPRGHT ? (PORTD &= ~0b10000000) : (PORTD |= 0b10000000);
    level & BACKLIGHT_LEVEL_PCB ? (PORTD |= 0b01000000) : (PORTD &= ~0b01000000);
}

void led_set(uint8_t usb_led)
{
    usb_led & (1 << USB_LED_CAPS_LOCK) ? (PORTB &= ~(1 << 0)) : (PORTB |= (1 << 0));
    usb_led & (1 << USB_LED_NUM_LOCK) ? (PORTB &= ~(1 << 4)) : (PORTB |= (1 << 4));
}
