#!/usr/bin/env bash
ollama list         \
  |awk '{print $1}' \
  |grep -v NAME     \
  >models
