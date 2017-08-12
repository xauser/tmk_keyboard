#include "fc660c.h"

// Layer switch
#define AC_LY1      ACTION_LAYER_TAP_KEY(2, KC_ESC)    // esc and mouse layer
#define AC_LY2      ACTION_LAYER_TAP_KEY(3, KC_SPACE)  // space and function layer
#define AC_LY3      ACTION_LAYER_MOMENTARY(3)          // function layer
#define AC_LY4      ACTION_LAYER_TOGGLE(1)             // gaming layer
// German Umlaute
#define AC_DE1      ACTION_MODS_KEY(MOD_RALT, KC_Q)    // ä
#define AC_DE2      ACTION_MODS_KEY(MOD_RALT, KC_Y)    // ü
#define AC_DE3      ACTION_MODS_KEY(MOD_RALT, KC_P)    // ö
#define AC_DE4      ACTION_MODS_KEY(MOD_RALT, KC_M)    // µ
#define AC_DE5      ACTION_MODS_KEY(MOD_RALT, KC_S)    // ß
#define AC_DE6      ACTION_MODS_KEY(MOD_RALT, KC_5)    // €
// Symbols
#define AC_SY1      ACTION_MODS_KEY(MOD_LSFT, KC_LBRC) // {
#define AC_SY2      ACTION_MODS_KEY(MOD_LSFT, KC_RBRC) // }
#define AC_SY3      ACTION_MODS_KEY(MOD_LSFT, KC_9)    // (
#define AC_SY4      ACTION_MODS_KEY(MOD_LSFT, KC_0)    // )
#define AC_SY5      ACTION_MODS_KEY(MOD_LSFT, KC_EQL)  // +
#define AC_SY6      ACTION_MODS_KEY(MOD_LSFT, KC_MINS) // _
#define AC_SY7      ACTION_MODS_KEY(MOD_LSFT, KC_8)    // *
#define AC_SY8      ACTION_MODS_KEY(MOD_LSFT, KC_GRV)  // ~
#define AC_SY9      ACTION_MODS_KEY(MOD_LSFT, KC_4)    // $
#define AC_SY10     ACTION_MODS_KEY(MOD_LSFT, KC_2)    // @
#define AC_SY11     ACTION_MODS_KEY(MOD_LSFT, KC_3)    // #
#define AC_SY12     ACTION_MODS_KEY(MOD_LSFT, KC_5)    // %
#define AC_SY13     ACTION_MODS_KEY(MOD_LSFT, KC_7)    // &

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: qwerty
  KMAP(GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     PGUP,
       TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
       LY1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
       LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,UP,
       LCTL,LALT,LGUI,               LY2,                RGUI,RALT,RCTL,LEFT,DOWN,RGHT),
  // layer 1: gaming
  KMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     INS,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     DEL,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,
       TRNS,LY3, LALT,               SPC,                RALT,RGUI,TRNS,TRNS,TRNS,TRNS),
  // layer 2: mouse
  KMAP(TRNS,LY4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_D,WH_U,TRNS,TRNS,TRNS,TRNS,     TRNS,
       TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     TRNS,
       TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,     TRNS,TRNS,
       TRNS,TRNS,TRNS,               BTN1,               NO,  TRNS,TRNS,TRNS,TRNS,TRNS),
  // layer 3: functions
  KMAP(PAUS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
       TRNS,DE1, DE2, DE3, SY1, SY2, SY8, HOME,INS, DEL, END, TRNS,TRNS,TRNS,     TRNS,
       TRNS,DE3, DE4, DE5, SY3, SY4, LEFT,DOWN,UP,  RGHT,SY9, TRNS,     TRNS,
       TRNS,     SY13,SY12,SY11,LBRC,RBRC,SY7, MINS,SY5, EQL, SY6,      TRNS,TRNS,
       TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS)
};

void hook_layer_change(uint32_t layer_state) {
  if (layer_state & (1 << 1)) {
    PORTB &= ~(1 << 5);
  } else {
    PORTB |=  (1 << 5);
  }
}
