#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    KEYMAP_65(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGDN, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT, DEL,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,  INS,  \
        LCTL,LGUI,LALT,          SPC,                RALT,NO,  RCTL,LEFT,DOWN,RGHT  ),
};

const uint16_t fn_actions[] PROGMEM = {
};
