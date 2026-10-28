# NOTICE

This repository contains a research port of **AquesTalk2** (`libAquesTalk2Eva.so.2.3`),
a proprietary speech synthesis library by AQUEST Corp. (株式会社アクエスト).

* `aqtk2-lnx/` is the unmodified AquesTalk2 Linux SDK evaluation package.
  Its use is governed by `aqtk2-lnx/aqtk2_lnx_eva_lic.pdf`.
* `decomp/` and `port/src/decomp.c` are derived from the machine code of that
  library by decompilation. They are not original work and carry the same
  licensing restrictions as the binary.
* `port/src/{shim,api}.cpp`, `port/tools/`, `port/web/` and the build scripts are
  the porting glue written for this project.
* The `phont/` voice data is part of the SDK and is likewise proprietary.

No license to AquesTalk2 is granted here. Running, distributing or commercially
using the synthesised voice requires an appropriate license from AQUEST Corp.
The port is intended for interoperability research and technical evaluation on
hardware/OS combinations for which no official build exists.
