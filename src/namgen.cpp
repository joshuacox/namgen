#include <algorithm>
#include <cstddef>  // for std::size_t
#include <cstdlib>
#include <filesystem>
#if defined(_WIN32) || defined(_WIN64)
#include <sys/system.h>
#endif
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;  // Add this to avoid qualifying with std::

struct CommandLineOptions {
    string adjFile;
    bool adjFileSet = false;
    string nounFile;
    bool nounFileSet = false;
    bool nullSeparator = false;
    bool separatorSet = false; 
    string separator;
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

/* Helper: pick a random element from a vector */
template <typename T>
const T& randomChoice(const std::vector<T>& vec, std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> dist(0, vec.size() - 1);
    return vec[dist(rng)];
}

/* Helper: convert a string to lower case */
std::string toLower(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    std::transform(s.begin(), s.end(), std::back_inserter(out),
                   [](unsigned char c) { return std::tolower(c); });
    return out;
}

static void capitalizeFirst(std::string& s) {
    if (!s.empty())
        s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
}

/* Debug printer – mirrors the shell script's debugger function */
void debugger(const std::string& adjective,
              const std::string& noun,
              const fs::path& adjFile,
              const fs::path& adjFolder,
              const fs::path& nounFile,
              const fs::path& nounFolder,
              std::size_t countzero,
              std::size_t counto) {
    const char* dbg = std::getenv("DEBUG");
    if (!dbg || std::string(dbg) != "true")
        return;

    std::cerr << "DEBUG:\n";
    std::cerr << "  adjective : " << adjective << "\n";
    std::cerr << "  noun      : " << noun << "\n";
    std::cerr << "  ADJ_FILE  : " << adjFile << "\n";
    std::cerr << "  ADJ_FOLDER: " << adjFolder << "\n";
    std::cerr << "  NOUN_FILE : " << nounFile << "\n";
    std::cerr << "  NOUN_FOLDER: " << nounFolder << "\n";
    std::cerr << "  " << countzero << " > " << counto << "\n";
}

/* Determine terminal height – fallback to 24 if we cannot query it */
std::size_t terminalLines() {
    // Simple fallback; more sophisticated approaches would use ioctl or termsize libs.
    return 24;
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
            // Expect a following argument that contains the adjective file path
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;                                   // move to the adjective file value
            opts.adjFile = argv[i];
            opts.adjFileSet = true;
        } else if (arg == "--noun-file" || arg == "-n") {
            // Expect a following argument that contains the noun file path
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;                                   // move to the noun file value
            opts.nounFile = argv[i];
            opts.nounFileSet = true;
        } else if (arg == "--separator" || arg == "-s") {
            // Expect a following argument that contains the separator string
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires an argument.\n";
                return 1;
            }
            ++i;                                   // move to the separator value
            opts.separator = argv[i];
            opts.separatorSet = true;
        } else if (arg == "--count" || arg == "-c") {
            // Expect a following argument that contains the numeric count
            if (i + 1 >= argc) {
                std::cerr << "Error: " << arg << " requires a numeric argument.\n";
                return 1;
            }
            ++i;                                   // move to the count value
            optCountArg = argv[i];
            try {
                counto = static_cast<std::size_t>(std::stoul(optCountArg));
                optCountSet = true;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid count value '" << optCountArg << "'.\n";
                return 1;
            }
        } else if (arg == "--capcasing") {    // new flag
            optCapcasing = true;
        } else if (arg == "--camelcasing") { // new flag
            optCamelcasing = true;
        } else if (arg == "--debug") {
            optDebug = true;
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./namgen [options]\n\n";
            std::cout << "Options:\n";
            std::cout << "  -a FILE, --adj-file FILE   Path to custom adjectives file\n";
            std::cout << "  -n FILE, --noun-file FILE   Path to custom nouns file\n";
            std::cout << "  -s SEP, --separator SEP    Custom separator string (default: -)\n";
            std::cout << "  -x, --null-separator       Do not print the separator\n";
            std::cout << "  -c COUNT, --count COUNT    Number of names to generate (default: terminal height)\n";
            std::cout << "      --capcasing            Capitalize first letter of adjective and noun\n";
            std::cout << "      --camelcasing          CamelCase style with only noun capitalized\n";
            std::cout << "      --debug                Enable debug output\n";
            std::cout << "      --help                 Show this help message and exit\n\n";
            std::cout << "Examples:\n";
            std::cout << "./namgen -c 5                  Generate 5 names\n";
            std::cout << "./namgen -a custom_adjectives.txt -n custom_nouns.txt\n";
            std::cout << "SEPARATOR='-' ./namgen          Use custom separator\n";
            return 0;
        }
    }
    // --------------------------------------------------------------------

    // Resolve configuration (environment variables with defaults)
    std::string separator;
    if (opts.separatorSet) {
        separator = opts.separator;                     // CLI overrides everything
    } else {
        separator = getEnv("SEPARATOR", "-");         // fall back to env / default
    }
    const std::string nullSeparatorEnv = getEnv("NULL_SEPARATOR", "false");
    const bool nullSeparator = (nullSeparatorEnv == "true") || opts.nullSeparator;
    const std::string capcasingEnv = getEnv("CAPCASING", "false");
    const bool capcasing = optCapcasing || (capcasingEnv == "true");
    const std::string camelcasingEnv = getEnv("CAMELCASING", "false");
    const bool camelcasing = optCamelcasing || (camelcasingEnv == "true"); // <-- UPDATED
    // Resolve count (number of names to generate)
    if (!optCountSet) {                     // CLI didn’t set it → fall back to env / default
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


    // -------------------------------------------------------------
    // Locate the installed assets directory.
    //   * If the user sets the environment variable ASSETS_DIR, we honour it.
    //   * Otherwise we fall back to a folder named “assets” located next to the
    //     current working directory (this works for typical source‑tree builds).
    //   * From the assets directory we derive the default noun and adjective
    //     folders (assets/nouns and assets/adjectives).  The user can still
    //     override these defaults with NOUN_FOLDER / ADJ_FOLDER.
    // -------------------------------------------------------------
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
    // If the resolved folder does not exist, fall back to the same
    // “share/assets” tree.
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
    // Resolve noun file from command line first, then fall back to NOUN_FILE and folder
    // Resolve adjective file from command line first
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

    // Resolve noun file from command line first
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
        std::cerr << "Error: selected noun or adjective file is empty.\n";
        return 1;
    }

    // Helper: prepare components with proper casing
    std::pair<std::string, std::string> prepareComponents(const std::string& rawAdj,
                                                         const std::string& rawNoun,
                                                         bool capcasing,
                                                         bool camelcasing) {
        std::string adjective = rawAdj;
        std::string noun = toLower(rawNoun);

        if (capcasing) {
            capitalizeFirst(adjective);
            capitalizeFirst(noun);
        } else if (camelcasing) {
            capitalizeFirst(noun);
        }

        return {adjective, noun};
    }

    // Helper: generate a single name combination
    std::string generateName(const std::string& adjective,
                            const std::string& noun,
                            bool nullSeparator,
                            const std::string& separator) {
        if (nullSeparator) {
            return adjective + noun;
        }
        return adjective + separator + noun;
    }

    // Helper: print generated name with debug info
    void printGeneratedName(const std::string& name,
                           size_t currentCount,
                           size_t totalNames,
                           const fs::path& adjFile,
                           const fs::path& adjFolder,
                           const fs::path& nounFile,
                           const fs::path& nounFolder) {
        // Extract original components for debugging (assuming separator is '-')
        std::string adj = name.substr(0, name.find(separator));
        std::string noun = name.substr(name.find(separator) + 1);
    
        debugger(adj, noun, adjFile, adjFolder, nounFile, nounFolder,
                 currentCount, totalNames);
        std::cout << name << "\n";
    }

    // Main loop – generate names
    std::size_t countzero = 0;
    while (countzero < counto) {
        const auto rawNoun = randomChoice(nounLines, rng);
        const auto rawAdj = randomChoice(adjLines, rng);

        // Prepare components with proper formatting
        const auto [adjective, noun] = prepareComponents(rawAdj, rawNoun, capcasing, camelcasing);

        // Generate and print the name
        const std::string name = generateName(adjective, noun, nullSeparator, separator);
        printGeneratedName(name, countzero, counto, adjFile, adjFolder, nounFile, nounFolder);

        ++countzero;
    }

    return 0;
}
