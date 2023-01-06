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
#include "../../xauser_common.h"

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    ACTIONMAP(
        EQL, 1,   2,   3,   4,   5,   TRNS,    TRNS,6,   7,   8,   9,   0,   MINS,
        TAB, Q,   W,   E,   R,   T,   HK3,     HK3, Y,   U,   I,   O,   P,   PIPE,
        TP3, A,   S,   D,   F,   G,                 H,   J,   K,   L,   SCLN,QUOT,
        LSFT,Z,   X,   C,   V,   B,   HK1,     HK2, N,   M,   COMM,DOT, SLSH,RSFT,
        LCTL,TRNS,TRNS,LALT,LGUI,                        RGUI,RALT,TRNS,MM3, RCTL,
                                 TRNS,TRNS,    TRNS,TRNS,
                                      TRNS,    TRNS,
                            TP4, DEL, TRNS,    TRNS,ENT, TP1),
    // gaming layer
    ACTIONMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        ESC, TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,MM1, TRNS,NO,  LALT,                        RALT,NO,  TRNS,TRNS,TRNS,
                                 TRNS,TRNS,    TRNS,TRNS,
                                      TRNS,    TRNS,
                            BSPC,TRNS,TRNS,    TRNS,TRNS,SPC),
    // nav layer
    ACTIONMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,              MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,WBAK,WH_D,WH_U,WFWD,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                                 TRNS,TRNS,    TRNS,TRNS,
                                      TRNS,    TRNS,
                            BTN1,TRNS,TRNS,    TRNS,TRNS,BTN1),
    // function layer
    ACTIONMAP(
        TILD,F1,  F2,  F3,  F4,  F5,  F11,     F12, F6,  F7,  F8,  F9,  F10, TRNS,
        MUTE,VOLD,VOLU,LBRC,RBRC,CIRC,TRNS,    TRNS,PAUS,HOME,INS, DEL, END, BSLS,
        MPLY,MPRV,MNXT,LPRN,RPRN,PERC,              LEFT,DOWN,UP,  RGHT,TRNS,TRNS,
        TRNS,TRNS,TRNS,LCBR,RCBR,AMPR,TRNS,    TRNS,ASTR,PGDN,PGUP,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,TRNS,
                                 TRNS,TRNS,    TRNS,TRNS,
                                      TRNS,    TRNS,
                            TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS),
    // toggle layer
    ACTIONMAP(
        CL1, TG1, TG2, TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PWR,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTLD,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,NO,                          TRNS,TRNS,TRNS,TRNS,TRNS,
                                 TRNS,TRNS,    TRNS,TRNS,
                                      TRNS,    TRNS,
                            TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS),
};
