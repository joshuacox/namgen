#include "mass_effect-batarians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_batarians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm2[] = {"a", "e", "u", "i", "o", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm3[] = {"b", "br", "c", "cr", "d", "dh", "dr", "f", "g", "gr", "gh", "k", "kh", "kr", "p", "pr", "r", "s"};
    static constexpr std::string_view nm4[] = {"a", "e", "a", "o"};
    static constexpr std::string_view nm5[] = {"chi", "chia", "cress", "fin", "fine", "kia", "kira", "kis", "lea", "leya", "lile", "lla", "lle", "lya", "men", "mis", "misa", "mye", "neya", "nim", "nin", "nine", "nis", "nith", "nna", "nne", "nya", "phe", "phi", "pril", "pris", "rish", "rith", "sin", "sina", "the", "tia", "tin", "vile", "zis"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "g", "k", "m", "n", "p", "r", "s"};
    static constexpr std::string_view nm7[] = {"'", ""};
    static constexpr std::string_view nm8[] = {"ba", "b", "bar", "can", "char", "dah", "drak", "dor", "gan", "goh", "gar", "han", "hal", "h", "kan", "kk", "lak", "lok", "lor", "mak", "mon", "nak", "nrek", "prak", "pos", "rah", "ral", "rk", "roh", "rok", "ros", "rr", "ss", "star", "th", "tor", "van", "vran", "war", "wen"};
    static constexpr std::string_view nm9[] = {"cor", "gan", "gar", "grom", "ko", "kon", "lem", "lo", "m", "mak", "mo", "n", "nk", "no", "po", "por", "prak", "rag", "rak", "rek", "rem", "rk", "rlak", "rn", "rok", "ros", "rvan", "sk", "srak", "svan", "svin", "th", "than", "thar", "thor", "tin", "to", "tok", "tor", "y"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm4);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    rnd9 = rng() % std::size(nm6);
    rnd10 = rng() % std::size(nm4);
    rnd11 = rng() % std::size(nm8);
    rnd12 = rng() % std::size(nm9);
    if (type == 1) {
    names = nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm9[rnd12] + " " + nm3[rnd5] + nm4[rnd6] + nm6[rnd7] + nm7[rnd8] + nm6[rnd9] + nm4[rnd10] + nm8[rnd11];
    } else {
    names = nm2[rnd] + nm3[rnd2] + nm4[rnd3] + nm5[rnd4] + " " + nm3[rnd5] + nm4[rnd6] + nm6[rnd7] + nm7[rnd8] + nm6[rnd9] + nm4[rnd10] + nm8[rnd11];
    }
    return names;
    }
}
