#!/bin/sh
# 290-case katakana breadth suite: engine vs aqtk1_lnx/lib64/<voice>.
set -e
cd "$(dirname "$0")/../../.."
python3 recovered/tools/linux/gen_cases.py
mkdir -p build/results
for v in f1 f2 f3 m1 m2 r1 imd1 jgr dvd; do
    ./build/tools/kana_bench "aqtk1_lnx/lib64/$v/libAquesTalk.so" "$v" build/cases.tsv 100 \
        > "build/results/$v.tsv"
    printf '%-5s %s\n' "$v" "$(tail -1 "build/results/$v.tsv")"
done
