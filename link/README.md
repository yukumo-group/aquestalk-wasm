# Relocatable engines and the single-memory bundle

The engines in `engines/` are also buildable as **relocatable WebAssembly
objects** (`.a` archives of `.o` files).  They can be linked by `wasm-ld`
together with Rust code into **one module with one memory**, which is what
browsers support today (the multi-memory proposal is not available in
Safari/Firefox and only partially in Chromium).

```
engines/<engine>/build-reloc.sh   ->  dist/reloc/lib<engine>.a
scripts/build-reloc.sh            ->  dist/aquestalk.wasm  (all five + Rust host)
link/test/reloc.mjs               ->  byte-for-byte parity with the old modules
```

## Quick start

```bash
./scripts/build-reloc.sh          # build archives, link, run parity tests
./scripts/build-reloc.sh --no-test
node link/test/reloc.mjs          # parity only (uses the existing bundle)
```

Requirements: LLVM with the `wasm32` target (`clang`, `wasm-ld`, `llvm-ar`,
`llvm-nm`), Rust with `wasm32-unknown-unknown`, Node.js 18+.

## What the bundle contains

| export prefix | engine | archive |
| --- | --- | --- |
| `aq1_` | AquesTalk1 (9 voices) | `libaq1.a` |
| `aq2_` | AquesTalk2 | `libaq2.a` |
| `aq10_` | AquesTalk10 | `libaq10.a` |
| `aqk2k_` | AqKanji2Koe | `libaqk2k.a` |
| `aqusr_` | AqUsrDic (Check + Import/Export) | `libaqusr.a` |
| — | Rust host (`malloc`, `free`, marker) | `libaq_host.a` |

`dist/reloc/exports.txt` is the authoritative list; `link/abis/*.json` maps
the original C names to the public names.

The module has **0 imports**, **exactly one memory** and one table
(`funcref`, needed by the decompiled indirect calls).  Initial memory is
64 MiB and the maximum is 1 GiB, both configurable through `INITIAL_MEMORY` /
`MAX_MEMORY` / `STACK_SIZE` when running `scripts/build-reloc.sh`.

## How namespacing works

Each engine used to be its own module, so helper names repeat between engines:
AqKanji2Koe and AqUsrDic both define `aqstr_append`, `aq_image`,
`__cxa_throw`, and the decompiler emits address-based `FUN_0010…` names in
overlapping ranges.  A static link rejects those duplicate globals.

Rewriting wasm symbol tables is awkward (`llvm-objcopy` has no `--prefix-symbols`
for wasm), so the relocatable build compiles twice:

1. pass 1 compiles the engine normally;
2. `link/tools/gen_prefix.py` reads `llvm-nm` and writes a `-include` header
   that renames every global to `<prefix><name>` (public entry points get the
   short names in `link/abis/<engine>.json`);
3. pass 2 recompiles with that header, and the objects go into the archive.

The header is applied to every translation unit, so definitions and references
stay consistent.  C++ mangled names and the compiler-emitted C++ ABI helpers
(`__cxa_atexit`, `__cxa_guard_*`, `__dso_handle`) cannot be renamed this way;
they are left alone and the final link proves there is no collision.

## libc and memory

The engines were freestanding: each carried its own bump/free-list allocator
starting at `__heap_base`, plus `memcpy`/`malloc`/`strlen`/stdio stubs.  Two
allocators sharing one `__heap_base` would corrupt each other, so the
relocatable builds **drop the engine runtime**:

| symbol family | supplied by |
| --- | --- |
| `malloc`, `free`, `calloc`, `realloc` | `link/host/src/lib.rs` on Rust's global allocator |
| `memcpy`, `memset`, `memmove` | Rust compiler-builtins |
| `strlen`, `strcmp`, `strncmp`, `strcpy`, `memcmp`, `time`, `abort` | `link/host/aq_host.c` |
| `fprintf`, `vfprintf`, `fputc`, `fwrite`, `puts`, `stderr` | `link/host/aq_host.c` (no-ops; diagnostics only) |
| `__assert_fail`, `__stack_chk_fail` | `link/host/aq_host.c` (trap) |

`malloc` keeps a 16-byte header so `free`/`realloc` can recover the layout, and
it zero-fills allocations.  AqKanji2Koe and AqUsrDic were originally built with
an allocator that zeroes reused small blocks (the decompiled code relies on
that), and zeroing also makes the other engines deterministic.  Payloads are
16-byte aligned.

The C++ engine (AqUsrDic/marisa) keeps its own `operator new`/`delete`, which
call the same `malloc`/`free`.

## Linking from Rust

`wasm-ld` (or rust-lld, which `cargo` uses for `wasm32-unknown-unknown`) needs
the archives plus the two host pieces:

```
<engine archives>  libaq1.a … libaqusr.a
<host object>      libaqhost.a   (aq_host.o: string/stdio/time/trap)
<Rust staticlib>   the crate that defines the malloc shims
```

Order matters for archives: put the engine archives first, then `libaqhost.a`,
then the Rust archive that provides `malloc`.  A convenient recipe is
`--whole-archive` around the engine archives (they are all wanted anyway), then
`--no-whole-archive` for the host and Rust archives.

`Yukw`'s `aq-wasm` crate uses exactly this layout behind its
`static-engines` Cargo feature; see its `build.rs` for the `cargo:rustc-link-arg`
lines.

## Symbol map

`dist/reloc/lib<engine>.symbols.json` records every rename for each archive, and
`dist/reloc/build-info.json` records the bundle size, memory limits and archive
list.  Regenerate both with the build script.

## Adding an engine

1. Add `link/abis/<name>.json` with the prefix and the public API mapping.
2. Add `engines/<engine>/build-reloc.sh` that compiles the sources (without the
   engine's allocator runtime) into `sources[]`, defines `compile_one`, sources
   `link/tools/reloc.sh` and calls `reloc_archive`.
3. Add the engine to `scripts/build-reloc.sh` and to the parity test.
