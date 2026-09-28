#include "miscellaneous-currencys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_currencys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"b", "br", "bl", "c", "cl", "cr", "d", "dr", "f", "fr", "fl", "g", "gr", "gl", "gn", "h", "j", "k", "kr", "kl", "kn", "m", "n", "p", "pr", "pl", "q", "qr", "ql", "r", "s", "st", "sr", "str", "sl", "t", "tr", "tl", "v", "vl", "vr", "w", "wr", "x", "z", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "o", "u", "y"};
    static constexpr std::string_view nm3[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z", "", "", "", "", "", ""};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "", "", "", ""};
    static constexpr std::string_view nm5[] = {"boa", "c", "cha", "ching", "de", "der", "ding", "do", "doba", "fa", "geni", "ham", "k", "kel", "la", "lar", "le", "ling", "moni", "na", "nar", "nat", "ne", "nea", "ni", "nia", "ning", "pee", "pi", "pia", "pira", "ra", "ram", "rani", "ri", "rin", "rint", "ro", "runa", "sar", "si", "so", "taca", "tas", "tos", "ty", "ya", "za", "zal"};
    static constexpr std::string_view nm6[] = {"Alliance", "Allied", "Amber", "Ancestral", "Black", "Blood", "Bloodbound", "Blue", "Bronze", "Castle", "Celestial", "Chrono", "Coalition", "Commonwealth", "Confederate", "Constellation", "Copper", "Crescent", "Crimson", "Crown", "Crystal", "Diamond", "Division", "Dominion", "Dwarven", "Earth", "Earthian", "Electric", "Elemental", "Elvish", "Emerald", "Emperor", "Empire", "Ethereal", "Federal", "Free World", "Freedom", "Galactic", "Ghost", "Glory", "Gnomish", "Gold", "Golden", "Gothic", "Honor", "Intergalactic", "Interstellar", "Jade", "King's", "Lunar", "Mystic", "New", "New Earth", "New Order", "Obsidian", "Orcish", "Phantom", "Phoenix", "Platinum", "Presidential", "Raven", "Republic", "Royal", "Sanguine", "Serpent", "Silver", "Solar", "Sovereign", "Space", "Spectral", "Supremacy", "Syndicate", "Tin", "Trade Federation", "Trader's", "Tribe", "Union", "Utopian", "Virtual", "White", "World League's", "World Union"};
    static constexpr std::string_view nm7[] = {"Air Coins", "Air Dollars", "Behavior Credits", "Belt Buckles", "Bits", "Black Gold", "Black Pennies", "Blings", "Blossoms", "Blue Orbs", "Bolts", "Bottle Caps", "Buckles", "Bullets", "Chips", "Chronocoins", "Chronocredits", "Chronodollars", "Chronos", "Chronus", "Claws", "Coins", "Constellation Coins", "Constellation Gold", "Constellatoin Credits", "Copper", "Credits", "Creds", "Crescents", "Crowns", "Crystals", "Cubes", "Cuts", "Diamonds", "Dominions", "Eagle Eyes", "Earth Coins", "Earthians", "Emeralds", "Empire Gold", "Eyes", "Feathers", "Federal Credits", "Federal Gold", "Free World Coins", "Free World Credits", "Freedom Credits", "Galactic Coins", "Galactic Credit", "Galactic Gold", "Gems", "Gold", "Gold Coins", "Gold Crowns", "Gold Pieces", "Golden Pennies", "Grains", "Influence Points", "Intergalactic Coins", "Intergalactic Gold", "Interstellar Credits", "Interstellar Gold", "Jewels", "Marks", "Nectar", "New Coins", "New Dollars", "New Earth Coins", "New Earth Credit", "New Earths", "New Order Credit", "Novas", "Orbs", "Pebbles", "Pennies", "Petals", "Platinum", "Quills", "Raven Claws", "Republic Dollars", "Rubies", "Seeds", "Shells", "Shinies", "Silver", "Silver Eyes", "Silver Pieces", "Solars", "Souls", "Space Bucks", "Space Dollars", "Space Gold", "Sparkles", "Talons", "Teeth", "Tokens", "Utopis", "White Gold", "White Orbs", "Widgets"};
    static constexpr std::string_view nm8[] = {"Alliance", "Allied", "Ancestral", "Astral", "Black", "Blood", "Bloodbound", "Blue", "Castle", "Celestial", "Chrono", "Coalition", "Commonwealth", "Confederate", "Constellation", "Crescent", "Crimson", "Crown", "Division", "Dominion", "Dragon", "Dwarven", "Earth", "Earthian", "Electric", "Elemental", "Elvish", "Emperor", "Empire", "Ethereal", "Federal", "Forest", "Free World", "Freedom", "Galactic", "Ghost", "Glory", "Gnomish", "Gothic", "Honor", "Intergalactic", "Interstellar", "King's", "Lion", "Lionheart", "Lunar", "Mountain", "Mystic", "New", "New Earth", "New Order", "Nova", "Obsidian", "Ocean", "Orcish", "Phantom", "Phoenix", "Presidential", "Raven", "Republic", "River", "Royal", "Sanguine", "Sea", "Seafarer", "Serpent", "Solar", "Sovereign", "Space", "Spectral", "Supremacy", "Syndicate", "Trade Federation", "Trader's", "Tribe", "Union", "Utopian", "Virtual", "Volcanic", "White", "World League's", "World Union"};
    static constexpr std::string_view nm9[] = {"Cash", "Chips", "Coins", "Coins", "Copper", "Copper", "Credits", "Credits", "Dime", "Dime", "Dollars", "Doubloons", "Gold", "Gold", "Pennies", "Pieces", "Silver", "Silver", "Tender", "Tokens"};
    static constexpr std::string_view nm10[] = {"Abazi", "Apsar", "Aureus", "Austral", "Balboa", "Birr", "Cedi", "Dalasi", "Daler", "Daric", "Denarius", "Dinar", "Dobra", "Dollar", "Drachma", "Dram", "Ducat", "Ekwele", "Elymais", "Escudo", "Euro", "Florin", "Follis", "Franc", "Gourde", "Guarani", "Guilder", "Hekte", "Hwan", "Inti", "Keping", "Kina", "Koruna", "Krone", "Kuna", "Kwacha", "Kwanza", "Kyat", "Lari", "Lempira", "Leone", "Leu", "Lev", "Lilangeni", "Lira", "Litas", "Loti", "Manat", "Mark", "Metica", "Mon", "Nakfa", "Pataca", "Peseta", "Peso", "Pound", "Prutah", "Pula", "Qirsh", "Quetzal", "Rand", "Real", "Rial", "Riel", "Ringgit", "Riyal", "Ruble", "Rufiyaa", "Rupee", "Rupiah", "Shekel", "Sheqel", "Shilling", "Sigloi", "Sol", "Solidus", "Som", "Somoni", "Stater", "Syli", "Tael", "Taka", "Talent", "Tenge", "Tolar", "Tremissis", "Trite", "Vatu", "Won", "Xu", "Yen", "Yuan", "Zaire", "Zuz"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    if (i < 2) {
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    } else {
    rnd6 = rng() % std::size(nm6);
    names = nm6[rnd6] + " " + nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + nm5[rnd5];
    }
    } else if (i < 6) {
    rnd = rng() % std::size(nm7);
    names = nm7[rnd];
    } else if (i < 8) {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm9);
    names = nm8[rnd] + " " + nm9[rnd2];
    } else {
    rnd = rng() % std::size(nm8);
    rnd2 = rng() % std::size(nm10);
    names = nm8[rnd] + " " + nm10[rnd2];
    }
    return names;
    }
}
