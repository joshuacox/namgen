# Multi-stage Dockerfile for namgen
# Stage 1: Build & Test
FROM debian:trixie-slim AS builder

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get -qq update && apt-get -qqy --no-install-recommends install \
    build-essential cmake bats ca-certificates && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY CMakeLists.txt .
COPY src src
COPY man man
COPY assets assets
COPY completions completions
COPY test test

RUN cmake -B build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build -j$(nproc) && \
    cmake --install build

RUN bats test/full.bats

# Stage 2: Minimal Runtime
FROM debian:trixie-slim

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get -qq update && apt-get -qqy --no-install-recommends install \
    libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /usr/local/bin/namgen /usr/local/bin/namgen
COPY --from=builder /usr/local/share/namgen /usr/local/share/namgen
COPY --from=builder /usr/local/share/man/man1/namgen.1 /usr/local/share/man/man1/namgen.1

ENTRYPOINT ["namgen"]
CMD ["-c", "1"]
