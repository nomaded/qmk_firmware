/* Copyright 2019-2020 Edmund C. Ng
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

/* If you wish to override any setting set by a previous config.h
 * you will need to first include some boilerplate code for the
 * settings you wish to change.
 */
#pragma once

/* overrides go here! */
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 5     // Number of taps to hold key, tap to release
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1500     // Time (ms) before one shot key is released
#undef TAPPING_TERM
#define TAPPING_TERM 300         // Global time (ms) to trigger hold vs tap
#undef TAPPING_TERM_PER_KEY
//#define TAPPING_TERM_PER_KEY
//#define PERMISSIVE_HOLD          // Mod Tap keys as Mod if another key tapped
//#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT // Hold both keys for TAPPING_TERM for hold
#undef IS_COMMAND
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT)))
//#define AUTO_SHIFT_TIMEOUT 150
//#define NO_AUTO_SHIFT_SPECIAL
#define COMBO_COUNT 2
#define COMBO_TERM 300

