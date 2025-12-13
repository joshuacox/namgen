#!/usr/bin/env bash
time ${AIDER_CMD} \
  --message "${MESSAGE}"

time ${AIDER_CMD} \
  --message "/test ./test.sh"
