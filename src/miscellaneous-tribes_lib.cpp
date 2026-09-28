#include "miscellaneous-tribes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_tribes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Ancient", "Angry", "Arcane", "Arctic", "Berserk", "Big", "Bitter", "Black", "Blessed", "Blind", "Blue", "Brave", "Bright", "Broken", "Bronze", "Brown", "Burned", "Clay", "Cold", "Crazy", "Crimson", "Cruel", "Dark", "Dead", "Diamond", "Dirty", "Ebon", "Eternal", "Evil", "Falling", "False", "First", "Free", "Frozen", "Gentle", "Giant", "Gifted", "Golden", "Grave", "Gray", "Green", "Grim", "Half", "Hard", "Hell", "Hidden", "High", "Impure", "Infamous", "Invincible", "Iron", "Large", "Last", "Light", "Lost", "Loyal", "Magic", "Master", "Mean", "Middle", "Miracle", "Misty", "Molten", "Murky", "Mute", "Night", "Nightmare", "Original", "Pale", "Poison", "Prime", "Pure", "Quiet", "Rabid", "Rapid", "Reckless", "Red", "Risen", "Rising", "Rude", "Salty", "Sapphire", "Savage", "Shadow", "Silent", "Silver", "Small", "Smelly", "Standing", "Steel", "Stone", "Strong", "Swift", "True", "Twilight", "Twin", "Undead", "Vicious", "White", "Yellow"};
    static constexpr std::string_view names2[] = {"Ancestor", "Angel", "Ant", "Arrow", "Ash", "Aura", "Axe", "Bat", "Bear", "Bison", "Bone", "Bones", "Boulder", "Bow", "Brothers", "Cave", "Claw", "Cloak", "Coyote", "Crow", "Crown", "Dagger", "Demon", "Dragon", "Eagle", "Ear", "Earth", "Ember", "Eye", "Feet", "Finger", "Fire", "Fish", "Fist", "Foot", "Forest", "Fox", "Fury", "Ghost", "Giant", "God", "Hammer", "Hand", "Hawk", "Heaven", "Hill", "Hounds", "Hunt", "Island", "Lake", "Lightning", "Lion", "Mage", "Mammoth", "Moon", "Mountain", "Mouth", "Oracle", "Owl", "Paw", "Phantom", "Phoenix", "Rage", "Raven", "Ribbon", "River", "Rock", "Sand", "Scar", "Scorpion", "Sea", "Seer", "Shark", "Shield", "Sisters", "Skeleton", "Skull", "Snake", "Snow", "Spear", "Spider", "Spirit", "Stag", "Stalker", "Star", "Storm", "Sun", "Swamp", "Sword", "Thunder", "Titan", "Tooth", "Tower", "Watch", "Water", "Whisper", "Wing", "Witch", "Wolf", "Woods"};
    static constexpr std::string_view names3[] = {"Tribe", "Kin", "Clan", "Warriors", "Children", "Caste", "Horde", "Tribe"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    rnd3 = rng() % std::size(names3);
    names = "The " + names1[rnd] + " " + names2[rnd2] + " " + names3[rnd3];
    return names;
    }
}
