#include "fantasy-werewolf_packs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_werewolf_packs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Ambersky", "Arctic", "Ash", "Bane", "Barbaric", "Black", "Bloodlust", "Bloodrose", "Bloodvenom", "Blue", "Broken", "Brown", "Brutal", "Calm", "Crescent", "Crimson", "Cruel", "Dark", "Dawn", "Dawnfall", "Dawnguard", "Dessert", "Dusk", "Duskfall", "Evening", "Feral", "Ferocious", "Fierce", "Golden", "Grey", "Hollow", "Imperial", "Kind", "Lichen", "Lightning", "Lost", "Lunar", "Lupine", "Lycan", "Midnight", "Morning", "Mountain", "Mystic", "Native", "Night", "Nightfall", "Nightshade", "Nightstar", "Primal", "Prime", "Raging", "Red", "Sanguis", "Savage", "Scarlet", "Scarred", "Sentinel", "Shadowed", "Silent", "Silver", "Silverback", "Solar", "Spirit", "Starry", "Sundown", "Sunset", "Thunder", "Tranquil", "Vanished", "Vengeful", "Vicious", "Whisper", "White", "Wild", "Moonlit", "Darkmoon", "Blue Moon", "Moonstone", "Bloodmoon", "Crescent Moon", "Moonvalley", "Full Moon", "Moon"};
    static constexpr std::string_view nm2[] = {"Ambersky", "Arctic", "Ash", "Bane", "Barbaric", "Black", "Bloodlust", "Bloodrose", "Bloodvenom", "Blue", "Broken", "Brown", "Brutal", "Calm", "Crescent", "Crimson", "Cruel", "Dark", "Dawn", "Dawnfall", "Dawnguard", "Dessert", "Dusk", "Duskfall", "Evening", "Feral", "Ferocious", "Fierce", "Golden", "Grey", "Hollow", "Imperial", "Kind", "Lichen", "Lightning", "Lost", "Lunar", "Lupine", "Lycan", "Midnight", "Morning", "Mountain", "Mystic", "Native", "Night", "Nightfall", "Nightshade", "Nightstar", "Primal", "Prime", "Raging", "Red", "Sanguis", "Savage", "Scarlet", "Scarred", "Sentinel", "Shadowed", "Silent", "Silver", "Silverback", "Solar", "Spirit", "Starry", "Sundown", "Sunset", "Thunder", "Tranquil", "Vanished", "Vengeful", "Vicious", "Whisper", "White", "Wild"};
    static constexpr std::string_view nm3[] = {"Alpha", "Angel", "Ash", "Beta", "Blood", "Burst", "Canine", "Canis", "Cave", "Creek", "Crows", "Darkness", "Delta", "Depths", "Dream", "Eclipse", "Edge", "Eye", "Eyed", "Eyes", "Feather", "Fire", "Forest", "Gloom", "Grin", "Heart", "Hill", "Ice", "Lake", "Light", "Lupis", "Oak", "Oasis", "Omega", "Peak", "Pride", "Raven", "River", "Rock", "Rufus", "Shadow", "Silence", "Sky", "Snow", "Star", "Stars", "Stealth", "Summit", "Tail", "Thunder", "Timber", "Tooth", "Valley", "Venture", "Water", "Woodland"};
    static constexpr std::string_view nm4[] = {"Alpha", "Angel", "Ash", "Beta", "Blood", "Burst", "Canine", "Canis", "Cave", "Creek", "Crows", "Darkness", "Delta", "Depths", "Dream", "Eclipse", "Edge", "Eye", "Eyed", "Eyes", "Feather", "Fire", "Forest", "Gloom", "Grin", "Heart", "Hill", "Ice", "Lake", "Light", "Lupis", "Moon", "Oak", "Oasis", "Omega", "Peak", "Pride", "Raven", "River", "Rock", "Rufus", "Shadow", "Silence", "Sky", "Snow", "Star", "Stars", "Stealth", "Summit", "Tail", "Thunder", "Timber", "Tooth", "Valley", "Venture", "Water", "Woodland"};
    static constexpr std::string_view nm5[] = {"Banes", "Canines", "Claws", "Furs", "Growlers", "Guardians", "Hounds", "Howlers", "Hunters", "Keepers", "Manes", "Nightstalkers", "Nightwalkers", "Prowlers", "Shadows", "Stalkers", "Walkers", "Warriors"};

    std::string names; size_t rnd = 0; size_t rnd3 = 0; int i = 0;

i = rng() % 10; {
    if (i < 4) {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm4);
    names = nm1[rnd] + " " + nm4[rnd3] + " Pack";
    } else if (i < 8) {
    rnd = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    names = nm2[rnd] + " " + nm3[rnd3] + " Pack";
    } else {
    rnd = rng() % std::size(nm1);
    rnd3 = rng() % std::size(nm5);
    names = "The " + nm1[rnd] + " " + nm5[rnd3];
    }
    return names;
    }
}
