/* aqtk10.js -- hand-written JS glue for the raw wasm build.
 *
 * There is no Emscripten runtime and no embind: the module only exports
 * plain C functions and its linear memory.  This file marshals strings,
 * copies the WAV out and frees the native buffers again.
 */

export const VOICES = {
  F1: { bas: 0, spd: 100, vol: 100, pit: 100, acc: 100, lmd: 100, fsc: 100 },
  F2: { bas: 1, spd: 100, vol: 100, pit: 77,  acc: 150, lmd: 100, fsc: 100 },
  F3: { bas: 0, spd: 80,  vol: 100, pit: 100, acc: 100, lmd: 61,  fsc: 148 },
  M1: { bas: 2, spd: 100, vol: 100, pit: 30,  acc: 100, lmd: 100, fsc: 100 },
  M2: { bas: 2, spd: 105, vol: 100, pit: 45,  acc: 130, lmd: 120, fsc: 100 },
  R1: { bas: 2, spd: 100, vol: 100, pit: 30,  acc: 20,  lmd: 190, fsc: 100 },
  R2: { bas: 1, spd: 70,  vol: 100, pit: 50,  acc: 50,  lmd: 50,  fsc: 180 },
};

const ERRORS = {
  100: 'buffer too small',
  101: 'out of memory',
  103: 'kana symbol not found',
  104: 'empty kana string',
  105: 'invalid kana symbol',
  109: 'invalid argument',
  120: 'internal buffer overflow',
};

export class AquesTalkError extends Error {
  constructor(code, message) {
    super(message || ERRORS[code] || `AquesTalk error ${code}`);
    this.name = 'AquesTalkError';
    this.code = code;
  }
}

function normalizeVoice(voice) {
  if (Array.isArray(voice)) {
    voice = { bas: voice[0], spd: voice[1], vol: voice[2], pit: voice[3],
              acc: voice[4], lmd: voice[5], fsc: voice[6] };
  }
  const v = voice ? { ...voice } : {};
  const pick = (k, d) => (Number.isFinite(v[k]) ? v[k] | 0 : d);
  return {
    bas: Math.max(0, Math.min(2, pick('bas', 0))),
    spd: pick('spd', 100),
    vol: pick('vol', 100),
    pit: pick('pit', 100),
    acc: pick('acc', 100),
    lmd: pick('lmd', 100),
    fsc: pick('fsc', 100),
  };
}

export class AquesTalk10 {
  constructor(instance) {
    this.instance = instance;
    this.e = instance.exports;
    this.e.aqtk_init();
    this._utf8 = new TextEncoder();
    this.lastError = 0;
  }

  /** Browser: fetch + instantiate. */
  static async load(url) {
    const bytes = await (await fetch(url)).arrayBuffer();
    return AquesTalk10.fromBytes(bytes);
  }

  /** Node or bundled bytes: instantiate an ArrayBuffer/Uint8Array. */
  static async fromBytes(bytes) {
    const { instance } = await WebAssembly.instantiate(
      bytes instanceof Uint8Array ? bytes : new Uint8Array(bytes), {});
    return new AquesTalk10(instance);
  }

  get memory() { return this.e.memory; }

  _u8() { return new Uint8Array(this.e.memory.buffer); }
  _i32() { return new DataView(this.e.memory.buffer); }

  _alloc(n) {
    const p = this.e.aqtk_malloc(n);
    if (!p) throw new AquesTalkError(101);
    return p;
  }

  _put(bytes) {
    const p = this._alloc(bytes.length + 2);
    this._u8().set(bytes, p);
    this._u8()[p + bytes.length] = 0;
    this._u8()[p + bytes.length + 1] = 0;
    return p;
  }

  _putVoice(voice) {
    const v = normalizeVoice(voice);
    const p = this._alloc(28);
    const d = this._i32();
    d.setInt32(p + 0, v.bas, true);
    d.setInt32(p + 4, v.spd, true);
    d.setInt32(p + 8, v.vol, true);
    d.setInt32(p + 12, v.pit, true);
    d.setInt32(p + 16, v.acc, true);
    d.setInt32(p + 20, v.lmd, true);
    d.setInt32(p + 24, v.fsc, true);
    return { ptr: p, v };
  }

  _take(ptr, sizePtr) {
    const size = this._i32().getInt32(sizePtr, true);
    if (!ptr) {
      this.lastError = size;
      throw new AquesTalkError(size);
    }
    const out = this._u8().slice(ptr, ptr + size);
    this.e.aqtk_free_wave(ptr);
    this.lastError = 0;
    return out;
  }

  /** Synthesize from a UTF-8 JS string. Returns a copy of the WAV bytes. */
  synthe(text, voice) {
    const v = normalizeVoice(voice);
    const koe = this._put(this._utf8.encode(String(text)));
    const sizePtr = this._alloc(4);
    try {
      const wavPtr = this.e.aqtk_synthe_utf8_default(
        koe, v.bas, v.spd, v.vol, v.pit, v.acc, v.lmd, v.fsc, sizePtr);
      return this._take(wavPtr, sizePtr);
    } finally {
      this.e.aqtk_free(koe);
      this.e.aqtk_free(sizePtr);
    }
  }

  /** Synthesize from raw Shift-JIS bytes (Uint8Array/Array). */
  syntheSjis(bytes, voice) {
    const { ptr: vp } = this._putVoice(voice);
    const koe = this._put(bytes instanceof Uint8Array ? bytes : Uint8Array.from(bytes));
    const sizePtr = this._alloc(4);
    try {
      return this._take(this.e.aqtk_synthe_sjis(vp, koe, sizePtr), sizePtr);
    } finally {
      this.e.aqtk_free(koe);
      this.e.aqtk_free(vp);
      this.e.aqtk_free(sizePtr);
    }
  }

  /** Synthesize from UTF-16 code units (JS string or Uint16Array). */
  syntheUtf16(text, voice) {
    let units;
    if (typeof text === 'string') {
      units = new Uint16Array(text.length);
      for (let i = 0; i < text.length; i++) units[i] = text.charCodeAt(i);
    } else {
      units = text instanceof Uint16Array ? text : Uint16Array.from(text);
    }
    const { ptr: vp } = this._putVoice(voice);
    const koe = this._put(new Uint8Array(units.buffer, units.byteOffset, units.byteLength));
    const sizePtr = this._alloc(4);
    try {
      return this._take(this.e.aqtk_synthe_utf16(vp, koe, sizePtr), sizePtr);
    } finally {
      this.e.aqtk_free(koe);
      this.e.aqtk_free(vp);
      this.e.aqtk_free(sizePtr);
    }
  }

  /** Development license key; returns 0 on success (see AquesTalk docs). */
  setDevKey(key) { return this._withString(key, (p) => this.e.aqtk_set_dev_key(p)); }
  /** Usage/content license key; returns 0 on success. */
  setUsrKey(key) { return this._withString(key, (p) => this.e.aqtk_set_usr_key(p)); }

  _withString(s, fn) {
    const p = this._put(this._utf8.encode(String(s)));
    try { return fn(p); } finally { this.e.aqtk_free(p); }
  }
}
