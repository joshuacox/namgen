#!/usr/bin/env bash
export PATH=".:$PATH"
for i in $(ls src/*lib.h)
do
  echo $i \
    |sed 's!src/!!' \
    |sed 's!_lib.h!!' \
    |sed 's/^/namgen -c 1 --/' \
    |bash
done
