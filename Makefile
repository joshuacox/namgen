MAKEFLAGS += -j$(shell nproc 2>/dev/null || echo 4)

CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -Isrc
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=build/%.o)
TARGET := namgen

all: $(TARGET)

build:
	mkdir -p build

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	rm -rf build $(WASM_BUILD) $(TARGET) $(WASM_DIR)

test: $(TARGET)
	bash test/tester.sh

completions: $(TARGET)
	python3 scripts/generate_completions.py

# WebAssembly configuration
WASM_CXX ?= em++
WASM_CXXFLAGS ?= -std=c++17 -O2 -Isrc
WASM_BUILD := build-wasm
WASM_DIR := wasm
WASM_OBJS := $(SRCS:src/%.cpp=$(WASM_BUILD)/%.o)
WASM_TARGET := $(WASM_DIR)/namgen.js

$(WASM_BUILD):
	mkdir -p $(WASM_BUILD)

$(WASM_BUILD)/%.o: src/%.cpp | $(WASM_BUILD)
	$(WASM_CXX) $(WASM_CXXFLAGS) -c $< -o $@

wasm: $(WASM_TARGET)

$(WASM_TARGET): $(WASM_OBJS)
	mkdir -p $(WASM_DIR)
	$(WASM_CXX) -std=c++17 -O2 $(WASM_OBJS) -o $@ \
	  -sWASM=1 \
	  -sALLOW_MEMORY_GROWTH=1 \
	  -sEXPORTED_RUNTIME_METHODS='["callMain","FS","ccall","cwrap"]' \
	  -sEXPORTED_FUNCTIONS='["_main","_namgen_generate_wasm","_namgen_has_generator_wasm"]' \
	  -sMODULARIZE=1 \
	  -sEXPORT_NAME="createNamgen" \
	  --preload-file assets@/usr/local/share/namgen/assets
	mkdir -p web/public/wasm
	cp $(WASM_DIR)/namgen.wasm web/public/wasm/ 2>/dev/null || true
	cp $(WASM_DIR)/namgen.js web/public/wasm/ 2>/dev/null || true
	cp $(WASM_DIR)/namgen.data web/public/wasm/ 2>/dev/null || true


install: $(TARGET) completions
	install -d $(DESTDIR)/usr/local/bin
	install -m 755 $(TARGET) $(DESTDIR)/usr/local/bin/
	install -d $(DESTDIR)/usr/local/share/man/man1
	install -m 644 man/namgen.1 $(DESTDIR)/usr/local/share/man/man1/
	install -d $(DESTDIR)/usr/local/share/namgen
	cp -r assets $(DESTDIR)/usr/local/share/namgen/
	install -d $(DESTDIR)/usr/local/share/bash-completion/completions
	install -m 644 completions/namgen.bash $(DESTDIR)/usr/local/share/bash-completion/completions/namgen
	install -d $(DESTDIR)/usr/local/share/zsh/site-functions
	install -m 644 completions/_namgen $(DESTDIR)/usr/local/share/zsh/site-functions/_namgen
	install -d $(DESTDIR)/usr/local/share/fish/vendor_completions.d
	install -m 644 completions/namgen.fish $(DESTDIR)/usr/local/share/fish/vendor_completions.d/namgen.fish

.PHONY: all clean test install completions wasm
