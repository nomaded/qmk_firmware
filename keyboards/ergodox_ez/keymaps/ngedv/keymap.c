/* Copyright 2019 Edmund C. Ng
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

#include QMK_KEYBOARD_H
/*
 * #include "debug.h"
 * #include "action_layer.h"
 */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

/* Each layer gets a name for readability, which is then used in the keymap 
 * matrix below. The underscores don't mean anything - you can have a layer 
 * called STUFF or any other name. Layer names don't all need to be of the 
 * same length, obviously, and you can also skip them entirely and just use 
 * numbers.
 */
#define _DVORAK 0
#define _QWERTY 1
#define _PUNCTPAD_DV 2
#define _PUNCTPAD_QW 3
#define _RESET_NUMPAD 4
//#define _ONEHAND_DV 5
//#define _ONEHAND_FLIP_DV 6

/* Helpful defines */
#define TT_QW TT(_QWERTY)                        // Layer Tap Toggle
#define TT_RST TT(_RESET_NUMPAD)                // Layer Tap Toggle
#define M_PPDV MO(_PUNCTPAD_DV)                    // Momentary activates layer
#define M_PPQW MO(_PUNCTPAD_QW)                    // Momentary activates layer
#define LT_PDTB LT(_PUNCTPAD_DV, KC_TAB)        // Momentary layer or tap key
#define LT_PDET LT(_PUNCTPAD_DV, KC_ENT)        // Momentary layer or tap key
#define LT_PQTB LT(_PUNCTPAD_QW, KC_TAB)        // Momentary layer or tap key
#define LT_PQET LT(_PUNCTPAD_QW, KC_ENT)        // Momentary layer or tap key
#define CTL_ESC CTL_T(KC_ESC)                    // Hold mod or tap key
#define CTL_TAB CTL_T(KC_TAB)                    // Hold mod or tap key
#define GUI_ENT GUI_T(KC_ENT)                    // Hold mod or tap key
#define CTL_ENT CTL_T(KC_ENT)                    // Hold mod or tap key
#define GUI_TAB GUI_T(KC_TAB)                    // Hold mod or tap key
//#define TT_OHDV TT(_ONEHAND_DV)                    // Layer Tap Toggle
//#define TT_OHDF TT(_ONEHAND_FLIP_DV)            // Layer Tap Toggle
//#define M_OHFDV MO(_ONEHAND_FLIP_DV)            // Momentary activates layer
//#define OS_OHFD OSL(_ONEHAND_FLIP_DV)            // One shot layer
//#define LT_OFSP LT(_ONEHAND_FLIP_DV, KC_SPC)    // Momentary layer or tap key
//#define LT_OFBS LT(_ONEHAND_FLIP_DV, KC_BSPC)    // Momentary layer or tap key
//#define LT_OFTB LT(_ONEHAND_FLIP_DV, KC_TAB)    // Momentary layer or tap key
//#define LT_OFET LT(_ONEHAND_FLIP_DV, KC_ENT)    // Momentary layer or tap key

/* defining keycodes for LSft + RSft = CpLk */
enum my_keycodes {
    LSFT2CP = SAFE_RANGE,
    RSFT2CP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* default, dvorak in keyboard, qwerty in OS
     * ,--------------------------------------------------.                ,--------------------------------------------------.
     * |  \ |   | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  | ` ~  |                | App  | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |  = +   |
     * |--------+------+------+------+------+-------------|                |------+------+------+------+------+------+--------|
     * | Tab    | ' "  | , <  | . >  | p P  | y Y  | Esc  |                | Esc  | f F  | g G  | c C  | r R  | l L  |  / ?   |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | C(Esc) | a A  | o O  | e E  | u U  | i I  |------|                |------| d D  | h H  | t T  | n N  | s S  |  - _   |
     * |--------+------+------+------+------+------| Tab  |                | Tab  |------+------+------+------+------+--------|
     * | LShift | ; :  | q Q  | j J  | k K  | x X  |      |                |      | b B  | m M  | w W  | v V  | z Z  | RShift |
     * `--------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
     *   | Home | End  | LAlt | Del  | BkSp |                                            | Spce | Left | Down |  Up  | Rght |
     *   `----------------------------------'                                            `----------------------------------'
     *                                             ,-------------.  ,-------------.
     *                                             | LGui | +L4  |  | PgUp | RGui |
     *                                      ,------|------|------|  |------+------+------.
     *                                      |      | Ctrl | +L1  |  | PgDn | Gui  |      |
     *                                      | ~L2  |      |------|  |------|      | ~L2  |
     *                                      |      | Tab  |G(Ent)|  |C(Tab)| Entr |      |
     *                                      `--------------------'  `--------------------'
     */
    [_DVORAK] = LAYOUT_ergodox(  /* default, dvorak in keyboard, qwerty in OS */
        // left hand
        KC_BSLS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_ESC,
        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        LSFT2CP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_TAB,
        KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC,
                                                              KC_LGUI, TT_RST,
                                                                       TT_QW,
                                                     M_PPDV,  CTL_TAB, GUI_ENT,
        // right hand
                 KC_APP,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
                 KC_ESC,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
                 KC_TAB,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RSFT2CP,
                                   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_PGDN, KC_RGUI,
        KC_PGDN,
        CTL_TAB, GUI_ENT, M_PPDV
    ),

