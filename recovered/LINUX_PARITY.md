# 与新版 AquesTalk1 Linux 库对齐

`aqtk1_lnx/lib64/*` 在 2026-10 被换成了新构建（每个非 f3 声库从 158 384 字节
变为 170 176 字节，f3 从 158 768 字节变为 166 080 字节）。本文件记录把
`recovered/src` 对齐到这批新库的过程与结果。

## 结论

| 声库 | 290 例逐样本比较 |
|---|---|
| f1, f2, m1, m2, r1, imd1, jgr, dvd | **252 例 PCM 逐位一致 + 38 例双方同码报错 = 290/290**，0 个 PCM 差异、0 个长度差异 |
| f3 | 20 例逐位一致 + 35 例同码报错；87 例长度不同、3 例 PCM 不同、145 例单侧报错（尚不支持 f3 的新符号集） |

同样的结果在语速 50/100/150/300% 下成立（18 例抽查全部 18/18）。

## Ghidra 定位到的三处差异

新库用 Ghidra 12.1.2 headless 反编译（脚本复用
`aquestalk2/scripts/DumpDecomp.java`，工程在 `build/ghidra-proj`）。
反编译地址以镜像基址 `0x100000` 偏移，文件偏移 = 反编译地址 − 0x100000。

1. **每个声库的时长缩放因子。**
   `FUN_0010d06c`（f2 的 `0x10d06c`）是唯一的时长计算入口：

   ```c
   uVar1 = (delta * M) / 0xa3 + dur_base;        // 0xa3 = 163
   ```

   老实现只做了 `dur_base + delta`，等价于 `M = 163`。新库每个声库的 `M`
   是编译进代码的常量（f1 163、f2 130、f3 152、m1 49、m2 74、r1 33、
   imd1 130、jgr 210、dvd 10），`dur_base` 也各不相同。单摩拉时 delta 很小，
   音高字往往四舍五入到同一个整数，所以“单假名全对、多假名全错”。

2. **class-2 的 special 分支换了目标参数。**
   新库把 class-2 的 formant 混合抽成 `FUN_0010b24e`；special 分支
   （`+k +g +b +q ,k`）以**当前符号的最后一个参数** `param(rec, count-1)`
   为目标，普通分支以**下一个符号的第一个参数** `param(next, 0)` 为目标。
   老实现 special 分支做的是 `sample * prev_form / param(rec, 0)`，只在
   塞音过渡段引入细微差异（本次 アカ 在 sample 420 起差、其余段一致）。

3. **数据表整体更新。**
   - formant 表从 25465 词增长到 **25476 词**（f3 为 25584）；新库在
     `Tu` 附近插入了一行，`Tu` 之后的符号 index 全部 +1。
   - symbols、phoneme_word 的取值更新（f3 的符号表 211 条与旧 Windows f3
     完全一致，但新 f3 的 *词汇表* 变了，见下文）。
   - UTF-8→SJIS 表从 162 项变为 **164 项**（新增 `ヮ`）；新库另外接受
     `ヴ` `ヂ` `ヅ` `ヷ` `ヸ` `ヹ` `ヺ` `ヽ` `ヾ` `・` `゛` `ヵ` `ヶ` `！`
     等字符（返回 105 = 不在字典）。老实现对这些字符返回 “offset+1”，
     错误码不一致。
   - 周期/脉冲/时长表（period、pulse、dur_key、dur_scale、dur_val）与
     根表逐字节相同。

## 代码改动

| 文件 | 改动 |
|---|---|
| `recovered/include/ot_preset.h` | `OtVoice` 增加 `dur_scale_num`（M） |
| `recovered/src/data/ot_preset.c` | chunk 9 支持 8/10 字节；formant/phoneme_word 长度改为数据驱动；内置 formant 25476 词 |
| `recovered/src/synth/ot_duration.c` | `dur = dur_base + delta * dur_scale_num / 163` |
| `recovered/src/synth/ot_expand.c` | 新增 `ot_blend_form()`（`FUN_0010b24e`）；class-2 两个分支都走它，special 分支目标为 `param(rec,-1)` |
| `recovered/src/data/ot_frame_data.c` | 用新 f1 库重新生成 symbols / phoneme_word / formant（25476） |
| `recovered/src/data/ot_data.c` | UTF 表换成新库的 164 项 + 14 个 JIS-2004/CP932 假名 |
| `recovered/include/ot_internal.h`、`ot_data.h` | `OT_UTF_COUNT = 0xB2`（178） |
| `recovered/presets/*.bin` | 全部按当前 `lib64` 重新抽取（含 f3 的独立表与常量） |

`Open_Talk.h` 的 chunk 9 说明同步为可选的 `dur_scale`。旧的 8 字节 chunk 9
仍然可用（默认 M = 163），所以旧 preset 文件不会失效。

## 复现

```sh
./build/build.sh
./build/run_bench.sh
# 单声库：
./build/kana_bench aqtk1_lnx/lib64/f2/libAquesTalk.so recovered/presets/f2.bin build/cases.tsv 100
# 内置（不带 preset）路径：
./build/kana_bench aqtk1_lnx/lib64/f1/libAquesTalk.so - build/cases.tsv 100
```

`build/extract_presets.py` 从当前 `.so` 重新生成 `recovered/presets/*.bin`；
表地址写在脚本头部（来自 Ghidra 反编译）。若以后库再次更新，只需改这些地址
和每个声库的 `(dur_base, M, pulse_len, q_tail, render_mode)`。

## f3 仍缺的部分

新 f3 的符号表使用了一套新词汇：`_S/7`、`_.`、`--/9`、`__/10`、`@S/8`、
`.K/0`、`.S/4`、`.q/0`、`.@/11` 等，class 6–11 的语义也是新的。当前实现
仍按根声库的 `.k`/`ka`/`a.` 命名生成 token，所以 f3 的塞音行在
`ot_find_symbol` 处返回 102；单假名里只有元音等 20 例能走通。

要补全 f3，需要把 `FUN_0010c278`（f3 的 token builder）和 class 6–11 的
expander 分支一起移植；这已经不是数据问题，而是新引擎特性。
