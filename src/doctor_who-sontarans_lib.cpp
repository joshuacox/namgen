#include "doctor_who-sontarans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_doctor_who_sontarans_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"B", "Br", "D", "Dr", "Gr", "J", "K", "Kr", "L", "N", "M", "S", "Sk", "Sn", "St", "T", "Tr", "V", "Vr"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y", "aa", "ee"};
    static constexpr std::string_view nm3[] = {"g", "gg", "gt", "gh", "k", "kt", "kk", "l", "ll", "nt", "nx", "r", "rl", "rr", "rk", "rn", "rg", "sk"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm5[] = {"d", "g", "gr", "j", "k", "kr", "l", "mt", "ng", "nt", "r", "rt", "rn", "st", "ts", "th", "v"};
    static constexpr std::string_view nm6[] = {"", "", "g", "k", "l", "m", "n", "r", "x"};
    static constexpr std::string_view nm7[] = {"Adept", "Admired", "Aggressive", "Aggressor", "Agile", "Ambitious", "Assassin", "Avenger", "Beast", "Behemoth", "Bloodbringer", "Bloodhunter", "Bloodied", "Bold", "Brave", "Brilliant", "Brutal", "Butcher", "Champion", "Clever", "Corruptor", "Crafty", "Crooked", "Cunning", "Danger", "Dapper", "Defiant", "Diligent", "Doombringer", "Eliminator", "Enforcer", "Enormous", "Exalted", "Executioner", "Expert", "Fearless", "Glorious", "Grand", "Great", "Hunter", "Illustrious", "Immortal", "Incredible", "Infamous", "Inventor", "Killer", "Knowing", "Loyal", "Magnificent", "Marvelous", "Master", "Masterful", "Menace", "Merciless", "Mighty", "Paragon", "Powerful", "Prestigious", "Proud", "Razor", "Reckless", "Reliable", "Ruthless", "Slayer", "Sneaky", "Stark", "Stout", "Strong", "Terrific", "Terror", "Turbulent", "Undefeated", "Valiant", "Vengeful", "Victorious", "Vigilant", "Warlord", "Warmonger", "Warrior", "Wild", "Wonderful", "Wrathful", "Wretched", "Zealous"};
    static constexpr std::string_view nm8[] = {"B", "D", "G", "J", "K", "L", "N", "M", "S", "T", "V"};
    static constexpr std::string_view nm9[] = {"d", "g", "gg", "gr", "k", "kr", "kk", "l", "ll", "ng", "n", "nn", "r", "rl", "rr", "rk", "rn", "rg", "st", "sk", "th", "v"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd7 = rng() % std::size(nm8);
    rnd8 = rng() % std::size(nm4);
    rnd9 = rng() % std::size(nm9);
    rnd10 = rng() % std::size(nm4);
    rnd11 = rng() % std::size(nm6);
    if (i < 5) {
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm7);
    names = nm8[rnd7] + nm4[rnd8] + nm9[rnd9] + nm4[rnd10] + nm6[rnd11] + "  " + nm1[rnd] + nm2[rnd2] + nm3[rnd3] + " the " + nm7[rnd4];
    } else if (i < 8) {
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = nm8[rnd7] + nm4[rnd8] + nm9[rnd9] + nm4[rnd10] + nm6[rnd11] + "  " + nm1[rnd] + nm4[rnd2] + nm5[rnd3] + nm4[rnd4] + nm6[rnd5] + " the " + nm7[rnd6];
    } else {
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm7);
    names = nm8[rnd7] + nm4[rnd8] + nm9[rnd9] + nm4[rnd10] + nm6[rnd11] + "  " + nm1[rnd] + nm4[rnd2] + nm5[rnd3] + nm4[rnd4] + nm3[rnd5] + " the " + nm7[rnd6];
    }
    return names;
    }
}
