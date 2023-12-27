#include QMK_KEYBOARD_H
#ifdef OLED_ENABLE
    #include "oled_task.c"
#endif

enum my_keycode {
  DP_MAIN = SAFE_RANGE, //字母数字动画开关
  DP_FUNC,              //其他键动画开关
};

// 按键映射
// 关于keymap和层的解读，详见 https://docs.qmk.fm/#/feature_layers 和 https://docs.qmk.fm/#/keymap
// 可用的键详见 https://docs.qmk.fm/#/keycodes
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
};

#ifdef OLED_ENABLE
void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user(); //读取EEPROM储存内容
    action_timer = timer_read32();          //初始化超时计时器
    caps_state = host_keyboard_led_state().caps_lock;   //初始化Caps状态
}

//EEPROM初始化
void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.main_key = true;
  user_config.function_key = true;
  eeconfig_update_user(user_config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    action_timer = timer_read32();  //有键按下，重置超时计时器，重新计时
	if(keycode >= KC_A && keycode <= KC_0) {    //字母或数字
		if (record->event.pressed) {    //记录按键
			++buffer_top;
			record_buffer[buffer_top] = keycode;
			buffer_index[keycode] = buffer_top;
            ++a_0_regitster;
		}
		else {  //消除按键记录
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
        keycode == KC_BSPC  ||
        keycode == KC_LEFT  ||
        keycode == KC_RIGHT ||
        keycode == KC_UP    ||
        keycode == KC_DOWN  ) {
		if (record->event.pressed) {    //记录按键
			if(buffer_top < BUFFER_SIZE) ++buffer_top;
			record_buffer[buffer_top] = keycode;
			buffer_index[keycode] = buffer_top;
		}
		else {  //消除按键记录
			for(uint8_t operate_index = buffer_index[keycode]; operate_index <= buffer_top; ++operate_index) {
				record_buffer[operate_index] = record_buffer[operate_index + 1];
			}
			--buffer_top;
            buffer_index[keycode] = 0;
		}
	}
    switch (keycode) {
        case DP_MAIN:   //字母数字动画开关
            if (record->event.pressed) {
                user_config.main_key ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case DP_FUNC:
            if (record->event.pressed) {    //其他键动画开关
                user_config.function_key ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        default:
            return true;
    }
}
#endif

#ifdef ENCODER_MAP_ENABLE
//编码器映射
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#ifdef OLED_ENABLE
//将屏幕旋转90度
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_90;
}

bool oled_task_user(void) {
    //记录当前按键动画，开始倒计时
    if(buffer_top != 0) {
        last_buffer = record_buffer[buffer_top];
        animation_timer = timer_read32();
    }
    //数字及字母动画重置
    if( a_0_regitster == 0 && (last_buffer < KC_A || last_buffer > KC_0) )
        now_frame_a_0 = 0;
    //Esc动画重置
    if(buffer_index[KC_ESC] == 0 && last_buffer != KC_ESC)
        now_frame_esc = 0;
    //Enter动画重置
    if(buffer_index[KC_ENTER] == 0 && last_buffer != KC_ENTER)
        now_frame_enter = 0;
    //Space动画重置
    if(buffer_index[KC_SPACE] == 0 && last_buffer != KC_SPACE)
        now_frame_space = 0;
    //Delete动画重置
    if(buffer_index[KC_DELETE] == 0 &&
    buffer_index[KC_BSPC] == 0   &&
    last_buffer != KC_DELETE     &&
    last_buffer != KC_BSPC)
        now_frame_delete = 0;
    //主动画进程
    oled_animation();
    //数字及字母动画递增
    if( (a_0_regitster != 0 || (last_buffer >= KC_A && last_buffer <= KC_0)) && now_frame_a_0 < MAX_FRAME(a_0_animation[0]) - 1)
        ++now_frame_a_0;
    //Esc动画循环
    if(buffer_index[KC_ESC] != 0 || last_buffer == KC_ESC) {
        if(now_frame_esc < MAX_FRAME(esc) - 1)
            ++now_frame_esc;
        else now_frame_esc = ESC_LOOP_START - 1;
    }
    //Enter动画递增
    if( (buffer_index[KC_ENTER] != 0 || last_buffer == KC_ENTER) && now_frame_enter < MAX_FRAME(enter) - 1)
        ++now_frame_enter;
    //Space动画递增
    if( (buffer_index[KC_SPACE] != 0 || last_buffer == KC_SPACE) && now_frame_space < MAX_FRAME(space) - 1)
        ++now_frame_space;
    //Delete动画递增
    if( (buffer_index[KC_DELETE] != 0 || buffer_index[KC_BSPC] != 0 ||
    last_buffer == KC_DELETE || last_buffer == KC_BSPC) &&
    now_frame_delete < MAX_FRAME(delete) - 1)
        ++now_frame_delete;
    //UP动画循环
    if(buffer_index[KC_UP] != 0 || last_buffer == KC_UP) {
        if(now_frame_up < MAX_FRAME(up) - 1)
            ++now_frame_up;
        else now_frame_up = 0;
    }
    //DOWN动画循环
    if(buffer_index[KC_DOWN] != 0 || last_buffer == KC_DOWN) {
        if(now_frame_down < MAX_FRAME(down) - 1)
            ++now_frame_down;
        else now_frame_down = 0;
    }
    //LEFT动画循环
    if(buffer_index[KC_LEFT] != 0 || last_buffer == KC_LEFT) {
        if(now_frame_left < MAX_FRAME(left) - 1)
            ++now_frame_left;
        else now_frame_left = 0;
    }
    //RIGHT动画循环
    if(buffer_index[KC_RIGHT] != 0 || last_buffer == KC_RIGHT) {
        if(now_frame_right < MAX_FRAME(right) - 1)
            ++now_frame_right;
        else now_frame_right = 0;
    }

    return false;
}
#endif
