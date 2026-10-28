#!/bin/sh
# Build the raw wasm module with LLVM directly (no Emscripten, no embind).
set -eu
cd "$(dirname "$0")/.."

CLANG=${CLANG:-clang}
OUT=port/web/aqtk10.wasm

# image.c is generated from the original .so and is not in git.
if [ ! -f port/src/image.c ]; then
    python3 port/tools/gen_image.py
fi

$CLANG --target=wasm32 -std=gnu11 -O2 -nostdlib -ffreestanding \
    -fno-builtin -fno-strict-aliasing -fwrapv -fno-stack-protector \
    -Wno-everything -DAQTK_FREESTANDING -Iport/src \
    port/src/wasm_api.c port/src/minic.c port/src/decomp.c port/src/image.c \
    -Wl,--no-entry -Wl,--export-memory \
    -Wl,--initial-memory=16777216 -Wl,--max-memory=268435456 \
    -Wl,-z,stack-size=1048576 -Wl,--gc-sections -Wl,--strip-all \
    -Wl,--export=aqtk_init \
    -Wl,--export=aqtk_malloc \
    -Wl,--export=aqtk_free \
    -Wl,--export=aqtk_synthe_utf8 \
    -Wl,--export=aqtk_synthe_sjis \
    -Wl,--export=aqtk_synthe_utf16 \
    -Wl,--export=aqtk_synthe_utf8_default \
    -Wl,--export=aqtk_free_wave \
    -Wl,--export=aqtk_set_dev_key \
    -Wl,--export=aqtk_set_usr_key \
    -o "$OUT"

ls -l "$OUT"
