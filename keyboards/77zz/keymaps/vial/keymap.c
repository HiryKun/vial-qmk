#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT (
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, MO(1)
		),

	[1] = LAYOUT (
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, KC_TRNS
		)
};


led_config_t g_led_config = {
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, NO_LED},
		{11, 12, 13, NO_LED},
		{14, NO_LED, 15, 16}
	}, {
		{28, 3}, {84, 3}, {140, 3}, {196, 3}, 
		{28, 16}, {84, 16}, {140, 16}, {196, 19}, 
		{28, 29}, {84, 29}, {140, 29}, 
		{28, 41}, {84, 41}, {140, 41}, 
		{56, 54}, {140, 54},{196, 45}
	}, {
		4, 4, 4, 4, 
		4, 4, 4, 4, 
		4, 4, 4, 
		4, 4, 4, 
		4, 4, 4
	}
};