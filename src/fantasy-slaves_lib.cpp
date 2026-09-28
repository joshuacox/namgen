#include "fantasy-slaves_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_slaves_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Abnormality", "Ache", "Anguish", "Anomaly", "Ant", "Barbarian", "Bastard", "Peon", "Beast", "Beetle", "Birdbrain", "Blemish", "Blight", "Blockhead", "Boar", "Bonehead", "Boor", "Bottomfeeder", "Boy", "Brute", "Buffoon", "Bug", "Bum", "Corruption", "Crawler", "Creep", "Creeper", "Cretin", "Cricket", "Crud", "Crude", "Curse", "Defect", "Defiled", "Deformation", "Degenerate", "Demon", "Deviant", "Dirt", "Disease", "Disgrace", "Dog", "Dread", "Dreck", "Dunce", "Dust", "Dweller", "Fiend", "Filth", "Flaw", "Flea", "Fly", "Fool", "Freak", "Frog", "Garbage", "Girl", "Gloom", "Gnat", "Gnome", "Goblin", "Greasy", "Gremlin", "Grime", "Grotesque", "Grub", "Gunk", "Halfwit", "Hopeless", "Horror", "Hybrid", "Ill-bred", "Imp", "Impure", "Ingrate", "Insect", "Irregularity", "Junk", "Kobold", "Larva", "Leech", "Lewd", "Louse", "Lowbred", "Lowlife", "Maggot", "Malformed", "Miscreant", "Misery", "Mistake", "Mite", "Mole", "Mongrel", "Monster", "Moth", "Mouse", "Muck", "Mud", "Mug", "Mule", "Mutt", "Nit", "Oaf", "Obscenity", "Ogre", "Parasite", "Pervert", "Pest", "Pig", "Plague", "Pollution", "Prawn", "Primitive", "Rabbit", "Rags", "Rascal", "Rat", "Roach", "Rodent", "Rubble", "Runt", "Savage", "Scamp", "Scrub", "Scum", "Shrimp", "Simple-mind", "Simpleton", "Skunk", "Sleaze", "Slime", "Slop", "Slug", "Smear", "Smut", "Snail", "Snake", "Snot", "Sorrow", "Spider", "Squirmer", "Stain", "Stitch", "Syndrome", "Taint", "Termite", "Tick", "Toad", "Trash", "Troll", "Twerp", "Unchaste", "Uncivilized", "Unclean", "Uncouth", "Unformed", "Untaught", "Vermin", "Waste", "Weakness", "Weasel", "Weevil", "Whelp", "Woe", "Worm", "Wretch", "Wriggler"};
    static constexpr std::string_view nm2[] = {"Abomniable", "Ash", "Awful", "Bad", "Baseborn", "Black", "Bottom", "Broken", "Brown", "Cheap", "Dirt", "Dirty", "Disgusting", "Dismal", "Down", "Drab", "Dreck", "Dust", "Fecal", "Feeble", "Fetid", "Filthy", "Flimsy", "Foul", "Fragile", "Frail", "Garbage", "Grease", "Grim", "Grime", "Grisly", "Gross", "Grotesque", "Hideous", "Hollow", "Horrid", "Ill", "Inept", "Inferior", "Infirm", "Insignificant", "Junk", "Lesser", "Limp", "Little", "Lousy", "Low", "Lowborn", "Lowlife", "Lowly", "Meager", "Measly", "Mediocre", "Menial", "Messy", "Minor", "Miserable", "Monstrous", "Muck", "Mud", "Murky", "Nasty", "Noisome", "Paltry", "Pathetic", "Pesky", "Petty", "Pitiful", "Plague", "Puny", "Putrid", "Rancid", "Rank", "Raunchy", "Repulsive", "Revolting", "Rotten", "Sad", "Scant", "Scrap", "Senile", "Shame", "Shoddy", "Sick", "Slag", "Sleazy", "Slimey", "Slop", "Smut", "Soil", "Soot", "Sour", "Spoiled", "Stink", "Stinking", "Tainted", "Tiny", "Trash", "Trashy", "Trifling", "Trivial", "Ugly", "Useless", "Vile", "Waste", "Wicked", "Worthless", "Wracked", "Wretched"};
    static constexpr std::string_view nm3[] = {"Abnormality", "Ache", "Anomaly", "Ant", "Barbarian", "Bastard", "Beast", "Beetle", "Boar", "Boor", "Boy", "Brute", "Buffoon", "Bug", "Bum", "Corruption", "Crawler", "Creep", "Creeper", "Cretin", "Cricket", "Crud", "Crude", "Curse", "Demon", "Deviant", "Dog", "Dunce", "Dweller", "Fiend", "Flaw", "Flea", "Floom", "Fly", "Fool", "Freak", "Frog", "Girl", "Gnat", "Gnome", "Goblin", "Gremlin", "Halfwit", "Hybrid", "Imp", "Ingrate", "Insect", "Kobold", "Larva", "Leech", "Lewd", "Louse", "Lowlife", "Maggot", "Mistake", "Mite", "Mole", "Mongrel", "Monster", "Moth", "Mouse", "Mug", "Mule", "Mutt", "Nit", "Oaf", "Ogre", "Parasite", "Peon", "Pervert", "Pest", "Pig", "Prawn", "Rat", "Roach", "Rodent", "Runt", "Savage", "Scamp", "Scrub", "Scum", "Shrimp", "Skunk", "Sleaze", "Slime", "Slug", "Smut", "Snail", "Snake", "Snot", "Spider", "Termite", "Tick", "Toad", "Trash", "Troll", "Twerp", "Vermin", "Weasel", "Weevil", "Whelp", "Worm"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    } else {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    names = nm2[rnd] + " " + nm3[rnd2];
    }
    return names;
    }
}
