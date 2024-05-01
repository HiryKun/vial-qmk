#include "animation.c"

#define BUFFER_SIZE 10          //记录区大小
#define SCR_TIMEOUT 60000       //待机动画出现时间
#define OFF_TIMEOUT 120000      //息屏超时时间
#define KEY_TIMEOUT 6000        //按键动画恢复时间

typedef union {
  uint32_t raw;
  struct {
    bool main_key :1;       //字母数字动画开关
    bool function_key :1;   //其他键动画开关
  };
} user_config_t;

user_config_t user_config;

uint8_t record_buffer[BUFFER_SIZE + 2] = {0};   //按键记录区
uint8_t buffer_index[256] = {0};    //keycode对应记录区下标
uint8_t buffer_top = 0;     //记录区顶部
uint8_t last_buffer = 0;    //最后按键动画
uint8_t last_a_0 = 0;
uint8_t a_0_regitster = 0;  //数字及字母计数器
uint8_t last_animation = FIRSTBOOT; //最后播放的动画
uint8_t current_animation = FIRSTBOOT;  //当前动画
uint32_t action_timer = 0;      //超时计时器
uint32_t animation_timer = 0;   //按键动画恢复到默认动画计时器
bool is_firstboot = true;   //是否首次启动
bool fn_layer_appear = false;   //是否进入过Fn层
bool caps_state = false;    //Caps Lock状态

//动画当前帧
uint8_t now_frame_firstboot = 0;
uint8_t now_frame_timeout = 0;
uint8_t now_frame_caps_appear = 0;
uint8_t now_frame_caps_disappear = 0;
uint8_t now_frame_fn_appear = 0;
uint8_t now_frame_fn_disappear = 0;
uint8_t now_frame_a_0 = 0;
uint8_t now_frame_esc = 0;
uint8_t now_frame_enter = 0;
uint8_t now_frame_space = 0;
uint8_t now_frame_delete = 0;
uint8_t now_frame_up = 0;
uint8_t now_frame_down = 0;
uint8_t now_frame_left = 0;
uint8_t now_frame_right = 0;
uint8_t now_frame_default = 0;
uint8_t now_frame_transition = 0;

