#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "star_wars_the_old_republic-chiss_lib.h"

// The name parts for the Chiss generator.  These are taken directly from the
// original implementation; they are kept unchanged except for the bug‑fix
// below.
static const std::vector<std::string> nm1 = {"B", "C", "D", "G", "H", "J", "K", "M", "N", "P", "R", "S", "T", "V", "W", "Z"};
static const std::vector<std::string> nm2 = {"a", "e", "u", "i", "o", "a", "e", "u", "i", "o", "ra", "re", "ru", "ri", "ro", "la", "le", "lu", "li", "lo"};
static const std::vector<std::string> nm3 = {"th", "tth", "tt", "s", "ss", "sh", "st", "sd", "g", "gh", "w", "q", "qh", "r", "rr", "rs", "rt", "rd", "rg", "rk", "rm", "rn", "c", "rc", "sk", "z", "zz", "m", "mm", "n", "ng"};
static const std::vector<std::string> nm4 = {"i", "a", "o", "e", "u", "", "", "", "", "", "", "", ""};
static const std::vector<std::string> nm5 = {"b","c","d","g","h","m","n","l","p","r","s","t","v","w","z","b","c","d","g","h","m","n","l","p","r","s","t","v","w","z","ab","ac","ad","ag","ah","am","an","al","ap","ar","as","at","av","aw","az","ob","oc","od","og","oh","om","on","ol","op","or","os","ot","ov","ow","oz","ib","ic","id","ig","ih","im","in","il","ip","ir","is","it","iv","iw","iz","eb","ec","ed","eg","eh","em","en","el","ep","er","es","et","ev","ew","ez"};
static const std::vector<std::string> nm6 = {"a","e","u","i","o","a","e","u","i","o","ae","ea","au","ua","ao","oa","ou","uo","ia","ai"};
static const std::vector<std::string> nm7 = {"n","t","th","w","l","m","sh","s","k","w","z","r"};
static const std::vector<std::string> nm8 = {"i","a","o","e","u","","","","","","","","",""};
static const std::vector<std::string> nm9 = {"b","c","d","f","g","h","k","l","m","n","p","r","s","t","v","z","","","","","","","","","",""};
static const std::vector<std::string> nm10 = {"a","e","u","i","o","a","e","u","i","o","ra","re","ru","ri","ro","la","le","lu","li","lo","ae","ea","au","ua","ao","oa","ou","uo","ia","ai"};
static const std::vector<std::string> nm11 = {"th","tth","tt","s","s","s","g","g","r","r","c","c","m","m","n","n","z","z","ss","sh","st","sd","g","gh","w","q","qh","r","rr","rs","rt","rd","rg","rk","rm","rn","c","rc","sk","z","zz","m","mm","n","ng"};
static const std::vector<std::string> nm12 = {"i","a","o","e","u"};
static const std::vector<std::string> nm13 = {"th","tth","tt","s","s","s","g","g","r","r","c","c","m","m","n","n","z","z","ss","sh","st","sd","g","gh","w","q","qh","r","rr","rs","rt","rd","rg","rk","rm","rn","c","rc","sk","z","zz","m","mm","n","ng","","","","","","','','','','','','','','','','','','','','','','','','','','','','','','','','"};
static const std::vector<std::string> nm14 = {"i","a","o","e","u","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};

/**
 * @brief Generate a single Chiss name.
 *
 * The original implementation mistakenly used a single random index (`rnd`)
 * for *all* of the name parts, which caused out‑of‑bounds accesses when the
 * random value was larger than the size of some of the vectors.  The fix
 * is to use a distinct random index for each vector (rnd1 … rnd14).
 *
 * @param rng A reference to a seeded std::mt19937 random number generator.
 * @return A generated Chiss name.
 */
std::string generate_star_wars_the_old_republic_chiss_name(std::mt19937& rng) {
    // Generate a random index for each name‑part vector.
    const int rnd1  = std::uniform_int_distribution<int>(0, static_cast<int>(nm1.size())  - 1)(rng);
    const int rnd2  = std::uniform_int_distribution<int>(0, static_cast<int>(nm2.size())  - 1)(rng);
    const int rnd3  = std::uniform_int_distribution<int>(0, static_cast<int>(nm3.size())  - 1)(rng);
    const int rnd4  = std::uniform_int_distribution<int>(0, static_cast<int>(nm4.size())  - 1)(rng);
    const int rnd5  = std::uniform_int_distribution<int>(0, static_cast<int>(nm5.size())  - 1)(rng);
    const int rnd6  = std::uniform_int_distribution<int>(0, static_cast<int>(nm6.size())  - 1)(rng);
    const int rnd7  = std::uniform_int_distribution<int>(0, static_cast<int>(nm7.size())  - 1)(rng);
    const int rnd8  = std::uniform_int_distribution<int>(0, static_cast<int>(nm8.size())  - 1)(rng);
    const int rnd9  = std::uniform_int_distribution<int>(0, static_cast<int>(nm9.size())  - 1)(rng);
    const int rnd10 = std::uniform_int_distribution<int>(0, static_cast<int>(nm10.size()) - 1)(rng);
    const int rnd11 = std::uniform_int_distribution<int>(0, static_cast<int>(nm11.size()) - 1)(rng);
    const int rnd12 = std::uniform_int_distribution<int>(0, static_cast<int>(nm12.size()) - 1)(rng);
    const int rnd13 = std::uniform_int_distribution<int>(0, static_cast<int>(nm13.size()) - 1)(rng);
    const int rnd14 = std::uniform_int_distribution<int>(0, static_cast<int>(nm14.size()) - 1)(rng);

    // Assemble the name.  The original format inserts an apostrophe after the
    // fourth and eighth parts.
    return nm1[rnd1] + nm2[rnd2] + nm3[rnd3] + nm4[rnd4] + "'" +
           nm5[rnd5] + nm6[rnd6] + nm7[rnd7] + nm8[rnd8] + "'" +
           nm9[rnd9] + nm10[rnd10] + nm11[rnd11] + nm12[rnd12] + nm13[rnd13] + nm14[rnd14];
}
