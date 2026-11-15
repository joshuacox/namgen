#include "brand-classical_etymology_lib.h"

#include <array>
#include <cctype>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 42> kClassicalRoots = {
    "Anim", "Bellum", "Locus", "Myth", "Aegis", "Pact", "Chrono", "Vita",
    "Nex", "Lex", "Vox", "Velo", "Astra", "Sol", "Lun", "Ignis",
    "Ferr", "Cor", "Lux", "Noct", "Veri", "Ars", "Magn", "Omni",
    "Ordo", "Virt", "Fide", "Aura", "Kinet", "Logos", "Ethos", "Pathos",
    "Thalass", "Pyro", "Cryo", "Helio", "Morph", "Praxis", "Telos", "Vexil",
    "Arcan", "Dom"
};

constexpr std::array<const char*, 36> kClassicalSuffixes = {
    "mancy", "craft", "pact", "arch", "deck", "arium", "orium", "ex",
    "axis", "alis", "ia", "ica", "ius", "on", "um", "is",
    "nomia", "logia", "cracy", "scope", "sphere", "guard", "forge", "script",
    "spire", "nexus", "codex", "fex", "trix", "vor", "ward", "dom",
    "os", "gen", "lith", "thesis"
};

bool isVowel(char c) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
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

std::string generate_brand_classical_etymology_name(std::mt19937& rng) {
    std::string head = pick(rng, kClassicalRoots);
    std::string tail = pick(rng, kClassicalSuffixes);

    for (int i = 0; i < 4 && head.size() >= 3 && tail.size() >= 3 &&
                    std::tolower(static_cast<unsigned char>(head[0])) ==
                        std::tolower(static_cast<unsigned char>(tail[0])) &&
                    head.substr(0, 3) == tail.substr(0, 3);
         ++i) {
        tail = pick(rng, kClassicalSuffixes);
    }

    if (!head.empty() && !tail.empty()) {
        char last = static_cast<char>(std::tolower(static_cast<unsigned char>(head.back())));
        char first = static_cast<char>(std::tolower(static_cast<unsigned char>(tail.front())));
        if (last == first && isVowel(last)) {
            head.pop_back();
        }
    }
    return capitalizeOnly(head + tail);
}
