#include "fantasy-amazons_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$fantasy$amazons() {
 *       var nm1 = [...];
 *       var nm2 = [...];
 *       var nm3 = [...];
 *       var nm4 = [...];
 *       var nm5 = [...];
 *       var nm6 = [...];
 *
 *       i = Math.floor(Math.random() * 10);
 *       if (i < 5) {
 *           // pattern 1
 *           names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4] + nm6[rnd5];
 *       } else {
 *           // pattern 2
 *           names = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
 *       }
 *       return names;
 *   }
 *
 * The C++ version follows the same logic, using the supplied RNG.
 */
std::string generate_fantasy_amazons_name(std::mt19937& rng) {
    static const std::vector<std::string> nm1 = {
        "b", "bl", "br", "c", "chr", "cl", "cr", "d", "dr", "f", "g", "gl", "gr", "h", "j", "k", "kl", "kr", "m", "n", "p", "ph", "ps", "pr", "r", "rh", "s", "sm", "sc", "t", "th", "v", "x", "", "", "", "", "", "", ""
    };
    static const std::vector<std::string> nm2 = {
        "a", "e", "i", "o", "u", "y", "ou", "ei", "oe", "ao", "io", "eo", "a", "e", "i", "o", "u"
    };
    static const std::vector<std::string> nm3 = {
        "c", "d", "k", "l", "m", "r", "s", "t", "x", "", "", "", "", "", "", "", "", "", "", ""
    };
    static const std::vector<std::string> nm4 = {
        "c", "d", "k", "l", "m", "r", "s", "t", "x", "nd", "nt", "lk", "lc", "ll", "ndr", "br", "st", "ch", "br", "cl", "ph", "rm", "pp", "pt", "rp", "nth", "th", "rg", "thr", "dm", "lth", "lc", "chr", "phn", "dr", "mn", "rr", "rrh"
    };
    static const std::vector<std::string> nm5 = {
        "a", "e", "i", "o", "u", "y", "", "", "", "", "", "", "", "", ""
    };
    static const std::vector<std::string> nm6 = {
        "adia", "ameia", "anta", "asca", "cabe", "ce", "cleia", "cyone", "cyra", "da", "dae", "dia", "dice", "dora", "enice", "esia", "estra", "estris", "gea", "gone", "haedra", "hyia", "ippe", "isbe", "ises", "leia", "lene", "lete", "liope", "lipe", "lyte", "mache", "meia", "nache", "nara", "neira", "nestra", "nia", "nippe", "noe", "nousa", "ope", "padia", "pedo", "peia", "pesia", "phale", "pyle", "pyte", "rera", "reto", "roe", "scyra", "ses", "sippe", "sose", "tane", "thippe", "thoe", "thya", "thye", "thyia", "ybe", "yche", "yle", "yme", "yne", "yope", "yrbe", "ytie"
    };

    // Random i in [0,9]
    int i = static_cast<int>(rng() % 10);
    std::string name;

    if (i < 5) {
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm3.size();
        size_t rnd4 = rng() % nm5.size();
        size_t rnd5 = rng() % nm6.size();
        name = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd4] + nm6[rnd5];
    } else {
        size_t rnd  = rng() % nm1.size();
        size_t rnd2 = rng() % nm2.size();
        size_t rnd3 = rng() % nm4.size();
        size_t rnd4 = rng() % nm2.size();
        size_t rnd5 = rng() % nm6.size();
        name = nm1[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
    }

    return name;
}
