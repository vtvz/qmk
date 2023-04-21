/*
Use this for https://precondition.github.io/qmk-heatmap
As it's simpler to tap buttons in sequence

┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│0A││0B││0C││0D││0E││0F│            │4F││4E││4D││4C││4B││4A│
└──┘└──┘└──┘└──┘└──┘└──┘            └──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│1A││1B││1C││1D││1E││1F│            │5F││5E││5D││5C││5B││5A│
└──┘└──┘└──┘└──┘└──┘└──┘            └──┘└──┘└──┘└──┘└──┘└──┘
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│2A││2B││2C││2D││2E││2F│            │6F││6E││6D││6C││6B││6A│
└──┘└──┘└──┘└──┘└──┘└──┘            └──┘└──┘└──┘└──┘└──┘└──┘
                ┌──┐┌──┐┌──┐    ┌──┐┌──┐┌──┐
                │3D││3E││3F│    │7F││7E││7D│
                └──┘└──┘└──┘    └──┘└──┘└──┘
*/

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// Tap Dance declarations
enum {
  TD_NEXT,
};

void td_next(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    register_code(KC_LSFT);
    register_code(KC_LCTL);
    register_code(KC_LGUI);
    register_code(KC_LALT);

    tap_code(KC_Q);

    clear_mods();

    reset_tap_dance(state);
  } else {
    tap_code(KC_MNXT);

    reset_tap_dance(state);
  }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_NEXT] = ACTION_TAP_DANCE_FN(td_next),
};

enum layer_names { _BASE, _COLEMAK_DH, _EXTRA2, _NUM, _SYMB, _FN };
enum layer_names_double {
  B_BASE = 0,
  B_COLEMAK_DH = 2,
  B_EXTRA2 = 2 << 1,
  B_NUM = 2 << 2,
  B_SYMB = 2 << 3,
  B_FN = 2 << 4,
};

// bottom keys from left to wight
#define KLL KC_LCTL
#define KLR KC_SPC
#define KRL SC_SENT
#define KRR LALT_T(QK_BOOT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      KC_HYPR,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                               KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
       KC_TAB,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                               KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_QUOT,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      KC_LGUI,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                               KC_N,      KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,   KC_LBRC,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   TL_LOWR,       KLR,          KRL,   TL_UPPR,       KRR
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      KC_HYPR,      KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                               KC_J,      KC_L,      KC_U,      KC_Y,   KC_SCLN,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
       KC_TAB,      KC_A,      KC_R,      KC_S,      KC_T,      KC_G,                               KC_M,      KC_N,      KC_E,      KC_I,      KC_O,   KC_QUOT,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      KC_LGUI,      KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                               KC_K,      KC_H,   KC_COMM,    KC_DOT,  KC_SLASH,   KC_LBRC,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   TL_LOWR,       KLR,          KRL,   TL_UPPR,       KRR
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_EXTRA2] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   _______,       KLR,          KRL,   _______,       KRR
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_NUM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      _______,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                               KC_6,      KC_7,      KC_8,      KC_9,      KC_0,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,   KC_BRIU,   KC_VOLU,   KC_BSPC,    KC_ESC,    KC_DEL,                            KC_LEFT,   KC_DOWN,     KC_UP,  KC_RIGHT,HYPR(KC_M),   KC_MPLY,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,   KC_BRID,   KC_VOLD,    KC_TAB,   QK_LEAD,   CW_TOGG,                            KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,   KC_MPRV,TD(TD_NEXT),
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   _______,       KLR,          KRL,   _______,       KRR
                                                  //`--------------------------'  `--------------------------------'
  ),


  // The left side contains Hyper variants of alpha to navigate througs apps
  [_SYMB] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      _______,   KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,   KC_PERC,                            KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,HYPR(KC_A),HYPR(KC_S),HYPR(KC_D),HYPR(KC_F),HYPR(KC_G),                            KC_UNDS,    KC_EQL,   KC_LCBR,   KC_RCBR,   KC_PIPE,   KC_TILD,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,HYPR(KC_Z),HYPR(KC_X),HYPR(KC_C),HYPR(KC_V),HYPR(KC_B),                            KC_MINS,   KC_PLUS,   KC_LBRC,   KC_RBRC,   KC_BSLS,    KC_GRV,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   _______,       KLR, LSFT(KC_ENT),   _______,    KC_DEL
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_FN] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      QK_BOOT,     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                              KC_F6,     KC_F7,     KC_F8,     KC_F9,    KC_F10,   KC_PSCR,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,    KC_F11,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,   XXXXXXX,                            KC_MS_L,   KC_MS_D,   KC_MS_U,   KC_MS_R,    KC_F12,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,TG(_COLEMAK_DH),XXXXXXX,                          KC_WH_L,   KC_WH_D,   KC_WH_U,   KC_WH_R,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                      KLL,   _______,       KLR,          KRL,   _______,       KRR
                                                  //`--------------------------'  `--------------------------------'
  )
};
// clang-format on

