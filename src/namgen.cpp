#include <algorithm>
#include <cctype>    
#include <cstddef>   
#include <cstdlib>
#include <unordered_set>  
#include <filesystem>
#include <fstream>
#include <iostream>  
#include <random>
#include <string>
#include <vector>

#include "lord_of_the_rings-elfs_lib.h"
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
#include "dragon_ball-others_lib.h"
#include "dragon_ball-frieza_clans_lib.h"
#include "dragon_ball-hakaishins_lib.h"
#include "dragon_ball-humans_lib.h"
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
#include "fantasy-aliens_lib.h"
#include "fantasy-amazons_lib.h"
#include "fantasy-angels_lib.h"
#include "fantasy-animal_species_lib.h"
#include "fantasy-animatronics_lib.h"
#include "fantasy-apocalypse_mutants_lib.h"
#include "halo-forerunners_lib.h"
#include "military-united_states_lib.h"
#include "military-royal_navy_lib.h"
#include "diablo-angels_lib.h"
#include "warhammer-ogres_lib.h"
#include "doctor_who-silurians_lib.h"
#include "final_fantasy-roegadyns_lib.h"
#include "pets-marine_mammals_lib.h"
#include "rift-bahmis_lib.h"
#include "doctor_who-raxacoricofallapatorians_lib.h"
#include "inheritance_cycle-dragons_lib.h"
#include "pop_culture-homestucks_lib.h"
#include "warhammer_40k-sisters_of_battles_lib.h"
#include "towns_and_cities-ancient_greek_towns_lib.h"
#include "towns_and_cities-dwarven_citys_lib.h"
#include "towns_and_cities-east_european_towns_lib.h"
#include "towns_and_cities-west_european_towns_lib.h"
#include "real-norwegians_lib.h"
#include "rift-eths_lib.h"
#include "halo-mgalekgolos_lib.h"
#include "doctor_who-ice_warriors_lib.h"
#include "warhammer-daemons_of_chaos_lib.h"
#include "elder_scrolls-bosmers_lib.h"
#include "harry_potter-goblins_lib.h"
#include "harry_potter-dragon_species_lib.h"
#include "game_of_thrones-dothrakis_lib.h"

// Add new flag to CommandLineOptions
#include "eve_online-gallentes_lib.h"
#include "star_wars_the_old_republic-cathars_lib.h"
#include "places-plazas_lib.h"
#include "dragon_age-dwarfs_lib.h"
#include "pets-reptiles_lib.h"
#include "wildstar-mordeshs_lib.h"
#include "real-anglo_saxons_lib.h"

using namespace std::filesystem;
namespace fs = std::filesystem;

static constexpr int DEFAULT_TERMINAL_LINES = 24; // Used as fallback when terminal height detection fails

/* Helper: convert string to lower case */
std::string toLower(const std::string& str) {
    std::string result = str;
    for (auto& c : result) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return result;
}

void capitalizeFirst(std::string& str) {
    if (!str.empty()) {
        // Capitalize first letter and make rest lowercase
        str[0] = static_cast<char>(toupper(static_cast<unsigned char>(str[0])));
        for (size_t i = 1; i < str.size(); ++i) {
            str[i] = static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
        }
    }
}

void properCapcasing(std::string& str) {
    if (!str.empty()) {
        // Only capitalize first letter without changing the rest
        str[0] = static_cast<char>(toupper(static_cast<unsigned char>(str[0])));
    }
}

// Debug printer – mirrors the shell script's debugger function
void debugger(const std::string& adjective,
             const std::string& noun,
             const std::filesystem::path& adjFile,
             const std::filesystem::path& adjFolder,
             const std::filesystem::path& nounFile,
             const std::filesystem::path& nounFolder,
             std::size_t countzero,
             std::size_t counto) {
    if (const char* dbg = std::getenv("DEBUG")) {
        if (std::string(dbg) == "true") {
            std::cerr << "DEBUG:\n";
            std::cerr << "  adjective : " << adjective << "\n";
            std::cerr << "  noun      : " << noun << "\n";
            std::cerr << "  ADJ_FILE  : " << adjFile << "\n";
            std::cerr << "  ADJ_FOLDER: " << adjFolder << "\n";
            std::cerr << "  NOUN_FILE : " << nounFile << "\n";
            std::cerr << "  NOUN_FOLDER: " << nounFolder << "\n";
            std::cerr << "  " << countzero << " > " << counto << "\n";
        }
    }
}

/* Prepare components with proper casing */
std::pair<std::string, std::string> prepareComponents(const std::string& rawAdj,
                                                     const std::string& rawNoun,
                                                     bool capcasing,
                                                     bool camelcasing) {
    if (rawAdj.empty() || rawNoun.empty()) {
        throw std::invalid_argument("Input strings must not be empty");
    }
    std::string adjective = rawAdj;
    std::string noun = toLower(rawNoun);

    if (capcasing) {
        capitalizeFirst(adjective);
        capitalizeFirst(noun);
    } else if (camelcasing) {
        // Keep adjective lowercase and only capitalize first letter of noun
        for (auto& c : adjective) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        properCapcasing(noun);
    }

    return {adjective, noun};
}

