/* AquesTalk 音声記号列仕様書 (Version 1.5) conformance corpus.
 *
 * Source: engines/aquestalk2/aqtk2-lnx/siyo_onseikigou.pdf
 *
 * The PDF defines four kinds of symbols: reading symbols (kana), the accent
 * mark, phrase separators and numeric tags.  This module turns the normative
 * parts of the document (sections 2-7) into data that the notation test can
 * execute against every AquesTalk1/2/10 voice.
 *
 * Valid cases are expected to be accepted.  Invalid cases are expected to be
 * rejected; the engines are known to be lenient in places, so the report
 * records the divergence instead of failing the build.  SEMANTIC_CASES cover
 * the places where a symbol is supposed to change the audio, not just be
 * accepted.
 */

/* ------------------------------------------------------------------ */
/* section 5: reading symbol table                                     */
/* ------------------------------------------------------------------ */

export const READING_SYMBOL_GROUPS = {
  /* The table is laid out as rows; repeated here in reading order. */
  basic: [
    'あ', 'か', 'さ', 'た', 'な', 'は', 'ま', 'や', 'ら', 'わ', 'ん', 'が', 'ざ', 'だ', 'ば', 'ぱ',
    'い', 'き', 'し', 'ち', 'に', 'ひ', 'み', 'り', 'っ', 'ぎ', 'じ', 'び', 'ぴ',
    'う', 'く', 'す', 'つ', 'ぬ', 'ふ', 'む', 'ゆ', 'る', 'ー', 'ぐ', 'ず', 'ぶ', 'ぷ',
    'え', 'け', 'せ', 'て', 'ね', 'へ', 'め', 'いぇ', 'れ', 'げ', 'ぜ', 'で', 'べ', 'ぺ',
    'お', 'こ', 'そ', 'と', 'の', 'ほ', 'も', 'よ', 'ろ', 'を', 'ご', 'ぞ', 'ど', 'ぼ', 'ぽ',
  ],
  yoon: [
    'きゃ', 'しゃ', 'ちゃ', 'にゃ', 'ひゃ', 'みゃ', 'りゃ', 'ぎゃ', 'じゃ', 'つぁ', 'ふぁ', 'びゃ', 'ぴゃ', 'すぃ', 'とぅ',
    'きゅ', 'しゅ', 'ちゅ', 'にゅ', 'ひゅ', 'みゅ', 'りゅ', 'ぎゅ', 'じゅ', 'うぃ', 'つぃ', 'ふぃ', 'びゅ', 'ぴゅ', 'てぃ', 'どぅ',
    'きぇ', 'しぇ', 'ちぇ', 'にぇ', 'ひぇ', 'みぇ', 'りぇ', 'ぎぇ', 'じぇ', 'うぇ', 'つぇ', 'ふぇ', 'びぇ', 'ぴぇ', 'ずぃ', 'でゅ',
    'きょ', 'しょ', 'ちょ', 'にょ', 'ひょ', 'みょ', 'りょ', 'ぎょ', 'じょ', 'うぉ', 'つぉ', 'ふぉ', 'びょ', 'ぴょ', 'でぃ', 'てゅ',
  ],
  /* 2.7: manual g-row nasalisation, 2.6: manual devoicing. */
  nasal: ['カ゜', 'キ゜', 'ク゜', 'ケ゜', 'コ゜', 'キ゜ャ', 'キ゜ュ', 'キ゜ェ', 'キ゜ョ'],
  devoiced: ['_キ', '_ク', '_スィ', '_ス', '_ティ', '_トゥ', '_ヒ', '_フ', '_ピ',
             '_プ', '_シ', '_シュ', '_チ', '_チュ', '_ツィ', '_ツ', '_フィ'],
};

export const READING_SYMBOLS = Object.entries(READING_SYMBOL_GROUPS)
  .flatMap(([group, symbols]) => symbols.map((symbol) => ({ group, symbol })));

/** Wrap one reading symbol in the smallest valid phrase (section 3.8). */
export function readingSymbolProbe(symbol) {
  if (symbol === 'っ') return 'あっか。'; // a bare っ before a delimiter is invalid
  if (symbol === 'ー') return 'あー。';   // a phrase may not start with ー
  return `${symbol}。`;
}

/* ------------------------------------------------------------------ */
/* sections 2.2-2.9, 3.4-3.7: valid notation                           */
/* ------------------------------------------------------------------ */

