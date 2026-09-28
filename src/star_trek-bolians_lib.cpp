#include "star_trek-bolians_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_star_trek_bolians_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Ado", "Ara", "Ardo", "Ba", "Bo", "Bra", "Che", "Co", "Cra", "Da", "Dai", "Dri", "Ga", "Grai", "Gri", "Ha", "Hi", "Hra", "La", "Li", "Lo", "Ma", "Mai", "Mo", "Na", "Ni", "No", "Oda", "Ori", "Orla", "Qa", "Qe", "Qhi", "Ra", "Rai", "Ri", "Sa", "Sho", "Sra", "The", "To", "Tra", "Va", "Vo", "Vri", "Xa", "Xai", "Xi", "Ya", "Yai", "Ye", "Za", "Zai", "Zi"};
    static constexpr std::string_view nm2[] = {"d", "dar", "daw", "ds", "f", "fe", "fel", "fer", "g", "ge", "gg", "gon", "k", "ken", "kin", "kk", "l", "lar", "ll", "ls", "m", "man", "mix", "ms", "n", "nd", "nn", "nor", "q", "q'no", "q'ra", "q'si", "q'ta", "qar", "r", "ran", "rr", "rs", "s", "sh", "sia", "ss", "t", "thaw", "tix", "tt", "w", "wd", "wer", "ws", "x", "xin", "xor", "xx"};
    static constexpr std::string_view nm3[] = {"Ala", "Ana", "Ara", "Bela", "Bine", "By", "Che", "Cia", "Cila", "Di", "Dire", "Do", "Eli", "Ena", "Era", "Fely", "Fri", "Fy", "Gile", "Go", "Gy", "He", "Hia", "Hira", "Keno", "Kise", "Ky", "Lena", "Lo", "Ly", "Mi", "Mite", "My", "Myne", "Nera", "Ni", "Ny", "Oli", "Ora", "Oshe", "Qena", "Qhi", "Qi", "Rely", "Ri", "Ria", "Se", "Seri", "So", "Tia", "Tri", "Ty", "Veli", "Vira", "Vy", "Wane", "Wile", "Wy", "Ya", "Yle", "Yra", "Ze", "Zi"};
    static constexpr std::string_view nm4[] = {"des", "dia", "dit", "dra", "ha", "hara", "his", "hya", "kena", "kia", "kis", "kye", "lara", "lea", "leya", "lwat", "mena", "mia", "mis", "moya", "na", "ndis", "ndra", "nila", "sea", "sen", "sia", "sina", "tea", "tena", "tia", "tra", "ves", "vil", "vria", "vya", "wela", "wia", "win", "wira", "xea", "xena", "xia", "xis", "zena", "zia", "zila", "zira"};
    static constexpr std::string_view nm5[] = {"Adi", "Ara", "Arli", "Bela", "Bore", "Bro", "Cha", "Chu", "Cora", "Dina", "Do", "Dra", "Era", "Erno", "Esra", "Fera", "Fo", "Fro", "Gadi", "Gara", "Gro", "Ha", "Hera", "Ho", "Kera", "Ki", "Kra", "La", "Lica", "Lyna", "Ma", "Mari", "Mo", "Na", "Ne", "Nora", "Ora", "Orna", "Oro", "Qa", "Qira", "Qo", "Ra", "Re", "Rina", "Sa", "Sina", "So", "Tado", "Tari", "Tra", "Va", "Vade", "Viro", "Wa", "Wera", "Wora", "Xa", "Xira", "Xo", "Za", "Zira", "Zo"};
    static constexpr std::string_view nm6[] = {"d", "das", "dd", "din", "f", "far", "ff", "fit", "g", "gg", "git", "gon", "ha", "har", "hino", "ht", "l", "lar", "lin", "ll", "mar", "min", "mm", "nar", "nat", "nin", "nn", "ra", "ras", "ro", "rr", "sa", "sin", "slo", "ss", "ta", "ten", "tor", "tt", "wa", "was", "wat"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    names = nm3[rnd] + nm4[rnd2] + " " + nm5[rnd3] + nm6[rnd4];
    } else {
    rnd = rng() % std::size(nm1);
    rnd2 = rng() % std::size(nm2);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm6);
    names = nm1[rnd] + nm2[rnd2] + " " + nm5[rnd3] + nm6[rnd4];
    }
    return names;
    }
}
