# NOTICE

This repository is a technical interoperability study. It is **not** an official
AQUEST product and grants no license to any AQUEST software.

## Proprietary components

The following components are proprietary software of AQUEST Corp.
(株式会社アクエスト) and are subject to the license terms shipped with their
SDKs:

| component | original binary | SDK / license |
| --- | --- | --- |
| AquesTalk1 | `aqtk1_lnx/lib64/*/libAquesTalk.so` | `engines/aquestalk1/aqtk1_lnx/` |
| AquesTalk2 | `libAquesTalk2Eva.so.2.3` | `engines/aquestalk2/aqtk2-lnx/` (`aqtk2_lnx_eva_lic.pdf`) |
| AquesTalk10 | `libAquesTalk10.so.1.1` | `engines/aquestalk10/aqtk10_lnx/` |
| AqKanji2Koe | `libAqKanji2Koe.so.4.1` | `engines/aqk2k/aqk2k_lnx/` |

The `.so` files, the phont data, the AqKanji2Koe dictionaries (including the
generated `lookup.bin`), and the code under each project's `decomp/` and
`port/src/decomp.c` are derived from or are part of those products. They carry
the same restrictions as the original binaries.

`aqk2k_lnx/aq_dic/aqdic.bin` and `aqk2k_lnx/aq_dic/lookup.bin` are **not**
distributed in this repository. You need your own licensed SDK copy to use the
AqKanji2Koe tab.

## Evaluation builds

AquesTalk1, AquesTalk10 and AqKanji2Koe are built from the evaluation version
of their SDKs; the evaluation restriction (ナ行/マ行 become ヌ) is reproduced
faithfully. AquesTalk2's supplied `libAquesTalk2Eva.so.2.3` differs from its
`.bak` by two bytes that make the na/ma→nu mapping unreachable, so the
AquesTalk2 port distinguishes those kana; see
`engines/aquestalk2/README.md`. The license-key entry points
(`AquesTalk_SetDevKey`, `AquesTalk_SetUsrKey`, `AqKanji2Koe_SetDevKey`) are
ported as-is; no key is generated, bypassed or embedded.

## Port glue

The WebAssembly builds, the Ghidra scripts, the JS wrappers and the unified
demo (`demo/`, `tests/`, `scripts/`) were written for this study. They are
provided for research and evaluation only; no license to the underlying
AQUEST engines is implied. Running or distributing synthesized voices requires
an appropriate license from AQUEST Corp.

## Third-party credits

AqKanji2Koe uses MARISA and NAIST Japanese Dictionary; see
`engines/aqk2k/aqk2k_lnx/aq_dic/CREDITS`. AquesTalk1's recovered code copies the
MIT notice from `engines/aquestalk1/lib64/LICENSE`.
