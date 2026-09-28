#include "miscellaneous-softwares_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_softwares_name(std::mt19937& rng) {
    static constexpr std::string_view nm2[] = {"", "", "", "", "", "", "", "", "", "", "", "", " Advanced", " Base", " Basic", " Engine", " Language", " Pro", " Script", " System", "#", "+", "++", "-2", "-3", "Base", "Code", "Edge", "Pro", "Script", "X"};
    static constexpr std::string_view nm1[] = {"Abra", "Ace", "Aer", "Agent", "Ample", "Ape", "Asap", "Ash", "Aspect", "Asset", "Aura", "Aurora", "Beacon", "Beat", "Bindle", "Blithe", "Blossom", "Boop", "Borealis", "Bundle", "Cell", "Chant", "Chasm", "Chime", "Cinch", "Cloud", "Clout", "Cluster", "Clutch", "Cobolt", "Combi", "Core", "Cozy", "Crux", "Curator", "Cure", "Curio", "Curious", "Dawn", "Digi", "Ditto", "Ditty", "Divi", "Djinni", "Dodge", "Domino", "Dozer", "Dragoon", "Drake", "Echo", "Effigy", "Efflux", "Ego", "Elementary", "Ellipse", "Ember", "Emblem", "Entity", "Ether", "Ex.", "Fig", "Flare", "Fleet", "Flex", "Flix", "Float", "Flow", "Fluo", "Fuse", "Galore", "GameOn", "Gem", "Geode", "Gig", "Gist", "Glint", "Gloss", "Glow", "Groove", "Guise", "Hellion", "Hex", "Hiero", "Hustle", "Ideo", "ImAge", "Imp", "Imput", "Influx", "Iris", "Jade", "Jewel", "Jinx", "Jive", "Kazam", "Knock", "Lax", "Limbo", "Lithe", "Lode", "Lumos", "Lure", "Melody", "Mic", "Mime", "Mini", "Minmax", "Mirage", "Mirror", "Mist", "Mix", "Mobius", "Moxie", "Mumbo", "Myth", "Neo", "Neon", "Nimbus", "Notch", "Obsidian", "Oculus", "Odd", "Ode", "Onyx", "Opt", "Optic", "Oracle", "Orbit", "Paltry", "Para", "Paragon", "Parcel", "Parry", "Particle", "Patter", "Petal", "Pickle", "Picnic", "Picolo", "Pinnacle", "Pitch", "Pivot", "Pose", "Precious", "Prism", "Pronto", "Prospect", "Pulse", "Query", "Rascal", "Rebus", "Reflect", "Reverb", "Ripple", "Rune", "Rush", "Sabre", "Sapphire", "Scale", "Scoop", "Segue", "Semble", "Shift", "Slang", "Slice", "Slick", "Sliver", "Smooth", "Snap", "Soar", "Sonic", "Spark", "Sparkle", "Speckle", "Sphinx", "Spirit", "Splice", "Strut", "Tiger", "Tremor", "Tri", "Triad", "Trifle", "Trinity", "Trix", "Tru", "Tune", "Twist", "Vertex", "Vibe", "Vim", "Virtue", "Visage", "Vitae", "Vitality", "Vortex", "Voyage", "Wave", "Wiz", "Zest"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
