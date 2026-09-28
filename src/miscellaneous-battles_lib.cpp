#include "miscellaneous-battles_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_battles_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Battle", "Assault", "Battle", "Battle", "Attack", "War", "War", "Siege"};
    static constexpr std::string_view names2[] = {"Advisors", "Allies", "Ancients", "Attrition", "Bad Omen", "Beliefs", "Bent Truths", "Betrayal", "Blind Justice", "Bloodthirst", "Bows", "Broken Bones", "Broken Dreams", "Broken Homes", "Broken Laws", "Broken Love", "Broken Minds", "Broken Mountains", "Broken Pacts", "Broken Wills", "Brothers", "Burning Fields", "Burning Lands", "Burning Plains", "Camouflage", "Chemistry", "Chiefs", "Corrupted Lands", "Corrupted Minds", "Courage", "Covert Actions", "Cowards", "Craftsmen", "Death's Fall", "Death's Rise", "Deception", "Delirium", "Devotion", "Dictators", "Differences", "Dishonesty", "Equality", "Eternal Bombardments", "Eternal Fires", "Eternal Hunger", "Eternal Regrets", "Eternal Suffering", "Executioners", "Exploding Mountains", "Faiths", "Fallen Angels", "False Promises", "False Prophets", "Fear", "Final Rests", "Fools", "Freedom", "Frozen Fires", "Frozen Lakes", "Glimmering Hope", "Glorious Conquests", "Gold", "Hallow Hill", "Heaven", "Hell", "Heroes", "High Tide", "Horrors", "Ignorance", "Imbalance", "Impending Doom", "Independence", "Insanity", "Integrity", "Iron", "Ivory", "Justice", "Kings Betrayal", "Kings Glory", "Kings Hill", "Kings Mountain", "Last Resorts", "Last Rites", "Liberty", "Lost Brothers", "Lost Faiths", "Lost Friends", "Lost Security", "Lost Sons", "Lost Souls", "Loyalties", "Lust", "Mad Bulls", "Mad Kings", "Mad Minds", "Maidens", "Mercy", "Naive Trust", "Nature", "Nature's Protectors", "New Allies", "New Hope", "New Orphans", "Nightmares", "Open Seas", "Pawns", "Pests", "Plagued Fires", "Poisoned Crops", "Poisoned Minds", "Purification", "Rats", "Red Waters", "Regrets", "Resources", "Scimitars", "Secrets", "Silence", "Smoking Homes", "Sons", "Spears", "Spies", "Starvation", "Steel", "Storms", "Strong Desires", "Tenacity", "Terror", "Titans", "Total Destruction", "Total Domination", "Treason", "Tribulation", "Trust", "Truth", "Tycoons", "Tyrants", "Unforseen Victory", "Unsung Heroes", "Utopia", "Vengeance", "Vile Actions", "Vile Men", "White Mountain", "Widow Makers", "Widows", "Wits", "the Ancestors", "the Apocalypse", "the Atlantic", "the Betrayed", "the Black Scar", "the Blood River", "the Broken Mountain", "the Burning Forest", "the Burning Sea", "the Chanceless", "the Curse", "the Dark", "the Dead Sea", "the Dieing Forest", "the Drained Sea", "the Dry Sea", "the Dunes", "the Eclipse", "the Endless Storm", "the Eternal Day", "the Eternal Night", "the Falling Sky", "the False King", "the False Prophet", "the Fiery Lake", "the Frozen Harbor", "the Frozen Ocean", "the High Seas", "the Homeless", "the Infested", "the Last Stand", "the Light", "the Molten Mountain", "the Night", "the Nomads", "the Occult", "the Oppressor", "the Peaks", "the People", "the Plague", "the Planet", "the Rebellion", "the Red Mountain", "the Retreating Ocean", "the Righteous", "the Risen", "the River Bank", "the Scorching Lands", "the Scourge", "the Shores", "the Towers", "the True King", "the True Prophet", "the Void"};
    static constexpr std::string_view names3[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view names4[] = {"a", "e", "i", "o", "u", "y", "a", "e", "i", "o", "u"};
    static constexpr std::string_view names5[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view names6[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view names7[] = {"b", "d", "g", "gh", "h", "hr", "hs", "ht", "hst", "hsh", "hn", "hm", "hl", "hz", "hx", "hq", "k", "ks", "kx", "l", "ll", "lk", "ln", "lm", "lz", "lp", "lt", "ls", "lst", "lf", "m", "mn", "mm", "mt", "ms", "n", "nn", "nt", "ns", "p", "ps", "pt", "ph", "q", "r", "rs", "rt", "rst", "rq", "rk", "rc", "rf", "rb", "rd", "s", "st", "ss", "sh", "sk", "sp", "t", "th", "ts", "w", "wth", "x", "z"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = names1[rnd] + " of " + names2[rnd2];
    } else if (i < 8) {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    rnd4 = rng() % std::size(names7);
    names = names1[rnd] + " of " + names3[rnd2] + names4[rnd3] + names7[rnd4];
    } else {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    rnd4 = rng() % std::size(names5);
    rnd5 = rng() % std::size(names6);
    rnd6 = rng() % std::size(names7);
    names = names1[rnd] + " of " + names3[rnd2] + names4[rnd3] + names5[rnd4] + names6[rnd5] + names7[rnd];
    }
    return names;
    }
}
