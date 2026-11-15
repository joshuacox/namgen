#include "tabletop-villain_schemes_lib.h"

#include <array>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 14> kMasterminds = {
    "An ambitious guild-treasurer",
    "A deposed spymaster",
    "A honey-tongued lichen necromancer",
    "A disillusioned planar cartographer",
    "A charismatic blood-cleric",
    "An immortal porcelain automaton",
    "A syndicate of rival glassblowers",
    "A starved fey archivist",
    "A fallen paladin-turned-magistrate",
    "A telepathic aberration beneath the sewers",
    "A disgraced court alchemist",
    "A triad of storm-caller pirates",
    "An ancient silver-tongued vampire",
    "A clockwork cardinal"
};

constexpr std::array<const char*, 14> kMethods = {
    "quietly mints cursed silver coins",
    "grafts sleep-spores into the city's grain silos",
    "bribes harbor pilots to steer ships into a planar rift",
    "replaces noble heirs with wax-sculpted mimics",
    "erects obelisks disguised as aqueduct boundary stones",
    "auctions forged pardons stamped with a dead king's seal",
    "siphons dreams from a dozen orphanages through mirrored wells",
    "pays mercenary companies to stage monster attacks outside the walls",
    "smuggles living rust-monster eggs into the royal armory",
    "inscribes binding runes inside popular tavern ballads",
    "poisons only the ink used in civic marriage contracts",
    "diverts volcanic steam beneath the cathedral foundations",
    "captures stray thunderbolts inside lead-lined belltowers",
    "colludes with goblin sappers to hollow out the cliffside keep"
};

constexpr std::array<const char*, 14> kEndgames = {
    "to declare martial sovereignty during the winter solstice.",
    "to blackmail the High Conclave for an unbreakable seat.",
    "to awaken a buried colossus slumbering beneath the market square.",
    "to sever the trade road and starve the capital into a vassal pact.",
    "to anchor an upside-down citadel in the sky above the bay.",
    "to ransom the memory of magic itself back to the guilds.",
    "to force a shotgun coronation before the rightful heir comes of age.",
    "to swap the town's entire populace with a mirrored Shadowfell twin.",
    "to rewrite centuries-old property deeds in their immortal name.",
    "to crack open an ancient vault sealed by seven dragon oaths.",
    "to monopolize every healing potion within three provinces.",
    "to harvest enough soul-sparks to ascend into demi-lichdom.",
    "to frame the party's primary patron for high treason.",
    "to shatter the planar ward protecting the valley from infernal tide."
};

template <std::size_t N>
const char* pick(std::mt19937& rng, const std::array<const char*, N>& arr) {
    return arr[std::uniform_int_distribution<std::size_t>(0, N - 1)(rng)];
}

} // namespace

std::string generate_tabletop_villain_schemes_name(std::mt19937& rng) {
    return std::string(pick(rng, kMasterminds)) + " " + pick(rng, kMethods) + " " + pick(rng, kEndgames);
}
