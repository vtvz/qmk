#pragma once

#include "quantum.h"

enum layer_names {
  _BASE,
  _COLEMAK_DH,
  _EXTRA2,
  _NUM,
  _SYMB,
  _FN,
#ifdef ZOOM_MODE
  _ZOOM,
#endif
};

enum custom_keycodes {
  M_EN = SAFE_RANGE,
  M_RU,
#ifdef ZOOM_MODE
  CKC_ZM_A, // Audio
#endif
  NEW_SAFE_RANGE,
};

#define CKC_ZM_H LALT(KC_Y)
