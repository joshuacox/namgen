#include "descriptions-gems_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_gems_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Agate", "Agate Geode", "Alexandrite", "Almandine Garnet", "Amazonite", "Amethyst", "Ametrine", "Ammolite", "Andalusite", "Apatite", "Aquamarine", "Aventurine", "Axinite", "Beryl", "Bloodstone", "Boulder Opal", "Calcite", "Carnelian", "Cassiterite", "Charoite", "Chrome Diopside", "Citrine", "Clinohumite", "Diamond", "Emerald", "Enstatite", "Fire Agate", "Fire Opal", "Fluorite", "Hematite", "Hiddenite", "Howlite", "Iolite", "Jasper", "Kyanite", "Lapis Lazuli", "Malachite", "Mali Garnet", "Melanite", "Moldavite", "Moonstone", "Morganite", "Moss Opal", "Nuummite", "Obsidian", "Onyx", "Opal", "Peridot", "Prehnite", "Pyrope Garnet", "Quartz", "Rainbow Moonstone", "Rainbow Pyrite", "Rhodochrosite", "Rhodolite Garnet", "Rhodonite", "Rose Quartz", "Ruby", "Sapphire", "Scapolite", "Seraphinite", "Serpentine", "Snowflake Obsidian", "Sodalite", "Sphalerite", "Sphene", "Spinel", "Star Diopside", "Star Garnet", "Star Ruby", "Star Sapphire", "Sugilite", "Sunstone", "Tanzanite", "Tiger's Eye", "Topaz", "Tourmaline", "Turquoise", "Verdite", "Zircon"};
    static constexpr std::string_view nm2[] = {"an antique cushion", "a baguette", "a brilliant", "a briolette", "a cabochon", "a cushion", "an emerald", "a heart", "a kite", "a marquise", "an octagon", "an oval", "a pear", "a princess", "a radiant", "a round", "a royal", "a square", "a triangle", "a trillion"};
    static constexpr std::string_view nm3[] = {"bean", "blueberry", "fig", "fist", "grape", "hazelnut", "kumquat", "lemon", "lentil", "lime", "pea", "peanut", "strawberry", "walnut"};
    static constexpr std::string_view nm4[] = {"average", "decent", "excellent", "fair", "fairly decent", "fairly poor", "fairly rough", "fine", "great", "inferior", "magnificent", "mediocre", "near flawless", "outstanding", "poor", "premium", "presentable", "pristine", "reasonable", "rough", "rugged", "superb", "supreme", "terrific"};
    static constexpr std::string_view nm5[] = {"barely sought after", "decently popular", "fairly popular", "in average demand", "in decent demand", "in fairly high demand", "in low demand", "in very high demand", "not that popular", "not very sought after", "often ignored", "often in high demand", "often quite popular", "quite unpopular", "rarely sought after"};
    static constexpr std::string_view nm6[] = {"an incredibly common", "a very common", "a fairly common", "a fairly uncommon", "a quite uncommon", "a very uncommon", "a fairly rare", "a quite rare", "a very rare", "an incredibly rare"};
    static constexpr std::string_view nm7[] = {"amplifying", "augmentative", "controlling", "cooling", "defensive", "desirable", "diminishing", "disabling", "electric", "elemental", "emotional", "enhancing", "enlarging", "fiery", "focusing", "fortunate", "healing", "icy", "invigorating", "life", "light", "mending", "potent", "protective", "rejuvenating", "seductive", "shady", "strengthening", "tenacious", "warming"};
    static constexpr std::string_view nm8[] = {"defensive weapon", "offensive weapon", "defensive spell focus", "offensive spell focus", "beneficial spell focus", "offensive weapon enhancement", "defensive weapon enhancement", "defensive spell focus enhancement", "offensive spell focus enhancement", "beneficial spell focus enhancement", "defensive artifact", "offensive artifact", "defensive artifact enhancement", "offensive artifact enhancement", "defensive jewelry", "offensive jewelry", "defensive jewelry enhancement", "offensive jewelry enhancement"};

    std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string result; size_t rnd1 = 0; size_t rnd10 = 0; size_t rnd11 = 0; size_t rnd12 = 0; size_t rnd13 = 0; size_t rnd14 = 0; size_t rnd15 = 0; size_t rnd16 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    rnd1 = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm1);
    rnd10 = rng() % std::size(nm2);
    rnd11 = rng() % std::size(nm3);
    rnd12 = rng() % std::size(nm4);
    rnd13 = rng() % std::size(nm5);
    rnd14 = rng() % std::size(nm6);
    rnd15 = rng() % std::size(nm7);
    rnd16 = rng() % std::size(nm8);
    name = "This " + nm1[rnd1] + " with " + nm2[rnd2] + " cut and the size of a " + nm3[rnd3] + " is in " + nm4[rnd4] + " condition. These gems are " + nm5[rnd5] + ", but they're " + nm6[rnd6] + " gemstone species.";
    name2 = "It's said these gems contain " + nm7[rnd7] + " properties which make for a great " + nm8[rnd8] + ".";
    name3 = "-----------------------------------------------------------------------------------------------------------------------------";
    name4 = "This " + nm1[rnd9] + " with " + nm2[rnd10] + " cut and the size of a " + nm3[rnd11] + " is in " + nm4[rnd12] + " condition. These gems are " + nm5[rnd13] + ", but they're " + nm6[rnd14] + " gemstone species.";
    name5 = "It's said these gems contain " + nm7[rnd15] + " properties which make for a great " + nm8[rnd16] + ".";
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    result += "\n";
    result += "\n";
    result += name4;
    result += "\n";
    result += name5;
    return result;
}
