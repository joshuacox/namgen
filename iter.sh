#!/usr/bin/env bash
 export time1=$(date +%s.%N)
time ${AIDER_CMD} \
  --message "${MESSAGE}"
time ${AIDER_CMD} \
  --message "/test ./test.sh"
 time2=$(date +%s.%N)
 export time_delta=$(echo "scale=40;${time2} - ${time1}" | bc)
