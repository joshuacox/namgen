#include "brand-sovereign_neologisms_lib.h"

#include <array>
#include <cctype>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 34> kOnsets = {
    "V", "K", "Z", "Th", "Or", "X", "Dr", "Br", "Kr", "Vr",
    "Ny", "Ly", "Syl", "R", "T", "M", "N", "S", "Al", "El",
    "Val", "Mal", "Sol", "Vor", "Cor", "Tor", "Kal", "Zor", "Ryn", "Fen",
    "Cael", "Vyr", "Oph", "Ael"
};

constexpr std::array<const char*, 12> kNuclei = {
    "a", "e", "i", "o", "ae", "ai", "au", "ei", "ia", "io", "ou", "y"
};

constexpr std::array<const char*, 16> kCodas = {
    "", "x", "v", "l", "n", "r", "th", "z", "k", "m", "s", "nd", "lt", "st", "rk", "nx"
};

constexpr std::array<const char*, 24> kEndings = {
    "ora", "ith", "ar", "is", "ax", "ix", "on", "ia",
    "en", "os", "um", "ara", "yra", "eon", "eth", "orn",
    "ane", "ova", "ux", "el", "ir", "alis", "oris", "axis"
};

bool endsWithVowel(const std::string& s) {
    if (s.empty()) return false;
    char c = static_cast<char>(std::tolower(static_cast<unsigned char>(s.back())));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool startsWithVowel(const std::string& s) {
    if (s.empty()) return false;
    char c = static_cast<char>(std::tolower(static_cast<unsigned char>(s.front())));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

template <std::size_t N>
const char* pick(std::mt19937& rng, const std::array<const char*, N>& arr) {
    return arr[std::uniform_int_distribution<std::size_t>(0, N - 1)(rng)];
}

std::string capitalizeOnly(std::string s) {
    if (s.empty()) return s;
    s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
    for (std::size_t i = 1; i < s.size(); ++i) {
        s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    }
    return s;
}

} // namespace

std::string generate_brand_sovereign_neologisms_name(std::mt19937& rng) {
    std::string onset = pick(rng, kOnsets);
    std::string nucleus = endsWithVowel(onset) ? "" : pick(rng, kNuclei);
    std::string coda = pick(rng, kCodas);
    std::string ending = pick(rng, kEndings);

    // Avoid cluster collisions when coda is non-empty and ending starts with consonant, or empty coda + vowel ending
    if (coda.empty() && startsWithVowel(ending)) {
        coda = kCodas[std::uniform_int_distribution<std::size_t>(1, 10)(rng)];
    }
    std::string raw = onset + nucleus + coda + ending;
    // Collapse any accidental triple identical chars
    std::string cleaned;
    cleaned.reserve(raw.size());
    for (char c : raw) {
        char lc = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (cleaned.size() >= 2 &&
            static_cast<char>(std::tolower(static_cast<unsigned char>(cleaned[cleaned.size() - 1]))) == lc &&
            static_cast<char>(std::tolower(static_cast<unsigned char>(cleaned[cleaned.size() - 2]))) == lc) {
            continue;
        }
        cleaned.push_back(c);
    }
    return capitalizeOnly(cleaned);
}
