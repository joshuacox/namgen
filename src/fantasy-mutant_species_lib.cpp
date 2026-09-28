#include "fantasy-mutant_species_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_mutant_species_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Aberrations", "Abnormalities", "Invincible", "Abominations", "Anomalies", "Blessed", "Chosen Ones", "Cleansed", "Enigmas", "Eternals", "Freaks", "Giants", "Gifted", "Horned Ones", "Impure", "Infected", "Lost Ones", "Lost Souls", "Miracles", "Monsters", "Newmans", "Paragons", "Phantoms", "Phoenixes", "Stalkers", "Tails", "Walkers", "Transparent", "Translucent", "Luminescent", "Green Skins", "Triclopses", "Cyclopses", "Beaks", "Fins", "Wings", "Fangs", "Claws", "Pelts", "Behemoths", "Fiends", "Savages", "Unnaturals", "Miscreants", "Miscreations", "Grotesque", "Misshapen", "Gills", "Hellions", "Horrors", "Pincers", "Eyeless", "Faceless", "Rock Skins", "Leather Skins", "Dwellers", "Otherworldly", "Forsaken", "Upgraded", "Beasts", "Creatures", "Missfits", "Howlers", "Scales", "Scaled Ones", "Tentacles", "Tentacled", "Silver Eyes", "Burdened", "Marked", "Horns", "Horned Ones", "Maniacs", "Bugs", "Creeps", "Sirens", "Finned Ones", "Fins", "Bended", "Four Legged", "Quadrupeds", "Decapeds", "Armored", "Blue Skins", "Black Skins", "Serpents", "Arachnids", "Arachnumans", "Serpumans", "Hogmen", "Demons", "Evolved", "Devolved", "Deviants", "Perverse", "Irregularities", "Synthetics", "Nonentities", "Beings", "Entities", "Creatures", "Critters", "Seedlings", "Shrubs", "Weeds", "Vines", "Progressed", "Aquatic", "Aquas", "Aerials", "Avians", "Aviumans", "Transformed", "Furs", "Shells", "Shelled Ones"};
    static constexpr std::string_view names2[] = {"Abna", "Abno", "Ani", "Ano", "Arach", "Arthro", "Ave", "Avi", "Barba", "Bea", "Beas", "Behe", "Bru", "Canin", "Car", "Care", "Carni", "Chi", "Chime", "Chiro", "Cla", "Crea", "Cree", "Crit", "Cro", "Croco", "Crus", "Cryp", "Dasy", "Devi", "Dice", "Felin", "Gas", "Gil", "Heli", "Inno", "Levi", "Loxo", "Lupu", "Modi", "Mus", "Muscu", "Mut", "Nea", "Neo", "Pan", "Permu", "Prima", "Probo", "Psy", "Rufu", "Serpen", "Strigi", "Tigri", "Ur", "Ursi", "Ver", "Vermi", "Vici", "Vul"};
    static constexpr std::string_view names3[] = {"barias", "bines", "bites", "crians", "cries", "crites", "garians", "garis", "gees", "gians", "gites", "narians", "neans", "nees", "nians", "nines", "nirians", "nites", "ratis", "rees", "sees", "sias", "tarians", "tasians", "teans", "tees", "tians", "tines", "tirians", "tites"};
    static constexpr std::string_view names4[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z"};
    static constexpr std::string_view names5[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names6[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names7[] = {"", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(names1);
    names = "The " + names1[rnd];
    } else if (i < 7) {
    rnd = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    names = names2[rnd] + names3[rnd2];
    } else {
    rnd = rng() % std::size(names4);
    rnd2 = rng() % std::size(names5);
    rnd3 = rng() % std::size(names6);
    rnd4 = rng() % std::size(names7);
    if (rnd3 > 64) {
    rnd4 = 0;
    }
    rnd5 = rng() % std::size(names3);
    names = names4[rnd] + names5[rnd2] + names6[rnd3] + names7[rnd4] + names3[rnd5];
    }
    return names;
    }
}
