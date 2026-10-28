#!/usr/bin/env node
/* Long-session / large-input soak test for the wasm32 AqKanji2Koe build.
 *
 *   node engines/aqk2k/tests/soak.mjs
 *
 * The runtime now recycles freed blocks, so one instance can serve an
 * unlimited number of conversions without the old "recreate every 32 calls"
 * workaround.  This test keeps the differential corpus running for several
 * passes, converts a large passage, checks the small-buffer error path, and
 * exercises handle release/recreate with borrowed dictionary buffers.
 */
import { readFileSync } from 'node:fs';
import assert from 'node:assert/strict';

const ROOT = new URL('../', import.meta.url);
const wasmBytes = readFileSync(new URL('port/build-wasm32/aqk2k32.wasm', ROOT));
const dic = new URL('aqk2k_lnx/aq_dic/', ROOT);
const sys = readFileSync(new URL('aqdic.bin', dic));
const user = readFileSync(new URL('aq_user.dic', dic));
const lookup = readFileSync(new URL('lookup.bin', dic));
const corpus = readFileSync(new URL('tests/corpus_diff.txt', ROOT), 'utf8')
  .split('\n').filter((s, i, a) => !(i === a.length - 1 && s === ''));
const expected = readFileSync(new URL('tests/expected64.txt', ROOT), 'utf8')
  .split('\n').slice(0, corpus.length);

const encoder = new TextEncoder();
const decoder = new TextDecoder();

const { instance } = await WebAssembly.instantiate(wasmBytes, {});
const e = instance.exports;
let u8 = new Uint8Array(e.memory.buffer);

function alloc(bytes) {
  const p = e.aq_alloc(bytes.length);
  assert.ok(p, `aq_alloc(${bytes.length})`);
  u8 = new Uint8Array(e.memory.buffer);
  u8.set(bytes, p);
  return p;
}

// Borrowed dictionary buffers: aq_release() must not free them.
const sysPtr = alloc(sys);
const userPtr = alloc(user);
const lookupPtr = alloc(lookup);
assert.equal(e.aq_set_lookup(lookupPtr, lookup.length), 0, 'lookup.bin');

const errPtr = e.aq_alloc(4);
const outCap = 4 * 1024 * 1024;
const outPtr = e.aq_alloc(outCap);

function create() {
  const h = e.aq_create(sysPtr, userPtr, errPtr);
  const err = new DataView(e.memory.buffer).getInt32(errPtr, true);
  assert.ok(h, `aq_create (${err})`);
  assert.equal(err, 0);
  return h;
}

function convert(h, text, cap = outCap) {
  const input = encoder.encode(text);
  const inPtr = e.aq_alloc(input.length + 1);
  assert.ok(inPtr, 'input allocation');
  u8 = new Uint8Array(e.memory.buffer);
  u8.set(input, inPtr);
  u8[inPtr + input.length] = 0;
  const rc = e.aq_convert(h, inPtr, outPtr, cap);
  u8 = new Uint8Array(e.memory.buffer);
  let end = outPtr;
  while (end < outPtr + cap && u8[end]) end++;
  const out = decoder.decode(u8.subarray(outPtr, end));
  e.aq_free(inPtr);
  return { rc, out };
}

function convertRoman(h, text, cap = outCap) {
  const input = encoder.encode(text);
  const inPtr = e.aq_alloc(input.length + 1);
  assert.ok(inPtr, 'roman input allocation');
  u8 = new Uint8Array(e.memory.buffer);
  u8.set(input, inPtr);
  u8[inPtr + input.length] = 0;
  const rc = e.aq_conv_roman(h, inPtr, outPtr, cap);
  u8 = new Uint8Array(e.memory.buffer);
  let end = outPtr;
  while (end < outPtr + cap && u8[end]) end++;
  const out = decoder.decode(u8.subarray(outPtr, end));
  e.aq_free(inPtr);
  return { rc, out };
}

const memMB = () => e.memory.buffer.byteLength / 1048576;
const startMB = memMB();
let h = create();

// 10 full corpus passes = 3030 conversions.
for (let pass = 0; pass < 10; pass++) {
  for (let i = 0; i < corpus.length; i++) {
    const r = convert(h, corpus[i]);
    assert.equal(r.rc, 0, `pass ${pass} #${i} rc`);
    assert.equal(r.out, expected[i], `pass ${pass} #${i} output`);
  }
}
const afterPassesMB = memMB();
assert.ok(afterPassesMB - startMB < 8,
  `memory grew ${(afterPassesMB - startMB).toFixed(1)} MiB over 3030 calls`);

// Roman conversion shares the same handle and allocator.
for (let i = 0; i < 500; i++) {
  const r = convertRoman(h, '音声合成テスト。');
  assert.equal(r.rc, 0, 'roman rc');
  assert.equal(r.out, "onnse-go-se-te'_suto.", 'roman output');
}
assert.ok(memMB() - startMB < 8, 'memory after roman loop');

// A long passage (24k characters) must complete without truncation.
const longText = '東京は日本の首都です。明日の天気は晴れでしょう。'.repeat(1000);
const long = convert(h, longText);
assert.equal(long.rc, 0, 'long conversion rc');
assert.ok(long.out.length > 40000, `long output length ${long.out.length}`);
assert.match(long.out, /トーキョー/);

// Too-small output buffer reports 0x69 instead of overflowing.
assert.equal(convert(h, longText, 64).rc, 0x69, 'small-buffer error');

// Release/recreate with borrowed buffers.
for (let i = 0; i < 10; i++) {
  e.aq_release(h);
  h = create();
  const r = convert(h, '音声合成テスト。');
  assert.equal(r.rc, 0);
  assert.equal(r.out, "オンセーゴーセーテ'_スト。");
}
e.aq_release(h);

assert.ok(memMB() - startMB < 64, 'final memory growth');
console.log(
  `PASS AqKanji2Koe soak: ${corpus.length * 10} conversions, ` +
  `${longText.length}-char passage, memory ${startMB.toFixed(1)} -> ${memMB().toFixed(1)} MiB`,
);
