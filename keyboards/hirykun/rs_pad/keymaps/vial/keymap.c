// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

extern audio_config_t audio_config;
extern bool music_activated;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                                   TO(1),
        KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
        KC_P4,   KC_P5,   KC_P6,   KC_NUM,
        KC_P1,   KC_P2,   KC_P3,
        MO(1),   KC_P0,   KC_PDOT, KC_PENT
    ),

    [1] = LAYOUT(
                                   TO(2),
        GU_TOGG, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______
    ),

    [2] = LAYOUT(
                                   TO(3),
        AU_TOGG, RGB_SAI, RGB_SAD, RGB_MOD,
        CK_TOGG, RGB_SPI, RGB_SPD, RGB_TOG,
        CK_UP,   RGB_HUI, RGB_HUD,
        CK_DOWN, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT(
                                   TO(4),
        KC_P1,   KC_P1,   KC_P1,   KC_P1,
        KC_P1,   KC_P1,   KC_P1,   KC_P1,
        KC_P1,   KC_P1,   KC_P1,
        KC_P1,   KC_P1,   KC_P1,   KC_P1
    ),

    [4] = LAYOUT(
                                   TO(0),
        QK_BOOT, EE_CLR,  QK_RBT,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [3] = { ENCODER_CCW_CW(MU_NEXT, MU_TOGG) },
    [4] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif
 
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer:\n"), false);
    switch (get_highest_layer(layer_state))
    {
    case 0:
        oled_write_P(PSTR("Default\n"), false);
        break;
    case 1:
        oled_write_P(PSTR("Fn\n"), false);
        break;
    case 2:
        oled_write_P(PSTR("Audio&RGB\n"), false);
        break;
    case 3:
        oled_write_P(PSTR("Music\n"), false);
        break;
    case 4:
        oled_write_P(PSTR("Advance\n"), false);
        break;
    default:
        oled_write_P(PSTR("Unknow\n"), false);
        break;
    }

    if(audio_config.enable == 1) {
        oled_write_P(PSTR("Audio "), false);
        oled_write_P(audio_config.clicky_enable ? PSTR(" Clicky ") : PSTR("       "), false);
        oled_write_P(music_activated ? PSTR(" Music") : PSTR("      "), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("\nNUM ") : PSTR("\n    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
