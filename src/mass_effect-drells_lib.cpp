#include "mass_effect-drells_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_drells_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1_1[] = {""};
    static constexpr std::string_view nm2[] = {"ka", "ki", "ku", "ke", "ko", "sa", "si", "su", "se", "so", "sha", "shi", "shu", "she", "sho", "ta", "ti", "tu", "te", "to", "tha", "thi", "thu", "the", "tho", "dra", "dri", "dru", "dre", "dro", "ma", "mi", "mu", "me", "mo", "na", "ni", "nu", "ne", "no", "ha", "hi", "hu", "he", "ho", "fa", "fi", "fu", "fe", "fo", "ra", "ri", "ru", "re", "ro", "la", "li", "lu", "le", "lo", "ya", "yi", "yu", "ye", "yo"};
    static constexpr std::string_view nm3[] = {"n", "l", "t", "k", "s", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"ka", "ki", "ku", "ke", "ko", "sa", "si", "su", "se", "so", "ta", "ti", "tu", "te", "to", "ma", "mi", "mu", "me", "mo", "na", "ni", "nu", "ne", "no", "ha", "hi", "hu", "he", "ho", "fa", "fi", "fu", "fe", "fo", "ra", "ri", "ru", "re", "ro", "la", "li", "lu", "le", "lo", "ya", "yi", "yu", "ye", "yo"};
    static constexpr std::string_view nm5[] = {"n", "l", "t", "k", "s", "h", "m", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"n", "l", "t", "k", "s"};
    static constexpr std::string_view nm1_2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm1_3[] = {""};

    ArrayView nm1; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

    nm1 = make_view(nm1_1);
    if (type == 1) {
    nm1 = make_view(nm1_2);
    } else {
    nm1 = make_view(nm1_3);
    }
i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm2);
    rnd7 = rng() % std::size(nm6);
    rnd8 = rng() % std::size(nm7);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + " " + nm2[rnd6] + nm6[rnd7] + nm7[rnd8];
    return names;
    }
}
