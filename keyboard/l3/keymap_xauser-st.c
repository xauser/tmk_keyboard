#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* layer 0: qwerty */
  KEYMAP_ST(
      ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,PGUP,
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
      FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,
      LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,       UP,
      LCTL,LGUI,LALT,               SPC,                     FN1, RGUI,RCTL,LEFT,DOWN,RGHT),
  /* layer 1: space fn */
  KEYMAP_ST(
      FN2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
      FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
      TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
      TRNS,TRNS,TRNS,               FN4,                     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
  /* layer 2: gaming */
  KEYMAP_ST(
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
      TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
      TRNS,NO,  TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
  /* layer 3: first function layer */
  KEYMAP_ST(
      FN5, FN6, FN7, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN8, FN9, FN10,FN11,NO,  TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,     TRNS,
      TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,
      TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
      TRNS,NO,  TRNS,               BTN1,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
  /* layer 4: second function layer */
  KEYMAP_ST(
      GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  TRNS,TRNS,
      TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, VOLD,VOLU,MUTE,     TRNS,
      CAPS,M,   TRNS,TRNS,WSCH,TRNS,LEFT,DOWN,UP,  RGHT,MPRV,MNXT,NO,  MPLY,
      TRNS,NO,  SLEP,TRNS,CALC,TRNS,WFAV,FN12,PGDN,PGUP,TRNS,TRNS,TRNS,NO,       TRNS,
      TRNS,NO,  TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS)
};

enum ActionId {
  ACTION_LED_CHANGE_MODE,
  ACTION_RGB_CHANGE_MODE
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case ACTION_LED_CHANGE_MODE:
      led_change_mode();
      break;
    case ACTION_RGB_CHANGE_MODE:
      rgb_change_mode();
      break;
    default:
      break;
  }
}

enum LayerId {
  LAYER_QWERTY,
  LAYER_SPACEFN,
  LAYER_GAMING,
  LAYER_FUNCTIONS_FIRST,
  LAYER_FUNCTIONS_SECOND
};

const action_t fn_actions[] PROGMEM = {
  [0]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_CAPS),
  [1]  = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
  [2]  = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [3]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_ESC),
  [4]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
  [5]  = ACTION_DEFAULT_LAYER_SET(LAYER_QWERTY),
  [6]  = ACTION_DEFAULT_LAYER_SET(LAYER_SPACEFN),
  [7]  = ACTION_DEFAULT_LAYER_SET(LAYER_GAMING),
  [8]  = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
  [9]  = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_PCB),
  [10] = ACTION_FUNCTION(ACTION_LED_CHANGE_MODE),
  [11] = ACTION_FUNCTION(ACTION_RGB_CHANGE_MODE),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};