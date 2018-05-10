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

// Backlight
#define AC_BL1 ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0: space-fn layer (default layer)
    ACTIONMAP_MX1800(
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,      INS, HOME,PGUP,PSCR,
                                                                                   DEL, END, PGDN,SLCK,
        AMPR,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,NLCK,PSLS,PAST,PAUS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     P7,  P8,  P9,  PMNS,
        ESC, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  TP2,      P4,  P5,  P6,  PPLS,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT,
        LCTL,LGUI,LALT,               TP1,                     RALT,RCTL,LEFT,DOWN,RGHT,P0,  COMM,NO),
    // layer 1: gaming layer (toggle layer)
    ACTIONMAP_MX1800(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                                   TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,LY3, TRNS,               SPC,                     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
    // layer 2: nav cluster layer (toggle layer)
    ACTIONMAP_MX1800(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                                   TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
    // layer 3: mouse layer (toggle layer)
    ACTIONMAP_MX1800(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                                   TRNS,TRNS,TRNS,TRNS,
        TRNS,BTN1,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,WH_D,MS_U,WH_U,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,     MS_U,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               BTN1,                    TRNS,TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,NO),
    // layer 4: function layer 'space' (momentary layer)
    ACTIONMAP_MX1800(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                                   TRNS,TRNS,TRNS,TRNS,
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  PAUS,TRNS,TRNS,TRNS,TRNS,
        TRNS,DE1, DE2, DE3, LCBR,RCBR,AMPR,HOME,INS, DEL, END, HK1, HK2, BTN3,     TRNS,TRNS,TRNS,TRNS,
        TRNS,DE4, DE5, DE6, LPRN,RPRN,LEFT,DOWN,UP,  RGHT,CIRC,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  SY13,HK5, HK4, LBRC,RBRC,ASTR,MINS,TILD,EQL, PIPE,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
    // layer 5: function layer 'enter' (momentary layer)
    ACTIONMAP_MX1800(
        TRNS,     BL1, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
                                                                                   TRNS,TRNS,TRNS,TRNS,
        CL1, TG1, TG2, TG3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  PWR, TRNS,TRNS,TRNS,TRNS,
        TRNS,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,MPRV,MNXT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  MPLY,MUTE,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
};
