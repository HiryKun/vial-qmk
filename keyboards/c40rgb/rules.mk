MCU = STM32F103            #MCU型号

BOOTLOADER = stm32duino

NKRO_ENABLE = yes          #开启全键无冲

EXTRAKEY_ENABLE = yes      #控制音量等操作（额外键）

#LTO_ENABLE = yes          #AVR主控（MCU内存空间较小时开启）

#ENCODER_ENABLE = yes      #编码器开关

#OLED_ENABLE = yes         #OLED功能

RGB_MATRIX_ENABLE = yes    #RGB矩阵
RGB_MATRIX_DRIVER = WS2812

#NO
BOOTMAGIC_ENABLE = no      #按住某键进入BOOTLODER模式
RGBLIGHT_ENABLE = no
CONSOLE_ENABLE = no        #Console for debug(+400)
COMMAND_ENABLE = no        #Command for debug and configuration
MOUSEKEY_ENABLE = no       #模拟鼠标
SLEEP_LED_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
AUDIO_ENABLE = no
BACKLIGHT_ENABLE = no
