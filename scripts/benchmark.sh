#!/usr/bin/env bash
: ${counto:=12}
: "${SPEED:=normal}"
: ${SCAN_START:=1}
: ${SCAN_END:=15}
: ${HYPERFINE_LOGDIR:=log}
#: ${COMMON_HYPERFINE_OPTS:="counto={num_count} ./name-generator" "counto={num_count} ./name-generator_go" -P num_count 1 3 --export-csv log/timing.csv --export-json log/timing.json --export-asciidoc log/timing.ascii --export-markdown log/timing.md
#: ${COMMON_HYPERFINE_OPTS:='-P num_count 1 3'} --export-csv log/timing.csv --export-json log/timing.json --export-asciidoc log/timing.ascii --export-markdown log/timing.md
#: ${HYPERFINE_LOGS:=--export-csv log/timing.csv --export-json log/timing.json --export-asciidoc log/timing.ascii --export-markdown log/timing.md
export counto=${counto}
set -eux
mkdir -p log

slow_bench_runnr () {
  hyperfine \
    --export-csv ${HYPERFINE_LOGDIR}/timing-slow-${counto}.csv \
    --export-json ${HYPERFINE_LOGDIR}/timing-slow-${counto}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/timing-slow-${counto}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/timing-slow-${counto}.md \
    --warmup 1 \
    --runs 3 \
    --shell=none \
    './namgen'
}

slowest_scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto={num_count} ./namgen\'
}

slow_scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto=$((2**{num_count})) ./namgen'
}

scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto=$((2**{num_count})) ./namgen'
}

fast_scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto=$((2**{num_count})) ./namgen'
}

faster_scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto=$((2**{num_count})) ./namgen'
}

fastest_scanner_bench_runnr () {
  hyperfine \
    -P num_count ${SCAN_START} ${SCAN_END} \
    --export-csv ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.csv \
    --export-json ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/${SPEED}-${SCAN_END}.md \
    --warmup 1 \
    --runs 2 \
    --shell=bash \
    'counto=$((2**{num_count})) ./namgen'
}

bench_runnr () {
  hyperfine \
    --warmup 3 \
    --runs 8 \
    --shell=none \
    --export-csv ${HYPERFINE_LOGDIR}/timing-${counto}.csv \
    --export-json ${HYPERFINE_LOGDIR}/timing-${counto}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/timing-${counto}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/timing-${counto}.md \
    './namgen'
}

fast_bench_runnr () {
  hyperfine \
    --warmup 3 \
    --runs 15 \
    --shell=none \
    --export-csv ${HYPERFINE_LOGDIR}/timing-fast-${counto}.csv \
    --export-json ${HYPERFINE_LOGDIR}/timing-fast-${counto}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/timing-fast-${counto}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/timing-fast-${counto}.md \
    './namgen'
}

faster_bench_runnr () {
  hyperfine \
    --warmup 1 \
    --runs 3 \
    --shell=none \
    --export-csv ${HYPERFINE_LOGDIR}/timing-faster-${counto}.csv \
    --export-json ${HYPERFINE_LOGDIR}/timing-faster-${counto}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/timing-faster-${counto}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/timing-faster-${counto}.md \
    './namgen'
}

fastest_bench_runnr () {
  hyperfine \
    --warmup 1 \
    --runs 2 \
    --shell=none \
    --export-csv ${HYPERFINE_LOGDIR}/timing-fastest-${counto}.csv \
    --export-json ${HYPERFINE_LOGDIR}/timing-fastest-${counto}.json \
    --export-asciidoc ${HYPERFINE_LOGDIR}/timing-fastest-${counto}.adoc \
    --export-markdown ${HYPERFINE_LOGDIR}/timing-fastest-${counto}.md \
    './namgen'
}

main () {
if [[ ${SPEED} == 'fast' ]]; then
  fast_bench_runnr
elif [[ ${SPEED} == 'slow' ]]; then
  slow_bench_runnr
elif [[ ${SPEED} == 'faster' ]]; then
  faster_bench_runnr
elif [[ ${SPEED} == 'fastest' ]]; then
  fastest_bench_runnr
elif [[ ${SPEED} == 'scanner' ]]; then
  scanner_bench_runnr
elif [[ ${SPEED} == 'slowest_scanner' ]]; then
  slowest_scanner_bench_runnr
elif [[ ${SPEED} == 'slow_scanner' ]]; then
  slow_scanner_bench_runnr
elif [[ ${SPEED} == 'fast_scanner' ]]; then
  fast_scanner_bench_runnr
elif [[ ${SPEED} == 'faster_scanner' ]]; then
  faster_scanner_bench_runnr
elif [[ ${SPEED} == 'fastest_scanner' ]]; then
  fastest_scanner_bench_runnr
else
  bench_runnr
fi
}

time main

exit 0

# WIP
  # 'export counto={counto} ./name-generator.sh' \
  # 'export counto={counto} ./name-generator.bash' \
  # 'export counto={counto} ./name-generator.zsh' \
  # 'export counto={counto} ./name-generator.py'
  #--parameter-scan counto 100 1000 \
  #--parameter-step-size 100 \
  #'export ${counto} ${commands}'
  #--parameter-list commands ./name-generator.sh,./name-generator.bash,./name-generator.zsh,./name-generator.py \
  #--parameter-list commands ./name-generator.sh,./name-generator.bash,./name-generator.zsh,./name-generator.py \
