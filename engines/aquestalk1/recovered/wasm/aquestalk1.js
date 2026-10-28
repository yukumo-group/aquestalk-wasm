/*
 * Minimal ES module wrapper for dist/aquestalk1.wasm.
 *
 *   import { AquesTalk1 } from './aquestalk1.js';
 *   const aq = await AquesTalk1.load('./aquestalk1.wasm');
 *   aq.select('f2');
 *   const wav = aq.synthe('こんにちは', 100);   // Uint8Array | null
 */

export class AquesTalk1 {
    static async load(url) {
        const response = await fetch(url);
        const { instance } = await WebAssembly.instantiateStreaming(response, {});
        return new AquesTalk1(instance);
    }

    static async loadFile(buffer) {
        const { instance } = await WebAssembly.instantiate(buffer, {});
        return new AquesTalk1(instance);
    }

    constructor(instance) {
        this.x = instance.exports;
        this.lastError = 0;
    }

    _mem() {
        return new Uint8Array(this.x.memory.buffer);
    }

    _cstr(ptr) {
        const mem = this._mem();
        let end = ptr;
        while (mem[end]) end++;
        return new TextDecoder().decode(mem.subarray(ptr, end));
    }

    voices() {
        const n = this.x.aq_voice_count();
        const out = [];
        for (let i = 0; i < n; i++) out.push(this._cstr(this.x.aq_voice_name(i)));
        return out;
    }

    select(name) {
        const bytes = new TextEncoder().encode(name);
        const ptr = this.x.aq_alloc(bytes.length + 1);
        if (!ptr) return false;
        this._mem().set(bytes, ptr);
        this._mem()[ptr + bytes.length] = 0;
        const rc = this.x.aq_select_voice(ptr);
        this.x.aq_free(ptr);
        return rc === 0;
    }

    /* UTF-8 text -> complete WAV file, or null (see lastError). */
    synthe(text, speed = 100) {
        const bytes = new TextEncoder().encode(text);
        const str = this.x.aq_alloc(bytes.length + 1);
        const sizePtr = this.x.aq_alloc(4);
        if (!str || !sizePtr) {
            if (str) this.x.aq_free(str);
            if (sizePtr) this.x.aq_free(sizePtr);
            this.lastError = 101;
            return null;
        }
        this._mem().set(bytes, str);
        this._mem()[str + bytes.length] = 0;
        const wav = this.x.aq_synthe_utf8(str, speed, sizePtr);
        const size = new Int32Array(this.x.memory.buffer, sizePtr, 1)[0];
        let out = null;
        if (wav) {
            out = this._mem().slice(wav, wav + size);
            this.x.aq_free_wave(wav);
            this.lastError = 0;
        } else {
            this.lastError = size;
        }
        this.x.aq_free(str);
        this.x.aq_free(sizePtr);
        return out;
    }
}

export default AquesTalk1;
