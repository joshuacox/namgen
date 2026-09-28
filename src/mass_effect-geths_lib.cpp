#include "mass_effect-geths_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_mass_effect_geths_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Unit", "Platform", "Mod", "System", "SysMod", "GU", "G-Unit", "Geth-Unit", "Module"};
    static constexpr std::string_view names3[] = {"a", "b", "c", "e", "s", "x"};
    static constexpr std::string_view names4[] = {"Armada", "Batallion", "Alpha", "Omega", "Myriad", "Sundry", "Horde", "Brigade", "Phalanx", "Host", "Enigma", "Terminus", "Prophet", "Genesis", "Dawn", "Oracle", "Anomaly", "Centurion", "Obelisk", "Pinnacle", "Goliath", "Apex", "Vortex", "Vertex", "Armageddon", "Oblivion", "Eternity", "Daemon", "Demise", "Destiny"};

    std::string names; size_t names2 = 0; size_t rnd = 0; size_t rnd0 = 0; size_t rnd1 = 0; int i = 0;

i = rng() % 10; {
    if (i < 6) {
    rnd = rng() % std::size(names1);
    names2 = (rng() % 250) + 1;
    rnd1 = rng() % std::size(names3);
    names = names1[rnd] + "-" + names2 + names3[rnd1];
    } else {
    rnd0 = rng() % std::size(names4);
    names = names4[rnd0];
    }
    return names;
    }
}
