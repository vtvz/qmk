#include "vtvz.h"

__attribute__((weak)) bool caps_word_press_keymap(uint16_t keycode) {
  return false; // Deactivate Caps Word.
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
    add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
    return true;

    // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case KC_UNDS:
  case TL_LOWR:
  case TL_UPPR:
    return true;

  default:
    return caps_word_press_keymap(keycode);
  }
}
