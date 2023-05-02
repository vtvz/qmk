const uint16_t PROGMEM combo_capslock[] = {KC_H, KC_K, COMBO_END};

const uint16_t PROGMEM combo_shift_capslock[] = {KC_G, KC_D, COMBO_END};

enum combo_events {
  CB_CAPS_LOCK,
  CB_SHIFT_CAPS_LOCK,
};

combo_t key_combos[COMBO_COUNT] = {
    [CB_CAPS_LOCK] = COMBO_ACTION(combo_capslock),
    [CB_SHIFT_CAPS_LOCK] = COMBO_ACTION(combo_shift_capslock),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case CB_CAPS_LOCK:
    if (pressed) {
      tap_code16(KC_CAPS_LOCK);
      // layer_on(_COLEMAK_DH);
    }
    break;
  case CB_SHIFT_CAPS_LOCK:
    if (pressed) {
      tap_code16(LSFT(KC_CAPS_LOCK));
      layer_off(_COLEMAK_DH);
    }
    break;
  }
}
