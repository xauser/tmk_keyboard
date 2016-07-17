#include "keymap.h"
#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //
  // layer 0: qwerty layer
  //
  //       |GRV | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 9  | -  | =  | BS |
  //       |TAB | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  | \  |
  //       |LS05| A  | S  | D  | F  | G  | H  | J  | K  | L  | '  | ;  |    |LS05|
  //       |SHFT|    | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |SHFT|    |
  //       |CTRL|ALT |GUI |              |LS04|              |    |GUI |ALT |CTRL|
  //
  KEYMAP_60(GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
            TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
            FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  FN1,
            LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,
            LCTL,LALT,LGUI,               FN2,                NO,  RGUI,RALT,RCTL),
  //
  // layer 1: gaming layer
  //
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |LS04|ALT |              |SPC |                   |ALT |GUI |    |
  //
  KEYMAP_60(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
            TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,
            TRNS,FN3, LALT,               SPC,                NO,  RALT,RGUI,TRNS),
  //
  // layer 2: nav cluster layer
  //
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |UP  |    |
  //       |    |    |    |              |    |                   |LEFT|DOWN|RGHT|
  //
  KEYMAP_60(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
            TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,UP,  NO,
            TRNS,TRNS,TRNS,               TRNS,               NO,  LEFT,DOWN,RGHT),
  //
  // layer 3: mouse layer
  //
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |    |    |    |MS_L|MS_D|MS_U|MS_R|    |    |    |    |
  //       |    |    |    |    |    |    |    |BTN3|BTN2|    |    |    |    |    |
  //       |    |    |    |              |    |                   |    |    |    |
  //
  KEYMAP_60(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,
            TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,
            TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,NO,
            TRNS,TRNS,TRNS,               BTN1,               NO,  TRNS,TRNS,TRNS),
  //
  // layer 4: function layer
  //
  //       |    |F1  |F2  |F3  |F4  |F5  |F6  |F7  |F8  |F9  |F10 |F11 |F12 |    |
  //       |    | ä  | ü  | ö  |PGUP|    |PAUS|HOME|INS |DEL |END |    |    |    |
  //       |    | µ  | ß  | €  |PGDN|    |LEFT|DOWN|UP  |RGHT|    |    |    |    |
  //       |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
  //       |    |    |    |              |    |                   |    |    |    |
  //
  KEYMAP_60(TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,
            TRNS,FN8 ,FN9, FN10,PGUP,TRNS,PAUS,HOME,INS, DEL, END, TRNS,TRNS,TRNS,
            TRNS,FN11,FN12,FN13,PGDN,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,
            TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,
            TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS),
  //
  // layer 5: symbol layer
  //
  //       |    |LT01|LT02|LT03|    |    |    |    |    |    |    |    |    |    |
  //       |    |    | <  | >  | "  | `  | &  |    | [  | ]  | %  |    |    |    |
  //       |    | !  | -  | +  | =  | #  | |  |    | (  | )  | ?  |    |    |    |
  //       |    |    | /  | *  | \  | _  | ~  | $  | {  | }  | @  |    |    |    |
  //       |    |    |    |              |    |                   |    |    |    |
  //
  KEYMAP_60(TRNS,FN4, FN5, FN6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
            TRNS,TRNS,FN29,FN30,TRNS,GRV, FN22,QUOT,LBRC,RBRC,FN20,TRNS,TRNS,TRNS,
            TRNS,FN16,MINS,FN26,EQL, FN18,FN28,MINS,FN24,FN25,TRNS,TRNS,NO,  TRNS,
            TRNS,NO,  SLSH,FN23,BSLS,FN27,FN31,FN19,FN14,FN15,FN17,TRNS,TRNS,NO,
            TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS)
};

enum LayerId {
  LAYER_QWERTY,
  LAYER_GAMING,
  LAYER_NAV,
  LAYER_MOUSE,
  LAYER_FUNCTION,
  LAYER_SYMBOL
};

const action_t fn_actions[] PROGMEM = {
  // Layer switch
  [0] = ACTION_LAYER_TAP_KEY(LAYER_SYMBOL, KC_ESC),
  [1] = ACTION_LAYER_TAP_KEY(LAYER_SYMBOL, KC_ENT),
  [2] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTION, KC_SPACE),
  [3] = ACTION_LAYER_MOMENTARY(LAYER_FUNCTION),
  // Layer toggle
  [4] = ACTION_LAYER_TOGGLE(LAYER_GAMING),
  [5] = ACTION_LAYER_TOGGLE(LAYER_NAV),
  [6] = ACTION_LAYER_TOGGLE(LAYER_MOUSE),
  // Backlight
  [7] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
  // German Umlaute
  [8] = ACTION_MODS_KEY(MOD_RALT, KC_Q),     // ä
  [9] = ACTION_MODS_KEY(MOD_RALT, KC_Y),     // ü
  [10] = ACTION_MODS_KEY(MOD_RALT, KC_P),    // ö
  [11] = ACTION_MODS_KEY(MOD_RALT, KC_M),    // µ
  [12] = ACTION_MODS_KEY(MOD_RALT, KC_S),    // ß
  [13] = ACTION_MODS_KEY(MOD_RALT, KC_5),    // €
  // Symbols
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // }
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_1),    // !
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_2),    // @
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_3),    // #
  [19] = ACTION_MODS_KEY(MOD_LSFT, KC_4),    // $
  [20] = ACTION_MODS_KEY(MOD_LSFT, KC_5),    // %
  [21] = ACTION_MODS_KEY(MOD_LSFT, KC_6),    // ^
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_7),    // &
  [23] = ACTION_MODS_KEY(MOD_LSFT, KC_8),    // *
  [24] = ACTION_MODS_KEY(MOD_LSFT, KC_9),    // (
  [25] = ACTION_MODS_KEY(MOD_LSFT, KC_0),    // )
  [26] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),  // +
  [27] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // _
  [28] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS), // |
  [29] = ACTION_MODS_KEY(MOD_LSFT, KC_COMM), // <
  [30] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),  // >
  [31] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),  // ~
};
