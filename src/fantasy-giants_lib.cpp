#include "fantasy-giants_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_giants_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "v", "w", "x", "z", "a", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "r", "s", "t", "v", "w", "x", "z", "ar", "br", "cr", "dr", "fr", "gr", "kr", "sr", "tr", "vr", "wr", "al", "bl", "cl", "dl", "fl", "gl", "kl", "sl", "vl", "zl", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"e", "i", "u", "o", "a"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "k", "l", "m", "n", "r", "s", "t", "w", "x", "z", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"ag", "am", "as", "bar", "barg", "bog", "bor", "bos", "brog", "der", "dhor", "dius", "dor", "dus", "fius", "fum", "fur", "gan", "gant", "gar", "gi", "gir", "grog", "kaos", "karos", "kos", "krus", "las", "lith", "log", "lor", "los", "malog", "mir", "mohr", "nar", "nas", "nir", "nus", "og", "om", "os", "rion", "roch", "rog", "rus", "rym", "sag", "sal", "sar", "sius", "sog", "sor", "tag", "tius", "theus", "thor", "thos", "to", "tor", "vag", "ver", "var", "vir", "vog", "war", "wor", "zar", "ziar", "zus"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4];
    return names;
    }
}
