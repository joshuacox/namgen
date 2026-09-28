#include "elder_scrolls-dwemers_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_elder_scrolls_dwemers_name(std::mt19937& rng, int type) {
    static constexpr std::string_view names3[] = {"Aga", "Alno", "Asra", "Aza", "Ba", "Bha", "Bno", "Bre", "Care", "Choa", "Chra", "Chru", "Chze", "Cra", "Csto", "Cza", "Dju", "Do", "Dru", "Dzre", "Ge", "Gra", "Gri", "Gzo", "Ilze", "Inra", "Ishe", "Izvu", "Ja", "Jho", "Jle", "Jra", "Ko", "Kre", "Ksre", "Kzre", "Me", "Mha", "Mro", "Mza", "Nchu", "Nhe", "No", "Nro", "Ra", "Rao", "Rho", "Ryu", "Shra", "Sne", "Stu", "Szo", "Ta", "Tcha", "Tro", "Tze", "Ya", "Ycho", "Ynza", "Yre"};
    static constexpr std::string_view names4[] = {"baln", "bchasz", "bnanch", "bwarn", "dchan", "dlin", "dras", "drunz", "dzach", "fnyg", "frach", "frysz", "furn", "garn", "glan", "glynsh", "grenz", "grozsch", "gwetch", "hatch", "hnch", "hretz", "hron", "huanch", "larn", "lchanf", "lratz", "lrohn", "lzarf", "maratzch", "mgunch", "morn", "mratz", "mrumhz", "nard", "ngnthumz", "nrazg", "nruz", "nrynn", "nzcharn", "rach", "rhytz", "rlakch", "rlatz", "rzhurk", "tarn", "tchatz", "tchzan", "thurzch", "tvar", "varn", "vnorz", "vragch", "vretch", "vzyrn", "zalf", "zchyn", "zhurz", "zlurch", "ztar"};
    static constexpr std::string_view names1_1[] = {"Akna", "Alzi", "Ara", "Azsa", "Blu", "Bri", "Byra", "Bze", "Cfra", "Che", "Chli", "Chro", "Chza", "Cra", "Csi", "Czou", "Da", "Dou", "Dre", "Dri", "Gli", "Go", "Grwe", "Gzi", "Ichu", "Iora", "Irda", "Itho", "Jare", "Jo", "Jri", "Jza", "Ka", "Kri", "Ksho", "Kzua", "Mhe", "Mli", "Mo", "Mra", "Na", "Nhe", "Nra", "Nri", "Rlo", "Rue", "Rya", "Rzu", "Shi", "Shtro", "So", "Stre", "Ta", "Tae", "Tche", "Thri", "Ylre", "Yne", "Yra", "Yzra"};
    static constexpr std::string_view names2_1[] = {"blan", "brina", "bryn", "bwyr", "dhis", "dilan", "dlen", "dryna", "drys", "flis", "frinn", "ftris", "fwinn", "glas", "glern", "grida", "griln", "gven", "gzis", "hken", "hner", "hrada", "hvlin", "hzis", "lamch", "lirda", "llez", "lnif", "lnmer", "mchin", "mdida", "mris", "mtrin", "mzlin", "nadis", "ncha", "nhatch", "nrida", "nvrin", "nwess", "rbira", "rlis", "rloar", "rtes", "rves", "tchis", "thanch", "trech", "trez", "twern", "vlara", "vlen", "vrash", "vrin", "vzal", "zara", "zlen", "znara", "zril", "zshen"};
    static constexpr std::string_view names1_2[] = {"Ancha", "Atha", "Achy", "Agru", "Bla", "Bzra", "Brazze", "Bthu", "Cuo", "Cbra", "Ctu", "Cna", "Chua", "Chra", "Chiu", "Chu", "Dzra", "Da", "Dha", "Du", "Gru", "Gou", "Ghro", "Gha", "Irha", "Igre", "Ingu", "Ihle", "Jna", "Jru", "Jhou", "Jlare", "Ka", "Kagre", "Kla", "Kzya", "Mi", "Mzu", "Mhu", "Mcha", "Nchu", "Nchy", "Ne", "Nevi", "Ra", "Rku", "Rhzo", "Rale", "Sza", "Suo", "Shtra", "Stho", "Tcha", "Tzo", "Tna", "Tugra", "Ya", "Yra", "Ytha", "Yhna"};
    static constexpr std::string_view names2_2[] = {"ban", "bgar", "bond", "brec", "dac", "dchu", "dgir", "dit", "drak", "fgru", "fk", "frak", "fuan", "ggo", "gr", "grac", "grath", "grum", "gvin", "harn", "hlac", "hld", "hrek", "hrk", "lbar", "lchond", "lec", "len", "lzrak", "mac", "mgar", "min", "mrond", "muard", "nac", "nbric", "nch", "nd", "ndam", "nzgar", "rd", "ren", "rhunch", "rk", "rlac", "tchan", "thas", "thld", "thunch", "thzgar", "vin", "vith", "vlar", "vnak", "vraz", "zbrar", "zdir", "zgar", "znak", "zzefk"};

    ArrayView names1; ArrayView names2; std::string names; size_t rnd0 = 0; size_t rnd1 = 0; size_t rnd2 = 0; size_t rnd3 = 0; int i = 0;

    if (type == 1) {
    names1 = make_view(names1_1);
    names2 = make_view(names2_1);
    } else {
    names1 = make_view(names1_2);
    names2 = make_view(names2_2);
    }
i = rng() % 10; {
    rnd0 = rng() % std::size(names1);
    rnd1 = rng() % std::size(names2);
    rnd2 = rng() % std::size(names3);
    rnd3 = rng() % std::size(names4);
    names = names1[rnd0] + names2[rnd1] + " " + names3[rnd2] + names4[rnd3];
    return names;
    }
}
