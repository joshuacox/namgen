#include "places-countrys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_countrys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "i", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "u"};
    static constexpr std::string_view nm3[] = {"br", "cr", "dr", "fr", "gr", "pr", "str", "tr", "bl", "cl", "fl", "gl", "pl", "sl", "sc", "sk", "sm", "sn", "sp", "st", "sw", "ch", "sh", "th", "wh"};
    static constexpr std::string_view nm4[] = {"ae", "ai", "ao", "au", "a", "ay", "ea", "ei", "eo", "eu", "e", "ey", "ua", "ue", "ui", "uo", "u", "uy", "ia", "ie", "iu", "io", "iy", "oa", "oe", "ou", "oi", "o", "oy"};
    static constexpr std::string_view nm5[] = {"stan", "dor", "vania", "nia", "lor", "cor", "dal", "bar", "sal", "ra", "la", "lia", "jan", "rus", "ze", "tan", "wana", "sil", "so", "na", "le", "bia", "ca", "ji", "ce", "ton", "ssau", "sau", "sia", "ca", "ya", "ye", "yae", "tho", "stein", "ria", "nia", "burg", "nia", "gro", "que", "gua", "qua", "rhiel", "cia", "les", "dan", "nga", "land"};
    static constexpr std::string_view nm6[] = {"ia", "a", "en", "ar", "istan", "aria", "ington", "ua", "ijan", "ain", "ium", "us", "esh", "os", "ana", "il", "ad", "or", "ea", "eau", "ax", "on", "ana", "ary", "ya", "ye", "yae", "ait", "ein", "urg", "al", "ines", "ela"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    } else if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm6[rnd4];
    } else if (i < 6) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3];
    } else if (i < 8) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm6);
    names = nm2[rnd] + nm3[rnd2] + nm6[rnd3];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm6);
    names = nm3[rnd] + nm4[rnd2] + nm1[rnd3] + "  " + nm3[rnd4] + nm6[rnd5];
    }
    return names;
    }
}
