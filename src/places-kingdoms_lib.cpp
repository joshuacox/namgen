#include "places-kingdoms_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_kingdoms_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"ae", "ea", "ai", "au", "ou", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names2[] = {"ae", "eo", "ea", "ai", "ui", "ou", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view names3[] = {"b", "c", "d", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "dr", "gr", "kr", "pr", "tr", "vr", "wr", "st", "sl", "ch", "sh", "ph", "kh", "th"};
    static constexpr std::string_view names4[] = {"b", "c", "d", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "bb", "cc", "dd", "ff", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt", "zz", "br", "cr", "dr", "gr", "kr", "pr", "sr", "tr", "zr", "st", "sl", "ch", "sh", "ph", "kh", "th"};
    static constexpr std::string_view names5[] = {"ba", "bet", "bia", "borg", "burg", "ca", "caea", "can", "cia", "curia", "dal", "del", "dia", "dian", "do", "dor", "dora", "dour", "galla", "gary", "gia", "gon", "han", "kar", "kha", "kya", "les", "lia", "lon", "lan", "lum", "lux", "lyra", "mid", "mor", "more", "nad", "nait", "nao", "nate", "nada", "neian", "nem", "nia", "nid", "niel", "ning", "ntis", "nyth", "pan", "phate", "pia", "pis", "ra", "ral", "rean", "rene", "renth", "ria", "rian", "rid", "rin", "ris", "rith", "rus", "ryn", "sal", "san", "sea", "seon", "sha", "sian", "site", "sta", "ston", "teron", "terra", "tha", "thage", "then", "thia", "tia", "tis", "tish", "ton", "topia", "tor", "tus", "valon", "varia", "vell", "ven", "via", "viel", "wen", "weth", "wyth", "ya", "zar", "zia"};
    static constexpr std::string_view names6[] = {"Kingdom", "Empire", "Dynasty"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names2);
    rnd4 = rng() % std::size(names5);
    rnd5 = rng() % std::size(names6);
    names = names1[rnd] + names3[rnd2] + names2[rnd3] + names5[rnd4] + " " + names6[rnd5];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names2);
    if (rnd < 5) {
    while (rnd3 < 6) {
    rnd3 = rng() % std::size(names2);
    }
    }
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names2);
    if (rnd3 < 6) {
    while (rnd5 < 6) {
    rnd5 = rng() % std::size(names2);
    }
    }
    rnd6 = rng() % std::size(names5);
    rnd7 = rng() % std::size(names6);
    names = names1[rnd] + names3[rnd2] + names2[rnd3] + names4[rnd4] + names2[rnd5] + names5[rnd6] + " " + names6[rnd7];
    }
    return names;
    }
}
