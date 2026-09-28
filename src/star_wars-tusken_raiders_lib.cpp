#include "star_wars-tusken_raiders_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_tusken_raiders_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"A'", "Ch'", "Gr'", "H'", "K'", "Q'", "R'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"B", "C", "Ch", "D", "G", "K", "Q", "R", "S", "Sh", "Sl", "T", "Th", "Y", "V", "Z"};
    static constexpr std::string_view nm3[] = {"a", "a", "e", "i", "o", "u", "a", "a", "o", "u", "e", "i", "o", "u", "a", "a", "o", "aa", "ai", "ee"};
    static constexpr std::string_view nm4[] = {"c", "cr", "g", "gg", "gd", "gr", "hr", "hv", "hm", "k", "kh", "kd", "kr", "kv", "km", "kn", "lm", "lr", "lh", "lg", "m", "mr", "mn", "mg", "md", "mv", "n", "nn", "nr", "nv", "q", "qq", "qh", "r", "rr", "rt", "rd", "t", "v", "z", "zh", "zr", "zd"};
    static constexpr std::string_view nm5[] = {"", "", "", "c", "d", "g", "gg", "k", "n", "q", "r", "r", "rk"};
    static constexpr std::string_view nm6[] = {"Gk", "Gr", "Gu", "Gg", "Kr", "Kk", "Ku", "Kg", "Or", "Ok", "Og", "Rr", "Rg", "Rk", "Ro", "Ru", "Ur", "Ur", "Ur"};
    static constexpr std::string_view nm7[] = {"k", "h", "r", "g", "rh", "ur", "or", "orur", "rrur", "rror", "rurr", "orr", "urr", "rorr", "rurr", "orrur", "ror", "rur", "urur"};
    static constexpr std::string_view nm8[] = {"or", "ok", "ro", "ot", "uk", "rk", "kr", "kk", "oa", "ur", "r", "tl", "ru"};
    static constexpr std::string_view nm9[] = {"r", "rs", "ruur", "ur", "rur", "urr", "rr", "rt", "urs", "rurs", "ruk"};
    static constexpr std::string_view nm10[] = {"ak", "ar", "rr", "r", "kt", "rt", "ku", "ra", "ro", "ru"};
    static constexpr std::string_view nm11[] = {"k", "r", "hr", "ur", "t", "ht", "or", "ar", "ut", "uk"};
    static constexpr std::string_view nm12[] = {"Ch", "G", "H", "Kh", "L", "Q", "R", "Rh", "Sh", "T", "Th", "V", "Y", "Z"};
    static constexpr std::string_view nm13[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "a", "e", "e", "e", "ee", "aa", "ie", "ei"};
    static constexpr std::string_view nm14[] = {"d", "g", "k", "kk", "kh", "kt", "kz", "q", "qt", "qr", "qz", "rt", "r", "rr", "rh", "rt", "x", "xt", "xr", "z", "zt", "zr"};
    static constexpr std::string_view nm15[] = {"c", "g", "gh", "k", "n", "m", "rn", "rm", "rr", "rg", "rc", "rh", "rk"};
    static constexpr std::string_view nm16[] = {"cr", "br", "b", "g", "gr", "h", "k", "kr", "l", "q", "qr", "r", "rh", "s", "sr", "sh", "t", "tr", "th", "y", "v", "z", "zr"};
    static constexpr std::string_view nm17[] = {"a", "e", "i", "o", "u", "a", "o"};
    static constexpr std::string_view nm18[] = {"c", "cr", "g", "gg", "gd", "gr", "k", "kh", "kd", "kr", "kv", "km", "kn", "n", "nn", "nr", "nv", "q", "qq", "qh", "r", "rr", "rt", "rd", "t", "v", "z", "zh", "zr", "zd"};
    static constexpr std::string_view nm19[] = {"c", "ct", "g", "gg", "k", "kt", "n", "q", "qt", "r", "rr", "rk", "rc", "rg", "rq", "rt", "rd", "tt", "t"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm16);
    rnd8 = rng() % std::size(nm17);
    rnd10 = rng() % std::size(nm19);
    if (i % 2 != 0) {
    namelast = nm16[rnd7] + nm17[rnd8] + nm19[rnd10];
    } else {
    rnd9 = rng() % std::size(nm17);
    rnd11 = rng() % std::size(nm18);
    namelast = nm16[rnd7] + nm17[rnd8] + nm18[rnd11] + nm17[rnd9] + nm19[rnd10];
    }
    if (type == 1) {
    rnd2 = rng() % std::size(nm12);
    rnd3 = rng() % std::size(nm13);
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm15);
    names = nm1[rnd] + nm12[rnd2] + nm13[rnd3] + nm15[rnd4] + " " + namelast;
    } else {
    rnd = rng() % std::size(nm14);
    rnd4 = rng() % std::size(nm13);
    names = nm12[rnd2] + nm13[rnd3] + nm14[rnd] + nm13[rnd4] + " " + namelast;
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm5);
    if (i < 3) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd5] + "  " + namelast;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd6] + nm5[rnd5] + "  " + namelast;
    }
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    if (i < 8) {
    names = nm6[rnd] + nm7[rnd2] + "'" + nm8[rnd3] + nm9[rnd4];
    } else {
    rnd5 = rng() % std::size(nm10);
    rnd6 = rng() % std::size(nm11);
    names = nm6[rnd] + nm7[rnd2] + "'" + nm8[rnd3] + nm9[rnd4] + "'" + nm10[rnd5] + nm11[rnd6];
    }
    }
    }
    return names;
    }
}
