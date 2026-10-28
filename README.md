# AquesTalk2 → WebAssembly

把 `libAquesTalk2Eva.so.2.3`（AquesTalk2 规则语音合成引擎，x86-64 ELF）移植到
WebAssembly。**不是模拟器**：用 Ghidra 把机器码还原成 C，再由 clang 编译成原生代码和
wasm；运行时没有任何 x86 解释器、JIT 或二进制翻译。

- 引擎：200 个函数，全部为重新编译的 C 代码（`port/src/decomp.c`）
- 数据：原库的 `.rodata`/`.data` 按原始虚拟地址镜像到 `aq_image`，并重放 85 个
  `R_X86_64_RELATIVE` + 7 个符号重定位（`port/src/image.c`）
- 接口：C++ + embind（`port/src/api.cpp`），另有与原始 `.so` 完全相同的 C ABI
- 产物：`dist/aquestalk2.js` + `dist/aquestalk2.wasm`（约 32 KB + 91 KB），附带浏览器 demo

## 验证结果

| 测试 | 结果 |
| --- | --- |
| 原生移植 vs 原始 `.so`（18 文本 × 4 编码 × 6 语速 = 432，外加声质/罗马字） | **512/512 逐字节一致** |
| wasm 移植 vs 原始 `.so`（同一矩阵） | **512/512 逐字节一致** |
| SHA-256 回归（`port/tests/expected.json`，130 例，无需原库即可跑） | **原生 130/130，wasm 130/130** |
| 400 字长文本（1.3 MB WAV） | 三方一致 |
| 连续 300 次合成（不同文本/语速） | 无崩溃、无泄漏、结果确定 |

## 快速开始

### 浏览器 demo

```bash
# 任意静态服务器都可以；wasm 需要正确的 application/wasm MIME
cd dist && python3 -m http.server 8000
# 打开 http://localhost:8000/
```

demo 支持 18 种声质（内建默认 + `phont/` 里的 17 个文件）、50–300% 语速、
波形显示、WAV 下载。

### JavaScript / embind

```js
import createModule from './dist/aquestalk2.js';

const aq = await createModule();

// UTF-8 假名记号列 → WAV (Uint8Array)；失败返回 null
const wav = aq.synthe('こんにちは、せかい。', 100);
if (!wav) console.error('error code', aq.lastError());

// 指定声质文件（Uint8Array）
const phont = new Uint8Array(await (await fetch('./phont/aq_rm.phont')).arrayBuffer());
const wav2 = aq.syntheWithPhont('おはようございます', 100, phont);

// 其它编码
aq.syntheSjis(sjisBytes, 100, null);
aq.syntheEuc(eucBytes, 100, null);
aq.syntheUtf16(uint16Array, 100, null);   // 主机序（wasm 为小端）
aq.syntheRoman('konnichiwa', 100, null);
aq.lastError();                            // 最近一次失败的 AquesTalk 错误码
aq.SAMPLE_RATE;                            // 8000
```

`wav` 是完整的 RIFF/WAVE 文件：8000 Hz、单声道、16 bit PCM。

### C ABI

`port/src/api.cpp` 保留了与 `aqtk2-lnx/lib64/AquesTalk2.h` 完全相同的 C ABI
（`AquesTalk2_Synthe`、`_Euc`、`_Utf8`、`_Utf16`、`_Roman`、`AquesTalk2_FreeWave`），
原生构建可直接链接。wasm 里这些函数也以 `_AquesTalk2_Synthe_Utf8` 等名字导出，
配合 emscripten 的 `ccall`/`cwrap`（已导出）即可直接调用；完整示例见
`port/tools/ccall_example.mjs`。

## 构建

