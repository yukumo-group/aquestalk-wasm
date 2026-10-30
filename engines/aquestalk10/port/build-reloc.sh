#!/usr/bin/env bash
# Build AquesTalk10 as a relocatable archive for a static wasm link.
#
# port/src/minic.c (freestanding allocator + mem*) is not compiled; the final
# module supplies those through the link kit.  link/tools/reloc.sh compiles
# twice so the decompiled globals are namespaced.
set -euo pipefail

HERE=$(cd "$(dirname "$0")" && pwd)
ENGINE=$(cd "$HERE/.." && pwd)
ROOT=$(cd "$ENGINE/../.." && pwd)
cd "$ENGINE"

OUT=${OUT:-"$ENGINE/port/web/reloc"}
RELOC_TMP=${RELOC_TMP:-"$HERE/.reloc-tmp"}
CC=${CC:-clang}

# image.c is generated from the original .so and is not in git.
if [ ! -f port/src/image.c ]; then
  python3 port/tools/gen_image.py
fi

CFLAGS=(
  --target=wasm32 -std=gnu11 -O2 -nostdlib -ffreestanding
  -fno-builtin -fno-strict-aliasing -fwrapv -fno-stack-protector -w -Wno-everything
  -DAQTK_FREESTANDING -DAQ_RELOC
  -Iport/src
)

shopt -s nullglob
sources=(
  port/src/wasm_api.c
  port/src/decomp.c
  port/src/image.c
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

echo "AquesTalk10 -> $OUT/libaq10.a"
reloc_archive "$ROOT/link/abis/aq10.json" "$OUT/libaq10.a"
rm -rf "$RELOC_TMP"
