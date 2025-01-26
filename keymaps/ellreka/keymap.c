// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keymap_layer {
    _BASE,
    _EX,
    _QWERTY,
    _SHIFT,
    _JAPANESE,
    _MOD
};

enum my_keycodes {
    KC_LANG1_ENT,
    KC_CANCEL_ENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_ESC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F13,   KC_F14, KC_Z,    KC_G,    KC_C,    KC_R,    KC_L,    KC_PLUS,
        KC_TAB, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_F15,   KC_F16, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        LM(_SHIFT, MOD_LSFT),KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC,  KC_RBRC,KC_B,    KC_M,    KC_W,    KC_V,    KC_F,    LT(_MOD, KC_SLSH),
        KC_LCTL,KC_LALT, KC_ESC,  KC_LGUI, KC_SPC,  KC_ENT,                    KC_BSPC, KC_LANG1_ENT,  MO(_MOD),_______, KC_GRV, KC_BSLS
    ),
    [_EX] = LAYOUT(
                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_ESC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F13,   KC_F14, KC_Z,    KC_G,    KC_K,    KC_R,    KC_L,    KC_PLUS,
        KC_TAB, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_F15,   KC_F16, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        LM(_SHIFT, MOD_LSFT),KC_SCLN, KC_Q,    KC_J,    KC_C,    KC_X,    KC_LBRC,  KC_RBRC,KC_B,    KC_M,    KC_W,    KC_V,    KC_F,    LT(_MOD, KC_SLSH),
        KC_LCTL,KC_LALT, KC_ESC,  KC_LGUI, KC_SPC,  KC_ENT,                    KC_BSPC, KC_LANG1_ENT,  MO(_MOD),_______, KC_GRV, KC_BSLS
    ),
    [_QWERTY] = LAYOUT(
                _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,  _______,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______,_______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______
    ),
    [_SHIFT] = LAYOUT(
                _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PEQL,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______
    ),
    [_JAPANESE] = LAYOUT(
                KC_CANCEL_ENT, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, KC_BSPC,                   _______, _______, _______, _______, _______, _______
    ),
    [_MOD] = LAYOUT(
                KC_CANCEL_ENT, _______, _______, _______, _______,             _______, _______, _______, _______, TG(_EX),
        _______,_______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILDE,
        _______,KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______,_______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______
    )

};


static bool is_cancel_enter = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LALT:
        case KC_LCTL:
            if(record->event.pressed) {
                layer_on(_QWERTY);
            } else {
                layer_off(_QWERTY);
            }
            return true;
        case KC_LGUI:
            if(record->event.pressed) {
                layer_on(_QWERTY);
                tap_code(KC_LNG2);
            } else {
                layer_off(_QWERTY);
                tap_code(KC_LNG2);
            }
            return true;
        // TapしたときはEnterを、Holdしたときは日本語入力に切り替える
        case KC_LANG1_ENT:
            if(record->event.pressed) {
                layer_on(_JAPANESE);
                tap_code(KC_LNG1);
            } else {
                if(!is_cancel_enter){
                    tap_code(KC_ENT);
                }
                tap_code(KC_LNG2);
                layer_off(_JAPANESE);
                is_cancel_enter = false;
            }
            return false;
        case KC_CANCEL_ENT:
            is_cancel_enter = true;
            return false;
    }
    return true;
}
