#include "real-burmese_myanmars_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_burmese_myanmars_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm2[] = {"Aeindra", "Ag", "Aung", "Aye", "Cho", "Ei", "Eindra", "Eka", "Hayma", "Haymar", "Hlaing", "Hline", "Hnin", "Hsu", "Htay", "Htet", "Htun", "Inzali", "Kay", "Khaing", "Khin", "Khine", "Kyaw", "Le", "Marlar", "May", "Mon", "Myat", "Myint", "Myitzu", "Naing", "Nanda", "Nandar", "New", "Nhin", "Nila", "Nilar", "Nine", "Nway", "Nwe", "Ohmar", "Ommar", "Phone", "Phyo", "Phyu", "Pwint", "San", "Sanda", "Sandar", "Su", "Thanda", "Thandar", "Thawda", "Thawdar", "Thawka", "Theingi", "Thet", "Thi", "Thida", "Thidar", "Thin", "Thinza", "Thinzar", "Thiri", "Thu", "Thuzar", "Tun", "U", "Win", "Yadana", "Yadanar", "Yati", "Yee", "Yi", "Yin", "Yu", "Yuzana", "Zar", "Zaw", "Zin"};
    static constexpr std::string_view nm1[] = {"Ag", "Arkar", "Aung", "Bo", "Hein", "Htet", "Htun", "Htut", "Kan", "Kaung", "Khaing", "Khant", "Khine", "Ko", "Kyaw", "Lin", "Linn", "Maung", "Mg", "Min", "Myat", "Myint", "Myo", "Naing", "Nyan", "Phone", "Phyo", "Phyoe", "Pyae", "Pyay", "Sein", "Soe", "Thant", "Thawda", "Thet", "Thiha", "Thu", "Thura", "Thurein", "Thuta", "Tun", "U", "Wai", "Win", "Wunna", "Yarzar", "Yaza", "Ye", "Zarni", "Zaw", "Zeya", "Zeyar", "Zin"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 4) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm2);
    names = nm2[rnd] + " " + nm2[rnd2];
    } else if (i < 7) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm2);
    names = nm2[rnd] + " " + nm2[rnd2] + " " + nm2[rnd3];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm2);
    rnd4 = rng() % std::size(nm2);
    names = nm2[rnd] + " " + nm2[rnd2] + " " + nm2[rnd3] + " " + nm2[rnd4];
    }
    } else {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm1[rnd2];
    } else if (i < 7) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm1[rnd2] + " " + nm1[rnd3];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm1);
    rnd4 = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm1[rnd2] + " " + nm1[rnd3] + " " + nm1[rnd4];
    }
    }
    return names;
    }
}
