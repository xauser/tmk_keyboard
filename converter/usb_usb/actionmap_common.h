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

/*         ,---------------. ,---------------. ,---------------.
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
 * |-----------------------------------------------------------| |-----------| |---------------| |-------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 * |-----------------------------------------------------------| `-----------' |---------------| |-------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
 * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
 * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
 * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
 * `-----------------------------------------------------------' `-----------' `---------------' `-------'
 *
 *
 * App:         Windows Menu key
 * Gui:         Windows key, Mac ⌘ key or Meta key
 *
 * Pwr:         Power for Unix and Mac
 * VDn,Vup,Mut: Volume control for Unix and Mac
 * Stp,Agn..:   for Unix
 *
 * KP,:         Brazilian Keypad Comma
 * KP=:         Keypad = for Mac
 * <,#:         ISO keys(UK legend)
 * JPY:         Japanese Yen(￥)
 * RO:          Japanese ろ or Brazilian /
 * MHEN:        Japanese 無変換 Non Conversion
 * HENK:        Japanese 変換 Conversion
 * KANA:        Japanese かな Hiragana/Katakana
 *              https://en.wikipedia.org/wiki/Keyboard_layout#Japanese
 * H/E:         Korean 한/영 Hangul/English
 * HNJ:         Korean 한자 Hanja
 *              https://en.wikipedia.org/wiki/Keyboard_layout#Hangul_.28for_Korean.29
 *
 * TODO: use same keycode to pass through instead of AC_NO?
 */
