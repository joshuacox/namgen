#include "generator_registry.h"
#include <algorithm>
#include <cctype>
#include <memory>

#include "armour-belts_lib.h"
#include "armour-boots_lib.h"
#include "armour-chests_lib.h"
#include "armour-cloaks_lib.h"
#include "armour-gauntlets_lib.h"
#include "armour-helmets_lib.h"
#include "armour-legs_lib.h"
#include "armour-pauldrons_lib.h"
#include "armour-shields_lib.h"
#include "armour-vambraces_lib.h"
#include "descriptions-aliens_lib.h"
#include "descriptions-animals_lib.h"
#include "descriptions-armys_lib.h"
#include "descriptions-backstorys_lib.h"
#include "descriptions-battlefields_lib.h"
#include "descriptions-bows_lib.h"
#include "descriptions-castles_lib.h"
#include "descriptions-characters_lib.h"
#include "descriptions-citys_lib.h"
#include "descriptions-coat_of_arms_lib.h"
#include "descriptions-constellations_lib.h"
#include "descriptions-countrys_lib.h"
#include "descriptions-diseases_lib.h"
#include "descriptions-dragons_lib.h"
#include "descriptions-dungeons_lib.h"
#include "descriptions-dyings_lib.h"
#include "descriptions-fancy_clothings_lib.h"
#include "descriptions-flags_lib.h"
#include "descriptions-gems_lib.h"
#include "descriptions-ghost_towns_lib.h"
#include "descriptions-gods_lib.h"
#include "descriptions-hand_gestures_lib.h"
#include "descriptions-holidays_lib.h"
#include "descriptions-houses_lib.h"
#include "descriptions-humanoids_lib.h"
#include "descriptions-laws_lib.h"
#include "descriptions-leather_armors_lib.h"
#include "descriptions-martial_arts_lib.h"
#include "descriptions-medieval_clothings_lib.h"
#include "descriptions-monuments_lib.h"
#include "descriptions-pains_lib.h"
#include "descriptions-personalitys_lib.h"
#include "descriptions-pistols_lib.h"
#include "descriptions-planets_lib.h"
#include "descriptions-plants_lib.h"
#include "descriptions-plate_armors_lib.h"
#include "descriptions-plots_lib.h"
#include "descriptions-pokemons_lib.h"
#include "descriptions-potions_lib.h"
#include "descriptions-prophecys_lib.h"
#include "descriptions-quests_lib.h"
#include "descriptions-rag_clothings_lib.h"
#include "descriptions-rifles_lib.h"
#include "descriptions-school_uniforms_lib.h"
#include "descriptions-shields_lib.h"
#include "descriptions-shotguns_lib.h"
#include "descriptions-societys_lib.h"
#include "descriptions-spells_lib.h"
#include "descriptions-staffs_lib.h"
#include "descriptions-taverns_lib.h"
#include "descriptions-towns_lib.h"
#include "descriptions-traditions_lib.h"
#include "descriptions-wands_lib.h"
#include "descriptions-weapons_lib.h"
#include "destiny-awokens_lib.h"
#include "destiny-cabals_lib.h"
#include "destiny-exos_lib.h"
#include "destiny-fallens_lib.h"
#include "destiny-hives_lib.h"
#include "destiny-humans_lib.h"
#include "destiny-vexs_lib.h"
#include "diablo-angels_lib.h"
#include "diablo-demons_lib.h"
#include "diablo-khazras_lib.h"
#include "diablo-nephalems_lib.h"
#include "doctor_who-daleks_lib.h"
#include "doctor_who-gallifreyans_lib.h"
#include "doctor_who-ice_warriors_lib.h"
#include "doctor_who-raxacoricofallapatorians_lib.h"
#include "doctor_who-silurians_lib.h"
#include "doctor_who-sontarans_lib.h"
#include "doctor_who-zygons_lib.h"
#include "dragon_age-dwarfs_lib.h"
#include "dragon_age-elfs_lib.h"
#include "dragon_age-humans_lib.h"
#include "dragon_age-qunaris_lib.h"
#include "dragon_ball-frieza_clans_lib.h"
#include "dragon_ball-hakaishins_lib.h"
#include "dragon_ball-humans_lib.h"
#include "dragon_ball-others_lib.h"
#include "dragon_ball-saiyans_lib.h"
#include "dragon_ball-skians_lib.h"
#include "dragon_ball-tuffles_lib.h"
#include "dungeon_and_dragons-devas_lib.h"
#include "dungeon_and_dragons-dragonborns_lib.h"
#include "dungeon_and_dragons-drows_lib.h"
#include "dungeon_and_dragons-dwarfs_lib.h"
#include "dungeon_and_dragons-eladrins_lib.h"
#include "dungeon_and_dragons-elfs_lib.h"
#include "dungeon_and_dragons-githzerais_lib.h"
#include "dungeon_and_dragons-gnomes_lib.h"
#include "dungeon_and_dragons-goliaths_lib.h"
#include "dungeon_and_dragons-half_elfs_lib.h"
#include "dungeon_and_dragons-half_orcs_lib.h"
#include "dungeon_and_dragons-halflings_lib.h"
#include "dungeon_and_dragons-humans_lib.h"
#include "dungeon_and_dragons-minotaurs_lib.h"
#include "dungeon_and_dragons-shardminds_lib.h"
#include "dungeon_and_dragons-shifters_lib.h"
#include "dungeon_and_dragons-tieflings_lib.h"
#include "dungeon_and_dragons-wildens_lib.h"
#include "elder_scrolls-altmers_lib.h"
#include "elder_scrolls-argonians_lib.h"
#include "elder_scrolls-bosmers_lib.h"
#include "elder_scrolls-bretons_lib.h"
#include "elder_scrolls-daedrics_lib.h"
#include "elder_scrolls-dragons_lib.h"
#include "elder_scrolls-dunmers_lib.h"
#include "elder_scrolls-dwemers_lib.h"
#include "elder_scrolls-falmers_lib.h"
#include "elder_scrolls-forsworns_lib.h"
#include "elder_scrolls-imperials_lib.h"
#include "elder_scrolls-khajiits_lib.h"
#include "elder_scrolls-nords_lib.h"
#include "elder_scrolls-orc_lib.h"
#include "elder_scrolls-redguards_lib.h"
#include "elder_scrolls-spriggans_lib.h"
#include "eve_online-amarrs_lib.h"
#include "eve_online-caldaris_lib.h"
#include "eve_online-gallentes_lib.h"
#include "eve_online-minmatars_lib.h"
#include "fantasy-aliens_lib.h"
#include "fantasy-amazons_lib.h"
#include "fantasy-angels_lib.h"
#include "fantasy-animal_species_lib.h"
#include "fantasy-animatronics_lib.h"
#include "fantasy-apocalypse_mutants_lib.h"
#include "fantasy-bandits_lib.h"
#include "fantasy-barbarians_lib.h"
#include "fantasy-bounty_hunters_lib.h"
#include "fantasy-cat_people_nekojins_lib.h"
#include "fantasy-cavemens_lib.h"
#include "fantasy-centaurs_lib.h"
#include "fantasy-christmas_elfs_lib.h"
#include "fantasy-codes_lib.h"
#include "fantasy-cowboys_lib.h"
#include "fantasy-creatures_lib.h"
#include "fantasy-deaths_lib.h"
#include "fantasy-demons_lib.h"
#include "fantasy-detectives_lib.h"
#include "fantasy-dragons_lib.h"
#include "fantasy-dryads_lib.h"
#include "fantasy-dwarfs_lib.h"
#include "fantasy-elementals_lib.h"
#include "fantasy-elfs_lib.h"
#include "fantasy-ents_lib.h"
#include "fantasy-evils_lib.h"
#include "fantasy-fairys_lib.h"
#include "fantasy-fantasy_animals_lib.h"
#include "fantasy-fantasy_races_lib.h"
#include "fantasy-fantasy_surnames_lib.h"
#include "fantasy-fursonas_lib.h"
#include "fantasy-futuristics_lib.h"
#include "fantasy-ghost_classifications_lib.h"
#include "fantasy-ghosts_lib.h"
#include "fantasy-giants_lib.h"
#include "fantasy-gnolls_lib.h"
#include "fantasy-gnomes_lib.h"
#include "fantasy-goblins_lib.h"
#include "fantasy-gods_lib.h"
#include "fantasy-gorgons_lib.h"
#include "fantasy-griffins_lib.h"
#include "fantasy-half_elfs_lib.h"
#include "fantasy-harpys_lib.h"
#include "fantasy-heros_lib.h"
#include "fantasy-hobbits_lib.h"
#include "fantasy-horses_lib.h"
#include "fantasy-imps_lib.h"
#include "fantasy-kaijus_lib.h"
#include "fantasy-killers_lib.h"
#include "fantasy-knights_lib.h"
#include "fantasy-kobolds_lib.h"
#include "fantasy-lamias_lib.h"
#include "fantasy-lichs_lib.h"
#include "fantasy-mechas_lib.h"
#include "fantasy-medievals_lib.h"
#include "fantasy-mermaids_lib.h"
#include "fantasy-minotaurs_lib.h"
#include "fantasy-mobsters_lib.h"
#include "fantasy-monsters_lib.h"
#include "fantasy-mutant_species_lib.h"
#include "fantasy-nagas_lib.h"
#include "fantasy-necromancers_lib.h"
#include "fantasy-nephilims_lib.h"
#include "fantasy-ninjas_lib.h"
#include "fantasy-nymphs_lib.h"
#include "fantasy-ogres_lib.h"
#include "fantasy-orcs_lib.h"
#include "fantasy-pegasus_lib.h"
#include "fantasy-phoenixs_lib.h"
#include "fantasy-pirates_lib.h"
#include "fantasy-robots_lib.h"
#include "fantasy-satyr_fauns_lib.h"
#include "fantasy-sea_creatures_lib.h"
#include "fantasy-servants_lib.h"
#include "fantasy-shapeshifters_lib.h"
#include "fantasy-sirens_lib.h"
#include "fantasy-slaves_lib.h"
#include "fantasy-species_lib.h"
#include "fantasy-steampunks_lib.h"
#include "fantasy-succubus_lib.h"
#include "fantasy-superhero_teams_lib.h"
#include "fantasy-sylphs_lib.h"
#include "fantasy-taurens_lib.h"
#include "fantasy-trolls_lib.h"
#include "fantasy-twins_lib.h"
#include "fantasy-unicorns_lib.h"
#include "fantasy-valkyries_lib.h"
#include "fantasy-vampire_clans_lib.h"
#include "fantasy-vampires_lib.h"
#include "fantasy-villains_lib.h"
#include "fantasy-warrior_nicknames_lib.h"
#include "fantasy-werewolf_packs_lib.h"
#include "fantasy-werewolfs_lib.h"
#include "fantasy-witchs_lib.h"
#include "fantasy-wizards_lib.h"
#include "fantasy-zombie_types_lib.h"
#include "final_fantasy-au_ras_lib.h"
#include "final_fantasy-elezens_lib.h"
#include "final_fantasy-hyurs_lib.h"
#include "final_fantasy-lalafells_lib.h"
#include "final_fantasy-miqotes_lib.h"
#include "final_fantasy-roegadyns_lib.h"
#include "game_of_thrones-dothrakis_lib.h"
#include "game_of_thrones-free_citys_lib.h"
#include "game_of_thrones-free_folks_lib.h"
#include "game_of_thrones-ghiscaris_lib.h"
#include "game_of_thrones-mountain_clans_lib.h"
#include "game_of_thrones-nicknames_lib.h"
#include "game_of_thrones-summer_islanders_lib.h"
#include "game_of_thrones-unsullieds_lib.h"
#include "game_of_thrones-valyrians_lib.h"
#include "game_of_thrones-westeros_lib.h"
#include "guild_wars-asuras_lib.h"
#include "guild_wars-charrs_lib.h"
#include "guild_wars-human_lib.h"
#include "guild_wars-norns_lib.h"
#include "guild_wars-sylvaris_lib.h"
#include "halo-forerunners_lib.h"
#include "halo-huragoks_lib.h"
#include "halo-jiralhanaes_lib.h"
#include "halo-kig_yars_lib.h"
#include "halo-mgalekgolos_lib.h"
#include "halo-san_shyuums_lib.h"
#include "halo-sangheilis_lib.h"
#include "halo-unggoys_lib.h"
#include "harry_potter-dragon_species_lib.h"
#include "harry_potter-goblins_lib.h"
#include "harry_potter-hippogriffs_lib.h"
#include "harry_potter-house_elfs_lib.h"
#include "harry_potter-winged_horses_lib.h"
#include "inheritance_cycle-dragons_lib.h"
#include "inheritance_cycle-dwarfs_lib.h"
#include "inheritance_cycle-elfs_lib.h"
#include "inheritance_cycle-humans_lib.h"
#include "inheritance_cycle-urgals_lib.h"
#include "legend_of_zelda-anoukis_lib.h"
#include "legend_of_zelda-deitys_lib.h"
#include "legend_of_zelda-dekus_lib.h"
#include "legend_of_zelda-fairys_lib.h"
#include "legend_of_zelda-gerudos_lib.h"
#include "legend_of_zelda-gorons_lib.h"
#include "legend_of_zelda-humans_lib.h"
#include "legend_of_zelda-korok_kokiris_lib.h"
#include "legend_of_zelda-minishs_lib.h"
#include "legend_of_zelda-zoras_lib.h"
#include "lord_of_the_rings-dwarfs_lib.h"
#include "lord_of_the_rings-elfs_lib.h"
#include "lord_of_the_rings-hobbits_lib.h"
#include "lord_of_the_rings-humans_lib.h"
#include "lord_of_the_rings-maiars_lib.h"
#include "lord_of_the_rings-orcs_lib.h"
#include "lord_of_the_rings_online-beorning_lib.h"
#include "lord_of_the_rings_online-dwarf_lib.h"
#include "lord_of_the_rings_online-elf_lib.h"
#include "lord_of_the_rings_online-hobbit_lib.h"
#include "lord_of_the_rings_online-human_lib.h"
#include "mass_effect-asaris_lib.h"
#include "mass_effect-batarians_lib.h"
#include "mass_effect-drells_lib.h"
#include "mass_effect-geths_lib.h"
#include "mass_effect-humans_lib.h"
#include "mass_effect-krogans_lib.h"
#include "mass_effect-quarians_lib.h"
#include "mass_effect-salarians_lib.h"
#include "mass_effect-turians_lib.h"
#include "military-itu_lib.h"
#include "military-nato_lib.h"
#include "military-numeric_lib.h"
#include "military-royal_air_force_lib.h"
#include "military-royal_navy_lib.h"
#include "military-signalese_lib.h"
#include "military-telegram_lib.h"
#include "military-united_states_lib.h"
#include "miscellaneous-afterlifes_lib.h"
#include "miscellaneous-airplanes_lib.h"
#include "miscellaneous-airships_lib.h"
#include "miscellaneous-alliances_lib.h"
#include "miscellaneous-animal_groups_lib.h"
#include "miscellaneous-anime_attacks_lib.h"
#include "miscellaneous-apocalypses_lib.h"
#include "miscellaneous-armys_lib.h"
#include "miscellaneous-artifacts_lib.h"
#include "miscellaneous-attack_moves_lib.h"
#include "miscellaneous-awards_lib.h"
#include "miscellaneous-bands_lib.h"
#include "miscellaneous-battles_lib.h"
#include "miscellaneous-birds_lib.h"
#include "miscellaneous-board_games_lib.h"
#include "miscellaneous-book_titles_lib.h"
#include "miscellaneous-bouquets_lib.h"
#include "miscellaneous-brands_lib.h"
#include "miscellaneous-candys_lib.h"
#include "miscellaneous-cars_lib.h"
#include "miscellaneous-chivalric_orders_lib.h"
#include "miscellaneous-class_lib.h"
#include "miscellaneous-clothing_brands_lib.h"
#include "miscellaneous-colors_lib.h"
#include "miscellaneous-constellations_lib.h"
#include "miscellaneous-creepypastas_lib.h"
#include "miscellaneous-crops_lib.h"
#include "miscellaneous-currencys_lib.h"
#include "miscellaneous-dances_lib.h"
#include "miscellaneous-dates_lib.h"
#include "miscellaneous-dinosaurs_lib.h"
#include "miscellaneous-diseases_lib.h"
#include "miscellaneous-drinks_lib.h"
#include "miscellaneous-drugs_lib.h"
#include "miscellaneous-enchantments_lib.h"
#include "miscellaneous-energy_types_lib.h"
#include "miscellaneous-epithets_lib.h"
#include "miscellaneous-evil_groups_lib.h"
#include "miscellaneous-foods_lib.h"
#include "miscellaneous-fruit_vegetables_lib.h"
#include "miscellaneous-fungis_lib.h"
#include "miscellaneous-galaxys_lib.h"
#include "miscellaneous-game_engines_lib.h"
#include "miscellaneous-game_soundtracks_lib.h"
#include "miscellaneous-gangs_lib.h"
#include "miscellaneous-gear_enchantments_lib.h"
#include "miscellaneous-gem_minerals_lib.h"
#include "miscellaneous-graffiti_tags_lib.h"
#include "miscellaneous-guilds_lib.h"
#include "miscellaneous-hackers_lib.h"
#include "miscellaneous-heists_lib.h"
#include "miscellaneous-helicopters_lib.h"
#include "miscellaneous-herbs_lib.h"
#include "miscellaneous-holidays_lib.h"
#include "miscellaneous-holy_books_lib.h"
#include "miscellaneous-human_species_lib.h"
#include "miscellaneous-instruments_lib.h"
#include "miscellaneous-inventions_lib.h"
#include "miscellaneous-jewelrys_lib.h"
#include "miscellaneous-languages_lib.h"
#include "miscellaneous-love_nicknames_lib.h"
#include "miscellaneous-magazines_lib.h"
#include "miscellaneous-magic_types_lib.h"
#include "miscellaneous-magical_diseases_lib.h"
#include "miscellaneous-magical_plants_lib.h"
#include "miscellaneous-magical_trees_lib.h"
#include "miscellaneous-martial_arts_lib.h"
#include "miscellaneous-mascots_lib.h"
#include "miscellaneous-medicines_lib.h"
#include "miscellaneous-metals_lib.h"
#include "miscellaneous-military_divisions_lib.h"
#include "miscellaneous-military_operations_lib.h"
#include "miscellaneous-military_ranks_lib.h"
#include "miscellaneous-military_vehicles_lib.h"
#include "miscellaneous-molecules_lib.h"
#include "miscellaneous-motorcycle_clubs_lib.h"
#include "miscellaneous-mutant_plants_lib.h"
#include "miscellaneous-natural_disasters_lib.h"
#include "miscellaneous-newspapers_lib.h"
#include "miscellaneous-nicknames_lib.h"
#include "miscellaneous-noble_houses_lib.h"
#include "miscellaneous-pirate_crews_lib.h"
#include "miscellaneous-pirate_ships_lib.h"
#include "miscellaneous-plagues_lib.h"
#include "miscellaneous-plants_lib.h"
#include "miscellaneous-poisons_lib.h"
#include "miscellaneous-political_partys_lib.h"
#include "miscellaneous-post_apocalyptic_societys_lib.h"
#include "miscellaneous-potions_lib.h"
#include "miscellaneous-professions_lib.h"
#include "miscellaneous-racers_lib.h"
#include "miscellaneous-railways_lib.h"
#include "miscellaneous-ranks_lib.h"
#include "miscellaneous-religions_lib.h"
#include "miscellaneous-scientific_creatures_lib.h"
#include "miscellaneous-ships_lib.h"
#include "miscellaneous-siege_engines_lib.h"
#include "miscellaneous-softwares_lib.h"
#include "miscellaneous-song_titles_lib.h"
#include "miscellaneous-space_fleets_lib.h"
#include "miscellaneous-spaceships_lib.h"
#include "miscellaneous-spells_lib.h"
#include "miscellaneous-sports_lib.h"
#include "miscellaneous-sports_teams_lib.h"
#include "miscellaneous-squads_lib.h"
#include "miscellaneous-superpowers_lib.h"
#include "miscellaneous-teleportations_lib.h"
#include "miscellaneous-thrones_lib.h"
#include "miscellaneous-time_periods_lib.h"
#include "miscellaneous-titles_lib.h"
#include "miscellaneous-tool_nicknames_lib.h"
#include "miscellaneous-treatys_lib.h"
#include "miscellaneous-trees_lib.h"
#include "miscellaneous-tribals_lib.h"
#include "miscellaneous-tribes_lib.h"
#include "miscellaneous-usernames_lib.h"
#include "miscellaneous-vehicles_lib.h"
#include "miscellaneous-video_games_lib.h"
#include "miscellaneous-vocal_groups_lib.h"
#include "miscellaneous-weapon_abilities_lib.h"
#include "miscellaneous-web_series_lib.h"
#include "miscellaneous-wines_lib.h"
#include "miscellaneous-wrestlers_lib.h"
#include "miscellaneous-wrestling_moves_lib.h"
#include "pathfinder-aasimars_lib.h"
#include "pathfinder-catfolks_lib.h"
#include "pathfinder-drows_lib.h"
#include "pathfinder-dwarfs_lib.h"
#include "pathfinder-elfs_lib.h"
#include "pathfinder-fetchlings_lib.h"
#include "pathfinder-gnomes_lib.h"
#include "pathfinder-goblins_lib.h"
#include "pathfinder-half_elfs_lib.h"
#include "pathfinder-half_orcs_lib.h"
#include "pathfinder-halflings_lib.h"
#include "pathfinder-hobgoblins_lib.h"
#include "pathfinder-humans_lib.h"
#include "pathfinder-ifrits_lib.h"
#include "pathfinder-kobolds_lib.h"
#include "pathfinder-orcs_lib.h"
#include "pathfinder-oreads_lib.h"
#include "pathfinder-ratfolks_lib.h"
#include "pathfinder-sylphs_lib.h"
#include "pathfinder-tengus_lib.h"
#include "pathfinder-tians_lib.h"
#include "pathfinder-tieflings_lib.h"
#include "pathfinder-undines_lib.h"
#include "pets-aliens_lib.h"
#include "pets-amphibians_lib.h"
#include "pets-bats_lib.h"
#include "pets-bears_lib.h"
#include "pets-bird_of_preys_lib.h"
#include "pets-birds_lib.h"
#include "pets-cats_lib.h"
#include "pets-cows_lib.h"
#include "pets-crabs_lib.h"
#include "pets-deers_lib.h"
#include "pets-dogs_lib.h"
#include "pets-elephants_lib.h"
#include "pets-fishs_lib.h"
#include "pets-horses_lib.h"
#include "pets-insects_lib.h"
#include "pets-lions_lib.h"
#include "pets-marine_mammals_lib.h"
#include "pets-monkeys_lib.h"
#include "pets-mouses_lib.h"
#include "pets-owls_lib.h"
#include "pets-parrots_lib.h"
#include "pets-pigs_lib.h"
#include "pets-rabbits_lib.h"
#include "pets-reptiles_lib.h"
#include "pets-rodents_lib.h"
#include "pets-sheeps_lib.h"
#include "pets-turtles_lib.h"
#include "pets-wolfs_lib.h"
#include "places-amusement_parks_lib.h"
#include "places-antique_stores_lib.h"
#include "places-asylums_lib.h"
#include "places-bakerys_lib.h"
#include "places-banks_lib.h"
#include "places-battle_arenas_lib.h"
#include "places-beachs_lib.h"
#include "places-brewerys_lib.h"
#include "places-bridges_lib.h"
#include "places-business_lib.h"
#include "places-cafes_lib.h"
#include "places-camps_lib.h"
#include "places-casinos_lib.h"
#include "places-castles_lib.h"
#include "places-caves_lib.h"
#include "places-circus_lib.h"
#include "places-city_districts_lib.h"
#include "places-civilizations_lib.h"
#include "places-cliffs_lib.h"
#include "places-companys_lib.h"
#include "places-continents_lib.h"
#include "places-countrys_lib.h"
#include "places-day_cares_lib.h"
#include "places-dimensions_lib.h"
#include "places-dungeons_lib.h"
#include "places-farms_lib.h"
#include "places-film_studios_lib.h"
#include "places-fire_lands_lib.h"
#include "places-forests_lib.h"
#include "places-game_studios_lib.h"
#include "places-grasslands_lib.h"
#include "places-graveyards_lib.h"
#include "places-harbors_lib.h"
#include "places-headquarters_lib.h"
#include "places-hospitals_lib.h"
#include "places-hotels_lib.h"
#include "places-inns_lib.h"
#include "places-islands_lib.h"
#include "places-jungles_lib.h"
#include "places-kingdoms_lib.h"
#include "places-laboratorys_lib.h"
#include "places-lakes_lib.h"
#include "places-lands_lib.h"
#include "places-librarys_lib.h"
#include "places-magic_schools_lib.h"
#include "places-magic_shops_lib.h"
#include "places-mansions_lib.h"
#include "places-mining_companys_lib.h"
#include "places-mountains_lib.h"
#include "places-museums_lib.h"
#include "places-nightclubs_lib.h"
#include "places-oasis_lib.h"
#include "places-orphanages_lib.h"
#include "places-outposts_lib.h"
#include "places-parks_lib.h"
#include "places-pirate_coves_lib.h"
#include "places-planets_lib.h"
#include "places-plantations_lib.h"
#include "places-plazas_lib.h"
#include "places-prisons_lib.h"
#include "places-realms_lib.h"
#include "places-restaurants_lib.h"
#include "places-rivers_lib.h"
#include "places-roads_lib.h"
#include "places-ruins_lib.h"
#include "places-schools_lib.h"
#include "places-shops_lib.h"
#include "places-sky_islands_lib.h"
#include "places-snowlands_lib.h"
#include "places-space_colonys_lib.h"
#include "places-stadiums_lib.h"
#include "places-stars_lib.h"
#include "places-streets_lib.h"
#include "places-swamps_lib.h"
#include "places-temples_lib.h"
#include "places-theaters_lib.h"
#include "places-towers_lib.h"
#include "places-volcanos_lib.h"
#include "places-waterfalls_lib.h"
#include "places-waters_lib.h"
#include "pop_culture-arthurians_lib.h"
#include "pop_culture-avatar_last_airbenders_lib.h"
#include "pop_culture-digimons_lib.h"
#include "pop_culture-dragonriders_of_perns_lib.h"
#include "pop_culture-homestucks_lib.h"
#include "pop_culture-how_to_train_your_dragons_lib.h"
#include "pop_culture-hunger_games_lib.h"
#include "pop_culture-hyborians_lib.h"
#include "pop_culture-lovecraftians_lib.h"
#include "pop_culture-maze_runners_lib.h"
#include "pop_culture-mortal_kombats_lib.h"
#include "pop_culture-my_little_ponys_lib.h"
#include "pop_culture-one_piece_devil_fruits_lib.h"
#include "pop_culture-pacific_rims_lib.h"
#include "pop_culture-pokemons_lib.h"
#include "pop_culture-rwbys_lib.h"
#include "pop_culture-shadowhunter_chronicles_lib.h"
#include "pop_culture-skulduggery_pleasants_lib.h"
#include "pop_culture-starcrafts_lib.h"
#include "pop_culture-stormlight_archives_lib.h"
#include "pop_culture-transformers_lib.h"
#include "pop_culture-warrior_cats_lib.h"
#include "pop_culture-wheel_of_times_lib.h"
#include "pop_culture-wings_of_fires_lib.h"
#include "pop_culture-x_mens_lib.h"
#include "real-20th_century_englishs_lib.h"
#include "real-aboriginals_lib.h"
#include "real-african_americans_lib.h"
#include "real-akans_lib.h"
#include "real-albanians_lib.h"
#include "real-algerians_lib.h"
#include "real-amazighs_lib.h"
#include "real-ancient_greeks_lib.h"
#include "real-anglo_saxons_lib.h"
#include "real-argentinians_lib.h"
#include "real-armenians_lib.h"
#include "real-assyrians_lib.h"
#include "real-azerbaijanis_lib.h"
#include "real-aztecs_lib.h"
#include "real-babylonians_lib.h"
#include "real-basothos_lib.h"
#include "real-basques_lib.h"
#include "real-belgians_lib.h"
#include "real-bengalis_lib.h"
#include "real-biblicals_lib.h"
#include "real-bosnians_lib.h"
#include "real-brazilians_lib.h"
#include "real-bulgarians_lib.h"
#include "real-burmese_myanmars_lib.h"
#include "real-cajuns_lib.h"
#include "real-catalans_lib.h"
#include "real-celtic_bretons_lib.h"
#include "real-celtic_welshs_lib.h"
#include "real-celtics_lib.h"
#include "real-chineses_lib.h"
#include "real-circassians_lib.h"
#include "real-colonial_americans_lib.h"
#include "real-croatians_lib.h"
#include "real-czechs_lib.h"
#include "real-danishs_lib.h"
#include "real-dutchs_lib.h"
#include "real-edo_japaneses_lib.h"
#include "real-edwardians_lib.h"
#include "real-egyptians_lib.h"
#include "real-englishs_lib.h"
#include "real-enochians_lib.h"
#include "real-estonians_lib.h"
#include "real-ethiopians_lib.h"
#include "real-faroeses_lib.h"
#include "real-filipinos_lib.h"
#include "real-finnishs_lib.h"
#include "real-frankishs_lib.h"
#include "real-frenchs_lib.h"
#include "real-frisians_lib.h"
#include "real-georgians_lib.h"
#include "real-germans_lib.h"
#include "real-gothics_lib.h"
#include "real-greeks_lib.h"
#include "real-hausas_lib.h"
#include "real-hawaiians_lib.h"
#include "real-hebrews_lib.h"
#include "real-hillbillys_lib.h"
#include "real-hindus_lib.h"
#include "real-hippies_lib.h"
#include "real-hispanics_lib.h"
#include "real-hungarians_lib.h"
#include "real-icelandics_lib.h"
#include "real-indonesians_lib.h"
#include "real-inuits_lib.h"
#include "real-irishs_lib.h"
#include "real-italians_lib.h"
#include "real-jamaicans_lib.h"
#include "real-japaneses_lib.h"
#include "real-jewishs_lib.h"
#include "real-kazakhs_lib.h"
#include "real-khmers_lib.h"
#include "real-koreans_lib.h"
#include "real-kurdishs_lib.h"
#include "real-laotians_lib.h"
#include "real-latins_lib.h"
#include "real-latvians_lib.h"
#include "real-lithuanians_lib.h"
#include "real-malaysians_lib.h"
#include "real-malteses_lib.h"
#include "real-maoris_lib.h"
#include "real-mayans_lib.h"
#include "real-modern_egyptians_lib.h"
#include "real-mongolians_lib.h"
#include "real-moroccans_lib.h"
#include "real-muslims_lib.h"
#include "real-native_americans_lib.h"
#include "real-natures_lib.h"
#include "real-nepaleses_lib.h"
#include "real-normans_lib.h"
#include "real-norwegians_lib.h"
#include "real-old_high_germans_lib.h"
#include "real-pashtuns_lib.h"
#include "real-persians_lib.h"
#include "real-polishs_lib.h"
#include "real-portugueses_lib.h"
#include "real-poshs_lib.h"
#include "real-punjabis_lib.h"
#include "real-puritans_lib.h"
#include "real-quebecois_lib.h"
#include "real-roma_gypsys_lib.h"
#include "real-romanians_lib.h"
#include "real-romans_lib.h"
#include "real-russians_lib.h"
#include "real-serbians_lib.h"
#include "real-shakespeareans_lib.h"
#include "real-shonas_lib.h"
#include "real-sikhs_lib.h"
#include "real-sinhaleses_lib.h"
#include "real-slavics_lib.h"
#include "real-slovenians_lib.h"
#include "real-somalis_lib.h"
#include "real-stages_lib.h"
#include "real-suebis_lib.h"
#include "real-sumerians_lib.h"
#include "real-swahilis_lib.h"
#include "real-swedishs_lib.h"
#include "real-swiss_lib.h"
#include "real-tajiks_lib.h"
#include "real-tamils_lib.h"
#include "real-telugus_lib.h"
#include "real-thais_lib.h"
#include "real-tibetans_lib.h"
#include "real-turkishs_lib.h"
#include "real-twins_lib.h"
#include "real-ukrainians_lib.h"
#include "real-victorians_lib.h"
#include "real-vietnameses_lib.h"
#include "real-vikings_lib.h"
#include "real-yorubas_lib.h"
#include "real-zulus_lib.h"
#include "rift-bahmis_lib.h"
#include "rift-dwarfs_lib.h"
#include "rift-eths_lib.h"
#include "rift-high_elfs_lib.h"
#include "rift-kelaris_lib.h"
#include "rift-mathosians_lib.h"
#include "star_trek-andorians_lib.h"
#include "star_trek-bajorans_lib.h"
#include "star_trek-benzites_lib.h"
#include "star_trek-betazoids_lib.h"
#include "star_trek-bolians_lib.h"
#include "star_trek-caitians_lib.h"
#include "star_trek-ferengis_lib.h"
#include "star_trek-gorns_lib.h"
#include "star_trek-jemhadars_lib.h"
#include "star_trek-klingons_lib.h"
#include "star_trek-letheans_lib.h"
#include "star_trek-nausicaans_lib.h"
#include "star_trek-orions_lib.h"
#include "star_trek-pakleds_lib.h"
#include "star_trek-remans_lib.h"
#include "star_trek-rigelians_lib.h"
#include "star_trek-romulans_lib.h"
#include "star_trek-saurians_lib.h"
#include "star_trek-tellarites_lib.h"
#include "star_trek-trills_lib.h"
#include "star_trek-vulcans_lib.h"
#include "star_wars-anzatis_lib.h"
#include "star_wars-biths_lib.h"
#include "star_wars-bothans_lib.h"
#include "star_wars-darths_lib.h"
#include "star_wars-devaronians_lib.h"
#include "star_wars-dugs_lib.h"
#include "star_wars-duross_lib.h"
#include "star_wars-ewoks_lib.h"
#include "star_wars-falleens_lib.h"
#include "star_wars-gamorreans_lib.h"
#include "star_wars-gands_lib.h"
#include "star_wars-gotals_lib.h"
#include "star_wars-grans_lib.h"
#include "star_wars-gungans_lib.h"
#include "star_wars-hutts_lib.h"
#include "star_wars-iktotchis_lib.h"
#include "star_wars-ishi_tibs_lib.h"
#include "star_wars-ithorians_lib.h"
#include "star_wars-jawas_lib.h"
#include "star_wars-kel_dors_lib.h"
#include "star_wars-korunnais_lib.h"
#include "star_wars-mandalorians_lib.h"
#include "star_wars-mon_calamaris_lib.h"
#include "star_wars-nautolans_lib.h"
#include "star_wars-neimoidians_lib.h"
#include "star_wars-niktos_lib.h"
#include "star_wars-ortolans_lib.h"
#include "star_wars-quarrens_lib.h"
#include "star_wars-rodians_lib.h"
#include "star_wars-shistavanens_lib.h"
#include "star_wars-sullustans_lib.h"
#include "star_wars-swiss_lib.h"
#include "star_wars-toydarians_lib.h"
#include "star_wars-trandoshans_lib.h"
#include "star_wars-tusken_raiders_lib.h"
#include "star_wars-weequays_lib.h"
#include "star_wars-wookiees_lib.h"
#include "star_wars_the_old_republic-cathars_lib.h"
#include "star_wars_the_old_republic-chiss_lib.h"
#include "star_wars_the_old_republic-cyborgs_lib.h"
#include "star_wars_the_old_republic-human_sws_lib.h"
#include "star_wars_the_old_republic-miralukas_lib.h"
#include "star_wars_the_old_republic-mirialans_lib.h"
#include "star_wars_the_old_republic-rattatakis_lib.h"
#include "star_wars_the_old_republic-siths_lib.h"
#include "star_wars_the_old_republic-togrutas_lib.h"
#include "star_wars_the_old_republic-twileks_lib.h"
#include "star_wars_the_old_republic-zabraks_lib.h"
#include "the_witcher-dwarfs_lib.h"
#include "the_witcher-elfs_lib.h"
#include "the_witcher-halflings_lib.h"
#include "the_witcher-humans_lib.h"
#include "towns_and_cities-ancient_greek_towns_lib.h"
#include "towns_and_cities-apocalypse_towns_lib.h"
#include "towns_and_cities-central_african_towns_lib.h"
#include "towns_and_cities-central_american_towns_lib.h"
#include "towns_and_cities-central_east_african_towns_lib.h"
#include "towns_and_cities-city_nicknames_lib.h"
#include "towns_and_cities-citys_lib.h"
#include "towns_and_cities-dwarven_citys_lib.h"
#include "towns_and_cities-east_asian_towns_lib.h"
#include "towns_and_cities-east_european_towns_lib.h"
#include "towns_and_cities-egyptian_towns_lib.h"
#include "towns_and_cities-elven_citys_lib.h"
#include "towns_and_cities-fantasy_towns_lib.h"
#include "towns_and_cities-middle_eastern_towns_lib.h"
#include "towns_and_cities-north_african_towns_lib.h"
#include "towns_and_cities-north_american_towns_lib.h"
#include "towns_and_cities-north_european_towns_lib.h"
#include "towns_and_cities-northern_south_american_towns_lib.h"
#include "towns_and_cities-oceania_towns_lib.h"
#include "towns_and_cities-orcish_citys_lib.h"
#include "towns_and_cities-roman_towns_lib.h"
#include "towns_and_cities-russian_towns_lib.h"
#include "towns_and_cities-south_african_towns_lib.h"
#include "towns_and_cities-south_american_towns_lib.h"
#include "towns_and_cities-south_asian_towns_lib.h"
#include "towns_and_cities-south_european_towns_lib.h"
#include "towns_and_cities-southeast_african_towns_lib.h"
#include "towns_and_cities-southeast_asian_towns_lib.h"
#include "towns_and_cities-southeast_european_lib.h"
#include "towns_and_cities-steampunk_citys_lib.h"
#include "towns_and_cities-towns_lib.h"
#include "towns_and_cities-underwater_citys_lib.h"
#include "towns_and_cities-viking_towns_lib.h"
#include "towns_and_cities-west_african_towns_lib.h"
#include "towns_and_cities-west_european_towns_lib.h"
#include "towns_and_cities-wild_west_towns_lib.h"
#include "warhammer-beastmens_lib.h"
#include "warhammer-bretonnias_lib.h"
#include "warhammer-daemons_of_chaos_lib.h"
#include "warhammer-dark_elfs_lib.h"
#include "warhammer-dwarfs_lib.h"
#include "warhammer-empires_lib.h"
#include "warhammer-goblins_lib.h"
#include "warhammer-high_elfs_lib.h"
#include "warhammer-lizardmens_lib.h"
#include "warhammer-ogres_lib.h"
#include "warhammer-orcs_lib.h"
#include "warhammer-skavens_lib.h"
#include "warhammer-tomb_kings_lib.h"
#include "warhammer-vampire_counts_lib.h"
#include "warhammer-warriors_of_chaos_lib.h"
#include "warhammer-wood_elfs_lib.h"
#include "warhammer_40k-chaos_lib.h"
#include "warhammer_40k-dark_eldars_lib.h"
#include "warhammer_40k-eldars_lib.h"
#include "warhammer_40k-necrons_lib.h"
#include "warhammer_40k-orks_lib.h"
#include "warhammer_40k-sisters_of_battles_lib.h"
#include "warhammer_40k-space_marines_lib.h"
#include "warhammer_40k-taus_lib.h"
#include "weapons-battle_axes_lib.h"
#include "weapons-bomb_missiles_lib.h"
#include "weapons-bows_lib.h"
#include "weapons-claw_weapons_lib.h"
#include "weapons-daggers_lib.h"
#include "weapons-dual_wields_lib.h"
#include "weapons-fist_weapons_lib.h"
#include "weapons-flails_lib.h"
#include "weapons-magic_books_lib.h"
#include "weapons-magic_weapons_lib.h"
#include "weapons-pistols_lib.h"
#include "weapons-rifles_lib.h"
#include "weapons-sci_fi_guns_lib.h"
#include "weapons-scythes_lib.h"
#include "weapons-shotguns_lib.h"
#include "weapons-spears_lib.h"
#include "weapons-staffs_lib.h"
#include "weapons-swords_lib.h"
#include "weapons-throwing_weapons_lib.h"
#include "weapons-war_hammers_lib.h"
#include "weapons-whips_lib.h"
#include "wildstar-aurins_lib.h"
#include "wildstar-cassians_lib.h"
#include "wildstar-chuas_lib.h"
#include "wildstar-drakens_lib.h"
#include "wildstar-granoks_lib.h"
#include "wildstar-humans_lib.h"
#include "wildstar-mecharis_lib.h"
#include "wildstar-mordeshs_lib.h"
#include "world_of_warcraft-blood_elf_lib.h"
#include "world_of_warcraft-draenei_lib.h"
#include "world_of_warcraft-dwarf_lib.h"
#include "world_of_warcraft-forsaken_lib.h"
#include "world_of_warcraft-gnome_lib.h"
#include "world_of_warcraft-goblin_lib.h"
#include "world_of_warcraft-human_lib.h"
#include "world_of_warcraft-night_elf_lib.h"
#include "world_of_warcraft-orc_lib.h"
#include "world_of_warcraft-pandaren_lib.h"
#include "world_of_warcraft-tauren_lib.h"
#include "world_of_warcraft-troll_lib.h"
#include "world_of_warcraft-worgen_lib.h"
#include "world_of_warcraft_pets-bat_dragonhawks_lib.h"
#include "world_of_warcraft_pets-birds_lib.h"
#include "world_of_warcraft_pets-boars_bears_lib.h"
#include "world_of_warcraft_pets-cats_lib.h"
#include "world_of_warcraft_pets-crabs_lib.h"
#include "world_of_warcraft_pets-dino_rhinos_lib.h"
#include "world_of_warcraft_pets-dog_wolfs_lib.h"
#include "world_of_warcraft_pets-goat_porcupines_lib.h"
#include "world_of_warcraft_pets-gorilla_monkeys_lib.h"
#include "world_of_warcraft_pets-insects_lib.h"
#include "world_of_warcraft_pets-reptiles_lib.h"
#include "world_of_warcraft_pets-wow_pets_lib.h"

