/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYMBOL,
    _NUMBER,
    _NAV,
    _MOUSE,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.      ,--------------------------------------------------------------.
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LCTL,        KC_RCTL,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_ESC,     LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_LALT,          KC_RALT,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
    //|--------+--------+--------+--------+--------+--------+--------'        `--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,       KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------|
            LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),       LT(_SYMBOL, KC_ENT), LT(_NUMBER, KC_BSPC), LT(_SYMBOL, KC_DEL)
                                      //`--------------------------'        `--------------------------'
  ),

    [_SYMBOL] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                     ,-----------------------------------------------------.
    _______, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, _______,             _______, KC_CIRC,   KC_AMPR,    KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, KC_PLUS, KC_LPRN,  KC_DQUO, KC_RPRN, KC_QUOTE, _______,            _______, KC_COLN,   KC_LCBR,    KC_EQL,    KC_RCBR, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, KC_LABK, KC_PIPE,  KC_MINS, KC_RABK, KC_BACKSLASH,                          KC_GRV,    KC_UNDS,    KC_QUES,   KC_TILD, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,                       _______, _______, _______
                                      //`--------------------------'            `--------------------------'
  ),

    [_NUMBER] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, KC_LBRC, KC_7,     KC_8,   KC_9,   KC_RBRC, _______,               _______, _______,   _______,    _______,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_SCLN, KC_4,     KC_5,   KC_6,   KC_EQL,  _______,               _______, _______,   KC_RSFT,    KC_RCTL,    KC_RALT, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_DOT,  KC_1,     KC_2,   KC_3,   KC_BSLS,                                 _______,   _______,    _______,    KC_LALT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_DOT, KC_0,    KC_MINUS,                       _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______, _______,              _______, _______,   _______,    _______,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,              _______, KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,                       _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
    _______, _______, _______, _______, _______, _______, _______,               _______, _______,  _______,    _______,    _______, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,               _______, MS_LEFT,  MS_DOWN,    MS_UP,      MS_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______,  MS_WHLD,    MS_WHLU,    _______, _______, _______,
                               _______, _______, _______,                                 MS_BTN1,  MS_BTN2,    MS_BTN3
    ),

    [_MEDIA] = LAYOUT_split_3x6_3_ex2(
    _______, _______, _______, _______, _______, _______, _______,               _______, UG_TOGG,  UG_NEXT,    UG_HUEU,    UG_SATU, UG_VALU, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,               _______, KC_MRWD, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MFFD, _______,    _______,
    _______, _______, _______, _______, _______, _______,                                 _______,  MS_WHLD,    MS_WHLU,    _______,    _______,    _______,
                               _______, _______, _______,                                 _______,  KC_MPLY, KC_AUDIO_MUTE
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
