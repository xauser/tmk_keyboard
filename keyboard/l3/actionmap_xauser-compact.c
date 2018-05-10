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

// Actions
#define ACTION_LED_CHANGE_MODE 0
#define ACTION_RGB_CHANGE_MODE 1

// Backlight
#define AC_BL1 ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)
#define AC_BL2 ACTION_BACKLIGHT_LEVEL(BACKLIGHT_PCB)
#define AC_BL3 ACTION_FUNCTION(ACTION_LED_CHANGE_MODE)
#define AC_BL4 ACTION_FUNCTION(ACTION_RGB_CHANGE_MODE)

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    ACTIONMAP_COMPACT(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS, HOME,PSCR,SLCK,PAUS,
        TILD,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSLS,NLCK,PSLS,PAST,PMNS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   HK4, HK5, BSPC,     P7,  P8,  P9,  NO,
        TP3, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  TP2,      P4,  P5,  P6,  PPLS,
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT,
        LCTL,LALT,LGUI,NO,  NO,       TP1,      NO,       RALT,NO,  RCTL,LEFT,DOWN,RGHT,P0,  COMM,NO),
    // gaming layer
    ACTIONMAP_COMPACT(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  BSPC,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,BSLS,     TRNS,TRNS,TRNS,NO,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,MM1, LALT,NO,  NO,       SPC,      NO,       TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
    // nav layer
    ACTIONMAP_COMPACT(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,NO,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,TRNS,     MS_U,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,NO,  NO,       BTN1,     NO,       TRNS,NO,  TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,NO),
    // function layer
    ACTIONMAP_COMPACT(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        MUTE,VOLD,VOLU,LBRC,RBRC,CIRC,PAUS,HOME,INS, DEL, END, HK1, HK2, TRNS,     TRNS,TRNS,TRNS,NO,
        MPLY,MPRV,MNXT,LPRN,RPRN,PERC,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,LCBR,RCBR,AMPR,ASTR,PGDN,PGUP,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,NO,  NO,       TRNS,     NO,       TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
    // toggle layer
    ACTIONMAP_COMPACT(
        TRNS,BL1, BL2, BL3, BL4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,
        CL1, TG1, TG2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  PWR, TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,NO,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS,
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,NO,  NO,       TRNS,     NO,       TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ACTION_LED_CHANGE_MODE:
            led_change_mode();
        break;
        case ACTION_RGB_CHANGE_MODE:
            rgb_change_mode();
        break;
        default:
        break;
    }
}
