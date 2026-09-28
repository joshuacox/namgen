#include "warhammer_40k-orks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_40k_orks_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"b", "br", "ch", "d", "dh", "dr", "g", "gh", "gr", "hr", "k", "kh", "kr", "m", "n", "r", "sk", "sm", "sn", "t", "tr", "v", "vr", "w", "wr", "z", "zh", "zr", "", "", "", "", ""};
    static constexpr std::string_view names2[] = {"a", "i", "o", "u", "a", "u"};
    static constexpr std::string_view names3[] = {"b", "d", "dbr", "dr", "g", "gb", "gd", "gg", "gh", "gn", "gt", "gz", "hrbl", "k", "kg", "kk", "kt", "lgr", "nz", "r", "rb", "rg", "rgn", "rgr", "rk", "rkr", "rl", "rz", "sk", "skr", "t", "tgr", "tzm", "tzn", "zdr", "zg", "zgr"};
    static constexpr std::string_view names4[] = {"a", "o", "u"};
    static constexpr std::string_view names5[] = {"d", "g", "gar", "gas", "gg", "gus", "k", "kh", "kk", "m", "nak", "r", "rd", "rk", "x", "z", "zak", "zz", };
    static constexpr std::string_view names6[] = {"Barb", "Battle", "Big", "Blood", "Blud", "Bone", "Brain", "Crook", "Crown", "Dark", "Dome", "Doom", "Dream", "Ead", "Ed", "Face", "Fire", "Fist", "Gloom", "Glum", "God", "Gore", "Grave", "Grim", "Gut", "Gutz", "Hed", "Hell", "Ice", "Iron", "Jaw", "Jowl", "Kill", "Klaw", "Krook", "Mad", "Mighty", "Mug", "Muzzle", "Rabid", "Rage", "Rekk", "Rock", "Scalp", "Skar", "Skull", "Slay", "Strong", "War", "Wild"};
    static constexpr std::string_view names7[] = {"acka", "ackah", "basha", "bashah", "boila", "boilah", "braka", "brakah", "brakka", "brakkah", "breaka", "breakah", "busta", "choppa", "choppah", "cleava", "cleavah", "clompa", "clompah", "cooka", "cookah", "cracka", "crackah", "crasha", "crashah", "crumpa", "crumpah", "crusha", "crushah", "cutta", "cuttah", "dagga", "daggah", "fang", "fist", "gasha", "gashah", "gutta", "guttah", "hacka", "hackah", "kleava", "kleavah", "krak", "kraka", "krakah", "krumpa", "krumpah", "krusha", "krushah", "rippa", "rippah", "shredda", "shreddah", "skar", "skorcha", "skorchah", "slasha", "slashah", "smasha", "smashah", "snagga", "snaggah", "snappa", "snappah", "spitta", "spittah", "splitta", "splittah", "stampa", "stampah", "stompa", "stompah", "trasha", "trashah", "wakka", "wakkah", "whacka", "whackah"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    rnd4 = rng() % std::size(names4);
    rnd5 = rng() % std::size(names5);
    names = names1[rnd] + names2[rnd2] + names3[rnd3] + names4[rnd4] + names5[rnd5];
    } else {
    rnd = rng() % std::size(names6);
    rnd2 = rng() % std::size(names7);
    names = names6[rnd] + names7[rnd2];
    }
    return names;
    }
}
