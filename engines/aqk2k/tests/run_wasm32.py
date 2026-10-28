#!/usr/bin/env python3
"""Compare the wasm32 build against the original SDK on common text."""
import os, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
def main():
    r = subprocess.run(['node', os.path.join(ROOT, 'port/wasm32_corpus.mjs'),
                        os.path.join(ROOT, 'tests/corpus_common.txt')],
                       text=True, capture_output=True, cwd=ROOT)
    if r.returncode != 0:
        print(r.stderr)
        return 1
    got = r.stdout.splitlines()
    exp = open(os.path.join(ROOT, 'tests/expected_common.txt'), encoding='utf-8').read().splitlines()
    bad = [(i, exp[i], got[i] if i < len(got) else '<missing>')
           for i in range(min(len(exp), len(got))) if exp[i] != got[i]]
    print(f"wasm32 common: {len(exp)-len(bad)}/{len(exp)} match")
    for b in bad:
        print('  ', b)
    return 0 if not bad else 1
if __name__ == '__main__':
    sys.exit(main())
