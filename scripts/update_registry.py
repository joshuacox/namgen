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
        'brand-arcane_cyberpunk': 'Generate Arcane / Cyberpunk brand and game title candidates',
        'brand-classical_etymology': 'Generate Classical Etymology Latin and Greek brand names',
        'brand-punchy_portmanteaus': 'Generate Punchy Portmanteau compound brand and game titles',
        'brand-functional_minimalist': 'Generate Functional Minimalist two-word title candidates',
        'brand-sovereign_neologisms': 'Generate Sovereign Neologism coined phonetic brand names',
        'tabletop-plot_hooks': 'Generate tabletop RPG plot hooks and quest sparks',
        'tabletop-tavern_rumors': 'Generate fantasy tavern rumors and town gossip',
        'tabletop-item_quirks': 'Generate magic item quirks, curses, and arcane history',
        'tabletop-villain_schemes': 'Generate antagonist plots, schemes, and masterplans',
        'tabletop-dungeon_traps': 'Generate dungeon traps, hazards, and arcane puzzles',
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
    'static bool isConsonant(char c) {',
    '    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));',
    "    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');",
    '}',
    '',
    'static std::vector<std::string> generateSpellingVariants(const std::string& key) {',
    '    std::vector<std::string> variants;',
    '    if (key.find("citys") != std::string::npos) {',
    '        std::string v = key;',
    '        std::size_t pos = 0;',
    '        while ((pos = v.find("citys", pos)) != std::string::npos) {',
    '            v.replace(pos, 5, "cities");',
    '            pos += 6;',
    '        }',
    '        variants.push_back(v);',
    '    }',
    '    if (key.find("cities") != std::string::npos) {',
    '        std::string v = key;',
    '        std::size_t pos = 0;',
    '        while ((pos = v.find("cities", pos)) != std::string::npos) {',
    '            v.replace(pos, 6, "citys");',
    '            pos += 5;',
    '        }',
    '        variants.push_back(v);',
    '    }',
    '    if (key.size() >= 3 && key.rfind("ys") == key.size() - 2 && isConsonant(key[key.size() - 3])) {',
    '        variants.push_back(key.substr(0, key.size() - 2) + "ies");',
    '    }',
    '    if (key.size() >= 4 && key.rfind("ies") == key.size() - 3 && isConsonant(key[key.size() - 4])) {',
    '        variants.push_back(key.substr(0, key.size() - 3) + "ys");',
    '    }',
    '    // elfs <-> elves, dwarfs <-> dwarves, wolfs <-> wolves, halfs <-> halves',
    '    auto replaceAll = [](std::string str, const std::string& from, const std::string& to) -> std::string {',
    '        size_t start_pos = 0;',
    '        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {',
    '            str.replace(start_pos, from.length(), to);',
    '            start_pos += to.length();',
    '        }',
    '        return str;',
    '    };',
    '    if (key.find("elfs") != std::string::npos) variants.push_back(replaceAll(key, "elfs", "elves"));',
    '    if (key.find("elves") != std::string::npos) variants.push_back(replaceAll(key, "elves", "elfs"));',
    '    if (key.find("dwarfs") != std::string::npos) variants.push_back(replaceAll(key, "dwarfs", "dwarves"));',
    '    if (key.find("dwarves") != std::string::npos) variants.push_back(replaceAll(key, "dwarves", "dwarfs"));',
    '    if (key.find("wolfs") != std::string::npos) variants.push_back(replaceAll(key, "wolfs", "wolves"));',
    '    if (key.find("wolves") != std::string::npos) variants.push_back(replaceAll(key, "wolves", "wolfs"));',
    '    if (key.find("halfs") != std::string::npos) variants.push_back(replaceAll(key, "halfs", "halves"));',
    '    if (key.find("halves") != std::string::npos) variants.push_back(replaceAll(key, "halves", "halfs"));',
    '    return variants;',
    '}',
    '',
    'void GeneratorRegistry::registerGenerator(GeneratorInfo info) {',
    '    auto ptr = std::make_unique<GeneratorInfo>(std::move(info));',
    '    const GeneratorInfo* raw = ptr.get();',
    '    generators_.push_back(std::move(ptr));',
    '    lookup_[normalizeKey(raw->flag)] = raw;',
    '    lookup_[raw->flag] = raw;',
    '    for (const auto& variant : generateSpellingVariants(normalizeKey(raw->flag))) {',
    '        lookup_[variant] = raw;',
    '    }',
    '    for (const auto& alias : raw->aliases) {',
    '        lookup_[normalizeKey(alias)] = raw;',
    '        lookup_[alias] = raw;',
    '        for (const auto& variant : generateSpellingVariants(normalizeKey(alias))) {',
    '            lookup_[variant] = raw;',
    '        }',
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
    '    for (const auto& variant : generateSpellingVariants(normalizeKey(flagName))) {',
    '        auto itv = lookup_.find(variant);',
    '        if (itv != lookup_.end()) {',
    '            return itv->second;',
    '        }',
    '    }',
    '    return nullptr;',
    '}',
    '',
    'std::vector<const GeneratorInfo*> GeneratorRegistry::search(const std::string& query) const {',
    '    std::vector<const GeneratorInfo*> results;',
    '    if (query.empty()) return results;',
    '',
    '    std::string q = query;',
    '    std::transform(q.begin(), q.end(), q.begin(), [](unsigned char c) { return std::tolower(c); });',
    '    std::string qNorm = normalizeKey(q);',
    '',
    '    for (const auto& gen : generators_) {',
    '        std::string flagLower = gen->flag;',
    '        std::transform(flagLower.begin(), flagLower.end(), flagLower.begin(), [](unsigned char c) { return std::tolower(c); });',
    '        std::string flagNorm = normalizeKey(gen->flag);',
    '',
    '        std::string descLower = gen->description;',
    '        std::transform(descLower.begin(), descLower.end(), descLower.begin(), [](unsigned char c) { return std::tolower(c); });',
    '',
    '        bool match = (flagLower.find(q) != std::string::npos) ||',
    '                     (flagNorm.find(qNorm) != std::string::npos) ||',
    '                     (descLower.find(q) != std::string::npos);',
    '',
    '        if (!match) {',
    '            for (const auto& alias : gen->aliases) {',
    '                std::string aLower = alias;',
    '                std::transform(aLower.begin(), aLower.end(), aLower.begin(), [](unsigned char c) { return std::tolower(c); });',
    '                if (aLower.find(q) != std::string::npos || normalizeKey(alias).find(qNorm) != std::string::npos) {',
    '                    match = true;',
    '                    break;',
    '                }',
    '            }',
    '        }',
    '',
    '        if (match) {',
    '            results.push_back(gen.get());',
    '        }',
    '    }',
    '    return results;',
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
