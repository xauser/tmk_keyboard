#include "keymap_common.h"

extern uint8_t backlight_rgb_r;
extern uint8_t backlight_rgb_g;
extern uint8_t backlight_rgb_b;

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: space fn */
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR,SLCK,PAUS,
        FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGDN,
        FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT, DEL,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,  INS,
        LCTL,LGUI,LALT,               FN2,           FN3, NO,  RCTL,LEFT,DOWN,RGHT),
    /* layer 1: gaming */
    KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,               SPC,           TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 2: first function layer */
    KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN5, FN6, FN7, FN8, FN9, FN10,FN11,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               BTN1,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 3: second function layer */
    KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,TRNS,
        TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,PGDN,TRNS,
        CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,FN12,PGDN,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS)
};

enum ActionId {
  ACTION_STEP_RED,
  ACTION_STEP_GREEN,
  ACTION_STEP_BLUE,
  ACTION_RGB_RESET
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  const uint8_t step = 15;
  switch(id) {
    case ACTION_STEP_RED: {
      if(backlight_rgb_r + step >= 255) {
        backlight_rgb_r = 255;
      } else {
        backlight_rgb_r += step;
      }
    } break;
    case ACTION_STEP_GREEN: {
      if(backlight_rgb_g + step >= 255) {
        backlight_rgb_g = 255;
      } else {
        backlight_rgb_g += step;
      }
    } break;
    case ACTION_STEP_BLUE: {
      if(backlight_rgb_b + step >= 255) {
        backlight_rgb_b = 255;
      } else {
        backlight_rgb_b += step;
      }
    } break;
    case ACTION_RGB_RESET: {
      backlight_rgb_r = 0;
      backlight_rgb_g = 0;
      backlight_rgb_b = 0;
    } break;
    default:
      break;
  }
  backlight_toggle_rgb(true);
}

enum LayerId {
  LAYER_SPACEFN,
  LAYER_GAMING,
  LAYER_FUNCTIONS_FIRST,
  LAYER_FUNCTIONS_SECOND
};

const action_t fn_actions[] PROGMEM = {
  [0]  = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [1]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_ESC),
  [2]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
  [3]  = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
  [4]  = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_CAPS),
  [5]  = ACTION_LAYER_TOGGLE(LAYER_GAMING),
  [6]  = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
  [7]  = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGB),
  [8]  = ACTION_FUNCTION(ACTION_STEP_RED),
  [9]  = ACTION_FUNCTION(ACTION_STEP_GREEN),
  [10] = ACTION_FUNCTION(ACTION_STEP_BLUE),
  [11] = ACTION_FUNCTION(ACTION_RGB_RESET),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};
