#include "fantasy-ghosts_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_ghosts_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names1[] = {"Aberran", "Aeran", "Aiden", "Airian", "Airon", "Alaife", "Alastor", "Cloud", "Malone", "Alife", "Angelo", "Anim", "Auran", "Aurath", "Aurin", "Azur", "Bane", "Benedict", "Blase", "Brand", "Brath", "Cense", "Chase", "Curce", "Daemn", "Daimon", "Damian", "Damon", "Delic", "Desir", "Dwell", "Dyno", "Eaden", "Empyr", "Ether", "Ethern", "Flaym", "Ghose", "Guarian", "Guyde", "Hall", "Hallo", "Harro", "Haunn", "Hawnt", "Hyde", "Illus", "Immor", "Karm", "Kurse", "Lloyl", "Menos", "Mort", "Nate", "Paradai", "Pawer", "Perm", "Perry", "Phanto", "Phyntom", "Rath", "Rayth", "Remane", "Saul", "Sentine", "Shephard", "Spiro", "Torme", "Torne", "Vitali", "Ward", "Warde", "Wayke", "Wayte", "Waythe", "Will"};
    static constexpr std::string_view names2[] = {"Abby", "Aeriel", "Airiel", "Airielle", "Angelica", "Angy", "Anima", "Anshee", "Lucy", "Apaera", "Appara", "Arriel", "Aura", "Aurabelle", "Auralee", "Aure", "Auriana", "Auriel", "Aurora", "Azure", "Mallory", "Evilyn", "Belesse", "Blesse", "Branda", "Breeth", "Carisma", "Celeste", "Chasey", "Chasity", "Daeva", "Damia", "Damya", "Delica", "Delice", "Desira", "Dove", "Dwelle", "Ela", "Elega", "Elisum", "Elle", "Ellis", "Elvira", "Elvire", "Elyse", "Enya", "Erie", "Essence", "Essy", "Eterna", "Exme", "Fade", "Faith", "Fantasia", "Fayde", "Faythe", "Felicity", "Gloria", "Guardia", "Guida", "Haeven", "Illuse", "Infi", "Karisma", "Karma", "Karmay", "Kendel", "Loya", "Mindy", "Mira", "Misrey", "Missy", "Misty", "Mortia", "Mortitia", "Mystique", "Natura", "Ondine", "Ora", "Perma", "Queste", "Sentina", "Shay", "Spiri", "Sprit", "Temperance", "Temperence", "Temprence", "Topia", "Umber", "Umbra", "Vex", "Vexa", "Via", "Vissi", "Zoe"};
    static constexpr std::string_view names3[] = {"Aberra", "Aener", "Aerel", "Aeren", "Aerin", "Angis", "Kindel", "Aethe", "Aerie", "Aide", "Aidel", "Aidis", "Airin", "Angel", "Apara", "Arie", "Aurel", "Auris", "Blaise", "Blisse", "Blythe", "Bone", "Bones", "Bowne", "Celes", "Charis", "Daevi", "Defi", "Desi", "Deth", "Devi", "Devo", "Duff", "Eaven", "Ener", "Ethae", "Ethe", "Fidel", "Flo", "Flowe", "Folo", "Fyre", "Gallo", "Gose", "Guardi", "Guya", "Harth", "Ligh", "Lite", "Lloial", "Lyte", "Mewse", "Muse", "Myst", "Perris", "Phan", "Psyche", "Remane", "Shado", "Shayde", "Shaydo", "Shayepe", "Sparkle", "Spec", "Spooks", "Spryte", "Spryth", "Stray", "Strey", "Tormey", "Undine", "Undy", "Vysio", "Yuto", "Zion"};
    static constexpr std::string_view names4[] = {"Abandoned", "Accepted", "Amusing", "Angry", "Beach", "Bitter", "Black", "Blind", "Bloodied", "Bloody", "Blue", "Brown", "Burning", "Cheerful", "Cherished", "Crying", "Crypt", "Dark", "Defending", "Drifting", "Escaped", "Fat", "Fiery", "Following", "Forest", "Friendly", "Full Moon", "Garden", "Graveyard", "Gray", "Grim", "Headless", "Helpful", "Hostile", "Howling", "Ignored", "Invited", "Ivory", "Jolly", "Killer", "Laughing", "Light", "Lost", "Malevolent", "Mansion", "Marching", "Midnight", "Mocking", "Mourning", "Mute", "Noisy", "Oblivious", "Playful", "Pleasant", "Praying", "Preaching", "Protecting", "Raging", "Reading", "Red", "Roaming", "Running", "Sad", "Saluting", "Screaming", "Searching", "Seeking", "Shrieking", "Shy", "Silent", "Silver", "Sinister", "Sitting", "Sleeping", "Slender", "Snoring", "Sobbing", "Spying", "Stalking", "Standing", "Staring", "Sweet", "Talking", "Thin", "Tombstone", "Twin", "Unaware", "Unwanted", "Vengeful", "Vicious", "Violent", "Wandering", "Watching", "Waving", "Weeping", "Welcome", "Whispering", "White", "Wicked", "Wild"};
    static constexpr std::string_view names5[] = {"Baron", "Boy", "Father", "Gentleman", "Grandfather", "Groom", "Groomsman", "Incubus", "Mailman", "Man", "Angel", "Apparition", "Appearance", "Artist", "Barber", "Barkeeper", "Blacksmith", "Butcher", "Camper", "Child", "Cleaner", "Clown", "Cook", "Curator", "Dancer", "Defender", "Demon", "Devil", "Doctor", "Eyes", "Force", "Gatekeeper", "Ghost", "Guard", "Guardian", "Guest", "Hunter", "Jester", "Judge", "Keeper", "Kid", "Knight", "Lover", "Maniac", "Mime", "Monk", "Musician", "Necromancer", "Nightmare", "Nightwatch", "Nurse", "Orphan", "Patrol", "Phantom", "Prisoner", "Protector", "Reaper", "Revenant", "Rider", "Screamer", "Sentinel", "Sentry", "Servant", "Shade", "Shadow", "Shepherd", "Shopkeeper", "Soldier", "Soul", "Specter", "Squire", "Stalker", "Student", "Teacher", "Teenager", "Templar", "Toddler", "Torturer", "Vision", "Visitor", "Warden", "Widow", "Wizard", "Woman", "Wraith", "Writer"};
    static constexpr std::string_view names6[] = {"Banshee", "Baroness", "Bride", "Bridesmaid", "Girl", "Grandmother", "Lady", "Maiden", "Mother", "Succubus", "Temptress", "Trickster", "Witch", "Angel", "Apparition", "Appearance", "Artist", "Barber", "Barkeeper", "Blacksmith", "Butcher", "Camper", "Child", "Cleaner", "Clown", "Cook", "Curator", "Dancer", "Defender", "Demon", "Devil", "Doctor", "Eyes", "Force", "Gatekeeper", "Ghost", "Guard", "Guardian", "Guest", "Hunter", "Jester", "Judge", "Keeper", "Kid", "Knight", "Lover", "Maniac", "Mime", "Monk", "Musician", "Necromancer", "Nightmare", "Nightwatch", "Nurse", "Orphan", "Patrol", "Phantom", "Prisoner", "Protector", "Reaper", "Revenant", "Rider", "Screamer", "Sentinel", "Sentry", "Servant", "Shade", "Shadow", "Shepherd", "Shopkeeper", "Soldier", "Soul", "Specter", "Squire", "Stalker", "Student", "Teacher", "Teenager", "Templar", "Toddler", "Torturer", "Vision", "Visitor", "Warden", "Widow", "Wizard", "Woman", "Wraith", "Writer"};
    static constexpr std::string_view names7[] = {"Angel", "Apparition", "Appearance", "Artist", "Barber", "Barkeeper", "Blacksmith", "Butcher", "Camper", "Child", "Cleaner", "Clown", "Cook", "Curator", "Dancer", "Defender", "Demon", "Devil", "Doctor", "Eyes", "Force", "Gatekeeper", "Ghost", "Guard", "Guardian", "Guest", "Hunter", "Jester", "Judge", "Keeper", "Kid", "Knight", "Lover", "Maniac", "Mime", "Monk", "Musician", "Necromancer", "Nightmare", "Nightwatch", "Nurse", "Orphan", "Patrol", "Phantom", "Prisoner", "Protector", "Reaper", "Revenant", "Rider", "Screamer", "Sentinel", "Sentry", "Servant", "Shade", "Shadow", "Shepherd", "Shopkeeper", "Soldier", "Soul", "Specter", "Squire", "Stalker", "Student", "Teacher", "Teenager", "Templar", "Toddler", "Torturer", "Vision", "Visitor", "Warden", "Widow", "Wizard", "Woman", "Wraith", "Writer"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    if (type == 1) {
    rnd = rng() % std::size(names2);
    names = names2[rnd];
    } else if (type == 2) {
    rnd = rng() % std::size(names3);
    names = names3[rnd];
    } else {
    rnd = rng() % std::size(names1);
    names = names1[rnd];
    }
    } else {
    if (type == 1) {
    rnd = rng() % std::size(names4);
    rnd2 = rng() % std::size(names6);
    names = "The " + names4[rnd] + " " + names6[rnd2];
    } else if (type == 2) {
    rnd = rng() % std::size(names4);
    rnd2 = rng() % std::size(names7);
    names = "The " + names4[rnd] + " " + names7[rnd2];
    } else {
    rnd = rng() % std::size(names4);
    rnd2 = rng() % std::size(names5);
    names = "The " + names4[rnd] + " " + names5[rnd2];
    }
    }
    return names;
    }
}
