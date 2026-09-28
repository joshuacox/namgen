#include "star_wars-dugs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_wars_dugs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "d", "g", "gr", "j", "k", "n", "p", "pr", "r", "s", "t", "tr", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ei", "ou", "aa", "ai"};
    static constexpr std::string_view nm3[] = {"b", "br", "bh", "d", "dd", "dw", "g", "gn", "gr", "gw", "gg", "k", "kw", "kh", "ln", "lw", "lg", "lb", "lt", "nr", "nb", "nd", "ng", "ns", "rd", "r", "rg", "rn", "s", "sw", "ss", "w"};
    static constexpr std::string_view nm4[] = {"", "", "", "d", "hx", "n", "s", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "d", "g", "gr", "j", "k", "n", "p", "pr", "r", "s", "t", "tr", "v"};
    static constexpr std::string_view nm6[] = {"", "", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"d", "n", "r", "s"};

    std::string namelast; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd2b = 0; size_t rnd2c = 0; size_t rnd2d = 0; size_t rnd2e = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd3c = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd2b = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd2d = rng() % std::size(nm2);
    rnd3c = rng() % std::size(nm3);
    rnd2e = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    namelast = nm3[rnd5] + nm2[rnd2d] + nm3[rnd3c] + nm2[rnd2e] + nm7[rnd7] + nm6[rnd6];
    if (i < 5) {
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd2b] + nm4[rnd4] + " " + namelast;
    } else {
    rnd3b = rng() % std::size(nm3);
    rnd2c = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd2b] + nm3[rnd3b] + nm2[rnd2c] + " " + namelast;
    }
    return names;
    }
}
