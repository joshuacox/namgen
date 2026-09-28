import json
import re

with open(".javascript-fantasy-names-deprecated/generators/descriptions/pokemons.js") as f:
    text = f.read()

# 1. Parse all 1D arrays
arrays = {}
for m in re.finditer(r"var\s+([a-zA-Z0-9_]+)\s*=\s*(\[[^\[\]]*\]);", text):
    var_name = m.group(1)
    raw_arr = m.group(2)
    try:
        arrays[var_name] = json.loads(raw_arr)
    except Exception as e:
        pass

# 2. Parse pkm arrays
m = re.search(r"var pkm = \[(.*?)\];\s*var traits", text, re.DOTALL)
pkm_all = json.loads(re.sub(r",\s*([\]\}])", r"\1", "[" + m.group(1) + "]"))

m_bug = re.search(r"if \(pkType === \"bug\"\) \{\s*pkm = \[(.*?)\];\s*rnd1", text, re.DOTALL)
pkm_bug = json.loads(re.sub(r",\s*([\]\}])", r"\1", "[" + m_bug.group(1) + "]"))

m_drg = re.search(r"if \(pkType === \"dragon\"\) \{\s*pkm = \[(.*?)\];\s*rnd1", text, re.DOTALL)
pkm_dragon = json.loads(re.sub(r",\s*([\]\}])", r"\1", "[" + m_drg.group(1) + "]"))

def format_str(s):
    return json.dumps(s)

def format_1d_array(name, arr):
    items = ", ".join(format_str(x) for x in arr)
    return f"static constexpr std::string_view {name}[] = {{{items}}};"

def format_pkm_list(name, pkm_list):
    lines = [f"static constexpr PokemonBase {name}[] = {{"]
    for entry in pkm_list:
        p_name = format_str(entry[0])
        # Pad habitats up to 3
        h_items = [format_str(h) for h in entry[1]]
        num_habs = len(h_items)
        while len(h_items) < 3:
            h_items.append('""')
        habs = "{" + ", ".join(h_items) + "}"
        
        # Pad coverings up to 2
        c_items = [format_str(c) for c in entry[2]]
        num_covs = len(c_items)
        while len(c_items) < 2:
            c_items.append('""')
        covs = "{" + ", ".join(c_items) + "}"
        
        # Pad limbs up to 2
        l_items = [format_str(l) for l in entry[3]]
        num_limbs = len(l_items)
        while len(l_items) < 2:
            l_items.append('""')
        limbs = "{" + ", ".join(l_items) + "}"
        
        head = format_str(entry[4])
        tail = format_str(entry[5])
        ear = format_str(entry[6])
        lines.append(f"    {{{p_name}, {habs}, {num_habs}, {covs}, {num_covs}, {limbs}, {num_limbs}, {head}, {tail}, {ear}}},")
    lines.append("};")
    return "\n".join(lines)

