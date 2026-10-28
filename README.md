# AquesTalk2 → WebAssembly

把 `libAquesTalk2Eva.so.2.3`（AquesTalk2 规则语音合成引擎，x86-64 ELF）移植到
WebAssembly。**不是模拟器**：用 Ghidra 把机器码还原成 C，再由 LLVM 直接编译成
wasm；运行时没有任何 x86 解释器、JIT 或二进制翻译。

当前版本是**裸 wasm**：`clang --target=wasm32` + `wasm-ld`，`-nostdlib`，**没有
Emscripten、没有 embind、没有 libc，模块 imports 为 0**。JS 侧只有一个约 5 KB 的
手写封装负责传字符串/取 WAV 字节。

- 引擎：200 个函数，全部为重新编译的 C 代码（`port/src/decomp.c`）
- 数据：原库 `.rodata`/`.data` 按原始虚拟地址镜像到 `aq_image`，重放 85 个
  `R_X86_64_RELATIVE` + 7 个符号重定位（`port/src/image.c`）
- 运行时：`port/src/runtime.c` 自带 `memcpy/memset/memmove` 和边界标记分配器
- 接口：原始 C ABI（`AquesTalk2_Synthe*` / `FreeWave`）+ `aq_malloc`/`aq_free`/
  `aq_last_error`，全部直接导出为 wasm 函数
- 产物：`dist/aquestalk2-core.wasm`（79 KB，0 imports）+ `dist/aquestalk2.js`
  （手写封装），附带浏览器 demo

## 验证结果

| 测试 | 结果 |
| --- | --- |
| 原生移植 vs 原始 `.so`（18 文本 × 4 编码 × 6 语速 = 432，外加声质/罗马字） | **512/512 逐字节一致** |
| wasm（裸模块）vs 原始 `.so`（同一矩阵） | **512/512 逐字节一致** |
| SHA-256 回归（`port/tests/expected.json`，130 例，无需原库即可跑） | **原生 130/130，wasm 130/130** |
| 400 字长文本 → 1.3 MB WAV | 与原始 `.so` 逐字节一致 |
| 分配器 fuzz（20 000 次随机 malloc/free、越界/踩内存检查） | 通过，内存不增长 |
| 同一实例连续 400 次合成（不同文本/语速） | 无崩溃、结果确定、内存稳定 |

## 快速开始

### 浏览器 demo

```bash
./port/tools/serve.sh 8000     # 等价于 cd dist && python3 -m http.server
# 打开 http://localhost:8000/
```

demo 支持 18 种声质（内建默认 + `phont/` 里的 17 个文件）、50–300% 语速、
波形显示、WAV 下载。

### JavaScript

```js
import { createAquesTalk2 } from './dist/aquestalk2.js';

const aq = await createAquesTalk2();          // 默认加载同目录 aquestalk2-core.wasm

const wav = aq.synthe('こんにちは、せかい。', 100);   // Uint8Array 或 null
if (!wav) console.error('error code', aq.lastError());

// 指定声质文件
const phont = new Uint8Array(await (await fetch('./phont/aq_rm.phont')).arrayBuffer());
const wav2 = aq.syntheWithPhont('おはようございます', 100, phont);

// 其它编码
aq.syntheSjis(sjisBytes, 100, null);
aq.syntheEuc(eucBytes, 100, null);
aq.syntheRoman('konnichiwa', 100, null);
aq.syntheUtf16(uint16Array, 100, null);   // UTF-16 码元，wasm 为小端

aq.SAMPLE_RATE;   // 8000
```

`createAquesTalk2(source)` 也接受 `WebAssembly.Module`、`ArrayBuffer` 或
`Uint8Array`，便于离线/打包场景。返回值失败时为 `null`，错误码通过
`lastError()` 获取。

### C ABI / 裸 wasm 导出

wasm 导出（无 imports，全部是普通 C 函数）：

```
AquesTalk2_Synthe            AquesTalk2_Synthe_Euc
AquesTalk2_Synthe_Utf8       AquesTalk2_Synthe_Utf16
AquesTalk2_Synthe_Roman      AquesTalk2_FreeWave
aq_malloc  aq_free  aq_last_error  aq_sample_rate  aq_image_base
memory
```

