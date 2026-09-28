#include "fantasy-harpys_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_fantasy_harpys_name(std::mt19937& rng) {
    static constexpr std::string_view nm1[] = {"Aell", "Aer", "Air", "Ar", "Av", "Bel", "Ber", "Caell", "Cal", "Cec", "Cel", "Crel", "Cyl", "Der", "Des", "Dhon", "Dhyl", "Dor", "Dys", "Faen", "Fean", "Fer", "Flor", "Glor", "God", "Gwyn", "Gyl", "Hell", "Hem", "Heph", "Hyn", "Hyst", "Ial", "Ier", "Ill", "Ion", "Laer", "Lin", "Lor", "Lyn", "Lyph", "Lys", "Lyv", "Maer", "Men", "Mes", "Mor", "Myn", "Nel", "Nell", "Neph", "Ner", "Nor", "Nyph", "Nyr", "Nys", "Oc", "Ocyp", "Oll", "Or", "Orin", "Pel", "Per", "Phel", "Phlor", "Phyn", "Pod", "Sav", "Seph", "Sol", "Syl", "Syr", "Taer", "Ten", "Thel", "Ther", "Thyl", "Tyl", "Typh", "Tyr", "Tyv", "Uem", "Ur", "Uv", "Vael", "Vel", "Ver", "Vol", "Vyn", "Xel", "Xir", "Xyl", "Xyn", "Yen", "Yes", "Yor", "Zean", "Zel", "Zeph", "Zer"};
    static constexpr std::string_view nm2[] = {"a", "aene", "aeno", "alin", "alis", "alle", "ane", "aphe", "aphine", "ara", "arge", "aria", "ase", "asha", "asis", "ea", "eano", "eanor", "efis", "elle", "ena", "enne", "eo", "ephise", "era", "erin", "eris", "ete", "ethe", "evis", "ia", "ial", "ialle", "iana", "iane", "iara", "ie", "ielle", "iene", "inis", "inore", "iphis", "iris", "is", "ise", "o", "oah", "oe", "oelle", "oene", "oinne", "ola", "one", "onia", "ophine", "ophis", "ora", "orena", "oris", "oya", "ya", "yana", "ylia", "ylis", "yne", "ynea", "ynne", "ynore", "yore", "yphe", "yre", "yrea", "yris", "ys", "yth"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; int i = 0;

i = rng() % 10; {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    names = nm1[rnd] + nm2[rnd2];
    return names;
    }
}
