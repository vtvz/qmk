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

  langswitch_process_record(keycode, record);

  switch (keycode) {
  case CKC_ZOOM:
    // This is for the press and release for push-to-talk funtionality
    tap_code16(LALT(KC_A));
    break;
  }

  return process_record_keymap(keycode, record);
}
