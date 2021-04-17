/* Copyright 2021 Edmund C. Ng
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
#define _PUNCT_DV 2
#define _PUNCT_QW 3
#define _NAV_DV 4
#define _NAV_QW 5
#define _RESET_NUMPAD 6
#define _ONEHAND_DV 7
#define _ONEHAND_FLIP_DV 8

/* Helpful defines */
/* Layer-related */
#define TT_QW TT(_QWERTY)                       // Tap Toggle Qwerty Layer
#define TT_RST TT(_RESET_NUMPAD)                // Tap Toggle Reset/Num Layer
#define M_PUNDV MO(_PUNCT_DV)                   // Momentary DV Punct layer
#define M_PUNQW MO(_PUNCT_QW)                   // Momentary QW Punct layer
#define M_NAVDV MO(_NAV_DV)                     // Momentary DV Nav layer
#define M_NAVQW MO(_NAV_QW)                     // Momentary QW Nav layer
#define OS_PUND OSL(_PUNCT_DV)                  // One shot DV Punct layer
#define OS_PUNQ OSL(_PUNCT_QW)                  // One shot QW Punct layer
#define OS_NAVD OSL(_NAV_DV)                    // One shot DV Nav layer
#define OS_NAVQ OSL(_NAV_QW)                    // One shot QW Nav layer
#define LT_PD_X LT(_PUNCT_DV, KC_X)             // Momentary layer or tap key
//#define TT_OHDV TT(_ONEHAND_DV)                 // Layer Tap Toggle
//#define TT_OHDF TT(_ONEHAND_FLIP_DV)            // Layer Tap Toggle
//#define M_OHFDV MO(_ONEHAND_FLIP_DV)            // Momentary activates layer
//#define OS_OHFD OSL(_ONEHAND_FLIP_DV)           // One shot layer
//#define LT_OFSP LT(_ONEHAND_FLIP_DV, KC_SPC)    // Momentary layer or tap key
//#define LT_OFBS LT(_ONEHAND_FLIP_DV, KC_BSPC)   // Momentary layer or tap key
//#define LT_OFTB LT(_ONEHAND_FLIP_DV, KC_TAB)    // Momentary layer or tap key
//#define LT_OFET LT(_ONEHAND_FLIP_DV, KC_ENT)    // Momentary layer or tap key

/* Modifier-related */
#define CTL_ENT LCTL_T(KC_ENT)                  // Ctrl on hold, Enter on tap
#define CTL_ESC LCTL_T(KC_ESC)                  // Ctrl on hold, Esc on tap
#define CTL_TAB LCTL_T(KC_TAB)                  // Ctrl on hold, Tab on tap
#define CTL_DEL LCTL_T(KC_DEL)                  // Ctrl on hold, Tab on tap
#define GUI_ENT LGUI_T(KC_ENT)                  // Gui on hold, Enter on tap
#define GUI_TAB LGUI_T(KC_TAB)                  // Gui on hold, Tab on tap
#define C_HOME LCTL(KC_HOME)                    // Go to top of page
#define C_END LCTL(KC_END)                      // Go to bottom of page
#define OS_LALT OSM(MOD_LALT)                   // One shot Left Alt
#define LSFT_SC LSFT_T(KC_SCLN)
#define LALT__Q LALT_T(KC_Q)
#define LCTL__J LCTL_T(KC_J)
#define LGUI__K LGUI_T(KC_K)
#define RGUI__M RGUI_T(KC_M)
#define RCTL__W RCTL_T(KC_W)
#define LALT__V LALT_T(KC_V)
#define RSFT__Z RSFT_T(KC_Z)
#define ALT_DEL LALT_T(KC_DEL)
#define GUI_BSP LGUI_T(KC_BSPC)
#define CTL_SPC RCTL_T(KC_SPC)

/* defining keycodes for LSft + RSft = CpLk. Not needed anymore. Keeping for
 * reference -- ECN
 */
// enum my_keycodes {
//     LSFT2CP = SAFE_RANGE,
//     RSFT2CP
// };

