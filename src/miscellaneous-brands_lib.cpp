#include "miscellaneous-brands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_brands_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "br", "cr", "dr", "fr", "gr", "kr", "pr", "qr", "sr", "tr", "vr", "wr", "zr", "str", "spr", "st", "bl", "cl", "dl", "fl", "gl", "kl", "pl", "sl", "vl", "zl", "bh", "ch", "dh", "gh", "kh", "ph", "sh", "sch", "th", "thr", "sph", "vh", "wh", "zh", "gn", "kn", "sn", "zn", "sm", "zm", "sw", "tw", "zw", "sc"};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm4[] = {"ee", "eu", "eo", "ea", "ei", "aa", "ai", "au", "ae", "io", "ia", "iu", "ie", "oo", "oa", "ou", "oe", "oi", "uu", "ua", "ue", "ui", "uo"};
    static constexpr std::string_view nm5[] = {"bb", "bd", "bh", "br", "cc", "ch", "ck", "cl", "cr", "cs", "csh", "ct", "cth", "cz", "dd", "dg", "dn", "dr", "ff", "fk", "fn", "fr", "ft", "gb", "gd", "gg", "gh", "gm", "gn", "gr", "hh", "hk", "hl", "hm", "hn", "hr", "kh", "kk", "kn", "kr", "ks", "kt", "kz", "lb", "lc", "ld", "lf", "lg", "lh", "lk", "ll", "lm", "ln", "lp", "lph", "lq", "lr", "ls", "lsh", "lt", "lw", "lz", "mb", "md", "mh", "mk", "ml", "mm", "mn", "mp", "mph", "mr", "ms", "msh", "mt", "nc", "nd", "ng", "nk", "nl", "nn", "np", "nq", "nr", "ns", "nt", "nw", "nz", "ph", "pm", "pn", "pp", "pq", "pr", "phr", "pt", "ps", "pz", "rb", "rc", "rd", "rf", "rg", "rh", "rk", "rl", "rm", "rn", "rp", "rph", "rq", "rr", "rs", "rst", "rt", "rw", "rz", "sb", "sc", "sd", "sh", "sk", "sl", "sm", "sn", "sp", "sph", "sr", "ss", "st", "str", "sz", "th", "tl", "tm", "tn", "tr", "thr"};
    static constexpr std::string_view nm6[] = {"c", "ck", "d", "f", "g", "ght", "l", "ld", "ll", "m", "mp", "n", "nd", "ng", "ngs", "nk", "nt", "q", "p", "pp", "r", "rn", "rs", "s", "sh", "sm", "ss", "st", "t", "th", "w", "wn", "x", "y", "z"};
    static constexpr std::string_view nm7[] = {"able", "ack", "acy", "ad", "age", "ail", "ain", "ake", "al", "ale", "all", "am", "ame", "an", "ance", "ank", "ap", "app", "ar", "ash", "at", "ate", "aw", "ay", "dom", "eat", "eel", "eep", "eet", "ell", "en", "ence", "ent", "er", "ers", "esque", "est", "ful", "fy", "ible", "ic", "ical", "ice", "ick", "ide", "ier", "ies", "ife", "ify", "ight", "ile", "ill", "in", "ine", "ing", "ink", "ion", "ious", "ip", "ise", "ish", "ism", "ist", "it", "ite", "ity", "ive", "ize", "led", "less", "ment", "ned", "ness", "oat", "ock", "og", "oil", "oke", "oo", "ood", "oof", "ook", "ool", "oom", "oon", "oop", "oot", "op", "or", "ore", "orn", "ot", "ought", "ould", "ous", "ouse", "out", "ow", "own", "red", "ship", "sion", "ted", "ter", "tes", "tion", "ty", "uck", "ug", "ump", "un", "unk", "y", "zed"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "eu", "eo", "ea", "ei", "aa", "ai", "au", "ae", "io", "ia", "iu", "ie", "oo", "oa", "ou", "oe", "oi", "uu", "ua", "ue", "ui", "uo"};
    static constexpr std::string_view nm9[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "eu", "eo", "ea", "ei", "aa", "ai", "au", "ae", "io", "ia", "iu", "ie", "oo", "oa", "ou", "oe", "oi", "uu", "ua", "ue", "ui", "uo"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm11[] = {"A", "An", "Ante", "Anti", "As", "Auto", "Bi", "Bin", "Car", "Cha", "Char", "Com", "Como", "Con", "Contra", "De", "Demi", "Di", "Dis", "Du", "En", "Ex", "Extra", "Gall", "Hemi", "Hyper", "Il", "Im", "In", "Inter", "Intra", "Ir", "Micro", "Mono", "Non", "Omni", "Out", "Over", "Par", "Post", "Pre", "Pro", "Quin", "Res", "Rese", "Scar", "Semi", "Sha", "Spin", "Sta", "Stra", "Stri", "Sub", "Syn", "Tech", "Tran", "Trans", "Tri", "Un", "Uni"};

    std::string names; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd1 = rng() % std::size(nm11);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm7);
    names = nm11[rnd1] + nm2[rnd2] + nm7[rnd3];
    } else if (i < 4) {
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm10);
    names = nm1[rnd1] + nm8[rnd2] + nm6[rnd3] + nm10[rnd4];
    } else if (i < 6) {
    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm7);
    names = nm1[rnd1] + nm3[rnd2] + nm2[rnd3] + nm7[rnd4];
    } else if (i < 8) {
    rnd1 = rng() % std::size(nm11);
    rnd3 = rng() % std::size(nm7);
    names = nm11[rnd1] + nm7[rnd3];
    } else if (i < 9) {
    rnd1 = rng() % std::size(nm11);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm6);
    names = nm11[rnd1] + nm2[rnd2] + nm3[rnd3] + nm6[rnd4];
    } else {
    rnd1 = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm8);
    names = nm8[rnd1] + nm1[rnd2] + nm8[rnd3];
    }
    return names;
    }
}
