#!/usr/bin/env bash
export SHELL=/bin/bash
set -eu
#make clean
make
bats test/full.bats
