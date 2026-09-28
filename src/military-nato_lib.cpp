#include "military-nato_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_military_nato_name(std::mt19937& rng) {
    static constexpr std::string_view names[] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Zulu"};

    size_t r1 = 0; size_t r2 = 0; int i = 0;

    r1 = rng() % std::size(names);
    r2 = rng() % (std::size(names) - 1);
    if (r2 >= r1) r2 = r2 + 1;
    return names[r1] + " " + names[r2];
}
