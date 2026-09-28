# namgen

A fast, flexible, and extensible command-line name generator written in C++17.

**Documentation & Interactive Simulator**: [https://joshuacox.github.io/namgen/](https://joshuacox.github.io/namgen/)

`namgen` combines adjectives and nouns to produce memorable names with custom casing and separators, while also providing built-in procedural name generators for fantasy, sci-fi, historical, and pop-culture universes.

---

## Features

- **Adjective + Noun Combinations**: Generate combinations from built-in or custom wordlists.
- **Casing Styles**: Normal, `camelCase`, and `CapWords` (`PascalCase`).
- **Flexible Separators**: Custom separator strings or null-separator (concatenation) mode.
- **907 Specialized Procedural Generators**: Standalone, high-performance, zero-allocation C++17 generators spanning 40 categories (Fantasy, Real-World cultural/historical names, Descriptions & Lore, Sci-Fi, Gaming universes, Weapons, Armour, Places, Pets, and more).
- **Dynamic Generator Registry**: Adding or querying procedural generators is fully modular and decoupled from CLI parsing.
- **Environment Variable Configuration**: Fine-tune default behavior via shell environment variables.

---

## Installation

### Prerequisites
- C++17 compiler (`g++` or `clang++`)
- `cmake` (version 3.12 or newer) and `make` (optional: can also build directly via `g++`)

### Build and Install
```bash
# Clone the repository
git clone https://github.com/joshuacox/namgen.git
cd namgen

# Build with CMake
cmake -B build
cmake --build build

# Install binary, assets, and man page
sudo cmake --install build
```

### Direct Compilation
```bash
# Fast parallel make build
make -j$(nproc)

# Or directly with g++
g++ -std=c++17 -O2 src/*.cpp -o namgen
```

### One-liner Installation
```bash
curl https://raw.githubusercontent.com/joshuacox/namgen/refs/heads/main/scripts/install.sh | sh
```

---

## Project Structure

```text
namgen/
├── assets/               # Default wordlists (adjectives, nouns)
├── harness/              # AI porting & evaluation harness (Aider, Loopster, models)
│   ├── fantasyloop.sh    # Generator porting loop runner
│   ├── score.csv         # Benchmark & model evaluation metrics
│   └── ...
├── man/                  # Unix manual page (man/namgen.1)
├── scripts/              # Developer & CI scripts (install, benchmark, test)
├── src/                  # C++17 source code
│   ├── namgen.cpp        # Lightweight CLI orchestrator & option parser
│   ├── generator_registry.h / .cpp # Centralized dynamic generator registry
│   └── *_lib.cpp / *_lib.h # 907 modular procedural name generators (zero-allocation .rodata)
├── test/                 # Test suites (Bats integration tests & tester.sh)
├── web/                  # Next.js static documentation website & interactive simulator
├── CMakeLists.txt        # CMake configuration with dynamic source discovery
├── Makefile              # Parallel build & installation targets
└── Dockerfile            # Container build specification
```

---

## Command-line Options

### General & Formatting Options

| Option | Description |
|---|---|
| `-c, --count COUNT` | Number of names to generate (default: terminal height, or 24) |
| `-s, --separator SEP` | Custom separator string (default: `-`) |
| `-x, --null-separator` | Do not print separator (concatenates words) |
| `--cap, --capcasing` | Capitalize first letter of both words (`CapWords` style) |
| `--camel, --camelcasing` | Lowercase adjective, capitalize noun (`camelCase` style) |
| `-a, --adj-file FILE` | Path to custom adjective wordlist |
| `-n, --noun-file FILE` | Path to custom noun wordlist |
| `-e, --exclude STRING` | Characters to strip from generated names (default: `-`, `'`) |
| `--debug` | Enable debug printing of word source and counter info |
| `-h, --help` | Display help message and exit |

---

### Specialized Procedural Generators

When any generator option is passed (e.g. `--<category>-<name>`), `namgen` uses that procedural generator instead of adjective/noun combinations.

All 907 generators are compiled directly into `.rodata` with zero runtime heap allocation for maximum generation speed.

#### Category Summary (907 Generators across 40 Universes & Themes)

| Category | Count | Examples & Descriptions |
|---|:---:|---|
| **Real-World Cultures** (`real-`) | 130 | `--real-anglo_saxons`, `--real-egyptians`, `--real-japaneses`, `--real-norwegians`, `--real-romans` |
| **Miscellaneous & Lore** (`miscellaneous-`) | 124 | `--miscellaneous-bands`, `--miscellaneous-guilds`, `--miscellaneous-potions`, `--miscellaneous-spells`, `--miscellaneous-airships` |
| **Fantasy Races & Beings** (`fantasy-`) | 96 | `--fantasy-aliens`, `--fantasy-amazons`, `--fantasy-angels`, `--fantasy-dragons`, `--fantasy-goblins`, `--fantasy-vampires` |
| **Places & Geography** (`places-`) | 80 | `--places-castles`, `--places-dungeons`, `--places-forests`, `--places-islands`, `--places-mountains`, `--places-temples` |
| **Descriptions & Backstories** (`descriptions-`) | 54 | Full procedural narrative blocks: `--descriptions-characters`, `--descriptions-backstorys`, `--descriptions-pokemons`, `--descriptions-planets` |
| **Star Wars Universe** (`star_wars-`, `star_wars_the_old_republic-`) | 48 | `--star_wars-darths`, `--star_wars-mandalorians`, `--star_wars-wookiees`, `--star_wars_the_old_republic-chiss`, `--star_wars_the_old_republic-siths` |
| **Towns & Cities** (`towns_and_cities-`) | 36 | `--towns_and_cities-dwarven_citys`, `--towns_and_cities-steampunk_citys`, `--towns_and_cities-viking_towns` |
| **Armour & Weapons** (`armour-`, `weapons-`) | 31 | `--armour-helmets`, `--armour-shields`, `--weapons-swords`, `--weapons-bows`, `--weapons-shotguns` |
| **Pets & Animals** (`pets-`) | 28 | `--pets-cats`, `--pets-dogs`, `--pets-marine_mammals`, `--pets-reptiles`, `--pets-birds` |
| **World of Warcraft** (`world_of_warcraft-`, `world_of_warcraft_pets-`) | 25 | `--world_of_warcraft-blood_elf`, `--world_of_warcraft-tauren`, `--world_of_warcraft_pets-wow_pets` |
| **Pop Culture & Comics** (`pop_culture-`) | 25 | `--pop_culture-homestucks`, `--pop_culture-pokemons`, `--pop_culture-transformers`, `--pop_culture-x_mens` |
| **Warhammer & 40K** (`warhammer-`, `warhammer_40k-`) | 24 | `--warhammer-daemons_of_chaos`, `--warhammer_40k-space_marines`, `--warhammer_40k-necrons` |
| **Pathfinder RPG** (`pathfinder-`) | 23 | `--pathfinder-aasimars`, `--pathfinder-dwarfs`, `--pathfinder-tieflings` |
| **Star Trek** (`star_trek-`) | 21 | `--star_trek-klingons`, `--star_trek-vulcans`, `--star_trek-romulans`, `--star_trek-ferengis` |
| **Dungeons & Dragons** (`dungeon_and_dragons-`) | 18 | `--dungeon_and_dragons-dragonborns`, `--dungeon_and_dragons-drows`, `--dungeon_and_dragons-dwarfs` |
| **The Elder Scrolls** (`elder_scrolls-`) | 16 | `--elder_scrolls-altmers`, `--elder_scrolls-bosmers`, `--elder_scrolls-khajiits`, `--elder_scrolls-nords` |
| **Lord of the Rings** (`lord_of_the_rings-`, `lord_of_the_rings_online-`) | 11 | `--elf` / `--lotr-elf`, `--lord_of_the_rings-hobbits`, `--lord_of_the_rings-dwarfs` |
| **Game of Thrones** (`game_of_thrones-`) | 10 | `--game_of_thrones-dothrakis`, `--game_of_thrones-valyrians`, `--game_of_thrones-free_folks` |
| **The Legend of Zelda** (`legend_of_zelda-`) | 10 | `--legend_of_zelda-gorons`, `--legend_of_zelda-gerudos`, `--legend_of_zelda-zoras` |
| **Mass Effect** (`mass_effect-`) | 9 | `--mass_effect-asaris`, `--mass_effect-turians`, `--mass_effect-krogans`, `--mass_effect-salarians` |
| **WildStar** (`wildstar-`) | 8 | `--wildstar-aurins`, `--wildstar-chuas`, `--wildstar-mordeshs` |
| **Halo** (`halo-`) | 8 | `--halo-forerunners`, `--halo-sangheilis`, `--halo-kig_yars` |
| **Military Call-Signs** (`military-`) | 8 | `--military-royal_navy`, `--military-united_states`, `--military-royal_air_force` |
| **Destiny** (`destiny-`) | 7 | `--destiny-awokens`, `--destiny-cabals`, `--destiny-exos`, `--destiny-hives` |
| **Doctor Who** (`doctor_who-`) | 7 | `--doctor_who-daleks`, `--doctor_who-gallifreyans`, `--doctor_who-ice_warriors`, `--doctor_who-silurians` |
| **Dragon Ball** (`dragon_ball-`) | 7 | `--dragon_ball-saiyans`, `--dragon_ball-frieza_clans`, `--dragon_ball-hakaishins` |
| **Final Fantasy** (`final_fantasy-`) | 6 | `--final_fantasy-elezens`, `--final_fantasy-lalafells`, `--final_fantasy-roegadyns` |
| **Rift** (`rift-`) | 6 | `--rift-bahmis`, `--rift-eths`, `--rift-kelaris` |
| **Guild Wars** (`guild_wars-`) | 5 | `--guild_wars-asuras`, `--guild_wars-charrs`, `--guild_wars-norns`, `--guild_wars-sylvaris` |
| **Harry Potter** (`harry_potter-`) | 5 | `--harry_potter-dragon_species`, `--harry_potter-goblins`, `--harry_potter-house_elfs` |
| **Inheritance Cycle** (`inheritance_cycle-`) | 5 | `--inheritance_cycle-dragons`, `--inheritance_cycle-elfs`, `--inheritance_cycle-urgals` |
| **Diablo** (`diablo-`) | 4 | `--diablo-angels`, `--diablo-demons`, `--diablo-nephalems` |
| **Dragon Age** (`dragon_age-`) | 4 | `--dragon_age-dwarfs`, `--dragon_age-elfs`, `--dragon_age-qunaris` |
| **EVE Online** (`eve_online-`) | 4 | `--eve_online-caldaris`, `--eve_online-gallentes`, `--eve_online-minmatars` |
| **The Witcher** (`the_witcher-`) | 4 | `--the_witcher-dwarfs`, `--the_witcher-elfs`, `--the_witcher-halflings`, `--the_witcher-humans` |

To list all available generator flags, run:
```bash
namgen --help
# or
man namgen
```

---

## Testing

Run the full automated test suite:
```bash
./test.sh
```

Or run the Bats integration tests:
```bash
bats test/full.bats
```

Or verify non-empty generation across all 907 procedural generators:
```bash
bash test/tester.sh
```

---

## License

GPLv3 - see [LICENSE](LICENSE) for details.
