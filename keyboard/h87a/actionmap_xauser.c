/*
Copyright 2026 Ralf Schmitt <ralf@bunkertor.net>

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
#include "actionmap_common.h"
#include "led_h87a.h"
#include "../../xauser_common.h"

// Backlight
#define AC_BL1 ACTION_FUNCTION(BACKLIGHT_STEP_RED)
#define AC_BL2 ACTION_FUNCTION(BACKLIGHT_STEP_GREEN)
#define AC_BL3 ACTION_FUNCTION(BACKLIGHT_STEP_BLUE)
#define AC_BL4 ACTION_FUNCTION(BACKLIGHT_STEP_RESET)

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0: base layer
    ACTIONMAP(
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,       F9,  F10, F11, F12,     PSCR,SLCK,PAUS,
        AMPR,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSLS,    INS, HOME,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   HK4, HK5, BSPC,         DEL, END, PGDN,
        TP3, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,                UP,
        LCTL,LALT,LGUI,               TP1,                NO,  RALT,MM1, RCTL,         LEFT,DOWN,RGHT),
    // layer 1: gaming layer
    ACTIONMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  BSPC,    TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,BSLS,         TRNS,TRNS,TRNS,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,                TRNS,
        TRNS,MM1, LALT,               SPC,                NO,  TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS),
    // layer 2: nav layer
    ACTIONMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,WH_U,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,    TRNS,TRNS,WH_D,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,         BTN1,BTN3,BTN2,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,NO,                MS_U,
        TRNS,TRNS,TRNS,               BTN1,               NO,  TRNS,TRNS,TRNS,         MS_L,MS_D,MS_R),
    // layer 3: function layer
    ACTIONMAP(
        TRNS,     BL1, BL2, BL3, BL4, TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  PWR,     TRNS,TRNS,TRNS,
        MUTE,VOLD,VOLU,LBRC,RBRC,AMPR,PAUS,HOME,INS, DEL, END, HK1, HK2, TRNS,         TRNS,TRNS,TRNS,
        MPLY,MPRV,MNXT,LPRN,RPRN,CIRC,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,LCBR,RCBR,PERC,ASTR,PGDN,PGUP,TRNS,TRNS,TRNS,NO,                TRNS,
        TRNS,TRNS,TG1,                TRNS,               NO,  TG2, TRNS,TRNS,         TRNS,TRNS,TRNS),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
        backlight_set_step(id);
    }
}
