#!/usr/bin/env python3
"""
Transpile a JavaScript fantasy name generator to C++17.
Usage:
    python3 scripts/transpile_generator.py <path_to_js_file> [--force]
"""
import os
import re
import sys
import argparse

def find_matching_bracket(code, start_idx):
    depth = 0
    in_quote = None
    escape = False
    for i in range(start_idx, len(code)):
        ch = code[i]
        if escape:
            escape = False
            continue
        if ch == '\\':
            escape = True
            continue
        if in_quote:
            if ch == in_quote:
                in_quote = None
            continue
        if ch in ('"', "'"):
            in_quote = ch
            continue
        if ch == '[':
            depth += 1
        elif ch == ']':
            depth -= 1
            if depth == 0:
                return i
    return -1

def find_matching_brace(code, start_idx):
    depth = 0
    in_quote = None
    escape = False
    for i in range(start_idx, len(code)):
        ch = code[i]
        if escape:
            escape = False
            continue
        if ch == '\\':
            escape = True
            continue
        if in_quote:
            if ch == in_quote:
                in_quote = None
            continue
        if ch in ('"', "'"):
            in_quote = ch
            continue
        if ch == '{':
            depth += 1
        elif ch == '}':
            depth -= 1
            if depth == 0:
                return i
    return -1

def parse_js(js_path):
    with open(js_path, 'r', encoding='utf-8', errors='ignore') as f:
        code = f.read().replace('\ufeff', '')

    # Match generator function name
    m_func = re.search(r'function\s+([a-zA-Z0-9_$]+)\s*\(([^)]*)\)\s*\{', code)
    if not m_func:
        return None, "Function signature not found"

    func_name = m_func.group(1)
    params = m_func.group(2).strip()
    has_type = 'type' in params

    func_close_idx = find_matching_brace(code, m_func.end() - 1)
    if func_close_idx == -1:
        func_close_idx = len(code)

    # Find all array definitions: var <name> = [ ... ];
    raw_arrays = []
    pattern = re.compile(r'(?:var\s+)?([a-zA-Z0-9_]+)\s*=\s*\[', re.MULTILINE)
    for match in pattern.finditer(code):
        if match.start() >= func_close_idx:
            break
        var_name = match.group(1)
        start_idx = match.start()
        bracket_start = match.end() - 1  # at '['
        bracket_end = find_matching_bracket(code, bracket_start)
        if bracket_end == -1:
            continue
        array_content = code[bracket_start:bracket_end+1]
        end_pos = bracket_end + 1
        m_semi = re.match(r'^[ \t]*;+', code[end_pos:])
        if m_semi:
            end_pos += m_semi.end()

        if re.match(r'^\s*\[\s*\]\s*$', array_content.strip()):
            continue

        raw_arrays.append({
            'name': var_name,
            'start': start_idx,
            'end': end_pos,
            'content': array_content
        })

    if not raw_arrays:
        return None, "No array definitions found"

    # Count occurrences of array names
    counts = {}
    for a in raw_arrays:
        counts[a['name']] = counts.get(a['name'], 0) + 1

    duplicate_names = {name for name, cnt in counts.items() if cnt > 1}
    body_raw = code[m_func.end():func_close_idx]
    reassigned_names = set(duplicate_names)
    for a in raw_arrays:
        aname = a['name']
        if re.search(rf'(?<!var\s)\b{aname}\s*=', body_raw):
            reassigned_names.add(aname)

    # Build unique static array definitions and body replacements
    array_defs = []
    # Replace from back to front in code to maintain indices
    occurrences = {}
    code_mod = list(code[m_func.end():func_close_idx])  # code inside function body
    func_offset = m_func.end()

    # Sort raw_arrays by start descending
    sorted_raw = sorted(raw_arrays, key=lambda x: x['start'], reverse=True)
    for a in sorted_raw:
        var_name = a['name']
        s = a['start'] - func_offset
        e = a['end'] - func_offset
        if s < 0 or e > len(code_mod):
            continue

        if var_name in reassigned_names:
            occ = occurrences.get(var_name, counts.get(var_name, 1))
            occurrences[var_name] = occ - 1
            unique_name = f"{var_name}_{occ}"
            array_defs.insert(0, (unique_name, a['content']))
            replacement = f"{var_name} = make_view({unique_name});"
        else:
            array_defs.insert(0, (var_name, a['content']))
            replacement = ""

        code_mod[s:e] = list(replacement)

    body = "".join(code_mod).strip()

    return {
        'func_name': func_name,
        'has_type': has_type,
        'arrays': array_defs,
        'array_view_vars': reassigned_names,
        'body': body
    }, None

