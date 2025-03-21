#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _QWERTY,
    _SYMBOL,
    _NUMBER,
    _NAV,
    _MOUSE,
    _MEDIA
};

#define LGUI_PLUS   LGUI_T(KC_PLUS)
#define LALT_LPRN   LALT_T(KC_LPRN)
#define LCTL_DQUO   LCTL_T(KC_DQUO)
#define LSFT_RPRN   LSFT_T(KC_RPRN)
#define RSFT_LCBR   RSFT_T(KC_LCBR)
#define RALT_RCBR   RALT_T(KC_RCBR)

/*
#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP
*/

// TODO: _BASE and _QWERTY there are 2 ESC. need to define a key on the right
// Function to determine the current tapdance state

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // https://getreuer.info/posts/keyboards/faqs/index.html#mt-doesnt-work-with-this-keycode-qmk
    switch (keycode) {
        case LGUI_PLUS:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_PLUS);
                }
                return false;  // Skip default handling.
            }
            break;
        case LALT_LPRN:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_LPRN);
                }
                return false;  // Skip default handling.
            }
            break;
        case LCTL_DQUO:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_DQUO);
                }
                return false;  // Skip default handling.
            }
            break;
        case LSFT_RPRN:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_RPRN);
                }
                return false;  // Skip default handling.
            }
            break;
        case RSFT_LCBR:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_LCBR);
                }
                return false;  // Skip default handling.
            }
            break;
        case RALT_RCBR:  // LEFT Command layer on hold, KC_PLUS on tap.
            if (record->tap.count) {  // On tap.
                if (record->event.pressed) {  // On press.
                    tap_code16(KC_RCBR);
                }
                return false;  // Skip default handling.
            }
            break;

    }
    return true;  // Continue default handling.
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // base layer; colemak DH
	[_BASE] = LAYOUT_split_3x6_3(
            KC_TAB,     KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                               KC_J,   KC_L,           KC_U,           KC_Y,           KC_SCLN,            KC_BSLS,
            KC_ESC,     LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   KC_G,                               KC_M,   RSFT_T(KC_N),   RCTL_T(KC_E),   RALT_T(KC_I),   RGUI_T(KC_O),       KC_QUOT,
            KC_LSFT,    KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                               KC_K,   KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_RSFT,
                                LT(_MEDIA, KC_ESC),     LT(_NAV, KC_SPC),     LT(_MOUSE, KC_TAB),                           LT(_SYMBOL, KC_ENT),    LT(_NUMBER, KC_BSPC),   LT(_SYMBOL, KC_DEL)
            ),

    // QWERTY LAYER
	[_QWERTY] = LAYOUT_split_3x6_3(
            KC_TAB,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                               KC_Y,   KC_U,           KC_I,           KC_O,           KC_P,               KC_BSLS,
            KC_LCTL,    LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                               KC_H,   RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),    KC_QUOT,
            KC_LSFT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                               KC_N,   KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_RSFT,
                                                                _______, _______, _______,                                  _______, _______, _______
            ),

    // symbol layer
	[_SYMBOL] = LAYOUT_split_3x6_3(
            _______,    KC_EXLM,            KC_AT,              KC_HASH,            KC_DLR,          KC_PERC,               KC_CIRC,    KC_AMPR,            KC_ASTR,            KC_LBRC,            KC_RBRC,            _______,
            _______,    LGUI_T(KC_PLUS),    LALT_T(KC_LPRN),    LCTL_T(KC_DQUO),    LSFT_T(KC_RPRN), KC_QUOTE,              KC_COLN,    RSFT_T(KC_LCBR),    RCTL_T(KC_EQL),     RALT_T(KC_RCBR),    RGUI_T(KC_SCLN),    _______,
            _______,    KC_LABK,            KC_PIPE,            KC_MINS,            KC_RABK,         KC_BACKSLASH,          KC_GRV,     KC_UNDS,            KC_QUES,            KC_TILD,            _______,            _______,
                                                                                    _______, _______, _______,              _______, _______, _______
            ),

	[_NUMBER] = LAYOUT_split_3x6_3(
            _______,    KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,                            _______,    _______,    _______,        _______,        _______,            _______,
            _______,    KC_SCLN,        KC_4,           KC_5,           KC_6,           KC_EQL,                             _______,    KC_RSFT,    KC_RCTL,        KC_RALT,        KC_RGUI,            _______,
            _______,    KC_GRV,         KC_1,           KC_2,           KC_3,           KC_BSLS,                            _______,    _______,    _______,        KC_LALT,        _______,            _______,
                                        KC_DOT,         KC_0,           KC_MINUS,                                           _______,    _______,    _______
            ),

	[_NAV] = LAYOUT_split_3x6_3(
            _______,    _______,        _______,        _______,        _______,        _______,                            _______,    _______,    _______,        _______,        _______,            _______,
            _______,    KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        _______,                            KC_LEFT,    KC_DOWN,    KC_UP,          KC_RGHT,        _______,            _______,
            _______,    _______,        _______,        _______,        _______,        _______,                            KC_HOME,    KC_PGDN,    KC_PGUP,        KC_END,         _______,            _______,
                                        _______,        _______,        _______,                                            _______,    _______,    _______
            ),

	[_MOUSE] = LAYOUT_split_3x6_3(
            _______,    _______,        _______,        _______,        _______,        _______,                            _______,    _______,    _______,        _______,        _______,            _______,
            _______,    KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        _______,                            KC_MS_L,    KC_MS_D,    KC_MS_U,        KC_MS_R,        _______,            _______,
            _______,    _______,        _______,        _______,        _______,        _______,                            _______,    KC_WH_D,    KC_WH_U,        _______,         _______,            _______,
                                        _______,        _______,        _______,                                            KC_MS_BTN1,    KC_MS_BTN2,    KC_MS_BTN3
            ),

    [_MEDIA] = LAYOUT_split_3x6_3(
            _______,    _______,        _______,        _______,        _______,        _______,                            RGB_TOG,    RGB_MOD,            RGB_HUI,            RGB_SAI,        RGB_VAI,            _______,
            _______,    KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        _______,                            KC_MRWD,    KC_KB_VOLUME_DOWN,  KC_KB_VOLUME_UP,    KC_MFFD,        _______,            _______,
            _______,    _______,        _______,        _______,        _______,        _______,                            _______,    _______,            _______,            _______,        _______,            _______,
                                        _______,        _______,        _______,                                            _______,    KC_MPLY,    KC_AUDIO_MUTE
            ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
