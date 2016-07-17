#include "actionmap.h"
#include "action_code.h"
#include "actionmap_common.h"
#include "backlight.h"

// Layer switch
#define AC_LY1      ACTION_LAYER_TAP_KEY(3, KC_ESC)    // esc and mouse layer
#define AC_LY2      ACTION_LAYER_TAP_KEY(4, KC_SPACE)  // space and function layer
#define AC_LY3      ACTION_LAYER_MOMENTARY(4)          // function layer
#define AC_LY4      ACTION_LAYER_TOGGLE(1)             // gaming layer
#define AC_LY5      ACTION_LAYER_TOGGLE(2)             // nav layer
#define AC_LY6      ACTION_LAYER_TOGGLE(3)             // mouse layer
// Backlight
#define AC_BL1      ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)
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
  // layer 0: qwerty layer
  ACTIONMAP_60(GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
               TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
               LY1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,
               LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,
               LCTL,LALT,LGUI,               LY2,                NO,  RGUI,RALT,RCTL),
  // layer 1: gaming layer
  ACTIONMAP_60(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
               TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,
               TRNS,LY3, LALT,               SPC,                NO,  RALT,RGUI,TRNS),
  // layer 2: nav cluster layer
  ACTIONMAP_60(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
               TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,UP,  NO,
               TRNS,TRNS,TRNS,               TRNS,               NO,  LEFT,DOWN,RGHT),
  // layer 3: mouse layer
  ACTIONMAP_60(TRNS,LY4, LY5, LY6, BL1, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
               TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,
               TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,
               TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,NO,
               TRNS,TRNS,TRNS,               BTN1,               NO,  TRNS,TRNS,TRNS),
  // layer 4: function layer
  ACTIONMAP_60(PAUS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,
               TRNS,DE1 ,DE2, DE3, SY1, SY2, SY8, HOME,INS, DEL, END, TRNS,TRNS,TRNS,
               TRNS,DE4, DE5, DE6, SY3, SY4, LEFT,DOWN,UP,  RGHT,SY9, TRNS,NO,  TRNS,
               TRNS,NO,  SY13,SY12,SY11,LBRC,RBRC,SY7, MINS,SY5, EQL, SY6, TRNS,NO,
               TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS)
};
