#include "wildstar-aurins_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_wildstar_aurins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "d", "f", "g", "h", "l", "m", "n", "s", "r", "t", "v"};
    static constexpr std::string_view nm2[] = {"a", "e", "i", "y"};
    static constexpr std::string_view nm3[] = {"b", "ff", "h", "l", "ll", "m", "mm", "n", "nn", "r", "rv", "rl", "v", "w", "z"};
    static constexpr std::string_view nm4[] = {"l", "ll", "n", "nn", "r", "s"};
    static constexpr std::string_view nm5[] = {"d", "f", "h", "l", "m", "n", "r", "s", "sh", "t", "th", "v", "w"};
    static constexpr std::string_view nm6[] = {"a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "a", "e", "i", "ya", "ia"};
    static constexpr std::string_view nm7[] = {"h", "ff", "hn", "hl", "l", "ll", "ln", "lm", "m", "mm", "n", "nn", "r", "rs", "rl", "rn", "rm", "s", "sh", "ss", "w"};
    static constexpr std::string_view nm8[] = {"amber", "autumn", "blue", "bright", "comet", "dawn", "day", "dew", "dusk", "ember", "even", "ever", "far", "feather", "fire", "flame", "fog", "forest", "green", "lake", "leaf", "light", "luna", "lunar", "mirth", "mist", "moon", "morning", "moss", "night", "ocean", "opal", "rain", "red", "river", "rose", "ruby", "shadow", "silver", "sky", "solar", "stem", "still", "storm", "summer", "sun", "twilight", "water", "wild", "wind", "winter", "wood"};
    static constexpr std::string_view nm9[] = {"bloom", "blossom", "blower", "branch", "breath", "breeze", "brook", "cloud", "clouds", "dance", "drift", "fall", "flame", "flock", "flower", "gaze", "gazer", "grass", "heart", "lead", "leaf", "mind", "petal", "root", "shade", "shine", "sky", "snow", "song", "spirit", "spyre", "stalk", "star", "strike", "swift", "thorn", "vale", "walk", "watch", "whisper", "wing"};

    std::string lname; std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; int i = 0;

i = rng() % 10; {
    rnd6 = rng() % std::size(nm8);
    rnd7 = rng() % std::size(nm9);
    while (nm8[rnd6] == nm9[rnd7]) {
    rnd7 = rng() % std::size(nm9);
    }
    lname = nm8[rnd6] + nm9[rnd7];
    if (type == 1) {
    rnd = rng() % std::size(nm5);
    rnd2 = rng() % std::size(nm6);
    rnd3 = rng() % std::size(nm7);
    rnd4 = rng() % std::size(nm6);
    names = nm5[rnd] + nm6[rnd2] + nm7[rnd3] + nm6[rnd4] + " " + lname;
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    rnd4 = rng() % std::size(nm2);
    rnd5 = rng() % std::size(nm4);
    names = nm1[rnd] + nm2[rnd2] + nm3[rnd3] + nm2[rnd4] + nm4[rnd5] + " " + lname;
    }
    return names;
    }
}
