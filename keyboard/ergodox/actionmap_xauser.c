/*
Copyright 2024 Ralf Schmitt <ralf@bunkertor.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "actionmap.h"
#include "actionmap_common.h"
#include <LUFA/Drivers/USB/USB.h>

enum ActionId {
  ACTION_TEENSY
};

// Layer switch
#define AC_LS1      ACTION_LAYER_TAP_KEY(1, KC_BSPC)   // backspace and function layer
#define AC_LS2      ACTION_LAYER_TAP_KEY(1, KC_SPACE)  // space and function layer
#define AC_LS3      ACTION_LAYER_TAP_KEY(2, KC_ESC)    // esc and mouse layer
#define AC_LS4      ACTION_LAYER_MODS(1, MOD_LALT | MOD_LGUI) // layer 1 enabled with alt and gui
// German Umlaute
#define AC_DE1      ACTION_MODS_KEY(MOD_RALT, KC_Q)    // ä
#define AC_DE2      ACTION_MODS_KEY(MOD_RALT, KC_Y)    // ü
#define AC_DE3      ACTION_MODS_KEY(MOD_RALT, KC_P)    // ö
#define AC_DE4      ACTION_MODS_KEY(MOD_RALT, KC_M)    // µ
#define AC_DE5      ACTION_MODS_KEY(MOD_RALT, KC_S)    // ß
#define AC_DE6      ACTION_MODS_KEY(MOD_RALT, KC_5)    // €
// Bootloader
#define AC_BL1      ACTION_FUNCTION(ACTION_TEENSY)     // Bootloader jump
// Symbols
#define AC_SY1      ACTION_MODS_KEY(MOD_LSFT, KC_LBRC) // {
#define AC_SY2      ACTION_MODS_KEY(MOD_LSFT, KC_RBRC) // }
#define AC_SY3      ACTION_MODS_KEY(MOD_LSFT, KC_9)    // (
#define AC_SY4      ACTION_MODS_KEY(MOD_LSFT, KC_0)    // )
#define AC_SY5      ACTION_MODS_KEY(MOD_LSFT, KC_EQL)  // +
#define AC_SY6      ACTION_MODS_KEY(MOD_LSFT, KC_MINS) // _
#define AC_SY7      ACTION_MODS_KEY(MOD_LSFT, KC_8)    // *
#define AC_SY8      ACTION_MODS_KEY(MOD_LSFT, KC_GRV)  // ~
#define AC_SY9      ACTION_MODS_KEY(MOD_LSFT, KC_4)    // $
#define AC_SY10     ACTION_MODS_KEY(MOD_LSFT, KC_2)    // @
#define AC_SY11     ACTION_MODS_KEY(MOD_LSFT, KC_3)    // #
#define AC_SY12     ACTION_MODS_KEY(MOD_LSFT, KC_5)    // %
#define AC_SY13     ACTION_MODS_KEY(MOD_LSFT, KC_7)    // &
#define AC_SY14     ACTION_MODS_KEY(MOD_LSFT, KC_6)    // ^
// Hotkeys
#define AC_HK1      ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_K)  // Switch to monitor on the right
#define AC_HK2      ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_J)  // Switch to monitor on the left
#define AC_HK3      ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_M)  // Ctrl+Shift+M to mute in Teams

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: qwerty
  ACTIONMAP(
    EQL, 1,   2,   3,   4,   5,   MPLY,    MUTE,6,   7,   8,   9,   0,   MINS,
    TAB, Q,   W,   E,   R,   T,   LS4,     HK3, Y,   U,   I,   O,   P,   BSLS,
    LS3, A,   S,   D,   F,   G,                 H,   J,   K,   L,   SCLN,QUOT,
    LSFT,Z,   X,   C,   V,   B,   HK2,     HK1, N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,PGDN,PGUP,LALT,LGUI,                        RGUI,RALT,WH_D,WH_U,RCTL,
                             MPRV,MNXT,    LEFT,RGHT,
                                  VOLU,    UP,
                        LS1, DEL, VOLD,    DOWN,ENT, LS2),
  // layer 1: functions
  ACTIONMAP(
    SY8, F1,  F2,  F3,  F4,  F5,  F11,     F12, F6,  F7,  F8,  F9,  F10, TRNS,
    SY14,DE1, DE2, DE3, SY1, SY2, PSCR,    APP, SY10,HOME,INS, DEL, END, TRNS,
    CAPS,DE4, DE5, DE6, SY3, SY4,               LEFT,DOWN,UP,  RGHT,SY9, TRNS,
    TRNS,SY13,SY12,SY11,LBRC,RBRC,PAUS,    TRNS,SY7, MINS,SY5, EQL ,SY6, TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS),
  // layer 2: mouse
  ACTIONMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BL1,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,
    TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,              MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PWR,
    TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                             TRNS,TRNS,    TRNS,TRNS,
                                  TRNS,    TRNS,
                        TRNS,TRNS,TRNS,    TRNS,BTN1,TRNS)
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
