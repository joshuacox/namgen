#include "pop_culture-homestucks_lib.h"

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <vector>

static std::string random_choice(const std::vector<std::string>& vec,
                                std::mt19937& rng) {
    return vec[rng() % vec.size()];
}

/* The original JavaScript generator builds a name from several
 * character pools (nm0‑nm6).  The logic is reproduced verbatim
 * (modulo language differences) to keep the output identical.
 */
std::string generate_pop_culture_homestucks_name(std::mt19937& rng) {
    const std::vector<std::string> nm0 = {"c", "d", "f", "g", "h", "k", "l", "m",
                                          "n", "r", "p", "s", "t", "v", "x",
                                          "z"};
    const std::vector<std::string> nm1 = {"cr", "dr", "fr", "gr", "gh", "kh",
                                          "kr", "rh", "ph", "pr", "sk", "st",
                                          "tr", "vr", "xh", "zh"};
    const std::vector<std::string> nm2 = {"a", "e", "i", "o", "u", "a", "e", "i",
                                          "o", "u", "a", "e", "i", "o", "u",
                                          "a", "e", "i", "o", "u", "a", "e",
                                          "i", "o", "u", "a", "e", "i", "o",
                                          "u", "aa", "ai", "ea", "ee", "eu",
                                          "ei", "ia", "ie", "io"};
    const std::vector<std::string> nm3 = {"a", "e", "i", "o", "u"};
    const std::vector<std::string> nm4 = {"dc", "dj", "dn", "dr", "dv", "dy",
                                          "dz", "fg", "fk", "fr", "ft", "fz",
                                          "gg", "gh", "gn", "gr", "gt", "gz",
                                          "kh", "kk", "kn", "kr", "ks", "kt",
                                          "kz", "ld", "lg", "lk", "ll", "lm",
                                          "ln", "lr", "lv", "ly", "mk", "mm",
                                          "mr", "mv", "mz", "nc", "nd", "ng",
                                          "nk", "nl", "nn", "nr", "nt", "nv",
                                          "ny", "nz", "qq", "qr", "qt", "rc",
                                          "rg", "rk", "rl", "rm", "rn", "rr",
                                          "rt", "rv", "rx", "rz", "sc", "sh",
                                          "sk", "sl", "sm", "sn", "sp", "sr",
                                          "ss", "st", "sy", "th", "tr", "vl",
                                          "vr", "zl", "zr", "zz"};
    const std::vector<std::string> nm5 = {"d", "f", "g", "k", "l", "m", "n",
                                          "q", "r", "s", "t", "v", "y", "z"};
    const std::vector<std::string> nm6 = {"h", "k", "m", "n", "r", "s", "t",
                                          "x", "z"};

    // i = Math.floor(Math.random() * 10);
    std::size_t i = rng() % 10;
    std::string namesf, names;

    if (i % 2 == 0) {
        // first branch
        std::size_t rnd  = rng() % nm0.size();
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm4.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            while (rnd4 > 29) {
                rnd4 = rng() % nm2.size();
            }
        }
        if (rnd2 < 30 && rnd4 < 30) {
            std::size_t rnd5 = rng() % nm6.size();
            namesf = nm0[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
        } else {
            namesf = nm0[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4];
        }
    } else if (i % 3 == 0) {
        // second branch
        std::size_t rnd  = rng() % nm1.size();
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm5.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            while (rnd4 > 29) {
                rnd4 = rng() % nm2.size();
            }
        }
        if (rnd2 < 30 && rnd4 < 30) {
            std::size_t rnd5 = rng() % nm6.size();
            namesf = nm1[rnd] + nm2[rnd2] + nm5[rnd3] + nm2[rnd4] + nm6[rnd5];
        } else {
            namesf = nm1[rnd] + nm2[rnd2] + nm5[rnd3] + nm2[rnd4];
        }
    } else {
        // third branch
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm4.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            if (rnd4 > 29) {
                namesf = nm2[rnd2] + nm4[rnd3] + nm2[rnd4];
            } else {
                std::size_t rnd5 = rng() % nm6.size();
                namesf = nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
            }
        } else {
            if (rnd4 > 29) {
                std::size_t rnd5 = rng() % nm6.size();
                namesf = nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
            } else {
                std::size_t rnd5 = rng() % nm5.size();
                std::size_t rnd6 = rng() % nm3.size();
                namesf = nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm5[rnd5] + nm3[rnd6];
            }
        }
    }

    // second half – add a second word
    if (i % 2 == 0) {
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm4.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            if (rnd4 > 29) {
                names = namesf + " " + nm2[rnd2] + nm4[rnd3] + nm2[rnd4];
            } else {
                std::size_t rnd5 = rng() % nm6.size();
                names = namesf + " " + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
            }
        } else {
            if (rnd4 > 29) {
                std::size_t rnd5 = rng() % nm6.size();
                names = namesf + " " + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
            } else {
                std::size_t rnd5 = rng() % nm5.size();
                std::size_t rnd6 = rng() % nm3.size();
                names = namesf + " " + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm5[rnd5] + nm3[rnd6];
            }
        }
    } else if (i % 3 == 0) {
        std::size_t rnd  = rng() % nm0.size();
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm4.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            while (rnd4 > 29) {
                rnd4 = rng() % nm2.size();
            }
        }
        if (rnd2 < 30 && rnd4 < 30) {
            std::size_t rnd5 = rng() % nm6.size();
            names = namesf + " " + nm0[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4] + nm6[rnd5];
        } else {
            names = namesf + " " + nm0[rnd] + nm2[rnd2] + nm4[rnd3] + nm2[rnd4];
        }
    } else {
        std::size_t rnd  = rng() % nm1.size();
        std::size_t rnd2 = rng() % nm2.size();
        std::size_t rnd3 = rng() % nm5.size();
        std::size_t rnd4 = rng() % nm2.size();

        if (rnd2 > 29) {
            while (rnd4 > 29) {
                rnd4 = rng() % nm2.size();
            }
        }
        if (rnd2 < 30 && rnd4 < 30) {
            std::size_t rnd5 = rng() % nm6.size();
            names = namesf + " " + nm1[rnd] + nm2[rnd2] + nm5[rnd3] + nm2[rnd4] + nm6[rnd5];
        } else {
            names = namesf + " " + nm1[rnd] + nm2[rnd2] + nm5[rnd3] + nm2[rnd4];
        }
    }

    return names;
}
