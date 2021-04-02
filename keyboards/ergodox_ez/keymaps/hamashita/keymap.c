// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define _______         KC_TRNS
#define XXXXXXX         KC_NO
#define KC_BQ LALT(KC_TILD) // back quote

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
enum {
    L_BASE,      // default layer
    L_CODE,       // navigation
    L_NAV,       // navigation
 //   L_WIN,       // Windows
    L_SYS,      // system
};

enum custom_keycodes {
  C_PLACEHOLDER = SAFE_RANGE, // can always be here
  C_ESC_TILDE,
  C_VRSN,

  C_WH_START,
  C_WH_U      = C_WH_START,
  C_WH_D,
  C_WH_L,
  C_WH_R,
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Home |           | PgUp |   Y  |   U  |   I  |   O  |   P  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|  End |           | PgDn |------+------+------+------+------+--------|
 * |  LSft  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSft   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | LAlt |~LCode| LGUI |                                       | RGUI |~LNav |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BSPC |      |------|       |------| Enter| space|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
// KC_DEL
// C_ESC_TILDE
[L_BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,       KC_2,       KC_3,                KC_4,              KC_5,               XXXXXXX,
        KC_TAB,         KC_Q,       KC_W,       KC_E,                KC_R,              KC_T,               KC_HOME,
        KC_LCTL,        KC_A,       KC_S,       KC_D,                KC_F,              KC_G,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,                KC_V,              KC_B,               KC_END,
        XXXXXXX,        XXXXXXX,    KC_LALT,    MO(L_CODE),           KC_LGUI,
                                                                                        XXXXXXX,            XXXXXXX,
                                                                                                            XXXXXXX,
                                                                     KC_BSPC,           XXXXXXX,            XXXXXXX,
        // right hand
        XXXXXXX,        KC_6,       KC_7,             KC_8,       KC_9,       KC_0,             KC_MINS,
        KC_PGUP,        KC_Y,       KC_U,             KC_I,       KC_O,       KC_P,             KC_BSLS,
                        KC_H,       KC_J,             KC_K,       KC_L,       KC_SCLN,          KC_ENT,
        KC_PGDN,        KC_N,       KC_M,             KC_COMM,    KC_DOT,     KC_SLSH,          KC_RSFT,
                                    KC_RGUI,          MO(L_NAV),  XXXXXXX,    XXXXXXX,          XXXXXXX,
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        XXXXXXX,        KC_ENT,   KC_SPC
    ),
/* Keymap 1: Code Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    `   |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      | PgDn |  MsU | PgUp |      |      |           |      |      |   {  |   }  |   +  |      |  ` / ~ |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | BtnL |  MsL |  MsD |  MsR | BtnR |------|           |------|      |   [  |   ]  |   =  |   '  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  WhD |  WhU |  WhR |  WhL |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[L_CODE] = LAYOUT_ergodox(
       // left hand
       KC_GRV,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,
       _______, XXXXXXX,    KC_PGDN,    KC_MS_U,    KC_PGUP,    XXXXXXX,    _______,
       _______, KC_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,
       _______, C_WH_D,     C_WH_U,     C_WH_R,     C_WH_L,     XXXXXXX,    _______,
       XXXXXXX, XXXXXXX,    XXXXXXX,    _______,    _______,
                                                                _______,    _______,
                                                                            _______,
                                                    _______,    _______,    _______,
       // right hand
       KC_F12,  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
       _______, XXXXXXX,    S(KC_LBRC), S(KC_RBRC), S(KC_EQL),  _______,    KC_GRV,
                KC_BSPC,    KC_LBRC,    KC_RBRC,    KC_EQL,     KC_QUOT,    XXXXXXX,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            _______,    _______,    _______,    _______,    _______,
       _______, _______,
       _______,
       _______, _______,    _______
),
/* Keymap 2: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |BrDown|Bri Up|VoDown|Vol Up|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[L_NAV] = LAYOUT_ergodox(
       // left hand
       KC_GRV,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
       _______, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
       XXXXXXX, XXXXXXX,    XXXXXXX,    _______,    _______,
                                                                _______,    _______,
                                                                            _______,
                                                    _______,    _______,    _______,
       // right hand
       KC_F12,                KC_F6,                 KC_F7,               KC_F8,                  KC_F9,              KC_F10,     KC_DEL,
       XXXXXXX,               KC_BRIGHTNESS_DOWN,    KC_BRIGHTNESS_UP,    KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    XXXXXXX,    XXXXXXX,
                              KC_6,                  KC_7,                KC_8,                   KC_9,               KC_0,       XXXXXXX,
       _______,               XXXXXXX,               XXXXXXX,             XXXXXXX,                XXXXXXX,            XXXXXXX,    XXXXXXX,
                                                     _______,             _______,                _______,            _______,    _______,
       _______, _______,
       _______,
       _______, _______,    _______
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
