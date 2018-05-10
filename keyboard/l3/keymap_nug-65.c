#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP_65(
         ESC,   1,   2,   3,   4,   5,   6,   7,   8,    9,    0, MINS,  EQL, BSLS,  GRV,  DEL,
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,    O,    P, LBRC, RBRC, BSPC,       PGUP,
        CAPS,   A,   S,   D,   F,   G,   H,   J,   K,    L, SCLN, QUOT,   NO,  ENT,       PGDN,
        LSFT, FN0,   Z,   X,   C,   V,   B,   N,   M, COMM,  DOT, SLSH, RSFT,         UP,  END,
        LCTL,LGUI,LALT, SPC,           SPC,      SPC, RALT,             RCTL, LEFT, DOWN, RGHT),
    [1] = KEYMAP_65(
         PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,   F9,  F10,  F11,  F12,  INS,  DEL,  FN1,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,
        TRNS,TRNS,TRNS,TRNS,          TRNS,     TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS),
    [2] = KEYMAP_65(
         PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,   F9,  F10,  F11,  F12,  INS,  DEL,  FN1,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,
        TRNS,TRNS,TRNS,TRNS,          TRNS,     TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TOGGLE(2),
};
