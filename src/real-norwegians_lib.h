#ifndef REAL_NORWEGIANS_LIB_H
#define REAL_NORWEGIANS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Norwegian name (male or female) using built‑in lists.
 *
 * The function mirrors the behaviour of the legacy JavaScript generator
 * `generator$real$norwegians`.  If `type` is 1 a female first name is used,
 * otherwise a male first name is used.  When `type` is omitted a random gender
 * is chosen.
 *
 * @param rng   Random number generator to use.
 * @param type  0 = male (default), 1 = female.  Any other value will be treated
 *              as random.
 * @return      A string containing "<first name> <surname>".
 */
std::string generate_real_norwegians_name(std::mt19937& rng, int type = 0);

#endif // REAL_NORWEGIANS_LIB_H
