#!/usr/bin/env bash
# Build AquesTalk2 as a relocatable archive for a static wasm link.
#
# src/runtime.c is intentionally not compiled: the final module supplies
# malloc/mem* through the link kit.  link/tools/reloc.sh compiles twice so the
# engine's globals are namespaced before the archive is created.
#
# The Aq2Preset phont files are compiled into this archive (aq_builtin_phont).
# The standalone web build still loads them at runtime.
set -euo pipefail

HERE=$(cd "$(dirname "$0")" && pwd)
ENGINE=$(cd "$HERE/.." && pwd)
ROOT=$(cd "$ENGINE/../.." && pwd)
cd "$HERE"

OUT=${OUT:-"$ENGINE/dist/reloc"}
RELOC_TMP=${RELOC_TMP:-"$HERE/.reloc-tmp"}
CC=${CC:-clang}

CFLAGS=(
  --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin
  -fno-stack-protector -w
  -DAQ_FREESTANDING -DAQ_RELOC
  -Isrc
  -Wno-incompatible-pointer-types -Wno-int-conversion
)

shopt -s nullglob
mkdir -p "$RELOC_TMP"
python3 tools/gen_builtin_phonts.py \
  "$ENGINE/aqtk2-lnx/phont" \
  "$RELOC_TMP/builtin_phonts.c"
sources=(src/decomp.c src/image.c src/shim.c src/wasm_api.c "$RELOC_TMP/builtin_phonts.c")

compile_one() {
  local src=$1 out=$2 pass=$3
  local extra=()
  if [ "$pass" = 2 ]; then
    extra=(-include "$RELOC_HEADER")
  fi
  "$CC" "${CFLAGS[@]}" "${extra[@]}" -c "$src" -o "$out"
}

. "$ROOT/link/tools/reloc.sh"

echo "AquesTalk2 -> $OUT/libaq2.a"
reloc_archive "$ROOT/link/abis/aq2.json" "$OUT/libaq2.a"
rm -rf "$RELOC_TMP"
