/* KEYBOARD PET START */
#include "pet.h"
#include "vtvz.h"

#ifdef OLED_PET_OLIVER
#include "pet_oliver.c"
#endif

#ifdef OLED_PET_SNAKEY
#include "pet_snakey.c"
#endif

#ifdef OLED_PET_FELIX
#include "pet_felix.c"
#endif

#ifdef OLED_PET_LUNA
#include "pet_luna.c"
#endif

/* timers */
uint32_t pet_anim_timer = 0;

/* current frame */
uint8_t pet_current_frame = 0;

bool pet_is_sneaking = false;
bool pet_is_jumping = false;
bool pet_showed_jump = true;

/* logic */
static void render_pet(int PET_X, int PET_Y, uint8_t current_wpm) {
  void clear_line(void) {
    static const char PROGMEM clean_line[32] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    oled_write_raw_P(clean_line, 32);
  }
  /* animation */
  void animate_pet(void) {
    bool do_jump = false;
    /* jump */
    if (pet_is_jumping && !pet_showed_jump) {
      /* clear */
      oled_set_cursor(PET_X, PET_Y + 3);
      clear_line();
      oled_set_cursor(PET_X, PET_Y + 2);
      clear_line();

      oled_set_cursor(PET_X, PET_Y - 1);

      pet_showed_jump = true;
      do_jump = true;
    } else {
      /* clear */
      oled_set_cursor(PET_X, PET_Y - 1);
      clear_line();

      oled_set_cursor(PET_X, PET_Y);
    }

    /* switch frame */
    pet_current_frame = (pet_current_frame + 1) % 2;

    /* current status */
    if (is_caps_word_on() || get_mods() & (MOD_LSFT | MOD_RSFT)) {
      oled_write_raw_P(pet_anim_bark[pet_current_frame], PET_ANIM_SIZE);

    } else if (pet_is_sneaking) {
      oled_write_raw_P(pet_anim_sneak[pet_current_frame], PET_ANIM_SIZE);

    } else if (do_jump) {
      oled_write_raw_P(pet_anim_run[0], PET_ANIM_SIZE);

    } else if (current_wpm <= PET_MIN_WALK_SPEED) {
      oled_write_raw_P(pet_anim_sit[pet_current_frame], PET_ANIM_SIZE);

    } else if (current_wpm <= PET_MIN_RUN_SPEED) {
      oled_write_raw_P(pet_anim_walk[pet_current_frame], PET_ANIM_SIZE);

    } else {
      oled_write_raw_P(pet_anim_run[pet_current_frame], PET_ANIM_SIZE);
    }
  }

#if OLED_TIMEOUT > 0
  /* the animation prevents the normal timeout from occuring */
  if (last_input_activity_elapsed() > OLED_TIMEOUT &&
      last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return;
  } else {
    oled_on();
  }
#endif

  /* animation timer */
  if (timer_elapsed32(pet_anim_timer) > PET_ANIM_FRAME_DURATION) {
    pet_anim_timer = timer_read32();
    animate_pet();
  }
}

/* KEYBOARD PET END */

void process_pet(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LCTL:
    if (record->event.pressed) {
      pet_is_sneaking = true;
    } else {
      pet_is_sneaking = false;
    }
    break;
  case KC_SPC:
  case KC_ENT:
    if (record->event.pressed) {
      pet_is_jumping = true;
      pet_showed_jump = false;
    }
    break;
  }
}
