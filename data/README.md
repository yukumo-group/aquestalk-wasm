# 统一数据集

这个目录是 demo 与所有无头测试的唯一 TTS 输入来源。三个声库引擎
（AquesTalk1/2/10）的输入字母表相同（假名 + AquesTalk 記号），所以同一份
文本可以同时跑 34 个声库，不需要为每个引擎维护自己的样例表。

## `kana-corpus.js`

151 条日常日语，按场景分为 14 类：

| 分类 | 条数 | 内容 |
| --- | --- | --- |
| `greeting` | 12 | 问候、告别、感谢 |
| `weather` | 12 | 天气、温度、雨雪 |
| `food` | 12 | 三餐、饮料、水果 |
| `shopping` | 12 | 价格、付款、退换 |
| `transit` | 12 | 电车、公交、问路 |
| `work` | 12 | 会议、邮件、学校 |
| `home` | 12 | 家人、家务、宠物 |
| `health` | 12 | 症状、医院、吃药 |
| `numbers` | 12 | 数字、时间、数量 |
| `request` | 12 | 请求、疑问 |
| `katakana` | 12 | 片假名外来语 |
| `long` | 6 | 较长叙述 |
| `notation` | 8 | 标点、促音、拗音 |
| `prosody` | 5 | アクセント记号、句切 `/` |

全部直接写成假名（含全角「、」「。」「？」和半角 `'` `/`），**不含汉字**，
因此不需要 AqKanji2Koe 词典。句子是手写的日常表达，不复制外部语料库文本。

同一个文件还导出行为探针：

- `DEMO_KANA_SAMPLES`：demo 的 8 个示例按钮；
- `KANA_SCRIPT_PAIRS`：平假名 / 片假名写法对；
- `EVALUATION_PROBES`：ナ行/マ行 → ヌ/ム 的评价版探针；
- `INVALID_INPUTS`：空串、ASCII、汉字、半角假名、emoji、kana+Latin、全角「！」；
- `DIVERGENT_INPUTS`：引擎代际接受度不同的 ASCII 空格、`えっ？`；
- `SPEED_PROBES` / `SPEED_PROBE_TEXT`：50–300% 语速；
- `LONG_PROBE_TEXT`：长文本分配器路径。

日常语料刻意不使用 ASCII 空格和全角「！」：

- 空格只有 AquesTalk2 接受，AquesTalk1/10 返回 105；需要停顿时用「、」。
- 「！」不被三个引擎支持；句切符号使用「。」「？」「、」「,」「;」「/」「+」。

## `notation-corpus.js`

把 `engines/aquestalk2/aqtk2-lnx/siyo_onseikigou.pdf`（音声記号列仕様書
Version 1.5）转成可执行数据：

- `READING_SYMBOL_GROUPS` / `READING_SYMBOLS`：section 5 的 161 个読み記号
  （72 基本 + 63 拗音/外来音 + 9 鼻濁音 + 17 無声化）；
- `VALID_NOTATION_CASES`：section 2.2–2.9 / 3.4–3.7 的合法记法；
- `SPEC_SAMPLE_CASES`：section 4 的 17 个示例；
- `INVALID_NOTATION_CASES`：section 3.8 禁止组合、3.1 换行/Tab、3.6 标签格式；
- `SEMANTIC_CASES`：アクセント/無声化/鼻濁音/疑问符/句末「、」是否真的改变音频；
- `PAUSE_CASES`：`、` > `,` > `/` 的停顿层级；
- `COUNTERS`：section 6 的 27 个助数词；
- `NUMK_RANGE_CASES`：`<NUMK>` 的数值范围；
- `ROMAN_CASES`：section 7 的ローマ字表記（AquesTalk2）。

## 约定

- 新增语料必须写假名读音，不要写汉字；需要 kana 化时用 AqKanji2Koe
  生成后再人工校对，但不要把 k2k 的输出直接当作“标准答案”。
- 新增日常语料先跑 `npm run test:consistency`，确认 34 个声库都能接受；
  引擎确实不支持的字符放到 `INVALID_INPUTS` 或 `DIVERGENT_INPUTS`。
- 新增記号列用例优先引用 PDF 的节号（`section` 字段），方便回溯。
- ID 必须唯一；`tests/consistency.mjs` 和 `tests/notation.mjs` 会做基本校验。
