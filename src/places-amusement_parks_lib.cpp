#include "places-amusement_parks_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_amusement_parks_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Angel", "Animal", "Aqua", "Arcane", "Astral", "Astro", "Aura", "Beach", "Beast", "Carny", "Cartoon", "Child", "Clown", "Comic", "Creep", "Critter", "Crypt", "Demon", "Dino", "Doll", "Dragon", "Dread", "Dream", "Elf", "Ember", "Epic", "Eterni", "Ever", "Expo", "Fable", "Fairy", "Feral", "Festi", "Film", "Fire", "Forest", "Freak", "Fright", "Fun", "Game", "Ghost", "Giant", "Groovy", "Happy", "Hell", "Hero", "Horror", "Ice", "Jungle", "Kids", "Luna", "Lunar", "Magic", "Marina", "Maze", "Mega", "Mini", "Miracle", "Mirror", "Monster", "Movie", "Mutant", "Never", "Night", "Ocean", "Paradox", "Phantom", "Play", "Quest", "Rain", "Rainbow", "River", "Robot", "Saga", "Sand", "Scream", "Secret", "Shadow", "Shock", "Sky", "Snow", "Solar", "Space", "Speed", "Spirit", "Splash", "Star", "Stellar", "Storm", "Story", "Summer", "Sun", "Super", "Terra", "Terror", "Thrill", "Titan", "Toy", "Undead", "Vision", "Warp", "Water", "Winter", "Witch", "Wizard", "Wonder", "Zombie", "Zoo"};
    static constexpr std::string_view nm2[] = {"land", "world", "zone", "park", "town", "fair", "realm", "ville", "land", "park", "ventures"};
    static constexpr std::string_view nm3[] = {"Adventure", "Amazing", "Amazon", "Angel", "Animal", "Animation", "Anime", "Aqua", "Arcane", "Astral", "Beach", "Beast", "Bird", "Candy", "Cartoon", "Castle", "Child", "Chocolate", "Clown", "Comic", "Creep", "Critter", "Crypt", "Crystal", "Demon", "Dino", "Dinosaur", "Discovery", "Doll", "Dragon", "Dread", "Dream", "Elf", "Ember", "Enchanted", "Epic", "Fable", "Fairy", "Fairy Tale", "Family", "Fantasy", "Feral", "Festival", "Film", "Fire", "Forest", "Freak", "Fright", "Fun", "Galaxy", "Game", "Ghost", "Giant", "Happy", "Hell", "Hero", "Horror", "Ice", "Jungle", "Kids", "King's", "Knight", "Legend", "Luna", "Lunar", "Magic", "Magic Forest", "Marina", "Marine", "Maze", "Mega", "Midnight", "Mini", "Miniature", "Miracle", "Mirror", "Monster", "Movie", "Mutant", "Mystery", "Mystic", "Mythic", "Nature", "Night", "Nightmare", "Oasis", "Ocean", "Panorama", "Paradox", "Parody", "Phantom", "Phoenix", "Pirate", "Play", "Power", "Quest", "Rain", "Rainbow", "River", "Robot", "Saga", "Sand", "Santa's", "Science", "Scream", "Secret", "Serpent", "Shadow", "Shock", "Sky", "Snow", "Solar", "Space", "Speed", "Spirit", "Splash", "Star", "Storebook", "Storm", "Story", "Summer", "Sun", "Super", "Surprise", "Terror", "Thrill", "Titan", "Toy", "Trampoline", "Transilvanian", "Undead", "Underwater", "Universe", "Vampire", "Vision", "Warp", "Water", "Werewolf", "Wild Water", "Wild West", "Wildlife", "Winter", "Witch", "Wizard", "Wonder", "Zombie", "Zoo"};
    static constexpr std::string_view nm4[] = {"World", "Land", "Zone", "Park", "Town", "Village", "Realm", "Fair", "Island", "Fun Park", "Fun World", "Kingdom", "Dome", "Paradise", "Experience"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    names = nm3[rnd] + " " + nm4[rnd2];
    }
    return names;
    }
}
