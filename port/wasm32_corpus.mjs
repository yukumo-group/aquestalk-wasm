// Run a UTF-8 line corpus through the wasm32 build in fresh batches.
// A fresh instance per 40 lines avoids the arena-allocator growth limit.
import { readFileSync } from 'node:fs';

const wasmBytes = readFileSync(new URL('./build-wasm32/aqk2k32.wasm', import.meta.url));
const dir = new URL('../aqk2k_lnx/aq_dic/', import.meta.url);
const sys = readFileSync(new URL('aqdic.bin', dir));
const user = readFileSync(new URL('aq_user.dic', dir));
const lookup = readFileSync(new URL('lookup.bin', dir));
const enc = new TextEncoder(), dec = new TextDecoder();

let lines = readFileSync(process.argv[2], 'utf8').split('\n');
if (lines[lines.length - 1] === '') lines.pop();

async function runBatch(batch) {
  const e = (await WebAssembly.instantiate(wasmBytes, {})).instance.exports;
  const mem = e.memory;
  let u8 = new Uint8Array(mem.buffer);
  const alloc = (b) => { const p = e.aq_alloc(b.length); if (!p) throw new Error('alloc'); u8.set(b, p); return p; };
  const sp = alloc(sys), up = alloc(user), lp = alloc(lookup);
  if (e.aq_set_lookup(lp, lookup.length)) throw new Error('lookup');
  const errP = e.aq_alloc(4);
  const h = e.aq_create(sp, up, errP);
  if (!h) throw new Error('create ' + new DataView(mem.buffer).getInt32(errP, true));
  const outP = e.aq_alloc(65536);
  const out = [];
  for (const text of batch) {
    const inP = alloc(enc.encode(text));
    const r = e.aq_convert(h, inP, outP, 65536);
    u8 = new Uint8Array(mem.buffer);
    if (r !== 0) { out.push('<ERR ' + r + '>'); continue; }
    let end = outP; while (u8[end]) end++;
    out.push(dec.decode(u8.subarray(outP, end)));
  }
  e.aq_release(h);
  return out;
}

const out = [];
for (let i = 0; i < lines.length; i += 40)
  out.push(...await runBatch(lines.slice(i, i + 40)));
console.log(out.join('\n'));
