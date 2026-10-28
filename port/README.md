# Port internals

Technical notes on how `libAquesTalk2Eva.so.2.3` became `port/src/decomp.c`
and a freestanding wasm module.  See `../README.md` for the user-facing
overview.

## Pipeline

```
aqtk2-lnx/lib64/libAquesTalk2Eva.so.2.3
        │
        ├─ Ghidra headless ──────────────► decomp/all.c   (200 functions)
        │       scripts/DumpDecomp.java    decomp/data.tsv (data types)
        │
        ├─ tools/gen_decomp.py ──────────► src/decomp.c   (real C functions)
        │
        └─ tools/gen_image.py ───────────► src/image.c    (.rodata/.data + relocs)

src/decomp.c + src/image.c + src/shim.c + src/runtime.c + src/wasm_api.c
        │
        ├─ gcc ──────────────────────────► build-native/aqtest       (differential test)
        └─ clang --target=wasm32 ───────► dist/aquestalk2-core.wasm  (0 imports)

dist/aquestalk2.js + dist/aquestalk2-core.wasm
        └─ hand-written JS wrapper (web/aquestalk2.js) + demo
```

Nothing in the runtime interprets x86: `decomp.c` is ordinary C with branches
and loops, compiled to wasm by clang.  There is no Emscripten runtime and no
embind: the wasm module imports nothing and exports plain C functions.

## What is recompiled

`decomp/functions.tsv` lists 223 entries.  Ghidra's function coverage of
`.text` is 48 019 of 48 136 bytes; the gaps are alignment padding.

Excluded from `decomp.c`:

| Address | Reason |
| --- | --- |
| `0x100d50`–`0x100dc0` | `_init`, PLT stubs, `_start` |
| `0x100de0`, `0x100e60` | `__do_global_dtors_aux`, `frame_dummy` |
| `0x100e8c`…`0x101211` (5) | public `AquesTalk2_Synthe*` wrappers, rewritten in `wasm_api.c` |
| `0x101589` | `AquesTalk2_FreeWave`, rewritten in `wasm_api.c` |
| `0x10c990`, `0x10c9c8` | `.fini_array` walker and `_fini` |
| `>= 0x300000` | Ghidra's "bad instruction" pseudo-functions in `.data.rel.ro` |

Everything else (200 functions) is compiled as-is.

## Data image

The shared object has two `PT_LOAD` segments:

```
LOAD  offset 0x000000  vaddr 0x000000  filesz 0x15724   R E
LOAD  offset 0x016670  vaddr 0x216670  filesz 0x009b8   RW
```

The second segment's file offset is *not* its virtual address (the segment is
page-aligned at `0x200000`), so `image.c` places bytes at their VMA:

* `.rodata`      `0xc9e0` .. `0x136cc`  (27 884 bytes; includes the built-in phont)
* writable data  `0x216670` .. `0x217028`  (2 488 bytes)
* `.bss`         `0x217028` .. `0x217038`  (zero)

`aq_image[0x217038]` mirrors the original address space, which is why
`DAT_00110640` is simply `*(char *)(aq_image + 0x10640)`.  In the wasm module
this is a 2.2 MB `.bss` region filled at start-up by `aq_init_image()`.

### Relocations

`tools/gen_image.py` parses `.rela.dyn` / `.rela.plt`:

* 85 × `R_X86_64_RELATIVE` — `image + addend`
* 3 × `R_X86_64_GLOB_DAT` / 4 × `R_X86_64_JUMP_SLOT` — `malloc`, `free`,
  `memcpy`, `__cxa_finalize`, `__gmon_start__`, `_Jv_RegisterClasses`

No relocation points into `.text`, so no address-to-function mapping is needed
(the code contains no indirect calls through data).  `shim.c` traps at start-up
if that assumption is ever violated.

The relocation writes always store a full 64-bit value (`aq_put64`).  On wasm32
this keeps 8-byte pointer slots zero-extended, so code that reads a slot as
`undefined8` still sees a valid address.

### Data symbol types

`gen_decomp.py` emits a `#define` per referenced symbol:

* `undefined1` data → `*(char *)` (signed byte, matching the original `cmpb`
  tests; e.g. `DAT_00111e38 == -0x7e` at `0x3014` is `cmpb $0x82`).
* `undefined2/4/8` → `uint16_t/32/64_t`.
* `PTR_…` pointer slots → `uint64_t` if the code takes their address as an
  array (`(&PTR_DAT_003166a0)[i]` must keep the 8-byte stride on wasm32),
  otherwise the natural pointer type (`unsigned char *`, `void *`).

## Decompiler fixes

`gen_decomp.py` performs only mechanical rewrites, which are all visible in the
generated file:

1. `undefinedN` → fixed-width `uintN_t`; `long`/`ulong` → `int64_t`/`uint64_t`
   (the original is LP64; wasm32 `long` would otherwise be 32-bit).
2. Partial writes `x._0_4_ = v` → `*(uint32_t *)((char *)&x) = v`.
3. `CONCAT11(a,b)` helper (one occurrence).

In addition there are four **manual** patches, listed in `MANUAL_FIXES` with
their reason.  All four are functions whose machine code returns the value of a
tail-called function, but which Ghidra typed `void` because the first call
sites ignored the result:

| Function | Machine-code behaviour |
| --- | --- |
| `FUN_0010504a` | tail call `FUN_00105136`, returns its `ushort` |
| `FUN_0010b132` | tail call `FUN_0010b157`, returns its `int` |
| `FUN_00108397` | returns result of `FUN_00104f65` in `eax` |
| `FUN_001082aa` | returns result of `FUN_00104f65` in `eax` |

