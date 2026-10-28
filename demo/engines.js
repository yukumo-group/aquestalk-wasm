/* Unified engine adapters for the AquesTalk monorepo demo.
 *
 * The four components live side by side under ../engines/:
 *
 *   AquesTalk1   engines/aquestalk1/dist/aquestalk1.wasm
 *   AquesTalk2   engines/aquestalk2/dist/aquestalk2-core.wasm (+ phont/)
 *   AquesTalk10  engines/aquestalk10/port/web/aqtk10.wasm
 *   AqKanji2Koe  engines/aqk2k/port/build-wasm32/aqk2k32.wasm (+ aq_dic/)
 *
 * Every adapter exposes the same tiny surface:
 *
 *   await loadEngine('aqtk2')  -> { synth(text, {voice, speed, params}) }
 *   await loadKanji2Koe()      -> { convert(text), convertRoman(text) }
 *
 * No bundler, no framework: plain ES modules and the hand-written wrappers
 * that ship with each engine.
 */

import { AquesTalk1 } from '../engines/aquestalk1/dist/aquestalk1.js';
import { createAquesTalk2 } from '../engines/aquestalk2/dist/aquestalk2.js';
import {
  AquesTalk10,
  VOICES as AQTK10_VOICES,
  AquesTalkError,
} from '../engines/aquestalk10/port/web/aqtk10.js';

export { AQTK10_VOICES };

/* ------------------------------------------------------------------ */
/* asset locations                                                     */
/* ------------------------------------------------------------------ */

let engineRoot = new URL('../engines/', import.meta.url);

/** Override the engines/ root (used by the Node smoke test). */
export function setEngineRoot(root) {
  engineRoot = root instanceof URL ? root : new URL(root, import.meta.url);
}

function asset(path) {
  return new URL(path, engineRoot);
}

/* ------------------------------------------------------------------ */
/* engine catalogue                                                     */
/* ------------------------------------------------------------------ */

const KANA_SAMPLES = [
  'こんにちは、せかい。',
  'おはようございます',
  'ありがとう',
  'きょうは いい てんき ですね',
  'すもももももももものうち',
  'えっ？そうなんですか！',
  'おかあさん、おねえさん、おおきいとおおきい',
  'なにぬねの まみむめも',
];

const KANJI_SAMPLES = [
  '音声合成テスト。東京は日本の首都です。',
  '明日の天気は晴れでしょう。',
  '吾輩は猫である。名前はまだ無い。',
  '１２３円でございます。',
  'おはようございます。今日もいい一日にしましょう。',
];

const AQTK1_VOICES = [
  { id: 'f1', label: 'f1 · Female' },
  { id: 'f2', label: 'f2 · Female' },
  { id: 'm1', label: 'm1 · Male' },
  { id: 'm2', label: 'm2 · Male' },
  { id: 'r1', label: 'r1 · Robot' },
  { id: 'imd1', label: 'imd1' },
  { id: 'jgr', label: 'jgr' },
  { id: 'dvd', label: 'dvd' },
  { id: 'f3', label: 'f3 · Female (new)' },
];

const AQTK2_VOICES = [
  { id: '', label: 'Built-in default (aq_defo1)' },
  { id: 'aq_defo1.phont', label: 'Default (phont file)' },
  { id: 'aq_rm.phont', label: 'Female (aq_rm)' },
  { id: 'aq_f1c.phont', label: 'Female (aq_f1c)' },
  { id: 'aq_f3a.phont', label: 'Female (aq_f3a)' },
  { id: 'aq_m4b.phont', label: 'Male (aq_m4b)' },
  { id: 'aq_mf1.phont', label: 'Male (aq_mf1)' },
  { id: 'aq_momo1.phont', label: 'Momo (aq_momo1)' },
  { id: 'aq_huskey.phont', label: 'Husky (aq_huskey)' },
  { id: 'aq_rb2.phont', label: 'Robot (aq_rb2)' },
  { id: 'aq_rb3.phont', label: 'Robot (aq_rb3)' },
  { id: 'aq_robo.phont', label: 'Robot (aq_robo)' },
  { id: 'aq_teto1.phont', label: 'Teto (aq_teto1)' },
  { id: 'aq_yukkuri.phont', label: 'Yukkuri (aq_yukkuri)' },
  { id: 'ar_f4.phont', label: 'ar_f4' },
  { id: 'ar_m5.phont', label: 'ar_m5' },
  { id: 'ar_mf2.phont', label: 'ar_mf2' },
  { id: 'ar_rm3.phont', label: 'ar_rm3' },
];

