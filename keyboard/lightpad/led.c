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
#include "stdint.h"
#include "led.h"

void led_set(uint8_t usb_led) {
    (usb_led & (1<<USB_LED_NUM_LOCK)) ? backlight_enable_numlock() : backlight_disable_numlock();
}

/*
void led_layer_set(uint32_t state) {
  backlight_disable_fn1();
  backlight_disable_fn2();
  backlight_disable_fn3();
  backlight_disable_fn4();
  if(state & (1<<0)) {
    backlight_enable_fn1();
  }
  if(state & (1<<1)) {
    backlight_enable_fn2();
  }
  if(state & (1<<2)) {
    backlight_enable_fn3();
  }
  if(state & (1<<3)) {
    backlight_enable_fn4();
  }
}
*/