/* Helper: generate a single name combination */
std::string generateName(const std::string& adjective,
                        const std::string& noun,
                        bool nullSeparator,
                        const std::string& separator,
                        bool camelcasing) {
    if (nullSeparator || separator.empty()) {
        return (camelcasing ? toLower(adjective) : adjective) + noun;
    }

    // When using both separator and camel casing:
    // - Keep adjective as‑as from prepareComponents
    // - Only apply separator without forcing lower case
    return adjective + separator + noun;
}

/* Helper: print generated name with debug info */
void printGeneratedName(const std::string& name,
                       size_t currentCount,
                       size_t totalNames,
                       const std::filesystem::path& adjFile,
                       const std::filesystem::path& adjFolder,
                       const std::filesystem::path& nounFile,
                       const std::filesystem::path& nounFolder,
                       const std::string& separator) {
    // Extract original components for debugging using provided separator.
    // If no separator is used (empty string), we cannot reliably split the name,
    // so we pass the whole name as the adjective and leave noun empty.
    std::string adj;
    std::string noun;
    if (!separator.empty()) {
        std::size_t pos = name.find(separator);
        if (pos != std::string::npos) {
            adj = name.substr(0, pos);
            noun = name.substr(pos + separator.size());
        } else {
            // Separator not found – fallback to whole name as adjective.
            adj = name;
            noun.clear();
        }
    } else {
        adj = name;
        noun.clear();
    }

    debugger(adj, noun, adjFile, adjFolder, nounFile, nounFolder,
             currentCount, totalNames);
    std::cout << name << "\n";
}

struct CommandLineOptions {
    std::string adjFile;
    bool adjFileSet = false;
    std::string nounFile;
    bool nounFileSet = false;
    bool nullSeparator = false;
    bool separatorSet = false;
    std::string separator;
    std::string excludeChars;
    bool excludeSet = true;
    size_t count = 0;
    bool countSet = false;
    bool debug = false;
    bool capcasing = false;
    bool camelcasing = false;
    bool elfFlag = false;
    bool haloForerunners = false;
    bool fantasyAnimatronics = false;
    bool destinyAwokens = false;
    bool destinyCabals = false;
    bool destinyExos = false;
    bool destinyFallens = false;
    bool destinyHives = false;
    bool destinyHumans = false;
    bool destinyVexs = false;
    bool diabloAngels = false;
    bool diabloDemons = false;
    bool diabloKhazras = false;
    bool diabloNephalems = false;
    bool dragonBallOthers = false;
    bool dragonBallFriezaClans = false;
    bool dragonBallHakaishins = false;
    bool dragonBallHumans = false;
    bool dragonBallSaiyans = false;
    bool dragonBallSkians = false;
    bool dragonBallTuffles = false;
    bool dungeonAndDragonsDevas = false;
    bool dungeonAndDragonsDragonborns = false;
    bool dungeonAndDragonsDrows = false;
    bool dungeonAndDragonsDwarfs = false;
    bool dungeonAndDragonsEladrins = false;
    bool dungeonAndDragonsElfs = false;
    bool dungeonAndDragonsGithzerais = false;
    bool fantasyAliens = false;
    bool fantasyAmazons = false;
    bool fantasyAngels = false;
    bool fantasyAnimalSpecies = false;
    bool fantasyApocalypseMutants = false;
    bool militaryUnitedStates = false;
    bool warhammerOgres = false;
    bool doctor_who_silurians = false;
    bool townsAndCitiesAncientGreekTowns = false;
    bool townsAndCitiesEastEuropeanTowns = false;
    bool townsAndCitiesWestEuropeanTowns = false;
    bool finalFantasyRoegadyns = false;
    bool petsMarineMammals = false;
    bool riftBahmis = false;
    bool riftEths = false;
    bool doctor_who_raxacoricofallapatorians = false;
    bool inheritanceCycleDragons = false;
    bool popCultureHomestucks = false;
    bool warhammer40kSistersOfBattles = false;
    bool realNorwegians = false;
    bool haloMgalekgolos = false;
    bool doctor_who_ice_warriors = false;
    bool warhammerDaemonsOfChaos = false;
    bool elderScrollsBosmers = false;
    bool harryPotterGoblins = false;
    bool eveOnlineGallentes = false;
    bool starWarsTheOldRepublicCathars = false;
    bool militaryRoyalNavy = false;
    bool placesPlazas = false;
    bool dragonAgeDwarfs = false;
    bool petsReptiles = false;
    bool wildstarMordeshs = false;
    bool townsAndCitiesDwarvenCitys = false;
    bool realAngloSaxons = false;
    bool harryPotterDragonSpecies = false;
    bool gameOfThronesDothrakis = false;
};

/* Helper: get environment variable or fallback */
std::string getEnv(const std::string& var, const std::string& fallback) {
    const char* val = std::getenv(var.c_str());
    return (val && *val) ? std::string(val) : fallback;
}

/* Helper: read all non‑empty lines from a file */
std::vector<std::string> readLines(const fs::path& filePath) {
    std::vector<std::string> lines;
    std::ifstream in(filePath);
    if (!in) {
        std::cerr << "Error: cannot open file " << filePath << "\n";
        std::exit(1);
    }
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty())
            lines.push_back(line);
    }
    return lines;
}