const AQTK10_VOICE_INFO = [
  { id: 'F1', label: 'F1 · Female' },
  { id: 'F2', label: 'F2 · Female' },
  { id: 'F3', label: 'F3 · Female (high)' },
  { id: 'M1', label: 'M1 · Male' },
  { id: 'M2', label: 'M2 · Male' },
  { id: 'R1', label: 'R1 · Robot' },
  { id: 'R2', label: 'R2 · Robot' },
];

export const ENGINES = [
  {
    id: 'aqtk1',
    name: 'AquesTalk1',
    subtitle: '9 voices',
    badge: '9 voices',
    kind: 'tts',
    voiceLabel: 'Voice',
    textLabel: 'Kana symbols (hiragana / katakana)',
    description:
      'Recompiled from the AquesTalk1 Linux engines (f1/f2/m1/m2/r1/imd1/jgr/dvd + f3). Nine built-in voices; 8 kHz / 16-bit / mono WAV.',
    voices: AQTK1_VOICES,
    defaultVoice: 'f1',
    samples: KANA_SAMPLES,
  },
  {
    id: 'aqtk2',
    name: 'AquesTalk2',
    subtitle: '18 phonts',
    badge: '18 voices',
    kind: 'tts',
    voiceLabel: 'Voice (phont)',
    textLabel: 'Kana symbols (hiragana / katakana)',
    description:
      'Recompiled from the evaluation build of libAquesTalk2Eva.so.2.3. 18 switchable phonts; 8 kHz / 16-bit / mono WAV.',
    voices: AQTK2_VOICES,
    defaultVoice: '',
    samples: KANA_SAMPLES,
  },
  {
    id: 'aqtk10',
    name: 'AquesTalk10',
    subtitle: '7 presets',
    badge: '7 presets',
    kind: 'tts',
    voiceLabel: 'Voice preset',
    textLabel: 'Kana symbols (hiragana / katakana)',
    description:
      'Recompiled from libAquesTalk10.so.1.1. Seven voice presets plus bas / vol / pit / acc / lmd / fsc parameters.',
    voices: AQTK10_VOICE_INFO,
    defaultVoice: 'F1',
    samples: KANA_SAMPLES,
    advanced: true,
  },
  {
    id: 'k2k',
    name: 'AqKanji2Koe',
    subtitle: 'kanji/kana → kana',
    badge: '4.1',
    kind: 'converter',
    voiceLabel: '',
    textLabel: 'Kanji/kana mixed text (UTF-8)',
    description:
      'wasm32 build of libAqKanji2Koe.so.4.1. Converts kanji/kana mixed text into AquesTalk kana symbols with accent marks.',
    voices: [],
    defaultVoice: '',
    samples: KANJI_SAMPLES,
  },
];

export function getEngineInfo(id) {
  const info = ENGINES.find((e) => e.id === id);
  if (!info) throw new Error(`unknown engine: ${id}`);
  return info;
}

/* ------------------------------------------------------------------ */
/* errors                                                              */
/* ------------------------------------------------------------------ */

export class EngineError extends Error {
  constructor(engine, code, message) {
    super(message || `${engine} error${code != null ? ` (${code})` : ''}`);
    this.name = 'EngineError';
    this.engine = engine;
    this.code = code;
  }
}

const ERROR_TEXT = {
  100: 'Buffer too small',
  101: 'Out of memory',
  102: 'Internal error',
  103: 'Kana symbol not found',
  104: 'Empty kana string',
  105: 'Invalid kana symbol string',
  106: 'Empty tag',
  107: 'Unclosed tag',
  109: 'Invalid argument',
  120: 'Internal buffer overflow',
  122: 'Output size limit exceeded',
  200: 'Phoneme buffer overflow',
  201: 'Phoneme list full',
  202: 'Chunk join failed',
  203: 'Work buffer allocation failed',
  204: 'Frame list full',
};

function errorText(code) {
  if (code == null) return '';
  return ERROR_TEXT[code] ? `${ERROR_TEXT[code]} (${code})` : `Error code ${code}`;
}

function throwEngineError(engine, code) {
  throw new EngineError(engine, code, `${engine} ${errorText(code)}`);
}

/* ------------------------------------------------------------------ */
/* helpers                                                             */
/* ------------------------------------------------------------------ */

const encoder = new TextEncoder();

