#include "places-sky_islands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_sky_islands_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "b", "c", "d", "dh", "f", "g", "h", "l", "m", "n", "ph", "s", "sh", "th", "v", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "o", "a", "e", "i", "o", "u", "a", "e", "o", "ea", "ae", "ia", "ai", "eo"};
    static constexpr std::string_view nm3[] = {"b", "b", "f", "f", "ff", "g", "g", "h", "h", "j", "j", "l", "l", "ll", "m", "m", "mm", "n", "n", "nn", "r", "r", "s", "s", "ss", "th", "th", "v", "v", "b", "bh", "bl", "bs", "br", "f", "ff", "fl", "fr", "g", "gh", "gn", "gl", "h", "hn", "hl", "hm", "j", "l", "lf", "ll", "lt", "lc", "lb", "ld", "lm", "ln", "lr", "lw", "m", "mm", "mn", "mr", "n", "nn", "ns", "nth", "nt", "nm", "nf", "nph", "pr", "phr", "r", "rl", "rm", "rn", "s", "sf", "sh", "sp", "st", "sw", "ss", "sn", "sm", "th", "v"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "", "f", "h", "l", "m", "n", "r", "s", "th"};
    static constexpr std::string_view nm6[] = {"Island", "Enclave", "Isle", "Islet", "Island", "Isle"};
    static constexpr std::string_view nm5[] = {"Aeranas", "Aerene", "Aeria", "Aeris", "Aeros", "Aerule", "Albatross", "Angel", "Apex", "Apogee", "Ataraxia", "Ataraxis", "Atmos", "Aura", "Aurora", "Avia", "Avian", "Avis", "Azura", "Azure", "Azuris", "Billow", "Bliss", "Borealis", "Buoya", "Bustard", "Cassowary", "Celes", "Celeste", "Cerulea", "Cerulis", "Cerulle", "Chinook", "Cirrostratus", "Cirrus", "Condor", "Crane", "Crow", "Crown", "Cuckoo", "Cumulus", "Dove", "Eagle", "Elysium", "Empyre", "Empyrea", "Empyris", "Falcon", "Flamingo", "Gale", "Griffin", "Gull", "Halo", "Halos", "Harmony", "Harpy", "Hippogriff", "Hummingbird", "Imperos", "Macaw", "Mistral", "Mistros", "Murmus", "Nebula", "Nightingale", "Nightowl", "Obelisk", "Owl", "Ozone", "Peacock", "Pegasus", "Pelican", "Phoenix", "Pigeon", "Raven", "Serenity", "Solace", "Sonas", "Sonus", "Sparrow", "Spire", "Stork", "Storm", "Stormy", "Stratos", "Stratus", "Swan", "Swift", "Thunder", "Toocan", "Tranquility", "Tropos", "Tumul", "Tumulus", "Utopia", "Valkyrie", "Ventis", "Vertex", "Volance", "Volantis", "Volar", "Volaris", "Vortex", "Vox", "Voxis", "Vulture", "Windy", "Zenith", "Zephyr", "Zephys", "Zion"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd7 = rng() % std::size(nm6);
    if (i < 6) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 3) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + nm6[rnd7];
    } else if (i < 6) {
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd8] + nm2[rnd9] + nm4[rnd5] + " " + nm6[rnd7];
    }
    } else {
    rnd = rng() % std::size(nm5);
    names = nm5[rnd] + " " + nm6[rnd7];
    }
    return names;
    }
}
