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
	rm -rf build $(TARGET)

test: $(TARGET)
	bash test/tester.sh

completions: $(TARGET)
	python3 scripts/generate_completions.py

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

.PHONY: all clean test install completions
