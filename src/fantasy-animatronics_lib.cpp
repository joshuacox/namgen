#include "fantasy-animatronics_lib.h"

#include <vector>
#include <string>

/* Implementation mirrors the original JavaScript generator:
 *
 *   function generator$fantasy$animatronics(type) {
 *       var nm1 = [ [prefixes..., suffixes...] , ... ];
 *       var nm2 = [ [alt_prefixes..., alt_suffixes...] , ... ];
 *       i = Math.floor(Math.random() * 10);
 *       if (type === 1) {
 *           // pick from nm2
 *       } else {
 *           // pick from nm1
 *       }
 *       return prefix + " " + suffix;
 *   }
 *
 * The C++ version follows the same logic, using the supplied RNG.
 */
std::string generate_fantasy_animatronics_name(std::mt19937& rng, int type) {
    // Each entry contains a pair: first vector = possible prefixes,
    // second vector = possible suffixes.
    static const std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> nm1 = {
        {
            {
                "Abalone", "Ace the", "Achilles", "Acro the", "Acrobat", "Admiral",
                "Ajax the", "Alfie", "Alistair", "Alpha", "Ammo the", "Angel",
                "Anger the", "Apache the", "Apollo the", "Apple", "Aragog the",
                "Archer the", "Arrow the", "Artemis", "Artic", "Ash the", "Ashes",
                "Aslan the", "Asterix", "Astro the", "Athene the", "Atlas",
                "Aura the", "Avalanche", "Avalon the", "Axe the", "Axel the",
                "Axis the", "Azrael the"
            },
            {
                "Angel", "Astronaut", "Alligator", "Ant", "Ape", "Anaconda"
            }
        },
        {
            {
                "Babbit", "Bacon the", "Badger the", "Bailey", "Baltazar the",
                "Bambam", "Bandit the", "Bane the", "Baron", "Barry", "Basil",
                "Batista", "Baxter", "Bay the", "Bazal the", "Beacon the",
                "Beaker the", "Belch the", "Belcher", "Bingo", "Berry",
                "Beta the", "Big B the", "Bigglesworth", "Biggs the", "Biggy",
                "Bilbo", "Bing the", "Binky the", "Biscuit the", "Blackjack the",
                "Blade the", "Blaze the", "Blazer", "Bleach the", "Blight the",
                "Blister the", "Blitz the", "Blizz the", "Bloats the", "Blob the",
                "Blood the", "Blue the", "Bluster the", "Bob the", "Bolt the",
                "Bones the", "Booboo", "Booger the", "Boogy the", "Booker the",
                "Boomboom", "Boomer the", "Boomerang the", "Booth the",
                "Boots the", "Bosco the", "Boulder the", "Bounce th", "Bowser the",
                "Brawn the", "Brock the", "Brownie the", "Bruce the", "Brutus",
                "Bubba the", "Bubbles the", "Buck the", "Bud the", "Buddy",
                "Buff the", "Buffles the", "Bullet the", "Bully", "Bumble the",
                "Buster the", "Butch the", "Butters the", "Button", "Buttons the",
                "Buzz the"
            },
            {
                "Baboon", "Badger", "Bandicoot", "Bandit", "Bat", "Bear",
                "Beaver", "Bee", "Bigfoot", "Bird", "Bison", "Boar", "Buffalo"
            }
        },
        {
            {
                "Caine the", "Calvin the", "Camelot", "Captain", "Casanova the",
                "Cashew the", "Casper the", "Caspian the", "Catastrophe", "Caveman",
                "Chaos the", "Clacker the", "Claw the", "Clawde the", "Clawdius",
                "Clawford the", "Claws the", "Clawz the", "Clicker the",
                "Clipper the", "Cloud the", "Clyde the", "Coal the", "Cole the",
                "Coloss the", "Colt the", "Comet the", "Conan the", "Cookie the",
                "Cosmo the", "Cotton the", "Count", "Courage the", "Cozmo",
                "Crack the", "Crackle the", "Crash the", "Crazy", "Cream the",
                "Crook the", "Crooked", "Cruise the", "Crunch the", "Cruncher the",
                "Crunchy", "Crust the", "Crusty", "Cuddles the", "Cupcake the",
                "Cupid the", "Kaine the", "Kane the", "Kargo", "Khan the",
                "Killer", "Kindle the", "King"
            },
            {
                "Camel", "Cat", "Chameleon", "Cobra", "Cockroach", "Cougar",
                "Cow", "Coyote", "Crab", "Crane", "Croc", "Crow", "Kangaroo",
                "Koala", "Kobold", "Komodo"
            }
        }
        // Additional entries can be added here if desired.
    };

    static const std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> nm2 = {
        {
            {
                "Abalone", "Abby", "Acadia the", "Aerial the", "Aggie", "Aggy",
                "Agnes the", "Alexi", "Alexia", "Alexis", "Algee",
                "Alibi the", "Alize the", "Alpine the", "Amazone the",
                "Amazonia the", "Amber", "Amethyst the", "Angel the", "Angi",
                "Angie", "Annabella", "Aphrodite the", "Apple the", "April the",
                "Aqua", "Ares the", "Aria", "Arial the", "Ariel the", "Arizona",
                "Artica the", "Ash the", "Ashelia", "Ashes the", "Ashley",
                "Aspen the", "Astral", "Athena the", "Atilla the", "Atolle the",
                "Aura", "Aurora the", "Autumn", "Azraelle the", "Azura the",
                "Azure the", "Azurys the"
            },
            {
                "Angel", "Astronaut", "Alligator", "Ant", "Anaconda", "Ape"
            }
        }
        // Additional entries can be added here if desired.
    };

    // Generate a random i in [0,9] to keep parity with the original JS (unused)
    (void)rng(); // consume a random number

    if (type == 1) {
        const auto& entry = nm2[rng() % nm2.size()];
        const std::string& prefix = entry.first[rng() % entry.first.size()];
        const std::string& suffix = entry.second[rng() % entry.second.size()];
        return prefix + " " + suffix;
    } else {
        const auto& entry = nm1[rng() % nm1.size()];
        const std::string& prefix = entry.first[rng() % entry.first.size()];
        const std::string& suffix = entry.second[rng() % entry.second.size()];
        return prefix + " " + suffix;
    }
}
