#include "real-laotians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_real_laotians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Akamu", "Analu", "Aulii", "Bane", "Bane ", "Havika", "Ikaika", "Kahoku", "Kai", "Kaili", "Kaipo", "Kalani", "Kale", "Kale ", "Kalei", "Kanoa", "Kapono", "Kawaii", "Keahi", "Keanu", "Kelii", "Keoki", "Keola", "Keon", "Keona", "Keowynn", "Kimo", "Kimo ", "Koa", "Konala", "Kye", "Kye ", "Lae", "Lani", "Leilani", "Liko", "Lilo", "Loe", "Maiele", "Maik", "Makaio", "Makan", "Makan ", "Makani", "Malo", "Malo ", "Mauli", "Meka", "Mele", "Moana", "Moke", "Mya", "Noi", "Oke", "Palani", "Paxathipatai", "Pekelo", "Phetdum", "Phonesavanh", "Saravan", "Sathanalat", "Sengprachanh", "Sommai", "Somphone", "Songkram", "Sonxai", "Teyvada", "Ulani", "Wongduan", "Xaisomboun"};
    static constexpr std::string_view nm2[] = {"Aelan", "Ailani", "Akela", "Alaina", "Alamea", "Alana", "Alani", "Alanna", "Alaula", "Aleka", "Alika", "Alli", "Allyn", "Aloha", "Alohi", "Alohilani", "Alona", "Alun", "Alyn", "Anani", "Ani", "Aolani", "Aolha", "Aulani", "Aulii", "Bane", "Bounmy", "Chansouda", "Chanthadeth", "Dorit", "Edena", "Gladi", "Haimi", "Haleah", "Haleigha", "Halia", "Hina", "Inoke", "Iokina", "Iolana", "Iolani", "Ipo", "Iwalani", "Jeanitha", "Kai", "Kaiah", "Kailani", "Kailea", "Kaili", "Kalaina", "Kalama", "Kalani", "Kalea", "Kaleah", "Kalei", "Kaleigh", "Kaleikaumaka", "Kalena", "Kalia", "Kalina", "Kaloni", "Kamea", "Kawailani", "Kawena", "Keahi", "Keala", "Keanu", "Keiki", "Keilana", "Keili", "Kekiokolanee", "Kekona", "Keola", "Ketsada", "Khampheng", "Kiana", "Kiele", "Kieli", "Kina", "Kinipela", "Konane", "Lae", "Lahela", "Laina", "Lanai", "Lani", "Lanikai", "Laya", "Leigha", "Leilana", "Leilana ", "Leilani", "Leilanie", "Liliha", "Lilo", "Loe", "Lokelani", "Lulani", "Mahina", "Maik", "Maile", "Makaio", "Makala", "Makana", "Makani", "Makelina", "Makenna", "Malana", "Maleah", "Malia", "Malu", "Mauli", "Mei", "Milani", "Mily", "Moana", "Moanna", "Moke", "Mya", "Nalani", "Nalanie", "Nani", "Napua", "Noelani", "Noma", "Okalani", "Oke", "Okelani", "Okilani", "Oliana", "Olina", "Onaona", "Palila", "Peni", "Phetmany", "Phetsavanh", "Pilialoha", "Pilis", "Pualani", "Roselani", "Saengvone", "Sasilvia", "Sathit", "Somphone", "Soukchanda", "Sousida", "Suke", "Ulani", "Ululani", "Wanika"};
    static constexpr std::string_view nm3[] = {"Bokeo", "Bouphavanh", "Bouvanaat", "Champasack", "Champasak", "Chanthanane", "Chanthavong	 ", "Chanthavong", "Chanthraphone", "Cheruene", "Douangmala", "Douangvily", "Genevong", "Inthisane", "Kaewdara", "Keobounphanh", "Keobunta", "Keomany", "Keopraseuth", "Keothavong", "Kethavongsa", "Ketthavong", "Khamchanh", "Khamsomphou", "Khamvongsouk", "Khanthavong", "Khotpanya", "Khouphongsy", "Kittiphan", "Kommandam", "Kouanchao", "Lengsavad", "Louangrath	 ", "Malaythong", "Manwilaivong", "Menorath", "Ornpaeng", "Oudomphonh", "Pakdimounivong", "Phanivong", "Phankham", "Phaophanit", "Phengsavath", "Phetphommasouk", "Phommajack", "Phommasane", "Phommathep", "Phomsouvanh", "Phomvihane", "Phothisarath", "Phoumsavanh", "Phoutthasinh", "Phrasavath", "Rattanavongsa", "Saenbouthalath", "Saengsavang", "Saengsouriya", "Saenthavisouk", "Savang", "Sayasone", "Sayavong", "Saysamongdy", "Saysanasy", "Seeha", "Sengprachanh", "Sengtavisouk", "Siharath ", "Simnouansai", "Siphandon", "Sisoulith", "Siyavong", "Somphonpadee", "Somphousiharath", "Sonexarth", "Souksanh", "Soulignavong", "Southavilay", "Souvannaphouma", "Syrypanha", "Syvongsa", "Tayvihane", "Thammasith", "Thammavong", "Thammavong ", "Thammavongsa", "Thepsenavong", "Thiamphasone", "Thonemany", "Vatthana", "Viravongs", "Vongphachanh", "Vongphakdy", "Vongsamphanh", "Vongsay", "Vongvichit", "Vongvilay", "Vorachith", "Xiengboree"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd2 = rng() % std::size(nm3);
    if (type == 1) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd] + " " + nm3[rnd2];
    } else {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd] + " " + nm3[rnd2];
    }
    return names;
    }
}
