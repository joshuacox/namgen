#include "harry_potter-hippogriffs_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_harry_potter_hippogriffs_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Agile", "Beauty", "Blitz", "Breeze", "Brisk", "Buck", "Charge", "Class", "Dart", "Dash", "Draft", "Fleet", "Flow", "Flurry", "Flux", "Gale", "Gentle", "Glamor", "Grace", "Guard", "Gust", "Hale", "Hate", "Hurricane", "Iron", "Keen", "Loud", "Mellow", "Nimble", "Quick", "Quiet", "Rough", "Rush", "Sharp", "Silk", "Soft", "Spirit", "Spry", "Stark", "Steel", "Storm", "Stout", "Strong", "Surge", "Swift", "Tame", "Tender", "Thunder", "Wild", "Wind"};
    static constexpr std::string_view nm2[] = {"beak", "bill", "claw", "colt", "eye", "feather", "fluff", "fringe", "hoof", "hook", "mane", "plume", "quill", "scream", "screech", "steed", "tail", "talon", "tuft", "wing"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
