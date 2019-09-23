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

/* If you wish to override any setting set by a previous config.h
 * you will need to first include some boilerplate code for the
 * settings you wish to change.
 */
#pragma once

/* overrides go here! */
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 3
#undef IS_COMMAND
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT)))
#undef TAPPING_TERM
#define TAPPING_TERM 150
//#define PERMISSIVE_HOLD

