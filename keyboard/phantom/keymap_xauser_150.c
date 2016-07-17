#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: qwerty */
    KEYMAP_ANSI_150(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,PAUS, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                       \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,           UP,        \
        LCTL,LGUI,LALT,               SPC,                     FN1, RGUI,RCTL,      LEFT,DOWN,RGHT),
    /* Layer 1: Space fn */
    KEYMAP_ANSI_150(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        FN2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,                      \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,           TRNS,      \
        TRNS,TRNS,TRNS,               FN4,                     TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),\
    /* Layer 2: First function layer (caps) */
    KEYMAP_ANSI_150(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        FN5, FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_L,WH_D,WH_U,WH_R,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     TRNS,                      \
        TRNS,     TRNS,TRNS,TRNS,BTN3,BTN2,BTN1,BTN4,BTN5,TRNS,TRNS,     TRNS,           TRNS,      \
        TRNS,TRNS,TRNS,               BTN1,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),\
    /* Layer 3: Second function layer (space) */
    KEYMAP_ANSI_150(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,INS, DEL, END, TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,FN7, TRNS,     TRNS,                      \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,FN8, TRNS,TRNS,TRNS,TRNS,     TRNS,           TRNS,      \
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),\
    /* Layer 4: Third function layer (right alt) */
    KEYMAP_ANSI_150(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,FN9, FN10,FN11,PSCR,SLCK,PAUS,HOME,INS, DEL, END, VOLD,VOLU,MUTE,      TRNS,TRNS,TRNS, \
        TRNS,FN12,FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPRV,MNXT,     MPLY,                      \
        TRNS,     SLEP,TRNS,TRNS,TRNS,TRNS,TRNS,PGDN,PGUP,TRNS,TRNS,     TRNS,           TRNS,      \
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),\
};

enum MacroId {
  MACRO_ALT_TAB
};

const macro_t* action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case MACRO_ALT_TAB:
      return (record->event.pressed ?
              MACRO(D(LALT), D(TAB), END) : MACRO(U(TAB), END));
  }
  return MACRO_NONE;
}

const action_t fn_actions[] PROGMEM = {
    [0]  = ACTION_LAYER_TAP_KEY(2, KC_CAPS),
    [1]  = ACTION_LAYER_MOMENTARY(4),
    [2]  = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
    [3]  = ACTION_LAYER_TAP_KEY(2, KC_ESC),
    [4]  = ACTION_LAYER_TAP_KEY(3, KC_SPACE),
    [5]  = ACTION_LAYER_SET_CLEAR(0),
    [6]  = ACTION_LAYER_ON(1, ON_RELEASE),
    [7]  = ACTION_MODS_KEY(MOD_LSFT, KC_INS),
    [8]  = ACTION_MACRO(MACRO_ALT_TAB),
    [9]  = ACTION_MODS_KEY(MOD_RALT, KC_Q),
    [10] = ACTION_MODS_KEY(MOD_RALT, KC_Y),
    [11] = ACTION_MODS_KEY(MOD_RALT, KC_P),
    [12] = ACTION_MODS_KEY(MOD_RALT, KC_5),
    [13] = ACTION_MODS_KEY(MOD_RALT, KC_S)
};
