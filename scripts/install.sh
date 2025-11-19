#!/bin/sh
TMP=$(mktemp -d)
cleanup_func () {
  echo rm -Rfv ${TMP}
}
trap cleanup_func EXIT

install_main () {
  cd ${TMP}
  set -eux
  curl -L -o namgen-main.zip https://github.com/joshuacox/namgen/archive/refs/heads/main.zip
  unzip namgen-main.zip
  cd namgen-main
  cmake .
  make clean
  make
  sudo make install
}

time install_main
