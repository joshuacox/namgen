#include "miscellaneous-teleportations_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_miscellaneous_teleportations_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Apparate", "Beam", "Blink", "Body Flicker", "Bounce", "Broadcast", "Bunnyhop", "Burst", "Bypass", "Conversion", "Cross", "Crosscut", "Crossover", "Depart", "Detour", "Deviate", "Dimension Door", "Discharge", "Echo", "Escape", "Ether Leap", "Ethereal Pass", "Etheric Transfer", "Fae Walk", "Flash", "Flicker", "Flip-flop", "Flutter", "Flux", "Fluxuate", "Geo Burst", "Geo Dash", "Geo Deflect", "Geo Leap", "Geo Pass", "Geo Relocation", "Geocast", "Geodrift", "Geoflect", "Geogenerate", "Geomorphosis", "Geoport", "Geostep", "Geotemper", "Geovolve", "Glimmer", "Jolt", "Light Step", "Lightning Step", "Localeap", "Omit", "Pass", "Pass Through", "Plane Step", "Plane Walk", "Portal", "Pulse", "Pulse Pass", "Quantum Leap", "Quick Shift", "Quick Switch", "Quick Transit", "Quick Travel", "Quickstep", "Radiate", "Relocaleap", "Relocate", "Relocation", "Relocus", "Resurge", "Shadowstep", "Shift", "Shortcut", "Sidestep", "Skip", "Skipstep", "Skirt", "Slipstream", "Space Jump", "Split Step", "Stream", "Streamstep", "Switch", "Take Flight", "Tele", "Tele Out", "Telecast", "Teleskip", "Transfer", "Transflux", "Transkip", "Translocation", "Transmaterialize", "Transmit", "Transtep", "Transwarp", "Tripskip", "Void Step", "Warp", "Wink"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    return names;
    }
}
