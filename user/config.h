/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define TAP_CODE_DELAY 10
#define TAPPING_TERM 180
#define DYNAMIC_KEYMAP_MACRO_COUNT 0

#define LEADER_TIMEOUT 350
#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 15
#define MOUSEKEY_MOVE_DELTA 4
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define SFTENT_KEYS KC_LSFT, KC_TRNS, SFTENT_KEY
