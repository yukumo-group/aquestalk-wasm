#!/usr/bin/env bash
# Build AqUsrDic (AqUsrDic Check + memory-buffer Import/Export) as a
# relocatable archive for a static wasm link.
#
# The generated runtime.c is not compiled; malloc/mem*/stdio come from the
# link kit.  C and C++ (marisa-trie) translation units are both namespaced by
# link/tools/reloc.sh before the archive is created.
set -euo pipefail

HERE=$(cd "$(dirname "$0")" && pwd)
ENGINE=$(cd "$HERE/.." && pwd)
ROOT=$(cd "$ENGINE/../.." && pwd)
cd "$HERE"

OUT=${OUT:-"$HERE/build-wasm32/reloc"}
RELOC_TMP=${RELOC_TMP:-"$HERE/.reloc-tmp"}
CC=${CC:-clang}
CXX=${CXX:-clang++}
RESOURCE_DIR=$("$CC" -print-resource-dir)

python3 tools/gen_image.py >/dev/null
python3 tools/gen_check.py >/dev/null
python3 tools/gen_wasm32.py >/dev/null

CFLAGS=(
  --target=wasm32-unknown-unknown -O2 -nostdlib -w
  -fno-strict-aliasing -DAQK2K_WASM -DAQ_RELOC -Wno-everything
  -Ibuild-wasm32/gen
)
CXXFLAGS=(
  --target=wasm32-unknown-unknown -std=c++17 -O2 -nostdlib -w
  -fno-exceptions -fno-rtti -Wno-everything
  -nostdinc -isystem "$RESOURCE_DIR/include"
  -Ibuild-wasm32/gen
  -Imarisa_fs/cxx -Imarisa_fs/include -Imarisa_fs/lib
)

shopt -s nullglob
sources=(
  build-wasm32/gen/shim.c
  build-wasm32/gen/image.c
  build-wasm32/gen/decomp_check.c
  build-wasm32/gen/api_check.c
  build-wasm32/gen/errors.c
  src/api_usr.c
  src/marisa_glue.cc
  marisa_fs/cxx_runtime.cc
  marisa_fs/lib/marisa/agent.cc
  marisa_fs/lib/marisa/keyset.cc
  marisa_fs/lib/marisa/trie.cc
  marisa_fs/lib/marisa/grimoire/trie/louds-trie.cc
  marisa_fs/lib/marisa/grimoire/trie/tail.cc
  marisa_fs/lib/marisa/grimoire/vector/bit-vector.cc
  marisa_fs/lib/marisa/grimoire/io/io_mem.cc
)

compile_one() {
  local src=$1 out=$2 pass=$3
  local extra=()
  if [ "$pass" = 2 ]; then
    extra=(-include "$RELOC_HEADER")
  fi
  case "$src" in
    *.cc)
      "$CXX" "${CXXFLAGS[@]}" "${extra[@]}" -c "$src" -o "$out"
      ;;
    *)
      "$CC" "${CFLAGS[@]}" "${extra[@]}" -c "$src" -o "$out"
      ;;
  esac
}

. "$ROOT/link/tools/reloc.sh"

echo "AqUsrDic -> $OUT/libaqusr.a"
reloc_archive "$ROOT/link/abis/aqusr.json" "$OUT/libaqusr.a"
rm -rf "$RELOC_TMP"