    /* qwerty in keyboard, dvorak in OS; turn on LED 2
     * ,--------------------------------------------------.                ,--------------------------------------------------.
     * |  \ |   | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  | ` ~  |                | App  | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |  ] }   |
     * |--------+------+------+------+------+-------------|                |------+------+------+------+------+------+--------|
     * | Tab    | q Q  | w W  | e E  | r R  | t T  | Esc  |                | Esc  | y Y  | u U  | i I  | o O  | p P  |  [ {   |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | C(Esc) | a A  | s S  | d D  | f F  | g G  |------|                |------| h H  | j J  | k K  | l L  | ; :  |  ' "   |
     * |--------+------+------+------+------+------| Tab  |                | Tab  |------+------+------+------+------+--------|
     * | LShift | z Z  | x X  | c C  | v V  | b B  |      |                |      | n N  | m M  | , <  | . >  | / ?  | RShift |
     * `--------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
     *   | Home | End  | LAlt | Del  | BkSp |                                            | Spce | Left | Down |  Up  | Rght |
     *   `----------------------------------'                                            `----------------------------------'
     *                                             ,-------------.  ,-------------.
     *                                             | LGui | +L4  |  | PgUp | RGui |
     *                                      ,------|------|------|  |------+------+------.
     *                                      |      | Ctrl | -L1  |  | PgDn | Gui  |      |
     *                                      | ~L3  |      |------|  |------|      | ~L3  |
     *                                      |      | Tab  |G(Ent)|  |C(Tab)| Entr |      |
     *                                      `--------------------'  `--------------------'
     */
    [_QWERTY] = LAYOUT_ergodox(  /* qwerty in keyboard, dvorak in OS; turn on LED 2 */
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, _______, _______, _______, _______,
                                                              _______, TT_RST,
                                                                       _______,
                                                     M_PPQW,  _______, _______,
        // right hand
                 _______, _______, _______, _______, _______, _______, KC_RBRC,
                 _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
                 _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                   _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, M_PPQW
    ),

