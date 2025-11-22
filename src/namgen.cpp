#include <algorithm>
#include <cctype>    // for tolower
#include <cstddef>  // for std::size_t
#include <cstdlib>
#include <unordered_set>  // for excluded characters set
#include <filesystem>
#include <fstream>
#include <iostream>  // for std::cerr
#include <random>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
#include <sys/system.h>
#endif
#include <vector>

using namespace std::filesystem;


static constexpr int DEFAULT_TERMINAL_LINES = 24; // Used as fallback when terminal height detection fails

/* Helper: convert string to lower case */
std::string toLower(const std::string& str) {
    std::string result = str;
    for (auto& c : result) {
        c = tolower(c);
    }
    return result;
}

void capitalizeFirst(std::string& str) {
    if (!str.empty()) {
        // Capitalize first letter and make rest lowercase
        str[0] = toupper(str[0]);
        for (size_t i = 1; i < str.size(); ++i) {
            str[i] = tolower(str[i]);
        }
    }
}

void properCapcasing(std::string& str) {
    if (!str.empty()) {
        // Only capitalize first letter without changing the rest
        str[0] = toupper(str[0]);
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
            c = tolower(c);
        }
        properCapcasing(noun);
    }

    return {adjective, noun};
}

// Random choice helper template

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
    // - Keep adjective as-is from prepareComponents
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
    // Extract original components for debugging using provided separator
    std::string adj = name.substr(0, name.find(separator));
    std::string noun = name.substr(name.find(separator) + 1);
    
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
};

CommandLineOptions parseCommandLine(int argc, char* argv[]) {
    CommandLineOptions opts;
    std::random_device rd;
    std::mt19937 rng(rd());
    return opts;
}

namespace fs = std::filesystem;

#ifndef INSTALL_PREFIX
#   define INSTALL_PREFIX ""   // safety net for builds without the macro
#endif

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
        set.insert(tolower(c));
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
            if (!excluded.count(tolower(c))) { // Check lowercase version
                cleaned += c; // Preserve original case
            }
        }
        if (!cleaned.empty()) { // Only add non-empty strings
            filtered.push_back(cleaned);
        }
    }
    
    return filtered;
}

/* Helper: pick a random element from a vector */
template <typename T>
const T& randomChoice(const std::vector<T>& vec, std::mt19937& rng) {
    return vec[rng() % vec.size()];
}

