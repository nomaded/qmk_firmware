// If you wish to override any setting set by a previous config.h
// you will need to first include some boilerplate code for the
// settings you wish to change.
#pragma once

// overrides go here!
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 3
#undef IS_COMMAND
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT)))
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD

