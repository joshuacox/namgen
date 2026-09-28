#include "pathfinder-dwarfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_dwarfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "br", "d", "dr", "f", "g", "gr", "h", "j", "k", "m", "r", "sr", "st", "str", "t", "tr", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "y", "y", "aa", "ai", "oo", "uu", "io", "io"};
    static constexpr std::string_view nm3[] = {"b", "br", "bm", "bn", "cr", "cd", "cn", "cm", "d", "dd", "dg", "dn", "dm", "g", "gr", "gn", "gm", "gr", "gg", "gd", "k", "kk", "kl", "kn", "l", "ld", "lb", "lbr", "ldr", "lg", "lgr", "lm", "lk", "mg", "md", "n", "nf", "nm", "nth", "ng", "ngr", "ndr", "nr", "r", "rg", "rgr", "rs", "rst", "rd", "rb", "v", "zm", "zb", "zd"};
    static constexpr std::string_view nm4[] = {"c", "ck", "d", "dd", "g", "k", "l", "ls", "ld", "m", "n", "r", "rd", "rsk", "rg", "t"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "b", "bh", "d", "dr", "f", "g", "gr", "gh", "h", "k", "kh", "l", "m", "n", "r", "s", "sr", "t", "thr", "y", "v", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"bn", "bh", "bb", "b", "cw", "cn", "d", "dw", "dn", "dg", "dd", "dr", "dl", "h", "hn", "hl", "hg", "gn", "gl", "gw", "gr", "gv", "k", "kk", "l", "ll", "ld", "lw", "lgr", "lgw", "lb", "lk", "m", "mm", "mw", "mgw", "mr", "n", "nd", "ng", "ngr", "ngv", "nn", "nngv", "nw", "r", "rg", "rgw", "rl", "rb", "s", "ss", "tr", "v", "vr", "vl", "z", "zl", "zw"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "l", "ll", "m", "n", "mn", "s", "r", "t", "th"};
    static constexpr std::string_view nm9[] = {"b", "br", "bh", "d", "dr", "f", "g", "gr", "gh", "h", "j", "k", "kh", "l", "m", "n", "r", "s", "sr", "st", "str", "t", "thr", "tr", "v", "w", "y", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "a", "e", "o", "u", "a", "o", "u", "a", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "o", "u", "y", "y"};
    static constexpr std::string_view nm11[] = {"b", "bb", "bh", "bm", "bn", "br", "cd", "cm", "cn", "cr", "cw", "d", "dd", "dg", "dl", "dm", "dn", "dr", "dw", "g", "gd", "gg", "gl", "gm", "gn", "gr", "gv", "gw", "h", "hg", "hl", "hn", "k", "kk", "kl", "kn", "l", "lb", "lbr", "ld", "ldr", "lg", "lgr", "lgw", "lk", "ll", "lm", "lw", "m", "md", "mg", "mgw", "mm", "mr", "mw", "n", "nd", "ndr", "nf", "ng", "ngr", "ngv", "nm", "nn", "nngv", "nr", "nth", "nw", "r", "rb", "rd", "rg", "rgr", "rgw", "rl", "rs", "rst", "s", "ss", "tr", "v", "vl", "vr", "z", "zb", "zd", "zl", "zm", "zw"};
    static constexpr std::string_view nm12[] = {"b", "c", "ck", "d", "dd", "g", "h", "k", "l", "ll", "ls", "ld", "m", "n", "mn", "r", "rd", "rsk", "rg", "s", "t", "th"};
    static constexpr std::string_view nm13[] = {"Amber", "Axe", "Battle", "Black", "Blaze", "Boulder", "Bright", "Bronze", "Cinder", "Cloud", "Cold", "Common", "Crag", "Dark", "Deep", "Dew", "Earth", "Ember", "Fair", "Fire", "Fist", "Flame", "Flat", "Flint", "Free", "Full", "Fuse", "Gold", "Grand", "Great", "Hammer", "Hard", "Heavy", "High", "Humble", "Iron", "Keen", "Lone", "Low", "Molten", "Noble", "Plain", "Pride", "Proud", "Pyre", "Rock", "Rumble", "Shield", "Silent", "Simple", "Single", "Soft", "Solid", "Steel", "Stern", "Stone", "Storm", "Stout", "Strong", "Terra", "Thunder", "Titan", "True", "War", "Wild", "Winter", "Wise"};
    static constexpr std::string_view nm14[] = {"arm", "bash", "beam", "beard", "belly", "bend", "blaze", "bluff", "bough", "brace", "brand", "breath", "brew", "brow", "crest", "crusher", "dew", "fall", "fell", "flare", "flow", "force", "forge", "fury", "gaze", "gem", "gleam", "glide", "glow", "grip", "guard", "gut", "hair", "hand", "heart", "helm", "hide", "horn", "ingot", "mane", "mantle", "maul", "might", "more", "pelt", "punch", "ridge", "roar", "scar", "shade", "shadow", "shard", "shot", "shout", "sky", "snow", "spark", "steam", "strength", "stride", "strike", "surge", "sword", "thorn", "track", "ward"};

    std::string nameLast; std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm10);
    rnd10 = rng() % std::size(nm12);
    if (i % 3 == 0 && i % 2 != 0) {
    nameLast = nm9[rnd7] + nm10[rnd8] + nm12[rnd10];
    } else if (i % 2 == 0) {
    rnd9 = rng() % std::size(nm13);
    rnd10 = rng() % std::size(nm14);
    nameLast = nm13[rnd9] + nm14[rnd10];
    } else {
    rnd9 = rng() % std::size(nm10);
    rnd11 = rng() % std::size(nm11);
    nameLast = nm9[rnd7] + nm10[rnd8] + nm11[rnd11] + nm10[rnd9] + nm12[rnd10];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 5) {
    while (rnd < 6) {
    rnd = rng() % std::size(nm5);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + "  " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + "  " + nameLast;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nameLast;
    }
    }
    return names;
    }
}
