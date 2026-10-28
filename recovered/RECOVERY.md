# Open_Talk.dll recovery

Reconstruction of the speech library in `lib64/Open_Talk.dll`. The MIT notice from `lib64/LICENSE` is copied into `Open_Talk.h` and `open_talk.c`. The files under `lib64/` were not modified.

## Binary

| | |
|---|---|
| Path | `D:\DNV\Documents\Github\Yukumo-Group\OpenTalk1\lib64\Open_Talk.dll` |
| Size | 215552 bytes |
| Format | PE32+ DLL, AMD64 (`machine 0x8664`, optional magic `0x20B`) |
| Image base | `0x180000000` |
| Compiler | Visual C++ (statically linked CRT) |
| MD5 | `e2f1b3fa1bb223a6dc96ae76cd2f26ce` |
| SHA256 | `5bda97fd90d7b8ca02fb28a0add9665415ccb17ea8b42c5784488266b10d2658` |
| IDA database | `lib64/Open_Talk.dll.i64` (opened read-only; not saved) |

`main.py` only opens that database with `ida_domain`. It does not call the DLL. The six speech exports match `lib64/Open_Talk.h`.

Imports are 68 `KERNEL32` symbols used by the CRT (heap, TLS, locale, console, exception unwind). The synthesizer itself does not import a second DLL.

## Tools

`ida_domain` 0.5.1 was used, from the project virtualenv, against the existing `.i64`. Hex-Rays decompiled 60 of the 61 application functions on the first pass (`db.pseudocode.get_text`).

`sub_18000242C` (2358 bytes, the diphone expander) failed with Hex-Rays `MERR_BADFRAME` ("function frame is wrong"). The prologue is `lea rbp, [entry_rsp-0x5F]` plus `sub rsp, 0xB8`, and IDA had not recorded a stack-pointer delta (reported SPD 0). After re-creating the function and adding stack points (SPD `-248` at the calls), decompilation succeeded. Call analysis had also failed (`MERR_CALL_ANALYSIS` at `0x180002CB5`, the 5-argument call to `sub_180002D64`) until those points existed. The listing is `decompiled/18000242C_retry.c`.

No Ghidra pass was required. The MSVC CRT (everything from `__security_check_cookie` onward) was not reconstructed.

## What the library does

It turns a Shift-JIS kana string into an 8000 Hz, mono, 16-bit PCM WAV.

- Speaking rate is clamped to 50..300. The internal period is `25600 / speed` samples.
- `Open_Talk_Synthe` copies the SJIS string and synthesizes it.
- `Open_Talk_Synthe_Utf8` / `Open_Talk_Synthe_Utf16` convert through a 162-entry table (`RVA 0x2EF60`, 10 bytes each: SJIS, UTF-8, UTF-16) and then take the same path. UTF-16 accepts an optional `U+FEFF` BOM. A code that is not in the table returns `offset+1` in `*pSize` and a NULL wave. Output overflow returns `-1`. A bad argument returns `-2`.
- `Open_Talk_FreeWave` is `free`.
- An empty koe string returns NULL and does not write `*pSize`.

Error codes seen in the application code: 100 (bad state), 101 (PCM allocation), 102 (unknown symbol in the expander), 105 (kana not in the dictionary), 106 (empty `<...>` tag), 107 (unclosed `<` tag), 200 (phoneme buffer past 2047, or a chunk past 26624 bytes), 201 (phoneme list full), 202 (chunk merge failed), 203 (32 KB work-buffer allocation), 204 (frame list full).

### License marks

`Open_Talk_SetDevKey` and `Open_Talk_SetUsrKey` parse up to 16 uppercase hex digits (dashes are skipped; any other character counts as a zero nibble), then run 1391 rounds of a 3-bit rotate mixed with the 7-byte table at `RVA 0x1B808` and the constant `0xD271BA9DF61EED07`.

- Dev key: low byte `110`, byte 1 at least `0x14`, byte 6 equal to `86`. On success the halfword at bits 16..31 is stored. If that halfword is `22614` (`0x5856`), the parser keeps phoneme bytes 30..34 and 0x27..0x2B. Otherwise those bytes are replaced with `0x20` (the evaluation limit described in the header).
- User key: low byte `110` or `0xFF`, byte 1 at least `0x14`, byte 6 equal to `23`. A `0xFF` key also has to fall in a window around bits 16..31 measured in days since the Unix epoch (`time/86400`, from 31 days before that halfword through 396 days after). Bits 48..63 must be `1303` before the mark at bits 32..47 and the raw (pre-unscramble) integer are stored. The orchestrator copies the low 12 bits of the mark into the synth state and tests one bit of the raw integer as the sign of the noise excitation (`sub_1800059B4`, the byte at state offset 32). Hex-Rays left that bit index as `2048 & 63`, which is bit 0. Whether a later store replaces 2048 with the phrase index is UNCERTAIN.

