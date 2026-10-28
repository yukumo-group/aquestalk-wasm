# 与新版 AquesTalk1 Linux 库对齐

`aqtk1_lnx/lib64/*` 是 2026-10 的新构建（f1..dvd 170 176 字节，f3 166 080 字节）。
本文件记录把 `recovered/src` 对齐到这批新库的结果，以及现在的打包方式。

## 结果

| 声库 | 290 例逐样本比较 |
|---|---|
| f1, f2, m1, m2, r1, imd1, jgr, dvd | **252 例逐位一致 + 38 例双方同码报错 = 290/290** |
| f3 | 79 例逐位一致 + 35 例同码报错；108 例长度不同、2 例 PCM 不同、66 例单侧报错 |

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

## f3 专门模块

新 f3 是另一套引擎：符号词汇变成 `_S/7`、`_.`、`--/9`、`__/10`、`@S/8`、
`.K/0`、`.S/4`、`.q/0`、`.@/11`，class 6–11 的语义也是新的，class-2/3 的
混合用 9-bit。所有 f3 特化都在 `recovered/src/f3/ot_f3.c`（由
`voice->engine == OT_ENGINE_F3` 调用），旧式声库的代码路径不受影响。

当前 f3 模块只实现了普通 CV 下不渲染 `.k` 过渡这一条（因此 カ 行等 79 例
已逐位一致）；`.s`/class 6–11 和 9-bit 混合还没有移植，所以塞音仍是 102 或
长度不同。

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
