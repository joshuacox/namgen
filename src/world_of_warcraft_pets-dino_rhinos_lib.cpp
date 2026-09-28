#include "world_of_warcraft_pets-dino_rhinos_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_world_of_warcraft_pets_dino_rhinos_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"HueJass", "Albinosaur", "Angar", "Auron", "Bahir", "Barakah", "Barney", "Bellow", "Bigfoot", "Bitsy", "Bloodmaw", "Bloodymuzzle", "Bobosaur", "Brand", "BrokeFang", "Brokenfang", "Buck", "Byte", "Chaos", "ChompStomp", "Chomper", "Chopper", "Claws", "Clawz", "CleverGirl", "Crush", "Crusher", "Cuddles", "Daffy", "Dan", "Daniel", "Danny", "Darla", "Dash", "Deathmaw", "Delilah", "Dentist", "Denver", "Destructor", "Devastator", "Deviant", "Deviltry", "DharanSar", "Didi", "Digger", "Dingo", "Dino", "Don", "Donald", "Donna", "Donny", "Doodles", "Drake", "Dreadtooth", "Dred", "Ebony", "Emerald", "Extinct", "Extinction", "Fang", "Fayng", "Fearme", "Fearsome", "Fetch", "Fido", "Flaay", "Fluffy", "Fossil", "FossilFuel", "Fuel", "Fuzzmuffin", "Gambit", "Geico", "Godzilla", "Gorosaurus", "Greenback", "Gregarious", "Grimlock", "Grimnir", "Gullet", "Halmar", "Hammerit", "Hannibal", "Helm", "Hjollder", "IBite", "IDK", "Ibite", "IronHide", "Ivory", "JPEscapee", "Jaws", "Jill", "Junior", "Jurassic", "JurasskickMark", "KingTerror", "Krush", "Kuvar", "Kyouryuu", "Largepaw", "Lilarms", "Limey", "Littlearms", "Littlefoot", "Lizard", "Lizzy", "Lockjaw", "Lohtur", "Lollipop", "LongTooth", "Longfang", "Lumos", "Maugrim", "Midnight", "Mittens", "MrBiteyPantz", "Nightmare", "NomNomNom", "NotATRex", "OMNOMNOM", "Obsidian", "Oscar", "Overbite", "Paleosaurus", "Peanut", "Phearsome", "Philosoraptor", "Pickles", "Protego", "Pumpkin", "Punkin", "Quickfang", "Rahon", "Rampardos", "RapTrap", "RaptorXXL", "Raw", "Ray", "Razor", "Razzak", "Relish", "Render", "Rex", "Rexette", "Rexxy", "Rhedosaurus", "Riff", "Rikko", "Rip", "Ripmaw", "Ripper", "Roflsaurs", "Ryp", "Sammy", "Sargon", "Sauros", "Scales", "Scaly", "Scyther", "SexyRexy", "Shaaux", "Sharpclaw", "Sharptooth", "Shifty", "SirSlicey", "SliceNDice", "Sly", "Smiley", "Smileysaur", "Smurf", "Snapp", "Sneaker", "Speilberg", "Spike", "Spyke", "Squint", "Stevosaur", "Stomp", "StompStomp", "Stompy", "Sunshine", "Swiftscale", "TWrecks", "Ter", "Thanatos", "Thunderlizard", "TinyTim", "Titan", "Titanosaurus", "Tooth", "Toothy", "Trex", "Twinkletoes", "Tyr", "Tyra", "Tyran", "Tyranitar", "Tyranno", "Tyrannos", "Tyro", "Ulfang", "Velocity", "Viridian", "Wafflemeow", "Wily", "Xero", "Xerxes", "YellowTooth", "Zahra", "Zahrax", "Zarin", "Zinrokh", "Zulzin", "myBFF"};
    static constexpr std::string_view nm2[] = {"HueJass", "Bakari", "BigBoss", "Boomer", "BowlingBall", "Brutus", "Buba", "Bubbles", "Buhrahrum", "Bulldozer", "Bummer", "Charge", "Charger", "Dakari", "Dodge", "Dunia", "Duniya", "Eddie", "Faustosilva", "Fizzawick", "Gelom", "GnomeSlinger		", "Gnomepunter", "Grace", "Hasani", "Hummer", "Humperdink", "Jimbi", "Johari", "Juba", "Jump", "Kibibbi", "Kirushou", "Kito", "Kneel", "LittleOne", "Lokthar", "Maret", "MrLittle", "Muchi", "Njord", "Noosie", "Nyika", "Rae", "Rafael", "Rafiki", "Ralph", "Ralphie", "Randey", "Rando", "Random", "Randy", "Ray", "Raymond", "Raz", "Redd", "Respighi", "Retro", "Rex", "Rhina", "Rhinester", "Rhino911", "Rhinoldinho", "Rhinoplasty", "Riddick", "RiffRaff", "Rigby", "Riley", "Ringo", "Rizzo", "Roadblock", "Robbie", "Robby", "Rodeo", "Rodger", "Rodney", "Rolo", "Roma", "Romeo", "Romey", "Ron", "Ronan", "Rondo", "Ronin", "Rorschach", "Rory", "Rosco", "Roscoe", "Rosita", "Ross", "Roswell", "Roudy", "Rua", "Ruban", "Rubit", "Ruby", "Ruckus", "Rudolph", "Rudy", "Ruffie", "Ruffus", "Ruffy", "Rufus", "Ruger", "Rugrat", "Runt", "Rupert", "Rupurt", "Rusalka", "Russell", "Rusti", "Rusty", "Ryan", "Ryder", "Ryelle", "Rythum", "Sama", "Samahe", "Spearmeant", "Stomper", "Stompy", "Thunderstomp", "TickBird", "Tiirkar", "Tiny", "TinyTim", "Tubby", "Ugmak", "Vlad", "Wagtail", "Wooly", "Zuvan"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    }
    return names;
    }
}
