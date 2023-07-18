#pragma once

#include_next <halconf.h>

#undef HAL_USE_PWM
#define HAL_USE_PWM TRUE
/*按需使能外设，无需则留空*/