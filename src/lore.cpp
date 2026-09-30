#include "lore.h"
#include <vector>

namespace Lore {

static const std::vector<std::string> EPITHET_PREFIXES = {
    "Dawn", "Void", "Iron", "Moon", "Star", "Shadow", "Flame", "Wind",
    "Storm", "Frost", "Silent", "Sun", "Blood", "Silver", "Night", "Rune",
    "Ash", "Thunder", "Ember", "Dusk", "Golden", "Mist", "Deep", "Ghost"
};

static const std::vector<std::string> EPITHET_SUFFIXES = {
    "Stalker", "Walker", "Forged", "Touched", "Weaver", "Bane", "Warden",
    "Rider", "Bringer", "Bitten", "Watcher", "Caller", "Strider", "Seeker",
    "Blade", "Heart", "Giver", "Singer", "Fang", "Breaker", "Shield", "Sworn"
};

static const std::vector<std::string> CULTURES = {
    "Sindarin", "High Valyrian", "Old Norse", "Ancient Terran", "Draconic",
    "Elder Tongue", "Proto-Elven", "Dwarven Runes", "Celestial", "Abyssal",
    "First Language", "Aethelgardian", "Githzerai Glyphs", "Klingon Proverb"
};

static const std::vector<std::string> MEANING_ROOTS = {
    "Beacon of the Pale Horizon", "Unyielding as the Mountain", "Born of Dragonfire",
    "Shadow in the Autumn Mist", "Keeper of the Quantum Gates", "Song of the Golden Leaf",
    "Hammer of the Deep Stone", "Eye of the Astral Sea", "Whisper in the High Pines",
    "Child of the Eclipse", "Defender of the Silent Citadel", "Blade That Cuts the Wind",
    "Flame That Never Dies", "Echo of the Ancient Stars", "Tide That Swallows Kings",
    "Sovereign of the Frozen Veil", "Light Across the Void", "Pledge of the Eternal Oath"
};

std::string generateEpithet(std::mt19937& rng) {
    std::uniform_int_distribution<size_t> pDist(0, EPITHET_PREFIXES.size() - 1);
    std::uniform_int_distribution<size_t> sDist(0, EPITHET_SUFFIXES.size() - 1);
    return "the " + EPITHET_PREFIXES[pDist(rng)] + "-" + EPITHET_SUFFIXES[sDist(rng)];
}

std::string generateMeaning(std::mt19937& rng) {
    std::uniform_int_distribution<size_t> cDist(0, CULTURES.size() - 1);
    std::uniform_int_distribution<size_t> mDist(0, MEANING_ROOTS.size() - 1);
    return CULTURES[cDist(rng)] + ": \"" + MEANING_ROOTS[mDist(rng)] + "\"";
}

std::string formatWithLore(const std::string& name, std::mt19937& rng) {
    return name + " " + generateEpithet(rng) + " [" + generateMeaning(rng) + "]";
}

} // namespace Lore
