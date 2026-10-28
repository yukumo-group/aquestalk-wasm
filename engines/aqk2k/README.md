# aqk2k → C++ / WebAssembly port

Reimplementation of AQUEST's `libAqKanji2Koe.so.4.1` (kanji-kana mixed text →
AquesTalk kana symbol string) as portable C/C++.

## Status

The port now matches the original 64-bit Linux library on the full
differential corpus:

* **303/303 (100%)** exact matches, including sentence-final punctuation,
  accent positions, `<NUMK VAL="…" COUNTER="…">` / `<NUM VAL="…">` tags, and
  ASCII/English word readings.
* The wasm32 build matches **303/303** on the same corpus and **11/11** on
  `tests/corpus_common.txt`.
* Long sessions reuse one instance; `tests/soak.mjs` runs 3030 consecutive
  conversions and a 24k-character passage with bounded memory.

The whole library was analyzed with Ghidra (`ghidra-scripts/`, `decomp/`).

* `port/src/decomp.c` is a mechanically recompiled translation of the
  decompiled machine code (178 functions, custom code + marisa_a reader),
  with a small set of documented hand fixes listed below.
* `port/src/shim.c` implements the libstdc++ `std::string` ABI used by the
  decompiled code, allocation, and the C++ exception stubs.
* `port/src/image.c` embeds the original `.rodata`/`.data` image and applies
  its relative relocations at startup.
* Dictionary lookups are served by two precomputed surface → record-id tables
  (`port/tools/gen_lookup.mjs`) instead of the modified MARISA search code:
  the master dictionary (MSTD) and the single-character reading dictionary
  (MCGD).  This also makes wasm32 work, where the decompiled MARISA search's
  64-bit pointer arithmetic is not reliable.
* `port/src/api.cpp` implements the public AqKanji2Koe API for the native
  build (embind was removed).
* `port/src/api_raw.c` + `port/src/lookup_c.c` + `port/src/runtime.c` form a
  **freestanding C ABI** used by the raw wasm build: no embind, no Emscripten,
  no libc.  See below.

### Port-specific fixes

These are encoded in `port/tools/gen_decomp.py` / `gen_wasm32.py` where
possible; the checked-in `decomp.c` also contains older hand fixes that the
generator does not reproduce.

1. `FUN_0010e830` takes a UTF-16 code unit, but Ghidra typed it as signed
   `short`.  Values ≥ 0x8000 (fullwidth digits `0xff10..0xff19`) never
   compared equal, which disabled the entire numeric-tag pipeline.
2. The original tokenizer enumerates **every** common prefix in the MARISA
   trie.  The replacement lookup enumerates hashed prefixes shortest-first;
   returning only the longest match lost segmentations such as `[絶][する]`
   and `[一][人]`.
3. `FUN_0010d610` built a `std::string` temporary from three separate stack
   locals.  The compiler may reorder them, so `&local_68` was not a valid
   string pointer; English transliteration crashed or dropped words.  It is
   now one contiguous `AqStr`.
4. The three inlined `std::u16string::replace` calls in `FUN_0010ef60`
   (NUMK counter suffix `テン→てん`, `ニチ→にち`, `ニン→にん`) were replaced
   with a direct `FUN_0010d130` call.  The old overlap branches assumed LP64
   pointer sizes and corrupted wasm32 output.
5. `-0x80000001` in Ghidra's signed-range test is unsigned in C, so the
   "same length" branch was always false.  It is rewritten as a plain
   `lVar11 == 0` check.
6. wasm32 AqU16 pointer arithmetic (`sb.p + n`) is rewritten in byte units;
   the 64-bit pointer cells otherwise advanced by one byte instead of two.
7. The allocator zero-fills reused small blocks: the decompiled code assumes
   fresh objects are zeroed (the original arena/allocator behaviour), and
   reusing stale blocks produced wrong readings.

### Known gaps

* Arabic/fullwidth number runs are emitted as the original `<NUMK>` / `<NUM>`
  tags, matching the 64-bit library.
* The evaluation-version restriction (ナ行/マ行 → ヌ) is reproduced, as in the
  original evaluation build.
* Very large single passages are CPU-bound in the original algorithm (roughly
  quadratic); 24k characters take about 0.5 s and 72k about 6 s in wasm32.
  Split extremely long text at sentence/paragraph boundaries if needed.
* The wasm32 build serves the system dictionary (MSTD) and the per-character
  reading dictionary (MCGD) from `lookup.bin`.  User-dictionary-only entries
  are still searched through the decompiled MARISA path, which is not
  reliable for every key in wasm32; the shipped `aq_user.dic` sample works for
  ordinary Japanese words, but a user-dict-only key containing fullwidth
  Latin may fall back to per-character readings.  Native builds use the
  original search path.
* The original `aqdic.bin` and generated `lookup.bin` are **not** in this
  repository. You need your own licensed copy of the SDK.

## Data files

```
aqk2k_lnx/aq_dic/aqdic.bin      (not committed, 9.8 MB)
aqk2k_lnx/aq_dic/aq_user.dic    (committed sample)
aqk2k_lnx/aq_dic/lookup.bin     (generated, not committed)
```

