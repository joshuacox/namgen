#include "miscellaneous-post_apocalyptic_societys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_post_apocalyptic_societys_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Abandoned", "Aberration", "Abnormality", "Abomination", "Acid", "Acidic", "Acrid", "Amnesia", "Anomaly", "Armageddon", "Asylum", "Babylon", "Black Ashes", "Black Dust", "Black Earth", "Black Moon", "Black Rain", "Black Sun", "Blessed", "Burning World", "Cataclysm", "Chaos", "Cockroach", "Decimation", "Desolate", "Deviant", "Dominance", "Eclipse", "Ember", "Enigma", "Eternal", "Eternal Darkness", "Eternal Eclipse", "Eternal Fire", "Eternal Void", "Evolution", "Extinction", "Fallen Star", "Fallout", "False Prophet", "Forsaken", "Found Fortune", "Gifts of Mutation", "Godless", "Honor", "Honorbound", "Human Expiration", "Human Extinction", "Human Hunter", "Isolation", "Law Abiding", "Lawless", "Legion", "Limbo", "Lost Soul", "Martial Law", "Metamorphosis", "Miracle", "Misery", "Monster", "Monster Hunter", "Mutant", "Mutant Hunter", "Myriad", "Neo-Human", "New Friends", "New God", "New Haven", "New Hope", "New Law", "New Monster", "New Moon", "New Prophet", "New Start", "New Sun", "New Supremacy", "New World", "No Legacy", "Nuclear", "Oath", "Oblivion", "Old Ruins", "Orphan", "Our Legacy", "Outcast", "Paragon", "Phoenix", "Prodigy", "Rebirth", "Red Moon", "Red Sun", "Reincarnation", "Resurrection", "Revelation", "Risen Ashes", "Sanctuary", "Survivor", "Total Eclipse", "Traitor", "Warhead"};
    static constexpr std::string_view names2[] = {"Alliance", "Association", "Brotherhood", "Clan", "Coalition", "Confederacy", "Cooperative", "Federation", "Gang", "League", "Order", "Republic", "Syndicate", "Tribe", "Nation", "Union"};
    static constexpr std::string_view names3[] = {"Abandoned", "Aberrations", "Abnormalities", "Invincible", "Abominations", "Anomalies", "Armageddons", "Asylum", "Babylonians", "Black Ashes", "Blessed", "Chosen Ones", "Cleansed", "Cockroaches", "Dead", "Defiance", "Deviants", "Droplets", "Enigmas", "Eternals", "Evolved", "Expired", "Extinct", "Fallen", "Flock", "Forsaken", "Freaks", "Giants", "Gifted", "Godless", "Hermits", "Hidden", "Homeless", "Honorbound", "Honorless", "Horned Ones", "Immune", "Impure", "Infected", "Invisible", "Law", "Lawless", "Legion", "Living", "Lost Ones", "Lost Souls", "Miracles", "Monsters", "Mutants", "Myriad", "Neo-Human", "New Friends", "New Humans", "New Monsters", "Newmans", "Orphans", "Outcasts", "Paragons", "Phantoms", "Phoenixes", "Prodigies", "Pure", "Purified", "Rats", "Reincarnated", "Resurrected", "Risen", "Roaches", "Salvation", "Shadows", "Stalkers", "Survivors", "Tails", "Tormented", "Vanished", "Walkers", "Warheads", "White Ashes"};

    std::string names; size_t rnd = 0; size_t rnd1 = 0; int i = 0;

i = rng() % 10; {
    if (i < 5) {
    rnd = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    names = names1[rnd] + " " + names2[rnd1];
    } else {
    rnd = rng() % std::size(names3);
    names = "The " + names3[rnd];
    }
    return names;
    }
}
