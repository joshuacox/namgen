#include "places-lakes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_lakes_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Abysmal", "Alligator", "Amazon", "Arctic", "Arrowhead", "Bamboo", "Barren", "Black", "Bland", "Blue", "Bogbeast", "Boiling", "Bottomless", "Brilliant", "Bursting", "Calm", "Calmest", "Charmed", "Cheerless", "Cobalt", "Cold", "Coral", "Crocodile", "Crystal", "Cursed", "Dancing", "Dark", "Darkest", "Dead", "Deep", "Deepest", "Dense", "Depraved", "Distant", "Dragonfly", "Dread", "Dreaded", "Eastern", "Emerald", "Empty", "Enchanted", "Ethereal", "Fair", "Flat", "Flowing", "Fluorescent", "Foaming", "Forbidden", "Frothy", "Frozen", "Furthest", "Glassy", "Gleaming", "Glistening", "Grave", "Gray", "Green", "Harmonious", "Harmony", "Heartless", "Heaving", "Hungry", "Infernal", "Infinite", "Invisible", "Iris", "Isolated", "Jade", "Laughing", "Lifeless", "Lilypad", "Living", "Lonely", "Lotus", "Lucent", "Majestic", "Mesmerizing", "Midnight", "Mighty", "Mirror", "Mirrored", "Misty", "Moaning", "Moon-lit", "Motionless", "Moving", "Narrow", "Neglected", "New", "Northern", "Peaceful", "Perfumed", "Pleasant", "Primeval", "Pristine", "Quiet", "Raging", "Rainy", "Red", "Reflecting", "Relaxing", "Restless", "Rippling", "Rocking", "Rolling", "Rough", "Rushing", "Salty", "Sandy", "Sanguine", "Sapphire", "Savage", "Serene", "Shaded", "Shadow", "Shady", "Shimmering", "Silent", "Sleeping", "Soundless", "Southern", "Spacious", "Sparkling", "Sterile", "Sunny", "Surging", "Tadpole", "Teal", "Thundering", "Tinted", "Tortoise", "Tranquil", "Tropic", "Troubled", "Turbulent", "Turquoise", "Turtle", "Ugly", "Uncanny", "Unknown", "Unstable", "Vast", "Violent", "Walled", "Wasted", "Wasteful", "Wasting", "Waveless", "Western", "Whispering", "White", "Wild", "Windy", "Wondering", "Wrinkled", "Yearning"};
    static constexpr std::string_view nm2[] = {"Basin", "Cove", "Depths", "Domain", "Expanse", "Gorge", "Lagoon", "Lake", "Loch", "Pond", "Reservoir", "Shallows", "Waters"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm2[rnd2];
    } else if (i < 7) {
    rnd = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm7);
    names = nm3[rnd] + nm4[rnd3] + nm7[rnd4] + " " + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm3[rnd] + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm7[rnd6] + " " + nm2[rnd2];
    }
    return names;
    }
}
