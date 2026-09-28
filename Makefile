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

install: $(TARGET)
	install -d $(DESTDIR)/usr/local/bin
	install -m 755 $(TARGET) $(DESTDIR)/usr/local/bin/
	install -d $(DESTDIR)/usr/local/share/man/man1
	install -m 644 man/namgen.1 $(DESTDIR)/usr/local/share/man/man1/
	install -d $(DESTDIR)/usr/local/share/namgen
	cp -r assets $(DESTDIR)/usr/local/share/namgen/

.PHONY: all clean test install
