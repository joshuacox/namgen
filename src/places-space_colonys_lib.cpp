#include "places-space_colonys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_space_colonys_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aegis", "Aeon", "Aeris", "Babylon", "Aeternitas", "Aether", "Alliance", "Alpha", "Amazone", "Ancestor", "Anemone", "Angel", "Anomaly", "Apollo", "Arcadia", "Arcadis", "Arch", "Architect", "Ark", "Artemis", "Asphodel", "Asteria", "Astraeus", "Athena", "Atlas", "Atmos", "Aura", "Aurora", "Awe", "Azura", "Azure", "Baldur", "Beacon", "Blue Moon", "Borealis", "Burrow", "Caelestis", "Canaan", "Century", "Chrono", "Chronos", "Crescent", "Curator", "Curiosity", "Data", "Dawn", "Daydream", "Demeter", "Dogma", "Dream", "Dune", "Ecstacys", "Eir", "Elyse", "Elysium", "Empyrea", "Ender", "Enigma", "Eos", "Epiphany", "Epitome", "Erebus", "Escort", "Eternis", "Eternity", "Exposure", "Fable", "Father", "Fauna", "Felicity", "Flora", "Fortuna", "Frontier", "Gaia", "Galaxy", "Genesis", "Genius", "Glory", "Guardian", "Halo", "Heirloom", "Helios", "Hemera", "Hera", "Heritage", "Hermes", "Horus", "Hymn", "Hyperion", "Hypnos", "Ignis", "Illume", "Inception", "Infinity", "Isis", "Janus", "Juno", "Legacy", "Liberty", "Lore", "Lucent", "Lumina", "Luminous", "Luna", "Lunis", "Magni", "Mammoth", "Mani", "Marvel", "Memento", "Minerva", "Miracle", "Mother", "Muse", "Mystery", "Mythos", "Nebula", "Nemesis", "Nemo", "Neo", "Nero", "Nimbus", "Nott", "Nova", "Novis", "Nox", "Nyx", "Odyssey", "Olympus", "Omega", "Oracle", "Orbital", "Origin", "Orphan", "Osiris", "Outlander", "Parable", "Paradox", "Paragon", "Pedigree", "Phantasm", "Phantom", "Phenomenon", "Phoenix", "Pilgrim", "Pioneer", "Prism", "Prodigy", "Prometheus", "Prophecy", "Proto", "Radiance", "Rebus", "Relic", "Revelation", "Reverie", "Rogue", "Rune", "Saga", "Sancus", "Scout", "Selene", "Serenity", "Settler", "Shangris", "Shepherd", "Shu", "Sol", "Solas", "Spectacle", "Specter", "Spectrum", "Spire", "Symbolica", "Tartarus", "Terminus", "Terra", "Terran", "Terraria", "Themis", "Tiberius", "Titan", "Titanus", "Torus", "Tranquility", "Trivia", "Utopis", "Valhalla", "Vanguard", "Vanquish", "Vesta", "Vestige", "Victoria", "Virtue", "Visage", "Voyage", "Vulcan", "Warden", "Yggdrasil", "Zeus", "Zion"};
    static constexpr std::string_view nm2[] = {"", "Colony", "Station", "Colony", "Station", "Base", "Terminal", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    return names;
    }
}