export const VALID_NOTATION_CASES = [
  { id: 'particle-ha', section: '2.1', text: "これわ、おんせーき'ごーです。" },
  { id: 'accent-kare', section: '2.2', text: "か'れし。" },
  { id: 'accent-kurabu', section: '2.2', text: "く'らぶ。" },
  { id: 'accent-no-mark', section: '2.2', text: 'かれし。' },
  { id: 'accent-yoon', section: '2.2', text: "じゅ'んび、できたよ。" },
  { id: 'sep-semicolon', section: '2.3', text: "あ'くせんと;な'どの/かなめとな'る、" },
  { id: 'sep-slash', section: '2.3', text: "あ'くせんと/な'どの/かなめとな'る、" },
  { id: 'sep-plus', section: '2.3', text: "あ'くせんと+な'どの/かなめとな'る、" },
  { id: 'sep-joined', section: '2.3', text: "あ'くせんとなどの/かなめとな'る、" },
  { id: 'sep-full-comma', section: '2.4', text: 'あ、い。' },
  { id: 'sep-half-comma', section: '2.4', text: 'あ,い。' },
  { id: 'terminal-comma', section: '2.5', text: 'ふぁいるお/ほぞん、' },
  { id: 'terminal-question', section: '2.5', text: "ろくおん+しま'すか？" },
  { id: 'devoice-example', section: '2.6', text: "え'るめ_スの/あ'_クせさりー。" },
  { id: 'voicing-katakana', section: '2.6', text: 'よみあげまス。' },
  { id: 'nasal-example', section: '2.7', text: "めだかの/カ゜っこーわ、かわの+な'か。" },
  { id: 'num-phone', section: '2.8.1', text: "でんわば'んごーわ、<NUM VAL=01-2345-6789>です。" },
  { id: 'num-pi', section: '2.8.1', text: "ぱ'いわ、<NUM VAL=3.1415926535897932>。" },
  { id: 'numk-counter', section: '2.8.2', text: "のこり+じ'かんわ、あ'と/<NUMK VAL=10 COUNTER=ふん>です。" },
  { id: 'multi-sentence', section: '2.9', text: "さんだるを、つっかけとゆう。ちょ'っと+ま'ってを、た'んまとゆう。" },
];

/* Section 4 examples, kept separate because the older engines are known to
 * fail some of them (NUMK without a counter, long phont phrases). */
export const SPEC_SAMPLE_CASES = [
  { id: 'sample-01', section: '4', text: "でんわば'んごーわ、<NUM VAL=01-2345-6789>です。" },
  { id: 'sample-02', section: '4', text: "さーばー;<NUM VAL=3512>の/はーどでぃ'_ス_クに、え'らー+はっせー。" },
  { id: 'sample-03', section: '4', text: "げつよ'ーの/<NUMK VAL=21 COUNTER=じ>から、<NUMK VAL=8 COUNTER=ちゃ'んねる>で/よやく+しま'した。" },
  { id: 'sample-04', section: '4', text: "りょ'ーきんわ;<NUMK VAL=550 COUNTER=えん>です。" },
  { id: 'sample-05', section: '4', text: "すみませ'ん、<NUMK VAL=10 COUNTER=ふん>+おくれま'す。" },
  { id: 'sample-06', section: '4', text: "<NUMK VAL=20 COUNTER=ふん>に、え'きで/ま'ってます。" },
  { id: 'sample-07', section: '4', text: "あすのて'んき、とーきょー、はれ'のち+くもり、さいこーき'おん、<NUMK VAL=25 COUNTER=ど>。" },
  { id: 'sample-08', section: '4', text: "<NUMK VAL=100 COUNTER=め'ーとる>さき、こーえんいりぐちの/こーさてんを+ひだりで'す。" },
  { id: 'sample-09', section: '4', text: "このさき;<NUMK VAL=3 COUNTER=きろ>/じゅーたいちゅー。つーかじ'かん;<NUMK VAL=10 COUNTER=ふん>、" },
  { id: 'sample-10', section: '4', text: "よろし'いですか？" },
  { id: 'sample-11', section: '4', text: "これでい'い？" },
  { id: 'sample-12', section: '4', text: "ばってりーの/じゅーでん+かんりょー。" },
  { id: 'sample-13', section: '4', text: "<NUM VAL=2006 COUNTER=ねん>、<NUM VAL=1 COUNTER=がつ>;<NUM VAL=15 COUNTER=にち>。" },
  { id: 'sample-14', section: '4', text: "<NUM VAL=16 COUNTER=じ>;<NUM VAL=5 COUNTER=ふん>/<NUM VAL=35 COUNTER=びょー>です。" },
  { id: 'sample-15', section: '4', text: "それから'わ、やまぐち'けんで;やとわれば'んとーお/するよ'ーに+な'り、か'ぞくの/もと'にわ、ほと'んど;もどれ'なく+なりま'した。" },
  { id: 'sample-16', section: '4', text: "ばくおんが、ぎんせ'かいの/こーげんに/ひろがる。" },
  { id: 'sample-17', section: '2.8.2', text: "きの'ーわ、<NUMK VAL=321162567>+でした。" },
];

/* ------------------------------------------------------------------ */
/* sections 2.2, 2.6, 2.7, 3.1, 3.4, 3.6, 3.8: invalid notation        */
/* ------------------------------------------------------------------ */

