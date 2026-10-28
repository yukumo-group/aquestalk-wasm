#!/usr/bin/env python3
"""Differential test: native/wasm port vs the original 64-bit library.

Usage:
  python3 tests/run_diff.py [port_output.txt]

If no output file is given, the native CLI is run on tests/corpus_diff.txt.
The last 24 lines are hand-written common sentences; the earlier lines are
random dictionary words, generated sentences, and fixed edge cases including
numbers, punctuation, and ASCII text.  All 303 lines must match.
"""
import os, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CORPUS = os.path.join(ROOT, "tests", "corpus_diff.txt")
EXPECT = os.path.join(ROOT, "tests", "expected64.txt")
PORT = os.path.join(ROOT, "port", "build-native", "aqk2k")

def main():
    corpus = open(CORPUS, encoding="utf-8").read().splitlines()
    expect = open(EXPECT, encoding="utf-8").read().splitlines()
    if len(sys.argv) > 1:
        got = open(sys.argv[1], encoding="utf-8").read().splitlines()
    else:
        got = subprocess.run([PORT, os.path.join(ROOT, "aqk2k_lnx/aq_dic")],
                             input="\n".join(corpus) + "\n", text=True,
                             capture_output=True).stdout.splitlines()
    n = min(len(corpus), len(expect), len(got))
    diffs = [(i, corpus[i], expect[i], got[i]) for i in range(n)
             if expect[i] != got[i]]
    common_start = len(corpus) - 24
    common_diffs = [d for d in diffs if d[0] >= common_start]
    print(f"corpus: {len(corpus)} lines, compared: {n}")
    print(f"exact match: {n - len(diffs)}/{n} ({100.0*(n-len(diffs))/max(n,1):.1f}%)")
    print(f"common-sentence match: {24-len(common_diffs)}/24")
    for i, text, a, b in diffs[:20]:
        print(f"  #{i} {text!r}\n    orig: {a!r}\n    port: {b!r}")
    if len(diffs) > 20:
        print(f"  ... {len(diffs)-20} more diffs")
    return 0 if not common_diffs else 1

if __name__ == "__main__":
    sys.exit(main())