签名与 `aqtk2-lnx/lib64/AquesTalk2.h` 一致；可以从任何支持 WebAssembly 的宿主
（Node、Rust/wasmtime、C++/wasmtime、浏览器）直接调用。原生构建同样保留这些
符号，可直接链接。

内存模型：宿主用 `aq_malloc` 分配、写字符串、调用合成函数，读 `*pSize` 后拷贝
WAV，再调用 `AquesTalk2_FreeWave` / `aq_free`。示例见
[port/tools/example.mjs](port/tools/example.mjs)。

## 构建

只需要带 wasm32 目标的 LLVM（clang + wasm-ld），**不需要 Emscripten**：

```bash
./port/build-wasm.sh        # → dist/aquestalk2-core.wasm + demo
./port/build-native.sh      # → port/build-native/aqtest（与原库对拍）
```

可用环境变量：`CLANG`、`CFLAGS`、`INITIAL_MEMORY`（默认 8 MB）、`MAX_MEMORY`
（512 MB）、`STACK_SIZE`（512 KB）。

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

# 分配器 fuzz + 400 次连续合成
node port/tools/stress_test.mjs
```

## 目录

```
aqtk2-lnx/            原始 SDK（库、头文件、phont、手册）
decomp/               Ghidra 导出的反编译结果（all.c / data.tsv / functions.tsv）
scripts/              Ghidra 导出脚本
port/
  src/decomp.c        机械还原的 200 个函数（生成物）
  src/image.c         .rodata/.data 镜像 + 重定位表（生成物）
  src/shim.[ch]       固定宽度类型、数据镜像加载
  src/runtime.c       无 libc 运行时：mem*、malloc/free
  src/wasm_api.c      原始 C ABI + aq_malloc/aq_free/aq_last_error
  web/                demo + 手写 JS 封装 aquestalk2.js（构建时复制进 dist/）
  tools/              生成器、对拍/回归/压力脚本、参考实现 driver
  tests/              测试语料与 SHA-256 期望值
dist/                 可直接部署的 wasm + JS 封装 + demo
```

## 实现要点

1. **反编译**：Ghidra 在 `.text` 中找到 210 个函数；去掉 3 个启动函数、
   6 个公开 API 包装、1 个 `.fini_array` 遍历函数，以及 `.init/.plt/.fini/.data`
   中的 13 个条目后，剩余 200 个函数被机械翻译为 C，覆盖 `.text` 的
   46 628 字节。
2. **只重编译代码**：`decomp.c` 里是真正的控制流和算术，没有 x86 解释循环。
3. **数据镜像**：原 ELF 的两段 `PT_LOAD` 虚拟地址是 `0` 和 `0x216670`，第二段
   文件偏移与虚拟地址不同，因此按 VMA 重建 `aq_image[0x217038]`，只嵌入
   `.rodata`（27 884 B，含内建 phont）和可写数据段（2 488 B）。
4. **指针宽度**：原库是 LP64。wasm32 上 C 指针只有 4 字节，所以代码中的 8 字节
   指针槽一律按 8 字节读写（高 32 位保持 0），表步长与 x86-64 一致。原生与 wasm
   的 512 例逐字节一致就是这条路径正确性的证明。
5. **无 libc 运行时**：`-nostdlib` 下由 `runtime.c` 提供 `memcpy/memset/memmove`；
   `malloc` 是带边界标记和合并的 first-fit 分配器，堆从链接器给出的
   `__heap_base` 向上生长，按 64 KB 页调用 `memory.grow`，释放顶部块时回退 brk。
   分配器经过 20 000 次随机 malloc/free 的模式校验 fuzz。
6. **JS 封装**：`createAquesTalk2()` 只做 `WebAssembly.instantiate(bytes, {})`
   （零 imports），随后是字符串编码、内存读写和 WAV 拷贝，没有任何 JS 运行时依赖。

### 与上一版（embind）的关系

仓库的第一个提交 `ffd5303` 是 Emscripten + embind 版本（`dist/aquestalk2.js` +
`aquestalk2.wasm`，约 32 KB + 91 KB，运行时带 emscripten JS 胶水）。当前版本用
LLVM 直接产出裸 wasm 并移除了 embind，模块更小、零 imports、可在任意 wasm 宿主
中加载。旧的 C++ 绑定层已删除，只保留在 git 历史中。

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
