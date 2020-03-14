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
#define _ONEHAND_DV 5
#define _ONEHAND_FLIP_DV 6

/* Helpful defines */
#define TT_QW TT(_QWERTY)                       // Layer Tap Toggle
#define TT_RST TT(_RESET_NUMPAD)                // Layer Tap Toggle
#define M_PPDV MO(_PUNCTPAD_DV)                 // Momentary activates layer
#define M_PPQW MO(_PUNCTPAD_QW)                 // Momentary activates layer
#define LT_PDTB LT(_PUNCTPAD_DV, KC_TAB)        // Momentary layer or tap key
#define LT_PDET LT(_PUNCTPAD_DV, KC_ENT)        // Momentary layer or tap key
#define LT_PQTB LT(_PUNCTPAD_QW, KC_TAB)        // Momentary layer or tap key
#define LT_PQET LT(_PUNCTPAD_QW, KC_ENT)        // Momentary layer or tap key
#define CTL_ESC CTL_T(KC_ESC)                   // Hold mod or tap key
#define CTL_TAB CTL_T(KC_TAB)                   // Hold mod or tap key
#define GUI_ENT GUI_T(KC_ENT)                   // Hold mod or tap key
#define CTL_ENT CTL_T(KC_ENT)                   // Hold mod or tap key
#define GUI_TAB GUI_T(KC_TAB)                   // Hold mod or tap key
#define TT_OHDV TT(_ONEHAND_DV)               // Layer Tap Toggle
#define TT_OHDF TT(_ONEHAND_FLIP_DV)          // Layer Tap Toggle
#define M_OHFDV MO(_ONEHAND_FLIP_DV)          // Momentary activates layer
#define OS_OHFD OSL(_ONEHAND_FLIP_DV)         // One shot layer
#define LT_OFSP LT(_ONEHAND_FLIP_DV, KC_SPC)  // Momentary layer or tap key
#define LT_OFBS LT(_ONEHAND_FLIP_DV, KC_BSPC) // Momentary layer or tap key
#define LT_OFTB LT(_ONEHAND_FLIP_DV, KC_TAB)  // Momentary layer or tap key
#define LT_OFET LT(_ONEHAND_FLIP_DV, KC_ENT)  // Momentary layer or tap key