enum combos {
    LR_CAPS,
    EU_GUI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* default, dvorak in keyboard, qwerty in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * | LAlt | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |     |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |      |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | +L6  | ' "  | , <  | . >  | p P  | y Y  | Esc  |     | Esc  | f F  | g G  | c C  | r R  | l L  | +L1  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc| a A  | o O  | e E  | u U  | i I  | LGui |     | RGui | d D  | h H  | t T  | n N  | s S  | - _  |
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft | ; :  | q Q  | j J  | k K  | x X  | ,------. ,------. | b B  | m M  | w W  | v V  | z Z  | RSft |
     * `-----------------------------------------' | C_Tab| | G_Ent| `-----------------------------------------'
     *                               ,-------------+------| |------+-------------.
     *                               | Bksp |OS(L4)| C_Del| | G_Ent|OS(L2)| Spce |
     *                               `--------------------' `--------------------'
     */
    [_DVORAK] = LAYOUT_centromere_plus( /* default, dvorak in keyboard, qwerty in OS */
        OS_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        TT_RST,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_ESC,           KC_ESC,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_LGUI,          KC_RGUI, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT, LSFT_SC, LALT__Q, LCTL__J, LGUI__K, KC_X,       CTL_TAB,   GUI_ENT,     KC_B,    RGUI__M, RCTL__W, LALT__V, RSFT__Z, KC_RSFT,
                                               KC_BSPC, OS_NAVD, CTL_DEL,   GUI_ENT, OS_PUND, KC_SPC
    ),

    /* qwerty in keyboard, dvorak in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * | LAlt | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |     |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |      |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | +L6  | q Q  | w W  | e E  | r R  | t T  | Esc  |     | Esc  | y Y  | u U  | i I  | o O  | p P  | -L1  |
     * |------+------+------+------+------+------+------|     |------|------+------+------+------+------+------|
     * | C_Esc| a A  | s S  | d D  | f F  | g G  | LGui |     | RGui | h H  | j J  | k K  | l L  | ; :  | ' "  |
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft | z Z  | x X  | c C  | v V  | b B  | ,------. ,------. | n N  | m M  | , <  | . >  | / ?  | RSft |
     * `-----------------------------------------' | C_Tab| | G_Ent| `--+---+--+-------------------------------'
     *                               ,-------------+------| |------+-------------'
     *                               | Bksp |OS(L5)| C_Del| | G_Ent|OS(L3)| Spce |
     *                               `--------------------' `--------------------'
     */
    [_QWERTY] = LAYOUT_centromere_plus( /* qwerty in keyboard, dvorak in OS */
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, XXXXXXX,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,          _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,          _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       _______,   _______,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                               _______, OS_NAVQ, _______,   _______, OS_PUNQ, _______
    ),

    /* punctpad, dvorak in keyboard, qwerty in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |     |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * |      | Eject| Prev | Play | Next |      | Esc  |     | Esc  | `    | [    | ]    | {    | }    | F12  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc|      |Vol Dn| Mute |Vol Up| \    | LGui |     | RGui | /    | -    | _    | (    | )    | C_Esc|
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft | Undo | Cut  | Copy | Paste|      | ,------. ,------. | ~    | =    | +    | |    | ?    | RSft |
     * `-----------------------------------------' | G_Ent| | C_Tab| `-----------------------------------------'
     *                               ,-------------+------' `------+-------------.
     *                               | Spce | ~L4  | G_Ent| | C_Del|OS(L4)| Bksp |
     *                               `--------------------' `--------------------'
     */
    [_PUNCT_DV] = LAYOUT_centromere_plus( /* punctpad, dvorak in keyboard, qwerty in OS */
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,          XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        XXXXXXX, KC_EJCT, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_ESC,           KC_ESC,  KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_F12,
        _______, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, KC_BSLS, KC_LGUI,          KC_RGUI, KC_SLSH, KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, CTL_ESC,
        _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX,    GUI_ENT,   CTL_TAB,     KC_TILD, KC_EQL,  KC_PLUS, KC_PIPE, KC_QUES, _______,
                                               KC_SPC,  M_NAVDV, GUI_ENT,   CTL_DEL, OS_NAVD, KC_BSPC
    ),