This file describes those checks because they are the exported functions. It is not a key generator.

### Pipeline after the kana decode

1. Dictionary match (`sub_1800017EC`). 329 SJIS or ASCII keys, searched from the last entry backward. Misses return 105. The table is `ot_dict` in `ot_data.c`.
2. Youon rewrite of bytes 196..204, using the previous byte to pick one of two 9-entry maps (`sub_180003F3C`).
3. Vowel rewrite of bytes 179..195 via `sub_1800018C0` / `sub_18000195C`. The choice that depends on `dword_18001B8D0` is UNCERTAIN (Hex-Rays reused one register for the scan and the subscript). `ot_rewrite_vowels` implements only the branches that do not use that table.
4. Evaluation blanking, above.
5. `<...>` tags are scanned with quotes honored (`sub_180004288`). Unclosed tags return 107. `ALPHA VAL=...` is romaji (`sub_180001000`). `NUM VAL=...` and `NUMK VAL=...` are the number readers below, including `COUNTER`, `MODE`, and a decimal point.
6. Phoneme bytes become 4-byte diphone tokens (`sub_180003440`, `sub_1800034F0`, `sub_180002164`), then `sub_18000242C` writes frames and `sub_18000141C` renders them. That path is `ot_speak`.
7. Each sample (`sub_1800059B4`) is an 8000 Hz source-filter step: signed period table `ot_period` (4096 entries at `RVA 0x2AF90`, loaded with `movsx`) plus a signed pulse table `ot_pulse` (`RVA 0x2DB40`), then an 11-tap filter. The period product is divided by 128 with a sign-adjusting `sar` (`cdq`, `and edx, 7Fh`, add, `sar 7`), which is toward-zero division. Formants are turned into those taps by `sub_180001F00` and `sub_180001E20` (`ot_lattice`, `ot_formants_to_lpc`). Hex-Rays reordered the lattice's live `p`/`g`/`h` slots; `ot_lattice` follows the disassembly at `Open_Talk+0x1F00`. Slot duration is `13248 + sub_180003A1C`, and the pitch word is `0x3E8000 / duration`.
8. PCM is appended 16-bit little-endian (`sub_180002358`), growing the buffer in 32 KB steps from a 44-byte header. The header is RIFF/WAVE, PCM, 1 channel, 8000 Hz, 16-bit (`sub_180005F54`).

## Files

- `recovered/include/Open_Talk.h` — public API, same names and `__stdcall` prototypes as `lib64/Open_Talk.h`
- `recovered/include/ot_internal.h` — error codes and the calls that cross the API split
- `recovered/include/ot_text_int.h` — calls between the kana scan, the tag lexer, and the number readers
- `recovered/include/ot_synth.h` — diphone token, frame, and phrase-chunk types
- `recovered/include/ot_speak.h`, `ot_data.h`, `ot_frame_data.h`, `ot_dur_data.h` — internal table and synth declarations
- `recovered/include/ot_voice.h` — voice descriptor and the embedded voice registry
- `recovered/include/ot_f3.h` — f3-specific hooks
- `recovered/src/api/ot_api.c` — the six exports, UTF conversion, license marks, WAV entry
- `recovered/src/text/ot_kana.c` — dictionary scan, youon and vowel rewrite
- `recovered/src/text/ot_tag.c` — `<NUM>`, `<NUMK>`, `<ALPHA>` lexer, including decimals
- `recovered/src/text/ot_num.c` — `NUM` digit readings
- `recovered/src/text/ot_numk.c` — `NUMK` place-name readings
- `recovered/src/text/ot_counter.c` — `COUNTER`, `MODE`, rendaku, and irregular counters
- `recovered/src/audio/ot_audio.c` — PCM buffer, WAV header, lattice, and the sample filter
- `recovered/src/synth/ot_tokens.c` — phoneme bytes to diphone tokens, including `+`, `/`, and `?`
- `recovered/src/synth/ot_duration.c` — per-slot duration and the `+` join
- `recovered/src/synth/ot_expand.c` — frame expansion
- `recovered/src/synth/ot_speak.c` — phrase driver
- `recovered/src/data/` — dictionary/UTF tables (`ot_data.c`), phoneme names (`ot_frame_data.c`), duration tables, the per-voice raw dumps (`voice_<name>.c`) and the registry (`ot_voices.c`). Those tables are the only sources allowed to stay long.
- `recovered/src/f3/ot_f3.c` — f3 token adjustments (the f3 build is a different symbol vocabulary)
- `recovered/wasm/` — freestanding wasm32 build (runtime, exports, JS wrapper, demo)
- `recovered/tools/linux/` — native build, rawdump, corpus generator and parity harness
- `recovered/tools/ot_cmp.c` — compares reconstructed PCM with `Open_Talk_Synthe_Utf8` from `lib64/Open_Talk.dll`
- `recovered/decompiled/*.c` — Hex-Rays listing of each application function, one file per function

