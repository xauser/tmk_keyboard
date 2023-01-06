/*
Copyright 2024 Ralf Schmitt <ralf@bunkertor.net>

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

#define ACTIONMAP( \
    k00,k01,k02,k03,k04,k05,k06,    k07,k08,k09,k0A,k0B,k0C,k0D, \
    k10,k11,k12,k13,k14,k15,k16,    k17,k18,k19,k1A,k1B,k1C,k1D, \
    k20,k21,k22,k23,k24,k25,            k28,k29,k2A,k2B,k2C,k2D, \
    k30,k31,k32,k33,k34,k35,k36,    k37,k38,k39,k3A,k3B,k3C,k3D, \
    k40,k41,k42,k43,k44,                    k49,k4A,k4B,k4C,k4D, \
                        k55,k56,    k57,k58,                     \
                            k54,    k59,                         \
                    k53,k52,k51,    k5C,k5B,k5A                  \
) { \
    { AC_##k00,AC_##k10,AC_##k20,AC_##k30,AC_##k40,AC_NO   },    \
    { AC_##k01,AC_##k11,AC_##k21,AC_##k31,AC_##k41,AC_##k51},    \
    { AC_##k02,AC_##k12,AC_##k22,AC_##k32,AC_##k42,AC_##k52},    \
    { AC_##k03,AC_##k13,AC_##k23,AC_##k33,AC_##k43,AC_##k53},    \
    { AC_##k04,AC_##k14,AC_##k24,AC_##k34,AC_##k44,AC_##k54},    \
    { AC_##k05,AC_##k15,AC_##k25,AC_##k35,AC_NO,   AC_##k55},    \
    { AC_##k06,AC_##k16,AC_NO,   AC_##k36,AC_NO,   AC_##k56},    \
    { AC_##k07,AC_##k17,AC_NO,   AC_##k37,AC_NO,   AC_##k57},    \
    { AC_##k08,AC_##k18,AC_##k28,AC_##k38,AC_NO,   AC_##k58},    \
    { AC_##k09,AC_##k19,AC_##k29,AC_##k39,AC_##k49,AC_##k59},    \
    { AC_##k0A,AC_##k1A,AC_##k2A,AC_##k3A,AC_##k4A,AC_##k5A},    \
    { AC_##k0B,AC_##k1B,AC_##k2B,AC_##k3B,AC_##k4B,AC_##k5B},    \
    { AC_##k0C,AC_##k1C,AC_##k2C,AC_##k3C,AC_##k4C,AC_##k5C},    \
    { AC_##k0D,AC_##k1D,AC_##k2D,AC_##k3D,AC_##k4D,AC_NO   }     \
}

#endif // ACTIONMAP_COMMON_H
