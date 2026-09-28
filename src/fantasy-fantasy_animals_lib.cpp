#include "fantasy-fantasy_animals_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_fantasy_animals_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Alba", "Alli", "Ana", "Ante", "Arma", "Barra", "Bea", "Buffa", "Cani", "Cari", "Cate", "Coyo", "Cri", "Cro", "Croco", "Drago", "Ele", "Feli", "Fla", "Flami", "Gaze", "Gira", "Hexa", "Hone", "Jagu", "Komo", "Leo", "Locu", "Mana", "Moo", "Pa", "Pea", "Peli", "Phea", "Porcu", "Rhi", "Rhino", "Sala", "Sco", "Sku", "Sna", "Snai", "Spa", "Spi", "Squi", "Sti", "Toa", "Ursa", "Vi", "Wea", "Wha", "Woo"};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "br", "cr", "dr", "gr", "kr", "pr", "sr", "st", "str", "bl", "cl", "fl", "gl", "kl", "pl", "sl", "vl", "cs", "ds", "fs", "gs", "ks", "ls", "ms", "ns", "ps", "rs", "ss", "ts", "bb", "cc", "dd", "ff", "gg", "kk", "ll", "mm", "nn", "pp", "rr", "ss", "tt", "ww", "zz"};
    static constexpr std::string_view nm3[] = {"a", "o", "i", "e", "u", "aa", "oo", "ee", "au", "ou", "ea", "eo"};
    static constexpr std::string_view nm4[] = {"", "", "c", "d", "k", "l", "m", "n", "p", "r", "s", "t", "x", "cs", "ks", "ps", "rs", "ts", "st"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "a", "o", "i", "e", "u", "ee", "ea", "eo"};
    static constexpr std::string_view nm6[] = {"Alb", "All", "Alp", "Ant", "Arach", "Arm", "Bab", "Badg", "Barr", "Beav", "Bis", "Buff", "Cam", "Cat", "Chick", "Cobr", "Coy", "Croc", "Dol", "Don", "Drag", "Eag", "El", "Eleph", "Fal", "Falc", "Fer", "Flam", "Gaz", "Ger", "Gir", "Guin", "Hedg", "Hex", "Hipp", "Hor", "Horn", "Humm", "Hyen", "Jag", "Kang", "Koal", "Kom", "Komod", "Leop", "Lob", "Mag", "Mall", "Mant", "Mon", "Mong", "Mos", "Mosq", "Mul", "Oct", "Ost", "Pan", "Pand", "Parr", "Pel", "Pen", "Peng", "Pon", "Por", "Quad", "Rab", "Rabb", "Rac", "Racc", "Rhin", "Sal", "Sar", "Scor", "Ser", "Serp", "Skun", "Snak", "Spar", "Sparr", "Spid", "Stin", "Sting", "Ter", "Term", "Tetr", "Tuc", "Tur", "Turt", "Vul", "Vult", "Wal", "Wall", "War", "Wart", "Wol", "Wolv", "Wom", "Wor", "Zeb"};
    static constexpr std::string_view nm7[] = {"abura", "aby", "acle", "acuda", "adger", "adillo", "alo", "amander", "amel", "ander", "anzee", "api", "arak", "aroo", "aros", "atee", "atross", "ecta", "een", "ela", "elope", "ena", "eon", "ephant", "erine", "erpillar", "eton", "ey", "ibia", "ibou", "ican", "ida", "igator", "illa", "ing", "ingale", "ingo", "ish", "itar", "eleon", "ypus", "ite", "ium", "oceros", "oda", "odile", "odo", "onite", "oon", "oose", "opotamus", "opus", "ora", "orb", "os", "osaur", "ossum", "oth", "owary", "oyote", "uar", "uin", "uito", "upine", "utor", "ybara", "yte"};
    static constexpr std::string_view nm8[] = {"bat", "bil", "boon", "bug", "dine", "fly", "meleon", "guin", "hawk", "hog", "hopper", "key", "king", "ling", "madillo", "mingo", "mite", "nea", "pecker", "phant", "phin", "pie", "pion", "quito", "raffe", "ray", "rilla", "roach", "ron", "sel", "ster", "tile", "topus", "vark", "whale", "wing", "zelle"};
    static constexpr std::string_view nm9[] = {"b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "b", "c", "d", "f", "g", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "br", "cr", "dr", "gr", "kr", "pr", "sr", "st", "str", "bl", "cl", "fl", "gl", "kl", "pl", "sl", "vl"};

    std::string nm; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (rnd4 < 2) {
    rnd5 = 0;
    }
    nm = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    } else if (i < 4) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    if (rnd5 < 2) {
    rnd6 = 0;
    }
    nm = nm6[rnd] + nm3[rnd2] + nm2[rnd3] + nm3[rnd4] + nm4[rnd5] + nm5[rnd6];
    } else if (i < 6) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    while (rnd3 < 2) {
    rnd3 = rng() % std::size(nm4);
    }
    rnd4 = rng() % std::size(nm7);
    nm = nm9[rnd] + nm3[rnd2] + nm4[rnd3] + nm7[rnd4];
    } else if (i < 8) {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    if (rnd3 < 2) {
    rnd4 = 0;
    }
    rnd5 = rng() % std::size(nm8);
    nm = nm9[rnd] + nm3[rnd2] + nm4[rnd3] + nm5[rnd4] + nm8[rnd5];
    } else {
    rnd = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm3);
    rnd5 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm5);
    if (rnd5 < 2) {
    rnd6 = 0;
    }
    nm = nm9[rnd] + nm3[rnd2] + nm2[rnd3] + nm3[rnd4] + nm4[rnd5] + nm5[rnd6];
    }
    return nm;
    }
}
