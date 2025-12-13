#!/usr/bin/env bash

#aider \
aider-ce \
  --file src/namgen.cpp \
  --model "ollama_chat/${model_name}"           \
  --editor-model "ollama_chat/${model_name}"    \
  --weak-model "ollama_chat/${weak_model_name}" \
  --message '/test ./test.sh'
  #--agent \
  #--test \
  #--agent-config '{ "skip_cli_confirmations": true }' \
  #--test-cmd './test.sh' \
  #-m 'can you suggest improvements?'
