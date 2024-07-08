#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE

// #undef STM32_PWM_USE_TIM4
// #define STM32_PWM_USE_TIM4 TRUE
/*按需使能外设，无需则留空*/
