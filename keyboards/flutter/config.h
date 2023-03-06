/*
Copyright 2023 Joel Willians

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

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6

#define MATRIX_COL_PINS {C6, D7, E6, F7, B6, F6}
#define MATRIX_ROW_PINS {D2, F5, D4, B3, B2}

#define DIODE_DIRECTION ROW2COL

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define CAPS_WORD_IDLE_TIMEOUT 0

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define POINTING_DEVICE_ROTATION_90
