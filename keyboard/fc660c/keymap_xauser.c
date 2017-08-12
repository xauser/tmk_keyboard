#include "fc660c.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* layer 0: spacefn */
  KMAP(FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     PGUP,
       TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
       FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
       LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,UP,
       LCTL,LGUI,LALT,               FN2,                FN3, RGUI,RCTL,LEFT,DOWN,RGHT),
  /* layer 1: gaming */
  KMAP(GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     INS,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     DEL,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
       TRNS,FN4, TRNS,               SPC,                TRNS,FN4, TRNS,TRNS,TRNS,TRNS),
  /* layer 2: mouse */
  KMAP(FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_D,WH_U,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     TRNS,
       TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,     TRNS,TRNS,
       TRNS,TRNS,TRNS,               BTN1,               NO,  TRNS,TRNS,TRNS,TRNS,TRNS),
  /* layer 3: functions */
  KMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
       TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,TRNS,     TRNS,
       CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,     TRNS,
       TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
       TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS)
};

enum LayerId {
  LAYER_SPACEFN,
  LAYER_GAMING,
  LAYER_MOUSE,
  LAYER_FUNCTIONS
};

const action_t fn_actions[] PROGMEM = {
  [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [1] = ACTION_LAYER_TAP_KEY(LAYER_MOUSE, KC_ESC),
  [2] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS, KC_SPACE),
  [3] = ACTION_LAYER_MODS(LAYER_FUNCTIONS, MOD_RALT),
  [4] = ACTION_LAYER_MOMENTARY(LAYER_FUNCTIONS),
  [5] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
};

void hook_layer_change(uint32_t layer_state) {
  if (layer_state & (1 << 1)) {
    PORTB &= ~(1 << 5);
  } else {
    PORTB |=  (1 << 5);
  }
}