def transpile_body(body, array_names, array_view_vars=None, has_type=False):
    if array_view_vars is None:
        array_view_vars = set()

    lines = body.split('\n')
    cpp_lines = []
    
    # Collect all assigned variables in body
    assign_matches = re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=', body)
    return_matches = re.findall(r'return\s+([a-zA-Z_][a-zA-Z0-9_]*)', body)
    math_vars = set(re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(?:parseInt\s*\(\s*)?\(?\s*Math\.(?:floor|random)', body))
    math_vars.update(re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=[^;\n]*\|\s*0', body))

    float_vars = set(re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=[^;\n]*(?:/\s*10|0\.393701)', body))
    for f_candidate in ('gnd', 'intelligent', 'basicLife'):
        if f_candidate in body:
            float_vars.add(f_candidate)
    if not has_type and 'type' in assign_matches: # if type is a local variable
        float_vars.add('type')

    # Collect array aliases: e.g. namesFirst = names1; or names1 = type === 1 ? namesFemale : namesMale;
    alias_matches = re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*;', body)
    ternary_matches = re.findall(r'(?:var\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*([^?;\n]+)\?\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*:\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*;*', body)

    changed = True
    while changed:
        changed = False
        for lhs, rhs in alias_matches:
            if (rhs in array_names or rhs in array_view_vars) and lhs not in array_view_vars:
                array_view_vars.add(lhs)
                changed = True
        for lhs, cond, rhs1, rhs2 in ternary_matches:
            if (rhs1 in array_names or rhs1 in array_view_vars or rhs2 in array_names or rhs2 in array_view_vars) and lhs not in array_view_vars:
                array_view_vars.add(lhs)
                changed = True

    rnd_vars = set()
    int_vars = set()
    string_vars = set()

    INT_VAR_NAMES = {'i', 'j', 'k', 'v', 'w', 'x', 'y', 'z', 'attk1', 'attk2', 'lifeType', 'maxGrav', 'maxSize', 'minGrav', 'minSize', 'planetType', 'tyr'}

    for v in set(assign_matches) | set(return_matches):
        if v in array_names or v in array_view_vars or (v == 'type' and has_type):
            continue
        if v in float_vars:
            continue
        if re.search(r'(?:var\s+)?\b' + re.escape(v) + r'\s*=\s*(?:[a-zA-Z0-9_]+\.toString\(|")', body):
            string_vars.add(v)
            continue
        if v in INT_VAR_NAMES:
            int_vars.add(v)
        elif re.search(r'(?:var\s+)?\b' + re.escape(v) + r'\s*=\s*\(?\s*(?:Math\.|\d+|/\s*10)', body):
            if re.match(r'^(rnd|random)[0-9a-zA-Z]*$', v):
                rnd_vars.add(v)
            else:
                int_vars.add(v)
        elif re.match(r'^(rnd|random)[0-9a-zA-Z]*$', v) or v in math_vars:
            rnd_vars.add(v)
        else:
            string_vars.add(v)

    if not int_vars:
        int_vars.add('i')

    # Header declarations for variables
    decl_line = []
    for av in sorted(array_view_vars):
        decl_line.append(f'ArrayView {av};')
    for fv in sorted(float_vars):
        decl_line.append(f'double {fv} = 0.0;')
    for s in sorted(string_vars):
        decl_line.append(f'std::string {s};')
    for r in sorted(rnd_vars):
        decl_line.append(f'size_t {r} = 0;')
    for iv in sorted(int_vars):
        decl_line.append(f'int {iv} = 0;')

    cpp_lines.append('    ' + ' '.join(decl_line))
    cpp_lines.append('')

    def fix_array_names(text):
        def repl(m):
            aname = m.group(1)
            idx = m.group(2)
            if aname not in array_names and aname not in array_view_vars:
                for a in list(array_names) + list(array_view_vars):
                    if a.startswith(aname):
                        aname = a
                        break
            return f"{aname}[{idx}]"
        return re.sub(r'([a-zA-Z0-9_]+)\[([a-zA-Z0-9_]+)\]', repl, text)

    last_array_for_rnd = {}

    for line in lines:
        stripped = line.strip()
        if not stripped:
            continue

        # Skip splice calls
        if '.splice(' in stripped:
            continue

        # Skip empty array assignments: e.g. names = []; or var names = [];
        if re.match(r'^(?:var\s+)?[a-zA-Z_][a-zA-Z0-9_]*\s*=\s*\[\s*\]\s*;?', stripped):
            continue

        # Strip 'var ' at beginning of lines
        if stripped.startswith('var '):
            stripped = stripped[4:].strip()

        # Add missing semicolon for assignment lines
        if re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*\s*=', stripped) and not stripped.endswith(';') and not stripped.endswith('{') and not stripped.endswith('}'):
            stripped += ';'

        # Upstream bug and typo normalization
        stripped = re.sub(r'\brnd24\s*=\s*" shirt "', 'nm24 = " shirt "', stripped)
        stripped = re.sub(r'\bnames(\d+)\s*(<|>|<=|>=)\s*(\d+)', r'random\1 \2 \3', stripped)
        stripped = re.sub(r'([a-zA-Z0-9_]+)\.toString\(\)', r'std::to_string(\1)', stripped)
        if re.match(r'^\s*null\s*;\s*$', stripped):
            continue

        # Math.floor(Math.random() * (A - B + 1)) + B
        def repl_range(m):
            a, b, c = int(m.group(1)), int(m.group(2)), int(m.group(3))
            return f'((rng() % {a - b + 1}) + {c})'
        stripped = re.sub(r'Math\.floor\s*\(\s*Math\.random\s*\(\s*\)\s*\*\s*\(\s*(\d+)\s*-\s*(\d+)\s*\+\s*1\s*\)\s*\)\s*\+\s*(\d+)', repl_range, stripped)

        # Bitwise or with 0: (Math.random() * N | 0) or (expr | 0)
        stripped = re.sub(r'\(?\s*Math\.random\s*\(\s*\)\s*\*\s*(\d+)\s*\|\s*0\s*\)?', r'(rng() % \1)', stripped)
        stripped = re.sub(r'\(\s*([^|;]+?)\s*\|\s*0\s*\)', r'((int)(\1))', stripped)



        # rndX = Math.floor((Math.random() * N) + M); or Math.floor(Math.random() * N) + M;
        m_rnd_add = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(?:parseInt\s*\(\s*)?Math\.floor\s*\(\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*(\d+)\s*\)?\s*(?:\+\s*(\d+)\s*\)|\)\s*\+\s*(\d+))\s*;?', stripped)
        if m_rnd_add:
            var_name = m_rnd_add.group(1)
            n = m_rnd_add.group(2)
            add_n = m_rnd_add.group(3) or m_rnd_add.group(4)
            cpp_lines.append(f'    {var_name} = (rng() % {n}) + {add_n};')
            continue

        # i = Math.floor(Math.random() * N); {
        m_i = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(?:parseInt\s*\(\s*)?Math\.floor\s*\(\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*(\d+)\s*\)?\s*\)\s*\)?\s*;?(.*)', stripped)
        if m_i:
            var_name = m_i.group(1)
            n = m_i.group(2)
            rest = m_i.group(3).strip()
            if rest.startswith('+') or rest.startswith('-'):
                m_op = re.match(r'([+-])\s*(\d+)\s*;?(.*)', rest)
                if m_op:
                    op = m_op.group(1)
                    val = m_op.group(2)
                    r_rest = m_op.group(3).strip()
                    cpp_lines.append(f'    {var_name} = (rng() % {n}) {op} {val}; {r_rest}'.strip())
                    continue
            cpp_lines.append(f'    {var_name} = rng() % {n}; {rest}'.strip())
            continue

        # rndX = Math.floor(Math.random() * arr.length);
        m_rnd = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(?:parseInt\s*\(\s*)?Math\.floor\s*\(\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*([a-zA-Z_][a-zA-Z0-9_]*)\.length\s*\)?\s*\)\s*\)?\s*;?', stripped)
        if m_rnd:
            var_name = m_rnd.group(1)
            arr = m_rnd.group(2)
            if arr not in array_names and arr not in array_view_vars:
                for a in list(array_names) + list(array_view_vars):
                    if a.startswith(arr):
                        arr = a
                        break
            last_array_for_rnd[var_name] = arr
            cpp_lines.append(f'    {var_name} = rng() % std::size({arr});')
            continue

        # rndX = Math.floor(Math.random() * (arr.length - N));
        m_rnd_sub = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(?:parseInt\s*\(\s*)?Math\.floor\s*\(\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*\(([a-zA-Z_][a-zA-Z0-9_]*)\.length\s*-\s*(\d+)\)\s*\)?\s*\)\s*\)?\s*;?', stripped)
        if m_rnd_sub:
            var_name = m_rnd_sub.group(1)
            arr = m_rnd_sub.group(2)
            sub_n = m_rnd_sub.group(3)
            if arr not in array_names and arr not in array_view_vars:
                for a in list(array_names) + list(array_view_vars):
                    if a.startswith(arr):
                        arr = a
                        break
            last_array_for_rnd[var_name] = arr
            cpp_lines.append(f'    {var_name} = rng() % (std::size({arr}) - {sub_n});')
            continue

        # Auto-heal upstream bug: while (rnd === "") -> while (arr[rnd] == "")
        m_cmp_empty = re.match(r'(while|if)\s*\(\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*(===?|!==?)\s*""\s*\)\s*(\{?)', stripped)
        if m_cmp_empty:
            kw = m_cmp_empty.group(1)
            v = m_cmp_empty.group(2)
            op = '==' if '!' not in m_cmp_empty.group(3) else '!='
            brace = m_cmp_empty.group(4)
            if v in last_array_for_rnd:
                arr = last_array_for_rnd[v]
                cpp_lines.append(f'    {kw} ({arr}[{v}] {op} "") {brace}'.strip())
                continue

        # tyr = Math.random() * 300 | 0; or Math.random() * arr.length | 0;
        m_bitwise = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*([^|;]+?)\s*\)?\s*\|\s*0\s*;?', stripped)
        if m_bitwise:
            var_name = m_bitwise.group(1)
            expr = m_bitwise.group(2).strip()
            m_arr = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\.length', expr)
            if m_arr:
                arr = m_arr.group(1)
                cpp_lines.append(f'    {var_name} = rng() % std::size({arr});')
            else:
                cpp_lines.append(f'    {var_name} = rng() % ({expr});')
            continue

        # Array alias ternary assignment: e.g. names1 = type === 1 ? namesFemale : namesMale;
        m_ternary = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.*?)\s*\?\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*:\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*;*$', stripped)
        if m_ternary and m_ternary.group(1) in array_view_vars:
            lhs = m_ternary.group(1)
            cond = m_ternary.group(2).strip().replace('===', '==')
            rhs1 = m_ternary.group(3)
            rhs2 = m_ternary.group(4)
            cpp_lines.append(f'    {lhs} = ({cond}) ? make_view({rhs1}) : make_view({rhs2});')
            continue

        # Array alias assignment: e.g. namesFirst = names1; -> namesFirst = make_view(names1);
        m_alias = re.match(r'([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*;', stripped)
        if m_alias and m_alias.group(1) in array_view_vars and (m_alias.group(2) in array_names or m_alias.group(2) in array_view_vars):
            cpp_lines.append(f'    {m_alias.group(1)} = make_view({m_alias.group(2)});')
            continue

        # Handle names[i] = ... when names is a string
        m_names_idx = re.match(r'^names\[[a-zA-Z0-9_]+\]\s*=\s*(.*)', stripped)
        if m_names_idx and 'names' in string_vars:
            rhs = m_names_idx.group(1)
            rhs_clean = fix_array_names(rhs)
            cpp_lines.append(f'    names = {rhs_clean}')
            continue

        # Fix array name typos
        s = fix_array_names(stripped)

        # Capitalize helper
        s = re.sub(r'([a-zA-Z0-9_]+)\.substr\(0,\s*1\)\.toUpperCase\(\)\s*\+\s*\1\.substr\(1\)', r'capitalize(\1)', s)

        # Substring and case helpers
        s = re.sub(r'([a-zA-Z0-9_\[\]]+)\.substring\(0,\s*([^)]+)\)\.toLowerCase\(\)', r'to_lower(\1.substr(0, \2))', s)
        s = re.sub(r'([a-zA-Z0-9_\[\]]+)\.substring\(0,\s*([^)]+)\)', r'std::string(\1.substr(0, \2))', s)
        s = re.sub(r'([a-zA-Z0-9_\[\]]+)\.toLowerCase\(\)', r'to_lower(\1)', s)

        # Standard JS to C++ replacements
        s = s.replace('===', '==')
        s = s.replace('!==', '!=')
        s = s.replace('var ', '')

        # Fall-through math and random replacements
        s = re.sub(r'\(Math\.floor\(\(Math\.random\(\)\s*\*\s*(\d+)\)\s*\+\s*(\d+)\)\)\s*/\s*(\d+)', r'((double)((rng() % \1) + \2)) / \3', s)
        s = re.sub(r'Math\.floor\s*\(\s*\(?\s*Math\.random\s*\(\s*\)\s*\*\s*(\d+)\s*\)?\s*\+\s*(\d+)\s*\)', r'((rng() % \1) + \2)', s)
        s = re.sub(r'Math\.floor\s*\(\s*Math\.random\s*\(\s*\)\s*\*\s*(\d+)\s*\)', r'(rng() % \1)', s)
        s = re.sub(r'\bMath\.random\s*\(\s*\)', r'((double)(rng() % 10000) / 10000.0)', s)
        s = re.sub(r'\bMath\.floor\b', r'std::floor', s)
        s = re.sub(r'\bparseInt\s*\(', r'(int)(', s)

        # Convert int/double + "..." or "..." + int/double to std::to_string
        for iv in list(int_vars) + list(float_vars):
            s = re.sub(rf'\b{iv}\s*\+\s*"', f'std::to_string({iv}) + "', s)
            s = re.sub(rf'"\s*\+\s*{iv}\b', f'" + std::to_string({iv})', s)
        
        # Replace remaining arr.length for arrays and array views
        for arr in list(array_names) + list(array_view_vars):
            s = re.sub(rf'\b{arr}\.length\b', f'std::size({arr})', s)

        # Replace str.length for string variables
        for sv in string_vars:
            s = re.sub(rf'\b{sv}\.length\b', f'{sv}.length()', s)

        # Replace any remaining .length on expressions with .length()
        s = re.sub(r'\.length(?!\(\))\b', '.length()', s)

        # Clean trailing extra semicolons (e.g. ;; -> ;)
        s = re.sub(r';+;$', ';', s)

        cpp_lines.append('    ' + s)

    return '\n'.join(cpp_lines)

