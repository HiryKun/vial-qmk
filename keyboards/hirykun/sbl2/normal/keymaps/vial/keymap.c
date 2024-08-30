// Copyright 2023 Dane Lipscombe (@dlip)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  MO(1),  KC_NO,  KC_NO,  KC_NO,  KC_NO
    ),
    [1] = LAYOUT(
        RGB_SPD,  KC_NO,  RGB_TOG,  RGB_SPI,  KC_NO,  KC_NO,  KC_NO,  RGB_RMOD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO
    )
};