/* defining keycodes for LSft + RSft = CpLk */
enum my_keycodes {
    LSFT2CP = SAFE_RANGE,
    RSFT2CP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* default, dvorak in keyboard, qwerty in OS
     * ,--------------------------------------------------------------------------------------------------------.
     * | LAlt | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |AS Tog|      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | +L5  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | +L4  | ' "  | , <  | . >  | p P  | y Y  | Esc  |AS Rep| Esc  | f F  | g G  | c C  | r R  | l L  | +L1  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(Esc)| a A  | o O  | e E  | u U  | i I  | Tab  |AS Up | Tab  | d D  | h H  | t T  | n N  | s S  | - _  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSft | ; :  | q Q  | j J  | k K  | x X  | LGui |AS Dn | RGui | b B  | m M  | w W  | v V  | z Z  | RSft |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      | Del  | Bksp | ~L2  |C(Tab)|      |G(Ent)| ~L2  | Spce | RAlt |      |      |      |
     * `-----------------------------------------+------+------+------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_5x15( /* default, dvorak in keyboard, qwerty in OS */
        KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_ASTG, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TT_OHDV,
        TT_RST,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_ESC,  KC_ASRP, KC_ESC,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_TAB,  KC_ASUP, KC_TAB,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        LSFT2CP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LGUI, KC_ASDN, KC_RGUI, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RSFT2CP,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, M_PPDV,  CTL_TAB, XXXXXXX, GUI_ENT, M_PPDV,  KC_SPC,  KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX
    ),
 
    /* qwerty in keyboard, dvorak in OS
     * ,--------------------------------------------------------------------------------------------------------.
     * | LAlt | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |      |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | +L4  | q Q  | w W  | e E  | r R  | t T  | Esc  |      | Esc  | y Y  | u U  | i I  | o O  | p P  | -L1  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(Esc)| a A  | s S  | d D  | f F  | g G  | Tab  |      | Tab  | h H  | j J  | k K  | l L  | ; :  | ' "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSft | z Z  | x X  | c C  | v V  | b B  | LGui |      | RGui | n N  | m M  | , <  | . >  | / ?  | RSft |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      | Del  | Bksp | ~L3  |C(Tab)|      |G(Ent)| ~L3  | Spce | RAlt |      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x15( /* qwerty in keyboard, dvorak in OS */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
        TT_RST,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, M_PPQW,  _______, _______, _______, M_PPQW,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  
    /* punctpad, dvorak in keyboard, qwerty in OS
     * ,--------------------------------------------------------------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |      |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | {    | [    | Up   |      | PgUp |      |      |      | `    | (    | )    | ]    | }    | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(Esc)| Home | Left | Down | Rght | \    |      |      |      | /    | Left | Down | Up   | Rght |C(Esc)|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSft | End  |      | +    | =    | PgDn |      |      |      | ~    | -    | _    | |    | ?    | RSft |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |G(Ent)| Spce | ~L2  |      |      |      | ~L2  | BkSp | Del  |      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_PUNCTPAD_DV] = LAYOUT_ortho_5x15( /* punctpad, dvorak in keyboard, qwerty in OS */
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
        XXXXXXX, KC_LCBR, KC_LBRC, KC_UP,   XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, KC_F12, 
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTL_ESC,
        _______, KC_END,  XXXXXXX, KC_PLUS, KC_EQL,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_MINS, KC_UNDS, KC_PIPE, KC_QUES, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, GUI_ENT, KC_SPC,  _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX
    ),
  
    /* punctpad, qwerty in keyboard, dvorak in OS
     * ,--------------------------------------------------------------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |      |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | _    | -    | Up   |      | PgUp |      |      |      | `    | (    | )    | =    | +    | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(Esc)| Home | Left | Down | Rght | \    |      |      |      | [    | Left | Down | Up   | Rght |C(Esc)|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSft | End  |      | }    | ]    | PgDn |      |      |      | ~    | '    | "    | |    | {    | RSft |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |G(Ent)| Spce | ~L3  |      |      |      | ~L3  | BkSp | Del  |      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_PUNCTPAD_QW] = LAYOUT_ortho_5x15( /* punctpad, qwerty in keyboard, dvorak in OS */
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
        XXXXXXX, KC_UNDS, KC_MINS, KC_UP,   XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_LPRN, KC_RPRN, KC_EQL,  KC_PLUS, KC_F12, 
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTL_ENT,
        _______, KC_END,  XXXXXXX, KC_RCBR, KC_RBRC, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_QUOT, KC_DQUO, KC_PIPE, KC_LCBR, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  
    /* reset, and numpad
     * ,--------------------------------------------------------------------------------------------------------.
     * |      |      |      |      |      | Rst  |      |      |      | NmLk |      | Np / | Np * | Np - | SLck |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | -L4  |      |      |      |      |      |      |      |      |      | Np 7 | Np 8 | Np 9 | Np + | PScr |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(Esc)|      |      |      |      |      |      |      |      |      | Np 4 | Np 5 | Np 6 | Np + | Paus |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSft |      |      |      |      |      |      |      |      | Np 0 | Np 1 | Np 2 | Np 3 | Np . | RSft |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      | Del  | Bksp |      |C(Ent)|      |Np Ent| Np 0 | Spce | Left | Down |  Up  | Rght |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_RESET_NUMPAD] = LAYOUT_ortho_5x15( /* reset, and numpad */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   RGB_TOG, RGB_MOD, RGB_M_T, KC_NLCK, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_SLCK,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSCR,
        CTL_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_K, RGB_M_X, RGB_M_G, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAUS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, CTL_ENT, XXXXXXX, KC_PENT, KC_P0,   _______, _______, _______, _______, _______
    ),

    //
    //    /* one-handed dvorak.
    //     * Meant to be typed primarily with the left hand. Hold momentary Layer 6
    //     * key to type mirrored right hand with left hand.
    //     * Backspace stays the same as Layer 1, but need to hold LShift to get
    //     * Space key.
    //     * CTL_TAB becomes Tab key, and need to hold LShift to get Enter key.
    //     * CTL_ESC stays the same. Need to hold CTL_ESC and ~L6 key for C-c.
    //     *
    //     * ,-----------------------------------------.                ,-----------------------------------------.
    //     * | App  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | -L5  |
    //     * |------+------+------+------+------+------|                |------+------+------+------+------+------|
    //     * | ~+L6 | ' "  | , <  | . >  | p P  | y Y  |                | f F  | g G  | c C  | r R  | l L  |      |
    //     * |------+------+------+------+------+------|                |------+------+------+------+------+------|
    //     * |C(Esc)| a A  | o O  | e E  | u U  | i I  |,------.,------.| d D  | h H  | t T  | n N  | s S  | - _  |
    //     * |------+------+------+------+------+------|| Ctrl || Gui  ||------+------+------+------+------+------|
    //     * | LSft | ; :  | q Q  | j J  | k K  | x X  ||      ||      || b B  | m M  | w W  | v V  | z Z  | RSft |
    //     * |------+------+------+------+------+------|| Entr || Tab  ||------+------+------+------+------+------|
    //     * | Home | End  | LAlt | Del  | Bksp |L6/Tab|`------'`------'|L6/Ent| Spce | Left | Down |  Up  | Rght |
    //     * `-----------------------------------------'                `-----------------------------------------'
    //     */
    //    [_ONEHAND_DV] = LAYOUT_ortho_5x15( /* default, dvorak in keyboard, qwerty in OS */
    //        KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    //        OS_OHFD, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX,
    //        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    //        LSFT2CP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RSFT2CP,
    //        KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, LT_OFTB, CTL_ENT, GUI_TAB, LT_OFET, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    //    ),
    //  
    //    /* one-handed dvorak.
    //     * Meant to be typed primarily with the left hand. Hold momentary Layer 6
    //     * key to type mirrored right hand with left hand.
    //     * Backspace stays the same, but need to hold LShift to get Space key.
    //     * CTL_TAB becomes Tab key, and need to hold LShift to get Enter key.
    //     * CTL_ESC stays the same. Need to hold CTL_ESC and ~L6 key for C-c.
    //     *
    //     * ,-----------------------------------------.                ,-----------------------------------------.
    //     * | App  | 0 )  | 9 (  | 8 *  | 7 &  | 6 ^  |                | 5 %  | 4 $  | 3 #  | 2 @  | 1 !  |      |
    //     * |------+------+------+------+------+------|                |------+------+------+------+------+------|
    //     * | ~-L6 | l L  | r R  | c C  | g G  | f F  |                | y Y  | p P  | . >  | , <  | ' "  |      |
    //     * |------+------+------+------+------+------|                |------+------+------+------+------+------|
    //     * | - _  | s S  | n N  | t T  | h H  | d D  |,------.,------.| i I  | u U  | e E  | o O  | a A  |C(Esc)|
    //     * |------+------+------+------+------+------|| Gui  || Ctrl ||------+------+------+------+------+------|
    //     * | LSft | z Z  | v V  | w W  | m M  | b B  ||      ||      || x X  | k K  | j J  | q Q  | ; :  | RSft |
    //     * |------+------+------+------+------+------|| Tab  || Entr ||------+------+------+------+------+------|
    //     * | Rght |  Up  | Down | Left | Spce | Entr |`------'`------'| Tab  | Bksp | Del  | LAlt | End  | Home |
    //     * `-----------------------------------------'                `-----------------------------------------'
    //     */
    //    [_ONEHAND_FLIP_DV] = LAYOUT_ortho_5x15( /* default, dvorak in keyboard, qwerty in OS */
    //        KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    //        _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
    //        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    //        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    //        KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, M_PPDV,  CTL_TAB, GUI_ENT, M_PPDV,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    //    ),
    //
};

