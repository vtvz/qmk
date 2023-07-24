qmk_home:="~/.qmk"
keymap:="vtvz"
keyboard:="crkbd"

qmk *args:
  qmk {{ args }} -km {{ keymap }} -kb {{ keyboard }}

upgrade:
  cd {{ qmk_home }} && git fetch --all --tags \
    && git checkout $(git describe --tags `git rev-list --tags --max-count=1`)

setup:
  qmk setup -H {{ qmk_home }}

link:
  ln -Tsf {{ quote(justfile_directory() + "/crkbd") }} {{ qmk_home }}/keyboards/crkbd/keymaps/{{ keymap }}
  ln -Tsf {{ quote(justfile_directory() + "/cantor") }} {{ qmk_home }}/keyboards/cantor/keymaps/{{ keymap }}

flash *args:
  just keymap={{ keymap }} keyboard={{ keyboard }} qmk flash {{ args }}

flash-cantor *args:
  just keymap={{ keymap }} keyboard=cantor qmk flash {{ args }}

flash-corne *args:
  just keymap={{ keymap }} keyboard=crkbd qmk flash {{ args }}

flash-left:
  just flash -bl avrdude-split-left

flash-right:
  just flash -bl avrdude-split-right

compile *args:
  just qmk compile {{ args }}

compile-cantor *args:
  just keymap={{ keymap }} keyboard=cantor qmk compile {{ args }}

udev:
  sudo sh -c 'udevadm control --reload && udevadm trigger'

console:
  qmk console -d 4653:0001

prepare-log:
  cat keylog.csv | sort > keylog-safe.csv

log:
  just console | grep -o -E --line-buffered "(0x[A-F0-9]+,)?[0-9]+,[0-9]+,[0-9]{1,2}" | tee -a keylog.csv