    /* punctpad, dvorak in keyboard, qwerty in OS; turn on LED 1
     * ,--------------------------------------------------.                ,--------------------------------------------------.
     * |        | F1   | F2   | F3   | F4   | F5   | LShf |                |      | F6   | F7   | F8   | F9   | F10  |        |
     * |--------+------+------+------+------+-------------|                |------+------+------+------+------+------+--------|
     * |        | F11  | F12  | Up   |      | PgUp | Esc  |                | Esc  | `    | [    | ]    | {    | }    |        |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | C(Esc) | Home | Left | Down | Rght | \    |------|                |------| /    | -    | _    | (    | )    | Esc    |
     * |--------+------+------+------+------+------| \    |                | /    |------+------+------+------+------+--------|
     * | LShift | Entr | Home |      | End  | PgDn |      |                |      | ~    | =    | +    | |    | ?    | RShift |
     * `--------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
     *   |      |      | LAlt | Del  | BkSp |                                            | Spce | Left | Down |  Up  | Rght |
     *   `----------------------------------'                                            `----------------------------------'
     *                                             ,-------------.  ,-------------.
     *                                             |      |      |  |      |      |
     *                                      ,------|------|------|  |------+------+------.
     *                                      |      |      |      |  |      |      |      |
     *                                      | ~L2  |      |------|  |------|      | ~L2  |
     *                                      |      |      |      |  |      |      |      |
     *                                      `--------------------'  `--------------------'
     */
    [_PUNCTPAD_DV] = LAYOUT_ergodox(  /* punctpad, dvorak in keyboard, qwerty in OS; turn on LED 1 */
        // left hand
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LSFT,
        XXXXXXX, KC_F11,  KC_F12,  KC_UP,   XXXXXXX, KC_PGUP, KC_ESC,
        CTL_ESC, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,
        _______, KC_ENT,  KC_HOME, XXXXXXX, KC_END,  KC_PGDN, KC_BSLS,
        XXXXXXX, XXXXXXX, _______, _______, _______,
                                                              XXXXXXX, XXXXXXX,
                                                                       XXXXXXX,
                                                     _______, XXXXXXX, XXXXXXX,
        // right hand
                 XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
                 KC_ESC,  KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX,
                          KC_SLSH, KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, KC_ESC, 
                 KC_SLSH, KC_TILD, KC_EQL,  KC_PLUS, KC_PIPE, KC_QUES, _______,
                                   _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX,
        XXXXXXX,
        XXXXXXX, XXXXXXX, _______
    ),

    /* punctpad, qwerty in keyboard, dvorak in OS; turn on LED 1 & 2
     * ,--------------------------------------------------.                ,--------------------------------------------------.
     * |        | F1   | F2   | F3   | F4   | F5   | LShf |                |      | F6   | F7   | F8   | F9   | F10  |        |
     * |--------+------+------+------+------+-------------|                |------+------+------+------+------+------+--------|
     * |        | F11  | F12  | Up   |      | PgUp | Esc  |                | Esc  | `    | -    | =    | _    | +    |        |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | C(Esc) | Home | Left | Down | Rght | \    |------|                |------| [    | '    | "    | (    | )    | Esc    |
     * |--------+------+------+------+------+------| \    |                | /    |------+------+------+------+------+--------|
     * | LShift | Entr | Home |      | End  | PgDn |      |                |      | ~    | ]    | }    | |    | {    | RShift |
     * `--------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
     *   |      |      | LAlt | Del  | BkSp |                                            | Spce | Left | Down |  Up  | Rght |
     *   `----------------------------------'                                            `----------------------------------'
     *                                             ,-------------.  ,-------------.
     *                                             |      |      |  |      |      |
     *                                      ,------|------|------|  |------+------+------.
     *                                      |      |      |      |  |      |      |      |
     *                                      | ~L3  |      |------|  |------|      | ~L3  |
     *                                      |      |      |      |  |      |      |      |
     *                                      `--------------------'  `--------------------'
     */
    [_PUNCTPAD_QW] = LAYOUT_ergodox(  /* punctpad, qwerty in keyboard, dvorak in OS; turn on LED 1 & 2 */
        // left hand
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LSFT,
        XXXXXXX, KC_F11,  KC_F12,  KC_UP,   XXXXXXX, KC_PGUP, KC_ESC,
        CTL_ESC, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,
        _______, KC_ENT,  KC_HOME, XXXXXXX, KC_END,  KC_PGDN, KC_BSLS,
        XXXXXXX, XXXXXXX, _______, _______, _______,
                                                              XXXXXXX, XXXXXXX,
                                                                       XXXXXXX,
                                                     _______, XXXXXXX, XXXXXXX,
        // right hand
                 XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
                 KC_ESC,  KC_GRV,  KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, XXXXXXX,
                          KC_LBRC, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_ESC, 
                 KC_SLSH, KC_TILD, KC_RBRC, KC_RCBR, KC_PIPE, KC_LCBR, _______,
                                   _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX,
        XXXXXXX,
        XXXXXXX, XXXXXXX, _______
    ),

