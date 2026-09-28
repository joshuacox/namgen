#!/bin/bash
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SCORE_FILE="${REPO_ROOT}/harness/score.csv"
if [[ ! -f "$SCORE_FILE" ]]; then
  SCORE_FILE="${REPO_ROOT}/score.csv"
fi

if [[ -f "$SCORE_FILE" ]]; then
  cp -v "$SCORE_FILE" /tmp/
fi
git add .
git commit -am bork
git checkout main
if [[ -f /tmp/score.csv ]]; then
  mkdir -p "${REPO_ROOT}/harness"
  cp -v /tmp/score.csv "${REPO_ROOT}/harness/score.csv"
fi
git commit -am 'adding score'
