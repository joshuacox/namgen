#include "doctor_who-daleks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_doctor_who_daleks_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"C", "Ch", "D", "Dh", "G", "Gh", "K", "Kh", "R", "S", "Th", "V"};
    static constexpr std::string_view nm2[] = {"a", "aa", "e", "a", "e", "a", "e", "i", "o"};
    static constexpr std::string_view nm3[] = {"c", "d", "k", "m", "n", "r", "s", "ss", "st", "t", "th", "y"};

    std::string names; size_t ext = 0; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

ext = rng() % 150;
i = rng() % 10; {
    if (ext == 1) {
    names = "Exterminate! Exterminate! Exterminate!";
    if (i == 9) {
    names = "Just kidding. :) Enjoy this Easter egg.";
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3];
    }
    return names;
    }
}
