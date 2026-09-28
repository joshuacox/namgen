#include "final_fantasy-elezens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_final_fantasy_elezens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"A", "E", "I", "O", "U", "Au", "Eau", "A", "E", "I", "O"};
    static constexpr std::string_view nm2[] = {"b", "d", "f", "j", "l", "m", "n", "p", "r", "s", "t", "v", "z", "br", "dr", "fr", "gr", "str", "tr", "vr", "rr", "fl", "gl", "ll", "pl", "rl", "ch", "ph", "sh", "lb", "ld", "lf", "lm", "ln", "lp", "ls", "lv", "lw"};
    static constexpr std::string_view nm3[] = {"B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "R", "S", "T", "V", "Z", "Br", "Dr", "Gr", "Pr", "Tr", "Cl", "Gl", "Sh", "Ph"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "eau", "oi", "au", "io", "ai", "eo", "ou", "ei", "io", "ia"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "f", "h", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "y", "z", "ff", "ll", "mm", "nn", "rr", "ss", "tt", "sh", "ph", "ch"};
    static constexpr std::string_view nm6[] = {"onne", "inne", "anne", "ionne", "ianne", "one", "ine", "ane", "ione", "iane", "ette", "elle", "itte", "ie", "iene", "enne", "ene", "eanne", "eane", "eone", "eonne"};
    static constexpr std::string_view nm7[] = {"ant", "ault", "aut", "aux", "ax", "eaux", "ent", "ert", "eux", "ex", "ix", "oix", "ont", "ort", "oux"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "ui", "eau", "ai", "ou", "au", "ui", "ea", "ie"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "l", "m", "n", "p", "r", "s", "t", "v"};
    static constexpr std::string_view nm10[] = {"", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"b", "c", "d", "f", "g", "h", "j", "l", "m", "n", "p", "r", "s", "t", "v"};
    static constexpr std::string_view nm12[] = {"ain", "air", "aire", "ame", "anc", "and", "ane", "ant", "ard", "at", "ault", "aut", "aux", "eaux", "elle", "ent", "eois", "ert", "ette", "eur", "eux", "ie", "ier", "iere", "ieu", "in", "ine", "ins", "ione", "ionne", "ois", "oix", "on", "ond", "ont", "ort", "oud", "oux", "oy", "uet", "uste"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 16) {
    rnd9 = 0;
    }
    if (rnd8 > 15) {
    while (rnd9 == 0) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    names = nm1[rnd] + nm2[rnd2] + nm6[rnd5] + " " + nm3[rnd6] + nm8[rnd7] + nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm12[rnd11];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 16) {
    rnd9 = 0;
    }
    if (rnd8 > 15) {
    while (rnd9 == 0) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm6[rnd4] + " " + nm3[rnd6] + nm8[rnd7] + nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm12[rnd11];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 16) {
    rnd9 = 0;
    }
    if (rnd8 > 15) {
    while (rnd9 == 0) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    names = nm1[rnd] + nm2[rnd2] + nm7[rnd5] + " " + nm3[rnd6] + nm8[rnd7] + nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm12[rnd11];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm9);
    rnd9 = rng() % std::size(nm10);
    if (rnd8 < 16) {
    rnd9 = 0;
    }
    if (rnd8 > 15) {
    while (rnd9 == 0) {
    rnd9 = rng() % std::size(nm10);
    }
    }
    rnd10 = rng() % std::size(nm11);
    rnd11 = rng() % std::size(nm12);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm7[rnd4] + " " + nm3[rnd6] + nm8[rnd7] + nm9[rnd8] + nm10[rnd9] + nm11[rnd10] + nm12[rnd11];
    }
    }
    return names;
    }
}
