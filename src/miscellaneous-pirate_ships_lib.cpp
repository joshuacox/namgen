#include "miscellaneous-pirate_ships_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_pirate_ships_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "", "", "", "Adventure", "Anger of the", "Angry", "Barbaric", "Bearded", "Black", "Blasted", "Crimson", "Sanguine", "Blind", "Bloodthirsty", "Bloody", "Broken", "Buccaneers", "Burning", "Cacophonous", "Captains", "Corrupted", "Cour", "Cruel", "Cry", "Cry of the", "Curse of the", "Cursed", "Damnation of the", "Damned", "Davy Jones", "Death of", "Deceit of", "Deceitful", "Devils", "Dirty", "Discourteous", "Silent", "Disgrace of the", "Disgraced", "Disgraceful", "Dishonorable", "Disrespectful", "Dragons", "Drunken", "Elusive", "Evil", "Fall of", "Fearful", "Fearful Grail of", "Festering", "Filthy", "Flying", "Fortune", "Foul Serpent of", "Gold", "Golden", "Good", "Greed of the", "Greedy", "Grief of the", "Hades", "Happy", "Hateful", "Hell-born", "Hellish", "Homicidal", "Horrid", "Howl of the", "Howling", "Howling ", "Impolite", "Killers", "Liberty", "Little", "Loyal", "Lust of the", "Mad", "Grand", "Madness of the", "Mangy", "Mayflower", "Most", "Murderers", "Murderous", "Mermaid's", "Neptune's", "New", "Last", "Night", "Nights", "Oceans", "Pillaging", "Pirates", "Plundering", "Poison", "Poisoned", "Poisonous", "Poseidon's", "Pride of the", "Privateers", "Rancid", "Red", "Revenge", "Rising", "Rude", "Sadness of the", "Savage", "Scurvy", "Sea", "Seas", "Shadows of the", "Snap", "Speedy", "Sudden", "Uncultured", "Vicious", "Victory", "Vile", "White"};
    static constexpr std::string_view nm2[] = {"Anger", "Abandoned", "Scorn", "Tainted", "Atlantis", "Captain", "Caribbean", "Corruption", "Corsair", "Coward", "Curse", "Cutlass", "Dagger", "Damnation", "Damned", "Death", "Deciet", "Delight", "Delivery", "Demon", "Disgrace", "Doom", "Doubloon", "Dragon", "Eel", "Executioner", "Executioners", "Fall", "Fear", "Fortune", "Galley", "Ghost", "Gold", "Grail", "Hades", "Hangman", "Hind", "Horror", "Howl", "Insanity", "James", "Jewel", "Killer", "Killers", "King", "Knave", "Lightning", "Lust", "Manta", "Minnow", "Tide", "Murderer", "Murderers", "Night", "North", "Pearl", "Pillager", "Pirate", "Plague", "Plunder", "Plunderer", "Plunderers", "Princess", "Privateer", "Raider", "Rambler", "Ranger", "Return", "Revenge", "Saber", "Scream", "Sea", "Seas", "Marauders", "Swashbucklers", "Rovers", "Sea Rovers", "Buccaneers", "Rose", "Rift", "Deceit", "Secret", "Serpent", "Servant", "Servants", "Seven Seas", "Shark", "Slave", "Squid", "Storm", "Strumpet", "Sun", "Terror", "Tortuga", "Treasure", "Trinity", "Valant", "Wolf"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    return names;
    }
}
