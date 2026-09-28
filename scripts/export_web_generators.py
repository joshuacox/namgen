#!/usr/bin/env python3
"""
Export all 907 JavaScript generators from .javascript-fantasy-names-deprecated/generators
into web/public/generators/<gen_id>.js wrapped for direct, safe execution in the browser.
"""
import os
import re
import json
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
GENS_JSON = REPO_ROOT / "web" / "data" / "generators.json"
SOURCE_BASE = REPO_ROOT / ".javascript-fantasy-names-deprecated" / "generators"
TARGET_DIR = REPO_ROOT / "web" / "public" / "generators"

def main():
    TARGET_DIR.mkdir(parents=True, exist_ok=True)
    with open(GENS_JSON, "r", encoding="utf-8") as f:
        generators = json.load(f)

    exported = 0
    missing = []

    for gen in generators:
        gen_id = gen["id"]
        parts = gen_id.split("-", 1)
        cat = parts[0]
        sub = parts[1] if len(parts) > 1 else parts[0]

        # Check for min.js or js
        p_min = SOURCE_BASE / cat / f"{sub}.min.js"
        if not p_min.exists():
            p_min = SOURCE_BASE / cat / f"{cat}_{sub}.min.js"
        if not p_min.exists():
            p_js = SOURCE_BASE / cat / f"{sub}.js"
            if not p_js.exists():
                p_js = SOURCE_BASE / cat / f"{cat}_{sub}.js"
            p_min = p_js

        if not p_min.exists():
            missing.append(gen_id)
            continue

        with open(p_min, "r", encoding="utf-8", errors="ignore") as f:
            code = f.read().strip()

        # Find entrypoint function name
        funcs = re.findall(r'function\s+([a-zA-Z0-9_\$]+)\s*\(', code)
        best = None
        for fn in funcs:
            if fn.startswith("generator$") and not fn.endswith("Male") and not fn.endswith("Female"):
                best = fn
                break
        if not best and funcs:
            best = funcs[0]

        if not best:
            missing.append(f"{gen_id} (no func)")
            continue

        # Wrap in safe IIFE with declared loop variables so strict mode doesn't throw ReferenceError
        wrapped = f"""(function(root) {{
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  {code}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {{}};
  root.__NAMGEN_GENS["{gen_id}"] = function(type) {{
    return {best}(type !== undefined ? type : 0);
  }};
}})(typeof window !== "undefined" ? window : globalThis);
"""
        target_file = TARGET_DIR / f"{gen_id}.js"
        target_file.write_text(wrapped, encoding="utf-8")
        exported += 1

    print(f"Exported {exported} / {len(generators)} generators to {TARGET_DIR}")
    if missing:
        print(f"Missing ({len(missing)}):", missing[:10])

if __name__ == "__main__":
    main()
