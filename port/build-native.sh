#!/usr/bin/env bash
# Build the native x86-64 port.  Used to prove that the recompiled C behaves
# exactly like the original shared object (see tools/verify.py).
set -euo pipefail
cd "$(dirname "$0")"

CFLAGS=${CFLAGS:--O2}
BUILD=build-native
mkdir -p "$BUILD"

gcc $CFLAGS -I. -c src/decomp.c -o "$BUILD/decomp.o" \
    -Wno-incompatible-pointer-types -Wno-int-conversion
gcc $CFLAGS -I. -c src/image.c -o "$BUILD/image.o"
gcc $CFLAGS -I. -c src/shim.c -o "$BUILD/shim.o"
g++ $CFLAGS -std=c++17 -I. -c src/api.cpp -o "$BUILD/api.o"
g++ $CFLAGS -std=c++17 -I. -c tools/aqtest.cpp -o "$BUILD/aqtest.o"
g++ -o "$BUILD/aqtest" "$BUILD/decomp.o" "$BUILD/image.o" "$BUILD/shim.o" \
    "$BUILD/api.o" "$BUILD/aqtest.o"

echo "built $BUILD/aqtest"
