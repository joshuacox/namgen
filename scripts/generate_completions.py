#!/usr/bin/env python3
"""
Generate shell completions (Bash, Zsh, Fish) for namgen.
Extracts all CLI flags and specialized generators from namgen.
"""
import os
import re
import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
COMPLETIONS_DIR = REPO_ROOT / "completions"

def get_generators():
    cmd = [str(REPO_ROOT / "namgen"), "--help"]
    out = subprocess.check_output(cmd, text=True)
    gens = []
    in_specialized = False
    for line in out.splitlines():
        if "Specialized Generators:" in line:
            in_specialized = True
            continue
        if not in_specialized:
            continue
        line = line.strip()
        if not line or not line.startswith("--"):
            continue
        parts = line.split(None, 1)
        flag = parts[0][2:] # strip --
        desc = parts[1] if len(parts) > 1 else flag
        gens.append((flag, desc))
    return gens

def generate_bash(gens):
    core_opts = [
        "-a", "--adj", "--adj-file",
        "-n", "--noun", "--noun-file",
        "-s", "--separator",
        "-x", "--null-separator",
        "-c", "--count",
        "-S", "--seed",
        "-u", "--unique",
        "-m", "--match",
        "--min-len", "--max-len",
        "--compose", "--template",
        "-i", "--interactive",
        "--json",
        "--csv",
        "--slug", "--kebab",
        "--cap", "--capcasing",
        "--camel", "--camelcasing",
        "--debug",
        "-h", "--help"
    ]
    all_flags = core_opts + [f"--{flag}" for flag, _ in gens]
    opts_str = " ".join(all_flags)

    content = f"""# Bash completion for namgen
# Generated automatically by scripts/generate_completions.py

_namgen_completions() {{
    local cur prev opts
    COMPREPLY=()
    cur="${{COMP_WORDS[COMP_CWORD]}}"
    prev="${{COMP_WORDS[COMP_CWORD-1]}}"

    case "${{prev}}" in
        -a|--adj|--adj-file|-n|--noun|--noun-file)
            COMPREPLY=( $(compgen -f -- "${{cur}}") )
            return 0
            ;;
        -s|--separator|-c|--count|-S|--seed|-m|--match|--min-len|--max-len|--compose|--template)
            return 0
            ;;
    esac

    opts="{opts_str}"

    if [[ "${{cur}}" == -* ]]; then
        COMPREPLY=( $(compgen -W "${{opts}}" -- "${{cur}}") )
        return 0
    fi
}}

complete -F _namgen_completions namgen
"""
    return content

def generate_zsh(gens):
    lines = [
        "#compdef namgen",
        "# Zsh completion for namgen",
        "# Generated automatically by scripts/generate_completions.py",
        "",
        "_arguments -s -S \\",
        "  '(-h --help)'{-h,--help}'[Show help message]' \\",
        "  '(-c --count)'{-c,--count}'[Number of names to generate]:count:' \\",
        "  '(-S --seed)'{-S,--seed}'[Seed random number generator deterministically]:seed:' \\",
        "  '(-u --unique)'{-u,--unique}'[Ensure no duplicate names are emitted]' \\",
        "  '(-m --match)'{-m,--match}'[Filter generated names by regular expression]:regex:' \\",
        "  '--min-len[Minimum character length]:length:' \\",
        "  '--max-len[Maximum character length]:length:' \\",
        "  '--compose[Compose multiple generators together]:generators:' \\",
        "  '--template[Template for composition]:template:' \\",
        "  '(-i --interactive)'{-i,--interactive}'[Launch interactive terminal explorer UI]' \\",
        "  '--json[Output results as a JSON array]' \\",
        "  '--csv[Output results in CSV format]' \\",
        "  '(--slug --kebab)'{--slug,--kebab}'[Convert output to lowercase kebab-case slugs]' \\",
        "  '(-s --separator)'{-s,--separator}'[Custom separator string]:separator:' \\",
        "  '(-x --null-separator)'{-x,--null-separator}'[Do not print separator]' \\",
        "  '(--cap --capcasing)'{--cap,--capcasing}'[Capitalize first letter of both words]' \\",
        "  '(--camel --camelcasing)'{--camel,--camelcasing}'[CamelCase style]' \\",
        "  '--debug[Enable debug output]' \\",
        "  '(-a --adj --adj-file)'{-a,--adj,--adj-file}'[Path to custom adjective file]:file:_files' \\",
        "  '(-n --noun --noun-file)'{-n,--noun,--noun-file}'[Path to custom noun file]:file:_files' \\"
    ]
    for i, (flag, desc) in enumerate(gens):
        clean_desc = desc.replace("'", "'\\''").replace("[", "\\[").replace("]", "\\]")
        trailing = " \\" if i + 1 < len(gens) else ""
        lines.append(f"  '--{flag}[{clean_desc}]'{trailing}")
    lines.append("")
    return "\n".join(lines)

def generate_fish(gens):
    lines = [
        "# Fish completion for namgen",
        "# Generated automatically by scripts/generate_completions.py",
        "",
        "complete -c namgen -s h -l help -d 'Show help message'",
        "complete -c namgen -s c -l count -d 'Number of names to generate' -x",
        "complete -c namgen -s S -l seed -d 'Seed random number generator deterministically' -x",
        "complete -c namgen -s u -l unique -d 'Ensure no duplicate names are emitted'",
        "complete -c namgen -s m -l match -d 'Filter names by regular expression' -x",
        "complete -c namgen -l min-len -d 'Minimum character length' -x",
        "complete -c namgen -l max-len -d 'Maximum character length' -x",
        "complete -c namgen -l compose -d 'Compose multiple generators together' -x",
        "complete -c namgen -l template -d 'Template for composition' -x",
        "complete -c namgen -s i -l interactive -d 'Launch interactive terminal explorer UI'",
        "complete -c namgen -l json -d 'Output results as a JSON array'",
        "complete -c namgen -l csv -d 'Output results in CSV format'",
        "complete -c namgen -l slug -d 'Convert output to lowercase kebab-case slugs'",
        "complete -c namgen -l kebab -d 'Convert output to lowercase kebab-case slugs'",
        "complete -c namgen -s s -l separator -d 'Custom separator string' -x",
        "complete -c namgen -s x -l null-separator -d 'Do not print the separator'",
        "complete -c namgen -l cap -l capcasing -d 'Capitalize first letter of both words'",
        "complete -c namgen -l camel -l camelcasing -d 'CamelCase style'",
        "complete -c namgen -l debug -d 'Enable debug output'",
        "complete -c namgen -s a -l adj -l adj-file -d 'Path to custom adjective file' -r",
        "complete -c namgen -s n -l noun -l noun-file -d 'Path to custom noun file' -r"
    ]
    for flag, desc in gens:
        clean_desc = desc.replace("'", "\\'")
        lines.append(f"complete -c namgen -l {flag} -d '{clean_desc}'")
    lines.append("")
    return "\n".join(lines)

def main():
    COMPLETIONS_DIR.mkdir(parents=True, exist_ok=True)
    gens = get_generators()
    print(f"Found {len(gens)} generators.")

    bash_file = COMPLETIONS_DIR / "namgen.bash"
    bash_file.write_text(generate_bash(gens))
    print(f"Wrote {bash_file}")

    zsh_file = COMPLETIONS_DIR / "_namgen"
    zsh_file.write_text(generate_zsh(gens))
    print(f"Wrote {zsh_file}")

    fish_file = COMPLETIONS_DIR / "namgen.fish"
    fish_file.write_text(generate_fish(gens))
    print(f"Wrote {fish_file}")

if __name__ == "__main__":
    main()
