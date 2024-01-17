#include "tap_dance.h"
#include "vtvz.h"

void td_next(tap_dance_state_t *state, void *user_data) {
  if (state->interrupted || !state->pressed) {
    tap_code(KC_MNXT);

    reset_tap_dance(state);
  } else {
    tap_code16(CKC_DIS);

    reset_tap_dance(state);
  }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_NEXT] = ACTION_TAP_DANCE_FN(td_next),
    [TD_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),
};
