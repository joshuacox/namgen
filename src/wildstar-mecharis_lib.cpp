#include "wildstar-mecharis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_wildstar_mecharis_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "d", "gl", "h", "l", "m", "p", "pr", "r", "s", "t", "tr", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "io", "au", "ei"};
    static constexpr std::string_view nm3[] = {"c", "cr", "chr", "ct", "g", "gn", "gz", "kr", "kt", "kx", "kn", "l", "lb", "ll", "mph", "n", "ph", "pr", "ps", "r", "rx", "rc", "rct", "rm", "rv", "rz", "st", "sp", "t", "tr", "v", "x", "xt", "c", "g", "l", "n", "r", "t", "v", "x"};
    static constexpr std::string_view nm4[] = {"", "c", "cs", "n", "m", "r", "s", "t", "x"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "c", "d", "h", "l", "m", "n", "ph", "phr", "s", "sh", "t", "th", "v", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "a", "e", "i", "o", "y", "y", "y", "ia", "au", "ie", "io"};
    static constexpr std::string_view nm7[] = {"b", "br", "c", "d", "dr", "f", "fr", "fn", "fl", "gh", "lv", "ln", "lm", "lz", "lph", "lf", "m", "mz", "mr", "mn", "n", "nv", "nz", "r", "rk", "rv", "rz", "rs", "t", "th", "v", "x", "z", "zn", "b", "c", "d", "f", "m", "n", "r", "t", "v", "x", "z", "b", "c", "d", "f", "m", "n", "r", "t", "v", "x", "z"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "c", "h", "n", "l", "ll", "s", "sh", "th", "x"};
    static constexpr std::string_view nm9[] = {"Alpha", "Beta", "Bi", "Cen", "Cent", "Centi", "Chi", "Dec", "Deca", "Decem", "Delta", "Di", "Dodeca", "Du", "Duo", "Duodec", "Ennea", "Epsilon", "Eta", "Gamma", "Hec", "Hecato", "Hect", "Hep", "Hept", "Hepta", "Hex", "Hexa", "Iota", "Kappa", "Kilo", "Lambda", "Milli", "Mono", "Mu", "Non", "Nove", "Nu", "Nulli", "Oc", "Oct", "Octa", "Octo", "Ogdo", "Omega", "Penta", "Phi", "Pi", "Psi", "Quadri", "Quadru", "Rho", "Sedec", "Semi", "Sep", "Sept", "Sigma", "Tau", "Tetra", "Theta", "Tri", "Trio", "Unci", "Uni", "Upsilon", "Xi", "Zeta"};
    static constexpr std::string_view nm10[] = {"bit", "byt", "coil", "col", "cue", "cy", "frag", "gine", "helix", "hicle", "jet", "lap", "lic", "lit", "lix", "logy", "loop", "maton", "mech", "mic", "mics", "net", "nic", "nics", "niq", "nis", "nism", "nix", "nogy", "nox", "pin", "ping", "pute", "ram", "rom", "ron", "ser", "sor", "tec", "tic", "tics", "ton", "tred", "tric", "tron", "vex", "vox", "ware", "xis", "zip"};

    std::string lname; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm9);
    rnd7 = rng() % std::size(nm10);
    lname = nm9[rnd6] + nm10[rnd7];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    rnd5 = rng() % std::size(nm8);
    if (rnd < 5) {
    while (rnd5 < 5) {
    rnd5 = rng() % std::size(nm8);
    }
    }
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + lname;
    } else {
    rnd6 = rng() % std::size(nm7);
    rnd7 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd6] + nm6[rnd7] + " " + lname;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd < 5) {
    while (rnd5 == 0) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    }
    return names;
    }
}
