#ifndef RIFT_ETHS_LIB_H
#define RIFT_ETHS_LIB_H

#include <string>
#include <random>

/**
 * @brief Generate a Rift‑Eths name.
 *
 * The generator mirrors the behaviour of the legacy JavaScript generator
 * `generators/rift/eths.js`.  If `type` is `1` a different set of name parts
 * is used; otherwise the default set (type `0`) is used.
 *
 * @param rng   Random number generator to use.
 * @param type  Either `0` (default) or `1` to select the name‑part tables.
 * @return      Concatenated name string.
 */
std::string generate_rift_eths_name(std::mt19937& rng, int type = 0);

#endif // RIFT_ETHS_LIB_H
