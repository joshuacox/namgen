#include "inheritance_cycle-dwarfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_inheritance_cycle_dwarfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "b", "br", "bl", "d", "dr", "f", "fl", "fr", "g", "gr", "h", "ht", "hv", "k", "kr", "kv", "m", "n", "r", "sk", "sv", "th", "thr", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "û", "ó", "é", "á", "î", "â", "ei", "ie", "eo"};
    static constexpr std::string_view nm3[] = {"d", "dg", "dr", "fn", "g", "gn", "gd", "gm", "k", "kr", "kksv", "kn", "km", "ldh", "ldhr", "lm", "m", "mm", "mn", "nd", "ndf", "nn", "nndr", "r", "rd", "rg", "rgh", "rh", "rm", "rr", "s", "st", "th", "thg", "thm", "v", "w"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "fk", "g", "k", "kk", "l", "ldn", "m", "n", "nd", "r", "rd", "rk", "rm", "rn", "rst", "rv", "s", "st", "th"};
    static constexpr std::string_view nm5[] = {"bh", "d", "dh", "f", "fl", "fr", "fn", "g", "gl", "gh", "gl", "h", "hn", "hr", "hl", "hv", "m", "n", "mh", "s", "th", "v"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "û", "í", "á", "ûi", "io", "îo"};
    static constexpr std::string_view nm7[] = {"d", "df", "dr", "fn", "fl", "fr", "gn", "gm", "gh", "l", "ln", "lm", "lr", "ld", "ll", "m", "mr", "mn", "mh", "md", "mm", "nd", "nr", "nh", "nn", "n", "ngl", "nh", "r", "rd", "rdr", "rn", "rh", "s", "ss", "th", "v", "w"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "n", "nn", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (rnd5 < 5) {
    rnd4 = 0;
    }
    if (i < 6) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd6] + nm7[rnd7] + nm6[rnd4] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 3) {
    if (rnd < 4) {
    while (rnd4 < 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4];
    } else if (i < 7) {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm3[rnd6] + nm2[rnd7] + nm4[rnd4];
    }
    }
    return names;
    }
}
