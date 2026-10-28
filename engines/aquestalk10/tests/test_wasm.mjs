/* Node test for the raw wasm build.  No Emscripten runtime is involved. */
import fs from 'fs';
import crypto from 'crypto';

const root = new URL('..', import.meta.url);
const wasmBytes = fs.readFileSync(new URL('port/web/aqtk10.wasm', root));
const cases = JSON.parse(fs.readFileSync(new URL('tests/cases.json', root), 'utf8'));

const mod = await WebAssembly.compile(wasmBytes);
if (WebAssembly.Module.imports(mod).length)
    throw new Error('wasm module unexpectedly has imports');
const instance = await WebAssembly.instantiate(mod, {});
const e = instance.exports;
e.aqtk_init();

const mem = () => new Uint8Array(e.memory.buffer);
const dv = () => new DataView(e.memory.buffer);

function putBytes(u8) {
    const p = e.aqtk_malloc(u8.length + 2);
    if (!p) throw new Error('out of memory');
    mem().set(u8, p);
    mem()[p + u8.length] = 0;
    mem()[p + u8.length + 1] = 0;
    return p;
}
function putString(s) { return putBytes(new TextEncoder().encode(s)); }
function putVoice(v) {
    const p = e.aqtk_malloc(28);
    const d = dv();
    for (let i = 0; i < 7; i++) d.setInt32(p + i * 4, v[i], true);
    return p;
}
function takeWave(ptr, sizePtr) {
    const n = dv().getInt32(sizePtr, true);
    if (!ptr) return { error: n, data: null };
    const data = mem().slice(ptr, ptr + n);
    e.aqtk_free_wave(ptr);
    return { error: 0, data };
}
function synthUtf8(text, voice) {
    const koe = putString(text);
    const sp = e.aqtk_malloc(4);
    const ptr = e.aqtk_synthe_utf8_default(koe, ...voice, sp);
    const r = takeWave(ptr, sp);
    e.aqtk_free(koe); e.aqtk_free(sp);
    return r;
}
function synthBytes(bytes, voice, mode) {
    const koe = putBytes(bytes);
    const vp = putVoice(voice);
    const sp = e.aqtk_malloc(4);
    const fn = mode === 'sjis' ? e.aqtk_synthe_sjis : e.aqtk_synthe_utf16;
    const ptr = fn(vp, koe, sp);
    const r = takeWave(ptr, sp);
    e.aqtk_free(vp); e.aqtk_free(koe); e.aqtk_free(sp);
    return r;
}
const sha = (b) => crypto.createHash('sha256').update(b).digest('hex');

let ok = 0, bad = 0;
for (const c of cases) {
    const sj = Buffer.from(c.sjis, 'base64');
    const u16 = Buffer.from(c.utf16, 'base64');
    for (const [mode, fn] of [['utf8', () => synthUtf8(c.text, c.voice)],
                              ['sjis', () => synthBytes(sj, c.voice, 'sjis')],
                              ['utf16', () => synthBytes(u16, c.voice, 'utf16')]]) {
        const r = fn();
        if (!r.data || r.data.length !== c.size || sha(r.data) !== c.sha256) {
            console.log('FAIL', c.name, mode, r.error, r.data && r.data.length);
            bad++;
        } else ok++;
    }
}
console.log(`wasm corpus: ${ok} ok, ${bad} bad`);

// error paths
{
    const sp = e.aqtk_malloc(4);
    const empty = putBytes(new Uint8Array(0));
    const p = e.aqtk_synthe_utf8_default(empty, 0, 100, 100, 100, 100, 100, 100, sp);
    const err = dv().getInt32(sp, true);
    console.log('empty string ->', p, err, (p === 0 && err === 0x68) ? 'OK' : 'BAD');
    const p2 = e.aqtk_synthe_utf8(0, empty, sp);
    console.log('null voice ->', p2, dv().getInt32(sp, true),
                (p2 === 0 && dv().getInt32(sp, true) === 0x6d) ? 'OK' : 'BAD');
    e.aqtk_free(empty); e.aqtk_free(sp);
}
{
    const badKey = putString('not-a-real-key');
    console.log('SetDevKey(invalid) =', e.aqtk_set_dev_key(badKey));
    console.log('SetUsrKey(invalid) =', e.aqtk_set_usr_key(badKey));
    e.aqtk_free(badKey);
}
// a long input, to exercise memory growth / reuse
{
    const long = 'こんにちは、'.repeat(200);
    const t0 = Date.now();
    const r = synthUtf8(long, [0, 100, 100, 100, 100, 100, 100]);
    console.log('long input:', r.data ? r.data.length : 'ERR ' + r.error,
                'bytes in', Date.now() - t0, 'ms, mem MB',
                (e.memory.buffer.byteLength / 1048576).toFixed(1));
}
if (bad) process.exit(1);
