#include "keymap_common.h"
#include <LUFA/Drivers/USB/USB.h>

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: qwerty
  KEYMAP(
    EQL, 1,   2,   3,   4,   5,   PSCR,    PAUS,6,   7,   8,   9,   0,   MINS,
    TAB, Q,   W,   E,   R,   T,   CAPS,    APP, Y,   U,   I,   O,   P,   BSLS,
    FN1, A,   S,   D,   F,   G,                 H,   J,   K,   L,   SCLN,QUOT,
    LSFT,Z,   X,   C,   V,   B,   MUTE,    MPLY,N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,PGDN,PGUP,LALT,LGUI,                        RGUI,RALT,WH_D,WH_U,RCTL,
                             MPRV,MNXT,    LEFT,RGHT,
                                  VOLU,    UP,
                        FN7, FN11,VOLD,    DOWN,FN12, FN8),
  // layer 1: mouse
  KEYMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,
    TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,              MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PWR,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,BTN1,TRNS),
  // layer 2: functions
  KEYMAP(
    FN0, F1,  F2,  F3,  F4,  F5,  TRNS,    TRNS,F6,  F7,  F8,  F9,  F10, F11,
    TRNS,FN23,FN24,FN25,FN4, FN5, TRNS,    TRNS,TRNS,HOME,INS, DEL, END, F12,
    TRNS,FN26,FN27,FN28,FN2, FN3,               LEFT,DOWN,UP,  RGHT,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,    TRNS,MPRV,VOLD,VOLU,MNXT,MPLY,MUTE,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS),
  // layer 3: functions
  KEYMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,1,   2,   3,   4,   5,   TRNS,    TRNS,6,   7,   8,   9,   0,   TRNS,
    TRNS,FN21,FN14,FN16,FN0, FN15,              FN18,MINS,FN20,EQL, FN19,TRNS,
    TRNS,FN29,FN17,FN22,SLSH,BSLS,TRNS,    TRNS,FN13,GRV, FN10,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS)
};

enum ActionId {
  ACTION_TEENSY
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case ACTION_TEENSY: {
      USB_Disable();
      cli();
      _delay_ms(2000);

      EIMSK = 0; PCICR = 0; SPCR = 0; ACSR = 0; EECR = 0; ADCSRA = 0;
      TIMSK0 = 0; TIMSK1 = 0; TIMSK3 = 0; TIMSK4 = 0; UCSR1B = 0; TWCR = 0;
      DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0; TWCR = 0;
      PORTB = 0; PORTC = 0; PORTD = 0; PORTE = 0; PORTF = 0;

      ((void (*)(void))((((0x7FFF) + 1L) - 512)/2))();
    } break;
  }
}

enum LayerId {
  LAYER_0,
  LAYER_1,
  LAYER_2,
  LAYER_3
};

const action_t fn_actions[] PROGMEM = {
  [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [1] = ACTION_LAYER_TAP_KEY(LAYER_1, KC_ESC),
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
  [6] = ACTION_LAYER_MODS(LAYER_2, MOD_RALT),
  [7] = ACTION_LAYER_TAP_KEY(LAYER_2, KC_BSPC),
  [8] = ACTION_LAYER_TAP_KEY(LAYER_2, KC_SPACE),
  [9] = ACTION_FUNCTION(ACTION_TEENSY),
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
  [11] = ACTION_LAYER_TAP_KEY(LAYER_3, KC_DEL),
  [12] = ACTION_LAYER_TAP_KEY(LAYER_3, KC_ENT),
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [19] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
  [20] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
  [21] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [23] = ACTION_MODS_KEY(MOD_RALT, KC_Q),
  [24] = ACTION_MODS_KEY(MOD_RALT, KC_Y),
  [25] = ACTION_MODS_KEY(MOD_RALT, KC_P),
  [26] = ACTION_MODS_KEY(MOD_RALT, KC_M),
  [27] = ACTION_MODS_KEY(MOD_RALT, KC_S),
  [28] = ACTION_MODS_KEY(MOD_RALT, KC_5),
  [29] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
};
