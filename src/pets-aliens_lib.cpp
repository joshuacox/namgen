#include "pets-aliens_lib.h"
#include "generator_common.h"
#include <string_view>
#include <string>
#include <iterator>

std::string generate_pets_aliens_name(std::mt19937& rng, int type) {
    static constexpr std::string_view nm1[] = {"Aether", "Altair", "Aphelion", "Aster", "Astro", "Atlas", "Azimuth", "Baryon", "Blazar", "Blyde", "Bolide", "Boo", "Bose", "Bullet", "Carbon", "Chaos", "Chewy", "Chromos", "Chrono", "Chronos", "Cluster", "Comet", "Core", "Cosmo", "Cosmos", "Creature", "Crescent", "Crimson", "Cyclops", "Dalek", "Darth", "Diablo", "Dock", "Doppler", "Drake", "Dusty", "Einstein", "Element", "Equinox", "Fang", "Fire", "Flare", "Galax", "Gamma", "Ghost", "Gibbs", "Glob", "Grav", "Grog", "Halo", "Hannibal", "Helio", "Hertz", "Hubble", "Hubbles", "Hunter", "Hyde", "Hyper", "Ion", "Irone", "It", "Jabs", "Jet", "Kelvin", "Kepler", "Kraken", "Kuiper", "Lecter", "Lens", "Light", "Lightyear", "Magni", "Malif", "Meridian", "Merlin", "Micron", "Milky", "Moonbeam", "Naut", "Nebula", "Neutron", "Nibbler", "Nova", "Ogre", "Omega", "Orb", "Orbit", "Parallax", "Phantom", "Phase", "Pixel", "Prism", "Pulse", "Pyre", "Pyro", "Radio", "Raye", "Reaper", "Rocket", "Salem", "Sasquatch", "Scar", "Seti", "Shadow", "Sky", "Solace", "Soleil", "Solstice", "Spectre", "Spectro", "Spook", "Spot", "Spud", "Starlight", "Steele", "Syzygy", "Terra", "Thing", "Trojan", "Umbra", "Vayne", "Vlad", "Void", "Xray", "Yoda", "Zero", "Zodiac"};
    static constexpr std::string_view nm2[] = {"Aerial", "Aire", "Andromeda", "Aphelia", "Astero", "Astral", "Astralle", "Aura", "Aurora", "Celeste", "Chewy", "Chromy", "Chronis", "Cloude", "Comette", "Cookie", "Corona", "Cosmo", "Density", "Duste", "Eclipse", "Ejecta", "Element", "Ellipse", "Enigma", "Equinox", "Eye", "Flare", "Fyre", "Galaxy", "Gamma", "Ghoste", "Gibbsy", "Gravi", "Gravity", "Harpie", "Helio", "Hydra", "Ice", "Infra", "Ion", "Iso", "Light", "Lumi", "Lumina", "Luna", "Magni", "Mare", "Medusa", "Meridian", "Midnight", "Milky", "Moon", "Moonbeam", "Moone", "Moonlight", "Nadir", "Nasa", "Nebula", "Nessie", "Nighte", "Nova", "Oracle", "Orbit", "Ozone", "Patera", "Penumbra", "Pixel", "Plasma", "Polaris", "Prism", "Pulse", "Pyre", "Raye", "Selena", "Seti", "Shade", "Shadow", "Sky", "Skylar", "Sola", "Solare", "Solstice", "Spectra", "Spooky", "Sputs", "Star", "Stardust", "Starlight", "Stella", "Stellar", "Summer", "Sunspot", "Syzygy", "Tera", "Terra", "Therma", "Twilight", "Umbra", "Venus", "Violet", "Voide", "Winter", "Zenith"};
    static constexpr std::string_view nm3[] = {"", "", "", "", "", "", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "r", "s", "t", "v", "w", "y", "z", "ch", "sh", "gr", "br", "gl", "kr", "kl", "pr", "ph", "str", "st", "wr"};
    static constexpr std::string_view nm4[] = {"a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ai", "ao", "au", "ea", "ei", "eo", "eu", "ee", "aa", "ia", "ie", "io", "iu", "oa", "oe", "oo", "ou", "ua", "ue", "ui", "uo", "uu"};
    static constexpr std::string_view nm5[] = {"b", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "x", "y", "z", "b", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "x", "y", "z", "b", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "x", "y", "z", "b", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "v", "x", "y", "z", "bb", "cc", "dd", "gg", "hh", "ll", "mm", "nn", "rr", "ss", "tt", "vv", "xx", "zz", "bl", "br", "by", "cd", "ch", "ck", "cl", "cm", "cn", "cr", "cs", "ct", "cv", "cz", "cst", "cstr", "dr", "dy", "gd", "gl", "gr", "gy", "hk", "hl", "hm", "hn", "hr", "kd", "kl", "km", "kn", "kr", "ky", "kx", "lc", "ld", "lg", "lk", "lm", "ln", "lr", "lt", "lv", "ly", "lz", "nr", "ny", "nz", "ns", "nst", "nstr", "rb", "rc", "rd", "rg", "rk", "rl", "rm", "rn", "rs", "rt", "rst", "rstr", "rv", "rx", "ry", "rz", "sb", "sc", "sd", "sg", "sh", "sk", "sl", "sm", "sn", "sr", "st", "str", "sy", "sz", "tl", "tr", "ty", "tz", "vl", "vr", "vy", "xr", "xy", "zl", "zy"};
    static constexpr std::string_view nm6[] = {"", "", "", "", "", "", "", "", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "x", "c", "d", "g", "h", "k", "l", "m", "n", "r", "s", "t", "x", "rc", "rd", "rg", "rk", "rm", "rn", "rs", "rt", "rx", "rz", "st", "sh", "sz", "ns", "nz"};
    static constexpr std::string_view nm7[] = {"", "", "", "", "", "", "", "", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "a", "e", "i", "o", "u", "ae", "ea", "ee", "aa", "ia", "ua", "ue"};

    std::string names; size_t rnd = 0; size_t rnd2 = 0; size_t rnd3 = 0; size_t rnd4 = 0; size_t rnd5 = 0; size_t rnd6 = 0; int i = 0;

i = rng() % 10; {
    if (type == 1) {
    if (i < 6) {
    rnd = rng() % std::size(nm2);
    names = nm2[rnd];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm4);
    if (rnd2 > 34) {
    while (rnd4 > 34) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    rnd5 = rng() % std::size(nm6);
    rnd6 = rng() % std::size(nm7);
    if (rnd5 < 8) {
    rnd6 = 0;
    }
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm4[rnd4] + nm6[rnd5] + nm7[rnd6];
    }
    } else {
    if (i < 6) {
    rnd = rng() % std::size(nm1);
    names = nm1[rnd];
    } else {
    rnd = rng() % std::size(nm3);
    rnd2 = rng() % std::size(nm4);
    rnd3 = rng() % std::size(nm5);
    rnd4 = rng() % std::size(nm4);
    if (rnd2 > 34) {
    while (rnd4 > 34) {
    rnd4 = rng() % std::size(nm4);
    }
    }
    rnd5 = rng() % std::size(nm6);
    names = nm3[rnd] + nm4[rnd2] + nm5[rnd3] + nm4[rnd4] + nm6[rnd5];
    }
    }
    return names;
    }
}
