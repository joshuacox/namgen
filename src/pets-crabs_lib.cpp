#include "pets-crabs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pets_crabs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"AlPinchino", "Alpha", "Apollo", "Aqua", "Atoll", "Aura", "Azure", "BamBam", "Barnacle", "Biscuit", "Blazer", "Blister", "Boulder", "Bounce", "Butters", "Buttons", "Carapace", "Checkers", "Chester", "Chowder", "Chuck", "Clacker", "Clawford", "Claws", "Clawz", "Clicker", "Clipper", "Clyde", "Cobbler", "CrabCake", "Crabanasty", "Crabapple", "Crabbitz", "Crabohydrate", "Crack", "Crane", "Crash", "Cruncher", "Crunchy", "Crust", "Crusty", "DrZoidberg", "Dude", "Escape", "Fang", "Fangs", "Fuzzball", "Fuzzy", "Gil", "Gillian", "Grabandhold", "Grabby", "Grabs", "Griper", "Grouch", "Grouchy", "Grump", "Hardhead", "Hardy", "Herman", "Hermi", "Hermie", "Hermit", "Hermy", "Hifive", "Hyde", "Kingler", "Krabby", "Krabs", "Kraken", "Kuka", "MaxPayne", "Muffin", "Nemo", "Neptune", "Nero", "Norbert", "Omega", "Onyx", "Orea", "Pace", "Patty", "Payne", "Piccolo", "Pinch", "Pincher", "Pinchino", "Pinchy", "Pinstripe", "Pointy", "Popeye", "Poseidon", "Prawn", "Ranger", "Reef", "Ripple", "Riptide", "Rock", "Rocklobster", "Rocky", "Rogue", "Salt", "Salty", "Saul", "Scratch", "Scratchy", "Sebastion", "Sellfish", "Shabby", "Shade", "Shadow", "Shamrock", "Sheldon", "Shell", "Shelly", "Sideways", "Skipper", "SmallFry", "Snap", "Snapp", "Snappah", "Snapper", "Snappy", "Snaps", "Snipper", "Snippy", "Snips", "Snookums", "Softshell", "Softy", "Sparkle", "Spike", "Spikes", "Spot", "Surf", "Surimi", "Twitch", "Waddle", "Waddles", "Wave", "Waves", "Whopper", "Wobble", "Wobbles", "Zippy", "Zoidberg", "iClaw", "iPinch", "iSnap"};
    static constexpr std::string_view nm2[] = {"Aphrodite", "Arial", "Aqua", "Ariel", "Atolle", "Aura", "Ava", "Aurora", "Ava", "Azure", "Azura", "Bashful", "Bashy", "Bash", "Bay", "Baye", "Biscuit", "Bitsy", "Star", "Bo", "Bounce", "Bouncy", "Brooke", "Bubble", "Bubbles", "Button", "Buttons", "Cake", "Cami", "Carapace", "Checkers", "Chesty", "Clawford", "Snips", "Snippy", "Snipsnap", "Clacks", "Clacky", "Clawdia", "Clawdis", "Claws", "Clips", "Clippy", "Cobble", "Coco", "Coral", "Cora", "Cakes", "Crabine", "Crabina", "Crackle", "Crackles", "Crash", "Crunchey", "Dazzle", "Dora", "Sandy", "Nemo", "Escape", "Fuzzball", "Fuzzy", "Gill", "Gilly", "Grabby", "Grabbis", "Gripes", "Hermine", "Hermione", "Hermi", "Hermilia", "Hermyse", "Pinchy", "Itsy", "Krabsy", "MsKraken", "Lily", "Lime", "MrsCrabapple", "Crabapple", "Muffin", "MsPinch", "MrsKrabs", "Oasis", "Oceane", "Oceana", "Pinchys", "Pinchy", "Pique", "Pixie", "Princess", "Rainbow", "Sparkle", "Reefe", "Ria", "Ripples", "Ripple", "Rogue", "Shadow", "Shade", "Ruby", "Sally", "Sandy", "Sapphire", "Scratches", "Biscuit", "Shelly", "Shine", "Snappy", "Snips", "Snaps", "Sparkles", "Sparkle", "Spot", "Dot", "Dots", "Surimi", "Waddles", "Wobble", "Wobbles", "Waddle"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    }
    return names;
    }
}
