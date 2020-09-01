#include "keymap_common.h"
#include "led.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: space fn */
    KEYMAP(
        FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,PAUS,
        TAB, Q,   W,   E,   R,   T,        Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGUP,
        FN1, A,   S,   D,   F,   G,        H,   J,   K,   L,   SCLN,QUOT,ENT,      PGDN,
        LSFT,Z,   X,   C,   V,   B,        B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,
        LCTL,     LALT,     FN2, LGUI,     FN2,      FN3,      RCTL,     LEFT,DOWN,RGHT),
    /* layer 1: gaming */
    KEYMAP(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN4, TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,     TRNS,     SPC, TRNS,     SPC,      TRNS,     TRNS,     TRNS,TRNS,TRNS),
    /* layer 2: first function layer */
    KEYMAP(
        FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,WH_D,WH_U,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,     MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,     TRNS,     TRNS,TRNS,     BTN1,     TRNS,     TRNS,     TRNS,TRNS,TRNS),
    /* layer 3: second function layer */
    KEYMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  TRNS,TRNS,
        TRNS,TRNS,Y,   P,   PSCR,SLCK,     PAUS,HOME,INS, DEL, END, TRNS,TRNS,TRNS,TRNS,
        CAPS,M,   TRNS,5,   TRNS,TRNS,     LEFT,DOWN,UP,  RGHT,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,     TRNS,     TRNS,TRNS,     TRNS,     TRNS,     TRNS,     TRNS,TRNS,TRNS)
};

enum LayerId {
    LAYER_SPACEFN,
    LAYER_GAMING,
    LAYER_FUNCTIONS_FIRST,
    LAYER_FUNCTIONS_SECOND
};

const action_t fn_actions[] PROGMEM = {
    [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
    [1] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_ESC),
    [2] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
    [3] = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
    [4] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_CAPS),
    [5] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
    [6] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};

void led_set(uint8_t usb_led)
{
    usb_led & (1 << USB_LED_CAPS_LOCK)   ? (PORTD |= (1 << 3)) : (PORTD &= ~(1 << 3));
    usb_led & (1 << USB_LED_SCROLL_LOCK) ? (PORTD |= (1 << 5)) : (PORTD &= ~(1 << 5));
}
