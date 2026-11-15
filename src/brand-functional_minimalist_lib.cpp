#include "brand-functional_minimalist_lib.h"

#include <array>
#include <cctype>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 38> kMinimalHeads = {
    "Draft", "Card", "Deck", "Lane", "Pact", "Cast", "Turn", "Hand",
    "Tile", "Board", "Grid", "Edge", "Core", "Base", "Node", "Line",
    "Path", "Gate", "Key", "Slot", "Stack", "Queue", "Seed", "Root",
    "Loop", "Beat", "Step", "Rank", "Tier", "Role", "Plan", "Form",
    "Mode", "Play", "Draw", "Flip", "Swap", "Mark"
};

constexpr std::array<const char*, 38> kMinimalTails = {
    "lane", "rift", "arena", "line", "draft", "card", "deck", "cast",
    "work", "kit", "lab", "hub", "box", "pad", "bay", "dock",
    "yard", "port", "desk", "bench", "room", "post", "way", "track",
    "trail", "band", "frame", "grid", "map", "set", "flow", "sync",
    "pipe", "sort", "mark", "lock", "point", "works"
};

template <std::size_t N>
const char* pick(std::mt19937& rng, const std::array<const char*, N>& arr) {
    return arr[std::uniform_int_distribution<std::size_t>(0, N - 1)(rng)];
}

std::string lowerStr(std::string s) {
    for (char& c : s) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return s;
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

std::string generate_brand_functional_minimalist_name(std::mt19937& rng) {
    std::string head = lowerStr(pick(rng, kMinimalHeads));
    std::string tail = lowerStr(pick(rng, kMinimalTails));
    for (int i = 0; i < 6 && head == tail; ++i) {
        tail = lowerStr(pick(rng, kMinimalTails));
    }
    if (!head.empty() && !tail.empty() && head.back() == tail.front()) {
        // Keep clean double letters out when awkward unless natural
        if (head.back() != 's' && head.back() != 'l') {
            tail = lowerStr(pick(rng, kMinimalTails));
        }
    }
    return capitalizeOnly(head + tail);
}
