/*
Copyright 2016 Ralf Schmitt <ralf@bunkertor.net>

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

#include "backlight.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "led.h"

#define T1H  900
#define T1L  600
#define T0H  400
#define T0L  900
#define RES 6000

#define NS_PER_SEC (1000000000L)
#define CYCLES_PER_SEC (F_CPU)
#define NS_PER_CYCLE (NS_PER_SEC / CYCLES_PER_SEC)
#define NS_TO_CYCLES(n) ((n) / NS_PER_CYCLE)

enum Device {
  Device_PCBRGB,
  Device_STATUSLED
};

uint8_t backlight_rgb_r = 255;
uint8_t backlight_rgb_g = 0;
uint8_t backlight_rgb_b = 0;
uint8_t backlight_os_state = 0;
uint32_t backlight_layer_state = 0;

void send_bit_d4(bool bitVal)
{
  if(bitVal) {
    asm volatile (
        "sbi %[port], %[bit] \n\t"
        ".rept %[onCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        "cbi %[port], %[bit] \n\t"
        ".rept %[offCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        ::
        [port]      "I" (_SFR_IO_ADDR(PORTD)),
        [bit]       "I" (4),
        [onCycles]  "I" (NS_TO_CYCLES(T1H) - 2),
        [offCycles] "I" (NS_TO_CYCLES(T1L) - 2));
  } else {
    asm volatile (
        "sbi %[port], %[bit] \n\t"
        ".rept %[onCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        "cbi %[port], %[bit] \n\t"
        ".rept %[offCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        ::
        [port]      "I" (_SFR_IO_ADDR(PORTD)),
        [bit]       "I" (4),
        [onCycles]  "I" (NS_TO_CYCLES(T0H) - 2),
        [offCycles] "I" (NS_TO_CYCLES(T0L) - 2));
  }
}

void send_bit_d6(bool bitVal)
{
  if(bitVal) {
    asm volatile (
        "sbi %[port], %[bit] \n\t"
        ".rept %[onCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        "cbi %[port], %[bit] \n\t"
        ".rept %[offCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        ::
        [port]      "I" (_SFR_IO_ADDR(PORTD)),
        [bit]       "I" (6),
        [onCycles]  "I" (NS_TO_CYCLES(T1H) - 2),
        [offCycles] "I" (NS_TO_CYCLES(T1L) - 2));
  } else {
    asm volatile (
        "sbi %[port], %[bit] \n\t"
        ".rept %[onCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        "cbi %[port], %[bit] \n\t"
        ".rept %[offCycles] \n\t"
        "nop \n\t"
        ".endr \n\t"
        ::
        [port]      "I" (_SFR_IO_ADDR(PORTD)),
        [bit]       "I" (6),
        [onCycles]  "I" (NS_TO_CYCLES(T0H) - 2),
        [offCycles] "I" (NS_TO_CYCLES(T0L) - 2));
  }
}

void send_byte(uint8_t byte, enum Device device)
{
  for(uint8_t b = 0; b < 8; b++) {
    if(device == Device_STATUSLED) {
      send_bit_d4(byte & 0b10000000);
    }
    if(device == Device_PCBRGB) {
      send_bit_d6(byte & 0b10000000);
    }
    byte <<= 1;
  }
}

void send_color(uint8_t r, uint8_t g, uint8_t b, enum Device device)
{
  send_byte(g, device);
  send_byte(r, device);
  send_byte(b, device);
}

void show()
{
  _delay_us((RES / 1000UL) + 1);
}

void backlight_init_ports(void)
{
  DDRD  |=  0b11010000;
  PORTD &= ~0b01010000;
  PORTD |=  0b10000000;
  DDRB  |=  0b00011111;
  PORTB &= ~0b00001110;
  PORTB |=  0b00010001;
  DDRE  |=  0b01000000;
  PORTE &= ~0b01000000;
}

void backlight_set_state(bool cfg[7])
{
  cli();
  send_color(cfg[1] ? 255 : 0, cfg[2] ? 255 : 0, cfg[0] ? 255 : 0, Device_STATUSLED);
  send_color(cfg[4] ? 255 : 0, cfg[3] ? 255 : 0, cfg[5] ? 255 : 0, Device_STATUSLED);
  cfg[6] ? (PORTD &= ~0b10000000) : (PORTD |= 0b10000000);
  sei();
  show();
}

void backlight_toggle_rgb(bool enabled)
{
  if(enabled) {
    uint8_t rgb[17][3] = {
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b},
      {backlight_rgb_r, backlight_rgb_g, backlight_rgb_b}
    };
    backlight_set_rgb(rgb);
  } else {
    uint8_t rgb[17][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}
    };
    backlight_set_rgb(rgb);
  }
}

void backlight_set_rgb(uint8_t cfg[17][3])
{
  cli();
  for(uint8_t i = 0; i < 17; ++i) {
    send_color(cfg[i][0], cfg[i][1], cfg[i][2], Device_PCBRGB);
  }
  sei();
  show();
}

void backlight_set(uint8_t level)
{
  level & BACKLIGHT_ALPHA ? (PORTB |= 0b00000010) : (PORTB &= ~0b00000010);
  level & BACKLIGHT_EXTRA ? (PORTB |= 0b00000100) : (PORTB &= ~0b00000100);
  level & BACKLIGHT_MODNUM ? (PORTB |= 0b00001000) : (PORTB &= ~0b00001000);
  level & BACKLIGHT_FROW ? (PORTE |= 0b01000000) : (PORTE &= ~0b01000000);
  level & BACKLIGHT_RGB ? backlight_toggle_rgb(true) : backlight_toggle_rgb(false);
}

void led_set(uint8_t usb_led)
{
  backlight_os_state = usb_led;
  backlight_update_state();
}
/*
void led_layer_set(uint32_t state)
{
  backlight_layer_state = state;
  backlight_update_state();
}
*/

void backlight_update_state(void)
{
  bool status[7] = {
    backlight_os_state & (1<<USB_LED_CAPS_LOCK),
    backlight_os_state & (1<<USB_LED_SCROLL_LOCK),
    backlight_os_state & (1<<USB_LED_NUM_LOCK),
    backlight_layer_state & (1<<1),
    backlight_layer_state & (1<<2),
    backlight_layer_state & (1<<3),
    backlight_layer_state & (1<<4)
  };
  backlight_set_state(status);
  backlight_os_state & (1<<USB_LED_CAPS_LOCK) ? (PORTB &= ~0b00000001) : (PORTB |= 0b00000001);
  backlight_os_state & (1<<USB_LED_SCROLL_LOCK) ? (PORTB &= ~0b00010000) : (PORTB |= 0b00010000);
}
