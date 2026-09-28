#!/usr/bin/env python3
"""Generate man/namgen.1 from registered C++ headers."""
import glob
import os

repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
man_path = os.path.join(repo_root, "man", "namgen.1")
headers = sorted(glob.glob(os.path.join(repo_root, "src", "*_lib.h")))

content = [
    r'.TH NAMGEN 1 "2026" "namgen" "User Commands"',
    r'.SH NAME',
    r'namgen \- Flexible name generator and procedural fantasy/sci-fi name generator',
    r'.SH SYNOPSIS',
    r'.B namgen',
    r'[OPTIONS]',
    r'.SH DESCRIPTION',
    r'.B namgen',
    r'generates names by combining adjectives and nouns with configurable casing and separators, or using built-in procedural name generators for fantasy and science fiction universes.',
    r'.SH OPTIONS',
    r'.TP',
    r'.B \-a, \-\-adj\-file FILE',
    r'Path to custom adjectives file',
    r'.TP',
    r'.B \-e, \-\-exclude STRING',
    r'Characters to strip from generated words (default: hyphen, apostrophe)',
    r'.TP',
    r'.B \-n, \-\-noun\-file FILE',
    r'Path to custom noun file',
    r'.TP',
    r'.B \-s SEP, \-\-separator SEP',
    r'Custom separator string (default: \-)',
    r'.TP',
    r'.B \-x, \-\-null\-separator',
    r'Do not print the separator (concatenates words)',
    r'.TP',
    r'.B \-c COUNT, \-\-count COUNT',
    r'Number of names to generate (default: terminal height)',
    r'.TP',
    r'.B \-\-cap, \-\-capcasing',
    r'Capitalize first letter of both adjective and noun',
    r'.TP',
    r'.B \-\-camel, \-\-camelcasing',
    r'CamelCase style (adjective lower-cased, noun capitalized)',
    r'.TP',
    r'.B \-\-debug',
    r'Enable debug output',
    r'.TP',
    r'.B \-\-elf, \-\-lotr\-elf, \-\-lord_of_the_rings\-elfs',
    r'Generate Lord of the Rings elf style names',
]

for h in headers:
    flag = os.path.basename(h).replace('_lib.h', '')
    if flag == 'lord_of_the_rings-elfs':
        continue
    roff_flag = r'\-\-' + flag.replace('-', r'\-')
    display_name = flag.replace('-', ' ').replace('_', ' ')
    content.append(r'.TP')
    content.append(f'.B {roff_flag}')
    content.append(f'Generate {display_name} style names')

content.extend([
    r'.TP',
    r'.B \-h, \-\-help',
    r'Show help message and exit',
    r'.SH AUTHORS',
    r'Written by Joshua Edward McLaughlin Cox and contributors.',
    r'.SH COPYRIGHT',
    r'GNU General Public License v3.',
    ''
])

with open(man_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(content))

print(f"Generated {man_path} successfully ({len(headers)} generator modules).")
