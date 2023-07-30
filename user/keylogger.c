#include "print.h"

void keylogger_process_record(uint16_t keycode, keyrecord_t *record) {
  uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n", keycode,
          record->event.key.row, record->event.key.col,
          get_highest_layer(layer_state), record->event.pressed, get_mods(),
          get_oneshot_mods(), record->tap.count);
}
