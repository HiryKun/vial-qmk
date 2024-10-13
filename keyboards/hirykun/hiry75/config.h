#pragma once

#define AUDIO_PIN B15
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL 3
#define AUDIO_PWM_COMPLEMENTARY_OUTPUT
#define AUDIO_CLICKY
#define AUDIO_INIT_DELAY
#define AUDIO_CLICKY_FREQ_DEFAULT 1500.0f
#define AUDIO_CLICKY_FREQ_MIN 1000.0f
#define AUDIO_CLICKY_FREQ_MAX 2500.0f

#define SOLENOID_PIN B9
#define SOLENOID_DWELL_STEP_SIZE 5
#define HAPTIC_OFF_IN_LOW_POWER 1

#define WS2812_PWM_DRIVER PWMD4
#define WS2812_PWM_CHANNEL 3
#define WS2812_DMA_STREAM STM32_DMA1_STREAM7
#define WS2812_DMA_CHANNEL 7
#define RGB_MATRIX_LED_COUNT 78
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
