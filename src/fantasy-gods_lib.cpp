#include "fantasy-gods_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_gods_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "u", "i", "o", "y"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"agi", "aldir", "aos", "arus", "borh", "bris", "bum", "bus", "dall", "dar", "darr", "des", "dis", "dite", "dohr", "don", "dos", "dros", "dum", "dur", "emis", "enar", "esis", "eus", "eyar", "eyr", "her", "ion", "ione", "ius", "jun", "ldir", "lios", "lo", "lous", "mes", "mir", "mjir", "mos", "mus", "nia", "lotl", "zotz", "zotl", "nir", "nos", "nus", "ohr", "orr", "rasil", "reus", "ros", "ruer", "rus", "ses", "stus", "tar", "tarr", "teus", "thar", "ther", "tia", "ton", "tos", "tyx", "ysus"};
    static constexpr std::string_view nm5[] = {"ra", "ara", "ella", "elia", "nja", "yja", "ulla", "la", "na", "ana", "otz", "otl", "neas", "phine", "tris", "gyn", "syn", "dite", "ena", "hena", "tia", "anke", "mera", "nera", "soi", "heia", "mis", "thys", "asis", "one", "dione", "dona", "ona", "phion", "trix", "tix", "lene", "lena", "phy", "tune", "va", "una", "tuna", "arae", "aris", "ris", "tia", "rena", "raura", "dea", "enta", "dia", "ta"};
    static constexpr std::string_view nm6[] = {"Abundance", "Agriculture", "Animals", "Battle", "Beauty", "Beer", "Beginnings", "Blacksmiths", "Chaos", "Children", "Chivalry", "Commerce", "Conquest", "Dawn", "Day", "Death", "Destiny", "Destruction", "Dreams", "Dusk", "Duty", "Earth", "Education", "Endings", "Envy", "Fall", "Fame", "Fertility", "Finance", "Fire", "Forgiveness", "Fortune", "Freedom", "Funerals", "Good Luck", "Governance", "Harvest", "Hatred", "Health", "Home", "Honesty", "Honor", "Hope", "Hunting", "Infamy", "Jealousy", "Judgement", "Justice", "Law", "Life", "Life & Death", "Light", "Logic", "Love", "Loyalty", "Magic", "Marriage", "Medicine", "Mercy", "Messages", "Miracles", "Misfortune", "Music", "Nature", "Night", "Night & Day", "Oracles", "Order", "Peace", "Penance", "Pleasure", "Poetry", "Prosperity", "Revenge", "Science", "Secrecy", "Shadows", "Sleep", "Spring", "Strength", "Success", "Summer", "Thunder", "Time", "Torture", "Trade", "Tranquility", "Tricks", "Truth", "Vengeance", "Victory", "Virtues", "War", "Water", "Weddings", "Wind", "Wine", "Winter", "Wisdom", "Work", "Youth", "the Afterlife", "the Dark", "the Hearth", "the Hunt", "the Insane", "the Land", "the Military", "the Moon", "the Mountains", "the Ocean", "the Ostracized", "the Rivers", "the Sea", "the Sky", "the Stars", "the Sun", "the Underworld"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd6 = rng() % std::size(nm6);
    if (type == 1) {
    rnd5 = rng() % std::size(nm5);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm5[rnd5] + ", Goddess of " + nm6[rnd6];
    } else {
    rnd4 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + ", God of " + nm6[rnd6];
    }
    return names;
    }
}