## Layout

The engine now targets the current Linux `aqtk1_lnx/lib64/*` builds.  Voice
tables are raw-dumped into C (no preset files): `voice_<name>.c` per voice,
`ot_voices.c` as the registry, `ot_f3.c` for the f3-specific token rules.

```
gcc -std=c11 -Wall -Wextra -Werror -O2 -Irecovered/include -c <each source>
```

Build and test with:

```
./recovered/tools/linux/build.sh     # native engine + parity tools
./recovered/tools/linux/run_bench.sh # 290-case suite vs aqtk1_lnx/lib64
./recovered/wasm/build.sh            # dist/aquestalk1.wasm (+ js/demo)
node recovered/wasm/verify.mjs       # wasm vs native
```

No logic source is 1000 lines or longer. The dumped voice tables and the
dictionary in `recovered/src/data/` are the long files.  See
`recovered/LINUX_PARITY.md` for the Ghidra findings and the current match
results.

## Function-by-function

Confidence is about the decompilation, not about the compilable file matching every sample. High means the listing is straight-line or the control flow is consistent. Medium means Hex-Rays reused registers or dropped a call argument. Low means the listing is incomplete or the compilable body is a stub.

| Address | Role | Confidence |
|---|---|---|
| `Open_Talk_Synthe` `0x180005C40` | Copy SJIS, synthesize, free the copy. Allocation failure sets `*pSize` to 101 | High |
| `Open_Talk_Synthe_Utf8` `0x180005CEC` | UTF-8 to SJIS, then the same path. Conversion failure is returned in `*pSize` | High |
| `Open_Talk_Synthe_Utf16` `0x180005D9C` | UTF-16 to SJIS, BOM optional | High |
| `Open_Talk_FreeWave` `0x180005F40` | `free` | High |
| `Open_Talk_SetDevKey` `0x180006094` | Decode and store the dev halfword | High |
| `Open_Talk_SetUsrKey` `0x1800060E0` | Decode, optional day window, store mark and raw key | High |
| `sub_180005F54` | 32 KB work buffer, clamp speed, build the WAV header. Failure 203 | High |
| `sub_18000141C` | Phrase loop: pauses of 666/2000/4000 units, frame class in the top 2 bits of the pitch word (40/200/240/280 units), trailing 256-sample pad, watermark bit | Medium. The bit index is UNCERTAIN |
| `sub_180003F3C` | Kana scan, youon map, vowel map, eval blanking, `<` tags | Medium. Tag body and the `dword_18001B8D0` branch are UNCERTAIN |
| `sub_1800017EC` | Dictionary search, 329 entries | High |
| `sub_180001000` | Romaji inside `ALPHA` tags: A-Z rows at `RVA 0x1B6D0` (12 bytes, two C strings), punctuation rows at `RVA 0x1B810` (21 x 8). Digit runs still call the number reader | High for letters and punctuation. Digits UNCERTAIN |
| `sub_180004704`, `sub_1800049F8`, `sub_180004B24`, `sub_180004F48`, `sub_180004CA0`, `sub_180005170`, `sub_18000521C`, `sub_1800052DC`, `sub_18000541C`, `sub_180005514`, `sub_1800055DC`, `sub_180005774` | Number, counter, and MODE reading used from the tag parser | High for the utterances below. Place classes above 4 digits are still the short-number path |
| `sub_180004288` | `<...>` property list, tokens split on space, `=>`, tab, and newline. `ALPHA`, `NUM`, and `NUMK` are wired | High |
| `sub_180004660` | Case-insensitive string table lookup | High |
| `sub_180001274` | Hex parse | High |
| `sub_1800012C8` | Key unscramble | High |
| `sub_180001348` | Byte-wise compare | High |
| `sub_180001380` | Tokenize on `" =>\t\n"` | High |
| `sub_1800018C0`, `sub_18000195C` | Vowel code maps | High |
| `sub_1800019F8` | Append bytes, cap 2047, else 200 | High |
| `sub_180001A40`, `sub_180001B2C` | Delete a phoneme byte; `sub_180001A40` drops the return value of the delete into an uninitialized local in the Hex-Rays text | Medium |
| `sub_180001B74`, `sub_180001C04` | Phoneme-parameter lookup by record kind | High |
| `sub_180001C38` | Find a 6-byte symbol record between `RVA 0x2AAA0` and `0x2AF86` | High |
| `sub_180001C78` | Emit a frame record of 6, 8, or 10 bytes. Overflow 204 | High |
| `sub_180001D74` | Interpolate 10 formant int16s, then call the LPC converter | High |
| `sub_180001E20` | Even/odd lattice, then 11 LPC int16s with a 4096 leading coefficient | High |
| `sub_180001F00` | Fixed-point lattice. The compilable body follows the disassembly, not the Hex-Rays slot order | High. Even and odd outputs matched a breakpoint dump |
| `sub_180002164` | Push a 4-byte phoneme token. Full list returns -1 (surfaced as 201) | High |
| `sub_1800021D8`, `sub_1800022C0`, `sub_1800022F8` | Chunk cursor. Marker byte `0xAB`. Cap 26624 | High |
| `sub_180002330` | Free the PCM buffer | High |
| `sub_180002358` | Append N identical int16 samples, grow by 32 KB | High |
| `sub_180002D64` | Two-byte scale `out = num * mul / den` | High |
| `sub_180002DC0` | Read one phrase, record pause units for codes 6..9 | Medium. A few call arguments are dropped |
| `sub_180003010`, `sub_180003290`, `sub_180003440`, `sub_1800034F0`, `sub_180003784`, `sub_1800037F0`, `sub_180003C68` | Expand chunks into diphone tokens. `sub_1800037F0` sets the scale (including `+` and `/`) and replaces the next chunk's first slot. `sub_180003C68` averages a `+` join. A final `?` adds 6400 to the closing duration | High. The sixteen sentences below match the DLL |
| `sub_180003A1C` | Per-slot duration delta added to 13248. Scale is `word_18002CF90[7 * high_nibble - 24 + low_nibble]`, then `* scale / 1024` | High for the path these utterances take. Alpha slots returned 6854 and 1640 under cdb |
| `sub_18000242C` | Diphone frame expander. Classes 1, 2, and 5 are implemented from the disassembly. Class 2 adds 4 to the next formant id only on the special arm. See the register map below | High. The utterances in the table below match the DLL sample for sample |
| `sub_1800059B4` | One-sample source filter | High. Table loads confirmed as `movsx`. Full PCM matches the DLL for the two utterances below |
| `sub_1800061B8` | UTF-8 to the internal 2-byte code | High |
| `DllMain` and everything from `0x1800062D0` | MSVC CRT and SEH | Not part of the synthesizer. Left as the binary |

