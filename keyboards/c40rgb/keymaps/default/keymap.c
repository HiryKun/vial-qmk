#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT (
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_ENT , 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_CAPS, 
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC ,          KC_SPC , KC_RALT, TO(1)  , KC_RCTL 
    ),
    [1] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ ,                   _______ ,          _______ , _______ , TO(2)  , _______   
    ),
    [2] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ ,                   _______ ,          _______ , _______ , TO(3)  , _______ 
    ),
    [3] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,  
        _______ , _______ , _______ ,                   _______ ,          _______ , _______ , TO(4)  , QK_BOOT
    )
};

led_config_t g_led_config = { {
  // 轴灯对应的灯的序号
    {  0,  1,  2,  3,      4,      5,  6,       7,  8,  9, 10,    11 }, 
    { 22, 21, 20, 19,     18,     17,  16,     15, 14, 13, 12, NO_LED}, 
    { 23, 24, 25, 26,     27,     28,  29,     30, 31, 32, 33, NO_LED}, 
    { 41, 40, 39, 38, NO_LED, NO_LED,  37, NO_LED, 36, 35, 34, NO_LED}  
}, {
  // 所有RGB的物理位置
  //       0             1           2            3               4           5            6               7             8              9          10          11
/*0*/  { 0,  0 },  { 24,   0 }, { 41,   0 }, { 61,   0 }, {  81,   0 }, {  103,    0 }, { 124,    0 }, { 142,    0 }, { 162,    0 }, { 183,    0 } ,{ 203,   0 } ,{ 224,  0 },
/*1*/  { 4,  21 }, { 27,  21 }, { 45,  21 }, { 67,  21 }, {  86,  21 }, {  106,   21 }, { 128,   21 }, { 146,   21 }, { 166,   21 }, { 187,   21 } ,{ 217,  21 },
/*2*/  { 8,  43 }, { 33,  43 }, { 52,  43 }, { 73,  43 }, {  93,  43 }, {  114,   43 }, { 134,   43 }, { 155,   43 }, { 175,   43 }, { 196,   43 } ,{ 200,  43 },
/*3*/  { 4,  64 }, { 27,  64 }, { 46,  64 }, { 79,  64 },                               { 130,   64 },                { 172,   64 }, { 196,   64 } ,{ 200,  64 }
}, {
  // 所有RGB的标记（FLAG）
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4,       4,    4, 4, 4, 4
} };

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if(host_keyboard_led_state().caps_lock){
        rgb_matrix_set_color(33, 255, 0, 0);
    }
    /*
    if(get_highest_layer(layer_statr) == 1){         //键盘层级指示灯
        for( uint8_t i = 0; i <=41 ; i++ ){
            if(HAS_FLAGS(g_led_config.flags[i], 0x02)){
                rgb_matrix_set_color(i, 0, 255, 0);
            }
        }

    } 
    */    
    return true;
}

/*
//OLED设置
#ifdef OLED_ENABLE

static const char PROGMEM rhodes_logo[] = {          //rhodes_logo可变

}


bool oled_tast_user(void){
    //OLED要执行的任务
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_raw_P(rhodes_logo,sizeof(rhodes_logo));      // oled_write_raw_P():该函数显示静态画面
            break;
        case 1:
            oled_write_raw_P(rhodes_Fn,sizeof(rhodes_Fn));
            break;
        case 2:
            oled_write_raw_P(rhodes_RGB,sizeof(rhodes_RGB));
            break;
        case 3:
            oled_write_raw_P(rhodes_logo,sizeof(rhodes_logo));
            break;
    }
    return false;
}
#endif
*/
