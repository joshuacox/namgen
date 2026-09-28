#include "real-tibetans_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_tibetans_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Bhakto", "Bhuchung", "Bhuti", "Chodag", "Chodak", "Choden", "Chodrak", "Choedon", "Choegyal", "Choejor", "Choenyi", "Choephel", "Choezom", "Chokey", "Chokphel", "Chokzay", "Chonden", "Chophel", "Dakpa", "Damchoe", "Dawa", "Dema", "Dhadul", "Dhakpa", "Dhardon", "Dhargay ", "Dhargey", "Dhargye", "Dharma", "Dhundup", "Dickey", "Dolkar", "Dolker", "Dolma", "Dorje", "Dorjee", "Duga", "Gelek", "Gephel", "Gonpo", "Gurmey", "Gyalchok", "Gyaltsen", "Gyamtso", "Gyatso", "Gyurmey", "Jamma", "Jampa", "Jamtso", "Jamyang", "Jangchup", "Jinpa", "Jorden", "Jungney", "Kalsang", "Karma", "Kechok", "Kelden", "Kelsang", "Kesang", "Khando", "Khandro", "Khedrup", "Khetsun", "Konchok", "Kunchen", "Kundang", "Kunga", "Legshey", "Lhakpa", "Lhamo", "Lhawang", "Lhundrup", "Lhundup", "Lobsang", "Metok", "Monlam", "Namdak", "Namdol", "Namgyal", "Namgyal Wangchuk", "Ngawang", "Ngodup", "Ngonga", "Norbu", "Norzin", "Nyandak", "Nyima", "Padma", "Palden", "Paldon", "Paljor", "Palkyi", "Palmo", "Passang", "Pema", "Pemba", "Penpa", "Phuntsok", "Rabgyal", "Rabten", "Rabyang", "Rangdol", "Rapten", "Richen", "Rigsang", "Rigzin", "Rinchen", "Samdup", "Samten", "Sangey", "Sangmo", "Sangyal", "Sangye", "Seldon", "Shenlha Woekar", "Sherab", "Sherap", "Sonam", "Tamdin", "Tashi", "Tempa", "Tenzin", "Thekchen", "Thokmay", "Thubten", "Tinley", "Topden", "Tsamchoe", "Tselha", "Tsering", "Tseten", "Tsewang", "Tsomo", "Tsultrim", "Tsundue", "Ugyen", "Wangchen", "Wangchuk", "Wangdak", "Wangdue", "Wangdup", "Wangmo", "Wangyal", "Woenang", "Woeser", "Woeten", "Yama", "Yangdon", "Yangkey", "Yangtso", "Yangzom", "Yeshi", "Yonten", "Youdon", "Youdron", "Yudron", "Yungdrung", "Zopa"};
    static constexpr std::string_view nm2[] = {"Aukatsang", "Bhutia", "Bongpatsang", "Chodron", "Damdul", "Dhanacktsang", "Dhompa", "Dorje", "Drakpa", "Drakthonpa", "Dramuktsang", "Drupa", "Geymutsang", "Gonpo", "Gorkha", "Gurung", "Gyaktsen", "Gyatso", "Jigme", "Jungne", "Kalingpong", "Karpo", "Kyidtodpa", "Ladakh", "Lhamo", "Lingpa", "Lotsawa", "Lukhangwa", "Manriwa", "Mingyur", "Mipham", "Monpa", "Namdak", "Nepali", "Norbu", "Nyima", "Nyingpo", "Pakshi", "Palsang", "Pandita", "Repa", "Sambhota", "Sangpo", "Shakabpa", "Sherpa", "Tamang", "Tangpa", "Tenzin", "Thaye", "Trengwa", "Trungpa", "Tsemo", "Tsogyal", "Wangpo", "Yeshy"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    if (i < 5) {
    names = nm1[rnd];
    } else {
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + " " + nm2[rnd2];
    }
    return names;
    }
}
