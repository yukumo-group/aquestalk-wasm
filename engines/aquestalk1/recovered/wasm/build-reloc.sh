#!/usr/bin/env bash
# Build AquesTalk1 as a relocatable archive for a static wasm link.
#
# The module keeps the engine sources but drops recovered/wasm/runtime.c: the
# final module uses the embedder's allocator and libc.  link/tools/reloc.sh
# compiles twice so every global can be namespaced (see gen_prefix.py).
set -euo pipefail

HERE=$(cd "$(dirname "$0")" && pwd)
ENGINE=$(cd "$HERE/../.." && pwd)
ROOT=$(cd "$ENGINE/../.." && pwd)
cd "$ENGINE"

OUT=${OUT:-"$ENGINE/dist/reloc"}
RELOC_TMP=${RELOC_TMP:-"$ENGINE/.reloc-tmp"}
CC=${CC:-clang}

CFLAGS=(
  --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin
  -fno-stack-protector -w
  -D__stdcall= -DAQ_FREESTANDING -DAQ_RELOC
  -fpermissive -Wno-int-conversion -Wno-incompatible-pointer-types
  -Irecovered/include -Irecovered/f3port/include -Irecovered/wasm/freestanding
)

shopt -s nullglob
sources=(
  recovered/src/api/ot_api.c
  recovered/src/text/*.c
  recovered/src/audio/*.c
  recovered/src/synth/*.c
  recovered/src/data/*.c
  recovered/src/f3/*.c
  recovered/f3port/src/*.c
  recovered/wasm/wasm_api.c
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

echo "AquesTalk1 -> $OUT/libaq1.a"
reloc_archive "$ROOT/link/abis/aq1.json" "$OUT/libaq1.a"
rm -rf "$RELOC_TMP"
