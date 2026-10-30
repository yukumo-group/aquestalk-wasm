#!/usr/bin/env python3
"""Emit the wasm-ld arguments that export the bundle's public ABI.

Reads every ``link/abis/*.json`` manifest and prints one ``--export=<name>``
per line.  ``--write`` also saves a readable list next to the bundle.
"""

from __future__ import annotations

import argparse
import glob
import json
import sys
from pathlib import Path


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--write", type=Path, help="also write a readable export list")
    args = parser.parse_args()

    names = ["malloc", "free", "aq_host_abi"]
    seen: set[str] = set(names)
    lines: list[str] = []
    for path in sorted(glob.glob(str(args.root / "link/abis/*.json"))):
        manifest = json.loads(Path(path).read_text())
        api = manifest["api"]
        lines.append(f"# {manifest['engine']} ({manifest['archive']})")
        for original, public in sorted(api.items()):
            if public in seen:
                raise SystemExit(f"duplicate public symbol {public} ({original})")
            seen.add(public)
            lines.append(f"--export={public}")
            names.append(public)

    if args.write:
        args.write.write_text("\n".join(lines) + "\n")

    for name in names:
        print(f"--export={name}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
