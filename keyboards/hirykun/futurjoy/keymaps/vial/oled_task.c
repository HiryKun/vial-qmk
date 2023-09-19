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
uint8_t a_0_regitster = 0;  //数字及字母计数器
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

void oled_animation(void) {
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
        oled_write_raw_P(black_screen, FRAME_SIZE);
        return;
    }
    if(timer_read32() - action_timer > SCR_TIMEOUT) {
        oled_write_raw_P(time_out[now_frame_timeout], FRAME_SIZE);
        if(now_frame_timeout < MAX_FRAME(time_out) - 1)
            ++now_frame_timeout;
        else now_frame_timeout = 0;
        return;
    }
    //Caps动画
    if(host_keyboard_led_state().caps_lock) {
        oled_write_raw_P(caps_appear[now_frame_caps_appear], FRAME_SIZE);
        if(now_frame_caps_appear < MAX_FRAME(caps_appear) - 1)
            ++now_frame_caps_appear;
        caps_state = host_keyboard_led_state().caps_lock;
        now_frame_caps_disappear = 0;
        return;
    }
    else if(host_keyboard_led_state().caps_lock != caps_state) {
        oled_write_raw_P(caps_disappear[now_frame_caps_disappear], FRAME_SIZE);
        if(now_frame_caps_disappear < MAX_FRAME(caps_appear) - 1)
            ++now_frame_caps_disappear;
        else caps_state = host_keyboard_led_state().caps_lock;
        now_frame_caps_appear = 0;
        return;
    }
    //Fn出现动画
    if(get_highest_layer(layer_state) == 1) {
        oled_write_raw_P(fn_appear[now_frame_fn_appear], FRAME_SIZE);
        if(now_frame_fn_appear < MAX_FRAME(fn_appear) - 1)
            ++now_frame_fn_appear;
        now_frame_fn_disappear = 0;
        fn_layer_appear = true;
        return;
    }
    //Fn消失动画
    if(fn_layer_appear) {
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
            oled_write_raw_P(a_0_animation[last_buffer - KC_A][now_frame_a_0], FRAME_SIZE);
            return;
    }
    //其他按键动画
    if( user_config.function_key &&
        animation_timer != 0 &&
        timer_read32() - animation_timer < KEY_TIMEOUT ) {
            switch (last_buffer) {
                case KC_ESC:
                    oled_write_raw_P(esc[now_frame_esc], FRAME_SIZE);
                    return;
                case KC_ENTER:
                    oled_write_raw_P(enter[now_frame_enter], FRAME_SIZE);
                    return;
                case KC_SPACE:
                    oled_write_raw_P(space[now_frame_space], FRAME_SIZE);
                    return;
                case KC_DELETE:
                    oled_write_raw_P(delete[now_frame_delete], FRAME_SIZE);
                    return;
                case KC_UP:
                    oled_write_raw_P(up[now_frame_up], FRAME_SIZE);
                    return;
                case KC_DOWN:
                    oled_write_raw_P(down[now_frame_down], FRAME_SIZE);
                    return;
                case KC_LEFT:
                    oled_write_raw_P(left[now_frame_left], FRAME_SIZE);
                    return;
                case KC_RIGHT:
                    oled_write_raw_P(right[now_frame_right], FRAME_SIZE);
                    return;
                default:
                    return;
            }
    }
    //默认动画
    oled_write_raw_P(default_animation[now_frame_default], FRAME_SIZE);
    if(now_frame_default < MAX_FRAME(default_animation) - 1)
        ++now_frame_default;
    else now_frame_default = 0;
    return;

}

