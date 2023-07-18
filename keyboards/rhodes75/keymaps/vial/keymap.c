#include QMK_KEYBOARD_H

/*按键映射*/
/*关于keymap和层的解读，详见 https://docs.qmk.fm/#/feature_layers 和 https://docs.qmk.fm/#/keymap */
/*可用的键详见 https://docs.qmk.fm/#/keycodes */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*默认层*/
    [0] = LAYOUT (
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , TO(1)  ,
	KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_HOME,
	KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR,
	KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
	KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          KC_UP  ,
	KC_LCTL, KC_LWIN, KC_LALT,                   KC_SPC ,                            KC_RALT, MO(1)  , KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT	//MO()所指层的相同位置，需要写KC_TRNS，不能是XXXXXXX
    ),
	/*Fn层*/
    [1] = LAYOUT (
    QK_BOOT, EE_CLR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0)  ,
	XXXXXXX, RGB_HUI, RGB_SAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, RGB_HUD, RGB_SAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_VAI,
	XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, KC_TRNS, RGB_TOG, XXXXXXX, RGB_VAD, RGB_MOD	//MO()所指层的相同位置，需要写KC_TRNS，不能是XXXXXXX
    )
};	//这里的分号一定不要忘记

led_config_t g_led_config = { {
	//轴灯对应的灯的序号
	{15, 14, 13, 12,     11,     10, 9 ,     8 ,     7 ,     6 , 5 , 4 , 3 ,     2 ,     1     },
	{17, 18, 19, 21,     22,     23, 25,     26,     27,     28, 30, 31, 32,     34,     36    },
	{51, 50, 49, 48,     47,     46, 45,     44,     43,     42, 41, 40, 39,     38,     37    },
	{52, 53, 54, 55,     56,     57, 58,     59,     60,     61, 62, 63, 64,     NO_LED, NO_LED},
	{77, 76, 75, 74,     73,     72, 71,     70,     69,     68, 67, 66, NO_LED, 65,     NO_LED},
	{79, 80, 82, NO_LED, NO_LED, 84, NO_LED, NO_LED, NO_LED, 86, 87, 88, 90,     91,     92    }
}, {
	//所有RGB物理位置
	{224, 6}, {216, 0}, {202, 0}, {184, 0}, {169, 0}, {155, 0}, {140, 0}, {123, 0}, {108, 0}, {94, 0}, {79, 0}, {61, 0}, {47, 0 }, {36, 0 }, {18, 0 }, {0, 0},
	{0, 0}, {0, 13}, {14, 13}, {29, 13}, {36, 0}, {43, 13}, {58, 13}, {72, 13}, {79, 0}, {87, 13}, {101, 13}, {115, 13}, {130, 13}, {137, 0}, {145, 13}, {159, 13}, {173, 13}, {188, 0}, {195, 13}, {224, 0}, {224, 13},
	{224, 26}, {199, 26}, {181, 26}, {166, 26}, {152, 26}, {137, 26}, {123, 26}, {108, 26}, {94, 26}, {79, 26}, {65, 26}, {51, 26}, {36, 26}, {22, 26}, {4, 26},
	{4, 38}, {25, 38}, {40, 38}, {54, 38}, {69, 38}, {83, 38}, {98, 38}, {112, 38}, {126, 38}, {141, 38}, {155, 38}, {170, 38}, {191, 38},
	{206, 51}, {184, 51}, {163, 51}, {148, 51}, {134, 51}, {119, 51}, {105, 51}, {90, 51}, {76, 51}, {61, 51}, {47, 51}, {33, 51}, {11, 51},
	{0, 64}, {0, 64}, {20, 64}, {29, 64}, {40, 64}, {79, 64}, {90, 64}, {134, 64}, {145, 64}, {156, 64}, {173, 64}, {185, 64}, {191, 64}, {206, 64}, {220, 64}, {224, 64}
}, {
	//所有RGB的标记（Flag）
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	2, 4, 4, 4, 2, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 4, 2, 4, 2, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
	2, 4, 4, 2, 4, 2, 4, 2, 4, 4, 4, 2, 4, 4, 4, 2
} };

void rgb_matrix_indicators_kb(void) {
    if(host_keyboard_led_state().caps_lock) {
		rgb_matrix_set_color(52, 255, 0, 0);
	}
	if(get_highest_layer(layer_state) == 1) {
		for(uint8_t i = 0; i <= 93; ++i) {
			if(HAS_FLAGS(g_led_config.flags[i], 0x02)) {
				rgb_matrix_set_color(i, 0, 255, 0);
			}
		}
	}
    return;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif

