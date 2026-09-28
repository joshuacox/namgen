#include "places-snowlands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_snowlands_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Aquamarine", "Arctic", "Avalanche", "Azure", "Blasting", "Bleak", "Blizzard", "Bone-Chilling", "Boreal", "Brilliant", "Chillbreath", "Chillwind", "Coldwind", "Cracking", "Crisp", "Crystal", "Crystalline", "Diamond", "Flurry", "Freezing", "Frigid", "Frost", "Frostbite", "Frostbreath", "Frosted", "Frostfever", "Frostfinger", "Frostfire", "Frozen", "Ghostly", "Glacial", "Glacier", "Glazed", "Glimmering", "Ice Crystal", "Ice Floe", "Ice Needle", "Iceberg", "Icebound", "Icecap", "Iced", "Iceshelf", "Icicle", "Icy", "Igloo", "Ivory", "Meltwater", "Milky", "Mirror", "Mute", "Muted", "Nevermelting", "Northbound", "Northern", "Numb", "Pale", "Pearly", "Penguin", "Permafrost", "Petrified", "Polar", "Powder", "Quiet", "Quivering", "Raw", "Reflecting", "Shattering", "Shimmering", "Shivering", "Shuddering", "Silent", "Silver", "Silvery", "Sleeted", "Sliding", "Slippery", "Snow Angel", "Snow Crystal", "Snow Owl", "Snow Pack", "Snow Storm", "Snowbank", "Snowcap", "Snowdrift", "Snowfall", "Snowflake", "Snowman", "Snowslide", "Snowy", "Solid", "Soundless", "Sparkling", "Thundersnow", "Twinkling", "Wailing", "Weeping", "Whimpering", "Whispering", "White", "Winter", "Yowling"};
    static constexpr std::string_view names2[] = {"Desert", "Tundra", "Taiga", "Forests", "Expanse", "Fields", "Flatlands", "Plains"};
    static constexpr std::string_view names3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names4[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};
    static constexpr std::string_view names8[] = {"Tundra", "Taiga", "Expanse", "Snow Fields", "Snowlands", "Snow Plains", "Ice Fields", "Icelands", "Ice Plains"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = "The " + names1[rnd] + " " + names2[rnd2];
    } else {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names5);
    rnd4 = rng() % std::size(names6);
    rnd5 = rng() % std::size(names7);
    rnd6 = rng() % std::size(names8);
    names = "The " + names3[rnd] + names4[rnd2] + names5[rnd3] + names6[rnd4] + names7[rnd5] + " " + names8[rnd6];
    }
    return names;
    }
}
