// Copyright 2023 HiryKun (@HiryKun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//RGB配置
#define RGB_MATRIX_LED_COUNT 85
#define WS2812_PWM_DRIVER PWMD8
#define WS2812_PWM_CHANNEL 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM1
#define WS2812_DMA_CHANNEL 1

//I2C配置
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#define OLED_UPDATE_INTERVAL 40

//EEPROM配置
//此数值不影响固件大小，但如果超出 Flash 导致越界，第一次刷入固件的键盘讲无法正常运行
//对于此键盘，不要改大此数据
#define WEAR_LEVELING_LOGICAL_SIZE 4096
#define WEAR_LEVELING_BACKING_SIZE 8192
