#ifndef EVE_ONLINE_GALLENTES_LIB_H
#define EVE_ONLINE_GALLENTES_LIB_H

#include <string>
#include <random>

/* Generate a name in the style of EVE Online Gallentes.
 * `type` mirrors the original JavaScript generator:
 *   type == 1  -> use the “short” name set (names5/6)
 *   otherwise  -> use the “long” name set (names1/2)
 * The function returns a string of the form:
 *   "<firstPart> <secondPart>"
 * where firstPart and secondPart are each concatenations of two
 * randomly‑chosen fragments.
 */
std::string generate_eve_online_gallentes_name(std::mt19937& rng, int type = 0);

#endif // EVE_ONLINE_GALLENTES_LIB_H
