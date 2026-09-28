#include "miscellaneous-gangs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_gangs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"azure", "black", "blue", "brass", "bronze", "brown", "cardinal", "cobalt", "copper", "crimson", "crystal", "demon", "denim", "diamond", "ebony", "electric", "emerald", "fire", "flame", "gold", "green", "grey", "grizzly", "ice", "ivory", "jade", "onyx", "orange", "red", "royal", "ruby", "sanguine", "sapphire", "scarlet", "thunder", "violet", "white", "yellow", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view nm2[] = {"alien", "alligator", "angel", "badger", "banner", "bat", "bear", "blood", "blooddrop", "blossom", "boar", "bull", "bulldog", "butterfly", "chainsaw", "cobra", "coyote", "crocodile", "cross", "crow", "death", "demon", "devil", "dragon", "dragonfly", "dragontooth", "dwarf", "eagle", "elephant", "enigma", "fang", "forsaken", "ghost", "gorilla", "hand", "hog", "honey badger", "horn", "jackal", "knife", "knuckle", "leopard", "lily", "lion", "liontooth", "mamba", "mammoth", "monkey", "moth", "needle", "owl", "phantom", "pygmy", "pincer", "pistol", "rat", "raven", "ravenclaw", "razor", "reaper", "rebel", "rider", "rose", "saber", "sabortooth", "serpent", "shark", "sharkfin", "sharktooth", "skeleton", "skull", "snake", "spider", "sword", "tear", "thorn", "tiger", "toad", "troll", "undead", "viper", "vulture", "warthog", "water", "wolf", "wolverine"};
    static constexpr std::string_view nm3[] = {"aliens", "alligators", "angels", "badgers", "bats", "bears", "blooddrops", "bloods", "blossoms", "boars", "bulldogs", "bulls", "butterflies", "chainsaws", "cobras", "coyotes", "crocs", "crosses", "crows", "demons", "devils", "dragonflies", "dragons", "dwarves", "eagles", "elephants", "enigmas", "fangs", "forsaken", "ghosts", "gorillas", "growlers", "hogs", "honey badgers", "horns", "jackals", "knives", "knuckles", "leopards", "lilies", "lions", "mambas", "mammoths", "monkeys", "moths", "needles", "owls", "phantoms", "pigmies", "pillagers", "pincers", "pistols", "plunderers", "rats", "ravenclaws", "ravens", "razors", "reapers", "rebels", "riders", "roses", "sabors", "seals", "serpents", "sharkfins", "sharks", "sharkteeth", "skeletons", "skulls", "slicers", "snakes", "spiders", "swords", "takers", "tears", "thorns", "tigers", "toads", "trolls", "undead", "vipers", "vultures", "warthogs", "wolverines", "wolves"};
    static constexpr std::string_view nm4[] = {"association", "band", "brotherhood", "clan", "company", "crew", "gang", "posse", "riders", "soldiers", "squad", "syndicate", "tribe"};
    static constexpr std::string_view nm5[] = {"abandoned", "anarchists", "anonymous", "chargers", "damnation", "day walkers", "dead eyes", "destroyers", "disciples", "doom bringers", "dreamers", "liberated", "liberation front", "empty eyes", "eternals", "faceless ones", "fallen angels", "forsaken", "grim reapers", "hopeless", "hopeless ones", "hunters", "idealists", "immortals", "invincibles", "invisibles", "kings", "life takers", "loners", "men of limbo", "men of the night", "women of limbo", "women of the night", "mob", "nameless", "night stalkers", "poison ivies", "purgatory", "ravagers", "risen demons", "salvation", "shadows", "silence", "silent death", "silent footsteps", "soul stealers", "soulless ones", "united front", "unseen", "untamed", "voiceless ones", "void", "whisperers", "wild ones", "wildlings"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd0 = rng() % std::size(nm1);
    rnd1 = rng() % std::size(nm2);
    rnd2 = rng() % std::size(nm4);
    names = "The " + nm1[rnd0] + " " + nm2[rnd1] + " " + nm4[rnd2];
    } else if (i < 8) {
    rnd0 = rng() % std::size(nm1);
    rnd1 = rng() % std::size(nm3);
    names = "The " + nm1[rnd0] + " " + nm3[rnd1];
    } else {
    rnd0 = rng() % std::size(nm5);
    names = "The " + nm5[rnd0];
    }
    return names;
    }
}
