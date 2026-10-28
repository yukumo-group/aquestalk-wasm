# 与新版 AquesTalk1 Linux 库对齐

`aqtk1_lnx/lib64/*` 是 2026-10 的新构建（f1..dvd 170 176 字节，f3 166 080 字节）。
本文件记录把 `recovered/src` 对齐到这批新库的结果，以及现在的打包方式。

## 结果

| 声库 | 290 例逐样本比较 |
|---|---|
| f1, f2, m1, m2, r1, imd1, jgr, dvd | **252 例逐位一致 + 38 例双方同码报错 = 290/290** |
| f3 | **255 例逐位一致 + 35 例双方同码报错 = 290/290**（机械重编译移植，见下） |

8 个旧式声库在 50/150/300% 语速下同样 18/18；wasm 构建与原生构建逐字节一致
（`recovered/wasm/verify.mjs`，19/19）。

## 架构：rawdump、无 preset

- 每个声库的整张表（formant / symbols / phoneme_word / period / pulse /
  dur_scale / dur_key / dur_val + 常量）由 `recovered/tools/linux/rawdump.py`
  从当前 `.so` 直接 dump 成 C 数组：`recovered/src/data/voice_<name>.c`。
- `recovered/src/data/ot_voices.c` 是注册表；
  `Open_Talk_SelectVoice("f2")` 选择声库（NULL/"" 回到 f1）。
- **OTPR preset 文件与 `*_Preset` 接口已删除**，`recovered/presets/` 不再存在。
- `ot_data.c` 只保留字典、UTF-8 表、字母/标点表；`ot_frame_data.c` 只保留
  音素名表；其余数值表都在 `voice_*.c` 里。

## Ghidra 定位到的三处差异

新库用 Ghidra 12.1.2 headless 反编译（脚本复用
`aquestalk2/scripts/DumpDecomp.java`，工程 `build/ghidra-proj`；反编译地址 −
0x100000 = 文件偏移）。

1. **时长缩放**：唯一时长入口 `FUN_0010d06c` 计算
   `dur = dur_base + delta * M / 163`。M 是编译期常量（f1 163、f2 130、
   f3 152、m1 49、m2 74、r1 33、imd1 130、jgr 210、dvd 10）。旧代码只加
   `dur_base`。
2. **class-2 special 分支**：新库统一走 `FUN_0010b24e`；`+k/+g/+b/+q`、`,k`
   以当前符号最后一个参数为目标，普通分支以下一符号首参数为目标。
3. **数据表**：formant 25476 词（f3 25584），symbols / phoneme_word / UTF
   表整体更新（UTF 164 项，含 `ヮ`；另外接受 `ヴ ヂ ヅ ヷ…` 并返回 105）。

## f3：用重编译方式整体移植

f3 是另一套引擎（新符号词汇 `_S/7`、`_.`、`--/9`、`__/10`、`@S/8`、`.K/0`、
`.S/4`、`.q/0`，class 6–11，9-bit 混合），不再逐条逆向实现，而是复用
`aquestalk2` 的移植方法，把整个 f3 `.so` 机械重编译：

```
aqtk1_lnx/lib64/f3/libAquesTalk.so
  → Ghidra 反编译 build/decomp-f3/all.c
  → recovered/f3port/tools/gen_decomp.py → recovered/f3port/src/decomp.c
  → recovered/f3port/tools/gen_image.py  → recovered/f3port/src/image.c
  → recovered/f3port/src/shim.c + f3api.c
```

- `decomp.c` 是 206 个函数的普通 C（clang 编译成原生 / wasm 机器码，不是
  解释器）；`image.c` 把 3 个只读/可写 PT_LOAD 段约 116 KB 按原虚拟地址放
  进 `aq_image`，并在启动时应用 823 个 `R_X86_64_RELATIVE` 和 9 个符号重
  定位（malloc/free/memcpy/time/__stack_chk_fail）。
- `Open_Talk_Synthe{,_Utf8,_Utf16}` 在 `voice->engine == OT_F3` 时直接调用
  移植后的 `AquesTalk_Synthe*`，因此输出与 `.so` 逐位相同；`recovered/src/f3/
  ot_f3.c` 仍保留为词汇参考，但合成不再经过它。
- 与 `aquestalk2` 相同的两个手工修正（都记在 `gen_decomp.py`）：
  1. `FUN_0010c278`（token builder）里 Ghidra 把 6 字节栈缓冲拆成了 6 个
     独立 `char`，编译器不保证相邻 → 合并成 `sbuf[6]`；
  2. `FUN_00109a18` 把 `+8` 的 int count 和 `+0xc` 的 int max 当 8 字节读，
     靠 `int*`/`int64_t*` 别名优化后返回旧值 → 改写成两个独立 int。
- 另外去掉 `in_FS_OFFSET` 栈保护读取，并把它指向 `.init_array/.fini_array`
  的两个 `.text` 重定位置 0（这两个函数不参与合成）。

移植后 290 例全部一致：**255 例逐位相同 + 35 例同码报错**，包括单假名、
浊音/半浊音、拗音、长音、促音、`、` 分词和 50/150/300% 语速。

## WebAssembly

```
./recovered/wasm/build.sh
# dist/aquestalk1.wasm  dist/aquestalk1.js  dist/demo.html
node recovered/wasm/verify.mjs
```

- 用 clang `--target=wasm32 -nostdlib -ffreestanding` 直接编译，无
  Emscripten、无 imports、无 libc；`recovered/wasm/runtime.c` 提供 mem*、
  分配器和 `time()`。
- 导出 `aq_alloc/aq_free/aq_select_voice/aq_voice_count/aq_voice_name/
  aq_synthe_utf8/aq_free_wave`，`aquestalk1.js` 是薄封装，`demo.html` 可直
  接用静态服务器打开。
- `recovered/wasm/verify.mjs`：wasm 与原生 `build/tools/dump` 的 WAV 逐字节
  比较，当前 19/19。

## 复现

```sh
./recovered/tools/linux/build.sh
./recovered/tools/linux/run_bench.sh
./recovered/wasm/build.sh && node recovered/wasm/verify.mjs
# 单声库：./build/tools/kana_bench aqtk1_lnx/lib64/f2/libAquesTalk.so f2 build/cases.tsv 100
```
