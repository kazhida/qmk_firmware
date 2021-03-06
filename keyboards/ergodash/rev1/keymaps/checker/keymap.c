#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
 * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
 * ,----------------------------------------------------------------------------------------------------------------------.
 */
[_QWERTY] = LAYOUT( \
    KC_A,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,                  KC_RCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_S, \
    KC_B,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_M,                        KC_E, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_M, \
    KC_C,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_L ,                       KC_D, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_L, \
    KC_D,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K ,                       KC_C, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_K, \
    KC_E,  KC_F,    KC_G,    KC_H,             KC_I,    KC_J , KC_N,         KC_A,   KC_B, KC_F,             KC_G,    KC_H,    KC_I,    KC_J  \
  ),

/* Lower
 * ,----------------------------------------------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
 * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
 * ,----------------------------------------------------------------------------------------------------------------------.
 */
[_LOWER] = LAYOUT(
    KC_A,  KC_O,    KC_1,    KC_2,    KC_3,    KC_4,    KC_LCBR,                  KC_RCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_S, \
    KC_B,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_M,                        KC_E, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_M, \
    KC_C,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_L ,                       KC_D, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_L, \
    KC_D,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K ,                       KC_C, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_K, \
    KC_E,  KC_F,    KC_G,    KC_H,             KC_I,    KC_J , KC_N,         KC_A,   KC_B, KC_F,             KC_G,    KC_H,    KC_I,    KC_J  \
  ),

/* Raise
 * ,----------------------------------------------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
 * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
 * ,----------------------------------------------------------------------------------------------------------------------.
 */
[_RAISE] = LAYOUT(
    KC_A,  KC_O,    KC_1,    KC_2,    KC_3,    KC_4,    KC_LCBR,                  KC_RCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_S, \
    KC_B,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_M,                        KC_E, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_M, \
    KC_C,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_L ,                       KC_D, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_L, \
    KC_D,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K ,                       KC_C, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_K, \
    KC_E,  KC_F,    KC_G,    KC_H,             KC_I,    KC_J , KC_N,         KC_A,   KC_B, KC_F,             KC_G,    KC_H,    KC_I,    KC_J  \
  ),

/* Adjust
 * ,----------------------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
 * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
 * ,----------------------------------------------------------------------------------------------------------------------.
 */
[_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}
