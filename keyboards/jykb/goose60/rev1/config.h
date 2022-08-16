// Copyright 2022 yuhao-kuo (@yuhao-kuo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

#define MATRIX_ROWS	5
#define MATRIX_COLS	14

#define MATRIX_ROW_PINS	{ A0, B8, A2, A15, A3 }
#define MATRIX_COL_PINS { B14, B13, B12, B15, B3, B4, B5, B6, B7, B9, B0, B1, B11, B10 }

#define DIODE_DIRECTION	ROW2COL

#define DEBOUNCE	10



