// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0
#define NAV 1
#define DEV 2
#define NUM 3
#define SYM 4
#define FUN 5
#define GAME 6

#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)

#define NAV_ESC LT(NAV, KC_ESC)
#define DEV_TAB LT(DEV, KC_TAB)

#define NUM_SPC LT(NUM, KC_SPC)
#define SYM_ENT LT(SYM, KC_ENT)
#define FUN_BSPC LT(FUN, KC_BSPC)

#define OLGUI OSM(MOD_LGUI)
#define OLALT OSM(MOD_LALT)
#define OLCTL OSM(MOD_LCTL)
#define OLSFT OSM(MOD_LSFT)

#define ORGUI OSM(MOD_RGUI)
#define ORCTL OSM(MOD_RCTL)
#define ORSFT OSM(MOD_RSFT)

#define GAME_TG TG(GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │aS │cD │sF │ G │       │ H │sJ │cK │aL │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤BSP│
      *           └───┤ESC├───┐   ┌───┤ENT├───┘
      *               └───┤TAB│   │   ├───┘
      *                   └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,                               KC_H,   SFT_J,   CTL_K,   ALT_L,    KC_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,    KC_DOT,  KC_SLSH,
                                   KC_DEL, NAV_ESC, DEV_TAB,        NUM_SPC, SYM_ENT, FUN_BSPC
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │GUI│ALT│CTL│SFT│   │       │ < │ v │ ^ │ > │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │GUI│   │       │HOM│PgD│PgU│END│   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤BSP│
      *           └───┤   ├───┐   ┌───┤ENT├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [NAV] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,     XXX,                                XXX,     XXX,      XXX,     XXX,     XXX,
      OLGUI,   OLALT,   OLCTL,   OLSFT,     XXX,                            KC_LEFT, KC_DOWN,    KC_UP, KC_RGHT,     XXX,
        XXX,     XXX,     XXX, KC_LGUI,     XXX,                            KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,     XXX,
                                   XXX,     ___,     XXX,            KC_SPC,  KC_ENT,  KC_BSPC

    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │ _ │ = │ ( │ ) │ ` │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │GUI│ALT│CTL│SFT│   │       │ - │ + │ { │ } │ : │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │GUI│   │       │ | │ \ │ [ │ ] │ ; │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤BSP│
      *           └───┤   ├───┐   ┌───┤ENT├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [DEV] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,     XXX,                            KC_UNDS,  KC_EQL,  KC_LPRN, KC_RPRN,  KC_GRV,
      OLGUI,   OLALT,   OLCTL,   OLSFT,     XXX,                            KC_MINS, KC_PLUS,  KC_LCBR, KC_RCBR, KC_COLN,
        XXX,     XXX,     XXX, KC_LGUI,     XXX,                            KC_PIPE, KC_BSLS,  KC_LBRC, KC_RBRC, KC_SCLN,
                                   XXX,     XXX,     ___,            KC_SPC,  KC_ENT,  KC_BSPC

    ),


     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ 6 │ 7 │ 8 │ 9 │ 0 │       │   │SFT│CTL│ALT│GUI│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │GUI│   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤   │
      *           └───┤ESC├───┐   ┌───┤   ├───┘
      *               └───┤TAB│   │   ├───┘
      *                   └───┘   └───┘
      */
    [NUM] = LAYOUT_split_3x5_3(
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                XXX,     XXX,      XXX,     XXX,     XXX,
       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                XXX,   ORSFT,    ORCTL,   OLALT,   ORGUI,
        XXX,     XXX,     XXX,     XXX,     XXX,                                XXX, KC_RGUI,      XXX,     XXX,     XXX,
                                KC_DEL,  KC_ESC,  KC_TAB,              ___,     XXX,     XXX

    ),


     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ ! │ @ │ # │ $ │ % │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ^ │ & │ * │ ( │ ) │       │   │SFT│CTL│ALT│GUI│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │ ` │ ~ │       │   │GUI│   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤   │
      *           └───┤ESC├───┐   ┌───┤   ├───┘
      *               └───┤TAB│   │   ├───┘
      *                   └───┘   └───┘
      */
    [SYM] = LAYOUT_split_3x5_3(
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                XXX,     XXX,      XXX,     XXX,     XXX,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                                XXX,   ORSFT,    ORCTL,   OLALT,   ORGUI,
        XXX,     XXX,     XXX,  KC_GRV, KC_TILD,                                XXX, KC_RGUI,      XXX,     XXX,     XXX,
                                KC_DEL,  KC_ESC,  KC_TAB,              XXX,     ___,     XXX

    ),


     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │F6 │F7 │f8 │F9 │F10│       │   │SFT│CTL│ALT│GUI│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │F11│F12│       │TGM│GUI│   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤   │
      *           └───┤ESC├───┐   ┌───┤   ├───┘
      *               └───┤TAB│   │   ├───┘
      *                   └───┘   └───┘
      */
    [FUN] = LAYOUT_split_3x5_3(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                XXX,     XXX,      XXX,     XXX,     XXX,
      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                XXX,   ORSFT,    ORCTL,   OLALT,   ORGUI,
        XXX,     XXX,     XXX,  KC_F11,  KC_F12,                            GAME_TG, KC_RGUI,      XXX,     XXX,     XXX,
                                KC_DEL,  KC_ESC,  KC_TAB,              XXX,     XXX,     ___
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │TAB│ Q │ W │ E │ R │       │F1 │F2 │F3 │F4 │F5 │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │SFT│ A │ S │ D │ F │       │F6 │F7 │F8 │F9 │F10│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │CTL│ X │ C │ V │ B │       │ N │ M │   │F11│F12│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │TAB├───┐           ┌───┤   │
      *           └───┤ESC├───┐   ┌───┤   ├───┘
      *               └───┤   │   │TGM├───┘
      *                   └───┘   └───┘
      */
    [GAME] = LAYOUT_split_3x5_3(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
     KC_LCTL,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,     XXX,  KC_F11,  KC_F12,
                                   KC_TAB, KC_ESC, KC_SPC,            GAME_TG,   XXX,     XXX
    )
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_F:
      return true;
    case SFT_J:
      return true;
    default:
      return false;
  }
}
