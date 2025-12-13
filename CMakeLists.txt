cmake_minimum_required(VERSION 3.10)
project(namgen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(namgen
    src/namgen.cpp
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
    src/fantasy-angels_lib.cpp
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
    src/rift-bahmis_lib.cpp
    src/doctor_who-raxacoricofallapatorians_lib.cpp
    src/inheritance_cycle-dragons_lib.cpp
    src/pop_culture-homestucks_lib.cpp
    src/warhammer_40k-sisters_of_battles_lib.cpp
    src/towns_and_cities-east_european_towns_lib.cpp
    src/real-norwegians_lib.cpp
    src/rift-eths_lib.cpp
    src/halo-mgalekgolos_lib.cpp
    src/doctor_who-ice_warriors_lib.cpp
    src/warhammer-daemons_of_chaos_lib.cpp
    src/elder_scrolls-bosmers_lib.cpp
    src/harry_potter-goblins_lib.cpp
    src/eve_online-gallentes_lib.cpp
    src/star_wars_the_old_republic-cathars_lib.cpp
    src/military-royal_navy_lib.cpp
    src/towns_and_cities-west_european_towns_lib.cpp
    src/places-plazas_lib.cpp
    src/dragon_age-dwarfs_lib.cpp
    src/pets-reptiles_lib.cpp
    src/wildstar-mordeshs_lib.cpp
    src/towns_and_cities-dwarven_citys_lib.cpp
    src/real-anglo_saxons_lib.cpp
    src/harry_potter-dragon_species_lib.cpp
    src/game_of_thrones-dothrakis_lib.cpp
    src/descriptions-prophecys_lib.cpp
)

install(TARGETS namgen DESTINATION bin)
install(DIRECTORY assets/ DESTINATION share/namgen/assets)
install(FILES man/namgen.1 DESTINATION share/man/man1)
