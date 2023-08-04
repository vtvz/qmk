#ifdef OLED_ENABLE
#include "oled/keylogger.h"
#endif

#include "vtvz.h"

__attribute__((weak)) void leader_end_keymap(void) {}

void leader_end_user(void) {
  if (leader_sequence_two_keys(KC_M, KC_A)) {
    SEND_STRING("vtvz.ru@gmail.com");
  }

  if (leader_sequence_two_keys(KC_R, KC_B)) {
    soft_reset_keyboard();
  }

  if (leader_sequence_two_keys(KC_Z, KC_M)) {
    layer_on(_ZOOM);
  }

#ifdef OLED_KEYLOGGER_ENABLE
  if (leader_sequence_three_keys(KC_K, KC_L, KC_G)) {
    oled_keylog_toggle();
  }
#endif /* ifdef OLED_KEYLOGGER_ENABLE */

  leader_end_keymap();
}
