#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _DV 1
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5
#define _L4 6

// Macro name shortcuts
#define QWERTY M(_QW)
#define DVORAK M(_DV)
#define COLEMAK M(_CM)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,------------------------------------------------------------------------------.
  * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |       Bksp |
  * |------------------------------------------------------------------------------|
  * | Prgm    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   Prgm |
  * |------------------------------------------------------------------------------|
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Hack |
  * |------------------------------------------------------------------------------|
  * | Ctrl    | Hack   | Debug| Enter        | Space    | Alt  | Shift  |     Lock |
  * `------------------------------------------------------------------------------'
  */
  [_QW] = {
    {LT(_L4), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
    {MO(_L1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MO(_L1) },
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2) },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, KC_RSFT, XXXXXXX, TG(_L3) }
  },
  /* Dvorak
  * ,------------------------------------------------------------------------------.
  * | Esc |  /  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |       Bksp |
  * |------------------------------------------------------------------------------|
  * | Prgm    |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |   Prgm |
  * |------------------------------------------------------------------------------|
  * | Shift      |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |Shift|
  * |------------------------------------------------------------------------------|
  * | Ctrl    | Hack   | Debug| Enter        | Space    | Alt  | Hack   |     Lock |
  * `------------------------------------------------------------------------------'
  */
  [_DV] = {
    {KC_ESC,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC },
    {MO(_L1), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    MO(_L1) },
    {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, MO(_L2), XXXXXXX, TG(_L3) }
  },
  /* Colemak
  * ,------------------------------------------------------------------------------.
  * | Esc |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |       Bksp |
  * |------------------------------------------------------------------------------|
  * | Prgm    |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |   Prgm |
  * |------------------------------------------------------------------------------|
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  |Hack |
  * |------------------------------------------------------------------------------|
  * | Ctrl    | Hack   | Debug| Enter        | Space    | Alt  | Shift  |     Lock |
  * `------------------------------------------------------------------------------'
  */
  [_CM] = {
    {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC },
    {MO(_L1), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MO(_L1) },
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2) },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, KC_RSFT, XXXXXXX, TG(_L3) }
  },
  /* PRGM
  * ,------------------------------------------------------------------------------.
  * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |      Del   |
  * |------------------------------------------------------------------------------|
  * |         |  \  |  '  |  -  |  =  |  [  |  ]  |  ←  |  ↓  |  ↑  |  →  |        |
  * |------------------------------------------------------------------------------|
  * |            | Tab | Esc |Print|     |     |     |Prev |Stop |Play |Next |     |
  * |------------------------------------------------------------------------------|
  * | Qwerty  | Dvorak|Colemak|              |          |      |        |          |
  * `------------------------------------------------------------------------------'
  */
  [_L1] = { /* LAYER 1 - PRGM */
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL  },
    {_______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______ },
    {_______, KC_TAB,  KC_ESC,  KC_PSCR, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______ },
    {QWERTY,  DVORAK,  COLEMAK, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______ }
  },
  /* HACK
  * ,------------------------------------------------------------------------------.
  * |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |      Del   |
  * |------------------------------------------------------------------------------|
  * |         |  |  |  "  |  _  |  +  |  {  |  }  |BlInc| PgUp| Home|VolUp|        |
  * |------------------------------------------------------------------------------|
  * |            | Tab | Esc |     |     |     |     |BlDec| PgDn| End |VolDn| Mute|
  * |------------------------------------------------------------------------------|
  * |         |        |      |              |          |BlTogg|        |          |
  * `------------------------------------------------------------------------------'
  */
  [_L2] = { /* LAYER 2 - HACK */
    {LSFT(KC_GRV), KC_1,  KC_2, KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
    {_______, KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, LSFT(KC_LBRC), LSFT(KC_RBRC), BL_INC, BL_PGUP, KC_HOME, KC_VOLUP, _______ },
    {_______, KC_TAB,  KC_ESC,  _______, _______, _______, _______,  BL_DEC, KC_PGDN,  KC_END, KC_VOLD, KC_MUTE },
    {_______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, BL_TOGG, _______, XXXXXXX, _______ }
  },
  /* Tap Function - This layer contains F keys on a tap layer accessed by holding ESC
  * ,------------------------------------------------------------------------------.
  * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |            |
  * |------------------------------------------------------------------------------|
  * |         | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |        |
  * |------------------------------------------------------------------------------|
  * |            |     |     |     |     |     |     |     |     |     |     |     |
  * |------------------------------------------------------------------------------|
  * |         |        |      |              |          |      |        |          |
  * `------------------------------------------------------------------------------'
  */
  [_L4] = { /* LAYER 4 - Tap Function Layer */
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
    {_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______ },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    {_______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______ }
  },
  /* LOCK
  * ,------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |  +  |  7  |  8  |  9  |  0  |            |
  * |------------------------------------------------------------------------------|
  * |         |     |     |     |     |     |  -  |  4  |  5  |  6  |  =  |        |
  * |------------------------------------------------------------------------------|
  * |            |     |    |    |    |  /  |  *  |  1  |  2  |  3  |Enter|     |
  * |------------------------------------------------------------------------------|
  * |         |        |      |              |          |      |        |          |
  * `------------------------------------------------------------------------------'
  */
  [_L3] = { /* LAYER 3 - LOCK */
    {_______, _______, _______, _______, _______, _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______ },
    {_______, _______, _______, _______, _______, _______, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, _______ },
    {_______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______ },
    {_______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______ }
  }
};

const uint16_t PROGMEM fn_actions[] = {
  [6] = ACTION_LAYER_TAP_KEY(6, KC_ESC)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _DV:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_DV);
          }
          break;
        case _QW:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QW);
          }
          break;
        case _CM:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_CM);
          }
          break;
      }
    return MACRO_NONE;
};