#define ACTIONMAP_ALL( \
            K68,K69,K6A,K6B,K6C,K6D,K6E,K6F,K70,K71,K72,K73,                                              \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  K81,K80,K7F,K66, K75,     \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, K78,K79, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  K5F,K60,K61,K57, K76,K7A, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K32,K28,                K5C,K5D,K5E,K85, K77,K7C, \
    KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    K87,KE5,      K52,      K59,K5A,K5B,K67, K74,K7D, \
    KE0,KE3,KE2,K8B,K91,    K2C,    K90,K8A,K88,KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, K7E,K7B  \
) { \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_##K04, AC_##K05, AC_##K06, AC_##K07,   /* 00-07 */ \
      AC_##K08, AC_##K09, AC_##K0A, AC_##K0B, AC_##K0C, AC_##K0D, AC_##K0E, AC_##K0F }, /* 08-0F */ \
    { AC_##K10, AC_##K11, AC_##K12, AC_##K13, AC_##K14, AC_##K15, AC_##K16, AC_##K17,   /* 10-17 */ \
      AC_##K18, AC_##K19, AC_##K1A, AC_##K1B, AC_##K1C, AC_##K1D, AC_##K1E, AC_##K1F }, /* 18-1F */ \
    { AC_##K20, AC_##K21, AC_##K22, AC_##K23, AC_##K24, AC_##K25, AC_##K26, AC_##K27,   /* 20-27 */ \
      AC_##K28, AC_##K29, AC_##K2A, AC_##K2B, AC_##K2C, AC_##K2D, AC_##K2E, AC_##K2F }, /* 28-2F */ \
    { AC_##K30, AC_##K31, AC_##K32, AC_##K33, AC_##K34, AC_##K35, AC_##K36, AC_##K37,   /* 30-37 */ \
      AC_##K38, AC_##K39, AC_##K3A, AC_##K3B, AC_##K3C, AC_##K3D, AC_##K3E, AC_##K3F }, /* 38-3F */ \
    { AC_##K40, AC_##K41, AC_##K42, AC_##K43, AC_##K44, AC_##K45, AC_##K46, AC_##K47,   /* 40-47 */ \
      AC_##K48, AC_##K49, AC_##K4A, AC_##K4B, AC_##K4C, AC_##K4D, AC_##K4E, AC_##K4F }, /* 48-4F */ \
    { AC_##K50, AC_##K51, AC_##K52, AC_##K53, AC_##K54, AC_##K55, AC_##K56, AC_##K57,   /* 50-57 */ \
      AC_##K58, AC_##K59, AC_##K5A, AC_##K5B, AC_##K5C, AC_##K5D, AC_##K5E, AC_##K5F }, /* 58-5F */ \
    { AC_##K60, AC_##K61, AC_##K62, AC_##K63, AC_##K64, AC_##K65, AC_##K66, AC_##K67,   /* 60-67 */ \
      AC_##K68, AC_##K69, AC_##K6A, AC_##K6B, AC_##K6C, AC_##K6D, AC_##K6E, AC_##K6F }, /* 68-6F */ \
    { AC_##K70, AC_##K71, AC_##K72, AC_##K73, AC_##K74, AC_##K75, AC_##K76, AC_##K77,   /* 70-77 */ \
      AC_##K78, AC_##K79, AC_##K7A, AC_##K7B, AC_##K7C, AC_##K7D, AC_##K7E, AC_##K7F }, /* 78-7F */ \
    { AC_##K80, AC_##K81, AC_NO,    AC_NO,    AC_NO,    AC_##K85, AC_NO,    AC_##K87,   /* 80-87 */ \
      AC_##K88, AC_##K89, AC_##K8A, AC_##K8B, AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* 88-8F */ \
    { AC_##K90, AC_##K91, AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* 90-97 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* 98-9F */ \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* A0-A7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* A8-AF */ \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* B0-B7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* B8-BF */ \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* C0-C7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* C8-CF */ \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* D0-D7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* D8-DF */ \
    { AC_##KE0, AC_##KE1, AC_##KE2, AC_##KE3, AC_##KE4, AC_##KE5, AC_##KE6, AC_##KE7,   /* E0-E7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* E8-EF */ \
    { AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,      /* F0-F7 */ \
      AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO,    AC_NO    }, /* F8-FF */ \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define ACTIONMAP( \
    K29,K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31,  K4C,K4D,K4E,  K5F,K60,K61,     \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28,                K5C,K5D,K5E,K57, \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        KE5,      K52,      K59,K5A,K5B,     \
    KE0,KE3,KE2,        K2C,                KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58  \
) ACTIONMAP_ALL( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  NO, NO, NO, NO,  NO,      \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  K49,K4A,K4B,  K53,K54,K55,K56, NO, NO,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  K5F,K60,K61,K57, NO, NO,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO, K28,                K5C,K5D,K5E,NO,  NO, NO,  \
    KE1,NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, KE5,      K52,      K59,K5A,K5B,NO,  NO, NO,  \
    KE0,KE3,KE2,NO, NO,     K2C,    NO, NO, NO, KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, NO, NO   \
)

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define ACTIONMAP_ISO( \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,  K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K28,  K4C,K4D,K4E,  K5F,K60,K61,K57, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,K32,                    K5C,K5D,K5E,     \
    KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    KE5,      K52,      K59,K5A,K5B,K58, \
    KE0,KE3,KE2,        K2C,                KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63      \
) ACTIONMAP_ALL( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  NO, NO, NO, NO,  NO,      \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  K49,K4A,K4B,  K53,K54,K55,K56, NO, NO,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K32,  K4C,K4D,K4E,  K5F,K60,K61,K57, NO, NO,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K32,K28,                K5C,K5D,K5E,NO,  NO, NO,  \
    KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, KE5,      K52,      K59,K5A,K5B,NO,  NO, NO,  \
    KE0,KE3,KE2,NO, NO,     K2C,    NO, NO, NO, KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, NO, NO   \
)

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  ^|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  @|  [| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  ]|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft    |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|MHEN|      Space      |HENK|KNA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define ACTIONMAP_JIS( \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K28,  K4C,K4D,K4E,  K5F,K60,K61,K57, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,K32,                        K5C,K5D,K5E,     \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        K87,KE5,      K52,      K59,K5A,K5B,K58, \
    KE0,KE3,KE2,K8B,    K2C,        K8A,K88,KE6,KE7,K65,KE4,      K50,K51,K4F,  K62,    K63      \
) ACTIONMAP_ALL( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  NO, NO, NO, NO,  NO,      \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, NO, NO,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K32,  K4C,K4D,K4E,  K5F,K60,K61,K57, NO, NO,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K32,K28,                K5C,K5D,K5E,NO,  NO, NO,  \
    KE1,NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    K87,KE5,      K52,      K59,K5A,K5B,NO,  NO, NO,  \
    KE0,KE3,KE2,K8B,NO,     K2C,    NO, K8A,K88,KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, NO, NO   \
)

#endif