type_mapping = {
    "bug": {"skin": "bugSkin", "legs": "bugLegs", "arms": "bugArms", "wings": "bugWings", "mouth": "bugMouth", "beak": "", "snout": "", "ears": "", "horns": "", "tail": "", "places": "placeBug", "attks": "bugAttk"},
    "dark": {"skin": "darkSkin", "legs": "darkLegs", "arms": "darkArms", "wings": "darkWings", "mouth": "darkMouth", "beak": "darkBeak", "snout": "darkSnout", "ears": "darkEars", "horns": "darkHorns", "tail": "darkTail", "places": "placeDark", "attks": "darkAttk"},
    "dragon": {"skin": "dragonSkin", "legs": "dragonLegs", "arms": "dragonArms", "wings": "dragonWings", "mouth": "dragonMouth", "beak": "", "snout": "", "ears": "dragonEars", "horns": "dragonHorns", "tail": "dragonTail", "places": "placeDragon", "attks": "dragonAttk"},
    "electric": {"skin": "elecSkin", "legs": "elecLegs", "arms": "elecArms", "wings": "elecWings", "mouth": "elecMouth", "beak": "elecBeak", "snout": "elecSnout", "ears": "elecEars", "horns": "elecHorns", "tail": "elecTail", "places": "placeElectric", "attks": "electricAttk"},
    "fairy": {"skin": "fairySkin", "legs": "fairyLegs", "arms": "fairyArms", "wings": "fairyWings", "mouth": "fairyMouth", "beak": "fairyBeak", "snout": "fairySnout", "ears": "fairyEars", "horns": "fairyHorns", "tail": "fairyTail", "places": "placeFairy", "attks": "fairyAttk"},
    "fighting": {"skin": "fightSkin", "legs": "fightLegs", "arms": "fightArms", "wings": "fightWings", "mouth": "fightMouth", "beak": "fightBeak", "snout": "fightSnout", "ears": "fightEars", "horns": "fightHorns", "tail": "fightTail", "places": "placeFighting", "attks": "fightingAttk"},
    "fire": {"skin": "fireSkin", "legs": "fireLegs", "arms": "fireArms", "wings": "fireWings", "mouth": "fireMouth", "beak": "fireBeak", "snout": "fireSnout", "ears": "fireEars", "horns": "fireHorns", "tail": "fireTail", "places": "placeFire", "attks": "fireAttk"},
    "flying": {"skin": "flySkin", "legs": "flyLegs", "arms": "", "wings": "flyWings", "mouth": "flyMouth", "beak": "flyBeak", "snout": "", "ears": "flyEars", "horns": "flyHorns", "tail": "flyTail", "places": "placeFlying", "attks": "flyingAttk"},
    "ghost": {"skin": "ghostSkin", "legs": "ghostLegs", "arms": "ghostArms", "wings": "ghostWings", "mouth": "ghostMouth", "beak": "ghostBeak", "snout": "ghostSnout", "ears": "ghostEars", "horns": "ghostHorns", "tail": "ghostTail", "places": "placeGhost", "attks": "ghostAttk"},
    "grass": {"skin": "grassSkin", "legs": "grassLegs", "arms": "grassArms", "wings": "grassWings", "mouth": "grassMouth", "beak": "grassBeak", "snout": "grassSnout", "ears": "grassEars", "horns": "grassHorns", "tail": "grassTail", "places": "placeGrass", "attks": "grassAttk"},
    "ground": {"skin": "groundSkin", "legs": "groundLegs", "arms": "groundArms", "wings": "", "mouth": "groundMouth", "beak": "groundBeak", "snout": "groundSnout", "ears": "groundEars", "horns": "groundHorns", "tail": "groundTail", "places": "placeGround", "attks": "groundAttk"},
    "ice": {"skin": "iceSkin", "legs": "iceLegs", "arms": "iceArms", "wings": "iceWings", "mouth": "iceMouth", "beak": "iceBeak", "snout": "iceSnout", "ears": "iceEars", "horns": "iceHorns", "tail": "iceTail", "places": "placeIce", "attks": "iceAttk"},
    "normal": {"skin": "normSkin", "legs": "normLegs", "arms": "normArms", "wings": "normWings", "mouth": "normMouth", "beak": "normBeak", "snout": "normSnout", "ears": "normEars", "horns": "normHorns", "tail": "normTail", "places": "placeNormal", "attks": "normalAttk"},
    "poison": {"skin": "poisonSkin", "legs": "poisonLegs", "arms": "poisonArms", "wings": "poisonWings", "mouth": "poisonMouth", "beak": "poisonBeak", "snout": "poisonSnout", "ears": "poisonEars", "horns": "poisonHorns", "tail": "poisonTail", "places": "placePoison", "attks": "poisonAttk"},
    "psychic": {"skin": "psySkin", "legs": "psyLegs", "arms": "psyArms", "wings": "psyWings", "mouth": "psyMouth", "beak": "psyBeak", "snout": "psySnout", "ears": "psyEars", "horns": "psyHorns", "tail": "psyTail", "places": "placePsychic", "attks": "psychicAttk"},
    "rock": {"skin": "rockSkin", "legs": "rockLegs", "arms": "rockArms", "wings": "", "mouth": "rockMouth", "beak": "rockBeak", "snout": "rockSnout", "ears": "rockEars", "horns": "rockHorns", "tail": "rockTail", "places": "placeRock", "attks": "rockAttk"},
    "steel": {"skin": "steelSkin", "legs": "steelLegs", "arms": "steelArms", "wings": "steelWings", "mouth": "steelMouth", "beak": "steelBeak", "snout": "steelSnout", "ears": "steelEars", "horns": "steelHorns", "tail": "steelTail", "places": "placeSteel", "attks": "steelAttk"},
    "water": {"skin": "waterSkin", "legs": "waterLegs", "arms": "waterArms", "wings": "waterWings", "mouth": "waterMouth", "beak": "waterBeak", "snout": "waterSnout", "ears": "waterEars", "horns": "waterHorns", "tail": "waterTail", "places": "placeWater", "attks": "waterAttk"}
}

