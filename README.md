# AquesTalk WebAssembly monorepo

把 AQUEST 的四个语音组件收进一个仓库，并提供一个统一的浏览器 demo：

| 组件 | 作用 | 产物 | 声质 | 采样率 |
| --- | --- | --- | --- | --- |
| **AquesTalk1** | 规则语音合成 | `aquestalk1.wasm` (811 KB) | 9 个内置声库 | 8 kHz |
| **AquesTalk2** | 规则语音合成 | `aquestalk2-core.wasm` (79 KB) | 18 个 phont | 8 kHz |
| **AquesTalk10** | 规则语音合成 | `aqtk10.wasm` (362 KB) | 7 个预设 + 7 个参数 | 16 kHz（随 `fsc` 变化） |
| **AqKanji2Koe** | 汉字假名混合文 → 假名/罗马字 | `aqk2k32.wasm` (230 KB) | — | — |

四个模块都是从 x86-64 机器码经 Ghidra 反编译成 C，再由
`clang --target=wasm32` + `wasm-ld` 重新编译的 **裸 wasm**：没有 Emscripten、
没有 embind、没有 libc、**imports 为 0**。统一 demo 只是字符串编解码、内存读写和
WAV 拷贝，不包含任何 x86 解释器或二进制翻译。

![unified demo](docs/demo.png)

## 快速开始

```bash
cd aquestalk-wasm
./scripts/serve.sh
# 浏览器打开 http://127.0.0.1:8000/demo/
```

`serve.sh` 必须在仓库根目录起服务，因为 demo 直接引用
`engines/<engine>/...` 下的 wasm、phont 和词典。也可以：

```bash
python3 -m http.server 8000
```

> 不要用 `file://` 直接打开：ES module 和 `fetch()` 都需要 HTTP。

### AqKanji2Koe 词典

`aqdic.bin`（9.8 MB）和 `lookup.bin`（5.2 MB）是 AQUEST 的授权数据，**不提交到
git**。本机工作区里已经有了；如果没有，把 `aqdic.bin` 放到：

```
engines/aqk2k/aqk2k_lnx/aq_dic/aqdic.bin
```

然后生成查找表（需要 `engines/aqk2k/bakak2k` 这个第三方 checkout）：

```bash
cd engines/aqk2k
node port/tools/gen_lookup.mjs \
  aqk2k_lnx/aq_dic/aqdic.bin \
  aqk2k_lnx/aq_dic/lookup.bin
```

缺词典时 demo 仍可正常使用 AquesTalk1/2/10，AqKanji2Koe 标签会显示“辞書なし”。

## 统一 demo

`demo/` 以 AquesTalk2 的 demo 为底（声质选择、50–300% 话速、波形、WAV 下载），
加上引擎切换和 AqKanji2Koe 文本前端：

- **AquesTalk1**：9 个内置声库（f1/f2/m1/m2/r1/imd1/jgr/dvd/f3）。
- **AquesTalk2**：18 个 phont，内置默认 + `phont/` 文件。
- **AquesTalk10**：F1/F2/F3/M1/M2/R1/R2 预设，`<details>` 里可调
  `bas / vol / pit / acc / lmd / fsc`；话速滑块覆盖 `spd`。
- **AqKanji2Koe**：汉字假名混合文 → 假名（带アクセント记号）或罗马字；
  可一键用 AquesTalk2 播放。
- **流水线**：在任意合成标签勾选“AqKanji2Koe で変換”，输入汉字文本会先转成
  假名再合成，转换结果显示在“読み”栏。
- 合成失败时显示引擎名和原始错误码；波形、时长、采样率、合成耗时都会显示。
- 所有引擎按需加载；AqKanji2Koe 词典只在第一次用到时拉取（约 15 MB）。

demo 的入口是 `demo/index.html`，适配器在 `demo/engines.js`，UI 在
`demo/app.js`。

## 目录

```
aquestalk-wasm/
├── engines/
│   ├── aquestalk1/      # 原始 SDK、反编译、wasm 源、dist、原 demo
│   ├── aquestalk2/      # 同上（统一 demo 的 UI 基础）
│   ├── aquestalk10/     # 同上
│   └── aqk2k/           # AqKanji2Koe 源、wasm32 构建、词典目录
├── demo/                # 统一前端 demo
│   ├── index.html
│   ├── style.css
│   ├── app.js
│   └── engines.js       # 四个引擎的统一适配层
├── scripts/
│   ├── serve.sh
│   └── test.sh
├── tests/
│   ├── smoke.mjs        # Node 冒烟测试（无浏览器）
│   └── browser.mjs      # 可选 Playwright 测试
├── package.json
├── NOTICE.md
└── README.md
```

