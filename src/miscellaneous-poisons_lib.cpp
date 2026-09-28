#include "miscellaneous-poisons_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_poisons_name(std::mt19937& rng) {
    static constexpr std::string_view nma[] = {"", "", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "x", "z", "bh", "br", "ch", "cl", "cr", "dh", "dr", "fh", "fl", "fr", "gh", "gl", "gr", "kh", "kl", "kr", "ph", "pn", "pr", "rh", "sc", "sh", "st", "str", "th", "tr", "vr"};
    static constexpr std::string_view nmb[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y", "y", "y", "ae", "ai", "ei", "ia", "ie", "ee", "eo"};
    static constexpr std::string_view nmc[] = {"c", "d", "f", "g", "h", "k", "l", "m", "n", "q", "r", "s", "t", "v", "x", "z", "c", "d", "f", "g", "h", "k", "l", "m", "n", "q", "r", "s", "t", "v", "x", "z", "c", "d", "f", "g", "h", "k", "l", "m", "n", "q", "r", "s", "t", "v", "x", "z", "c", "d", "f", "g", "h", "k", "l", "m", "n", "q", "r", "s", "t", "v", "x", "z", "cc", "cl", "cn", "dd", "dh", "ff", "fn", "fr", "fl", "gd", "gg", "gh", "gm", "gn", "gr", "hh", "kk", "kb", "kh", "kl", "kn", "km", "kr", "ll", "lc", "lg", "lk", "lm", "ln", "lq", "lv", "lz", "mm", "mh", "mn", "mr", "mz", "ng", "nd", "nc", "nh", "nk", "nl", "nm", "nn", "nr", "nt", "nv", "nz", "qn", "qr", "rc", "rd", "rg", "rh", "rk", "rl", "rm", "rn", "rq", "rr", "rt", "rv", "rz", "sc", "sg", "sl", "sm", "sn", "sp", "ss", "st", "th", "tr", "ts", "vr", "xn", "xm", "xl"};
    static constexpr std::string_view nmd[] = {"caine", "cide", "cin", "cite", "cyn", "cyne", "din", "dis", "dyn", "fen", "fin", "fyde", "hyde", "kite", "kyde", "laine", "lax", "lic", "lite", "lyce", "lys", "mane", "mide", "min", "mine", "mis", "mith", "nade", "nari", "nic", "nide", "nine", "nite", "nith", "nix", "nol", "nyde", "nyte", "phax", "phis", "phite", "phix", "phyn", "raide", "raine", "rax", "rin", "rine", "ris", "rith", "rix", "ron", "rux", "ryn", "sane", "sax", "sel", "sin", "sine", "sinth", "site", "sithe", "smin", "sol", "syl", "syn", "sys", "syth", "tain", "thine", "tin", "tith", "tocin", "tyl", "tyne", "vain", "vine", "vis", "vith", "vyl", "vys", "vyth", "xain", "xal", "xide", "xin", "xol", "xyl", "xyth", "zal", "zid", "zite", "zol", "zon", "zyl"};
    static constexpr std::string_view nm1[] = {"Abyss", "Agony", "Alpha", "Anarchy", "Angel's", "Angelic", "Baleful", "Banshee", "Basilisk", "Belch", "Belching", "Berserker", "Bitter", "Bleak", "Bleeding", "Blind", "Blinded", "Blistering", "Bloat", "Bloating", "Bold", "Brain", "Burning", "Chaos", "Cherub", "Child's", "Chimera", "Cipher", "Cold", "Crimson", "Crying", "Crystal", "Cursed", "Cyst", "Daemon", "Dark", "Daydream", "Death's", "Demonic", "Devil's", "Dire", "Divine", "Doom", "Dragon", "Drake", "Dream", "Dull", "Dying", "Ebon", "Eerie", "Entropy", "Eternal", "Ethereal", "Execution", "Fading", "Fatal", "Fey", "Fiendish", "Fiery", "Final", "Fire", "Flame", "Forbidden", "Forlorn", "Frost", "Frozen", "Fury", "Futile", "Gal", "Ghost", "Gloom", "Goblin", "Grave", "Grim", "Hag's", "Hellish", "Hemorrhage", "Hopeless", "Humming", "Hyper", "Immortal", "Impossible", "Incurable", "Infernal", "Ire", "Ivory", "Jester", "Killing", "Last", "Leeching", "Livid", "Lost", "Lover's", "Luminous", "Malefic", "Manic", "Medusa", "Meta", "Monster", "Mortal", "Moss", "Necron", "Necrotic", "Nether", "Neutral", "Night", "Nightmare", "Nimble", "Numbing", "Obsidian", "Ogre", "Onyx", "Pandemonium", "Passion", "Peace", "Phantom", "Plague", "Pygmy", "Quivering", "Radiant", "Rage", "Rapid", "Reaper", "Sanguine", "Savage", "Scourged", "Serpent", "Shade", "Shadow", "Sharp", "Shrew", "Shriveling", "Shrouded", "Silent", "Silver", "Sinister", "Skull", "Slag", "Sleeping", "Smile", "Smiling", "Soulless", "Specter", "Spewing", "Spider", "Sprite's", "Stiff", "Strangler", "Strangling", "Summer's", "Swelling", "Symbiotic", "Tainted", "Terminal", "Tomb", "Torment", "Torture", "Trembling", "Twilight", "Unseen", "Veiled", "Vicious", "Vile", "Violet", "Vision", "Vivid", "Void", "Vortex", "Weeping", "Wicked", "Winter's", "Witch's", "Wither", "Woeful", "Wraith"};
    static constexpr std::string_view nm2[] = {"Bane", "Blade", "Blight", "Caress", "Clutch", "Compound", "Dust", "Embrace", "Flower", "Fungus", "Itch", "Gas", "Grasp", "Growth", "Grudge", "Kiss", "Leaf", "Lock", "Malice", "Mist", "Mutagen", "Petal", "Poison", "Powder", "Rancor", "Scale", "Scratch", "Seed", "Smile", "Smoke", "Spine", "Spite", "Spore", "Spray", "Stalk", "Taint", "Taste", "Tears", "Thorn", "Torment", "Touch", "Toxin", "Venom", "Water"};
    static constexpr std::string_view nm3[] = {"Abra", "Ache", "Allure", "Alpha", "Appetite", "Arachnid", "Ash", "Asphyx", "Ataxia", "Axiom", "Bane", "Banshee", "Basilisk", "Beta", "Bilge", "Billow", "Bloat", "Brimstone", "Burnout", "Catalyst", "Chaos", "Cinder", "Coax", "Craze", "Crucifix", "Daemon", "Debris", "Decoy", "Desire", "Dew", "Djinn", "Dolor", "Dupe", "Eclipse", "Empathy", "Entropy", "Enzyme", "Fiend", "Finis", "Frenzy", "Garrotte", "Ghost", "Goad", "Greed", "Grief", "Gunk", "Gyre", "Harrow", "Heartache", "Hellion", "Hound", "Imp", "Impetus", "Impulse", "Incentive", "Inferno", "Itch", "Jester", "Jinx", "Knave", "Knockout", "Limbo", "Malady", "Manes", "Mangle", "Mania", "Martyr", "Medusa", "Mire", "Misery", "Muffle", "Musk", "Muze", "Nag", "Necro", "Nightmare", "Pandemonium", "Pest", "Phantom", "Pixie", "Purgatory", "Quelch", "Rapture", "Relish", "Residue", "Revelation", "Revenant", "Rogue", "Rune", "Scapegoat", "Scorch", "Serpent", "Shush", "Silence", "Silt", "Slag", "Sludge", "Smite", "Smother", "Smudge", "Sprite", "Spur", "Stitch", "Stranger", "Strangle", "Symbiote", "Tease", "Terra", "Throe", "Throttle", "Tickle", "Toll", "Torment", "Tremble", "Truth", "Twilight", "Twinge", "Vision", "Voodoo", "Vortex", "Wish", "Wraith", "Wyvern"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; int i = 0;

i = rng() % 10; {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    } else if (i < 4) {
    rnd = rng() % std::size(nm3);
    names = nm3[rnd];
    } else {
    rnd = rng() % std::size(nma);
    rnd2 = rng() % std::size(nmb);
    rnd3 = rng() % std::size(nmd);
    if (i < 7) {
    while (rnd < 7) {
    rnd = rng() % std::size(nma);
    }
    names = nma[rnd] + nmb[rnd2] + nmd[rnd3];
    } else {
    rnd4 = rng() % std::size(nmc);
    rnd5 = rng() % std::size(nmb);
    names = nma[rnd] + nmb[rnd2] + nmc[rnd4] + nmb[rnd5] + nmd[rnd3];
    }
    }
    return names;
    }
}
