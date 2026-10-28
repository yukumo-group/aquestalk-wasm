#!/bin/sh
set -e
cd "$(dirname "$0")"
CLANGXX=${CLANGXX:-/usr/bin/clang++}
CC=${CC:-/usr/bin/clang}
INC="-nostdinc -isystem /usr/lib/clang/23/include -I cxx -I include -I lib"
OUT=.build
rm -rf "$OUT"; mkdir -p "$OUT"
$CLANGXX --target=wasm32-unknown-unknown -std=c++17 -O2 -fno-exceptions -fno-rtti $INC -c cxx_runtime.cc -o "$OUT/cxxrt.o"
for f in lib/marisa/agent.cc lib/marisa/keyset.cc lib/marisa/trie.cc \
         lib/marisa/grimoire/trie/louds-trie.cc lib/marisa/grimoire/trie/tail.cc \
         lib/marisa/grimoire/vector/bit-vector.cc lib/marisa/grimoire/io/io_mem.cc mtest.cc; do
  $CLANGXX --target=wasm32-unknown-unknown -std=c++17 -O2 -fno-exceptions -fno-rtti $INC -c "$f" -o "$OUT/$(basename "$f").o"
done
$CC --target=wasm32-unknown-unknown -O2 -nostdlib -DAQK2K_WASM -c ../src/runtime.c -o "$OUT/runtime.o"
wasm-ld --no-entry --export-memory --export=marisa_test_build --export=marisa_test_read \
  --export=marisa_test_build_static --export=marisa_test_out \
  --initial-memory=33554432 --max-memory=268435456 -z stack-size=1048576 \
  -o "$OUT/mtest.wasm" "$OUT"/*.o
ls -lh "$OUT/mtest.wasm"