需要 [emsdk](https://emscripten.org)（`emcc`/`em++` 在 PATH 中，或设置 `EMSDK`）。

```bash
./port/build-wasm.sh     # → dist/aquestalk2.js + dist/aquestalk2.wasm + demo
./port/build-native.sh   # → port/build-native/aqtest（用于和原库对拍）
```

重新生成反编译源码（需要 Ghidra）：

```bash
# 1. Ghidra headless 分析原库并导出 C（脚本在 scripts/）
analyzeHeadless ghidra-proj AqTk2 -import aqtk2-lnx/lib64/libAquesTalk2Eva.so.2.3 \
  -scriptPath scripts -postScript DumpDecomp.java decomp \
  -postScript DumpData.java decomp/data.tsv
# 2. 机械生成 decomp.c / image.c
./port/gen.sh
```

## 验证

```bash
# 构建原始库对拍工具（dlopen 原 .so）
./port/tools/build-ref.sh

# 逐字节对比（需要原 .so），加 --wasm 测 wasm
python3 port/tools/verify.py
python3 port/tools/verify.py --wasm

# 只跑已记录的 SHA-256 回归（不需要原 .so）
python3 port/tools/check_expected.py
python3 port/tools/check_expected.py --wasm
```

## 目录

```
aqtk2-lnx/            原始 SDK（库、头文件、phont、手册）
decomp/               Ghidra 导出的反编译结果（all.c / data.tsv / 每函数 .c）
scripts/              Ghidra 导出脚本
port/
  src/decomp.c        机械还原的 200 个函数（生成物）
  src/image.c         .rodata/.data 镜像 + 重定位表（生成物）
  src/shim.[ch]       固定宽度类型、数据镜像加载
  src/api.cpp         原始 C ABI 包装 + embind
  tools/              生成器、对拍/回归脚本、参考实现 driver
  tests/              测试语料与 SHA-256 期望值
  web/                demo 源码（构建时复制进 dist/）
dist/                 可直接部署的 wasm + demo
```

## 实现要点

1. **反编译**：Ghidra 在 `.text` 中找到 210 个函数；去掉 3 个启动函数、
   6 个公开 API 包装、1 个 `.fini_array` 遍历函数，以及 `.init/.plt/.fini/.data`
   中的 13 个条目后，剩余 200 个函数被机械翻译为 C，覆盖 `.text` 的
   46 628 字节；其余为这 10 个被替代的函数与对齐填充。
2. **只重编译代码，不重定位代码**：`decomp.c` 里是真正的控制流和算术，不是
   `switch(pc)` 之类的解释循环。
3. **数据镜像**：原 ELF 的两段 `PT_LOAD` 虚拟地址分别是 `0` 和 `0x216670`，第二段
   的文件偏移与虚拟地址不同，因此按 VMA 重建 `aq_image[0x217038]`，只嵌入
   `.rodata`（27 884 B，含内建 phont）和可写数据段（2 488 B）。
4. **指针宽度**：原库是 LP64。wasm32 上 C 指针只有 4 字节，所以代码中的 8 字节
   指针槽一律按 8 字节读写（高 32 位保持 0），表步长与 x86-64 完全一致。
5. **类型归一化**：Ghidra 的 `undefinedN` → `uintN_t`，`long` → `int64_t`（原库
   LP64），`._0_4_` 部分写 → 定宽指针写回；少量被 Ghidra 误判为 `void` 的尾调用
   包装函数按机器码补回返回值（见 `port/README.md`）。

## 关于这个二进制

- 本仓库的 `libAquesTalk2Eva.so.2.3` 与同目录的 `.bak` **只差 2 个字节**
  （文件偏移 `0x4ef4`：`76 06` → `eb 28`）。该补丁让一段「ナ行/マ行 → ヌ」的
  映射代码不可达；用 `.bak` 合成 `な`/`ぬ`/`ま`/`む` 得到的波形完全相同，
  而当前 `.so` 会正常区分。也就是说，提供的 `.so` 是解除评价版限制后的版本，
  移植结果严格复现它的行为。
- Ghidra 按这份二进制的实际控制流分析，那段被跳过的代码在 `decomp.c` 中自然不存在。
- 输出格式固定为 8 kHz / 16 bit / 单声道 WAV；输入只支持假名与 AquesTalk
  记号（汉字需要另外的 AqKanji2Koe 库）。

## 许可证

AquesTalk2 是株式会社アクエスト（AQUEST Corp.）的商用软件，本仓库中的
二进制、phont 文件及其派生的反编译代码均受其许可约束。仓库只用于技术验证/
互操作性研究；运行或分发合成引擎需要向アクエスト取得相应许可。详见
`aqtk2-lnx/aqtk2_lnx_eva_lic.pdf` 与 `NOTICE.md`。
