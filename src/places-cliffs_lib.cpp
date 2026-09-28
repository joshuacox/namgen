#include "places-cliffs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_cliffs_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Adamantine", "Albatross", "Ancient", "Angry", "Arctic", "Arid", "Bare", "Basalt", "Basanite", "Bellowing", "Black", "Black Cavern", "Blackrock", "Blazing", "Broken", "Broken Ship", "Bronze", "Burning", "Calm", "Clay", "Claystone", "Clouded", "Collapsing", "Colossal", "Cracking", "Crumbling", "Crushing", "Cursed", "Cyclone", "Dark", "Dead", "Desolate", "Diamond", "Distant", "Eagle", "Eastern", "Ebon", "Empty", "Enchanted", "Eroded", "Ever Reaching", "Fabled", "Faraway", "Feared", "Fearsome", "Fishermen", "Flower", "Forbidden", "Foxtail", "Fractured", "Frightening", "Frozen", "Giant", "Gloomy", "Golden", "Granite", "Gray", "Grim", "Growling", "Guardian", "Haunted", "Hidden", "Hidden Gold", "Hollow", "Hooded", "Hopeless", "Howling", "Hungry", "Hurricane", "Ice-Crowned", "Iced", "Icy", "Infernal", "Iron", "Ironbeak", "Ivory", "Jagged", "Killer Whale", "Laughing", "Lifeless", "Limestone", "Lobster", "Lonely", "Mammoth", "Marble", "Mermaid", "Mighty", "Mirrored", "Misty", "Moaning", "Moonlit", "Mountain Goat", "Mumbling", "Murky", "Musselbay", "Mysterious", "Narrow", "Neverending", "Northern", "Obsidian", "Oyster", "Peaceful", "Penguin", "Petal", "Pinetree", "Plain", "Pristine", "Quiet", "Rabbit Ear", "Raging", "Ravenclaw", "Red", "Restless", "Roaring", "Rock Lobster", "Rocky", "Rugged", "Sacred", "Sad", "Salmon", "Sandstone", "Sandy", "Savage", "Scarlet", "Scented", "Screaming", "Screeching", "Sea Gull", "Seal", "Serpent", "Severed", "Shadowed", "Shattered", "Shattering", "Shimmering", "Sighing", "Silent", "Silver", "Silver Cavern", "Silverrock", "Slippery", "Slumbering", "Snaketail", "Snowy", "Soft", "Southern", "Sterile", "Stonetalon", "Storm", "Stormy", "Sunken Ship", "Tempest", "Thunder", "Thundering", "Thunderrock", "Thunderstorm", "Titan", "Tradepost", "Treachorous", "Violent", "Voiceless", "Volcanic", "Wailing", "Warthog", "Western", "Whimpering", "Whining", "Whirlwind", "Whispering", "Whisperwind", "White", "White Feather", "Wild", "Windless", "Windy"};
    static constexpr std::string_view names2[] = {"Cliff", "Cliffs", "Fjord", "Fjords", "Wall", "Crag", "Bluff", "Bluffs", "Ravine", "Crevice", "Gorge", "Chasm", "Canyon", "Abyss", "Gulch"};
    static constexpr std::string_view names3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view names4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = "The " + names1[rnd] + " " + names2[rnd2];
    return names;
    } else if (i < 8) {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names7);
    rnd4 = rng() % std::size(names2);
    names = names3[rnd] + names4[rnd2] + names7[rnd3] + " " + names2[rnd4];
    return names;
    } else {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names5);
    rnd4 = rng() % std::size(names6);
    rnd5 = rng() % std::size(names7);
    rnd6 = rng() % std::size(names2);
    names = names3[rnd] + names4[rnd2] + names5[rnd3] + names6[rnd4] + names7[rnd5] + " " + names2[rnd6];
    return names;
    }
    }
}
