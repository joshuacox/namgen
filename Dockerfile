FROM debian:trixie-slim

RUN DEBIAN_FRONTEND=noninteractive \
apt-get -qq update && apt-get -qqy dist-upgrade && \
apt-get -qqy --no-install-recommends install \
build-essential cmake bats sudo && \
apt-get -y autoremove && \
apt-get clean && \
rm -Rf /var/lib/apt/lists/*

COPY src /assets/src
COPY man /assets/man
COPY assets /assets/assets
COPY test /assets/test
COPY CMakeLists.txt /assets/CMakeLists.txt
WORKDIR /assets

RUN cmake . && make && make install
RUN bats test/full.bats

#CMD ["./namgen"]
ENTRYPOINT ["./namgen"]
