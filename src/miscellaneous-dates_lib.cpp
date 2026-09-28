#include "miscellaneous-dates_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_dates_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    static constexpr std::string_view nm2[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    static constexpr std::string_view nm3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm5[] = {"", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z"};
    static constexpr std::string_view nm6[] = {"", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "b", "cus", "cius", "d", "g", "gh", "h", "hr", "hs", "ht", "hn", "hm", "hl", "k", "kius", "kix", "l", "ll", "lk", "ln", "lm", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rd", "s", "st", "ss", "sis", "sius", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "xis", "xius", "z", "zis"};
    static constexpr std::string_view nm8[] = {"Aardvark", "Albatross", "Alligator", "Alpaca", "Ant", "Antelope", "Ape", "Armadillo", "Baboon", "Badger", "Bandicoot", "Barracuda", "Basilisk", "Bat", "Bear", "Beaver", "Beetle", "Bighorn", "Bird", "Bison", "Boa", "Boar", "Bobcat", "Bongo", "Buffalo", "Bull", "Butterfly", "Caiman", "Camel", "Canary", "Cat", "Caterpillar", "Catfish", "Centipede", "Chameleon", "Cheetah", "Chicken", "Chimpanzee", "Cockroach", "Cow", "Coyote", "Crab", "Crane", "Crocodile", "Crow", "Deer", "Dingo", "Dog", "Dolphin", "Donkey", "Dragon", "Dragonfly", "Duck", "Eagle", "Elephant", "Elk", "Emu", "Falcon", "Ferret", "Fish", "Flamingo", "Fly", "Fox", "Frog", "Gazelle", "Gecko", "Goat", "Goose", "Gopher", "Gorilla", "Grasshopper", "Guinea Pig", "Hamster", "Hare", "Hedgehog", "Hippopotamus", "Hog", "Hornet", "Horse", "Hound", "Human", "Hummingbird", "Hyena", "Ibis", "Iguana", "Insect", "Jackal", "Jaguar", "Jellyfish", "Kangaroo", "Kingfisher", "Kiwi", "Koala", "Ladybird", "Lamb", "Lemming", "Lemur", "Leopard", "Lion", "Lizard", "Llama", "Lobster", "Lynx", "Macaw", "Magpie", "Manatee", "Mantis", "Meerkat", "Mole", "Mongoose", "Monkey", "Moose", "Moth", "Mouse", "Mule", "Nightingale", "Ocelot", "Octopus", "Orangutan", "Orca", "Ostrich", "Otter", "Owl", "Ox", "Oyster", "Panda", "Panther", "Parrot", "Peacock", "Pelican", "Penguin", "Pheasant", "Pig", "Piranha", "Platypus", "Porcupine", "Prawn", "Quail", "Rabbit", "Raccoon", "Rat", "Raven", "Rhinoceros", "Salamander", "Scorpion", "Seahorse", "Seal", "Shark", "Sheep", "Shrimp", "Skunk", "Sloth", "Snail", "Snake", "Sparrow", "Spider", "Squid", "Squirrel", "Starfish", "Stork", "Swan", "Termite", "Tiger", "Toad", "Tortoise", "Toucan", "Turkey", "Turtle", "Vulture", "Warthog", "Wasp", "Weasel", "Whale", "Wolf", "Wolverine", "Wombat", "Woodchuck", "Woodpecker", "Yak", "Zebra"};
    static constexpr std::string_view nm9[] = {"Accomplishments", "Agony", "Amusement", "Ancestors", "Ancients", "Anguish", "Animals", "Anticipation", "Ashes", "Beasts", "Beginnings", "Beliefs", "Birth", "Blessings", "Blight", "Bliss", "Blood", "Bloodlust", "Brotherhood", "Burdens", "Celebration", "Ceremonies", "Champions", "Chaos", "Charm", "Cheers", "Children", "Comfort", "Construction", "Corruption", "Cruelty", "Cunning", "Darkness", "Dawn", "Death", "Decay", "Deception", "Defeat", "Delight", "Delusions", "Desires", "Despair", "Destruction", "Dismay", "Dreams", "Drinking", "Earth", "Echoes", "Ecstasy", "Education", "Elation", "Ends", "Establishing", "Eternity", "Euphoria", "Executions", "Expansion", "Failure", "Families", "Fathers", "Feasts", "Festivals", "Fire", "Fools", "Fortune", "Frost", "Fury", "Giants", "Gifts", "Glee", "Glory", "Grace", "Growth", "Happiness", "Harvest", "Hate", "Hatred", "Heroes", "History", "Honor", "Hope", "Horrors", "Humor", "Illumination", "Immortality", "Insanity", "Joy", "Judgement", "Justice", "Laughter", "Legacies", "Life", "Light", "Loss", "Luxury", "Magic", "Memorials", "Memories", "Mercy", "Misery", "Moonlight", "Mothers", "Mountains", "Mourning", "Mystery", "Nightmares", "Nights", "Oblivion", "Origins", "Pain", "Paradise", "Parents", "Parties", "Peace", "Perdition", "Phantoms", "Plagues", "Pleasure", "Poverty", "Power", "Preparation", "Pride", "Prosperity", "Protection", "Putrefaction", "Rapture", "Reckoning", "Redemption", "Regrets", "Rejoice", "Remembrance", "Rest", "Riches", "Riddles", "Safety", "Sanctuary", "Secrecy", "Secrets", "Shadows", "Silence", "Slaughter", "Snow", "Sorrow", "Souls", "Stars", "Storms", "Struggles", "Suffering", "Summoning", "Sunlight", "Terror", "Thunder", "Titans", "Torment", "Training", "Trials", "Triumphs", "Truth", "Vengeance", "Victory", "Visions", "Voices", "Void", "War", "Water", "Wealth", "Whispers", "Widows", "Wind", "Winds", "Wizardry", "Woe", "Wonder", "Work", "Wraiths"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd3b = 0; size_t rnd3c = 0; size_t rnd4 = 0; size_t rnd4b = 0; size_t rnd4c = 0; size_t rnd5 = 0; size_t rnd5b = 0; size_t rnd5c = 0; size_t rnd6 = 0; size_t rnd6b = 0; size_t rnd6c = 0; size_t rnd7 = 0; size_t rnd7b = 0; size_t rnd7c = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm3);
    rnd9 = rng() % std::size(nm4);
    rnd10 = rng() % std::size(nm7);
    names = "Year: " + nm1[rnd] + nm2[rnd2] + ", Month: " + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + ", Day: " + nm3[rnd8] + nm4[rnd9] + nm7[rnd10];
    } else if (i < 5) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    names = "Month: " + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + ", Year of the " + nm8[rnd8];
    } else if (i < 8) {
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd3b = rng() % std::size(nm3);
    rnd4b = rng() % std::size(nm4);
    rnd5b = rng() % std::size(nm5);
    rnd6b = rng() % std::size(nm6);
    rnd7b = rng() % std::size(nm7);
    rnd3c = rng() % std::size(nm3);
    rnd4c = rng() % std::size(nm4);
    rnd5c = rng() % std::size(nm5);
    rnd6c = rng() % std::size(nm6);
    rnd7c = rng() % std::size(nm7);
    if (rnd5 > 6) {
    while (rnd6 == 0) {
    rnd6 = rng() % std::size(nm6);
    }
    }
    if (rnd5b > 6) {
    while (rnd6b == 0) {
    rnd6b = rng() % std::size(nm6);
    }
    }
    if (rnd5c > 6) {
    while (rnd6c == 0) {
    rnd6c = rng() % std::size(nm6);
    }
    }
    names = "Year: " + nm3[rnd3] + nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + ", Month: " + nm3[rnd3b] + nm4[rnd4b] + nm5[rnd5b] + nm6[rnd6b] + nm7[rnd7b] + ", Day: " + nm3[rnd3c] + nm4[rnd4c] + nm5[rnd5c] + nm6[rnd6c] + nm7[rnd7c];
    } else {
    rnd9 = rng() % std::size(nm9);
    rnd8 = rng() % std::size(nm8);
    names = "Month of " + nm9[rnd9] + ", Year of the " + nm8[rnd8];
    }
    return names;
    }
}
