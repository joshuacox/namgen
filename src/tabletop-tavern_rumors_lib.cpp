#include "tabletop-tavern_rumors_lib.h"

#include <array>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 14> kSpeakers = {
    "Two dockhands over watered ale swear",
    "The one-eyed cooper mutters that",
    "A frostbitten trapper insists",
    "Gossip by the hearth claims",
    "The stableboy whispers for a copper that",
    "An off-duty watchman boasts in his cups that",
    "A travelling tinker warns anyone listening that",
    "Old Widow Vane tells the bartender that",
    "A trio of mud-caked prospectors argue whether",
    "The bard tunes a snapped lute string and murmurs",
    "A hooded herbalist trades word that",
    "A half-asleep charcoal burner mumbles that",
    "The innkeeper's parrot keeps repeating that",
    "Notice-board loungers bet three silvers that"
};

constexpr std::array<const char*, 14> kSubjects = {
    "the ruined watchtower on Crow Ridge",
    "the basement beneath the chandler's shop",
    "the old quarry ferry",
    "the magistrate's prize greyhound",
    "the moss-choked millwheel east of town",
    "Baron Kestrel's tax barge",
    "the ironbound fountain in the Old Ward",
    "every crow within five miles of the crossroads",
    "the apothecary's copper still",
    "the sunken chapel belltower",
    "a hooded stranger in velvet spurs",
    "the lantern-lighter's night shift",
    "the northern timber road",
    "the alchemist's condemned greenhouse"
};

constexpr std::array<const char*, 14> kClaims = {
    "echoes with hammered anvil-strokes whenever a storm gathers",
    "changes architecture every third Tuesday after curfew",
    "swallows coin dropped near it and spits out tarnished bone keys",
    "has been quietly buying up every silver mirror in the shire",
    "was spotted moving against the river current without oars",
    "smells strongly of ozone and burnt cinnamon around twilight",
    "guides lost livestock straight to an overgrown marble staircase",
    "pays double wages to recruits who promise never to carry iron",
    "froze solid during midsummer noon without melting a single icicle",
    "speaks three words of High Draconic whenever horses pass by",
    "conceals a bricked-up tunnel leading straight under the keep",
    "marks anyone who camps there with a faint copper handprint",
    "hosts hooded card games where debts are paid in childhood memories",
    "keeps spitting blue sparks down the well shaft after moonrise"
};

template <std::size_t N>
const char* pick(std::mt19937& rng, const std::array<const char*, N>& arr) {
    return arr[std::uniform_int_distribution<std::size_t>(0, N - 1)(rng)];
}

} // namespace

std::string generate_tabletop_tavern_rumors_name(std::mt19937& rng) {
    return std::string(pick(rng, kSpeakers)) + " " + pick(rng, kSubjects) + " " + pick(rng, kClaims) + ".";
}
