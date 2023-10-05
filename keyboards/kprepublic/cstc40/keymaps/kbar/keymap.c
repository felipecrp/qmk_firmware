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
    KBAR_MSE,      // kBar num layer
    KBAR_SYM,      // kBar num layer
    KBAR_SY2,     // kBar num layer
    KBAR_FUN,     // kBar num layer
    KBAR_CTL      // kBar num layer
};

// Aliases
// Home row mod aliases
#define MT_A MT(MOD_LGUI, KC_A)
#define MT_S MT(MOD_LALT, KC_S) 
#define MT_D MT(MOD_LCTL, KC_D) 
#define MT_F MT(MOD_LSFT, KC_F)
#define MT_J MT(MOD_RSFT, KC_J) 
#define MT_K MT(MOD_RCTL, KC_K) 
#define MT_L MT(MOD_LALT, KC_L) 
#define MT_SCLN MT(MOD_RGUI, KC_SCLN)

// Layers
#define MT_ESC LT(KBAR_MSE, KC_ESC)
#define MT_SPC LT(KBAR_NUM, KC_SPC)
#define MT_TAB LT(KBAR_NAV, KC_TAB)
#define MT_ENT LT(KBAR_SY2, KC_ENT)
#define MT_BSPC LT(KBAR_SYM, KC_BSPC)
#define MT_DEL LT(KBAR_FUN, KC_DEL)
#define MT_Z LT(KBAR_CTL, KC_Z)
        
// Operations
#define KC_CUT  LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)

enum combos {
    JK_ESC,
    FJ_CAPS
};
const uint16_t PROGMEM jk_combo[] = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {MT_F, MT_J, COMBO_END};
combo_t key_combos[] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [FJ_CAPS] = COMBO(fj_combo, CW_TOGG)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[KBAR_BSE] = LAYOUT_planck_mit(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_NO,    KC_NO,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    MT_A,     MT_S,     MT_D,     MT_F,     KC_G,     KC_NO,    KC_NO,    KC_H,     MT_J,     MT_K,     MT_L,     MT_SCLN,
    MT_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,    KC_NO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    KC_NO,    KC_NO,    MT_ESC,  MT_SPC,    MT_TAB,   KC_NO,              MT_ENT,   MT_BSPC,  MT_DEL,   KC_NO,    KC_NO   
),

[KBAR_NAV] = LAYOUT_planck_mit(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   KC_CUT,   KC_COPY,  KC_PSTE,  KC_PSCR,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CW_TOGG,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_CAPS,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  MT_DEL,  _______,  _______,  _______   
),

[KBAR_NUM] = LAYOUT_planck_mit(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     _______,  _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,  KC_4,     KC_5,     KC_6,     KC_EQL,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PLUS,  KC_1,     KC_2,     KC_3,     KC_ASTR,
    _______,  _______,  _______,  _______,  _______,  _______,            KC_COMM,  KC_0,     KC_DOT,   _______,  _______   
),

[KBAR_MSE] = LAYOUT_planck_mit(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, 
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            KC_BTN1,  KC_BTN2,  KC_BTN3,  _______,  _______   
),

[KBAR_SYM] = LAYOUT_planck_mit(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_AMPR,  _______,  _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,
    KC_DQUO,  KC_TILD,  KC_QUOT,  KC_LPRN,  KC_RPRN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_BSLS,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_MINS,  KC_UNDS,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_SY2] = LAYOUT_planck_mit(
    KC_AMPR,  KC_ASTR,  KC_UNDS,  KC_MINS,  KC_EQL,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_PERC,  KC_GRV,   KC_CIRC,  KC_LCBR,  KC_RCBR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_PIPE,  _______,  KC_PLUS,  KC_LABK,  KC_RABK,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  MT_ESC,   _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_FUN] = LAYOUT_planck_mit(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[KBAR_CTL] = LAYOUT_planck_mit(
    _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,  _______,  RGB_TOG,  RGB_SPD,  RGB_SPI,  RGB_MOD,
    _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  RGB_VAD,  RGB_VAI,  _______,  RGB_HUI,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SAD,  RGB_SAI,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

// [KBAR_SYM] = LAYOUT_planck_mit(
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
// ),

};
