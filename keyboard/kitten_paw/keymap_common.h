/*
Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

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

#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include "action.h"

#define KEYMAP( \
    KG6,      KH4, KI4, KI2, KI6, KP5, KL6, KM2, KM4, KO4, KO5, KO6, KO0,   KN5, KN7, KP7,                       \
    KG4, KG5, KH5, KI5, KJ5, KJ4, KK4, KK5, KL5, KM5, KF5, KF4, KL4, KO2,   KR4, KC4, KE4,   KQ1, KR1, KE1, KE0, \
    KG2, KG7, KH7, KI7, KJ7, KJ2, KK2, KK7, KL7, KM7, KF7, KF2, KL2, KO3,   KQ4, KC5, KE5,   KQ7, KR7, KE7, KC7, \
    KH2, KG3, KH3, KI3, KJ3, KJ6, KK6, KK3, KL3, KM3, KF3, KF6,      KO1,                    KQ2, KR2, KE2,      \
    KB2,      KG1, KH1, KI1, KJ1, KJ0, KK0, KK1, KL1, KM1, KF0,      KB3,        KC6,        KQ3, KR3, KE3, KC3, \
    KP4, KD2, KN6,                KQ6,                KN0, KA3, KM0, KP1,   KC0, KQ0, KR0,   KR6,      KE6       \
) { \
/*           A0        B1        C2        D3        E4        F5        G6        H7        I8        J9        K10       L11       M12       N13       O14       P15       Q16       R17 */  \
/*  0 */ {KC_NO,    KC_NO,    KC_##KC0, KC_NO,    KC_##KE0, KC_##KF0, KC_NO,    KC_NO,    KC_NO,    KC_##KJ0, KC_##KK0, KC_NO,    KC_##KM0, KC_##KN0, KC_##KO0, KC_NO,    KC_##KQ0, KC_##KR0},  \
/*  1 */ {KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##KE1, KC_NO,    KC_##KG1, KC_##KH1, KC_##KI1, KC_##KJ1, KC_##KK1, KC_##KL1, KC_##KM1, KC_NO,    KC_##KO1, KC_##KP1, KC_##KQ1, KC_##KR1},  \
/*  2 */ {KC_NO,    KC_##KB2, KC_NO,    KC_##KD2, KC_##KE2, KC_##KF2, KC_##KG2, KC_##KH2, KC_##KI2, KC_##KJ2, KC_##KK2, KC_##KL2, KC_##KM2, KC_NO,    KC_##KO2, KC_NO,    KC_##KQ2, KC_##KR2},  \
/*  3 */ {KC_##KA3, KC_##KB3, KC_##KC3, KC_NO,    KC_##KE3, KC_##KF3, KC_##KG3, KC_##KH3, KC_##KI3, KC_##KJ3, KC_##KK3, KC_##KL3, KC_##KM3, KC_NO,    KC_##KO3, KC_NO,    KC_##KQ3, KC_##KR3},  \
/*  4 */ {KC_NO,    KC_NO,    KC_##KC4, KC_NO,    KC_##KE4, KC_##KF4, KC_##KG4, KC_##KH4, KC_##KI4, KC_##KJ4, KC_##KK4, KC_##KL4, KC_##KM4, KC_NO,    KC_##KO4, KC_##KP4, KC_##KQ4, KC_##KR4},  \
/*  5 */ {KC_NO,    KC_NO,    KC_##KC5, KC_NO,    KC_##KE5, KC_##KF5, KC_##KG5, KC_##KH5, KC_##KI5, KC_##KJ5, KC_##KK5, KC_##KL5, KC_##KM5, KC_##KN5, KC_##KO5, KC_##KP5, KC_NO,    KC_NO},  \
/*  6 */ {KC_NO,    KC_NO,    KC_##KC6, KC_NO,    KC_##KE6, KC_##KF6, KC_##KG6, KC_NO,    KC_##KI6, KC_##KJ6, KC_##KK6, KC_##KL6, KC_NO,    KC_##KN6, KC_##KO6, KC_NO,    KC_##KQ6, KC_##KR6},  \
/*  7 */ {KC_NO,    KC_NO,    KC_##KC7, KC_NO,    KC_##KE7, KC_##KF7, KC_##KG7, KC_##KH7, KC_##KI7, KC_##KJ7, KC_##KK7, KC_##KL7, KC_##KM7, KC_##KN7, KC_NO,    KC_##KP7, KC_##KQ7, KC_##KR7}   \
}

#endif // KEYMAP_COMMON_H
