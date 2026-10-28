#!/usr/bin/env python3
"""Compare the wasm32 build against the original SDK.

Runs the common 11-line gate and the full 303-line differential corpus.
"""
import os, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def run_wasm(corpus):
    r = subprocess.run(
        ['node', os.path.join(ROOT, 'port/wasm32_corpus.mjs'),
         os.path.join(ROOT, 'tests', corpus)],
        text=True, capture_output=True, cwd=ROOT)
    if r.returncode != 0:
        print(r.stderr, file=sys.stderr)
        return None
    return r.stdout.splitlines()

def compare(name, corpus, expected):
    got = run_wasm(corpus)
    if got is None:
        return False
    exp = open(os.path.join(ROOT, 'tests', expected), encoding='utf-8').read().splitlines()
    n = min(len(exp), len(got))
    bad = [(i, exp[i], got[i]) for i in range(n) if exp[i] != got[i]]
    if len(got) != len(exp):
        print(f'{name}: line count {len(got)} != {len(exp)}')
        return False
    print(f'{name}: {len(exp)-len(bad)}/{len(exp)} match')
    for b in bad[:10]:
        print('  ', b)
    return not bad

def main():
    ok = compare('wasm32 common', 'corpus_common.txt', 'expected_common.txt')
    ok = compare('wasm32 full', 'corpus_diff.txt', 'expected64.txt') and ok
    return 0 if ok else 1

if __name__ == '__main__':
    sys.exit(main())
