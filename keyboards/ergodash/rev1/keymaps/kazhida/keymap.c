#include QMK_KEYBOARD_H
#include "keymap_jp.h"

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
  M_EISU,
  M_KANA
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |   BS |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Home | Tab  |  Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   @  |   [  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgUp | Ctrl | 	A   |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   :  |   ]  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgDn | Shift| 	Z   |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |   ▲  | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | End  | Opt  | Cmd  | |||| | Raise| Eisu | Cmd  | Space| |||| |  Ent | Kana | Opt  | Lower| |||| |  ◀  |   ▼  |  ▶  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_BSPC, \
    KC_HOME, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,   JP_LBRC, \
    KC_PGUP, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_COLN, JP_RBRC, \
    KC_PGDN, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT, \
    KC_END,  KC_LALT, KC_LGUI,          KC_SPC,  KC_SPC,  RAISE,   KC_SPC,           KC_ENT,  LOWER,   KC_ENT,           KC_RO,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   BS |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Home | Tab  |  Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   @  |   [  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgUp | Ctrl | 	A   |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   :  |   ]  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgDn | Shift| 	Z   |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ^  |   ¥  |   \  | PgUp | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | End  | Opt  | Cmd  | |||| | Raise| Eisu | Cmd  | Space| |||| |  Ent | Kana | Opt  | Lower| |||| | Home | PgDn | End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, KC_ENT,  \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, KC_ENT,  \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, JP_CIRC, JP_YEN,  _______, KC_PGUP, _______, \
    KC_END,  KC_LALT, KC_LGUI,          KC_SPC,  KC_SPC,  RAISE,   M_EISU,           M_KANA,  LOWER,   KC_ENT,           KC_RO,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   BS |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Home | Tab  |  Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   @  |   [  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgUp | Ctrl | 	A   |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   :  |   ]  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | PgDn | Shift| 	Z   |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ~  |   |  |   _  | PgUp | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | End  | Opt  | Cmd  | |||| | Raise| Eisu | Cmd  | Space| |||| |  Ent | Kana | Opt  | Lower| |||| | Home | PgDn | End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, KC_ENT,  \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, KC_ENT,  \
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, JP_CIRC, JP_YEN,  _______, KC_PGUP, _______, \
      KC_END,  KC_LALT, KC_LGUI,          KC_SPC,  KC_SPC,  RAISE,   M_EISU,           M_KANA,  LOWER,   KC_ENT,         KC_RO,   KC_LEFT, KC_DOWN, KC_RGHT  \
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
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case M_EISU:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui==false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
    case M_KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
  }
  return true;
}
