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
#include "../../xauser_common.h"

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    ACTIONMAP_ANSI_150(
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,PAUS,
        TILD,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,      INS, HOME,PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   HK4, HK5, BSPC,      DEL, END, PGDN,
        TP3, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,           UP,
        LCTL,LALT,LGUI,               TP1,                     RALT,MM3, RCTL,      LEFT,DOWN,RGHT),
    // gaming layer
    ACTIONMAP_ANSI_150(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSPC,      TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,BSLS,      TRNS,TRNS,TRNS,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,           TRNS,
        TRNS,MM1, LALT,               SPC,                     TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    // nav layer
    ACTIONMAP_ANSI_150(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,     TRNS,           TRNS,
        TRNS,TRNS,TRNS,               BTN1,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    // function layer
    ACTIONMAP_ANSI_150(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,      TRNS,TRNS,TRNS,
        MUTE,VOLD,VOLU,LBRC,RBRC,CIRC,PAUS,HOME,INS, DEL, END, HK1, HK2, TRNS,      TRNS,TRNS,TRNS,
        MPLY,MPRV,MNXT,LPRN,RPRN,PERC,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,     TRNS,
        TRNS,     TRNS,TRNS,LCBR,RCBR,AMPR,ASTR,PGDN,PGUP,TRNS,TRNS,     TRNS,           TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    // toggle layer
    ACTIONMAP_ANSI_150(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        CL1, TG1, TG2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PWR,       TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,           TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
};
