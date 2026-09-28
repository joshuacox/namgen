import json

with open("traditions_dump.json", "r") as f:
    data = json.load(f)

def to_cpp_arr(name, arr):
    escaped = []
    for item in arr:
        clean = item.replace('\\', '\\\\').replace('"', '\\"')
        escaped.append(f'"{clean}"')
    items = ", ".join(escaped)
    return f"static constexpr std::string_view {name}[] = {{{items}}};"

lines = [
    '#include "descriptions-traditions_lib.h"',
    '#include "generator_common.h"',
    '#include <string_view>',
    '#include <string>',
    '',
    to_cpp_arr("nm1", data["nm1"]),
    to_cpp_arr("nm2", data["nm2"]),
    to_cpp_arr("nm3", data["nm3"]),
    to_cpp_arr("nm4", data["nm4"]),
    to_cpp_arr("nm5", data["nm5"]),
    to_cpp_arr("nm7", data["nm7"]),
    to_cpp_arr("nm8", data["nm8"]),
    to_cpp_arr("nm9", data["nm9"]),
]

for i in range(3):
    for j in range(2):
        lines.append(to_cpp_arr(f"nm6_{i}_{j}", data["nm6"][i][j]))
for i in range(3):
    for j in range(2):
        lines.append(to_cpp_arr(f"nm10_{i}_{j}", data["nm10"][i][j]))

lines.append('''
static constexpr ArrayView nm6[3][2] = {
    { make_view(nm6_0_0), make_view(nm6_0_1) },
    { make_view(nm6_1_0), make_view(nm6_1_1) },
    { make_view(nm6_2_0), make_view(nm6_2_1) }
};

static constexpr ArrayView nm10[3][2] = {
    { make_view(nm10_0_0), make_view(nm10_0_1) },
    { make_view(nm10_1_0), make_view(nm10_1_1) },
    { make_view(nm10_2_0), make_view(nm10_2_1) }
};

std::string generate_descriptions_traditions_name(std::mt19937& rng) {
    size_t rnd1 = rng() % std::size(nm1);
    size_t rnd2 = rng() % std::size(nm2);
    size_t rnd3 = rng() % std::size(nm3);
    size_t rnd4 = rng() % std::size(nm4);
    size_t rnd5 = rng() % std::size(nm5);
    size_t rnd6 = rng() % 3;
    size_t rnd6b = rng() % nm6[rnd6][0].size();
    size_t rnd6c = rng() % nm6[rnd6][1].size();
    size_t rnd6d = rng() % nm6[rnd6][1].size();
    while (rnd6c == rnd6d) {
        rnd6d = rng() % nm6[rnd6][1].size();
    }
    size_t rnd7 = rng() % std::size(nm7);
    size_t rnd8 = rng() % std::size(nm8);
    size_t rnd9 = rng() % std::size(nm9);

    size_t rnd10 = rng() % std::size(nm1);
    size_t rnd11 = rng() % std::size(nm2);
    size_t rnd12 = rng() % std::size(nm3);
    size_t rnd13 = rng() % std::size(nm4);
    size_t rnd14 = rng() % std::size(nm5);
    size_t rnd15 = rng() % 3;
    size_t rnd15b = rng() % nm10[rnd15][0].size();
    size_t rnd15c = rng() % nm10[rnd15][1].size();

    std::string name = "In the " + std::string(nm1[rnd1]) + " of " + std::string(nm2[rnd2]) + std::string(nm3[rnd3]) + std::string(nm4[rnd4]) + std::string(nm5[rnd5]) + " it is tradition for " + std::string(nm6[rnd6][0][rnd6b]) + " " + std::string(nm9[rnd9]) + ". It\'s supposed to be a symbol of " + std::string(nm6[rnd6][1][rnd6c]) + " and " + std::string(nm6[rnd6][1][rnd6d]) + " and it\'s usually part of a " + std::string(nm7[rnd7]) + " that can " + std::string(nm8[rnd8]) + ".";
    std::string name2 = "-------------------------";
    std::string name3 = "In the " + std::string(nm1[rnd10]) + " of " + std::string(nm2[rnd11]) + std::string(nm3[rnd12]) + std::string(nm4[rnd13]) + std::string(nm5[rnd14]) + " it is tradition " + std::string(nm10[rnd15][0][rnd15b]) + ". It\'s supposed to " + std::string(nm10[rnd15][1][rnd15c]) + ".";

    std::string result = name + "\\n\\n" + name2 + "\\n\\n" + name3;
    return result;
}
''')

with open("src/descriptions-traditions_lib.cpp", "w") as f:
    f.write("\n".join(lines))
print("Successfully generated src/descriptions-traditions_lib.cpp")
