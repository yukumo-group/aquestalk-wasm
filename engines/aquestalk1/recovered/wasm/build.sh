#!/bin/sh
# Freestanding wasm32 build: no emscripten, no imports, one module.
set -e
cd "$(dirname "$0")/../.."
CC=${CC:-clang}
mkdir -p dist
SRC="recovered/src/api/ot_api.c recovered/src/text/*.c recovered/src/audio/*.c \
     recovered/src/synth/*.c recovered/src/data/*.c recovered/src/f3/*.c recovered/f3port/src/*.c"
$CC --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin -fno-stack-protector \
    -D__stdcall= -DAQ_FREESTANDING -fpermissive -Wno-int-conversion -Wno-incompatible-pointer-types \
    -Irecovered/include -Irecovered/f3port/include -Irecovered/wasm/freestanding \
    -Wl,--no-entry -Wl,--export-memory \
    -Wl,--initial-memory=16777216 -Wl,--max-memory=268435456 \
    -Wl,-z,stack-size=1048576 \
    recovered/wasm/runtime.c recovered/wasm/wasm_api.c $SRC \
    -o dist/aquestalk1.wasm
cp recovered/wasm/aquestalk1.js recovered/wasm/demo.html dist/
ls -l dist/aquestalk1.wasm dist/aquestalk1.js dist/demo.html