static std::string normalizeKey(const std::string& key) {
    std::string s = key;
    if (s.rfind("--", 0) == 0) {
        s = s.substr(2);
    }
    for (char& c : s) {
        if (c == '_') {
            c = '-';
        } else {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }
    return s;
}

GeneratorRegistry& GeneratorRegistry::instance() {
    static GeneratorRegistry reg;
    return reg;
}

GeneratorRegistry::GeneratorRegistry() {
    initBuiltins();
}

static bool isConsonant(char c) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

static std::vector<std::string> generateSpellingVariants(const std::string& key) {
    std::vector<std::string> variants;
    if (key.find("citys") != std::string::npos) {
        std::string v = key;
        std::size_t pos = 0;
        while ((pos = v.find("citys", pos)) != std::string::npos) {
            v.replace(pos, 5, "cities");
            pos += 6;
        }
        variants.push_back(v);
    }
    if (key.find("cities") != std::string::npos) {
        std::string v = key;
        std::size_t pos = 0;
        while ((pos = v.find("cities", pos)) != std::string::npos) {
            v.replace(pos, 6, "citys");
            pos += 5;
        }
        variants.push_back(v);
    }
    if (key.size() >= 3 && key.rfind("ys") == key.size() - 2 && isConsonant(key[key.size() - 3])) {
        variants.push_back(key.substr(0, key.size() - 2) + "ies");
    }
    if (key.size() >= 4 && key.rfind("ies") == key.size() - 3 && isConsonant(key[key.size() - 4])) {
        variants.push_back(key.substr(0, key.size() - 3) + "ys");
    }
    return variants;
}

void GeneratorRegistry::registerGenerator(GeneratorInfo info) {
    auto ptr = std::make_unique<GeneratorInfo>(std::move(info));
    const GeneratorInfo* raw = ptr.get();
    generators_.push_back(std::move(ptr));
    lookup_[normalizeKey(raw->flag)] = raw;
    lookup_[raw->flag] = raw;
    for (const auto& variant : generateSpellingVariants(normalizeKey(raw->flag))) {
        lookup_[variant] = raw;
    }
    for (const auto& alias : raw->aliases) {
        lookup_[normalizeKey(alias)] = raw;
        lookup_[alias] = raw;
        for (const auto& variant : generateSpellingVariants(normalizeKey(alias))) {
            lookup_[variant] = raw;
        }
    }
}

const GeneratorInfo* GeneratorRegistry::find(const std::string& flagName) const {
    auto it = lookup_.find(normalizeKey(flagName));
    if (it != lookup_.end()) {
        return it->second;
    }
    auto it2 = lookup_.find(flagName);
    if (it2 != lookup_.end()) {
        return it2->second;
    }
    for (const auto& variant : generateSpellingVariants(normalizeKey(flagName))) {
        auto itv = lookup_.find(variant);
        if (itv != lookup_.end()) {
            return itv->second;
        }
    }
    return nullptr;
}

const std::vector<std::unique_ptr<GeneratorInfo>>& GeneratorRegistry::getAll() const {
    return generators_;
}

void GeneratorRegistry::initBuiltins() {
    registerGenerator({
        "armour-belts",
        {},
        "Generate Armour Belts style names",
        [](std::mt19937& rng) { return generate_armour_belts_name(rng, 0); }
    });
    registerGenerator({
        "armour-boots",
        {},
        "Generate Armour Boots style names",
        [](std::mt19937& rng) { return generate_armour_boots_name(rng, 0); }
    });
    registerGenerator({
        "armour-chests",
        {},
        "Generate Armour Chests style names",
        [](std::mt19937& rng) { return generate_armour_chests_name(rng, 0); }
    });
    registerGenerator({
        "armour-cloaks",
        {},
        "Generate Armour Cloaks style names",
        [](std::mt19937& rng) { return generate_armour_cloaks_name(rng); }
    });
    registerGenerator({
        "armour-gauntlets",
        {},
        "Generate Armour Gauntlets style names",
        [](std::mt19937& rng) { return generate_armour_gauntlets_name(rng, 0); }
    });
    registerGenerator({
        "armour-helmets",
        {},
        "Generate Armour Helmets style names",
        [](std::mt19937& rng) { return generate_armour_helmets_name(rng, 0); }
    });
    registerGenerator({
        "armour-legs",
        {},
        "Generate Armour Legs style names",
        [](std::mt19937& rng) { return generate_armour_legs_name(rng, 0); }
    });
    registerGenerator({
        "armour-pauldrons",
        {},
        "Generate Armour Pauldrons style names",
        [](std::mt19937& rng) { return generate_armour_pauldrons_name(rng, 0); }
    });
    registerGenerator({
        "armour-shields",
        {},
        "Generate Armour Shields style names",
        [](std::mt19937& rng) { return generate_armour_shields_name(rng); }
    });
    registerGenerator({
        "armour-vambraces",
        {},
        "Generate Armour Vambraces style names",
        [](std::mt19937& rng) { return generate_armour_vambraces_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-aliens",
        {},
        "Generate Descriptions Aliens style names",
        [](std::mt19937& rng) { return generate_descriptions_aliens_name(rng); }
    });
    registerGenerator({
        "descriptions-animals",
        {},
        "Generate Descriptions Animals style names",
        [](std::mt19937& rng) { return generate_descriptions_animals_name(rng); }
    });
    registerGenerator({
        "descriptions-armys",
        {},
        "Generate Descriptions Armys style names",
        [](std::mt19937& rng) { return generate_descriptions_armys_name(rng); }
    });
    registerGenerator({
        "descriptions-backstorys",
        {},
        "Generate Descriptions Backstorys style names",
        [](std::mt19937& rng) { return generate_descriptions_backstorys_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-battlefields",
        {},
        "Generate Descriptions Battlefields style names",
        [](std::mt19937& rng) { return generate_descriptions_battlefields_name(rng); }
    });
    registerGenerator({
        "descriptions-bows",
        {},
        "Generate Descriptions Bows style names",
        [](std::mt19937& rng) { return generate_descriptions_bows_name(rng); }
    });
    registerGenerator({
        "descriptions-castles",
        {},
        "Generate Descriptions Castles style names",
        [](std::mt19937& rng) { return generate_descriptions_castles_name(rng); }
    });
    registerGenerator({
        "descriptions-characters",
        {},
        "Generate Descriptions Characters style names",
        [](std::mt19937& rng) { return generate_descriptions_characters_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-citys",
        {},
        "Generate Descriptions Citys style names",
        [](std::mt19937& rng) { return generate_descriptions_citys_name(rng); }
    });
    registerGenerator({
        "descriptions-coat_of_arms",
        {},
        "Generate Descriptions Coat Of Arms style names",
        [](std::mt19937& rng) { return generate_descriptions_coat_of_arms_name(rng); }
    });
    registerGenerator({
        "descriptions-constellations",
        {},
        "Generate Descriptions Constellations style names",
        [](std::mt19937& rng) { return generate_descriptions_constellations_name(rng); }
    });
    registerGenerator({
        "descriptions-countrys",
        {},
        "Generate Descriptions Countrys style names",
        [](std::mt19937& rng) { return generate_descriptions_countrys_name(rng); }
    });
    registerGenerator({
        "descriptions-diseases",
        {},
        "Generate Descriptions Diseases style names",
        [](std::mt19937& rng) { return generate_descriptions_diseases_name(rng); }
    });
    registerGenerator({
        "descriptions-dragons",
        {},
        "Generate Descriptions Dragons style names",
        [](std::mt19937& rng) { return generate_descriptions_dragons_name(rng); }
    });
    registerGenerator({
        "descriptions-dungeons",
        {},
        "Generate Descriptions Dungeons style names",
        [](std::mt19937& rng) { return generate_descriptions_dungeons_name(rng); }
    });
    registerGenerator({
        "descriptions-dyings",
        {},
        "Generate Descriptions Dyings style names",
        [](std::mt19937& rng) { return generate_descriptions_dyings_name(rng); }
    });
    registerGenerator({
        "descriptions-fancy_clothings",
        {},
        "Generate Descriptions Fancy Clothings style names",
        [](std::mt19937& rng) { return generate_descriptions_fancy_clothings_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-flags",
        {},
        "Generate Descriptions Flags style names",
        [](std::mt19937& rng) { return generate_descriptions_flags_name(rng); }
    });
    registerGenerator({
        "descriptions-gems",
        {},
        "Generate Descriptions Gems style names",
        [](std::mt19937& rng) { return generate_descriptions_gems_name(rng); }
    });
    registerGenerator({
        "descriptions-ghost_towns",
        {},
        "Generate Descriptions Ghost Towns style names",
        [](std::mt19937& rng) { return generate_descriptions_ghost_towns_name(rng); }
    });
    registerGenerator({
        "descriptions-gods",
        {},
        "Generate Descriptions Gods style names",
        [](std::mt19937& rng) { return generate_descriptions_gods_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-hand_gestures",
        {},
        "Generate Descriptions Hand Gestures style names",
        [](std::mt19937& rng) { return generate_descriptions_hand_gestures_name(rng); }
    });
    registerGenerator({
        "descriptions-holidays",
        {},
        "Generate Descriptions Holidays style names",
        [](std::mt19937& rng) { return generate_descriptions_holidays_name(rng); }
    });
    registerGenerator({
        "descriptions-houses",
        {},
        "Generate Descriptions Houses style names",
        [](std::mt19937& rng) { return generate_descriptions_houses_name(rng); }
    });
    registerGenerator({
        "descriptions-humanoids",
        {},
        "Generate Descriptions Humanoids style names",
        [](std::mt19937& rng) { return generate_descriptions_humanoids_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-laws",
        {},
        "Generate Descriptions Laws style names",
        [](std::mt19937& rng) { return generate_descriptions_laws_name(rng); }
    });
    registerGenerator({
        "descriptions-leather_armors",
        {},
        "Generate Descriptions Leather Armors style names",
        [](std::mt19937& rng) { return generate_descriptions_leather_armors_name(rng); }
    });
    registerGenerator({
        "descriptions-martial_arts",
        {},
        "Generate Descriptions Martial Arts style names",
        [](std::mt19937& rng) { return generate_descriptions_martial_arts_name(rng); }
    });
    registerGenerator({
        "descriptions-medieval_clothings",
        {},
        "Generate Descriptions Medieval Clothings style names",
        [](std::mt19937& rng) { return generate_descriptions_medieval_clothings_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-monuments",
        {},
        "Generate Descriptions Monuments style names",
        [](std::mt19937& rng) { return generate_descriptions_monuments_name(rng); }
    });
    registerGenerator({
        "descriptions-pains",
        {},
        "Generate Descriptions Pains style names",
        [](std::mt19937& rng) { return generate_descriptions_pains_name(rng); }
    });
    registerGenerator({
        "descriptions-personalitys",
        {},
        "Generate Descriptions Personalitys style names",
        [](std::mt19937& rng) { return generate_descriptions_personalitys_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-pistols",
        {},
        "Generate Descriptions Pistols style names",
        [](std::mt19937& rng) { return generate_descriptions_pistols_name(rng); }
    });
    registerGenerator({
        "descriptions-planets",
        {},
        "Generate Descriptions Planets style names",
        [](std::mt19937& rng) { return generate_descriptions_planets_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-plants",
        {},
        "Generate Descriptions Plants style names",
        [](std::mt19937& rng) { return generate_descriptions_plants_name(rng); }
    });
    registerGenerator({
        "descriptions-plate_armors",
        {},
        "Generate Descriptions Plate Armors style names",
        [](std::mt19937& rng) { return generate_descriptions_plate_armors_name(rng); }
    });
    registerGenerator({
        "descriptions-plots",
        {},
        "Generate Descriptions Plots style names",
        [](std::mt19937& rng) { return generate_descriptions_plots_name(rng); }
    });
    registerGenerator({
        "descriptions-pokemons",
        {},
        "Generate Descriptions Pokemons style names",
        [](std::mt19937& rng) { return generate_descriptions_pokemons_name(rng); }
    });
    registerGenerator({
        "descriptions-potions",
        {},
        "Generate Descriptions Potions style names",
        [](std::mt19937& rng) { return generate_descriptions_potions_name(rng); }
    });
    registerGenerator({
        "descriptions-prophecys",
        {},
        "Generate fantasy prophecy style descriptions",
        [](std::mt19937& rng) { return generate_descriptions_prophecys_name(rng); }
    });
    registerGenerator({
        "descriptions-quests",
        {},
        "Generate Descriptions Quests style names",
        [](std::mt19937& rng) { return generate_descriptions_quests_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-rag_clothings",
        {},
        "Generate Descriptions Rag Clothings style names",
        [](std::mt19937& rng) { return generate_descriptions_rag_clothings_name(rng, 0); }
    });
    registerGenerator({
        "descriptions-rifles",
        {},
        "Generate Descriptions Rifles style names",
        [](std::mt19937& rng) { return generate_descriptions_rifles_name(rng); }
    });
    registerGenerator({
        "descriptions-school_uniforms",
        {},
        "Generate Descriptions School Uniforms style names",
        [](std::mt19937& rng) { return generate_descriptions_school_uniforms_name(rng); }
    });
    registerGenerator({
        "descriptions-shields",
        {},
        "Generate Descriptions Shields style names",
        [](std::mt19937& rng) { return generate_descriptions_shields_name(rng); }
    });
    registerGenerator({
        "descriptions-shotguns",
        {},
        "Generate Descriptions Shotguns style names",
        [](std::mt19937& rng) { return generate_descriptions_shotguns_name(rng); }
    });
    registerGenerator({
        "descriptions-societys",
        {},
        "Generate Descriptions Societys style names",
        [](std::mt19937& rng) { return generate_descriptions_societys_name(rng); }
    });
    registerGenerator({
        "descriptions-spells",
        {},
        "Generate Descriptions Spells style names",
        [](std::mt19937& rng) { return generate_descriptions_spells_name(rng); }
    });
    registerGenerator({
        "descriptions-staffs",
        {},
        "Generate Descriptions Staffs style names",
        [](std::mt19937& rng) { return generate_descriptions_staffs_name(rng); }
    });
    registerGenerator({
        "descriptions-taverns",
        {},
        "Generate Descriptions Taverns style names",
        [](std::mt19937& rng) { return generate_descriptions_taverns_name(rng); }
    });
    registerGenerator({
        "descriptions-towns",
        {},
        "Generate Descriptions Towns style names",
        [](std::mt19937& rng) { return generate_descriptions_towns_name(rng); }
    });
    registerGenerator({
        "descriptions-traditions",
        {},
        "Generate Descriptions Traditions style names",
        [](std::mt19937& rng) { return generate_descriptions_traditions_name(rng); }
    });
    registerGenerator({
        "descriptions-wands",
        {},
        "Generate Descriptions Wands style names",
        [](std::mt19937& rng) { return generate_descriptions_wands_name(rng); }
    });
    registerGenerator({
        "descriptions-weapons",
        {},
        "Generate Descriptions Weapons style names",
        [](std::mt19937& rng) { return generate_descriptions_weapons_name(rng); }
    });
    registerGenerator({
        "destiny-awokens",
        {},
        "Generate Destiny Awokens style names",
        [](std::mt19937& rng) { return generate_destiny_awoken_name(rng, 0); }
    });
    registerGenerator({
        "destiny-cabals",
        {},
        "Generate Destiny Cabals style names",
        [](std::mt19937& rng) { return generate_destiny_cabals_name(rng); }
    });
    registerGenerator({
        "destiny-exos",
        {},
        "Generate Destiny Exos style names",
        [](std::mt19937& rng) { return generate_destiny_exos_name(rng); }
    });
    registerGenerator({
        "destiny-fallens",
        {},
        "Generate Destiny Fallens style names",
        [](std::mt19937& rng) { return generate_destiny_fallens_name(rng); }
    });
    registerGenerator({
        "destiny-hives",
        {},
        "Generate Destiny Hives style names",
        [](std::mt19937& rng) { return generate_destiny_hives_name(rng, 0); }
    });
    registerGenerator({
        "destiny-humans",
        {},
        "Generate Destiny Humans style names",
        [](std::mt19937& rng) { return generate_destiny_humans_name(rng, 0); }
    });
    registerGenerator({
        "destiny-vexs",
        {},
        "Generate Destiny Vexs style names",
        [](std::mt19937& rng) { return generate_destiny_vexs_name(rng); }
    });
    registerGenerator({
        "diablo-angels",
        {},
        "Generate Diablo Angels style names",
        [](std::mt19937& rng) { return generate_diablo_angels_name(rng, 0); }
    });
    registerGenerator({
        "diablo-demons",
        {},
        "Generate Diablo Demons style names",
        [](std::mt19937& rng) { return generate_diablo_demons_name(rng, 0); }
    });
    registerGenerator({
        "diablo-khazras",
        {},
        "Generate Diablo Khazras style names",
        [](std::mt19937& rng) { return generate_diablo_khazras_name(rng, 0); }
    });
    registerGenerator({
        "diablo-nephalems",
        {},
        "Generate Diablo Nephalems style names",
        [](std::mt19937& rng) { return generate_diablo_nephalems_name(rng, 0); }
    });
    registerGenerator({
        "doctor_who-daleks",
        {},
        "Generate Doctor Who Daleks style names",
        [](std::mt19937& rng) { return generate_doctor_who_daleks_name(rng); }
    });
    registerGenerator({
        "doctor_who-gallifreyans",
        {},
        "Generate Doctor Who Gallifreyans style names",
        [](std::mt19937& rng) { return generate_doctor_who_gallifreyans_name(rng, 0); }
    });
    registerGenerator({
        "doctor_who-ice_warriors",
        {},
        "Generate Doctor Who Ice Warriors style names",
        [](std::mt19937& rng) { return generate_doctor_who_ice_warriors_name(rng); }
    });
    registerGenerator({
        "doctor_who-raxacoricofallapatorians",
        {},
        "Generate Doctor Who Raxacoricofallapatorians style names",
        [](std::mt19937& rng) { return generate_doctor_who_raxacoricofallapatorians_name(rng); }
    });
    registerGenerator({
        "doctor_who-silurians",
        {},
        "Generate Doctor Who Silurians style names",
        [](std::mt19937& rng) { return generate_doctor_who_silurians_name(rng, 0); }
    });
    registerGenerator({
        "doctor_who-sontarans",
        {},
        "Generate Doctor Who Sontarans style names",
        [](std::mt19937& rng) { return generate_doctor_who_sontarans_name(rng); }
    });
    registerGenerator({
        "doctor_who-zygons",
        {},
        "Generate Doctor Who Zygons style names",
        [](std::mt19937& rng) { return generate_doctor_who_zygons_name(rng); }
    });
    registerGenerator({
        "dragon_age-dwarfs",
        {},
        "Generate Dragon Age Dwarfs style names",
        [](std::mt19937& rng) { return generate_dragon_age_dwarfs_name(rng); }
    });
    registerGenerator({
        "dragon_age-elfs",
        {},
        "Generate Dragon Age Elfs style names",
        [](std::mt19937& rng) { return generate_dragon_age_elfs_name(rng, 0); }
    });
    registerGenerator({
        "dragon_age-humans",
        {},
        "Generate Dragon Age Humans style names",
        [](std::mt19937& rng) { return generate_dragon_age_humans_name(rng, 0); }
    });
    registerGenerator({
        "dragon_age-qunaris",
        {},
        "Generate Dragon Age Qunaris style names",
        [](std::mt19937& rng) { return generate_dragon_age_qunaris_name(rng, 0); }
    });
    registerGenerator({
        "dragon_ball-frieza_clans",
        {},
        "Generate Dragon Ball Frieza Clans style names",
        [](std::mt19937& rng) { return generate_dragon_ball_frieza_clans_name(rng); }
    });
    registerGenerator({
        "dragon_ball-hakaishins",
        {},
        "Generate Dragon Ball Hakaishins style names",
        [](std::mt19937& rng) { return generate_dragon_ball_hakaishins_name(rng); }
    });
    registerGenerator({
        "dragon_ball-humans",
        {},
        "Generate Dragon Ball Humans style names",
        [](std::mt19937& rng) { return generate_dragon_ball_humans_name(rng, 0); }
    });
    registerGenerator({
        "dragon_ball-others",
        {},
        "Generate Dragon Ball Others style names",
        [](std::mt19937& rng) { return generate_dragon_ball_others_name(rng); }
    });
    registerGenerator({
        "dragon_ball-saiyans",
        {},
        "Generate Dragon Ball Saiyans style names",
        [](std::mt19937& rng) { return generate_dragon_ball_saiyans_name(rng); }
    });
    registerGenerator({
        "dragon_ball-skians",
        {},
        "Generate Dragon Ball Skians style names",
        [](std::mt19937& rng) { return generate_dragon_ball_skians_name(rng); }
    });
    registerGenerator({
        "dragon_ball-tuffles",
        {},
        "Generate Dragon Ball Tuffles style names",
        [](std::mt19937& rng) { return generate_dragon_ball_tuffles_name(rng); }
    });
    registerGenerator({
        "dungeon_and_dragons-devas",
        {},
        "Generate Dungeon And Dragons Devas style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_devas_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-dragonborns",
        {},
        "Generate Dungeon And Dragons Dragonborns style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_dragonborns_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-drows",
        {},
        "Generate Dungeon And Dragons Drows style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_drows_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-dwarfs",
        {},
        "Generate Dungeon And Dragons Dwarfs style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-eladrins",
        {},
        "Generate Dungeon And Dragons Eladrins style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_eladrins_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-elfs",
        {},
        "Generate Dungeon And Dragons Elfs style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_elfs_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-githzerais",
        {},
        "Generate Dungeon And Dragons Githzerais style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_githzerais_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-gnomes",
        {},
        "Generate Dungeon And Dragons Gnomes style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_gnomes_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-goliaths",
        {},
        "Generate Dungeon And Dragons Goliaths style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_goliaths_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-half_elfs",
        {},
        "Generate Dungeon And Dragons Half Elfs style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_half_elfs_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-half_orcs",
        {},
        "Generate Dungeon And Dragons Half Orcs style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_half_orcs_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-halflings",
        {},
        "Generate Dungeon And Dragons Halflings style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_halflings_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-humans",
        {},
        "Generate Dungeon And Dragons Humans style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_humans_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-minotaurs",
        {},
        "Generate Dungeon And Dragons Minotaurs style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_minotaurs_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-shardminds",
        {},
        "Generate Dungeon And Dragons Shardminds style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_shardminds_name(rng); }
    });
    registerGenerator({
        "dungeon_and_dragons-shifters",
        {},
        "Generate Dungeon And Dragons Shifters style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_shifters_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-tieflings",
        {},
        "Generate Dungeon And Dragons Tieflings style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_tieflings_name(rng, 0); }
    });
    registerGenerator({
        "dungeon_and_dragons-wildens",
        {},
        "Generate Dungeon And Dragons Wildens style names",
        [](std::mt19937& rng) { return generate_dungeon_and_dragons_wildens_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-altmers",
        {},
        "Generate Elder Scrolls Altmers style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_altmers_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-argonians",
        {},
        "Generate Elder Scrolls Argonians style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_argonians_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-bosmers",
        {},
        "Generate Elder Scrolls Bosmers style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_bosmers_name(rng); }
    });
    registerGenerator({
        "elder_scrolls-bretons",
        {},
        "Generate Elder Scrolls Bretons style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_bretons_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-daedrics",
        {},
        "Generate Elder Scrolls Daedrics style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_daedrics_name(rng); }
    });
    registerGenerator({
        "elder_scrolls-dragons",
        {},
        "Generate Elder Scrolls Dragons style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_dragons_name(rng); }
    });
    registerGenerator({
        "elder_scrolls-dunmers",
        {},
        "Generate Elder Scrolls Dunmers style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_dunmers_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-dwemers",
        {},
        "Generate Elder Scrolls Dwemers style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_dwemers_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-falmers",
        {},
        "Generate Elder Scrolls Falmers style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_falmers_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-forsworns",
        {},
        "Generate Elder Scrolls Forsworns style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_forsworns_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-imperials",
        {},
        "Generate Elder Scrolls Imperials style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_imperials_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-khajiits",
        {},
        "Generate Elder Scrolls Khajiits style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_khajiits_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-nords",
        {},
        "Generate Elder Scrolls Nords style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_nords_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-orc",
        {},
        "Generate Elder Scrolls Orc style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_orc_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-redguards",
        {},
        "Generate Elder Scrolls Redguards style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_redguards_name(rng, 0); }
    });
    registerGenerator({
        "elder_scrolls-spriggans",
        {},
        "Generate Elder Scrolls Spriggans style names",
        [](std::mt19937& rng) { return generate_elder_scrolls_spriggans_name(rng); }
    });
    registerGenerator({
        "eve_online-amarrs",
        {},
        "Generate Eve Online Amarrs style names",
        [](std::mt19937& rng) { return generate_eve_online_amarrs_name(rng, 0); }
    });
    registerGenerator({
        "eve_online-caldaris",
        {},
        "Generate Eve Online Caldaris style names",
        [](std::mt19937& rng) { return generate_eve_online_caldaris_name(rng, 0); }
    });
    registerGenerator({
        "eve_online-gallentes",
        {},
        "Generate Eve Online Gallentes style names",
        [](std::mt19937& rng) { return generate_eve_online_gallentes_name(rng, 0); }
    });
    registerGenerator({
        "eve_online-minmatars",
        {},
        "Generate Eve Online Minmatars style names",
        [](std::mt19937& rng) { return generate_eve_online_minmatars_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-aliens",
        {},
        "Generate Fantasy Aliens style names",
        [](std::mt19937& rng) { return generate_fantasy_aliens_name(rng); }
    });
    registerGenerator({
        "fantasy-amazons",
        {},
        "Generate Fantasy Amazons style names",
        [](std::mt19937& rng) { return generate_fantasy_amazons_name(rng); }
    });
    registerGenerator({
        "fantasy-angels",
        {},
        "Generate Fantasy Angels style names",
        [](std::mt19937& rng) { return generate_fantasy_angels_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-animal_species",
        {},
        "Generate Fantasy Animal Species style names",
        [](std::mt19937& rng) { return generate_fantasy_animal_species_name(rng); }
    });
    registerGenerator({
        "fantasy-animatronics",
        {},
        "Generate Fantasy Animatronics style names",
        [](std::mt19937& rng) { return generate_fantasy_animatronics_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-apocalypse_mutants",
        {},
        "Generate Fantasy Apocalypse Mutants style names",
        [](std::mt19937& rng) { return generate_fantasy_apocalypse_mutants_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-bandits",
        {},
        "Generate Fantasy Bandits style names",
        [](std::mt19937& rng) { return generate_fantasy_bandits_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-barbarians",
        {},
        "Generate Fantasy Barbarians style names",
        [](std::mt19937& rng) { return generate_fantasy_barbarians_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-bounty_hunters",
        {},
        "Generate Fantasy Bounty Hunters style names",
        [](std::mt19937& rng) { return generate_fantasy_bounty_hunters_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-cat_people_nekojins",
        {},
        "Generate Fantasy Cat People Nekojins style names",
        [](std::mt19937& rng) { return generate_fantasy_cat_people_nekojins_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-cavemens",
        {},
        "Generate Fantasy Cavemens style names",
        [](std::mt19937& rng) { return generate_fantasy_cavemens_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-centaurs",
        {},
        "Generate Fantasy Centaurs style names",
        [](std::mt19937& rng) { return generate_fantasy_centaurs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-christmas_elfs",
        {},
        "Generate Fantasy Christmas Elfs style names",
        [](std::mt19937& rng) { return generate_fantasy_christmas_elfs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-codes",
        {},
        "Generate Fantasy Codes style names",
        [](std::mt19937& rng) { return generate_fantasy_codes_name(rng); }
    });
    registerGenerator({
        "fantasy-cowboys",
        {},
        "Generate Fantasy Cowboys style names",
        [](std::mt19937& rng) { return generate_fantasy_cowboys_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-creatures",
        {},
        "Generate Fantasy Creatures style names",
        [](std::mt19937& rng) { return generate_fantasy_creatures_name(rng); }
    });
    registerGenerator({
        "fantasy-deaths",
        {},
        "Generate Fantasy Deaths style names",
        [](std::mt19937& rng) { return generate_fantasy_deaths_name(rng); }
    });
    registerGenerator({
        "fantasy-demons",
        {},
        "Generate Fantasy Demons style names",
        [](std::mt19937& rng) { return generate_fantasy_demons_name(rng); }
    });
    registerGenerator({
        "fantasy-detectives",
        {},
        "Generate Fantasy Detectives style names",
        [](std::mt19937& rng) { return generate_fantasy_detectives_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-dragons",
        {},
        "Generate Fantasy Dragons style names",
        [](std::mt19937& rng) { return generate_fantasy_dragons_name(rng); }
    });
    registerGenerator({
        "fantasy-dryads",
        {},
        "Generate Fantasy Dryads style names",
        [](std::mt19937& rng) { return generate_fantasy_dryads_name(rng); }
    });
    registerGenerator({
        "fantasy-dwarfs",
        {},
        "Generate Fantasy Dwarfs style names",
        [](std::mt19937& rng) { return generate_fantasy_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-elementals",
        {},
        "Generate Fantasy Elementals style names",
        [](std::mt19937& rng) { return generate_fantasy_elementals_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-elfs",
        {},
        "Generate Fantasy Elfs style names",
        [](std::mt19937& rng) { return generate_fantasy_elfs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-ents",
        {},
        "Generate Fantasy Ents style names",
        [](std::mt19937& rng) { return generate_fantasy_ents_name(rng); }
    });
    registerGenerator({
        "fantasy-evils",
        {},
        "Generate Fantasy Evils style names",
        [](std::mt19937& rng) { return generate_fantasy_evils_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-fairys",
        {},
        "Generate Fantasy Fairys style names",
        [](std::mt19937& rng) { return generate_fantasy_fairys_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-fantasy_animals",
        {},
        "Generate Fantasy Animals style names",
        [](std::mt19937& rng) { return generate_fantasy_fantasy_animals_name(rng); }
    });
    registerGenerator({
        "fantasy-fantasy_races",
        {},
        "Generate Fantasy Races style names",
        [](std::mt19937& rng) { return generate_fantasy_fantasy_races_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-fantasy_surnames",
        {},
        "Generate Fantasy Surnames style names",
        [](std::mt19937& rng) { return generate_fantasy_fantasy_surnames_name(rng); }
    });
    registerGenerator({
        "fantasy-fursonas",
        {},
        "Generate Fantasy Fursonas style names",
        [](std::mt19937& rng) { return generate_fantasy_fursonas_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-futuristics",
        {},
        "Generate Fantasy Futuristics style names",
        [](std::mt19937& rng) { return generate_fantasy_futuristics_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-ghost_classifications",
        {},
        "Generate Fantasy Ghost Classifications style names",
        [](std::mt19937& rng) { return generate_fantasy_ghost_classifications_name(rng); }
    });
    registerGenerator({
        "fantasy-ghosts",
        {},
        "Generate Fantasy Ghosts style names",
        [](std::mt19937& rng) { return generate_fantasy_ghosts_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-giants",
        {},
        "Generate Fantasy Giants style names",
        [](std::mt19937& rng) { return generate_fantasy_giants_name(rng); }
    });
    registerGenerator({
        "fantasy-gnolls",
        {},
        "Generate Fantasy Gnolls style names",
        [](std::mt19937& rng) { return generate_fantasy_gnolls_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-gnomes",
        {},
        "Generate Fantasy Gnomes style names",
        [](std::mt19937& rng) { return generate_fantasy_gnomes_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-goblins",
        {},
        "Generate Fantasy Goblins style names",
        [](std::mt19937& rng) { return generate_fantasy_goblins_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-gods",
        {},
        "Generate Fantasy Gods style names",
        [](std::mt19937& rng) { return generate_fantasy_gods_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-gorgons",
        {},
        "Generate Fantasy Gorgons style names",
        [](std::mt19937& rng) { return generate_fantasy_gorgons_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-griffins",
        {},
        "Generate Fantasy Griffins style names",
        [](std::mt19937& rng) { return generate_fantasy_griffins_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-half_elfs",
        {},
        "Generate Fantasy Half Elfs style names",
        [](std::mt19937& rng) { return generate_fantasy_half_elfs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-harpys",
        {},
        "Generate Fantasy Harpys style names",
        [](std::mt19937& rng) { return generate_fantasy_harpys_name(rng); }
    });
    registerGenerator({
        "fantasy-heros",
        {},
        "Generate Fantasy Heros style names",
        [](std::mt19937& rng) { return generate_fantasy_heros_name(rng); }
    });
    registerGenerator({
        "fantasy-hobbits",
        {},
        "Generate Fantasy Hobbits style names",
        [](std::mt19937& rng) { return generate_fantasy_hobbits_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-horses",
        {},
        "Generate Fantasy Horses style names",
        [](std::mt19937& rng) { return generate_fantasy_horses_name(rng); }
    });
    registerGenerator({
        "fantasy-imps",
        {},
        "Generate Fantasy Imps style names",
        [](std::mt19937& rng) { return generate_fantasy_imps_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-kaijus",
        {},
        "Generate Fantasy Kaijus style names",
        [](std::mt19937& rng) { return generate_fantasy_kaijus_name(rng); }
    });
    registerGenerator({
        "fantasy-killers",
        {},
        "Generate Fantasy Killers style names",
        [](std::mt19937& rng) { return generate_fantasy_killers_name(rng); }
    });
    registerGenerator({
        "fantasy-knights",
        {},
        "Generate Fantasy Knights style names",
        [](std::mt19937& rng) { return generate_fantasy_knights_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-kobolds",
        {},
        "Generate Fantasy Kobolds style names",
        [](std::mt19937& rng) { return generate_fantasy_kobolds_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-lamias",
        {},
        "Generate Fantasy Lamias style names",
        [](std::mt19937& rng) { return generate_fantasy_lamias_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-lichs",
        {},
        "Generate Fantasy Lichs style names",
        [](std::mt19937& rng) { return generate_fantasy_lichs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-mechas",
        {},
        "Generate Fantasy Mechas style names",
        [](std::mt19937& rng) { return generate_fantasy_mechas_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-medievals",
        {},
        "Generate Fantasy Medievals style names",
        [](std::mt19937& rng) { return generate_fantasy_medievals_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-mermaids",
        {},
        "Generate Fantasy Mermaids style names",
        [](std::mt19937& rng) { return generate_fantasy_mermaids_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-minotaurs",
        {},
        "Generate Fantasy Minotaurs style names",
        [](std::mt19937& rng) { return generate_fantasy_minotaurs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-mobsters",
        {},
        "Generate Fantasy Mobsters style names",
        [](std::mt19937& rng) { return generate_fantasy_mobsters_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-monsters",
        {},
        "Generate Fantasy Monsters style names",
        [](std::mt19937& rng) { return generate_fantasy_monsters_name(rng); }
    });
    registerGenerator({
        "fantasy-mutant_species",
        {},
        "Generate Fantasy Mutant Species style names",
        [](std::mt19937& rng) { return generate_fantasy_mutant_species_name(rng); }
    });
    registerGenerator({
        "fantasy-nagas",
        {},
        "Generate Fantasy Nagas style names",
        [](std::mt19937& rng) { return generate_fantasy_nagas_name(rng); }
    });
    registerGenerator({
        "fantasy-necromancers",
        {},
        "Generate Fantasy Necromancers style names",
        [](std::mt19937& rng) { return generate_fantasy_necromancers_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-nephilims",
        {},
        "Generate Fantasy Nephilims style names",
        [](std::mt19937& rng) { return generate_fantasy_nephilims_name(rng); }
    });
    registerGenerator({
        "fantasy-ninjas",
        {},
        "Generate Fantasy Ninjas style names",
        [](std::mt19937& rng) { return generate_fantasy_ninjas_name(rng); }
    });
    registerGenerator({
        "fantasy-nymphs",
        {},
        "Generate Fantasy Nymphs style names",
        [](std::mt19937& rng) { return generate_fantasy_nymphs_name(rng); }
    });
    registerGenerator({
        "fantasy-ogres",
        {},
        "Generate Fantasy Ogres style names",
        [](std::mt19937& rng) { return generate_fantasy_ogres_name(rng); }
    });
    registerGenerator({
        "fantasy-orcs",
        {},
        "Generate Fantasy Orcs style names",
        [](std::mt19937& rng) { return generate_fantasy_orcs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-pegasus",
        {},
        "Generate Fantasy Pegasus style names",
        [](std::mt19937& rng) { return generate_fantasy_pegasus_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-phoenixs",
        {},
        "Generate Fantasy Phoenixs style names",
        [](std::mt19937& rng) { return generate_fantasy_phoenixs_name(rng); }
    });
    registerGenerator({
        "fantasy-pirates",
        {},
        "Generate Fantasy Pirates style names",
        [](std::mt19937& rng) { return generate_fantasy_pirates_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-robots",
        {},
        "Generate Fantasy Robots style names",
        [](std::mt19937& rng) { return generate_fantasy_robots_name(rng); }
    });
    registerGenerator({
        "fantasy-satyr_fauns",
        {},
        "Generate Fantasy Satyr Fauns style names",
        [](std::mt19937& rng) { return generate_fantasy_satyr_fauns_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-sea_creatures",
        {},
        "Generate Fantasy Sea Creatures style names",
        [](std::mt19937& rng) { return generate_fantasy_sea_creatures_name(rng); }
    });
    registerGenerator({
        "fantasy-servants",
        {},
        "Generate Fantasy Servants style names",
        [](std::mt19937& rng) { return generate_fantasy_servants_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-shapeshifters",
        {},
        "Generate Fantasy Shapeshifters style names",
        [](std::mt19937& rng) { return generate_fantasy_shapeshifters_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-sirens",
        {},
        "Generate Fantasy Sirens style names",
        [](std::mt19937& rng) { return generate_fantasy_sirens_name(rng); }
    });
    registerGenerator({
        "fantasy-slaves",
        {},
        "Generate Fantasy Slaves style names",
        [](std::mt19937& rng) { return generate_fantasy_slaves_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-species",
        {},
        "Generate Fantasy Species style names",
        [](std::mt19937& rng) { return generate_fantasy_species_name(rng); }
    });
    registerGenerator({
        "fantasy-steampunks",
        {},
        "Generate Fantasy Steampunks style names",
        [](std::mt19937& rng) { return generate_fantasy_steampunks_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-succubus",
        {},
        "Generate Fantasy Succubus style names",
        [](std::mt19937& rng) { return generate_fantasy_succubus_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-superhero_teams",
        {},
        "Generate Fantasy Superhero Teams style names",
        [](std::mt19937& rng) { return generate_fantasy_superhero_teams_name(rng); }
    });
    registerGenerator({
        "fantasy-sylphs",
        {},
        "Generate Fantasy Sylphs style names",
        [](std::mt19937& rng) { return generate_fantasy_sylphs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-taurens",
        {},
        "Generate Fantasy Taurens style names",
        [](std::mt19937& rng) { return generate_fantasy_taurens_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-trolls",
        {},
        "Generate Fantasy Trolls style names",
        [](std::mt19937& rng) { return generate_fantasy_trolls_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-twins",
        {},
        "Generate Fantasy Twins style names",
        [](std::mt19937& rng) { return generate_fantasy_twins_name(rng); }
    });
    registerGenerator({
        "fantasy-unicorns",
        {},
        "Generate Fantasy Unicorns style names",
        [](std::mt19937& rng) { return generate_fantasy_unicorns_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-valkyries",
        {},
        "Generate Fantasy Valkyries style names",
        [](std::mt19937& rng) { return generate_fantasy_valkyries_name(rng); }
    });
    registerGenerator({
        "fantasy-vampire_clans",
        {},
        "Generate Fantasy Vampire Clans style names",
        [](std::mt19937& rng) { return generate_fantasy_vampire_clans_name(rng); }
    });
    registerGenerator({
        "fantasy-vampires",
        {},
        "Generate Fantasy Vampires style names",
        [](std::mt19937& rng) { return generate_fantasy_vampires_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-villains",
        {},
        "Generate Fantasy Villains style names",
        [](std::mt19937& rng) { return generate_fantasy_villains_name(rng); }
    });
    registerGenerator({
        "fantasy-warrior_nicknames",
        {},
        "Generate Fantasy Warrior Nicknames style names",
        [](std::mt19937& rng) { return generate_fantasy_warrior_nicknames_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-werewolf_packs",
        {},
        "Generate Fantasy Werewolf Packs style names",
        [](std::mt19937& rng) { return generate_fantasy_werewolf_packs_name(rng); }
    });
    registerGenerator({
        "fantasy-werewolfs",
        {},
        "Generate Fantasy Werewolfs style names",
        [](std::mt19937& rng) { return generate_fantasy_werewolfs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-witchs",
        {},
        "Generate Fantasy Witchs style names",
        [](std::mt19937& rng) { return generate_fantasy_witchs_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-wizards",
        {},
        "Generate Fantasy Wizards style names",
        [](std::mt19937& rng) { return generate_fantasy_wizards_name(rng, 0); }
    });
    registerGenerator({
        "fantasy-zombie_types",
        {},
        "Generate Fantasy Zombie Types style names",
        [](std::mt19937& rng) { return generate_fantasy_zombie_types_name(rng); }
    });
    registerGenerator({
        "final_fantasy-au_ras",
        {},
        "Generate Final Fantasy Au Ras style names",
        [](std::mt19937& rng) { return generate_final_fantasy_au_ras_name(rng, 0); }
    });
    registerGenerator({
        "final_fantasy-elezens",
        {},
        "Generate Final Fantasy Elezens style names",
        [](std::mt19937& rng) { return generate_final_fantasy_elezens_name(rng, 0); }
    });
    registerGenerator({
        "final_fantasy-hyurs",
        {},
        "Generate Final Fantasy Hyurs style names",
        [](std::mt19937& rng) { return generate_final_fantasy_hyurs_name(rng, 0); }
    });
    registerGenerator({
        "final_fantasy-lalafells",
        {},
        "Generate Final Fantasy Lalafells style names",
        [](std::mt19937& rng) { return generate_final_fantasy_lalafells_name(rng, 0); }
    });
    registerGenerator({
        "final_fantasy-miqotes",
        {},
        "Generate Final Fantasy Miqotes style names",
        [](std::mt19937& rng) { return generate_final_fantasy_miqotes_name(rng, 0); }
    });
    registerGenerator({
        "final_fantasy-roegadyns",
        {},
        "Generate Final Fantasy Roegadyns style names",
        [](std::mt19937& rng) { return generate_final_fantasy_roegadyns_name(rng); }
    });
    registerGenerator({
        "game_of_thrones-dothrakis",
        {},
        "Generate Game Of Thrones Dothrakis style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_dothrakis_name(rng); }
    });
    registerGenerator({
        "game_of_thrones-free_citys",
        {},
        "Generate Game Of Thrones Free Citys style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_free_citys_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-free_folks",
        {},
        "Generate Game Of Thrones Free Folks style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_free_folks_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-ghiscaris",
        {},
        "Generate Game Of Thrones Ghiscaris style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_ghiscaris_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-mountain_clans",
        {},
        "Generate Game Of Thrones Mountain Clans style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_mountain_clans_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-nicknames",
        {},
        "Generate Game Of Thrones Nicknames style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_nicknames_name(rng); }
    });
    registerGenerator({
        "game_of_thrones-summer_islanders",
        {},
        "Generate Game Of Thrones Summer Islanders style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_summer_islanders_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-unsullieds",
        {},
        "Generate Game Of Thrones Unsullieds style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_unsullieds_name(rng); }
    });
    registerGenerator({
        "game_of_thrones-valyrians",
        {},
        "Generate Game Of Thrones Valyrians style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_valyrians_name(rng, 0); }
    });
    registerGenerator({
        "game_of_thrones-westeros",
        {},
        "Generate Game Of Thrones Westeros style names",
        [](std::mt19937& rng) { return generate_game_of_thrones_westeros_name(rng, 0); }
    });
    registerGenerator({
        "guild_wars-asuras",
        {},
        "Generate Guild Wars Asuras style names",
        [](std::mt19937& rng) { return generate_guild_wars_asuras_name(rng, 0); }
    });
    registerGenerator({
        "guild_wars-charrs",
        {},
        "Generate Guild Wars Charrs style names",
        [](std::mt19937& rng) { return generate_guild_wars_charrs_name(rng, 0); }
    });
    registerGenerator({
        "guild_wars-human",
        {},
        "Generate Guild Wars Human style names",
        [](std::mt19937& rng) { return generate_guild_wars_human_name(rng, 0); }
    });
    registerGenerator({
        "guild_wars-norns",
        {},
        "Generate Guild Wars Norns style names",
        [](std::mt19937& rng) { return generate_guild_wars_norns_name(rng, 0); }
    });
    registerGenerator({
        "guild_wars-sylvaris",
        {},
        "Generate Guild Wars Sylvaris style names",
        [](std::mt19937& rng) { return generate_guild_wars_sylvaris_name(rng, 0); }
    });
    registerGenerator({
        "halo-forerunners",
        {},
        "Generate Halo Forerunners style names",
        [](std::mt19937& rng) { return generate_halo_forerunners_name(rng); }
    });
    registerGenerator({
        "halo-huragoks",
        {},
        "Generate Halo Huragoks style names",
        [](std::mt19937& rng) { return generate_halo_huragoks_name(rng); }
    });
    registerGenerator({
        "halo-jiralhanaes",
        {},
        "Generate Halo Jiralhanaes style names",
        [](std::mt19937& rng) { return generate_halo_jiralhanaes_name(rng); }
    });
    registerGenerator({
        "halo-kig_yars",
        {},
        "Generate Halo Kig Yars style names",
        [](std::mt19937& rng) { return generate_halo_kig_yars_name(rng); }
    });
    registerGenerator({
        "halo-mgalekgolos",
        {},
        "Generate Halo Mgalekgolos style names",
        [](std::mt19937& rng) { return generate_halo_mgalekgolos_name(rng); }
    });
    registerGenerator({
        "halo-san_shyuums",
        {},
        "Generate Halo San Shyuums style names",
        [](std::mt19937& rng) { return generate_halo_san_shyuums_name(rng); }
    });
    registerGenerator({
        "halo-sangheilis",
        {},
        "Generate Halo Sangheilis style names",
        [](std::mt19937& rng) { return generate_halo_sangheilis_name(rng, 0); }
    });
    registerGenerator({
        "halo-unggoys",
        {},
        "Generate Halo Unggoys style names",
        [](std::mt19937& rng) { return generate_halo_unggoys_name(rng); }
    });
    registerGenerator({
        "harry_potter-dragon_species",
        {},
        "Generate Harry Potter Dragon Species style names",
        [](std::mt19937& rng) { return generate_harry_potter_dragon_species_name(rng); }
    });
    registerGenerator({
        "harry_potter-goblins",
        {},
        "Generate Harry Potter Goblins style names",
        [](std::mt19937& rng) { return generate_harry_potter_goblins_name(rng); }
    });
    registerGenerator({
        "harry_potter-hippogriffs",
        {},
        "Generate Harry Potter Hippogriffs style names",
        [](std::mt19937& rng) { return generate_harry_potter_hippogriffs_name(rng, 0); }
    });
    registerGenerator({
        "harry_potter-house_elfs",
        {},
        "Generate Harry Potter House Elfs style names",
        [](std::mt19937& rng) { return generate_harry_potter_house_elfs_name(rng, 0); }
    });
    registerGenerator({
        "harry_potter-winged_horses",
        {},
        "Generate Harry Potter Winged Horses style names",
        [](std::mt19937& rng) { return generate_harry_potter_winged_horses_name(rng, 0); }
    });
    registerGenerator({
        "inheritance_cycle-dragons",
        {},
        "Generate Inheritance Cycle Dragons style names",
        [](std::mt19937& rng) { return generate_inheritance_cycle_dragons_name(rng, 0); }
    });
    registerGenerator({
        "inheritance_cycle-dwarfs",
        {},
        "Generate Inheritance Cycle Dwarfs style names",
        [](std::mt19937& rng) { return generate_inheritance_cycle_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "inheritance_cycle-elfs",
        {},
        "Generate Inheritance Cycle Elfs style names",
        [](std::mt19937& rng) { return generate_inheritance_cycle_elfs_name(rng, 0); }
    });
    registerGenerator({
        "inheritance_cycle-humans",
        {},
        "Generate Inheritance Cycle Humans style names",
        [](std::mt19937& rng) { return generate_inheritance_cycle_humans_name(rng, 0); }
    });
    registerGenerator({
        "inheritance_cycle-urgals",
        {},
        "Generate Inheritance Cycle Urgals style names",
        [](std::mt19937& rng) { return generate_inheritance_cycle_urgals_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-anoukis",
        {},
        "Generate Legend Of Zelda Anoukis style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_anoukis_name(rng); }
    });
    registerGenerator({
        "legend_of_zelda-deitys",
        {},
        "Generate Legend Of Zelda Deitys style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_deitys_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-dekus",
        {},
        "Generate Legend Of Zelda Dekus style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_dekus_name(rng); }
    });
    registerGenerator({
        "legend_of_zelda-fairys",
        {},
        "Generate Legend Of Zelda Fairys style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_fairys_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-gerudos",
        {},
        "Generate Legend Of Zelda Gerudos style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_gerudos_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-gorons",
        {},
        "Generate Legend Of Zelda Gorons style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_gorons_name(rng); }
    });
    registerGenerator({
        "legend_of_zelda-humans",
        {},
        "Generate Legend Of Zelda Humans style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_humans_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-korok_kokiris",
        {},
        "Generate Legend Of Zelda Korok Kokiris style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_korok_kokiris_name(rng, 0); }
    });
    registerGenerator({
        "legend_of_zelda-minishs",
        {},
        "Generate Legend Of Zelda Minishs style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_minishs_name(rng); }
    });
    registerGenerator({
        "legend_of_zelda-zoras",
        {},
        "Generate Legend Of Zelda Zoras style names",
        [](std::mt19937& rng) { return generate_legend_of_zelda_zoras_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings-dwarfs",
        {},
        "Generate Lord Of The Rings Dwarfs style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_dwarfs_name(rng); }
    });
    registerGenerator({
        "lord_of_the_rings-elfs",
        {"elf", "lotr-elf", "lord-of-the-rings-elfs"},
        "Generate Lord of the Rings elf style names",
        [](std::mt19937& rng) { return generate_lotr_elf_name(1); }
    });
    registerGenerator({
        "lord_of_the_rings-hobbits",
        {},
        "Generate Lord Of The Rings Hobbits style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_hobbits_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings-humans",
        {},
        "Generate Lord Of The Rings Humans style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_humans_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings-maiars",
        {},
        "Generate Lord Of The Rings Maiars style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_maiars_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings-orcs",
        {},
        "Generate Lord Of The Rings Orcs style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_orcs_name(rng); }
    });
    registerGenerator({
        "lord_of_the_rings_online-beorning",
        {},
        "Generate Lord Of The Rings Online Beorning style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_online_beorning_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings_online-dwarf",
        {},
        "Generate Lord Of The Rings Online Dwarf style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_online_dwarf_name(rng); }
    });
    registerGenerator({
        "lord_of_the_rings_online-elf",
        {},
        "Generate Lord Of The Rings Online Elf style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_online_elf_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings_online-hobbit",
        {},
        "Generate Lord Of The Rings Online Hobbit style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_online_hobbit_name(rng, 0); }
    });
    registerGenerator({
        "lord_of_the_rings_online-human",
        {},
        "Generate Lord Of The Rings Online Human style names",
        [](std::mt19937& rng) { return generate_lord_of_the_rings_online_human_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-asaris",
        {},
        "Generate Mass Effect Asaris style names",
        [](std::mt19937& rng) { return generate_mass_effect_asaris_name(rng); }
    });
    registerGenerator({
        "mass_effect-batarians",
        {},
        "Generate Mass Effect Batarians style names",
        [](std::mt19937& rng) { return generate_mass_effect_batarians_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-drells",
        {},
        "Generate Mass Effect Drells style names",
        [](std::mt19937& rng) { return generate_mass_effect_drells_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-geths",
        {},
        "Generate Mass Effect Geths style names",
        [](std::mt19937& rng) { return generate_mass_effect_geths_name(rng); }
    });
    registerGenerator({
        "mass_effect-humans",
        {},
        "Generate Mass Effect Humans style names",
        [](std::mt19937& rng) { return generate_mass_effect_humans_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-krogans",
        {},
        "Generate Mass Effect Krogans style names",
        [](std::mt19937& rng) { return generate_mass_effect_krogans_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-quarians",
        {},
        "Generate Mass Effect Quarians style names",
        [](std::mt19937& rng) { return generate_mass_effect_quarians_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-salarians",
        {},
        "Generate Mass Effect Salarians style names",
        [](std::mt19937& rng) { return generate_mass_effect_salarians_name(rng, 0); }
    });
    registerGenerator({
        "mass_effect-turians",
        {},
        "Generate Mass Effect Turians style names",
        [](std::mt19937& rng) { return generate_mass_effect_turians_name(rng, 0); }
    });
    registerGenerator({
        "military-itu",
        {},
        "Generate Military Itu style names",
        [](std::mt19937& rng) { return generate_military_itu_name(rng); }
    });
    registerGenerator({
        "military-nato",
        {},
        "Generate Military Nato style names",
        [](std::mt19937& rng) { return generate_military_nato_name(rng); }
    });
    registerGenerator({
        "military-numeric",
        {},
        "Generate Military Numeric style names",
        [](std::mt19937& rng) { return generate_military_numeric_name(rng); }
    });
    registerGenerator({
        "military-royal_air_force",
        {},
        "Generate Military Royal Air Force style names",
        [](std::mt19937& rng) { return generate_military_royal_air_force_name(rng); }
    });
    registerGenerator({
        "military-royal_navy",
        {},
        "Generate Royal Navy military call-sign style names",
        [](std::mt19937& rng) { return generate_military_royal_navy_name(rng); }
    });
    registerGenerator({
        "military-signalese",
        {},
        "Generate Military Signalese style names",
        [](std::mt19937& rng) { return generate_military_signalese_name(rng); }
    });
    registerGenerator({
        "military-telegram",
        {},
        "Generate Military Telegram style names",
        [](std::mt19937& rng) { return generate_military_telegram_name(rng); }
    });
    registerGenerator({
        "military-united_states",
        {},
        "Generate United States military NATO phonetic call-signs",
        [](std::mt19937& rng) { return generate_military_united_states_name(rng); }
    });
    registerGenerator({
        "miscellaneous-afterlifes",
        {},
        "Generate Miscellaneous Afterlifes style names",
        [](std::mt19937& rng) { return generate_miscellaneous_afterlifes_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-airplanes",
        {},
        "Generate Miscellaneous Airplanes style names",
        [](std::mt19937& rng) { return generate_miscellaneous_airplanes_name(rng); }
    });
    registerGenerator({
        "miscellaneous-airships",
        {},
        "Generate Miscellaneous Airships style names",
        [](std::mt19937& rng) { return generate_miscellaneous_airships_name(rng); }
    });
    registerGenerator({
        "miscellaneous-alliances",
        {},
        "Generate Miscellaneous Alliances style names",
        [](std::mt19937& rng) { return generate_miscellaneous_alliances_name(rng); }
    });
    registerGenerator({
        "miscellaneous-animal_groups",
        {},
        "Generate Miscellaneous Animal Groups style names",
        [](std::mt19937& rng) { return generate_miscellaneous_animal_groups_name(rng); }
    });
    registerGenerator({
        "miscellaneous-anime_attacks",
        {},
        "Generate Miscellaneous Anime Attacks style names",
        [](std::mt19937& rng) { return generate_miscellaneous_anime_attacks_name(rng); }
    });
    registerGenerator({
        "miscellaneous-apocalypses",
        {},
        "Generate Miscellaneous Apocalypses style names",
        [](std::mt19937& rng) { return generate_miscellaneous_apocalypses_name(rng); }
    });
    registerGenerator({
        "miscellaneous-armys",
        {},
        "Generate Miscellaneous Armys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_armys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-artifacts",
        {},
        "Generate Miscellaneous Artifacts style names",
        [](std::mt19937& rng) { return generate_miscellaneous_artifacts_name(rng); }
    });
    registerGenerator({
        "miscellaneous-attack_moves",
        {},
        "Generate Miscellaneous Attack Moves style names",
        [](std::mt19937& rng) { return generate_miscellaneous_attack_moves_name(rng); }
    });
    registerGenerator({
        "miscellaneous-awards",
        {},
        "Generate Miscellaneous Awards style names",
        [](std::mt19937& rng) { return generate_miscellaneous_awards_name(rng); }
    });
    registerGenerator({
        "miscellaneous-bands",
        {},
        "Generate Miscellaneous Bands style names",
        [](std::mt19937& rng) { return generate_miscellaneous_bands_name(rng); }
    });
    registerGenerator({
        "miscellaneous-battles",
        {},
        "Generate Miscellaneous Battles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_battles_name(rng); }
    });
    registerGenerator({
        "miscellaneous-birds",
        {},
        "Generate Miscellaneous Birds style names",
        [](std::mt19937& rng) { return generate_miscellaneous_birds_name(rng); }
    });
    registerGenerator({
        "miscellaneous-board_games",
        {},
        "Generate Miscellaneous Board Games style names",
        [](std::mt19937& rng) { return generate_miscellaneous_board_games_name(rng); }
    });
    registerGenerator({
        "miscellaneous-book_titles",
        {},
        "Generate Miscellaneous Book Titles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_book_titles_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-bouquets",
        {},
        "Generate Miscellaneous Bouquets style names",
        [](std::mt19937& rng) { return generate_miscellaneous_bouquets_name(rng); }
    });
    registerGenerator({
        "miscellaneous-brands",
        {},
        "Generate Miscellaneous Brands style names",
        [](std::mt19937& rng) { return generate_miscellaneous_brands_name(rng); }
    });
    registerGenerator({
        "miscellaneous-candys",
        {},
        "Generate Miscellaneous Candys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_candys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-cars",
        {},
        "Generate Miscellaneous Cars style names",
        [](std::mt19937& rng) { return generate_miscellaneous_cars_name(rng); }
    });
    registerGenerator({
        "miscellaneous-chivalric_orders",
        {},
        "Generate Miscellaneous Chivalric Orders style names",
        [](std::mt19937& rng) { return generate_miscellaneous_chivalric_orders_name(rng); }
    });
    registerGenerator({
        "miscellaneous-class",
        {},
        "Generate Miscellaneous Class style names",
        [](std::mt19937& rng) { return generate_miscellaneous_class_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-clothing_brands",
        {},
        "Generate Miscellaneous Clothing Brands style names",
        [](std::mt19937& rng) { return generate_miscellaneous_clothing_brands_name(rng); }
    });
    registerGenerator({
        "miscellaneous-colors",
        {},
        "Generate Miscellaneous Colors style names",
        [](std::mt19937& rng) { return generate_miscellaneous_colors_name(rng); }
    });
    registerGenerator({
        "miscellaneous-constellations",
        {},
        "Generate Miscellaneous Constellations style names",
        [](std::mt19937& rng) { return generate_miscellaneous_constellations_name(rng); }
    });
    registerGenerator({
        "miscellaneous-creepypastas",
        {},
        "Generate Miscellaneous Creepypastas style names",
        [](std::mt19937& rng) { return generate_miscellaneous_creepypastas_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-crops",
        {},
        "Generate Miscellaneous Crops style names",
        [](std::mt19937& rng) { return generate_miscellaneous_crops_name(rng); }
    });
    registerGenerator({
        "miscellaneous-currencys",
        {},
        "Generate Miscellaneous Currencys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_currencys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-dances",
        {},
        "Generate Miscellaneous Dances style names",
        [](std::mt19937& rng) { return generate_miscellaneous_dances_name(rng); }
    });
    registerGenerator({
        "miscellaneous-dates",
        {},
        "Generate Miscellaneous Dates style names",
        [](std::mt19937& rng) { return generate_miscellaneous_dates_name(rng); }
    });
    registerGenerator({
        "miscellaneous-dinosaurs",
        {},
        "Generate Miscellaneous Dinosaurs style names",
        [](std::mt19937& rng) { return generate_miscellaneous_dinosaurs_name(rng); }
    });
    registerGenerator({
        "miscellaneous-diseases",
        {},
        "Generate Miscellaneous Diseases style names",
        [](std::mt19937& rng) { return generate_miscellaneous_diseases_name(rng); }
    });
    registerGenerator({
        "miscellaneous-drinks",
        {},
        "Generate Miscellaneous Drinks style names",
        [](std::mt19937& rng) { return generate_miscellaneous_drinks_name(rng); }
    });
    registerGenerator({
        "miscellaneous-drugs",
        {},
        "Generate Miscellaneous Drugs style names",
        [](std::mt19937& rng) { return generate_miscellaneous_drugs_name(rng); }
    });
    registerGenerator({
        "miscellaneous-enchantments",
        {},
        "Generate Miscellaneous Enchantments style names",
        [](std::mt19937& rng) { return generate_miscellaneous_enchantments_name(rng); }
    });
    registerGenerator({
        "miscellaneous-energy_types",
        {},
        "Generate Miscellaneous Energy Types style names",
        [](std::mt19937& rng) { return generate_miscellaneous_energy_types_name(rng); }
    });
    registerGenerator({
        "miscellaneous-epithets",
        {},
        "Generate Miscellaneous Epithets style names",
        [](std::mt19937& rng) { return generate_miscellaneous_epithets_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-evil_groups",
        {},
        "Generate Miscellaneous Evil Groups style names",
        [](std::mt19937& rng) { return generate_miscellaneous_evil_groups_name(rng); }
    });
    registerGenerator({
        "miscellaneous-foods",
        {},
        "Generate Miscellaneous Foods style names",
        [](std::mt19937& rng) { return generate_miscellaneous_foods_name(rng); }
    });
    registerGenerator({
        "miscellaneous-fruit_vegetables",
        {},
        "Generate Miscellaneous Fruit Vegetables style names",
        [](std::mt19937& rng) { return generate_miscellaneous_fruit_vegetables_name(rng); }
    });
    registerGenerator({
        "miscellaneous-fungis",
        {},
        "Generate Miscellaneous Fungis style names",
        [](std::mt19937& rng) { return generate_miscellaneous_fungis_name(rng); }
    });
    registerGenerator({
        "miscellaneous-galaxys",
        {},
        "Generate Miscellaneous Galaxys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_galaxys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-game_engines",
        {},
        "Generate Miscellaneous Game Engines style names",
        [](std::mt19937& rng) { return generate_miscellaneous_game_engines_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-game_soundtracks",
        {},
        "Generate Miscellaneous Game Soundtracks style names",
        [](std::mt19937& rng) { return generate_miscellaneous_game_soundtracks_name(rng); }
    });
    registerGenerator({
        "miscellaneous-gangs",
        {},
        "Generate Miscellaneous Gangs style names",
        [](std::mt19937& rng) { return generate_miscellaneous_gangs_name(rng); }
    });
    registerGenerator({
        "miscellaneous-gear_enchantments",
        {},
        "Generate Miscellaneous Gear Enchantments style names",
        [](std::mt19937& rng) { return generate_miscellaneous_gear_enchantments_name(rng); }
    });
    registerGenerator({
        "miscellaneous-gem_minerals",
        {},
        "Generate Miscellaneous Gem Minerals style names",
        [](std::mt19937& rng) { return generate_miscellaneous_gem_minerals_name(rng); }
    });
    registerGenerator({
        "miscellaneous-graffiti_tags",
        {},
        "Generate Miscellaneous Graffiti Tags style names",
        [](std::mt19937& rng) { return generate_miscellaneous_graffiti_tags_name(rng); }
    });
    registerGenerator({
        "miscellaneous-guilds",
        {},
        "Generate Miscellaneous Guilds style names",
        [](std::mt19937& rng) { return generate_miscellaneous_guilds_name(rng); }
    });
    registerGenerator({
        "miscellaneous-hackers",
        {},
        "Generate Miscellaneous Hackers style names",
        [](std::mt19937& rng) { return generate_miscellaneous_hackers_name(rng); }
    });
    registerGenerator({
        "miscellaneous-heists",
        {},
        "Generate Miscellaneous Heists style names",
        [](std::mt19937& rng) { return generate_miscellaneous_heists_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-helicopters",
        {},
        "Generate Miscellaneous Helicopters style names",
        [](std::mt19937& rng) { return generate_miscellaneous_helicopters_name(rng); }
    });
    registerGenerator({
        "miscellaneous-herbs",
        {},
        "Generate Miscellaneous Herbs style names",
        [](std::mt19937& rng) { return generate_miscellaneous_herbs_name(rng); }
    });
    registerGenerator({
        "miscellaneous-holidays",
        {},
        "Generate Miscellaneous Holidays style names",
        [](std::mt19937& rng) { return generate_miscellaneous_holidays_name(rng); }
    });
    registerGenerator({
        "miscellaneous-holy_books",
        {},
        "Generate Miscellaneous Holy Books style names",
        [](std::mt19937& rng) { return generate_miscellaneous_holy_books_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-human_species",
        {},
        "Generate Miscellaneous Human Species style names",
        [](std::mt19937& rng) { return generate_miscellaneous_human_species_name(rng); }
    });
    registerGenerator({
        "miscellaneous-instruments",
        {},
        "Generate Miscellaneous Instruments style names",
        [](std::mt19937& rng) { return generate_miscellaneous_instruments_name(rng); }
    });
    registerGenerator({
        "miscellaneous-inventions",
        {},
        "Generate Miscellaneous Inventions style names",
        [](std::mt19937& rng) { return generate_miscellaneous_inventions_name(rng); }
    });
    registerGenerator({
        "miscellaneous-jewelrys",
        {},
        "Generate Miscellaneous Jewelrys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_jewelrys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-languages",
        {},
        "Generate Miscellaneous Languages style names",
        [](std::mt19937& rng) { return generate_miscellaneous_languages_name(rng); }
    });
    registerGenerator({
        "miscellaneous-love_nicknames",
        {},
        "Generate Miscellaneous Love Nicknames style names",
        [](std::mt19937& rng) { return generate_miscellaneous_love_nicknames_name(rng); }
    });
    registerGenerator({
        "miscellaneous-magazines",
        {},
        "Generate Miscellaneous Magazines style names",
        [](std::mt19937& rng) { return generate_miscellaneous_magazines_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-magic_types",
        {},
        "Generate Miscellaneous Magic Types style names",
        [](std::mt19937& rng) { return generate_miscellaneous_magic_types_name(rng); }
    });
    registerGenerator({
        "miscellaneous-magical_diseases",
        {},
        "Generate Miscellaneous Magical Diseases style names",
        [](std::mt19937& rng) { return generate_miscellaneous_magical_diseases_name(rng); }
    });
    registerGenerator({
        "miscellaneous-magical_plants",
        {},
        "Generate Miscellaneous Magical Plants style names",
        [](std::mt19937& rng) { return generate_miscellaneous_magical_plants_name(rng); }
    });
    registerGenerator({
        "miscellaneous-magical_trees",
        {},
        "Generate Miscellaneous Magical Trees style names",
        [](std::mt19937& rng) { return generate_miscellaneous_magical_trees_name(rng); }
    });
    registerGenerator({
        "miscellaneous-martial_arts",
        {},
        "Generate Miscellaneous Martial Arts style names",
        [](std::mt19937& rng) { return generate_miscellaneous_martial_arts_name(rng); }
    });
    registerGenerator({
        "miscellaneous-mascots",
        {},
        "Generate Miscellaneous Mascots style names",
        [](std::mt19937& rng) { return generate_miscellaneous_mascots_name(rng); }
    });
    registerGenerator({
        "miscellaneous-medicines",
        {},
        "Generate Miscellaneous Medicines style names",
        [](std::mt19937& rng) { return generate_miscellaneous_medicines_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-metals",
        {},
        "Generate Miscellaneous Metals style names",
        [](std::mt19937& rng) { return generate_miscellaneous_metals_name(rng); }
    });
    registerGenerator({
        "miscellaneous-military_divisions",
        {},
        "Generate Miscellaneous Military Divisions style names",
        [](std::mt19937& rng) { return generate_miscellaneous_military_divisions_name(rng); }
    });
    registerGenerator({
        "miscellaneous-military_operations",
        {},
        "Generate Miscellaneous Military Operations style names",
        [](std::mt19937& rng) { return generate_miscellaneous_military_operations_name(rng); }
    });
    registerGenerator({
        "miscellaneous-military_ranks",
        {},
        "Generate Miscellaneous Military Ranks style names",
        [](std::mt19937& rng) { return generate_miscellaneous_military_ranks_name(rng); }
    });
    registerGenerator({
        "miscellaneous-military_vehicles",
        {},
        "Generate Miscellaneous Military Vehicles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_military_vehicles_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-molecules",
        {},
        "Generate Miscellaneous Molecules style names",
        [](std::mt19937& rng) { return generate_miscellaneous_molecules_name(rng); }
    });
    registerGenerator({
        "miscellaneous-motorcycle_clubs",
        {},
        "Generate Miscellaneous Motorcycle Clubs style names",
        [](std::mt19937& rng) { return generate_miscellaneous_motorcycle_clubs_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-mutant_plants",
        {},
        "Generate Miscellaneous Mutant Plants style names",
        [](std::mt19937& rng) { return generate_miscellaneous_mutant_plants_name(rng); }
    });
    registerGenerator({
        "miscellaneous-natural_disasters",
        {},
        "Generate Miscellaneous Natural Disasters style names",
        [](std::mt19937& rng) { return generate_miscellaneous_natural_disasters_name(rng); }
    });
    registerGenerator({
        "miscellaneous-newspapers",
        {},
        "Generate Miscellaneous Newspapers style names",
        [](std::mt19937& rng) { return generate_miscellaneous_newspapers_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-nicknames",
        {},
        "Generate Miscellaneous Nicknames style names",
        [](std::mt19937& rng) { return generate_miscellaneous_nicknames_name(rng); }
    });
    registerGenerator({
        "miscellaneous-noble_houses",
        {},
        "Generate Miscellaneous Noble Houses style names",
        [](std::mt19937& rng) { return generate_miscellaneous_noble_houses_name(rng); }
    });
    registerGenerator({
        "miscellaneous-pirate_crews",
        {},
        "Generate Miscellaneous Pirate Crews style names",
        [](std::mt19937& rng) { return generate_miscellaneous_pirate_crews_name(rng); }
    });
    registerGenerator({
        "miscellaneous-pirate_ships",
        {},
        "Generate Miscellaneous Pirate Ships style names",
        [](std::mt19937& rng) { return generate_miscellaneous_pirate_ships_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-plagues",
        {},
        "Generate Miscellaneous Plagues style names",
        [](std::mt19937& rng) { return generate_miscellaneous_plagues_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-plants",
        {},
        "Generate Miscellaneous Plants style names",
        [](std::mt19937& rng) { return generate_miscellaneous_plants_name(rng); }
    });
    registerGenerator({
        "miscellaneous-poisons",
        {},
        "Generate Miscellaneous Poisons style names",
        [](std::mt19937& rng) { return generate_miscellaneous_poisons_name(rng); }
    });
    registerGenerator({
        "miscellaneous-political_partys",
        {},
        "Generate Miscellaneous Political Partys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_political_partys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-post_apocalyptic_societys",
        {},
        "Generate Miscellaneous Post Apocalyptic Societys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_post_apocalyptic_societys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-potions",
        {},
        "Generate Miscellaneous Potions style names",
        [](std::mt19937& rng) { return generate_miscellaneous_potions_name(rng); }
    });
    registerGenerator({
        "miscellaneous-professions",
        {},
        "Generate Miscellaneous Professions style names",
        [](std::mt19937& rng) { return generate_miscellaneous_professions_name(rng); }
    });
    registerGenerator({
        "miscellaneous-racers",
        {},
        "Generate Miscellaneous Racers style names",
        [](std::mt19937& rng) { return generate_miscellaneous_racers_name(rng); }
    });
    registerGenerator({
        "miscellaneous-railways",
        {},
        "Generate Miscellaneous Railways style names",
        [](std::mt19937& rng) { return generate_miscellaneous_railways_name(rng); }
    });
    registerGenerator({
        "miscellaneous-ranks",
        {},
        "Generate Miscellaneous Ranks style names",
        [](std::mt19937& rng) { return generate_miscellaneous_ranks_name(rng); }
    });
    registerGenerator({
        "miscellaneous-religions",
        {},
        "Generate Miscellaneous Religions style names",
        [](std::mt19937& rng) { return generate_miscellaneous_religions_name(rng); }
    });
    registerGenerator({
        "miscellaneous-scientific_creatures",
        {},
        "Generate Miscellaneous Scientific Creatures style names",
        [](std::mt19937& rng) { return generate_miscellaneous_scientific_creatures_name(rng); }
    });
    registerGenerator({
        "miscellaneous-ships",
        {},
        "Generate Miscellaneous Ships style names",
        [](std::mt19937& rng) { return generate_miscellaneous_ships_name(rng); }
    });
    registerGenerator({
        "miscellaneous-siege_engines",
        {},
        "Generate Miscellaneous Siege Engines style names",
        [](std::mt19937& rng) { return generate_miscellaneous_siege_engines_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-softwares",
        {},
        "Generate Miscellaneous Softwares style names",
        [](std::mt19937& rng) { return generate_miscellaneous_softwares_name(rng); }
    });
    registerGenerator({
        "miscellaneous-song_titles",
        {},
        "Generate Miscellaneous Song Titles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_song_titles_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-space_fleets",
        {},
        "Generate Miscellaneous Space Fleets style names",
        [](std::mt19937& rng) { return generate_miscellaneous_space_fleets_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-spaceships",
        {},
        "Generate Miscellaneous Spaceships style names",
        [](std::mt19937& rng) { return generate_miscellaneous_spaceships_name(rng); }
    });
    registerGenerator({
        "miscellaneous-spells",
        {},
        "Generate Miscellaneous Spells style names",
        [](std::mt19937& rng) { return generate_miscellaneous_spells_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-sports",
        {},
        "Generate Miscellaneous Sports style names",
        [](std::mt19937& rng) { return generate_miscellaneous_sports_name(rng); }
    });
    registerGenerator({
        "miscellaneous-sports_teams",
        {},
        "Generate Miscellaneous Sports Teams style names",
        [](std::mt19937& rng) { return generate_miscellaneous_sports_teams_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-squads",
        {},
        "Generate Miscellaneous Squads style names",
        [](std::mt19937& rng) { return generate_miscellaneous_squads_name(rng); }
    });
    registerGenerator({
        "miscellaneous-superpowers",
        {},
        "Generate Miscellaneous Superpowers style names",
        [](std::mt19937& rng) { return generate_miscellaneous_superpowers_name(rng); }
    });
    registerGenerator({
        "miscellaneous-teleportations",
        {},
        "Generate Miscellaneous Teleportations style names",
        [](std::mt19937& rng) { return generate_miscellaneous_teleportations_name(rng); }
    });
    registerGenerator({
        "miscellaneous-thrones",
        {},
        "Generate Miscellaneous Thrones style names",
        [](std::mt19937& rng) { return generate_miscellaneous_thrones_name(rng); }
    });
    registerGenerator({
        "miscellaneous-time_periods",
        {},
        "Generate Miscellaneous Time Periods style names",
        [](std::mt19937& rng) { return generate_miscellaneous_time_periods_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-titles",
        {},
        "Generate Miscellaneous Titles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_titles_name(rng); }
    });
    registerGenerator({
        "miscellaneous-tool_nicknames",
        {},
        "Generate Miscellaneous Tool Nicknames style names",
        [](std::mt19937& rng) { return generate_miscellaneous_tool_nicknames_name(rng); }
    });
    registerGenerator({
        "miscellaneous-treatys",
        {},
        "Generate Miscellaneous Treatys style names",
        [](std::mt19937& rng) { return generate_miscellaneous_treatys_name(rng); }
    });
    registerGenerator({
        "miscellaneous-trees",
        {},
        "Generate Miscellaneous Trees style names",
        [](std::mt19937& rng) { return generate_miscellaneous_trees_name(rng); }
    });
    registerGenerator({
        "miscellaneous-tribals",
        {},
        "Generate Miscellaneous Tribals style names",
        [](std::mt19937& rng) { return generate_miscellaneous_tribals_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-tribes",
        {},
        "Generate Miscellaneous Tribes style names",
        [](std::mt19937& rng) { return generate_miscellaneous_tribes_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-usernames",
        {},
        "Generate Miscellaneous Usernames style names",
        [](std::mt19937& rng) { return generate_miscellaneous_usernames_name(rng); }
    });
    registerGenerator({
        "miscellaneous-vehicles",
        {},
        "Generate Miscellaneous Vehicles style names",
        [](std::mt19937& rng) { return generate_miscellaneous_vehicles_name(rng); }
    });
    registerGenerator({
        "miscellaneous-video_games",
        {},
        "Generate Miscellaneous Video Games style names",
        [](std::mt19937& rng) { return generate_miscellaneous_video_games_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-vocal_groups",
        {},
        "Generate Miscellaneous Vocal Groups style names",
        [](std::mt19937& rng) { return generate_miscellaneous_vocal_groups_name(rng); }
    });
    registerGenerator({
        "miscellaneous-weapon_abilities",
        {},
        "Generate Miscellaneous Weapon Abilities style names",
        [](std::mt19937& rng) { return generate_miscellaneous_weapon_abilities_name(rng); }
    });
    registerGenerator({
        "miscellaneous-web_series",
        {},
        "Generate Miscellaneous Web Series style names",
        [](std::mt19937& rng) { return generate_miscellaneous_web_series_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-wines",
        {},
        "Generate Miscellaneous Wines style names",
        [](std::mt19937& rng) { return generate_miscellaneous_wines_name(rng); }
    });
    registerGenerator({
        "miscellaneous-wrestlers",
        {},
        "Generate Miscellaneous Wrestlers style names",
        [](std::mt19937& rng) { return generate_miscellaneous_wrestlers_name(rng, 0); }
    });
    registerGenerator({
        "miscellaneous-wrestling_moves",
        {},
        "Generate Miscellaneous Wrestling Moves style names",
        [](std::mt19937& rng) { return generate_miscellaneous_wrestling_moves_name(rng); }
    });
    registerGenerator({
        "pathfinder-aasimars",
        {},
        "Generate Pathfinder Aasimars style names",
        [](std::mt19937& rng) { return generate_pathfinder_aasimars_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-catfolks",
        {},
        "Generate Pathfinder Catfolks style names",
        [](std::mt19937& rng) { return generate_pathfinder_catfolks_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-drows",
        {},
        "Generate Pathfinder Drows style names",
        [](std::mt19937& rng) { return generate_pathfinder_drows_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-dwarfs",
        {},
        "Generate Pathfinder Dwarfs style names",
        [](std::mt19937& rng) { return generate_pathfinder_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-elfs",
        {},
        "Generate Pathfinder Elfs style names",
        [](std::mt19937& rng) { return generate_pathfinder_elfs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-fetchlings",
        {},
        "Generate Pathfinder Fetchlings style names",
        [](std::mt19937& rng) { return generate_pathfinder_fetchlings_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-gnomes",
        {},
        "Generate Pathfinder Gnomes style names",
        [](std::mt19937& rng) { return generate_pathfinder_gnomes_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-goblins",
        {},
        "Generate Pathfinder Goblins style names",
        [](std::mt19937& rng) { return generate_pathfinder_goblins_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-half_elfs",
        {},
        "Generate Pathfinder Half Elfs style names",
        [](std::mt19937& rng) { return generate_pathfinder_half_elfs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-half_orcs",
        {},
        "Generate Pathfinder Half Orcs style names",
        [](std::mt19937& rng) { return generate_pathfinder_half_orcs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-halflings",
        {},
        "Generate Pathfinder Halflings style names",
        [](std::mt19937& rng) { return generate_pathfinder_halflings_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-hobgoblins",
        {},
        "Generate Pathfinder Hobgoblins style names",
        [](std::mt19937& rng) { return generate_pathfinder_hobgoblins_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-humans",
        {},
        "Generate Pathfinder Humans style names",
        [](std::mt19937& rng) { return generate_pathfinder_humans_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-ifrits",
        {},
        "Generate Pathfinder Ifrits style names",
        [](std::mt19937& rng) { return generate_pathfinder_ifrits_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-kobolds",
        {},
        "Generate Pathfinder Kobolds style names",
        [](std::mt19937& rng) { return generate_pathfinder_kobolds_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-orcs",
        {},
        "Generate Pathfinder Orcs style names",
        [](std::mt19937& rng) { return generate_pathfinder_orcs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-oreads",
        {},
        "Generate Pathfinder Oreads style names",
        [](std::mt19937& rng) { return generate_pathfinder_oreads_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-ratfolks",
        {},
        "Generate Pathfinder Ratfolks style names",
        [](std::mt19937& rng) { return generate_pathfinder_ratfolks_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-sylphs",
        {},
        "Generate Pathfinder Sylphs style names",
        [](std::mt19937& rng) { return generate_pathfinder_sylphs_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-tengus",
        {},
        "Generate Pathfinder Tengus style names",
        [](std::mt19937& rng) { return generate_pathfinder_tengus_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-tians",
        {},
        "Generate Pathfinder Tians style names",
        [](std::mt19937& rng) { return generate_pathfinder_tians_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-tieflings",
        {},
        "Generate Pathfinder Tieflings style names",
        [](std::mt19937& rng) { return generate_pathfinder_tieflings_name(rng, 0); }
    });
    registerGenerator({
        "pathfinder-undines",
        {},
        "Generate Pathfinder Undines style names",
        [](std::mt19937& rng) { return generate_pathfinder_undines_name(rng, 0); }
    });
    registerGenerator({
        "pets-aliens",
        {},
        "Generate Pets Aliens style names",
        [](std::mt19937& rng) { return generate_pets_aliens_name(rng, 0); }
    });
    registerGenerator({
        "pets-amphibians",
        {},
        "Generate Pets Amphibians style names",
        [](std::mt19937& rng) { return generate_pets_amphibians_name(rng, 0); }
    });
    registerGenerator({
        "pets-bats",
        {},
        "Generate Pets Bats style names",
        [](std::mt19937& rng) { return generate_pets_bats_name(rng, 0); }
    });
    registerGenerator({
        "pets-bears",
        {},
        "Generate Pets Bears style names",
        [](std::mt19937& rng) { return generate_pets_bears_name(rng, 0); }
    });
    registerGenerator({
        "pets-bird_of_preys",
        {},
        "Generate Pets Bird Of Preys style names",
        [](std::mt19937& rng) { return generate_pets_bird_of_preys_name(rng, 0); }
    });
    registerGenerator({
        "pets-birds",
        {},
        "Generate Pets Birds style names",
        [](std::mt19937& rng) { return generate_pets_birds_name(rng, 0); }
    });
    registerGenerator({
        "pets-cats",
        {},
        "Generate Pets Cats style names",
        [](std::mt19937& rng) { return generate_pets_cats_name(rng, 0); }
    });
    registerGenerator({
        "pets-cows",
        {},
        "Generate Pets Cows style names",
        [](std::mt19937& rng) { return generate_pets_cows_name(rng, 0); }
    });
    registerGenerator({
        "pets-crabs",
        {},
        "Generate Pets Crabs style names",
        [](std::mt19937& rng) { return generate_pets_crabs_name(rng, 0); }
    });
    registerGenerator({
        "pets-deers",
        {},
        "Generate Pets Deers style names",
        [](std::mt19937& rng) { return generate_pets_deers_name(rng, 0); }
    });
    registerGenerator({
        "pets-dogs",
        {},
        "Generate Pets Dogs style names",
        [](std::mt19937& rng) { return generate_pets_dogs_name(rng, 0); }
    });
    registerGenerator({
        "pets-elephants",
        {},
        "Generate Pets Elephants style names",
        [](std::mt19937& rng) { return generate_pets_elephants_name(rng, 0); }
    });
    registerGenerator({
        "pets-fishs",
        {},
        "Generate Pets Fishs style names",
        [](std::mt19937& rng) { return generate_pets_fishs_name(rng, 0); }
    });
    registerGenerator({
        "pets-horses",
        {},
        "Generate Pets Horses style names",
        [](std::mt19937& rng) { return generate_pets_horses_name(rng, 0); }
    });
    registerGenerator({
        "pets-insects",
        {},
        "Generate Pets Insects style names",
        [](std::mt19937& rng) { return generate_pets_insects_name(rng, 0); }
    });
    registerGenerator({
        "pets-lions",
        {},
        "Generate Pets Lions style names",
        [](std::mt19937& rng) { return generate_pets_lions_name(rng, 0); }
    });
    registerGenerator({
        "pets-marine_mammals",
        {},
        "Generate Pets Marine Mammals style names",
        [](std::mt19937& rng) { return generate_pets_marine_mammals_name(rng, 0); }
    });
    registerGenerator({
        "pets-monkeys",
        {},
        "Generate Pets Monkeys style names",
        [](std::mt19937& rng) { return generate_pets_monkeys_name(rng, 0); }
    });
    registerGenerator({
        "pets-mouses",
        {},
        "Generate Pets Mouses style names",
        [](std::mt19937& rng) { return generate_pets_mouses_name(rng, 0); }
    });
    registerGenerator({
        "pets-owls",
        {},
        "Generate Pets Owls style names",
        [](std::mt19937& rng) { return generate_pets_owls_name(rng, 0); }
    });
    registerGenerator({
        "pets-parrots",
        {},
        "Generate Pets Parrots style names",
        [](std::mt19937& rng) { return generate_pets_parrots_name(rng, 0); }
    });
    registerGenerator({
        "pets-pigs",
        {},
        "Generate Pets Pigs style names",
        [](std::mt19937& rng) { return generate_pets_pigs_name(rng, 0); }
    });
    registerGenerator({
        "pets-rabbits",
        {},
        "Generate Pets Rabbits style names",
        [](std::mt19937& rng) { return generate_pets_rabbits_name(rng, 0); }
    });
    registerGenerator({
        "pets-reptiles",
        {},
        "Generate Pets Reptiles style names",
        [](std::mt19937& rng) { return generate_pets_reptiles_name(rng, 0); }
    });
    registerGenerator({
        "pets-rodents",
        {},
        "Generate Pets Rodents style names",
        [](std::mt19937& rng) { return generate_pets_rodents_name(rng, 0); }
    });
    registerGenerator({
        "pets-sheeps",
        {},
        "Generate Pets Sheeps style names",
        [](std::mt19937& rng) { return generate_pets_sheeps_name(rng, 0); }
    });
    registerGenerator({
        "pets-turtles",
        {},
        "Generate Pets Turtles style names",
        [](std::mt19937& rng) { return generate_pets_turtles_name(rng, 0); }
    });
    registerGenerator({
        "pets-wolfs",
        {},
        "Generate Pets Wolfs style names",
        [](std::mt19937& rng) { return generate_pets_wolfs_name(rng, 0); }
    });
    registerGenerator({
        "places-amusement_parks",
        {},
        "Generate Places Amusement Parks style names",
        [](std::mt19937& rng) { return generate_places_amusement_parks_name(rng); }
    });
    registerGenerator({
        "places-antique_stores",
        {},
        "Generate Places Antique Stores style names",
        [](std::mt19937& rng) { return generate_places_antique_stores_name(rng); }
    });
    registerGenerator({
        "places-asylums",
        {},
        "Generate Places Asylums style names",
        [](std::mt19937& rng) { return generate_places_asylums_name(rng); }
    });
    registerGenerator({
        "places-bakerys",
        {},
        "Generate Places Bakerys style names",
        [](std::mt19937& rng) { return generate_places_bakerys_name(rng); }
    });
    registerGenerator({
        "places-banks",
        {},
        "Generate Places Banks style names",
        [](std::mt19937& rng) { return generate_places_banks_name(rng); }
    });
    registerGenerator({
        "places-battle_arenas",
        {},
        "Generate Places Battle Arenas style names",
        [](std::mt19937& rng) { return generate_places_battle_arenas_name(rng); }
    });
    registerGenerator({
        "places-beachs",
        {},
        "Generate Places Beachs style names",
        [](std::mt19937& rng) { return generate_places_beachs_name(rng); }
    });
    registerGenerator({
        "places-brewerys",
        {},
        "Generate Places Brewerys style names",
        [](std::mt19937& rng) { return generate_places_brewerys_name(rng, 0); }
    });
    registerGenerator({
        "places-bridges",
        {},
        "Generate Places Bridges style names",
        [](std::mt19937& rng) { return generate_places_bridges_name(rng); }
    });
    registerGenerator({
        "places-business",
        {},
        "Generate Places Business style names",
        [](std::mt19937& rng) { return generate_places_business_name(rng); }
    });
    registerGenerator({
        "places-cafes",
        {},
        "Generate Places Cafes style names",
        [](std::mt19937& rng) { return generate_places_cafes_name(rng); }
    });
    registerGenerator({
        "places-camps",
        {},
        "Generate Places Camps style names",
        [](std::mt19937& rng) { return generate_places_camps_name(rng); }
    });
    registerGenerator({
        "places-casinos",
        {},
        "Generate Places Casinos style names",
        [](std::mt19937& rng) { return generate_places_casinos_name(rng, 0); }
    });
    registerGenerator({
        "places-castles",
        {},
        "Generate Places Castles style names",
        [](std::mt19937& rng) { return generate_places_castles_name(rng); }
    });
    registerGenerator({
        "places-caves",
        {},
        "Generate Places Caves style names",
        [](std::mt19937& rng) { return generate_places_caves_name(rng); }
    });
    registerGenerator({
        "places-circus",
        {},
        "Generate Places Circus style names",
        [](std::mt19937& rng) { return generate_places_circus_name(rng); }
    });
    registerGenerator({
        "places-city_districts",
        {},
        "Generate Places City Districts style names",
        [](std::mt19937& rng) { return generate_places_city_districts_name(rng); }
    });
    registerGenerator({
        "places-civilizations",
        {},
        "Generate Places Civilizations style names",
        [](std::mt19937& rng) { return generate_places_civilizations_name(rng); }
    });
    registerGenerator({
        "places-cliffs",
        {},
        "Generate Places Cliffs style names",
        [](std::mt19937& rng) { return generate_places_cliffs_name(rng); }
    });
    registerGenerator({
        "places-companys",
        {},
        "Generate Places Companys style names",
        [](std::mt19937& rng) { return generate_places_companys_name(rng); }
    });
    registerGenerator({
        "places-continents",
        {},
        "Generate Places Continents style names",
        [](std::mt19937& rng) { return generate_places_continents_name(rng); }
    });
    registerGenerator({
        "places-countrys",
        {},
        "Generate Places Countrys style names",
        [](std::mt19937& rng) { return generate_places_countrys_name(rng); }
    });
    registerGenerator({
        "places-day_cares",
        {},
        "Generate Places Day Cares style names",
        [](std::mt19937& rng) { return generate_places_day_cares_name(rng); }
    });
    registerGenerator({
        "places-dimensions",
        {},
        "Generate Places Dimensions style names",
        [](std::mt19937& rng) { return generate_places_dimensions_name(rng); }
    });
    registerGenerator({
        "places-dungeons",
        {},
        "Generate Places Dungeons style names",
        [](std::mt19937& rng) { return generate_places_dungeons_name(rng); }
    });
    registerGenerator({
        "places-farms",
        {},
        "Generate Places Farms style names",
        [](std::mt19937& rng) { return generate_places_farms_name(rng); }
    });
    registerGenerator({
        "places-film_studios",
        {},
        "Generate Places Film Studios style names",
        [](std::mt19937& rng) { return generate_places_film_studios_name(rng); }
    });
    registerGenerator({
        "places-fire_lands",
        {},
        "Generate Places Fire Lands style names",
        [](std::mt19937& rng) { return generate_places_fire_lands_name(rng); }
    });
    registerGenerator({
        "places-forests",
        {},
        "Generate Places Forests style names",
        [](std::mt19937& rng) { return generate_places_forests_name(rng); }
    });
    registerGenerator({
        "places-game_studios",
        {},
        "Generate Places Game Studios style names",
        [](std::mt19937& rng) { return generate_places_game_studios_name(rng); }
    });
    registerGenerator({
        "places-grasslands",
        {},
        "Generate Places Grasslands style names",
        [](std::mt19937& rng) { return generate_places_grasslands_name(rng); }
    });
    registerGenerator({
        "places-graveyards",
        {},
        "Generate Places Graveyards style names",
        [](std::mt19937& rng) { return generate_places_graveyards_name(rng); }
    });
    registerGenerator({
        "places-harbors",
        {},
        "Generate Places Harbors style names",
        [](std::mt19937& rng) { return generate_places_harbors_name(rng); }
    });
    registerGenerator({
        "places-headquarters",
        {},
        "Generate Places Headquarters style names",
        [](std::mt19937& rng) { return generate_places_headquarters_name(rng); }
    });
    registerGenerator({
        "places-hospitals",
        {},
        "Generate Places Hospitals style names",
        [](std::mt19937& rng) { return generate_places_hospitals_name(rng); }
    });
    registerGenerator({
        "places-hotels",
        {},
        "Generate Places Hotels style names",
        [](std::mt19937& rng) { return generate_places_hotels_name(rng); }
    });
    registerGenerator({
        "places-inns",
        {},
        "Generate Places Inns style names",
        [](std::mt19937& rng) { return generate_places_inns_name(rng); }
    });
    registerGenerator({
        "places-islands",
        {},
        "Generate Places Islands style names",
        [](std::mt19937& rng) { return generate_places_islands_name(rng); }
    });
    registerGenerator({
        "places-jungles",
        {},
        "Generate Places Jungles style names",
        [](std::mt19937& rng) { return generate_places_jungles_name(rng); }
    });
    registerGenerator({
        "places-kingdoms",
        {},
        "Generate Places Kingdoms style names",
        [](std::mt19937& rng) { return generate_places_kingdoms_name(rng); }
    });
    registerGenerator({
        "places-laboratorys",
        {},
        "Generate Places Laboratorys style names",
        [](std::mt19937& rng) { return generate_places_laboratorys_name(rng); }
    });
    registerGenerator({
        "places-lakes",
        {},
        "Generate Places Lakes style names",
        [](std::mt19937& rng) { return generate_places_lakes_name(rng); }
    });
    registerGenerator({
        "places-lands",
        {},
        "Generate Places Lands style names",
        [](std::mt19937& rng) { return generate_places_lands_name(rng); }
    });
    registerGenerator({
        "places-librarys",
        {},
        "Generate Places Librarys style names",
        [](std::mt19937& rng) { return generate_places_librarys_name(rng, 0); }
    });
    registerGenerator({
        "places-magic_schools",
        {},
        "Generate Places Magic Schools style names",
        [](std::mt19937& rng) { return generate_places_magic_schools_name(rng); }
    });
    registerGenerator({
        "places-magic_shops",
        {},
        "Generate Places Magic Shops style names",
        [](std::mt19937& rng) { return generate_places_magic_shops_name(rng); }
    });
    registerGenerator({
        "places-mansions",
        {},
        "Generate Places Mansions style names",
        [](std::mt19937& rng) { return generate_places_mansions_name(rng); }
    });
    registerGenerator({
        "places-mining_companys",
        {},
        "Generate Places Mining Companys style names",
        [](std::mt19937& rng) { return generate_places_mining_companys_name(rng, 0); }
    });
    registerGenerator({
        "places-mountains",
        {},
        "Generate Places Mountains style names",
        [](std::mt19937& rng) { return generate_places_mountains_name(rng); }
    });
    registerGenerator({
        "places-museums",
        {},
        "Generate Places Museums style names",
        [](std::mt19937& rng) { return generate_places_museums_name(rng); }
    });
    registerGenerator({
        "places-nightclubs",
        {},
        "Generate Places Nightclubs style names",
        [](std::mt19937& rng) { return generate_places_nightclubs_name(rng); }
    });
    registerGenerator({
        "places-oasis",
        {},
        "Generate Places Oasis style names",
        [](std::mt19937& rng) { return generate_places_oasis_name(rng); }
    });
    registerGenerator({
        "places-orphanages",
        {},
        "Generate Places Orphanages style names",
        [](std::mt19937& rng) { return generate_places_orphanages_name(rng); }
    });
    registerGenerator({
        "places-outposts",
        {},
        "Generate Places Outposts style names",
        [](std::mt19937& rng) { return generate_places_outposts_name(rng); }
    });
    registerGenerator({
        "places-parks",
        {},
        "Generate Places Parks style names",
        [](std::mt19937& rng) { return generate_places_parks_name(rng); }
    });
    registerGenerator({
        "places-pirate_coves",
        {},
        "Generate Places Pirate Coves style names",
        [](std::mt19937& rng) { return generate_places_pirate_coves_name(rng); }
    });
    registerGenerator({
        "places-planets",
        {},
        "Generate Places Planets style names",
        [](std::mt19937& rng) { return generate_places_planets_name(rng); }
    });
    registerGenerator({
        "places-plantations",
        {},
        "Generate Places Plantations style names",
        [](std::mt19937& rng) { return generate_places_plantations_name(rng, 0); }
    });
    registerGenerator({
        "places-plazas",
        {},
        "Generate Places Plazas style names",
        [](std::mt19937& rng) { return generate_places_plazas_name(rng); }
    });
    registerGenerator({
        "places-prisons",
        {},
        "Generate Places Prisons style names",
        [](std::mt19937& rng) { return generate_places_prisons_name(rng); }
    });
    registerGenerator({
        "places-realms",
        {},
        "Generate Places Realms style names",
        [](std::mt19937& rng) { return generate_places_realms_name(rng); }
    });
    registerGenerator({
        "places-restaurants",
        {},
        "Generate Places Restaurants style names",
        [](std::mt19937& rng) { return generate_places_restaurants_name(rng); }
    });
    registerGenerator({
        "places-rivers",
        {},
        "Generate Places Rivers style names",
        [](std::mt19937& rng) { return generate_places_rivers_name(rng); }
    });
    registerGenerator({
        "places-roads",
        {},
        "Generate Places Roads style names",
        [](std::mt19937& rng) { return generate_places_roads_name(rng); }
    });
    registerGenerator({
        "places-ruins",
        {},
        "Generate Places Ruins style names",
        [](std::mt19937& rng) { return generate_places_ruins_name(rng); }
    });
    registerGenerator({
        "places-schools",
        {},
        "Generate Places Schools style names",
        [](std::mt19937& rng) { return generate_places_schools_name(rng); }
    });
    registerGenerator({
        "places-shops",
        {},
        "Generate Places Shops style names",
        [](std::mt19937& rng) { return generate_places_shops_name(rng); }
    });
    registerGenerator({
        "places-sky_islands",
        {},
        "Generate Places Sky Islands style names",
        [](std::mt19937& rng) { return generate_places_sky_islands_name(rng); }
    });
    registerGenerator({
        "places-snowlands",
        {},
        "Generate Places Snowlands style names",
        [](std::mt19937& rng) { return generate_places_snowlands_name(rng); }
    });
    registerGenerator({
        "places-space_colonys",
        {},
        "Generate Places Space Colonys style names",
        [](std::mt19937& rng) { return generate_places_space_colonys_name(rng, 0); }
    });
    registerGenerator({
        "places-stadiums",
        {},
        "Generate Places Stadiums style names",
        [](std::mt19937& rng) { return generate_places_stadiums_name(rng, 0); }
    });
    registerGenerator({
        "places-stars",
        {},
        "Generate Places Stars style names",
        [](std::mt19937& rng) { return generate_places_stars_name(rng); }
    });
    registerGenerator({
        "places-streets",
        {},
        "Generate Places Streets style names",
        [](std::mt19937& rng) { return generate_places_streets_name(rng, 0); }
    });
    registerGenerator({
        "places-swamps",
        {},
        "Generate Places Swamps style names",
        [](std::mt19937& rng) { return generate_places_swamps_name(rng); }
    });
    registerGenerator({
        "places-temples",
        {},
        "Generate Places Temples style names",
        [](std::mt19937& rng) { return generate_places_temples_name(rng); }
    });
    registerGenerator({
        "places-theaters",
        {},
        "Generate Places Theaters style names",
        [](std::mt19937& rng) { return generate_places_theaters_name(rng); }
    });
    registerGenerator({
        "places-towers",
        {},
        "Generate Places Towers style names",
        [](std::mt19937& rng) { return generate_places_towers_name(rng); }
    });
    registerGenerator({
        "places-volcanos",
        {},
        "Generate Places Volcanos style names",
        [](std::mt19937& rng) { return generate_places_volcanos_name(rng); }
    });
    registerGenerator({
        "places-waterfalls",
        {},
        "Generate Places Waterfalls style names",
        [](std::mt19937& rng) { return generate_places_waterfalls_name(rng); }
    });
    registerGenerator({
        "places-waters",
        {},
        "Generate Places Waters style names",
        [](std::mt19937& rng) { return generate_places_waters_name(rng); }
    });
    registerGenerator({
        "pop_culture-arthurians",
        {},
        "Generate Pop Culture Arthurians style names",
        [](std::mt19937& rng) { return generate_pop_culture_arthurians_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-avatar_last_airbenders",
        {},
        "Generate Pop Culture Avatar Last Airbenders style names",
        [](std::mt19937& rng) { return generate_pop_culture_avatar_last_airbenders_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-digimons",
        {},
        "Generate Pop Culture Digimons style names",
        [](std::mt19937& rng) { return generate_pop_culture_digimons_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-dragonriders_of_perns",
        {},
        "Generate Pop Culture Dragonriders Of Perns style names",
        [](std::mt19937& rng) { return generate_pop_culture_dragonriders_of_perns_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-homestucks",
        {},
        "Generate Pop Culture Homestucks style names",
        [](std::mt19937& rng) { return generate_pop_culture_homestucks_name(rng); }
    });
    registerGenerator({
        "pop_culture-how_to_train_your_dragons",
        {},
        "Generate Pop Culture How To Train Your Dragons style names",
        [](std::mt19937& rng) { return generate_pop_culture_how_to_train_your_dragons_name(rng); }
    });
    registerGenerator({
        "pop_culture-hunger_games",
        {},
        "Generate Pop Culture Hunger Games style names",
        [](std::mt19937& rng) { return generate_pop_culture_hunger_games_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-hyborians",
        {},
        "Generate Pop Culture Hyborians style names",
        [](std::mt19937& rng) { return generate_pop_culture_hyborians_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-lovecraftians",
        {},
        "Generate Pop Culture Lovecraftians style names",
        [](std::mt19937& rng) { return generate_pop_culture_lovecraftians_name(rng); }
    });
    registerGenerator({
        "pop_culture-maze_runners",
        {},
        "Generate Pop Culture Maze Runners style names",
        [](std::mt19937& rng) { return generate_pop_culture_maze_runners_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-mortal_kombats",
        {},
        "Generate Pop Culture Mortal Kombats style names",
        [](std::mt19937& rng) { return generate_pop_culture_mortal_kombats_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-my_little_ponys",
        {},
        "Generate Pop Culture My Little Ponys style names",
        [](std::mt19937& rng) { return generate_pop_culture_my_little_ponys_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-one_piece_devil_fruits",
        {},
        "Generate Pop Culture One Piece Devil Fruits style names",
        [](std::mt19937& rng) { return generate_pop_culture_one_piece_devil_fruits_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-pacific_rims",
        {},
        "Generate Pop Culture Pacific Rims style names",
        [](std::mt19937& rng) { return generate_pop_culture_pacific_rims_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-pokemons",
        {},
        "Generate Pop Culture Pokemons style names",
        [](std::mt19937& rng) { return generate_pop_culture_pokemons_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-rwbys",
        {},
        "Generate Pop Culture Rwbys style names",
        [](std::mt19937& rng) { return generate_pop_culture_rwbys_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-shadowhunter_chronicles",
        {},
        "Generate Pop Culture Shadowhunter Chronicles style names",
        [](std::mt19937& rng) { return generate_pop_culture_shadowhunter_chronicles_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-skulduggery_pleasants",
        {},
        "Generate Pop Culture Skulduggery Pleasants style names",
        [](std::mt19937& rng) { return generate_pop_culture_skulduggery_pleasants_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-starcrafts",
        {},
        "Generate Pop Culture Starcrafts style names",
        [](std::mt19937& rng) { return generate_pop_culture_starcrafts_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-stormlight_archives",
        {},
        "Generate Pop Culture Stormlight Archives style names",
        [](std::mt19937& rng) { return generate_pop_culture_stormlight_archives_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-transformers",
        {},
        "Generate Pop Culture Transformers style names",
        [](std::mt19937& rng) { return generate_pop_culture_transformers_name(rng); }
    });
    registerGenerator({
        "pop_culture-warrior_cats",
        {},
        "Generate Pop Culture Warrior Cats style names",
        [](std::mt19937& rng) { return generate_pop_culture_warrior_cats_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-wheel_of_times",
        {},
        "Generate Pop Culture Wheel Of Times style names",
        [](std::mt19937& rng) { return generate_pop_culture_wheel_of_times_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-wings_of_fires",
        {},
        "Generate Pop Culture Wings Of Fires style names",
        [](std::mt19937& rng) { return generate_pop_culture_wings_of_fires_name(rng, 0); }
    });
    registerGenerator({
        "pop_culture-x_mens",
        {},
        "Generate Pop Culture X Mens style names",
        [](std::mt19937& rng) { return generate_pop_culture_x_mens_name(rng); }
    });
    registerGenerator({
        "real-20th_century_englishs",
        {},
        "Generate Real 20Th Century Englishs style names",
        [](std::mt19937& rng) { return generate_real_20th_century_englishs_name(rng, 0); }
    });
    registerGenerator({
        "real-aboriginals",
        {},
        "Generate Real Aboriginals style names",
        [](std::mt19937& rng) { return generate_real_aboriginals_name(rng, 0); }
    });
    registerGenerator({
        "real-african_americans",
        {},
        "Generate Real African Americans style names",
        [](std::mt19937& rng) { return generate_real_african_americans_name(rng, 0); }
    });
    registerGenerator({
        "real-akans",
        {},
        "Generate Real Akans style names",
        [](std::mt19937& rng) { return generate_real_akans_name(rng, 0); }
    });
    registerGenerator({
        "real-albanians",
        {},
        "Generate Real Albanians style names",
        [](std::mt19937& rng) { return generate_real_albanians_name(rng, 0); }
    });
    registerGenerator({
        "real-algerians",
        {},
        "Generate Real Algerians style names",
        [](std::mt19937& rng) { return generate_real_algerians_name(rng, 0); }
    });
    registerGenerator({
        "real-amazighs",
        {},
        "Generate Real Amazighs style names",
        [](std::mt19937& rng) { return generate_real_amazighs_name(rng, 0); }
    });
    registerGenerator({
        "real-ancient_greeks",
        {},
        "Generate Real Ancient Greeks style names",
        [](std::mt19937& rng) { return generate_real_ancient_greeks_name(rng, 0); }
    });
    registerGenerator({
        "real-anglo_saxons",
        {},
        "Generate Real Anglo Saxons style names",
        [](std::mt19937& rng) { return generate_real_anglo_saxons_name(rng); }
    });
    registerGenerator({
        "real-argentinians",
        {},
        "Generate Real Argentinians style names",
        [](std::mt19937& rng) { return generate_real_argentinians_name(rng, 0); }
    });
    registerGenerator({
        "real-armenians",
        {},
        "Generate Real Armenians style names",
        [](std::mt19937& rng) { return generate_real_armenians_name(rng, 0); }
    });
    registerGenerator({
        "real-assyrians",
        {},
        "Generate Real Assyrians style names",
        [](std::mt19937& rng) { return generate_real_assyrians_name(rng, 0); }
    });
    registerGenerator({
        "real-azerbaijanis",
        {},
        "Generate Real Azerbaijanis style names",
        [](std::mt19937& rng) { return generate_real_azerbaijanis_name(rng, 0); }
    });
    registerGenerator({
        "real-aztecs",
        {},
        "Generate Real Aztecs style names",
        [](std::mt19937& rng) { return generate_real_aztecs_name(rng, 0); }
    });
    registerGenerator({
        "real-babylonians",
        {},
        "Generate Real Babylonians style names",
        [](std::mt19937& rng) { return generate_real_babylonians_name(rng, 0); }
    });
    registerGenerator({
        "real-basothos",
        {},
        "Generate Real Basothos style names",
        [](std::mt19937& rng) { return generate_real_basothos_name(rng, 0); }
    });
    registerGenerator({
        "real-basques",
        {},
        "Generate Real Basques style names",
        [](std::mt19937& rng) { return generate_real_basques_name(rng, 0); }
    });
    registerGenerator({
        "real-belgians",
        {},
        "Generate Real Belgians style names",
        [](std::mt19937& rng) { return generate_real_belgians_name(rng, 0); }
    });
    registerGenerator({
        "real-bengalis",
        {},
        "Generate Real Bengalis style names",
        [](std::mt19937& rng) { return generate_real_bengalis_name(rng, 0); }
    });
    registerGenerator({
        "real-biblicals",
        {},
        "Generate Real Biblicals style names",
        [](std::mt19937& rng) { return generate_real_biblicals_name(rng, 0); }
    });
    registerGenerator({
        "real-bosnians",
        {},
        "Generate Real Bosnians style names",
        [](std::mt19937& rng) { return generate_real_bosnians_name(rng, 0); }
    });
    registerGenerator({
        "real-brazilians",
        {},
        "Generate Real Brazilians style names",
        [](std::mt19937& rng) { return generate_real_brazilians_name(rng, 0); }
    });
    registerGenerator({
        "real-bulgarians",
        {},
        "Generate Real Bulgarians style names",
        [](std::mt19937& rng) { return generate_real_bulgarians_name(rng, 0); }
    });
    registerGenerator({
        "real-burmese_myanmars",
        {},
        "Generate Real Burmese Myanmars style names",
        [](std::mt19937& rng) { return generate_real_burmese_myanmars_name(rng, 0); }
    });
    registerGenerator({
        "real-cajuns",
        {},
        "Generate Real Cajuns style names",
        [](std::mt19937& rng) { return generate_real_cajuns_name(rng, 0); }
    });
    registerGenerator({
        "real-catalans",
        {},
        "Generate Real Catalans style names",
        [](std::mt19937& rng) { return generate_real_catalans_name(rng, 0); }
    });
    registerGenerator({
        "real-celtic_bretons",
        {},
        "Generate Real Celtic Bretons style names",
        [](std::mt19937& rng) { return generate_real_celtic_bretons_name(rng, 0); }
    });
    registerGenerator({
        "real-celtic_welshs",
        {},
        "Generate Real Celtic Welshs style names",
        [](std::mt19937& rng) { return generate_real_celtic_welshs_name(rng, 0); }
    });
    registerGenerator({
        "real-celtics",
        {},
        "Generate Real Celtics style names",
        [](std::mt19937& rng) { return generate_real_celtics_name(rng, 0); }
    });
    registerGenerator({
        "real-chineses",
        {},
        "Generate Real Chineses style names",
        [](std::mt19937& rng) { return generate_real_chineses_name(rng, 0); }
    });
    registerGenerator({
        "real-circassians",
        {},
        "Generate Real Circassians style names",
        [](std::mt19937& rng) { return generate_real_circassians_name(rng, 0); }
    });
    registerGenerator({
        "real-colonial_americans",
        {},
        "Generate Real Colonial Americans style names",
        [](std::mt19937& rng) { return generate_real_colonial_americans_name(rng, 0); }
    });
    registerGenerator({
        "real-croatians",
        {},
        "Generate Real Croatians style names",
        [](std::mt19937& rng) { return generate_real_croatians_name(rng, 0); }
    });
    registerGenerator({
        "real-czechs",
        {},
        "Generate Real Czechs style names",
        [](std::mt19937& rng) { return generate_real_czechs_name(rng, 0); }
    });
    registerGenerator({
        "real-danishs",
        {},
        "Generate Real Danishs style names",
        [](std::mt19937& rng) { return generate_real_danishs_name(rng, 0); }
    });
    registerGenerator({
        "real-dutchs",
        {},
        "Generate Real Dutchs style names",
        [](std::mt19937& rng) { return generate_real_dutchs_name(rng, 0); }
    });
    registerGenerator({
        "real-edo_japaneses",
        {},
        "Generate Real Edo Japaneses style names",
        [](std::mt19937& rng) { return generate_real_edo_japaneses_name(rng, 0); }
    });
    registerGenerator({
        "real-edwardians",
        {},
        "Generate Real Edwardians style names",
        [](std::mt19937& rng) { return generate_real_edwardians_name(rng, 0); }
    });
    registerGenerator({
        "real-egyptians",
        {},
        "Generate Real Egyptians style names",
        [](std::mt19937& rng) { return generate_real_egyptians_name(rng, 0); }
    });
    registerGenerator({
        "real-englishs",
        {},
        "Generate Real Englishs style names",
        [](std::mt19937& rng) { return generate_real_englishs_name(rng, 0); }
    });
    registerGenerator({
        "real-enochians",
        {},
        "Generate Real Enochians style names",
        [](std::mt19937& rng) { return generate_real_enochians_name(rng); }
    });
    registerGenerator({
        "real-estonians",
        {},
        "Generate Real Estonians style names",
        [](std::mt19937& rng) { return generate_real_estonians_name(rng, 0); }
    });
    registerGenerator({
        "real-ethiopians",
        {},
        "Generate Real Ethiopians style names",
        [](std::mt19937& rng) { return generate_real_ethiopians_name(rng, 0); }
    });
    registerGenerator({
        "real-faroeses",
        {},
        "Generate Real Faroeses style names",
        [](std::mt19937& rng) { return generate_real_faroeses_name(rng, 0); }
    });
    registerGenerator({
        "real-filipinos",
        {},
        "Generate Real Filipinos style names",
        [](std::mt19937& rng) { return generate_real_filipinos_name(rng, 0); }
    });
    registerGenerator({
        "real-finnishs",
        {},
        "Generate Real Finnishs style names",
        [](std::mt19937& rng) { return generate_real_finnishs_name(rng, 0); }
    });
    registerGenerator({
        "real-frankishs",
        {},
        "Generate Real Frankishs style names",
        [](std::mt19937& rng) { return generate_real_frankishs_name(rng, 0); }
    });
    registerGenerator({
        "real-frenchs",
        {},
        "Generate Real Frenchs style names",
        [](std::mt19937& rng) { return generate_real_frenchs_name(rng, 0); }
    });
    registerGenerator({
        "real-frisians",
        {},
        "Generate Real Frisians style names",
        [](std::mt19937& rng) { return generate_real_frisians_name(rng, 0); }
    });
    registerGenerator({
        "real-georgians",
        {},
        "Generate Real Georgians style names",
        [](std::mt19937& rng) { return generate_real_georgians_name(rng, 0); }
    });
    registerGenerator({
        "real-germans",
        {},
        "Generate Real Germans style names",
        [](std::mt19937& rng) { return generate_real_germans_name(rng, 0); }
    });
    registerGenerator({
        "real-gothics",
        {},
        "Generate Real Gothics style names",
        [](std::mt19937& rng) { return generate_real_gothics_name(rng, 0); }
    });
    registerGenerator({
        "real-greeks",
        {},
        "Generate Real Greeks style names",
        [](std::mt19937& rng) { return generate_real_greeks_name(rng, 0); }
    });
    registerGenerator({
        "real-hausas",
        {},
        "Generate Real Hausas style names",
        [](std::mt19937& rng) { return generate_real_hausas_name(rng, 0); }
    });
    registerGenerator({
        "real-hawaiians",
        {},
        "Generate Real Hawaiians style names",
        [](std::mt19937& rng) { return generate_real_hawaiians_name(rng, 0); }
    });
    registerGenerator({
        "real-hebrews",
        {},
        "Generate Real Hebrews style names",
        [](std::mt19937& rng) { return generate_real_hebrews_name(rng, 0); }
    });
    registerGenerator({
        "real-hillbillys",
        {},
        "Generate Real Hillbillys style names",
        [](std::mt19937& rng) { return generate_real_hillbillys_name(rng, 0); }
    });
    registerGenerator({
        "real-hindus",
        {},
        "Generate Real Hindus style names",
        [](std::mt19937& rng) { return generate_real_hindus_name(rng, 0); }
    });
    registerGenerator({
        "real-hippies",
        {},
        "Generate Real Hippies style names",
        [](std::mt19937& rng) { return generate_real_hippies_name(rng, 0); }
    });
    registerGenerator({
        "real-hispanics",
        {},
        "Generate Real Hispanics style names",
        [](std::mt19937& rng) { return generate_real_hispanics_name(rng, 0); }
    });
    registerGenerator({
        "real-hungarians",
        {},
        "Generate Real Hungarians style names",
        [](std::mt19937& rng) { return generate_real_hungarians_name(rng, 0); }
    });
    registerGenerator({
        "real-icelandics",
        {},
        "Generate Real Icelandics style names",
        [](std::mt19937& rng) { return generate_real_icelandics_name(rng, 0); }
    });
    registerGenerator({
        "real-indonesians",
        {},
        "Generate Real Indonesians style names",
        [](std::mt19937& rng) { return generate_real_indonesians_name(rng, 0); }
    });
    registerGenerator({
        "real-inuits",
        {},
        "Generate Real Inuits style names",
        [](std::mt19937& rng) { return generate_real_inuits_name(rng); }
    });
    registerGenerator({
        "real-irishs",
        {},
        "Generate Real Irishs style names",
        [](std::mt19937& rng) { return generate_real_irishs_name(rng, 0); }
    });
    registerGenerator({
        "real-italians",
        {},
        "Generate Real Italians style names",
        [](std::mt19937& rng) { return generate_real_italians_name(rng, 0); }
    });
    registerGenerator({
        "real-jamaicans",
        {},
        "Generate Real Jamaicans style names",
        [](std::mt19937& rng) { return generate_real_jamaicans_name(rng, 0); }
    });
    registerGenerator({
        "real-japaneses",
        {},
        "Generate Real Japaneses style names",
        [](std::mt19937& rng) { return generate_real_japaneses_name(rng, 0); }
    });
    registerGenerator({
        "real-jewishs",
        {},
        "Generate Real Jewishs style names",
        [](std::mt19937& rng) { return generate_real_jewishs_name(rng, 0); }
    });
    registerGenerator({
        "real-kazakhs",
        {},
        "Generate Real Kazakhs style names",
        [](std::mt19937& rng) { return generate_real_kazakhs_name(rng, 0); }
    });
    registerGenerator({
        "real-khmers",
        {},
        "Generate Real Khmers style names",
        [](std::mt19937& rng) { return generate_real_khmers_name(rng, 0); }
    });
    registerGenerator({
        "real-koreans",
        {},
        "Generate Real Koreans style names",
        [](std::mt19937& rng) { return generate_real_koreans_name(rng, 0); }
    });
    registerGenerator({
        "real-kurdishs",
        {},
        "Generate Real Kurdishs style names",
        [](std::mt19937& rng) { return generate_real_kurdishs_name(rng, 0); }
    });
    registerGenerator({
        "real-laotians",
        {},
        "Generate Real Laotians style names",
        [](std::mt19937& rng) { return generate_real_laotians_name(rng, 0); }
    });
    registerGenerator({
        "real-latins",
        {},
        "Generate Real Latins style names",
        [](std::mt19937& rng) { return generate_real_latins_name(rng, 0); }
    });
    registerGenerator({
        "real-latvians",
        {},
        "Generate Real Latvians style names",
        [](std::mt19937& rng) { return generate_real_latvians_name(rng, 0); }
    });
    registerGenerator({
        "real-lithuanians",
        {},
        "Generate Real Lithuanians style names",
        [](std::mt19937& rng) { return generate_real_lithuanians_name(rng, 0); }
    });
    registerGenerator({
        "real-malaysians",
        {},
        "Generate Real Malaysians style names",
        [](std::mt19937& rng) { return generate_real_malaysians_name(rng, 0); }
    });
    registerGenerator({
        "real-malteses",
        {},
        "Generate Real Malteses style names",
        [](std::mt19937& rng) { return generate_real_malteses_name(rng, 0); }
    });
    registerGenerator({
        "real-maoris",
        {},
        "Generate Real Maoris style names",
        [](std::mt19937& rng) { return generate_real_maoris_name(rng, 0); }
    });
    registerGenerator({
        "real-mayans",
        {},
        "Generate Real Mayans style names",
        [](std::mt19937& rng) { return generate_real_mayans_name(rng, 0); }
    });
    registerGenerator({
        "real-modern_egyptians",
        {},
        "Generate Real Modern Egyptians style names",
        [](std::mt19937& rng) { return generate_real_modern_egyptians_name(rng, 0); }
    });
    registerGenerator({
        "real-mongolians",
        {},
        "Generate Real Mongolians style names",
        [](std::mt19937& rng) { return generate_real_mongolians_name(rng, 0); }
    });
    registerGenerator({
        "real-moroccans",
        {},
        "Generate Real Moroccans style names",
        [](std::mt19937& rng) { return generate_real_moroccans_name(rng, 0); }
    });
    registerGenerator({
        "real-muslims",
        {},
        "Generate Real Muslims style names",
        [](std::mt19937& rng) { return generate_real_muslims_name(rng, 0); }
    });
    registerGenerator({
        "real-native_americans",
        {},
        "Generate Real Native Americans style names",
        [](std::mt19937& rng) { return generate_real_native_americans_name(rng, 0); }
    });
    registerGenerator({
        "real-natures",
        {},
        "Generate Real Natures style names",
        [](std::mt19937& rng) { return generate_real_natures_name(rng, 0); }
    });
    registerGenerator({
        "real-nepaleses",
        {},
        "Generate Real Nepaleses style names",
        [](std::mt19937& rng) { return generate_real_nepaleses_name(rng, 0); }
    });
    registerGenerator({
        "real-normans",
        {},
        "Generate Real Normans style names",
        [](std::mt19937& rng) { return generate_real_normans_name(rng, 0); }
    });
    registerGenerator({
        "real-norwegians",
        {},
        "Generate Real Norwegians style names",
        [](std::mt19937& rng) { return generate_real_norwegians_name(rng, 0); }
    });
    registerGenerator({
        "real-old_high_germans",
        {},
        "Generate Real Old High Germans style names",
        [](std::mt19937& rng) { return generate_real_old_high_germans_name(rng, 0); }
    });
    registerGenerator({
        "real-pashtuns",
        {},
        "Generate Real Pashtuns style names",
        [](std::mt19937& rng) { return generate_real_pashtuns_name(rng, 0); }
    });
    registerGenerator({
        "real-persians",
        {},
        "Generate Real Persians style names",
        [](std::mt19937& rng) { return generate_real_persians_name(rng, 0); }
    });
    registerGenerator({
        "real-polishs",
        {},
        "Generate Real Polishs style names",
        [](std::mt19937& rng) { return generate_real_polishs_name(rng, 0); }
    });
    registerGenerator({
        "real-portugueses",
        {},
        "Generate Real Portugueses style names",
        [](std::mt19937& rng) { return generate_real_portugueses_name(rng, 0); }
    });
    registerGenerator({
        "real-poshs",
        {},
        "Generate Real Poshs style names",
        [](std::mt19937& rng) { return generate_real_poshs_name(rng, 0); }
    });
    registerGenerator({
        "real-punjabis",
        {},
        "Generate Real Punjabis style names",
        [](std::mt19937& rng) { return generate_real_punjabis_name(rng, 0); }
    });
    registerGenerator({
        "real-puritans",
        {},
        "Generate Real Puritans style names",
        [](std::mt19937& rng) { return generate_real_puritans_name(rng); }
    });
    registerGenerator({
        "real-quebecois",
        {},
        "Generate Real Quebecois style names",
        [](std::mt19937& rng) { return generate_real_quebecois_name(rng, 0); }
    });
    registerGenerator({
        "real-roma_gypsys",
        {},
        "Generate Real Roma Gypsys style names",
        [](std::mt19937& rng) { return generate_real_roma_gypsys_name(rng, 0); }
    });
    registerGenerator({
        "real-romanians",
        {},
        "Generate Real Romanians style names",
        [](std::mt19937& rng) { return generate_real_romanians_name(rng, 0); }
    });
    registerGenerator({
        "real-romans",
        {},
        "Generate Real Romans style names",
        [](std::mt19937& rng) { return generate_real_romans_name(rng, 0); }
    });
    registerGenerator({
        "real-russians",
        {},
        "Generate Real Russians style names",
        [](std::mt19937& rng) { return generate_real_russians_name(rng, 0); }
    });
    registerGenerator({
        "real-serbians",
        {},
        "Generate Real Serbians style names",
        [](std::mt19937& rng) { return generate_real_serbians_name(rng, 0); }
    });
    registerGenerator({
        "real-shakespeareans",
        {},
        "Generate Real Shakespeareans style names",
        [](std::mt19937& rng) { return generate_real_shakespeareans_name(rng, 0); }
    });
    registerGenerator({
        "real-shonas",
        {},
        "Generate Real Shonas style names",
        [](std::mt19937& rng) { return generate_real_shonas_name(rng, 0); }
    });
    registerGenerator({
        "real-sikhs",
        {},
        "Generate Real Sikhs style names",
        [](std::mt19937& rng) { return generate_real_sikhs_name(rng, 0); }
    });
    registerGenerator({
        "real-sinhaleses",
        {},
        "Generate Real Sinhaleses style names",
        [](std::mt19937& rng) { return generate_real_sinhaleses_name(rng, 0); }
    });
    registerGenerator({
        "real-slavics",
        {},
        "Generate Real Slavics style names",
        [](std::mt19937& rng) { return generate_real_slavics_name(rng, 0); }
    });
    registerGenerator({
        "real-slovenians",
        {},
        "Generate Real Slovenians style names",
        [](std::mt19937& rng) { return generate_real_slovenians_name(rng, 0); }
    });
    registerGenerator({
        "real-somalis",
        {},
        "Generate Real Somalis style names",
        [](std::mt19937& rng) { return generate_real_somalis_name(rng, 0); }
    });
    registerGenerator({
        "real-stages",
        {},
        "Generate Real Stages style names",
        [](std::mt19937& rng) { return generate_real_stages_name(rng, 0); }
    });
    registerGenerator({
        "real-suebis",
        {},
        "Generate Real Suebis style names",
        [](std::mt19937& rng) { return generate_real_suebis_name(rng, 0); }
    });
    registerGenerator({
        "real-sumerians",
        {},
        "Generate Real Sumerians style names",
        [](std::mt19937& rng) { return generate_real_sumerians_name(rng, 0); }
    });
    registerGenerator({
        "real-swahilis",
        {},
        "Generate Real Swahilis style names",
        [](std::mt19937& rng) { return generate_real_swahilis_name(rng, 0); }
    });
    registerGenerator({
        "real-swedishs",
        {},
        "Generate Real Swedishs style names",
        [](std::mt19937& rng) { return generate_real_swedishs_name(rng, 0); }
    });
    registerGenerator({
        "real-swiss",
        {},
        "Generate Real Swiss style names",
        [](std::mt19937& rng) { return generate_real_swiss_name(rng, 0); }
    });
    registerGenerator({
        "real-tajiks",
        {},
        "Generate Real Tajiks style names",
        [](std::mt19937& rng) { return generate_real_tajiks_name(rng, 0); }
    });
    registerGenerator({
        "real-tamils",
        {},
        "Generate Real Tamils style names",
        [](std::mt19937& rng) { return generate_real_tamils_name(rng, 0); }
    });
    registerGenerator({
        "real-telugus",
        {},
        "Generate Real Telugus style names",
        [](std::mt19937& rng) { return generate_real_telugus_name(rng, 0); }
    });
    registerGenerator({
        "real-thais",
        {},
        "Generate Real Thais style names",
        [](std::mt19937& rng) { return generate_real_thais_name(rng, 0); }
    });
    registerGenerator({
        "real-tibetans",
        {},
        "Generate Real Tibetans style names",
        [](std::mt19937& rng) { return generate_real_tibetans_name(rng, 0); }
    });
    registerGenerator({
        "real-turkishs",
        {},
        "Generate Real Turkishs style names",
        [](std::mt19937& rng) { return generate_real_turkishs_name(rng, 0); }
    });
    registerGenerator({
        "real-twins",
        {},
        "Generate Real Twins style names",
        [](std::mt19937& rng) { return generate_real_twins_name(rng, 0); }
    });
    registerGenerator({
        "real-ukrainians",
        {},
        "Generate Real Ukrainians style names",
        [](std::mt19937& rng) { return generate_real_ukrainians_name(rng, 0); }
    });
    registerGenerator({
        "real-victorians",
        {},
        "Generate Real Victorians style names",
        [](std::mt19937& rng) { return generate_real_victorians_name(rng, 0); }
    });
    registerGenerator({
        "real-vietnameses",
        {},
        "Generate Real Vietnameses style names",
        [](std::mt19937& rng) { return generate_real_vietnameses_name(rng, 0); }
    });
    registerGenerator({
        "real-vikings",
        {},
        "Generate Real Vikings style names",
        [](std::mt19937& rng) { return generate_real_vikings_name(rng, 0); }
    });
    registerGenerator({
        "real-yorubas",
        {},
        "Generate Real Yorubas style names",
        [](std::mt19937& rng) { return generate_real_yorubas_name(rng, 0); }
    });
    registerGenerator({
        "real-zulus",
        {},
        "Generate Real Zulus style names",
        [](std::mt19937& rng) { return generate_real_zulus_name(rng, 0); }
    });
    registerGenerator({
        "rift-bahmis",
        {},
        "Generate Rift Bahmis style names",
        [](std::mt19937& rng) { return generate_rift_bahmis_name(rng); }
    });
    registerGenerator({
        "rift-dwarfs",
        {},
        "Generate Rift Dwarfs style names",
        [](std::mt19937& rng) { return generate_rift_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "rift-eths",
        {},
        "Generate Rift Eths style names",
        [](std::mt19937& rng) { return generate_rift_eths_name(rng, 0); }
    });
    registerGenerator({
        "rift-high_elfs",
        {},
        "Generate Rift High Elfs style names",
        [](std::mt19937& rng) { return generate_rift_high_elfs_name(rng, 0); }
    });
    registerGenerator({
        "rift-kelaris",
        {},
        "Generate Rift Kelaris style names",
        [](std::mt19937& rng) { return generate_rift_kelaris_name(rng, 0); }
    });
    registerGenerator({
        "rift-mathosians",
        {},
        "Generate Rift Mathosians style names",
        [](std::mt19937& rng) { return generate_rift_mathosians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-andorians",
        {},
        "Generate Star Trek Andorians style names",
        [](std::mt19937& rng) { return generate_star_trek_andorians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-bajorans",
        {},
        "Generate Star Trek Bajorans style names",
        [](std::mt19937& rng) { return generate_star_trek_bajorans_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-benzites",
        {},
        "Generate Star Trek Benzites style names",
        [](std::mt19937& rng) { return generate_star_trek_benzites_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-betazoids",
        {},
        "Generate Star Trek Betazoids style names",
        [](std::mt19937& rng) { return generate_star_trek_betazoids_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-bolians",
        {},
        "Generate Star Trek Bolians style names",
        [](std::mt19937& rng) { return generate_star_trek_bolians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-caitians",
        {},
        "Generate Star Trek Caitians style names",
        [](std::mt19937& rng) { return generate_star_trek_caitians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-ferengis",
        {},
        "Generate Star Trek Ferengis style names",
        [](std::mt19937& rng) { return generate_star_trek_ferengis_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-gorns",
        {},
        "Generate Star Trek Gorns style names",
        [](std::mt19937& rng) { return generate_star_trek_gorns_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-jemhadars",
        {},
        "Generate Star Trek Jemhadars style names",
        [](std::mt19937& rng) { return generate_star_trek_jemhadars_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-klingons",
        {},
        "Generate Star Trek Klingons style names",
        [](std::mt19937& rng) { return generate_star_trek_klingons_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-letheans",
        {},
        "Generate Star Trek Letheans style names",
        [](std::mt19937& rng) { return generate_star_trek_letheans_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-nausicaans",
        {},
        "Generate Star Trek Nausicaans style names",
        [](std::mt19937& rng) { return generate_star_trek_nausicaans_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-orions",
        {},
        "Generate Star Trek Orions style names",
        [](std::mt19937& rng) { return generate_star_trek_orions_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-pakleds",
        {},
        "Generate Star Trek Pakleds style names",
        [](std::mt19937& rng) { return generate_star_trek_pakleds_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-remans",
        {},
        "Generate Star Trek Remans style names",
        [](std::mt19937& rng) { return generate_star_trek_remans_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-rigelians",
        {},
        "Generate Star Trek Rigelians style names",
        [](std::mt19937& rng) { return generate_star_trek_rigelians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-romulans",
        {},
        "Generate Star Trek Romulans style names",
        [](std::mt19937& rng) { return generate_star_trek_romulans_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-saurians",
        {},
        "Generate Star Trek Saurians style names",
        [](std::mt19937& rng) { return generate_star_trek_saurians_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-tellarites",
        {},
        "Generate Star Trek Tellarites style names",
        [](std::mt19937& rng) { return generate_star_trek_tellarites_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-trills",
        {},
        "Generate Star Trek Trills style names",
        [](std::mt19937& rng) { return generate_star_trek_trills_name(rng, 0); }
    });
    registerGenerator({
        "star_trek-vulcans",
        {},
        "Generate Star Trek Vulcans style names",
        [](std::mt19937& rng) { return generate_star_trek_vulcans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-anzatis",
        {},
        "Generate Star Wars Anzatis style names",
        [](std::mt19937& rng) { return generate_star_wars_anzatis_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-biths",
        {},
        "Generate Star Wars Biths style names",
        [](std::mt19937& rng) { return generate_star_wars_biths_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-bothans",
        {},
        "Generate Star Wars Bothans style names",
        [](std::mt19937& rng) { return generate_star_wars_bothans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-darths",
        {},
        "Generate Star Wars Darths style names",
        [](std::mt19937& rng) { return generate_star_wars_darths_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-devaronians",
        {},
        "Generate Star Wars Devaronians style names",
        [](std::mt19937& rng) { return generate_star_wars_devaronians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-dugs",
        {},
        "Generate Star Wars Dugs style names",
        [](std::mt19937& rng) { return generate_star_wars_dugs_name(rng); }
    });
    registerGenerator({
        "star_wars-duross",
        {},
        "Generate Star Wars Duross style names",
        [](std::mt19937& rng) { return generate_star_wars_duross_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-ewoks",
        {},
        "Generate Star Wars Ewoks style names",
        [](std::mt19937& rng) { return generate_star_wars_ewoks_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-falleens",
        {},
        "Generate Star Wars Falleens style names",
        [](std::mt19937& rng) { return generate_star_wars_falleens_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-gamorreans",
        {},
        "Generate Star Wars Gamorreans style names",
        [](std::mt19937& rng) { return generate_star_wars_gamorreans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-gands",
        {},
        "Generate Star Wars Gands style names",
        [](std::mt19937& rng) { return generate_star_wars_gands_name(rng); }
    });
    registerGenerator({
        "star_wars-gotals",
        {},
        "Generate Star Wars Gotals style names",
        [](std::mt19937& rng) { return generate_star_wars_gotals_name(rng); }
    });
    registerGenerator({
        "star_wars-grans",
        {},
        "Generate Star Wars Grans style names",
        [](std::mt19937& rng) { return generate_star_wars_grans_name(rng); }
    });
    registerGenerator({
        "star_wars-gungans",
        {},
        "Generate Star Wars Gungans style names",
        [](std::mt19937& rng) { return generate_star_wars_gungans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-hutts",
        {},
        "Generate Star Wars Hutts style names",
        [](std::mt19937& rng) { return generate_star_wars_hutts_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-iktotchis",
        {},
        "Generate Star Wars Iktotchis style names",
        [](std::mt19937& rng) { return generate_star_wars_iktotchis_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-ishi_tibs",
        {},
        "Generate Star Wars Ishi Tibs style names",
        [](std::mt19937& rng) { return generate_star_wars_ishi_tibs_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-ithorians",
        {},
        "Generate Star Wars Ithorians style names",
        [](std::mt19937& rng) { return generate_star_wars_ithorians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-jawas",
        {},
        "Generate Star Wars Jawas style names",
        [](std::mt19937& rng) { return generate_star_wars_jawas_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-kel_dors",
        {},
        "Generate Star Wars Kel Dors style names",
        [](std::mt19937& rng) { return generate_star_wars_kel_dors_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-korunnais",
        {},
        "Generate Star Wars Korunnais style names",
        [](std::mt19937& rng) { return generate_star_wars_korunnais_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-mandalorians",
        {},
        "Generate Star Wars Mandalorians style names",
        [](std::mt19937& rng) { return generate_star_wars_mandalorians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-mon_calamaris",
        {},
        "Generate Star Wars Mon Calamaris style names",
        [](std::mt19937& rng) { return generate_star_wars_mon_calamaris_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-nautolans",
        {},
        "Generate Star Wars Nautolans style names",
        [](std::mt19937& rng) { return generate_star_wars_nautolans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-neimoidians",
        {},
        "Generate Star Wars Neimoidians style names",
        [](std::mt19937& rng) { return generate_star_wars_neimoidians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-niktos",
        {},
        "Generate Star Wars Niktos style names",
        [](std::mt19937& rng) { return generate_star_wars_niktos_name(rng); }
    });
    registerGenerator({
        "star_wars-ortolans",
        {},
        "Generate Star Wars Ortolans style names",
        [](std::mt19937& rng) { return generate_star_wars_ortolans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-quarrens",
        {},
        "Generate Star Wars Quarrens style names",
        [](std::mt19937& rng) { return generate_star_wars_quarrens_name(rng); }
    });
    registerGenerator({
        "star_wars-rodians",
        {},
        "Generate Star Wars Rodians style names",
        [](std::mt19937& rng) { return generate_star_wars_rodians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-shistavanens",
        {},
        "Generate Star Wars Shistavanens style names",
        [](std::mt19937& rng) { return generate_star_wars_shistavanens_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-sullustans",
        {},
        "Generate Star Wars Sullustans style names",
        [](std::mt19937& rng) { return generate_star_wars_sullustans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-swiss",
        {},
        "Generate Star Wars Swiss style names",
        [](std::mt19937& rng) { return generate_star_wars_swiss_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-toydarians",
        {},
        "Generate Star Wars Toydarians style names",
        [](std::mt19937& rng) { return generate_star_wars_toydarians_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-trandoshans",
        {},
        "Generate Star Wars Trandoshans style names",
        [](std::mt19937& rng) { return generate_star_wars_trandoshans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-tusken_raiders",
        {},
        "Generate Star Wars Tusken Raiders style names",
        [](std::mt19937& rng) { return generate_star_wars_tusken_raiders_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-weequays",
        {},
        "Generate Star Wars Weequays style names",
        [](std::mt19937& rng) { return generate_star_wars_weequays_name(rng, 0); }
    });
    registerGenerator({
        "star_wars-wookiees",
        {},
        "Generate Star Wars Wookiees style names",
        [](std::mt19937& rng) { return generate_star_wars_wookiees_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-cathars",
        {},
        "Generate Star Wars The Old Republic Cathars style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_cathars_name(rng); }
    });
    registerGenerator({
        "star_wars_the_old_republic-chiss",
        {},
        "Generate Star Wars The Old Republic Chiss style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_chiss_name(rng); }
    });
    registerGenerator({
        "star_wars_the_old_republic-cyborgs",
        {},
        "Generate Star Wars The Old Republic Cyborgs style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_cyborgs_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-human_sws",
        {},
        "Generate Star Wars The Old Republic Human Sws style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_human_sws_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-miralukas",
        {},
        "Generate Star Wars The Old Republic Miralukas style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_miralukas_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-mirialans",
        {},
        "Generate Star Wars The Old Republic Mirialans style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_mirialans_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-rattatakis",
        {},
        "Generate Star Wars The Old Republic Rattatakis style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_rattatakis_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-siths",
        {},
        "Generate Star Wars The Old Republic Siths style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_siths_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-togrutas",
        {},
        "Generate Star Wars The Old Republic Togrutas style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_togrutas_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-twileks",
        {},
        "Generate Star Wars The Old Republic Twileks style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_twileks_name(rng, 0); }
    });
    registerGenerator({
        "star_wars_the_old_republic-zabraks",
        {},
        "Generate Star Wars The Old Republic Zabraks style names",
        [](std::mt19937& rng) { return generate_star_wars_the_old_republic_zabraks_name(rng, 0); }
    });
    registerGenerator({
        "the_witcher-dwarfs",
        {},
        "Generate The Witcher Dwarfs style names",
        [](std::mt19937& rng) { return generate_the_witcher_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "the_witcher-elfs",
        {},
        "Generate The Witcher Elfs style names",
        [](std::mt19937& rng) { return generate_the_witcher_elfs_name(rng, 0); }
    });
    registerGenerator({
        "the_witcher-halflings",
        {},
        "Generate The Witcher Halflings style names",
        [](std::mt19937& rng) { return generate_the_witcher_halflings_name(rng, 0); }
    });
    registerGenerator({
        "the_witcher-humans",
        {},
        "Generate The Witcher Humans style names",
        [](std::mt19937& rng) { return generate_the_witcher_humans_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-ancient_greek_towns",
        {},
        "Generate Towns And Cities Ancient Greek Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_ancient_greek_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-apocalypse_towns",
        {},
        "Generate Towns And Cities Apocalypse Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_apocalypse_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-central_african_towns",
        {},
        "Generate Towns And Cities Central African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_central_african_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-central_american_towns",
        {},
        "Generate Towns And Cities Central American Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_central_american_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-central_east_african_towns",
        {},
        "Generate Towns And Cities Central East African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_central_east_african_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-city_nicknames",
        {},
        "Generate Towns And Cities City Nicknames style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_city_nicknames_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-citys",
        {},
        "Generate Towns And Cities Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-dwarven_citys",
        {},
        "Generate Towns And Cities Dwarven Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_dwarven_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-east_asian_towns",
        {},
        "Generate Towns And Cities East Asian Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_east_asian_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-east_european_towns",
        {},
        "Generate Towns And Cities East European Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_east_european_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-egyptian_towns",
        {},
        "Generate Towns And Cities Egyptian Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_egyptian_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-elven_citys",
        {},
        "Generate Towns And Cities Elven Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_elven_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-fantasy_towns",
        {},
        "Generate Towns And Cities Fantasy Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_fantasy_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-middle_eastern_towns",
        {},
        "Generate Towns And Cities Middle Eastern Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_middle_eastern_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-north_african_towns",
        {},
        "Generate Towns And Cities North African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_north_african_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-north_american_towns",
        {},
        "Generate Towns And Cities North American Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_north_american_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-north_european_towns",
        {},
        "Generate Towns And Cities North European Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_north_european_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-northern_south_american_towns",
        {},
        "Generate Towns And Cities Northern South American Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_northern_south_american_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-oceania_towns",
        {},
        "Generate Towns And Cities Oceania Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_oceania_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-orcish_citys",
        {},
        "Generate Towns And Cities Orcish Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_orcish_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-roman_towns",
        {},
        "Generate Towns And Cities Roman Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_roman_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-russian_towns",
        {},
        "Generate Towns And Cities Russian Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_russian_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-south_african_towns",
        {},
        "Generate Towns And Cities South African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_south_african_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-south_american_towns",
        {},
        "Generate Towns And Cities South American Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_south_american_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-south_asian_towns",
        {},
        "Generate Towns And Cities South Asian Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_south_asian_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-south_european_towns",
        {},
        "Generate Towns And Cities South European Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_south_european_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-southeast_african_towns",
        {},
        "Generate Towns And Cities Southeast African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_southeast_african_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-southeast_asian_towns",
        {},
        "Generate Towns And Cities Southeast Asian Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_southeast_asian_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-southeast_european",
        {},
        "Generate Towns And Cities Southeast European style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_southeast_european_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-steampunk_citys",
        {},
        "Generate Towns And Cities Steampunk Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_steampunk_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-towns",
        {},
        "Generate Towns And Cities Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-underwater_citys",
        {},
        "Generate Towns And Cities Underwater Citys style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_underwater_citys_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-viking_towns",
        {},
        "Generate Towns And Cities Viking Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_viking_towns_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-west_african_towns",
        {},
        "Generate Towns And Cities West African Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_west_african_towns_name(rng, 0); }
    });
    registerGenerator({
        "towns_and_cities-west_european_towns",
        {},
        "Generate Towns And Cities West European Towns style names",
        [](std::mt19937& rng) { return generate_west_european_town_name(rng); }
    });
    registerGenerator({
        "towns_and_cities-wild_west_towns",
        {},
        "Generate Towns And Cities Wild West Towns style names",
        [](std::mt19937& rng) { return generate_towns_and_cities_wild_west_towns_name(rng); }
    });
    registerGenerator({
        "warhammer-beastmens",
        {},
        "Generate Warhammer Beastmens style names",
        [](std::mt19937& rng) { return generate_warhammer_beastmens_name(rng); }
    });
    registerGenerator({
        "warhammer-bretonnias",
        {},
        "Generate Warhammer Bretonnias style names",
        [](std::mt19937& rng) { return generate_warhammer_bretonnias_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-daemons_of_chaos",
        {},
        "Generate Warhammer Daemons Of Chaos style names",
        [](std::mt19937& rng) { return generate_warhammer_daemons_of_chaos_name(rng); }
    });
    registerGenerator({
        "warhammer-dark_elfs",
        {},
        "Generate Warhammer Dark Elfs style names",
        [](std::mt19937& rng) { return generate_warhammer_dark_elfs_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-dwarfs",
        {},
        "Generate Warhammer Dwarfs style names",
        [](std::mt19937& rng) { return generate_warhammer_dwarfs_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-empires",
        {},
        "Generate Warhammer Empires style names",
        [](std::mt19937& rng) { return generate_warhammer_empires_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-goblins",
        {},
        "Generate Warhammer Goblins style names",
        [](std::mt19937& rng) { return generate_warhammer_goblins_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-high_elfs",
        {},
        "Generate Warhammer High Elfs style names",
        [](std::mt19937& rng) { return generate_warhammer_high_elfs_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-lizardmens",
        {},
        "Generate Warhammer Lizardmens style names",
        [](std::mt19937& rng) { return generate_warhammer_lizardmens_name(rng); }
    });
    registerGenerator({
        "warhammer-ogres",
        {},
        "Generate Warhammer Ogres style names",
        [](std::mt19937& rng) { return generate_warhammer_ogres_name(rng); }
    });
    registerGenerator({
        "warhammer-orcs",
        {},
        "Generate Warhammer Orcs style names",
        [](std::mt19937& rng) { return generate_warhammer_orcs_name(rng); }
    });
    registerGenerator({
        "warhammer-skavens",
        {},
        "Generate Warhammer Skavens style names",
        [](std::mt19937& rng) { return generate_warhammer_skavens_name(rng); }
    });
    registerGenerator({
        "warhammer-tomb_kings",
        {},
        "Generate Warhammer Tomb Kings style names",
        [](std::mt19937& rng) { return generate_warhammer_tomb_kings_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-vampire_counts",
        {},
        "Generate Warhammer Vampire Counts style names",
        [](std::mt19937& rng) { return generate_warhammer_vampire_counts_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-warriors_of_chaos",
        {},
        "Generate Warhammer Warriors Of Chaos style names",
        [](std::mt19937& rng) { return generate_warhammer_warriors_of_chaos_name(rng, 0); }
    });
    registerGenerator({
        "warhammer-wood_elfs",
        {},
        "Generate Warhammer Wood Elfs style names",
        [](std::mt19937& rng) { return generate_warhammer_wood_elfs_name(rng, 0); }
    });
    registerGenerator({
        "warhammer_40k-chaos",
        {},
        "Generate Warhammer 40K Chaos style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_chaos_name(rng, 0); }
    });
    registerGenerator({
        "warhammer_40k-dark_eldars",
        {},
        "Generate Warhammer 40K Dark Eldars style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_dark_eldars_name(rng, 0); }
    });
    registerGenerator({
        "warhammer_40k-eldars",
        {},
        "Generate Warhammer 40K Eldars style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_eldars_name(rng, 0); }
    });
    registerGenerator({
        "warhammer_40k-necrons",
        {},
        "Generate Warhammer 40K Necrons style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_necrons_name(rng); }
    });
    registerGenerator({
        "warhammer_40k-orks",
        {},
        "Generate Warhammer 40K Orks style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_orks_name(rng); }
    });
    registerGenerator({
        "warhammer_40k-sisters_of_battles",
        {},
        "Generate Warhammer 40K Sisters Of Battles style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_sisters_of_battles_name(rng); }
    });
    registerGenerator({
        "warhammer_40k-space_marines",
        {},
        "Generate Warhammer 40K Space Marines style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_space_marines_name(rng); }
    });
    registerGenerator({
        "warhammer_40k-taus",
        {},
        "Generate Warhammer 40K Taus style names",
        [](std::mt19937& rng) { return generate_warhammer_40k_taus_name(rng); }
    });
    registerGenerator({
        "weapons-battle_axes",
        {},
        "Generate Weapons Battle Axes style names",
        [](std::mt19937& rng) { return generate_weapons_battle_axes_name(rng); }
    });
    registerGenerator({
        "weapons-bomb_missiles",
        {},
        "Generate Weapons Bomb Missiles style names",
        [](std::mt19937& rng) { return generate_weapons_bomb_missiles_name(rng); }
    });
    registerGenerator({
        "weapons-bows",
        {},
        "Generate Weapons Bows style names",
        [](std::mt19937& rng) { return generate_weapons_bows_name(rng); }
    });
    registerGenerator({
        "weapons-claw_weapons",
        {},
        "Generate Claw Weapons style names",
        [](std::mt19937& rng) { return generate_weapons_claw_weapons_name(rng); }
    });
    registerGenerator({
        "weapons-daggers",
        {},
        "Generate Weapons Daggers style names",
        [](std::mt19937& rng) { return generate_weapons_daggers_name(rng); }
    });
    registerGenerator({
        "weapons-dual_wields",
        {},
        "Generate Weapons Dual Wields style names",
        [](std::mt19937& rng) { return generate_weapons_dual_wields_name(rng); }
    });
    registerGenerator({
        "weapons-fist_weapons",
        {},
        "Generate Fist Weapons style names",
        [](std::mt19937& rng) { return generate_weapons_fist_weapons_name(rng); }
    });
    registerGenerator({
        "weapons-flails",
        {},
        "Generate Weapons Flails style names",
        [](std::mt19937& rng) { return generate_weapons_flails_name(rng); }
    });
    registerGenerator({
        "weapons-magic_books",
        {},
        "Generate Weapons Magic Books style names",
        [](std::mt19937& rng) { return generate_weapons_magic_books_name(rng); }
    });
    registerGenerator({
        "weapons-magic_weapons",
        {},
        "Generate Magic Weapons style names",
        [](std::mt19937& rng) { return generate_weapons_magic_weapons_name(rng); }
    });
    registerGenerator({
        "weapons-pistols",
        {},
        "Generate Weapons Pistols style names",
        [](std::mt19937& rng) { return generate_weapons_pistols_name(rng); }
    });
    registerGenerator({
        "weapons-rifles",
        {},
        "Generate Weapons Rifles style names",
        [](std::mt19937& rng) { return generate_weapons_rifles_name(rng); }
    });
    registerGenerator({
        "weapons-sci_fi_guns",
        {},
        "Generate Weapons Sci Fi Guns style names",
        [](std::mt19937& rng) { return generate_weapons_sci_fi_guns_name(rng); }
    });
    registerGenerator({
        "weapons-scythes",
        {},
        "Generate Weapons Scythes style names",
        [](std::mt19937& rng) { return generate_weapons_scythes_name(rng); }
    });
    registerGenerator({
        "weapons-shotguns",
        {},
        "Generate Weapons Shotguns style names",
        [](std::mt19937& rng) { return generate_weapons_shotguns_name(rng); }
    });
    registerGenerator({
        "weapons-spears",
        {},
        "Generate Weapons Spears style names",
        [](std::mt19937& rng) { return generate_weapons_spears_name(rng); }
    });
    registerGenerator({
        "weapons-staffs",
        {},
        "Generate Weapons Staffs style names",
        [](std::mt19937& rng) { return generate_weapons_staffs_name(rng); }
    });
    registerGenerator({
        "weapons-swords",
        {},
        "Generate Weapons Swords style names",
        [](std::mt19937& rng) { return generate_weapons_swords_name(rng); }
    });
    registerGenerator({
        "weapons-throwing_weapons",
        {},
        "Generate Throwing Weapons style names",
        [](std::mt19937& rng) { return generate_weapons_throwing_weapons_name(rng); }
    });
    registerGenerator({
        "weapons-war_hammers",
        {},
        "Generate Weapons War Hammers style names",
        [](std::mt19937& rng) { return generate_weapons_war_hammers_name(rng); }
    });
    registerGenerator({
        "weapons-whips",
        {},
        "Generate Weapons Whips style names",
        [](std::mt19937& rng) { return generate_weapons_whips_name(rng); }
    });
    registerGenerator({
        "wildstar-aurins",
        {},
        "Generate Wildstar Aurins style names",
        [](std::mt19937& rng) { return generate_wildstar_aurins_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-cassians",
        {},
        "Generate Wildstar Cassians style names",
        [](std::mt19937& rng) { return generate_wildstar_cassians_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-chuas",
        {},
        "Generate Wildstar Chuas style names",
        [](std::mt19937& rng) { return generate_wildstar_chuas_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-drakens",
        {},
        "Generate Wildstar Drakens style names",
        [](std::mt19937& rng) { return generate_wildstar_drakens_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-granoks",
        {},
        "Generate Wildstar Granoks style names",
        [](std::mt19937& rng) { return generate_wildstar_granoks_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-humans",
        {},
        "Generate Wildstar Humans style names",
        [](std::mt19937& rng) { return generate_wildstar_humans_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-mecharis",
        {},
        "Generate Wildstar Mecharis style names",
        [](std::mt19937& rng) { return generate_wildstar_mecharis_name(rng, 0); }
    });
    registerGenerator({
        "wildstar-mordeshs",
        {},
        "Generate Wildstar Mordeshs style names",
        [](std::mt19937& rng) { return generate_wildstar_mordeshs_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft-blood_elf",
        {},
        "Generate World Of Warcraft Blood Elf style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_blood_elf_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-draenei",
        {},
        "Generate World Of Warcraft Draenei style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_draenei_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-dwarf",
        {},
        "Generate World Of Warcraft Dwarf style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_dwarf_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-forsaken",
        {},
        "Generate World Of Warcraft Forsaken style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_forsaken_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-gnome",
        {},
        "Generate World Of Warcraft Gnome style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_gnome_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-goblin",
        {},
        "Generate World Of Warcraft Goblin style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_goblin_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-human",
        {},
        "Generate World Of Warcraft Human style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_human_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-night_elf",
        {},
        "Generate World Of Warcraft Night Elf style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_night_elf_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-orc",
        {},
        "Generate World Of Warcraft Orc style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_orc_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-pandaren",
        {},
        "Generate World Of Warcraft Pandaren style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pandaren_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-tauren",
        {},
        "Generate World Of Warcraft Tauren style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_tauren_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-troll",
        {},
        "Generate World Of Warcraft Troll style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_troll_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft-worgen",
        {},
        "Generate World Of Warcraft Worgen style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_worgen_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-bat_dragonhawks",
        {},
        "Generate World Of Warcraft Pets Bat Dragonhawks style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_bat_dragonhawks_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-birds",
        {},
        "Generate World Of Warcraft Pets Birds style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_birds_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft_pets-boars_bears",
        {},
        "Generate World Of Warcraft Pets Boars Bears style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_boars_bears_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-cats",
        {},
        "Generate World Of Warcraft Pets Cats style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_cats_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft_pets-crabs",
        {},
        "Generate World Of Warcraft Pets Crabs style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_crabs_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft_pets-dino_rhinos",
        {},
        "Generate World Of Warcraft Pets Dino Rhinos style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_dino_rhinos_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-dog_wolfs",
        {},
        "Generate World Of Warcraft Pets Dog Wolfs style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_dog_wolfs_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-goat_porcupines",
        {},
        "Generate World Of Warcraft Pets Goat Porcupines style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_goat_porcupines_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-gorilla_monkeys",
        {},
        "Generate World Of Warcraft Pets Gorilla Monkeys style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_gorilla_monkeys_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft_pets-insects",
        {},
        "Generate World Of Warcraft Pets Insects style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_insects_name(rng); }
    });
    registerGenerator({
        "world_of_warcraft_pets-reptiles",
        {},
        "Generate World Of Warcraft Pets Reptiles style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_reptiles_name(rng, 0); }
    });
    registerGenerator({
        "world_of_warcraft_pets-wow_pets",
        {},
        "Generate World Of Warcraft Pets Wow Pets style names",
        [](std::mt19937& rng) { return generate_world_of_warcraft_pets_wow_pets_name(rng, 0); }
    });
}