/* Helper: recursively collect all regular files under a directory */
std::vector<fs::path> collectFiles(const fs::path& folder) {
    std::vector<fs::path> files;
    if (!fs::exists(folder) || !fs::is_directory(folder)) {
        std::cerr << "Error: folder does not exist or is not a directory: " << folder << "\n";
        std::exit(1);
    }
    for (auto const& entry : fs::recursive_directory_iterator(folder)) {
        if (fs::is_regular_file(entry.path())) {
            files.push_back(entry.path());
        }
    }
    if (files.empty()) {
        std::cerr << "Error: no regular files found in folder " << folder << "\n";
        std::exit(1);
    }
    return files;
}

/* Create a set of characters to exclude from words */
std::unordered_set<char> createExclusionSet(const std::string& chars) {
    std::unordered_set<char> set;
    for (char c : chars) {
        set.insert(static_cast<char>(tolower(static_cast<unsigned char>(c))));
    }
    return set;
}

/* Remove excluded characters from words */
std::vector<std::string> filterWords(const std::vector<std::string>& words,
                                    const std::string& excludeChars) {
    // Initialize excluded character set with proper handling of apostrophes and case sensitivity
    std::unordered_set<char> excluded;
    if (!excludeChars.empty()) {
        excluded = createExclusionSet(excludeChars);
    } else {
        excluded.insert('\'');
        excluded.insert('-');
    }
    std::vector<std::string> filtered;

    for (const auto& word : words) {
        std::string cleaned;
        for (char c : word) {
            if (!excluded.count(static_cast<char>(tolower(static_cast<unsigned char>(c))))) {
                cleaned += c; // Preserve original case
            }
        }
        if (!cleaned.empty()) {
            filtered.push_back(cleaned);
        }
    }

    return filtered;
}

/* Helper: pick a random element from a vector using the supplied RNG */
template <typename T>
const T& randomChoice(const std::vector<T>& vec, std::mt19937& rng) {
    return vec[rng() % vec.size()];
}

/* Determine terminal height – fallback to 24 if we can't query it */
std::size_t terminalLines() {
    // Default to configurable value if we can't determine terminal size
    return DEFAULT_TERMINAL_LINES;
}

/* Resolve a file path from an environment variable, falling back to a random file in a folder */
fs::path resolveFile(const std::string& envVar,
                     const fs::path& folder,
                     std::mt19937& rng) {
    std::string envPath = getEnv(envVar, "");
    if (!envPath.empty()) {
        fs::path p = fs::absolute(envPath);
        if (!fs::exists(p) || !fs::is_regular_file(p)) {
            std::cerr << "Error: environment variable " << envVar
                      << " points to a non‑regular file: " << p << "\n";
            std::exit(1);
        }
        return p;
    }
    // No env var – pick a random file from the folder
    std::vector<fs::path> files = collectFiles(folder);
    return randomChoice(files, rng);
}

