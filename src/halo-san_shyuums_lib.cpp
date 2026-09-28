#include "halo-san_shyuums_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_halo_san_shyuums_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "", "b", "c", "d", "f", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "z"};
    static constexpr std::string_view nm2[] = {"o", "a", "u"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "g", "k", "p", "t", "rd", "rb", "rc", "rd", "rg", "rk", "rp", "rt"};
    static constexpr std::string_view nm4[] = {"b", "br", "c", "cr", "d", "dr", "f", "fr", "h", "k", "l", "m", "n", "p", "pr", "r", "s", "sr", "t", "tr", "v", "vr", "w", "z", "mr", "kr"};
    static constexpr std::string_view nm5[] = {"b", "bt", "c", "ct", "d", "f", "ft", "h", "k", "kt", "l", "m", "mnt", "mt", "n", "nb", "nc", "nct", "nd", "nf", "nft", "nst", "nt", "p", "pt", "r", "rc", "rnt", "rt", "s", "sc", "st", "t", "w", "wt", "z", "zc", "zt"};
    static constexpr std::string_view nm6[] = {"o", "a", "u", "", ""};
    static constexpr std::string_view nm7[] = {"Prophet", "Minister", "High Prophet"};
    static constexpr std::string_view nm8[] = {"Absolution", "Analysis", "Atonement", "Attrition", "Audacity", "Aversion", "Boldness", "Bravery", "Candor", "Caution", "Censure", "Charity", "Civility", "Clemency", "Commitment", "Compassion", "Confidence", "Conscience", "Conservancy", "Constraint", "Contrition", "Control", "Conviction", "Courage", "Courtesy", "Creed", "Decency", "Defiance", "Dignity", "Disdain", "Doubt", "Duty", "Elegance", "Empathy", "Endurance", "Esteem", "Etiology", "Fairness", "Favor", "Fervor", "Forbearance", "Fortitude", "Gallantry", "Generosity", "Goodwill", "Grace", "Honesty", "Honor", "Inhibition", "Inquisition", "Insolence", "Integrity", "Interrogation", "Intrepidity", "Investigation", "Kindness", "Legitimacy", "Lenience", "Mercy", "Moderation", "Nobility", "Objection", "Obligation", "Patience", "Penance", "Penitence", "Pity", "Principles", "Protection", "Protest", "Prowess", "Qualm", "Recognition", "Regret", "Reliance", "Remorse", "Repentance", "Resilience", "Resistance", "Restraint", "Restriction", "Reverence", "Salvation", "Saving", "Silence", "Sincerity", "Sorrow", "Stewardship", "Strength", "Suffering", "Supposition", "Sympathy", "Tenacity", "Tolerance", "Trust", "Truth", "Valiance", "Veracity", "Vigor", "Virtue"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (rnd < 7) {
    while (rnd3 < 7) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    if (rnd > 6) {
    while (rnd3 < 6) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + " " + nm4[rnd4] + nm2[rnd5] + nm5[rnd6] + nm6[rnd7];
    } else {
    rnd = rng() % std::size(nm7);
    rnd2 = rng() % std::size(nm8);
    names = nm7[rnd] + " of " + nm8[rnd2];
    }
    return names;
    }
}
