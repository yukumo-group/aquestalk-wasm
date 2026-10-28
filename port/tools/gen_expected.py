#!/usr/bin/env python3
"""Record SHA-256 of the *original* library's output for the regression matrix.

Run once (with the original .so present) to refresh port/tests/expected.json.
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
LIB = os.path.join(ROOT, 'aqtk2-lnx', 'lib64', 'libAquesTalk2Eva.so.2.3')
REF = os.path.join(ROOT, 'port', 'build-native', 'ref')
OUT = os.path.join(ROOT, 'port', 'tests', 'expected.json')


def main():
    if not os.path.exists(REF):
        sys.exit('build build-native/ref first (tools/build-ref.sh)')
    tmp = tempfile.mkdtemp(prefix='aqexp')
    entries = []
    for c in cases.cases():
        src = os.path.join(cases.CORPUS, c['text'])
        inp = os.path.join(tmp, 'in.bin')
        cases.convert(src, c['enc'], inp)
        wav = os.path.join(tmp, 'out.wav')
        if os.path.exists(wav):
            os.unlink(wav)
        cmd = [REF, LIB, c['enc'], str(c['speed']), inp, wav]
        if c['phont']:
            cmd.append(os.path.join(cases.PHONT, c['phont']))
        p = subprocess.run(cmd, capture_output=True, text=True)
        e = dict(c)
        out = p.stdout.strip()
        if out.startswith('OK '):
            data = open(wav, 'rb').read()
            e['size'] = len(data)
            e['sha256'] = hashlib.sha256(data).hexdigest()
        else:
            e['error'] = out
        entries.append(e)
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump({'source': 'libAquesTalk2Eva.so.2.3', 'cases': entries},
              open(OUT, 'w'), indent=1)
    print('wrote', OUT, len(entries), 'cases')


if __name__ == '__main__':
    main()
