#include "elder_scrolls-bosmers_lib.h"
#include <vector>
#include <string>

/*  Data taken directly from the original JavaScript generator.
    The arrays are declared as `static const` so they are constructed once
    and shared across calls.
*/

static const std::vector<std::string> nm1 = {
    "Aen","Aeng","Aga","Agar","Ale","Alen","All","Alli","Alv","Alve","Amr","Amra","Amri","An","Ang","Angl","Angu","Ano","Anor","Anr","Anru","Ar","Ara","Aran","Arat","Ath","Athr","Bae","Baen","Baer","Bar","Bara","Bas","Bast","Ber","Bere","Bol","Bolr","Bolw","Bra","Brag","Bral","Bre","Brel","Bri","Brit","Bro","Brod","Brol","Cae","Caen","Cel","Cele","Cin","Cing","Cle","Clen","Co","Cun","Dae","Daen","Dan","Dang","Den","Dene","Der","Derv","Dir","Dird","Don","Dond","Edo","Edor","Elb","Elbe","Ele","Eleg","Elis","Elo","Elor","Elr","Elri","End","Endr","Eng","Enga","Engo","Eni","Enil","Ent","Enth","Era","Erad","Eras","Eri","Erid","Err","Erra","Ert","Erth","Erv","Erva","Fae","Faen","Fal","Fald","Far","Farg","Fau","Faul","Fil","Fill","Fim","Fimm","Fin","Find","Fit","Fith","For","Foro","Gad","Gadn","Gae","Gael","Gaen","Gal","Galm","Galt","Gaz","Gaza","Gel","Gele","Ger","Gerr","Gir","Gird","Gla","Glar","Glau","Glo","Glon","Gloo","God","Godr","Gor","Gorc","Gun","Gund","Gwi","Gwil","Gwin","Hag","Haga","Hay","Haym","Hin","Hing","Hun","Hund","Karo","Lego","Li","Mae","Maen","Mag","Magl","Mal","Malb","Man","Mank","Mel","Meld","Men","Mene","Min","Mine","Ming","Mon","Mont","Mor","Mort","Nal","Nali","Ned","Nedh","Nir","Nira","Niru","Nor","Nord","Orb","Orbe","Orc","Orch","Pali","Peg","Pega","Per","Pera","Ria","Rin","Rind","Rit","Rith","Ron","Ront","Sil","Syl","Sylc","Syn","Synd","Ta","Tar","Tarh","Tha","Thad","Thae","Thau","Tho","Thor","Thr","Thra","Thu","Thur","Tuu","Tuun","Ulw","Ulwa","Ung","Unge","Ungo","Ungr","Uru","Urun","Uun","Uung","Uur","Uura","Val","Vali"
};

static const std::vector<std::string> nm2 = {
    "adan","adras","aegaer","aen","aer","agar","agon","agor","agoth","al","alas","alem","alorn","alos","an","angirfin","ar","as","asai","ast","born","bros","chalas","cher","chond","chor","dal","dalas","dan","dell","dhel","dil","ding","dinor","dir","dis","dol","dolin","don","dor","dras","driel","duin","dulain","dus","ebros","edhel","egaer","egor","egorn","elas","eleb","eleg","elfin","elor","elorn","elras","engeval","endor","enin","ephor","er","eroth","fin","gaer","gal","gan","glos","gon","gor","gorn","goth","gvir","hadan","halas","haur","helas","helfin","helorn","hen","hendor","hiel","hil","hir","hndil","hor","hragaer","hragoth","hrannir","hroth","iath","iel","ien","il","ilgor","ilon","imir","in","indil","indir","indor","ing","inor","ion","ior","ir","irin","kar","lalos","las","ldol","leb","leg","lem","lern","lgor","lim","lin","lion","lir","llin","llion","lmir","lor","lorn","los","lras","lroth","man","mion","mir","mirn","mo","mon","nagoth","nas","ndal","ndil","ndir","ndis","ndor","ng","ngeval","ngirfin","nil","nim","nir","nis","nlin","nlorn","nnir","nor","och","olim","olin","omlallor","on","ond","onir","onor","or","ore","oren","orm","orn","orolros","oron","os","oth","phor","ragaer","ragar","ralorn","rannir","ras","rast","relor","rfin","riath","rien","rilgor","rim","rin","rindil","ring","rm","rolros","romlallor","rond","ronir","ronor","ros","roth","rron","rthir","sai","smo","sor","tan","th","thadan","thaur","thil","thir","thor","thragoth","throth","uilon","uin","ulain","um","urron","us","van","venin","vir","wing"
};

static const std::vector<std::string> nm5 = {
    "Acorn","Apple","Balf","Bark","Blue","Camo","Dorn","Dusk","Elm","Fern","Forest","Green","Ivy","Lichen","Lumber","Moss","Night","Oak","Oaken","Pine","River","Rose","Sage","Seed","Shady","Soft","Spring","Timber","Willow"
};

static const std::vector<std::string> nm6 = {
    "blossom","branch","brook","dale","grass","grove","hollow","lake","lock","mire","pool","rock","run","scrub","shade","sky","stone","thorn","vale","wind","wing","wood"
};

std::string generate_elder_scrolls_bosmers_name(std::mt19937& rng) {
    // Choose suffix parts (nm5 + nm6)
    std::size_t rnd3 = rng() % nm5.size();
    std::size_t rnd4 = rng() % nm6.size();

    // Choose main parts (nm1 + nm2) – the original JS uses a `type` flag;
    // we always emulate the default (type != 1) behaviour.
    std::size_t rnd = rng() % nm1.size();
    std::size_t rnd2 = rng() % nm2.size();

    std::string name = nm1[rnd] + nm2[rnd2] + " " + nm5[rnd3] + nm6[rnd4];
    return name;
}
