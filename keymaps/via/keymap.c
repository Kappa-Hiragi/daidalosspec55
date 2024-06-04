// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,   KC_4,    KC_5,     KC_6,   KC_7,    KC_8,    KC_9,     KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,     KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,     KC_LALT,
        KC_LCTL,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,     KC_H,   KC_J,    KC_K,    KC_L,     KC_ENT,
                  KC_LSFT,  KC_Z,     KC_X,   KC_C,    KC_V,     KC_B,   KC_N,    KC_M,    KC_RSFT,  KC_HOME,
                  KC_LCTL,  KC_LALT,                   KC_SPC,                             KC_RWIN,  KC_HOME
    )
};

static bool wkeep = false;
static bool akeep = false;
static bool skeep = false;
static bool dkeep = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
/*
aka killswitch
 */

    case QK_KB_0:
        if (record->event.pressed) {
			wkeep = true;
			unregister_code(KC_S);
            register_code(KC_W);
        } else {
			wkeep = false;
            unregister_code(KC_W);
			if (skeep) {
				register_code(KC_S);
			}
        }
        break;

    case QK_KB_1:
        if (record->event.pressed) {
			akeep = true;
			unregister_code(KC_D);
            register_code(KC_A);
        } else {
			akeep = false;
            unregister_code(KC_A);
			if (dkeep) {
				register_code(KC_D);
			}
        }
        break;

    case QK_KB_2:
        if (record->event.pressed) {
			skeep = true;
			unregister_code(KC_W);
            register_code(KC_S);
        } else {
			skeep = false;
            unregister_code(KC_S);
			if (wkeep) {
				register_code(KC_W);
			}
        }
        break;

    case QK_KB_3:
        if (record->event.pressed) {
			dkeep = true;
			unregister_code(KC_A);
            register_code(KC_D);
        } else {
			dkeep = false;
            unregister_code(KC_D);
			if (akeep) {
				register_code(KC_A);
			}
        }
        break;


    }
    return true;
};