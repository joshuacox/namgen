#include "miscellaneous-molecules_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_molecules_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "deca", "di", "duo", "hepta", "hexa", "hydra", "hydro", "hypo", "iso", "mono", "octa", "penta", "tetra", "tri"};
    static constexpr std::string_view nm2[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o"};
    static constexpr std::string_view nm3[] = {"b", "br", "c", "ch", "chl", "chr", "cl", "d", "f", "fl", "fr", "g", "gl", "h", "j", "k", "l", "m", "n", "p", "ph", "pl", "pr", "ps", "r", "rh", "s", "sh", "sp", "st", "str", "t", "th", "tr", "v", "w", "z"};
    static constexpr std::string_view nm4[] = {"b", "bd", "br", "bsc", "c", "cc", "cch", "ch", "chl", "chr", "cl", "cr", "ct", "d", "dr", "dv", "f", "ff", "fl", "g", "gl", "gn", "h", "k", "l", "lb", "lc", "lch", "ldr", "lf", "lg", "ll", "lp", "lph", "lpr", "lt", "m", "mm", "mn", "mph", "n", "nc", "nd", "nh", "nk", "nn", "ns", "nt", "nth", "nthr", "nz", "p", "ph", "phth", "pp", "pr", "ps", "pt", "pth", "q", "rb", "rchl", "rd", "rf", "rg", "rh", "rk", "rl", "rn", "rph", "rq", "rr", "rrh", "rs", "rt", "rv", "s", "sc", "sg", "sp", "sph", "spl", "ss", "st", "str", "t", "th", "tr", "v", "x", "z"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "ae", "aa", "ai", "au", "ea", "ee", "ei", "eo", "eu", "ia", "ie", "io", "iu", "ua", "ue", "ui", "ya", "ye", "yo"};
    static constexpr std::string_view nm6[] = {"aene", "an", "ane", "ar", "as", "ase", "asy", "ate", "eide", "ein", "eite", "el", "ene", "er", "ial", "id", "ide", "iene", "in", "ine", "iol", "ite", "ium", "oate", "ocin", "ol", "ole", "on", "one", "or", "ose", "ox", "oxin", "uene", "um", "ur", "ycin", "yde", "yl", "yme", "yn"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4] + nm4[rnd5] + nm6[rnd6];
    } else if (i < 7) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm4);
    rnd8 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4] + nm4[rnd5] + nm5[rnd6] + nm4[rnd7] + nm6[rnd8];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm4);
    rnd8 = rng() % std::size(nm5);
    rnd9 = rng() % std::size(nm4);
    rnd10 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4] + nm4[rnd5] + nm5[rnd6] + nm4[rnd7] + nm5[rnd8] + nm4[rnd9] + nm6[rnd10];
    }
    return names;
    }
}