每个 `engines/<name>/` 保留原来的目录结构、README、NOTICE、SDK 和 git 历史，
原有 demo 仍然可以在各自目录下单独运行。

## 测试

```bash
npm test            # 等价于 ./scripts/test.sh
```

`tests/smoke.mjs` 自带一个临时 HTTP 服务，依次验证：

- AquesTalk1 f1/f3、AquesTalk2 内置 phont 和 `aq_rm.phont`、AquesTalk10 F1/F3；
- 每个 WAV 的 RIFF/WAVE 头、采样率、时长；
- AqKanji2Koe 假名转换、罗马字转换、连续 40 次转换（覆盖 arena 重建）；
- AqKanji2Koe → AquesTalk2 的完整流水线。

可选的真实浏览器测试：

```bash
npm install --no-save playwright
PLAYWRIGHT_BROWSERS_PATH="$PWD/.playwright-browsers" \
  ./node_modules/.bin/playwright install chromium

./scripts/serve.sh &
node tests/browser.mjs http://127.0.0.1:8000/demo/
```

它会点击四个标签、合成、转换、勾选流水线，并把截图写到 `.test-artifacts/`。

## 各自构建

已构建的 wasm 已提交，直接跑 demo 不需要编译。重新构建时只需要带 wasm32 目标的
LLVM（clang + wasm-ld），不需要 Emscripten：

```bash
cd engines/aquestalk1 && ./recovered/wasm/build.sh
cd engines/aquestalk2 && ./port/build-wasm.sh
cd engines/aquestalk10 && ./port/build-wasm.sh
cd engines/aqk2k && ./port/build_wasm32.sh
```

更细的生成/对拍步骤见各子项目的 `README.md`。注意 AquesTalk10 的
`port/src/image.c` 和 AqKanji2Koe 的 `aqdic.bin`/`lookup.bin` 是生成/授权数据，
不在 git 里。

## 验证结果

各子项目自带的验证（详见各自 README）：

- AquesTalk2：原生与 wasm 各 **512/512** 逐字节一致；SHA-256 回归 130/130。
- AquesTalk10：**252/252** 逐字节一致（84 句 × 7 声种 × 3 编码）。
- AqKanji2Koe：原生 **265/303 (87.5%)** 完全一致；wasm32 公共语料 **11/11**。
- AquesTalk1：与 Linux SDK 的多声库对拍通过。

本仓库额外做了：

- 修复 wasm32 下 `AqKanji2Koe_ConvRoman` 的 16 字节表步长问题（wasm32 指针是
  4 字节，反编译代码按 LP64 的 8 字节步长走会错位）。修复后
  `音声合成テスト。` → `onnse-go-se-te'_suto.`，与原生 64 位库一致。
- `tests/smoke.mjs` 和 Playwright 浏览器测试覆盖四个标签和 k2k 流水线。

## 已知限制

- AquesTalk1、AquesTalk10、AqKanji2Koe 是**评价版**：ナ行/マ行 → ヌ。AquesTalk2
  提供的 `.so` 与 `.bak` 只差 2 字节，该补丁让「ナ行/マ行 → ヌ」的映射不可达，
  因此 AquesTalk2 会正常区分（详见 `engines/aquestalk2/README.md`）。demo 不提供
  开发/使用许可证密钥输入，也没有绕过限制。需要产品行为请向 AQUEST 购买相应
  许可证并调用 `AquesTalk_SetDevKey` / `AqKanji2Koe_SetDevKey`。
- AqKanji2Koe 的数字 `<NUMK>`/`<NUM>` 标签、句末标点、少数重音位置与原库仍有
  差异（见 `engines/aqk2k/README.md`）。
- AqKanji2Koe 的 wasm32 构建使用 arena 分配器（`-DAQK2K_LEAK`）；统一适配层
  每 32 次转换重建一次实例，避免内存无限增长。
- AquesTalk1 的 f3 使用独立的 recompiled f3 引擎（另一套音声记号词汇）。
- Safari 不支持 memory64，因此 AqKanji2Koe 使用 wasm32 构建（保留 LP64 字段
  布局）。

## 历史与许可

四个子项目通过 `git subtree` 导入到 `engines/`，各自的提交历史完整保留；仓库
根部的提交只包含 monorepo 脚手架、统一 demo 和集成修复。原来的独立仓库仍在
上一级目录中，未改动。

AquesTalk1/2/10 与 AqKanji2Koe 是株式会社アクエスト（AQUEST Corp.）的商用软件。
本仓库中的二进制、phont、词典及其反编译派生代码均受其许可约束；仓库仅用于
技术验证/互操作性研究，不授予任何使用、分发或商业运行许可。详见 `NOTICE.md`
以及各子项目 SDK 目录下的许可证 PDF。
