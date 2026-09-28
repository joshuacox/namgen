#include "miscellaneous-squads_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_squads_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Alpha", "Angel", "Annihilation", "Apache", "Arachnid", "Ash", "Bane", "Recon", "Assault", "Banshee", "Barrage", "Beast", "Behemoth", "Black Skull", "Blast", "Blitz", "Bravo", "Burning", "Carnage", "Cobra", "Coyote", "Crisis", "Cyclone", "Daemon", "Danger", "Demon", "Disaster", "Dragon", "Electric", "Elimination", "Enigma", "Ethereal", "Extinction", "Feral", "Fiery", "Fire", "Firebolt", "Flux", "Frozen", "Ghost", "Grindstone", "Guardian", "Havoc", "Hazard", "Honor", "Hurricane", "Ice", "Jackal", "Jester", "Leopard", "Lightning", "Lion", "Mammoth", "Marvel", "Miracle", "Mirage", "Monster", "Mutant", "Nemesis", "Nightmare", "Omega", "Oracle", "Padlock", "Panther", "Phantom", "Phoenix", "Plague", "Prodigy", "Rage", "Raid", "Rattle", "Ravage", "Red Demon", "Riot", "Rogue", "Rubble", "Rumble", "Scourge", "Serpent", "Shadow", "Shatter", "Silent", "Silver", "Skirmish", "Spider", "Spirit", "Stampede", "Storm", "Surge", "Thunder", "Tiger", "Titan", "Turtle", "Viper", "Void", "Whisper", "White Skull", "White Wolf", "Wild", "Wipe Out", "Wolf", "Wreckage"};
    static constexpr std::string_view names2[] = {"Freaks", "Alphas", "Angels", "Silver Angels", "Hellhounds", "Thunderbirds", "Vikings", "Arachnids", "Ashes", "Banshees", "Beasts", "Behemoths", "Black Skulls", "Cobras", "Coyotes", "Cyclones", "Daemons", "Demons", "Dragons", "Enigmas", "Ethereals", "Ferals", "Firebolts", "Ghosts", "Guardians", "Hurricanes", "Jackals", "Jesters", "Leopards", "Lightning Bolts", "Lions", "Mammoths", "Marvels", "Miracles", "Monsters", "Mutants", "Nightmares", "Omegas", "Oracles", "Padlocks", "Panthers", "Black Panthers", "Silver Banshees", "Phantoms", "Phoenixes", "Prodigies", "Red Demons", "Rogues", "Serpents", "Shadows", "Spiders", "Spirits", "Stormwalkers", "Rolling Thunders", "Tigers", "Titans", "Turtles", "Vipers", "Whispers", "White Skulls", "White Wolves", "Wolves", "Barbarians", "Wildlings", "Black Masks", "All Blacks", "Fiends", "War Turtles", "Mongrels", "Spooks", "Silence", "Scepters", "Strikers", "Lone Wolves", "Black Angels", "Black Vipers", "Black Mambas", "Silver Wolves", "White Tigers", "Black Lions", "Silver Lions", "Black Bulls", "Invisible", "Disguised", "Mysteries", "Coverts", "Goliaths", "Black Cats", "Daggers", "Blades", "Eagles", "Falcons", "Hornets", "Red Devils", "Saints", "Stripes", "Hammers", "Wasps", "Red Dragons", "Black Dragons", "Braves", "Golden Tigers", "Knights", "Street Dogs", "Sharks", "Scorpions", "Flames", "Mambas", "Shields", "Jaguars", "Nightowls", "Clockworks", "Valkyries"};
    static constexpr std::string_view names3[] = {"Advanced", "Classified", "Covert", "Crisis", "Disaster", "Emergency", "Extreme", "Incident", "Pressure", "Situational", "Special", "Specialized", "Standby", "Stategic", "Tactical", "Trauma"};
    static constexpr std::string_view names4[] = {"Airborne", "Assault", "Assemble", "Combat", "Command", "Control", "Evaluation", "Counter", "Engage", "Force", "Intelligence", "Liberation", "Maintenance", "Management", "Mobilization", "Operation", "Organization", "Pursuit", "Reinforce", "Reconnaisance", "Relief", "Rescue", "Response", "Retaliation", "Salvage", "Service", "Support", "Task", "Tracking", "Training", "Weapons"};
    static constexpr std::string_view names5[] = {"Crew", "Division", "Squad", "Squadron", "Team", "Unit"};
    static constexpr std::string_view names6[] = {"Crew", "Squad", "Squadron"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names6);
    names = "The " + names1[rnd] + " " + names6[rnd2];
    } else if (i < 6) {
    rnd = rng() % std::size(names2);
    names = "The " + names2[rnd];
    } else {
    rnd = rng() % std::size(names3);
    rnd2 = rng() % std::size(names4);
    rnd3 = rng() % std::size(names5);
    names = names3[rnd] + " " + names4[rnd2] + " " + names5[rnd3];
    }
    return names;
    }
}
