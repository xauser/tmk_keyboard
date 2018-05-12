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

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "led.h"
#include "led_jetfire.h"

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
  Device_STATELED
};

uint8_t backlight_rgb_r = 255;
uint8_t backlight_rgb_g = 0;
uint8_t backlight_rgb_b = 0;
uint8_t backlight_state_led = 1<<STATE_LED_LAYER_0;

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
  for (uint8_t b = 0; b < 8; b++) {
    if (device == Device_STATELED) {
      send_bit_d4(byte & 0b10000000);
    }
    if (device == Device_PCBRGB) {
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

void led_init(void)
{
  DDRD  |=  0b01010000;
  PORTD &=  0b10101111;
  DDRB  |=  0b00001110;
  PORTB &=  0b11110001;
  DDRE  |=  0b01000000;
  PORTE &=  0b10111111;

  backlight_update_state_led();
}

void backlight_update_state_led()
{
  cli();
  send_color(backlight_state_led & (1<<STATE_LED_SCROLL_LOCK) ? 255 : 0,
             backlight_state_led & (1<<STATE_LED_CAPS_LOCK) ? 255 : 0,
             backlight_state_led & (1<<STATE_LED_NUM_LOCK) ? 255 : 0,
             Device_STATELED);
  send_color(backlight_state_led & (1<<STATE_LED_LAYER_1) ? 255 : 0,
             backlight_state_led & (1<<STATE_LED_LAYER_2) ? 255 : 0,
             backlight_state_led & (1<<STATE_LED_LAYER_0) ? 255 : 0,
             Device_STATELED);
  send_color(backlight_state_led & (1<<STATE_LED_LAYER_4) ? 255 : 0,
             backlight_state_led & (1<<STATE_LED_LAYER_3) ? 255 : 0,
             0,
             Device_STATELED);
  sei();
  show();
}

void backlight_toggle_rgb(bool enabled)
{
  if (enabled) {
    uint8_t rgb[RGB_LED_COUNT][3] = {
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
    uint8_t rgb[RGB_LED_COUNT][3] = {
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

void backlight_set_rgb(uint8_t cfg[RGB_LED_COUNT][3])
{
  cli();
  for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
    send_color(cfg[i][0], cfg[i][1], cfg[i][2], Device_PCBRGB);
  }
  sei();
  show();
}

void backlight_set(uint8_t level)
{
  level & BACKLIGHT_LEVEL_ALPHA    ? (PORTB |= 0b00000010) : (PORTB &= ~0b00000010);
  level & BACKLIGHT_LEVEL_MOD      ? (PORTB |= 0b00000100) : (PORTB &= ~0b00000100);
  level & BACKLIGHT_LEVEL_FROW     ? (PORTB |= 0b00001000) : (PORTB &= ~0b00001000);
  level & BACKLIGHT_LEVEL_NUMBLOCK ? (PORTE |= 0b01000000) : (PORTE &= ~0b01000000);
  backlight_toggle_rgb(level & BACKLIGHT_LEVEL_RGB);
}

void led_set(uint8_t led_state)
{
  if (led_state & (1<<USB_LED_CAPS_LOCK)) {
    backlight_state_led |=   1<<STATE_LED_CAPS_LOCK;
  } else {
    backlight_state_led &= ~(1<<STATE_LED_CAPS_LOCK);
  }
  if (led_state & (1<<USB_LED_SCROLL_LOCK)) {
    backlight_state_led |=   1<<STATE_LED_SCROLL_LOCK;
  } else {
    backlight_state_led &= ~(1<<STATE_LED_SCROLL_LOCK);
  }
  if (led_state & (1<<USB_LED_NUM_LOCK)) {
    backlight_state_led |=   1<<STATE_LED_NUM_LOCK;
  } else {
    backlight_state_led &= ~(1<<STATE_LED_NUM_LOCK);
  }
  backlight_update_state_led();
}

void backlight_set_step(uint8_t step)
{
  const uint8_t value = 15;
  switch (step) {
    case BACKLIGHT_STEP_RED: {
      if (backlight_rgb_r + value >= 255) {
        backlight_rgb_r = 255;
      } else {
        backlight_rgb_r += value;
      }
    } break;
    case BACKLIGHT_STEP_GREEN: {
      if (backlight_rgb_g + value >= 255) {
        backlight_rgb_g = 255;
      } else {
        backlight_rgb_g += value;
      }
    } break;
    case BACKLIGHT_STEP_BLUE: {
      if (backlight_rgb_b + value >= 255) {
        backlight_rgb_b = 255;
      } else {
        backlight_rgb_b += value;
      }
    } break;
    case BACKLIGHT_STEP_RESET: {
      backlight_rgb_r = 0;
      backlight_rgb_g = 0;
      backlight_rgb_b = 0;
    } break;
    default:
    break;
  }
  backlight_toggle_rgb(true);
}
