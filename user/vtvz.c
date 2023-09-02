#include "vtvz.h"

#ifdef OLED_ENABLE
#include "oled/oled.c"
#endif

#ifdef CONSOLE_KEYLOGGER_ENABLE
#include "keylogger.c"
#endif

#ifdef TAP_DANCE_ENABLE
#include "tap_dance.c"
#endif

#include "langswitch.c"

#include "process_record.c"

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
  debug_enable = true;

  set_tri_layer_layers(_NUM, _SYMB, _FN);

  keyboard_post_init_keymap();
}

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) { layer_on(_COLEMAK_DH); }
