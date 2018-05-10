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
#include "led_l3.h"
#include "../../xauser_common.h"

// Let firmware know that rgb leds are not soldered
#define RGB_LEDS_NOT_SOLDERED

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0: space-fn layer (default layer)
    ACTIONMAP_ST(
        AMPR,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
        ESC, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  TP2,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,       UP,
        LCTL,LGUI,LALT,               TP1,                     RALT,RGUI,RCTL,LEFT,DOWN,RGHT),
    // layer 1: gaming layer (toggle layer)
    ACTIONMAP_ST(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
        TRNS,MM1, TRNS,               SPC,                     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // layer 2: nav cluster layer (toggle layer)
    ACTIONMAP_ST(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // layer 3: mouse layer (toggle layer)
    ACTIONMAP_ST(
        TRNS,BTN1,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,
        TRNS,WH_D,MS_U,WH_U,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,NO,       MS_U,
        TRNS,NO,  TRNS,               BTN1,                    TRNS,TRNS,TRNS,MS_L,MS_D,MS_R),
    // layer 4: function layer 'space' (momentary layer)
    ACTIONMAP_ST(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  PAUS,TRNS,
        TRNS,DE1, DE2, DE3, LCBR,RCBR,AMPR,HOME,INS, DEL, END, HK1, HK2, TRNS,     TRNS,
        TRNS,DE4, DE5, DE6, LPRN,RPRN,LEFT,DOWN,UP,  RGHT,CIRC,TRNS,NO,  TRNS,
        TRNS,NO,  SY13,HK5, HK4, LBRC,RBRC,ASTR,MINS,TILD,EQL, PIPE,TRNS,NO,       TRNS,
        TRNS,NO,  TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // layer 5: function layer 'enter' (momentary layer)
    ACTIONMAP_ST(
        CL1, TG1, TG2, TG3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  PWR, TRNS,
        TRNS,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,MPRV,MNXT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,
        TRNS,NO,  MPLY,MUTE,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,       TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS)
};
