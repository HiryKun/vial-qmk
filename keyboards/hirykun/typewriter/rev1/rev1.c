#include "quantum.h"

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().num_lock)
        rgb_matrix_set_color(3, RGB_WHITE);
    else rgb_matrix_set_color(3, RGB_OFF);
    if (host_keyboard_led_state().caps_lock)
        rgb_matrix_set_color(4, RGB_RED);
    else rgb_matrix_set_color(4, RGB_OFF);
    if (host_keyboard_led_state().scroll_lock)
        rgb_matrix_set_color(5, RGB_GREEN);
    else rgb_matrix_set_color(5, RGB_OFF);
    return true;
}