#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 2
#define _TOOLS 3


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  TOOLS

};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             .-----------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtEnt |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |(none)|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Sh(  |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Sh)  |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * | L2   | GUI  | Alt  |(none)| LOWER| Bspc |CtDel ||Enter|Space |(none)|  Left| Up   | Down | Right|
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GESC,          KC_1,    KC_2,    KC_3,     KC_4,       KC_5,                                 KC_6,     KC_7,        KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,           KC_Q,    KC_W,    KC_E,     KC_R,       KC_T,                                 KC_Y,     KC_U,        KC_I,    KC_O,    KC_P,    KC_BSLS, \
    LCTL(KC_ENT),     KC_A,    KC_S,    KC_D,     KC_F,       KC_G,                                 KC_H,     KC_J,        KC_K,    KC_L,    KC_QUOT, _______, \
    KC_LSPO,          KC_Z,    KC_X,    KC_C,     KC_V,       KC_B,                                 KC_N,     KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
    LALT(KC_LSFT),    KC_LGUI, KC_LALT, _______,  MO(_LOWER), KC_BSPC, LCTL_T(KC_SPACE),  KC_ENT,   KC_SPACE, MO(_TOOLS),  KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT \
  ),

  /* LOWER
   * ,-----------------------------------------.             .-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |             |   Del| Home |  Up  | End  |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  ^   |  &   |  *   |  =   |  [   |             |   ]  |Left  | Down |  Rt  |   ;  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | CtIns|      |      |      |      |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * | WinL |      |      |      |      |      |      ||     |      |      |      |      |      |CtAltD|
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     _______, _______,       _______, _______, _______, _______, \
    _______,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_DEL,  KC_HOME,       KC_UP,   KC_END,  _______, _______, \
    _______,    KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_LBRC,                   KC_RBRC, KC_LEFT,       KC_DOWN, KC_RGHT, KC_SCLN, _______, \
    _______,    _______, _______, _______, _______, _______,                   _______, LCTL(KC_INS),  _______, _______, _______, _______, \
    LGUI(KC_L), _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, LCTL(LALT(KC_DEL)) \
  ),

  /* TOOLS
   * ,-----------------------------------------.             .-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGBSAI|RGBVAI|RGBSAD| RESET|      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGBHUD|RGBVAD|RGBHUI|RGBTOG|      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      | Pause| Back | Next |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * |      |      |      |RGBMOD|      |      |      ||     |      |      |      | Mute | VOLUP| VOLDN|
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_TOOLS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   _______,                   _______, _______, _______, _______, _______, _______, \
    _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_TOG, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, \
    _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD \
  ),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    //case COLEMAK:
      //if (record->event.pressed) {
        //#ifdef AUDIO_ENABLE
          //PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        //#endif
        //persistant_default_layer_set(1UL<<_COLEMAK);
      //}
      //return false;
      //break;
  }
  return true;
}
