// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F13,   KC_F14, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PLUS,
        KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F15,   KC_F16, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINUS,
        KC_LSFT,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SLSH,
        KC_LCTL,KC_LALT, KC_ESC,  KC_LGUI, KC_SPC,  KC_ENT,                    KC_BSPC, KC_ENT,  _______,  _______, KC_GRV, KC_BSLS
    )
};
