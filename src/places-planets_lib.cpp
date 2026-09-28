#include "places-planets_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_planets_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "i", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "u"};
    static constexpr std::string_view nm3[] = {"br", "cr", "dr", "fr", "gr", "pr", "str", "tr", "bl", "cl", "fl", "gl", "pl", "sl", "sc", "sk", "sm", "sn", "sp", "st", "sw", "ch", "sh", "th", "wh"};
    static constexpr std::string_view nm4[] = {"ae", "ai", "ao", "au", "a", "ay", "ea", "ei", "eo", "eu", "e", "ey", "ua", "ue", "ui", "uo", "u", "uy", "ia", "ie", "iu", "io", "iy", "oa", "oe", "ou", "oi", "o", "oy"};
    static constexpr std::string_view nm5[] = {"turn", "ter", "nus", "rus", "tania", "hiri", "hines", "gawa", "nides", "carro", "rilia", "stea", "lia", "lea", "ria", "nov", "phus", "mia", "nerth", "wei", "ruta", "tov", "zuno", "vis", "lara", "nia", "liv", "tera", "gantu", "yama", "tune", "ter", "nus", "cury", "bos", "pra", "thea", "nope", "tis", "clite"};
    static constexpr std::string_view nm6[] = {"una", "ion", "iea", "iri", "illes", "ides", "agua", "olla", "inda", "eshan", "oria", "ilia", "erth", "arth", "orth", "oth", "illon", "ichi", "ov", "arvis", "ara", "ars", "yke", "yria", "onoe", "ippe", "osie", "one", "ore", "ade", "adus", "urn", "ypso", "ora", "iuq", "orix", "apus", "ion", "eon", "eron", "ao", "omia"};
    static constexpr std::string_view nm7[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

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
    rnd = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm4[rnd4] + nm5[rnd5];
    } else if (i < 8) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm5);
    names = nm3[rnd3] + nm2[rnd2] + nm1[rnd] + nm2[rnd4] + nm5[rnd5];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm7);
    names = nm3[rnd] + nm6[rnd2] + " " + nm7[rnd3] + nm7[rnd4] + nm7[rnd5] + nm7[rnd6];
    }
    return names;
    }
}
