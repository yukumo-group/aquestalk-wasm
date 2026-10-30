#!/usr/bin/env bash
# Link every engine into one single-memory WebAssembly module with Rust code.
#
#   ./scripts/build-reloc.sh              build + parity test
#   ./scripts/build-reloc.sh --no-test    build only
#
# For each engine this runs engines/<...>/build-reloc.sh, which compiles a
# namespaced static archive (see link/tools/gen_prefix.py).  The archives are
# then linked with:
#
#   * link/host/aq_host.c   -- string/stdio/time/trap helpers (C)
#   * link/host/Cargo.toml  -- malloc/free/calloc/realloc on Rust's allocator
#
# The result has no imports, one memory and one table, so it runs in browsers
# that do not implement the multi-memory proposal.
set -euo pipefail

ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT"

RUN_TESTS=1
for arg in "$@"; do
  case "$arg" in
    --no-test) RUN_TESTS=0 ;;
    -h|--help) sed -n '2,18p' "$0"; exit 0 ;;
    *) echo "unknown argument: $arg" >&2; exit 2 ;;
  esac
done

OUT=${OUT:-"$ROOT/dist/reloc"}
BUNDLE=${BUNDLE:-"$ROOT/dist/aquestalk.wasm"}
CC=${CC:-clang}
INITIAL_MEMORY=${INITIAL_MEMORY:-67108864}     # 64 MiB
MAX_MEMORY=${MAX_MEMORY:-1073741824}           # 1 GiB
STACK_SIZE=${STACK_SIZE:-16777216}             # 16 MiB

for tool in clang wasm-ld llvm-ar llvm-nm cargo python3; do
  command -v "$tool" >/dev/null || { echo "missing $tool" >&2; exit 1; }
done

mkdir -p "$OUT" "$(dirname "$BUNDLE")"

echo "== relocatable engine archives"
OUT="$OUT" bash engines/aquestalk1/recovered/wasm/build-reloc.sh
OUT="$OUT" bash engines/aquestalk2/port/build-reloc.sh
OUT="$OUT" bash engines/aquestalk10/port/build-reloc.sh
OUT="$OUT" bash engines/aqk2k/port/build_reloc.sh
OUT="$OUT" bash engines/aqk2k/port_usr/build_reloc.sh

echo "== link kit host"
"$CC" --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin \
  -fno-stack-protector -w -c link/host/aq_host.c -o "$OUT/aq_host.o"
llvm-ar crs "$OUT/libaqhost.a" "$OUT/aq_host.o"
cargo build --manifest-path link/host/Cargo.toml \
  --target wasm32-unknown-unknown --release
HOST_A="$ROOT/link/host/target/wasm32-unknown-unknown/release/libaq_host.a"

echo "== wasm-ld"
python3 link/tools/exports.py --write "$OUT/exports.txt" > "$OUT/exports.args"
mapfile -t EXPORTS < "$OUT/exports.args"
wasm-ld --no-entry --export-memory "${EXPORTS[@]}" \
  --initial-memory="$INITIAL_MEMORY" --max-memory="$MAX_MEMORY" \
  -z "stack-size=$STACK_SIZE" \
  -o "$BUNDLE" \
  "$OUT/aq_host.o" \
  --whole-archive \
  "$OUT/libaq1.a" "$OUT/libaq2.a" "$OUT/libaq10.a" \
  "$OUT/libaqk2k.a" "$OUT/libaqusr.a" \
  --no-whole-archive \
  "$HOST_A"

python3 - "$ROOT" "$BUNDLE" "$OUT" "$INITIAL_MEMORY" "$MAX_MEMORY" "$STACK_SIZE" <<'PY'
import json, sys
from pathlib import Path
root, bundle, out = map(Path, sys.argv[1:4])
initial, maximum, stack = map(int, sys.argv[4:7])
info = {
    "bundle": str(bundle.relative_to(root)),
    "bytes": bundle.stat().st_size,
    "imports": [],
    "memory": {"count": 1, "initial": initial, "max": maximum},
    "stack": stack,
    "archives": sorted(p.name for p in out.glob("lib*.a")),
}
(out / "build-info.json").write_text(json.dumps(info, indent=2) + "\n")
PY

printf '  %-24s %s\n' "dist/aquestalk.wasm" "$(du -h "$BUNDLE" | cut -f1)"
echo "wrote $OUT/exports.txt"

if [ "$RUN_TESTS" = 1 ]; then
  node link/test/reloc.mjs
fi
