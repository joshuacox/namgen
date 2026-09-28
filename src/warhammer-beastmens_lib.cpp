#include "warhammer-beastmens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_beastmens_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "d", "g", "gh", "k", "kn", "kh", "m", "n", "t", "th", "v", "z", "zh"};
    static constexpr std::string_view nm2[] = {"a", "o", "u", "a", "o", "u", "a", "o", "u", "a", "o", "u", "a", "o", "u", "e", "i", "e", "i", "au", "ao", "aa", "oo"};
    static constexpr std::string_view nm3[] = {"cr", "cn", "cc", "cv", "cth", "g", "gh", "gth", "gd", "gdh", "k", "kh", "kz", "kk", "kr", "kt", "kth", "l", "lg", "lgh", "lgr", "ltr", "lc", "n", "ng", "nk", "nc", "r", "rr", "rz", "rg", "rk", "rkr", "rgh", "rth", "zr", "zg", "zc", "zk", "zz"};
    static constexpr std::string_view nm4[] = {"c", "g", "k", "r", "x", "z"};
    static constexpr std::string_view nm5[] = {"amber", "ashen", "battle", "bitter", "black", "blazing", "bleeding", "blood", "bright", "bristle", "broad", "brown", "chaos", "cinder", "dark", "dawn", "dead", "death", "ember", "fallen", "fiery", "fire", "flame", "frozen", "giant", "gloom", "gore", "grand", "gray", "great", "grim", "grizzly", "heavy", "hell", "iron", "keen", "lightning", "lone", "metal", "molten", "moon", "morning", "moss", "mountain", "nether", "night", "onyx", "plain", "proud", "pyre", "rage", "rapid", "rough", "rumble", "serpent", "shadow", "sharp", "shatter", "silent", "silver", "slug", "solid", "spring", "star", "steel", "stern", "stone", "storm", "strong", "swift", "thunder", "wild"};
    static constexpr std::string_view nm6[] = {"arm", "bane", "belly", "belt", "braid", "breath", "brow", "chest", "chin", "claw", "coat", "crest", "eye", "eyes", "fang", "fangs", "feet", "finger", "fingers", "fist", "foot", "gaze", "grip", "gut", "hair", "hand", "hands", "head", "heart", "hide", "jaw", "mane", "manes", "mantle", "maw", "mouth", "paw", "pelt", "ridge", "scar", "shoulder", "shoulders", "snout", "spine", "tail", "teeth", "toe", "toes", "tongue", "tooth", "wound"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5];
    } else {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    while (nm5[rnd] == nm6[rnd2]) {
    rnd2 = rng() % std::size(nm6);
    }
    names = nm5[rnd] + nm6[rnd2];
    }
    return names;
    }
}