def normalize_array_content(content):
    def repl(m):
        full = m.group(0)
        if full.startswith('"'):
            return full
        item = m.group(2)
        item = item.replace(r"\'", "'")
        item = item.replace('"', r'\"')
        return f'"{item}"'
    return re.sub(r'"([^"\\]*(?:\\.[^"\\]*)*)"|\'([^\'\\]*(?:\\.[^\'\\]*)*)\'', repl, content)

def transpile_file(js_path, output_dir=None, force=False):
    parsed, err = parse_js(js_path)
    if err:
        return False, f"Parse error: {err}"

    # Determine category and name from path
    rel_path = os.path.relpath(js_path, '/home/thoth/namgen/.javascript-fantasy-names-deprecated/generators')
    parts = rel_path.split(os.sep)
    category = parts[0]
    filename = os.path.splitext(parts[-1])[0].replace('wildstar_', '')
    mod_name = f"{category}-{filename}"

    repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    target_dir = output_dir or os.path.join(repo_root, "src")

    header_file = os.path.join(target_dir, f"{mod_name}_lib.h")
    cpp_file = os.path.join(target_dir, f"{mod_name}_lib.cpp")

    if os.path.exists(header_file) and not force:
        return False, f"{header_file} already exists (use --force to overwrite)"

    c_func_name = f"generate_{mod_name.replace('-', '_')}_name"
    guard = f"{mod_name.upper().replace('-', '_')}_LIB_H"

    # Generate Header
    has_type = parsed['has_type']
    type_param = "int type = 0" if has_type else ""
    header_content = f"""#ifndef {guard}
#define {guard}

#include <random>
#include <string>

std::string {c_func_name}(std::mt19937& rng{', ' + type_param if type_param else ''});

#endif // {guard}
"""

    # Generate Cpp
    array_names = [a[0] for a in parsed['arrays']]
    body_cpp = transpile_body(parsed['body'], array_names, parsed['array_view_vars'], has_type=has_type)

    cpp_parts = [
        f'#include "{mod_name}_lib.h"',
        '#include "generator_common.h"',
        '#include <string_view>',
        '#include <string>',
        '#include <iterator>',
        '',
        f'std::string {c_func_name}(std::mt19937& rng{", int type" if has_type else ""}) {{'
    ]

    # Arrays
    for arr_name, arr_content in parsed['arrays']:
        # Ensure single string format and convert 'single-quotes' to "double-quotes"
        clean_content = normalize_array_content(arr_content.strip())
        is_2d = bool(re.search(r'\[\s*\[', clean_content))
        if is_2d:
            # Replace inner pairs [ [ "a" ], [ "b" ] ] or [ "a", "b" ] with { "a", "b" }
            clean_content = re.sub(r'\[\s*\[\s*("[^"\\]*(?:\\.[^"\\]*)*")\s*\]\s*,\s*\[\s*("[^"\\]*(?:\\.[^"\\]*)*")\s*\]\s*\]', r'{\1, \2}', clean_content)
            clean_content = re.sub(r'\[\s*("[^"\\]*(?:\\.[^"\\]*)*")\s*,\s*("[^"\\]*(?:\\.[^"\\]*)*")\s*\]', r'{\1, \2}', clean_content)
            init_content = "{" + clean_content[1:-1] + "}"
            cpp_parts.append(f"    static constexpr std::string_view {arr_name}[][2] = {init_content};")
        else:
            init_content = "{" + clean_content[1:-1] + "}"
            cpp_parts.append(f"    static constexpr std::string_view {arr_name}[] = {init_content};")

    cpp_parts.append('')
    cpp_parts.append(body_cpp)
    cpp_parts.append('}')
    cpp_parts.append('')

    with open(header_file, 'w', encoding='utf-8') as f:
        f.write(header_content)

    with open(cpp_file, 'w', encoding='utf-8') as f:
        f.write('\n'.join(cpp_parts))

    return True, f"Generated {mod_name}_lib.h and {mod_name}_lib.cpp"

def main():
    parser = argparse.ArgumentParser(description="Transpile fantasy name generator from JS to C++17")
    parser.add_argument("js_file", help="Path to input JS generator file")
    parser.add_argument("--force", "-f", action="store_true", help="Overwrite existing files")
    parser.add_argument("--out-dir", "-o", default=None, help="Output directory (default: src/)")

    args = parser.parse_args()
    success, msg = transpile_file(args.js_file, args.out_dir, args.force)
    if success:
        print(f"SUCCESS: {msg}")
    else:
        print(f"FAILED: {msg}", file=sys.stderr)
        sys.exit(1)

if __name__ == '__main__':
    main()
