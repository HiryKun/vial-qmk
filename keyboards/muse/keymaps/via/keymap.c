#include QMK_KEYBOARD_H

enum layer_names {
    _BASE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
	      	            KC_3,   KC_4,	 KC_5,   KC_A,	KC_W,	         	             	            KC_1,   KC_1,	 KC_1,   KC_1,	KC_1,	         	                 
        KC_1   ,   KC_1,   KC_A,	 KC_G,	 KC_1,	KC_D,   KC_1,	             KC_1   ,   KC_1,   KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	             KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,KC_1,    	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,
        	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,KC_1,    	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,
        	         	         	         	         	           KC_1,	         	             	         	         	         	         	           KC_1	 
																	           	    ),
  [1] = LAYOUT(
	      	            KC_1,   KC_1,	 KC_1,   KC_1,	KC_1,	         	             	            KC_1,   KC_1,	 KC_1,   KC_1,	KC_1,	         	                 
        KC_1   ,   KC_1,   KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	             KC_1   ,   KC_1,   KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	             KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,KC_1,    	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,
        	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,KC_1,    	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,
        	         	         	         	         	           KC_1,	         	             	         	         	         	         	           KC_1	 
																	           	    ),


  [2] = LAYOUT(
	      	            KC_1,   KC_1,	 KC_1,   KC_1,	KC_1,	         	             	            KC_1,   KC_1,	 KC_1,   KC_1,	KC_1,	         	                 
        KC_1   ,   KC_1,   KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	             KC_1   ,   KC_1,   KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	             KC_1   ,   KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,	         
        	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,KC_1,    	            KC_1,	 KC_1,	 KC_1,	 KC_1,	KC_1,   KC_1,   KC_1,
        	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,KC_1,    	         	            KC_1,	 KC_1,	           KC_1,   KC_1,   KC_1,
        	         	         	         	         	           KC_1,	         	             	         	         	         	         	           KC_1	 
																	           	    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),           ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),           ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
};
#endif
