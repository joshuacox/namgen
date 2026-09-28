#!/usr/bin/env bash
export SHELL=/bin/bash
set -eu

if [[ -f Makefile ]]; then
  make
elif command -v cmake >/dev/null 2>&1; then
  cmake .
  make
else
  echo "cmake not found, compiling with g++..."
  g++ -std=c++17 -O2 src/*.cpp -o namgen
fi

if command -v bats >/dev/null 2>&1; then
  bats test/full.bats
else
  echo "bats not found, running test/tester.sh..."
  bash test/tester.sh
fi
