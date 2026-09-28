#include "fantasy-gnolls_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_gnolls_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "br", "d", "dr", "g", "gr", "gh", "gn", "k", "kh", "kr", "m", "r", "rr", "t", "th", "tr", "thr", "v", "x", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "y", "y", "aa", "ei", "ia", "ou", "ua", "uo"};
    static constexpr std::string_view nm3[] = {"br", "g", "gr", "gn", "gl", "gz", "gv", "gg", "grr", "ghr", "hr", "hg", "kz", "kr", "kn", "kz", "kk", "lg", "lz", "lk", "lr", "mk", "mm", "mr", "ng", "nr", "ngr", "ndr", "nk", "nkr", "r", "rr", "rg", "rgr", "rk", "rkr", "x", "xx", "v", "vk", "vg", "zg", "zz", "zr"};
    static constexpr std::string_view nm4[] = {"r", "rr", "rg", "rrg", "rk", "c", "k", "kk", "x", "kx", "z", "zz", "t", "h", "n"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "b", "d", "dh", "dr", "g", "gl", "gr", "grr", "gn", "h", "hr", "kh", "kn", "l", "m", "mr", "n", "p", "r", "rh", "rr", "rrh", "s", "sh", "sr", "sn", "sz", "t", "th", "tr", "trr", "ts", "v", "z", "zh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "aa", "ae", "ai", "ea", "ei", "ie", "ia", "ui"};
    static constexpr std::string_view nm7[] = {"b", "bn", "bl", "d", "dd", "dn", "g", "gh", "gg", "gz", "gr", "hr", "hz", "hg", "hn", "hl", "hrr", "l", "ll", "lr", "lm", "ln", "lg", "lz", "lv", "mn", "mv", "ms", "ng", "nk", "nr", "nz", "nv", "r", "rr", "rh", "rg", "rt", "rtr", "rth", "rx", "s", "ss", "sz", "sr", "szr", "str", "sl", "sn", "sg", "sh", "szh", "t", "th", "thr", "ts", "thn", "tn", "tz", "tzs", "tsz", "tsh", "thv", "thg", "thm", "thn", "w", "wv", "vn", "vg", "vl", "vr", "zr", "zn", "zl", "zh", "zs", "zsh"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "r", "rh", "hr", "h", "hn", "s", "sh", "z", "hz", "th", "rth"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "b", "d", "g", "gn", "gr", "k", "kr", "kn", "m", "r", "rr", "s", "sz", "sr", "t", "th", "tr", "thr", "v", "x", "z"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "aa", "ei", "ou", "ua", "ue", "ei", "ai", "ia"};
    static constexpr std::string_view nm11[] = {"b", "bb", "d", "dd", "g", "gg", "gr", "gn", "gl", "gv", "grr", "ghr", "hr", "hg", "hn", "hl", "hz", "l", "ll", "lg", "lz", "lv", "lk", "lm", "m", "mm", "mr", "mv", "mk", "mg", "nk", "nn", "nz", "nv", "ng", "ngr", "r", "rr", "rg", "rh", "rhg", "rn", "rm", "rl", "rz", "x", "xr", "z", "zz", "zs", "zn", "zl", "zg"};
    static constexpr std::string_view nm12[] = {"", "", "", "c", "l", "n", "m", "h", "r", "rr", "th", "t"};
    static constexpr std::string_view nm13[] = {"Ash", "Blight", "Blood", "Boom", "Brine", "Broken", "Burst", "Clay", "Crack", "Cracked", "Damp", "Dead", "Dirt", "Dreck", "Dregs", "Dust", "Fail", "Far", "Fast", "Filth", "Fizz", "Fizzle", "Foam", "Froth", "Fungi", "Fungus", "Glop", "Gold", "Goo", "Gore", "Grapple", "Grease", "Grime", "Ground", "Gunk", "Lard", "Loose", "Lump", "Mire", "Mole", "Muck", "Mucus", "Mud", "Murk", "Ooze", "Pebble", "Pest", "Rent", "River", "Rot", "Salt", "Sand", "Scourge", "Scum", "Scuz", "Silt", "Slab", "Sleaze", "Slime", "Sludge", "Snore", "Snot", "Soil", "Soot", "Sore", "Split", "Stain", "Sweat", "Tame", "Woe", "Zest"};
    static constexpr std::string_view nm14[] = {"barb", "bash", "basher", "beam", "blase", "blast", "bolt", "boot", "brass", "cast", "cheek", "clash", "claw", "cloak", "club", "crook", "dance", "death", "dent", "ear", "ears", "eye", "eyes", "face", "fang", "fangs", "feet", "finger", "fingers", "fist", "fists", "foot", "frown", "fuse", "gall", "gaze", "gleam", "glob", "gob", "grapnel", "grappler", "grin", "grinder", "guard", "guise", "hallow", "hammer", "hand", "hands", "head", "hook", "hunter", "knob", "knuckle", "mask", "maw", "mouth", "mug", "nail", "nails", "nose", "paw", "pince", "pincer", "pinch", "scowl", "scrap", "shrapnel", "skin", "smile", "smirk", "snag", "spear", "stick", "talon", "teeth", "thumb", "tine", "toe", "toes", "tongue", "tooth", "tusk", "watch", "wizzle"};

    std::string names; std::string nmLast; size_t rnd = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd22 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd12 = rng() % std::size(nm13);
    rnd22 = rng() % std::size(nm14);
    nmLast = nm13[rnd12] + nm14[rnd22];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm8);
    if (rnd < 5) {
    while (rnd3 < 5) {
    rnd3 = rng() % std::size(nm8);
    }
    }
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd3] + " " + nmLast;
    } else {
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd5] + nm6[rnd4] + nm8[rnd3] + " " + nmLast;
    }
    } else if (type == 2) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    rnd3 = rng() % std::size(nm12);
    if (rnd < 5) {
    while (rnd3 < 5) {
    rnd3 = rng() % std::size(nm12);
    }
    }
    if (i < 5) {
    names = nm9[rnd] + nm10[rnd2] + nm12[rnd3] + " " + nmLast;
    } else {
    rnd4 = rng() % std::size(nm10);
    rnd5 = rng() % std::size(nm11);
    names = nm9[rnd] + nm10[rnd2] + nm11[rnd5] + nm10[rnd4] + nm12[rnd3] + " " + nmLast;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm4);
    if (rnd < 5) {
    while (rnd3 < 5) {
    rnd3 = rng() % std::size(nm4);
    }
    }
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + " " + nmLast;
    } else {
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + nm2[rnd4] + nm4[rnd3] + " " + nmLast;
    }
    }
    return names;
    }
}
