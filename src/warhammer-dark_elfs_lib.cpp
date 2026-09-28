#include "warhammer-dark_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_dark_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"c", "d", "g", "k", "l", "m", "n", "q", "r", "t", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ou", "au"};
    static constexpr std::string_view nm3[] = {"c", "cc", "cr", "ch", "g", "gh", "gr", "gn", "k", "kh", "kr", "kk", "kz", "l", "ll", "lk", "lc", "lg", "n", "nn", "nk", "r", "rv", "rk", "rc", "rg", "rz", "rl", "tr", "th", "vr", "v", "c", "g", "k", "l", "n", "r", "v", "c", "g", "k", "l", "n", "r", "v", "c", "g", "k", "l", "n", "r", "v"};
    static constexpr std::string_view nm4[] = {"c", "k", "l", "n", "r", "s", "t", "th"};
    static constexpr std::string_view nm5[] = {"c", "f", "h", "l", "m", "n", "r", "s", "sh", "th", "v"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o"};
    static constexpr std::string_view nm7[] = {"b", "bh", "c", "ch", "gh", "gg", "h", "hh", "kh", "l", "ll", "lr", "ln", "lv", "r", "rr", "rt", "rl", "rs", "rn", "rv", "s", "ss", "sh", "t", "tt", "th", "v", "vh", "b", "c", "h", "l", "r", "s", "t", "v", "kh", "b", "c", "h", "l", "r", "s", "t", "v", "kh"};
    static constexpr std::string_view nm8[] = {"h", "n", "l", "sh", "s", "th", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"amber", "ash", "battle", "blood", "cinder", "dark", "dawn", "dead", "death", "doom", "dread", "dusk", "dust", "ember", "fall", "fallen", "fell", "fire", "flame", "gloom", "grim", "haze", "hell", "nether", "night", "pyre", "rage", "rain", "shade", "shadow", "silent", "skull", "steel", "storm", "thunder", "void", "war", "wild"};
    static constexpr std::string_view nm10[] = {"arm", "arrow", "axe", "bane", "basher", "binder", "blade", "blaze", "bleeder", "blight", "breaker", "bringer", "caller", "cleaver", "crusher", "cutter", "eye", "eyes", "fall", "fury", "grip", "hand", "heart", "hunter", "mantle", "maul", "might", "more", "reaper", "reaver", "rider", "ripper", "runner", "scar", "seeker", "shade", "shadow", "shard", "slayer", "sorrow", "stalker", "stride", "strike", "striker", "surge", "taker"};

    std::string nameL; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    while (nm9[rnd] == nm10[rnd2]) {
    rnd2 = rng() % std::size(nm10);
    }
    nameL = nm9[rnd] + nm10[rnd2];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameL;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + nm8[rnd5] + " " + nameL;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameL;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + nameL;
    }
    }
    return names;
    }
}
