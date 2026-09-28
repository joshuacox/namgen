#include "elder_scrolls-daedrics_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_daedrics_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "br", "c", "cr", "ch", "d", "dr", "g", "gr", "j", "k", "kr", "kn", "km", "p", "pr", "q", "qr", "r", "st", "str", "t", "tr", "v", "vr", "w", "wr", "x", "z", "zr", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y", "au", "ou", "ei", "uy", "oe", "ua", "ue", "uo", "a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "g", "j", "k", "l", "m", "p", "q", "r", "s", "t", "v", "w", "x", "z", "br", "cr", "dr", "gr", "kr", "km", "pr", "qr", "st", "tr", "xx", "g", "q'", "k'", "rr", "r'", "t'", "tt", "vv", "v'", "x'", "z'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"ag", "ah", "al", "ala", "alag", "ath", "bal", "cath", "cius", "cus", "dea", "dia", "hala", "icus", "ina", "ine", "ira", "ite", "lag", "maeus", "mina", "nal", "nes", "oth", "rath", "roth", "unes", "ura", "us", "vus", "yite", };
    static constexpr std::string_view nm6[] = {"b", "bl", "c", "cl", "ch", "d", "f", "fr", "fl", "g", "gl", "gn", "h", "kl", "kn", "m", "n", "p", "pl", "ph", "q", "ql", "s", "st", "sl", "t", "v", "vl", "w", "z", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"a", "e", "i", "o", "u", "y", "ae", "ea", "eo", "oe", "ie", "ue", "ua", "a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm8[] = {"b", "c", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "w", "bb", "bl", "ff", "fl", "gl", "gn", "hh", "hs", "hl", "hn", "hm", "ks", "ll", "lh", "kh", "bh", "ch", "dh", "lm", "ln", "lf", "mm", "mn", "ms", "nn", "ns", "p", "ph", "ps", "rf", "ss", "st", "sh", "th", "ts", "s'", "l'", "n'", "m'", "f'", "h'"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "y", "", "", "", "", "", ""};
    static constexpr std::string_view nm10[] = {"ag", "ah", "al", "ala", "alag", "ath", "bal", "cath", "cius", "cus", "dea", "dia", "hala", "icus", "ina", "ine", "ira", "ite", "lag", "maeus", "mina", "nal", "nes", "oth", "rath", "roth", "unes", "ura", "us", "vus", "yite"};
    static constexpr std::string_view nm11[] = {"Insomnia", "Lunacy", "Luna", "Mania", "Phobia", "Luna", "Solar", "Dementia", "Hysteria", "Delirium", "Pedigree", "Bane", "Anathema", "Grace", "Hope", "Malison", "Misery", "Blight", "Poison", "Venom", "Calamity", "Malificent", "Sinister", "Grim", "Gloom", "Dire", "Malign", "Malefic", "Joy", "Nova", "Misty", "Dusk", "Dawn", "Twilight", "Rogue", "Ominous", "Vile", "Nefarious", "Melancholy", "Saturnine", "Solemn", "Glum", "Austere", "Morose", "Surly", "Brusque", "Gruff", "Demise", "Necrosis", "Silence", "Enigma", "Virulence", "Spite", "Malign", "Storm", "Serene", "Harmony", "Strife", "Striker", "Sloth", "Drowsy", "Supine", "Laggard"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    if (rnd3 < 46) {
    while (rnd4 > 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    } else if (i < 8) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm9);
    if (rnd3 < 46) {
    while (rnd4 > 5) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    rnd5 = rng() % std::size(nm10);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + nm9[rnd4] + nm10[rnd5];
    } else {
    rnd = rng() % std::size(nm11);
    names = nm11[rnd];
    }
    return names;
    }
}
