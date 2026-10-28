/* aquestalk2.js -- hand written host wrapper for the raw WebAssembly build.
 *
 * The module is produced by clang --target=wasm32 + wasm-ld with -nostdlib:
 * it has no imports at all, so instantiation is just
 * `WebAssembly.instantiate(bytes, {})`.  This file only marshals strings /
 * byte arrays in and WAV bytes out.
 */

const encoder = new TextEncoder();

async function instantiate(source) {
  if (source instanceof WebAssembly.Module)
    return new WebAssembly.Instance(source, {});
  if (source instanceof ArrayBuffer || ArrayBuffer.isView(source))
    return (await WebAssembly.instantiate(source, {})).instance;

  const url = source instanceof URL ? source : new URL(source, import.meta.url);

  /* Node can read the file directly; browsers use fetch(). */
  if (url.protocol === 'file:') {
    const fs = await import('node:fs/promises');
    const bytes = await fs.readFile(url);
    return (await WebAssembly.instantiate(bytes, {})).instance;
  }

  const resp = await fetch(url);
  if (!resp.ok)
    throw new Error(`failed to fetch ${url}: ${resp.status}`);
  const type = resp.headers.get('content-type') || '';
  if (typeof WebAssembly.instantiateStreaming === 'function' &&
      type.includes('application/wasm')) {
    return (await WebAssembly.instantiateStreaming(resp, {})).instance;
  }
  return (await WebAssembly.instantiate(await resp.arrayBuffer(), {})).instance;
}

export async function createAquesTalk2(source = 'aquestalk2-core.wasm') {
  const instance = await instantiate(source);
  return new AquesTalk2(instance.exports);
}

export class AquesTalk2 {
  constructor(exports) {
    this.e = exports;
    this.SAMPLE_RATE = exports.aq_sample_rate();
    this._raw = exports;
  }

  /** Error code of the most recent failed synthesis (0 if none). */
  lastError() {
    return this.e.aq_last_error();
  }

  _mem() {
    return new Uint8Array(this.e.memory.buffer);
  }

  _alloc(n) {
    const p = this.e.aq_malloc(n);
    if (!p)
      throw new Error('AquesTalk2: out of WebAssembly memory');
    return p;
  }

  /* kind 0: byte string, 1: UTF-16 code units */
  _synth(exportName, text, speed, phont, utf16) {
    const e = this.e;
    let textPtr = 0;
    let phontPtr = 0;
    let sizePtr = 0;
    let wavPtr = 0;
    try {
      const count = utf16 ? text.length : text.length;
      textPtr = this._alloc(utf16 ? count * 2 + 2 : count + 1);
      if (phont && phont.length)
        phontPtr = this._alloc(phont.length);
      sizePtr = this._alloc(4);

      /* All allocations done: only now take views (memory may have grown). */
      if (utf16) {
        const units = new Uint16Array(e.memory.buffer, textPtr, count + 1);
        for (let i = 0; i < count; i++)
          units[i] = text[i] & 0xffff;
        units[count] = 0;
      } else {
        const mem = this._mem();
        mem.set(text, textPtr);
        mem[textPtr + count] = 0;
      }
      if (phontPtr)
        this._mem().set(phont, phontPtr);
      new Int32Array(e.memory.buffer, sizePtr, 1)[0] = 0;

      wavPtr = e[exportName](textPtr, speed | 0, sizePtr, phontPtr);
      const size = new Int32Array(e.memory.buffer, sizePtr, 1)[0];
      if (!wavPtr)
        return null;
      const wav = new Uint8Array(e.memory.buffer, wavPtr, size).slice();
      e.AquesTalk2_FreeWave(wavPtr);
      wavPtr = 0;
      return wav;
    } finally {
      if (wavPtr)
        e.AquesTalk2_FreeWave(wavPtr);
      if (sizePtr)
        e.aq_free(sizePtr);
      if (phontPtr)
        e.aq_free(phontPtr);
      if (textPtr)
        e.aq_free(textPtr);
    }
  }

  _utf8(str) {
    return encoder.encode(str);
  }

  _latin1Bytes(str) {
    const out = new Uint8Array(str.length);
    for (let i = 0; i < str.length; i++)
      out[i] = str.charCodeAt(i) & 0xff;
    return out;
  }

  _u8(data) {
    return data instanceof Uint8Array ? data : Uint8Array.from(data);
  }

  /** UTF-8 kana text -> complete WAV file (Uint8Array) or null. */
  synthe(text, speed = 100) {
    return this._synth('AquesTalk2_Synthe_Utf8', this._utf8(text), speed, null, false);
  }

  /** Same, with an external phont file (Uint8Array). */
  syntheWithPhont(text, speed, phont) {
    return this._synth('AquesTalk2_Synthe_Utf8', this._utf8(text), speed,
                       this._u8(phont), false);
  }

  /** Shift-JIS byte string. */
  syntheSjis(bytes, speed = 100, phont = null) {
    return this._synth('AquesTalk2_Synthe', this._u8(bytes), speed,
                       phont ? this._u8(phont) : null, false);
  }

  /** EUC-JP byte string. */
  syntheEuc(bytes, speed = 100, phont = null) {
    return this._synth('AquesTalk2_Synthe_Euc', this._u8(bytes), speed,
                       phont ? this._u8(phont) : null, false);
  }

  /** Romanised text (ASCII). */
  syntheRoman(text, speed = 100, phont = null) {
    return this._synth('AquesTalk2_Synthe_Roman', this._latin1Bytes(text), speed,
                       phont ? this._u8(phont) : null, false);
  }

  /** UTF-16 code units (Uint16Array or array of numbers). */
  syntheUtf16(units, speed = 100, phont = null) {
    return this._synth('AquesTalk2_Synthe_Utf16', units, speed,
                       phont ? this._u8(phont) : null, true);
  }
}
