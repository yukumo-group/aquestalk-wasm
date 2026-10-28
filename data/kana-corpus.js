/* Canonical kana corpus shared by the demo and every headless test.
 *
 * All AquesTalk1/2/10 voice banks take the same input alphabet: Japanese
 * kana plus AquesTalk notation.  Keeping the corpus here (instead of one
 * private sample list per engine/test) means the demo buttons, the smoke
 * test and the cross-voice consistency matrix all exercise exactly the same
 * daily-Japanese material.
 *
 * Text is written directly in kana, so no AqKanji2Koe conversion (and no
 * dictionary) is needed to run the TTS tests.  Categories are metadata only;
 * they are used by the report to show coverage.
 */

export const KANA_CORPUS = [
  /* greetings ------------------------------------------------------- */
  { id: 'greet-01', category: 'greeting', text: 'おはようございます。きょうもよろしくおねがいします。' },
  { id: 'greet-02', category: 'greeting', text: 'こんにちは。おげんきですか。' },
  { id: 'greet-03', category: 'greeting', text: 'こんばんは。いいよるですね。' },
  { id: 'greet-04', category: 'greeting', text: 'ありがとうございます。たすかりました。' },
  { id: 'greet-05', category: 'greeting', text: 'すみません、ちょっといいですか。' },
  { id: 'greet-06', category: 'greeting', text: 'はじめまして。どうぞよろしく。' },
  { id: 'greet-07', category: 'greeting', text: 'おつかれさまです。おさきにしつれいします。' },
  { id: 'greet-08', category: 'greeting', text: 'いってきます。きをつけてね。' },
  { id: 'greet-09', category: 'greeting', text: 'おかえりなさい。ごはんができています。' },
  { id: 'greet-10', category: 'greeting', text: 'おやすみなさい。またあした。' },
  { id: 'greet-11', category: 'greeting', text: 'しばらくですね。おかわりありませんか。' },
  { id: 'greet-12', category: 'greeting', text: 'おめでとうございます。よかったですね。' },

  /* weather --------------------------------------------------------- */
  { id: 'weather-01', category: 'weather', text: 'きょうはいいてんきですね。' },
  { id: 'weather-02', category: 'weather', text: 'あしたはあめがふるそうです。' },
  { id: 'weather-03', category: 'weather', text: 'かぜがつよくて、すずしいです。' },
  { id: 'weather-04', category: 'weather', text: 'なつはとてもあついですね。' },
  { id: 'weather-05', category: 'weather', text: 'ふゆはゆきがたくさんふります。' },
  { id: 'weather-06', category: 'weather', text: 'たいふうがくるので、そとにでないでください。' },
  { id: 'weather-07', category: 'weather', text: 'こんやははれ、あしたはくもりでしょう。' },
  { id: 'weather-08', category: 'weather', text: 'にじがきれいにみえます。' },
  { id: 'weather-09', category: 'weather', text: 'かさをわすれないでください。' },
  { id: 'weather-10', category: 'weather', text: 'きおんはにじゅうどくらいです。' },
  { id: 'weather-11', category: 'weather', text: 'そとはすごくさむいですから、コートをきてください。' },
  { id: 'weather-12', category: 'weather', text: 'あめのひはかぜがつよくふきます。' },

  /* food ------------------------------------------------------------ */
  { id: 'food-01', category: 'food', text: 'あさごはんはパンとたまごです。' },
  { id: 'food-02', category: 'food', text: 'ひるごはんにラーメンをたべました。' },
  { id: 'food-03', category: 'food', text: 'よるはカレーライスをつくります。' },
  { id: 'food-04', category: 'food', text: 'このケーキはとてもおいしいです。' },
  { id: 'food-05', category: 'food', text: 'おちゃをいっぱいどうぞ。' },
  { id: 'food-06', category: 'food', text: 'くだものはりんごとバナナがすきです。' },
  { id: 'food-07', category: 'food', text: 'すしをたべにいきましょう。' },
  { id: 'food-08', category: 'food', text: 'からいものはちょっとにがてです。' },
  { id: 'food-09', category: 'food', text: 'みずをコップいっぱいください。' },
  { id: 'food-10', category: 'food', text: 'ごちそうさまでした。おいしかったです。' },
  { id: 'food-11', category: 'food', text: 'やさいをたくさんたべるようにしています。' },
  { id: 'food-12', category: 'food', text: 'あしたのゆうはんはなににしましょうか。' },

  /* shopping -------------------------------------------------------- */
  { id: 'shop-01', category: 'shopping', text: 'このシャツはいくらですか。' },
  { id: 'shop-02', category: 'shopping', text: 'もうすこしやすいのはありますか。' },
  { id: 'shop-03', category: 'shopping', text: 'これをください。カードではらいます。' },
  { id: 'shop-04', category: 'shopping', text: 'レシートをおねがいします。' },
  { id: 'shop-05', category: 'shopping', text: 'あしたのごごにうけとりにきます。' },
  { id: 'shop-06', category: 'shopping', text: 'おつりをまちがえないでください。' },
  { id: 'shop-07', category: 'shopping', text: 'セールはあさってまではじまります。' },
  { id: 'shop-08', category: 'shopping', text: 'このくつはサイズがおおきいです。' },
  { id: 'shop-09', category: 'shopping', text: 'ほかのいろもみてみたいです。' },
  { id: 'shop-10', category: 'shopping', text: 'まいどありがとうございます。' },
  { id: 'shop-11', category: 'shopping', text: 'このくだものはどこでつくられましたか。' },
  { id: 'shop-12', category: 'shopping', text: 'ふくろはべつにいりません。' },

  /* transit --------------------------------------------------------- */
  { id: 'transit-01', category: 'transit', text: 'えきはこのみちをまっすぐいったところです。' },
  { id: 'transit-02', category: 'transit', text: 'つぎのでんしゃはごふんおくれています。' },
  { id: 'transit-03', category: 'transit', text: 'しんじゅくまでいくらかかりますか。' },
  { id: 'transit-04', category: 'transit', text: 'このバスはとうきょうえきにとまりますか。' },
  { id: 'transit-05', category: 'transit', text: 'きっぷはじどうはんばいきでかえます。' },
  { id: 'transit-06', category: 'transit', text: 'みちがこんでいるので、すこしおそくなります。' },
  { id: 'transit-07', category: 'transit', text: 'タクシーをよんでください。' },
  { id: 'transit-08', category: 'transit', text: 'ひだりにまがるとこうえんがあります。' },
  { id: 'transit-09', category: 'transit', text: 'あしたのあさはちじにでかけます。' },
  { id: 'transit-10', category: 'transit', text: 'でんしゃのなかではしずかにおねがいします。' },
  { id: 'transit-11', category: 'transit', text: 'つぎのえきでおります。' },
  { id: 'transit-12', category: 'transit', text: 'このでんしゃはおおさかにいきますか。' },

  /* work / school --------------------------------------------------- */
  { id: 'work-01', category: 'work', text: 'あしたのかいぎはじゅうじからです。' },
  { id: 'work-02', category: 'work', text: 'しりょうをコピーしておいてください。' },
  { id: 'work-03', category: 'work', text: 'メールをかくにんしました。' },
  { id: 'work-04', category: 'work', text: 'しゅっちょうはらいしゅうのすいようびです。' },
  { id: 'work-05', category: 'work', text: 'しごとがおわったら、のみにいきましょう。' },
  { id: 'work-06', category: 'work', text: 'がっこうはあしたからはじまります。' },
  { id: 'work-07', category: 'work', text: 'しゅくだいをわすれないでください。' },
  { id: 'work-08', category: 'work', text: 'せんせいにしつもんしてください。' },
  { id: 'work-09', category: 'work', text: 'テストはなんじにはじまりますか。' },
  { id: 'work-10', category: 'work', text: 'ともだちとえいがをみにいきます。' },
  { id: 'work-11', category: 'work', text: 'かいぎのしりょうをかいじょうにはいはいしてください。' },
  { id: 'work-12', category: 'work', text: 'らいしゅうのよていをメールでおくります。' },

  /* home / family --------------------------------------------------- */
  { id: 'home-01', category: 'home', text: 'かぞくはよにんです。' },
  { id: 'home-02', category: 'home', text: 'ちちはまいにちしんぶんをよみます。' },
  { id: 'home-03', category: 'home', text: 'はははりょうりがとてもじょうずです。' },
  { id: 'home-04', category: 'home', text: 'あねはとうきょうにはたらいています。' },
  { id: 'home-05', category: 'home', text: 'おとうとはこうこうせいです。' },
  { id: 'home-06', category: 'home', text: 'いぬとねこをかっています。' },
  { id: 'home-07', category: 'home', text: 'へやをそうじしてから、せんたくをします。' },
  { id: 'home-08', category: 'home', text: 'まどをあけてください。あついですから。' },
  { id: 'home-09', category: 'home', text: 'でんきをけすのをわすれないでください。' },
  { id: 'home-10', category: 'home', text: 'いえのちかくにスーパーがあります。' },
  { id: 'home-11', category: 'home', text: 'きょうはかぞくでばんごはんをたべます。' },
  { id: 'home-12', category: 'home', text: 'にもつがおおいので、くるまでいきます。' },

  /* health ---------------------------------------------------------- */
  { id: 'health-01', category: 'health', text: 'あたまがいたいので、くすりをのみます。' },
  { id: 'health-02', category: 'health', text: 'ねつがあるなら、はやくねてください。' },
  { id: 'health-03', category: 'health', text: 'びょういんはあさくじからです。' },
  { id: 'health-04', category: 'health', text: 'たいちょうはどうですか。' },
  { id: 'health-05', category: 'health', text: 'すこしやすんだほうがいいですよ。' },
  { id: 'health-06', category: 'health', text: 'かぜをひかないようにきをつけてください。' },
  { id: 'health-07', category: 'health', text: 'てをよくあらってください。' },
  { id: 'health-08', category: 'health', text: 'めがかゆいので、めぐすりをさします。' },
  { id: 'health-09', category: 'health', text: 'ここがちょっといたいです。' },
  { id: 'health-10', category: 'health', text: 'おだいじにしてください。' },
  { id: 'health-11', category: 'health', text: 'よるはよくねむれていますか。' },
  { id: 'health-12', category: 'health', text: 'びょういんへいくまえに、よやくしてください。' },

  /* numbers / time -------------------------------------------------- */
  { id: 'number-01', category: 'numbers', text: 'いち、に、さん、し、ご、ろく、しち、はち、きゅう、じゅう。' },
  { id: 'number-02', category: 'numbers', text: 'いまはごぜんくじはんすぎです。' },
  { id: 'number-03', category: 'numbers', text: 'らいげつのみっかはやすみです。' },
  { id: 'number-04', category: 'numbers', text: 'ひゃくえんのものをにかいかいます。' },
  { id: 'number-05', category: 'numbers', text: 'さんびゃくごじゅうえんおあずかりします。' },
  { id: 'number-06', category: 'numbers', text: 'せんえんさつでおねがいします。' },
  { id: 'number-07', category: 'numbers', text: 'ごふんまってください。' },
  { id: 'number-08', category: 'numbers', text: 'にじかんくらいかかります。' },
  { id: 'number-09', category: 'numbers', text: 'あとさんぷんではじまります。' },
  { id: 'number-10', category: 'numbers', text: 'まいにちしちじにおきます。' },
  { id: 'number-11', category: 'numbers', text: 'きょうははつかです。' },
  { id: 'number-12', category: 'numbers', text: 'よんじゅうにんくらいきます。' },

  /* requests / questions ------------------------------------------- */
  { id: 'request-01', category: 'request', text: 'ちょっとまってください。' },
  { id: 'request-02', category: 'request', text: 'もういちどおしえてください。' },
  { id: 'request-03', category: 'request', text: 'ゆっくりはなしてください。' },
  { id: 'request-04', category: 'request', text: 'これはなんですか。' },
  { id: 'request-05', category: 'request', text: 'どこにありますか。' },
  { id: 'request-06', category: 'request', text: 'だれときましたか。' },
  { id: 'request-07', category: 'request', text: 'なぜそうおもうのですか。' },
  { id: 'request-08', category: 'request', text: 'いつがいいですか。' },
  { id: 'request-09', category: 'request', text: 'いっしょにいきませんか。' },
  { id: 'request-10', category: 'request', text: 'てつだってもらえますか。' },
  { id: 'request-11', category: 'request', text: 'もうすこしおおきいこえでおねがいします。' },
  { id: 'request-12', category: 'request', text: 'このてがみをだしてもらえますか。' },

  /* katakana loanwords --------------------------------------------- */
  { id: 'katakana-01', category: 'katakana', text: 'パソコンのちょうしがわるいです。' },
  { id: 'katakana-02', category: 'katakana', text: 'スマートフォンでしゃしんをとります。' },
  { id: 'katakana-03', category: 'katakana', text: 'エアコンをつけてもいいですか。' },
  { id: 'katakana-04', category: 'katakana', text: 'コーヒーをいっぱいください。' },
  { id: 'katakana-05', category: 'katakana', text: 'インターネットがつながりません。' },
  { id: 'katakana-06', category: 'katakana', text: 'テレビをみながらごはんをたべます。' },
  { id: 'katakana-07', category: 'katakana', text: 'カメラをわすれてしまいました。' },
  { id: 'katakana-08', category: 'katakana', text: 'エレベーターはどこですか。' },
  { id: 'katakana-09', category: 'katakana', text: 'ホテルのよやくをおねがいします。' },
  { id: 'katakana-10', category: 'katakana', text: 'プレゼントをかいにいきます。' },
  { id: 'katakana-11', category: 'katakana', text: 'このレストランはよやくがひつようです。' },
  { id: 'katakana-12', category: 'katakana', text: 'パーティーはなんじからですか。' },

  /* longer daily narrative ----------------------------------------- */
  { id: 'long-01', category: 'long', text: 'けさはあめがふっていたので、かさをもってでかけましたが、ひるからはよくはれました。' },
  { id: 'long-02', category: 'long', text: 'しごとがおわったあとで、えきのちかくのスーパーでくだものとパンをかって、いえにかえりました。' },
  { id: 'long-03', category: 'long', text: 'こんしゅうのどようびに、かぞくといっしょにこうえんへいって、おべんとうをたべるよていです。' },
  { id: 'long-04', category: 'long', text: 'ともだちにメールをおくったけれど、まだへんじがきません。ちょっとしんぱいです。' },
  { id: 'long-05', category: 'long', text: 'らいげつのしゅうまつに、おおさかへあそびにいくので、ホテルとでんしゃのきっぷをよやくしました。' },
  { id: 'long-06', category: 'long', text: 'きのうはよるおそくまでしごとをして、あさおきたらとてもつかれていました。きょうははやくねます。' },

  /* punctuation / small kana --------------------------------------- */
  { id: 'notation-01', category: 'notation', text: 'えっと、そうなんですか。' },
  { id: 'notation-02', category: 'notation', text: 'はい、そうです。でも、ちょっとむずかしいです。' },
  { id: 'notation-03', category: 'notation', text: 'おはよう。きょうは、はれ。あしたは、あめ。' },
  { id: 'notation-04', category: 'notation', text: 'こんにちは、せかい。' },
  { id: 'notation-05', category: 'notation', text: 'すもももももももものうち。' },
  { id: 'notation-06', category: 'notation', text: 'おかあさん、おねえさん、おおきいとおおきい。' },
  { id: 'notation-07', category: 'notation', text: 'なにぬねの、まみむめも。' },
  { id: 'notation-08', category: 'notation', text: 'きゃきゅきょ、しゃしゅしょ、ちゃちゅちょ。' },

  /* accent mark / phrase slash ------------------------------------- */
  { id: 'prosody-01', category: 'prosody', text: "こんにちは'、せかい。" },
  { id: 'prosody-02', category: 'prosody', text: 'おはよう/ございます。' },
  { id: 'prosody-03', category: 'prosody', text: "これわ、ごーせー/お'んせーです。" },
  { id: 'prosody-04', category: 'prosody', text: 'きょうは/いい/てんき/ですね。' },
  { id: 'prosody-05', category: 'prosody', text: "ありがとう'ございます。" },
];

