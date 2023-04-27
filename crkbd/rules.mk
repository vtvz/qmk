LTO_ENABLE       = yes
MOUSEKEY_ENABLE  = yes # Mouse keys
RGBLIGHT_ENABLE  = no # Disable WS2812 RGB underlight.
VIA_ENABLE       = no # Disable VIA

CAPS_WORD_ENABLE = yes
COMBO_ENABLE     = yes
LEADER_ENABLE    = yes
TRI_LAYER_ENABLE = yes


DYNAMIC_MACRO_ENABLE = no
TAP_DANCE_ENABLE     = yes

CONSOLE_ENABLE    = no
KEYLOGGER_ENABLE ?= no

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled/*.c
endif

ifneq ($(strip $(CONSOLE_ENABLE)), yes)
  OLED_ENABLE      = yes
  OLED_DRIVER      = SSD1306
  WPM_ENABLE = yes
endif
