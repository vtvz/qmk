qmk_home:="~/.qmk"
keymap:="vtvz"
keyboard:=""

qmk *args:
  qmk {{ args }} -km {{ keymap }} -kb {{ keyboard }}

upgrade:
  set -x && cd {{ qmk_home }} && git fetch --all --tags \
    && git checkout $(git describe --tags `git rev-list --tags --max-count=1`)

setup:
  qmk setup -H {{ qmk_home }}

link:
  ln -Tsf {{ quote(justfile_directory() + "/crkbd") }} {{ qmk_home }}/keyboards/crkbd/keymaps/{{ keymap }}
  ln -Tsf {{ quote(justfile_directory() + "/cantor") }} {{ qmk_home }}/keyboards/cantor/keymaps/{{ keymap }}
  ln -Tsf {{ quote(justfile_directory() + "/user") }} {{ qmk_home }}/users/{{ keymap }}

cantor-flash *args:
  just keymap={{ keymap }} keyboard=cantor qmk flash {{ args }}

corne-flash *args:
  just keymap={{ keymap }} keyboard=crkbd qmk flash {{ args }}

corne-compile *args:
  just keymap={{ keymap }} keyboard=crkbd qmk compile {{ args }}

cantor-compile *args:
  just keymap={{ keymap }} keyboard=cantor qmk compile {{ args }}

console:
  qmk console -d 4653:0001

# Make sorted log without bottom keys
prepare-log-no-bottom:
  cat keylog.csv | sort | grep -E "^(0x[A-F0-9]+,)[^3,7]" > keylog-safe.csv

prepare-log:
  cat keylog.csv | sort > keylog-safe.csv

log-raw:
  just console | grep -o -E --line-buffered "(0x[A-F0-9]+,)?[0-9]+,[0-9]+,[0-9]{1,2}"

log:
  @echo "Logging started. It's quiet"
  just log-raw >> keylog.csv
