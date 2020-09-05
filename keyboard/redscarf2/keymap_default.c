#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    KEYMAP(
        F1,  F2,  FN30,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,NLCK,PSLS,PAST,PMNS, \
        F3,  F4,  TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,P7,  P8,  P9,  PPLS, \
        F5,  F6,  CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,GRV, ENT, P4,  P5,  P6,  PPLS, \
        F7,  F8,  LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0, P1,  P2,  P3,  PENT, \
        F9,  F10, LCTL,LGUI,LALT,          SPC,                RALT,FN0, RCTL,RGUI,RCTL,P0,  P0,  PDOT,PENT  ),
};

const uint16_t fn_actions[] PROGMEM = {
};
