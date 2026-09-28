#include "pathfinder-tians_lib.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pathfinder_tians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"", "", "", "b", "c", "ch", "d", "g", "h", "kh", "l", "m", "ng", "nh", "ph", "q", "s", "th", "t", "tr", "v", "x"};
    static constexpr std::string_view nm2[] = {"a", "ai", "ao", "i", "ia", "ie", "ieu", "o", "oa", "oai", "u", "ua", "ue", "ui", "uo", "uu"};
    static constexpr std::string_view nm3[] = {"", "c", "n", "ng", "nh", "t", "y"};
    static constexpr std::string_view nm4[] = {"", "", "", "b", "c", "ch", "d", "g", "h", "hy", "k", "kh", "l", "m", "n", "ng", "nh", "ph", "q", "s", "t", "th", "tr", "v", "x", "y"};
    static constexpr std::string_view nm5[] = {"a", "ai", "ao", "au", "e", "h", "i", "ia", "ie", "ieu", "iu", "o", "oa", "u", "ua", "ue", "uo"};
    static constexpr std::string_view nm6[] = {"", "", "", "c", "ch", "m", "n", "ng", "nh", "p", "t", "y"};
    static constexpr std::string_view nm7[] = {"b", "c", "ch", "d", "g", "h", "k", "kh", "l", "m", "ng", "nh", "nz", "ph", "q", "s", "t", "th", "tr", "v"};
    static constexpr std::string_view nm8[] = {"a", "ai", "ao", "au", "i", "ia", "ie", "ieu", "o", "oa", "oi", "oo", "ou", "u", "ua", "ue", "ui", "uo", "uu", "uy", "uye"};
    static constexpr std::string_view nm9[] = {"", "", "c", "ch", "m", "n", "ng", "nh", "p", "y"};
    static constexpr std::string_view nm10[] = {"b", "ch", "chh", "d", "h", "kh", "k", "kr", "l", "m", "n", "ph", "p", "pr", "r", "s", "sr", "th", "v"};
    static constexpr std::string_view nm11[] = {"oeu", "ou", "ea", "ei", "ia", "ao", "au", "ai", "uo", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm12[] = {"b", "ch", "d", "h", "k", "kb", "kd", "kh", "kng", "kr", "ks", "ksm", "ktr", "l", "m", "mb", "ml", "mn", "mph", "mr", "n", "nch", "ngh", "ngs", "nkr", "nl", "nm", "nn", "nr", "ns", "nth", "ntr", "nv", "ny", "p", "ph", "r", "rk", "ry", "s", "sm", "sn", "t", "td", "th", "tt", "v", "y"};
    static constexpr std::string_view nm13[] = {"k", "l", "m", "n", "ng", "nn", "p", "r", "s", "th", "y"};
    static constexpr std::string_view nm14[] = {"b", "ch", "d", "j", "k", "kr", "l", "m", "n", "ph", "p", "r", "s", "sr", "t", "th", "v"};
    static constexpr std::string_view nm15[] = {"b", "ch", "d", "k", "kd", "kh", "kkl", "kr", "kry", "ksm", "l", "ll", "lth", "m", "mb", "md", "mj", "mp", "mph", "mr", "n", "nch", "nd", "ngs", "nkr", "nl", "nm", "nn", "nnl", "nt", "nth", "ntr", "nv", "ny", "p", "ph", "r", "rk", "rph", "rsd", "rt", "rv", "ry", "s", "sm", "sn", "sn", "t", "td", "th", "tr", "tt", "v", "vy", "w", "y", "yh", "ym", "yn", "yp"};
    static constexpr std::string_view nm16[] = {"ch", "k", "kry", "l", "lly", "ly", "m", "mphy", "n", "ng", "nn", "nny", "ny", "ry", "s", "ss", "th", "vy", "y"};
    static constexpr std::string_view nm17[] = {"b", "ch", "chh", "d", "h", "j", "k", "kh", "khl", "l", "m", "nh", "n", "p", "ph", "r", "s", "t", "th", "v", "y"};
    static constexpr std::string_view nm18[] = {"a", "aa", "ae", "ao", "e", "ea", "eo", "i", "ia", "ie", "o", "oe", "ou", "u", "uo"};
    static constexpr std::string_view nm19[] = {"ch", "k", "l", "m", "n", "ng", "r", "rn", "s", "t", "th", "v", "y"};
    static constexpr std::string_view nm20[] = {"b", "by", "ch", "d", "g", "h", "hy", "j", "k", "kw", "ky", "m", "my", "n", "p", "py", "s", "sh", "t", "w", "y"};
    static constexpr std::string_view nm21[] = {"a", "ae", "am", "an", "ang", "e", "ee", "ejun", "eo", "eon", "eong", "eung", "i", "ihu", "ihun", "in", "injae", "injun", "o", "ochun", "ohyon", "on", "ong", "onghyon", "ongmin", "onjun", "onu", "oo", "oon", "oung", "u", "uck", "uk", "ul", "un", "ung", "unghyon", "unho", "unso", "unyong", "uwon"};
    static constexpr std::string_view nm22[] = {"bok", "bong", "cheol", "chol", "chuk", "chul", "dae", "eun", "gi", "gu", "gun", "gyu", "hae", "han", "hee", "heon", "ho", "hoo", "hoon", "hu", "hui", "hun", "hwa", "hwan", "hyeon", "hyok", "hyon", "hyuk", "hyun", "il", "ja", "jae", "jin", "jo", "joon", "jun", "jung", "ki", "kyu", "kyung", "min", "mo", "mun", "nam", "sam", "sang", "seo", "seok", "seon", "seong", "shik", "sik", "song", "soo", "sook", "su", "sun", "sung", "tae", "u", "won", "woo", "wook", "woong", "yeol", "yeon", "yeong", "yol", "yong", "yoon", "young", "yul"};
    static constexpr std::string_view nm23[] = {"b", "ch", "d", "g", "gr", "h", "hy", "j", "k", "ky", "l", "m", "my", "n", "r", "ry", "s", "sh", "t", "w", "y"};
    static constexpr std::string_view nm24[] = {"a", "ae", "am", "an", "ang", "ara", "e", "ee", "eh", "eo", "eon", "eong", "eul", "eum", "eun", "eung", "i", "ihye", "ihyon", "im", "imin", "in", "inji", "inso", "it", "iyeon", "iyong", "iyun", "o", "ohyon", "on", "ong", "oo", "ook", "oon", "oung", "oyon", "oyun", "u", "ubin", "uk", "un", "ung", "unji", "unso"};
    static constexpr std::string_view nm25[] = {"ae", "ah", "ahn", "bi", "bin", "bon", "byul", "chae", "dong", "eum", "eun", "gyo", "gyong", "gyung", "ha", "hae", "hee", "ho", "hui", "hwa", "hyang", "hye", "hyo", "hyun", "hyung", "in", "ja", "jeong", "ji", "jin", "jong", "joo", "joong", "ju", "jung", "kyeong", "kyung", "min", "na", "neul", "ok", "ra", "rae", "rang", "ri", "rim", "rin", "ryung", "seo", "seon", "shil", "so", "song", "soo", "sook", "soon", "su", "suk", "sun", "u", "un", "won", "woo", "woon", "yeon", "yon", "yong", "yoon", "young", "yun", "yung"};
    static constexpr std::string_view nm26[] = {"Ae", "Ah", "An", "Ch'a", "Ch'ae", "Ch'ang", "Ch'o", "Ch'oe", "Ch'on", "Ch'u", "Cha", "Chang", "Changgok", "Che", "Chegal", "Chi", "Chin", "Cho", "Chom", "Chon", "Chong", "Chu", "Chun", "Chung", "Chup", "Chwa", "Eoh", "Ha", "Hae", "Hak", "Ham", "Han", "Ho", "Hong", "Hu", "Hung", "Hwa", "Hwan", "Hwang", "Hwangbo", "Hyon", "Hyong", "Im", "In", "Ka", "Kae", "Kal", "Kam", "Kan", "Kang", "Kangjon", "Ki", "Kil", "Kim", "Ko", "Kok", "Kong", "Ku", "Kuk", "Kum", "Kun", "Kung", "Kwak", "Kwok", "Kwon", "Kye", "Kyo", "Kyon", "Kyong", "Ma", "Mae", "Maeng", "Man", "Mangjol", "Mi", "Min", "Mo", "Mok", "Muk", "Mun", "Myo", "Myong", "Na", "Nae", "Nam", "Namgung", "Nan", "Nang", "No", "Noe", "Nu", "Ogum", "Oh", "Ok", "Om", "On", "Ong", "P'aeng", "P'an", "P'i", "P'il", "P'o", "P'ung", "P'yo", "P'yon", "P'yong", "Pae", "Paek", "Pak", "Pan", "Pang", "Pi", "Pin", "Ping", "Pok", "Pom", "Pong", "Pu", "Pyon", "Ra", "Ran", "Rang", "Ri", "Rim", "Ro", "Roe", "Ru", "Ryang", "Ryo", "Ryom", "Ryon", "Ryong", "Ryu", "Ryuk", "Sa", "Sagong", "Sam", "Sang", "Si", "Sim", "Sin", "Sip", "So", "Sobong", "Sok", "Sol", "Somun", "Son", "Song", "Sonu", "Sop", "Su", "Sun", "Sung", "T'ae", "T'ak", "T'an", "Tae", "Tam", "Tan", "Tang", "To", "Tokko", "Ton", "Tong", "Tongbang", "Tu", "Uh", "Um", "Un", "Wang", "Wi", "Won", "Wu", "Ya", "Yang", "Ye", "Yi", "Yo", "Yom", "Yon", "Yong", "Yop", "Yu", "Yuk", "Yun"};
    static constexpr std::string_view nm27[] = {"", "", "", "b", "c", "ch", "d", "dh", "g", "gh", "h", "j", "k", "kh", "l", "m", "n", "q", "s", "sh", "t", "th", "ts", "x", "y", "z", "zh"};
    static constexpr std::string_view nm28[] = {"aie", "aa", "ei", "aiu", "ua", "uu", "eio", "oi", "ai", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm29[] = {"b", "cch", "ch", "d", "dk", "dy", "g", "gh", "ght", "gm", "gs", "j", "k", "kh", "khg", "khj", "kt", "l", "lb", "lch", "ld", "lg", "lgh", "lj", "lt", "lz", "m", "mb", "ml", "n", "nb", "ndj", "ng", "ngg", "ngs", "nksh", "nt", "nz", "q", "r", "rch", "rd", "rg", "rgh", "rk", "rkh", "rt", "s", "sg", "sh", "sl", "t", "tb", "tg", "tl", "ts", "y", "z", "zb", "zh"};
    static constexpr std::string_view nm30[] = {"", "", "", "d", "g", "gh", "gt", "l", "ld", "m", "n", "nt", "r", "t", "y"};
    static constexpr std::string_view nm31[] = {"", "", "", "b", "ch", "c", "d", "dh", "g", "gh", "h", "j", "k", "kh", "l", "m", "n", "s", "sh", "t", "th", "ts", "y", "z", "zh"};
    static constexpr std::string_view nm32[] = {"aa", "ui", "ei", "oa", "ui", "ai", "uu", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm33[] = {"b", "ch", "d", "dts", "dv", "g", "gch", "gh", "gm", "gtb", "j", "k", "kh", "khg", "khts", "l", "lj", "lm", "lt", "m", "mb", "n", "nb", "nch", "ng", "nkhh", "nkht", "nkhts", "nts", "nts", "nz", "q", "r", "rb", "rd", "rdz", "rg", "rgh", "rm", "rt", "rz", "s", "t", "ts", "tts", "y", "z"};
    static constexpr std::string_view nm34[] = {"", "", "", "d", "g", "gh", "l", "m", "n", "r", "sh"};
    static constexpr std::string_view nm35[] = {"a", "ba", "bai", "be", "bo", "bu", "chi", "da", "dai", "ei", "fu", "ga", "ge", "gi", "go", "ha", "hei", "hi", "ho", "hyo", "i", "ie", "jo", "ju", "ka", "ke", "kei", "ki", "ko", "ku", "kyu", "ma", "mi", "mo", "mu", "na", "nao", "ni", "no", "o", "ri", "ro", "ryo", "ryu", "sa", "se", "sei", "shi", "sho", "shu", "so", "su", "ta", "te", "tei", "to", "tsu", "u", "wa", "ya", "yo", "yu"};
    static constexpr std::string_view nm36[] = {"bumi", "buro", "buru", "chemon", "chi", "chiro", "chiyo", "chizo", "dayu", "deki", "do", "fu", "fumi", "gobei", "goro", "hari", "haru", "hide", "hiko", "hira", "hiro", "hisa", "hito", "ji", "jio", "jiro", "juro", "kado", "kan", "kao", "karu", "kazu", "kei", "ki", "kichi", "kin", "kio", "kira", "ko", "koto", "kuchu", "kudo", "kumi", "kuni", "kusai", "kushi", "kusho", "kuzo", "mane", "maro", "masu", "matsu", "mei", "miaki", "michi", "mio", "mitsu", "mon", "mori", "moru", "moto", "mune", "nabu", "naga", "nari", "nji", "njiro", "nkei", "nko", "nobu", "nori", "noru", "noto", "noye", "npaku", "nshiro", "ntaro", "nzo", "rata", "rei", "ro", "roji", "roshi", "ru", "sada", "sake", "saku", "sami", "samu", "sashi", "sato", "seki", "setsu", "shashi", "shi", "shige", "shiko", "shiro", "sho", "shushu", "soshi", "su", "suke", "suki", "ta", "tada", "taka", "tane", "tari", "taro", "taru", "toki", "toku", "tomo", "tora", "toshi", "tsu", "tsugu", "tsumi", "tsuna", "tsune", "tsuta", "tsuyo", "tzumi", "wane", "yaki", "yasu", "yori", "yoshi", "yuki", "zane", "zo", "zuka", "zuki", "zuko", "zuma", "zumi", "zumo", "zushi"};
    static constexpr std::string_view nm37[] = {"a", "ai", "ba", "be", "chi", "e", "ei", "fu", "ge", "ha", "hai", "hi", "ho", "i", "jo", "ka", "kae", "ki", "ko", "ku", "ma", "mae", "me", "mi", "mo", "mu", "na", "nao", "ni", "no", "o", "rai", "rei", "ri", "ro", "ru", "sa", "sai", "se", "shi", "su", "ta", "te", "to", "tsu", "u", "wa", "ya", "yae", "yo", "yu"};
    static constexpr std::string_view nm38[] = {"bari", "chi", "chiha", "chiho", "chiko", "cho", "deko", "doka", "fumi", "fuyu", "gino", "gusa", "haru", "hiro", "ho", "hoko", "homi", "hori", "jiko", "ka", "kage", "kako", "kami", "kane", "kari", "karu", "kaze", "ki", "kichi", "kiko", "kina", "kio", "kira", "ko", "koto", "kuko", "kuma", "kuro", "kyo", "maki", "mako", "mari", "maya", "meka", "meko", "mi", "miho", "mika", "miki", "miko", "mina", "miri", "miya", "mugi", "na", "nae", "nai", "nako", "nami", "natsu", "neka", "neko", "niko", "no", "noka", "nomi", "noue", "nu", "nuko", "nuye", "nuyo", "ra", "rako", "rante", "rari", "rea", "ri", "rika", "riko", "rime", "rimi", "rino", "risa", "risu", "rize", "ro", "roe", "roko", "romi", "roshi", "ru", "rui", "ruka", "ruko", "rumi", "sa", "sae", "sahi", "saji", "saki", "sako", "sami", "samu", "sano", "sato", "se", "shi", "shiko", "shiyo", "soko", "sono", "suka", "suki", "sumi", "suzu", "taba", "tako", "taru", "to", "tomi", "tomo", "tose", "toshi", "tsu", "tsue", "tsuka", "tsuko", "tsumi", "tsune", "tsuyo", "yaka", "yako", "yame", "yano", "yeko", "yo", "yu", "yuka", "yuki", "yuko", "yume", "yumi", "yuri", "zami", "zu", "zue", "zuki", "zuko", "zumi", "zuru", "zusa"};
    static constexpr std::string_view nm39[] = {"a", "aka", "ama", "ao", "ara", "asa", "ashi", "azu", "chi", "e", "fu", "fuji", "fuku", "furu", "go", "ha", "hagi", "hama", "hara", "hata", "haya", "hi", "hira", "hiro", "ho", "i", "ichi", "iga", "ike", "ima", "ina", "ise", "ishi", "iwa", "ka", "kaga", "kane", "kawa", "ki", "kishi", "kita", "ko", "koya", "ku", "kura", "kuri", "kuro", "kusu", "ma", "mae", "masu", "matsu", "mi", "mika", "miya", "mo", "mori", "mu", "mura", "na", "naga", "naka", "ni", "nishi", "no", "nomu", "nona", "o", "oga", "oka", "oku", "osa", "sa", "saka", "saku", "sawa", "saza", "se", "shi", "shiba", "shima", "shimi", "shimo", "shino", "so", "su", "suga", "sugi", "sumi", "ta", "taba", "tachi", "taga", "taha", "taka", "tama", "tana", "tani", "te", "tera", "to", "toku", "tsu", "u", "ue", "uye", "wa", "waka", "wata", "ya", "yama", "yoko", "yoshi"};
    static constexpr std::string_view nm40[] = {"ba", "bara", "bashi", "bata", "be", "bota", "chi", "chida", "da", "dama", "gai", "gamine", "gano", "gashi", "gata", "gawa", "gi", "guchi", "hara", "hira", "hita", "jima", "jino", "kada", "kaga", "kai", "kaki", "kama", "kami", "kawa", "ki", "kino", "kuchi", "kuda", "kui", "ma", "mada", "magai", "mano", "mari", "matsu", "maya", "mei", "mine", "miya", "mori", "moto", "mura", "naga", "nagi", "nai", "naka", "name", "nda", "ndo", "neko", "nishi", "nno", "no", "ra", "rada", "rai", "rano", "rashi", "rata", "raya", "ri", "rine", "rino", "rita", "roda", "rose", "rota", "ruta", "ruya", "sai", "saki", "sano", "sato", "sawa", "se", "shi", "shida", "shigawa", "shige", "shima", "shino", "shiro", "shita", "suda", "ta", "tani", "to", "tori", "tsuda", "tsuno", "wa", "wano", "wara", "wata", "ya", "yabu", "yake", "yama", "yashi", "yata", "yeda", "yoshi", "zaki", "zuki", "zuma", "zumi"};
    static constexpr std::string_view nm41[] = {"b", "ch", "d", "f", "g", "h", "j", "k", "l", "m", "p", "q", "r", "sh", "s", "t", "ts", "w", "x", "y", "z", "zh"};
    static constexpr std::string_view nm42[] = {"ai", "uo", "ao", "eu", "ia", "ua", "uo", "ei", "ui", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm43[] = {"ch", "d", "g", "h", "j", "k", "l", "m", "n", "nch", "nf", "ng", "ngb", "ngf", "ngg", "ngh", "ngk", "ngl", "ngm", "ngp", "ngq", "ngsh", "ngw", "ngx", "ngzh", "nh", "nj", "nl", "nm", "nsh", "ny", "nz", "q", "r", "sh", "t", "w", "x", "y", "z", "zh"};
    static constexpr std::string_view nm44[] = {"", "", "", "n", "ng"};
    static constexpr std::string_view nm45[] = {"b", "ch", "c", "d", "f", "g", "h", "j", "k", "kw", "l", "m", "n", "p", "q", "r", "sh", "s", "t", "w", "x", "y", "zh", "z"};
    static constexpr std::string_view nm46[] = {"ao", "ua", "ai", "ui", "ia", "ei", "ue", "iu", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm47[] = {"b", "c", "ch", "d", "f", "h", "hw", "j", "k", "l", "m", "n", "nd", "nf", "ng", "ngch", "ngg", "ngh", "ngj", "ngl", "ngm", "ngt", "ngx", "ngy", "ngzh", "nh", "nl", "nm", "nq", "nr", "nt", "nx", "ny", "nzh", "q", "r", "sh", "t", "w", "x", "y", "zh"};
    static constexpr std::string_view nm48[] = {"b", "c", "ch", "d", "f", "g", "h", "hs", "hw", "j", "k", "kh", "kw", "l", "m", "n", "p", "q", "r", "s", "sh", "sz", "t", "ts", "w", "x", "y", "zh", "z"};
    static constexpr std::string_view nm49[] = {"ai", "ao", "au", "ee", "ea", "eo", "eu", "ia", "iao", "ie", "io", "ua", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm50[] = {"b", "c", "d", "dj", "dw", "g", "h", "j", "kr", "k", "p", "r", "s", "sl", "t", "tr", "w", "y"};
    static constexpr std::string_view nm51[] = {"ua", "ia", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm52[] = {"b", "d", "dd", "dw", "g", "h", "hy", "j", "k", "l", "m", "mb", "md", "n", "nd", "ndr", "ngk", "nn", "nt", "o", "r", "rj", "rm", "rn", "rt", "rw", "ry", "s", "sk", "sn", "t", "tr", "v", "w", "y"};
    static constexpr std::string_view nm53[] = {"", "", "", "h", "n", "ng", "r", "s", "t"};
    static constexpr std::string_view nm54[] = {"b", "c", "d", "dw", "f", "gl", "h", "k", "l", "m", "n", "p", "r", "s", "sh", "sr", "tr", "v", "w", "y"};
    static constexpr std::string_view nm55[] = {"ia", "eo", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u"};
    static constexpr std::string_view nm56[] = {"c", "d", "dy", "g", "h", "hy", "k", "l", "m", "nn", "nt", "nd", "ng", "nn", "nt", "r", "rj", "rl", "rm", "rt", "s", "sk", "st", "t", "th", "tn", "tr", "v", "w", "y"};
    static constexpr std::string_view nm57[] = {"", "", "", "h", "n", "r"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; size_t rnd7 = 0; size_t rnd8 = 0; int i = 0;

    i = rng() % 14; {
    if (type == 1) {
    if (i < 2) {
    rnd = rng() % std::size(nm4);
    rnd2 = rng() % std::size(nm5);
    rnd3 = rng() % std::size(nm6);
    if (rnd < 3) {
    while (rnd3 < 3) {
    rnd3 = rng() % std::size(nm6);
    }
    }
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm8);
    rnd6 = rng() % std::size(nm9);
    names = std::string(nm7[rnd4]) + std::string(nm8[rnd5]) + std::string(nm9[rnd6]) + "  " + std::string(nm4[rnd]) + std::string(nm5[rnd2]) + std::string(nm6[rnd3]);
    } else if (i < 4) {
    rnd = rng() % std::size(nm14);
    rnd2 = rng() % std::size(nm11);
    rnd3 = rng() % std::size(nm15);
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm16);
    rnd6 = rng() % std::size(nm17);
    rnd7 = rng() % std::size(nm18);
    rnd8 = rng() % std::size(nm19);
    names = std::string(nm17[rnd6]) + std::string(nm18[rnd7]) + std::string(nm19[rnd8]) + "  " + std::string(nm14[rnd]) + std::string(nm11[rnd2]) + std::string(nm15[rnd3]) + std::string(nm11[rnd4]) + std::string(nm16[rnd5]);
    } else if (i < 6) {
    rnd = rng() % std::size(nm23);
    rnd2 = rng() % std::size(nm24);
    rnd3 = rng() % std::size(nm25);
    rnd4 = rng() % std::size(nm26);
    names = std::string(nm26[rnd4]) + "  " + std::string(nm23[rnd]) + std::string(nm24[rnd2]) + "  " + std::string(nm25[rnd3]);
    } else if (i < 8) {
    rnd = rng() % std::size(nm31);
    rnd2 = rng() % std::size(nm32);
    rnd3 = rng() % std::size(nm33);
    rnd4 = rng() % std::size(nm32);
    rnd5 = rng() % std::size(nm34);
    if (rnd < 3) {
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm34);
    }
    }
    names = std::string(nm31[rnd]) + std::string(nm32[rnd2]) + std::string(nm33[rnd3]) + std::string(nm32[rnd4]) + std::string(nm34[rnd5]);
    } else if (i < 10) {
    rnd = rng() % std::size(nm37);
    rnd2 = rng() % std::size(nm38);
    rnd3 = rng() % std::size(nm39);
    rnd4 = rng() % std::size(nm40);
    names = std::string(nm39[rnd3]) + std::string(nm40[rnd4]) + "  " + std::string(nm37[rnd]) + std::string(nm38[rnd2]);
    } else if (i < 12) {
    rnd = rng() % std::size(nm45);
    rnd2 = rng() % std::size(nm46);
    rnd3 = rng() % std::size(nm47);
    rnd4 = rng() % std::size(nm46);
    rnd5 = rng() % std::size(nm44);
    rnd6 = rng() % std::size(nm48);
    rnd7 = rng() % std::size(nm49);
    names = std::string(nm48[rnd6]) + std::string(nm49[rnd7]) + "  " + std::string(nm45[rnd]) + std::string(nm46[rnd2]) + std::string(nm47[rnd3]) + std::string(nm46[rnd4]) + std::string(nm44[rnd5]);
    } else {
    rnd = rng() % std::size(nm54);
    rnd2 = rng() % std::size(nm55);
    rnd3 = rng() % std::size(nm56);
    rnd4 = rng() % std::size(nm55);
    rnd5 = rng() % std::size(nm57);
    names = std::string(nm54[rnd]) + std::string(nm55[rnd2]) + std::string(nm56[rnd3]) + std::string(nm55[rnd4]) + std::string(nm57[rnd5]);
    }
    } else {
    if (i < 2) {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm3);
    if (rnd < 3) {
    while (rnd3 == 0) {
    rnd3 = rng() % std::size(nm3);
    }
    }
    rnd4 = rng() % std::size(nm7);
    rnd5 = rng() % std::size(nm8);
    rnd6 = rng() % std::size(nm9);
    names = std::string(nm7[rnd4]) + std::string(nm8[rnd5]) + std::string(nm9[rnd6]) + "  " + std::string(nm1[rnd]) + std::string(nm2[rnd2]) + std::string(nm3[rnd3]);
    } else if (i < 4) {
    rnd = rng() % std::size(nm10);
    rnd2 = rng() % std::size(nm11);
    rnd3 = rng() % std::size(nm12);
    rnd4 = rng() % std::size(nm11);
    rnd5 = rng() % std::size(nm13);
    rnd6 = rng() % std::size(nm17);
    rnd7 = rng() % std::size(nm18);
    rnd8 = rng() % std::size(nm19);
    names = std::string(nm17[rnd6]) + std::string(nm18[rnd7]) + std::string(nm19[rnd8]) + "  " + std::string(nm10[rnd]) + std::string(nm11[rnd2]) + std::string(nm12[rnd3]) + std::string(nm11[rnd4]) + std::string(nm13[rnd5]);
    } else if (i < 6) {
    rnd = rng() % std::size(nm20);
    rnd2 = rng() % std::size(nm21);
    rnd3 = rng() % std::size(nm22);
    rnd4 = rng() % std::size(nm26);
    names = std::string(nm26[rnd4]) + "  " + std::string(nm20[rnd]) + std::string(nm21[rnd2]) + "  " + std::string(nm22[rnd3]);
    } else if (i < 8) {
    rnd = rng() % std::size(nm27);
    rnd2 = rng() % std::size(nm28);
    rnd3 = rng() % std::size(nm29);
    rnd4 = rng() % std::size(nm28);
    rnd5 = rng() % std::size(nm30);
    if (rnd < 3) {
    while (rnd5 < 3) {
    rnd5 = rng() % std::size(nm30);
    }
    }
    names = std::string(nm27[rnd]) + std::string(nm28[rnd2]) + std::string(nm29[rnd3]) + std::string(nm28[rnd4]) + std::string(nm30[rnd5]);
    } else if (i < 10) {
    rnd = rng() % std::size(nm35);
    rnd2 = rng() % std::size(nm36);
    rnd3 = rng() % std::size(nm39);
    rnd4 = rng() % std::size(nm40);
    names = std::string(nm39[rnd3]) + std::string(nm40[rnd4]) + "  " + std::string(nm35[rnd]) + std::string(nm36[rnd2]);
    } else if (i < 12) {
    rnd = rng() % std::size(nm41);
    rnd2 = rng() % std::size(nm42);
    rnd3 = rng() % std::size(nm43);
    rnd4 = rng() % std::size(nm42);
    rnd5 = rng() % std::size(nm44);
    rnd6 = rng() % std::size(nm48);
    rnd7 = rng() % std::size(nm49);
    names = std::string(nm48[rnd6]) + std::string(nm49[rnd7]) + "  " + std::string(nm41[rnd]) + std::string(nm42[rnd2]) + std::string(nm43[rnd3]) + std::string(nm42[rnd4]) + std::string(nm44[rnd5]);
    } else {
    rnd = rng() % std::size(nm50);
    rnd2 = rng() % std::size(nm51);
    rnd3 = rng() % std::size(nm52);
    rnd4 = rng() % std::size(nm51);
    rnd5 = rng() % std::size(nm53);
    names = std::string(nm50[rnd]) + std::string(nm51[rnd2]) + std::string(nm52[rnd3]) + std::string(nm51[rnd4]) + std::string(nm53[rnd5]);
    }
    }
    return names;
    }
}
