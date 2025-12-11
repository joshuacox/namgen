#!/usr/bin/env bash
git branch -a \
  |grep -v main \
  |grep -v -P '^\s*remotes' \
  |xargs -I% git branch -D %
