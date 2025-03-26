#include QMK_KEYBOARD_H

led_config_t g_led_config = { {
	{ NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
	{ NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED},
    },{
// "Fine-tuned" complex configuration
	{215,40},{215,39},{216,38},{217,37},{218,37},{220,37},{221,38},{222,39},{222,40},{222,41},
    {221,42},{220,43},{218,43},{217,43},{216,42},{215,41},{218,40},{218,39},{219,39},{219,40}
}, {
	2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2
} };

void keyboard_pre_init_user(void) {
    // Call the keyboard pre init code.

    // Set our LED pins as output
    gpio_set_pin_output(C15);
    gpio_write_pin_high(C15);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        gpio_write_pin_low(C15);
    } else {
        gpio_write_pin_high(C15);
    }
    return true; // Skip all further processing of this key
}
  