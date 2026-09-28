#include "miscellaneous-chivalric_orders_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_chivalric_orders_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Ash", "Autumn", "Balance", "Battle", "Blood", "Brass", "Carnage", "Chains", "Change", "Courage", "Darkness", "Dawn", "Death", "Defiance", "Desire", "Devotion", "Direction", "Dusk", "Exaltation", "Existence", "Faith", "Fate", "Fear", "Fire", "Fortitude", "Fury", "Gallantry", "Giants", "Glory", "Gold", "Grit", "Guidance", "Harmony", "Heroism", "History", "Honor", "Ice", "Infinity", "Iron", "Judgment", "Justice", "Knowledge", "Leather", "Light", "Limbo", "Nightfall", "Oaths", "Peace", "Pestilence", "Prayer", "Riddles", "Serenity", "Servitude", "Shadows", "Silver", "Smoke and Ash", "Solitude", "Spirit", "Spirits", "Spring", "Summer", "Sunrise", "Tenacity", "Thunder", "Time", "Tranquility", "Valiance", "Valor", "Wealth", "Winter", "Worship"};
    static constexpr std::string_view nm2[] = {"Abyss", "Angel", "Arachnid", "Arch", "Archangel", "Ash", "Banner", "Bat", "Bear", "Beast", "Birth", "Blade", "Blessed", "Book", "Brave", "Bridge", "Broken Sword", "Brother", "Bull", "Carriage", "Chain", "Chalice", "Cherub", "Circle", "Cleansing Flame", "Coast", "Crescent", "Crest", "Crib", "Cross", "Crow", "Crown", "Desire", "Divine", "Divine Hand", "Dragon", "Dust", "Eagle", "Earth", "Edge", "Eye", "Faith", "Falcon", "Fang", "Fate", "Father", "Feather", "Fist", "Flame", "Flower", "Fruit", "Garden", "Gate", "Golden Thread", "Griffin", "Guardian", "Hammer", "Heart", "Hook", "Horn", "Hydra", "Ice", "Isle", "Knot", "Lake", "Land", "Leaf", "Light", "Lion", "Maple", "Mask", "Mire", "Moon", "Mother", "Mountain", "Nest", "Night", "Oak", "Ocean", "Oracle", "Orb", "Owl", "Parchment", "Phoenix", "Prophet", "Pyre", "Quill", "Quiver", "Rain", "Raven", "Rose", "Saint", "Salt", "Sand", "Sanguine", "Scarf", "Scythe", "Seraph", "Seraphim", "Serpent", "Shadow", "Shield", "Silver", "Sister", "Sky", "Snake", "Spirit", "Spur", "Star", "Stars", "Stone", "Sun", "Sword", "Temple", "Truth", "Voyage", "Water", "Wave"};
    static constexpr std::string_view nm3[] = {"Abyss", "Angel", "Ashen", "Autumn", "Banner", "Birth", "Blessed", "Blood", "Brass", "Brave", "Chain", "Chalice", "Cherub", "Circle", "Cleansing", "Crescent", "Crest", "Cross", "Crow", "Crown", "Darkness", "Dawn", "Death", "Divine", "Dragon", "Dusk", "Dust", "Eagle", "Exaltation", "Faith", "Falcon", "Fang", "Fate", "Father", "Fear", "Feather", "Fire", "Flame", "Flower", "Fury", "Garden", "Gate", "Glory", "Golden", "Griffin", "Guardian", "Guiding", "Honor", "Hydra", "Infinity", "Iron", "Judgment", "Justice", "Knowledge", "Lake", "Land", "Leather", "Light", "Limbo", "Lion", "Maple", "Masked", "Mire", "Moon", "Mother", "Mountain", "Nest", "Night", "Nightfall", "Oak", "Ocean", "Oracle", "Owl", "Parchment", "Phoenix", "Prayer", "Prophet", "Pyre", "Raven", "Rose", "Salt", "Sand", "Sanguine", "Scythe", "Seraph", "Seraphim", "Serenity", "Serpent", "Shadow", "Silver", "Sister", "Sky", "Solitude", "Spirit", "Spring", "Star", "Stone", "Summer", "Sun", "Sunrise", "Temple", "Thunder", "Timeless", "Tranquil", "Valiant", "Valor", "Voyage", "Water", "Winter", "Worship"};
    static constexpr std::string_view nm4[] = {"Knights", "Order", "Soldiers", "Squires", "Preservers", "Guardians", "Custodians", "Legion", "League", "Circle", "Lancers", "Shields", "Helmets", "Templars", "Knights", "Order", "Knights", "Order"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm4);
    if (i < 3) {
    rnd = rng() % std::size(nm2);
    names = "The " + nm4[rnd2] + " of the " + nm2[rnd];
    } else if (i < 7) {
    rnd = rng() % std::size(nm3);
    names = "The " + nm3[rnd] + " " + nm4[rnd2];
    } else {
    rnd = rng() % std::size(nm1);
    names = "The " + nm4[rnd2] + " of " + nm1[rnd];
    }
    return names;
    }
}
