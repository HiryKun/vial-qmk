#include "animation.c"

#define BUFFER_SIZE 10

uint8_t record_buffer[BUFFER_SIZE + 2] = {0};   //按键记录区
uint8_t buffer_index[256] = {0};    //keycode对应记录区下标
uint8_t buffer_top = 0; //记录区顶部

uint8_t a_0_regitster = 0;  //数字及字母计数器
bool fn_layer_appear = false;   //是否进入过Fn层

//动画当前帧
uint8_t now_frame_a_0 = 0;
uint8_t now_frame_esc = 0;
uint8_t now_frame_enter = 0;
uint8_t now_frame_default = 0;
uint8_t now_frame_fn_appear = 0;
uint8_t now_frame_fn_disappear = 0;

void oled_animation(void) {
    //Fn出现动画
    if(get_highest_layer(layer_state) == 1) {
        oled_write_raw_P(fn_appear[now_frame_fn_appear], FRAME_SIZE);
        if(now_frame_enter < sizeof(fn_appear) / FRAME_SIZE - 1) ++now_frame_fn_appear;
        now_frame_fn_disappear = 0;
        fn_layer_appear = true;
        return;
    }
    //Fn消失动画
    else if(fn_layer_appear) {
            oled_write_raw_P(fn_disappear[now_frame_fn_disappear], FRAME_SIZE);
            if(now_frame_fn_disappear < sizeof(fn_disappear) / FRAME_SIZE - 1)
                ++now_frame_fn_disappear;
            else {
                fn_layer_appear = false;
                now_frame_fn_appear = 0;
            }
            return;
    }
    //默认动画
    if(buffer_top == 0) {
        oled_write_raw_P(default_animation[now_frame_default], FRAME_SIZE);
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

