#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: space fn
  KEYMAP_MX1800(
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,      INS, HOME,PGUP,PSCR,
                                                                               DEL, END, PGDN,SLCK,
    FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,NLCK,PSLS,PAST,PAUS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     P7,  P8,  P9,  PMNS,
    FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,      P4,  P5,  P6,  PPLS,
    LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT,
    LCTL,LGUI,LALT,               FN2,                     FN3, RCTL,LEFT,DOWN,RGHT,P0,  COMM,NO),
  // layer 1: gaming
  KEYMAP_MX1800(
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                               TRNS,TRNS,TRNS,TRNS,
    GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
    FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
    TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,NO,  TRNS,               SPC,                     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
  // layer 2: first function layer
  KEYMAP_MX1800(
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                               TRNS,TRNS,TRNS,TRNS,
    FN5, FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
    TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
    TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               BTN1,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
  // layer 3: second function layer
  KEYMAP_MX1800(
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                               TRNS,TRNS,TRNS,TRNS,
    GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  PGUP,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,PGDN,     TRNS,TRNS,TRNS,TRNS,
    CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
    TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,FN7, PGDN,PGUP,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO)
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
  [6] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
  [7] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};