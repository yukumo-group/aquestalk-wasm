#!/usr/bin/env python3
"""Regression test against recorded hashes (does not need the original .so).

usage: check_expected.py [--wasm]

Compares the native build (port/build-native/aqtest) or the wasm build
(dist/aquestalk2.js) against port/tests/expected.json, which was produced by
running the original libAquesTalk2Eva.so.2.3.
"""
import hashlib
import json
import os
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cases

ROOT = cases.ROOT
NATIVE = os.path.join(ROOT, 'port', 'build-native', 'aqtest')
WASM_JS = os.path.join(ROOT, 'dist', 'aquestalk2.js')
WASM_RUN = os.path.join(ROOT, 'port', 'tools', 'wasm_run.mjs')
EXPECTED = os.path.join(ROOT, 'port', 'tests', 'expected.json')


def main():
    wasm = '--wasm' in sys.argv
    if wasm and not os.path.exists(WASM_JS):
        sys.exit('build the wasm module first (port/build-wasm.sh)')
    if not wasm and not os.path.exists(NATIVE):
        sys.exit('build the native port first (port/build-native.sh)')

    data = json.load(open(EXPECTED))
    tmp = tempfile.mkdtemp(prefix='aqreg')
    bad = 0
    for c in data['cases']:
        src = os.path.join(cases.CORPUS, c['text'])
        inp = os.path.join(tmp, 'in.bin')
        cases.convert(src, c['enc'], inp)
        out = os.path.join(tmp, 'out.wav')
        if os.path.exists(out):
            os.unlink(out)
        tail = [os.path.join(cases.PHONT, c['phont'])] if c['phont'] else []
        if wasm:
            cmd = ['node', WASM_RUN, c['enc'], str(c['speed']), inp, out] + tail
        else:
            cmd = [NATIVE, c['enc'], str(c['speed']), inp, out] + tail
        p = subprocess.run(cmd, capture_output=True, text=True)
        got = p.stdout.strip()
        if 'error' in c:
            ok = got == c['error']
        else:
            ok = got == 'OK %d' % c['size'] and os.path.exists(out)
            if ok:
                h = hashlib.sha256(open(out, 'rb').read()).hexdigest()
                ok = h == c['sha256']
        if not ok:
            bad += 1
            print('FAIL %-14s %-5s speed=%-3d phont=%s: got %r want %r'
                  % (c['text'], c['enc'], c['speed'], c['phont'], got,
                     c.get('error', 'sha256 ' + c.get('sha256', '')[:12])))
    print('%d/%d cases match' % (len(data['cases']) - bad, len(data['cases'])))
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
