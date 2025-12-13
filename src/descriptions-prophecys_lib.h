#ifndef DESCRIPTIONS_PROPHECYS_LIB_H
#define DESCRIPTIONS_PROPHECYS_LIB_H

#include <random>
#include <string>

/* Generate a single description‑prophecy string.
   The function mimics the behaviour of the legacy JavaScript generator
   (generators/descriptions/prophecys.js) and returns a multi‑line string
   containing four prophecy sentences separated by a line of dashes. */
std::string generate_descriptions_prophecys_name(std::mt19937& rng);

#endif // DESCRIPTIONS_PROPHECYS_LIB_H
