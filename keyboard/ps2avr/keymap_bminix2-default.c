#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP_BMINIX2(
        ESC, FN1, FN2, FN3, FN4, FN5, FN6, FN7, FN8, FN9, FN10,FN11,FN12,NO,  HOME,END,
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     DEL,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     INS,
        FN2, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,           PGUP,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,          UP,  PGDN,
        FN0, LALT,LGUI,          SPC,                     RGUI,RALT,RCTL,LEFT,DOWN,RGHT
    ),
};

const action_t PROGMEM fn_actions[] = { };