     /* reset, and numpad; turn on teensy LED
     * ,--------------------------------------------------.                ,--------------------------------------------------.
     * |        |      |      |      |      |      | Rst  |                | NmLk |      |      | Np / | Np * | Np - | ScrLk  |
     * |--------+------+------+------+------+-------------|                |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |                |      |      | Np 7 | Np 8 | Np 9 | Np + | PrtScn |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | C(Esc) |      |      |      |      |      |------|                |------|      | Np 4 | Np 5 | Np 6 | Np + | Pause  |
     * |--------+------+------+------+------+------|      |                |      |------+------+------+------+------+--------|
     * | LShift |      |      |      |      |      |      |                |      | Np 0 | Np 1 | Np 2 | Np 3 | Np . | RShift |
     * `--------+------+------+------+------+-------------'                `-------------+------+------+------+------+--------'
     *   |      |      |      | Del  | BkSp |                                            | Spce | Left | Down |  Up  | Rght |
     *   `----------------------------------'                                            `----------------------------------'
     *                                             ,-------------.  ,-------------.
     *                                             |      | -L4  |  |      |      |
     *                                      ,------|------|------|  |------+------+------.
     *                                      |      | Ctrl |      |  |      |      |      |
     *                                      |      |      |------|  |------|Np Ent| Np 0 |
     *                                      |      | Ent  |      |  |      |      |      |
     *                                      `--------------------'  `--------------------'
     */
    [_RESET_NUMPAD] = LAYOUT_ergodox(  /* reset, and numpad; turn on teensy LED */
        // left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        CTL_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
                                                              XXXXXXX, _______,
                                                                       XXXXXXX,
                                                     XXXXXXX, CTL_ENT, XXXXXXX,
        // right hand
                 KC_NLCK, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_SLCK,
                 XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSCR,
                          XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAUS,
                 XXXXXXX, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
                                   _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX,
        XXXXXXX,
        XXXXXXX, KC_PENT, KC_P0
    ),

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
        case _QWERTY:
            // top LED - Qwerty layer
            ergodox_right_led_1_on();
            break;
        case _PUNCTPAD_DV:
            // middle LED - Dvorak & Pad layer
            ergodox_right_led_2_on();
            break;
        case _PUNCTPAD_QW:
            // top & middle LEDs - Qwerty & Pad layer
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case _RESET_NUMPAD:
            // teensy LED - NumPad & BootLoader layer
            ergodox_board_led_on();
            break;
        default:
            // none - Dvorak layer
            // bottom LED - reserved for CapsLock
            break;
    }

    // Caps lock
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    }
    /*
    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }
    }
    */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
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

/* Initializing variable needed for shift 2 capslock */
bool is_shift_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Toggle capslock when pressing both left and right shift keys
     * LSFT2CP
     * RSFT2CP
     */
    switch (keycode) {
        case LSFT2CP:
            if (record->event.pressed) {
                if (is_shift_pressed) {
                    /* is_shift_pressed is true, send capslock,
                     * turn on LED 3
                     */
                    register_code(KC_CAPS);
                    //ergodox_right_led_3_on();
                } else {
                    /* If is_shift_pressed is false, set to true and send
                     * shift
                     */
                    is_shift_pressed = true;
                    register_code(KC_LSFT);
                }
            } else {
                /* Set is_shift_pressed to false, and keyup for capslock and
                 * shift, turn off LED 3
                 */
                is_shift_pressed = false;
                unregister_code(KC_CAPS);
                //ergodox_right_led_3_off();
                unregister_code(KC_LSFT);
            } 
            /* Skip all further processing of this key */
            return false;
        case RSFT2CP:
            if (record->event.pressed) {
                if (is_shift_pressed) {
                    /* is_shift_pressed is true, send capslock,
                     * turn on LED 3
                     */
                    register_code(KC_CAPS);
                    //ergodox_right_led_3_on();
                } else {
                    /* If is_shift_pressed is false, set to true and send
                     * shift
                     */
                    is_shift_pressed = true;
                    register_code(KC_RSFT);
                }
            } else {
                /* Set is_shift_pressed to false, and keyup for capslock and
                 * shift, turn off LED 3
                 */
                is_shift_pressed = false;
                unregister_code(KC_CAPS);
                //ergodox_right_led_3_off();
                unregister_code(KC_RSFT);
            }
            /* Skip all further processing of this key */
            return false; 
        /*
        case KC_CAPS:
            if (record->event.pressed) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }
        */
        default: 
            /* Process all other keycodes normally */
            return true;
    }
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case QWERTY:
//    return false
//    break;
//    case LOWER:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case RAISE:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//  }
//  return true;
//}

