#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <unordered_set>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "generator_registry.h"
#include "tui.h"
#include "markov.h"
#include "linguistics.h"
#include "lore.h"
#include "http_server.h"

#if !defined(_WIN32) && !defined(__EMSCRIPTEN__)
#include <unistd.h>
#endif

namespace fs = std::filesystem;

static constexpr int DEFAULT_TERMINAL_LINES = 24;

enum class OutputFormat { Plain, Json, Csv, Slug };

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

extern "C" {
EMSCRIPTEN_KEEPALIVE
const char* namgen_generate_wasm(const char* flag, uint32_t seed) {
    static std::string result;
    static std::mt19937 rng(std::random_device{}());
    if (seed != 0) {
        rng.seed(seed);
    }
    std::string key = (flag != nullptr) ? flag : "";
    if (const auto* gen = GeneratorRegistry::instance().find(key)) {
        result = gen->generate(rng);
    } else {
        result = "Error: Unknown generator flag '" + key + "'";
    }
    return result.c_str();
}

EMSCRIPTEN_KEEPALIVE
int namgen_has_generator_wasm(const char* flag) {
    std::string key = (flag != nullptr) ? flag : "";
    return GeneratorRegistry::instance().find(key) != nullptr ? 1 : 0;
}
}
#endif

std::string escapeJson(const std::string& s) {
    std::string out;
    out.reserve(s.size() + 8);
    for (char c : s) {
        if (c == '"') out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else if (c == '\b') out += "\\b";
        else if (c == '\f') out += "\\f";
        else if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else if (c == '\t') out += "\\t";
        else out += c;
    }
    return out;
}

std::string escapeCsv(const std::string& s) {
    std::string out;
    out.reserve(s.size() + 8);
    for (char c : s) {
        if (c == '"') out += "\"\"";
        else out += c;
    }
    return out;
}

std::string toSlug(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    bool lastHyphen = false;
    for (char c : s) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            out += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            lastHyphen = false;
        } else if (!lastHyphen && !out.empty()) {
            out += '-';
            lastHyphen = true;
        }
    }
    while (!out.empty() && out.back() == '-') {
        out.pop_back();
    }
    return out;
}

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
    bool unique = false;
    bool seedSet = false;
    uint64_t seed = 0;
    OutputFormat format = OutputFormat::Plain;
    const GeneratorInfo* activeGenerator = nullptr;
    bool interactive = false;
    bool matchSet = false;
    std::string matchPattern;
    std::regex matchRegex;
    bool minLenSet = false;
    std::size_t minLen = 0;
    bool maxLenSet = false;
    std::size_t maxLen = 0;
    bool composeSet = false;
    std::vector<const GeneratorInfo*> composeGenerators;
    std::string composeTemplate = "{1} of {2}";
    bool markovMode = false;
    std::string markovGen;
    int markovOrder = 3;
    bool trainSet = false;
    std::string trainFile;
    bool syllablesSet = false;
    int minSyllables = 0;
    int maxSyllables = 0;
    bool alliterate = false;
    bool withLore = false;
    bool findSet = false;
    std::string findQuery;
    bool serveMode = false;
    std::string serveAddress = "127.0.0.1";
    int servePort = 8080;
    bool stdinMode = false;
    bool colorSet = false;
    std::string colorMode = "auto";
};

inline bool isValidCandidate(const std::string& s, const CommandLineOptions& opts) {
    if (opts.minLenSet && s.length() < opts.minLen) return false;
    if (opts.maxLenSet && s.length() > opts.maxLen) return false;
    if (opts.matchSet) {
        if (!std::regex_search(s, opts.matchRegex)) return false;
    }
    if (opts.syllablesSet) {
        if (!Linguistics::matchesSyllables(s, opts.minSyllables, opts.maxSyllables)) return false;
    }
    if (opts.alliterate) {
        if (!Linguistics::isAlliterative(s)) return false;
    }
    return true;
}

inline std::string renderCompose(const std::vector<const GeneratorInfo*>& gens,
                                 const std::string& tmpl,
                                 std::mt19937& rng) {
    std::vector<std::string> parts;
    parts.reserve(gens.size());
    for (const auto* g : gens) {
        parts.push_back(g->generate(rng));
    }
    std::string result = tmpl;
    for (std::size_t i = 0; i < parts.size(); ++i) {
        std::string placeholder = "{" + std::to_string(i + 1) + "}";
        std::size_t pos = 0;
        while ((pos = result.find(placeholder, pos)) != std::string::npos) {
            result.replace(pos, placeholder.length(), parts[i]);
            pos += parts[i].length();
        }
    }
    return result;
}

