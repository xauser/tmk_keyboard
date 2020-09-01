#include "keymap_common.h"
#include "led.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,PAUS,
        TAB, Q,   W,   E,   R,   T,        Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGUP,
        CAPS,A,   S,   D,   F,   G,        H,   J,   K,   L,   SCLN,QUOT,ENT,      PGDN,
        LSFT,Z,   X,   C,   V,   B,        B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,
        LCTL,     LALT,     SPC, LGUI,     SPC,      RALT,     RCTL,     LEFT,DOWN,RGHT)
};

const action_t fn_actions[] PROGMEM = {};

void led_set(uint8_t usb_led)
{
    usb_led & (1 << USB_LED_CAPS_LOCK)   ? (PORTD |= (1 << 3)) : (PORTD &= ~(1 << 3));
    usb_led & (1 << USB_LED_SCROLL_LOCK) ? (PORTD |= (1 << 5)) : (PORTD &= ~(1 << 5));
}
