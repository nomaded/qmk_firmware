// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _PUNCTPAD_DV 2
#define _PUNCTPAD_QW 3
#define _RESET_NUMPAD 4
#define _ONEHAND_DV 5
#define _ONEHAND_FLIP_DV 6

// Helpful defines
#define TT_QW TT(_QWERTY)
#define TT_RST TT(_RESET_NUMPAD)
#define M_PPDV MO(_PUNCTPAD_DV)
#define M_PPQW MO(_PUNCTPAD_QW)
#define LT_TBPD LT(_PUNCTPAD_DV, KC_TAB)
#define LT_ETPD LT(_PUNCTPAD_DV, KC_ENT)
#define LT_TBPQ LT(_PUNCTPAD_QW, KC_TAB)
#define LT_ETPQ LT(_PUNCTPAD_QW, KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_TAB CTL_T(KC_TAB)
#define GUI_ENT GUI_T(KC_ENT)
#define CTL_ENT CTL_T(KC_ENT)
#define GUI_TAB GUI_T(KC_TAB)
#define TT_OHDV TT(_ONEHAND_DV)
#define TT_OHDF TT(_ONEHAND_FLIP_DV)
#define M_OHFDV MO(_ONEHAND_FLIP_DV)
#define LT_SPCF LT(_ONEHAND_FLIP_DV, KC_SPC)
#define LT_BSPF LT(_ONEHAND_FLIP_DV, KC_BSPC)
// get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))

// defining keycodes for LSft + RSft = CpLk
enum my_keycodes {
  LSFT2CP = SAFE_RANGE,
  RSFT2CP
 };

bool is_shift_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* default, dvorak in keyboard, qwerty in OS
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | App  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | +L5  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | +L4  | ' "  | , <  | . >  | p P  | y Y  |                | f F  | g G  | c C  | r R  | l L  | +L1  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| a A  | o O  | e E  | u U  | i I  |,------.,------.| d D  | h H  | t T  | n N  | s S  | - _  |
   * |------+------+------+------+------+------|| Ctrl || Gui  ||------+------+------+------+------+------|
   * | LSft | ; :  | q Q  | j J  | k K  | x X  ||      ||      || b B  | m M  | w W  | v V  | z Z  | RSft |
   * |------+------+------+------+------+------|| Entr || Tab  ||------+------+------+------+------+------|
   * | Home | End  | LAlt | Del  | Bksp |L2/Tab|`------'`------'|L2/Ent| Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_DVORAK] = LAYOUT( /* default, dvorak in keyboard, qwerty in OS */
    KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TT_OHDV,
    TT_RST,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
    CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    LSFT2CP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RSFT2CP,
<<<<<<< HEAD
    KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, M_PPDV,  CTL_TAB, GUI_ENT, M_PPDV,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
=======
    KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, LT_TBPD, CTL_ENT, GUI_TAB, LT_ETPD, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