static bool shouldUseColor(const CommandLineOptions& opts) {
    if (opts.colorMode == "always") return true;
    if (opts.colorMode == "never") return false;
    if (std::getenv("NO_COLOR") != nullptr) return false;
#if !defined(_WIN32) && !defined(__EMSCRIPTEN__)
    return isatty(STDOUT_FILENO);
#else
    return false;
#endif
}

void emitOutput(const std::vector<std::string>& results,
                const CommandLineOptions& opts,
                bool optDebug,
                const fs::path& adjFile,
                const fs::path& adjFolder,
                const fs::path& nounFile,
                const fs::path& nounFolder,
                const std::string& separator) {
    if (opts.format == OutputFormat::Json) {
        std::cout << "[\n";
        for (std::size_t i = 0; i < results.size(); ++i) {
            std::cout << "  \"" << escapeJson(results[i]) << "\""
                      << (i + 1 < results.size() ? "," : "") << "\n";
        }
        std::cout << "]\n";
    } else if (opts.format == OutputFormat::Csv) {
        std::cout << "\"name\"\n";
        for (const auto& name : results) {
            std::cout << "\"" << escapeCsv(name) << "\"\n";
        }
    } else if (opts.format == OutputFormat::Slug) {
        for (const auto& name : results) {
            std::cout << toSlug(name) << "\n";
        }
    } else {
        bool useColor = shouldUseColor(opts);
        for (std::size_t i = 0; i < results.size(); ++i) {
            if (optDebug) {
                printGeneratedName(results[i], i, results.size(), adjFile, adjFolder, nounFile, nounFolder, separator);
            } else if (useColor) {
                std::string line = results[i];
                size_t lorePos = line.find(" [");
                if (lorePos != std::string::npos) {
                    std::cout << "\033[1;36m" << line.substr(0, lorePos) << "\033[0m \033[33m"
                              << line.substr(lorePos + 1) << "\033[0m\n";
                } else {
                    std::cout << "\033[1;36m" << line << "\033[0m\n";
                }
            } else {
                std::cout << results[i] << "\n";
            }
        }
    }
}

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
        } else if (arg == "--seed" || arg == "-S") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires a numeric seed argument.\n";
                return 1;
            }
            ++i;
            try {
                opts.seed = static_cast<uint64_t>(std::stoull(argv[i]));
                opts.seedSet = true;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid seed value '" << argv[i] << "'. Must be an unsigned integer.\n";
                return 1;
            }
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
        } else if (arg == "--json") {
            opts.format = OutputFormat::Json;
        } else if (arg == "--csv") {
            opts.format = OutputFormat::Csv;
        } else if (arg == "--slug" || arg == "--kebab") {
            opts.format = OutputFormat::Slug;
        } else if (arg == "--unique" || arg == "-u") {
            opts.unique = true;
        } else if (arg == "--interactive" || arg == "-i") {
            opts.interactive = true;
        } else if (arg == "--match" || arg == "-m") {
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires a regular expression argument.\n";
                return 1;
            }
            ++i;
            opts.matchPattern = argv[i];
            try {
                opts.matchRegex = std::regex(opts.matchPattern);
                opts.matchSet = true;
            } catch (const std::regex_error& e) {
                std::cerr << "Error: invalid regular expression '" << opts.matchPattern << "': " << e.what() << "\n";
                return 1;
            }
        } else if (arg == "--min-len") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --min-len requires a positive integer argument.\n";
                return 1;
            }
            ++i;
            try {
                opts.minLen = static_cast<std::size_t>(std::stoul(argv[i]));
                opts.minLenSet = true;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid --min-len value '" << argv[i] << "'. Must be an unsigned integer.\n";
                return 1;
            }
        } else if (arg == "--max-len") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --max-len requires a positive integer argument.\n";
                return 1;
            }
            ++i;
            try {
                opts.maxLen = static_cast<std::size_t>(std::stoul(argv[i]));
                opts.maxLenSet = true;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid --max-len value '" << argv[i] << "'. Must be an unsigned integer.\n";
                return 1;
            }
        } else if (arg == "--template") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --template requires a string format argument.\n";
                return 1;
            }
            ++i;
            opts.composeTemplate = argv[i];
        } else if (arg == "--compose") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --compose requires a comma-separated list of generator names.\n";
                return 1;
            }
            ++i;
            std::string compArg = argv[i];
            std::stringstream ss(compArg);
            std::string token;
            while (std::getline(ss, token, ',')) {
                // Trim token
                token.erase(token.begin(), std::find_if(token.begin(), token.end(), [](unsigned char ch) { return !std::isspace(ch); }));
                token.erase(std::find_if(token.rbegin(), token.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), token.end());
                if (token.empty()) continue;
                const GeneratorInfo* g = GeneratorRegistry::instance().find(token);
                if (!g && token.rfind("--", 0) != 0) {
                    g = GeneratorRegistry::instance().find("--" + token);
                }
                if (!g) {
                    std::cerr << "Error: unknown generator in --compose: '" << token << "'\n";
                    return 1;
                }
                opts.composeGenerators.push_back(g);
            }
            if (opts.composeGenerators.empty()) {
                std::cerr << "Error: --compose requires at least one valid generator.\n";
                return 1;
            }
            opts.composeSet = true;
        } else if (arg == "--markov") {
            opts.markovMode = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                ++i;
                opts.markovGen = argv[i];
            }
        } else if (arg == "--order") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --order requires an integer argument.\n";
                return 1;
            }
            ++i;
            opts.markovOrder = std::stoi(argv[i]);
        } else if (arg == "--train") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --train requires a file path argument.\n";
                return 1;
            }
            ++i;
            opts.trainSet = true;
            opts.trainFile = argv[i];
            opts.markovMode = true;
        } else if (arg == "--synthesize") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --synthesize requires a numeric argument.\n";
                return 1;
            }
            ++i;
            counto = static_cast<std::size_t>(std::stoul(argv[i]));
            optCountSet = true;
            opts.markovMode = true;
        } else if (arg == "--syllables") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --syllables requires a range (e.g. 2 or 2-3).\n";
                return 1;
            }
            ++i;
            std::string sArg = argv[i];
            size_t dash = sArg.find('-');
            if (dash != std::string::npos) {
                opts.minSyllables = std::stoi(sArg.substr(0, dash));
                opts.maxSyllables = std::stoi(sArg.substr(dash + 1));
            } else {
                opts.minSyllables = std::stoi(sArg);
                opts.maxSyllables = opts.minSyllables;
            }
            opts.syllablesSet = true;
        } else if (arg == "--alliterate") {
            opts.alliterate = true;
        } else if (arg == "--with-lore" || arg == "--meaning") {
            opts.withLore = true;
        } else if (arg == "--find") {
            if (i + 1 >= argc) {
                std::cerr << "Error: --find requires a search keyword.\n";
                return 1;
            }
            ++i;
            opts.findSet = true;
            opts.findQuery = argv[i];
        } else if (arg == "--serve") {
            opts.serveMode = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                ++i;
                std::string sArg = argv[i];
                size_t colon = sArg.find(':');
                if (colon != std::string::npos) {
                    opts.serveAddress = sArg.substr(0, colon);
                    opts.servePort = std::stoi(sArg.substr(colon + 1));
                } else {
                    opts.servePort = std::stoi(sArg);
                }
            }
        } else if (arg == "-") {
            opts.stdinMode = true;
        } else if (arg.rfind("--color=", 0) == 0) {
            opts.colorSet = true;
            opts.colorMode = arg.substr(8);
        } else if (arg == "--color") {
            opts.colorSet = true;
            opts.colorMode = "always";
        } else if (arg == "--no-color") {
            opts.colorSet = true;
            opts.colorMode = "never";
        } else if (arg == "--debug") {
            optDebug = true;
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./namgen [options] [generator]\n\n";
            std::cout << "Options:\n";
            std::cout << "  -a, --adj-file FILE      Path to custom adjectives file\n";
            std::cout << "  -e, --exclude STRING     Characters to strip from generated words\n";
            std::cout << "  -n, --noun FILE          Path to custom noun file\n";
            std::cout << "  -s SEP, --separator SEP  Custom separator string (default: -)\n";
            std::cout << "  -x, --null-separator     Do not print the separator\n";
            std::cout << "  -c COUNT, --count COUNT  Number of names to generate (default: terminal height)\n";
            std::cout << "  -S NUM, --seed NUM       Seed random number generator deterministically\n";
            std::cout << "  -u, --unique             Ensure no duplicate names are emitted\n";
            std::cout << "  -m, --match REGEX        Filter generated names by regular expression\n";
            std::cout << "  --min-len NUM            Minimum character length of generated names\n";
            std::cout << "  --max-len NUM            Maximum character length of generated names\n";
            std::cout << "  --syllables RANGE        Constraint syllable count (e.g. 2 or 2-3)\n";
            std::cout << "  --alliterate             Filter for alliterative multi-word names\n";
            std::cout << "  --with-lore, --meaning   Append procedural lore epithet and meaning\n";
            std::cout << "  --markov [GEN]           Generate novel names using Markov n-gram model\n";
            std::cout << "  --order NUM              N-gram order for Markov synthesizer (default: 3)\n";
            std::cout << "  --train FILE             Train Markov synthesizer from external text corpus\n";
            std::cout << "  --synthesize COUNT       Synthesize novel names from trained Markov model\n";
            std::cout << "  --find KEYWORD           Search generators matching keyword/pattern\n";
            std::cout << "  --compose GEN1,GEN2      Compose multiple generators together\n";
            std::cout << "  --template STRING        Template for composition (default: \"{1} of {2}\")\n";
            std::cout << "  --serve [ADDR:PORT]      Run embedded zero-dependency HTTP REST daemon (default: 127.0.0.1:8080)\n";
            std::cout << "  -                        Stream stdin line-by-line through casing/formatting pipeline\n";
            std::cout << "  --color[=WHEN]           Colorize output (auto, always, never; default: auto)\n";
            std::cout << "  -i, --interactive        Launch interactive terminal explorer UI\n";
            std::cout << "  --json                   Output results as a JSON array of strings\n";
            std::cout << "  --csv                    Output results in CSV format\n";
            std::cout << "  --slug                   Convert output to lowercase kebab-case slugs\n";
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

    std::mt19937 rng;
    if (opts.seedSet) {
        rng.seed(static_cast<std::mt19937::result_type>(opts.seed));
    } else {
        std::string seedEnv = getEnv("SEED", "");
        if (!seedEnv.empty()) {
            try {
                rng.seed(static_cast<std::mt19937::result_type>(std::stoull(seedEnv)));
            } catch (...) {
                rng.seed(std::random_device{}());
            }
        } else {
            rng.seed(std::random_device{}());
        }
    }

    // Embedded HTTP daemon mode
    if (opts.serveMode) {
        return namgen::runHttpServer(opts.serveAddress, opts.servePort);
    }

    // Stdin stream processing mode
    if (opts.stdinMode) {
        std::string line;
        std::vector<std::string> results;
        while (std::getline(std::cin, line)) {
            if (line.empty()) continue;
            std::string item = line;
            if (opts.composeSet) {
                std::string tmpl = opts.composeTemplate;
                size_t pos = 0;
                while ((pos = tmpl.find("{0}", pos)) != std::string::npos) {
                    tmpl.replace(pos, 3, item);
                    pos += item.length();
                }
                item = renderCompose(opts.composeGenerators, tmpl, rng);
            }
            if (capcasing) {
                capitalizeFirst(item);
            }
            if (opts.format == OutputFormat::Slug) {
                item = toSlug(item);
            }
            if (!isValidCandidate(item, opts)) continue;
            if (opts.withLore) {
                item = Lore::formatWithLore(item, rng);
            }
            results.push_back(std::move(item));
        }
        emitOutput(results, opts, optDebug, fs::path(), fs::path(), fs::path(), fs::path(), "");
        return 0;
    }

    // Keyword search mode
    if (opts.findSet) {
        auto matches = GeneratorRegistry::instance().search(opts.findQuery);
        if (matches.empty()) {
            std::cout << "No generators found matching '" << opts.findQuery << "'.\n";
            return 0;
        }
        std::cout << "Found " << matches.size() << " matching generator(s):\n\n";
        for (const auto* gen : matches) {
            std::string sample = gen->generate(rng);
            std::cout << "  --" << gen->flag << "\n";
            std::cout << "      Description : " << gen->description << "\n";
            std::cout << "      Sample Roll : " << sample << "\n\n";
        }
        return 0;
    }

    // Interactive TUI mode
    if (opts.interactive) {
        return namgen::runInteractiveTui(rng);
    }

    // Markov synthesis mode
    if (opts.markovMode) {
        MarkovModel model(opts.markovOrder);
        if (opts.trainSet) {
            if (!model.trainFromFile(opts.trainFile)) {
                std::cerr << "Error: could not train Markov model from file '" << opts.trainFile << "'\n";
                return 1;
            }
        } else {
            const GeneratorInfo* targetGen = nullptr;
            if (!opts.markovGen.empty()) {
                targetGen = GeneratorRegistry::instance().find(opts.markovGen);
                if (!targetGen && opts.markovGen.rfind("--", 0) != 0) {
                    targetGen = GeneratorRegistry::instance().find("--" + opts.markovGen);
                }
                if (!targetGen) {
                    std::cerr << "Error: unknown generator for Markov synthesis: '" << opts.markovGen << "'\n";
                    return 1;
                }
            } else if (opts.activeGenerator) {
                targetGen = opts.activeGenerator;
            }

            std::vector<std::string> trainingSamples;
            trainingSamples.reserve(100);
            if (targetGen) {
                for (int s = 0; s < 100; ++s) {
                    trainingSamples.push_back(targetGen->generate(rng));
                }
            } else {
                if (const auto* elfGen = GeneratorRegistry::instance().find("fantasy-elves")) {
                    for (int s = 0; s < 100; ++s) {
                        trainingSamples.push_back(elfGen->generate(rng));
                    }
                }
            }
            model.train(trainingSamples);
        }

        std::vector<std::string> results;
        results.reserve(counto);
        std::unordered_set<std::string> seen;
        std::size_t attempts = 0;
        const std::size_t maxAttempts = counto * 200 + 5000;
        while (results.size() < counto && attempts < maxAttempts) {
            ++attempts;
            std::string name = model.generate(rng);
            if (name.empty()) continue;
            if (!isValidCandidate(name, opts)) continue;
            if (opts.withLore) {
                name = Lore::formatWithLore(name, rng);
            }
            if (opts.unique) {
                if (seen.insert(name).second) {
                    results.push_back(std::move(name));
                }
            } else {
                results.push_back(std::move(name));
            }
        }
        emitOutput(results, opts, optDebug, fs::path(), fs::path(), fs::path(), fs::path(), "");
        return 0;
    }

    // Generator composition
    if (opts.composeSet) {
        std::vector<std::string> results;
        results.reserve(counto);
        std::unordered_set<std::string> seen;
        std::size_t attempts = 0;
        const std::size_t maxAttempts = counto * 200 + 5000;
        while (results.size() < counto && attempts < maxAttempts) {
            ++attempts;
            std::string name = renderCompose(opts.composeGenerators, opts.composeTemplate, rng);
            if (!isValidCandidate(name, opts)) continue;
            if (opts.withLore) {
                name = Lore::formatWithLore(name, rng);
            }
            if (opts.unique) {
                if (seen.insert(name).second) {
                    results.push_back(std::move(name));
                }
            } else {
                results.push_back(std::move(name));
            }
        }
        emitOutput(results, opts, optDebug, fs::path(), fs::path(), fs::path(), fs::path(), "");
        return 0;
    }

    // If a specialized generator was selected, run it and exit
    if (opts.activeGenerator) {
        std::vector<std::string> results;
        results.reserve(counto);
        std::unordered_set<std::string> seen;
        std::size_t attempts = 0;
        const std::size_t maxAttempts = counto * 200 + 5000;
        while (results.size() < counto && attempts < maxAttempts) {
            ++attempts;
            std::string name = opts.activeGenerator->generate(rng);
            if (!isValidCandidate(name, opts)) continue;
            if (opts.withLore) {
                name = Lore::formatWithLore(name, rng);
            }
            if (opts.unique) {
                if (seen.insert(name).second) {
                    results.push_back(std::move(name));
                }
            } else {
                results.push_back(std::move(name));
            }
        }
        emitOutput(results, opts, optDebug, fs::path(), fs::path(), fs::path(), fs::path(), "");
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

    std::vector<std::string> results;
    results.reserve(counto);
    std::unordered_set<std::string> seen;
    std::size_t attempts = 0;
    const std::size_t maxAttempts = counto * 100 + 1000;

    while (results.size() < counto && attempts < maxAttempts) {
        ++attempts;
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
        if (!isValidCandidate(generatedName, opts)) continue;
        if (opts.withLore) {
            generatedName = Lore::formatWithLore(generatedName, rng);
        }
        if (opts.unique) {
            if (seen.insert(generatedName).second) {
                results.push_back(std::move(generatedName));
            }
        } else {
            results.push_back(std::move(generatedName));
        }
    }

    emitOutput(results, opts, optDebug, adjFile, adjFolder, nounFile, nounFolder, separator);
    return 0;
}
