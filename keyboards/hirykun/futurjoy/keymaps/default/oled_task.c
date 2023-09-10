#include "animation.c"

#define BUFFER_SIZE 10

uint8_t record_buffer[BUFFER_SIZE + 2] = {0};
uint8_t buffer_index[256] = {0};
uint8_t buffer_top = 0;

uint8_t now_frame_enter = 0;

void oled_animation(void) {
    if(record_buffer[buffer_top] == KC_ENTER) {
        oled_write_raw_P(enter[now_frame_enter], FRAME_SIZE);
		if(now_frame_enter < sizeof(enter) / sizeof(enter[0]) - 1) ++now_frame_enter;
    }
    else if(buffer_top == 0) oled_write_raw_P(enter[0], FRAME_SIZE);
}