>>>>>>> Changed the PunctPad layer switch to overload with tab/enter tap keys, and changed the overloaded ctrl/gui keys to reverse the tap keys to enter/tab.
  ),

  /* qwerty in keyboard, dvorak in OS
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | App  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | +L4  | q Q  | w W  | e E  | r R  | t T  |                | y Y  | u U  | i I  | o O  | p P  | -L1  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| a A  | s S  | d D  | f F  | g G  |,------.,------.| h H  | j J  | k K  | l L  | ; :  | ' "  |
   * |------+------+------+------+------+------|| Ctrl || Gui  ||------+------+------+------+------+------|
   * | LSft | z Z  | x X  | c C  | v V  | b B  ||      ||      || n N  | m M  | , <  | . >  | / ?  | RSft |
   * |------+------+------+------+------+------|| Entr || Tab  ||------+------+------+------+------+------|
   * | Home | End  | LAlt | Del  | Bksp |L3/Tab|`------'`------'|L3/Ent| Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_QWERTY] = LAYOUT( /* qwerty in keyboard, dvorak in OS */
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, XXXXXXX,
    TT_RST,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, LT_TBPQ, _______, _______, LT_ETPQ, _______, _______, _______, _______, _______
  ),

  /* punctpad, dvorak in keyboard, qwerty in OS
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      | F1   | F2   | F3   | F4   | F5   |                | F6   | F7   | F8   | F9   | F10  |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | F11  | F12  | Up   |      | PgUp |                | `    | [    | ]    | {    | }    |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| Home | Left | Down | Rght | \    |,------.,------.| /    | -    | _    | (    | )    | Esc  |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * | LSft | Entr | Home |      | End  | PgDn ||  \   ||  /   || ~    | =    | +    | |    | ?    | RSft |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      | LAlt | Del  | Bksp |L2/Tab|`------'`------'|L2/Ent| Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_PUNCTPAD_DV] = LAYOUT( /* punctpad, dvorak in keyboard, qwerty in OS */
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, KC_F11,  KC_F12,  KC_UP,   XXXXXXX, KC_PGUP,                   KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX,
    CTL_ESC, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,                   KC_SLSH, KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, KC_ESC, 
    _______, KC_ENT,  KC_HOME, XXXXXXX, KC_END,  KC_PGDN,                   KC_TILD, KC_EQL,  KC_PLUS, KC_PIPE, KC_QUES, _______,
    XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_BSLS, KC_SLSH, _______, _______, _______, _______, _______, _______
  ),

  /* punctpad, qwerty in keyboard, dvorak in OS
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      | F1   | F2   | F3   | F4   | F5   |                | F6   | F7   | F8   | F9   | F10  |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | F11  | F12  | Up   |      | PgUp |                | `    | -    | =    | _    | +    |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| Home | Left | Down | Rght | \    |,------.,------.| [    | '    | "    | (    | )    | Esc  |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * | LSft | Entr | Home |      | End  | PgDn ||  \   ||  [   || ~    | ]    | }    | |    | {    | RSft |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      | LAlt | Del  | Bksp |L3/Tab|`------'`------'|L3/Ent| Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_PUNCTPAD_QW] = LAYOUT( /* punctpad, qwerty in keyboard, dvorak in OS */
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, KC_F11,  KC_F12,  KC_UP,   XXXXXXX, KC_PGUP,                   KC_GRV,  KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, XXXXXXX,
    CTL_ESC, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,                   KC_LBRC, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_ESC, 
    _______, KC_ENT,  KC_HOME, XXXXXXX, KC_END,  KC_PGDN,                   KC_TILD, KC_RBRC, KC_RCBR, KC_PIPE, KC_LCBR, _______,
    XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_BSLS, KC_LBRC, _______, _______, _______, _______, _______, _______
  ),

  /* reset, and numpad
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |      |      |      |      | Rst  |                | NmLk |      | Np / | Np * | Np - | SLck |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | -L4  |      |      |      |      |      |                |      | Np 7 | Np 8 | Np 9 | Np + | PScr |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)|      |      |      |      |      |,------.,------.|      | Np 4 | Np 5 | Np 6 | Np + | Paus |
   * |------+------+------+------+------+------|| Ctrl ||      ||------+------+------+------+------+------|
   * | LSft |      |      |      |      |      ||      ||Np Ent|| Np 0 | Np 1 | Np 2 | Np 3 | Np . | RSft |
   * |------+------+------+------+------+------|| Entr ||      ||------+------+------+------+------+------|
   * |      |      |      | Del  | Bksp |      |`------'`------'| Np 0 | Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_RESET_NUMPAD] = LAYOUT( /* reset, and numpad */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,                     KC_NLCK, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSCR,
    CTL_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAUS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, CTL_ENT, KC_PENT, KC_P0,   _______, _______, _______, _______, _______
  ),

  /* one-handed dvorak.
   * Meant to be typed primarily with the left hand. Hold momentary Layer 6
   * key to type mirrored right hand with left hand.
   * Backspace stays the same as Layer 1, but need to hold LShift to get
   * Space key.
   * CTL_TAB becomes Tab key, and need to hold LShift to get Enter key.
   * CTL_ESC stays the same. Need to hold CTL_ESC and ~L6 key for C-c.
   *
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | App  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | -L5  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | ' "  | , <  | . >  | p P  | y Y  |                | f F  | g G  | c C  | r R  | l L  | +L6  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| a A  | o O  | e E  | u U  | i I  |,------.,------.| d D  | h H  | t T  | n N  | s S  | - _  |
   * |------+------+------+------+------+------|| Ctrl || Gui  ||------+------+------+------+------+------|
   * | LSft | ; :  | q Q  | j J  | k K  | x X  ||      ||      || b B  | m M  | w W  | v V  | z Z  | RSft |
   * |------+------+------+------+------+------|| Tab  || Entr ||------+------+------+------+------+------|
   * | Home | End  | LAlt | Del  | Bksp |L6/SPC|`------'`------'|L6/BKS| Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_ONEHAND_DV] = LAYOUT( /* default, dvorak in keyboard, qwerty in OS */
    KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    TT_RST,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_OHDF,
    CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    LSFT2CP, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RSFT2CP,
    KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, LT_SPCF, CTL_TAB, GUI_ENT, LT_BSPF, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* one-handed dvorak.
   * Meant to be typed primarily with the left hand. Hold momentary Layer 6
   * key to type mirrored right hand with left hand.
   * Backspace stays the same, but need to hold LShift to get Space key.
   * CTL_TAB becomes Tab key, and need to hold LShift to get Enter key.
   * CTL_ESC stays the same. Need to hold CTL_ESC and ~L6 key for C-c.
   *
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | App  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | ' "  | , <  | . >  | p P  | y Y  |                | f F  | g G  | c C  | r R  | l L  | -L6  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |C(Esc)| a A  | o O  | e E  | u U  | i I  |,------.,------.| d D  | h H  | t T  | n N  | s S  | - _  |
   * |------+------+------+------+------+------|| Ctrl || Gui  ||------+------+------+------+------+------|
   * | LSft | ; :  | q Q  | j J  | k K  | x X  ||      ||      || b B  | m M  | w W  | v V  | z Z  | RSft |
   * |------+------+------+------+------+------|| Tab  || Entr ||------+------+------+------+------+------|
   * | Home | End  | LAlt | Del  | Bksp | ~L6  |`------'`------'| ~L6  | Spce | Left | Down |  Up  | Rght |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_ONEHAND_FLIP_DV] = LAYOUT( /* default, dvorak in keyboard, qwerty in OS */
    KC_APP,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    TT_RST,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TT_QW,
    CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    KC_HOME, KC_END,  KC_LALT, KC_DEL,  KC_BSPC, M_PPDV,  CTL_TAB, GUI_ENT, M_PPDV,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Toggle capslock when pressing both left and right shift keys
    // LSFT2CP
    // RSFT2CP
    //
    case LSFT2CP:
      if (record->event.pressed) {
	// Left shift keydown event
	//
	if (is_shift_pressed) {
	  // is_shift_pressed is true, send capslock
	  //
	  register_code(KC_CAPS);
	} else {
	  // If is_shift_pressed is false, set to true and send shift
	  //
	  is_shift_pressed = true;
	  register_code(KC_LSFT);
	}
      } else {
	// Left shift keyup event
	//
	// Set is_shift_pressed to false, and keyup for capslock and shift
	//
	is_shift_pressed = false;
	unregister_code(KC_CAPS);
	unregister_code(KC_LSFT);
      }
      return false; // Skip all further processing of this key
    case RSFT2CP:
      if (record->event.pressed) {
	// Right shift keydown event
	//
	if (is_shift_pressed) {
	  // is_shift_pressed is true, send capslock
	  //
	  register_code(KC_CAPS);
	} else {
	  // If is_shift_pressed is false, set to true and send shift
	  //
	  is_shift_pressed = true;
	  register_code(KC_RSFT);
	}
      } else {
	// Right shift keyup event
	//
	// Set is_shift_pressed to false, and keyup for capslock and shift
	//
	is_shift_pressed = false;
	unregister_code(KC_CAPS);
	unregister_code(KC_RSFT);
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
};

