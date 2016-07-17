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

// Convert physical keyboard layout to matrix array.
// This is a macro to define keymap easily in keyboard layout form.
#define ACTIONMAP( \
    K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N, K4O, K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      K2P, K2Q, K2R, \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N,      K1P, K1Q, K1R, \
    K0A, K0B, K0C, K0D,      K0F, K0G, K0H,           K0K, K0L, K0M, K0N,      K0P, K0Q, K0R  \
) { \
/*             0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15        16   */  \
/* 5 */   { AC_##K5A, AC_##K4A, AC_##K5C, AC_##K5D, AC_##K5E, AC_##K5F, AC_##K5H, AC_##K5I, AC_##K5J, AC_##K5K, AC_##K5L, AC_##K5M, AC_##K5N, AC_##K5O, AC_##K5P, AC_##K5Q, AC_##K5R}, \
/* 4 */   { AC_##K4B, AC_##K4C, AC_##K4D, AC_##K4E, AC_##K4F, AC_##K4G, AC_##K4H, AC_##K4I, AC_##K4J, AC_##K4K, AC_##K4L, AC_##K4M, AC_##K4N, AC_##K4O, AC_##K4P, AC_##K4Q, AC_##K4R}, \
/* 3 */   { AC_##K3A, AC_##K3B, AC_##K3C, AC_##K3D, AC_##K3E, AC_##K3F, AC_##K3G, AC_##K3H, AC_##K3I, AC_##K3J, AC_##K3K, AC_##K3L, AC_##K3M, AC_##K3N, AC_##K3P, AC_##K3Q, AC_##K3R}, \
/* 2 */   { AC_##K2A, AC_##K2B, AC_##K2C, AC_##K2D, AC_##K2E, AC_##K2F, AC_##K2G, AC_##K2H, AC_##K2I, AC_##K2J, AC_##K2K, AC_##K2L, AC_##K2M, AC_##K2N, AC_##K2P, AC_##K2Q, AC_##K2R}, \
/* 1 */   { AC_##K1A, AC_##K1B, AC_##K1C, AC_##K1D, AC_##K1E, AC_##K1F, AC_##K1G, AC_##K1H, AC_##K1I, AC_##K1J, AC_##K1K, AC_##K1L, AC_##K1M, AC_##K1N, AC_##K1P, AC_##K1Q, AC_##K1R}, \
/* 0 */   { AC_##K0A, AC_##K0B, AC_##K0C, AC_##K5B, AC_##K0D, AC_##K0F, AC_##K5G, AC_##K0G, AC_##K0H, AC_NO,    AC_##K0K, AC_##K0L, AC_##K0M, AC_##K0N, AC_##K0P, AC_##K0Q, AC_##K0R} \
}

#define ACTIONMAP_ANSI( \
    K5A,      K5C, K5D, K5E, K5F, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O,      K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4O,      K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L,      K2N,                     \
    K1A,      K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,      K1N,           K1Q,      \
    K0A, K0B, K0C,                K0G,                K0K, K0L, K0M, K0N,      K0P, K0Q, K0R  \
) ACTIONMAP( \
    K5A, NO,  K5C, K5D, K5E, K5F, NO,  K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, NO,  K4O, K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, NO,  K2N,      NO,  NO,  NO,  \
    K1A, NO,  K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, NO,  K1N,      NO,  K1Q, NO,  \
    K0A, K0B, K0C, NO,       NO,  K0G, NO,            K0K, K0L, K0M, K0N,      K0P, K0Q, K0R  \
)

#define ACTIONMAP_ANSI_150( \
    K5A,      K5C, K5D, K5E, K5F, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O,      K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4O,      K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L,      K2N,                     \
    K1A,      K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,      K1N,           K1Q,      \
    K0A, K0B, K0C,                K0G,                     K0L, K0M, K0N,      K0P, K0Q, K0R  \
) ACTIONMAP( \
    K5A, NO,  K5C, K5D, K5E, K5F, NO,  K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, NO,  K4O, K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,      K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, NO,  K2N,      NO,  NO,  NO,  \
    K1A, NO,  K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, NO,  K1N,      NO,  K1Q, NO,  \
    K0A, K0B, K0C, NO,       NO,  K0G, NO,            NO,  K0L, K0M, K0N,      K0P, K0Q, K0R  \
)

#define ACTIONMAP_ISO( \
    K5A,      K5C, K5D, K5E, K5F, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O,      K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4O,      K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M,           K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,                     \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,      K1N,           K1Q,      \
    K0A, K0B, K0C,                K0G,                K0K, K0L, K0M, K0N,      K0P, K0Q, K0R  \
) ACTIONMAP( \
    K5A, NO,  K5C, K5D, K5E, K5F, NO,  K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, NO,  K4O, K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, NO,       K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      NO,  NO,  NO,  \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, NO,  K1N,      NO,  K1Q, NO,  \
    K0A, K0B, K0C, NO,       NO,  K0G, NO,            K0K, K0L, K0M, K0N,      K0P, K0Q, K0R  \
)

#define ACTIONMAP_ISO_150( \
    K5A,      K5C, K5D, K5E, K5F, K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O,      K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4O,      K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M,           K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,                     \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,      K1N,           K1Q,      \
    K0A, K0B, K0C,                K0G,                     K0L, K0M, K0N,      K0P, K0Q, K0R  \
) ACTIONMAP( \
    K5A, NO,  K5C, K5D, K5E, K5F, NO,  K5H, K5I, K5J, K5K, K5L, K5M, K5N, K5O, K5P, K5Q, K5R, \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, NO,  K4O, K4P, K4Q, K4R, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, NO,       K3P, K3Q, K3R, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N,      NO,  NO,  NO,  \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, NO,  K1N,      NO,  K1Q, NO,  \
    K0A, K0B, K0C, NO,       NO,  K0G, NO,            NO,  K0L, K0M, K0N,      K0P, K0Q, K0R  \
)

#endif // ACTIONMAP_COMMON_H
