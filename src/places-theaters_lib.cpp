#include "places-theaters_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_places_theaters_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Academy", "Aeon", "Alliance", "Ambassador", "Ambition", "Ancestral", "Angel", "Animus", "Apex", "Apollo", "Apple Blossom", "Arcane", "Arts", "Aura", "Aurora", "Bamboo", "Beacon", "Bellevue", "Bluebell", "Borealis", "Boulevard", "Capital", "Carnival", "Casino", "Castle", "Celeste", "Celestial", "Century", "Cerberus", "Cherry Blossom", "Chimera", "Citadel", "Classic", "Climax", "Cosmos", "Courtyard", "Crescent", "Crown", "Crystal", "Curator", "Daydream", "Delight", "Desire", "Diamond", "Dominion", "Downtown", "Dreamland", "Eclipse", "Ecstasy", "Eden", "Ellipse", "Emerald", "Eminence", "Empire", "Enigma", "Epoch", "Eternity", "Euphony", "Exalted", "Fantasia", "Fantasy", "Festival", "Figment", "Firefly", "Flux", "Fortune", "Frontier", "Galaxy", "Gilded", "Globe", "Golden Gate", "Grand", "Grand Avenue", "Grand Centre", "Grand Chateau", "Grand Fountain", "Grand Guild", "Grand Palace", "Grand Park", "Grand River", "Grand Shrine", "Grandeur", "Grandview", "Guardian", "Harmony", "Heirloom", "Heritage", "Hippogriff", "Illusion", "Image", "Imagination", "Imagine", "Imperial", "Infinity", "Jupiter", "King's", "Landmark", "Legacy", "Legend", "Lilypad", "Limelight", "Lionheart", "Little", "Lumina", "Luminous", "Luminus", "Lunar", "Magic Lantern", "Magister", "Majesty", "Major", "Mammoth", "Melody", "Mercury", "Meridian", "Millennium", "Mirage", "Monolith", "Monument", "Moonlight", "Mystery", "Nebula", "Nightingale", "Obelisk", "Obsidian", "Onyx", "Oracle", "Orbit", "Orion", "Ornate", "Paradise", "Paragon", "Paramount", "Paramour", "Patriot", "Pavilion", "Peacock", "Phenomenon", "Phoenix", "Pilgrim", "Pinnacle", "Pioneer", "Platinum", "Pluto", "Prestige", "Prime", "Prism", "Prodigy", "Pyramid", "Radiance", "Rainbow", "Regal", "Resonance", "Rhinestone", "Rose Petal", "Rosebud", "Royal", "Royal Court", "Royal Hall", "Sapphire", "Serenity", "Silverlight", "Snowflake", "Solar", "Solaris", "Solstice", "Songbird", "Spectacle", "Spirit", "Spotlight", "Spring Garden", "Sprite", "Stargaze", "Starlight", "Stellar", "Summer Garden", "Summit", "Sunset", "Supremacy", "Swanlake", "Talisman", "Independence", "Temple", "Tiara", "Titan", "Tranquility", "Transcendence", "Treasure", "Trinity", "Twilight", "Unison", "Universe", "Uptown", "Utopia", "Valentine", "Vanilla Flower", "Velvet", "Vertex", "Victory", "Vintage", "Virtue", "Vision", "Vortex", "Warden", "Watchtower", "White Flare", "White Orchid", "Zion"};
    static constexpr std::string_view nm2[] = {"Theater", "Opera House", "Cinema", "Assembly Hall", "Amphitheater", "Concert Hall", "Theatre"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = "The " + nm1[rnd] + " " + nm2[rnd2];
    return names;
    }
}
