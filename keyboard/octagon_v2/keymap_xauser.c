#include "keymap_common.h"

extern uint8_t backlight_rgb_r;
extern uint8_t backlight_rgb_g;
extern uint8_t backlight_rgb_b;

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: qwerty */
    KEYMAP(\
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR,SLCK,PAUS,
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGDN,
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT, DEL,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,  INS,
        LCTL,LGUI,LALT,               SPC,           FN1, NO,  RCTL,LEFT,DOWN,RGHT),
    /* layer 1: space fn */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               FN4,           TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 2: gaming */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,               TRNS,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 3: first function layer */
    KEYMAP(\
        TRNS,FN5, FN6, FN7, FN8, FN9, FN10,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN11,FN12,FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               BTN1,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 4: second function layer */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, VOLD,VOLU,MUTE,TRNS,
        CAPS,TRNS,TRNS,TRNS,WSCH,TRNS,LEFT,DOWN,UP,  RGHT,MPRV,MNXT,NO,  MPLY,TRNS,
        TRNS,NO,  SLEP,TRNS,CALC,TRNS,WFAV,FN14,PGDN,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,
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
  [5]  = ACTION_FUNCTION(ACTION_RGB_RESET),
  [6]  = ACTION_FUNCTION(ACTION_STEP_RED),
  [7]  = ACTION_FUNCTION(ACTION_STEP_GREEN),
  [8]  = ACTION_FUNCTION(ACTION_STEP_BLUE),
  [9]  = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
  [10] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGB),
  [11] = ACTION_DEFAULT_LAYER_SET(LAYER_QWERTY),
  [12] = ACTION_DEFAULT_LAYER_SET(LAYER_SPACEFN),
  [13] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};
