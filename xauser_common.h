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
#ifndef XAUSER_COMMON_H
#define XAUSER_COMMON_H

// To change a mapping recursively for all keymaps with ripgrep, xargs and sed
//
// grep -l0 TP1 . | xargs -0 sed -i 's/TP1/TP2/g'

// Layer
#define LAYER_BASE 0
#define LAYER_GAMING 1
#define LAYER_NAV 2
#define LAYER_FUNCTION 3
#define LAYER_TOGGLE 4

// Layer tap
#define AC_TP1 ACTION_LAYER_TAP_KEY(LAYER_FUNCTION, KC_SPACE) // Hold for momentary function layer, tap for space
#define AC_TP2 ACTION_LAYER_TAP_KEY(LAYER_TOGGLE, KC_ENT)     // Hold for momentary toggle layer, tap for enter
#define AC_TP3 ACTION_LAYER_TAP_KEY(LAYER_NAV, KC_ESC)        // Hold for monentary nav layer, tap for esc
#define AC_TP4 ACTION_LAYER_TAP_KEY(LAYER_FUNCTION, KC_BSPC)  // Hold for momentary function layer, tap for backspace

// Layer momentary
#define AC_MM1 ACTION_LAYER_MOMENTARY(LAYER_FUNCTION) // Momentary function layer
#define AC_MM2 ACTION_LAYER_MOMENTARY(LAYER_NAV)      // Momentary nav layer
#define AC_MM3 ACTION_LAYER_MOMENTARY(LAYER_TOGGLE)   // Momentary toggle layer

// Layer clear
#define AC_CL1 ACTION_LAYER_SET_CLEAR(LAYER_BASE) // Reset to base layer

// Layer toggle
#define AC_TG1 ACTION_LAYER_TOGGLE(LAYER_NAV)    // Toggle nav layer
#define AC_TG2 ACTION_LAYER_TOGGLE(LAYER_GAMING) // Toggle gaming layer

// Shifted keys
#define AC_EXLM ACTION_MODS_KEY(MOD_LSFT, KC_1)    // !
#define AC_AT   ACTION_MODS_KEY(MOD_LSFT, KC_2)    // @
#define AC_HASH ACTION_MODS_KEY(MOD_LSFT, KC_3)    // #
#define AC_DLR  ACTION_MODS_KEY(MOD_LSFT, KC_4)    // $
#define AC_PERC ACTION_MODS_KEY(MOD_LSFT, KC_5)    // %
#define AC_CIRC ACTION_MODS_KEY(MOD_LSFT, KC_6)    // ^
#define AC_AMPR ACTION_MODS_KEY(MOD_LSFT, KC_7)    // &
#define AC_ASTR ACTION_MODS_KEY(MOD_LSFT, KC_8)    // *
#define AC_LPRN ACTION_MODS_KEY(MOD_LSFT, KC_9)    // (
#define AC_RPRN ACTION_MODS_KEY(MOD_LSFT, KC_0)    // )
#define AC_LCBR ACTION_MODS_KEY(MOD_LSFT, KC_LBRC) // {
#define AC_RCBR ACTION_MODS_KEY(MOD_LSFT, KC_RBRC) // }
#define AC_TILD ACTION_MODS_KEY(MOD_LSFT, KC_GRV)  // ~
#define AC_PIPE ACTION_MODS_KEY(MOD_LSFT, KC_BSLS) // |
#define AC_PLUS ACTION_MODS_KEY(MOD_LSFT, KC_EQL)  // +
#define AC_UNDS ACTION_MODS_KEY(MOD_LSFT, KC_MINS) // _

// Modifier combinations
#define AC_HK1 ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_J) // Switch to monitor on the left
#define AC_HK2 ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_K) // Switch to monitor on the right
#define AC_HK3 ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_M) // Ctrl+Shift+M mute microphone
#define AC_HK4 ACTION_MODS_KEY(MOD_LCTL, KC_P) // crtl-p
#define AC_HK5 ACTION_MODS_KEY(MOD_LCTL, KC_N) // crtl-n

#endif // XAUSER_COMMON_H
