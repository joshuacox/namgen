#include "pathfinder-catfolks_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_catfolks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"br", "c", "cr", "dr", "f", "g", "gr", "j", "k", "kr", "m", "n", "p", "pr", "q", "qr", "r", "t", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "ou", "au", "ei"};
    static constexpr std::string_view nm3[] = {"c", "cc", "cd", "cb", "g", "gg", "gt", "gb", "gd", "k", "kk", "kh", "kt", "mb", "mk", "mq", "nq", "nk", "ng", "q", "qh", "r", "rr", "rq", "rk", "th", "w"};
    static constexpr std::string_view nm4[] = {"", "m", "n", "r", "s", "th"};
    static constexpr std::string_view nm5[] = {"", "", "", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"f", "ff", "l", "ly", "lh", "ls", "lr", "lm", "ln", "m", "my", "mh", "n", "ny", "nh", "ph", "phr", "r", "rr", "ry", "rh", "sy", "sh", "sr", "sl", "th", "ty", "y"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "h", "s"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 6) {
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm8[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = std::string(nm5[rnd]) + std::string(nm6[rnd2]) + std::string(nm7[rnd3]) + std::string(nm6[rnd4]) + std::string(nm7[rnd6]) + std::string(nm6[rnd7]) + std::string(nm8[rnd5]);
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm3[rnd6]) + std::string(nm2[rnd7]) + std::string(nm4[rnd5]);
    }
    }
    return names;
    }
}
