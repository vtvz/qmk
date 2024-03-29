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

  if (!langswitch_process_record(keycode, record)) {
    return false;
  }

#ifdef SECRETS_ENABLE
  secrets_process_record(keycode, record);
#endif

#ifdef ZOOM_MODE
  switch (keycode) {
  case CKC_ZM_A:
    // This is for the press and release for push-to-talk funtionality
    tap_code16(LALT(KC_A));
    return false;
    break;
  case CKC_ZM_H:
    if (record->event.pressed && layer_state_cmp(layer_state, _ZOOM)) {
      tap_code16(KC_MS_D);
      wait_ms(100);
      tap_code16(KC_MS_U);
      // continue as CKC_ZM_H is an alias to alt+y
    }
    break;
  case CKC_ZM_S:
    tap_code16(KC_MS_D);
    wait_ms(100);
    tap_code16(KC_MS_U);

    return false;
    break;
  }
#endif

  return process_record_keymap(keycode, record);
}
