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
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4O, K4P, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3O, K3P, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2O, K2P, \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1O, K1P, \
    K0A, K0B, K0C,                K0G,           K0J, K0K,      K0M, K0O, K0P  \
) { \
  { AC_##K4A, AC_##K4B, AC_##K4C, AC_##K4D, AC_##K4E, AC_##K4F, AC_##K4G, AC_##K4H, AC_##K4I, AC_##K4J, AC_##K4K, AC_##K4L, AC_##K4M, AC_NO,    AC_##K4O, AC_##K4P }, \
  { AC_##K3A, AC_##K3B, AC_##K3C, AC_##K3D, AC_##K3E, AC_##K3F, AC_##K3G, AC_##K3H, AC_##K3I, AC_##K3J, AC_##K3K, AC_##K3L, AC_##K3M, AC_NO,    AC_##K3O, AC_##K3P }, \
  { AC_##K2A, AC_##K2B, AC_##K2C, AC_##K2D, AC_##K2E, AC_##K2F, AC_##K2G, AC_##K2H, AC_##K2I, AC_##K2J, AC_##K2K, AC_##K2L, AC_##K2M, AC_NO,    AC_##K2O, AC_##K2P }, \
  { AC_##K1A, AC_##K1B, AC_##K1C, AC_##K1D, AC_##K1E, AC_##K1F, AC_##K1G, AC_##K1H, AC_##K1I, AC_##K1J, AC_##K1K, AC_##K1L, AC_##K1M, AC_NO,    AC_##K1O, AC_##K1P }, \
  { AC_##K0A, AC_##K0B, AC_##K0C, AC_NO,    AC_NO,    AC_NO,    AC_##K0G, AC_NO,    AC_##K0J, AC_##K0J, AC_##K0K, AC_NO,    AC_##K0M, AC_NO,    AC_##K0O, AC_##K0P }  \
}

#endif // ACTIONMAP_COMMON_H
