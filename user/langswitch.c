#include "langswitch.h"
#include "vtvz.h"

static uint8_t lang_mode = LM_CAPS;

void langswitch_change_mode(uint8_t lang_mode_code) {
  lang_mode = lang_mode_code;
}

void langswitch_process_tap_code(uint16_t keycode) {
  switch (keycode) {
  case M_EN:
    switch (lang_mode) {
    case LM_CAPS:
      tap_code16(KC_CAPS_LOCK);
      break;
    case LM_SALT:
      tap_code16(LSFT(KC_LALT));
      break;
    case LM_CSPC:
      tap_code16(LCTL(KC_SPC));
      break;
    case LM_WSPC:
      tap_code16(LGUI(KC_SPC));
      break;
    }
    break;

  case M_RU:
    switch (lang_mode) {
    case LM_CAPS:
      tap_code16(LSFT(KC_CAPS_LOCK));
      break;
    case LM_SALT:
      tap_code16(LSFT(KC_LALT));
      break;
    case LM_CSPC:
      tap_code16(LCTL(KC_SPC));
      break;
    case LM_WSPC:
      tap_code16(LGUI(KC_SPC));
      break;
    }
    break;
  }
}

bool langswitch_process_layer(uint16_t keycode) {
  switch (keycode) {
  case M_EN:
    layer_on(_COLEMAK_DH);
    return false;
    break;

  case M_RU:
    layer_off(_COLEMAK_DH);
    return false;
    break;
  }
  return true;
}

bool langswitch_process_record(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  langswitch_process_tap_code(keycode);
  return langswitch_process_layer(keycode);
}
