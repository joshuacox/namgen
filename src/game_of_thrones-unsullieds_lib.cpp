#include "game_of_thrones-unsullieds_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_game_of_thrones_unsullieds_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Ash", "Awful", "Bad", "Black", "Blue", "Bottom", "Broken", "Brown", "Cheap", "Dirt", "Dirty", "Down", "Drab", "Dreck", "Dust", "Feeble", "Filthy", "Foul", "Fragile", "Frail", "Garbage", "Grease", "Grey", "Grim", "Grime", "Grisly", "Gross", "Grotesque", "Hideous", "Horrid", "Ill", "Inferior", "Infirm", "Junk", "Lesser", "Little", "Lousy", "Low", "Meager", "Measly", "Mediocre", "Menial", "Messy", "Minor", "Monstrous", "Muck", "Mud", "Murky", "Nasty", "Paltry", "Peon", "Pesky", "Poor", "Puny", "Raunchy", "Red", "Repulsive", "Revolting", "Sad", "Scant", "Scrap", "Shame", "Shoddy", "Sick", "Slag", "Slimey", "Slop", "Smut", "Soil", "Soot", "Stink", "Tiny", "Trash", "Trashy", "Trivial", "Ugly", "Vile", "Waste", "Worthless", "Wracked", "Wretched"};
    static constexpr std::string_view names2[] = {"Ant", "Beetle", "Bug", "Crawler", "Creep", "Creeper", "Cricket", "Curse", "Dog", "Flea", "Fly", "Frog", "Grub", "Insect", "Larva", "Leech", "Maggot", "Mite", "Mole", "Mongrel", "Moth", "Mouse", "Mule", "Mutt", "Nit", "Parasite", "Pest", "Pig", "Rabbit", "Rat", "Roach", "Rodent", "Scrub", "Shrimp", "Snail", "Spider", "Squirmer", "Termite", "Tick", "Toad", "Vermin", "Weasel", "Weevil", "Whelp", "Worm", "Wriggler", "Runt", "Slug", "Oaf", "Prawn", "Louse", "Skunk"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + " " + names2[rnd2];
    return names;
    }
}
