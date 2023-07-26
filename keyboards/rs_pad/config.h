// Copyright 2023 HiryKun (@HiryKun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 3

#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 4
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 2
#define RGB_MATRIX_LED_COUNT 15
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define AUDIO_PIN A8
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL 1
#define AUDIO_CLICKY
#define AUDIO_INIT_DELAY
#define AUDIO_CLICKY_FREQ_DEFAULT 1500.0f
#define AUDIO_CLICKY_FREQ_MIN 1000.0f
#define AUDIO_CLICKY_FREQ_MAX 2500.0f

#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#define OLED_SCROLL_TIMEOUT 60000
#define OLED_TIMEOUT 120000
#define OLED_UPDATE_INTERVAL 50

#define NO_USB_STARTUP_CHECK
#define RGB_DISABLE_WHEN_USB_SUSPENDED
