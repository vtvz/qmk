#ifdef OLED_ENABLE
#include "oled/keylogger.h"
#endif

#include "langswitch.h"
#include "vtvz.h"

__attribute__((weak)) void leader_end_keymap(void) {}

void leader_end_user(void) {
  if (leader_sequence_two_keys(KC_M, KC_A)) {
    SEND_STRING("vtvz.ru@gmail.com");
  }

  if (leader_sequence_two_keys(KC_R, KC_B)) {
    soft_reset_keyboard();
  }

#ifdef ZOOM_MODE
  if (leader_sequence_two_keys(KC_Z, KC_Z)) {
    layer_on(_ZOOM);
  }
#endif

#ifdef ONE_HAND_MODE
  if (leader_sequence_two_keys(KC_O, KC_H) ||
      leader_sequence_two_keys(KC_A, KC_D) ||
      leader_sequence_two_keys(KC_SCLN, KC_M) ||
      leader_sequence_two_keys(KC_A, KC_V)) {
    // Do I need this at all?
    // langswitch_process_tap_code(M_RU);
    layer_on(_OH);
    combo_enable();
  }
#endif

  if (leader_sequence_three_keys(KC_L, KC_C, KC_L)) {
    langswitch_change_mode(LM_CAPS);
  }

  if (leader_sequence_three_keys(KC_L, KC_S, KC_A)) {
    langswitch_change_mode(LM_SALT);
  }

  if (leader_sequence_three_keys(KC_L, KC_C, KC_S)) {
    langswitch_change_mode(LM_CSPC);
  }

  if (leader_sequence_three_keys(KC_L, KC_W, KC_S)) {
    langswitch_change_mode(LM_WSPC);
  }

#ifdef SECRETS_ENABLE
  if (leader_sequence_two_keys(KC_S, KC_Q)) {
    secrets_send_string(0);
  }

  if (leader_sequence_two_keys(KC_S, KC_W)) {
    secrets_send_string(1);
  }

  if (leader_sequence_two_keys(KC_S, KC_F)) {
    secrets_send_string(2);
  }

  if (leader_sequence_two_keys(KC_S, KC_P)) {
    secrets_send_string(3);
  }

  if (leader_sequence_two_keys(KC_S, KC_B)) {
    secrets_send_string(4);
  }
#endif

#ifdef OLED_KEYLOGGER_ENABLE
  if (leader_sequence_three_keys(KC_K, KC_L, KC_G)) {
    oled_keylog_toggle();
  }
#endif /* ifdef OLED_KEYLOGGER_ENABLE */

  leader_end_keymap();
}
