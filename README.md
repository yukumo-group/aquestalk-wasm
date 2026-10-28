# aquestalk10-wasm

Port of AquesTalk10 (`libAquesTalk10.so.1.1`, x86-64 Linux) to WebAssembly
by **recompiling the actual machine code**, not by emulating x86.

## Approach

Ghidra decompiles every function of the original shared object to C.  The
result is compiled to real native/wasm code.  The engine's *data* (kana
dictionaries and the ~290 KiB of voice/unit tables in `.rodata`) is kept as
an image and relocated at startup.  No x86 instruction interpretation or
CPU emulation is involved.

```
aqtk10_lnx/lib64/libAquesTalk10.so.1.1
        |  tools/gen_image.py   (Ghidra base 0x100000)
        v
port/src/image.c     .rodata + .data.rel.ro image + R_X86_64_RELATIVE relocs
        |
        |  Ghidra headless (ghidra-scripts/DumpDecomp.java)
        v
decomp/all.c  --tools/gen_decomp.py-->  port/src/decomp.c
        |
        +-- port/src/shim.[ch]   types / relocation glue
        +-- port/src/cli.c       native differential-test driver
```

Notes on the C translation:

* wasm32 `long` is 32-bit while the original is LP64, so 64-bit integer
  types are used explicitly.
* Ghidra's bit-field syntax (`x._0_3_`) is lowered to typed memory accesses.
* Stack slots that the original accesses as one 3-byte struct are grouped
  into small structs so their relative layout is preserved.
* The only external dependencies of the engine are `malloc`, `free`,
  `memcpy` and a stack; no libstdc++ is needed at run time.

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
| `port/src/cli.c` | native test driver |
| `tests/` | differential test corpus and harness |

`port/src/image.c` is generated (1.5 MiB) and is therefore not committed.
Run `python3 port/tools/gen_image.py` before building.

## Build (native, current)

```sh
python3 port/tools/gen_image.py
python3 port/tools/gen_decomp.py
clang -std=gnu11 -O1 -fno-strict-aliasing -fwrapv -Iport/src \
    port/src/cli.c port/src/decomp.c port/src/image.c \
    -o port/build-native/aqtk10_test
printf 'こんにちは' | port/build-native/aqtk10_test 0 100 100 100 100 100 100 utf8 > out.wav
```

## Status

Work in progress.  The recompiled engine builds and links, and the API is
reachable, but synthesis currently stops with error 103: the mora record's
second kana byte (e.g. `0x6b` in the original's `01 02 3b 6b`) is lost in
the generated C, so the dictionary lookup fails.  This is being tracked
down; the original library produces `tests/ref/*.wav` for comparison.

The previous plan used Emscripten + embind.  The next step is a dependency-
free wasm build with clang/LLVM directly (`--target=wasm32`, `-nostdlib`,
custom allocator) and a small hand-written JS loader, exporting a plain C
API instead of embind bindings.

## License

The original AquesTalk10 library and its data remain subject to AQUEST's
license.  This repository is a local reverse-engineering/porting experiment.
