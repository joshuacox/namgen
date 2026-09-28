#include "pop_culture-lovecraftians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_lovecraftians_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "u", "o", "a", "ai", "aiu", "aiue", "e", "i", "ia", "iau", "iu", "o", "u", "y", "ya", "yi", "yo"};
    static constexpr std::string_view nm2[] = {"bh", "br", "c'th", "cn", "ct", "cth", "cx", "d", "d'", "g", "gh", "ghr", "gr", "h", "k", "kh", "kth", "mh", "mh'", "ml", "n", "ng", "sh", "t", "th", "tr", "v", "v'", "vh", "vh'", "vr", "x", "z", "z'", "zh"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "u", "o", "a", "e", "i", "u", "o", "ao", "aio", "ui", "aa", "io", "ou", "y"};
    static constexpr std::string_view nm4[] = {"bb", "bh", "br", "cn", "ct", "dh", "dhr", "dr", "drr", "g", "gd", "gg", "ggd", "gh", "gn", "gnn", "gr", "jh", "kl", "l", "ld", "lk", "ll", "lp", "lth", "mbr", "nd", "p", "r", "rr", "rv", "th", "thl", "thr", "thrh", "tl", "vh", "x", "xh", "z", "zh", "zt"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'dhr", "'dr", "'end", "'gn", "'ith", "'itr", "'k", "'kr", "'l", "'m", "'r", "'th", "'vh", "'x", "'zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "u", "o"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "", "", "", "", "d", "g", "h", "l", "lb", "lbh", "n", "r", "rc", "rh", "s", "sh", "ss", "st", "sz", "th", "tl", "x", "xr", "xz"};

    std::string names; size_t rnd = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm7[rnd6];
    } else {
    rnd1 = rng() % std::size(nm1);
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm1[rnd1] + nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm7[rnd6];
    }
    return names;
    }
}
