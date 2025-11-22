#!/usr/bin/env bash
set -eu
make clean
make
bats test/full.bats
