#!/usr/bin/env python3
"""Build a fresh differential-test corpus from lookup.bin + fixed edge cases.

The checked-in tests/corpus_diff.txt and tests/expected64.txt are the
regression baseline.  Re-running this script changes the random dictionary
sample, so tests/expected64.txt must be re-captured from the original 64-bit
SDK afterwards.
"""
import random, struct, sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LOOKUP = os.path.join(ROOT, "aqk2k_lnx", "aq_dic", "lookup.bin")

def read_keys(path):
    d = open(path, "rb").read()
    assert d[:4] in (b"K2KL", b"K2K2")
    # Both formats start with the MSTD count at +4 and its entries at +12.
    n = struct.unpack_from("<I", d, 4)[0]
    off = 12
    keys = []
    for _ in range(n):
        klen, _id = struct.unpack_from("<II", d, off)
        off += 8
        s = d[off:off + klen * 2].decode("utf-16le")
        off += klen * 2
        keys.append(s)
    return keys

def is_jp(s):
    return all(0x3040 <= ord(c) <= 0x30FF or 0x4E00 <= ord(c) <= 0x9FFF
               or 0x3400 <= ord(c) <= 0x4DBF for c in s)

def main():
    keys = read_keys(LOOKUP)
    cand = [k for k in keys if 1 <= len(k) <= 8 and is_jp(k)]
    random.seed(20261028)
    random.shuffle(cand)
    words = []
    seen = set()
    for w in cand:
        if w in seen:
            continue
        seen.add(w)
        words.append(w)
        if len(words) >= 240:
            break
    lines = []
    lines += words
    particles = ["の", "は", "が", "を", "に", "で", "と", "も", "へ", "から"]
    random.seed(7)
    for i in range(40):
        a = random.choice(words)
        b = random.choice(words)
        p = random.choice(particles)
        lines.append(a + p + b + "です。")
    lines += [
        "こんにちは。", "おはようございます！", "ありがとう。",
        "東京は日本の首都です。", "今日はいい天気ですね。",
        "オハヨウゴザイマス", "テスト", "あ", "漢字",
        "これはテストです。これはテストです。これはテストです。",
        "", "。。。", "、", "「こんにちは」", "ABC", "hello world",
        "123", "12", "100円", "10時", "三日月", "一人", "2024年",
    ]
    out = os.path.join(ROOT, "tests", "corpus_diff.txt")
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")
    print("wrote", out, len(lines), "lines")

if __name__ == "__main__":
    main()
