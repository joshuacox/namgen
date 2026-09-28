#include "fantasy-cat_people_nekojins_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_cat_people_nekojins_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aiko", "Aki", "Akihiko", "Akihiro", "Akiko", "Akina", "Akira", "Anda", "Aneko", "Aoi", "Ayame", "Bento", "Chika", "Chiko", "Chiyo", "Cho", "Dai", "Daiki", "Daisuke", "Domo", "Eriko", "Gin", "Haiku", "Hana", "Haru", "Haruki", "Haruko", "Hideki", "Hideo", "Hikaru", "Hiro", "Hiroki", "Hiroshi", "Hisa", "Hisashi", "Hisoka", "Honcho", "Hoshi", "Hoshiko", "Ichiro", "Isamu", "Isao", "Jiro", "Judo", "Jun", "Juro", "Kabuki", "Kaede", "Kameko", "Katsumi", "Katsuo", "Katsuro", "Keiji", "Keiko", "Ken", "Kenji", "Kin", "Kioko", "Kioshi", "Ko", "Kobe", "Kohaku", "Koji", "Koto", "Kou", "Kumiko", "Kuro", "Kyo", "Kyoko", "Leiko", "Madoka", "Maeko", "Makoto", "Masa", "Masaaki", "Masaki", "Masi", "Masumi", "Masuru", "Matsui", "Michiko", "Michio", "Minoru", "Mitsuo", "Mitsuru", "Nami", "Nao", "Naoki", "Nariko", "Natsuko", "Nikki", "Nobu", "Nori", "Noriko", "Norio", "Nyoko", "Oki", "Orino", "Ran", "Rei", "Ryu", "Sachi", "Sachiko", "Sake", "Sakura", "Satu", "Shig", "Shika", "Shin", "Shina", "Shino", "Shiro", "Sho", "Suki", "Sumi", "Sumo", "Suzu", "Taiki", "Taiko", "Taji", "Taka", "Takara", "Tamae", "Toshi", "Yoshi", "Yukio"};
    static constexpr std::string_view nm2[] = {"Aiko", "Aimi", "Aio", "Akane", "Aki", "Akina", "Akira", "Amaya", "Ame", "Aoi", "Aozora", "Asa", "Asami", "Aya", "Ayaka", "Chi", "Chie", "Chika", "Chikako", "Chiyo", "Cho", "Choji", "Dai", "Eiko", "Emi", "Emiko", "Eri", "Fujiko", "Fuyu", "Ginkgo", "Haiku", "Hana", "Hanako", "Haru", "Haruki", "Haruko", "Hideko", "Hikari", "Hikaru", "Hiro", "Hiromi", "Hisanori", "Hisoka", "Hitomi", "Hoshi", "Hoshinka", "Hotaru", "Junko", "Kabuki", "Kaede", "Kameko", "Kaori", "Kasumi", "Katsu", "Kazumi", "Kei", "Keiko", "Kimi", "Kimiko", "Kioko", "Kiyoshi", "Ko", "Kohaku", "Kohana", "Koko", "Kou", "Kuro", "Kyo", "Kyoko", "Leiko", "Madoka", "Mai", "Maiya", "Masa", "Masako", "Masami", "Masumi", "Mi", "Michi", "Michiko", "Midori", "Mika", "Miki", "Miku", "Misuki", "Mitsuru", "Miyoshi", "Miyuki", "Moe", "Momo", "Momoe", "Moriko", "Name", "Nami", "Naoki", "Naoko", "Naomi", "Nari", "Nariko", "Natsu", "Natsumi", "Neka", "Nobu", "Nori", "Noriko", "Oki", "Rei", "Reiko", "Riko", "Rin", "Ryoko", "Saki", "Sakura", "Sayomi", "Sayuri", "Shig", "Shinju", "Shiori", "Shizumi", "Shoji", "Sora", "Suki", "Sumiko", "Susumu", "Suzaku", "Suzu", "Tamika", "Tanaka", "Tokiwa", "Tora", "Toshiko", "Tsuki", "Tsukiko", "Umeko", "Usagi", "Yoi", "Yoki", "Yoko", "Yori", "Yoshie", "Yuki", "Yukiko", "Yumi", "Yumiko", "Yuri", "Yuuki", "Zakuro"};
    static constexpr std::string_view nm3[] = {"Aiko", "Aki", "Akira", "Aoi", "Asa", "Ayame", "Chi", "Chie", "Chikako", "Dai", "Daiki", "Domo", "Eiko", "Eri", "Fuyu", "Haiku", "Haru", "Haruki", "Haruko", "Hikari", "Hikaru", "Hiro", "Hiroki", "Hisoka", "Honcho", "Hoshi", "Hotaru", "Isamu", "Jun", "Junko", "Kabuki", "Kaede", "Kameko", "Katsu", "Katsumi", "Kei", "Keiko", "Ken", "Kin", "Kio", "Kioko", "Kioshi", "Ko", "Kohaku", "Kohana", "Koko", "Kou", "Kyo", "Kyoko", "Leiko", "Madoka", "Maeko", "Mai", "Makoto", "Masa", "Masaaki", "Masako", "Masumi", "Masuru", "Matsui", "Michi", "Mika", "Minoru", "Mitsuru", "Miyoshi", "Momo", "Nami", "Nao", "Naoki", "Naoko", "Nari", "Nariko", "Natsu", "Nobu", "Nori", "Oki", "Rei", "Reiko", "Rin", "Ryoko", "Saki", "Shig", "Shin", "Sho", "Sora", "Suzaku", "Taiki", "Tanaka", "Tora", "Toshi", "Usagi", "Yoi", "Yoko", "Yori", "Yoshi", "Yuki", "Yukiko", "Yukio", "Yumi", "Yumiko"};
    static constexpr std::string_view nm4[] = {"ch", "c", "f", "g", "h", "k", "m", "n", "pr", "r", "s", "sh", "th", "x", "z"};
    static constexpr std::string_view nm5[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ia", "au", "iau", "aa", "ee", "ie", "y", "y"};
    static constexpr std::string_view nm6[] = {"ch", "c", "f", "fr", "cr", "k", "ks", "cs", "kr", "m", "mm", "mn", "ms", "mz", "kz", "n", "nm", "ns", "nz", "nx", "nch", "mch", "pr", "gr", "s", "ss", "sh", "sz", "shr", "sr", "th", "tr", "t", "x", "z", "zz", "zs", "zr", "c", "f", "k", "m", "n", "s", "t", "x", "z", "c", "f", "k", "m", "n", "s", "t", "x", "z"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ea", "ia", "au", "iau", "aa", "ee", "ie", "y", "y"};
    static constexpr std::string_view nm8[] = {"", "ch", "c", "f", "fr", "cr", "k", "ks", "cs", "kr", "m", "mm", "mn", "ms", "mz", "kz", "n", "nm", "ns", "nz", "nx", "nch", "mch", "pr", "gr", "s", "ss", "sh", "sz", "shr", "sr", "th", "tr", "t", "x", "z", "zz", "zs", "zr", "c", "f", "k", "m", "n", "s", "t", "x", "z", "c", "f", "k", "m", "n", "s", "t", "x", "z"};
    static constexpr std::string_view nm9[] = {"", "", "", "r", "rr", "s", "ss", "sh", "x", "z"};
    static constexpr std::string_view nm10[] = {"", "", "", "", "", "", "", "th", "h", "s", "ss", "sh"};
    static constexpr std::string_view nm11[] = {"s", "ss", "sh", "z", "h", "", "", "", "", "", ""};

    std::string names; size_t rnd = 0; size_t rnd10 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; size_t rnd9 = 0; int i = 0;

i = rng() % 10; {
    rnd4 = rng() % std::size(nm4);
    rnd5 = rng() % std::size(nm5);
    rnd6 = rng() % std::size(nm6);
    rnd7 = rng() % std::size(nm7);
    rnd8 = rng() % std::size(nm8);
    rnd9 = rng() % std::size(nm5);
    if (rnd7 < 35) {
    rnd8 = 0;
    } else {
    while (rnd8 == 0) {
    rnd8 = rng() % std::size(nm8);
    }
    }
    if (type == 1) {
    if (i < 5) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else {
    rnd10 = rng() % std::size(nm10);
    names = nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm5[rnd9] + nm10[rnd10];
    }
    } else if (type == 2) {
    if (i < 5) {
    rnd = rng() % std::size(nm3);
    names = nm3[rnd];
    } else {
    rnd10 = rng() % std::size(nm11);
    names = nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm5[rnd9] + nm11[rnd10];
    }
    } else {
    if (i < 5) {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    } else {
    rnd10 = rng() % std::size(nm9);
    names = nm4[rnd4] + nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + nm5[rnd9] + nm9[rnd10];
    }
    }
    return names;
    }
}
