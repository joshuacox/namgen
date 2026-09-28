#include "fantasy-ents_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_ents_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Algal", "Bare", "Barren", "Dense", "Dwarf", "Hard", "Pygmy", "Scorched", "Scorch", "Scrub", "Tender", "Wild", "Nettle", "Shadow", "Splint", "Splinter", "Mad", "Gentle", "Spring", "Summer", "Winter", "Autumn", "Fall", "Snow", "Iron", "Wise", "Clever", "Cunning", "Sharp", "Bland", "Taint", "Tainted", "Mellow", "Weeping", "Tender", "Kind", "Soft", "Quiet", "Silent", "Mild", "Bitter", "Cruel", "Mean", "Vine", "Black", "Gray", "Charred", "Burn", "Burned"};
    static constexpr std::string_view nm2[] = {"acorn", "alder", "ash", "beech", "birch", "cedar", "cherry", "cypress", "elm", "fir", "juniper", "larch", "locust", "maple", "oak", "peach", "pine", "poplar", "spruce", "walnut", "willow", "yew", "tree", "hazel", "twig", "trunk", "root", "nut", "trunk", "herb", "limb", "beard", "leaf", "husk", "spur", "sprout", "wood", "stump", "thorn", "talon", "blossom", "leg", "legs", "limbs", "tendril"};
    static constexpr std::string_view nm3[] = {"Acorn", "Alder", "Ash", "Beech", "Birch", "Cedar", "Cherry", "Cypress", "Elm", "Fir", "Juniper", "Larch", "Locust", "Maple", "Oak", "Oaken", "Peach", "Pine", "Poplar", "Spruce", "Walnut", "Willow", "Yew", "Tree", "Hazel", "Thistle"};
    static constexpr std::string_view nm4[] = {"bark", "beard", "blade", "bramble", "nettle", "spray", "bush", "shell", "husk", "claw", "fang", "talon", "paw", "crown", "fern", "copse", "scrub", "flesh", "fury", "grove", "covert", "stand", "herb", "leaf", "growl", "howl", "trunk", "root", "bellow", "roar", "snarl", "shade", "shadow", "flower", "blossom", "limb", "lock", "spine", "pad", "needle", "stalk", "splint", "splinter", "spur", "twig", "stub", "stump", "shrub", "skin", "thorn", "tip", "tooth", "twig", "wood", "burn", "scar", "eye", "brow", "sprout", "tendril"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = nm3[rnd] + nm4[rnd2];
    }
    return names;
    }
}
