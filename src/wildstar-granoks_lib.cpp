#include "wildstar-granoks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_wildstar_granoks_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"br", "d", "dr", "g", "gr", "j", "k", "kr", "q", "r", "t", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "u"};
    static constexpr std::string_view nm3[] = {"b", "br", "d", "dr", "g", "gg", "gn", "k", "kn", "kk", "lk", "lg", "r", "rr", "rk", "rg", "rv", "rz", "rd", "rb", "v", "z", "zk", "zg"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "k", "ll", "r", "s", "z"};
    static constexpr std::string_view nm5[] = {"ch", "d", "f", "h", "j", "k", "l", "n", "r", "t", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "o"};
    static constexpr std::string_view nm7[] = {"dk", "dr", "fk", "fr", "gn", "kn", "kr", "kz", "x", "lk", "lr", "lg", "lz", "rv", "rs", "rz", "rd", "rb", "sk", "sh", "sv", "st", "sr", "v", "vk", "z", "zk"};
    static constexpr std::string_view nm8[] = {"h", "l", "ll", "m", "n", "nn", "r", "s", "ss", "t", "tt", "z"};
    static constexpr std::string_view nm9[] = {"blast", "bleak", "bone", "boulder", "brutal", "bulk", "burst", "cold", "crack", "crag", "crash", "dark", "deep", "doom", "ember", "fight", "fire", "firm", "fist", "flame", "force", "frost", "grand", "grim", "hard", "ice", "iron", "long", "metal", "power", "red", "rigid", "shadow", "slab", "slam", "slate", "smash", "stark", "steel", "stern", "stone", "stout", "strong", "stubborn", "ten", "thunder", "timber", "titan", "tough", "vault"};
    static constexpr std::string_view nm10[] = {"bend", "blaze", "blight", "bough", "breaker", "brow", "burst", "buster", "clash", "crag", "crest", "crusher", "cut", "down", "dream", "fall", "flake", "force", "fury", "grip", "guard", "heart", "horn", "hunter", "keep", "keeper", "lash", "mark", "master", "might", "more", "prime", "quake", "rage", "reaper", "rend", "ridge", "right", "roar", "runner", "shade", "shadow", "shard", "shatter", "shout", "sky", "sliver", "smasher", "snap", "song", "sorrow", "spell", "spire", "spirit", "splinter", "split", "splitter", "storm", "stride", "strike", "thorn", "track", "trap", "valor", "walker", "ward", "watcher"};

    std::string lname; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm10);
    while (nm9[rnd6] == nm10[rnd7]) {
    rnd7 = rng() % std::size(nm10);
    }
    lname = nm9[rnd6] + nm10[rnd7];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    if (i < 6) {
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + lname;
    } else {
    rnd3 = rng() % std::size(nm8);
    names = nm5[rnd] + nm6[rnd2] + nm8[rnd3] + " " + lname;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (i < 6) {
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    } else {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd5] + " " + lname;
    }
    }
    return names;
    }
}
