#include QMK_KEYBOARD_H

#include "secrets.h"

#define MACRO_TIMER 5

void secrets_send_string(uint16_t index) {
  clear_mods();
  clear_oneshot_mods();
  send_string_with_delay(secrets[index], MACRO_TIMER);
}

bool secrets_process_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CKC_SECRET_1 ... CKC_SECRET_5: // Secrets!  Externally defined strings,
                                      // not stored in repo
    if (record->event.pressed) {
      secrets_send_string(keycode - CKC_SECRET_1);
    }
    return false;
    break;
  }
  return true;
}
