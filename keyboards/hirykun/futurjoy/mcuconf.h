#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM8
#define STM32_PWM_USE_TIM8 TRUE
/*按需使能外设，无需则留空*/