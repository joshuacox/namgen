#include "pop_culture-how_to_train_your_dragons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_how_to_train_your_dragons_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Adder", "Alder", "Arrow", "Bewilder", "Blaze", "Blubber", "Bone", "Bull", "Burro", "Change", "Cloud", "Crooked", "Dark", "Dawn", "Day", "Dead", "Death", "Desert", "Doom", "Dragon", "Dread", "Dream", "Dull", "Dusk", "Elder", "Eternal", "Fire", "Flame", "Flapper", "Flutter", "Forever", "Frost", "Fury", "Ghost", "Gloom", "Glow", "Gore", "Great", "Grim", "Ground", "Hallow", "Hell", "Hollow", "Hook", "Hypno", "Inferno", "Light", "Little", "Mild", "Mud", "Night", "Rage", "Razor", "Rocket", "Rumble", "Sand", "Sea", "Shadow", "Shiver", "Shock", "Silver", "Snow", "Song", "Speed", "Storm", "Swift", "Sword", "Talon", "Terror", "Thunder", "Torch", "Tranquil", "Tumble", "Venom", "Whirl", "Wild"};
    static constexpr std::string_view nm2[] = {"back", "beast", "belly", "breath", "claw", "cutter", "drum", "eye", "eyes", "fang", "flight", "glider", "grunt", "horn", "hunter", "jaw", "jumper", "nose", "paw", "ripper", "roar", "smasher", "song", "striker", "tail", "tongue", "tooth", "twister", "whip", "wing"};
    static constexpr std::string_view nm3[] = {"Awe", "Bait", "Bead", "Bellow", "Bigby", "Blare", "Blue", "Bluster", "Bolt", "Bones", "Boom", "Boulder", "Burst", "Buster", "Chase", "Chinook", "Cobble", "Cower", "Crackle", "Crest", "Crimson", "Crisscross", "Crumb", "Curly", "Dart", "Dash", "Dire", "Ditch", "Dodge", "Dozer", "Dread", "Dribble", "Drifter", "Drool", "Droplet", "Dusty", "Echo", "Eclipse", "Enigma", "Fawn", "Fay", "Feather", "Feint", "Flare", "Flash", "Flinch", "Flo", "Fluff", "Flurry", "Gale", "Ghast", "Ghost", "Glider", "Glimmer", "Glint", "Glum", "Gnaw", "Gobbles", "Goof", "Gravel", "Grim", "Grime", "Grouch", "Grumpy", "Grunt", "Gust", "Haze", "Helix", "Hogger", "Honey", "Hue", "Itchy", "Jitters", "Juke", "Knot", "Looper", "Magma", "Manes", "Muds", "Munchy", "Muzzle", "Needle", "Nibble", "Night", "Nimbles", "Nip", "Nozzle", "Paradox", "Pebble", "Phanom", "Pickle", "Pinch", "Pitch", "Plume", "Plummet", "Prickle", "Puds", "Pugs", "Quill", "Rainbow", "Riddle", "Rumble", "Saliva", "Sally", "Sapphire", "Scruffy", "Scuddle", "Shade", "Shadow", "Shay", "Shuffle", "Sidestep", "Skip", "Sky", "Skyler", "Slobber", "Slush", "Smudge", "Snare", "Sneak", "Snookum", "Snout", "Snowflake", "Soot", "Sparkle", "Spice", "Squall", "Squeak", "Sting", "Storm", "Subs", "Surge", "Surly", "Swifty", "Tails", "Thorn", "Thunder", "Tickles", "Tingle", "Trace", "Tremble", "Tumble", "Twilight", "Twinkle", "Twist", "Twister", "Typhoon", "Umbra", "Veil", "Whallop", "Whammy", "Wiggle", "Wriggle", "Zap", "Zigzag", "Zip"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    names = nm3[rnd];
    }
    return names;
    }
}
