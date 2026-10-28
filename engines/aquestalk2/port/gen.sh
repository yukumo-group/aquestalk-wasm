#!/usr/bin/env bash
# Regenerate the two mechanically produced translation units from Ghidra's
# output in ../../decomp.  Only needed if the decompiler dump changes.
set -euo pipefail
cd "$(dirname "$0")"
python3 tools/gen_image.py
python3 tools/gen_decomp.py
