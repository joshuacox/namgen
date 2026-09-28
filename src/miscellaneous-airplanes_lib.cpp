#include "miscellaneous-airplanes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_airplanes_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Agile", "Ancient", "Angry", "Arid", "Able", "Bad", "Big", "Bitter", "Black", "Blaring", "Blind", "Blue", "Bold", "Bronze", "Brown", "Buzzing", "Calm", "Classic", "Cold", "Cool", "Crazy", "Cruel", "Dapper", "Dark", "Defiant", "Diligent", "Double", "Eager", "Evil", "False", "Fast", "Fatal", "Feline", "Forsaken", "Free", "Frozen", "Gentle", "Gold", "Golden", "Grand", "Grave", "Gray", "Greedy", "Grim", "Happy", "Harsh", "High", "Hollow", "Hot", "Huge", "Humming", "Hungry", "Idle", "Infamous", "Infinite", "Ironclad", "Jagged", "Keen", "Last", "Lazy", "Light", "Little", "Livid", "Lone", "Long", "Loud", "Low", "Loyal", "Mad", "Major", "Mellow", "Nervous", "Numb", "Old", "Pale", "Parallel", "Prime", "Proud", "Quick", "Quiet", "Ragged", "Rapid", "Rare", "Reckless", "Red", "Regal", "Rough", "Round", "Royal", "Rude", "Sharp", "Shy", "Silent", "Silver", "Slim", "Small", "Smooth", "Subtle", "Sweet", "Swift", "Tiny", "Tough", "Vain", "Vengeful", "Vicious", "Vivid", "Warped", "White", "Wicked", "Wild", "Wise"};
    static constexpr std::string_view nm2[] = {"Albatross", "Freak", "Banshee", "Voodoo", "Arrow", "Beast", "Bee", "Beetle", "Bird", "Blimp", "Bolt", "Bomb", "Bomber", "Boomerang", "Boy", "Bullet", "Buzzard", "Centurion", "Chick", "Cobra", "Condor", "Crane", "Crow", "Daddy", "Dart", "Darter", "Diver", "Dragon", "Dragonfly", "Ducchess", "Duck", "Duke", "Eagle", "Falcon", "Fly", "Ghost", "Goose", "Gryphon", "Gull", "Harrier", "Hawk", "Hornet", "Ibis", "Jet", "King", "Legionnaire", "Lightning", "Mamba", "Mommy", "Mosquito", "Moth", "Overcast", "Owl", "Pelican", "Phantom", "Queen", "Raven", "Robin", "Rocket", "Serpent", "Shooter", "Sparrow", "Spirit", "Stork", "Thunder", "Torpedo", "Viper", "Vulture", "Widow", "Woodpecker"};
    static constexpr std::string_view nm3[] = {"Aerial", "Agile", "Air", "Avian", "Azure", "Banshee", "Brass", "Bright", "Chaos", "Cloud", "Dark", "Demon", "Devil", "Dragon", "Dream", "Drift", "Ebon", "Feral", "Flight", "Flying", "Free", "Frost", "Ghost", "Grey", "Heaven", "Hell", "Iron", "Little", "Mad", "Monster", "Night", "Nimble", "Phantom", "Prime", "Quick", "Rapid", "Rogue", "Shadow", "Sky", "Star", "Swift", "Thunder", "Twin", "Wild", "Wrath"};
    static constexpr std::string_view nm4[] = {"beast", "blast", "blaze", "blitz", "bolt", "bomb", "brute", "bullet", "burst", "charge", "charm", "comet", "core", "cry", "eater", "edge", "fire", "flare", "flight", "flow", "flux", "force", "freak", "fury", "glider", "hail", "heat", "lance", "light", "master", "nova", "pulse", "punch", "pyre", "rage", "raid", "rise", "roar", "rush", "scream", "shade", "spark", "storm", "strike", "thunder", "tooth", "urge", "ward", "wing", "wrath"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = nm3[rnd] + nm4[rnd2];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    }
    return names;
    }
}
