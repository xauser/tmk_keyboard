#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP_COMPACT(
      ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS, HOME,PSCR,SLCK,PAUS,
      GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,NLCK,PSLS,PAST,PMNS,
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     P7,  P8,  P9,  NO,
      CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,      P4,  P5,  P6,  PPLS,
      LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT,
      LCTL,LGUI,LALT,NO,  NO,       SPC,      NO,       RALT,NO,  RCTL,LEFT,DOWN,RGHT,P0,  COMM,NO)
};

const action_t PROGMEM fn_actions[] = {};
