#include "fantasy-vampire_clans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_vampire_clans_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Abyss", "Annihilation", "Banished", "Bite", "Black", "Blood", "Blood's", "Crypt's", "Dark", "Death", "Death's", "Demise's", "Demon", "Demonic", "Devil", "Devil's", "Dishonored", "Downfall", "Dusk's", "End's", "Enigma", "Eternal", "Fanged", "Ghoul", "Grave", "Heaven's", "Hell's", "Immortal", "Limbo's", "Lucifer's", "Midnight", "Misery's", "Moonlight", "Necrosis", "Nether", "Night", "Night's", "Nightmare", "Nightshade", "Onyx", "Perpetual", "Phantom", "Purgatory's", "Sanguine", "Shadow", "Shadow's", "Tempest", "Tomb", "Tormented", "Undying", "Unending", "Wicked"};
    static constexpr std::string_view nm2[] = {"Ancestors", "Ancestry", "Army", "Birth", "Brigade", "Castaways", "Company", "Coven", "Covet", "Craving", "Crawlers", "Defilers", "Descendants", "Descent", "Desire", "Division", "Dragons", "Eclipe", "Exiles", "Fiends", "Flight", "Flyers", "Gaze", "Gift", "Hearts", "Horde", "Hunger", "Insomniacs", "Leeches", "Legion", "Longing", "Lurkers", "Lust", "Marauders", "Mark", "Marks", "Myriad", "Nomads", "Oblivion", "Origin", "Outcasts", "Outlaws", "Phalanx", "Posse", "Quenchers", "Raiders", "Refugees", "Rejects", "Restless", "Rogues", "Runners", "Seekers", "Shadow", "Shadows", "Shroud", "Sundry", "Swarm", "Teeth", "Thirst", "Torment", "Void", "Wanderers", "Watch", "Wings"};
    static constexpr std::string_view nm3[] = {"Bite Mark", "Black Knights", "Blood Bankers", "Blood Infusion", "Bloodbound", "Bloodworth", "Carpe Noctem", "Children of the Night", "Citizens of Darkness", "Dark Heaven", "Dark Omen", "Demonix", "Denizens of Darkness", "Diluculum", "Fighters of the Fang", "House of the Bat", "House of the Night", "House of the Phoenix", "Insomniacs", "Lamia", "Masquerade", "Mediis Tenebris", "Midnight Terror", "Neck Romancers", "Night Dwellers", "Night Spawns", "Night's Harmony", "Nightmare Association", "Nightshades", "Nightworth", "Noctis", "Nox", "Purebloods", "Red Night", "Sanguine Ligurio", "Sanguinity", "Sanguinoso", "Silver Coven", "Solar Eclipse", "Tantibus", "The Ashes", "The Brood", "The Flock", "The Gauntlet", "The Mist", "The Sabbat", "The Scarlet Kiss", "The Unaligned", "The Will", "Total Eclipse", "Visio Aeternae", "Youngbloods"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    if (i < 8) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    } else {
    rnd = rng() % std::size(nm3);
    names = nm3[rnd];
    }
    return names;
    }
}