void keyboard_post_init_user(void) {
  debug_enable = true;

  set_tri_layer_layers(_NUM, _SYMB, _FN);
}

const uint16_t PROGMEM combo_capslock[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM combo_shift_capslock[] = {KC_F, KC_S, COMBO_END};

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

void leader_end_user(void) {
  if (leader_sequence_four_keys(KC_M, KC_A, KC_I, KC_L)) {
    SEND_STRING("vtvz.ru@gmail.com");
  } else if (leader_sequence_three_keys(KC_R, KC_B, KC_T)) {
    soft_reset_keyboard();
  }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
    add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
    return true;

    // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case KC_UNDS:
  case TL_LOWR:
  case TL_UPPR:
    return true;

  default:
    return false; // Deactivate Caps Word.
  }
}

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180; // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  if ((layer_state & B_FN) == B_FN) {
    oled_write_ln_P(PSTR("Fn&Mouse"), false);
  } else if ((layer_state & B_SYMB) == B_SYMB) {
    oled_write_ln_P(PSTR("Symbols"), false);
  } else if ((layer_state & B_NUM) == B_NUM) {
    oled_write_ln_P(PSTR("Num&Nav"), false);
  } else if ((layer_state & B_EXTRA2) == B_EXTRA2) {
    oled_write_ln_P(PSTR("Extra"), false);
  } else if ((layer_state & B_COLEMAK_DH) == B_COLEMAK_DH) {
    oled_write_ln_P(PSTR("Colemak DH"), false);
  } else if (layer_state == B_BASE) {
    oled_write_ln_P(PSTR("QWERTY"), false);
  } else {
    oled_write_ln_P(PSTR("Dunno"), false);
  }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ',  ' ', ' ', 'a',  'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j',  'k', 'l', 'm',  'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v',  'w', 'x', 'y',  'z', '1', '2', '3', '4', '5', '6',
    '7', '8',  '9', '0', 'R',  'E', 'B', 'T', '_', '-', '=', '[',
    ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }

  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) { oled_write_ln(keylog_str, false); }

void render_bootmagic_status(bool status) {
  /* Show Ctrl-Gui Swap options */
  static const char PROGMEM logo[][2][3] = {
      {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
      {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
  };
  if (status) {
    oled_write_ln_P(logo[0][0], false);
    oled_write_ln_P(logo[0][1], false);
  } else {
    oled_write_ln_P(logo[1][0], false);
    oled_write_ln_P(logo[1][1], false);
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

char wpm[8] = {};

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    oled_render_keylog();

    // sprintf(wpm, "WPM: %u", get_current_wpm());
    snprintf(wpm, sizeof(wpm), "WPM: %u", get_current_wpm());

    oled_write_ln(wpm, false);

  } else {
    oled_render_logo();
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
#ifdef KEYLOGGER_ENABLE
  uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n", keycode,
          record->event.key.row, record->event.key.col,
          get_highest_layer(layer_state), record->event.pressed, get_mods(),
          get_oneshot_mods(), record->tap.count);
#endif
#endif

#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif
  return true;
}
