#!/bin/sh
# Safari-compatible wasm32 build (no memory64, no embind, no Emscripten).
set -e
cd "$(dirname "$0")"
python3 tools/gen_wasm32.py
CC=${CC:-clang}
GEN=build-wasm32/gen
OUT=build-wasm32
FLAGS="--target=wasm32-unknown-unknown -O2 -nostdlib -fno-strict-aliasing \
 -Wno-incompatible-pointer-types -Wno-pointer-sign -Wno-int-conversion \
 -Wno-implicit-function-declaration -Wno-shift-op-parentheses \
 -Wno-return-mismatch -Wno-unused-value -DAQK2K_WASM -I$GEN"
if [ "${AQK2K_LEAK:-0}" = 1 ]; then FLAGS="$FLAGS -DAQK2K_LEAK"; fi
for f in runtime shim image cold_stubs decomp api_raw lookup_c; do
  $CC $FLAGS -c "$GEN/$f.c" -o "$OUT/$f.o"
done
$CC --target=wasm32-unknown-unknown -O2 -nostdlib \
 -Wl,--no-entry -Wl,--export-memory -Wl,--initial-memory=33554432 -Wl,--max-memory=1073741824 \
 -Wl,-z,stack-size=8388608 \
 -Wl,--export=aq_init -Wl,--export=aq_alloc -Wl,--export=aq_free \
 -Wl,--export=aq_set_lookup -Wl,--export=aq_create -Wl,--export=aq_release \
 -Wl,--export=aq_convert -Wl,--export=aq_conv_roman -Wl,--export=aq_set_devkey \
 -Wl,--export=__heap_base \
 -o "$OUT/aqk2k32.wasm" "$OUT"/*.o
ls -lh "$OUT/aqk2k32.wasm"