async function instantiateWasm(url) {
  const res = await fetch(url);
  if (!res.ok) {
    throw new Error(`Could not fetch wasm: ${url} (${res.status})`);
  }
  const type = res.headers.get('content-type') || '';
  if (typeof WebAssembly.instantiateStreaming === 'function' &&
      type.includes('application/wasm')) {
    try {
      return (await WebAssembly.instantiateStreaming(res.clone(), {})).instance;
    } catch (_) {
      /* fall through to the ArrayBuffer path */
    }
  }
  return (await WebAssembly.instantiate(await res.arrayBuffer(), {})).instance;
}

async function fetchBytes(url, what) {
  const res = await fetch(url);
  if (!res.ok) {
    throw new Error(`Could not fetch ${what}: ${url} (${res.status})`);
  }
  return new Uint8Array(await res.arrayBuffer());
}

/* ------------------------------------------------------------------ */
/* AquesTalk1                                                          */
/* ------------------------------------------------------------------ */

async function makeAqtk1() {
  const instance = await instantiateWasm(asset('aquestalk1/dist/aquestalk1.wasm'));
  const aq = new AquesTalk1(instance);
  let current = null;

  return {
    id: 'aqtk1',
    async synth(text, { voice = 'f1', speed = 100 } = {}) {
      if (current !== voice) {
        if (!aq.select(voice)) {
          throw new EngineError('AquesTalk1', null, `Could not select voice ${voice}.`);
        }
        current = voice;
      }
      const wav = aq.synthe(text, speed);
      if (!wav) throwEngineError('AquesTalk1', aq.lastError);
      return wav;
    },
  };
}

/* ------------------------------------------------------------------ */
/* AquesTalk2                                                          */
/* ------------------------------------------------------------------ */

const phontCache = new Map();

async function loadPhont(name) {
  if (!name) return null;
  if (!phontCache.has(name)) {
    const bytes = await fetchBytes(
      asset(`aquestalk2/dist/phont/${name}`), `phont ${name}`);
    phontCache.set(name, bytes);
  }
  return phontCache.get(name);
}

async function makeAqtk2() {
  const aq = await createAquesTalk2(asset('aquestalk2/dist/aquestalk2-core.wasm'));

  return {
    id: 'aqtk2',
    async synth(text, { voice = '', speed = 100 } = {}) {
      const phont = await loadPhont(voice);
      const wav = phont
        ? aq.syntheWithPhont(text, speed, phont)
        : aq.synthe(text, speed);
      if (!wav) throwEngineError('AquesTalk2', aq.lastError());
      return wav;
    },
  };
}

/* ------------------------------------------------------------------ */
/* AquesTalk10                                                         */
/* ------------------------------------------------------------------ */

async function makeAqtk10() {
  const tts = await AquesTalk10.load(asset('aquestalk10/port/web/aqtk10.wasm'));

  return {
    id: 'aqtk10',
    async synth(text, { voice = 'F1', speed = 100, params = {} } = {}) {
      const preset = AQTK10_VOICES[voice] || AQTK10_VOICES.F1;
      const merged = { ...preset, ...params, spd: speed };
      try {
        return tts.synthe(text, merged);
      } catch (e) {
        if (e instanceof AquesTalkError) {
          throw new EngineError('AquesTalk10', e.code, `AquesTalk10 ${e.message} (code ${e.code})`);
        }
        throw e;
      }
    },
  };
}

/* ------------------------------------------------------------------ */
/* AqKanji2Koe                                                         */
/* ------------------------------------------------------------------ */

const K2K_OUT_CAP = 128 * 1024;
const K2K_CALL_LIMIT = 32; // the wasm32 build uses an arena allocator

class Kanji2Koe {
  constructor(wasm, sys, user, lookup) {
    this.wasm = wasm;
    this.sys = sys;
    this.user = user;
    this.lookup = lookup;
    this.e = null;
    this.h = 0;
    this.calls = 0;
    this.chain = Promise.resolve();
  }

  _enqueue(fn) {
    const run = this.chain.then(fn, fn);
    this.chain = run.then(() => {}, () => {});
    return run;
  }

