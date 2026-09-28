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

#include "generator_registry.h"

namespace fs = std::filesystem;

static constexpr int DEFAULT_TERMINAL_LINES = 24;

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
        str[0] = static_cast<char>(toupper(static_cast<unsigned char>(str[0])));
        for (size_t i = 1; i < str.size(); ++i) {
            str[i] = static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
        }
    }
}

void properCapcasing(std::string& str) {
    if (!str.empty()) {
        str[0] = static_cast<char>(toupper(static_cast<unsigned char>(str[0])));
    }
}

// Debug printer – mirrors the shell script's debugger function
void debugger(const std::string& adjective,
             const std::string& noun,
             const fs::path& adjFile,
             const fs::path& adjFolder,
             const fs::path& nounFile,
             const fs::path& nounFolder,
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
    return adjective + separator + noun;
}

/* Helper: print generated name with debug info */
void printGeneratedName(const std::string& name,
                       size_t currentCount,
                       size_t totalNames,
                       const fs::path& adjFile,
                       const fs::path& adjFolder,
                       const fs::path& nounFile,
                       const fs::path& nounFolder,
                       const std::string& separator) {
    std::string adj;
    std::string noun;
    if (!separator.empty()) {
        std::size_t pos = name.find(separator);
        if (pos != std::string::npos) {
            adj = name.substr(0, pos);
            noun = name.substr(pos + separator.size());
        } else {
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
    const GeneratorInfo* activeGenerator = nullptr;
};

std::string getEnv(const std::string& varName, const std::string& fallback) {
    const char* val = std::getenv(varName.c_str());
    return (val && *val) ? std::string(val) : fallback;
}

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

std::unordered_set<char> createExclusionSet(const std::string& chars) {
    std::unordered_set<char> set;
    for (char c : chars) {
        set.insert(static_cast<char>(tolower(static_cast<unsigned char>(c))));
    }
    return set;
}

std::vector<std::string> filterWords(const std::vector<std::string>& words,
                                    const std::string& excludeChars) {
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
                cleaned += c;
            }
        }
        if (!cleaned.empty()) {
            filtered.push_back(cleaned);
        }
    }

    return filtered;
}

template <typename T>
const T& randomChoice(const std::vector<T>& vec, std::mt19937& rng) {
    return vec[rng() % vec.size()];
}

std::size_t terminalLines() {
    return DEFAULT_TERMINAL_LINES;
}

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
    std::vector<fs::path> files = collectFiles(folder);
    return randomChoice(files, rng);
}

int main(int argc, char* argv[]) {
    CommandLineOptions opts;
    std::mt19937 rng(std::random_device{}());
    std::size_t counto = 0;
    bool optCountSet = false;
    bool optDebug = false;
    bool optCapcasing = false;
    bool optCamelcasing = false;
    const char* optCountArg = nullptr;

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--null-separator" || arg == "-x") {
            opts.nullSeparator = true;
        } else if (arg == "--adj-file" || arg == "--adj" || arg == "-a") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;
            opts.adjFileSet = true;
            opts.adjFile = argv[i];
        } else if (arg == "--noun-file" || arg == "--noun" || arg == "-n") {
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
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./namgen [options]\n\n";
            std::cout << "Options:\n";
            std::cout << "  -a, --adj-file FILE      Path to custom adjectives file\n";
            std::cout << "  -e, --exclude STRING     Characters to strip from generated words\n";
            std::cout << "  -n, --noun FILE          Path to custom noun file\n";
            std::cout << "  -s SEP, --separator SEP  Custom separator string (default: -)\n";
            std::cout << "  -x, --null-separator     Do not print the separator\n";
            std::cout << "  -c COUNT, --count COUNT  Number of names to generate (default: terminal height)\n";
            std::cout << "  --cap, --capcasing       Capitalize first letter of both adjective and noun\n";
            std::cout << "  --camel, --camelcasing   CamelCase style (adjective lower-cased, noun capitalized)\n";
            std::cout << "  --debug                  Enable debug output\n";
            std::cout << "  -h, --help               Show this help message and exit\n\n";
            std::cout << "Specialized Generators:\n";
            for (const auto& gen : GeneratorRegistry::instance().getAll()) {
                std::string flagDisplay = "  --" + gen->flag;
                if (flagDisplay.size() < 38) {
                    flagDisplay.append(38 - flagDisplay.size(), ' ');
                } else {
                    flagDisplay += " ";
                }
                std::cout << flagDisplay << gen->description << "\n";
            }
            return 0;
        } else if (const auto* gen = GeneratorRegistry::instance().find(arg)) {
            opts.activeGenerator = gen;
        } else if (arg.rfind("-", 0) == 0) {
            std::cerr << "Error: unrecognized option '" << arg << "'\n";
            return 1;
        } else {
            std::cerr << "Error: unexpected argument '" << arg << "'\n";
            return 1;
        }
    }

    // Resolve configuration (environment variables with defaults)
    std::string separator;
    if (opts.separatorSet) {
        separator = opts.separator;
    } else {
        separator = getEnv("SEPARATOR", "-");
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
                counto = terminalLines();
            }
        } else {
            counto = terminalLines();
        }
    }

    if (optDebug) {
#if defined(_WIN32) || defined(_WIN64)
        _putenv_s("DEBUG", "true");
#else
        setenv("DEBUG", "true", 1);
#endif
    }

    // If a specialized generator was selected, run it and exit
    if (opts.activeGenerator) {
        for (std::size_t countzero = 0; countzero < counto; ++countzero) {
            std::string name = opts.activeGenerator->generate(rng);
            if (optDebug) {
                printGeneratedName(name, countzero, counto,
                                  fs::path(), fs::path(),
                                  fs::path(), fs::path(),
                                  "");
            } else {
                std::cout << name << "\n";
            }
        }
        return 0;
    }

    // Standard Adjective + Noun generator
    const fs::path here = fs::current_path();
    fs::path assetsFolder = fs::path(
        getEnv("ASSETS_DIR", (here / "assets").string()));

    if (!fs::exists(assetsFolder) && !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path("share/assets");
    }
    if (!fs::exists(assetsFolder) && !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path("/usr/local") / "share" / "namgen" / "assets";
    }

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

    std::string adjective;
    std::string noun;
    bool needCapcasing = capcasing || camelcasing;

    for (std::size_t countzero = 0; countzero < counto; ++countzero) {
        const std::string& rawAdj  = randomChoice(filteredAdjectives, rng);
        const std::string& rawNoun = randomChoice(filteredNouns, rng);

        if (needCapcasing) {
            auto [a, n] = prepareComponents(rawAdj, rawNoun, capcasing, camelcasing);
            adjective = a;
            noun = n;
        } else {
            adjective = rawAdj;
            noun = rawNoun;
        }

        std::string generatedName = generateName(adjective, noun, nullSeparator, separator, camelcasing);
        printGeneratedName(generatedName, countzero, counto, adjFile, adjFolder, nounFile, nounFolder, separator);
    }

    return 0;
}
