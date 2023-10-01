#pragma once

#include "quantum.h"

#define PET_MIN_WALK_SPEED 10
#define PET_MIN_RUN_SPEED 40

/* advanced settings */
// how long each frame lasts in ms
#define PET_ANIM_FRAME_DURATION 150

// number of bytes in array. If you change sprites, minimize for adequate
// firmware size. max is 1024
#ifdef OLED_PET_OLIVER
#define PET_ANIM_SIZE 128
#else
#define PET_ANIM_SIZE 96
#endif
