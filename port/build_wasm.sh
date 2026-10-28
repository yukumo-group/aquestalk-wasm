#!/bin/sh
# Build the freestanding wasm64 module with clang/LLVM directly (no embind,
# no Emscripten runtime).
set -e
cd "$(dirname "$0")"
SRC=src
OUT=build-wasm
CC=${CC:-clang}
mkdir -p "$OUT"

FLAGS="--target=wasm64-unknown-unknown -O2 -nostdlib -fno-strict-aliasing \
  -Wno-incompatible-pointer-types -Wno-pointer-sign -Wno-int-conversion \
  -Wno-implicit-function-declaration -Wno-shift-op-parentheses \
  -Wno-return-mismatch -Wno-unused-value -DAQK2K_WASM -DAQK2K_LEAK -I$SRC"

$CC $FLAGS -c $SRC/runtime.c      -o $OUT/runtime.o
$CC $FLAGS -c $SRC/shim.c         -o $OUT/shim.o
$CC $FLAGS -c $SRC/image.c        -o $OUT/image.o
$CC $FLAGS -c $SRC/cold_stubs.c   -o $OUT/cold_stubs.o
$CC $FLAGS -c $SRC/decomp.c       -o $OUT/decomp.o
$CC $FLAGS -c $SRC/api_raw.c      -o $OUT/api_raw.o
$CC $FLAGS -c $SRC/lookup_c.c     -o $OUT/lookup_c.o

EXPORTS="-Wl,--export=aq_init -Wl,--export=aq_alloc -Wl,--export=aq_free \
 -Wl,--export=aq_set_lookup -Wl,--export=aq_create -Wl,--export=aq_release \
 -Wl,--export=aq_convert -Wl,--export=aq_conv_roman -Wl,--export=aq_set_devkey \
 -Wl,--export=__heap_base"

$CC --target=wasm64-unknown-unknown -O2 -nostdlib \
  -Wl,--no-entry -Wl,--export-memory \
  -Wl,--initial-memory=33554432 -Wl,--max-memory=536870912 \
  -Wl,-z,stack-size=8388608 \
  $EXPORTS \
  -o "$OUT/aqk2k.wasm" \
  $OUT/runtime.o $OUT/shim.o $OUT/image.o $OUT/cold_stubs.o \
  $OUT/decomp.o $OUT/api_raw.o $OUT/lookup_c.o
echo "built $OUT/aqk2k.wasm"
ls -lh "$OUT/aqk2k.wasm"
