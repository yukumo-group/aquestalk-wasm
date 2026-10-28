# aquestalk10-wasm

Port of AquesTalk10 (`libAquesTalk10.so.1.1`, x86-64 Linux) to WebAssembly
by **recompiling the actual machine code**, not by emulating x86.

The wasm module is built with clang/LLVM directly: no Emscripten, no embind,
no WASI, no imports.  It exports a small plain-C API and its linear memory;
`port/web/aqtk10.js` is a hand-written JS wrapper.

## Approach

Ghidra decompiles every function of the original shared object to C.  That C
is compiled to real machine code for x86-64 and wasm32.  The engine's *data*
(kana dictionaries and the ~290 KiB of voice/unit tables in `.rodata`) is
kept as an image and relocated at startup.  No x86 instruction interpretation
or CPU emulation is involved.

```
aqtk10_lnx/lib64/libAquesTalk10.so.1.1
        |  port/tools/gen_image.py   (Ghidra base 0x100000)
        v
port/src/image.c     .rodata + .data.rel.ro image + 782 R_X86_64_RELATIVE relocs
        |
        |  Ghidra headless (ghidra-scripts/DumpDecomp.java)
        v
decomp/all.c  --port/tools/gen_decomp.py-->  port/src/decomp.c
        |
        +-- port/src/shim.[ch]     types / relocation glue
        +-- port/src/minic.c       freestanding malloc/free/mem* for wasm
        +-- port/src/wasm_api.c    exported C API
        +-- port/src/cli.c         native differential-test driver
```

The C translation needed a few non-obvious fixes, all documented in
`gen_decomp.py`:

* wasm32 `long` is 32-bit while the original is LP64, so 64-bit integer
  types are used explicitly.
* Ghidra's bit-field syntax (`x._0_3_`) is lowered to typed memory accesses.
* Adjacent byte/short stack slots are grouped into structs.  The engine
  passes `&first` to functions that read 2, 3 or 7 bytes across neighbouring
  slots (kana codes, prosody records); C does not otherwise guarantee their
  relative placement.
* Ghidra misread two zero-extended byte loads in `FUN_001104c2` as signed
  16-bit reads, and compared signed SJIS bytes against an unsigned table.
  Both are corrected against the disassembly.
* The relocation tables in `.data.rel.ro` are arrays of **8-byte** pointers.
  They are typed as `uint64_t` so wasm32 does not index them with a 4-byte
  stride.

The only external dependencies of the engine are `malloc`, `free`, `memcpy`
and a stack.  On wasm those are provided by `minic.c`.

## Verification

The native test driver (`cli.c`) was compared byte-for-byte against the
original `.so` (loaded with `ctypes`) for:

* 84 utterances,
* 7 voices (F1/F2/F3/M1/M2/R1/R2),
* 3 input encodings (UTF-8, Shift-JIS, UTF-16LE),

i.e. **252/252 byte-identical WAVs** from both the native build and the raw
wasm module.  Error paths (empty string, null pointers, invalid keys,
engine output limit) and 1000 repeated calls (allocator reuse) are also
tested.

## Layout

| path | purpose |
| --- | --- |
| `aqtk10_lnx/` | original SDK (library, header, docs) |
| `ghidra-scripts/` | headless decompiler dump scripts |
| `decomp/all.c` | raw Ghidra output |
| `port/tools/gen_image.py` | builds the data image + relocation table |
| `port/tools/gen_decomp.py` | turns Ghidra C into compilable LP64-safe C |
| `port/src/decomp.c` | generated engine translation |
| `port/src/shim.[ch]` | support types/macros |
| `port/src/minic.c` | freestanding allocator + mem* for wasm |
| `port/src/wasm_api.c` | exported wasm C API |
| `port/src/cli.c` | native test driver |
| `port/web/aqtk10.wasm` | built raw wasm module (experimental ABI) |
| `port/web/aqtk10.js` | hand-written ES-module wrapper |
| `port/web/index.html` | browser demo |
| `tests/` | differential corpus and wasm tests |

`port/src/image.c` is generated (1.5 MiB) and is not committed.  The build
scripts regenerate it from the original `.so`.

## Build native

```sh
python3 port/tools/gen_image.py
python3 port/tools/gen_decomp.py
clang -std=gnu11 -O1 -fno-strict-aliasing -fwrapv -Iport/src \
    port/src/cli.c port/src/decomp.c port/src/image.c \
    -o port/build-native/aqtk10_test
printf 'こんにちは' | port/build-native/aqtk10_test 0 100 100 100 100 100 100 utf8 > out.wav
```

The driver takes `bas spd vol pit acc lmd fsc utf8|utf16|sjis` and reads the
kana string from stdin.

## Build raw wasm

```sh
./port/build-wasm.sh
```

This runs essentially:

```sh
clang --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin \
    -DAQTK_FREESTANDING -Iport/src \
    port/src/wasm_api.c port/src/minic.c port/src/decomp.c port/src/image.c \
    -Wl,--no-entry -Wl,--export-memory -Wl,--initial-memory=16777216 \
    -Wl,--max-memory=268435456 -Wl,-z,stack-size=1048576 \
    -Wl,--gc-sections -Wl,--strip-all \
    -Wl,--export=aqtk_synthe_utf8_default ... \
    -o port/web/aqtk10.wasm
```

Result: ~355 KiB wasm (+ ~290 KiB of that is the original voice data),
zero imports, 16 MiB initial memory that grows on demand.

### JS usage

```js
import { AquesTalk10, VOICES } from './aqtk10.js';

const tts = await AquesTalk10.load('./aqtk10.wasm');
tts.setDevKey('...');                       // optional
const wav = tts.synthe('こんにちは', VOICES.F1); // Uint8Array
// also: tts.syntheSjis(uint8array), tts.syntheUtf16(str|u16array)
```

Errors throw `AquesTalkError` with `.code` (the original error code).

### Demo

```sh
cd port/web && python3 -m http.server 8000
# open http://localhost:8000/
```

The page loads the wasm, synthesizes and plays/downloads WAV.

## Tests

```sh
node tests/test_wasm.mjs       # 252 raw-ABI cases + error paths (no ref WAVs needed)
node tests/test_wrapper.mjs    # JS wrapper sample
```

`tests/cases.json` contains the 84-source corpus with UTF-8/SJIS/UTF-16
inputs and SHA-256 of the expected WAVs.

## Notes / limits

* This is the evaluation version of the library.  Without a valid
  development key the original restriction applies: ナ行/マ行 are voiced as
  ヌ.  License-key handling is ported as-is; no key is bypassed.
* The engine's output buffer limit is the original one (error 122 for very
  long inputs).
* The wasm ABI (i64 return values on some functions) is internal to the
  module; the exported `aqtk_*` API is a plain 32-bit-pointer C API.

## License

The original AquesTalk10 library and its data remain subject to AQUEST's
license.  This repository is a local reverse-engineering/porting experiment.
