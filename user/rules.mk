# 10150 bytes free

LTO_ENABLE       = yes
VIA_ENABLE       = no # Disable VIA

# −7450 bytes (2700 bytes free)
OLED_ENABLE            = no
# -692 to oled (2008 bytes free)
OLED_KEYLOGGER_ENABLE ?= no
OLED_PET              ?= LUNA

MOUSEKEY_ENABLE  = yes # Mouse keys
RGBLIGHT_ENABLE  = no # Disable WS2812 RGB underlight.

CAPS_WORD_ENABLE = yes
LEADER_ENABLE    = yes
TRI_LAYER_ENABLE = yes

DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE     = yes

# −2188 bytes (7962 bytes free)
CONSOLE_ENABLE            = no
# -202 to console (7760 bytes free)
CONSOLE_KEYLOGGER_ENABLE ?= no

AVR_USE_MINIMAL_PRINTF = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

include $(KEYMAP_PATH)/post_rules.mk

ifeq ($(strip $(CONSOLE_KEYLOGGER_ENABLE)), yes)
  CONSOLE_ENABLE = yes
  OPT_DEFS      += -DCONSOLE_KEYLOGGER_ENABLE
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
  WPM_ENABLE  = yes
else
  OLED_KEYLOGGER_ENABLE = no
endif

ifeq ($(strip $(OLED_KEYLOGGER_ENABLE)), yes)
  OPT_DEFS += -DOLED_KEYLOGGER_ENABLE
endif

ifeq ($(strip $(OLED_PET)), LUNA)
  OPT_DEFS += -DOLED_PET_LUNA
else ifeq ($(strip $(OLED_PET)), FELIX)
  OPT_DEFS += -DOLED_PET_FELIX
else ifeq ($(strip $(OLED_PET)), SNAKEY)
  OPT_DEFS += -DOLED_PET_SNAKEY
else
  $(error Specify correct pet name)
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
