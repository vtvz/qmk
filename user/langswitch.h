#pragma once

#include "quantum.h"

enum language_mode_codes {
  LM_CAPS,
  LM_SALT,
  LM_CSPC,
  LM_WSPC,
};

void langswitch_change_mode(uint8_t lang_mode_code);

void langswitch_process_tap_code(uint16_t keycode);