/* The demo shows a small, representative subset of the corpus. */
export const DEMO_SAMPLE_IDS = [
  'greet-02',
  'weather-01',
  'food-04',
  'shop-01',
  'transit-02',
  'katakana-01',
  'long-02',
  'notation-01',
];

const byId = new Map(KANA_CORPUS.map((entry) => [entry.id, entry]));

export function corpusEntry(id) {
  const entry = byId.get(id);
  if (!entry) throw new Error(`unknown corpus entry: ${id}`);
  return entry;
}

export const DEMO_KANA_SAMPLES = DEMO_SAMPLE_IDS.map((id) => corpusEntry(id).text);

/* ------------------------------------------------------------------ */
/* behaviour probes (not part of the daily corpus)                     */
/* ------------------------------------------------------------------ */

/* Hiragana and katakana spellings of the same phrase.  Both must be accepted;
 * byte-identical output is *not* required, because the engines may use the
 * script as a pronunciation/accent hint (e.g. は as a particle vs ハ as a
 * mora).  The consistency report records whether each voice treats them
 * identically. */
export const KANA_SCRIPT_PAIRS = [
  { id: 'script-hello', hiragana: 'こんにちは、せかい。', katakana: 'コンニチハ、セカイ。' },
  { id: 'script-weather', hiragana: 'きょうはいい、てんきですね。', katakana: 'キョウハイイ、テンキデスネ。' },
  { id: 'script-food', hiragana: 'すしをたべにいきましょう。', katakana: 'スシオタベニイキマショウ。' },
  { id: 'script-transit', hiragana: 'つぎのでんしゃはごふんおくれています。', katakana: 'ツギノデンシャハゴフンオクレテイマス。' },
  { id: 'script-thanks', hiragana: 'ありがとう', katakana: 'アリガトウ' },
  { id: 'script-long', hiragana: 'おかあさん、おねえさん、おおきいとおおきい。', katakana: 'オカアサン、オネエサン、オオキイトオオキイ。' },
  { id: 'script-small', hiragana: 'きゃきゅきょ', katakana: 'キャキュキョ' },
  { id: 'script-namagome', hiragana: 'なまむぎなまごめ', katakana: 'ナマムギナマゴメ' },
  { id: 'script-punct', hiragana: 'そうなんですか？', katakana: 'ソウナンデスカ？' },
  { id: 'script-numbers', hiragana: 'いち、に、さん', katakana: 'イチ、ニ、サン' },
];

