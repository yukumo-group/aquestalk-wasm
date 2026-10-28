#!/usr/bin/env python3
"""Differential test: recompiled port vs. the original shared object.

Runs the same input through work/ref (dlopen of libAquesTalk2Eva.so.2.3) and
the native build of the port, then compares the exit status, the reported
wave size and the WAV bytes.  Requires both binaries to be built; see build.sh.
"""
import os
import subprocess
import sys
import tempfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
LIB = os.path.join(ROOT, 'aqtk2-lnx', 'lib64', 'libAquesTalk2Eva.so.2.3')
REF = os.path.join(ROOT, "port", "build-native", "ref")
PORT = os.path.join(ROOT, 'port', 'build-native', 'aqtest')
WASM = '--wasm' in sys.argv
PORT_CMD = None
CORPUS = os.path.join(ROOT, "port", "tests", "corpus")
OUT = os.path.join(ROOT, "port", "build-native", "out")
PHONT = os.path.join(ROOT, 'aqtk2-lnx', 'phont')

ENCODINGS = ['utf8', 'sjis', 'euc', 'utf16']
ICONV = {'sjis': 'SHIFT-JIS', 'euc': 'EUC-JP', 'utf16': 'UTF-16LE'}


def convert(src, enc, dst):
    if enc == 'utf8':
        data = open(src, 'rb').read()
    else:
        data = subprocess.run(['iconv', '-f', 'UTF-8', '-t', ICONV[enc], src],
                              capture_output=True, check=True).stdout
    open(dst, 'wb').write(data)


def run(cmd):
    p = subprocess.run(cmd, capture_output=True)
    return p.returncode, p.stdout.decode(errors='replace').strip()


def compare(enc, speed, path, phont=None):
    os.makedirs(OUT, exist_ok=True)
    a = os.path.join(OUT, 'ref.wav')
    b = os.path.join(OUT, 'port.wav')
    for f in (a, b):
        if os.path.exists(f):
            os.unlink(f)
    tail = [phont] if phont else []
    ra, oa = run([REF, LIB, enc, str(speed), path, a] + tail)
    rb, ob = run(PORT_CMD(enc, speed, path, b, phont))
    wa = open(a, 'rb').read() if os.path.exists(a) else None
    wb = open(b, 'rb').read() if os.path.exists(b) else None
    if oa != ob or wa != wb:
        return 'status %r/%r size %s/%s' % (
            oa, ob, len(wa) if wa else None, len(wb) if wb else None)
    return None


def main():
    global PORT_CMD
    if WASM:
        PORT_CMD = lambda enc, speed, path, out, phont: ['node', os.path.join(ROOT, 'port', 'tools', 'wasm_run.mjs'), enc, str(speed), path, out] + ([phont] if phont else [])
        if not os.path.exists(os.path.join(ROOT, 'dist', 'aquestalk2.js')):
            sys.exit('build dist/aquestalk2.js first')
    else:
        PORT_CMD = lambda enc, speed, path, out, phont: [PORT, enc, str(speed), path, out] + ([phont] if phont else [])
    if not (os.path.exists(REF) and (WASM or os.path.exists(PORT))):
        sys.exit('build work/ref and the port first')
    texts = sorted(f for f in os.listdir(CORPUS) if f.endswith('.txt'))
    fails = 0
    total = 0
    tmp = tempfile.mkdtemp(prefix='aqcmp')

    for t in texts:
        for enc in ENCODINGS:
            src = os.path.join(CORPUS, t)
            dst = os.path.join(tmp, t + '.' + enc)
            convert(src, enc, dst)
            for speed in (50, 100, 150, 300, 0, 400):
                total += 1
                err = compare(enc, speed, dst)
                if err:
                    fails += 1
                    print('DIFF %-12s %-6s speed=%-3d %s' % (t, enc, speed, err))

    # every voice file, with a few representative phrases
    phonts = sorted(f for f in os.listdir(PHONT) if f.endswith('.phont'))
    for p in phonts:
        for t in ('hello.txt', 'ohayo.txt', 'long.txt', 'punct.txt'):
            dst = os.path.join(tmp, t + '.utf8')
            if not os.path.exists(dst):
                convert(os.path.join(CORPUS, t), 'utf8', dst)
            total += 1
            err = compare('utf8', 100, dst, os.path.join(PHONT, p))
            if err:
                fails += 1
                print('DIFF phont=%s %s %s' % (p, t, err))

    # roman input
    roman_dir = os.path.join(CORPUS, 'roman')
    if os.path.isdir(roman_dir):
        for t in sorted(os.listdir(roman_dir)):
            for speed in (80, 100, 200):
                total += 1
                err = compare('roman', speed, os.path.join(roman_dir, t))
                if err:
                    fails += 1
                    print('DIFF roman %s speed=%d %s' % (t, speed, err))

    print('%d/%d cases identical' % (total - fails, total))
    return 1 if fails else 0


if __name__ == '__main__':
    sys.exit(main())
