"""
namgen Python Package
High-performance procedural fantasy and real-world name generator with 900+ generators.
Supports zero-overhead in-process C-FFI (via libnamgen.so) and CLI subprocess fallback.
"""

import json
import os
import shutil
import subprocess
import ctypes
from pathlib import Path
from typing import List, Optional, Union

__version__ = "1.1.0"

_LOCAL_BIN = Path(__file__).resolve().parent.parent.parent / "namgen"
_LOCAL_SO = Path(__file__).resolve().parent.parent.parent / "libnamgen.so"
_LOCAL_WASM = Path(__file__).resolve().parent.parent.parent / "wasm" / "namgen-cli.js"

_LIB = None


def _get_native_lib():
    global _LIB
    if _LIB is not None:
        return _LIB

    candidate_paths = [
        _LOCAL_SO,
        Path(__file__).resolve().parent / "libnamgen.so",
        Path("/usr/local/lib/libnamgen.so"),
        Path("/usr/lib/libnamgen.so"),
    ]

    for p in candidate_paths:
        if p.exists():
            try:
                lib = ctypes.CDLL(str(p))
                lib.namgen_c_generate.argtypes = [
                    ctypes.c_char_p,
                    ctypes.c_int,
                    ctypes.c_uint,
                    ctypes.c_char_p,
                    ctypes.c_int,
                ]
                lib.namgen_c_generate.restype = ctypes.c_int

                lib.namgen_c_markov.argtypes = [
                    ctypes.c_char_p,
                    ctypes.c_int,
                    ctypes.c_int,
                    ctypes.c_uint,
                    ctypes.c_char_p,
                    ctypes.c_int,
                ]
                lib.namgen_c_markov.restype = ctypes.c_int

                lib.namgen_c_generator_count.argtypes = []
                lib.namgen_c_generator_count.restype = ctypes.c_int

                lib.namgen_c_generator_flag.argtypes = [ctypes.c_int]
                lib.namgen_c_generator_flag.restype = ctypes.c_char_p

                _LIB = lib
                return _LIB
            except Exception:
                continue
    return None


def _find_namgen_binary(custom_bin: Optional[str] = None) -> List[str]:
    if custom_bin and Path(custom_bin).exists():
        return [custom_bin]

    if _LOCAL_BIN.exists() and os.access(_LOCAL_BIN, os.X_OK):
        return [str(_LOCAL_BIN)]

    sys_bin = shutil.which("namgen")
    if sys_bin:
        return [sys_bin]

    if _LOCAL_WASM.exists() and shutil.which("node"):
        return ["node", str(_LOCAL_WASM)]

    raise RuntimeError(
        "Could not find 'namgen' executable or 'node wasm/namgen-cli.js'. "
        "Please build the project with 'make' or ensure 'namgen' is on your PATH."
    )


def fast_generate(generator: str = "fantasy-elfs", count: int = 1, seed: int = 0) -> List[str]:
    """
    Zero-overhead native C-FFI generation executing in <0.05ms without subprocesses.
    """
    lib = _get_native_lib()
    if lib:
        buf_size = max(4096, count * 128)
        buf = ctypes.create_string_buffer(buf_size)
        res = lib.namgen_c_generate(generator.encode("utf-8"), count, seed, buf, buf_size)
        if res > 0:
            return buf.value.decode("utf-8", errors="replace").splitlines()
    return generate(generator=generator, count=count, seed=seed if seed != 0 else None)


def markov(generator: str = "fantasy-elfs", count: int = 1, order: int = 3, seed: int = 0) -> List[str]:
    """
    Generate novel names synthesized via character n-gram Markov state machine.
    """
    lib = _get_native_lib()
    if lib:
        buf_size = max(4096, count * 128)
        buf = ctypes.create_string_buffer(buf_size)
        res = lib.namgen_c_markov(generator.encode("utf-8"), count, order, seed, buf, buf_size)
        if res > 0:
            return buf.value.decode("utf-8", errors="replace").splitlines()
    return generate(generator=generator, count=count, markov=True, order=order, seed=seed if seed != 0 else None)


def generate(
    generator: Optional[str] = None,
    count: int = 1,
    seed: Optional[int] = None,
    unique: bool = False,
    format: str = "plain",
    match: Optional[str] = None,
    min_len: Optional[int] = None,
    max_len: Optional[int] = None,
    syllables: Optional[str] = None,
    alliterate: bool = False,
    with_lore: bool = False,
    markov: bool = False,
    order: Optional[int] = None,
    compose: Optional[str] = None,
    template: Optional[str] = None,
    executable: Optional[str] = None,
) -> Union[List[str], str]:
    """
    Generate names using namgen CLI.
    """
    cmd = list(_find_namgen_binary(executable))

    if generator:
        flag = generator if generator.startswith("--") else f"--{generator}"
        cmd.append(flag)

    if count != 24:
        cmd.extend(["-c", str(count)])

    if seed is not None:
        cmd.extend(["-S", str(seed)])

    if unique:
        cmd.append("-u")

    if match:
        cmd.extend(["-m", match])

    if min_len is not None:
        cmd.extend(["--min-len", str(min_len)])

    if max_len is not None:
        cmd.extend(["--max-len", str(max_len)])

    if syllables:
        cmd.extend(["--syllables", str(syllables)])

    if alliterate:
        cmd.append("--alliterate")

    if with_lore:
        cmd.append("--with-lore")

    if markov:
        cmd.append("--markov")

    if order is not None:
        cmd.extend(["--order", str(order)])

    if compose:
        cmd.extend(["--compose", compose])

    if template:
        cmd.extend(["--template", template])

    if format == "json":
        cmd.append("--json")
    elif format == "csv":
        cmd.append("--csv")
    elif format == "slug":
        cmd.append("--slug")

    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    stdout = result.stdout.strip()

    if format == "json":
        return json.loads(stdout)
    elif format == "csv" or format == "slug":
        return stdout

    return [line for line in stdout.splitlines() if line]
