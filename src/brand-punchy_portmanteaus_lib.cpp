#include "brand-punchy_portmanteaus_lib.h"

#include <array>
#include <cctype>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 40> kPortmanteauHeads = {
    "Deck", "Spell", "Summon", "Mana", "Draft", "Rune", "Card", "Crit",
    "Quest", "Hex", "Blade", "Shield", "Guild", "Crest", "Moba", "Arena",
    "Lane", "Turn", "Hand", "Draw", "Buff", "Raid", "Boss", "Craft",
    "Forge", "Brawl", "Clash", "Blitz", "Snap", "Flip", "Spark", "Surge",
    "Pulse", "Dash", "Strike", "Vault", "Tower", "Loot", "Pact", "Charm"
};

constexpr std::array<const char*, 40> kPortmanteauTails = {
    "brawl", "clash", "rift", "cast", "deck", "craft", "moba", "pact",
    "lock", "drop", "roll", "stack", "forge", "blast", "rush", "leap",
    "guard", "ward", "link", "swap", "flip", "grid", "zone", "ring",
    "run", "duel", "brew", "meld", "splice", "spark", "wave", "shift",
    "spike", "vault", "keep", "gate", "core", "surge", "strike", "deck"
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

std::string lowerStr(std::string s) {
    for (char& c : s) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return s;
}

} // namespace

std::string generate_brand_punchy_portmanteaus_name(std::mt19937& rng) {
    std::string head = lowerStr(pick(rng, kPortmanteauHeads));
    std::string tail = lowerStr(pick(rng, kPortmanteauTails));

    for (int i = 0; i < 6 && head == tail; ++i) {
        tail = lowerStr(pick(rng, kPortmanteauTails));
    }

    // Attempt smooth bigram or monogram overlap fusion if present
    if (head.size() >= 3 && tail.size() >= 3 && head.substr(head.size() - 2) == tail.substr(0, 2)) {
        return capitalizeOnly(head + tail.substr(2));
    }
    if (head.size() >= 3 && tail.size() >= 3 && head.back() == tail.front()) {
        return capitalizeOnly(head + tail.substr(1));
    }
    if ((rng() % 3) == 0 && head.size() >= 4 && tail.size() >= 4) {
        return capitalizeOnly(head.substr(0, head.size() - 1) + tail);
    }
    return capitalizeOnly(head + tail);
}
