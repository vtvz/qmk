#include "keylogger.h"
#include "vtvz.h"

struct last_key {
  char name;
  uint16_t keycode;
  uint8_t col;
  uint8_t row;
};

struct last_key last_key = {
    .name = ' ',
    .keycode = 0,
    .col = 0,
    .row = 0,
};

bool keylog_enabled = false;

char keylog_history[KEYLOG_HISTORY_LEN] = {};

// clang-format off
static const char code_to_name[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
   0xDB,0xDC,0xDD,0xDE,0XDF,0xFB, 'P', 'S',  19, ' ',  17,  30,  16,  16,  31,  26,  // 4x
     27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ',0x9E,0x9E, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',0x9D,0x9D,0x9D,0x9D,  // Cx
   0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  // Dx
    'C', 'S', 'A', 'G', 'C', 'S', 'A', 'G', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
     25, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  25,  27,  26, ' ', ' ', ' '   // Fx
};
// clang-format on

bool oled_keylog_toggle(void) {
  keylog_enabled = !keylog_enabled;

  oled_clear();

  return keylog_enabled;
}

bool is_keylog_enabled(void) { return keylog_enabled; }

void process_keylog(uint16_t in_keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return;
  }

  char name = ' ';
  uint16_t keycode = in_keycode;

  if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
    keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  } else if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
    keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
  } else if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
    keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
  }

  if (keycode < 256) {
    name = code_to_name[keycode];
  }

  // update keylog
  // snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
  //          record->event.key.row, record->event.key.col, in_keycode, name);
  last_key.name = name;
  last_key.keycode = in_keycode;
  last_key.col = record->event.key.col;
  last_key.row = record->event.key.row;

  // Rotate
  for (int i = 1; i < KEYLOG_HISTORY_LEN; i++) {
    keylog_history[i - 1] = keylog_history[i];
  }

  keylog_history[KEYLOG_HISTORY_LEN - 1] = name;
}

char *get_keylog_history(void) { return keylog_history; }