    /* punctpad, qwerty in keyboard, dvorak in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |     |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * |      | Eject| Prev | Play | Next |      | Esc  |     | Esc  | `    | -    | =    | _    | +    | F12  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc|      |Vol Dn| Mute |Vol Up| \    | LGui |     | RGui | [    | '    | "    | (    | )    | C_Esc|
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft | Undo | Cut  | Copy | Paste|      | ,------. ,------. | ~    | ]    | }    | |    | {    | RSft |
     * `-----------------------------------------' | G_Ent| | C_Tab| `-----------------------------------------'
     *                               ,-------------+------| |------+-------------.
     *                               | Spce | ~L5  | G_Ent| | C_Del|OS(L5)| Bksp |
     *                               `--------------------' `--------------------'
     */
    [_PUNCT_QW] = LAYOUT_centromere_plus( /* punctpad, qwerty in keyboard, dvorak in OS */
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, KC_LBRC, KC_QUOT, KC_DQUO, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, KC_RBRC, KC_RCBR, _______, KC_LCBR, _______,
                                               _______, M_NAVQW, _______,    _______, OS_NAVQ, _______
    ),

     /* nav, dvorak in keyboard, qwerty in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |     |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * |      |C(Hom)|      | Up   | PgUp |C(End)| Esc  |     | Esc  | `    | (    | )    | ]    | }    | F12  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc| Home | Left | Down | Rght | End  | LGui |     | RGui | /    | Left | Down | Up   | Rght | C_Esc|
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft |      |      |      | PgDn | Tab  | ,------. ,------. | ~    | -    | _    | |    | ?    | RSft |
     * `-----------------------------------------' | G_Ent| | C_Tab| `-----------------------------------------'
     *                               ,-------------+------| |------+-------------.
     *                               | Spce |OS(L2)| G_Ent| | C_Del| ~L2  | Bksp |
     *                               `--------------------' `--------------------'
     */
    [_NAV_DV] = LAYOUT_centromere_plus( /* nav, dvorak in keyboard, qwerty in OS */
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,          XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        XXXXXXX, C_HOME,  XXXXXXX, KC_UP,   KC_PGUP, C_END,   KC_ESC,           KC_ESC,  KC_GRV,  KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, KC_F12,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_LGUI,          KC_RGUI, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_TAB,     GUI_ENT,    KC_TILD,    KC_TILD, KC_MINS, KC_UNDS, KC_PIPE, KC_QUES, _______,
                                               KC_SPC,  OS_PUND, GUI_ENT,    CTL_DEL, M_PUNDV, KC_BSPC
    ),

    /* nav, qwerty in keyboard, dvorak in OS
     * ,------------------------------------------------.     ,------------------------------------------------.
     * |      | F1   | F2   | F3   | F4   | F5   |      |     |      | F6   | F7   | F8   | F9   | F10  | F11  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * |      |C(Hom)|      | Up   | PgUp |C(End)| Esc  |     | Esc  | `    | (    | )    | =    | +    | F12  |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc| Home | Left | Down | Rght | End  | LGui |     | RGui | [    | Left | Down | Up   | Rght | C_Esc|
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft |      |      |      | PgDn | Tab  | ,------. ,------. | ~    | '    | "    | |    | {    | RSft |
     * `-----------------------------------------' | G_Ent| | C_Tab| `-----------------------------------------'
     *                               ,-------------+------| |------+-------------.
     *                               | Spce |OS(L3)| G_Ent| | C_Del| ~L3  | Bksp |
     *                               `--------------------' `--------------------'
     */
    [_NAV_QW] = LAYOUT_centromere_plus( /* nav, qwerty in keyboard, dvorak in OS */
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_LPRN, KC_RPRN, KC_EQL,  KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, KC_LBRC, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______,    _______,    _______, KC_QUOT, KC_DQUO, KC_PIPE, KC_LCBR, _______,
                                               _______, OS_PUNQ, _______,    _______, M_PUNQW, _______
    ),