void oled_animation(void) {
    //淡入淡出动画
    if(last_animation != current_animation) {
        if(now_frame_transition == 2) {
            oled_write_raw_P(black_screen, FRAME_SIZE);
            ++now_frame_transition;
            return;
        }
        uint8_t transition_animation[FRAME_SIZE] = {0};
        uint8_t mask[2];
        if(now_frame_transition >= 0 && now_frame_transition <= 1) {
            switch (last_animation)
            {
            case TIME_OUT:
                memcpy(transition_animation, time_out[MAX_FRAME(time_out) - 1], FRAME_SIZE);
                break;
            case DEFAULT_ANIMATION:
                memcpy(transition_animation, default_animation[MAX_FRAME(default_animation) - 1], FRAME_SIZE);
                break;
            case FIRSTBOOT:
                memcpy(transition_animation, firstboot[MAX_FRAME(firstboot) - 1], FRAME_SIZE);
                break;
            case FN:
                if(get_highest_layer(layer_state) == 1) memcpy(transition_animation, fn_appear[MAX_FRAME(fn_appear) - 1], FRAME_SIZE);
                else memcpy(transition_animation, fn_disappear[now_frame_fn_disappear], FRAME_SIZE);
                break;
            case CAPS:
                if(host_keyboard_led_state().caps_lock) memcpy(transition_animation, caps_appear[MAX_FRAME(caps_appear) - 1], FRAME_SIZE);
                else memcpy(transition_animation, caps_disappear[now_frame_caps_disappear], FRAME_SIZE);
                break;
            case A_0:
                memcpy(transition_animation, a_0_animation[last_a_0 - KC_A][A_0_FRAME_NUM - 1], FRAME_SIZE);
                break;
            case ESC:
                memcpy(transition_animation, esc[MAX_FRAME(esc) - 1], FRAME_SIZE);
                break;
            case ENTER:
                memcpy(transition_animation, enter[MAX_FRAME(enter) - 1], FRAME_SIZE);
                break;
            case SPACE:
                memcpy(transition_animation, space[MAX_FRAME(space) - 1], FRAME_SIZE);
                break;
            case DELETE:
                memcpy(transition_animation, delete[MAX_FRAME(delete) - 1], FRAME_SIZE);
                break;
            case UP_:
                memcpy(transition_animation, up[MAX_FRAME(up) - 1], FRAME_SIZE);
                break;
            case DOWN:
                memcpy(transition_animation, down[MAX_FRAME(down) - 1], FRAME_SIZE);
                break;
            case LEFT:
                memcpy(transition_animation, left[MAX_FRAME(left) - 1], FRAME_SIZE);
                break;
            case RIGHT:
                memcpy(transition_animation, right[MAX_FRAME(right) - 1], FRAME_SIZE);
                break;
            default:
                break;
            }
        }
        else {
            switch (current_animation)
            {
            case TIME_OUT:
                memcpy(transition_animation, time_out[now_frame_timeout], FRAME_SIZE);
                break;
            case DEFAULT_ANIMATION:
                memcpy(transition_animation, default_animation[now_frame_default], FRAME_SIZE);
                break;
            case FN:
                if(get_highest_layer(layer_state) == 1) memcpy(transition_animation, fn_appear[now_frame_fn_appear], FRAME_SIZE);
                else memcpy(transition_animation, fn_disappear[now_frame_fn_disappear], FRAME_SIZE);
                break;
            case CAPS:
                if(host_keyboard_led_state().caps_lock) memcpy(transition_animation, caps_appear[now_frame_caps_appear], FRAME_SIZE);
                else memcpy(transition_animation, caps_disappear[now_frame_caps_disappear], FRAME_SIZE);
                break;
            case A_0:
                memcpy(transition_animation, a_0_animation[last_buffer - KC_A][now_frame_a_0], FRAME_SIZE);
                break;
            case ESC:
                memcpy(transition_animation, esc[now_frame_esc], FRAME_SIZE);
                break;
            case ENTER:
                memcpy(transition_animation, enter[now_frame_enter], FRAME_SIZE);
                break;
            case SPACE:
                memcpy(transition_animation, space[now_frame_space], FRAME_SIZE);
                break;
            case DELETE:
                memcpy(transition_animation, delete[now_frame_delete], FRAME_SIZE);
                break;
            case UP_:
                memcpy(transition_animation, up[now_frame_up], FRAME_SIZE);
                break;
            case DOWN:
                memcpy(transition_animation, down[now_frame_down], FRAME_SIZE);
                break;
            case LEFT:
                memcpy(transition_animation, left[now_frame_left], FRAME_SIZE);
                break;
            case RIGHT:
                memcpy(transition_animation, right[now_frame_right], FRAME_SIZE);
                break;
            default:
                break;
            }
        }
        if(now_frame_transition == 0 || now_frame_transition == 3) {
            mask[0] = 0x55;
            mask[1] = 0x00;
        }
        else if(now_frame_transition == 1 || now_frame_transition == 2) {
            mask[0] = 0x55;
            mask[1] = 0xAA;
        }
        for(uint16_t current_byte = 0; current_byte < FRAME_SIZE; ++current_byte) {
            transition_animation[current_byte] &= mask[current_byte & 1];
        }
        oled_write_raw_P((const char *)(transition_animation), FRAME_SIZE);
        if(now_frame_transition < 4)
            ++now_frame_transition;
        else {
            last_animation = current_animation;
            now_frame_transition = 0;
        }
        return;
    }
    //开机动画
    if(is_firstboot) {
        oled_write_raw_P(firstboot[now_frame_firstboot], FRAME_SIZE);
        if(now_frame_firstboot < MAX_FRAME(firstboot) - 1)
            ++now_frame_firstboot;
        else is_firstboot = false;
        return;
    }
    //超时屏保动画
    if(timer_read32() - action_timer > OFF_TIMEOUT) {
        if(last_animation != BLACK_SCREEN) {
            current_animation = BLACK_SCREEN;
            return;
        }
        oled_write_raw_P(black_screen, FRAME_SIZE);
        return;
    }
    if(timer_read32() - action_timer > SCR_TIMEOUT) {
        if(last_animation != TIME_OUT) {
            current_animation = TIME_OUT;
            return;
        }
        oled_write_raw_P(time_out[now_frame_timeout], FRAME_SIZE);
        if(now_frame_timeout < MAX_FRAME(time_out) - 1)
            ++now_frame_timeout;
        else now_frame_timeout = 0;
        return;
    }
    //Caps动画
    if(host_keyboard_led_state().caps_lock) {
        if(last_animation != CAPS) {
            current_animation = CAPS;
            return;
        }
        oled_write_raw_P(caps_appear[now_frame_caps_appear], FRAME_SIZE);
        if(now_frame_caps_appear < MAX_FRAME(caps_appear) - 1)
            ++now_frame_caps_appear;
        caps_state = host_keyboard_led_state().caps_lock;
        now_frame_caps_disappear = 0;
        return;
    }
    else if(host_keyboard_led_state().caps_lock != caps_state) {
        if(last_animation != CAPS) {
            current_animation = CAPS;
            return;
        }
        oled_write_raw_P(caps_disappear[now_frame_caps_disappear], FRAME_SIZE);
        if(now_frame_caps_disappear < MAX_FRAME(caps_appear) - 1)
            ++now_frame_caps_disappear;
        else caps_state = host_keyboard_led_state().caps_lock;
        now_frame_caps_appear = 0;
        return;
    }
    //Fn出现动画
    if(get_highest_layer(layer_state) == 1) {
        if(last_animation != FN) {
            current_animation = FN;
            return;
        }
        oled_write_raw_P(fn_appear[now_frame_fn_appear], FRAME_SIZE);
        if(now_frame_fn_appear < MAX_FRAME(fn_appear) - 1)
            ++now_frame_fn_appear;
        now_frame_fn_disappear = 0;
        fn_layer_appear = true;
        return;
    }
    //Fn消失动画
    if(fn_layer_appear) {
        if(last_animation != FN) {
            current_animation = FN;
            return;
        }
        oled_write_raw_P(fn_disappear[now_frame_fn_disappear], FRAME_SIZE);
        if(now_frame_fn_disappear < MAX_FRAME(fn_disappear) - 1)
            ++now_frame_fn_disappear;
        else fn_layer_appear = false;
        now_frame_fn_appear = 0;
        return;
    }
    //数字及字母按键动画
    if( user_config.main_key &&
        animation_timer != 0 &&
        timer_read32() - animation_timer < KEY_TIMEOUT &&
        last_buffer >= KC_A &&
        last_buffer <= KC_0 ) {
            if(last_animation != A_0) {
                current_animation = A_0;
                return;
            }
            oled_write_raw_P(a_0_animation[last_buffer - KC_A][now_frame_a_0], FRAME_SIZE);
            last_a_0 = last_buffer;
            return;
    }
    //其他按键动画
    if( user_config.function_key &&
        animation_timer != 0 &&
        timer_read32() - animation_timer < KEY_TIMEOUT ) {
            switch (last_buffer) {
                case KC_ESC:
                    if(last_animation != ESC) {
                        current_animation = ESC;
                        return;
                    }
                    oled_write_raw_P(esc[now_frame_esc], FRAME_SIZE);
                    return;
                case KC_ENTER:
                    if(last_animation != ENTER) {
                        current_animation = ENTER;
                        return;
                    }
                    oled_write_raw_P(enter[now_frame_enter], FRAME_SIZE);
                    return;
                case KC_SPACE:
                    if(last_animation != SPACE) {
                        current_animation = SPACE;
                        return;
                    }
                    oled_write_raw_P(space[now_frame_space], FRAME_SIZE);
                    return;
                case KC_DELETE:
                    if(last_animation != DELETE) {
                        current_animation = DELETE;
                        return;
                    }
                    oled_write_raw_P(delete[now_frame_delete], FRAME_SIZE);
                    return;
                case KC_BSPC:
                    if(last_animation != DELETE) {
                        current_animation = DELETE;
                        return;
                    }
                    oled_write_raw_P(delete[now_frame_delete], FRAME_SIZE);
                    return;
                case KC_UP:
                    if(last_animation != UP_) {
                        current_animation = UP_;
                        return;
                    }
                    oled_write_raw_P(up[now_frame_up], FRAME_SIZE);
                    return;
                case KC_DOWN:
                    if(last_animation != DOWN) {
                        current_animation = DOWN;
                        return;
                    }
                    oled_write_raw_P(down[now_frame_down], FRAME_SIZE);
                    return;
                case KC_LEFT:
                    if(last_animation != LEFT) {
                        current_animation = LEFT;
                        return;
                    }
                    oled_write_raw_P(left[now_frame_left], FRAME_SIZE);
                    return;
                case KC_RIGHT:
                    if(last_animation != RIGHT) {
                        current_animation = RIGHT;
                        return;
                    }
                    oled_write_raw_P(right[now_frame_right], FRAME_SIZE);
                    return;
                default:
                    return;
            }
    }
    //默认动画
    if(last_animation != DEFAULT_ANIMATION) {
        current_animation = DEFAULT_ANIMATION;
        return;
    }
    oled_write_raw_P(default_animation[now_frame_default], FRAME_SIZE);
    if(now_frame_default < MAX_FRAME(default_animation) - 1)
        ++now_frame_default;
    else now_frame_default = 0;
    return;
}
