#include "warhammer-tomb_kings_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_tomb_kings_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "ch", "f", "h", "k", "kh", "m", "n", "r", "s", "t", "th"};
    static constexpr std::string_view nm2[] = {"a", "e", "o", "a", "e", "o", "a", "e", "o", "a", "e", "o", "i", "i"};
    static constexpr std::string_view nm3[] = {"b", "ch", "f", "h", "k", "kh", "l", "m", "mh", "n", "p", "ph", "r", "s", "sh", "t", "th", "y", "b", "bd", "ch", "ct", "f", "h", "k", "kh", "kht", "kt", "l", "m", "mh", "mkh", "mt", "n", "nkh", "ns", "p", "ph", "phk", "phr", "pht", "pr", "pth", "r", "rkh", "rs", "rt", "s", "sf", "sh", "shk", "skh", "sph", "ss", "st", "t", "th", "tm", "tr", "ttr", "y"};
    static constexpr std::string_view nm4[] = {"", "", "f", "h", "kh", "m", "n", "nb", "p", "ph", "r", "rs", "s"};
    static constexpr std::string_view nm5[] = {"b", "h", "k", "kh", "m", "n", "p", "ph", "r", "s", "sh", "t", "th"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "o", "o"};
    static constexpr std::string_view nm7[] = {"b", "d", "f", "fr", "g", "gt", "gh", "h", "k", "kh", "kt", "l", "m", "mkh", "mph", "n", "nkh", "nph", "nth", "nkhn", "ns", "nt", "p", "ph", "phr", "pth", "r", "rh", "rm", "rt", "ry", "s", "st", "t", "tr", "th", "thy", "y", "z", "zh"};
    static constexpr std::string_view nm8[] = {"Academic", "Acclaimed", "Adept", "Ambitious", "Ancient", "Architect", "Artist", "Austere", "Black", "Blessed", "Bright", "Brilliant", "Celebrated", "Chaste", "Composed", "Conjurer", "Content", "Crimson", "Cunning", "Devoted", "Diligent", "Earnest", "Educated", "Elegant", "Enchanted", "Enlightened", "Euphoric", "Exalted", "Flawless", "Generous", "Gifted", "Giving", "Glorious", "Graceful", "Grand", "Great", "Hallowed", "Herald", "Hierpohant", "Holy", "Honorable", "Honored", "Humble", "Idealist", "Illustrious", "Immortal", "Imperishable", "Incredible", "Infinite", "Knowing", "Learned", "Light", "Loyal", "Magnificent", "Majestic", "Marvelous", "Oracle", "Paragon", "Patient", "Powerful", "Prestigious", "Prime", "Prophet", "Soothsayer", "Sophisticated", "Terrific", "Treasure", "Treasured", "Valiant", "Visionary", "Watcher", "White", "Zealous"};

    std::string nameL; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm8);
    nameL = " the " + nm8[rnd];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 5) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nameL;
    } else {
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6] + nameL;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (rnd < 4) {
    while (rnd5 < 2) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    if (i < 5) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + nameL;
    } else {
    rnd6 = rng() % std::size(nm3);
    rnd7 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + nameL;
    }
    }
    return names;
    }
}
