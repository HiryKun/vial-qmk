// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_1,    KC_ENT,
        KC_LSFT, KC_2,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, KC_3,    KC_SPC,  KC_4,    KC_5,    KC_SPC,  KC_6,    MO(1),   KC_RALT, KC_RCTL
    )
};

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index)
    {
    case 0:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 10);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 10);
            unregister_code16(keycode);
        }
        
        break;
    case 1:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2, 1);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2, 1);
            unregister_code16(keycode);
        }
        break;
    case 2:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 3);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 3);
            unregister_code16(keycode);
        }
        break;
    case 3:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 5);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 5);
            unregister_code16(keycode);
        }
        break;
    case 4:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 6);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 6);
            unregister_code16(keycode);
        }
        break;
    case 5:
        if(active) {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 8);
            register_code16(keycode);
        }
        else {
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3, 8);
            unregister_code16(keycode);
        }
        break;
    default:
        break;
    }
    return false;
}
#endif