  async _boot() {
    const { instance } = await WebAssembly.instantiate(this.wasm, {});
    const e = instance.exports;
    e.aq_init();

    const alloc = (bytes) => {
      const p = e.aq_alloc(bytes.length);
      if (!p) throw new EngineError('AqKanji2Koe', 101, 'Could not allocate wasm memory.');
      new Uint8Array(e.memory.buffer).set(bytes, p);
      return p;
    };

    const sysPtr = alloc(this.sys);
    const userPtr = alloc(this.user);
    const lookupPtr = alloc(this.lookup);

    const lookupRc = e.aq_set_lookup(lookupPtr, this.lookup.length);
    if (lookupRc) {
      throw new EngineError('AqKanji2Koe', lookupRc,
        'Could not initialise lookup.bin (check that it matches aqdic.bin).');
    }

    const errPtr = e.aq_alloc(4);
    if (!errPtr) throw new EngineError('AqKanji2Koe', 101, 'Could not allocate wasm memory.');
    const h = e.aq_create(sysPtr, userPtr, errPtr);
    const err = new DataView(e.memory.buffer).getInt32(errPtr, true);
    if (!h || err) {
      throw new EngineError('AqKanji2Koe', err || 101,
        `Could not load the dictionaries${err ? ` (code ${err})` : ''}.`);
    }

    this.e = e;
    this.h = h;
    this.calls = 0;
  }

  _convert(kind, text) {
    return this._enqueue(async () => {
      if (!this.e || this.calls >= K2K_CALL_LIMIT) await this._boot();

      const e = this.e;
      const input = encoder.encode(text);
      const inPtr = e.aq_alloc(input.length + 1);
      const outPtr = e.aq_alloc(K2K_OUT_CAP);
      if (!inPtr || !outPtr) {
        if (inPtr) e.aq_free(inPtr);
        if (outPtr) e.aq_free(outPtr);
        throw new EngineError('AqKanji2Koe', 101, 'Could not allocate wasm memory.');
      }

      let bytes = new Uint8Array(e.memory.buffer);
      bytes.set(input, inPtr);
      bytes[inPtr + input.length] = 0;

      const rc = kind === 'roman'
        ? e.aq_conv_roman(this.h, inPtr, outPtr, K2K_OUT_CAP)
        : e.aq_convert(this.h, inPtr, outPtr, K2K_OUT_CAP);

      let out = '';
      if (!rc) {
        bytes = new Uint8Array(e.memory.buffer);
        let end = outPtr;
        while (end < outPtr + K2K_OUT_CAP && bytes[end]) end++;
        out = new TextDecoder().decode(bytes.subarray(outPtr, end));
      }

      e.aq_free(inPtr);
      e.aq_free(outPtr);
      this.calls++;

      if (rc) {
        throw new EngineError('AqKanji2Koe', rc,
          `AqKanji2Koe conversion error (code ${rc}).`);
      }
      return out;
    });
  }

  convert(text) { return this._convert('kana', text); }
  convertRoman(text) { return this._convert('roman', text); }
}

export async function loadKanji2Koe() {
  let wasm, sys, user, lookup;
  try {
    [wasm, sys, user, lookup] = await Promise.all([
      fetchBytes(asset('aqk2k/port/build-wasm32/aqk2k32.wasm'), 'AqKanji2Koe wasm'),
      fetchBytes(asset('aqk2k/aqk2k_lnx/aq_dic/aqdic.bin'), 'aqdic.bin'),
      fetchBytes(asset('aqk2k/aqk2k_lnx/aq_dic/aq_user.dic'), 'aq_user.dic'),
      fetchBytes(asset('aqk2k/aqk2k_lnx/aq_dic/lookup.bin'), 'lookup.bin'),
    ]);
  } catch (e) {
    throw new EngineError('AqKanji2Koe', null,
      `Could not load the AqKanji2Koe dictionaries. Place aqdic.bin and lookup.bin in ` +
      `engines/aqk2k/aqk2k_lnx/aq_dic/. (${e.message})`);
  }
  const k2k = new Kanji2Koe(wasm, sys, user, lookup);
  await k2k._boot();
  return k2k;
}

/* ------------------------------------------------------------------ */
/* cache + factories                                                   */
/* ------------------------------------------------------------------ */

const cache = new Map();

export function loadEngine(id) {
  if (!cache.has(id)) {
    let factory;
    if (id === 'aqtk1') factory = makeAqtk1;
    else if (id === 'aqtk2') factory = makeAqtk2;
    else if (id === 'aqtk10') factory = makeAqtk10;
    else throw new Error(`unknown engine: ${id}`);

    const p = factory().catch((e) => {
      cache.delete(id);
      throw e;
    });
    cache.set(id, p);
  }
  return cache.get(id);
}

export function clearEngineCache() {
  cache.clear();
}
