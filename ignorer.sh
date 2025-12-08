#!/bin/bash
echo LICENSE > .aiderignore
find src -iname '*_lib.h' >> .aiderignore
find src -iname '*_lib.cpp' >> .aiderignore
