#include "keymap_common.h"
#include "rgb.h"

uint8_t rgb_red = 0;
uint8_t rgb_green = 0;
uint8_t rgb_blue = 0;

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0: space fn
    KEYMAP(
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,       F9,  F10, F11, F12,     PSCR,SLCK,PAUS,
        FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,    INS, HOME,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,         DEL, END, PGDN,
        FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,                UP,
        LCTL,LGUI,LALT,               FN2,                NO,  FN3, RGUI,RCTL,         LEFT,DOWN,RGHT),
    // layer 1: gaming
    KEYMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
        FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,
        TRNS,NO,  TRNS,               SPC,                TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS),
    // layer 2: mouse
    KEYMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_D,WH_U,TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,
        TRNS,TRNS,TRNS,               BTN1,               TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS),
    // layer 3: function layer
    KEYMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,FN7, FN8, FN9, FN10,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,TRNS,    TRNS,TRNS,TRNS,
        TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,PGDN,         TRNS,TRNS,TRNS,
        CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,
        TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS)
};

enum LayerId {
  LAYER_SPACEFN,
  LAYER_GAMING,
  LAYER_MOUSE,
  LAYER_FUNCTION
};

enum ActionId {
  ACTION_RGB_RESET,
  ACTION_RGB_STEP_RED,
  ACTION_RGB_STEP_GREEN,
  ACTION_RGB_STEP_BLUE
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (record->event.pressed) {
    switch(id) {
      case ACTION_RGB_RESET: {
        rgb_red = 0;
        rgb_green = 0;
        rgb_blue = 0;
      } break;
      case ACTION_RGB_STEP_RED: {
        rgb_red = (rgb_red + 15) % 255;
      } break;
      case ACTION_RGB_STEP_GREEN: {
        rgb_green = (rgb_green + 15) % 255;
      } break;
      case ACTION_RGB_STEP_BLUE: {
        rgb_blue = (rgb_blue + 15) % 255;
      } break;
    }
    rgb_set(rgb_red, rgb_green, rgb_blue);
  }
}

const action_t fn_actions[] PROGMEM = {
  [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [1] = ACTION_LAYER_TAP_KEY(LAYER_MOUSE, KC_ESC),
  [2] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTION, KC_SPACE),
  [3] = ACTION_LAYER_MODS(LAYER_FUNCTION, MOD_RALT),
  [4] = ACTION_LAYER_TAP_KEY(LAYER_MOUSE, KC_CAPS),
  [5] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
  [6] = ACTION_MODS_KEY(MOD_LSFT, KC_INS),
  [7] = ACTION_FUNCTION(ACTION_RGB_STEP_RED),
  [8] = ACTION_FUNCTION(ACTION_RGB_STEP_GREEN),
  [9] = ACTION_FUNCTION(ACTION_RGB_STEP_BLUE),
  [10] = ACTION_FUNCTION(ACTION_RGB_RESET)
};
