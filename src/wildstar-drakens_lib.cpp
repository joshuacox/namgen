#include "wildstar-drakens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_wildstar_drakens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "d", "g", "h", "j", "k", "m", "n", "r", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "a", "i", "o", "u", "aa", "ua", "ia", "uu"};
    static constexpr std::string_view nm3[] = {"c", "cr", "dr", "g", "gg", "gr", "gh", "k", "kr", "kk", "l", "n", "nk", "ng", "q", "r", "rr", "rk", "rg", "rq", "v", "vr", "vh", "z", "zg", "c", "g", "k", "l", "n", "q", "r", "v", "z", "c", "g", "k", "l", "n", "q", "r", "v", "z", "c", "g", "k", "l", "n", "q", "r", "v", "z", "c", "g", "k", "l", "n", "q", "r", "v", "z"};
    static constexpr std::string_view nm4[] = {"d", "n", "r", "s", "th", "z"};
    static constexpr std::string_view nm5[] = {"c", "g", "j", "k", "m", "n", "r", "s", "t", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "ia", "ee", "ae", "ie"};
    static constexpr std::string_view nm7[] = {"cc", "g", "gn", "gr", "k", "kk", "kr", "kn", "kz", "kl", "lk", "lg", "lr", "lz", "m", "mz", "mm", "n", "nn", "nk", "ng", "nz", "nr", "r", "rg", "rk", "rs", "rv", "s", "sz", "sr", "sq", "zz", "g", "k", "m", "n", "r", "t", "v", "z", "g", "k", "m", "n", "r", "t", "v", "z", "g", "k", "m", "n", "r", "t", "v", "z", "g", "k", "m", "n", "r", "t", "v", "z"};
    static constexpr std::string_view nm8[] = {"amber", "ash", "axe", "battle", "beast", "blaze", "blood", "burning", "chaos", "cinder", "claw", "cold", "dark", "dead", "death", "deep", "doom", "ember", "far", "fire", "fist", "flame", "fury", "fuse", "glow", "grand", "hard", "haze", "heavy", "hell", "iron", "keen", "lone", "mist", "molten", "moon", "mountain", "mourn", "nether", "night", "pride", "proud", "pyre", "rage", "rough", "rumble", "shade", "shadow", "sharp", "skull", "spider", "steel", "still", "storm", "stout", "strong", "sun", "swift", "titan", "true", "wild", "wolf", "wrath"};
    static constexpr std::string_view nm9[] = {"bane", "bash", "basher", "beam", "blade", "blaze", "blight", "bow", "branch", "brand", "breaker", "bringer", "caller", "claw", "crusher", "cut", "cutter", "fall", "fang", "fire", "fist", "flaw", "flayer", "force", "forge", "fury", "gaze", "gloom", "glory", "grip", "guard", "hammer", "hell", "horn", "hunter", "killer", "lash", "mane", "mark", "maul", "maw", "mourn", "rage", "reaper", "reaver", "ripper", "roar", "run", "runner", "scream", "shade", "shadow", "shard", "shot", "slayer", "snarl", "soar", "spear", "spire", "splitter", "stalker", "storm", "strike", "taker", "talon", "thorn", "ward", "weaver"};

    std::string lname; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm9);
    while (nm8[rnd6] == nm9[rnd7]) {
    rnd7 = rng() % std::size(nm9);
    }
    lname = nm8[rnd6] + nm9[rnd7];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + lname;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + " " + lname;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 7) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + lname;
    }
    }
    return names;
    }
}
