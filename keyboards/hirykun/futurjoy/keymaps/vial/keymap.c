#include QMK_KEYBOARD_H
#include "oled_task.c"

enum my_keycode {
  DP_MAIN = SAFE_RANGE,
  DP_FUNC,
};

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
    QK_BOOT, EE_CLR , DP_MAIN, DP_FUNC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0)  ,
	XXXXXXX, RGB_HUI, RGB_SAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, RGB_HUD, RGB_SAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_VAI,
	XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, KC_TRNS, RGB_TOG, XXXXXXX, RGB_VAD, RGB_MOD	//MO()所指层的相同位置，需要写KC_TRNS，不能是XXXXXXX
    )
};	//这里的分号一定不要忘记

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    action_timer = timer_read32();
    caps_state = host_keyboard_led_state().caps_lock;
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.main_key = true;
  user_config.function_key = true;
  eeconfig_update_user(user_config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    action_timer = timer_read32();
	if(keycode >= KC_A && keycode <= KC_0) {
		if (record->event.pressed) {
			++buffer_top;
			record_buffer[buffer_top] = keycode;
			buffer_index[keycode] = buffer_top;
            ++a_0_regitster;
		}
		else {
			for(uint8_t operate_index = buffer_index[keycode]; operate_index <= buffer_top; ++operate_index) {
				record_buffer[operate_index] = record_buffer[operate_index + 1];
			}
			--buffer_top;
            --a_0_regitster;
		}
	}

    if(	keycode == KC_ENTER ||
		keycode == KC_ESC	||
		keycode == KC_SPACE ||
        keycode == KC_DELETE||
        keycode == KC_LEFT  ||
        keycode == KC_RIGHT ||
        keycode == KC_UP    ||
        keycode == KC_DOWN  ) {
		if (record->event.pressed) {
			if(buffer_top < BUFFER_SIZE) ++buffer_top;
			record_buffer[buffer_top] = keycode;
			buffer_index[keycode] = buffer_top;
		}
		else {
			for(uint8_t operate_index = buffer_index[keycode]; operate_index <= buffer_top; ++operate_index) {
				record_buffer[operate_index] = record_buffer[operate_index + 1];
			}
			--buffer_top;
            buffer_index[keycode] = 0;
		}
	}
    switch (keycode) {
        case DP_MAIN:
            if (record->event.pressed) {
                user_config.main_key ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case DP_FUNC:
            if (record->event.pressed) {
                user_config.function_key ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        default:
            return true;
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_90; /*将屏幕旋转90度*/
}

bool oled_task_user(void) {
    if(a_0_regitster == 0)
        now_frame_a_0 = 0;      //数字及字母动画重置

    if(buffer_index[KC_ESC] == 0)
        now_frame_esc = 0;      //Esc动画重置

    if(buffer_index[KC_ENTER] == 0)
        now_frame_enter = 0;    //Enter动画重置

    if(buffer_index[KC_SPACE] == 0)
        now_frame_space = 0;    //Space动画重置

    if(buffer_index[KC_DELETE] == 0)
        now_frame_delete = 0;   //Delete动画重置

    if(buffer_index[KC_UP] == 0)
        now_frame_up = 0;       //UP动画重置

    if(buffer_index[KC_DOWN] == 0)
        now_frame_down = 0;     //DOWN动画重置

    if(buffer_index[KC_LEFT] == 0)
        now_frame_left = 0;     //LEFT动画重置

    if(buffer_index[KC_RIGHT] == 0)
        now_frame_right = 0;    //RIGHT动画重置

    oled_animation();   //主动画进程

    if(a_0_regitster != 0 && now_frame_a_0 < MAX_FRAME(a_0_animation[0]) - 1)
        ++now_frame_a_0;    //数字及字母动画递增

    if(buffer_index[KC_ESC] != 0) {
        if(now_frame_esc < MAX_FRAME(esc) - 1)
            ++now_frame_esc;    //Esc动画递增
        else now_frame_esc = ESC_LOOP_START - 1;    //Esc动画循环
    }

    if(buffer_index[KC_ENTER] != 0 && now_frame_enter < MAX_FRAME(enter) - 1)
        ++now_frame_enter;      //Enter动画递增

    if(buffer_index[KC_SPACE] != 0 && now_frame_space < MAX_FRAME(space) - 1)
        ++now_frame_space;      //Space动画递增

    if(buffer_index[KC_DELETE] != 0 && now_frame_delete < MAX_FRAME(delete) - 1)
        ++now_frame_delete;     //Delete动画递增

    if(buffer_index[KC_UP] != 0) {
        if(now_frame_up < MAX_FRAME(up) - 1)
            ++now_frame_up;     //UP动画递增
        else now_frame_up = 0;
    }

    if(buffer_index[KC_DOWN] != 0) {
        if(now_frame_down < MAX_FRAME(down) - 1)
            ++now_frame_down;     //down动画递增
        else now_frame_down = 0;
    }

    if(buffer_index[KC_LEFT] != 0) {
        if(now_frame_left < MAX_FRAME(left) - 1)
            ++now_frame_left;     //UP动画递增
        else now_frame_left = 0;
    }

    if(buffer_index[KC_RIGHT] != 0) {
        if(now_frame_right < MAX_FRAME(right) - 1)
            ++now_frame_right;     //UP动画递增
        else now_frame_right = 0;
    }

    return false;
}
#endif
