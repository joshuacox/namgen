# namgen
A Name Generator

A flexible name generator that combines adjectives and nouns to create unique names. Supports various formatting options and custom assets.

A sister project to [name-generator](https://github.com/joshuacox/name-generator), the difference between this project and that one is that this is taking the C plus plus version and adding more features CapCasing and camelCasing and more. 

## Features
- Combine words from adjective and noun lists
- Custom separator support
- Multiple casing styles (normal, camelCase, CapWords)
- Null separator mode for no spacing
- Environment variable configuration
- Debug mode with detailed output
- Installable via make
- **New**: `--elf` flag to generate fantasy‑elf style names using the built‑in ELF name generator

## Installation

1. Clone the repository
2. Run `cmake .`
3. Run `make`
4. Optionally install with `sudo make install`

### oneliner installation

```
curl https://raw.githubusercontent.com/joshuacox/namgen/refs/heads/main/scripts/install.sh | sh
```

## Usage
```bash
./namgen [options]
```

Command-line options:
- `-a FILE` or `--adj-file FILE`: Path to custom adjectives file (default: assets/adjectives/adjectives.list)
- `-n FILE` or `--noun-file FILE`: Path to custom nouns file (default: assets/nouns/nouns.list)
- `-s SEP` or `--separator SEP`: Use custom separator (default: "-")
- `-x` or `--null-separator`: do not print the separator variable in the name
- `-c COUNT` or `--count COUNT`: Number of names to generate (default: terminal height)
- `--capcasing`: Capitalize the first letter of both adjective and noun
- `--camelcasing`: CamelCase style with only noun capitalized
- `--debug`: Enable debug output
- `--elf`: Generate fantasy‑elf style names using the built‑in ELF name generator (ignores adjective/noun files)

## Configuration via Environment Variables
- `ASSETS_DIR`: Path to assets directory containing adjectives/nouns subfolders
- `ADJ_FILE`: Path to default adjectives file (overrides ADJ_FOLDER if set)
- `NOUN_FILE`: Path to default nouns file (overrides NOUN_FOLDER if set)
- `NOUN_FOLDER`: Path to nouns file/folder (default: assets/nouns)
- `ADJ_FOLDER`: Path to adjectives file/folder (default: assets/adjectives)
- `NULL_SEPARATOR`: Enable null separator mode (true/false)
- `SEPARATOR`: Custom separator string
- `CAPCASING`: Enable capcasing style (true/false)
- `CAMELCASING`: Enable camel casing style (true/false)

## Examples

Basic usage:
```bash
./namgen --count 5
```

Using custom files:
```bash
# Use specific adjective and noun files
./namgen -a custom_adjectives.txt -n custom_nouns.txt

# Chain with other options
./namgen -a my_adj.txt -n my_nouns.txt --camelcasing --count 10
```

Custom separator:
```bash
SEPARATOR='-' ./namgen
```

CamelCase style:
```bash
./namgen --camelcasing
```

Null separator mode:
```bash
NULL_SEPARATOR=true ./namgen
```

Generate fantasy‑elf style names:
```bash
./namgen --elf -c 5
```

## License
GPLv3 - see LICENSE file for details.
```