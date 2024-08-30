// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define OLED_FONT_H "./lib/glcdfont.c"

#define RGB_MATRIX_LED_COUNT 56
#define RGBLED_NUM 56     // Number of LEDs in your strip
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 125
#define RGB_MATRIX_TYPING_HEATMAP_SLIM
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
