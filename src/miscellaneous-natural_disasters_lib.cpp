#include "miscellaneous-natural_disasters_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_natural_disasters_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"200 minute", "24 hour", "50 minute", "Abrupt", "Almighty", "Ambush", "Annihilation", "Blessed", "Blight", "Blocked", "Boosted", "Brief", "Carnage", "Cataclysmic", "Cleansing", "Collapsing", "Corrupting", "Crashing", "Deception", "Delayed", "Demolition", "Dire", "Directed", "Disrupted", "Dormant", "Double", "Early Morning", "Eclipse", "Elimination", "Endless", "Eradication", "Eternal", "Evaded", "Expiration", "Exploding", "Extermination", "Extinction", "Final", "Gentle", "Grave", "Grim Reaper", "Growing", "Harmless", "Idle", "Intended", "Interrupted", "Last Minute", "Lazy", "Life-giving", "Living", "Man-made", "Midnight", "Midsummer", "Midwinter", "Mighty", "Necrotic", "Nightmare", "Nonstop", "Noxious", "Obliteration", "Overlooked", "Persistent", "Positive", "Predicted", "Rapid", "Record", "Released", "Relentless", "Seven Day", "Shock", "Shrouded", "Silence", "Sleeping", "Sudden", "Supported", "Surreal", "Swift", "Tainted", "Tainting", "Tenacious", "Tense", "Thunder", "Total Destruction", "Toxic", "Triple", "Trivial", "Twilight", "Twin", "Unbound", "Unconstrained", "Unforeseen", "Unlimited", "Unnatural", "Unstoppable", "Veiled", "Vicious", "Void", "Weak", "Wreckage", "Wrecking"};
    static constexpr std::string_view names2[] = {"Hurricane", "Flood", "Tornado", "Eruption", "Avalanche", "Drought", "Hail Storm", "Blizzard", "Tsunami", "Wildfire", "Epidemic", "Cyclone", "Heat Wave", "Solar Flare"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(names1);
    rnd2 = rng() % std::size(names2);
    names = "The " + names1[rnd] + " " + names2[rnd2];
    return names;
    }
}
