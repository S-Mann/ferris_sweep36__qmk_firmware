#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER LT(_LOWER, KC_QUOT)
#define RAISE LT(_RAISE, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |LOWER,'| Enter|    |BckSpc|RAISE,Space| |
 *                  `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_split_3x5_2(
  KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,   KC_Y,    KC_U,          KC_I,         KC_O,         KC_P,
  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F),   KC_G,   KC_H,    RSFT_T(KC_J),  RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),
  KC_Z,         KC_X,         KC_C,         KC_V,           KC_B,   KC_N,    KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,
                                            LOWER,          KC_ENT, KC_BSPC, RAISE
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Left |  Up  | Down | Right| Tab  |           |   `  |   -  |   +  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Home | End  | PgUp | PgDw |      |           |   =  |   /  |   *  |   \  |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_split_3x5_2(
  KC_1,    KC_2,    KC_3,       KC_4,           KC_5,       KC_6,       KC_7,      KC_8,    KC_9,       KC_0,
  KC_LEFT, KC_UP,   KC_DOWN,    KC_RGHT,        KC_TAB,     KC_GRV,     KC_MINS,   KC_PLUS, KC_LBRC,    KC_RBRC,
  KC_HOME, KC_END,  KC_PAGE_UP, KC_PAGE_DOWN,   _______,    KC_EQL,     KC_SLSH,   KC_ASTR, KC_BSLS,    _______,
                                _______,        _______,    _______,     _______
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |   ~  |   _  |      |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|      |      |      |      |           |      |      |      |   |  |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER| Del  |    |      | RAISE|      |
 *                  `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT_split_3x5_2(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  _______, _______, _______, _______,      KC_TILD, KC_UNDS, _______, KC_LCBR, KC_RCBR,
  KC_CAPS, _______, _______, _______, _______,      _______, _______, _______, KC_PIPE, _______,
                             _______, KC_DEL,       _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | Prev | Play | Next | Mute |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | VolDw| VolUp|      |      |      |           |  F11 |  F12 |      |      | Reset|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_split_3x5_2(
  _______,              _______,                _______,                _______,                TO(_QWERTY),    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  _______,              KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_AUDIO_MUTE,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
  KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,        _______,                _______,                _______,        KC_F11,  KC_F12,  _______, _______,  QK_BOOT,
                                                                        _______,                _______,        _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
