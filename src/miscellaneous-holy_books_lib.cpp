#include "miscellaneous-holy_books_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_holy_books_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm3[] = {"Book", "Books", "Scroll", "Scrolls", "Testament", "Testaments", "Codex", "Codices", "Chronicle", "Chronicles", "Tome", "Tomes", "Word", "Words"};
    static constexpr std::string_view nm4[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"a", "e", "u", "i", "o", "y"};
    static constexpr std::string_view nm6[] = {"b", "c", "d", "f", "g", "h", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm7[] = {"agi", "aldir", "aos", "arus", "borh", "bris", "bum", "bus", "dall", "dar", "darr", "des", "dis", "dite", "dohr", "don", "dos", "dros", "dum", "dur", "emis", "enar", "esis", "eus", "eyar", "eyr", "her", "ion", "ione", "ius", "jun", "ldir", "lios", "lo", "lous", "mes", "mir", "mjir", "mos", "mus", "nia", "nir", "nos", "nus", "ohr", "orr", "rasil", "reus", "ros", "ruer", "rus", "ses", "stus", "tar", "tarr", "teus", "thar", "ther", "tia", "ton", "tos", "tyx", "ysus"};
    static constexpr std::string_view nm8[] = {"ra", "ara", "ella", "elia", "nja", "yja", "ulla", "la", "na", "ana", "neas", "phine", "tris", "gyn", "syn", "dite", "ena", "hena", "tia", "anke", "mera", "nera", "soi", "heia", "mis", "thys", "asis", "one", "dione", "dona", "ona", "phion", "trix", "tix", "lene", "lena", "phy", "tune", "va", "una", "tuna", "arae", "aris", "ris", "tia", "rena", "raura", "dea", "enta", "dia", "ta"};
    static constexpr std::string_view nm1[] = {"Absolution", "Angels", "Answers", "Ardor", "Balance", "Birth", "Births", "Blessings", "Brotherhood", "Cerberus", "Change", "Children", "Clarity", "Connections", "Cycles", "Dawn", "Death", "Dedication", "Design", "Desires", "Divines", "Divinity", "Dominion", "Duality", "Dusk", "Earth", "Effigies", "Elements", "Embers", "Emissaries", "Epochs", "Eternity", "Eyes", "Facts", "Faith", "Fate", "Fealty", "Fears", "Felicity", "Fidelity", "Fire", "Flames", "Fury", "Genesis", "Glory", "Gods", "Grace", "Guidance", "Harmony", "Hearts", "Heaven", "Heralds", "Hope", "Illumination", "Inception", "Infinity", "Innocence", "Integrity", "Kinship", "Legacies", "Life", "Light", "Loyalty", "Miracles", "Moons", "Morality", "Nature", "Passion", "Perfection", "Piety", "Prophecies", "Prophets", "Prudence", "Purity", "Revelations", "Saints", "Sanction", "Seraphs", "Serenity", "Service", "Sight", "Sisterhood", "Souls", "Spirits", "Stars", "Suns", "Teachings", "Titans", "Tranquility", "Truths", "Valediction", "Virtues", "Vision", "Visions", "Vitality", "Witnesses", "Worship", "Worth", "Zeal", "Zion", "the Alpha", "the Archangel", "the Aspect", "the Child", "the Children", "the Curator", "the Custodian", "the Cycle", "the Daemon", "the Divine", "the Emissary", "the Equilibrium", "the Eye", "the Father", "the Heart", "the Matriarch", "the Mind", "the Moon", "the Mother", "the Omega", "the Oracle", "the Past", "the Patriarch", "the Phoenix", "the Rapture", "the Sentinel", "the Shepherd", "the Sign", "the Solstice", "the Sun", "the Truth"};
    static constexpr std::string_view nm2[] = {"Absolution", "Aeon", "Affinity", "Afterworld", "Almighty", "Alpha", "Amity", "Amnesty", "Angelic", "Apex", "Ardor", "Ascension", "Aspect", "Astral", "Ataraxia", "Azure", "Balance", "Birth", "Blessed", "Bloodline", "Brotherhood", "Celestial", "Century", "Cerberus", "Clarity", "Concord", "Connection", "Covenant", "Crown", "Curator", "Custodian", "Cycle", "Daemon", "Dawn", "Descendant", "Devotion", "Divine", "Divinity", "Dominion", "Duality", "Effigy", "Element", "Elysian", "Ember", "Emissary", "Empyrean", "Epitome", "Epoch", "Equilibrium", "Essence", "Eternal", "Ethereal", "Evidence", "Exemplary", "Faith", "Fate", "Fealty", "Felicity", "Fidelity", "Fire", "Force", "Fundamental", "Generation", "Genesis", "Glory", "Guardian", "Hallowed", "Harmony", "Heaven", "Heirloom", "Herald", "Heritage", "Heritage", "Holy", "Idol", "Illumination", "Immortal", "Inception", "Infinitude", "Infinity", "Innocence", "Integrity", "Keeper", "Kindred", "Kingdom", "Kinship", "Legacy", "Life", "Light", "Lineage", "Loyalty", "Lustrous", "Master", "Matriarch", "Mercy", "Messenger", "Miracle", "Moon", "Morality", "Myriad", "Noble", "Observance", "Omega", "Oracle", "Paragon", "Passion", "Patriarch", "Pedigree", "Perfection", "Phoenix", "Piety", "Pinnacle", "Pious", "Power", "Prime", "Prodigy", "Prophecy", "Prophet", "Prudence", "Pure", "Purity", "Rapture", "Realm", "Revelation", "Revered", "Reverent", "Righteous", "Sacred", "Saintly", "Sanctified", "Sanctity", "Sentinel", "Seraph", "Serenity", "Service", "Shepherd", "Sign", "Sinless", "Sisterhood", "Solemn", "Solstice", "Soul", "Spire", "Spirit", "Sun", "Titan", "Totem", "Tranquility", "Truth", "Unity", "Utopia", "Venerable", "Vertex", "Virtue", "Vision", "Vitality", "Witness", "Worship", "Worthy", "Zeal", "Zenith", "Zion"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm3);
    if (i < 3) {
    rnd2 = rng() % std::size(nm1);
    names = "The " + nm3[rnd] + " of " + nm1[rnd2];
    } else if (i < 6) {
    rnd2 = rng() % std::size(nm2);
    names = "The " + nm2[rnd2] + " " + nm3[rnd];
    } else if (i < 8) {
    rnd2 = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm8);
    names = "The " + nm1[rnd2] + " of " + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm8[rnd6];
    } else {
    rnd3 = rng() % std::size(nm4);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    names = "The " + nm3[rnd] + " of " + nm4[rnd3] + nm5[rnd4] + nm6[rnd5] + nm7[rnd6];
    }
    return names;
    }
}
