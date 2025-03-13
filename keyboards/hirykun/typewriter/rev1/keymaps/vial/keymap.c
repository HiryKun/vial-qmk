// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     rgb_anim:true;
  };
} user_config_t;

user_config_t user_config;

enum my_keycodes {
  RGB_ANI = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_PSCR, KC_SCRL, KC_PAUS, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,
        KC_INS,  KC_HOME, KC_PGUP, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NUM,  KC_CALC, KC_PSLS, KC_PAST,
        KC_DEL,  KC_END,  KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_UP,            KC_DOWN, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,          KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LEFT,          KC_RGHT, KC_LGUI, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
                                            KC_LCTL, KC_LALT,                                     KC_SPC,                             KC_RALT, KC_RCTL,          KC_P0,            KC_PDOT
    ),
    [1] = LAYOUT(
        QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        HF_TOGG, HF_DWLU, HF_DWLD, CK_UP,   CK_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
        HF_RST,  HF_BUZZ, _______, MU_NEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
        AU_TOGG,          CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        MU_TOGG,          CK_RST,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______,                                     RGB_ANI,                            RGB_MOD, _______,          _______,          _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_ANI:
        if (record->event.pressed) {
            user_config.rgb_anim ^= 1U;
            eeconfig_update_user(user_config.raw);
        }
        return false;
    default:
        return true;
  }
}

bool rgb_matrix_indicators_user(void) {
    if (!user_config.rgb_anim) {
        rgb_matrix_set_color_all(RGB_BLACK);
    }
    return true;
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  if (!user_config.rgb_anim) {
    rgb_matrix_set_color_all(RGB_BLACK);
  }
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.rgb_anim = true;
  eeconfig_update_user(user_config.raw);
}