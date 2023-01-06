#include "keymap_common.h"
#include "led.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
      ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,       F9,  F10, F11, F12,     PSCR,SLCK,PAUS,
      GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,    INS, HOME,PGUP,
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,         DEL, END, PGDN,
      CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,
      LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,                UP,
      LCTL,LGUI,LALT,               SPC,                NO,  RALT,RGUI,RCTL,         LEFT,DOWN,RGHT),
};

const action_t fn_actions[] PROGMEM = {};

