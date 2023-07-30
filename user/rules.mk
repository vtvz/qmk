LTO_ENABLE       = yes
VIA_ENABLE       = no # Disable VIA

KEYLOGGER_ENABLE ?= no

MOUSEKEY_ENABLE  = yes # Mouse keys
RGBLIGHT_ENABLE  = no # Disable WS2812 RGB underlight.

CAPS_WORD_ENABLE = yes
LEADER_ENABLE    = yes
TRI_LAYER_ENABLE = yes

DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE     = yes

CONSOLE_ENABLE   = no
OLED_ENABLE      = no

include $(KEYMAP_PATH)/post_rules.mk

ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
  OLED_ENABLE      = no
  CONSOLE_ENABLE =yes
  OPT_DEFS += -DKEYLOGGER_ENABLE
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
  WPM_ENABLE  = yes
endif

SRC += vtvz.c

ifeq ($(strip $(LEADER_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += leader.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += caps_word.c
endif
