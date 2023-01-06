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

#define ACTIONMAP(\
    K11A,       K11B, K10B, K11C, K10C, K11D, K10D, K11E, K10E,       K10F, K11G, K10G, K11H,    K10H, K11I, K10I,  \
    K09A, K08A, K09B, K08B, K09C, K08C, K09D, K08D, K09E, K08E, K09F, K08F, K09G, K08G, K09H,    K08H, K09I, K08I,  \
    K07A, K06A, K07B, K06B, K07C, K06C, K07D, K06D, K07E, K06E, K07F, K06F, K07G, K06G,          K06H, K07I, K06I,  \
    K05A, K04A, K05B, K04B, K05C, K04C, K05D, K04D, K05E, K04E, K05F, K04F, K05G, K04G,                             \
    K03A, K02A, K03B, K02B, K03C, K02C, K03D, K02D, K03E, K02E, K03F, K02F, K03G, K02G,                K03I,        \
    K01A, K00A, K01B,                   K00D,                   K01F, K00F, K01G, K00G,          K00H, K01I, K00I   \
    ) { \
  { AC_##K11A, AC_##K11B, AC_##K11C, AC_##K11D, AC_##K11E, AC_NO,     AC_##K11G, AC_##K11H, AC_##K11I }, \
  { AC_NO,     AC_##K10B, AC_##K10C, AC_##K10D, AC_##K10E, AC_##K10F, AC_##K10G, AC_##K10H, AC_##K10I }, \
  { AC_##K09A, AC_##K09B, AC_##K09C, AC_##K09D, AC_##K09E, AC_##K09F, AC_##K09G, AC_##K09H, AC_##K09I }, \
  { AC_##K08A, AC_##K08B, AC_##K08C, AC_##K08D, AC_##K08E, AC_##K08F, AC_##K08G, AC_##K08H, AC_##K08I }, \
  { AC_##K07A, AC_##K07B, AC_##K07C, AC_##K07D, AC_##K07E, AC_##K07F, AC_##K07G, AC_NO,     AC_##K07I }, \
  { AC_##K06A, AC_##K06B, AC_##K06C, AC_##K06D, AC_##K06E, AC_##K06F, AC_##K06G, AC_##K06H, AC_##K06I }, \
  { AC_##K05A, AC_##K05B, AC_##K05C, AC_##K05D, AC_##K05E, AC_##K05F, AC_##K05G, AC_NO,     AC_NO },     \
  { AC_##K04A, AC_##K04B, AC_##K04C, AC_##K04D, AC_##K04E, AC_##K04F, AC_##K04G, AC_NO,     AC_NO },     \
  { AC_##K03A, AC_##K03B, AC_##K03C, AC_##K03D, AC_##K03E, AC_##K03F, AC_##K03G, AC_NO,     AC_##K03I }, \
  { AC_##K02A, AC_##K02B, AC_##K02C, AC_##K02D, AC_##K02E, AC_##K02F, AC_##K02G, AC_NO,     AC_NO },     \
  { AC_##K01A, AC_##K01B, AC_NO,     AC_NO,     AC_NO,     AC_##K01F, AC_##K01G, AC_NO,     AC_##K01I }, \
  { AC_##K00A, AC_NO,     AC_NO,     AC_##K00D, AC_NO,     AC_##K00F, AC_##K00G, AC_##K00H, AC_##K00I }  \
}

#endif // ACTIONMAP_COMMON_H
