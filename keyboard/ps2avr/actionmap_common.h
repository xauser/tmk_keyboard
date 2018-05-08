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

#include <stdint.h>
#include "action.h"
#include "actionmap.h"

#define ACTIONMAP_B87( \
    K05,      K25, K35, K45, K55, K06, KA6, KA7, K07, KB5, KC5, KD5, KE5,   KD1, KE1, KE2,   K65, K75, K85, K95, \
    K04, K14, K24, K34, K44, K54, K16, KB6, KB7, K17, KA4, KB4, KC4, KE4,   KD0, KE0, K97,   K64, K74, K84, K94, \
    K03, K13, K23, K33, K43, K53, K26, KC6, KC7, K27, KA3, KB3, KC3, KD3,   K67, K77, K87,   K63, K73, K83, K92, \
    K02, K12, K22, K32, K42, K52, K36, KD6, KD7, K37, KA2, KB2,      KD2,                    K62, K72, K82,      \
    K01,      K11, K21, K31, K41, K51, K46, KE6, KE7, K47, KA1,      KB1,        K86,        K61, K71, K81, K90, \
    K00, K10, K20,                K56,                     K57, KB0, KC0,   K66, K76, K96,   K60,      K80       \
) \
{ \
    { AC_##K00, AC_##K10, AC_##K20, AC_NO,    AC_NO,    AC_NO,    AC_##K60, AC_NO,    AC_##K80, AC_##K90, AC_NO,    AC_##KB0, AC_##KC0, AC_##KD0, AC_##KE0 }, \
    { AC_##K01, AC_##K11, AC_##K21, AC_##K31, AC_##K41, AC_##K51, AC_##K61, AC_##K71, AC_##K81, AC_NO,    AC_##KA1, AC_##KB1, AC_NO,    AC_##KD1, AC_##KE1 }, \
    { AC_##K02, AC_##K12, AC_##K22, AC_##K32, AC_##K42, AC_##K52, AC_##K62, AC_##K72, AC_##K82, AC_##K92, AC_##KA2, AC_##KB2, AC_NO,    AC_##KD2, AC_##KE2 }, \
    { AC_##K03, AC_##K13, AC_##K23, AC_##K33, AC_##K43, AC_##K53, AC_##K63, AC_##K73, AC_##K83, AC_NO,    AC_##KA3, AC_##KB3, AC_##KC3, AC_##KD3, AC_NO    }, \
    { AC_##K04, AC_##K14, AC_##K24, AC_##K34, AC_##K44, AC_##K54, AC_##K64, AC_##K74, AC_##K84, AC_##K94, AC_##KA4, AC_##KB4, AC_##KC4, AC_NO,    AC_##KE4 }, \
    { AC_##K05, AC_NO,    AC_##K25, AC_##K35, AC_##K45, AC_##K55, AC_##K65, AC_##K75, AC_##K85, AC_##K95, AC_NO,    AC_##KB5, AC_##KC5, AC_##KD5, AC_##KE5 }, \
    { AC_##K06, AC_##K16, AC_##K26, AC_##K36, AC_##K46, AC_##K56, AC_##K66, AC_##K76, AC_##K86, AC_##K96, AC_##KA6, AC_##KB6, AC_##KC6, AC_##KD6, AC_##KE6 }, \
    { AC_##K07, AC_##K17, AC_##K27, AC_##K37, AC_##K47, AC_##K57, AC_##K67, AC_##K77, AC_##K87, AC_##K97, AC_##KA7, AC_##KB7, AC_##KC7, AC_##KD7, AC_##KE7 }  \
}

#endif // ACTIONMAP_COMMON_H
