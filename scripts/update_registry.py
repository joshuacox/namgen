#!/usr/bin/env python3
"""Scan all src/*_lib.h files and regenerate src/generator_registry.cpp."""
import glob
import os
import re

repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
src_dir = os.path.join(repo_root, "src")
headers = sorted(glob.glob(os.path.join(src_dir, "*_lib.h")))

aliases_map = {
    'lord_of_the_rings-elfs': ['elf', 'lotr-elf', 'lord-of-the-rings-elfs'],
}

def make_description(flag):
    # Custom overrides
    special = {
        'descriptions-prophecys': 'Generate fantasy prophecy style descriptions',
        'military-royal_navy': 'Generate Royal Navy military call-sign style names',
        'military-united_states': 'Generate United States military NATO phonetic call-signs',
        'lord_of_the_rings-elfs': 'Generate Lord of the Rings elf style names',
    }
    if flag in special:
        return special[flag]
    
    parts = flag.split('-')
    cat = parts[0].replace('_', ' ').title()
    name = parts[1].replace('_', ' ').title() if len(parts) > 1 else ''
    if cat.lower() in name.lower():
        return f"Generate {name} style names"
    return f"Generate {cat} {name} style names".strip()

code = [
    '#include "generator_registry.h"',
    '#include <algorithm>',
    '#include <cctype>',
    '#include <memory>',
    '',
]

for h in headers:
    code.append(f'#include "{os.path.basename(h)}"')

code.extend([
    '',
    'static std::string normalizeKey(const std::string& key) {',
    '    std::string s = key;',
    '    if (s.rfind("--", 0) == 0) {',
    '        s = s.substr(2);',
    '    }',
    '    for (char& c : s) {',
    '        if (c == \'_\') {',
    '            c = \'-\';',
    '        } else {',
    '            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));',
    '        }',
    '    }',
    '    return s;',
    '}',
    '',
    'GeneratorRegistry& GeneratorRegistry::instance() {',
    '    static GeneratorRegistry reg;',
    '    return reg;',
    '}',
    '',
    'GeneratorRegistry::GeneratorRegistry() {',
    '    initBuiltins();',
    '}',
    '',
    'void GeneratorRegistry::registerGenerator(GeneratorInfo info) {',
    '    auto ptr = std::make_unique<GeneratorInfo>(std::move(info));',
    '    const GeneratorInfo* raw = ptr.get();',
    '    generators_.push_back(std::move(ptr));',
    '    lookup_[normalizeKey(raw->flag)] = raw;',
    '    lookup_[raw->flag] = raw;',
    '    for (const auto& alias : raw->aliases) {',
    '        lookup_[normalizeKey(alias)] = raw;',
    '        lookup_[alias] = raw;',
    '    }',
    '}',
    '',
    'const GeneratorInfo* GeneratorRegistry::find(const std::string& flagName) const {',
    '    auto it = lookup_.find(normalizeKey(flagName));',
    '    if (it != lookup_.end()) {',
    '        return it->second;',
    '    }',
    '    auto it2 = lookup_.find(flagName);',
    '    if (it2 != lookup_.end()) {',
    '        return it2->second;',
    '    }',
    '    return nullptr;',
    '}',
    '',
    'const std::vector<std::unique_ptr<GeneratorInfo>>& GeneratorRegistry::getAll() const {',
    '    return generators_;',
    '}',
    '',
    'void GeneratorRegistry::initBuiltins() {',
])

for h in headers:
    flag = os.path.basename(h).replace('_lib.h', '')
    desc = make_description(flag)
    aliases = aliases_map.get(flag, [])
    alias_str = '{' + ', '.join(f'"{a}"' for a in aliases) + '}'
    
    with open(h, encoding='utf-8') as f:
        content = f.read()
    m = re.search(r'std::string\s+([a-zA-Z0-9_]+)\s*\(([^)]*)\)', content)
    if not m:
        continue
    fn = m.group(1)
    args = m.group(2)
    
    if fn == 'generate_lotr_elf_name':
        call_expr = 'generate_lotr_elf_name(1)'
    elif 'type' in args:
        call_expr = f'{fn}(rng, 0)'
    else:
        call_expr = f'{fn}(rng)'
        
    code.append('    registerGenerator({')
    code.append(f'        "{flag}",')
    code.append(f'        {alias_str},')
    code.append(f'        "{desc}",')
    code.append(f'        [](std::mt19937& rng) {{ return {call_expr}; }}')
    code.append('    });')

code.extend(['}', ''])

out_path = os.path.join(src_dir, "generator_registry.cpp")
with open(out_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(code))

print(f"Updated {out_path} with {len(headers)} registered generators.")
