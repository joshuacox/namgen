#include "fantasy-ogres_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_ogres_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"B", "Bl", "Br", "D", "Dr", "G", "Gl", "Gr", "K", "Kl", "Kr", "M", "N", "T", "Tr", "V", "Vr", "W", "X", "Y", "Z", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"e", "i", "u", "o", "a"};
    static constexpr std::string_view nm3[] = {"b", "d", "g", "k", "l", "m", "n", "r", "s", "t", "w", "x", "z", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"g", "k", "rug", "rog", "rag", "ruk", "rok", "kag", "rth", "rub", "rob", "rig", "kohr", "kuhr", "kor", "kur", "ret", "rut", "rot", "kug", "kog", "kig", "keg", "reg", "rek", "rg", "rk", "zar", "zug", "zor", "zag", "zig", "zir", "zur", "nk", "gut", "grut", "grot", "gruk", "grok", "rok", "ruk", "rag", "gark", "gork", "gurk", "kur", "kurk", "kurg", "kor", "kork", "korg", "zog", "zug", "zig", "zrog", "zrug"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm4[rnd4];
    } else {
    rnd3 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd5] + nm4[rnd4];
    }
    return names;
    }
}
