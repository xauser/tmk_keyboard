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
#include "led_jetfire.h"
#include "../../xauser_common.h"

extern uint8_t backlight_state_led;

// Backlight
#define AC_BL1 ACTION_BACKLIGHT_LEVEL(BACKLIGHT_LEVEL_SWITCH)
#define AC_BL2 ACTION_BACKLIGHT_LEVEL(BACKLIGHT_LEVEL_RGB)
#define AC_BL3 ACTION_FUNCTION(BACKLIGHT_STEP_RED)
#define AC_BL4 ACTION_FUNCTION(BACKLIGHT_STEP_GREEN)
#define AC_BL5 ACTION_FUNCTION(BACKLIGHT_STEP_BLUE)
#define AC_BL6 ACTION_FUNCTION(BACKLIGHT_STEP_RESET)

const action_t PROGMEM actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    ACTIONMAP(
        ESC,      F1,  F2,  F3,  F4,       F5,  F6,  F7,  F8,  F9,  F10, F11, F12, HOME,PSCR,SLCK,PAUS,PGUP,
        TILD,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,      BSLS,INS, NLCK,PSLS,PAST,PMNS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   HK4, HK5,      BSPC,DEL, P7,  P8,  P9,  PPLS,
        TP3, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,          TP2,      P4,  P5,  P6,
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,      SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT,
        LCTL,LALT,LGUI,               TP1,                          RALT,RCTL,LEFT,DOWN,RGHT,P0,  COMM),
    // gaming layer
    ACTIONMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     BSPC,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,     BSLS,TRNS,TRNS,TRNS,TRNS,TRNS,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,     TRNS,TRNS,TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,MM1, LALT,               SPC,                          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // nav layer
    ACTIONMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,          TRNS,     TRNS,TRNS,TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,WBAK,WH_D,WH_U,WFWD,     TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               BTN1,                         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // function layer
    ACTIONMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        MUTE,VOLD,VOLU,LBRC,RBRC,CIRC,PAUS,HOME,INS, DEL, END, HK1, HK2,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        MPLY,MPRV,MNXT,LPRN,RPRN,PERC,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,          TRNS,     TRNS,TRNS,TRNS,
        TRNS,     TRNS,TRNS,LCBR,RCBR,AMPR,ASTR,PGDN,PGUP,TRNS,     TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
    // toggle layer
    ACTIONMAP(
        TRNS,     BL1, BL2, TRNS,TRNS,     BL3, BL4, BL5, BL6, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        CL1, TG1, TG2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     PWR, TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,     TRNS,TRNS,TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
        backlight_set_step(id);
    }
}

void hook_layer_change(uint32_t layer_state)
{
    if (layer_state & (1L << LAYER_GAMING)) {
        backlight_state_led |= 1 << STATE_LED_LAYER_1;
    } else {
        backlight_state_led &= ~(1 << STATE_LED_LAYER_1);
    }

    if (layer_state & (1L << LAYER_NAV)) {
        backlight_state_led |= 1 << STATE_LED_LAYER_2;
    } else {
        backlight_state_led &= ~(1 << STATE_LED_LAYER_2);
    }

    backlight_update_state_led();
}
