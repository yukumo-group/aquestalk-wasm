#!/usr/bin/env bash
# Build the freestanding WebAssembly module with clang/LLVM directly.
#
# No Emscripten, no embind, no libc: the module has zero imports and exports
# the AquesTalk2 C ABI plus a tiny host API (aq_malloc/aq_free/...).  The
# hand-written wrapper in web/aquestalk2.js is copied next to it.
set -euo pipefail
cd "$(dirname "$0")"
ROOT=$(cd .. && pwd)

CLANG=${CLANG:-}
if [ -z "$CLANG" ]; then
    if command -v clang >/dev/null 2>&1; then
        CLANG=$(command -v clang)
    else
        for cand in "${AQ_EMSDK:-}" "${EMSDK:-}" \
                    "$ROOT/emsdk" "/home/lc-022/Documents/GitHub/aqk2k/emsdk"; do
            if [ -n "$cand" ] && [ -x "$cand/upstream/bin/clang" ]; then
                CLANG="$cand/upstream/bin/clang"
                break
            fi
        done
    fi
fi
if [ -z "$CLANG" ] || [ ! -x "$CLANG" ]; then
    echo "clang not found; install LLVM with the wasm32 target" >&2
    exit 1
fi

CFLAGS=${CFLAGS:--O2}
INITIAL_MEMORY=${INITIAL_MEMORY:-8388608}
MAX_MEMORY=${MAX_MEMORY:-536870912}
STACK_SIZE=${STACK_SIZE:-524288}

mkdir -p "$ROOT/dist"

"$CLANG" --target=wasm32 $CFLAGS \
    -nostdlib -ffreestanding -fno-builtin -fno-stack-protector \
    -DAQ_FREESTANDING -I src \
    -Wno-incompatible-pointer-types -Wno-int-conversion \
    -Wl,--no-entry -Wl,--export-memory \
    -Wl,--initial-memory="$INITIAL_MEMORY" \
    -Wl,--max-memory="$MAX_MEMORY" \
    -Wl,-z,stack-size="$STACK_SIZE" \
    src/decomp.c src/image.c src/shim.c src/runtime.c src/wasm_api.c \
    -o "$ROOT/dist/aquestalk2-core.wasm"

# Ship the wrapper + demo + voices next to the module.
rm -f "$ROOT/dist/aquestalk2.wasm"          # leftover from the emscripten build
cp -r web/. "$ROOT/dist/"
mkdir -p "$ROOT/dist/phont"
cp "$ROOT"/aqtk2-lnx/phont/*.phont "$ROOT/dist/phont/"

echo "built $ROOT/dist/aquestalk2-core.wasm"
ls -l "$ROOT/dist"
