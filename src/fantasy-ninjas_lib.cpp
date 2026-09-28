#include "fantasy-ninjas_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_ninjas_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Agile", "Black", "Blue", "Bronze", "Cloaked", "Crimson", "Crouching", "Dark", "Deadly", "Elegant", "Falling", "Fast", "Floating", "Flying", "Ghost", "Golden", "Graceful", "Hidden", "Hollow", "Invisible", "Iron", "Jade", "Light", "Masked", "Muffled", "Muzzled", "Mysterious", "Mystic", "Nimble", "Phantom", "Quick", "Quiet", "Rapid", "Red", "Ruby", "Sanguine", "Sapphire", "Scarlet", "Serpent", "Shrouded", "Silent", "Silver", "Slender", "Smiling", "Smooth", "Snake", "Soothing", "Steel", "Still", "Swift", "Thin", "Tranquil", "Unheard", "Unknown", "Unmoving", "Unseen", "Veiled", "White", "Winged", "Wise"};
    static constexpr std::string_view names2[] = {"Angel", "Assassin", "Avalanche", "Basilisk", "Beast", "Blaze", "Breath", "Cat", "Child", "Cipher", "Crane", "Dagger", "Death", "Demise", "Demon", "Devil", "Dragon", "Drake", "Dream", "Echo", "Enigma", "Eye", "Eyes", "Figure", "Fire", "Flame", "Ghost", "Grin", "Hawk", "Hunter", "Illusion", "Image", "Jackal", "Knife", "Laugh", "Lion", "Lotus", "Mamba", "Mark", "Mask", "Master", "Mime", "Mimic", "Mind", "Mirage", "Moon", "Mute", "Oracle", "Paradox", "Phantom", "Phoenix", "Player", "Rain", "Ranger", "Raven", "Reflection", "Rock", "Rover", "Saber", "Samaritan", "Scar", "Scorpion", "Scythe", "Secret", "Serpent", "Shade", "Shadow", "Silence", "Smile", "Smirk", "Smoke", "Snake", "Snow", "Soldier", "Spider", "Stalker", "Star", "Striker", "Sword", "Thunder", "Tiger", "Viper", "Vision", "Wanderer", "Warden", "Watcher", "Whisper", "Wind", "Wolf", "Wrath"};
    static constexpr std::string_view names3[] = {"Black", "Blood", "Bullet", "Crimson", "Dark", "Dead", "Death", "Dream", "Ghost", "Golden", "Hollow", "Iron", "Jade", "Kill", "Lethal", "Light", "Lightning", "Phantom", "Quick", "Rabid", "Rapid", "Red", "Scarlet", "Silent", "Silver", "Snow", "Steel", "Still", "Swift", "Thunder"};
    static constexpr std::string_view names4[] = {"bang", "bash", "beat", "blade", "claw", "crash", "eye", "eyes", "fall", "flake", "flash", "flow", "kill", "lock", "mark", "moon", "saw", "scar", "shade", "shadow", "shiv", "shot", "sign", "slinger", "stain", "stike", "streak", "strikes", "stroke", "tooth"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = "The " + names1[rnd] + " " + names2[rnd2];
    } else {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    names = names3[rnd] + names4[rnd2];
    }
    return names;
    }
}
