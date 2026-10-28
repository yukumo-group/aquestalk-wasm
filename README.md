# aqk2k → C++ / WebAssembly port (work in progress)

Reimplementation of AQUEST's `libAqKanji2Koe.so.4.1` (kanji-kana mixed text →
AquesTalk kana symbol string) as portable C/C++.

## Status

This is a **work-in-progress**, not a finished port.

* The whole library was analyzed with Ghidra (`ghidra-scripts/`, `decomp/`).
* `port/src/decomp.c` is a mechanically recompiled translation of the
  decompiled machine code (178 functions, custom code + marisa_a reader).
* `port/src/shim.c` implements the libstdc++ `std::string` ABI used by the
  decompiled code, allocation, and the C++ exception stubs.
* `port/src/image.c` embeds the original `.rodata`/`.data` image and applies
  its relative relocations at startup.
* Dictionary lookups are served by a precomputed surface → record-id table
  (`port/tools/gen_lookup.mjs`) instead of the modified MARISA search code.
  This makes readings match the original for normal text.
* `port/src/api.cpp` implements the public AqKanji2Koe API (embind).
  `AqKanji2Koe_Create`, `AqKanji2Koe_Create_Ptr`, `AqKanji2Koe_Convert`,
  `AqKanji2Koe_ConvRoman`, `AqKanji2Koe_Release`, `AqKanji2Koe_SetDevKey`.

### Known gaps

* Arabic/fullwidth number runs still produce kana instead of the original
  `<NUMK VAL="…" COUNTER="…">` / `<NUM VAL="…">` tags (`12`, `100円`, …).
* The evaluation-version restriction (ナ行/マ行 → ヌ) is reproduced, as in the
  original evaluation build.
* The original `aqdic.bin` and generated `lookup.bin` are **not** in this
  repository. You need your own licensed copy of the SDK.

## Data files

```
aqk2k_lnx/aq_dic/aqdic.bin      (not committed, 9.8 MB)
aqk2k_lnx/aq_dic/aq_user.dic    (committed sample)
aqk2k_lnx/aq_dic/lookup.bin     (generated, not committed)
```

Generate the lookup table (requires a checkout of
[Love-Kogasa/bakak2k](https://github.com/Love-Kogasa/bakak2k) at `./bakak2k`):

```sh
node port/tools/gen_lookup.mjs aqk2k_lnx/aq_dic/aqdic.bin aqk2k_lnx/aq_dic/lookup.bin
```

## Native build

```sh
cd port/build-native
clang -std=gnu11 -O1 -fno-strict-aliasing -c ../src/decomp.c -o decomp.o
clang -std=gnu11 -O1 -c ../src/shim.c -o shim.o
clang -std=gnu11 -O1 -c ../src/image.c -o image.o
clang -std=gnu11 -O1 -c ../src/cold_stubs.c -o cold.o
clang++ -std=c++17 -O1 -c ../src/api.cpp -o api.o
clang++ -std=c++17 -O1 -c ../src/trie_lookup.cpp -o trie_lookup.o
clang++ -O1 -o aqk2k decomp.o shim.o image.o api.o cold.o trie_lookup.o
echo 音声合成テスト | ./aqk2k ../../aqk2k_lnx/aq_dic
# オンセーゴーセーテ'_スト。
```

## Analysis artifacts

* `decomp/all.c` – full Ghidra decompilation (318 functions).
* `decomp/functions.tsv`, `decomp/data.tsv` – function/data inventories.
* `ghidra-scripts/` – headless dump scripts used to produce the above.
* `port/tools/gen_decomp.py`, `gen_image.py` – generators for
  `decomp.c` / `image.c`.

## Licensing

`libAqKanji2Koe.so.*`, the headers, and `aqdic.bin` are AQUEST proprietary
files; they are only included here for interoperability research. The port
code itself follows the same restrictions as the original SDK.