/* Evaluation builds collapse the ナ行/マ行 onto ヌ/ム.  These pairs make the
 * restriction visible without needing a licence key: in an evaluation build
 * both sides render byte-identically, in a licensed build they differ. */
export const EVALUATION_PROBES = [
  { id: 'eval-na-nu', a: 'な', b: 'ぬ' },
  { id: 'eval-ni-nu', a: 'に', b: 'ぬ' },
  { id: 'eval-ne-nu', a: 'ね', b: 'ぬ' },
  { id: 'eval-no-nu', a: 'の', b: 'ぬ' },
  { id: 'eval-ma-mu', a: 'ま', b: 'む' },
  { id: 'eval-mi-mu', a: 'み', b: 'む' },
  { id: 'eval-me-mu', a: 'め', b: 'む' },
  { id: 'eval-mo-mu', a: 'も', b: 'む' },
  { id: 'eval-phrase', a: 'なまむぎなまごめ', b: 'ぬむむぎぬむごむ' },
];

/* Invalid input shared by all three engines.  The exact error code is
 * engine-specific; the test only requires "rejected" semantics. */
export const INVALID_INPUTS = [
  { id: 'invalid-empty', text: '', reason: 'empty string' },
  { id: 'invalid-ascii', text: 'hello world', reason: 'ASCII text' },
  { id: 'invalid-kanji', text: '漢字', reason: 'kanji without AqKanji2Koe' },
  { id: 'invalid-halfwidth', text: 'ｺﾝﾆﾁﾊ', reason: 'half-width katakana' },
  { id: 'invalid-emoji', text: 'こんにちは😀', reason: 'emoji' },
  { id: 'invalid-latin-mix', text: 'こんにちはABC', reason: 'kana + Latin' },
  { id: 'invalid-exclamation', text: 'そうなんですか！', reason: 'full-width exclamation mark' },
];

/* Valid kana that the three engine generations disagree about.  These are
 * reported, not treated as corpus failures, because the divergence itself is
 * the behaviour under test. */
export const DIVERGENT_INPUTS = [
  { id: 'divergent-space', text: 'こんにちは せかい。', note: 'ASCII space' },
  { id: 'divergent-sokuon-question', text: 'えっ？そうなんですか。', note: 'small tsu before a question mark' },
];

/* Same text at several rates; duration must not increase with speed. */
export const SPEED_PROBES = [50, 75, 100, 150, 200, 300];
export const SPEED_PROBE_TEXT = 'きょうはいい、てんきですね。さんぽにいきましょう。';

/* Long but valid input, used for buffer/allocation behaviour. */
export const LONG_PROBE_TEXT = 'こんにちは、せかい。'.repeat(40);
