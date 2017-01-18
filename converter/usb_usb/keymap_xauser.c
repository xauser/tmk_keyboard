#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // layer 0: space fn
  KEYMAP(ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,   PSCR,SLCK,BRK,
         FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,  INS, HOME,PGUP,  NLCK,PSLS,PAST,PMNS,
         TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,  DEL, END, PGDN,  P7,  P8,  P9,
         FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                    P4,  P5,  P6,  PPLS,
         LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,       UP,         P1,  P2,  P3,
         LCTL,LGUI,LALT,               FN2,                FN3, RGUI,APP, RCTL,  LEFT,DOWN,RGHT,  P0,       PDOT,PENT),
  // layer 1: gaming
  KEYMAP(TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,                   TRNS,TRNS,TRNS,TRNS,
         TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,       TRNS,       TRNS,TRNS,TRNS,
         TRNS,NO,  TRNS,               SPC,                TRNS,NO,  NO,  TRNS,  TRNS,TRNS,TRNS,  TRNS,     TRNS,TRNS),
  // layer 2: first function layer
  KEYMAP(TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     TRNS,                   TRNS,TRNS,TRNS,TRNS,
         TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,     TRNS,       TRNS,       TRNS,TRNS,TRNS,
         TRNS,TRNS,TRNS,               BTN1,               TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,     TRNS,TRNS),
  // layer 3: second layer function
  KEYMAP(GRV,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PGUP,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
         TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,PGDN,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
         CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,     TRNS,                   TRNS,TRNS,TRNS,TRNS,
         TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,FN6, TRNS,TRNS,TRNS,TRNS,     TRNS,       TRNS,       TRNS,TRNS,TRNS,
         TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,     TRNS,TRNS)
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

