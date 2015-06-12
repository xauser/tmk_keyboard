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

#ifndef ACTIONMAP_COMMON_H
#define ACTIONMAP_COMMON_H

#include "actionmap.h"

#define ACTIONMAP( \
    KG6,      KH4, KI4, KI2, KI6, KP5, KL6, KM2, KM4, KO4, KO5, KO6, KO0,   KN5, KN7, KP7,                       \
    KG4, KG5, KH5, KI5, KJ5, KJ4, KK4, KK5, KL5, KM5, KF5, KF4, KL4, KO2,   KR4, KC4, KE4,   KQ1, KR1, KE1, KE0, \
    KG2, KG7, KH7, KI7, KJ7, KJ2, KK2, KK7, KL7, KM7, KF7, KF2, KL2, KO3,   KQ4, KC5, KE5,   KQ7, KR7, KE7, KC7, \
    KH2, KG3, KH3, KI3, KJ3, KJ6, KK6, KK3, KL3, KM3, KF3, KF6,      KO1,                    KQ2, KR2, KE2,      \
    KB2,      KG1, KH1, KI1, KJ1, KJ0, KK0, KK1, KL1, KM1, KF0,      KB3,        KC6,        KQ3, KR3, KE3, KC3, \
    KP4, KD2, KN6,                KQ6,                KN0, KA3, KM0, KP1,   KC0, KQ0, KR0,   KR6,      KE6       \
) { \
/*           A0        B1        C2        D3        E4        F5        G6        H7        I8        J9        K10       L11       M12       N13       O14       P15       Q16       R17 */  \
/*  0 */ {AC_NO,    AC_NO,    AC_##KC0, AC_NO,    AC_##KE0, AC_##KF0, AC_NO,    AC_NO,    AC_NO,    AC_##KJ0, AC_##KK0, AC_NO,    AC_##KM0, AC_##KN0, AC_##KO0, AC_NO,    AC_##KQ0, AC_##KR0},  \
/*  1 */ {AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_##KE1, AC_NO,    AC_##KG1, AC_##KH1, AC_##KI1, AC_##KJ1, AC_##KK1, AC_##KL1, AC_##KM1, AC_NO,    AC_##KO1, AC_##KP1, AC_##KQ1, AC_##KR1},  \
/*  2 */ {AC_NO,    AC_##KB2, AC_NO,    AC_##KD2, AC_##KE2, AC_##KF2, AC_##KG2, AC_##KH2, AC_##KI2, AC_##KJ2, AC_##KK2, AC_##KL2, AC_##KM2, AC_NO,    AC_##KO2, AC_NO,    AC_##KQ2, AC_##KR2},  \
/*  3 */ {AC_##KA3, AC_##KB3, AC_##KC3, AC_NO,    AC_##KE3, AC_##KF3, AC_##KG3, AC_##KH3, AC_##KI3, AC_##KJ3, AC_##KK3, AC_##KL3, AC_##KM3, AC_NO,    AC_##KO3, AC_NO,    AC_##KQ3, AC_##KR3},  \
/*  4 */ {AC_NO,    AC_NO,    AC_##KC4, AC_NO,    AC_##KE4, AC_##KF4, AC_##KG4, AC_##KH4, AC_##KI4, AC_##KJ4, AC_##KK4, AC_##KL4, AC_##KM4, AC_NO,    AC_##KO4, AC_##KP4, AC_##KQ4, AC_##KR4},  \
/*  5 */ {AC_NO,    AC_NO,    AC_##KC5, AC_NO,    AC_##KE5, AC_##KF5, AC_##KG5, AC_##KH5, AC_##KI5, AC_##KJ5, AC_##KK5, AC_##KL5, AC_##KM5, AC_##KN5, AC_##KO5, AC_##KP5, AC_NO,    AC_NO},  \
/*  6 */ {AC_NO,    AC_NO,    AC_##KC6, AC_NO,    AC_##KE6, AC_##KF6, AC_##KG6, AC_NO,    AC_##KI6, AC_##KJ6, AC_##KK6, AC_##KL6, AC_NO,    AC_##KN6, AC_##KO6, AC_NO,    AC_##KQ6, AC_##KR6},  \
/*  7 */ {AC_NO,    AC_NO,    AC_##KC7, AC_NO,    AC_##KE7, AC_##KF7, AC_##KG7, AC_##KH7, AC_##KI7, AC_##KJ7, AC_##KK7, AC_##KL7, AC_##KM7, AC_##KN7, AC_NO,    AC_##KP7, AC_##KQ7, AC_##KR7}   \
}

#endif // ACTIONMAP_COMMON_H

