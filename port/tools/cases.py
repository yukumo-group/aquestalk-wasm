#!/usr/bin/env python3
"""Shared case list for the differential / regression tests."""
import os
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
CORPUS = os.path.join(ROOT, 'port', 'tests', 'corpus')
PHONT = os.path.join(ROOT, 'aqtk2-lnx', 'phont')

ICONV = {'sjis': 'SHIFT-JIS', 'euc': 'EUC-JP', 'utf16': 'UTF-16LE'}


def convert(src, enc, dst):
    if enc in ('utf8', 'roman'):
        data = open(src, 'rb').read()
    else:
        data = subprocess.run(['iconv', '-f', 'UTF-8', '-t', ICONV[enc], src],
                              capture_output=True, check=True).stdout
    open(dst, 'wb').write(data)


def cases():
    """Return the regression matrix.

    Each entry: text file, encoding, speed, optional voice file.  The matrix
    covers every text/encoding combination plus every bundled voice and a few
    speed extremes.
    """
    texts = sorted(f for f in os.listdir(CORPUS) if f.endswith('.txt'))
    out = []
    for t in texts:
        for enc in ('utf8', 'sjis', 'euc', 'utf16'):
            out.append(dict(text=t, enc=enc, speed=100, phont=None))
    for t in ('hello.txt', 'ohayo.txt', 'long.txt', 'punct.txt'):
        for speed in (50, 150, 300):
            out.append(dict(text=t, enc='utf8', speed=speed, phont=None))
    for p in sorted(f for f in os.listdir(PHONT) if f.endswith('.phont')):
        out.append(dict(text='hello.txt', enc='utf8', speed=100, phont=p))
        out.append(dict(text='long.txt', enc='utf8', speed=100, phont=p))
    roman = os.path.join(CORPUS, 'roman')
    if os.path.isdir(roman):
        for t in sorted(os.listdir(roman)):
            for speed in (80, 100, 200):
                out.append(dict(text='roman/' + t, enc='roman', speed=speed, phont=None))
    return out
