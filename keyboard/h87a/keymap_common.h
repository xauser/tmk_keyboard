/*
Copyright 2020 Ralf Schmitt <ralf@bunkertor.net>

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

#define KEYMAP(\
    K11A,       K11B, K10B, K11C, K10C, K11D, K10D, K11E, K10E,       K10F, K11G, K10G, K11H,    K10H, K11I, K10I,  \
    K09A, K08A, K09B, K08B, K09C, K08C, K09D, K08D, K09E, K08E, K09F, K08F, K09G, K08G, K09H,    K08H, K09I, K08I,  \
    K07A, K06A, K07B, K06B, K07C, K06C, K07D, K06D, K07E, K06E, K07F, K06F, K07G, K06G,          K06H, K07I, K06I,  \
    K05A, K04A, K05B, K04B, K05C, K04C, K05D, K04D, K05E, K04E, K05F, K04F, K05G, K04G,                             \
    K03A, K02A, K03B, K02B, K03C, K02C, K03D, K02D, K03E, K02E, K03F, K02F, K03G, K02G,                K03I,        \
    K01A, K00A, K01B,                   K00D,                   K01F, K00F, K01G, K00G,          K00H, K01I, K00I   \
    ) { \
  { KC_##K11A, KC_##K11B, KC_##K11C, KC_##K11D, KC_##K11E, KC_NO,     KC_##K11G, KC_##K11H, KC_##K11I }, \
  { KC_NO,     KC_##K10B, KC_##K10C, KC_##K10D, KC_##K10E, KC_##K10F, KC_##K10G, KC_##K10H, KC_##K10I }, \
  { KC_##K09A, KC_##K09B, KC_##K09C, KC_##K09D, KC_##K09E, KC_##K09F, KC_##K09G, KC_##K09H, KC_##K09I }, \
  { KC_##K08A, KC_##K08B, KC_##K08C, KC_##K08D, KC_##K08E, KC_##K08F, KC_##K08G, KC_##K08H, KC_##K08I }, \
  { KC_##K07A, KC_##K07B, KC_##K07C, KC_##K07D, KC_##K07E, KC_##K07F, KC_##K07G, KC_NO,     KC_##K07I }, \
  { KC_##K06A, KC_##K06B, KC_##K06C, KC_##K06D, KC_##K06E, KC_##K06F, KC_##K06G, KC_##K06H, KC_##K06I }, \
  { KC_##K05A, KC_##K05B, KC_##K05C, KC_##K05D, KC_##K05E, KC_##K05F, KC_##K05G, KC_NO,     KC_NO },     \
  { KC_##K04A, KC_##K04B, KC_##K04C, KC_##K04D, KC_##K04E, KC_##K04F, KC_##K04G, KC_NO,     KC_NO },     \
  { KC_##K03A, KC_##K03B, KC_##K03C, KC_##K03D, KC_##K03E, KC_##K03F, KC_##K03G, KC_NO,     KC_##K03I }, \
  { KC_##K02A, KC_##K02B, KC_##K02C, KC_##K02D, KC_##K02E, KC_##K02F, KC_##K02G, KC_NO,     KC_NO },     \
  { KC_##K01A, KC_##K01B, KC_NO,     KC_NO,     KC_NO,     KC_##K01F, KC_##K01G, KC_NO,     KC_##K01I }, \
  { KC_##K00A, KC_NO,     KC_NO,     KC_##K00D, KC_NO,     KC_##K00F, KC_##K00G, KC_##K00H, KC_##K00I }  \
}

#endif // KEYMAP_COMMON_H
