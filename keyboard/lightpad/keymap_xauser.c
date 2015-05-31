#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Numpad */
    KEYMAP(\
        FN0, FN1, FN2, FN3,  \
        NLCK,PSLS,PAST,PMNS, \
        P7,  P8,  P9,  PPLS, \
        P4,  P5,  P6,        \
        P1,  P2,  P3,  PENT, \
        P0,  NO,  COMM),     \
    /* Layer 1: Multimedia */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS, \
        ESC, ENT, DEL, F,    \
        MSEL,MSTP,MPLY,VOLU, \
        MPRV,UP,  MNXT,      \
        LEFT,DOWN,RGHT,VOLD, \
        MUTE,NO,  SPC),      \
    /* Layer 2: Mouse */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS, \
        NO,  NO,  NO,  NO,   \
        BTN1,BTN3,BTN2,WH_U, \
        NO,  MS_U,NO,        \
        MS_L,MS_D,MS_R,WH_D, \
        NO,  NO,  NO),       \
    /* Layer 3: Functions */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS, \
        NO,  NO,  NO,   NO,  \
        NO,  NO,  NO,   NO,  \
        NO,  NO,  NO,        \
        FN4, FN5, NO,   NO,  \
        SLEP,NO,  NO)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_SET(0, 1),
    [1] = ACTION_LAYER_SET(1, 1),
    [2] = ACTION_LAYER_SET(2, 1),
    [3] = ACTION_LAYER_SET(3, 1),
    [4] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_NUMPAD),
    [5] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_REAR)
};
