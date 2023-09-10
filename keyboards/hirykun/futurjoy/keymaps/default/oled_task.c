#include "animation.c"

#define BUFFER_SIZE 10

uint8_t record_buffer[BUFFER_SIZE + 2] = {0};
uint8_t buffer_index[256] = {0};
uint8_t buffer_top = 0;

uint8_t a_0_regitster = 0;

uint8_t now_frame_a_0 = 0;
uint8_t now_frame_enter = 0;

void oled_animation(void) {
    if(record_buffer[buffer_top] >= KC_A && record_buffer[buffer_top] <= KC_0) {
        oled_write_raw_P(a_0_animation[record_buffer[buffer_top] - KC_A][now_frame_a_0], FRAME_SIZE);
        return;
    }
    switch (record_buffer[buffer_top]) {
        case KC_ENTER:
            oled_write_raw_P(enter[now_frame_enter], FRAME_SIZE);
            if(now_frame_enter < sizeof(enter) / sizeof(enter[0])) ++now_frame_enter;
            return;
        default:
            if(buffer_top == 0) oled_write_raw_P(enter[0], FRAME_SIZE);
            return;
    }
}

