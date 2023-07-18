#pragma once

/* RGBPWM */
#define WS2812_PWM_DRIVER PWMD1  // default: PWMD2
#define WS2812_PWM_CHANNEL 3  // default: 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM5  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL 5  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.

/* RGB参数 */
#define RGB_DI_PIN A10
#define WS2812_DI_PIN A10
#define RGBLED_NUM 17
#define RGB_MATRIX_LED_COUNT 17
#define DRIVER_LED_TOTAL 17
//#define RGB_MATRIX_KEYPRESSES
//#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
//#define RGB_DISABLE_WHEN_USB_SUSPENDED false
//#define RGB_MATRIX_CENTER { 112, 32 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 40 //led亮度

/* RGB灯效 */
#define ENABLE_RGB_MATRIX_ALPHAS_MODS	//使RGB_MATRIX_ALPHAS_MODS