## Expander registers

Hex-Rays left these uninitialized in `decompiled/18000242C_retry.c`. The second pass re-applied the SPD `-248` stack points in memory (the `.i64` was not saved) and mapped them from the disassembly. `rbp = entry_rsp - 0x5F`.

| Hex-Rays | Where it lives | What it is |
|---|---|---|
| `v20` | `r10` | Class 1 count, the byte at symbol record + 3. The `cmp r10b, 1` is this |
| `v21` | `r11`, `xor r11d, r11d` at `0x18000251D` | Constant 0. Class 1 passes it as the blend byte, and the special-case pitch is 0 |
| `v24` | `r10` copied to `ecx` and `[rbp-55h]` | Class 3 count, the divisor |
| `v39` | `r10` after `xor r10d, r10d` at `0x18000272B` | Class 2 loop index, starts at 0 |
| `v43` | leftover `rcx` at the `sub_180002D64` call `0x180002801` | Dead. `sub_180002D64` does not read its first argument |
| `v46` | same cleared `r10` | The other class 2 loop also starts at 0 |
| `v49` | `r10b` after `sub_180001B74` | Low byte of the current symbol's index-0 parameter |
| `v50` | `r11b` after the following `sub_180001B74` | Low byte of that symbol's last parameter |
| `v67` | leftover `rcx` at `0x180002BF5` | Dead first argument of `sub_180002D64` |
| `v69` | `r10` stored at `[rbp-55h]` | Class 5 count, the divisor at `0x180002CE2` |
| `v72` | leftover `rcx` at `0x180002CB5` | Dead first argument of `sub_180002D64` |

