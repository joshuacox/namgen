#!/usr/bin/env bash
HARNESS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${HARNESS_DIR}/.." && pwd)"

echo "${this_new_name},${model_name},${diff},${loopster_count},loopster-success" >> "${HARNESS_DIR}/score.csv"
"${REPO_ROOT}/scripts/reset2main.sh"
