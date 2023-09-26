/* Copyright 2023
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

enum __layers {
	KBAR_BSE,     // kBar base kayer
    KBAR_NAV,     // kBar navigation layer
    KBAR_NUM,     // kBar num layer
    KBAR_SYM,     // kBar num layer
    KBAR_ACC      // kBar num layer
};

// Aliases
// Home row mod aliases
#define MLG_A MT(MOD_LGUI, KC_A)
#define MLA_S MT(MOD_LALT, KC_S) 
#define MLC_D MT(MOD_LCTL, KC_D) 
#define MLS_F MT(MOD_LSFT, KC_F)
#define MRG_J MT(MOD_RSFT, KC_J) 
#define MRA_K MT(MOD_RCTL, KC_K) 
#define MRC_L MT(MOD_LALT, KC_L) 
#define MRS_C MT(MOD_RGUI, KC_SCLN)

// Layers
#define LMO_NAV LT(KBAR_NAV, KC_BSPC)
#define LMO_NUM LT(KBAR_NUM, KC_ESC)
#define LMO_SYM LT(KBAR_SYM, KC_ENT)
#define LMO_ACC LT(KBAR_ACC, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[KBAR_BSE] = LAYOUT_planck_mit(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS,
    KC_BSPC,  MLG_A,    MLA_S,    MLC_D,    MLS_F,    KC_G,     KC_H,     MRG_J,    MRA_K,    MRC_L,   MRS_C,    KC_QUOT,
    KC_ESC,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  LMO_NUM,  LMO_NAV,  KC_SPC,             LMO_SYM,  LMO_ACC,  KC_RALT,  KC_RGUI, KC_RCTL   
),

[KBAR_NAV] = LAYOUT_planck_mit(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_NUM] = LAYOUT_planck_mit(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_4,     KC_5,     KC_6,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_0,     KC_1,     KC_2,     KC_3,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_SYM] = LAYOUT_planck_mit(
    _______,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_LCBR,  KC_RCBR,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_CIRC,  KC_DLR,   KC_LABK,  KC_LPRN,  KC_RPRN,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_PIPE,  KC_PERC,  KC_RABK,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_ACC] = LAYOUT_planck_mit(
    KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  QK_BOOT   
),

// [KBAR_SYM] = LAYOUT_planck_mit(
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
// ),

};
