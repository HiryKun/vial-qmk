#include "animation.c"

#define BUFFER_SIZE 10
#define ACT_TIMEOUT 60000

uint8_t record_buffer[BUFFER_SIZE + 2] = {0};   //按键记录区
uint8_t buffer_index[256] = {0};    //keycode对应记录区下标
uint8_t buffer_top = 0; //记录区顶部

uint8_t a_0_regitster = 0;  //数字及字母计数器
bool fn_layer_appear = false;   //是否进入过Fn层
uint32_t action_timeout;    //超时计时器
bool is_firstboot = true;   //是否首次启动
bool caps_state = false;

//动画当前帧
uint8_t now_frame_a_0 = 0;
uint8_t now_frame_esc = 0;
uint8_t now_frame_enter = 0;
uint8_t now_frame_default = 0;
uint8_t now_frame_fn_appear = 0;
uint8_t now_frame_fn_disappear = 0;
uint8_t now_frame_timeout = 0;
uint8_t now_frame_firstboot = 0;
uint8_t now_frame_caps_appear = 0;
uint8_t now_frame_caps_disappear = 0;

void oled_animation(void) {
    if(is_firstboot) {
        oled_write_raw_P(firstboot[now_frame_firstboot], FRAME_SIZE);
        if(now_frame_firstboot < MAX_FRAME(firstboot) - 1)
            ++now_frame_firstboot;
        else is_firstboot = false;
        return;
    }

    if(timer_expired32(timer_read32(), action_timeout)) {
        oled_write_raw_P(time_out[now_frame_timeout], FRAME_SIZE);
        if(now_frame_timeout < MAX_FRAME(time_out) - 1)
            ++now_frame_timeout;
        else now_frame_timeout = 0;
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

    if(host_keyboard_led_state().caps_lock != caps_state) {
        if(host_keyboard_led_state().caps_lock) {
            oled_write_raw_P(caps_appear[now_frame_caps_appear], FRAME_SIZE);
            if(now_frame_caps_appear < MAX_FRAME(caps_appear) - 1)
                ++now_frame_caps_appear;
            else caps_state = host_keyboard_led_state().caps_lock;
        }
        else {
            oled_write_raw_P(caps_disappear[now_frame_caps_disappear], FRAME_SIZE);
            if(now_frame_caps_disappear < MAX_FRAME(caps_appear) - 1)
                ++now_frame_caps_disappear;
            else caps_state = host_keyboard_led_state().caps_lock;
        }
    }
    else {
        now_frame_caps_appear = 0;
        now_frame_caps_disappear = 0;
    }

    //默认动画
    if(buffer_top == 0) {
        oled_write_raw_P(default_animation[now_frame_default], FRAME_SIZE);
        if(now_frame_default < MAX_FRAME(default_animation) - 1)
            ++now_frame_default;    //默认动画递增
        else now_frame_default = 0; //默认动画重置（循环）
        return;
    }
    //数字及字母按键动画
    if(record_buffer[buffer_top] >= KC_A && record_buffer[buffer_top] <= KC_0) {
        oled_write_raw_P(a_0_animation[record_buffer[buffer_top] - KC_A][now_frame_a_0], FRAME_SIZE);
        return;
    }
    //其他按键动画
    switch (record_buffer[buffer_top]) {
        case KC_ENTER:
            oled_write_raw_P(enter[now_frame_enter], FRAME_SIZE);
            return;
        case KC_ESC:
            oled_write_raw_P(esc[now_frame_esc], FRAME_SIZE);
            return;
        default:
            return;
    }
}

