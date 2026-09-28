#include "dungeon_and_dragons-goliaths_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_dungeon_and_dragons_goliaths_name(std::mt19937& rng, int type) {
    static constexpr std::string_view namesFemF[] = {"Age", "Ane", "Gau", "Ge", "Ina", "Kau", "Ke", "Ki", "Kuo", "La", "Le", "Maa", "Man", "Mau", "Me", "Na", "Nal", "Ni", "One", "Ori", "Paa", "Pau", "Pe", "Tha", "The", "Thu", "Vaa", "Vau", "Ve", "Vu"};
    static constexpr std::string_view namesFemL[] = {"gea", "geo", "gia", "gu", "kea", "keo", "ki", "kia", "kio", "la", "lai", "lane", "lea", "leo", "lo", "lu", "meo", "mi", "mia", "ne", "nea", "neo", "ni", "nia", "nu", "peo", "peu", "pu", "rea", "ri", "ria", "the", "thea", "thia", "thio", "thu", "vea", "vi", "via", "vu"};
    static constexpr std::string_view namesMaleF[] = {"Ag", "Apa", "Au", "Aug", "Eg", "Gau", "Gea", "Gha", "Ili", "Kana", "Kava", "Keo", "Khu", "La", "Ma", "Mau", "Mea", "Mo", "Na", "Neo", "Pa", "Pu", "Tha", "Thava", "Tho", "Va", "Vau", "Vega", "Vi", "Vo"};
    static constexpr std::string_view namesMaleL[] = {"gak", "gal", "gan", "gath", "ghan", "gith", "glath", "gun", "kan", "kein", "khal", "kin", "kon", "lath", "lig", "lok", "mahg", "mahk", "mahl", "mak", "man", "mith", "mul", "nak", "nath", "nihl", "noth", "path", "phak", "thag", "thak", "tham", "thi", "thok", "veith", "vek", "vhal", "vhik", "vith", "voi"};
    static constexpr std::string_view namesMid[] = {"Adeptweaver", "Bearfinder", "Bearkiller", "Bearvigor", "Braveguard", "Braveheart", "Brightheart", "Dawncaller", "Daydreamer", "Deerchaser", "Deerfrightner", "Deerhunter", "Deerstalker", "Dreamwanderer", "Fearless", "Flintfinder", "Flowerpicker", "Foodfinder", "Foodmaker", "Frightheart", "Goatherder", "Goatwatcher", "Hardworker", "Hidetanner", "Highclimber", "Honestheart", "Horncarver", "Keeneye", "Keenshot", "Keenwatcher", "Lonehunter", "Lonewalker", "Longleaper", "Lowlander", "Lumberbearer", "Lumberhauler", "Mastercook", "Messenger", "Minddrifter", "Mountainclimber", "Nightrunner", "Nightwarrior", "Rainwatcher", "Riverjumper", "Rockbreaker", "Rocksmasher", "Rootfinder", "Rootsmasher", "Silentstalker", "Silentwalker", "Skywatcher", "Slywalker", "Smartleader", "Steadyhand", "Stonebreaker", "Stormwatcher", "Stronghunter", "Strongleader", "Strongwalker", "Swiftaid", "Swifthunter", "Swiftrunner", "Swiftstriker", "Swiftwalker", "Threadtwister", "Thunderfist", "Treelogger", "Tribeguard", "Truefriend", "Truthspeaker", "Wanderlost", "Wildfinder", "Wildstalker", "Wisewalker", "Woundmender"};
    static constexpr std::string_view namesSurF[] = {"Agu-Ul", "Agu-V", "Anakal", "Apuna-M", "Athun", "Egena-V", "Egum", "Elan", "Ganu-M", "Gathak", "Gean", "Inul", "Kalag", "Kaluk", "Katho-Ol", "Kolae-G", "Kolak", "Kulan", "Kulum", "Lakum", "Maluk", "Munak", "Muthal", "Nalak", "Nola-K", "Nugal", "Nulak", "Ogol", "Oveth", "Thenal", "Thul", "Thunuk", "Ugun", "Uthenu-K", "Vaimei-L", "Valu-N", "Vathun", "Veom", "Vuma-Th", "Vunak"};
    static constexpr std::string_view namesSurL[] = {"aga", "ageane", "akane", "akanu", "akume", "alathi", "amino", "amune", "anathi", "atake", "athai", "athala", "atho", "avea", "avi", "avone", "eaku", "ekali", "elo", "iaga", "iago", "iala", "iano", "igala", "igane", "igano", "igo", "igone", "ileana", "ithino", "olake", "ugate", "ugoni", "ukane", "ukate", "ukena", "ulane", "upine", "utha", "uthea"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

    i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(namesFemF);
    rnd2 = rng() % std::size(namesFemL);
    rnd3 = rng() % std::size(namesMid);
    rnd4 = rng() % std::size(namesSurF);
    rnd5 = rng() % std::size(namesSurL);
    names = std::string(namesFemF[rnd]) + std::string(namesFemL[rnd2]) + " " + std::string(namesMid[rnd3]) + " " + std::string(namesSurF[rnd4]) + std::string(namesSurL[rnd5]);
    } else {
    rnd = rng() % std::size(namesMaleF);
    rnd2 = rng() % std::size(namesMaleL);
    rnd3 = rng() % std::size(namesMid);
    rnd4 = rng() % std::size(namesSurF);
    rnd5 = rng() % std::size(namesSurL);
    names = std::string(namesMaleF[rnd]) + std::string(namesMaleL[rnd2]) + " " + std::string(namesMid[rnd3]) + " " + std::string(namesSurF[rnd4]) + std::string(namesSurL[rnd5]);
    }
    return names;
    }
}
