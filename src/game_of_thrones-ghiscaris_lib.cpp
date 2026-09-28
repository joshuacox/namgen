#include "game_of_thrones-ghiscaris_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_ghiscaris_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "dr", "g", "gr", "h", "kr", "m", "pr", "q", "r", "sr", "sh", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "ei", "i", "o", "e", "a", "e", "i", "o", "a", "a"};
    static constexpr std::string_view nm3[] = {"dn", "d", "gh", "ghd", "gn", "nd", "md", "k", "kh", "kn", "kl", "q", "qh", "qn", "rd", "rn", "rm", "sn", "zd", "zh", "zn", "zm", "zl"};
    static constexpr std::string_view nm4[] = {"hr", "hl", "k", "l", "n", "q", "r", "s", "z"};
    static constexpr std::string_view nm5[] = {"zo", "na", "mo"};
    static constexpr std::string_view nm6[] = {"Ch", "D", "G", "H", "K", "L", "M", "N", "P", "Pr", "R", "S", "Sh", "Z", "Zh"};
    static constexpr std::string_view nm7[] = {"a", "e", "i", "o", "a", "a"};
    static constexpr std::string_view nm8[] = {"dn", "g", "gd", "ghd", "gn", "nd", "n", "m", "md", "kh", "l", "q", "qh", "qn", "r", "rr", "sh", "ss", "zz", "zd", "zh", "zn", "zm", "zl"};
    static constexpr std::string_view nm9[] = {"", "", "", "d", "dh", "g", "gh", "h", "k", "l", "m", "n", "p", "qu", "r", "rh", "sh", "yh", "zh", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "u", "o", "a", "a"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "dh", "g", "hn", "hz", "hl", "kn", "kl", "l", "llh", "md", "nd", "q", "qu", "qq", "r", "rr", "rd", "sh", "sn", "z", "zk", "zz", "zn", "zd", "zh"};
    static constexpr std::string_view nm12[] = {"", "a", "e", "i", "u", "o", "a", "a"};
    static constexpr std::string_view nm13[] = {"", "", "", "hl", "k", "n", "q", "r", "z", "zn"};

    std::string names; std::string names1; std::string names2; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    rnd12 = rng() % std::size(nm12);
    rnd13 = rng() % std::size(nm13);
    names2 = nm9[rnd9] + nm10[rnd10] + nm11[rnd11] + nm12[rnd12] + nm13[rnd13];
    if (rnd11 < 5) {
    rnd12 = 0;
    } else {
    while (rnd12 == 0) {
    rnd12 = rng() % std::size(nm12);
    }
    }
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm8);
    rnd6 = rng() % std::size(nm7);
    names1 = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm7[rnd4] + nm8[rnd5] + nm7[rnd6];
    names = names1 + " " + capitalize(names2);
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    names1 = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    names = capitalize(names1) + " " + nm5[rnd6] + " " + capitalize(names2);
    }
    return names;
    }
}
