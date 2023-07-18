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

/* bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    rgb_matrix_set_color(0,255,0,0);
    return true;
}


 void rgb_matrix_indicators_user(void) {

	if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {

		rgb_matrix_set_color(0,255,0,0);
	}
	if (get_highest_layer(layer_state) == 1) {
		for (uint8_t i = 0; i <= 17; i++) {
			if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
				rgb_matrix_set_color(i, 255 0, 0);
			}
		}
	}	
	return true; 
};
*/

/* enum my_keycodes {
  RGB_ANIM = SAFE_RANGE,
};

void rgb_anim = 1;

void rgb_matrix_indicators_user(void) {
  switch (keycode) {
    case RGB_ANIM:
      if (record->event.pressed) {
		rgb_anim ^= 1;
      } else {
      }
      return false; // Skip all further processing of this key
	}
};

void rgb_matrix_indicators_user(void) {
	if (rgb_anim == 0) {
		rgb_matrix_set_color_all(0, 0, 0)
	}
	if (host_keyboard_led_state().caps_lock) {
		rgb_matrix_set_color(0, 255, 0, 0);
	}
} */