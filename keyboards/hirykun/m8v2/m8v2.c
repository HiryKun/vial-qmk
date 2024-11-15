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
	{211,39},{212,37},{213,36},{215,36},{217,36},{218,37},{219,39},{218,41},{217,42},{215,42},{213,42},{212,41},{215,40},{216,39},{214,39},

}, {
	2,2,2,2,2,
    2,2,2,2,2,
    2,2,2,2,2
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
