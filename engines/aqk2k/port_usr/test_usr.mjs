#!/usr/bin/env node
/* AqUsrDic wasm32: Check + memory-buffer Import/Export. */
import { readFileSync, writeFileSync } from 'node:fs';
const root = new URL('./', import.meta.url);
const wasm = readFileSync(new URL('build-wasm32/aqusr.wasm', root));
const { instance } = await WebAssembly.instantiate(wasm, {});
const e = instance.exports;
const mem = () => new Uint8Array(e.memory.buffer);
const enc = new TextEncoder(), dec = new TextDecoder();
const alloc = (n) => { const p = e.aq_alloc(n); if (!p) throw new Error('alloc ' + n); return p; };
const putBytes = (b) => { const p = alloc(b.length); mem().set(b, p); return p; };
const putStr = (s) => putBytes(enc.encode(s));
function getStr(p) { const m = mem(); let q = p; while (m[q]) q++; return dec.decode(m.subarray(p, q)); }
const CSV = readFileSync(new URL('tests/sample.csv', root), 'utf8');
const CSV_LINES = new Set(CSV.trim().split('\n'));
const lit = (s) => s.trim().split('\n').sort().join('\n');

e.aus_init();
const sys = readFileSync(new URL('../aqk2k_lnx/aq_dic/aqdic.bin', root));
const sp = putBytes(sys);
let rc = e.aus_set_system_dic(sp, sys.length);
console.log('set_system_dic:', rc, getStr(e.aus_error()));
const cap = 1024 * 1024;
const out = alloc(cap), outLenPtr = alloc(4), ex = alloc(cap), exLenPtr = alloc(4);

const cp = putStr(CSV);
rc = e.aus_import(cp, enc.encode(CSV).length, out, cap, outLenPtr);
const dicLen = new DataView(e.memory.buffer).getUint32(outLenPtr, true);
console.log('import sample:', rc, dicLen, getStr(e.aus_error()));
writeFileSync(new URL('build-wasm32/wasm_user.dic', root), mem().subarray(out, out + dicLen));

rc = e.aus_export(out, dicLen, ex, cap, exLenPtr);
let exLen = new DataView(e.memory.buffer).getUint32(exLenPtr, true);
const round = dec.decode(mem().subarray(ex, ex + exLen));
console.log('export roundtrip:', rc, exLen, 'lines-equal:', lit(round) === lit(CSV));

const origDic = readFileSync(new URL('../aqk2k_lnx/aq_dic/aq_user.dic', root));
const op = putBytes(origDic);
rc = e.aus_export(op, origDic.length, ex, cap, exLenPtr);
exLen = new DataView(e.memory.buffer).getUint32(exLenPtr, true);
const origOut = dec.decode(mem().subarray(ex, ex + exLen));
console.log('export original:', rc, exLen, 'lines-equal:', lit(origOut) === lit(CSV));

const cases = JSON.parse(readFileSync(new URL('tests/check_cases.json', root), 'utf8'));
const expected = JSON.parse(readFileSync(new URL('tests/check_expected.json', root), 'utf8'));
let bad = 0;
for (let i = 0; i < cases.length; i++) {
  const r = e.aus_check(putStr(cases[i].surface), putStr(cases[i].yomi), cases[i].pos);
  let err = '';
  if (r !== 0) { const ep = e.aus_error(); err = getStr(ep); }
  if (r !== expected[i].rc || (r !== 0 && err !== expected[i].err)) {
    bad++; console.log('check DIFF', i, cases[i], { r, err }, expected[i]);
  }
}
console.log(`check: ${cases.length - bad}/${cases.length}`);
process.exit((bad || lit(round) !== lit(CSV)) ? 1 : 0);
