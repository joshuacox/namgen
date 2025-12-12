# namgen
A Name Generator

A flexible name generator that combines adjectives and nouns to create unique names. Supports various formatting options and custom assets.

A sister project to [name-generator](https://github.com/joshuacox/name-generator), the difference between this one and that one is that this is taking the C plus plus version and adding more features CapCasing and camelCasing and more. 

## Features
- Combine words from adjective and noun lists
- Custom separator support
- Multiple casing styles (normal, camelCase, CapWords)
- Null separator mode for no spacing
- Environment variable configuration
- Debug mode with detailed output
- Installable via make
- **New**: `--elf` flag to generate fantasy‑elf style names using the built‑in ELF name generator

## Command‑line Options
Below is the full list of options supported by `namgen`. Most options have a short and a long form; the long form is shown first.

- `-a, --adj-file FILE`  
  Path to a custom adjective list file.

- `-e, --exclude STRING`  
  Characters to strip from generated words.

- `-n, --noun FILE`  
  Path to a custom noun list file.

- `-s SEP, --separator SEP`  
  Custom separator string (default: `-`).

- `-x, --null-separator`  
  Do not print the separator (produces a concatenated name).

- `-c COUNT, --count COUNT`  
  Number of names to generate (default: terminal height).

- `--cap, --capcasing`  
  Capitalize the first letter of **both** adjective and noun (CapWords style).

- `--camel, --camelcasing`  
  CamelCase style – adjective lower‑cased, noun capitalized.

- `--debug`  
  Enable debug output (sets the `DEBUG=true` environment variable).

- `--elf`, `--lotr-elf`, `--lord_of_the_rings-elfs`  
  Generate fantasy‑elf style names (uses the built‑in ELF generator).

- `--halo-forerunners`  
  Generate Halo “forerunners” style names (ignores adjective/noun files).

- `--halo-mgalekgolos`  
  Generate Halo “Mgalekgolos” style names (built‑in generator).

- `--warhammer-daemons_of_chaos`  
  Generate Warhammer “Daemons of Chaos” style names (built‑in generator).

- `--fantasy-animatronics`  
  Generate fantasy “animatronics” style names (ignores adjective/noun files).

- `--destiny-awokens`  
  Generate fantasy‑destiny “awokens” style names.

- `--destiny-cabals`  
  Generate fantasy‑destiny “cabals” style names.

- `--destiny-exos`  
  Generate fantasy‑destiny “exos” style names.

- `--destiny-fallens`  
  Generate fantasy‑destiny “fallens” style names.

- `--destiny-hives`  
  Generate fantasy‑destiny “hives” style names.

- `--destiny-humans`  
  Generate fantasy‑destiny “humans” style names.

- `--destiny-vexs`  
  Generate fantasy‑destiny “vexs” style names.

- `--diablo-angels`  
  Generate Diablo “angels” style names.

- `--diablo-demons`  
  Generate Diablo “demons” style names.

- `--diablo-khazras`  
  Generate Diablo “khazras” style names.

- `--diablo-nephalems`  
  Generate Diablo “nephalems” style names.

- `--doctor_who-silurians`  
  Generate Doctor Who “Silurians” style names.

- `--doctor_who-raxacoricofallapatorians`  
  Generate Doctor Who “Raxacoricofallapatorians” (Rift‑Bahmis) style names.

- `--dragon_age-dwarfs`  
  Generate Dragon Age dwarf names (legacy JavaScript generator).

- `--dragon_ball-others`  
  Generate Dragon Ball “other …” style names.

- `--dragon_ball-frieza_clans`  
  Generate Dragon Ball “Frieza Clans” style names.

- `--dragon_ball-hakaishins`  
  Generate Dragon Ball “Hakaishins” style names.

- `--dragon_ball-humans`  
  Generate Dragon Ball human names (male/female).

- `--dragon_ball-saiyans`  
  Generate Dragon Ball “Saiyans” style names.

- `--dragon_ball-skians`  
  Generate Dragon Ball “Skians” style names.

- `--dragon_ball-tuffles`  
  Generate Dragon Ball “Tuffles” style names.

- `--dungeon_and_dragons-devas`  
  Generate Dungeons & Dragons “devas” style names.

- `--dungeon_and_dragons-dragonborns`  
  Generate Dungeons & Dragons “dragonborns” style names.

- `--dungeon_and_dragons-drows`  
  Generate Dungeons & Dragons “drows” style names.

- `--dungeon_and_dragons-dwarfs`  
  Generate Dungeons & Dragons “dwarfs” style names.

- `--dungeon_and_dragons-eladrins`  
  Generate Dungeons & Dragons “eladrins” style names.

- `--dungeon_and_dragons-elfs`  
  Generate Dungeons & Dragons “elfs” style names.

- `--dungeon_and_dragons-githzerais`  
  Generate Dungeons & Dragons “githzerais” style names.

- `--fantasy-aliens`  
  Generate fantasy “aliens” style names.

- `--fantasy-amazons`  
  Generate fantasy “amazons” style names.

- `--fantasy-angels`  
  Generate fantasy “angels” style names.

- `--fantasy-animal_species`  
  Generate fantasy “animal species” style names.

- `--fantasy-apocalypse_mutants`  
  Generate fantasy “apocalypse mutants” style names.

- `--elder_scrolls-bosmers`  
  Generate Elder Scrolls “Bosmers” style names (built‑in generator).

- `--eve_online-gallentes`  
  Generate Eve Online “Gallentes” style names (built‑in generator).

- `--harry_potter-goblins`  
  Generate Harry Potter “Goblins” style names (built‑in generator).

- `--places-plazas`  
  Generate plaza names.

- `--military-united_states`  
  Generate United States military call‑sign style names (two random NATO phonetic alphabet words).

- `--military-royal_navy`  
  Generate Royal Navy military call‑sign style names.

- `--warhammer-ogres`  
  Generate Warhammer “ogres” style names.

- `--towns_and_cities-ancient_greek_towns`  
  Generate ancient Greek town and city names.

- `--final_fantasy-roegadyns`  
  Generate Final Fantasy “Roegadyn” style names.

- `--pets-marine_mammals`  
  Generate marine‑mammal names (built‑in generator).

- `--rift-bahmis`  
  Generate Rift “Bahmis” names (built‑in generator).

- `--rift-eths`  
  Generate Rift “Eths” names (built‑in generator).

- `--inheritance_cycle-dragons`  
  Generate inheritance‑cycle dragon names.

- `--pop_culture-homestucks`  
  Generate pop‑culture “Homestucks” names.

- `--warhammer_40k-sisters_of_battles`  
  Generate Warhammer 40k “Sisters of Battles” names.

- `--towns_and_cities-east_european_towns`  
  Generate East European town and city names.

- `--real-norwegians`  
  Generate real Norwegian names.

- `--star_wars_the_old_republic-cathars`  
  Generate Star Wars: The Old Republic “Cathars” style names (built‑in generator).

- `--pets-reptiles`  
  Generate reptile pet names (legacy JavaScript generator).

- `--help`  
  Show the help message and exit.

> **Note:** Many of the above flags ignore the adjective/noun asset files and instead use built‑in generators specific to the selected universe.

## Usage
```bash
./namgen [options]
```

Command-line options:
- `-a, --adj-file FILE`      Path to custom adjectives file
- `-e, --exclude STRING`     Characters to strip from generated words
- `-n, --noun FILE`          Path to custom noun file
- `-s SEP, --separator SEP`  Custom separator string (default: -)
- `-x, --null-separator`     Do not print the separator
- `-c COUNT, --count COUNT`  Number of names to generate (default: terminal height)
- `--cap --capcasing`        Capitalize first letter of both adjective and noun
- `--camel --camelcasing`    CamelCase style (adjective lower‑cased, noun capitalized)
- `--debug`                  Enable debug output
- `--destiny-awokens`        Generate fantasy‑destiny awoken style names
- `--destiny-cabals`         Generate fantasy‑destiny cabals style names
- `--destiny-exos`           Generate fantasy‑destiny exos style names
- `--destiny-fallens`        Generate fantasy‑destiny fallens style names
- `--destiny-hives`          Generate fantasy‑destiny hives style names
- `--destiny-humans`         Generate fantasy‑destiny humans style names
- `--destiny-vexs`           Generate fantasy‑destiny vexs style names
- `--diablo-angels`          Generate Diablo angels style names
- `--diablo-demons`          Generate Diablo demons style names
- `--diablo-khazras`         Generate Diablo khazras style names
- `--diablo-nephalems`       Generate Diablo nephalems style names
- `--doctor_who-silurians`   Generate Doctor Who Silurians style names
- `--doctor_who-raxacoricofallapatorians` Generate a Rift‑Bahmis name (uses built‑in generator)
- `--dragon_age-dwarfs`      Generate Dragon Age dwarf names (legacy JS generator)
- `--dragon_ball-others`     Generate Dragon Ball “other …” style names
- `--dragon_ball-frieza_clans` Generate Dragon Ball Frieza Clans names
- `--dragon_ball-hakaishins` Generate Dragon Ball Hakaishins names
- `--dragon_ball-humans`     Generate Dragon Ball human names (male/female)
- `--dragon_ball-saiyans`    Generate Dragon Ball Saiyan names
- `--dragon_ball-skians`     Generate Dragon Ball Skians names
- `--dragon_ball-tuffles`    Generate Dragon Ball Tuffles names
- `--dungeon_and_dragons-devas` Generate Dungeons & Dragons “devas” names
- `--dungeon_and_dragons-dragonborns` Generate Dungeons & Dragons “dragonborns” names
- `--dungeon_and_dragons-drows` Generate Dungeons & Dragons “drows” names
- `--dungeon_and_dragons-dwarfs` Generate Dungeons & Dragons “dwarfs” names
- `--dungeon_and_dragons-eladrins` Generate Dungeons & Dragons “eladrins” names
- `--dungeon_and_dragons-elfs` Generate Dungeons & Dragons “elfs” names
- `--dungeon_and_dragons-githzerais` Generate Dungeons & Dragons “githzerais” names
- `--elf`                    Generate fantasy‑elf style names (uses built‑in generator)
- `--elder_scrolls-bosmers`  Generate Elder Scrolls Bosmer style names (uses built‑in generator)
- `--eve_online-gallentes`   Generate Gallentes style names (uses built‑in generator)
- `--fantasy-aliens`         Generate fantasy “aliens” names
- `--fantasy-amazons`        Generate fantasy “amazons” names
- `--fantasy-angels`         Generate fantasy “angels” names
- `--fantasy-animal_species` Generate fantasy “animal species” names
- `--fantasy-animatronics`   Generate fantasy “animatronics” style names (ignores adjective/noun files)
- `--fantasy-apocalypse_mutants` Generate fantasy “apocalypse mutants” names
- `--halo-forerunners`       Generate Halo “forerunners” style names (ignores adjective/noun files)
- `--halo-mgalekgolos`       Generate Halo “Mgalekgolos” style names (uses built‑in generator)
- `--harry_potter-goblins`   Generate Harry Potter “Goblins” style names (uses built‑in generator)
- `--places-plazas`          Generate Plaza names
- `--military-united_states` Generate United States military call‑sign style names (two random NATO phonetic alphabet words)
- `--warhammer-ogres`        Generate Warhammer “ogres” style names
- `--towns_and_cities-ancient_greek_towns` Generate Ancient Greek Towns and Cities
- `--final_fantasy-roegadyns` Generate Final Fantasy Roegadyn names
- `--pets-marine_mammals`    Generate a marine‑mammal name (uses built‑in marine‑mammal generator)
- `--rift-bahmis`            Generate a Rift‑Bahmis name (uses built‑in generator)
- `--rift-eths`              Generate a Rift‑Eths name (uses built‑in generator)
- `--inheritance_cycle-dragons` Generate inheritance‑cycle dragons names
- `--pop_culture-homestucks` Generate pop‑culture homestucks names
- `--warhammer_40k-sisters_of_battles` Generate Warhammer 40k Sisters of Battles names
- `--towns_and_cities-east_european_towns` Generate East European Towns and Cities
- `--real-norwegians`        Generate real Norwegian names
- `--star_wars_the_old_republic-cathars` Generate Cathars style names (uses built‑in generator)
- `--military-royal_navy`    Generate Royal Navy military call‑sign style names 
- `--pets-reptiles`          Generate reptile pet names (legacy JS generator)

## Installation

1. Clone the repository
2. Run `cmake .`
3. Run `make`
4. Optionally install with `sudo make install`

### oneliner installation

```
curl https://raw.githubusercontent.com/joshuacox/namgen/refs/heads/main/scripts/install.sh | sh
```

## License
GPLv3 - see LICENSE file for details.
