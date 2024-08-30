#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool group_2:1;
    uint8_t group_1:8;
    uint8_t group_3:8;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.group_1 = 0xFF; // We want this enabled by default
  user_config.group_2 = 0;
  user_config.group_3 = 0xFF;
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index

  { 3,  4,  5, 6,  7, 8, 9,  10,  11,  12, 13, 14, 15},
  {  26,27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 16},
  { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 38},
  { 48, 49,50, NO_LED,NO_LED,51, NO_LED,NO_LED,NO_LED,52, 53, 54, 55},
  { 81, NO_LED, 0, 1, 2,         17, 18, 19,           20, 21, 22,NO_LED,NO_LED },
  { 85, NO_LED,23, 24, 25,       39, 40, 41,           42, 43, 44,NO_LED,NO_LED},
  { NO_LED,NO_LED, 45, 46, 47,    NO_LED, 60,NO_LED,       61, 62,63,NO_LED,NO_LED },
  { NO_LED,NO_LED, 64, 65, 66,    75, 76, 77,             78, 79, 80, NO_LED,NO_LED}



}, {
  // LED Index to Physical Position
            {9, 0}, {19, 0}, {28, 0},      {40, 0}, {51, 0}, {61, 0}, {70, 0}, {79, 0}, {89, 0}, {98, 0}, {107, 0}, {117, 0}, {126, 0}, {135, 0}, {145, 0}, {154, 0}, {166, 0},          {177, 0}, {187, 0}, {196, 0},      {205, 0}, {215, 0}, {224, 0},
            {9, 21},{19, 21}, {28, 21},   {41, 21}, {54, 21}, {63, 21}, {72, 21}, {82, 21}, {91, 21}, {100, 21}, {110, 21}, {119, 21}, {128, 21}, {138, 21}, {147, 21}, {162, 21},      {177, 21}, {187, 21}, {196, 21},   {205, 21}, {215, 21}, {224, 21},
            {9, 43}, {19, 43}, {28, 43},   {43, 43}, {58, 43}, {68, 43}, {77, 43}, {86, 43}, {96, 43}, {105, 43}, {114, 43}, {124, 43}, {133, 43}, {142, 43},        {160, 43},                     {187, 43},              {205, 43}, {215, 43}, {224, 43},
            {9, 64}, {19, 64}, {28, 64},   {38, 64}, {50, 64}, {62, 64},                     {97, 64},                                  {132, 64}, {144, 64}, {155, 64}, {167, 64},      {177, 64}, {187, 64}, {196, 64},   {205, 64}, {215, 64}, {224, 64},


    {0, 0},{0,10},{0,30},{0,50},{0, 64},
     {0,11},                    {28,11},                       {70,11},                            {107,11},                            {140,11},                              {182,11},                            {219,11},
     {0,50},                    {28,50},                       {70,50},                            {107,50},                            {140,50},                              {182,50},                            {219,50},
}, {
  // LED Index to Flag
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4,


      4, 2, 2, 2, 4,
      2, 2, 2, 2, 2, 2, 2,
      2, 2, 2, 2, 2, 2, 2,
} };

bool rgb_matrix_indicators_kb(void) {
    rgb_matrix_set_color_all(0, 0, 0);
    if(current_led_count <= 3){
        if(user_config.group_1 != current_led_count){
            user_config.group_1 = current_led_count;
            eeconfig_update_user(user_config.raw);
        }
        current_led_count = 0xFF;
    }
    else if(current_led_count == 5 ){
        user_config.group_2 ^= 1;
        eeconfig_update_user(user_config.raw);
        current_led_count = 0xFF;
    }
    else if(current_led_count >= 6 && current_led_count <= 8){
        if(user_config.group_3 != current_led_count){
            user_config.group_3 = current_led_count;
            eeconfig_update_user(user_config.raw);
        }
        current_led_count = 0xFF;
    }
    if(user_config.group_1 != 0xFF) rgb_matrix_set_color(user_config.group_1, RGB_YELLOW);
    if(user_config.group_2 == 1) rgb_matrix_set_color(5, RGB_RED);
    if(user_config.group_3 != 0xFF) rgb_matrix_set_color(user_config.group_3, RGB_BLUE);
    return true;
}

#endif
