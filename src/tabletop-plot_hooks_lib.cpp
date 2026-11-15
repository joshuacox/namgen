#include "tabletop-plot_hooks_lib.h"

#include <array>
#include <random>
#include <string>

namespace {

constexpr std::array<const char*, 16> kInciting = {
    "A breathless courier collapses with",
    "A guild archivist secretly offers double coin for",
    "An exiled noble swears a blood-oath to recover",
    "The local magistrate discreetly seals off",
    "At midnight, every bell in town chimes to herald",
    "A retired mercenary confesses on their deathbed about",
    "An inked crow delivers a wax-sealed plea regarding",
    "Caravan guards flee into the gatehouses whispering of",
    "A weeping clockmaker begs adventurers to halt",
    "Three rival factions simultaneously bid for",
    "A sudden eclipse reveals the hidden location of",
    "The temple's sacred brazier turns ice-blue over",
    "A shipwreck washes ashore carrying nothing but",
    "A street urchin picks a pocket and pulls out",
    "During the harvest festival, a sinkhole swallows",
    "A bounty notice penned in silver ink demands proof of"
};

constexpr std::array<const char*, 16> kTarget = {
    "a cracked obsidian signet ring",
    "an unmapped subterranean aqueduct",
    "the tax collector's enchanted ledger",
    "a slumbering brass construct",
    "three stolen star-charts of the First Age",
    "the mayor's missing twin shadow",
    "an ironbound reliquary humming with static",
    "a petrified griffon hatching in the stables",
    "the forgotten deed to the Sunken Bastion",
    "a talking lantern that lies only at dusk",
    "a shipment of unlabeled alchemical vials",
    "an unburned treaty written on dragon hide",
    "the chapel bell's silver clapper",
    "a spectral ferryman demanding forgotten names",
    "a map tattooed across a wooden shield",
    "the last seed of an extinct moon-orchard"
};

constexpr std::array<const char*, 14> kTwist = {
    "before the high tide submerges the vault at dawn",
    "while a doppelganger already sits on the council",
    "though the rightful heir refuses to acknowledge it",
    "as a rival inquisitor band closes in from the north road",
    "even though touching it swaps two allies' voices",
    "only to discover the employer never existed",
    "while every mirror within three leagues clouds with frost",
    "guarded by bind-sworn gargoyles who trade exclusively in secrets",
    "under the shadow of an impending martial curfew",
    "whose true owner was sealed away three centuries ago",
    "unless the party negotiates passage through smuggler tunnels",
    "before the planar convergence locks the gate for a decade",
    "though half the witnesses insist it happened last winter",
    "at the exact crossroads where three fey courts overlap"
};

template <std::size_t N>
const char* pick(std::mt19937& rng, const std::array<const char*, N>& arr) {
    return arr[std::uniform_int_distribution<std::size_t>(0, N - 1)(rng)];
}

} // namespace

std::string generate_tabletop_plot_hooks_name(std::mt19937& rng) {
    return std::string(pick(rng, kInciting)) + " " + pick(rng, kTarget) + ", " + pick(rng, kTwist) + ".";
}
