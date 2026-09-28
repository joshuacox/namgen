#include "warhammer-dwarfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_dwarfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "br", "d", "dr", "g", "gr", "kh", "kr", "m", "n", "r", "s", "sr", "str", "th", "tr", "thr", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ai", "oa", "ao"};
    static constexpr std::string_view nm3[] = {"d", "g", "k", "l", "r", "th", "d", "g", "k", "l", "r", "th", "br", "d", "dh", "dr", "g", "gr", "gh", "gn", "gm", "gz", "gd", "k", "kr", "l", "lb", "ld", "lg", "lgr", "ldr", "nd", "ng", "nr", "ndr", "ngr", "r", "rd", "rdr", "rg", "rt", "rbr", "rb", "rgr", "th", "tr", "thr"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "gg", "k", "m", "mm", "n", "r", "rd", "t"};
    static constexpr std::string_view nm5[] = {"b", "bh", "c", "d", "dr", "g", "gh", "h", "m", "n", "s", "sk", "sc", "t", "th", "v", "z", "zh"};
    static constexpr std::string_view nm6[] = {"e", "i", "u", "e", "i", "u", "e", "i", "u", "e", "i", "u", "a", "a", "o", "o"};
    static constexpr std::string_view nm7[] = {"br", "dr", "dg", "dw", "dd", "ff", "fr", "gr", "gw", "gn", "gm", "gf", "gv", "kk", "kh", "kr", "kv", "lg", "lgr", "lv", "ng", "ngr", "ngw", "nd", "ndw", "ndr", "rg", "rgr", "rgw", "rw", "rz", "sg", "sgr", "sv", "th", "tr", "tv", "thr", "vr"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "d", "h", "m", "n", "t"};
    static constexpr std::string_view nm9[] = {"amber", "autumn", "battle", "bear", "bitter", "black", "blunt", "boulder", "brane", "bright", "brittle", "broad", "broken", "bronze", "brown", "cask", "cinder", "cliff", "coal", "cold", "common", "copper", "crag", "deep", "distant", "ember", "far", "fiery", "fire", "flame", "flat", "flint", "forge", "full", "fuse", "gold", "golden", "grand", "granite", "gray", "great", "grim", "grudge", "grumble", "hammer", "hill", "ingot", "iron", "keen", "keg", "krag", "lead", "light", "magma", "merry", "metal", "mild", "mirth", "mithril", "mountain", "noble", "onyx", "plain", "proud", "regal", "rich", "rock", "rough", "rumble", "shatter", "silver", "slender", "solid", "steel", "stone", "storm", "stout", "strong", "thunder", "true"};
    static constexpr std::string_view nm10[] = {"arm", "armor", "armour", "axe", "back", "basher", "beam", "beard", "bearer", "belly", "belt", "bender", "bluff", "bone", "bough", "brace", "branch", "brand", "breaker", "brew", "brewer", "bringer", "brow", "buckle", "buster", "chaser", "chest", "chin", "cloak", "crag", "crest", "digger", "dreamer", "feet", "finger", "fire", "fist", "fists", "flame", "foot", "force", "forge", "forged", "fury", "grip", "grog", "guard", "gut", "hammer", "hand", "hank", "head", "heart", "helm", "keeper", "maker", "mantle", "mark", "master", "might", "more", "punch", "rage", "seeker", "shaper", "shield", "shoulder", "shout", "strength", "strider", "striker", "surge", "sworn", "thane", "walker", "ward"};

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
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm8[rnd5] + " " + nameL;
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
