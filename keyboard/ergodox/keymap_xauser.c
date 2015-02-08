#include "keymap_common.h"
#include <LUFA/Drivers/USB/USB.h>

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* layer 0: qwerty/space/backspace fn */
  KEYMAP(
    FN0, 1,   2,   3,   4,   5,   MINS,    EQL, 6,   7,   8,   9,   0,   GRV,
    TAB, Q,   W,   E,   R,   T,   LBRC,    RBRC,Y,   U,   I,   O,   P,   BSLS,
    FN1, A,   S,   D,   F,   G,                 H,   J,   K,   L,   SCLN,QUOT,
    LSFT,Z,   X,   C,   V,   B,   FN2,     FN3, N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,UP,  DOWN,LGUI,LALT,                        FN4, RGUI,LEFT,RGHT,RCTL,
                             PSCR,PAUS,    APP, INS,
                                  HOME,    PGUP,
                        FN5, DEL, END,     PGDN,ENT, FN6),
  /* layer 1: first function layer */
  KEYMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN7,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,
    TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,              MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,TRNS,BTN1),
  /* layer 2: second function layer */
  KEYMAP(
    TRNS,F1,  F2,  F3,  F4,  F5,  F11,     F12, F6,  F7,  F8,  F9,  F10, TRNS,
    TRNS,TRNS,Y,   P,   TRNS,TRNS,TRNS,    TRNS,TRNS,HOME,INS, DEL, END, TRNS,
    CAPS,TRNS,TRNS,TRNS,WSCH,TRNS,              LEFT,DOWN,UP,  RGHT,TRNS,TRNS,
    TRNS,TRNS,SLEP,TRNS,CALC,TRNS,TRNS,    TRNS,TRNS,FN8,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    MPRV,MNXT,
                                  TRNS,    VOLU,
                        TRNS,TRNS,TRNS,    VOLD,MPLY,TRNS)
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
  [4] = ACTION_LAYER_MODS(LAYER_FUNCTIONS_SECOND, MOD_RALT),
  [5] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_BSPC),
  [6] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTIONS_SECOND, KC_SPACE),
  [7] = ACTION_FUNCTION(ACTION_TEENSY),
  [8] = ACTION_MODS_KEY(MOD_LSFT, KC_INS)
};
