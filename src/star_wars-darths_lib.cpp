#include "star_wars-darths_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_darths_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "b", "br", "c", "ch", "chr", "cr", "d", "dr", "f", "g", "gl", "gr", "h", "j", "k", "kr", "kh", "l", "m", "mh", "n", "pl", "pr", "q", "r", "s", "sc", "sk", "st", "str", "sr", "t", "th", "tr", "v", "w", "wr", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "ou", "ae", "ea", "ui", "ia", "ue", "ei", "uy"};
    static constexpr std::string_view nm3[] = {"ct", "cn", "cm", "gr", "kk", "kr", "kt", "ll", "lf", "lg", "lr", "ld", "nn", "nt", "nr", "mr", "mm", "md", "rr", "rk", "rt", "st", "sn", "sm", "th", "sh", "tt", "tr", "zz"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "", "", "c", "ch", "d", "dd", "ft", "hl", "k", "l", "m", "n", "ph", "r", "rd", "rn", "rr", "s", "t", "th", "wn", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "bh", "c", "ch", "f", "fr", "g", "gh", "h", "j", "k", "kh", "l", "m", "n", "ph", "phr", "phl", "q", "r", "rh", "s", "sh", "st", "t", "tr", "th", "thr", "v", "w", "wh", "x", "xh", "z", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ae", "ia", "ie", "ei", "ui"};
    static constexpr std::string_view nm7[] = {"b", "ch", "chr", "cr", "d", "dh", "dr", "g", "gr", "gn", "gm", "gl", "k", "kn", "km", "kh", "kk", "l", "ll", "lm", "lr", "ld", "lm", "m", "mn", "mr", "mm", "n", "nn", "nr", "ns", "nz", "nl", "r", "rm", "rl", "rz", "rg", "rr", "tr", "ttr", "th", "thr", "thn", "thm", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "d", "f", "h", "l", "n", "ph", "r", "s", "sh", "ss", "th", "w", "x"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    while (rnd < 13) {
    rnd = rng() % std::size(nm5);
    }
    while (rnd5 < 10) {
    rnd5 = rng() % std::size(nm8);
    }
    names = "Darth " + nm5[rnd] + nm6[rnd2] + nm8[rnd5];
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = "Darth " + nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5];
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = "Darth " + nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    while (rnd < 10) {
    rnd = rng() % std::size(nm1);
    }
    while (rnd5 < 7) {
    rnd5 = rng() % std::size(nm4);
    }
    names = "Darth " + nm1[rnd] + nm2[rnd2] + nm4[rnd5];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = "Darth " + nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    }
    return names;
    }
}
