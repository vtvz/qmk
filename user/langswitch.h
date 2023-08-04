#pragma once

#include "quantum.h"

enum language_mode_codes {
  LM_CAPS,
  LM_SALT,
  LM_CSPC,
};

void langswitch_change_mode(uint8_t lang_mode_code);
