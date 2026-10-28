#!/bin/sh
# Build the AqUsrDic_Check-only wasm32 test module (WIP).
set -e
cd "$(dirname "$0")"
python3 tools/gen_image.py >/dev/null
python3 tools/gen_check.py >/dev/null
python3 tools/gen_wasm32.py >/dev/null
GEN=build-wasm32/gen
OUT=build-wasm32
CC=${CC:-clang}
FLAGS="--target=wasm32-unknown-unknown -O2 -nostdlib -fno-strict-aliasing \
 -Wno-everything -DAQK2K_WASM -I$GEN"
for f in runtime shim image decomp_check api_check errors; do
  $CC $FLAGS -c "$GEN/$f.c" -o "$OUT/$f.o"
done
$CC --target=wasm32-unknown-unknown -O2 -nostdlib \
 -Wl,--no-entry -Wl,--export-memory -Wl,--initial-memory=33554432 \
 -Wl,--max-memory=268435456 -Wl,-z,stack-size=4194304 \
 -Wl,--export=aus_init -Wl,--export=aus_check -Wl,--export=aus_error -Wl,--export=aus_debug_len \
 -Wl,--export=aq_alloc -Wl,--export=aq_free \
 -Wl,--export=__heap_base \
 -o "$OUT/aqusr_check.wasm" "$OUT"/runtime.o "$OUT"/shim.o "$OUT"/image.o \
 "$OUT"/decomp_check.o "$OUT"/api_check.o "$OUT"/errors.o
ls -lh "$OUT/aqusr_check.wasm"
