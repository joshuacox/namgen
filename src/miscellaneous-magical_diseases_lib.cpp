#include "miscellaneous-magical_diseases_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_magical_diseases_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Aether", "Aethereal", "Alacadabra", "Angelic", "Arcane", "Astral", "Aura", "Banishing", "Banshee", "Basilisk", "Bog", "Celestial", "Centaur", "Chakra", "Changeling", "Chaos", "Charm", "Charmed", "Chimera", "Cipher", "Clairvoyance", "Clairvoyant", "Conjuring", "Coven", "Crystal", "Demon", "Diabolical", "Divine", "Djinni", "Dowsing", "Dragon", "Dryad", "Echo", "Ecto", "Ectoplasm", "Eerie", "Elemental", "Enchanted", "Enigma", "Ethereal", "Evocation", "Fairy", "Familiar", "Fire", "Flashing", "Flux", "Flying", "Fortune", "Giant's", "Glamour", "Goblin", "Griffin", "Grimoire", "Harpy", "Haunted", "Hellion", "Hex", "Hexing", "Hocuspocus", "Horror", "Hypnosis", "Hypnotic", "Illusion", "Infernal", "Invisible", "Juju", "Kelpie", "Lamia", "Levitation", "Lich", "Lucifer", "Magician's", "Magnetic", "Malediction", "Menace", "Miracle", "Mojo", "Morphing", "Mutant", "Mystic", "Nether", "Ogre", "Omen", "Oracle", "Ouija", "Pandora", "Paragon", "Paranormal", "Pendulum", "Pentacle", "Phantom", "Phoenix", "Pixie", "Prophecy", "Prowess", "Psi", "Psionic", "Psychic", "Pyro", "Qi", "Rune", "Scale", "Scrying", "Seance", "Shade", "Shadow", "Sigil", "Siren", "Skeleton", "Sorcerous", "Specter", "Spectral", "Spirit", "Tantra", "Titan", "Totem", "Totemic", "Transmutation", "Treant", "Troll", "Undine", "Vampire", "Vanishing", "Void", "Voodoo", "Warlock", "Wendigo", "Werewolf", "Witcher", "Witches'", "Wither", "Wizard", "Wyvern", "Zombie"};
    static constexpr std::string_view nm2[] = {"Ache", "Aches", "Affliction", "Amnesia", "Anemia", "Blight", "Blindness", "Blisters", "Blood", "Breakdown", "Burn", "Chills", "Cold", "Cough", "Cramps", "Curse", "Death", "Decay", "Delirium", "Delusion", "Dementia", "Disease", "Disorder", "Doom", "Drip", "Fatigue", "Fever", "Flu", "Gut", "Haze", "Infection", "Insanity", "Limb", "Madness", "Malady", "Mark", "Plague", "Pox", "Puffs", "Rage", "Rash", "Rot", "Shakes", "Sickness", "Sores", "Spasm", "Spasms", "Syndrome", "Thirst", "Vapors", "Virus", "Warts"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    return names;
    }
}
