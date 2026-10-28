#!/usr/bin/env node
/* AqUsrDic_Check wasm32 test against captured native .so results. */
import { readFileSync } from 'node:fs';
const root = new URL('./', import.meta.url);
const wasm = readFileSync(new URL('build-wasm32/aqusr_check.wasm', root));
const cases = JSON.parse(readFileSync(new URL('tests/check_cases.json', root), 'utf8'));
const expected = JSON.parse(readFileSync(new URL('tests/check_expected.json', root), 'utf8'));
const { instance } = await WebAssembly.instantiate(wasm, {});
const e = instance.exports;
e.aus_init();
const enc = new TextEncoder(), dec = new TextDecoder();
function put(s) {
  const b = enc.encode(s);
  const p = e.aq_alloc(b.length + 1);
  const u8 = new Uint8Array(e.memory.buffer);
  u8.set(b, p);
  u8[p + b.length] = 0;
  return p;
}
let bad = 0;
for (let i = 0; i < cases.length; i++) {
  const rc = e.aus_check(put(cases[i].surface), put(cases[i].yomi), cases[i].pos);
  let err = '';
  if (rc !== 0) {
    const ep = e.aus_error();
    const u8 = new Uint8Array(e.memory.buffer);
    let end = ep;
    while (u8[end]) end++;
    err = dec.decode(u8.subarray(ep, end));
  }
  if (rc !== expected[i].rc || (rc !== 0 && err !== expected[i].err)) {
    bad++;
    console.log('DIFF', i, cases[i], { rc, err }, expected[i]);
  }
}
console.log(`AqUsrDic_Check wasm32: ${cases.length - bad}/${cases.length} match`);
process.exit(bad ? 1 : 0);
