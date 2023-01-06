#include "keymap_common.h"
#include <LUFA/Drivers/USB/USB.h>

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: qwerty
  KEYMAP(
    EQL, 1,   2,   3,   4,   5,   PSCR,    PAUS,6,   7,   8,   9,   0,   MINS,
    TAB, Q,   W,   E,   R,   T,   CAPS,    APP, Y,   U,   I,   O,   P,   BSLS,
    FN1, A,   S,   D,   F,   G,                 H,   J,   K,   L,   SCLN,QUOT,
    LSFT,Z,   X,   C,   V,   B,   MUTE,    MPLY,N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,PGDN,PGUP,LALT,LGUI,                        RGUI,FN6, WH_D,WH_U,RCTL,
                             MPRV,MNXT,    LEFT,RGHT,
                                  VOLU,    UP,
                        FN7, DEL, VOLD,    DOWN,ENT, FN8),
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
    TRNS,TRNS,Y,   P,   FN4, FN5, TRNS,    TRNS,TRNS,HOME,INS, DEL, END, F12,
    CAPS,M,   TRNS,5,   FN2, FN3,               LEFT,DOWN,UP,  RGHT,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
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
  LAYER_BASE,
  LAYER_FUNCTIONS_FIRST,
  LAYER_FUNCTIONS_SECOND
};

const action_t fn_actions[] PROGMEM = {
  [0] = ACTION_MODS_KEY(MOD_RSFT, KC_GRV),
  [1] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_FIRST, KC_ESC),
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
  [6] = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
  [7] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_BSPC),
  [8] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
  [9] = ACTION_FUNCTION(ACTION_TEENSY),
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
};

