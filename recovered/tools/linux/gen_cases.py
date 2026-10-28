#!/usr/bin/env python3
"""Build a katakana breadth corpus for the AquesTalk1 comparison."""
import re

src = open("recovered/src/data/ot_data.c", encoding="utf-8").read()
block = src[src.index("const OtDictEnt ot_dict[]"):src.index("const int ot_dict_count")]
entries = []
for m in re.finditer(r'\{"((?:\\x[0-9A-Fa-f]{2})+)",\s*(\d+),\s*(\d+)\}', block):
    b = bytes(int(x, 16) for x in re.findall(r'\\x([0-9A-Fa-f]{2})', m.group(1)))
    entries.append(b.decode("shift_jis"))

seen = set()
mora = []
for e in entries:
    if e.startswith("_") or len(e) > 3:
        continue
    if not all(("\u30a0" <= c <= "\u30ff") or c == "\u30fc" for c in e):
        continue
    if e in seen:
        continue
    seen.add(e)
    mora.append(e)

rows = [
    "アイウエオ", "カキクケコ", "サシスセソ", "タチツテト", "ナニヌネノ",
    "ハヒフヘホ", "マミムメモ", "ヤユヨ", "ラリルレロ", "ワヲン",
    "ガギグゲゴ", "ザジズゼゾ", "ダヂヅデド", "バビブベボ", "パピプペポ",
    "キャキュキョ", "シャシュショ", "チャチュチョ", "ニャニュニョ",
    "ヒャヒュヒョ", "ミャミュミョ", "リャリュリョ", "ギャギュギョ",
    "ジャジュジョ", "ビャビュビョ", "ピャピュピョ",
    "アカサタナハマヤラワ", "ガザダバパ", "ァィゥェォャュョッ",
    "ヴァヴィヴヴェヴォ", "ファフィフェフォ", "ティディトゥドゥ",
]

contexts = [
    "アッ", "カッ", "サッ", "タッ", "ハッ", "マッ", "ヤッ", "ラッ", "ワッ",
    "キャッ", "シャッ", "チャッ", "アッア", "ッア", "ッ",
    "アー", "カー", "サー", "ター", "ハー", "マー", "ヤー", "ラー", "ワー",
    "キョー", "フュー", "アーア", "ー", "ーー",
    "アン", "カン", "サン", "タン", "ハン", "マン", "ヤン", "ラン", "ワン",
    "ン", "ンン", "アンア", "ンア",
    "アッカ", "アーン", "キャー", "チョッ", "キョウ", "シャッ", "アッバ",
    "イッショ", "ガッコウ", "ニッポン", "フュージョン", "ヴァイオリン",
    "ティー", "ディー", "トゥー", "ドゥー", "ツァー", "ウィー", "クァルテット",
    "シェー", "ジェー", "チェー", "スィー", "ズィー",
    "ア、イ、ウ、エ、オ。", "アカサタナ。", "ア？", "ア！",
]

extras = [
    "ァ", "ィ", "ゥ", "ェ", "ォ", "ャ", "ュ", "ョ", "ヮ", "ヵ", "ヶ",
    "ヂ", "ヅ", "ヴ", "ヷ", "ヸ", "ヹ", "ヺ", "ヽ", "ヾ", "・", "゛", "゜",
    "カ゜", "キ゜", "ク゜", "ケ゜", "コ゜", "キ゜ャ", "キ゜ョ", "ヴァ", "ヴィ",
    "ヴェ", "ヴォ", "ヂャ", "ヅァ", "イェ", "ウォ", "クヮ", "グヮ",
]

mixed = [
    "アカサタナハマヤラワガザダバパキャキュキョシャシュショチャチュチョ"
    "ニャニュニョヒャヒュヒョミャミュミョリャリュリョギャギュギョジャジュジョ"
    "ビャビュビョピャピュピョファフィフェフォヴァイオリン。",
    "アアアアアイイイイイウウウウウエエエエエオオオオオ",
]

cases = []
for i, t in enumerate(mora):
    cases.append((f"mora{i:03d}", t))
for i, t in enumerate(rows):
    cases.append((f"row{i:02d}", t))
for i, t in enumerate(contexts):
    cases.append((f"ctx{i:02d}", t))
for i, t in enumerate(extras):
    cases.append((f"extra{i:02d}", t))
for i, t in enumerate(mixed):
    cases.append((f"mixed{i:02d}", t))

with open("build/cases.tsv", "w", encoding="utf-8") as f:
    for label, text in cases:
        f.write(f"{label}\t{text}\n")

print(f"mora={len(mora)} rows={len(rows)} ctx={len(contexts)} extras={len(extras)} mixed={len(mixed)} total={len(cases)}")
