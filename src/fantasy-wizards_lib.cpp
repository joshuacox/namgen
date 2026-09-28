#include "fantasy-wizards_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_wizards_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "br", "c", "cr", "d", "dr", "g", "gr", "j", "k", "kr", "kn", "p", "pr", "q", "qr", "r", "st", "str", "t", "tr", "v", "vr", "w", "x", "z", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "g", "j", "k", "l", "m", "p", "q", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view nm5[] = {"bahn", "barin", "beus", "bin", "bus", "dalf", "del", "dium", "dore", "dus", "farihm", "faris", "feus", "flyn", "forn", "gast", "geor", "gorim", "groln", "grur", "hagan", "harad", "haris", "hith", "hone", "jahr", "jamar", "jeik", "jest", "jor", "kalis", "key", "kius", "kore", "kron", "lenor", "leus", "lin", "lius", "lore", "maex", "marim", "mazz", "monar", "morn", "naxx", "neus", "nior", "nitor", "norim", "pan", "phior", "pius", "pniar", "prix", "qiohr", "qium", "qor", "qrax", "quam", "ras", "rhan", "rius", "ronin", "rune", "shan", "sim", "sior", "sorin", "strum", "tarum", "taz", "thar", "tior", "trix", "veus", "viar", "vior", "vius", "vras", "wahl", "wix", "wras", "wrick", "wyn", "xarif", "xeor", "xium", "xius", "xon", "ydor", "ynas", "yorn", "yrin", "yus", "zahr", "zax", "zif", "zohr", "zor"};
    static constexpr std::string_view nm6[] = {"b", "bl", "c", "cl", "d", "f", "fr", "fl", "g", "gl", "gn", "h", "kl", "kn", "m", "n", "p", "pl", "ph", "q", "s", "st", "sl", "t", "v", "vl", "w", "z"};
    static constexpr std::string_view nm7[] = {"b", "c", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "w"};
    static constexpr std::string_view nm8[] = {"belle", "baris", "beus", "bine", "beus", "dali", "delis", "disum", "dores", "deis", "faeh", "faris", "fea", "fyne", "fora", "gaell", "georis", "gis", "garis", "grith", "haen", "harith", "harise", "hith", "hione", "jelle", "jes", "jyll", "jiane", "jior", "kealis", "key", "kely", "kora", "kon", "lyn", "leas", "lune", "laes", "lore", "maev", "mari", "meazz", "monora", "morith", "naxix", "neas", "nilor", "nirn", "nora", "paen", "phi", "pianne", "pyx", "prixys", "qiohn", "qille", "qora", "qix", "qian", "ras", "rihan", "ris", "ro", "rune", "shan", "saem", "sinor", "soph", "strea", "taris", "taz", "thal", "tosh", "trix", "veus", "via", "vira", "vys", "vae", "weahl", "wix", "wrys", "waelle", "wyn", "xaryl", "xea", "xis", "xyll", "xone", "ydae", "yna", "yora", "yrin", "yeas", "zahn", "zyxi", "zif", "zohra", "zora"};
    static constexpr std::string_view nm9[] = {"b", "bl", "c", "cl", "d", "f", "fr", "fl", "g", "gl", "gn", "h", "kl", "kn", "m", "n", "p", "pl", "ph", "q", "s", "st", "sl", "t", "v", "vl", "w", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm8);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd5] + nm8[rnd6];
    } else if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm8);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd5] + nm8[rnd6];
    } else if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm8);
    names = nm1[rnd] + nm9[rnd2] + nm3[rnd3] + nm7[rnd4] + nm3[rnd5] + nm8[rnd6];
    } else if (i < 8) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm8);
    names = nm1[rnd] + nm9[rnd2] + nm3[rnd5] + nm8[rnd6];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm8);
    names = nm3[rnd] + nm4[rnd2] + nm8[rnd5];
    }
    } else {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd5] + nm5[rnd6];
    } else if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd5] + nm5[rnd6];
    } else if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm6[rnd2] + nm3[rnd3] + nm7[rnd4] + nm3[rnd5] + nm5[rnd6];
    } else if (i < 8) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm5);
    names = nm1[rnd] + nm6[rnd2] + nm3[rnd5] + nm5[rnd6];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd5];
    }
    }
    return names;
    }
}
