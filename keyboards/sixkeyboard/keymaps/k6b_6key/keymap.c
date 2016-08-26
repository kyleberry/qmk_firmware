// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "sixkeyboard.h"
#include "matrix.h"

// Layers
#define _BL 0
#define _L1 1
#define _L2 2

// Tap Function Keys
#define TF_FN1 LT(_L1, MA_0)
#define TF_FN2 LT(_L2, MA_3)

// Macro Shortcuts
#define MA_0 M(0)
#define MA_1 M(1)
#define MA_2 M(2)
#define MA_3 M(3)
#define MA_4 M(4)
#define MA_5 M(5)
#define MA_6 M(6)
#define MA_7 M(7)
#define MA_8 M(8)
#define MA_9 M(9)
#define MA_10 M(10)
#define MA_11 M(11)
#define MA_12 M(12)
#define MA_13 M(13)

// Fillers
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base Layer
	* ,-----------------------.
	* | FN1/A |   B   |   C   |
	* |-----------------------|
	* | FN2/D |   E   |   F   |
	* `-----------------------'
	*/
	[_BL] = {
		{TF_FN1,  MA_1,  MA_2},
	  {TF_FN2,  MA_4,  MA_5}
	},
	/* Tap Layer 1
	* ,-----------------------.
	* |       |   B   |   C   |
	* |-----------------------|
	* |       |   E   |   F   |
	* `-----------------------'
	*/
	[_L1] = {
		{______,  MA_6,  MA_7},
		{______,  MA_8,  MA_9}
	},
	/* Tap Layer 2
	* ,-----------------------.
	* |       |   B   |   C   |
	* |-----------------------|
	* |       |   E   |   F   |
	* `-----------------------'
	*/
	[_L2] = {
		{______,  MA_10, MA_11},
		{______,  MA_12, MA_13}
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
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(0), END );
          }
        break;
				case 1:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(1), END );
					}
				break;
				case 2:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(2), END );
					}
				break;
				case 3:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(3), END );
					}
				break;
				case 4:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(4), END );
					}
				break;
				case 5:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(5), END );
					}
				break;
				case 6:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(6), END );
					}
				break;
				case 7:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(7), END );
					}
				break;
				case 8:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(8), END );
					}
				break;
				case 9:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(9), END );
					}
				break;
				case 10:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(1), T(0), END );
					}
				break;
				case 11:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(1), T(1), END );
					}
				break;
				case 12:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(1), T(2), END );
					}
				break;
				case 13:
					if (record->event.pressed) {
						return MACRO( I(255), T(T), T(E), T(S), T(T), T(1), T(3), END );
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
