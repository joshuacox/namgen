#include "warhammer-high_elfs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_high_elfs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm[] = {"Bel-", "", "", "", ""};
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "c", "d", "f", "g", "gh", "h", "k", "m", "s", "sh", "t", "th", "v", "z"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "e", "e", "o", "o", "ye", "ae", "io", "ya", "aa"};
    static constexpr std::string_view nm3[] = {"b", "d", "l", "n", "r", "z", "b", "d", "l", "n", "r", "z", "b", "br", "cl", "cr", "d", "dr", "dh", "gr", "l", "lv", "lr", "ln", "ld", "n", "nd", "nn", "nt", "nth", "ntr", "r", "rh", "rv", "rt", "rth", "rd", "rh", "th", "thl", "z", "zr"};
    static constexpr std::string_view nm4[] = {"c", "l", "n", "r", "s"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "d", "f", "h", "kh", "l", "m", "n", "r", "s", "sh", "t", "th", "z"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "o", "o", "o", "ie", "ia", "ae", "ye", "ei"};
    static constexpr std::string_view nm7[] = {"c", "d", "f", "h", "k", "l", "m", "n", "r", "s", "t", "v", "z", "c", "d", "dh", "dd", "f", "ff", "fn", "gh", "h", "hh", "k", "kh", "l", "ll", "lr", "lv", "lm", "ln", "lf", "lg", "m", "mm", "mn", "n", "nn", "nr", "nv", "r", "rr", "rh", "rn", "rl", "s", "sh", "ss", "t", "tt", "th", "v", "z", "zz"};
    static constexpr std::string_view nm8[] = {"Academic", "Acclaimed", "Admired", "Agile", "Ancient", "Angel", "Angelic", "Artist", "Austere", "Beast", "Beautiful", "Blessed", "Bold", "Brave", "Brilliant", "Celebrated", "Clever", "Composed", "Conqueror", "Defender", "Defiant", "Devoted", "Diligent", "Discrete", "Earnest", "Educated", "Elegant", "Enchanted", "Enchanting", "Enforcer", "Enlightened", "Exalted", "Executioner", "Expert", "Explorer", "Fearless", "Flamboyant", "Flawless", "Generous", "Gentle", "Gifted", "Giving", "Glorious", "Graceful", "Grand", "Great", "Grim", "Guardian", "Honest", "Honorable", "Honored", "Humble", "Illustrious", "Immortal", "Impetuous", "Incredible", "Just", "Learned", "Light", "Loremaster", "Loyal", "Magnificent", "Majestic", "Marvelous", "Merciful", "Mighty", "Oracle", "Paragon", "Patient", "Peacemaker", "Pious", "Pleasant", "Poet", "Powerful", "Prime", "Proud", "Radiant", "Sage", "Seafarer", "Serene", "Silent", "Slayer", "Specialist", "Stark", "Stout", "Strict", "Swift", "Valiant", "Vengeful", "Warrior", "Wild", "Wise"};

    std::string nameL; std::string names; size_t rnd = 0; size_t rnd0 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm8);
    nameL = nm8[rnd];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6] + " the " + nameL;
    } else {
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6] + nm7[rnd7] + nm6[rnd8] + " the " + nameL;
    }
    } else {
    rnd0 = rng() % std::size(nm);
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 5) {
    names = nm[rnd0] + nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " the " + nameL;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm[rnd0] + nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd5] + nm4[rnd5] + " the " + nameL;
    }
    }
    return names;
    }
}