Everything else is untouched Ghidra output.  The compiler warnings are harmless
pointer-signedness/implicit-conversion differences inherited from the
decompiler; builds pass `-Wno-incompatible-pointer-types -Wno-int-conversion`.

## wasm32 and the original LP64 ABI

The port keeps all pointer-sized *data* 64-bit where the decompiled code treats
it as integer (`undefined8`, `PTR_…` slots), and only uses real C pointers at
the point of dereference.  Because every address in the image is < 4 GiB,
zero-extension/truncation round-trips are lossless.  The native and wasm builds
produce identical bytes over the whole test matrix.

## Freestanding runtime (`runtime.c`)

The module is linked with `-nostdlib`, so there is no libc and no imports:

* `memcpy`, `memmove`, `memset` are implemented in C (`-fno-builtin` avoids
  turning them into calls to themselves).  Clang may emit calls to these
  symbols for struct copies in `decomp.c`, so they must exist with the standard
  ABI.
* `abort()` traps (`__builtin_trap`).
* `malloc`/`free` is a boundary-tag first-fit allocator:
  * 8-byte block header `{ uint32_t size; uint32_t prev; }`; payloads are
    8-byte aligned; minimum block 32 bytes.
  * free list is doubly linked through the payload; free blocks coalesce with
    their physical neighbours.
  * allocation from the top grows the heap with `memory.grow` (64 KB pages) and
    starts at the linker-provided `__heap_base`.  With wasm-ld's default layout
    the stack sits below the data segment, so growing upwards is safe.
  * freeing the top block moves the break back, so repeated synthesis at
    varying sizes does not accumulate memory.
  * `AQ_RT_TEST` swaps the wasm memory back end for a static host arena so the
    allocator can be fuzzed natively (the wasm build fuzzes it through
    `aq_malloc`/`aq_free` instead; see `tools/stress_test.mjs`).

Build flags used (`build-wasm.sh`):

```
clang --target=wasm32 -O2 -nostdlib -ffreestanding -fno-builtin
      -fno-stack-protector -DAQ_FREESTANDING
      -Wl,--no-entry -Wl,--export-memory
      -Wl,--initial-memory=8M -Wl,--max-memory=512M
      -Wl,-z,stack-size=512K
```

Result: 79 KB wasm, 0 imports, 12 exports (`memory` + 11 functions).

## Host API (`wasm_api.c`)

The five public wrappers mirror the original control flow exactly (see
`decomp/all.c`, `AquesTalk2_Synthe*`):

* `AquesTalk2_Synthe` — Shift-JIS input, no conversion.
* `_Euc`, `_Utf8`, `_Utf16`, `_Roman` — convert to Shift-JIS with the recovered
  conversion routines (`FUN_001019f0`, `FUN_00101b2f`, `FUN_00101c6e`,
  `FUN_00101dd6`) and call the core `FUN_001012f4`.
* `_Utf16` expects host byte order (wasm = little endian).
* `AquesTalk2_FreeWave` is `free()`.
* `aq_malloc`, `aq_free`, `aq_last_error`, `aq_sample_rate`, `aq_image_base`
  are the small host-facing helpers used by the JS wrapper.

`aq_init_image()` runs before any recovered function; the public wrappers call
it first (the conversion routines also read `.rodata`).

## JavaScript wrapper (`web/aquestalk2.js`)

`createAquesTalk2(source)` instantiates the module with an empty import object
(accepts a URL, `ArrayBuffer`, typed array or precompiled `Module`).  All
allocation and marshalling is explicit:

1. `aq_malloc` a NUL-terminated string (UTF-8 bytes, Shift-JIS/EUC bytes,
   Latin-1 bytes, or UTF-16 code units), plus the optional phont blob and a
   4-byte size slot.
2. Take fresh typed-array views *after* all allocations (the heap may have
   grown and detached earlier views).
3. Call the exported function, read `*pSize`, copy the WAV out, then
   `AquesTalk2_FreeWave` and `aq_free` everything.
4. Return `null` on failure; `lastError()` reads the exported error code.

## Verification

* `tools/verify.py` runs the original `.so` via `dlopen` (`tools/ref.c`) and the
  port side by side over the corpus, all encodings, speeds and voice files,
  comparing stdout (OK/ERR code) and WAV bytes.
* `tools/check_expected.py` is the same idea with hashes recorded in
  `tests/expected.json`, usable without the original library.
* `--wasm` switches the port side to `node tools/wasm_run.mjs`.
* `tools/stress_test.mjs` fuzzes the allocator (20 000 random malloc/free with
  pattern verification) and synthesises 400 phrases in one instance, checking
  determinism and memory stability.

## Notes on the provided binary

The supplied `.so` differs from `libAquesTalk2Eva.so.2.3.bak` at file offset
`0x4ef4` only: `76 06` (`jbe`) became `eb 28` (`jmp`).  That jump skips the
character-normalisation block at `0x4ef6`–`0x4f1c`, making it unreachable;
Ghidra's CFG stops at the `jmp`, so the generated C matches the patched
behaviour.  With the pristine `.bak`, `な`/`ぬ`/`ま`/`む` all synthesise the
same waveform (the SDK's evaluation restriction); with the supplied `.so` they
are distinct.  The port reproduces the supplied binary.

## History

Commit `ffd5303` is the earlier Emscripten + embind implementation.  The
current tree replaces it with the freestanding LLVM build described above; the
old `src/api.cpp` binding layer only exists in git history.
