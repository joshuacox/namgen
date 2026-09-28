#include "places-realms_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_realms_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "ch", "sh", "ph", "br", "cr", "dr", "gr", "kr", "pr", "str", "vr", "wr", "st", "bl", "cl", "gl", "fl", "kl", "pl", "sl"};
    static constexpr std::string_view names2[] = {"a", "e", "i", "o", "u", "ea", "eo", "ia", "io", "ae"};
    static constexpr std::string_view names3[] = {"sh", "ch", "ph", "br", "cr", "dr", "gr", "st", "str", "cl", "gl", "kl", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt"};
    static constexpr std::string_view names4[] = {"a", "e", "i", "o", "a", "e", "i", "o", "u", "ea", "eo", "ia", "io"};
    static constexpr std::string_view names5[] = {"bis", "chaeus", "cia", "cion", "cyre", "dalar", "dale", "dell", "din", "dolon", "dore", "dran", "du", "gana", "gar", "garth", "ghar", "goth", "gus", "jan", "la", "lan", "lar", "las", "lion", "lon", "lyn", "mar", "mel", "melan", "mond", "mos", "mund", "nara", "nary", "nata", "nem", "net", "nia", "nica", "nium", "non", "nor", "nys", "phere", "pia", "qar", "que", "rah", "ran", "rant", "rat", "rath", "rea", "rene", "rhia", "ria", "rial", "riel", "rim", "rion", "ron", "rona", "ros", "roth", "rune", "rus", "rynn", "ryon", "sia", "sos", "spea", "tall", "tara", "terra", "tha", "thae", "thaer", "than", "thas", "ther", "this", "thra", "tia", "tika", "tion", "tis", "tope", "topia", "tora", "tria", "tuary", "var", "ven", "ver", "vion", "xar", "xath", "xus", "zan"};
    static constexpr std::string_view names6[] = {"Abandoned", "Abyss", "Ageless", "All", "Amber", "Ancestor", "Ancient", "Animated", "Aquamarine", "Arctic", "Argent", "Ash", "August", "Autumn", "Azure", "Barbarian", "Barren", "Black", "Boiling", "Bone", "Broken", "Burning", "Calm", "Celestial", "Center", "Cerulean", "Cinder", "Cloud", "Conjured", "Conscious", "Cosmic", "Covert", "Crimson", "Cyber", "Dead", "Delusion", "Demi", "Desolate", "Destiny", "Divine", "Dormant", "Double", "Dragon", "Dream", "Dual", "Dying", "Ebon", "Echo", "Eclipse", "Edge", "Elder", "Ember", "Emerald", "Empty", "Enchanted", "Enigma", "Eternal", "Ethereal", "Ever", "Everday", "Fading", "Fantasy", "Fate", "Feral", "Fierce", "Final", "Flaming", "Floating", "Flowing", "Forged", "Forsaken", "Fortune", "Fractioned", "Frenzied", "Frozen", "Future", "Gentle", "Ghost", "Giant", "Glowing", "God", "Golden", "Hallowed", "Harsh", "Hell", "Hibernating", "Hidden", "Hollow", "Howling", "Ice", "Illusion", "Imagined", "Immortal", "Infernal", "Inferno", "Injured", "Invisible", "Iron", "Ivory", "Jade", "Legend", "Lifeless", "Limbo", "Living", "Lonely", "Lunar", "Lush", "Lustrous", "Mad", "Magic", "Malachite", "Mammoth", "Manifested", "Maroon", "Merciless", "Migrating", "Mimic", "Miniature", "Miracle", "Mirage", "Mirror", "Mist", "Mock", "Monster", "Mortal", "Moving", "Multi", "Mythic", "Nebula", "Nether", "Never", "Night", "Nightmare", "Nimbus", "Noble", "Oblivion", "Obscure", "Obsidian", "Onyx", "Oracle", "Paralyzed", "Parallel", "Past", "Patriarch", "Peaceful", "Perfect", "Perpetual", "Phantom", "Portal", "Pure", "Rabid", "Rain", "Regal", "Riddle", "Rune", "Sacred", "Sanguine", "Sapphire", "Savage", "Scarlet", "Second", "Severed", "Shadow", "Shattered", "Shifting", "Shivering", "Shrouded", "Silver", "Single", "Sinking", "Skeletal", "Sky", "Slumbering", "Snow", "Solar", "Solitary", "Soul", "Specter", "Spirit", "Spring", "Steam", "Sterile", "Storm", "Summer", "Tamed", "Tempest", "Temporary", "Terminal", "Thunder", "Timeless", "Titan", "Trance", "Transient", "Treacherous", "Trial", "Twilight", "Twin", "Undying", "Utopia", "Virtual", "Vision", "Void", "Wandering", "White", "Whole", "Wild", "Windy", "Winter", "Wonder"};
    static constexpr std::string_view names7[] = {"Country", "Domain", "Dominion", "Earth", "Empire", "Expanse", "Fields", "Forest", "Isle", "Isles", "Lake", "Land", "Lands", "Moon", "Nation", "Nexus", "Ocean", "Plane", "Planet", "Province", "Reach", "Realm", "Realms", "Region", "Sanctuary", "Sanctum", "Sea", "Terrain", "Territories", "Territory", "Universe", "Vale", "Vales", "Valley", "World", "Yonder"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    if (rnd > 41) {
    while (rnd3 < 12) {
    rnd3 = rng() % std::size(names3);
    }
    }
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5];
    } else {
    rnd = rng() % std::size(names6);
    rnd2 = rng() % std::size(names7);
    names = "The " + names6[rnd] + " " + names7[rnd2];
    }
    return names;
    }
}
