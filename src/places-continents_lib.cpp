#include "places-continents_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_continents_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "dr", "gr", "kr", "pr", "tr", "vr", "wr", "str", "bl", "cl", "fl", "gl", "kl", "pl", "sl", "vl", "ch", "ph", "sh", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names2[] = {"a", "e", "i", "o", "u", "eu", "eo", "ea", "ei", "ai", "au", "ae", "io", "ia", "iu", "ua"};
    static constexpr std::string_view names3[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "w", "y", "z", "br", "cr", "dr", "gr", "kr", "tr", "vr", "wr", "str", "bl", "cl", "pl", "sl", "ch", "ph", "sh"};
    static constexpr std::string_view names4[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "dr", "gr", "kr", "pr", "tr", "str", "ph", "sh"};
    static constexpr std::string_view names5[] = {"aes", "ai", "all", "an", "and", "ane", "ari", "as", "ath", "ax", "ea", "ela", "en", "end", "eon", "era", "eron", "es", "esh", "eth", "ia", "ias", "ica", "in", "ios", "ira", "is", "ish", "ith", "ix", "oa", "on", "one", "or", "ora", "oris", "os", "oth", "ox", "oya", "uan", "uin", "ul", "un", "une", "ura", "us", "ush", "uth", "ux"};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names6);
    rnd3 = rng() % std::size(names3);
    if (rnd > 20) {
    while (rnd3 > 17) {
    rnd3 = rng() % std::size(names3);
    }
    }
    rnd6 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names5[rnd6];
    } else if (i < 6) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd6 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names5[rnd6];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    if (rnd > 20) {
    while (rnd3 > 17) {
    rnd3 = rng() % std::size(names3);
    }
    }
    rnd4 = rng() % std::size(names2);
    if (rnd2 > 4) {
    while (rnd4 > 4) {
    rnd4 = rng() % std::size(names2);
    }
    }
    rnd5 = rng() % std::size(names4);
    if (rnd > 17 || rnd > 20) {
    while (rnd5 > 19) {
    rnd5 = rng() % std::size(names4);
    }
    }
    rnd6 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names2[rnd4] + names4[rnd5] + names5[rnd6];
    }
    return names;
    }
}
