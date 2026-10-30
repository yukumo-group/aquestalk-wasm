#!/usr/bin/env bash
# Shared driver for the relocatable engine builds.
#
# Each engine's build-reloc.sh sets:
#   ROOT         repository root
#   RELOC_TMP    scratch directory (one per engine)
#   sources      array of source files
#   compile_one  function(src, out, pass) -> compiles one translation unit
#
# and then calls:
#   reloc_archive <manifest.json> <out/libname.a>
#
# Pass 1 collects the engine's globals, gen_prefix.py writes a header, and
# pass 2 recompiles with it so the archive is namespaced.

set -euo pipefail

reloc_archive() {
  local manifest="$1"
  local archive="$2"
  local tmp="$RELOC_TMP"
  local p1=() p2=()
  local i=0 src obj

  mkdir -p "$tmp/pass1" "$tmp/pass2" "$(dirname "$archive")"

  for src in "${sources[@]}"; do
    obj="$tmp/pass1/$(printf '%03d' "$i")_$(basename "$src").o"
    compile_one "$src" "$obj" 1
    p1+=("$obj")
    i=$((i + 1))
  done

  RELOC_HEADER="$tmp/prefix.h"
  python3 "$ROOT/link/tools/gen_prefix.py" \
    --manifest "$manifest" \
    --objects "${p1[@]}" \
    --header "$RELOC_HEADER" \
    --report "$tmp/prefix.json"

  i=0
  for src in "${sources[@]}"; do
    obj="$tmp/pass2/$(printf '%03d' "$i")_$(basename "$src").o"
    compile_one "$src" "$obj" 2
    p2+=("$obj")
    i=$((i + 1))
  done

  rm -f "$archive"
  llvm-ar crs "$archive" "${p2[@]}"

  local report="${archive%.a}.symbols.json"
  cp "$tmp/prefix.json" "$report"
  printf '  %-28s %s\n' "$(basename "$archive")" "$(du -h "$archive" | cut -f1)"
}