`lookup.bin` uses the `K2K2` format: header + MSTD table + MCGD table.  It is
regenerated from the dictionary and must be present for numeric/punctuation
and English readings to match.  Old `K2KL` files still load, but only serve
MSTD.

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
clang -std=gnu11 -O1 -c ../src/lookup_c.c -o lookup_c.o
clang++ -std=c++17 -O1 -c ../src/api.cpp -o api.o
clang++ -O1 -o aqk2k decomp.o shim.o image.o api.o cold.o lookup_c.o
echo 音声合成テスト | ./aqk2k ../../aqk2k_lnx/aq_dic
# オンセーゴーセーテ'_スト。
printf '123円\n一人\nこんにちは。\n' | ./aqk2k ../../aqk2k_lnx/aq_dic
# <NUMK VAL="123" COUNTER="エン">。
# <NUMK VAL="1" COUNTER="にん">。
# コンヌチワ'。
```

`api.cpp` also keeps the original `AqKanji2Koe_Create`/`Create_Ptr` ownership
semantics: `Create` owns the file buffers it allocated, `Create_Ptr` borrows
the caller's buffers.

## Raw wasm32 build (Safari-compatible)

`port/build_wasm32.sh` compiles the C sources with
`clang --target=wasm32-unknown-unknown -nostdlib` and links with `wasm-ld`.
The result is a self-contained ~232 KB module with **no imports** and a plain
C ABI:

```
aq_init()
aq_alloc(n) -> ptr
aq_free(ptr)
aq_set_lookup(data, size) -> 0/1
aq_create(sysDicPtr, userDicPtr, &err) -> handle
aq_convert(handle, utf8In, utf8Out, outCap) -> 0/error
aq_conv_roman(handle, utf8In, utf8Out, outCap) -> 0/error
aq_release(handle)
aq_set_devkey(key) -> 0/1
```

The module keeps the original LP64 field layout by storing `long`/`ulong`
values, pointers and the `std::string`/`u16string` layout in 64-bit cells
while native pointers are 32-bit; all addresses stay below 4 GB.

```sh
./port/build_wasm32.sh          # clang --target=wasm32-unknown-unknown
node port/wasm32_test.mjs       # smoke test
node port/wasm32_corpus.mjs tests/corpus_diff.txt
node tests/soak.mjs             # 3030 conversions + long passage
```

`aq_create` borrows the dictionary buffers; `aq_release` therefore does not
free them.  The caller keeps them for the lifetime of the instance (the demo
does this).

### Memory / long sessions

The freestanding runtime uses segregated free lists with block splitting:
small objects are recycled in O(1), large blocks (dictionaries, output
buffers) are reused from an address-ordered list, and reused small blocks are
zeroed.  Memory stays flat across long sessions (3030 conversions stay at
32 MiB in `tests/soak.mjs`).  Set `AQK2K_LEAK=1` when building to switch back
to the old bump arena for very short-lived workers.

`port/web/index.html` is a browser demo (serve the repo root over HTTP, e.g.
`python3 -m http.server`), loading `aqdic.bin`, `aq_user.dic`, `lookup.bin`
and the wasm32 module.

Both `AqKanji2Koe_Convert` and `AqKanji2Koe_ConvRoman` work in the wasm32
build.  The roman table is an array of 16-byte `{kana, roman}` entries;
`port/tools/gen_wasm32.py` rewrites the decompiled pointer walk to use that
stride explicitly, because wasm32 pointers are 4 bytes.

## Analysis artifacts

* `decomp/all.c` – full Ghidra decompilation (318 functions).
* `decomp/functions.tsv`, `decomp/data.tsv` – function/data inventories.
* `ghidra-scripts/` – headless dump scripts used to produce the above.
* `port/tools/gen_decomp.py`, `gen_image.py` – generators for
  `decomp.c` / `image.c`.
* `port/tools/gen_lookup.mjs` – generates the MSTD + MCGD lookup file.
* `port/tools/gen_wasm32.py` – produces the wasm32 source tree with 64-bit
  scalar cells and explicit AqU16/AqStr pointer handling.

## Licensing

`libAqKanji2Koe.so.*`, the headers, and `aqdic.bin` are AQUEST proprietary
files; they are only included here for interoperability research. The port
code itself follows the same restrictions as the original SDK.

## Differential tests

`tests/corpus_diff.txt` contains 240 random dictionary words, 40 generated
sentences, and 23 fixed edge cases (punctuation, English, numbers).  The
expected output is produced by the original 64-bit library
(`tests/expected64.txt`); the 32-bit SDK produces byte-identical output on this
corpus (`tests/expected32.txt`).

```sh
python3 tests/gen_diff_corpus.py     # new random corpus (re-capture expected)
python3 tests/run_diff.py            # run native port against the baseline
python3 tests/run_wasm32.py          # wasm32 common corpus
node tests/soak.mjs                  # long session + large input
```

Current status: **303/303 (100%)** for both the native build and the wasm32
build.  The harness remains the baseline for future changes.