`ot_speak` walks those classes, writes 6/8/10-byte frames, and renders each frame for `40/200/240/280 * period / divisor` samples. The user-key mark seeds the phase (`state[1]`), and the watermark byte at state offset 32 inverts the noise only when it is set.

## What a test utterance does

The command in the layout section compiles the split sources. `recovered/tools/ot_cmp.c` loads `lib64/Open_Talk.dll` and compares every int16 after the 44-byte header. At speed 100:

| Input | Samples | Result |
|---|---|---|
| UTF-8 あ | 1636 | byte-identical to the DLL |
| `<ALPHA VAL=a>` | 2536 | byte-identical to the DLL |
| `<NUM VAL=2>` | 2296 | byte-identical to the DLL |
| `<ALPHA VAL=5>` | 2176 | byte-identical to the DLL |
| `<NUMK VAL=1>` | 3316 | byte-identical to the DLL |
| `<NUMK VAL=10>` | 3056 | byte-identical to the DLL |
| UTF-8 あ、あ | 5016 | byte-identical to the DLL |
| UTF-8 か | 2176 | byte-identical to the DLL |
| `<NUMK VAL=12>` | 4376 | byte-identical to the DLL |
| `<NUMK VAL=23>` | 6256 | byte-identical to the DLL |
| `<NUM VAL=23>` | 5016 | byte-identical to the DLL |
| `<NUMK VAL=1.5>` | 5676 | byte-identical to the DLL |
| `<NUMK VAL=12.34>` | 10616 | byte-identical to the DLL |
| `<NUMK VAL=1 COUNTER=にん>` | 4056 | byte-identical to the DLL |
| `<NUMK VAL=3 COUNTER=こ>` | 4436 | byte-identical to the DLL |
| `<NUMK VAL=3 COUNTER=こ MODE=TaO>` | 4436 | byte-identical to the DLL |

The old sample-3 mismatch (`-2393` vs `-2426`) was the lattice. Hex-Rays kept a stale `p` slot, so coefficients 2..4 and 6..8 were wrong while 0, 1, 5, 9, and 10 still matched, which is why only the first two samples agreed. A cdb breakpoint on `Open_Talk+0x1F00` dumped even-lattice output `01000000 febfb400 01e60a28 fed60a0c 0119faf8 ff9ff678`; the disassembly translation matches that and the odd call.

`<ALPHA VAL=a>` then mismatched at sample 26 (recovered 382, DLL 493) because the first slot's pitch was 309 instead of 203. `sub_180003A1C` returns 6854 for that slot; `13248 + 6854 = 20102`, and `0x3E8000 / 20102 = 203`. The pulse is `state[4] += 8` until it reaches the pitch, and it is applied on the following sample, so pitch 203 first changes sample 26.

## Closed in this pass

Numbers. `sub_180004704` / `sub_1800049F8` / `sub_180004B24` read `<NUM VAL=...>` and a digit run inside romaji. Digit tables are `byte_18002EEC8`, `byte_18002DFF8`, and `byte_18002E020`; a '.' inserts `byte_18002EF54` (`1a 9f 05`) and a '-' inserts pause 7. Proof: `<NUM VAL=2>` (2296 samples) and `<ALPHA VAL=5>` (2176). cdb on `Open_Talk+0x2DC0` showed `<NUM VAL=23>` phonemes `20 a1 14 01 9f`, the same bytes this reader emits after the evaluation blank.

NUMK without `MODE`, `COUNTER`, or a decimal point is `sub_1800047D0` → `sub_180004F48` → `sub_180004CA0`. Names live at RVA `0x2EBC0` (16 bytes per digit and place, accent dword at +12) and `sub_1800052DC` maps each pair through the symbol table. Tens digit 1, 5, 6, or 8 with a non-zero ones digit then runs `sub_180001A40`. Proof: `<NUMK VAL=1>` (3316) and `<NUMK VAL=10>` (3056). `MODE`, `COUNTER`, and a decimal point are the next section.

