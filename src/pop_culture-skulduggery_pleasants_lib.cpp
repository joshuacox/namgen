#include "pop_culture-skulduggery_pleasants_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pop_culture_skulduggery_pleasants_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aberrant", "Arbor", "Arch", "Archer", "Argent", "Art", "Ash", "Bane", "Barb", "Barbarous", "Barren", "Behemoth", "Bellow", "Berserk", "Birch", "Blade", "Blaze", "Booth", "Brawl", "Brawn", "Brick", "Brook", "Brutus", "Buster", "Cane", "Carnage", "Carter", "Chance", "Chaos", "Chase", "Chuck", "Cipher", "Cliff", "Clout", "Coal", "Copper", "Cosmo", "Coy", "Crimson", "Curse", "Daemon", "Dale", "Darth", "Dirk", "Dolor", "Drake", "Duke", "Dune", "Dusty", "Echo", "Edge", "Fiend", "Fink", "Flare", "Flint", "Forest", "Frank", "Furor", "Gale", "Gall", "Gallant", "Garotte", "Ghoul", "Giddy", "Glint", "Gloom", "Glum", "Grant", "Grim", "Grisly", "Grit", "Grog", "Grub", "Guillotine", "Haggard", "Hallow", "Harm", "Havoc", "Hazard", "Hog", "Honor", "Hunter", "Insidious", "Ire", "Jack", "Jasper", "Jet", "Jimmy", "Jinx", "Junior", "Justice", "Kindle", "Kirk", "Knave", "Kris", "Lament", "Lance", "Lore", "Lynx", "Lyric", "Magnum", "Mane", "Mark", "Mars", "Maverick", "Max", "Maze", "Meddle", "Menace", "Miles", "Morrow", "Mortar", "Morte", "Nick", "Norm", "Obsidian", "Ocean", "Omen", "Onyx", "Page", "Pale", "Paragon", "Parker", "Parrish", "Pester", "Phoenix", "Picket", "Proffer", "Putrid", "Pyre", "Quell", "Quill", "Rage", "Ray", "Raze", "Rebel", "Red", "Requiem", "Riot", "River", "Rob", "Rock", "Rod", "Rogue", "Ruckus", "Ruffian", "Rum", "Rusty", "Saber", "Sable", "Sage", "Sane", "Savage", "Scalawag", "Scourge", "Severus", "Shade", "Sinew", "Slate", "Slick", "Slug", "Sly", "Snarl", "Snitch", "Spark", "Spectre", "Stain", "Sterling", "Storm", "Stout", "Strife", "Sullen", "Sully", "Talon", "Tax", "Taylor", "Teal", "Tenor", "Thorn", "Torpid", "Trinket", "Tuck", "Tucker", "Vain", "Venom", "Venture", "Verve", "Vex", "Victor", "Vigor", "Wicked", "Will", "Wily", "Woe", "Wolf", "Wrath", "Wright", "Zeal", "Zero", "Zilch"};
    static constexpr std::string_view nm2[] = {"Affinity", "Agate", "Agony", "Alma", "Amber", "Angel", "Anima", "Answer", "Apathy", "Apple", "Aria", "Ash", "Atrophy", "August", "Aura", "Aurora", "Autumn", "Banshee", "Blaze", "Blemish", "Blight", "Bliss", "Blithe", "Blitz", "Bonnie", "Breeze", "Brook", "Cadence", "Caprice", "Carmine", "Carol", "Cat", "Cerise", "Chance", "Charity", "Chastity", "Chimera", "Cicatrix", "Cinnamon", "Claret", "Clover", "Coral", "Cosmo", "Crystal", "Cynthia", "Dahlia", "Daphne", "Darling", "Dawn", "Desire", "Destiny", "Dew", "Diamond", "Distress", "Dolorous", "Drew", "Ebony", "Echo", "Ember", "Empathy", "Enigma", "Ennui", "Erica", "Erin", "Euphoria", "Eve", "Faith", "Fatality", "Fawn", "Feather", "Felicity", "Fern", "Fever", "Flare", "Flora", "Gem", "Ginger", "Goldie", "Grace", "Grief", "Hail", "Harmony", "Hazel", "Heirloom", "Holly", "Hope", "Indigo", "Iris", "Isle", "Ivory", "Ivy", "Jade", "Jasmine", "Jeopardy", "Jewel", "Joy", "June", "Juniper", "Karma", "Kat", "Kelpie", "Kitty", "Laurel", "Legacy", "Liberty", "Lily", "Lullaby", "Luna", "Lyric", "Mae", "Magnolia", "Magpie", "Malady", "Malaise", "Melody", "Merry", "Mettle", "Mirage", "Mirth", "Misery", "Misty", "Morgana", "Muse", "Mystery", "Novelty", "Oceane", "Olive", "Onyx", "Opal", "Oracle", "Page", "Paige", "Paradox", "Parody", "Patience", "Pearl", "Penny", "Penury", "Pepper", "Peril", "Phoenix", "Pixie", "Psyche", "Pyre", "Raine", "Rarity", "Raven", "Ravish", "Riddle", "River", "Rose", "Rosemary", "Ruby", "Rune", "Ruth", "Sable", "Saffron", "Sage", "Sapphire", "Saturninity", "Scarlet", "Scout", "Serenity", "Serpente", "Shade", "Shenanigan", "Sierra", "Sky", "Skye", "Soots", "Sorrow", "Spectacle", "Sphinx", "Spirit", "Stigma", "Storm", "Summer", "Sybil", "Tawny", "Teal", "Tempest", "Thorne", "Thriller", "Tinder", "Tragedy", "Trinity", "Trinket", "Twilight", "Velleity", "Velvet", "Venus", "Vex", "Vice", "Violet", "Viper", "Volley", "Willow", "Winter", "Woe", "Wraith"};
    static constexpr std::string_view nm3[] = {"Ache", "Adroit", "Alabaster", "Alias", "Amity", "Anchor", "Angel", "Anguish", "Anomaly", "Arete", "Argent", "Armor", "Arrow", "Ash", "Askew", "Asset", "Awry", "Ballad", "Ballaster", "Bard", "Bargain", "Baron", "Barrow", "Battle", "Beacon", "Beggar", "Belch", "Belcher", "Bellow", "Binder", "Black", "Blade", "Blank", "Blood", "Bloodworth", "Bolt", "Bond", "Bones", "Boon", "Boor", "Boulder", "Bounty", "Bovine", "Brand", "Brawn", "Broke", "Bruiser", "Bullet", "Burden", "Burn", "Burrow", "Butler", "Buzzard", "Cairn", "Caliber", "Calibre", "Candor", "Cane", "Carver", "Cash", "Castle", "Chalice", "Champion", "Chance", "Chase", "Chosen", "Cite", "Clay", "Cloud", "Cole", "Conceit", "Couture", "Cove", "Craft", "Crass", "Crimson", "Cross", "Crumb", "Crypt", "Demise", "Destiny", "Diablo", "Dolor", "Doom", "Drake", "Dread", "Eliminate", "Epitome", "Fable", "Fade", "Fang", "Fatality", "Festoon", "Fletcher", "Fortune", "Foster", "Frost", "Gamble", "Garland", "Glass", "Gold", "Grave", "Graves", "Gripe", "Grove", "Grumble", "Halo", "Harsh", "Heart", "Heaven", "Heirloom", "Hook", "Horn", "Howler", "Humble", "Hunt", "Incognito", "Jinx", "Lament", "Largesse", "Legacy", "Lexicon", "Luck", "Memento", "Mercy", "Merit", "Mock", "Mondo", "Mourn", "Mute", "Mystery", "Myth", "Nemesis", "Nemo", "Nova", "Noxious", "Oblivion", "Obscure", "Occult", "Omnibus", "Pain", "Paradox", "Patience", "Pierce", "Price", "Quest", "Rapture", "Razor", "Remedy", "Remorse", "Repose", "Reserve", "Reverse", "Riddle", "Rube", "Rue", "Ruth", "Sanguine", "Scope", "Secret", "Serpent", "Shade", "Shields", "Silence", "Silver", "Sin", "Skinner", "Snow", "Stitch", "Stone", "Storm", "Strait", "Sulk", "Swagger", "Swift", "Sythe", "Terminal", "Token", "Tomb", "Torment", "Trace", "Trinket", "Triumph", "Truth", "Twist", "Unity", "Vaunt", "Veil", "Vermin", "Vigil", "Vile", "Virtue", "Vista", "Ward", "Whisper", "White", "Woods", "Worth", "Wretch", "Zephyr"};
    static constexpr std::string_view nm4[] = {"", "", "", "", "b", "ch", "d", "g", "h", "l", "m", "n", "ph", "r", "s", "sh", "t", "th", "tr", "v", "z"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ue", "au", "io", "ia", "ie", "ei", "ai"};
    static constexpr std::string_view nm6[] = {"d", "dd", "dr", "ff", "fr", "g", "gr", "gn", "gm", "k", "kk", "kn", "l", "ll", "ln", "lm", "m", "mm", "mr", "n", "nn", "nr", "nd", "nv", "nt", "ph", "rk", "rg", "rq", "rv", "rf", "rb", "rd", "rl", "rm", "s", "ss", "sh", "sl", "sr", "sn", "st", "t", "th", "tr", "v", "vr", "d", "d", "g", "g", "k", "k", "l", "l", "l", "m", "m", "n", "n", "s", "s", "t", "t", "v", "v"};
    static constexpr std::string_view nm7[] = {"", "", "l", "n", "s", "th"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    if (type == 2) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    rnd4 = rng() % std::size(nm5);
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm5);
    rnd7 = rng() % std::size(nm7);
    names = nm4[rnd] + nm5[rnd2] + nm6[rnd3] + nm5[rnd4] + nm6[rnd5] + nm5[rnd6] + nm7[rnd7];
    } else if (type == 1) {
    rnd = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm3);
    while (nm2[rnd] == nm3[rnd2]) {
    rnd = rng() % std::size(nm2);
    }
    names = nm2[rnd] + " " + nm3[rnd2];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm3);
    while (nm1[rnd] == nm3[rnd2]) {
    rnd = rng() % std::size(nm1);
    }
    names = nm1[rnd] + " " + nm3[rnd2];
    }
    return names;
    }
}
