#include "halo-sangheilis_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_halo_sangheilis_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "gr", "j", "k", "kh", "l", "mr", "n'th", "r", "rt", "s", "t", "th", "v", "x", "z", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm3[] = {"da", "do", "g", "ga", "ha", "ka", "kan", "ko", "l", "la", "pa", "po", "r", "ra", "re", "ro", "s", "sa", "san", "so", "sze", "t", "ta", "tan", "to", "va", "vo", "vu", "za", "ze", "zo"};
    static constexpr std::string_view nm4[] = {"Cha", "Da", "Dra", "Ga", "Go", "Ha", "Ka", "Ko", "Kra", "Ku", "La", "Lo", "Lu", "Ma", "Mda", "Mo", "Mu", "Na", "Nra", "Nu", "Ra", "Re", "Ro", "Sa", "Sra", "Su", "Ta", "Te", "Tra", "Tu", "Va", "Vo", "Vra", "Vu", "Wa", "Za", "Zo", "Zu"};
    static constexpr std::string_view nm5[] = {"cam", "dam", "dom", "dum", "fam", "fum", "gam", "gram", "gum", "ham", "hom", "kam", "lcam", "lkam", "ma", "man", "nam", "ngam", "nom", "ntak", "ralum", "ram", "rom", "rum", "sam", "sov", "sum", "tam", "tan", "ttin", "tum", "vam", "vum", "zam", "zum"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "h", "g", "k", "kh", "l", "m", "n", "r", "sh", "s", "t", "th", "v", "x", "z"};
    static constexpr std::string_view nm7[] = {"a", "e", "o", "u"};
    static constexpr std::string_view nm8[] = {"ea", "ha", "he", "ia", "ie", "io", "la", "le", "lo", "ma", "me", "mi", "mo", "n", "na", "ne", "pa", "sa", "se", "sha", "she", "so", "wa", "we", "xa", "xe", "xi", "ya", "ye", "yo"};
    static constexpr std::string_view nm9[] = {"", "", "ee", "", "ai"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    rnd3 = rng() % std::size(nm8);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm9);
    names = nm6[rnd] + nm7[rnd2] + nm8[rnd3] + " '" + nm4[rnd4] + nm5[rnd5] + nm9[rnd6];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm9);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + " '" + nm4[rnd4] + nm5[rnd5] + nm9[rnd6];
    }
    return names;
    }
}
