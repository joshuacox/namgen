#include "fantasy-phoenixs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_phoenixs_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Ash", "Ashes", "Aura", "Aurora", "Beacon", "Beak", "Beam", "Blaze", "Blazetalon", "Blink", "Bonfi", "Brilliancy", "Brim", "Cinder", "Cinders", "Crux", "Dawn", "Dazzle", "Deja", "Dusty", "Elemence", "Ember", "Eos", "Eterna", "Eternus", "Feathers", "Ferno", "Fiere", "Flambeau", "Flame", "Flametalon", "Flare", "Flash", "Flayme", "Fume", "Fury", "Fye", "Fyre", "Genesis", "Glaze", "Glint", "Gloss", "Glow", "Heat", "Icarus", "Ignite", "Illume", "Illumine", "Inferno", "Juvenate", "Kindle", "Light", "Lucent", "Lumino", "Luminos", "Morte", "Nether", "Nite", "Onyx", "Pharos", "Pire", "Plume", "Pyre", "Radiance", "Raise", "Ray", "Raye", "Revi", "Rise", "Ryse", "Ryze", "Scorch", "Scorchey", "Sheen", "Shimmer", "Shine", "Slag", "Soar", "Sol", "Solar", "Solaris", "Soleil", "Soot", "Soots", "Soul", "Spark", "Sparkle", "Sparkles", "Spirit", "Sprout", "Smoke", "Sunbeam", "Sunny", "Surge", "Tinder", "Torch", "Vitality", "Vitally", "Viva", "Vu", "Zeal"};

    std::string names; size_t rnd = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    return names;
    }
}
