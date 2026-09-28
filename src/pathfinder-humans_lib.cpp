#include "pathfinder-humans_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_humans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"b", "br", "d", "dr", "g", "k", "kr", "p", "pr", "q", "r", "str", "t", "tr", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm3[] = {"d", "l", "ld", "lb", "lk", "lr", "m", "ml", "n", "nd", "nk", "r", "rk", "rc", "rd", "rl"};
    static constexpr std::string_view nm4[] = {"c", "d", "g", "k", "n", "t"};
    static constexpr std::string_view nm5[] = {"", "", "b", "bh", "d", "dh", "h", "kh", "l", "m", "n", "p", "r", "s", "t", "th", "v", "y"};
    static constexpr std::string_view nm6[] = {"d", "ll", "lb", "ld", "lr", "l", "lk", "m", "n", "nn", "nr", "nd", "nk", "r", "rr", "rl", "rn", "rm", "rd"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "h", "n", "s", "t"};
    static constexpr std::string_view nm8[] = {"", "", "", "", "", "b", "bj", "br", "f", "fr", "g", "gr", "h", "hr", "hj", "j", "k", "kr", "m", "r", "s", "st", "sv", "sk", "t", "th", "v", "y"};
    static constexpr std::string_view nm9[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ei", "uu", "ae"};
    static constexpr std::string_view nm10[] = {"bj", "d", "ddv", "dg", "dm", "dv", "g", "gb", "gbj", "gf", "gg", "gn", "gnv", "k", "ks", "lb", "lbj", "ld", "ldm", "lk", "ll", "lld", "m", "n", "nd", "ng", "ngv", "nk", "nn", "nv", "p", "r", "rg", "rl", "rn", "rnl", "rr", "rs", "rt", "rv", "sg", "sk", "st", "th", "tv", "v", "w", "x", "z"};
    static constexpr std::string_view nm11[] = {"", "", "", "", "c", "d", "f", "g", "gg", "gr", "k", "ld", "lf", "lfr", "ll", "m", "n", "nd", "ndr", "nn", "r", "rk", "rl", "rn", "rr", "rth", "st", "t"};
    static constexpr std::string_view nm12[] = {"", "", "", "", "", "b", "br", "d", "dr", "f", "fr", "g", "gr", "h", "j", "k", "l", "lj", "m", "n", "r", "s", "sv", "th", "t", "v"};
    static constexpr std::string_view nm13[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "y", "y", "au", "ie", "ae"};
    static constexpr std::string_view nm14[] = {"bj", "d", "df", "dg", "dh", "dl", "dn", "dr", "fl", "g", "gd", "gn", "gv", "ld", "lk", "ll", "llg", "lv", "m", "n", "nd", "nfr", "ng", "nj", "nng", "nnv", "r", "rd", "rf", "rg", "rgr", "rl", "rn", "sfr", "sg", "sl", "str", "th", "thr"};
    static constexpr std::string_view nm15[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "d", "f", "g", "ld", "lf", "n", "nn", "rd", "rg", "s", "th"};
    static constexpr std::string_view nm16[] = {"Amber", "Arm", "Ash", "Autumn", "Battle", "Bear", "Black", "Blaze", "Blood", "Boar", "Boulder", "Brawl", "Bright", "Bronze", "Bull", "Cinder", "Cloud", "Cold", "Common", "Dark", "Dawn", "Dead", "Doom", "Dream", "Dusk", "Dust", "Ember", "Even", "Fine", "Forest", "Free", "Frost", "Frozen", "Gloom", "Gold", "Grand", "Great", "Grim", "Grizzly", "Hallow", "Hell", "High", "Honey", "Horn", "Ice", "Iron", "Keen", "Light", "Lone", "Long", "Mighty", "Mist", "Moss", "Mountain", "Night", "Noble", "Pale", "Plain", "Pride", "Proud", "Quick", "Rage", "Rapid", "Raven", "River", "Rock", "Rune", "Shadow", "Sharp", "Silent", "Silver", "Smoke", "Snow", "Soft", "Spirit", "Star", "Steel", "Stone", "Storm", "Strong", "Summer", "Swift", "Thunder", "Troll", "True", "War", "Wild", "Wind", "Winter", "Wolf"};
    static constexpr std::string_view nm17[] = {"arm", "arrow", "bane", "bash", "bear", "blade", "brace", "brand", "breaker", "breath", "brew", "caller", "cleaver", "crest", "crusher", "cut", "cutter", "dream", "eye", "eyes", "fall", "fire", "fist", "flame", "force", "forge", "fury", "gaze", "gleam", "grip", "guard", "hair", "hall", "hammer", "hand", "heart", "hunter", "killer", "lash", "mane", "mantle", "mark", "maul", "rage", "reaper", "reaver", "rider", "ripper", "roar", "rock", "root", "scar", "scream", "shield", "shout", "slayer", "snarl", "song", "spirit", "splitter", "star", "stride", "sun", "sword", "thorn", "tongue", "walker", "ward", "watcher", "wind", "wine", "wolf"};
    static constexpr std::string_view nm18[] = {"", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "r", "s", "tr", "v", "y"};
    static constexpr std::string_view nm19[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ua", "eo", "oi", "ia"};
    static constexpr std::string_view nm20[] = {"b", "br", "bg", "c", "d", "dg", "dr", "ds", "k", "l", "ld", "lp", "m", "n", "nd", "ndr", "nn", "r", "rdr", "rg", "rn", "rr", "sm", "sn", "ss", "st", "v", "vr", "vg", "vd"};
    static constexpr std::string_view nm21[] = {"", "", "", "c", "k", "l", "ll", "n", "r", "rd", "rt", "s", "sk", "v"};
    static constexpr std::string_view nm22[] = {"", "", "", "", "", "b", "c", "d", "f", "h", "k", "l", "m", "n", "r", "s", "sh", "t", "v", "z"};
    static constexpr std::string_view nm23[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ai", "ya", "uu", "ie", "ei", "ia", "eo", "ae"};
    static constexpr std::string_view nm24[] = {"d", "ff", "f", "fr", "fl", "j", "l", "ld", "ll", "lm", "lr", "ls", "lt", "m", "mm", "ms", "mr", "ns", "nr", "n", "nd", "nn", "ph", "r", "rl", "rh", "rm", "rn", "s", "sh", "sk", "sr", "ss", "sl", "th", "tl", "v", "x"};
    static constexpr std::string_view nm25[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "h", "k", "n", "r", "s"};
    static constexpr std::string_view nm26[] = {"", "", "", "", "", "c", "cz", "d", "f", "fr", "g", "gr", "j", "k", "kl", "m", "mv", "p", "r", "s", "ts", "v", "vh", "w", "z"};
    static constexpr std::string_view nm27[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ai", "io", "ae", "aa", "oo"};
    static constexpr std::string_view nm28[] = {"cc", "d", "ddr", "dm", "g", "gr", "j", "k", "l", "ld", "ll", "m", "ml", "n", "nd", "ndl", "ng", "nj", "nn", "nt", "r", "rdr", "rk", "rr", "rs", "shk", "sht", "sk", "st", "t", "th", "ttl", "v", "zm", "zn", "zz"};
    static constexpr std::string_view nm29[] = {"", "", "", "", "", "", "", "", "d", "kz", "kcz", "l", "lf", "n", "r", "rc", "rd", "rk", "s", "t", "v"};
    static constexpr std::string_view nm30[] = {"", "", "", "", "b", "br", "cr", "c", "d", "dh", "dr", "g", "gr", "j", "k", "kr", "m", "n", "nh", "r", "x", "z", "zr"};
    static constexpr std::string_view nm31[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "au", "ou"};
    static constexpr std::string_view nm32[] = {"b", "br", "bz", "c", "cr", "d", "dr", "dl", "gh", "gg", "gr", "gn", "gm", "k", "kk", "kn", "km", "kr", "lr", "lm", "ln", "lb", "lg", "ld", "m", "md", "mz", "mr", "mg", "n", "nd", "ng", "nd", "nr", "r", "rg", "rgh", "rp", "rr", "rz", "th"};
    static constexpr std::string_view nm33[] = {"", "", "", "", "", "c", "d", "g", "l", "n", "r", "s", "sh"};
    static constexpr std::string_view nm34[] = {"", "", "", "", "", "b", "bh", "ch", "d", "dh", "g", "h", "k", "kh", "l", "m", "n", "nh", "r", "s", "sh", "t", "th", "v"};
    static constexpr std::string_view nm35[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ia", "ea"};
    static constexpr std::string_view nm36[] = {"d", "dr", "dh", "f", "ff", "g", "gg", "gn", "gm", "gh", "gl", "h", "hh", "l", "ll", "llm", "ls", "lz", "lm", "ln", "lg", "ld", "m", "mm", "mn", "ms", "mz", "ml", "n", "nn", "nl", "ns", "nr", "r", "rs", "rr", "rl", "rsh", "s", "ss", "sh", "sr", "t", "v", "zn"};
    static constexpr std::string_view nm37[] = {"", "", "", "", "", "", "", "", "", "", "h", "l", "m", "n", "s", "st", "th"};
    static constexpr std::string_view nm38[] = {"", "", "", "", "", "b", "br", "c", "d", "dr", "g", "gr", "h", "k", "kr", "l", "m", "n", "r", "s", "sh", "st", "t", "th", "v", "x", "z"};
    static constexpr std::string_view nm39[] = {"a", "e", "i", "o", "u"};
    static constexpr std::string_view nm40[] = {"d", "dr", "f", "g", "gg", "gr", "gh", "gm", "j", "k", "kk", "kr", "kn", "kl", "l", "ll", "ld", "lg", "lb", "lm", "ln", "m", "mm", "md", "mb", "mr", "ml", "n", "nn", "nb", "nl", "ng", "ngr", "nr", "r", "rs", "rr", "rb", "rg", "rl", "ss", "sh", "t", "th", "v", "z"};
    static constexpr std::string_view nm41[] = {"", "", "", "", "", "g", "ll", "l", "m", "n", "r", "s", "sh", "st", "th"};
    static constexpr std::string_view nm42[] = {"", "", "", "", "b", "c", "d", "dh", "f", "gh", "gr", "h", "j", "k", "m", "n", "r", "s", "sh", "t", "x", "w", "z"};
    static constexpr std::string_view nm43[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "a", "i", "i", "u", "aa", "ya", "eo", "ee", "oo", "ai"};
    static constexpr std::string_view nm44[] = {"b", "d", "dd", "dh", "dr", "dw", "f", "g", "h", "hr", "hs", "j", "k", "km", "l", "ll", "m", "mm", "n", "ns", "q", "qd", "qm", "r", "rb", "rf", "rg", "rh", "rr", "rw", "s", "sf", "sh", "sm", "ss", "st", "z"};
    static constexpr std::string_view nm45[] = {"", "", "b", "d", "dh", "f", "j", "jh", "k", "l", "lf", "m", "n", "r", "s", "sh", "th", "wz", "z"};
    static constexpr std::string_view nm46[] = {"", "", "", "f", "gh", "h", "j", "k", "kh", "l", "m", "n", "p", "r", "s", "sh", "t", "th", "w", "z"};
    static constexpr std::string_view nm47[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "u", "i", "y", "ya", "aa", "ai", "iya", "ee"};
    static constexpr std::string_view nm48[] = {"b", "br", "d", "dh", "f", "fl", "fn", "h", "hd", "hj", "hm", "j", "km", "l", "lm", "m", "mt", "n", "nt", "ph", "q", "r", "rh", "s", "sf", "sh", "shm", "sm", "t", "th", "z"};
    static constexpr std::string_view nm49[] = {"", "", "", "", "", "", "", "", "", "", "f", "h", "l", "n", "r", "s", "t"};
    static constexpr std::string_view nm50[] = {"", "", "", "", "b", "bh", "d", "f", "gh", "h", "j", "k", "kh", "m", "q", "r", "s", "sh", "t", "vr", "y", "z"};
    static constexpr std::string_view nm51[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "a", "i", "i", "ee", "aa", "ou", "ei"};
    static constexpr std::string_view nm52[] = {"b", "bb", "d", "dd", "dr", "f", "h", "hr", "j", "k", "l", "lk", "ll", "lm", "m", "n", "nb", "nl", "ns", "r", "rw", "s", "sh", "sm", "sp", "sr", "ss", "st", "th", "tt", "v", "w", "z"};
    static constexpr std::string_view nm53[] = {"", "", "", "d", "h", "j", "kh", "l", "lm", "m", "n", "r", "s"};
    static constexpr std::string_view nm54[] = {"", "", "", "b", "ch", "f", "g", "h", "j", "k", "kh", "m", "n", "p", "q", "r", "s", "t", "th", "v", "z"};
    static constexpr std::string_view nm55[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ae", "eu", "aa", "ui"};
    static constexpr std::string_view nm56[] = {"b", "ch", "dr", "f", "fm", "g", "h", "hbr", "hm", "k", "kh", "kht", "l", "m", "mm", "ms", "n", "nh", "nk", "nkh", "nm", "nn", "nr", "ns", "nt", "p", "ph", "ps", "pt", "r", "rg", "rk", "rm", "rp", "rph", "rr", "rs", "rt", "s", "sk", "skh", "ss", "st", "t", "thr", "zgh"};
    static constexpr std::string_view nm57[] = {"", "", "", "b", "d", "f", "ff", "h", "ln", "nn", "p", "r", "s", "sh", "t", "x"};
    static constexpr std::string_view nm58[] = {"", "", "", "", "b", "ch", "cl", "h", "k", "kh", "l", "m", "n", "p", "r", "s", "sh", "t", "th", "z"};
    static constexpr std::string_view nm59[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ee", "ia", "au", "eo", "ei"};
    static constexpr std::string_view nm60[] = {"b", "c", "fs", "h", "hm", "k", "kh", "kr", "kt", "l", "m", "mm", "n", "nk", "nkh", "nn", "ns", "nt", "p", "pp", "q", "r", "rm", "rs", "s", "sh", "st", "t", "th", "tm", "tr", "z"};
    static constexpr std::string_view nm61[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "f", "h", "l", "m", "n", "r", "s", "t"};
    static constexpr std::string_view nm62[] = {"", "", "", "", "", "", "", "", "b", "ch", "cl", "f", "g", "h", "j", "k", "kh", "l", "m", "n", "p", "q", "r", "s", "sh", "t", "th", "v", "z"};
    static constexpr std::string_view nm63[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "ae", "eu", "aa", "ui", "ee", "ia", "au", "eo", "ei"};
    static constexpr std::string_view nm64[] = {"b", "c", "ch", "dr", "f", "fm", "fs", "g", "h", "hbr", "hm", "k", "kh", "kht", "kr", "kt", "l", "m", "mm", "ms", "n", "nh", "nk", "nkh", "nm", "nn", "nr", "ns", "nt", "p", "ph", "pp", "ps", "pt", "q", "r", "rg", "rk", "rm", "rp", "rph", "rr", "rs", "rt", "s", "sh", "sk", "skh", "ss", "st", "t", "th", "thr", "tm", "tr", "z", "zgh"};
    static constexpr std::string_view nm65[] = {"", "", "", "", "", "", "", "", "b", "d", "f", "ff", "h", "l", "ln", "m", "n", "nn", "p", "r", "s", "sh", "t", "x"};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

    i = rng() % 12; {
    if (type == 1) {
    if (i < 2) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm7);
    names = std::string(nm5[rnd]) + std::string(nm2[rnd2]) + std::string(nm6[rnd3]) + std::string(nm2[rnd4]) + std::string(nm7[rnd5]);
    } else if (i < 4) {
    rnd = rng() % std::size(nm12);
    rnd2 = rng() % std::size(nm13);
    rnd3 = rng() % std::size(nm14);
    rnd4 = rng() % std::size(nm13);
    rnd5 = rng() % std::size(nm15);
    rnd6 = rng() % std::size(nm16);
    rnd7 = rng() % std::size(nm17);
    names = std::string(nm12[rnd]) + std::string(nm13[rnd2]) + std::string(nm14[rnd3]) + std::string(nm13[rnd4]) + std::string(nm15[rnd5]) + " " + std::string(nm16[rnd6]) + std::string(nm17[rnd7]);
    } else if (i < 6) {
    rnd = rng() % std::size(nm22);
    rnd2 = rng() % std::size(nm23);
    rnd3 = rng() % std::size(nm24);
    rnd4 = rng() % std::size(nm23);
    rnd5 = rng() % std::size(nm25);
    rnd6 = rng() % std::size(nm26);
    rnd7 = rng() % std::size(nm27);
    rnd8 = rng() % std::size(nm28);
    rnd9 = rng() % std::size(nm27);
    rnd10 = rng() % std::size(nm29);
    names = std::string(nm22[rnd]) + std::string(nm23[rnd2]) + std::string(nm24[rnd3]) + std::string(nm23[rnd4]) + std::string(nm25[rnd5]) + " " + std::string(nm26[rnd6]) + std::string(nm27[rnd7]) + std::string(nm28[rnd8]) + std::string(nm27[rnd9]) + std::string(nm28[rnd10]);
    } else if (i < 8) {
    rnd = rng() % std::size(nm34);
    rnd2 = rng() % std::size(nm35);
    rnd3 = rng() % std::size(nm36);
    rnd4 = rng() % std::size(nm35);
    rnd5 = rng() % std::size(nm37);
    rnd6 = rng() % std::size(nm38);
    rnd7 = rng() % std::size(nm39);
    rnd8 = rng() % std::size(nm40);
    rnd9 = rng() % std::size(nm39);
    rnd10 = rng() % std::size(nm41);
    names = std::string(nm34[rnd]) + std::string(nm35[rnd2]) + std::string(nm36[rnd3]) + std::string(nm35[rnd4]) + std::string(nm37[rnd5]) + " " + std::string(nm38[rnd6]) + std::string(nm39[rnd7]) + std::string(nm40[rnd8]) + std::string(nm39[rnd9]) + std::string(nm41[rnd10]);
    } else if (i < 10) {
    rnd = rng() % std::size(nm46);
    rnd2 = rng() % std::size(nm47);
    rnd3 = rng() % std::size(nm48);
    rnd4 = rng() % std::size(nm47);
    rnd5 = rng() % std::size(nm49);
    rnd6 = rng() % std::size(nm50);
    rnd7 = rng() % std::size(nm51);
    rnd8 = rng() % std::size(nm52);
    rnd9 = rng() % std::size(nm51);
    rnd10 = rng() % std::size(nm53);
    names = std::string(nm46[rnd]) + std::string(nm47[rnd2]) + std::string(nm48[rnd3]) + std::string(nm47[rnd4]) + std::string(nm49[rnd5]) + " " + std::string(nm50[rnd6]) + std::string(nm51[rnd7]) + std::string(nm52[rnd8]) + std::string(nm51[rnd9]) + std::string(nm53[rnd10]);
    } else {
    rnd = rng() % std::size(nm58);
    rnd2 = rng() % std::size(nm59);
    rnd3 = rng() % std::size(nm60);
    rnd4 = rng() % std::size(nm59);
    rnd5 = rng() % std::size(nm61);
    rnd6 = rng() % std::size(nm62);
    rnd7 = rng() % std::size(nm63);
    rnd8 = rng() % std::size(nm64);
    rnd9 = rng() % std::size(nm63);
    rnd10 = rng() % std::size(nm65);
    names = std::string(nm58[rnd]) + std::string(nm59[rnd2]) + std::string(nm60[rnd3]) + std::string(nm59[rnd4]) + std::string(nm61[rnd5]) + " " + std::string(nm62[rnd6]) + std::string(nm63[rnd7]) + std::string(nm64[rnd8]) + std::string(nm63[rnd9]) + std::string(nm65[rnd10]);
    }
    } else {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm2[rnd4]) + std::string(nm4[rnd5]);
    } else if (i < 4) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    rnd3 = rng() % std::size(nm10);
    rnd4 = rng() % std::size(nm9);
    rnd5 = rng() % std::size(nm11);
    rnd6 = rng() % std::size(nm16);
    rnd7 = rng() % std::size(nm17);
    names = std::string(nm8[rnd]) + std::string(nm9[rnd2]) + std::string(nm10[rnd3]) + std::string(nm9[rnd4]) + std::string(nm11[rnd5]) + " " + std::string(nm16[rnd6]) + std::string(nm17[rnd7]);
    } else if (i < 6) {
    rnd = rng() % std::size(nm18);
    rnd2 = rng() % std::size(nm19);
    rnd3 = rng() % std::size(nm20);
    rnd4 = rng() % std::size(nm19);
    rnd5 = rng() % std::size(nm21);
    rnd6 = rng() % std::size(nm26);
    rnd7 = rng() % std::size(nm27);
    rnd8 = rng() % std::size(nm28);
    rnd9 = rng() % std::size(nm27);
    rnd10 = rng() % std::size(nm29);
    names = std::string(nm18[rnd]) + std::string(nm19[rnd2]) + std::string(nm20[rnd3]) + std::string(nm19[rnd4]) + std::string(nm21[rnd5]) + " " + std::string(nm26[rnd6]) + std::string(nm27[rnd7]) + std::string(nm28[rnd8]) + std::string(nm27[rnd9]) + std::string(nm28[rnd10]);
    } else if (i < 8) {
    rnd = rng() % std::size(nm30);
    rnd2 = rng() % std::size(nm31);
    rnd3 = rng() % std::size(nm32);
    rnd4 = rng() % std::size(nm31);
    rnd5 = rng() % std::size(nm33);
    rnd6 = rng() % std::size(nm38);
    rnd7 = rng() % std::size(nm39);
    rnd8 = rng() % std::size(nm40);
    rnd9 = rng() % std::size(nm39);
    rnd10 = rng() % std::size(nm41);
    names = std::string(nm30[rnd]) + std::string(nm31[rnd2]) + std::string(nm32[rnd3]) + std::string(nm31[rnd4]) + std::string(nm33[rnd5]) + " " + std::string(nm38[rnd6]) + std::string(nm39[rnd7]) + std::string(nm40[rnd8]) + std::string(nm39[rnd9]) + std::string(nm41[rnd10]);
    } else if (i < 10) {
    rnd = rng() % std::size(nm42);
    rnd2 = rng() % std::size(nm43);
    rnd3 = rng() % std::size(nm44);
    rnd4 = rng() % std::size(nm43);
    rnd5 = rng() % std::size(nm45);
    rnd6 = rng() % std::size(nm50);
    rnd7 = rng() % std::size(nm51);
    rnd8 = rng() % std::size(nm52);
    rnd9 = rng() % std::size(nm51);
    rnd10 = rng() % std::size(nm53);
    names = std::string(nm42[rnd]) + std::string(nm43[rnd2]) + std::string(nm44[rnd3]) + std::string(nm43[rnd4]) + std::string(nm45[rnd5]) + " " + std::string(nm50[rnd6]) + std::string(nm51[rnd7]) + std::string(nm52[rnd8]) + std::string(nm51[rnd9]) + std::string(nm53[rnd10]);
    } else {
    rnd = rng() % std::size(nm54);
    rnd2 = rng() % std::size(nm55);
    rnd3 = rng() % std::size(nm56);
    rnd4 = rng() % std::size(nm55);
    rnd5 = rng() % std::size(nm57);
    rnd6 = rng() % std::size(nm62);
    rnd7 = rng() % std::size(nm63);
    rnd8 = rng() % std::size(nm64);
    rnd9 = rng() % std::size(nm63);
    rnd10 = rng() % std::size(nm65);
    names = std::string(nm54[rnd]) + std::string(nm55[rnd2]) + std::string(nm56[rnd3]) + std::string(nm55[rnd4]) + std::string(nm57[rnd5]) + " " + std::string(nm62[rnd6]) + std::string(nm63[rnd7]) + std::string(nm64[rnd8]) + std::string(nm63[rnd9]) + std::string(nm65[rnd10]);
    }
    }
    return names;
    }
}
