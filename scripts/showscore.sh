#!/usr/bin/env bash
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SCORE_FILE="${REPO_ROOT}/harness/score.csv"
if [[ ! -f "$SCORE_FILE" ]]; then
  SCORE_FILE="${REPO_ROOT}/score.csv"
fi

if [[ -f "$SCORE_FILE" ]]; then
  column -t -s ',' "$SCORE_FILE"
else
  echo "No score.csv found."
fi