/* Part of default config. Commenting out for reference purposes.
 *
 * // Defines the keycodes used by our macros in process_record_user
 * enum custom_keycodes {
 *   QMKBEST = SAFE_RANGE,
 *   QMKURL
 * };
 * 
 * const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 *  [0] = LAYOUT_ortho_5x15( \
 *     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
 *     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
 *     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP, \
 *     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN, \
 *     KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
 *   ),
 * };
 * 
 * bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 *   switch (keycode) {
 *     case QMKBEST:
 *       if (record->event.pressed) {
 *         // when keycode QMKBEST is pressed
 *         SEND_STRING("QMK is the best thing ever!");
 *       } else {
 *         // when keycode QMKBEST is released
 *       }
 *       break;
 *     case QMKURL:
 *       if (record->event.pressed) {
 *         // when keycode QMKURL is pressed
 *         SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
 *       } else {
 *         // when keycode QMKURL is released
 *       }
 *       break;
 *   }
 *   return true;
 * }
 */

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch (id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            }
            else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};

/* Initializing variables needed for shift 2 capslock */
bool is_lsft_pressed = false;    // left shift
bool is_rsft_pressed = false;    // right shift

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Toggle capslock when pressing both left and right shift keys
     * LSFT2CP
     * RSFT2CP
     */
    switch (keycode) {
        case LSFT2CP:
            if (record->event.pressed) {
                if (is_rsft_pressed) {
                    /* If is_rsft_pressed is true, send capslock */
                    register_code(KC_CAPS);
                } else {
                    /* When left shift key is pressed, if is_rsft_pressed
                     * is false, set is_lsft_pressed to true and send shift
                     */
                    is_lsft_pressed = true;
                    register_code(KC_LSFT);
                }
            } else {
                /* When left shift key is released, set is_lsft_pressed
                 * to false, and keyup for capslock and shift
                 */
                is_lsft_pressed = false;
                unregister_code(KC_CAPS);
                unregister_code(KC_LSFT);
            } 
            /* Skip all further processing of this key */
            return false;
        case RSFT2CP:
            if (record->event.pressed) {
                if (is_lsft_pressed) {
                    /* If is_lsft_pressed is true, send capslock */
                    register_code(KC_CAPS);
                } else {
                    /* When right shift key is pressed, if is_lsft_pressed
                     * is false, set is_rsft_pressed to true and send shift
                     */
                    is_rsft_pressed = true;
                    register_code(KC_RSFT);
                }
            } else {
                /* When right shift key is released, set is_rsft_pressed
                 * to false, and keyup for capslock and shift
                 */
                is_rsft_pressed = false;
                unregister_code(KC_CAPS);
                unregister_code(KC_RSFT);
            }
            /* Skip all further processing of this key */
            return false; 
        default: 
            /* Process all other keycodes normally */
            return true;
    }
};


