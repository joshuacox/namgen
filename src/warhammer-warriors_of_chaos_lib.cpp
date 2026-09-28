#include "warhammer-warriors_of_chaos_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_warhammer_warriors_of_chaos_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "bl", "br", "d", "dr", "dj", "f", "fr", "g", "gr", "gh", "k", "kh", "kr", "m", "r", "s", "sc", "sr", "sk", "sz", "str", "t", "tr", "v", "w"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u", "y", "ao", "au", "oa", "ay"};
    static constexpr std::string_view nm3[] = {"d", "gg", "k", "kh", "l", "m", "r", "rr", "z", "zh", "zz", "d", "gg", "k", "kh", "l", "m", "r", "rr", "z", "zh", "zz", "d", "gg", "k", "kh", "l", "m", "r", "rr", "z", "zh", "zz", "d", "gg", "k", "kh", "l", "m", "r", "rr", "z", "zh", "zz", "d", "dr", "dz", "gv", "gg", "gr", "gn", "gtr", "gz", "k", "kr", "kz", "kh", "ktr", "kth", "kx", "l", "lr", "lfr", "lvr", "lv", "lg", "lgr", "ld", "ldr", "m", "mk", "mkr", "mz", "mv", "mvr", "r", "rr", "rx", "rz", "rzr", "rk", "rkh", "rch", "rgh", "rb", "sz", "str", "sgr", "sg", "sk", "skr", "st", "sht", "shtr", "shk", "szh", "z", "zh", "zz", "zr"};
    static constexpr std::string_view nm4[] = {"", "", "b", "ch", "k", "l", "lk", "ld", "n", "nd", "r", "rd", "rk", "rt", "rr", "s", "sk", "t", "tts", "tch", "x"};
    static constexpr std::string_view nm5[] = {"bh", "br", "d", "dh", "f", "fr", "fh", "g", "gh", "gr", "kh", "kr", "k", "m", "mh", "n", "nh", "r", "rh", "s", "sh", "sl", "sm", "sn", "st", "sth", "t", "th", "thr", "tr", "v", "vh", "vr", "w", "wh"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "a", "a", "ia", "ea", "ae"};
    static constexpr std::string_view nm7[] = {"d", "g", "gg", "gh", "k", "kk", "kh", "l", "ll", "m", "mm", "r", "rr", "s", "ss", "z", "zh", "zz", "d", "g", "gg", "gh", "k", "kk", "kh", "l", "ll", "m", "mm", "r", "rr", "s", "ss", "z", "zh", "zz", "d", "g", "gg", "gh", "k", "kk", "kh", "l", "ll", "m", "mm", "r", "rr", "s", "ss", "z", "zh", "zz", "d", "dj", "dn", "fr", "fg", "gg", "g", "gr", "gh", "gn", "gm", "gz", "k", "kk", "kn", "kh", "kr", "kz", "kt", "kth", "l", "ll", "lr", "lx", "lt", "lth", "ln", "lk", "m", "mm", "mn", "mr", "mv", "mz", "mk", "nk", "ng", "nm", "nr", "nth", "nz", "nv", "r", "rr", "rth", "rsh", "rz", "rzh", "rl", "rc", "rch", "s", "ss", "sz", "sh", "shz", "shn", "sq", "shq", "sht", "shtr", "szh", "z", "zz", "zh", "zn", "zhn"};
    static constexpr std::string_view nm8[] = {"amber", "battle", "bitter", "black", "blaze", "blazing", "blood", "burn", "burning", "chaos", "cinder", "daemon", "dark", "dead", "death", "demon", "doom", "ember", "fiery", "fire", "flame", "fuse", "gloom", "haze", "hell", "moon", "nether", "night", "pyre", "rage", "rot", "shade", "shadow", "silent", "storm", "sun", "thunder", "twice", "void", "wild", "wraith", "wrath"};
    static constexpr std::string_view nm9[] = {"bane", "bash", "blaze", "blight", "bone", "born", "bound", "breath", "buster", "chaser", "cleaver", "eater", "fall", "fang", "fire", "flame", "flare", "flaw", "force", "forge", "forged", "fury", "gaze", "guard", "gut", "hand", "heart", "lash", "mark", "marked", "might", "more", "mourn", "rage", "reaper", "reaver", "scar", "scream", "seeker", "shade", "shadow", "shard", "spawn", "spawned", "spew", "spit", "strength", "stride", "sunder", "surge", "sworn", "wrath"};
    static constexpr std::string_view nm10[] = {"Abandoned", "Aggressor", "Anguished", "Beast", "Befouled", "Behemoth", "Berserker", "Bewitched", "Blood Bathed", "Blood Soaked", "Bloodied", "Bloody", "Bone Crusher", "Corrupted Mind", "Corruption Lord", "Corruptor", "Crooked Smile", "Cunning", "Cunning Mind", "Curseling", "Dark Lord", "Dark Master", "Dark Night", "Dead Mind", "Defiled", "Dread Lord", "Eternal", "Everchosen", "Explosive", "Faithless", "Forsaken", "Fury", "Gory", "Grave Digger", "Grave Robber", "Grim Reaper", "Grotesque", "Hollow", "Hound", "Ill Tempered", "Impure", "Insane", "Irrational", "Jester", "Leechlord", "Lone Wolf", "Lost Mind", "Magnificent", "Mammoth", "Maneater", "Manslayer", "Menace", "Merciless", "Mutant", "Necromancer", "Nightmare", "Nomad", "Parasite", "Pollutor", "Rash", "Roamer", "Rotten", "Rotting", "Sanguine", "Sanguine Lord", "Serpent", "Serpent Tongue", "Shadow Dweller", "Sinner", "Skeptic", "Skinner", "Slaughterer", "Soothsayer", "Suneater", "Transient", "Unstable", "Vagrant", "Vengeful", "Volatile", "Wanderer", "Warmonger", "Wicked", "Wrathful", "Wreckage", "Wretched"};

    std::string lName; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (i % 3 == 0) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    while (nm8[rnd] == nm9[rnd2]) {
    rnd2 = rng() % std::size(nm9);
    }
    lName = nm8[rnd] + nm9[rnd2];
    } else {
    rnd = rng() % std::size(nm10);
    lName = "the " + nm10[rnd];
    }
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    if (i < 6) {
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + lName;
    } else {
    rnd5 = rng() % std::size(nm7);
    rnd6 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + nm7[rnd5] + nm6[rnd6] + " " + lName;
    }
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    if (i < 6) {
    if (rnd < 3) {
    while (rnd5 < 2) {
    rnd5 = rng() % std::size(nm4);
    }
    }
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lName;
    } else {
    rnd7 = rng() % std::size(nm2);
    rnd6 = rng() % std::size(nm3);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm3[rnd6] + nm2[rnd7] + nm4[rnd5] + " " + lName;
    }
    }
    return names;
    }
}
