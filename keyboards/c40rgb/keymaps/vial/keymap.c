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
        _______ , _______ , _______ ,                   _______ ,          _______ , _______ , TO(4)  , _______
    )
};


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