Pauses. A byte 6, 7, 8, or 9 ends the phrase. Following bytes `<= 9` add 666 / 2000 / 4000 units and are not spoken. Silence is the 32-bit product `period * units / 256`, appended only when more phonemes remain. The last of those bytes is the next phrase's prosody nibble (the reader starts at 8). Proof: UTF-8 あ、あ, phonemes `0a 07 0a`, 5016 samples. The 2000-unit pause sits between the two phrases; the 256-sample tail still replaces a trailing pause.

Vowels. `Open_Talk+0x40F6` rewrites codes 179..195. Map B (`sub_18000195C`) when `(prev+94) <= 16`, when the next byte is 6 or 7, when the next byte is 8 or 9 and either run counter is zero, or when `dword_18001B8D0[24 * key]` is zero. The scan skips bytes `<= 9`. `prev` becomes the mapped byte. Proof: UTF-8 か (code 179, next byte 0, table entry 0, map B → 16), 2176 samples. あ and `<ALPHA VAL=a>` do not enter this branch.

## Closed: longer numbers

Two instructions after the token list. cdb on `Open_Talk.dll` (existing IDB, not saved).

Class 2 formant id, `sub_18000242C`. The `+ 4` on the next symbol's index runs only when the token is special and the next class is 1: `'+'` with `(b - 'b') <= 15` and bit `0x8221`, or `",k"`. The other arm stores the index as written. Recovered code added 4 on every class-2 token whose next symbol was class 1. For `<NUMK VAL=12>` the token `"+n"` is not special (`'n' - 'b' = 12`, and bit 12 of `0x8221` is clear), so the next id is `"nu"` at 319 (`0x13F`), not 323 (`0x143`). First differing frame byte was offset 280: `01 00 13 3b df 80 43 01` versus `01 00 13 3b df 80 3f 01`. After the fix, `<NUMK VAL=12>` (4376 samples) and `<NUM VAL=23>` (5016) match the DLL.

Cross-chunk duration, `sub_1800037F0`. A breakpoint at `Open_Talk+0x3A1C` for `<NUMK VAL=23>` logged `slot 3, count 3, word4 1, scale 1665, nibble 0x84, a4 0` after the three slots of the first chunk, then the second chunk skipped slot 0. That call's result, plus 13248, is written into the next chunk's first slot unless the next chunk is exactly count 2 and word4 1, or the previous low nibble is 5 and the next word4 is 1. The symbol is `"sa"`. The DLL duration at `Open_Talk+0x2164` is 17482 (pitch `0xEA`); the per-slot formula had produced 15163 (pitch `0x10E`), and `sub_180003290` then filled the neighboring zero-duration pitches from that. `<NUMK VAL=23>` is 6256 samples and matches the DLL. The eight utterances above still match.

## Closed: MODE, COUNTER, and decimal NUMK

`sub_180004288` reads three properties. Keys are matched by `sub_180004660` (`VAL` is the string at RVA `0x1B8B8`). The value may be quoted. Order of the properties does not matter.

```
<NUMK VAL=<digits>[.<digits>] [COUNTER=<kana>] [MODE=<Abc>]>
```

`MODE` is three letters: first `A`..`T`, second `a`..`p`, third `A`..`P` (`sub_18000541C`). It is used only when `COUNTER` is present. Without `MODE`, the 27 records at RVA `0x2E070` supply the same three numbers for a known counter. `COUNTER` is dictionary text (UTF-8 in `Open_Talk_Synthe_Utf8`, SJIS after the conversion). `sub_180005170` turns each hit into a two-letter symbol (`g`/`G` become `v`/`V`). `sub_180005514` then applies rendaku from `byte_18002EE60`, and `sub_1800055DC` picks the accent from `byte_18002EAF0`. The counter is spoken on that accent after the last digit (`sub_18000521C`). Earlier digits of the same window stay on the plain name table.

`sub_180005774` replaces the whole reading when `MODE` is absent and the counter is SJIS にん (`RVA 0x30128`, values 1 and 2) or にち (`RVA 0x30138`, values 1..10, 14, 20, and 24). にち strips leading zeros first.