int main(int argc, char* argv[]) {
    // Directly construct the options struct; parsing is done manually below.
    CommandLineOptions opts;
    std::mt19937 rng(std::random_device{}());
    std::size_t counto = 0;                 // final number of names to generate
    bool optCountSet = false;               // true if user supplied --count / -c
    bool optDebug = false;                  // true if user passed --debug
    bool optCapcasing = false;              // true if user passed --capcasing
    bool optCamelcasing = false;            // true if user passed --camelcasing
    const char* optCountArg = nullptr;      // raw argument string (for error messages)

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--null-separator" || arg == "-x") {
            opts.nullSeparator = true;
        } else if (arg == "--adj-file" || arg == "-a") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;
            opts.adjFileSet = true;
            opts.adjFile = argv[i];
        } else if (arg == "--noun-file" || arg == "-n") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;
            opts.nounFileSet = true;
            opts.nounFile = argv[i];
        } else if (arg == "--separator" || arg == "-s") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;
            opts.separatorSet = true;
            opts.separator = argv[i];
        } else if (arg == "--count" || arg == "-c") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires a numeric argument.\n";
                return 1;
            }
            ++i;
            optCountArg = argv[i];
            try {
                counto = static_cast<std::size_t>(std::stoul(optCountArg));
                if (counto == 0) {
                    throw std::invalid_argument("Count must be >0");
                }
                optCountSet = true;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid count value '" << optCountArg
                          << "'. Must be a positive integer.\n";
                return 1;
            }
        } else if (arg == "--cap" || arg == "--capcasing") {
            optCapcasing = true;
        } else if (arg == "--exclude" || arg == "-e") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --exclude requires an argument.\n";
                return 1;
            }
            ++i;
            opts.excludeSet = true;
            opts.excludeChars = argv[i];
        } else if (arg == "--camel" || arg == "--camelcasing") {
            optCamelcasing = true;
        } else if (arg == "--debug") {
            optDebug = true;
        } else if (arg == "--elf"|| arg == "--lotr-elf"|| arg == "--lord_of_the_rings-elfs") {
            opts.elfFlag = true;
        } else if (arg == "--halo-forerunners") {
            opts.haloForerunners = true;
        } else if (arg == "--halo-mgalekgolos") {               // <-- new flag handling
            opts.haloMgalekgolos = true;
        } else if (arg == "--warhammer-daemons_of_chaos") {    // <-- new flag handling
            opts.warhammerDaemonsOfChaos = true;
        } else if (arg == "--fantasy-animatronics") {
            opts.fantasyAnimatronics = true;
        } else if (arg == "--destiny-awokens") {
            opts.destinyAwokens = true;
        } else if (arg == "--destiny-cabals") {
            opts.destinyCabals = true;
        } else if (arg == "--destiny-exos") {
            opts.destinyExos = true;
        } else if (arg == "--destiny-fallens") {
            opts.destinyFallens = true;
        } else if (arg == "--destiny-hives") {
            opts.destinyHives = true;
        } else if (arg == "--destiny-humans") {
            opts.destinyHumans = true;
        } else if (arg == "--destiny-vexs") {
            opts.destinyVexs = true;
        } else if (arg == "--diablo-angels") {
            opts.diabloAngels = true;
        } else if (arg == "--diablo-demons") {
            opts.diabloDemons = true;
        } else if (arg == "--diablo-khazras") {
            opts.diabloKhazras = true;
        } else if (arg == "--diablo-nephalems") {
            opts.diabloNephalems = true;
        } else if (arg == "--dragon_ball-others") {
            opts.dragonBallOthers = true;
        } else if (arg == "--dragon_ball-frieza_clans") {
            opts.dragonBallFriezaClans = true;
        } else if (arg == "--dragon_ball-hakaishins") {
            opts.dragonBallHakaishins = true;
        } else if (arg == "--dragon_ball-humans") {
            opts.dragonBallHumans = true;
        } else if (arg == "--dragon_ball-saiyans") {
            opts.dragonBallSaiyans = true;
        } else if (arg == "--dragon_ball-skians") {
            opts.dragonBallSkians = true;
        } else if (arg == "--dragon_ball-tuffles") {
            opts.dragonBallTuffles = true;
        } else if (arg == "--dungeon_and_dragons-devas") {
            opts.dungeonAndDragonsDevas = true;
        } else if (arg == "--dungeon_and_dragons-dragonborns") {
            opts.dungeonAndDragonsDragonborns = true;
        } else if (arg == "--dungeon_and_dragons-drows") {
            opts.dungeonAndDragonsDrows = true;
        } else if (arg == "--dungeon_and_dragons-dwarfs") {
            opts.dungeonAndDragonsDwarfs = true;
        } else if (arg == "--dungeon_and_dragons-eladrins") {
            opts.dungeonAndDragonsEladrins = true;
        } else if (arg == "--dungeon_and_dragons-elfs") {
            opts.dungeonAndDragonsElfs = true;
        } else if (arg == "--dungeon_and_dragons-githzerais") {
            opts.dungeonAndDragonsGithzerais = true;
        } else if (arg == "--fantasy-aliens") {
            opts.fantasyAliens = true;
        } else if (arg == "--fantasy-amazons") {
            opts.fantasyAmazons = true;
        } else if (arg == "--fantasy-angels") {
            opts.fantasyAngels = true;
        } else if (arg == "--fantasy-animal_species") {
            opts.fantasyAnimalSpecies = true;
        } else if (arg == "--fantasy-apocalypse_mutants") {
            opts.fantasyApocalypseMutants = true;
        } else if (arg == "--places-plazas") {
            opts.placesPlazas = true;
        } else if (arg == "--military-united_states") {
            opts.militaryUnitedStates = true;
        } else if (arg == "--warhammer-ogres") {
            opts.warhammerOgres = true;
        } else if (arg == "--doctor_who-silurians") {
            opts.doctor_who_silurians = true;
        } else if (arg == "--towns_and_cities-ancient_greek_towns") {
            opts.townsAndCitiesAncientGreekTowns = true;
        } else if (arg == "--towns_and_cities-west_european_towns") {
            opts.townsAndCitiesWestEuropeanTowns = true;
        } else if (arg == "--final_fantasy-roegadyns") {
            opts.finalFantasyRoegadyns = true;
        } else if (arg == "--pets-marine_mammals") {
            opts.petsMarineMammals = true;
        } else if (arg == "--rift-bahmis") {
            opts.riftBahmis = true;
        } else if (arg == "--rift-eths") {
            opts.riftEths = true;
        } else if (arg == "--doctor_who-raxacoricofallapatorians") {
            opts.doctor_who_raxacoricofallapatorians = true;
        } else if (arg == "--doctor_who-ice_warriors") {
            opts.doctor_who_ice_warriors = true;
        } else if (arg == "--inheritance_cycle-dragons") {
            opts.inheritanceCycleDragons = true;
        } else if (arg == "--pop_culture-homestucks") {
            opts.popCultureHomestucks = true;
        } else if (arg == "--warhammer_40k-sisters_of_battles") {
            opts.warhammer40kSistersOfBattles = true;
        } else if (arg == "--towns_and_cities-east_european_towns") {
            opts.townsAndCitiesEastEuropeanTowns = true;
        } else if (arg == "--real-norwegians") {
            opts.realNorwegians = true;
        } else if (arg == "--elder_scrolls-bosmers") {
            opts.elderScrollsBosmers = true;
        } else if (arg == "--harry_potter-goblins") {
            opts.harryPotterGoblins = true;
        } else if (arg == "--eve_online-gallentes") {
            opts.eveOnlineGallentes = true;
        } else if (arg == "--star_wars_the_old_republic-cathars") {
            opts.starWarsTheOldRepublicCathars = true;
        } else if (arg == "--military-royal_navy") {
            opts.militaryRoyalNavy = true;
        } else if (arg == "--dragon_age-dwarfs") {
            opts.dragonAgeDwarfs = true;
        } else if (arg == "--pets-reptiles") {
            opts.petsReptiles = true;
        } else if (arg == "--wildstar-mordeshs") {
            opts.wildstarMordeshs = true;
        } else if (arg == "--towns_and_cities-dwarven_citys") {
            opts.townsAndCitiesDwarvenCitys = true;
        } else if (arg == "--real-anglo_saxons") {
            opts.realAngloSaxons = true;
        } else if (arg == "--harry_potter-dragon_species") {
            opts.harryPotterDragonSpecies = true;
        } else if (arg == "--game_of_thrones-dothrakis") {
            opts.gameOfThronesDothrakis = true;
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./namgen [options]\\n\\n";
            std::cout << "Options:\\n";
            std::cout << "  -a, --adj-file FILE      Path to custom adjectives file\\n";
            std::cout << "  -e, --exclude STRING     Characters to strip from generated words\\n";
            std::cout << "  -n, --noun FILE          Path to custom noun file\\n";
            std::cout << "  -s SEP, --separator SEP  Custom separator string (default: -)\\n";
            std::cout << "  -x, --null-separator     Do not print the separator\\n";
            std::cout << "  -c COUNT, --count COUNT  Number of names to generate (default: terminal height)\\n";
            std::cout << "  --cap --capcasing        Capitalize first letter of both adjective and noun\\n";
            std::cout << "  --camel --camelcasing    CamelCase style (adjective lower‑cased, noun capitalized)\\n";
            std::cout << "  --debug                  Enable debug output\\n";
            std::cout << "  --destiny-awokens        Generate fantasy‑destiny awoken style names\\n";
            std::cout << "  --destiny-cabals         Generate fantasy‑destiny cabals style names\\n";
            std::cout << "  --destiny-exos           Generate fantasy‑destiny exos style names\\n";
            std::cout << "  --destiny-fallens        Generate fantasy‑destiny fallens style names\\n";
            std::cout << "  --destiny-hives          Generate fantasy‑destiny hives style names\\n";
            std::cout << "  --destiny-humans         Generate fantasy‑destiny humans style names\\n";
            std::cout << "  --destiny-vexs           Generate fantasy‑destiny vexs style names\\n";
            std::cout << "  --diablo-angels          Generate Diablo angels style names\\n";
            std::cout << "  --diablo-demons          Generate Diablo demons style names\\n";
            std::cout << "  --diablo-khazras         Generate Diablo khazras style names\\n";
            std::cout << "  --diablo-nephalems       Generate Diablo nephalems style names\\n";
            std::cout << "  --doctor_who-silurians   Generate Doctor Who Silurians style names\\n";
            std::cout << "  --doctor_who_raxacoricofallapatorians Generate a Rift‑Bahmis name (uses built‑in generator)\\n";
            std::cout << "  --dragon_age-dwarfs      Generate Dragon Age dwarf names (legacy JS generator)\\n";
            std::cout << "  --dragon_ball-others     Generate Dragon Ball “other …” style names\\n";
            std::cout << "  --dragon_ball-frieza_clans Generate Dragon Ball Frieza Clans names\\n";
            std::cout << "  --dragon_ball-hakaishins Generate Dragon Ball Hakaishins names\\n";
            std::cout << "  --dragon_ball-humans     Generate Dragon Ball human names (male/female)\\n";
            std::cout << "  --dragon_ball-saiyans    Generate Dragon Ball Saiyan names\\n";
            std::cout << "  --dragon_ball-skians     Generate Dragon Ball Skians names\\n";
            std::cout << "  --dragon_ball-tuffles    Generate Dragon Ball Tuffles names\\n";
            std::cout << "  --dungeon_and_dragons-devas Generate Dungeons & Dragons “devas” names\\n";
            std::cout << "  --dungeon_and_dragons-dragonborns Generate Dungeons & Dragons “dragonborns” names\\n";
            std::cout << "  --dungeon_and_dragons-drows Generate Dungeons & Dragons “drows” names\\n";
            std::cout << "  --dungeon_and_dragons-dwarfs Generate Dungeons & Dragons “dwarfs” names\\n";
            std::cout << "  --dungeon_and_dragons-eladrins Generate Dungeons & Dragons “eladrins” names\\n";
            std::cout << "  --dungeon_and_dragons-elfs Generate Dungeons & Dragons “elfs” names\\n";
            std::cout << "  --dungeon_and_dragons-githzerais Generate Dungeons & Dragons “githzerais” names\\n";
            std::cout << "  --elf                    Generate fantasy‑elf style names (uses built‑in generator)\\n";
            std::cout << "  --elder_scrolls-bosmers  Generate Elder Scrolls Bosmer style names (uses built‑in generator)\\n";
            std::cout << "  --eve_online-gallentes   Generate Gallentes style names (uses built‑in generator)\\n";
            std::cout << "  --fantasy-aliens         Generate fantasy “aliens” names\\n";
            std::cout << "  --fantasy-amazons        Generate fantasy “amazons” names\\n";
            std::cout << "  --fantasy-angels         Generate fantasy “angels” names\\n";
            std::cout << "  --fantasy-animal_species Generate fantasy “animal species” names\\n";
            std::cout << "  --fantasy-animatronics   Generate fantasy “animatronics” style names (ignores adjective/noun files)\\n";
            std::cout << "  --game_of_thrones-dothrakis   Generate Dothrakis style names\\n";
            std::cout << "  --halo-forerunners       Generate Halo “forerunners” style names (ignores adjective/noun files)\\n";
            std::cout << "  --halo-mgalekgolos       Generate Halo “Mgalekgolos” style names (uses built‑in generator)\\n";
            std::cout << "  --harry_potter-goblins   Generate Harry Potter “Goblins” style names (uses built‑in generator)\\n";
            std::cout << "  --harry_potter-dragon_species Generate harry_potter-dragon_species style names\n";
            std::cout << "  --inheritance_cycle-dragons Generate inheritance‑cycle dragons names\\n";
            std::cout << "  --military-united_states Generate United States military call‑sign style names (two random NATO phonetic alphabet words)\\n";
            std::cout << "  --military-royal_navy    Generate Royal Navy military call‑sign style names \\n";
            std::cout << "  --pets-marine_mammals    Generate a marine‑mammal name (uses built‑in marine‑mammal generator)\\n";
            std::cout << "  --pets-reptiles          Generate reptile pet names (legacy JS generator)\\n";
            std::cout << "  --rift-bahmis            Generate a Rift‑Bahmis name (uses built‑in generator)\\n";
            std::cout << "  --star_wars_the_old_republic-cathars   Generate Cathars style names (uses built‑in generator)\\n";
            std::cout << "  --towns_and_cities-dwarven_citys  Generate dwarven city names (towns_and_cities‑dwarven_citys)\\n";
            std::cout << "  --towns_and_cities-east_european_towns Generate East European Towns and Cities\\n";
            std::cout << "  --warhammer-daemons_of_chaos  Generate Warhammer “Daemons of Chaos” style names (uses built‑in generator)\\n";
            std::cout << "  --warhammer_40k-sisters_of_battles Generate Warhammer 40k Sisters of Battles names\\n";
            std::cout << "  --wildstar-mordeshs Generate Wildstar Mordeshs names\\n";
            std::cout << "  --real-anglo_saxons      Generate real Anglo-Saxon names (male and female)\\n"; // New help entry
            std::cout << "  --help, -h               Show this help message and exit\\n";
            return 0;
        } else if (arg.rfind("-", 0) == 0) {
            // Unrecognized option starting with '-'
            std::cerr << "Error: unrecognized option '" << arg << "'\n";
            return 1;
        } else {
            // Positional arguments are not supported; treat as error
            std::cerr << "Error: unexpected argument '" << arg << "'\n";
            return 1;
        }
    }

    // Resolve configuration (environment variables with defaults)
    std::string separator;
    if (opts.separatorSet) {
        separator = opts.separator;
    } else {
        separator = getEnv("SEPARATOR", "-"); // fall back to env / default
    }
    const std::string nullSeparatorEnv = getEnv("NULL_SEPARATOR", "false");
    const bool nullSeparator = (nullSeparatorEnv == "true") || opts.nullSeparator;
    const std::string capcasingEnv = getEnv("CAPCASING", "false");
    const bool capcasing = optCapcasing || (capcasingEnv == "true");
    const std::string camelcasingEnv = getEnv("CAMELCASING", "false");
    const bool camelcasing = optCamelcasing || (camelcasingEnv == "true");

    // Resolve count (number of names to generate)
    if (!optCountSet) {
        const std::string countoEnv = getEnv("counto", "");
        if (!countoEnv.empty()) {
            try {
                counto = static_cast<std::size_t>(std::stoul(countoEnv));
            } catch (...) {
                counto = terminalLines(); // fallback on parse error
            }
        } else {
            counto = terminalLines(); // default when no env var
        }
    }

    /* Apply --debug flag by setting the DEBUG environment variable */
    if (optDebug) {
#if defined(_WIN32) || defined(_WIN64)
        _putenv_s("DEBUG", "true");
#else
        setenv("DEBUG", "true", 1);
#endif
    }

    // ------ Locate the installed assets directory.
    const fs::path here = fs::current_path();

    // Primary assets location (env or ./assets)
    fs::path assetsFolder = fs::path(
        getEnv("ASSETS_DIR", (here / "assets").string()));

    // 1️⃣  If that does not exist...
    if (!fs::exists(assetsFolder) && !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path("share/assets");
    }

    // 2️⃣  If still not found...
    if (!fs::exists(assetsFolder) && !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path("/usr/local") / "share" / "namgen" / "assets";
    }

    // Resolve ... (unchanged code for adjective/noun handling)
    fs::path nounFolder = fs::path(
        getEnv("NOUN_FOLDER", (assetsFolder / "nouns").string()));
    if (!fs::exists(nounFolder) && !fs::is_directory(nounFolder)) {
        std::cerr << "Error: noun folder not found!\n";
        nounFolder = assetsFolder / "nouns";
    }

    fs::path adjFolder = fs::path(
        getEnv("ADJ_FOLDER", (assetsFolder / "adjectives").string()));
    if (!fs::exists(adjFolder) && !fs::is_directory(adjFolder)) {
        std::cerr << "Error: adj folder not found!\n";
        adjFolder = assetsFolder / "adjectives";
    }

    // Resolve the actual files, respecting NOUN_FILE / ADJ_FILE env vars
    fs::path adjFile;
    if (opts.adjFileSet) {
        adjFile = fs::absolute(opts.adjFile);
        if (!fs::exists(adjFile) || !fs::is_regular_file(adjFile)) {
            std::cerr << "Error: --adj-file points to a non‑regular file: " << adjFile << "\n";
            return 1;
        }
    } else {
        adjFile = resolveFile("ADJ_FILE", adjFolder, rng);
    }

    fs::path nounFile;
    if (opts.nounFileSet) {
        nounFile = fs::absolute(opts.nounFile);
        if (!fs::exists(nounFile) || !fs::is_regular_file(nounFile)) {
            std::cerr << "Error: --noun-file points to a non‑regular file: \n";
            return 1;
        }
    } else {
        nounFile = resolveFile("NOUN_FILE", nounFolder, rng);
    }

    const std::vector<std::string> nounLines = readLines(nounFile);
    const std::vector<std::string> adjLines  = readLines(adjFile);

    if (nounLines.empty() || adjLines.empty()) {
        std::cerr << "Error: Selected ...\n";
        return 1;
    }

    // Pre‑filter the words once outside the loop
    std::vector<std::string> filteredNouns = nounLines;
    std::vector<std::string> filteredAdjectives = adjLines;

    if (opts.excludeSet) {
        filteredNouns = filterWords(nounLines, opts.excludeChars);
        filteredAdjectives = filterWords(adjLines, opts.excludeChars);

        if (filteredNouns.empty() || filteredAdjectives.empty()) {
            std::cerr << "Error: No valid ...\n";
            return 1;
        }
    }

    // Variables to hold the current adjective and noun after optional casing
    std::string adjective;
    std::string noun;
    bool needCapcasing = capcasing || camelcasing;

    // ------ Main generation loop ------
    for (std::size_t countzero = 0; countzero < counto; ++countzero) {
        if (opts.harryPotterDragonSpecies) {
            std::string dragonName = generate_harry_potter_dragon_species_name(rng);
            if (optDebug) {
                printGeneratedName(dragonName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << dragonName << "\n";
            }
            continue;
        }

        if (opts.realAngloSaxons) { // New Anglo-Saxon names handling
            std::string angloSaxonName = generate_real_anglo_saxons_name(rng);
            if (optDebug) {
                printGeneratedName(angloSaxonName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << angloSaxonName << "\n";
            }
            continue;
        }

        if (opts.destinyAwokens) {
            std::string awokenName = generate_destiny_awoken_name(rng, 0);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << awokenName << "\n";
            continue;
        }

        if (opts.destinyCabals) {
            std::string cabalName = generate_destiny_cabals_name(rng);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << cabalName << "\n";
            continue;
        }

        if (opts.destinyExos) {
            std::string exosName = generate_destiny_exos_name(rng);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << exosName << "\n";
            continue;
        }

        if (opts.destinyFallens) {
            std::string fallensName = generate_destiny_fallens_name(rng);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << fallensName << "\n";
            continue;
        }

        if (opts.destinyHives) {
            std::string hivesName = generate_destiny_hives_name(rng, 0);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << hivesName << "\n";
            continue;
        }

        if (opts.destinyHumans) {
            std::string humansName = generate_destiny_humans_name(rng, 0);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << humansName << "\n";
            continue;
        }

        if (opts.destinyVexs) {
            std::string vexsName = generate_destiny_vexs_name(rng);
            if (optDebug) {
                debugger("", "", fs::path(), fs::path(), fs::path(), fs::path(),
                         countzero, counto);
            }
            std::cout << vexsName << "\n";
            continue;
        }

        if (opts.elfFlag) {
            // ELF mode – ignore adjective/noun files.
            std::string elfName = generate_lotr_elf_name(1);
            if (optDebug) {
                // For ELF mode we don't have adj/… files, so pass
                printGeneratedName(elfName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << elfName << "\n";
            }
            continue;
        }

        if (opts.haloForerunners) {
            // Halo Forerunners mode – ignore adjective/noun files.
            std::string haloName = generate_halo_forerunners_name(rng);
            if (optDebug) {
                printGeneratedName(haloName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << haloName << "\n";
            }
            continue;
        }

        if (opts.haloMgalekgolos) {                     // <-- new handling block
            std::string haloMgalekgolosName = generate_halo_mgalekgolos_name(rng);
            if (optDebug) {
                printGeneratedName(haloMgalekgolosName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << haloMgalekgolosName << "\n";
            }
            continue;
        }

        if (opts.warhammerDaemonsOfChaos) {               // <-- new handling block
            std::string chaosName = generate_warhammer_daemons_of_chaos_name(rng);
            if (optDebug) {
                printGeneratedName(chaosName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << chaosName << "\n";
            }
            continue;
        }

        if (opts.fantasyAnimatronics) {
            std::string animName = generate_fantasy_animatronics_name(rng, 0);
            if (optDebug) {
                // No adjective/… (same as above)
                printGeneratedName(animName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << animName << "\n";
            }
            continue;
        }

        if (opts.doctor_who_raxacoricofallapatorians) {
            // Doctor Who Raxacoricofallapatorians mode – ignore adjective/noun files.
            std::string raxName = generate_doctor_who_raxacoricofallapatorians_name(rng);
            if (optDebug) {
                printGeneratedName(raxName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << raxName << "\n";
            }
            continue;
        }

        if (opts.doctor_who_ice_warriors) {
            // Doctor Who Ice Warriors mode – ignore adjective/noun files.
            std::string iceName = generate_doctor_who_ice_warriors_name(rng);
            if (optDebug) {
                printGeneratedName(iceName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << iceName << "\n";
            }
            continue;
        }

        if (opts.elderScrollsBosmers) {
            // Elder Scrolls Bosmers mode – ignore adjective/noun files.
            std::string bosmerName = generate_elder_scrolls_bosmers_name(rng);
            if (optDebug) {
                printGeneratedName(bosmerName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << bosmerName << "\n";
            }
            continue;
        }

        if (opts.harryPotterGoblins) {
            std::string goblinName = generate_harry_potter_goblins_name(rng);
            if (optDebug) {
                printGeneratedName(goblinName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << goblinName << "\n";
            }
            continue;
        }

        if (opts.eveOnlineGallentes) {
            std::string goblinName = generate_eve_online_gallentes_name(rng);
            if (optDebug) {
                printGeneratedName(goblinName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << goblinName << "\n";
            }
            continue;
        }

        if (opts.starWarsTheOldRepublicCathars) {
            std::string goblinName = generate_star_wars_the_old_republic_cathars_name(rng);
            if (optDebug) {
                printGeneratedName(goblinName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << goblinName << "\n";
            }
            continue;
        }

        if (opts.militaryRoyalNavy) {
            std::string militaryRoyalNavyName = generate_military_royal_navy_name(rng);
            if (optDebug) {
                printGeneratedName(militaryRoyalNavyName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << militaryRoyalNavyName << "\n";
            }
            continue;
        }

        if (opts.militaryUnitedStates) {
            std::string militaryUnitedStatesName = generate_military_united_states_name(rng);
            if (optDebug) {
                printGeneratedName(militaryUnitedStatesName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << militaryUnitedStatesName << "\n";
            }
            continue;
        }

        if (opts.townsAndCitiesWestEuropeanTowns) {
            std::string townName = generate_west_european_town_name(rng);
            if (optDebug) {
                printGeneratedName(townName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << townName << "\n";
            }
            continue;
        }

        if (opts.placesPlazas) {
            std::string townName = generate_west_european_town_name(rng);
            if (optDebug) {
                printGeneratedName(townName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << townName << "\n";
            }
            continue;
        }

        if (opts.dragonAgeDwarfs) {
            std::string dwarfName = generate_dragon_age_dwarfs_name(rng);
            if (optDebug) {
                // No adjective/noun files involved, so we pass empty paths.
                printGeneratedName(dwarfName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << dwarfName << "\n";
            }
            continue;
        }

        if (opts.petsReptiles) {
            std::string petName = generate_pets_reptiles_name(rng, 0);
            if (optDebug) {
                printGeneratedName(petName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << petName << "\n";
            }
            continue;
        }

        if (opts.wildstarMordeshs) {
            std::string wsName = generate_wildstar_mordeshs_name(rng);
            if (optDebug) {
                printGeneratedName(wsName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << wsName << "\n";
            }
            continue;
        }

        if (opts.townsAndCitiesDwarvenCitys) {
            std::string dwarfName = generate_towns_and_cities_dwarven_citys_name(rng);
            if (optDebug) {
                printGeneratedName(dwarfName, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  ""); // no separator
            } else {
                std::cout << dwarfName << "\n";
            }
            continue;
        }

        // Default adjective + noun generation
        uint64_t randChoice = rng();
        const auto& randAdj = randomChoice(filteredAdjectives, rng);
        const auto& randNoun = randomChoice(filteredNouns, rng);

        std::string chosenAdj = randAdj;
        std::string chosenNoun = randNoun;

        // Apply casing if needed
        auto [adjCased, nounCased] = prepareComponents(chosenAdj, chosenNoun, capcasing, camelcasing);
        std::string finalName = generateName(adjCased, nounCased, nullSeparator, separator, camelcasing);

        if (optDebug) {
            printGeneratedName(finalName, countzero, counto,
                              adjFile, adjFolder,
                              nounFile, nounFolder,
                              separator);
        } else {
            std::cout << finalName << "\n";
        }
    }

    return 0;
}
