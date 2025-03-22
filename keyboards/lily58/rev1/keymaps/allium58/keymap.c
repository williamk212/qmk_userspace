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

// we will need to intercept mod-taps
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
    [_BASE] = LAYOUT(
        // base layer; colemak DH
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
        KC_ESC,   LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),   KC_G,           KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,      KC_LBRC,  KC_RBRC,          KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

        KC_LALT, LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),     LT(_SYMBOL, KC_ENT), LT(_NUMBER, KC_BSPC), LT(_SYMBOL, KC_DEL), KC_RGUI
    ),

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_QWERTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
        _______,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        _______,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                     KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      _______,  _______,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                    _______, _______, _______, _______,                        _______, _______, _______, _______
    ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMBOL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______,
  _______, LGUI_T(KC_PLUS), LALT_T(KC_LPRN), LCTL_T(KC_DQUO), LSFT_T(KC_RPRN), KC_QUOTE,            KC_COLN, RSFT_T(KC_LCBR), RCTL_T(KC_EQL), RALT_T(KC_RCBR), RGUI_T(KC_SCLN), _______,
  _______, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_BACKSLASH,    _______, _______,       KC_GRV, KC_UNDS, KC_QUES, KC_TILD, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMBER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                     _______, _______, _______, _______, _______, _______,
  _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                      _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,     _______, _______,       _______, _______, _______, KC_LALT, _______, _______,
                    _______, _______, _______,  _______,                    _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }
