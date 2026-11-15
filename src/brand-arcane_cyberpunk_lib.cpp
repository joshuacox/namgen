#include "brand-arcane_cyberpunk_lib.h"

#include <array>
#include <cctype>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 42> kArcanePrefixes = {
    "Hex", "Sigil", "Rune", "Void", "Vex", "Aether", "Astral", "Chrono",
    "Nyx", "Crypt", "Omen", "Arc", "Glyph", "Ward", "Grim", "Pyre",
    "Gloom", "Soul", "Lich", "Abyss", "Spell", "Mana", "Warp", "Veil",
    "Dusk", "Shad", "Bane", "Rift", "Pact", "Curse", "Tome", "Relic",
    "Nex", "Prism", "Orb", "Coven", "Thorn", "Kabal", "Wyrm", "Specter",
    "Sable", "Occult"
};

constexpr std::array<const char*, 42> kCyberSuffixes = {
    "grid", "stack", "frame", "node", "mesh", "pulse", "synth", "bit",
    "byte", "core", "port", "link", "flux", "wire", "vault", "cipher",
    "hash", "shunt", "loop", "shard", "ware", "bot", "chrome", "neon",
    "spark", "vec", "kern", "sock", "trace", "ping", "proxy", "gate",
    "rail", "deck", "net", "drive", "code", "matrix", "logic", "rig",
    "stream", "volt"
};

constexpr std::array<const char*, 24> kCyberPrefixes = {
    "Neon", "Cyber", "Nano", "Volt", "Zero", "Synth", "Kilo", "Hyper",
    "Data", "Proto", "Chrome", "Bit", "Net", "Grid", "Glitch", "Laser",
    "Neuro", "Quantum", "Ion", "Vector", "Pulse", "Proxy", "Chip", "Wire"
};

constexpr std::array<const char*, 24> kArcaneRoots = {
    "pakt", "rune", "hex", "sigil", "ward", "tome", "rift", "spell",
    "omen", "veil", "glyph", "crypt", "pyre", "mana", "bane", "soul",
    "lore", "craft", "cast", "spire", "grimoire", "nexus", "vault", "crest"
};

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

std::string generate_brand_arcane_cyberpunk_name(std::mt19937& rng) {
    std::uniform_int_distribution<int> patternDist(0, 2);
    if (patternDist(rng) != 2) {
        return capitalizeOnly(std::string(pick(rng, kArcanePrefixes)) + pick(rng, kCyberSuffixes));
    }
    return capitalizeOnly(std::string(pick(rng, kCyberPrefixes)) + pick(rng, kArcaneRoots));
}
