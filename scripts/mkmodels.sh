#!/usr/bin/env bash
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
mkdir -p "${REPO_ROOT}/harness"

ollama list         \
  |awk '{print $1}' \
  |grep -v NAME     \
  >"${REPO_ROOT}/harness/models"
