#!/bin/sh
# Build the AqUsrDic wasm32 module: Check + memory-buffer Import/Export.
set -e
cd "$(dirname "$0")"
python3 tools/gen_image.py >/dev/null
python3 tools/gen_check.py >/dev/null
python3 tools/gen_wasm32.py >/dev/null
GEN=build-wasm32/gen
OUT=build-wasm32
CC=${CC:-clang}
CXX=${CXX:-clang++}
CFLAGS="--target=wasm32-unknown-unknown -O2 -nostdlib -fno-strict-aliasing -Wno-everything -DAQK2K_WASM -I$GEN"
CXXFLAGS="--target=wasm32-unknown-unknown -std=c++17 -O2 -nostdlib -fno-exceptions -fno-rtti -Wno-everything -nostdinc -isystem $(/usr/bin/clang -print-resource-dir)/include -I marisa_fs/cxx -I marisa_fs/include -I marisa_fs/lib"
mkdir -p "$OUT"
for f in runtime shim image decomp_check api_check errors; do
  $CC $CFLAGS -c "$GEN/$f.c" -o "$OUT/$f.o"
done
$CC $CFLAGS -c src/api_usr.c -o "$OUT/api_usr.o"
$CXX $CXXFLAGS -c src/marisa_glue.cc -o "$OUT/marisa_glue.o"
$CXX $CXXFLAGS -c marisa_fs/cxx_runtime.cc -o "$OUT/cxx_runtime.o"
for f in lib/marisa/agent.cc lib/marisa/keyset.cc lib/marisa/trie.cc \
         lib/marisa/grimoire/trie/louds-trie.cc lib/marisa/grimoire/trie/tail.cc \
         lib/marisa/grimoire/vector/bit-vector.cc lib/marisa/grimoire/io/io_mem.cc; do
  $CXX $CXXFLAGS -c "marisa_fs/$f" -o "$OUT/mfs_$(basename "$f").o"
done
wasm-ld --no-entry --export-memory \
  --export=aus_init --export=aus_check --export=aus_error \
  --export=aus_set_system_dic --export=aus_import --export=aus_export \
  --export=aq_alloc --export=aq_free \
  --initial-memory=33554432 --max-memory=268435456 -z stack-size=4194304 \
  -o "$OUT/aqusr.wasm" "$OUT"/*.o
ls -lh "$OUT/aqusr.wasm"
