#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUN 3
#define _NUM 4

enum custom_keycodes
{
  NUM = SAFE_RANGE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// F5 or FUN(ction layer) when held
#define F5_FN LT(_FUN, KC_F5)

#define L_SPC LT(_LOWER, KC_SPC)
#define R_SPC LT(_RAISE, KC_SPC)

// Enter or Right Shift when held
#define RSF_EN MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Sf/Ent|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | NUM  |F5_FN |Lw/Spc|     |Rs/Spc| F12  | Left | Down |  Up  |Right |
 * `-----------------------------------------'     `-----------------------------------------'
 */
    [_QWERTY] = KEYMAP(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSF_EN,
        KC_LCTL, KC_LGUI, KC_LALT, NUM, F5_FN, L_SPC, R_SPC, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |  Up  |      |   (  |   )  |     |   |  |   _  |   =  |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      | Left | Down | Right|   {  |   }  |     |   \  |   -  |   +  |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |   [  |   ]  |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |Space |      |      |      |      |      |
 * `-----------------------------------------'     `-----------------------------------------'
 */
    [_LOWER] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_UP, _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_UNDS, KC_EQL, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_PLUS, _______, _______, _______,
        _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______),

    /* Raise
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |  Up  |      |   (  |   )  |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      | Left | Down | Right|   {  |   }  |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |   [  |   ]  |     |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |Space |     |      |      |      | Alt  | GUI  | Ctrl |
 * `-----------------------------------------'     `-----------------------------------------'
 */
    [_RAISE] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_UP, _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_UNDS, KC_EQL, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_PLUS, _______, _______, _______,
        _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_RSFT,
        _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, KC_RALT, KC_RGUI, KC_RCTL),

    /* Fun(ction)
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      | Ins  | Home | PgUp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      | Del  | End  | PgDn |
 * `-----------------------------------------'     `-----------------------------------------'
 */
    [_FUN] = KEYMAP(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
        _______, _______, _______, _______, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        _______, _______, _______, _______, _______, _______, KC_F11, KC_F12, _______, KC_INS, KC_HOME, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, KC_END, KC_PGDN),

    /* NUM
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  7   |  8   |  9   |  /   |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  4   |  5   |  6   |  *   |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  1   |  2   |  3   |  -   |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |Enter |  0   |  .   |  +   |      |      |
 * `-----------------------------------------'     `-----------------------------------------'
 */
    [_NUM] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_SLSH, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, KC_ASTR, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_MINS, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_ENT, KC_0, KC_DOT, KC_PLUS, _______, _______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case NUM:
    if (record->event.pressed)
    {
      layer_on(_NUM);
    }
    else
    {
      layer_off(_NUM);
    }
    return false;
    break;
  }
  return true;
}