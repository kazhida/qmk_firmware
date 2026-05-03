# MCU name
MCU = atmega32u4

# Bootloader selection
#BOOTLOADER = atmel-dfu
BOOTLOADER = caterina

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
I2C_DRIVER_REQUIRED = yes

#RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812

# custom matrix setup
CUSTOM_MATRIX = lite
SRC += matrix.c
# SRC += gabunshitu/modulo/atmega32u4/i2c_master.c
SRC += gabunshitu/modulo/atmega32u4/ti_xpa95xx/expander.c
