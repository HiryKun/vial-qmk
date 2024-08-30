#ifdef RGB_MATRIX_ENABLE

// The number of LEDs connected
#define RGB_MATRIX_LED_COUNT 100
//#define NO_RGB_MATRIX

//#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // 启用帧缓冲效果。这允许RGB矩阵使用更复杂的动画效果
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
//#define ENABLE_RGB_MATRIX_TYPING_HEATMAP// 启用打字热图效果。
#define REACTIVE_CUSTOM
#endif

/*via*/
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 1
/*vial*/

/* Encoder */
#ifdef ENCODER_ENABLE
#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { E6 }

//#    define ENCODER_DIRECTION_FLIP  //
#endif