export const INVALID_NOTATION_CASES = [
  { id: 'accent-inside-yoon', section: '2.2', text: "じ'ゅんび、できたよ。" },
  { id: 'accent-multiple', section: '3.4', text: "ひと'つのあくせんと'くです。" },
  { id: 'accent-multiple-2', section: '3.4', text: "あ'い'う。" },
  { id: 'restriction-final-sokuon', section: '3.8.1', text: 'あっ。' },
  { id: 'restriction-final-sokuon-2', section: '3.8.1', text: 'えっ、うそー。' },
  { id: 'restriction-double-sokuon', section: '3.8.2', text: 'えっっと。' },
  { id: 'restriction-double-sokuon-2', section: '3.8.2', text: 'えっッと。' },
  { id: 'restriction-initial-long', section: '3.8.3', text: 'ーか。' },
  { id: 'restriction-initial-long-2', section: '3.8.3', text: 'わたし;ーわ、' },
  { id: 'restriction-sokuon-long', section: '3.8.4', text: 'えっー。' },
  { id: 'restriction-devoice-long', section: '3.8.5', text: 'ナイ_スー。' },
  { id: 'restriction-devoice-vowel', section: '3.8.5', text: 'あ_キや。' },
  { id: 'devoice-hiragana', section: '2.6', text: '_す。' },
  { id: 'nasal-hiragana', section: '2.7', text: 'か゜。' },
  { id: 'num-alpha', section: '2.8.1', text: '<NUM VAL=12a>' },
  { id: 'num-unclosed', section: '3.6', text: '<NUM VAL=12' },
  { id: 'num-fullwidth', section: '3.6', text: '<NUM VAL=１２>' },
  { id: 'tag-lowercase', section: '3.6', text: '<num VAL=12>' },
  { id: 'tag-too-long', section: '3.6', text: `<NUM VAL=${'1'.repeat(260)}>` },
  { id: 'input-newline', section: '3.1', text: 'こんにちは\nせかい。' },
  { id: 'input-tab', section: '3.1', text: 'こんにちは\tせかい。' },
  { id: 'undefined-foreign', section: '2.9', text: 'ぐぃ。' },
];

/* ------------------------------------------------------------------ */
/* semantic effects (symbols must change the audio, not only parse)    */
/* ------------------------------------------------------------------ */

export const SEMANTIC_CASES = [
  { id: 'accent-changes-audio', section: '2.2', a: "か'れし。", b: 'かれし。', expectation: 'different' },
  { id: 'devoice-marker-changes-audio', section: '2.6', a: '_キ。', b: 'キ。', expectation: 'different' },
  { id: 'nasal-marker-changes-audio', section: '2.7', a: 'カ゜。', b: 'ガ。', expectation: 'different' },
  { id: 'question-raises-ending', section: '2.4', a: 'あ？', b: 'あ。', expectation: 'different' },
  { id: 'terminal-comma-vs-period', section: '2.5', a: 'あ、', b: 'あ。', expectation: 'different' },
];

/* Section 2.4: 、 > , > / (pause lengths).  ; and + have no pause and must
 * match / in duration. */
export const PAUSE_CASES = {
  long: 'あ、い。',
  short: 'あ,い。',
  none: 'あ/い。',
  semicolon: 'あ;い。',
  plus: 'あ+い。',
};

/* ------------------------------------------------------------------ */
/* sections 2.8, 3.6, 6: numeric tags and counters                      */
/* ------------------------------------------------------------------ */

export const COUNTERS = [
  'ねん', 'がつ', 'にち', 'じ', 'ふん', 'びょー', 'えん', 'かい', "か'い", "か'げつ",
  "か'ろりー", 'きゅー', 'ぎょー', 'きょく', "き'ろ", 'けん', 'こ', 'にん', 'さい',
  "じ'かん", 'だい', 'ちょーめ', 'つき', 'ばん', 'ほん', 'ひき', "ぱーせ'んと",
];

export const NUMK_RANGE_CASES = [
  { id: 'numk-1000', text: '<NUMK VAL=1000>' },
  { id: 'numk-10000', text: '<NUMK VAL=10000>' },
  { id: 'numk-321162567', text: '<NUMK VAL=321162567>' },
  { id: 'numk-max', text: '<NUMK VAL=9999999999999999>' },
  { id: 'numk-prefix', text: "きの'ーわ、<NUMK VAL=321162567>+でした。" },
];

/* ------------------------------------------------------------------ */
/* section 7: romanised notation (AquesTalk2 only)                    */
/* ------------------------------------------------------------------ */

export const ROMAN_CASES = [
  { id: 'roman-hello', section: '7.2', text: 'konnichiwa' },
  { id: 'roman-long', section: '7.2', text: 'ohayo-' },
  { id: 'roman-accent', section: '7.2', text: "o'nnse-" },
  { id: 'roman-sokuon', section: '7.2', text: 'gakko' },
  { id: 'roman-tag', section: '7.2', text: 'denwaba^ngo-wa <NUM VAL=01-2345-6789>desu.' },
  { id: 'roman-sample-02', section: '7.2', text: "sa-ba-;<NUM VAL=3512>no/ha-dodhi^_su_kuni e^ra-+hasse-." },
  { id: 'roman-sample-03', section: '7.2', text: "getuyo'-no/<NUMK VAL=21 COUNTER=ji>kara,<NUMK VAL=8 COUNTER=cya'nnneru>de/yoyaku+sima'sita." },
  { id: 'roman-tag-quoted', section: '7.1', text: '<NUMK VAL="10" COUNTER="funn">desu.' },
];
