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
  CKC_ZM_S, // Shake
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

// clang-format off
//
#define CKC_DIS  HYPR(KC_Q)
#define CKC_FF   KC_F13
#define CKC_TERM KC_F14
#define CKC_SLK  KC_F15
#define CKC_KEE  KC_F16
#define CKC_TG   KC_F17
#define CKC_SPOT KC_F18

/*
#define CKC_KEE  HYPR(KC_A)
#define CKC_SLK  HYPR(KC_S)
#define CKC_TERM HYPR(KC_D)
#define CKC_FF   HYPR(KC_F)
#define CKC_TG   HYPR(KC_G)
#define CKC_SPOT HYPR(KC_M)
*/
// clang-format on
