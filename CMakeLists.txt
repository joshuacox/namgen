cmake_minimum_required(VERSION 3.12)
project(namgen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB GENERATOR_SOURCES CONFIGURE_DEPENDS "src/*_lib.cpp")

add_executable(namgen
    src/namgen.cpp
    src/generator_registry.cpp
    ${GENERATOR_SOURCES}
)

target_include_directories(namgen PRIVATE src)

install(TARGETS namgen DESTINATION bin)
install(DIRECTORY assets/ DESTINATION share/namgen/assets)
install(FILES man/namgen.1 DESTINATION share/man/man1)
