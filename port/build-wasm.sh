#!/usr/bin/env bash
# Build the WebAssembly + embind module.
#
# Requires an activated emsdk (emcc/em++ in PATH) or EMSDK pointing at one.
# Set AQ_EMSDK to override the auto-detected SDK location.
set -euo pipefail
cd "$(dirname "$0")"
ROOT=$(cd .. && pwd)

if ! command -v emcc >/dev/null 2>&1; then
    for cand in "${AQ_EMSDK:-}" "${EMSDK:-}" \
                "$ROOT/emsdk" "/home/lc-022/Documents/GitHub/aqk2k/emsdk"; do
        if [ -n "$cand" ] && [ -f "$cand/emsdk_env.sh" ]; then
            # shellcheck disable=SC1090
            source "$cand/emsdk_env.sh" >/dev/null 2>&1 || true
            break
        fi
    done
fi
if ! command -v emcc >/dev/null 2>&1; then
    echo "emcc not found; install/activate emsdk (https://emscripten.org)" >&2
    exit 1
fi

# The SDK checkout may be read-only; keep emscripten's cache in the project.
export EM_CACHE="$ROOT/.emcache"
mkdir -p "$EM_CACHE" build-wasm "$ROOT/dist"

CFLAGS=${CFLAGS:--O2}
CXXFLAGS=${CXXFLAGS:--O2}
COMMON="-sMODULARIZE=1 -sEXPORT_ES6=1 -sENVIRONMENT=web,node \
        -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB -sSTACK_SIZE=1MB \
        -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,HEAPU8,HEAP16,HEAP32 \
        -sEXPORTED_FUNCTIONS=_AquesTalk2_Synthe,_AquesTalk2_Synthe_Euc,_AquesTalk2_Synthe_Utf8,_AquesTalk2_Synthe_Utf16,_AquesTalk2_Synthe_Roman,_AquesTalk2_FreeWave,_malloc,_free"

emcc $CFLAGS -I. -c src/decomp.c -o build-wasm/decomp.o \
    -Wno-incompatible-pointer-types -Wno-int-conversion
emcc $CFLAGS -I. -c src/image.c -o build-wasm/image.o
emcc $CFLAGS -I. -c src/shim.c -o build-wasm/shim.o
em++ $CXXFLAGS -I. -c src/api.cpp -o build-wasm/api.o

em++ $CXXFLAGS --bind $COMMON \
    build-wasm/decomp.o build-wasm/image.o build-wasm/shim.o build-wasm/api.o \
    -o "$ROOT/dist/aquestalk2.js"

# Ship the demo and the voice files next to the module.
cp -r web/. "$ROOT/dist/"
mkdir -p "$ROOT/dist/phont"
cp "$ROOT"/aqtk2-lnx/phont/*.phont "$ROOT/dist/phont/"

echo "built $ROOT/dist/aquestalk2.js + aquestalk2.wasm"
ls -l "$ROOT/dist"
