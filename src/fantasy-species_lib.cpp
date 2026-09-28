#include "fantasy-species_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_species_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "ai", "ea", "eo", "oi", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "ch", "chr", "chl", "z", "br", "cr", "dr", "fr", "gr", "kr", "pr", "sr", "tr", "str", "bl", "cl", "fl", "kl", "pl", "sl", "vl", "ph", "sh"};
    static constexpr std::string_view nm3[] = {"a", "e", "o", "i", "u", "a", "e", "o", "i", "u", "ai", "ea", "eo", "oi", "y"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z", "bl", "br", "bb", "bs", "bd", "bn", "ch", "chl", "chr", "cl", "ck", "cn", "cr", "cc", "dr", "dl", "ds", "dn", "dd", "fl", "ff", "fr", "fn", "gr", "gn", "gs", "gl", "gg", "kl", "kh", "kn", "kk", "kr", "ll", "ln", "lm", "ls", "ld", "lb", "mm", "mn", "md", "ml", "ms", "nn", "nd", "ng", "nt", "ns", "nst", "pp", "ph", "pl", "ps", "pd", "pr", "rr", "rd", "rn", "rl", "rs", "rt", "ss", "sh", "sht", "sl", "sn", "sr", "st", "str", "tr", "tt", "th", "tn", "tm", "tv", "vv", "vl", "vn"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "x", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "x", "ch", "ck", "th", "gs", "rd", "rg", "rk", "rm", "rn", "rq", "rs", "rst", "rx", "ds", "cs", "fs", "gs", "ks", "ls", "ms", "ns", "ps", "rs", "ts", "st", "ph", "sh", "ln", "lm", "lk", "ld", "lt"};
    static constexpr std::string_view nm8[] = {"c", "gian", "lese", "lian", "n", "nan", "ne", "nee", "nes", "nian", "nin", "no", "nsian", "r", "rd", "rn", "se", "sh", "t", "te", "vese", "vian"};
    static constexpr std::string_view check[] = {"anal", "anus", "arse", "ass", "balls", "bastard", "biatch", "bitch", "bollock", "bollok", "boner", "boob", "bugger", "bum", "butt", "clitoris", "cock", "coon", "crap", "cunt", "damn", "dick", "dildo", "dyke", "fag", "feck", "felching", "fellate", "fellatio", "flange", "fuck", "gay", "goddamn", "homo", "jackass", "jerk", "jizz", "knobend", "labia", "muff", "nigga", "nigger", "penis", "piss", "poop", "prick", "pube", "pussy", "queer", "scrotum", "sex", "shit", "slut", "smegma", "spunk", "tit", "tosser", "turd", "twat", "vagina", "wank", "whore", "wtf"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0; int j = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (i < 5) {
    rnd4 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm7[rnd4];
    for (j = 0; j < std::size(check); j++) {
    while (names == check[j]) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm7[rnd4];
    }
    }
    } else {
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd6] + nm8[rnd7];
    for (j = 0; j < std::size(check); j++) {
    while (names == check[j]) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm8);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm3[rnd6] + nm8[rnd7];
    }
    }
    }
    return names;
    }
}
