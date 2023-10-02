#include "vtvz.h"

/* Sit */
static const char PROGMEM pet_anim_sit[2][PET_ANIM_SIZE] = {
    /* 'sit1', 32x22px */
    {
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x0f, 0x31, 0x02, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2e, 0x41, 0x03, 0xfc, 0x50, 0x00, 0x00, 0x00, 0x80, 0x60,
        0x38, 0x47, 0x41, 0x41, 0x42, 0x2c, 0xb0, 0xc0, 0x40, 0x20, 0x20, 0x53,
        0x0c, 0x00, 0x20, 0x44, 0x8c, 0x08, 0x00, 0x40, 0x00, 0x8c, 0x64, 0x10,
        0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xc0, 0x30, 0x0c,
        0x02, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x60, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x01, 0xc1, 0x21, 0xf1, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
        0x47, 0x48, 0x48, 0x38, 0x3f, 0x40, 0x40, 0x40, 0x40, 0x3f, 0x20, 0x20,
        0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'sit2', 32x22px */
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x0f, 0x31, 0x02, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2e, 0x41, 0x03, 0xfc, 0x50, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0x30, 0x4c, 0x42, 0x41, 0x41, 0x27, 0xb8, 0xe0, 0x40, 0x20, 0x20, 0x53,
        0x0c, 0x00, 0x20, 0x44, 0x8c, 0x08, 0x00, 0x40, 0x00, 0x8c, 0x64, 0x10,
        0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0xc0, 0x30, 0x0c,
        0x02, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x60, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x01, 0xc1, 0x21, 0xf1, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
        0x47, 0x48, 0x48, 0x38, 0x3f, 0x40, 0x40, 0x40, 0x40, 0x3f, 0x20, 0x20,
        0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

/* Walk */
static const char PROGMEM pet_anim_walk[2][PET_ANIM_SIZE] = {
    /* 'walk1', 32x22px */
    {
        0x00, 0x00, 0x80, 0x44, 0x7c, 0x84, 0x84, 0x88, 0x08, 0x30, 0xc0, 0x00,
        0x00, 0x00, 0x00, 0xa0, 0x58, 0x64, 0x42, 0x1e, 0x24, 0x58, 0x60, 0x40,
        0x40, 0x70, 0x58, 0x44, 0x82, 0x06, 0xf8, 0xa0, 0xfe, 0x01, 0x00, 0x00,
        0x80, 0x40, 0x20, 0x30, 0x29, 0x26, 0x21, 0x20, 0x40, 0x40, 0x40, 0x47,
        0x38, 0x00, 0x00, 0x40, 0x80, 0x08, 0x18, 0x10, 0x00, 0x80, 0x00, 0x98,
        0x48, 0x30, 0x0f, 0x00, 0x01, 0x02, 0xf4, 0x0e, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x40, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x02, 0x02, 0x82, 0xe2, 0x3e, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x06, 0x38, 0x40, 0x40, 0x40, 0x5e, 0x61, 0x38, 0x07,
        0x00, 0x00, 0x00, 0x01, 0x3f, 0x40, 0x40, 0x40, 0x60, 0x1c, 0x1a, 0x21,
        0x20, 0x23, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
        // 0x00, 0x80, 0x40, 0x22, 0x3e, 0x42, 0x42, 0x44, 0x84, 0x18, 0xe0,
        // 0x00, 0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c,
        // 0x30, 0x20, 0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0xff,
        // 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10,
        // 0x20, 0x20, 0x20, 0x23, 0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c,
        // 0x08, 0x00, 0x40, 0x00, 0xcc, 0x24, 0x18, 0x07, 0x00, 0x00, 0x01,
        // 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0x60,
        // 0x20, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81,
        // 0x41, 0xf1, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        // 0x03, 0x1c, 0x60, 0x40, 0x40, 0x4f, 0x70, 0x3c, 0x03, 0x00, 0x00,
        // 0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0e, 0x1d, 0x20, 0x20,
        // 0x21, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'walk2', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        // 0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0,
        // 0x00, 0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c,
        // 0x30, 0x20, 0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f,
        // 0x80, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10,
        // 0x20, 0x20, 0x20, 0x23, 0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c,
        // 0x08, 0x00, 0x40, 0x00, 0xcc, 0x24, 0x18, 0x07, 0x00, 0x00, 0x01,
        // 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0xe0,
        // 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81,
        // 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
        // 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20, 0x20, 0x27,
        // 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47, 0x48,
        // 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

/* Run */
static const char PROGMEM pet_anim_run[2][PET_ANIM_SIZE] = {
    /* 'run1', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'run2', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

/* Bark */
static const char PROGMEM pet_anim_bark[2][PET_ANIM_SIZE] = {
    /* 'bark1', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'bark2', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

/* Sneak */
static const char PROGMEM pet_anim_sneak[2][PET_ANIM_SIZE] = {
    /* 'sneak1', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'sneak2', 32x22px */
    {
        0x00, 0x80, 0x40, 0x20, 0x31, 0x5f, 0x42, 0x82, 0x84, 0x88, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0xd0, 0x2c, 0x32, 0x21, 0x0f, 0x12, 0x2c, 0x30, 0x20,
        0x20, 0x38, 0x2c, 0x22, 0x41, 0x03, 0xfc, 0x50, 0x7f, 0x80, 0x00, 0x00,
        0xc0, 0x20, 0x10, 0x18, 0x14, 0x13, 0x10, 0x10, 0x20, 0x20, 0x20, 0x23,
        0x1c, 0x00, 0x00, 0x20, 0x40, 0x84, 0x0c, 0x08, 0x00, 0x40, 0x00, 0xcc,
        0x24, 0x18, 0x07, 0x00, 0x00, 0x01, 0xfa, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x40, 0x20, 0xe0, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x81, 0x41, 0x31, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x70, 0x0c, 0x03, 0x06, 0x18, 0x20,
        0x20, 0x27, 0x38, 0x00, 0x3f, 0x21, 0x22, 0x1c, 0x20, 0x40, 0x40, 0x47,
        0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
;