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

  /*
   * Qwerty
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_RO,                           JP_MINS,   KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,  \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     JP_CIRC,                         JP_YEN,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    JP_AT,    \
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     JP_LBRC,                         JP_RBRC,   KC_H,     KC_J,     KC_K,    KC_L,    JP_SCLN, JP_COLN,  \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     M_EISU,                          M_KANA,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_UP,   KC_ENT, \
    KC_LALT,  KC_LGUI,  KC_LGUI,            KC_TAB,   RAISE,    KC_LSFT,  KC_SPC,       KC_ENT,  KC_RSFT,   LOWER,              KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /*
   * Lower
   */
  [_LOWER] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC, \
    KC_TAB,   KC_EXLM,  JP_DQT,   KC_HASH,  KC_DLR,   KC_PERC,  JP_CIRC,                          JP_YEN,   JP_AMPR,  JP_QUOT,  JP_LPRN,  JP_RPRN,  XXXXXXX,  XXXXXXX, \
    KC_LCTL,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     JP_LBRC,                          JP_RBRC,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX, \
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  M_EISU,                           M_KANA,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_ENT,  \
    KC_LALT,  KC_LGUI,  KC_LGUI,            KC_TAB,   RAISE,    KC_LSFT,  KC_SPC,       KC_ENT,   KC_RSFT,  LOWER,              KC_SLSH,  KC_HOME,  KC_PGDN,  KC_END   \
  ),

  /*
   * Raise
   */
  [_RAISE] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC, \
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  JP_TILD,                          JP_PIPE,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  XXXXXXX, \
    KC_LCTL,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     JP_LCBR,                          JP_RCBR,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX, \
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  M_EISU,                           M_KANA,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_ENT,  \
    KC_LALT,  KC_LGUI,  KC_LGUI,            KC_TAB,   RAISE,    KC_LSFT,  KC_SPC,       KC_ENT,   KC_RSFT,  LOWER,              KC_SLSH,  KC_HOME,  KC_PGDN,  KC_END   \
  ),

  /*
   * Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|   INC|   DEC|      |                    |      |      |      |      |      |      |      |
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
