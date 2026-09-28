#include "places-mountains_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_mountains_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Adamantine", "Ancient", "Angry", "Arctic", "Arid", "Bare", "Barren", "Beholding", "Bellowing", "Black", "Bronze", "Burning", "Calm", "Calmest", "Charmed", "Cold", "Collapsing", "Colorless", "Colossal", "Cursed", "Dangerous", "Dark", "Darkest", "Dead", "Decayed", "Decaying", "Deserted", "Desolate", "Desolated", "Diamond", "Disintegrated", "Distant", "Dominating", "Eastern", "Empty", "Enchanted", "Enormous", "Eroded", "Ethereal", "Ever Reaching", "Everlasting", "Fabled", "Faraway", "Feared", "Fearsome", "Flaring", "Forbidden", "Forested", "Fractured", "Frightening", "Frozen", "Gargantuan", "Giant", "Gigantic", "Gloomy", "Gold", "Golden", "Gray", "Grim", "Haunted", "Heaven-reaching", "Hollow", "Homeless", "Hopeless", "Huge", "Humongous", "Hungry", "Ice-crowned", "Immense", "Infernal", "Iron", "Isolated", "Jagged", "Laughing", "Lifeless", "Light", "Lightest", "Lonely", "Mammoth", "Mighty", "Mirrored", "Misty", "Moaning", "Monstrous", "Moonlit", "Motionless", "Mysterious", "Naked", "Narrow", "Neverending", "New", "Northern", "Overhanging", "Plain", "Prickly", "Quiet", "Raging", "Red", "Relentless", "Remote", "Restless", "Rocky", "Round-topped", "Rugged", "Sad", "Savage", "Scarlet", "Severed", "Shadowed", "Shadowy", "Sharp-peaked", "Shimmering", "Silver", "Slumbering", "Snowy", "Southern", "Steep", "Symmetrical", "Terraced", "Thundering", "Titanic", "Towering", "Unresting", "Unscaled", "Unwelcoming", "Vast", "Violent", "Voiceless", "Volcanic", "Welcoming", "Western", "Whispering", "White", "Windless", "Windy", "Wintry", "Withered", "Yelling"};
    static constexpr std::string_view nm2[] = {"Bluff", "Heights", "Highland", "Highlands", "Hill", "Hills", "Hillside", "Mountain", "Mountains", "Peaks", "Pinnacle", "Rise", "Slopes", "Summit", "Tips", "Tops", "Volcano"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm2);
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
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
