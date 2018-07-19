/* Copyright 2018 Thomas HUMMEL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"
#include "keymap_bepo.h"
#include "keymap_french.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _AZERTY,
  _BEPO,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  AZERTY,
  BEPO,
  DISNEY
};

#define SFTENT_KEY KC_ENT  /* https://docs.qmk.fm/#/feature_space_shift_cadet */
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Raise|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Ctrl | Alt  | GUI  |Tab   |    Space    |Back  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {RAISE,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {LOWER,   KC_LCTL, KC_LGUI, KC_RALT, KC_TAB,  KC_SPC,  KC_SPC,  KC_BSPC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* AZERTY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | shift|   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Raise|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |   =  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower|Ctrl | Alt  | GUI   |Tab   |    Space    |Back | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = {
  {KC_ESC,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC},
  {KC_LSFT, KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_M,     KC_QUOT},
  {RAISE,   KC_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    FR_COMM, FR_SCLN, FR_COLN, KC_EQUAL, KC_ENT },
  {LOWER,   KC_LCTL, KC_LGUI, KC_RALT, KC_TAB,  KC_SPC,  KC_SPC,  KC_BSPC,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT}
},

/* Bépo
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |  W   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   À  |   Y  |   X  |   .  |   K  |   '  |   Q  |   G  |   H  |   F  |  Z   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|Ctrl  | Alt  | GUI  | Space|Lower | Back |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = {
  {KC_ESC,  BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE, BP_DEAD_CIRCUMFLEX, BP_V,    BP_D,    BP_L,    BP_J,  BP_W},
  {KC_TAB,  BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,   BP_C,               BP_T,    BP_S,    BP_R,    BP_N,  BP_M},
  {KC_LSFT, BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,       BP_APOS,            BP_Q,    BP_G,    BP_H,    BP_F,  BP_Z},
  {RAISE,   KC_LCTL,    KC_LGUI,    BP_ALGR, KC_SPC , LOWER,      KC_BSPC,            KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |  Prev|  Play|  Next| Mute |  Vol-| Vol+ |  Back|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ç   | Left | Down | Up   | Right| Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |c. tab|  cut | copy | paste|n. tab| Undo |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Rename|      |      |Del   | Enter|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______,     _______,      _______,     KC_MPRV,    KC_MPLY,      KC_MNXT,     KC__MUTE, KC_VOLD, KC_VOLU,  KC_BSPC},
  {_______, _______, _______,     _______,      _______,     _______,    BP_C_CEDILLA, KC_LEFT,     KC_DOWN,  KC_UP,   KC_RIGHT, KC_ENT},
  {_______, _______, LCTL(BP_W), LCTL(BP_X),  LCTL(BP_C), LCTL(BP_P),    LCTL(BP_T),  LCTL(BP_Z), _______,  _______, _______,  _______},
  {_______, _______, _______,     LCTL(KC_F2), _______,     _______,     KC_DEL,      KC_ENT,      _______,  _______, _______,  _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  #   |  1   |   2  |   3  |  4   |   5  |   6  |   7  |  8   |   9  |  0   |  Back|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  |   |   \  |   <  |   {  |  (   |   [  |   ]  |   )  |   }  |   >  |  /   |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   '  |   `  |   %  |   :  |   .  |  &   |   ,  |   *  |   +  |  -   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  €   |  @   |  _   |      |Del   | Enter|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {BP_HASH, BP_1,            BP_2,       BP_3,                BP_4,          BP_5,        BP_6,         BP_7,           BP_8,                 BP_9,       BP_0,     KC_BSPC},
  {BP_PIPE, BP_BACKSLASH,    BP_LESS,    BP_LEFT_CURLY_BRACE, BP_LEFT_PAREN, BP_LBRACKET, BP_RBRACKET,  BP_RIGHT_PAREN, BP_RIGHT_CURLY_BRACE, BP_GREATER, BP_SLASH, KC_ENT},
  {_______, BP_APOS,         BP_PERCENT, BP_GRAVE,            BP_COLON,      BP_DOT,      BP_AMPERSAND, BP_COMMA,       BP_ASTERISK,          BP_PLUS,    BP_MINUS, BP_EQUAL},
  {_______, BP_DOUBLE_QUOTE, BP_EURO,    BP_AT,               BP_UNDERSCORE, _______,     KC_DEL,      KC_ENT,         _______,              _______,    _______,  _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Azerty| Bépo |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______,  _______,   _______,  _______, _______, BEPO,  AZERTY, QWERTY,  _______,  _______},
  {_______, _______,  _______,  MU_ON,   MU_OFF,  _______,   _______,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float tone_startup[][2]   = SONG(STARTUP_SOUND);
  float tone_qwerty[][2]    = SONG(QWERTY_SOUND);
  float tone_dvorak[][2]    = SONG(DVORAK_SOUND);
  float tone_colemak[][2]   = SONG(COLEMAK_SOUND);
  float music_scale[][2]    = SONG(MUSIC_SCALE_SOUND);
  float tone_disney[][2]    = SONG(DISNEY_SONG);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
         #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case AZERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        set_single_persistent_default_layer(_AZERTY);
      }
      return false;
      break;
    case BEPO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        set_single_persistent_default_layer(_BEPO);
      }
      return false;
      break;
    case DISNEY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_disney);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
