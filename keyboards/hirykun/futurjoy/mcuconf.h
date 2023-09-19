#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM8
#define STM32_PWM_USE_TIM8 TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
