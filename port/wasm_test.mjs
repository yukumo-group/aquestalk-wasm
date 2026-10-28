import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';

const wasmPath = new URL('./build-wasm/aqk2k.wasm', import.meta.url);
const mod = await WebAssembly.instantiate(readFileSync(wasmPath), {});
const e = mod.instance.exports;
console.log('exports:', Object.keys(e));
const mem = e.memory;
let u8 = new Uint8Array(mem.buffer);

function alloc(bytes) {
  const p = e.aq_alloc(BigInt(bytes.length));
  if (p === 0n) throw new Error('alloc failed');
  u8.set(bytes, Number(p));
  return p;
}

const dicDir = new URL('../aqk2k_lnx/aq_dic/', import.meta.url);
const sys = readFileSync(new URL('aqdic.bin', dicDir));
const user = readFileSync(new URL('aq_user.dic', dicDir));
const lookup = readFileSync(new URL('lookup.bin', dicDir));
console.log('sizes', sys.length, user.length, lookup.length);

const sysP = alloc(sys);
const userP = alloc(user);
const lookupP = alloc(lookup);
const lr = e.aq_set_lookup(lookupP, lookup.length);
console.log('set_lookup', lr);

const errP = e.aq_alloc(4n);
const h = e.aq_create(sysP, userP, errP);
u8 = new Uint8Array(mem.buffer);
const err = new DataView(mem.buffer).getInt32(Number(errP), true);
console.log('handle', h, 'err', err);
if (h === 0n) process.exit(1);

const enc = new TextEncoder(), dec = new TextDecoder();
for (const text of ['テスト','こんにちは','東京','私','日本語','音声','あ','漢字','音声合成テスト','三日月','おはようございます']) {
  const inBytes = enc.encode(text);
  const inP = alloc(inBytes);
  const outP = e.aq_alloc(65536n);
  const r = e.aq_convert(h, inP, outP, 65536);
  u8 = new Uint8Array(mem.buffer);
  let end = Number(outP);
  while (u8[end]) end++;
  const out = dec.decode(u8.subarray(Number(outP), end));
  console.log(text, '=>', out, 'rc', r);
  e.aq_free(inP); e.aq_free(outP);
}
e.aq_release(h);
