#include QMK_KEYBOARD_H
#include "bootloader.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _DVORAK,
  _EUCALYN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  EUCALYN,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EISU,
  KANA,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define CMD_M     LGUI_T(KC_M)
#define SFT_G     LSFT_T(KC_G)
#define OPT_B     LALT_T(KC_B)
#define CNTL_T    LCTL_T(KC_T)
#define CNTL_S    RCTL_T(KC_S)
#define CMD_P     RGUI_T(KC_P)
#define SFT_N     RSFT_T(KC_N)
#define OPT_SLSH  RALT_T(KC_SLSH)
#define C_Y       LCTL(KC_Y)
#define C_Z       LCTL(KC_Z)
#define C_S_Z     LCTL(LSFT(KC_Z))
//#define RAISE_E   LT(RAISE, EISU)
//#define LOWER_K   LT(LOWER, KANA)

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * Qwerty
   */
  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /*
   * Dvorak
   */
  [_DVORAK] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL, \
      KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC, KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, EISU,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /*
   * Eucalyn
   */

  [_EUCALYN] = LAYOUT( \
      KC_Q,     KC_A,     KC_Z,     CMD_M,    SFT_G,    OPT_B,                    OPT_B,    SFT_G,    CMD_M,    KC_Z,     KC_A,     KC_Q,     \
      KC_W,     KC_O,     KC_X,     KC_R,     CNTL_T,   KC_H,                     KC_H,     CNTL_T,   KC_R,     KC_X,     KC_O,     KC_W,     \
      KC_COMM,  KC_E,     KC_C,     KC_D,     KC_K,     KC_J,                     KC_J,     KC_K,     KC_D,     KC_C,     KC_E,     KC_COMM,  \
      KC_DOT,   KC_I,     KC_V,     KC_Y,     CNTL_S,   KC_L,     RAISE,  RAISE,  KC_L,     CNTL_S,   KC_Y,     KC_V,     KC_I,     KC_DOT,   \
      KC_SCLN,  KC_U,     KC_F,     CMD_P,    SFT_N,    OPT_SLSH, LOWER,  LOWER,  OPT_SLSH, SFT_N,    CMD_P,    KC_F,     KC_U,     KC_SCLN   \
      ),

  /*
   * Lower
   */

  [_LOWER] = LAYOUT( \
      KC_1,     KC_6,     KC_MINS,  KC_LGUI,  KC_LSFT,  KC_LALT,                  KC_LALT,  KC_LSFT,  KC_LGUI,  KC_MINS,  KC_6,     KC_1, \
      KC_2,     KC_7,     KC_EQL,   KC_LBRC,  KC_LCTL,  KC_LEFT,                  KC_LEFT,  KC_RCTL,  KC_LBRC,  KC_EQL,   KC_7,     KC_2, \
      KC_3,     KC_8,     KC_QUOT,  KC_RBRC,  KC_UP,    KC_DOWN,                  KC_DOWN,  KC_UP,    KC_RBRC,  KC_QUOT,  KC_8,     KC_3, \
      KC_4,     KC_9,     KC_GRV,   KANA,     KC_RCTL,  KC_RGHT,  RAISE,  RAISE,  KC_RGHT,  KC_RCTL,  KANA,     KC_GRV,   KC_9,     KC_4, \
      KC_5,     KC_0,     KC_BSLS,  KC_RGUI,  KC_RSFT,  KC_RALT,  LOWER,  LOWER,  KC_RALT,  KC_RSFT,  KC_RGUI,  KC_ENT,   KC_0,     KC_5  \
      ),

  /*
   * Raise
   */

  [_RAISE] = LAYOUT( \
      KC_F1,    KC_F5,    KC_F9,    KC_LGUI,  KC_ESC,   KC_TAB,                   KC_TAB,   KC_ESC,   KC_LGUI,  KC_F9,    KC_F5,    KC_F1,  \
      KC_F2,    KC_F6,    KC_F10,   C_Z,      KC_LCTL,  KC_HOME,                  KC_HOME,  KC_LCTL,  C_Z,      KC_F10,   KC_F6,    KC_F2,  \
      KC_F3,    KC_F7,    KC_F11,   C_S_Z,    KC_PGUP,  KC_PGDN,                  KC_PGDN,  KC_PGUP,  C_S_Z,    KC_F11,   KC_F7,    KC_F3,  \
      KC_F4,    KC_F8,    KC_F12,   EISU,     KC_RCTL,  KC_END,   RAISE,  RAISE,  KC_END,   KC_RCTL,  EISU,     KC_F12,   KC_F8,    KC_F4,  \
      KC_BSPC,  KC_SPC,   KC_ENT,   KC_RGUI,  KC_RSFT,  KC_RALT,  LOWER,  LOWER,  KC_RALT,  KC_RSFT,  KC_RGUI,  KC_ENT,   KC_SPC,   KC_BSLS \
      ),

  /*
   * Adjust (Lower + Raise)
   */
  [_ADJUST] =  LAYOUT( \
      RESET,    RGBRST,   _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  RGBRST,   RESET,    \
      _______,  _______,  AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,                      AG_SWAP,  AG_NORM,  AU_OFF,   AU_ON,    _______,  _______,  \
      _______,  _______,  _______,  QWERTY,   DVORAK,   EUCALYN,                      EUCALYN,  DVORAK,   QWERTY,  _______,  _______,  _______,  \
      _______,  _______,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_TOG,  _______,  _______,  \
      _______,  _______,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_MOD,  _______,  _______   \
      )
};

#else
#error "undefined keymaps"
#endif


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
#ifdef RGBLIGHT_ENABLE
    //rgblight_mode(RGB_current_mode);
#endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(tone_qwerty);
#endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case EUCALYN:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(tone_colemak);
#endif
        persistent_default_layer_set(1UL<<_EUCALYN);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(tone_dvorak);
#endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
#ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
#endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
#ifdef RGBLIGHT_ENABLE
        //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
#endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
#ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGBLIGHT_MODE_SNAKE);
#endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
#ifdef RGBLIGHT_ENABLE
        //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
#endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
#ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
#endif
      return false;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
#endif
      break;
  }
  return true;
}

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  startup_user();
#endif
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_RAISE:
           matrix_write_P(matrix, PSTR("Raise"));
           break;
        case L_LOWER:
           matrix_write_P(matrix, PSTR("Lower"));
           break;
        case L_ADJUST:
        case L_ADJUST_TRI:
           matrix_write_P(matrix, PSTR("Adjust"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
