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

#include "layers.c"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#ifdef OLED_ENABLE
#include "oled/keylogger.c"
#include "oled/oled.c"
#endif

#ifdef COMBO_ENABLE
#include "feature/combo.c"
#endif

// Tap Dance declarations
enum {
  TD_NEXT,
};

enum custom_keycodes {
  M_EN = SAFE_RANGE,
  M_RU,
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
       KC_ESC,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                               KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
       KC_TAB,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                               KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_QUOT,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      KC_LGUI,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                               KC_N,      KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,   KC_LBRC,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                  KC_LCTL,   TL_LOWR,    KC_SPC,      SC_SENT,   TL_UPPR,   KC_LALT
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      _______,      KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                               KC_J,      KC_L,      KC_U,      KC_Y,   KC_SCLN,   _______,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,      KC_A,      KC_R,      KC_S,      KC_T,      KC_G,                               KC_M,      KC_N,      KC_E,      KC_I,      KC_O,   _______,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,      KC_Z,      KC_X,      KC_C,LT(_EXTRA2,KC_D),KC_V,                               KC_K,      KC_H,   KC_COMM,    KC_DOT,  KC_SLASH,   _______,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                  _______,   _______,   _______,      _______,   _______,   _______
                                                  //`--------------------------'  `--------------------------------'
  ),


  [_EXTRA2] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                               KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_QUOT,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                  _______,   _______,   _______,      _______,   _______,   _______
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
                                                  _______,   _______,   _______,      _______,   _______,   _______
                                                  //`--------------------------'  `--------------------------------'
  ),


  // The left side contains Hyper variants of alpha to navigate througs apps
  [_SYMB] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-----------------------------------------------------------------.
      _______,   KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,   KC_PERC,                            KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_BSPC,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,HYPR(KC_A),HYPR(KC_S),HYPR(KC_D),HYPR(KC_F),HYPR(KC_G),                            KC_UNDS,    KC_EQL,   KC_LCBR,   KC_RCBR,   KC_PIPE,   KC_TILD,
  //|--------+----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------+----------|
      _______,   XXXXXXX,   XXXXXXX,      M_RU,      M_EN,   XXXXXXX,                            KC_MINS,   KC_PLUS,   KC_LBRC,   KC_RBRC,   KC_BSLS,    KC_GRV,
  //|--------+----------+----------+----------+----------+----------+----------|  |----------+----------+----------+----------+----------+----------+----------|
                                                  _______,   _______,   _______,      _______,   _______,    KC_DEL
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
                                                  _______,   _______,   _______,      _______,   _______,   _______
                                                  //`--------------------------'  `--------------------------------'
  )
};
// clang-format on

void keyboard_post_init_user(void) {
  debug_enable = true;

  set_tri_layer_layers(_NUM, _SYMB, _FN);
}

#ifdef LEADER_ENABLE
void leader_end_user(void) {
  if (leader_sequence_four_keys(KC_M, KC_A, KC_I, KC_L)) {
    SEND_STRING("vtvz.ru@gmail.com");
  } else if (leader_sequence_three_keys(KC_R, KC_B, KC_T)) {
    soft_reset_keyboard();
  }

#ifdef OLED_ENABLE
  if (leader_sequence_three_keys(KC_K, KC_L, KC_G)) {
    oled_keylog_toggle();
  }
#endif /* ifdef OLED_ENABLE */
}
#endif /* ifdef LEADER_ENABLELEADER_ENABLE */

#ifdef CAPS_WORD_ENABLE
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
#endif /* ifdef CAPS_WORD_ENABLE */

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
  process_keylog(keycode, record);

  process_luna(keycode, record);
#endif

  switch (keycode) {
  case M_EN:
    if (record->event.pressed) {
      tap_code16(KC_CAPS_LOCK);
      layer_on(_COLEMAK_DH);
    }
    break;
  case M_RU:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      tap_code16(LSFT(KC_CAPS_LOCK));
      layer_off(_COLEMAK_DH);
    }
    break;
  }
  return true;
}

void keyboard_pre_init_user(void) { layer_on(_COLEMAK_DH); }
