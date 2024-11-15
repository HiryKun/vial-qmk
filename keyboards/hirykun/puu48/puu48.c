#include QMK_KEYBOARD_H

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) { 
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    switch (index)
    {
    case 0:
        if(active) {
            register_code16(KC_1);
        }
        else {
            unregister_code16(KC_1);
        }
        
        break;
    case 1:
        if(active) {
            register_code16(KC_2);
        }
        else {
            unregister_code16(KC_2);
        }
        break;
    case 2:
        if(active) {
            register_code16(KC_3);
        }
        else {
            unregister_code16(KC_3);
        }
        break;
    case 3:
        if(active) {
            register_code16(KC_4);
        }
        else {
            unregister_code16(KC_4);
        }
        break;
    case 4:
        if(active) {
            register_code16(KC_5);
        }
        else {
            unregister_code16(KC_5);
        }
        break;
    case 5:
        if(active) {
            register_code16(5);
        }
        else {
            unregister_code16(5);
        }
        break;
    default:
        break;
    }
    return true;
}
#endif