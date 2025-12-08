#include "destiny-exos_lib.h"

#include <vector>
#include <string>

std::string generate_destiny_exos_name(std::mt19937& rng) {
    // List of possible name prefixes – copied from the original JS generator
    static std::vector<std::string> nm1 = {
        "Ashes","Ace","Anarchy","Anger","Apparition","Arch","Ash","Aura","Band","Bandit","Banshee","Barbarian","Barrage","Beam","Beast","Behemoth","Bite","Blade","Blaze","Blight","Blow","Bolt","Bones","Boulder","Brass","Brute","Burn","Cast","Cavalier","Chain","Champ","Chance","Chaos","Cherub","Cloud","Crack","Critter","Crook","Crow","Crux","Daemon","Death","Demon","Design","Desire","Devil","Diablo","Dice","Dragon","Dragonfly","Dusk","Dust","Echo","Eclipse","Edge","End","Enigma","Fang","Fiend","Fire","Flame","Flint","Flow","Flux","Force","Fragment","Freak","Frost","Fury","Fuse","Gargoyle","Gem","Ghost","Giant","Glutton","Goliath","Grim","Guide","Hazard","Heart","Hellion","Hook","Horn","Horror","Hound","Ice","Imp","Impulse","Iron","Jackal","Jester","Jewel","Judge","Knife","Knight","Leviathan","Limbo","Mammoth","Maniac","Martyr","Mask","Merit","Mime","Mind","Mist","Monster","Motion","Myth","Naught","Needle","Night","Ogre","Omen","Oracle","Owl","Paladin","Paradox","Paragon","Pest","Phantom","Phoenix","Plasma","Purpose","Pyre","Quake","Quiver","Rain","Rat","Ray","Revenant","Riddle","Rime","Robin","Rogue","Ruse","Saint","Salt","Sand","Savage","Scale","Scout","Secret","Sentinel","Seraph","Serenity","Serpent","Shade","Shadow","Shift","Shock","Shockwave","Silver","Siren","Sky","Slip","Slither","Sliver","Sly","Snake","Snow","Song","Soul","Specter","Sphinx","Spider","Splinter","Sprite","Steel","Stitch","Storm","Summer","Surprise","Switch","Taint","Temper","Templar","Thunder","Titan","Toad","Touch","Trick","Twist","Umbra","Vamp","Varmint","Veil","Vermin","Villain","Viper","Virtue","Vision","Void","Vortex","Wave","Weasel","Whip","Whisper","Winter","Wraith","Zealot"
    };

    // Randomly pick an element from the list
    if (nm1.empty()) {
        // If the list has been exhausted, return an empty string
        return "";
    }

    size_t rnd = static_cast<size_t>(rng() % nm1.size());
    std::string prefix = nm1[rnd];

    // Remove the used prefix so it won't be reused in this run
    nm1.erase(nm1.begin() + rnd);

    // Generate a number between 0 and 49 (inclusive)
    int rnd2 = static_cast<int>(rng() % 50);

    // Assemble the final name
    return prefix + "-" + std::to_string(rnd2);
}
