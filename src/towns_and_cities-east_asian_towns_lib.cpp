#include "towns_and_cities-east_asian_towns_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_towns_and_cities_east_asian_towns_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Arida", "Asa", "Bira", "En", "Fuji", "Funa", "Furu", "Hashi", "Haya", "Hon", "Horo", "Iwa", "Jami", "Kamisu", "Ken", "Kiko", "Kimo", "Kiyo", "Kuma", "Kumi", "Kuri", "Kuro", "Kuzu", "Matsu", "Mina", "Miya", "Mutsu", "Naga", "Naka", "Nakashi", "Nara", "Oku", "Ran", "Shako", "Shi", "Shima", "Shin", "Shinto", "Shira", "Sou", "Taka", "Tate", "Tawa", "Tawara", "Tou", "Ura", "Wata", "Ya", "Yaha", "Yaku", "Yama", "Yoko", "Yuga"};
    static constexpr std::string_view names2[] = {"betsu", "biro", "buchi", "daka", "furano", "gata", "gawa", "haba", "hama", "hidaka", "homa", "horo", "kami", "kanai", "kawa", "kita", "konai", "koshi", "kotan", "kumo", "maki", "mamoto", "matsunai", "moto", "nagawa", "nai", "nobe", "nokawa", "nouchi", "raha", "ramoto", "rano", "raoi", "saki", "sato", "shibetsu", "shihoro", "shina", "shiri", "sunai", "tama", "tari", "tori", "toro", "tsukawa", "wara", "yako", "yama", "zaki", "zawa"};
    static constexpr std::string_view names3[] = {"Bao", "Chang", "Dan", "Dong", "Feng", "Fu", "Guang", "Gui", "Hang", "Heng", "Jiang", "Jiao", "Jin", "Kara", "Liao", "Mei", "Mian", "Mudan", "Nan", "Pan", "Ping", "Qi", "Qin", "Qing", "Qu", "Quan", "Shan", "Shang", "Shao", "Shi", "Shizui", "Su", "Tai", "Tang", "Teng", "Tong", "Xian", "Xiang", "Xin", "Xu", "Xuan", "Yuan", "Yue", "Zhao", "Zhen", "Zhong", "Zhou", "Zoa"};
    static constexpr std::string_view names4[] = {"chang", "cheng", "chong", "chun", "dao", "dong", "ging", "gong", "guan", "hai", "har", "hou", "hua", "jiang", "jing", "liang", "may", "men", "ping", "qihar", "qiu", "ramay", "rao", "shan", "shu", "shui", "tong", "tou", "wei", "xiang", "xing", "yang", "ying", "yuan", "zhou", "zihua", "zou", "zuishan"};
    static constexpr std::string_view names5[] = {"Altan", "Ba", "Baat", "Baga", "Baruun", "Batt", "Bayan", "Bi", "Bu", "Bul", "Bulan", "Buut", "Chand", "Choi", "Chu", "Chuluun", "Dar", "Del", "Dulaan", "Er", "Erdene", "Ga", "Gurvan", "Guu", "Han", "Jan", "Jar", "Jav", "Kha", "Khair", "Khar", "Kher", "Kherlen", "Khon", "Khot", "Khu", "Khyal", "Khyar", "Mal", "Man", "Na", "Naran", "Nogoon", "Nom", "On", "Or", "Sa", "Sai", "Sal", "Shar", "Sharyn", "Shi", "Shine", "Tai", "Taria", "Tsen", "Ulaan", "Zuun"};
    static constexpr std::string_view names6[] = {"bayan", "bulag", "chivlin", "dene", "ga", "gaa", "gai", "galan", "galant", "galjuut", "gana", "ganuur", "gas", "gat", "ger", "gol", "gon", "gor", "horoot", "jinst", "kh", "khaan", "khan", "khangai", "khet", "khir", "khit", "khlant", "khon", "khorin", "lan", "lig", "lin", "liun", "luut", "mandal", "mani", "nuur", "raat", "ran", "ryngol", "sagaan", "sai", "sengel", "serleg", "shaat", "shir", "sogt", "tai", "teeg", "tont", "tooroi", "tsogt", "turuun", "vi", "yant"};
    static constexpr std::string_view names7[] = {"An", "Bor", "Cheo", "Chun", "Chung", "Cong", "Dang", "Dong", "Gang", "Gim", "Gwa", "Gwang", "Gyeong", "Gyer", "Hae", "Ham", "Hoer", "Hui", "Hye", "Ik", "Je", "Jeon", "Jin", "Kae", "Kang", "Kim", "Ku", "Man", "Mung", "Na", "Nam", "Non", "Po", "Pyong", "Ra", "Sam", "Sari", "Seo", "Sin", "Sinui", "Sok", "Sun", "Tae", "Tan", "Tok", "Ui", "Won", "Yang", "Yeo"};
    static constexpr std::string_view names8[] = {"baek", "chaek", "cheok", "cheon", "cho", "chon", "dong", "geup", "gye", "hae", "hung", "je", "jin", "ju", "nan", "neung", "po", "san", "seong", "song", "su", "wang", "won", "yeong", "yong"};

    std::string names; size_t rnd0 = 0; size_t rnd1 = 0; int i = 0;

i = rng() % 10; {
    if (i < 3) {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    names = names1[rnd0] + names2[rnd1];
    } else if (i < 5) {
    rnd0 = rng() % std::size(names3);
    rnd1 = rng() % std::size(names4);
    names = names3[rnd0] + names4[rnd1];
    } else if (i < 7) {
    rnd0 = rng() % std::size(names5);
    rnd1 = rng() % std::size(names6);
    names = names5[rnd0] + names6[rnd1];
    } else {
    rnd0 = rng() % std::size(names7);
    rnd1 = rng() % std::size(names8);
    names = names7[rnd0] + names8[rnd1];
    }
    return names;
    }
}
