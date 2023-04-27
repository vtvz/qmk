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

bool keylog_enable = false;

char keylogs_str[6];
int keylogs_str_idx = 0;

// clang-format off
static const char code_to_name[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
    0xDB,0xDC,0xDD,0xDE,0XDF,0xFB,'P', 'S',  19, ' ',  17,  30,  16,  16,  31,  26,  // 4x
     27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
     25,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  24,  25,  27,  26, ' ', ' ', ' '   // Fx
};
// clang-format on

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

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}
