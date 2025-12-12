#ifndef PLACES_PLAZAS_LIB_H
#define PLACES_PLAZAS_LIB_H

#include <string>
#include <random>

/* Generate a random “places‑plazas” name.
   The implementation mirrors the legacy JavaScript generator which
   picks a random adjective from a large list (nm1) and appends either
   “Plaza” or “Square”. */
std::string generate_places_plazas_name(std::mt19937& rng);

#endif // PLACES_PLAZAS_LIB_H
