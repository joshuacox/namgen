#include "fantasy-gnomes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_gnomes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "cl", "d", "fr", "g", "gn", "h", "j", "kn", "kl", "l", "m", "n", "p", "r", "sc", "sl", "sn", "sm", "t", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "a", "e", "i", "o", "u", "a", "e", "i", "y", "y", "y", "oo", "ee", "aa", "ie", "ai"};
    static constexpr std::string_view nm3[] = {"bbn", "bk", "bn", "bbr", "db", "dd", "ddw", "dn", "ddn", "gn", "gb", "k", "km", "kn", "kp", "kw", "lk", "lb", "llb", "lv", "mb", "mj", "mm", "mp", "mt", "mw", "mz", "md", "nb", "nj", "nk", "nkk", "nsb", "nsm", "nsn", "nz", "nzb", "ngn", "pn", "pp", "pr", "r", "rk", "rb", "rw", "v"};
    static constexpr std::string_view nm4[] = {"c", "ck", "g", "m", "p", "r", "rt", "ss", "st", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "bl", "c", "cl", "f", "fl", "fn", "g", "gl", "gn", "h", "l", "m", "n", "p", "ph", "sh", "sl", "sn", "sm", "t", "th", "w"};
    static constexpr std::string_view nm6[] = {"bbl", "bbn", "bn", "bl", "db", "dd", "ddl", "dl", "dw", "ddw", "dn", "ddn", "gn", "gb", "gl", "km", "kn", "kw", "lk", "lm", "lw", "lb", "llb", "llm", "ln", "lln", "lv", "mb", "mm", "mw", "md", "nb", "nk", "nkl", "nsm", "nsn", "ngl", "ngn", "pn", "pp", "pw", "pr", "r", "rb", "rw", "v"};
    static constexpr std::string_view nm7[] = {"", "", "", "l", "ll", "m", "n", "p", "r", "s", "ss", "t", "th"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "b", "bl", "c", "cl", "d", "f", "fl", "fn", "g", "gl", "gn", "h", "j", "kl", "kn", "l", "m", "n", "p", "ph", "r", "sc", "sh", "sl", "sn", "sm", "t", "th", "w", "z"};
    static constexpr std::string_view nm9[] = {"bbl", "bbn", "bk", "bn", "bl", "bbr", "db", "dd", "ddl", "dl", "dw", "ddw", "dn", "ddn", "gn", "gb", "gl", "k", "kl", "km", "kn", "kp", "kw", "lk", "lm", "lw", "lb", "llb", "llm", "ln", "lln", "lv", "mb", "mj", "mm", "mp", "mt", "mw", "mz", "md", "nb", "nj", "nk", "nkk", "nkl", "nsb", "nsm", "nsn", "nz", "nzb", "ngl", "ngn", "pn", "pp", "pw", "pr", "r", "rk", "rb", "rw", "v"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "c", "ck", "g", "l", "ll", "m", "n", "p", "r", "rt", "s", "ss", "st", "t"};
    static constexpr std::string_view nm11[] = {"b", "c", "d", "g", "k", "m", "n", "r", "v"};
    static constexpr std::string_view nm12[] = {"b", "d", "f", "h", "l", "m", "n", "s", "v", "w"};
    static constexpr std::string_view nm13[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "r", "s", "v", "w"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    if (i < 5) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5];
    } else if (i < 7) {
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm6[rnd3] + nm2[rnd4] + nm12[rnd6] + nm2[rnd7] + nm7[rnd5];
    } else {
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm2);
    names = nm5[rnd] + nm2[rnd2] + nm12[rnd6] + nm2[rnd7] + nm6[rnd3] + nm2[rnd4] + nm7[rnd5];
    }
    } else if (type == 2) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm9);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm10);
    if (i < 5) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm8);
    }
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd4] + nm10[rnd5];
    } else if (i < 7) {
    rnd6 = rng() % std::size(nm13);
    rnd7 = rng() % std::size(nm2);
    names = nm8[rnd] + nm2[rnd2] + nm9[rnd3] + nm2[rnd4] + nm13[rnd6] + nm2[rnd7] + nm10[rnd5];
    } else {
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm2);
    names = nm8[rnd] + nm2[rnd2] + nm13[rnd6] + nm2[rnd7] + nm9[rnd3] + nm2[rnd4] + nm10[rnd5];
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else if (i < 7) {
    rnd6 = rng() % std::size(nm11);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm11[rnd6] + nm2[rnd7] + nm4[rnd5];
    } else {
    rnd6 = rng() % std::size(nm12);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm11[rnd6] + nm2[rnd7] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    }
    }
    return names;
    }
}
