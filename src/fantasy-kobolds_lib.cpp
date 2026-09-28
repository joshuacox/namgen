#include "fantasy-kobolds_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_kobolds_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "br", "cr", "cl", "ch", "chr", "d", "dr", "g", "gr", "ghr", "k", "kr", "kh", "kn", "q", "qr", "qh", "sh", "shr", "sk", "sn", "str", "sz", "tr", "v", "vr", "x", "z", "zr"};
    static constexpr std::string_view nm2[] = {"e", "i", "u", "e", "i", "u", "a", "o", "e", "i", "u", "e", "i", "u", "a", "o", "e", "i", "u", "e", "i", "u", "a", "o", "e", "i", "u", "e", "i", "u", "a", "o", "aa", "ai", "au", "ei", "ia", "ee"};
    static constexpr std::string_view nm3[] = {"b", "bb", "d", "dd", "g", "gg", "k", "kk", "r", "rr", "z", "zz", "b", "bb", "d", "dd", "g", "gg", "k", "kk", "r", "rr", "z", "zz", "b", "br", "bb", "d", "dd", "dr", "dg", "g", "gg", "gd", "gn", "gm", "gr", "gdr", "gbr", "gv", "k", "kk", "kr", "kz", "kzr", "kgr", "kv", "kdr", "lg", "lgr", "lk", "ldr", "lbr", "mg", "mgr", "mk", "mc", "md", "mq", "mz", "mzr", "ng", "nd", "ndr", "ngr", "nz", "nsz", "r", "rr", "rg", "rgr", "rd", "rdr", "rz", "rk", "rkr", "tk", "tz", "tr", "tv", "z", "zr", "zk", "zkr", "zz", "zzk", "zd"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "k", "c", "d", "g", "k", "n", "nk", "ng", "nd", "r", "rk", "rc", "rg", "s", "sk", "sz", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "b", "bhr", "bh", "cy", "cl", "ch", "chr", "d", "dh", "g", "gh", "ghr", "k", "khr", "kh", "kn", "kl", "khn", "sh", "shr", "sc", "sl", "sn", "shn", "sht", "str", "sz", "t", "th", "thr", "v", "vr", "z", "zh", "zr"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "o", "u", "o", "o", "u", "u", "ai", "ei", "ee", "ea", "aa"};
    static constexpr std::string_view nm7[] = {"b", "bb", "d", "dd", "g", "gg", "k", "kk", "r", "rr", "tt", "zz", "b", "bb", "d", "dd", "g", "gg", "k", "kk", "r", "rr", "tt", "zz", "b", "bn", "bb", "d", "dd", "dj", "dn", "g", "gg", "gl", "gn", "gm", "gr", "ggn", "ggv", "gv", "k", "kk", "kl", "ks", "ksh", "kg", "kn", "lz", "lv", "lg", "lgr", "lkh", "ldj", "lbl", "mg", "mgl", "mkh", "mch", "mdj", "ms", "msz", "msr", "ng", "nd", "ndr", "ngd", "ngl", "nsh", "nsz", "r", "rr", "rg", "rgl", "rdh", "rdj", "rsz", "rl", "rkh", "rch", "th", "tsz", "thr", "tt", "zs", "zsr", "zhk", "zkh", "zz", "zsz", "zd"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "hl", "hn", "hs", "l", "n", "ng", "s", "y", "z"};
    static constexpr std::string_view nm9[] = {"ash", "barb", "barbed", "bitter", "blood", "bone", "boulder", "brew", "brick", "broad", "bronze", "brown", "claw", "cliff", "coal", "cold", "common", "coven", "crag", "crow", "dark", "dim", "dust", "ember", "far", "fern", "fist", "flask", "flat", "fog", "fool", "fore", "full", "gore", "grass", "gray", "green", "grey", "grime", "grumble", "hard", "haze", "heavy", "hill", "horn", "iron", "keen", "krag", "large", "lead", "leather", "lone", "molten", "moon", "morning", "mountain", "mud", "muk", "nether", "night", "oat", "orb", "pale", "pebble", "pine", "plate", "rain", "rapid", "red", "river", "rock", "rough", "rumble", "sharp", "shatter", "silent", "simple", "skull", "spider", "star", "steel", "stone", "storm", "stout", "strong", "tusk", "wild", "wind"};
    static constexpr std::string_view nm10[] = {"arm", "ash", "back", "bane", "bash", "basher", "belly", "belt", "bender", "blade", "blood", "blower", "bluff", "bone", "born", "bough", "bow", "brace", "branch", "brand", "breaker", "breath", "bringer", "brow", "buckle", "buster", "chaser", "chest", "chew", "chewer", "chin", "claw", "cleaver", "coat", "crag", "crest", "crusher", "cut", "cutter", "delver", "digger", "drifter", "dust", "eye", "eyes", "fall", "fang", "feather", "feet", "finger", "fist", "flare", "flaw", "foot", "gaze", "gazer", "grip", "grog", "guard", "gut", "hammer", "head", "hide", "horn", "hunter", "jaw", "lash", "mail", "mane", "mark", "master", "maul", "maw", "pelt", "punch", "rage", "ripper", "runner", "scar", "seeker", "snarl", "snout", "spine", "splinter", "stalker", "stride", "strike", "surge", "thorn", "tongue", "watcher", "wound"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "", "b", "bhr", "cr", "cl", "ch", "chr", "d", "g", "ghr", "k", "kh", "kn", "sh", "shr", "sc", "sn", "str", "sz", "thr", "v", "vr", "x", "z", "zr"};
    static constexpr std::string_view nm12[] = {"a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "a", "e", "i", "u", "o", "o", "o", "o", "aa", "ee", "ia", "ai", "ei"};
    static constexpr std::string_view nm13[] = {"b", "bb", "d", "dd", "g", "gg", "k", "kk", "r", "rr", "tt", "z", "zz", "bhr", "dj", "gn", "gm", "gr", "gv", "kz", "kv", "khr", "lg", "lgr", "lk", "ld", "lz", "ldr", "mg", "mk", "mch", "mq", "msz", "mzr", "ng", "nd", "ndr", "nz", "nsz", "rg", "rd", "rdr", "rdj", "rsz", "rk", "rch", "tz", "tr", "thr", "zs", "zsz", "zzs", "zd"};
    static constexpr std::string_view nm14[] = {"", "", "", "", "", "h", "l", "m", "n", "ng", "r", "s", "sz", "x", "z"};

    std::string lName; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    while (nm9[rnd] == nm10[rnd2]) {
    rnd2 = rng() % std::size(nm10);
    }
    lName = " " + nm9[rnd] + nm10[rnd2];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm8);
    if (i < 4) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm5);
    }
    while (rnd5 < 15) {
    rnd5 = rng() % std::size(nm8);
    }
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd5] + lName;
    } else {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (rnd < 3) {
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm8);
    }
    }
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + lName;
    }
    } else if (type == 2) {
    rnd = rng() % std::size(nm11);
    rnd2 = rng() % std::size(nm12);
    rnd5 = rng() % std::size(nm14);
    if (i < 4) {
    while (rnd < 5) {
    rnd = rng() % std::size(nm11);
    }
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm14);
    }
    names = nm11[rnd] + nm12[rnd2] + nm14[rnd5] + lName;
    } else {
    rnd3 = rng() % std::size(nm13);
    rnd4 = rng() % std::size(nm12);
    if (rnd < 5) {
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm14);
    }
    }
    names = nm11[rnd] + nm12[rnd2] + nm13[rnd3] + nm12[rnd4] + nm14[rnd5] + lName;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 4) {
    while (rnd < 3) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + lName;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + lName;
    }
    }
    return names;
    }
}
