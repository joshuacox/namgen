#include "miscellaneous-afterlifes_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_afterlifes_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "ch", "sh", "ph"};
    static constexpr std::string_view nm3[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "io", "ae", "eo"};
    static constexpr std::string_view nm4[] = {"g", "h", "l", "m", "n", "r", "s", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"bea", "bis", "bo", "dah", "del", "den", "dia", "dore", "dows", "fey", "gan", "gish", "gren", "hala", "hana", "hel", "hina", "kala", "kira", "la", "lara", "laris", "las", "lear", "less", "lia", "lis", "lore", "mani", "mer", "mia", "mora", "mu", "muria", "mus", "naha", "nahar", "nara", "nas", "nase", "nee", "neer", "nemo", "nera", "nero", "ney", "neya", "nis", "nor", "nora", "now", "noya", "nya", "nyss", "phae", "phis", "pyre", "ra", "raya", "sira", "sium", "soah", "sone", "sora", "tia", "tira", "tory", "tu", "vana", "ven", "vyre", "wan", "wen", "wyn", "zo"};
    static constexpr std::string_view nm6[] = {"Aerial", "Ageless", "Angelic", "Argent", "Astral", "Azure", "Beatific", "Blessed", "Blissful", "Bright", "Celestial", "Cerulean", "Champion", "Chosen", "Cloud", "Cosmic", "Divine", "Dream", "Elysian", "Emerald", "Empyreal", "Empyrean", "Eternal", "Ethereal", "Euphoric", "Exalted", "Glorious", "Grand", "Green", "Hallowed", "Happy", "Harmonic", "Heavenly", "Hero", "Holy", "Hunting", "Immortal", "Infinite", "Ivory", "Jade", "Light", "Miracle", "Olympian", "Paradise", "Pearly", "Perpetual", "Prime", "Promised", "Proven", "Rainbow", "Sapphire", "Seraphic", "Silver", "Sky", "Spirit", "Spring", "Sublime", "Summer", "Timeless", "Utopia", "Warrior", "Wonder"};
    static constexpr std::string_view nm7[] = {"Domain", "Empire", "Field", "Fields", "Forest", "Forests", "Garden", "Gardens", "Ground", "Grounds", "Haven", "Heaven", "Heavens", "Home", "Kingdom", "Land", "Lands", "Meadow", "Meadows", "Oasis", "Pasture", "Pastures", "Plane", "Planes", "Realm", "Sanctuary", "Sanctum", "World"};
    static constexpr std::string_view nm8[] = {"a", "e", "i", "o", "u", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm9[] = {"b", "c", "d", "f", "g", "h", "j", "k", "m", "n", "p", "q", "r", "s", "t", "v", "x", "y", "z", "ch", "sh", "br", "cr", "dr", "gr", "kr", "pr", "str", "tr", "vr"};
    static constexpr std::string_view nm10[] = {"a", "e", "i", "o", "u", "ea", "ou", "ua", "iu"};
    static constexpr std::string_view nm11[] = {"n", "r", "s", "g", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm12[] = {"'dem", "'qar", "'qira", "'xin", "'ziha", "bax", "byss", "dahn", "dell", "dess", "dis", "doze", "dues", "gara", "garn", "gash", "gor", "grinn", "hara", "hull", "huza", "jura", "kax", "kaz", "khan", "kiru", "kura", "mas", "mez", "mixar", "morta", "muria", "mus", "muy", "nahar", "naq", "naza", "naze", "nery", "nex", "nin", "nixa", "niza", "no", "nur", "nura", "ny", "paqar", "pax", "pyre", "qa", "qore", "qu", "qur", "ra", "rax", "siux", "six", "sour", "sura", "thor", "tix", "turan", "vara", "vax", "vye", "wax", "wren", "wyn", "xan", "zar", "zo", "zora", "zya", "zyss"};
    static constexpr std::string_view nm13[] = {"Abominable", "Agony", "Anguish", "Ashen", "Battle", "Blasted", "Bleak", "Blind", "Burning", "Carnage", "Conflict", "Crimson", "Dark", "Dead", "Delirium", "Demon", "Demonic", "Devil", "Diabolic", "Dire", "Dread", "Ebon", "Fever", "Flaming", "Foul", "Frenzy", "Gallow", "Gloom", "Grave", "Gray", "Grim", "Horror", "Infernal", "Killing", "Mad", "Manic", "Misery", "Misty", "Nether", "Obsidian", "Onyx", "Penance", "Plague", "Punishment", "Retribution", "Rotten", "Sanguine", "Scarlet", "Scourge", "Shadow", "Silent", "Sinister", "Skeletal", "Slave", "Somber", "Sorrow", "Struggle", "Terror", "Torment", "Torture", "Vicious", "Vile", "Wayward", "Wicked"};
    static constexpr std::string_view nm14[] = {"Domain", "Empire", "Field", "Fields", "Ground", "Grounds", "Kingdom", "Land", "Lands", "Pasture", "Pastures", "Plane", "Planes", "Realm", "World"};

    std::string name; size_t rnd = 0; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (type != 1) {
    if (i < 5) {
    rnd0 = rng() % std::size(nm1);
    rnd1 = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    name = nm1[rnd0] + nm2[rnd1] + nm3[rnd2] + nm4[rnd3] + nm5[rnd4];
    } else {
    rnd = rng() % std::size(nm6);
    rnd2 = rng() % std::size(nm7);
    name = "The " + nm6[rnd] + " " + nm7[rnd2];
    }
    } else if (type == 1) {
    if (i < 5) {
    rnd0 = rng() % std::size(nm8);
    rnd1 = rng() % std::size(nm9);
    rnd2 = rng() % std::size(nm10);
    rnd3 = rng() % std::size(nm11);
    rnd4 = rng() % std::size(nm12);
    name = nm8[rnd0] + nm9[rnd1] + nm10[rnd2] + nm11[rnd3] + nm12[rnd4];
    } else {
    rnd = rng() % std::size(nm13);
    rnd2 = rng() % std::size(nm14);
    name = "The " + nm13[rnd] + " " + nm14[rnd2];
    }
    }
    return name;
    }
}
