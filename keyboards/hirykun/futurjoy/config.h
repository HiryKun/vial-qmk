// Copyright 2023 HiryKun (@HiryKun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGB_MATRIX_LED_COUNT 94
#define DRIVER_LED_TOTAL 94
#define WS2812_PWM_DRIVER PWMD8
#define WS2812_PWM_CHANNEL 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM1
#define WS2812_DMA_CHANNEL 1

#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
