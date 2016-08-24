// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "sixkeyboard.h"
#include "matrix.h"

// Layers
#define _BL 0
#define _L1 1
#define _L2 2

// Macros
#define MA_FN1 LT(_L1, KC_A)
#define MA_FN2 LT(_L2, KC_D)

// Fillers
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base Layer
	* ,-----------------------.
	* | FN1/A |       |       |
	* |-----------------------|
	* | FN2/B |       |       |
	* `-----------------------'
	*/
	[_BL] = {
		{MA_FN1,  KC_B,  KC_C},
	  {MA_FN2,  KC_E,  KC_F}
	},
	[_L1] = {
		{______,  KC_B,  KC_C},
		{______,  KC_E,  KC_F}
	},
	[_L2] = {
		{______,  KC_B,  KC_C},
		{______,  KC_E,  KC_F}
	}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {
  // jump to bootloaer when all keys are pressed
  if (matrix_get_row(0) == 0b111 && matrix_get_row(1) == 0b111) {
    clear_keyboard();
    bootloader_jump();
  }
};