A `.` in `VAL` is not a user `MODE`. `sub_180004288` nulls the dot, speaks the integer with the fixed counter at RVA `0x300FC` (てん) and `MODE` `TaO` (RVA `0x30104`), appends phoneme 5, then speaks the fraction with `sub_180004704` (the `NUM` reader). A user `COUNTER` on a decimal is appended after that as raw dictionary codes. An empty integer (`VAL=.5`) uses `0000` for the てん half.

Proof, all byte-identical at speed 100: `<NUMK VAL=1.5>` (5676), `<NUMK VAL=12.34>` (10616), `<NUMK VAL=1 COUNTER=にん>` (4056), `<NUMK VAL=3 COUNTER=こ>` (4436), `<NUMK VAL=3 COUNTER=こ MODE=TaO>` (4436). The eleven utterances above still match. Values longer than four integer digits are still rejected, as before this pass.

## Sentence check

`recovered/tools/ot_cmp.c` speaks these sixteen UTF-8 sentences with `Open_Talk_Synthe_Utf8` at speed 100 and compares every int16 with `lib64/Open_Talk.dll`. After the pitch-contour fix below, all sixteen match. The sixteen regression utterances listed above stayed byte-identical.

| # | Result | Samples |
|---|---|---|
| 1 | identical | 39396 |
| 2 | identical | 29616 |
| 3 | identical | 32236 |
| 4 | identical | 15996 |
| 5 | identical | 18476 |
| 6 | identical | 18716 |
| 7 | identical | 41856 |
| 8 | identical | 32216 |
| 9 | identical | 30896 |
| 10 | identical | 8176 |
| 11 | identical | 5416 |
| 12 | identical | 14336 |
| 13 | identical | 20636 |
| 14 | identical | 18156 |
| 15 | identical | 60876 |
| 16 | identical | 24156 |

## Closed: pitch contour of ' + / ?

Dictionary bytes: `'` is phoneme 1 (accent, sets the chunk's word at +4), `+` is phoneme 3, `/` is phoneme 4, `;` is phoneme 5, `?` is phoneme 9. Pitch on a diphone token is `0x3E8000 / duration` at `sub_180002164`. A breakpoint there (`Open_Talk+0x2164`) dumped every token duration for the four excerpts. The first token of `え'らー+はっせー。` was the first miss: DLL duration 20348 (pitch 201) against recovered 22259 (pitch 184).

`+`, `sub_1800037F0` and `sub_180003C68`. A chunk whose low nibble is 3 does not look up its scale with that nibble. `sub_1800022F8` walks forward and uses the next chunk whose low nibble is not 3 (or 8 if none). The following chunk keeps that same scale when its high nibble is 3. `sub_180003C68` then builds one joined phrase (accent index stays on the left chunk when that index is nonzero; otherwise it is the left count plus the right accent index). Slots from index 2 are timed again on the join, and each stored duration is the average of the separate timing and the joined timing. After that, the four excerpts and sentences 2, 3, 5, 7, and 15 match.

`?`, end of `sub_180003010`. The closing transition duration is 0 unless the last chunk's low nibble is 9 and the last slot duration is nonzero, in which case the duration is that slot plus 6400 (`0x1900`). Disassembled with `cdb -z` at `Open_Talk+0x3229`. Sentences 10 and 11 match after this. A period (nibble 8) still passes duration 0, so the earlier identical sentences are unchanged.

`/`, same scale walk in `sub_1800037F0`. When the previous chunk's accent index is 0 and this chunk's high nibble is 4, a scale below eight tenths of the previous scale is raised to that eight-tenths value. The scale is also left unchanged when the previous low nibble is 4, this high nibble is 4, the previous accent index is 0, and this accent index is 1. Sentences 8, 12, and 16 match after this. Sentence 6 already matched; its chunk before `/` has a nonzero accent index, so neither rule applies.

WAV pairs for the ten sentences that used to drift are in `recovered/wav/diff/`. Both sides are now the same buffer.

## Safety

The DLL is a kana-to-WAV synthesizer with a license-mark check. It is not a loader, exploit, or credential stealer. No safety stop.

## Voice presets

The OTPR preset loader is gone.  `recovered/tools/linux/rawdump.py` dumps the
tables out of each `libAquesTalk.so` into `recovered/src/data/voice_<name>.c`;
`Open_Talk_SelectVoice("f2")` selects one at runtime.  See LINUX_PARITY.md.
