#!/usr/bin/env bash
# Build AqKanji2Koe as a relocatable archive for a static wasm link.
#
# The generated runtime.c (freestanding allocator, mem*, stdio stubs) is not
# compiled; the final module supplies those through the link kit.  The
# decompiled sources are regenerated with tools/gen_wasm32.py first, then
# link/tools/reloc.sh compiles twice to namespace every global.
set -euo pipefail

HERE=$(cd "$(dirname "$0")" && pwd)
ENGINE=$(cd "$HERE/.." && pwd)
ROOT=$(cd "$ENGINE/../.." && pwd)
cd "$HERE"

OUT=${OUT:-"$HERE/build-wasm32/reloc"}
RELOC_TMP=${RELOC_TMP:-"$HERE/.reloc-tmp"}
CC=${CC:-clang}

python3 tools/gen_wasm32.py

CFLAGS=(
  --target=wasm32-unknown-unknown -O2 -nostdlib -w
  -fno-strict-aliasing -DAQK2K_WASM
  -Wno-incompatible-pointer-types -Wno-pointer-sign -Wno-int-conversion
  -Wno-implicit-function-declaration -Wno-shift-op-parentheses
  -Wno-return-mismatch -Wno-unused-value
  -Ibuild-wasm32/gen
)

shopt -s nullglob
sources=(
  build-wasm32/gen/shim.c
  build-wasm32/gen/image.c
  build-wasm32/gen/cold_stubs.c
  build-wasm32/gen/decomp.c
  build-wasm32/gen/api_raw.c
  build-wasm32/gen/lookup_c.c
)

compile_one() {
  local src=$1 out=$2 pass=$3
  local extra=()
  if [ "$pass" = 2 ]; then
    extra=(-include "$RELOC_HEADER")
  fi
  "$CC" "${CFLAGS[@]}" "${extra[@]}" -c "$src" -o "$out"
}

. "$ROOT/link/tools/reloc.sh"

echo "AqKanji2Koe -> $OUT/libaqk2k.a"
reloc_archive "$ROOT/link/abis/aqk2k.json" "$OUT/libaqk2k.a"
rm -rf "$RELOC_TMP"
