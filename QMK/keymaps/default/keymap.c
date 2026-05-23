// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    OPEN_ONSHAPE = SAFE_RANGE,
    OPEN_VSCODE,
    OPEN_SPOTIFY,
    OPEN_KICAD,
    OPEN_OBS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────────┬────────────┬──────────┐
     * │   Undo   │    Redo    │ Onshape  │
     * ├──────────┼────────────┼──────────┤
     * │  VSCode  │ Fullscreen │  Power   │
     * ├──────────┼────────────┼──────────┤
     * │ Spotify  │   KiCad   │   OBS    │
     * └──────────┴────────────┴──────────┘
     */
    [0] = LAYOUT_ortho_3x3(
        LCTL(KC_Z),   LCTL(KC_Y),  OPEN_ONSHAPE,
        OPEN_VSCODE,  KC_F11,      LALT(KC_F4),
        OPEN_SPOTIFY, OPEN_KICAD,  OPEN_OBS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case OPEN_ONSHAPE:
                SEND_STRING(SS_LGUI("r"));
                wait_ms(200);
                SEND_STRING("chrome https://cad.onshape.com\n");
                return false;
            case OPEN_VSCODE:
                SEND_STRING(SS_LGUI("r"));
                wait_ms(200);
                SEND_STRING("code\n");
                return false;
            case OPEN_SPOTIFY:
                SEND_STRING(SS_LGUI("r"));
                wait_ms(200);
                SEND_STRING("spotify\n");
                return false;
            case OPEN_KICAD:
                SEND_STRING(SS_LGUI("r"));
                wait_ms(200);
                SEND_STRING("kicad\n");
                return false;
            case OPEN_OBS:
                SEND_STRING(SS_LGUI("r"));
                wait_ms(200);
                SEND_STRING("obs64\n");
                return false;
        }
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Encoder 1 - Volume
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Encoder 2 - Brightness
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
    return false;
}