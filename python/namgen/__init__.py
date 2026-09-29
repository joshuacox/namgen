"""
namgen Python Package
High-performance procedural fantasy and real-world name generator with 900+ generators.
"""

import json
import os
import shutil
import subprocess
from pathlib import Path
from typing import List, Optional, Union

__version__ = "1.0.0"

_LOCAL_BIN = Path(__file__).resolve().parent.parent.parent / "namgen"
_LOCAL_WASM = Path(__file__).resolve().parent.parent.parent / "wasm" / "namgen-cli.js"


def _find_namgen_binary(custom_bin: Optional[str] = None) -> List[str]:
    if custom_bin and Path(custom_bin).exists():
        return [custom_bin]

    # Check local repo build
    if _LOCAL_BIN.exists() and os.access(_LOCAL_BIN, os.X_OK):
        return [str(_LOCAL_BIN)]

    # Check system PATH
    sys_bin = shutil.which("namgen")
    if sys_bin:
        return [sys_bin]

    # Fallback to local WASM runner via Node.js
    if _LOCAL_WASM.exists() and shutil.which("node"):
        return ["node", str(_LOCAL_WASM)]

    raise RuntimeError(
        "Could not find 'namgen' executable or 'node wasm/namgen-cli.js'. "
        "Please build the project with 'make' or ensure 'namgen' is on your PATH."
    )


def generate(
    generator: Optional[str] = None,
    count: int = 1,
    seed: Optional[int] = None,
    unique: bool = False,
    format: str = "plain",
    match: Optional[str] = None,
    min_len: Optional[int] = None,
    max_len: Optional[int] = None,
    compose: Optional[str] = None,
    template: Optional[str] = None,
    executable: Optional[str] = None,
) -> Union[List[str], str]:
    """
    Generate names using namgen.

    :param generator: Generator flag or name (e.g. '--fantasy-dragons' or 'fantasy-dragons')
    :param count: Number of names to generate (default: 1)
    :param seed: Deterministic seed for reproducible generation
    :param unique: Ensure all names in batch are distinct
    :param format: Output format ('plain', 'json', 'csv', 'slug')
    :param match: Regular expression filter pattern
    :param min_len: Minimum character length
    :param max_len: Maximum character length
    :param compose: Comma-separated list of generators to compose
    :param template: Custom composition template string
    :param executable: Path to custom namgen executable
    :return: List of generated names (or raw string if formatted)
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
