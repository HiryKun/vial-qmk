#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(0, 255, 255, 255);
    else rgb_matrix_set_color(0, 0, 0, 0);
    return true;
}