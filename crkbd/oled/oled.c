#include "luna.c"
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180; // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer"), false);

  switch (get_highest_layer(layer_state)) {
  case _BASE:
    oled_write_ln_P(PSTR("Qwert"), false);
    break;
  case _COLEMAK_DH:
    oled_write_ln_P(PSTR("Clemk"), false);
    break;
  case _EXTRA2:
    oled_write_ln_P(PSTR("Extra"), false);
    break;
  case _NUM:
    oled_write_ln_P(PSTR("NumNv"), false);
    break;
  case _SYMB:
    oled_write_ln_P(PSTR("Symb "), false);
    break;
  case _FN:
    oled_write_ln_P(PSTR("Fn&Ms"), false);
    break;
  default:
    oled_write_ln_P(PSTR("Dunno"), false);
  }
}

void oled_render_keylog(void) {
  if (keylog_enable) {
    // oled_write_ln(keylog_str, false);
    oled_write_ln(keylogs_str, false);
  }
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a,
      0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0,
      0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab,
      0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1,
      0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc,
      0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
  oled_write_P(crkbd_logo, false);
}

char wpm_str[6] = {};

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();

    // sprintf(wpm, "WPM: %u", get_current_wpm());
    uint16_t wpm = get_current_wpm();
    if (wpm >= 100) {
      snprintf(wpm_str, sizeof(wpm_str), "%uwp", wpm);
    } else {
      snprintf(wpm_str, sizeof(wpm_str), "%uwpm", wpm);
    }

    oled_write_ln(wpm_str, false);
    render_luna(0, 13, get_current_wpm());

    oled_render_keylog();
  } else {
    oled_render_logo();
  }
  return false;
}
