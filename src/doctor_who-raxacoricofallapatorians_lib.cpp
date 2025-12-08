#include "doctor_who-raxacoricofallapatorians_lib.h"

static const std::vector<std::string> nm1  = {"B","Bl","Br","D","Dr","Gr","G","Gl","J","K","Kr","L","S","Sr","Sl","Tr","Tl"};
static const std::vector<std::string> nm2  = {"a","e","i","o","u","ee","oo","aa"};
static const std::vector<std::string> nm3  = {"cra","ckt","ckto","f","ft","ll","lm","ln","m","n","ne","p","rm","rn","rs","rst","st","s","ss","sp","x","xa"};
static const std::vector<std::string> nm4  = {"B","D","F","G","K","L","M","N","R","T","V"};
static const std::vector<std::string> nm5  = {"a","e","i","o","u","y"};
static const std::vector<std::string> nm6  = {"d","f","g","gg","l","ll","m","mm","ng","nn","r","rr","rm","rn","s","ss","x","ze","z"};
static const std::vector<std::string> nm7  = {"B","Bl","D","Dr","F","Fl","G","Gr","Gl","Kl","L","M","N","T"};
static const std::vector<std::string> nm8  = {"bs","dd","gg","gs","ln","lm","ls","n","ng","rn","rm","rt","tch","sh","ze"};
static const std::vector<std::string> nm9  = {"B","D","G","H","K","L","M","N","P","R","S","Sh"};
static const std::vector<std::string> nm10 = {"a","e","i","o","u"};
static const std::vector<std::string> nm11 = {"bb","bl","gl","gr","gg","kr","kl","kk","lm","ln","lr","ll","pp","pr","pl","rr","rl","ss","t","tl"};
static const std::vector<std::string> nm12 = {"d","l","m","n","s","v"};
static const std::vector<std::string> nm13 = {"eer","en","een"};
static const std::vector<std::string> nm14 = {"B","Bl","D","G","Gl","Gr","Pl","P","Pr","R","S","Sl","T","Tr"};
static const std::vector<std::string> nm15 = {"f","l","m","n","r","s","y"};
static const std::vector<std::string> nm16 = {"B","Bl","C","Ch","F","Fl","Gl","G","H","K","L","M","N","P","R","Sl","S"};
static const std::vector<std::string> nm17 = {"ck","dr","ff","g","gr","kk","l","ll","m","n","pp","rl","st","str","tt","th","v","z"};
static const std::vector<std::string> nm18 = {"","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ar","er","et","ez","at","az","oz","el","al","es","as"};
static const std::vector<std::string> nm19 = {"een","ene"};

static inline std::size_t randIndex(const std::vector<std::string>& vec, std::mt19937& rng) {
    std::uniform_int_distribution<std::size_t> dist(0, vec.size() - 1);
    return dist(rng);
}

std::string generate_doctor_who_raxacoricofallapatorians_name(std::mt19937& rng) {
    // Choose random elements from each array
    const std::string &part1  = nm1[randIndex(nm1, rng)];
    const std::string &part2  = nm2[randIndex(nm2, rng)];
    const std::string &part3  = nm3[randIndex(nm3, rng)];
    const std::string &part4  = nm4[randIndex(nm4, rng)];
    const std::string &part5  = nm5[randIndex(nm5, rng)];
    const std::string &part6  = nm6[randIndex(nm6, rng)];
    const std::string &part7  = nm7[randIndex(nm7, rng)];
    const std::string &part8  = nm10[randIndex(nm10, rng)];
    const std::string &part9  = nm8[randIndex(nm8, rng)];
    const std::string &part10 = nm9[randIndex(nm9, rng)];
    const std::string &part11 = nm10[randIndex(nm10, rng)];
    const std::string &part12 = nm11[randIndex(nm11, rng)];
    const std::string &part13 = nm10[randIndex(nm10, rng)];
    const std::string &part14 = nm12[randIndex(nm12, rng)];
    const std::string &part15 = nm13[randIndex(nm13, rng)];
    const std::string &part16 = nm14[randIndex(nm14, rng)];
    const std::string &part17 = nm10[randIndex(nm10, rng)];
    const std::string &part18 = nm15[randIndex(nm15, rng)];
    const std::string &part19 = nm16[randIndex(nm16, rng)];
    const std::string &part20 = nm10[randIndex(nm10, rng)];
    const std::string &part21 = nm17[randIndex(nm17, rng)];
    const std::string &part22 = nm18[randIndex(nm18, rng)];
    const std::string &part23 = nm19[randIndex(nm19, rng)];

    // Assemble according to the original JS template
    std::string name = part1 + part2 + part3 + " " +
                       part4 + part5 + part6 + " " +
                       part7 + part8 + part9 + " " +
                       part10 + part11 + part12 + part13 + part14 + part15 +
                       "-" + part16 + part17 + part18 + " " +
                       part19 + part20 + part21 + part22 + part23;

    return name;
}
