cmake_minimum_required(VERSION 3.10)
project(namgen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(namgen
    src/namgen.cpp
    src/pets-marine_mammals_lib.cpp   # <-- added source file
    src/rift-bahmis_lib.cpp          # <-- new source file
    src/fantasy-angels_lib.cpp       # <-- added source file for angels
    src/lord_of_the_rings-elfs_lib.cpp
    src/destiny-awokens_lib.cpp
    src/destiny-cabals_lib.cpp
    src/destiny-exos_lib.cpp
    src/destiny-fallens_lib.cpp
    src/destiny-hives_lib.cpp
    src/destiny-humans_lib.cpp
    src/destiny-vexs_lib.cpp
    src/diablo-angels_lib.cpp
    src/diablo-demons_lib.cpp
    src/diablo-khazras_lib.cpp
    src/diablo-nephalems_lib.cpp
    src/dragon_ball-others_lib.cpp
    src/dragon_ball-frieza_clans_lib.cpp
    src/dragon_ball-hakaishins_lib.cpp
    src/dragon_ball-humans_lib.cpp
    src/dragon_ball-saiyans_lib.cpp
    src/dragon_ball-skians_lib.cpp
    src/dragon_ball-tuffles_lib.cpp
    src/dungeon_and_dragons-devas_lib.cpp
    src/dungeon_and_dragons-dragonborns_lib.cpp
    src/dungeon_and_dragons-drows_lib.cpp
    src/dungeon_and_dragons-dwarfs_lib.cpp
    src/dungeon_and_dragons-eladrins_lib.cpp
    src/dungeon_and_dragons-elfs_lib.cpp
    src/dungeon_and_dragons-githzerais_lib.cpp
    src/fantasy-aliens_lib.cpp
    src/fantasy-amazons_lib.cpp
    src/fantasy-animal_species_lib.cpp
    src/fantasy-animatronics_lib.cpp
    src/fantasy-apocalypse_mutants_lib.cpp
    src/halo-forerunners_lib.cpp
    src/military-united_states_lib.cpp
    src/diablo-angels_lib.cpp
    src/warhammer-ogres_lib.cpp
    src/doctor_who-silurians_lib.cpp
    src/towns_and_cities-ancient_greek_towns_lib.cpp
    src/final_fantasy-roegadyns_lib.cpp
    src/pets-marine_mammals_lib.cpp
    src/doctor_who-raxacoricofallapatorians_lib.cpp
)

# Installation
install(TARGETS namgen DESTINATION bin)

# Install the man page
install(FILES man/namgen.1 DESTINATION share/man/man1)
