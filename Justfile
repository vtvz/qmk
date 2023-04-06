qmk *args:
  qmk {{ args }} -km vtvz -kb crkbd

setup:
  qmk setup -H ~/.vial -b vial vial-kb/vial-qmk
  ln -Tsf {{ quote(justfile_directory() + "/crkbd") }} ~/.vial/keyboards/crkbd/keymaps/vtvz

flash:
  just qmk flash

compile:
  just qmk compile

udev:
  sudo sh -c 'udevadm control --reload && udevadm trigger'

log:
  qmk console -d 4653:0001 | grep -o -E --line-buffered "(0x[A-F0-9]+,)?[0-9]+,[0-9]+,[0-9]{1,2}" | tee -a keylog.csv

prepare-log:
  cat keylog.csv | sort > keylog-safe.csv
