// Copyright 2023 HiryKun (@HiryKun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGB_MATRIX_LED_COUNT 85
#define WS2812_PWM_DRIVER PWMD8
#define WS2812_PWM_CHANNEL 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM1
#define WS2812_DMA_CHANNEL 1

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#define OLED_UPDATE_INTERVAL 20
#define OLED_SCROLL_TIMEOUT 120000
#define OLED_TIMEOUT 180000

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
