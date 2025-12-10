#include "halo-mgalekgolos_lib.h"

#include <vector>

std::string generate_halo_mgalekgolos_name(std::mt19937& rng) {
    // Arrays taken directly from the original JavaScript generator
    static const std::vector<std::string> nm1 = {
        "b","d","f","g","h","k","l","m","n","p","r","s","t","w","x","y",
        "","","","","","","","","","","","","","",""
    };
    static const std::vector<std::string> nm2 = {
        "a","e","u","i","o"
    };
    static const std::vector<std::string> nm3 = {
        "b","d","f","g","h","k","l","m","n","p","r","s","t","w","x","y"
    };
    static const std::vector<std::string> nm4 = {
        "b","d","f","g","h","k","l","m","n","p","r","s","t","w","x","y",
        "b","d","f","g","h","k","l","m","n","p","r","s","t","w","x","y",
        "bn","dn","fn","gn","kn","pn","sn","tn","bm","dm","fm","gm","km","pm","sm","tm",
        "bk","dk","lk","mk","nk","pk","sk","tk","bl","fl","gl","pl","tl","xl","sl",
        "bd","gd","fd","ld","pd","sd","xd","bb","dd","ff","gg","kk","ll","mm","nn",
        "pp","rr","ss","tt","ww","br","dr","gr","fr","kr","pr","tr","xr"
    };

    auto randIndex = [&](const std::vector<std::string>& vec) -> size_t {
        std::uniform_int_distribution<std::size_t> dist(0, vec.size() - 1);
        return dist(rng);
    };

    // Build the three words exactly as the JS version does
    std::string word1 = nm1[randIndex(nm1)] + nm2[randIndex(nm2)] + nm3[randIndex(nm3)]
                      + nm2[randIndex(nm2)] + nm3[randIndex(nm3)] + nm2[randIndex(nm2)];

    std::string word2 = nm3[randIndex(nm3)] + nm2[randIndex(nm2)]
                      + nm3[randIndex(nm3)] + nm2[randIndex(nm2)];

    std::string word3 = nm3[randIndex(nm3)] + nm2[randIndex(nm2)]
                      + nm4[randIndex(nm4)] + nm2[randIndex(nm2)];

    return word1 + " " + word2 + " " + word3;
}
