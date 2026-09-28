#include "warhammer-skavens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_skavens_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "cr", "chr", "ch", "kr", "khr", "kh", "q", "qh", "qr", "qhr", "sn", "sk", "sr", "str", "st", "skr", "th", "thr", "tr", "t", "v", "x", "z", "zr", "zh", "zn"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ie", "ee", "uo", "ue", "uee", "ia", "ua"};
    static constexpr std::string_view nm3[] = {"ch", "cn", "cr", "cq", "cx", "gz", "gr", "gch", "gq", "k", "kh", "kr", "kz", "ktr", "kn", "nq", "nk", "nkr", "nqr", "q", "qr", "qz", "qtr", "sh", "shr", "shq", "sq", "sqh", "sqr", "sk", "skr", "t", "thr", "tr", "tz", "x", "xr", "xk", "xkr", "xq", "zq", "zk", "zkr"};
    static constexpr std::string_view nm4[] = {"ch", "k", "kch", "l", "lk", "n", "nq", "t", "tch"};
    static constexpr std::string_view nm5[] = {"amber", "ash", "ashen", "barb", "barbed", "bitter", "black", "blazing", "bone", "bristle", "broad", "cask", "cinder", "claw", "coven", "crag", "craven", "crest", "crow", "dark", "dead", "death", "deep", "dusk", "dust", "ember", "farrow", "feather", "fiery", "fire", "flint", "fore", "great", "grim", "head", "heart", "high", "iron", "keen", "krag", "lone", "low", "mourn", "night", "pine", "pride", "rapid", "rough", "shadow", "silent", "silver", "skull", "sky", "slate", "steel", "stern", "stone", "tusk", "vermin", "wild", "wind"};
    static constexpr std::string_view nm6[] = {"back", "basher", "bender", "binder", "bleeded", "blight", "blood", "bone", "born", "bough", "breaker", "breath", "brow", "buster", "chaser", "chest", "chewer", "chin", "claw", "cleaver", "crest", "crusher", "cutter", "digger", "fang", "fangs", "finger", "fingers", "fist", "flayer", "fury", "gaze", "gazer", "grip", "hunter", "jaw", "lash", "lasher", "master", "maul", "maw", "reaper", "reaver", "ripper", "runner", "sbark", "scar", "scream", "seeker", "shrieker", "slayer", "snout", "spine", "spire", "splitter", "stalker", "striker", "tail", "taker", "thorn", "walker", "watcher", "weaver"};

    std::string lName; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    while (nm5[rnd] == nm6[rnd2]) {
    rnd2 = rng() % std::size(nm6);
    }
    lName = " " + nm5[rnd] + nm6[rnd2];
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 6) {
    while (rnd < 4) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + lName;
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + lName;
    }
    return names;
    }
}