    /* reset, and numpad
     * ,------------------------------------------------.     ,------------------------------------------------.
     * |      |      |Vol Dn|Vol Up| Mute | Rst  |      |     |      | NmLk |      | Np / | Np * | Np - | SLck |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | -L6  |      |      | Up   |      |      |      |     |      |      | Np 7 | Np 8 | Np 9 | Np + | PScr |
     * |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------|
     * | C_Esc|      | Left | Down | Rght |      |      |     |      |      | Np 4 | Np 5 | Np 6 | Np + | Paus |
     * |------+------+------+------+------+------+------'     `------+------+------+------+------+------+------|
     * | LSft |      |      |      |      |      | ,------. ,------. | Np 0 | Np 1 | Np 2 | Np 3 | Np . | RSft |
     * `-----------------------------------------' | C_Tab| | G_Ent| `-----------------------------------------'
     *                               ,-------------+------| |------+-------------.
     *                               | Bksp |      | C_Del| |Np Ent| Np 0 | Spce |
     *                               `--------------------' `--------------------'
     */
    [_RESET_NUMPAD] = LAYOUT_centromere_plus( /* reset, and numpad */
        XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, RESET,   XXXXXXX,          XXXXXXX, KC_NLCK, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_SLCK,
        _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSCR,
        CTL_ESC, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAUS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    CTL_TAB,    GUI_ENT,    KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
                                               KC_BSPC, XXXXXXX, CTL_DEL,    KC_PENT, KC_P0,   KC_SPC
    ),

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
//    [_ONEHAND_DV] = LAYOUT_centromere_plus( /* default, dvorak in keyboard, qwerty in OS */
//        KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//        OS_OHFD, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX,
//        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
//        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
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
//    [_ONEHAND_FLIP_DV] = LAYOUT_centromere_plus( /* default, dvorak in keyboard, qwerty in OS */
//        KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//        _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
//        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
//        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
//        KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, M_PUNDV, CTL_TAB, GUI_ENT, M_PUNDV, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
//    ),

