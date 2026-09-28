#include "places-lands_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_lands_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Haunted", "Naked", "Angry", "Arctic", "Arid", "Bare", "Barren", "Black", "Bleak", "Boiling", "Bone-Dry", "Burned", "Burning", "Calm", "Calmest", "Charmed", "Cunning", "Cursed", "Dangerous", "Dark", "Darkest", "Dead", "Decayed", "Decaying", "Dehydrated", "Depraved", "Deserted", "Desolate", "Desolated", "Distant", "Dread", "Dreaded", "Dreadful", "Dreary", "Dry", "Eastern", "Empty", "Enchanted", "Ethereal", "Ever Reaching", "Everlasting", "Feared", "Fearsome", "Fiery", "Flat", "Forbidden", "Forbidding", "Frightening", "Frozen", "Grave", "Grim", "Hellish", "Homeless", "Hopeless", "Hot", "Hungry", "Infernal", "Infinite", "Isolated", "Killing", "Laughing", "Lifeless", "Light", "Lightest", "Lonely", "Malevolent", "Malicious", "Mighty", "Mirrored", "Misty", "Moaning", "Monotonous", "Motionless", "Mysterious", "Narrow", "Neverending", "Northern", "Open", "Painful", "Parched", "Perfumed", "Quiet", "Raging", "Red", "Restless", "Rocky", "Sad", "Sandy", "Sanguine", "Savage", "Scorching", "Scorched", "Shadowed", "Silent", "Sly", "Soundless", "Southern", "Sterile", "Thundering", "Treacherous", "Twisting", "Uncanny", "Uninteresting", "Uninviting", "Unknown", "Unresting", "Unwelcoming", "Vast", "Violent", "Voiceless", "Waterless", "Western", "Whispering", "White", "Windy", "Withered", "Yelling", "Yellow"};
    static constexpr std::string_view nm2[] = {"Badlands", "Barrens", "Borderlands", "Desert", "Expanse", "Fields", "Grasslands", "Hinterland", "Prairie", "Savanna", "Steppes", "Tundra", "Wasteland", "Wastes", "Wilderness", "Wilds", "Emptyness", "Frontier", "Flatlands"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    if (i < 5) {
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    } else {
    names = nm1[rnd] + " " + nm2[rnd2];
    }
    return names;
    }
}
