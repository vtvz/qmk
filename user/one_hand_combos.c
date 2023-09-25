#include "one_hand_combos.h"
#include "langswitch.h"
#include "vtvz.h"

const uint16_t PROGMEM com_T[] = {KC_Y, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_R[] = {KC_U, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_E[] = {KC_I, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_W[] = {KC_O, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_Q[] = {KC_P, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_G[] = {KC_H, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_F[] = {KC_J, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_D[] = {KC_K, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_S[] = {KC_L, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_A[] = {KC_SCLN, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_B[] = {KC_N, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_V[] = {KC_M, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_C[] = {KC_COMM, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_X[] = {KC_DOT, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_Z[] = {KC_SLSH, KC_SPC, COMBO_END};
const uint16_t PROGMEM com_reset[] = {KC_BSPC, KC_SPC, KC_Y, COMBO_END};

const uint16_t PROGMEM com_BSPC[] = {KC_J, KC_K, COMBO_END};

// clang-format off
combo_t key_combos[] = {
  [COMB_RESET] = COMBO_ACTION(com_reset),
  COMBO(com_T, KC_T),
  COMBO(com_R, KC_R),
  COMBO(com_E, KC_E),
  COMBO(com_W, KC_W),
  COMBO(com_Q, KC_Q),
  COMBO(com_G, KC_G),
  COMBO(com_F, KC_F),
  COMBO(com_D, KC_D),
  COMBO(com_S, KC_S),
  COMBO(com_A, KC_A),
  COMBO(com_B, KC_B),
  COMBO(com_V, KC_V),
  COMBO(com_C, KC_C),
  COMBO(com_X, KC_X),
  COMBO(com_Z, KC_Z),
  COMBO(com_BSPC, KC_BSPC),
};
// clang-format on

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case COMB_RESET:
    if (pressed) {
      layer_off(_OH);
      // Do I need this at all?
      // langswitch_process_tap_code(M_EN);
      layer_on(_COLEMAK_DH);
      combo_disable();
    }
    break;
  }
}
