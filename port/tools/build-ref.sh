#!/usr/bin/env bash
# Build the differential-test harness that dlopen()s the *original* library.
set -euo pipefail
cd "$(dirname "$0")/.."
mkdir -p build-native
gcc -O2 -o build-native/ref tools/ref.c -ldl
echo "built build-native/ref"