# Collect all 1D array definitions needed
out = []
out.append('#include "descriptions-pokemons_lib.h"')
out.append('#include "generator_common.h"')
out.append('#include <string_view>')
out.append('#include <string>')
out.append('#include <algorithm>')
out.append('#include <cstdint>')
out.append('')
out.append('struct PokemonBase {')
out.append('    std::string_view name;')
out.append('    std::string_view habitats[3];')
out.append('    uint8_t num_habitats;')
out.append('    std::string_view coverings[2];')
out.append('    uint8_t num_coverings;')
out.append('    std::string_view limbs[2];')
out.append('    uint8_t num_limbs;')
out.append('    std::string_view head;')
out.append('    std::string_view tail;')
out.append('    std::string_view ear;')
out.append('};')
out.append('')
out.append('struct PokemonTypeTables {')
out.append('    std::string_view type_name;')
out.append('    ArrayView skin;')
out.append('    ArrayView legs;')
out.append('    ArrayView arms;')
out.append('    ArrayView wings;')
out.append('    ArrayView mouth;')
out.append('    ArrayView beak;')
out.append('    ArrayView snout;')
out.append('    ArrayView ears;')
out.append('    ArrayView horns;')
out.append('    ArrayView tail;')
out.append('    ArrayView places;')
out.append('    ArrayView attks;')
out.append('};')
out.append('')

# Emit global 1D arrays
for g_arr in ["pers", "amnt", "wtr", "lnd", "air", "evo", "rsm"]:
    out.append(format_1d_array(g_arr, arrays[g_arr]))

# Emit all type-specific 1D arrays
emitted_arrays = set(["pers", "amnt", "wtr", "lnd", "air", "evo", "rsm"])
for t, m in type_mapping.items():
    for f, arr_name in m.items():
        if arr_name and arr_name not in emitted_arrays and arr_name in arrays:
            out.append(format_1d_array(arr_name, arrays[arr_name]))
            emitted_arrays.add(arr_name)

out.append('')
out.append(format_pkm_list("pkm_all", pkm_all))
out.append('')
out.append(format_pkm_list("pkm_bug", pkm_bug))
out.append('')
out.append(format_pkm_list("pkm_dragon", pkm_dragon))
out.append('')

# Emit type_tables array
out.append('static const PokemonTypeTables type_tables[] = {')
for t, m in type_mapping.items():
    def get_view(arr_name):
        return f"make_view({arr_name})" if arr_name else "ArrayView{}"
    
    skin = get_view(m["skin"])
    legs = get_view(m["legs"])
    arms = get_view(m["arms"])
    wings = get_view(m["wings"])
    mouth = get_view(m["mouth"])
    beak = get_view(m["beak"])
    snout = get_view(m["snout"])
    ears = get_view(m["ears"])
    horns = get_view(m["horns"])
    tail = get_view(m["tail"])
    places = get_view(m["places"])
    attks = get_view(m["attks"])
    out.append(f'    {{"{t}", {skin}, {legs}, {arms}, {wings}, {mouth}, {beak}, {snout}, {ears}, {horns}, {tail}, {places}, {attks}}},')
out.append('};')
out.append('')

