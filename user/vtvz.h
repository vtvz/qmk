#pragma once

#include "quantum.h"

enum layer_names {
  _BASE,
  _COLEMAK_DH,
  _EXTRA2,
  _NUM,
  _SYMB,
  _FN,
  _OH,
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
#ifdef SECRETS_ENABLE
  CKC_SECRET_1,
  CKC_SECRET_2,
  CKC_SECRET_3,
  CKC_SECRET_4,
  CKC_SECRET_5,
#endif
  NEW_SAFE_RANGE,
};

#define CKC_ZM_H LALT(KC_Y)

#ifndef SECRETS_ENABLE
#define CKC_SECRET_1 KC_ESC
#define CKC_SECRET_2 KC_ESC
#define CKC_SECRET_3 KC_ESC
#define CKC_SECRET_4 KC_ESC
#define CKC_SECRET_5 KC_ESC
#endif