  /*
  [_TRNS] = LAYOUT_centromere_plus(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};



//#include "centromere_plus.h"
//
//// Each layer gets a name for readability, which is then used in the keymap matrix below.
//// The underscores don't mean anything - you can have a layer called STUFF or any other name.
//// Layer names don't all need to be of the same length, obviously, and you can also skip them
//// entirely and just use numbers.
//enum telophase_layers
//{
//	_QWERTY,
//	_LOWER,
//	_RAISE,
//	_ADJUST
//};
//
//enum centromere_keycodes
//{
//  LOWER = SAFE_RANGE,
//  RAISE,
//  ADJUST
//};
//
//// Fillers to make layering more clear
////#define XXXXXXX KC_NO
////#define _______ KC_TRNS
//
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//[_QWERTY] = { /*QWERTY*/
//    { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC  },
//    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL   },
//    { KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT  },
//    { KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT   },
//    { XXXXXXX, XXXXXXX, KC_LALT, LOWER,   KC_HOME, KC_SPC,  XXXXXXX, XXXXXXX, KC_SPC,  KC_END,  RAISE,   KC_LGUI, XXXXXXX, XXXXXXX  }
//
//},
//
//[_LOWER] = {/*LOWER*/
//    { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL   },
//    { RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL   },
//    { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE  },
//    { KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  XXXXXXX, XXXXXXX, KC_F12,  S(KC_NUHS),S(KC_NUBS),KC_VOLD,KC_VOLU,KC_MPLY},
//    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  }
//
//},
//
//[_RAISE] = {/*RAISE*/
//    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_9,    KC_0,    XXXXXXX  },
//    { KC_GRV,  KC_1,    KC_2,    KC_MS_U, KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_UP,   KC_LBRC, KC_RBRC, KC_DEL   },
//    { KC_DEL,  KC_F1,   KC_MS_L, KC_MS_D, KC_MS_R, KC_F5,   XXXXXXX, XXXXXXX, KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC  },
//    { KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_NUHS, KC_NUBS, KC_MINS, KC_EQL,  KC_RGHT, KC_RGHT  },
//    { XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_HOME, _______, XXXXXXX, XXXXXXX, _______, KC_END,  KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX  }
//
//},
//
//[_ADJUST] = {/*ADJUST*/
//    { _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______  },
//    { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
//    { _______, RESET,   _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, KC_DEL   },
//    { _______, _______, _______, AU_ON,   AU_OFF,  _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______  },
//    { _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, KC_HOME, XXXXXXX, XXXXXXX  }
//},
//
//
//};
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case LOWER:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//      } else {
//        layer_off(_LOWER);
//      }
//      return false;
//      break;
//
//    case RAISE:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//      } else {
//        layer_off(_RAISE);
//      }
//      return false;
//      break;
//
//     case ADJUST:
//      if (record->event.pressed) {
//        layer_on(_ADJUST);
//      } else {
//        layer_off(_ADJUST);
//      }
//      return false;
//      break;
//
//  }
//  return true;
//};

void matrix_scan_user(void) {
		return;
};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     // MACRODOWN only works in this function
//     switch (id) {
//         case 0:
//             if (record->event.pressed) {
//                 register_code(KC_RSFT);
//             }
//             else {
//                 unregister_code(KC_RSFT);
//             }
//             break;
//     }
//     return MACRO_NONE;
// };

/* Using combo feature for shift-to-capslock functionality. Switched to combo
 * because my own function was not behaving as expected with mod-tap keys
 */
const uint16_t PROGMEM lsftrsft_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM eu_gui_combo[] = {KC_E, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [LR_CAPS] = COMBO(lsftrsft_combo, KC_CAPS),
    [EU_GUI] = COMBO(eu_gui_combo, KC_LGUI)
};

/* Code to cancel out oneshot state with escape key. Code copied from:
 * https://github.com/qmk/qmk_firmware/blob/master/users/dshields/dshields.c
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX)
            || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
            || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode == KC_ESC && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }
        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }
        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }
        return rc;
    }
    return true;
}

/* Original shift-to-caps code. Replaced with above combo. Keeping for
 * reference. - ECN
 */

// /* Initializing variables needed for shift 2 capslock */
// bool is_lsft_pressed = false;    // left shift
// bool is_rsft_pressed = false;    // right shift
// 
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     /* Toggle capslock when pressing both left and right shift keys
//      * LSFT2CP
//      * RSFT2CP
//      */
//     switch (keycode) {
//         case LSFT2CP:
//             if (record->event.pressed) {
//                 if (is_rsft_pressed) {
//                     /* If is_rsft_pressed is true, send capslock */
//                     register_code(KC_CAPS);
//                 } else {
//                     /* When left shift key is pressed, if is_rsft_pressed
//                      * is false, set is_lsft_pressed to true and send shift
//                      */
//                     is_lsft_pressed = true;
//                     register_code(KC_LSFT);
//                 }
//             } else {
//                 /* When left shift key is released, set is_lsft_pressed
//                  * to false, and keyup for capslock and shift
//                  */
//                 is_lsft_pressed = false;
//                 unregister_code(KC_CAPS);
//                 unregister_code(KC_LSFT);
//             } 
//             /* Skip all further processing of this key */
//             return false;
//         case RSFT2CP:
//             if (record->event.pressed) {
//                 if (is_lsft_pressed) {
//                     /* If is_lsft_pressed is true, send capslock */
//                     register_code(KC_CAPS);
//                 } else {
//                     /* When right shift key is pressed, if is_lsft_pressed
//                      * is false, set is_rsft_pressed to true and send shift
//                      */
//                     is_rsft_pressed = true;
//                     register_code(KC_RSFT);
//                 }
//             } else {
//                 /* When right shift key is released, set is_rsft_pressed
//                  * to false, and keyup for capslock and shift
//                  */
//                 is_rsft_pressed = false;
//                 unregister_code(KC_CAPS);
//                 unregister_code(KC_RSFT);
//             }
//             /* Skip all further processing of this key */
//             return false; 
//         default: 
//             /* Process all other keycodes normally */
//             return true;
//     }
// };

/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
};
*/

// vim:ai:ci:pi:et:sw=4:sts=4:ts=4:tw=78:norl:
