/* Stress test for the raw wasm build: allocator fuzz + repeated synthesis.
 *   node port/tools/stress_test.mjs
 */
import { createAquesTalk2 } from '../../dist/aquestalk2.js';
import crypto from 'node:crypto';

const aq = await createAquesTalk2(new URL('../../dist/aquestalk2-core.wasm', import.meta.url));
const e = aq._raw;

/* ---- allocator fuzz -------------------------------------------------- */
const live = [];
let maxHeap = 0;
let seed = 12345;
const rnd = () => (seed = (seed * 1103515245 + 12345) >>> 0) / 4294967296;

function writePattern(ptr, size, tag) {
  const mem = new Uint8Array(e.memory.buffer);
  for (let i = 0; i < size; i++) mem[ptr + i] = (tag + i) & 0xff;
}
function checkPattern(ptr, size, tag) {
  const mem = new Uint8Array(e.memory.buffer);
  for (let i = 0; i < size; i += (size > 256 ? 37 : 1)) {
    if (mem[ptr + i] !== ((tag + i) & 0xff)) return false;
  }
  return true;
}

for (let i = 0; i < 20000; i++) {
  const op = rnd();
  if (op < 0.55 || live.length === 0) {
    const size = 1 + Math.floor(rnd() * (rnd() < 0.05 ? 200000 : 4000));
    const ptr = e.aq_malloc(size);
    if (!ptr) throw new Error('malloc failed at ' + i + ' size ' + size);
    if (ptr % 8) throw new Error('misaligned pointer ' + ptr);
    const tag = (i * 31) & 0xff;
    writePattern(ptr, size, tag);
    live.push({ ptr, size, tag });
  } else {
    const k = Math.floor(rnd() * live.length);
    const blk = live[k];
    if (!checkPattern(blk.ptr, blk.size, blk.tag))
      throw new Error('pattern corrupted for block ' + k + ' (iteration ' + i + ')');
    e.aq_free(blk.ptr);
    live.splice(k, 1);
  }
  if (e.memory.buffer.byteLength > maxHeap) maxHeap = e.memory.buffer.byteLength;
}
while (live.length) {
  const blk = live.pop();
  if (!checkPattern(blk.ptr, blk.size, blk.tag)) throw new Error('final pattern corrupted');
  e.aq_free(blk.ptr);
}
const afterFuzz = e.memory.buffer.byteLength;
console.log('allocator fuzz OK; peak memory', maxHeap, 'after', afterFuzz);

/* ---- repeated synthesis --------------------------------------------- */
const texts = ['こんにちは', 'おはようございます', 'ありがとう',
               'きょうはいいてんきですね', 'すもももももももものうち',
               'がぎぐげご', 'ぱぴぷぺぽ', 'こんばんは、せかい。'];
const seen = new Map();
const before = e.memory.buffer.byteLength;
for (let i = 0; i < 400; i++) {
  const t = texts[i % texts.length];
  const s = 50 + (i * 7) % 251;
  const wav = aq.synthe(t, s);
  if (!wav) throw new Error('synthesis failed: ' + aq.lastError());
  const h = crypto.createHash('sha256').update(wav).digest('hex');
  const key = t + '|' + s;
  if (seen.has(key) && seen.get(key) !== h) throw new Error('nondeterministic ' + key);
  seen.set(key, h);
}
console.log('400 syntheses OK; memory before', before, 'after', e.memory.buffer.byteLength);
