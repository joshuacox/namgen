#include "descriptions-plants_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_descriptions_plants_name(std::mt19937& rng) {
    static constexpr std::string_view names1[] = {"Briza", "Brodiaea", "Browallia", "Brugmansia", "Buddleia", "Bumelia", "Buxus", "Caladium", "Calamagrostis", "Calendula", "Callicarpa", "Callistephus", "Calodecedrus", "Calochortus", "Calonyction", "Caltha", "Calycanthus", "Camassia", "Campanula", "Campsis", "Canna", "Cardiucrinum", "Carduus", "Carex", "Carpinus", "Carum", "Carya", "Caryopteris", "Cassia", "Castanea", "Castilleja", "Catalpa", "Catharanthus", "Ceanothus", "Cedrela", "Cedrus", "Celastrus", "Celosia", "Celtis", "Centaurea", "Centranthus", "Cephalanthus", "Ceratiola", "Cercidiphyllum", "Cercic", "Chamaecyperai", "Chamaecyparis", "Chasmanthe", "Chelone", "Chionanthus", "Chionodoxa", "Chlidanthus", "Chrysanthemum", "Chrysogonum", "Chicorium", "Cimicifuga", "Cladrastis", "Claytonia", "Clematis", "Cleome", "Clerodendrum", "Clethra", "Clifonia", "Clitoria", "Clivia", "Cobaena", "Cocculus", "Coix", "Colchicum", "Coleus", "Colocasia", "Commelina", "Conopholis", "Conradina", "Convallaria", "Coreopsis", "Coriandrum", "Cornus", "Cortaderia", "Corylorsis", "Corylus", "Cosmos", "Cotinus", "Cotoneaster", "Crataegus", "Cronum", "Crocosmia", "Crocus", "Cryptomeria", "Cunninghamia", "Cuphea", "Cupressus", "Curcuma", "Curtonus", "Cyclamen", "Cydonia", "Cymbopogon", "Cypredium", "Cyressus", "Cyrilla", "Dahlia", "Danae", "Daphne", "Datura", "Daucus", "Davidia", "Decumaria", "Delphinium", "Dandranthema", "Dennstaedtia", "Dentaria", "Deparia", "Deschampsia", "Desmodium", "Deutzia", "Dianthus", "Diascia", "Dicentra", "Dichichium", "Dichromena", "Doctamnus", "Diervilla", "Dietes", "Digitalis", "Diodia", "Dionaea", "Diospyros", "Dipelta", "Diphelleia", "Diplazium", "Disanthus", "Disporum", "Dodecatheon", "Dilochos", "Doronucum", "Drosera", "Dryopteris", "Duchesnea", "Duranta", "Dyssodia", "Eccremocarpus", "Echinecea", "Ehinops", "Echium", "Ehretia", "Eichornia", "Elaegnus", "Eleagnus", "Eleocharis", "Elymus", "Enkianthus", "Epifagus", "Epigaea", "Epilobium", "Epimedium", "Equisetum", "Eragrostrum", "Eranthis", "Eremurus", "Erianthus", "Erigeron", "Eriobotrya", "Eriocaulon", "Eriophorum", "Erysimum", "Erythronium", "Escallonia", "Eschscholzia", "Eucalyptus", "Eacharis", "Eucomis", "Eucommia", "Ecrosia", "Euonymus", "Eupotorium", "Eophorbia", "Euptellea", "Euryale", "Escaphis", "Evodia", "Evolvulus", "Exochorda", "Fagopyrum", "Fagus", "Falluiga", "Fathsedera", "Fatsia", "Feijoa", "Festuca", "Ficus", "Filipendula", "Firmiana", "Foeniculum", "Fontanesia", "Forsythia", "Fothergilla", "Fragaria", "Franklinia", "Fraxinus", "Freesia", "Fritillaria", "Fuchsia", "Gaillardia", "Galactia", "Galanthus", "Galax", "Galearis", "Galium", "Galtonia", "Gardenia"};
    static constexpr std::string_view names2[] = {"Ligustrina", "Ciliata", "Clethroides", "Numularia", "Quadrifolia", "Salicaria", "Amuremsis", "Pomifera", "Loebneri", "Acuminata", "Cylindrica", "Denudata", "Fraseri", "Kobus", "Liliflora", "Macrophylla", "Stella", "Tripetala", "Soulangiana", "Aquifolium", "Bealei", "Hortensis", "Halliana", "Hupehensis", "Yannanensis", "Moschata", "Arboreus", "Amabalis", "Graminifolia", "Carolinensis", "Recutita", "Struthiopteris", "Betonicifolia", "Paludosum", "Lineare", "Pratense", "Azadarach", "Ciliata", "Spicata", "Piperita", "Glyptostroboides", "Yunnanensis", "Decussata", "Lobata", "Verna", "Jalapa", "Floridulus", "Sinensis", "Transmorrisonensis", "Diphylla", "Caerulea", "Laevis", "Didyma", "Punctata", "Capillaris", "Armeniacum", "Botryoides", "Comosum", "Sylvatica", "Cerifera", "Domestica", "Tenuissima", "Lutea", "Strumosa", "Menziesii", "Faasenii", "Bowdenii", "Oleander", "Hippomanica", "Damascena", "Colorata", "Odorata", "Marliacea", "Pelatum", "Ogeche", "Biennis", "Fruticosa", "Speciosa", "Tetragona", "Linifolia", "Sensibilis", "Jaburan", "Majorana", "Vulgare", "Delavayi", "Fragrans", "Cinnamomea", "Claytoniana", "Hyoseroides", "Crassipes", "Violacea", "Arboreum", "Caeruleum", "Procumbens", "Terminalis", "Pandorana", "Virgatum", "Somniferum", "Asarifolia", "Persica", "Integrifolium", "Tricuspidata", "Incarnata", "Peltatum", "Hortorum", "Alopecuroides", "Setaceum", "Canescens", "Cobaea", "Atriplicifolia", "Borbonia", "Palustris", "Crispum", "Hybrida", "Bipinnatifida", "Purshii", "Arundarinacea", "Arundinaera", "Coccineus", "Hexagonoptera", "Sachalinense", "Amurense", "Coronarius", "Delavayi", "Inodorus", "Lemoinei", "Divaricata", "Glaberrima", "Paniculata", "Stolonifera", "Subulata", "Glabra", "Serrulata", "Villosa", "Fraseri", "Opulifolius", "Abies", "Asperata", "Glauca", "Mariana", "Omorika", "Ailanthoides", "Floribunda", "Officnarum", "Anisum", "Caerulea", "Baksiana", "Bungeana", "Cembra", "Densiflora", "Echinata", "Edulis", "Flexilis", "Heldreichii", "Korariensis", "Monticola", "Mugo", "Palustris", "Parviflora", "Peucea", "Piaster", "Ponderosa", "Rigida", "Strobus", "Sylvestris", "Taeda", "Thunbergiana", "Wallichiana", "Yunnanensis", "Stratiotes", "Tobira", "Psycodes", "Ciliaris", "Orbiculata", "Acerifolia", "Argentatus", "Fosteri", "Auricoma", "Variegatus", "Auriculata", "Macrophyllus", "Peltatum", "Hydrengeoides", "Campanulata", "Laustris", "Incana", "Intergrifolia", "Serrata", "Makinoi", "Spectabile", "Spurium", "Telepnoides", "Ternatum", "Tetractinum", "Aureus", "Giagenteum", "Punicea", "Pallida", "Galacifolia", "Intergrifolium", "Terebinthinaceum", "Rehdreriana", "Angustifolium"};
    static constexpr std::string_view names3[] = {"an extremely common", "a very common", "a common", "an uncommon", "a rare", "a very rare", "an extremely rare"};
    static constexpr std::string_view names4[] = {"tiny", "small", "modest", "medium-sized", "large", "tall", "giant", "huge"};
    static constexpr std::string_view names5_1[] = {"almost anywhere", "in most hot regions", "in most wet regions", "anywhere near rivers and lakes", "anywhere near rivers", "anywhere near lakes", "anywhere near the sea", "in most dry regions", "virtually anywhere", "in caves and other dark places", "in dark and wet places", "in damp places", "in any cold region", "in most mountains", "mostly on tropical islands", "in most jungles", "in most forests", "in most tropical regions", "in most humid regions", "in most highlands", "in most snowy regions", "in most subarctic regions", "mostly in swamps", "mostly in savannas", "mostly in tundras"};
    static constexpr std::string_view names6_1[] = {"in early spring", "in late spring", "in early summer", "in late summer", "in early autumn", "in late autumn", "in early winter", "in late winter", "once a year, for 1 month", "twice a year, for 1 week", "once a year, for 1 week", "once a year, for 2 weeks", "once a year, for 3 weeks", "twice a year, for 2 weeks", "twice a year, for 3 weeks", "twice a year, for 1 month", "twice a year, for 2 months", "once a year, for 2 months", "once a year, for 3 months", "once a year, for 4 months", "once a year, for 5 months", "once a year, for 6 months"};
    static constexpr std::string_view names7[] = {"dark green", "light green", "emerald", "lime green", "mint green", "pine green", "yellow-green", "blue-green", "olive-green", "forest green", "bright green", "dark red", "dark yellow", "light red", "light yellow", "green and white", "purple", "dark orange", "light orange"};
    static constexpr std::string_view names8[] = {"small", "large", "tiny", "huge", "thin", "thick", "narrow", "wide"};
    static constexpr std::string_view names9[] = {"barb shaped", "blunt tipped", "circular", "diamond shaped", "egg shaped", "elliptic", "fan shaped", "heart shaped", "kidney shaped", "lobed", "needle", "oval", "paired", "palmate", "pointed", "rosette", "round", "sickle shaped", "spear shaped", "spoon shaped", "squared", "toothed", "triangular", "trifoliate", "wedge shaped"};
    static constexpr std::string_view names10[] = {"small", "large", "tiny", "huge", "decent sized", "quite large", "quite small"};
    static constexpr std::string_view names11a[] = {"black", "blue", "bronze", "brown", "gold", "grey", "orange", "pink", "purple", "red", "silver", "white", "yellow", "dark blue", "dark bronze", "dark brown", "dark gold", "dark grey", "dark orange", "dark pink", "dark purple", "dark red", "dark silver", "dark yellow", "light blue", "light bronze", "light brown", "light gold", "light grey", "light orange", "light pink", "light purple", "light red", "light silver", "light yellow"};
    static constexpr std::string_view names11b[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names11c[] = {", black", ", blue", ", bronze", ", brown", ", gold", ", grey", ", orange", ", pink", ", purple", ", red", ", silver", ", white", ", yellow", ", dark blue", ", dark bronze", ", dark brown", ", dark gold", ", dark grey", ", dark orange", ", dark pink", ", dark purple", ", dark red", ", dark silver", ", dark yellow", ", light blue", ", light bronze", ", light brown", ", light gold", ", light grey", ", light orange", ", light pink", ", light purple", ", light red", ", light silver", ", light yellow", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
    static constexpr std::string_view names11d[] = {"black", " and blue", " and bronze", " and brown", " and gold", " and grey", " and orange", " and pink", " and purple", " and red", " and silver", " and white", " and yellow", " and dark blue", " and dark bronze", " and dark brown", " and dark gold", " and dark grey", " and dark orange", " and dark pink", " and dark purple", " and dark red", " and dark silver", " and dark yellow", " and light blue", " and light bronze", " and light brown", " and light gold", " and light grey", " and light orange", " and light pink", " and light purple", " and light red", " and light silver", " and light yellow"};
    static constexpr std::string_view names12_1[] = {"in huge numbers", "in decent numbers", "in small numbers", "in small groups", "in large groups", "within short distances from each other", "separated by a fair distance from each other", "in huge groups", "in tiny groups", "alone, but within a decent distance from each other"};
    static constexpr std::string_view names13[] = {"hard", "easy", "fairly easy", "fairly hard", "really tricky", "tricky", "a bit tricky", "really difficult", "extremely difficult", "near impossible", "extremely easy", "fairly simple", "hard, especially without experience,", "easy, even without experience,", "challenging", "tough", "very easy", "complicated", "no trouble", "quite straightforward"};
    static constexpr std::string_view names14[] = {"can be brewed as tea", "can be cooked and eaten", "can be used as medicine", "have no use, but look nice in gardens", "have no real use, besides their aesthetics", "have no use, but smell nice", "can be used to clean land", "can be used as an energizer when eaten", "can be used as an energizer when drunk as tea", "can be used as a hallucinogen", "can be used as an anesthetic", "can be used as a cooking ingredient, similar to herbs", "can be dried and used in cooking", "can be used to help relief pain", "can be used to relax", "can be used to treat wounds", "can be eaten to relief a sore throat", "can be eaten to relief stomach cramps", "have no real use", "can be used to create a poison"};
    static constexpr std::string_view names15[] = {"grows tiny thorns", "grows small thorns", "grows large thorns", "grows thick thorns", "tastes horrible, when eaten raw", "grows stinging hairs, like a nettle", "is poisonous for most creatures", "taste extremely sour", "taste very bitter", "has a thick, wooden stem", "produces a thick, sticky wax", "grow slippery leaves to prevent insects from easily eaten them", "can collapse its flowers when it detects vibrations", "mimics the overall look of a different, poisonous plant", "relies mostly on its surroundings to survive"};
    static constexpr std::string_view names16[] = {"animal pollination", "wind pollination", "self pollination", "water currents to carry their seeds away", "winds to carry their seeds away", "cloning themselves by growing a new specimen"};
    static constexpr std::string_view names17_1[] = {"Once pollinated, they grow delicious, small fruits.", "Once pollinated, they grow small, inedible fruits.", "Once pollinated, they grow fairly large, delicious fruits.", "Once pollinated, they grow fairly large, inedible fruits.", "Once pollinated, they grow small, delicious nuts.", "Once pollinated, they grow small, inedible nuts.", "Once pollinated, they grow fairly large, delicious nuts.", "Once pollinated, they grow fairly large, inedible nuts."};
    static constexpr std::string_view names5_2[] = {"only in very hot regions", "only in very wet regions", "only at lake borders", "only at river borders", "only near very large lakes", "only near sea dunes", "only in very dry region", "only in caves", "only in dark, shadowy places", "almost exclusively in dark caves", "only in very damp places", "only in very cold regions", "only high in the mountains", "only on mountain tops", "only on large tropical islands", "only on small tropical islands", "only in some jungles", "only in some forests", "only in some tropical regions", "only in some humid regions", "only in some highlands", "only in some snowy regions", "only in some subarctic regions", "only deep within swamps", "only in some savannas", "only in some tundras", "only in frozen lands", "only near volcanoes", "only deep within caves", "only in deserts"};
    static constexpr std::string_view names5_3[] = {"only on a few dozen islands", "only near graves", "only on a few mountains", "only in one large forest", "only in a few forests", "on the borders of only a few lakes", "on the borders of only a few rivers", "in the dunes of only a few ocean shores", "in only one region of the world", "in only one country", "next to just a few volcanoes", "in only the harshest lands", "only deep within murky swamps", "only deep within the darkest forests", "only deep within the darkest caves", "only in desert oases", "only on the tops of the highest mountains", "only at the bottom of deep cave systems", "only in the coldest regions", "only where something has died and decayed", "only near frozen lakes", "only on putrefied soil", "only after a fire", "only after a flood", "only in one mountain range", "only in ponds"};
    static constexpr std::string_view names6_2[] = {"in early spring", "in late spring", "in early summer", "in late summer", "in early autumn", "in late autumn", "in early winter", "in late winter", "once a year, for 1 month", "twice a year, for 1 week", "once a year, for 1 week", "once a year, for 2 weeks", "once a year, for 3 weeks"};
    static constexpr std::string_view names12_2[] = {"in small numbers", "in small groups", "within short distances from each other", "seperated by a fair distance from each other", "in tiny groups", "alone, but within a decent distance from each other", "alone, often without another in sight", "within a few feet/decimetres from each other", "alone, usually without another specimen around", "in pairs"};
    static constexpr std::string_view names5_4[] = {"exclusively on one island", "exclusively on one mountain", "only in one forest", "exclusively near one lake", "on the borders of only one large lake", "on the borders of only one small lake", "on the borders of only one large river", "on the borders of only one small river", "in the dunes of only one sea shore", "in only one region of the world", "in only one country", "next to one large volcano", "next to one small volcano", "in only one town", "in only one city", "in only the harshest lands", "only deep within a murky swamp", "only deep within a dark forest", "only deep within a dark cave", "only in one desert oasis", "only on the top of the highest mountain", "only at the bottom of a deep cave system", "only in the coldest region", "only where something has died and decayed", "only near graves", "only on putrefied soil", "only in the ashes of a fire", "only after a flood", "only in the gardens of a few lucky people", "exclusively in the garden of one person"};
    static constexpr std::string_view names6_3[] = {"in early spring", "in late spring", "in early summer", "in late summer", "in early autumn", "in late autumn", "in early winter", "in late winter", "once a year, for 1 month", "twice a year, for 1 week", "once a year, for 1 week", "once a year, for 2 weeks", "once a year, for 3 weeks"};
    static constexpr std::string_view names12_3[] = {"in small numbers", "in small groups", "within short distances from each other", "seperated by a fair distance from each other", "in tiny groups", "alone, but within a decent distance from each other", "alone, often without another in sight", "within a few feet/decimetres from each other", "alone, usually without another specimen around", "in pairs"};
    static constexpr std::string_view names17_2[] = {"Once pollinated, they grow delicious, small fruits.", "Once pollinated, they grow small, inedible fruits.", "Once pollinated, they grow fairly large, delicious fruits.", "Once pollinated, they grow fairly large, inedible fruits.", "Once pollinated, they grow small, delicious nuts.", "Once pollinated, they grow small, inedible nuts.", "Once pollinated, they grow fairly large, delicious nuts.", "Once pollinated, they grow fairly large, inedible nuts.", "To promote pollination, they give of a delicate smell.", "To promote pollination, they produce aromatic scents.", "To promote pollination, they produce a delicious nectar."};
    static constexpr std::string_view names17_3[] = {""};

    ArrayView names12; ArrayView names17; ArrayView names5; ArrayView names6; std::string name; std::string name2; std::string name3; std::string name4; std::string name5; std::string name6; std::string result; size_t random1 = 0; size_t random10 = 0; size_t random11a = 0; size_t random11b = 0; size_t random11c = 0; size_t random11d = 0; size_t random11e = 0; size_t random12 = 0; size_t random13 = 0; size_t random14 = 0; size_t random15 = 0; size_t random16 = 0; size_t random17 = 0; size_t random2 = 0; size_t random2b = 0; size_t random3 = 0; size_t random4 = 0; size_t random5 = 0; size_t random6 = 0; size_t random7 = 0; size_t random8 = 0; size_t random9 = 0; int i = 0;

    names5 = make_view(names5_1);
    names6 = make_view(names6_1);
    names12 = make_view(names12_1);
    names17 = make_view(names17_1);
    random1 = rng() % std::size(names1);
    random2 = rng() % std::size(names2);
    random3 = rng() % std::size(names3);
    if (random3 > 2 && random3 < 5) {
    names5 = make_view(names5_2);
    } else if (random1 == 5) {
    names5 = make_view(names5_3);
    names6 = make_view(names6_2);
    names12 = make_view(names12_2);
    } else if (random1 == 6) {
    names5 = make_view(names5_4);
    names6 = make_view(names6_3);
    names12 = make_view(names12_3);
    }
    random4 = rng() % std::size(names4);
    random5 = rng() % std::size(names5);
    random6 = rng() % std::size(names6);
    random7 = rng() % std::size(names7);
    random8 = rng() % std::size(names8);
    random9 = rng() % std::size(names9);
    random10 = rng() % std::size(names10);
    random11a = rng() % std::size(names11a);
    random11b = rng() % std::size(names11b);
    while (random11b == random11a) {
    random2b = rng() % std::size(names11b);
    }
    random11c = rng() % std::size(names11c);
    while (random11c == random11a || random11c == random11b) {
    random11c = rng() % std::size(names11c);
    }
    random11d = rng() % std::size(names11c);
    while (random11d == random11a || random11d == random11b || random11d == random11c) {
    random11d = rng() % std::size(names11c);
    }
    random11e = rng() % std::size(names11d);
    while (random11e == random11a || random11e == random11b || random11e == random11c || random11e == random11d) {
    random11e = rng() % std::size(names11d);
    }
    random12 = rng() % std::size(names12);
    random13 = rng() % std::size(names13);
    random14 = rng() % std::size(names14);
    random15 = rng() % std::size(names15);
    random16 = rng() % std::size(names16);
    if (random16 == 0) {
    names17 = make_view(names17_2);
    } else if (random16 == 5) {
    names17 = make_view(names17_3);
    }
    random17 = rng() % std::size(names17);
    name = "The " + names1[random1] + " " + names2[random2] + " is " + names3[random3] + ", " + names4[random4] + " plant and can be found " + names5[random5] + ". It blooms " + names6[random6] + ".";
    name2 = "It has " + names8[random8] + ", " + names9[random9] + " leaves, which are usually " + names7[random7] + ". It also grows " + names10[random10] + " flowers, which can be " + names11a[random11a] + names11b[random11b] + names11c[random11c] + names11c[random11d] + names11d[random11e] + ".";
    name3 = "These plants grow " + names12[random12] + ", but it's " + names13[random13] + " to control and maintain their growth.";
    name4 = "They " + names14[random14] + ".";
    name5 = "As a defense mechanism the " + names1[random1] + " " + names2[random2] + " " + names15[random15] + ".";
    name6 = "They rely on " + names16[random16] + " to reproduce. " + names17[random17];
    result = "";
    result += name;
    result += "\n";
    result += name2;
    result += "\n";
    result += "\n";
    result += name3;
    result += "\n";
    result += name4;
    result += "\n";
    result += "\n";
    result += name5;
    result += "\n";
    result += name6;
    return result;
}
