MCU_LDSCRIPT = STM32F103xB
# Bootloader selection
# Cannot use `BOOTLOADER = stm32duino` due to the need to override
# `MCU_LDSCRIPT`, therefore all parameters need to be specified here manually.

# EEPROM emulation not supported yet (need to implement a proper firmware size
# check first, otherwise the chance of the EEPROM backing store overwriting
# some part of the firmware code is really high).
