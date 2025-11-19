# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Project definition
project(namgen LANGUAGES CXX)

# --------------------------------------------------------------
# Build the executable
# --------------------------------------------------------------
add_executable(namgen src/namgen.cpp)

# expose the install prefix (e.g. /usr/local) to the C++ code
target_compile_definitions(namgen PRIVATE
    INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}"
)

# Require C++17 (or newer) – adjust if you need a different standard
target_compile_features(namgen PUBLIC cxx_std_17)

# --------------------------------------------------------------
# Installation rules
# --------------------------------------------------------------
# 1) Install the binary into <CMAKE_INSTALL_PREFIX>/bin
#    (default CMAKE_INSTALL_PREFIX is /usr/local, so this ends up in /usr/local/bin)
install(
    TARGETS namgen
    RUNTIME DESTINATION bin
)

# 2) Install the assets directory into <CMAKE_INSTALL_PREFIX>/share/namgen/assets
#    (default => /usr/local/share/namgen/assets)
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/
    DESTINATION share/namgen/assets
    FILES_MATCHING PATTERN "*"
)

# Install the man page with proper section handling
install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/man/namgen.1
    DESTINATION share/man/man1
    COMPONENT Runtime
)

# --------------------------------------------------------------
# Optional: make the install prefix visible to the user (helpful for packaging)
# --------------------------------------------------------------
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Binary will be installed to: ${CMAKE_INSTALL_PREFIX}/bin")
message(STATUS "Assets will be installed to: ${CMAKE_INSTALL_PREFIX}/share/namgen/assets")
