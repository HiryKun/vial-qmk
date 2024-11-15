#include QMK_KEYBOARD_H

bool key_pressing = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) key_pressing = true;
    else key_pressing = false;
    if (!process_record_user(keycode, record)) return false;
    return true;
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        if (!key_pressing) rgblight_setrgb_at(RGB_BLACK, 0);
    }
    return true;
}