# Function body
out.append('''std::string generate_descriptions_pokemons_name(std::mt19937& rng) {
    size_t rnPers = rng() % std::size(pers);
    size_t rnAmnt = rng() % std::size(amnt);
    size_t rnEvo = rng() % std::size(evo);
    size_t rnRsm = rng() % std::size(rsm);

    size_t rnd1 = rng() % std::size(pkm_all);
    const PokemonBase* chosen_pkm = &pkm_all[rnd1];

    size_t rnd2 = rng() % chosen_pkm->num_habitats;
    std::string_view habitat = chosen_pkm->habitats[rnd2];

    std::string_view pkType;
    if (habitat == "land") {
        pkType = lnd[rng() % std::size(lnd)];
    } else if (habitat == "water") {
        pkType = wtr[rng() % std::size(wtr)];
    } else {
        pkType = air[rng() % std::size(air)];
    }

    if (pkType == "bug") {
        rnd1 = rng() % std::size(pkm_bug);
        chosen_pkm = &pkm_bug[rnd1];
    } else if (pkType == "dragon") {
        rnd1 = rng() % std::size(pkm_dragon);
        chosen_pkm = &pkm_dragon[rnd1];
    }

    std::string_view candidates[5];
    size_t num_candidates = 0;
    candidates[num_candidates++] = chosen_pkm->coverings[rng() % chosen_pkm->num_coverings];
    candidates[num_candidates++] = chosen_pkm->limbs[rng() % chosen_pkm->num_limbs];
    if (!chosen_pkm->head.empty() && chosen_pkm->head != "none") {
        candidates[num_candidates++] = chosen_pkm->head;
    }
    if (!chosen_pkm->tail.empty() && chosen_pkm->tail != "none") {
        candidates[num_candidates++] = chosen_pkm->tail;
    }
    if (!chosen_pkm->ear.empty() && chosen_pkm->ear != "none") {
        candidates[num_candidates++] = chosen_pkm->ear;
    }

    for (size_t i = 0; i < 3 && i < num_candidates; ++i) {
        size_t j = i + (rng() % (num_candidates - i));
        std::swap(candidates[i], candidates[j]);
    }
    std::string_view traits[3] = { candidates[0], candidates[1], candidates[2] };

    const PokemonTypeTables* cur_tables = nullptr;
    for (const auto& tbl : type_tables) {
        if (tbl.type_name == pkType) {
            cur_tables = &tbl;
            break;
        }
    }

    std::string descrs[3];
    for (int i = 0; i < 3; ++i) {
        std::string_view t = traits[i];
        if (t == "skin" || t == "shell" || t == "hair" || t == "feathers" || t == "hide" || t == "fur" || t == "armor" || t == "scales") {
            descrs[i] = std::string(cur_tables->skin[rng() % cur_tables->skin.size()]) + " " + std::string(t);
        } else if (t == "wings") {
            ArrayView w = cur_tables->wings.empty() ? cur_tables->legs : cur_tables->wings;
            descrs[i] = std::string(w[rng() % w.size()]) + " " + std::string(t);
        } else if (t == "body") {
            ArrayView w = cur_tables->wings.empty() ? cur_tables->legs : cur_tables->wings;
            descrs[i] = "the added bonus of " + std::string(w[rng() % w.size()]) + " wings";
        } else if (t == "legs" || t == "fins") {
            descrs[i] = std::string(cur_tables->legs[rng() % cur_tables->legs.size()]) + " " + std::string(t);
        } else if (t == "arms" || t == "tentacles") {
            ArrayView a = cur_tables->arms.empty() ? cur_tables->legs : cur_tables->arms;
            descrs[i] = std::string(a[rng() % a.size()]) + " " + std::string(t);
        } else if (t == "mouth") {
            descrs[i] = "a " + std::string(cur_tables->mouth[rng() % cur_tables->mouth.size()]) + " " + std::string(t);
        } else if (t == "beak") {
            ArrayView b = cur_tables->beak.empty() ? cur_tables->mouth : cur_tables->beak;
            descrs[i] = "a " + std::string(b[rng() % b.size()]) + " " + std::string(t);
        } else if (t == "snout") {
            ArrayView s = cur_tables->snout.empty() ? cur_tables->mouth : cur_tables->snout;
            descrs[i] = "a " + std::string(s[rng() % s.size()]) + " " + std::string(t);
        } else if (t == "ears") {
            ArrayView e = cur_tables->ears.empty() ? cur_tables->mouth : cur_tables->ears;
            descrs[i] = std::string(e[rng() % e.size()]) + " " + std::string(t);
        } else if (t == "horns") {
            ArrayView h = cur_tables->horns.empty() ? cur_tables->mouth : cur_tables->horns;
            descrs[i] = std::string(h[rng() % h.size()]) + " " + std::string(t);
        } else if (t == "tail") {
            ArrayView tl = cur_tables->tail.empty() ? cur_tables->legs : cur_tables->tail;
            descrs[i] = std::string(tl[rng() % tl.size()]);
        }
    }

    std::string_view place = cur_tables->places[rng() % cur_tables->places.size()];
    size_t attk1 = rng() % cur_tables->attks.size();
    size_t attk2 = rng() % cur_tables->attks.size();
    while (attk1 == attk2) {
        attk2 = rng() % cur_tables->attks.size();
    }
    std::string_view atkOne = cur_tables->attks[attk1];
    std::string_view atkTwo = cur_tables->attks[attk2];

    std::string name = "This Pokemon is a " + std::string(pkType) + "-type Pokemon and " + std::string(rsm[rnRsm]) + " " + std::string(chosen_pkm->name) + ". It has " + descrs[0] + ", " + descrs[1] + " and " + descrs[2] + ".";
    std::string name2 = " They\'re generally " + std::string(pers[rnPers]) + " by nature and can often be found " + std::string(place) + ". If you\'re out looking for them they can often be seen " + std::string(amnt[rnAmnt]) + ".";
    std::string name3 = "It tends to attack with " + std::string(atkOne) + " and " + std::string(atkTwo) + ". It " + std::string(evo[rnEvo]) + ".";

    return name + name2 + "\\n" + name3;
}
''')

with open("src/descriptions-pokemons_lib.cpp", "w") as f:
    f.write("\n".join(out))

print("Successfully wrote src/descriptions-pokemons_lib.cpp")
