#!/usr/bin/env python3
"""
Batch convert JavaScript fantasy name generators to C++17.
Usage:
    python3 scripts/batch_convert.py --category dungeon_and_dragons
    python3 scripts/batch_convert.py --all
"""
import argparse
import glob
import os
import subprocess
import sys

repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
js_base = os.path.join(repo_root, ".javascript-fantasy-names-deprecated", "generators")
src_dir = os.path.join(repo_root, "src")
transpiler = os.path.join(repo_root, "scripts", "transpile_generator.py")
update_reg = os.path.join(repo_root, "scripts", "update_registry.py")
gen_man = os.path.join(repo_root, "scripts", "generate_man.py")

def convert_one(js_file, force=False):
    rel = os.path.relpath(js_file, js_base)
    parts = rel.split(os.sep)
    category = parts[0]
    filename = os.path.splitext(parts[-1])[0].replace('wildstar_', '')
    mod_name = f"{category}-{filename}"

    header = os.path.join(src_dir, f"{mod_name}_lib.h")
    cpp = os.path.join(src_dir, f"{mod_name}_lib.cpp")

    if os.path.exists(header) and os.path.exists(cpp) and not force:
        # Check if it actually compiles
        check_existing = subprocess.run(
            ["g++", "-std=c++17", "-fsyntax-only", cpp, "-I", src_dir],
            capture_output=True, text=True
        )
        if check_existing.returncode == 0:
            return True, "already exists", mod_name
        # If it fails compilation, re-transpile it below

    # Run transpiler
    res = subprocess.run([sys.executable, transpiler, js_file, "-f"], capture_output=True, text=True)
    if res.returncode != 0:
        return False, f"Transpilation failed: {res.stderr.strip()}", mod_name

    # Test compilation
    check = subprocess.run(
        ["g++", "-std=c++17", "-fsyntax-only", cpp, "-I", src_dir],
        capture_output=True, text=True
    )
    if check.returncode != 0:
        # Cleanup broken files
        if os.path.exists(header): os.remove(header)
        if os.path.exists(cpp): os.remove(cpp)
        return False, f"Compilation syntax error: {check.stderr.strip()[:150]}", mod_name

    return True, "Transpiled & Verified", mod_name

def main():
    parser = argparse.ArgumentParser(description="Batch convert JS generators to C++17")
    parser.add_argument("--category", "-c", help="Category subdirectory to convert")
    parser.add_argument("--all", "-a", action="store_true", help="Convert all available categories")
    parser.add_argument("--files", "-f", nargs="+", help="Specific JS files to convert")
    parser.add_argument("--force", action="store_true", help="Force re-transpilation of existing files")

    args = parser.parse_args()

    if args.files:
        js_files = args.files
    elif args.category:
        cat_dir = os.path.join(js_base, args.category)
        if not os.path.isdir(cat_dir):
            print(f"Error: Category '{args.category}' not found.", file=sys.stderr)
            sys.exit(1)
        js_files = sorted(glob.glob(os.path.join(cat_dir, "*.js")))
    elif args.all:
        js_files = sorted(glob.glob(os.path.join(js_base, "**", "*.js"), recursive=True))
    else:
        parser.print_help()
        sys.exit(1)

    js_files = [f for f in js_files if not f.endswith(".min.js")]
    print(f"Starting batch conversion on {len(js_files)} generator(s)...")

    success_count = 0
    skipped_count = 0
    fail_count = 0
    failed_items = []

    for idx, f in enumerate(js_files, 1):
        ok, msg, mod = convert_one(f, force=args.force)
        if ok and "already exists" in msg:
            skipped_count += 1
            print(f"[{idx}/{len(js_files)}] SKIPPED: {mod}")
        elif ok:
            success_count += 1
            print(f"[{idx}/{len(js_files)}] SUCCESS: {mod}")
        else:
            fail_count += 1
            failed_items.append((mod, msg))
            print(f"[{idx}/{len(js_files)}] FAILED:  {mod} -> {msg[:80]}")

    print("\n" + "=" * 60)
    print(f"Batch Summary: {success_count} converted, {skipped_count} skipped, {fail_count} failed")
    if failed_items:
        print("\nFailed modules:")
        for mod, err in failed_items:
            print(f"  - {mod}: {err}")

    # Regenerate registry and man page
    if success_count > 0:
        print("\nUpdating registry and man page...")
        subprocess.run([sys.executable, update_reg], check=True)
        subprocess.run([sys.executable, gen_man], check=True)
        print("Done!")

if __name__ == '__main__':
    main()
