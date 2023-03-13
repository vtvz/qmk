setup:
  qmk setup -H ~/.vial -b vial vial-kb/vial-qmk
  ln -Tsf {{ quote(justfile_directory() + "/crkbd") }} ~/.vial/keyboards/crkbd/keymaps/vtvz

flash:
  qmk flash -km vtvz -kb crkbd

compile:
  qmk compile -km vtvz -kb crkbd

udev:
  sudo sh -c 'udevadm control --reload && udevadm trigger'
