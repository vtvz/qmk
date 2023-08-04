#include "vtvz.h"

#ifdef OLED_ENABLE
#include "oled/oled.c"
#endif

#ifdef CONSOLE_KEYLOGGER_ENABLE
#include "keylogger.c"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
  oled_process_record(keycode, record);
#endif

#ifdef CONSOLE_KEYLOGGER_ENABLE
  keylogger_process_record(keycode, record);
#endif

  switch (keycode) {
  case M_EN:
    if (record->event.pressed) {
      tap_code16(KC_CAPS_LOCK);
      layer_invert(_COLEMAK_DH);
    }
    break;
  case M_RU:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      tap_code16(LSFT(KC_CAPS_LOCK));
      layer_off(_COLEMAK_DH);
    }
    break;
  case CKC_ZOOM:
    tap_code16(LALT(KC_A));
    break;
  }

  return process_record_keymap(keycode, record);
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
  debug_enable = true;

  set_tri_layer_layers(_NUM, _SYMB, _FN);

  keyboard_post_init_keymap();
}

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) { layer_on(_COLEMAK_DH); }