/* Determine terminal height – fallback to 24 if we cannot query it */
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
    CommandLineOptions opts = parseCommandLine(argc, argv);
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
        } else if (arg == "--noun-file" || arg == "-n") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;
            opts.nounFileSet = true;
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
            } catch (const std::exception& e) {
                std::cerr << "Error: invalid count value '" << optCountArg 
                          << "'. Must be a positive integer." << '\n';
                return 1;
            }
        } else if (arg == "--capcasing" || arg == "--cap") {
            optCapcasing = true;
        } else if (arg == "--exclude" || arg == "-e") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --exclude requires an argument.\n";
                return 1;
            }
            ++i;
            opts.excludeSet = true;
            opts.excludeChars = argv[i];
        } else if (arg == "--camelcasing" || arg == "--camel") {
            optCamelcasing = true;
        } else if (arg == "--debug") {
            optDebug = true;
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./namgen [options]\\n\\n";
            std::cout << "Options:\\n";
            std::cout << "  -a, --adj-file FILE      Path to custom adjectives file\\n";
            std::cout << "  -e, --exclude STRING     Remove these characters from adjective and noun words\\n";
            std::cout << "  -n, --noun-file FILE     Path to custom nouns file\\n";
            std::cout << "  -s SEP, --separator SEP  Custom separator string (default: -)\\n";
            std::cout << "  -x, --null-separator     Do not print the separator\\n";
            std::cout << "  -c COUNT, --count COUNT  Number of names to generate (default: terminal height)\\n";
            std::cout << "  --cap --capcasing        Capitalize first letter of adjective and noun\\n";
            std::cout << "  --camel --camelcasing    CamelCase style with only noun capitalized\\n";
            std::cout << "  --debug                  Enable debug output\\n";
            std::cout << "  --help                   Show this help message and exit\\n\\n";
            std::cout << "Examples:\\n";
            std::cout << "./namgen -c 5              Generate 5 names\\n";
            std::cout << "./namgen -c 5 -x --cap     Generate 5 names with capcasing and no separator\\n";
            std::cout << "./namgen -c 5 -x --camel   Generate 5 names with camelcasing and no separator\\n";
            std::cout << "./namgen -e 'aeiou'       Generate names with no vowels\\n";
            std::cout << "./namgen -a custom_adjectives.txt -n custom_nouns.txt\\n";
            std::cout << "SEPARATOR='-' ./namgen          Use custom separator\\n";
            std::cout << "./namgen -c 50000|sort|uniq -c|sort -n              Generate 50,000 names and count the duplicates and sort to see which occurred the most\\n";
            return 0;
        }
    }

    // Resolve configuration (environment variables with defaults)
    std::string separator;
    if (opts.separatorSet) {
        separator = opts.separator;
    } else {
        separator = getEnv("SEPARATOR", "-");         // fall back to env / default
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
                counto = terminalLines();   // fallback on parse error
            }
        } else {
            counto = terminalLines();       // default when no env var
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

    // 1️⃣  If that does not exist, try a sibling “share/assets” (source‑tree layout)
    if (!fs::exists(assetsFolder) || !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path("share/assets");
    }

    // 2️⃣  If still not found, fall back to the installed location:
    //      <CMAKE_INSTALL_PREFIX>/share/namgen/assets
    if (!fs::exists(assetsFolder) || !fs::is_directory(assetsFolder)) {
        assetsFolder = fs::path(INSTALL_PREFIX) / "share" / "namgen" / "assets";
    }

    // Resolve noun and adjective folders, allowing per‑type overrides.
    fs::path nounFolder = fs::path(
        getEnv("NOUN_FOLDER", (assetsFolder / "nouns").string()));
    if (!fs::exists(nounFolder) || !fs::is_directory(nounFolder)) {
        nounFolder = fs::path(INSTALL_PREFIX) / "share" / "namgen" / "assets" / "nouns";
    }

    fs::path adjFolder = fs::path(
        getEnv("ADJ_FOLDER", (assetsFolder / "adjectives").string()));
    if (!fs::exists(adjFolder) || !fs::is_directory(adjFolder)) {
        adjFolder = fs::path(INSTALL_PREFIX) / "share" / "namgen" / "assets" / "adjectives";
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
            std::cerr << "Error: --noun-file points to a non‑regular file: " << nounFile << "\n";
            return 1;
        }
    } else {
        nounFile = resolveFile("NOUN_FILE", nounFolder, rng);
    }

    // Load all lines from the selected files
    const std::vector<std::string> nounLines = readLines(nounFile);
    const std::vector<std::string> adjLines  = readLines(adjFile);

    if (nounLines.empty() || adjLines.empty()) {
        std::cerr << "Error: Selected noun or adjective file appears to be empty or contained only whitespace.\n";
        return 1;
    }

    // Pre-filter the words once outside the loop
    std::vector<std::string> filteredNouns = nounLines;
    std::vector<std::string> filteredAdjectives = adjLines;

    if (opts.excludeSet) {
        filteredNouns = filterWords(nounLines, opts.excludeChars);
        filteredAdjectives = filterWords(adjLines, opts.excludeChars);

        if (filteredNouns.empty() || filteredAdjectives.empty()) {
            std::cerr << "Error: No valid words remaining after removing default ' and - or specified exclude characters.\n";
            return 1;
        }
    }

    // Variables to hold the current adjective and noun after optional casing
    std::string adjective;
    std::string noun;
    bool needCapcasing = capcasing || camelcasing;

    // Generate requested number of names with optimized loop
    for (std::size_t countzero = 0; countzero < counto; ++countzero) {
        const uint64_t rand_num = rng();
        const auto& rawNoun = filteredNouns[rand_num % filteredNouns.size()];
        const auto& rawAdj  = filteredAdjectives[rand_num % filteredAdjectives.size()];

        if (needCapcasing) {
            auto [adjCased, nounCased] = prepareComponents(rawAdj, rawNoun, capcasing, camelcasing);
            adjective = std::move(adjCased);
            noun = std::move(nounCased);
        } else {
            adjective = rawAdj;
            noun = rawNoun;
        }

        const std::string name = generateName(adjective, noun, nullSeparator, separator, camelcasing);
        
        if (optDebug) {
            printGeneratedName(name, static_cast<std::size_t>(countzero), counto,
                              adjFile, adjFolder, nounFile, nounFolder, separator);
        } else {
            std::cout << name << "\n";
        }
    }

    return 0;
}
