#include "vtvz.h"

// Sit
static const char PROGMEM pet_anim_sit[2][PET_ANIM_SIZE] = {
    // 'sit1', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0,
        0xf0, 0xf8, 0xf8, 0xcc, 0xcc, 0xf8, 0xf8, 0xf0, 0xf0, 0x60, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0xfc, 0xf9, 0xf1,
        0xe1, 0xc1, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x38, 0x70,
        0x60, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x7e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    // 'sit2', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0,
        0xf0, 0xf8, 0xf8, 0xcc, 0xcc, 0xf8, 0xf8, 0xf0, 0xf0, 0x60, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0xfc, 0xf9, 0xf1,
        0xe1, 0xc1, 0x81, 0x00, 0x00, 0x01, 0x01, 0x02, 0x06, 0x0c, 0x04, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7c,
        0x60, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x7e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

// Walk
static const char PROGMEM pet_anim_walk[2][PET_ANIM_SIZE] = {
    // 'walk1', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xf8, 0xfc, 0xfe, 0xfe, 0x1f, 0x3f, 0x39, 0x39, 0x3f, 0x3f,
        0x1e, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x3e, 0x78, 0x70, 0xf8,
        0xfc, 0xfe, 0x7e, 0x3e, 0x3c, 0x3c, 0x78, 0x78, 0x78, 0xf0, 0xf1, 0xff,
        0x7f, 0x7f, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    // 'walk2', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x60, 0x60,
        0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x60,
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3e, 0x7f, 0xff, 0xff, 0xe7, 0xc7, 0x0e, 0x0e, 0x0f, 0x0f, 0x07, 0x07,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x3e,
        0x78, 0xf0, 0xfc, 0x7e, 0x1e, 0x1f, 0x0f, 0x0e, 0x1e, 0x1c, 0x3d, 0x7f,
        0xff, 0xff, 0xff, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

// Run
static const char PROGMEM pet_anim_run[2][PET_ANIM_SIZE] = {
    // 'run1', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0x98, 0xf8,
        0xf8, 0xf8, 0xf0, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0,
        0x87, 0x7f, 0xff, 0xff, 0xf1, 0xc3, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 0x3e,
        0x78, 0xf7, 0xff, 0x7f, 0x3d, 0x03, 0x07, 0x0f, 0x1e, 0x3d, 0x7f, 0xff,
        0xff, 0xff, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    // 'run2', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0xf8, 0x98,
        0xf8, 0xf8, 0xf8, 0xf0, 0x70, 0x20, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xf8, 0xfc, 0x3e, 0xde, 0xfe, 0xfc, 0xf8, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0x7f, 0x07, 0x01, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1e, 0x3c, 0x78, 0xff, 0xff, 0x7f,
        0x01, 0x00, 0x07, 0x1f, 0x3f, 0x7c, 0x78, 0xff, 0xff, 0x7f, 0x07, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

// Bark
static const char PROGMEM pet_anim_bark[2][PET_ANIM_SIZE] = {
    // 'bark1', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x30, 0x70,
        0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0x7f, 0xff, 0xff, 0xe7, 0xe7, 0xef, 0xef, 0xcf, 0xcb, 0x83, 0x83,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1c, 0x38, 0x78, 0xf1, 0xe3,
        0xe3, 0xe7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    // 'bark2', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x60, 0xe0,
        0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x9f,
        0x0f, 0x0e, 0x1f, 0x1f, 0x3f, 0x3f, 0x7e, 0xe6, 0x83, 0x03, 0x0f, 0x43,
        0x43, 0x90, 0x88, 0x08, 0x00, 0x00, 0x03, 0x1e, 0x3c, 0x78, 0xf0, 0xe0,
        0xe0, 0xf0, 0xf0, 0xfb, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x38, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

// Sneak
static const char PROGMEM pet_anim_sneak[2][PET_ANIM_SIZE] = {
    // 'sneak1', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc,
        0xf8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8,
        0x7c, 0xfc, 0xee, 0xe6, 0xfc, 0xfc, 0x78, 0x78, 0xb0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xf1, 0xf8, 0xf8, 0x7c,
        0x7c, 0xf8, 0xf0, 0xf0, 0xf1, 0xe7, 0xef, 0xef, 0xfe, 0xfe, 0xfe, 0xfc,
        0xfc, 0xf8, 0xf0, 0x60, 0x00, 0x01, 0x03, 0x06, 0x02, 0x00, 0x00, 0x00,
    },
    // 'sneak2', 32x22px
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0,
        0xf8, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8,
        0x7c, 0xfc, 0xee, 0xe6, 0xfc, 0xfc, 0x78, 0x78, 0x30, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xf0, 0xf8, 0xf8, 0x7c,
        0x7c, 0xf8, 0xf0, 0xf0, 0xf1, 0xe7, 0xef, 0xef, 0xfe, 0xfe, 0xfe, 0xfc,
        0xfc, 0xf8, 0xf0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
