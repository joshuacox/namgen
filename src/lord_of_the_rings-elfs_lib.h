#ifndef LORD_OF_THE_RINGS_ELFS_LIB_H
#define LORD_OF_THE_RINGS_ELFS_LIB_H

#include <string>

/**
 * @brief Generate a Lord of the Rings elf‑style name.
 *
 * The implementation resides in the corresponding source file
 * (src/lord_of_the_rings-elfs_lib.cpp).  The function name used
 * throughout the code base is `generate_elf_name`, so we expose that
 * exact signature here.
 *
 * @param type Optional type selector (mirrors the original JS generator;
 *             passing 0 yields the default behaviour).
 * @return Generated name string.
 */
std::string generate_lotr_elf_name(int type = 0);

#endif // LORD_OF_THE_RINGS_ELFS_LIB_H
