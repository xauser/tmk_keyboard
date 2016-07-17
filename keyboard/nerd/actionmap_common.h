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

#ifndef ACTIONMAP_COMMON_H
#define ACTIONMAP_COMMON_H

#include <stdint.h>
#include "action.h"

#define ACTIONMAP_80( \
        K08,      K09, K18, K19, K28, K29, K38, K39, K48, K49, K58, K59, K68,    K69, K88, K89, \
        K00, K01, K10, K11, K20, K21, K30, K31, K40, K41, K50, K51, K60, K61,    K80, K81, K84, \
        K02, K03, K12, K13, K22, K23, K32, K33, K42, K43, K52, K53, K62, K63,    K82, K83, K85, \
        K04, K14, K15, K24, K25, K34, K35, K44, K45, K54, K55, K64, K71, K65,                   \
        K07, K79, K16, K17, K26, K27, K36, K37, K46, K47, K56, K57, K66, K67,         K86,      \
        K06, K05, K78,                K70,                K72, K73, K74, K75,    K76, K77, K87  \
) { \
      { AC_##K00, AC_##K01, AC_##K02, AC_##K03, AC_##K04, AC_##K05, AC_##K06, AC_##K07, AC_##K08, AC_##K09 }, \
      { AC_##K10, AC_##K11, AC_##K12, AC_##K13, AC_##K14, AC_##K15, AC_##K16, AC_##K17, AC_##K18, AC_##K19 }, \
      { AC_##K20, AC_##K21, AC_##K22, AC_##K23, AC_##K24, AC_##K25, AC_##K26, AC_##K27, AC_##K28, AC_##K29 }, \
      { AC_##K30, AC_##K31, AC_##K32, AC_##K33, AC_##K34, AC_##K35, AC_##K36, AC_##K37, AC_##K38, AC_##K39 }, \
      { AC_##K40, AC_##K41, AC_##K42, AC_##K43, AC_##K44, AC_##K45, AC_##K46, AC_##K47, AC_##K48, AC_##K49 }, \
      { AC_##K50, AC_##K51, AC_##K52, AC_##K53, AC_##K54, AC_##K55, AC_##K56, AC_##K57, AC_##K58, AC_##K59 }, \
      { AC_##K60, AC_##K61, AC_##K62, AC_##K63, AC_##K64, AC_##K65, AC_##K66, AC_##K67, AC_##K68, AC_##K69 }, \
      { AC_##K70, AC_##K71, AC_##K72, AC_##K73, AC_##K74, AC_##K75, AC_##K76, AC_##K77, AC_##K78, AC_##K79 }, \
      { AC_##K80, AC_##K81, AC_##K82, AC_##K83, AC_##K84, AC_##K85, AC_##K86, AC_##K87, AC_##K88, AC_##K89 }  \
}

#define ACTIONMAP_60( \
        K08, K01, K10, K11, K20, K21, K30, K31, K40, K41, K50, K51, K60, K61, \
        K02, K03, K12, K13, K22, K23, K32, K33, K42, K43, K52, K53, K62, K63, \
        K04, K14, K15, K24, K25, K34, K35, K44, K45, K54, K55, K64, K71, K65, \
        K07, K79, K16, K17, K26, K27, K36, K37, K46, K47, K56, K57, K66, K67, \
        K06, K05, K78,                K70,                K72, K73, K74, K75  \
) ACTIONMAP_80( \
        K08,      NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   NO,  NO,  NO,  \
        NO,  K01, K10, K11, K20, K21, K30, K31, K40, K41, K50, K51, K60, K61,  NO,  NO,  NO,  \
        K02, K03, K12, K13, K22, K23, K32, K33, K42, K43, K52, K53, K62, K63,  NO,  NO,  NO,  \
        K04, K14, K15, K24, K25, K34, K35, K44, K45, K54, K55, K64, K71, K65,                 \
        K07, K79, K16, K17, K26, K27, K36, K37, K46, K47, K56, K57, K66, K67,       NO,       \
        K06, K05, K78,                K70,                K72, K73, K74, K75,  NO,  NO,  NO   \
)

#endif // ACTIONMAP_COMMON_H
