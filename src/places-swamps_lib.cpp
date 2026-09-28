#include "places-swamps_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_swamps_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Abysmal", "Alligator", "Amazon", "Ancient", "Arching", "Arrowhead", "Bamboo", "Barren", "Billowy", "Black", "Bland", "Blue", "Bogbeast", "Boiling", "Boundless", "Brown", "Bursting", "Calm", "Calmest", "Charmed", "Cheerless", "Clouded", "Cobalt", "Cold", "Coral", "Crocodile", "Crystal", "Cursed", "Dancing", "Dark", "Darkest", "Dead", "Deep", "Deepest", "Dense", "Depraved", "Distant", "Dragonfly", "Dread", "Dreaded", "Drowning", "Dying", "Eastern", "Emerald", "Empty", "Enchanted", "Ethereal", "Ever Reaching", "Flat", "Flowing", "Foaming", "Foggy", "Forbidden", "Frog", "Frozen", "Furthest", "Gleaming", "Glistening", "Grave", "Gray", "Green", "Harmonious", "Harmony", "Heartless", "Heaving", "Hidden", "Homeless", "Hungry", "Infernal", "Infested", "Infinite", "Invisible", "Isolated", "Jade", "Laughing", "Lifeless", "Lilypad", "Living", "Lonely", "Lotus", "Lucent", "Majestic", "Mesmerizing", "Mighty", "Mirrored", "Misty", "Moaning", "Molten", "Moon-lit", "Mosquito", "Motionless", "Moving", "Mushy", "Narrow", "Neglected", "New", "Northern", "Peaceful", "Perfumed", "Piranha", "Pleasant", "Primeval", "Quiet", "Raging", "Rainy", "Red", "Restless", "Rippling", "Rocking", "Rolling", "Rough", "Rushing", "Sandy", "Sanguine", "Savage", "Serene", "Serpent", "Shimmering", "Silent", "Sleeping", "Slumbrous", "Soundless", "Southern", "Spacious", "Sparkling", "Sterile", "Sunny", "Surging", "Thundering", "Tinted", "Toad", "Tortoise", "Tossing", "Toxic", "Tranquil", "Treacherous", "Tropic", "Troubled", "Turbulent", "Turquoise", "Turtle", "Uncanny", "Unfathomed", "Unknown", "Unstable", "Vast", "Venom", "Violent", "Walled", "Wasted", "Wasteful", "Western", "Whispering", "White", "Wild", "Willow", "Windy", "Wondering", "Wrinkled", "Yearning"};
    static constexpr std::string_view nm2[] = {"Abyss", "Basin", "Bog", "Bowels", "Cove", "Glades", "Labyrinth", "Mangrove", "Marsh", "Mire", "Morass", "Polder", "Quag", "Quagmire", "Slough", "Swamp", "Waters", "Wetlands"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    if (i < 2) {
    rnd1 = rng() % std::size(nm1);
    names = "The " + nm1[rnd1] + " " + nm2[rnd2];
    } else if (i < 4) {
    rnd1 = rng() % std::size(nm1);
    names = nm1[rnd1] + " " + nm2[rnd2];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm6);
    names = nm3[rnd3] + nm4[rnd4] + nm6[rnd7] + " " + nm2[rnd2];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm6);
    names = nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm4[rnd6] + nm6[rnd7] + " " + nm2[rnd2];
    }
    return names;
    }
}
