#include "keymap_common.h"
#include "rgb.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: space fn */
    KEYMAP_65(
        FN0, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,PGDN,
        FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT, DEL,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,  INS,
        LCTL,LGUI,LALT,          FN2,                FN3, NO,  RCTL,LEFT,DOWN,RGHT),
    /* layer 1: gaming */
    KEYMAP_65(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,               SPC,           TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 2: first function layer */
    KEYMAP_65(
        FN5, FN6, FN7, FN8, FN9, FN10,FN11,FN12,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               BTN1,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* layer 3: second function layer */
    KEYMAP_65(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,
        TRNS,TRNS,Y,   P,   PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,TRNS,TRNS,
        CAPS,M,   TRNS,5,   TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS)
};

enum LayerId {
    LAYER_SPACEFN,
    LAYER_GAMING,
    LAYER_FUNCTIONS_FIRST,
    LAYER_FUNCTIONS_SECOND
};

enum function_id {
    AF_RGB_ON = 0,
    AF_RGB_OFF,
    AF_RGB_TOGGLE,
    AF_RGB_INCREASE,
    AF_RGB_DECREASE,
    AF_RGB_FIXED,
    AF_RGB_VARIABLE,
    AF_RGB_STEP,
    AF_TRICKY_ESC
};

const action_t fn_actions[] PROGMEM = {
    [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
    [1] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_ESC),
    [2] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
    [3] = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
    [4] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_CAPS),
    [5] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
    [6] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_ALPHA),
    [7] = ACTION_FUNCTION(AF_RGB_TOGGLE),
    [8] = ACTION_FUNCTION_OPT(AF_RGB_FIXED, RGB_FIXED_RED),
    [9] = ACTION_FUNCTION_OPT(AF_RGB_FIXED, RGB_FIXED_GREEN),
    [10] = ACTION_FUNCTION_OPT(AF_RGB_FIXED, RGB_FIXED_BLUE),
    [11] = ACTION_FUNCTION_OPT(AF_RGB_FIXED, RGB_FIXED_GREEN_1),
    [12] = ACTION_FUNCTION_OPT(AF_RGB_FIXED, RGB_FIXED_GREEN_4),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
        switch (id) {
            case AF_RGB_ON:
                rgb_on();
                break;
            case AF_RGB_OFF:
                rgb_off();
                break;
            case AF_RGB_TOGGLE:
                rgb_toggle();
                break;
            case AF_RGB_INCREASE:
                rgb_increase();
                break;
            case AF_RGB_DECREASE:
                rgb_decrease();
                break;
            case AF_RGB_FIXED:
                rgb_set(RGB_FIXED, opt);
                break;
            case AF_RGB_VARIABLE:
                rgb_set(RGB_VARIABLE, opt);
                break;
            case AF_RGB_STEP:
                rgb_step(opt);
                break;
        }
    }
}
