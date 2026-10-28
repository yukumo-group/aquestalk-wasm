# f3port

Mechanically recompiled AquesTalk1 `f3` engine.  This is the same approach as
`aquestalk2/port`: Ghidra decompiles the library, `gen_decomp.py` turns the
output into portable C, `gen_image.py` embeds the data segments, and clang
compiles the result to native and wasm32 machine code.

```
tools/gen_decomp.py   build/decomp-f3/all.c  -> src/decomp.c
tools/gen_image.py    libAquesTalk.so        -> src/image.c
src/shim.c            aq_init_image(): segment copy + relocations
src/f3api.c           f3_port_synthe_{utf8,sjis,utf16}()
```

Regenerate:

```sh
python3 recovered/f3port/tools/gen_image.py
python3 recovered/f3port/tools/gen_decomp.py
```

`gen_decomp.py` carries two manual fixes that are required for f3; see the
comments at `FUNC_FIXES` / the `0x109a18` and `0x10c278` blocks:

1. `FUN_0010c278` uses a 6-byte stack scratch buffer that Ghidra split into
   separate chars; it is rebuilt as `char sbuf[6]` so the bytes stay adjacent.
2. `FUN_00109a18` reads an int count at +8 and an int max at +0xc through an
   8-byte load; strict aliasing makes the compiler reuse the stale value, so
   the function is emitted with two separate int locals.

The stack-protector `in_FS_OFFSET` reads are replaced with 0, and the two
`.init_array`/`.fini_array` relocations into `.text` are left null.
