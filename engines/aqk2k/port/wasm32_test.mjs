import { readFileSync } from 'node:fs';
const mod = await WebAssembly.instantiate(readFileSync(new URL('./build-wasm32/aqk2k32.wasm', import.meta.url)), {});
const e = mod.instance.exports;
const mem = e.memory;
let u8 = new Uint8Array(mem.buffer);
const alloc = (b) => { const p = e.aq_alloc(b.length); if (!p) throw new Error('alloc'); u8.set(b, p); return p; };
const dir = new URL('../aqk2k_lnx/aq_dic/', import.meta.url);
const sys = readFileSync(new URL('aqdic.bin', dir));
const user = readFileSync(new URL('aq_user.dic', dir));
const lookup = readFileSync(new URL('lookup.bin', dir));
const sp = alloc(sys), up = alloc(user), lp = alloc(lookup);
console.log('lookup', e.aq_set_lookup(lp, lookup.length));
const errP = e.aq_alloc(4);
const h = e.aq_create(sp, up, errP);
console.log('handle', h, 'err', new DataView(mem.buffer).getInt32(errP, true));
if (!h) process.exit(1);
const enc = new TextEncoder(), dec = new TextDecoder();
for (const text of ['テスト','こんにちは','東京','私','日本語','音声','あ','漢字','音声合成テスト','三日月','おはようございます']) {
  const inP = alloc(enc.encode(text));
  const outP = e.aq_alloc(65536);
  const r = e.aq_convert(h, inP, outP, 65536);
  u8 = new Uint8Array(mem.buffer);
  let end = outP; while (u8[end]) end++;
  console.log(text, '=>', dec.decode(u8.subarray(outP, end)), 'rc', r);
}
// ConvRoman walks a 16-byte {kana, roman} table; wasm32 needs an explicit
// stride (see port/tools/gen_wasm32.py).  Guard that path here.
const romanIn = alloc(enc.encode('音声合成テスト。'));
const romanOut = e.aq_alloc(65536);
const rr = e.aq_conv_roman(h, romanIn, romanOut, 65536);
u8 = new Uint8Array(mem.buffer);
let rend = romanOut; while (u8[rend]) rend++;
const roman = dec.decode(u8.subarray(romanOut, rend));
console.log('roman =>', roman, 'rc', rr);
if (rr !== 0 || roman !== "onnse-go-se-te'_suto.") process.exit(1);

e.aq_release(h);
