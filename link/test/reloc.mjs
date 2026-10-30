#!/usr/bin/env node
/* Parity test for the single-memory bundle: dist/aquestalk.wasm.
 *
 * Every engine was previously shipped as its own wasm module.  The bundle
 * links the relocatable archives and Rust code into one module with one
 * memory and no imports.  This test loads the bundle and the original
 * per-engine modules side by side and compares their output byte for byte.
 *
 *   node link/test/reloc.mjs
 *   ./scripts/build-reloc.sh
 */
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

import { DEMO_KANA_SAMPLES, KANA_CORPUS, SPEED_PROBES } from '../../data/kana-corpus.js';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(HERE, '../..');
const B = (rel) => path.join(ROOT, rel);
const encoder = new TextEncoder();
const decoder = new TextDecoder();

const failures = [];
const notes = [];

function fail(message) {
  failures.push(message);
  console.error(`FAIL ${message}`);
}

function note(message) {
  notes.push(message);
  console.log(message);
}

function exists(rel) {
  return fs.existsSync(B(rel));
}

async function load(rel) {
  const bytes = fs.readFileSync(B(rel));
  const { instance } = await WebAssembly.instantiate(bytes, {});
  return instance.exports;
}

/** Pointers are allocated with each module's own C allocator. */
class Heap {
  constructor(exports, allocName, freeName) {
    this.exports = exports;
    this.allocName = allocName;
    this.freeName = freeName;
  }

  get memory() {
    return this.exports.memory;
  }

  bytes() {
    return new Uint8Array(this.memory.buffer);
  }

  i32() {
    return new DataView(this.memory.buffer);
  }

  alloc(size) {
    const pointer = this.exports[this.allocName](size);
    if (!pointer) throw new Error(`${this.allocName}(${size}) returned 0`);
    return pointer;
  }

  free(pointer) {
    if (pointer) this.exports[this.freeName](pointer);
  }

  putBytes(data) {
    const pointer = this.alloc(data.length);
    this.bytes().set(data, pointer);
    return pointer;
  }

  putString(text) {
    const data = encoder.encode(`${text}\0`);
    const pointer = this.alloc(data.length);
    this.bytes().set(data, pointer);
    return pointer;
  }

  readCString(pointer) {
    const bytes = this.bytes();
    let end = pointer;
    while (end < bytes.length && bytes[end] !== 0) end++;
    return decoder.decode(bytes.subarray(pointer, end));
  }
}

function takeWave(heap, pointer, sizePointer, freeName) {
  if (!pointer) return null;
  const size = heap.i32().getInt32(sizePointer, true);
  const wave = Buffer.from(new Uint8Array(heap.memory.buffer, pointer, size));
  heap.exports[freeName](pointer);
  return wave;
}

function sameWave(a, b, label) {
  if (a === null || b === null) {
    if (a !== b) fail(`${label}: one side failed (${a?.length} vs ${b?.length})`);
    return a === b;
  }
  if (a.length !== b.length || !a.equals(b)) {
    fail(`${label}: ${a.length} vs ${b.length} bytes, first difference at ${firstDiff(a, b)}`);
    return false;
  }
  return true;
}

function firstDiff(a, b) {
  const limit = Math.min(a.length, b.length);
  for (let i = 0; i < limit; i++) if (a[i] !== b[i]) return i;
  return limit;
}

/* ------------------------------------------------------------------ */
/* module shape                                                        */
/* ------------------------------------------------------------------ */

const bundlePath = 'dist/aquestalk.wasm';
if (!exists(bundlePath)) {
  console.error(`missing ${bundlePath}; run ./scripts/build-reloc.sh first`);
  process.exit(2);
}

const bundleModule = new WebAssembly.Module(fs.readFileSync(B(bundlePath)));
const imports = WebAssembly.Module.imports(bundleModule);
assert.deepEqual(imports, [], 'the bundle must not import anything');
const moduleExports = WebAssembly.Module.exports(bundleModule);
assert.equal(moduleExports.filter((entry) => entry.kind === 'memory').length, 1,
  'bundle must have exactly one memory');
const exports = moduleExports.map((entry) => entry.name);
assert.ok(exports.includes('memory'), 'bundle exports memory');
assert.ok(exports.includes('aq_host_abi'), 'bundle exports the Rust host marker');

const buildInfo = JSON.parse(fs.readFileSync(B('dist/reloc/build-info.json'), 'utf8'));
const bundle = await load(bundlePath);
assert.equal(bundle.memory instanceof WebAssembly.Memory, true);
assert.equal(bundle.memory.buffer.byteLength, buildInfo.memory.initial, 'initial memory');
assert.equal(bundle.aq_host_abi(), 1, 'Rust host ABI');
note('module: 0 imports, 1 memory, 1 table');

/* ------------------------------------------------------------------ */
/* AquesTalk1                                                          */
/* ------------------------------------------------------------------ */

const AQ1_VOICES = ['f1', 'f2', 'f3', 'm1', 'm2', 'r1', 'imd1', 'jgr', 'dvd'];
const TEXTS = [
  DEMO_KANA_SAMPLES[0],
  KANA_CORPUS[3].text,
  "ありがとう'ございます。",
  'おはようございます、きょうもいいおてんきですね。',
];

if (exists('engines/aquestalk1/dist/aquestalk1.wasm')) {
  const standalone = await load('engines/aquestalk1/dist/aquestalk1.wasm');
  const oldHeap = new Heap(standalone, 'aq_alloc', 'aq_free');
  const newHeap = new Heap(bundle, 'malloc', 'free');
  let cases = 0;
  let same = 0;
  for (const voice of AQ1_VOICES) {
    const oldVoice = oldHeap.putString(voice);
    const newVoice = newHeap.putString(voice);
    assert.equal(standalone.aq_select_voice(oldVoice), 0, `select ${voice}`);
    assert.equal(bundle.aq1_select_voice(newVoice), 0, `bundle select ${voice}`);
    oldHeap.free(oldVoice);
    newHeap.free(newVoice);
    for (const text of TEXTS) {
      for (const speed of [70, 100, 180]) {
        const oldText = oldHeap.putString(text);
        const oldSize = oldHeap.alloc(4);
        const expected = takeWave(
          oldHeap, standalone.aq_synthe_utf8(oldText, speed, oldSize), oldSize,
          'aq_free_wave');
        oldHeap.free(oldText);
        oldHeap.free(oldSize);

        const newText = newHeap.putString(text);
        const newSize = newHeap.alloc(4);
        const actual = takeWave(
          newHeap, bundle.aq1_synthe_utf8(newText, speed, newSize), newSize,
          'aq1_free_wave');
        newHeap.free(newText);
        newHeap.free(newSize);

        cases++;
        if (sameWave(expected, actual, `AQ1 ${voice} ${speed} ${text}`)) same++;
      }
    }
  }
  assert.equal(same, cases, `AquesTalk1 parity ${same}/${cases}`);
  note(`AquesTalk1: ${same}/${cases} WAVs byte-identical (${AQ1_VOICES.length} voices)`);
} else {
  note('AquesTalk1: standalone wasm missing, skipped');
}

/* ------------------------------------------------------------------ */
/* AquesTalk2                                                          */
/* ------------------------------------------------------------------ */

const PHONTS = [null, 'aq_rm.phont', 'aq_m4b.phont', 'aq_yukkuri.phont'];
if (exists('engines/aquestalk2/dist/aquestalk2-core.wasm')) {
  const standalone = await load('engines/aquestalk2/dist/aquestalk2-core.wasm');
  const oldHeap = new Heap(standalone, 'aq_malloc', 'aq_free');
  const newHeap = new Heap(bundle, 'malloc', 'free');
  let cases = 0;
  let same = 0;
  for (const phont of PHONTS) {
    const data = phont ? fs.readFileSync(B(`engines/aquestalk2/dist/phont/${phont}`)) : null;
    for (const text of TEXTS) {
      const oldText = oldHeap.putString(text);
      const newText = newHeap.putString(text);
      const oldPhont = data ? oldHeap.putBytes(data) : 0;
      const newPhont = data ? newHeap.putBytes(data) : 0;
      const oldSize = oldHeap.alloc(4);
      const newSize = newHeap.alloc(4);
      const expected = takeWave(
        oldHeap, standalone.AquesTalk2_Synthe_Utf8(oldText, 100, oldSize, oldPhont),
        oldSize, 'AquesTalk2_FreeWave');
      const actual = takeWave(
        newHeap, bundle.aq2_synthe_utf8(newText, 100, newSize, newPhont),
        newSize, 'aq2_free_wave');
      oldHeap.free(oldText); oldHeap.free(oldSize);
      if (oldPhont) oldHeap.free(oldPhont);
      newHeap.free(newText); newHeap.free(newSize);
      if (newPhont) newHeap.free(newPhont);
      cases++;
      if (sameWave(expected, actual, `AQ2 ${phont ?? 'built-in'} ${text}`)) same++;
    }
  }
  assert.equal(same, cases, `AquesTalk2 parity ${same}/${cases}`);
  note(`AquesTalk2: ${same}/${cases} WAVs byte-identical (${PHONTS.length} phonts)`);
} else {
  note('AquesTalk2: standalone wasm missing, skipped');
}

/* ------------------------------------------------------------------ */
/* AquesTalk10                                                         */
/* ------------------------------------------------------------------ */

const AQ10_VOICES = {
  F1: { bas: 0, spd: 100, vol: 100, pit: 100, acc: 100, lmd: 100, fsc: 100 },
  F2: { bas: 1, spd: 100, vol: 100, pit: 77, acc: 150, lmd: 100, fsc: 100 },
  F3: { bas: 0, spd: 80, vol: 100, pit: 100, acc: 100, lmd: 61, fsc: 148 },
  M1: { bas: 2, spd: 100, vol: 100, pit: 30, acc: 100, lmd: 100, fsc: 100 },
  M2: { bas: 2, spd: 105, vol: 100, pit: 45, acc: 130, lmd: 120, fsc: 100 },
  R1: { bas: 2, spd: 100, vol: 100, pit: 30, acc: 20, lmd: 190, fsc: 100 },
  R2: { bas: 1, spd: 70, vol: 100, pit: 50, acc: 50, lmd: 50, fsc: 180 },
};

function putVoice(heap, voice) {
  const pointer = heap.alloc(7 * 4);
  const view = heap.i32();
  [voice.bas, voice.spd, voice.vol, voice.pit, voice.acc, voice.lmd, voice.fsc]
    .forEach((value, index) => view.setInt32(pointer + index * 4, value, true));
  return pointer;
}

if (exists('engines/aquestalk10/port/web/aqtk10.wasm')) {
  const standalone = await load('engines/aquestalk10/port/web/aqtk10.wasm');
  const oldHeap = new Heap(standalone, 'aqtk_malloc', 'aqtk_free');
  const newHeap = new Heap(bundle, 'malloc', 'free');
  standalone.aqtk_init();
  bundle.aq10_init();
  let cases = 0;
  let same = 0;
  for (const [name, voice] of Object.entries(AQ10_VOICES)) {
    for (const text of TEXTS) {
      for (const speed of [80, 120]) {
        const shaped = { ...voice, spd: speed };
        const oldVoice = putVoice(oldHeap, shaped);
        const newVoice = putVoice(newHeap, shaped);
        const oldText = oldHeap.putString(text);
        const newText = newHeap.putString(text);
        const oldSize = oldHeap.alloc(4);
        const newSize = newHeap.alloc(4);
        const expected = takeWave(
          oldHeap, standalone.aqtk_synthe_utf8(oldVoice, oldText, oldSize),
          oldSize, 'aqtk_free_wave');
        const actual = takeWave(
          newHeap, bundle.aq10_synthe_utf8(newVoice, newText, newSize),
          newSize, 'aq10_free_wave');
        oldHeap.free(oldText); oldHeap.free(oldSize); oldHeap.free(oldVoice);
        newHeap.free(newText); newHeap.free(newSize); newHeap.free(newVoice);
        cases++;
        if (sameWave(expected, actual, `AQ10 ${name} ${speed} ${text}`)) same++;
      }
    }
  }
  assert.equal(same, cases, `AquesTalk10 parity ${same}/${cases}`);
  note(`AquesTalk10: ${same}/${cases} WAVs byte-identical (7 presets)`);
} else {
  note('AquesTalk10: standalone wasm missing, skipped');
}

/* ------------------------------------------------------------------ */
/* AqKanji2Koe                                                         */
/* ------------------------------------------------------------------ */

const K2K_TEXTS = [
  '音声合成テスト。東京は日本の首都です。',
  '明日の天気は晴れでしょう。',
  '吾輩は猫である。名前はまだ無い。',
  '１２３円でございます。',
  'おはようございます。今日もいい一日にしましょう。',
  '<NUMK VAL=3 COUNTER=人>が来た。',
  'すもももももももものうち。',
];

if (exists('engines/aqk2k/port/build-wasm32/aqk2k32.wasm') &&
    exists('engines/aqk2k/aqk2k_lnx/aq_dic/lookup.bin') &&
    exists('engines/aqk2k/aqk2k_lnx/aq_dic/aqdic.bin')) {
  const dictionary = fs.readFileSync(B('engines/aqk2k/aqk2k_lnx/aq_dic/aqdic.bin'));
  const userDictionary = fs.readFileSync(B('engines/aqk2k/aqk2k_lnx/aq_dic/aq_user.dic'));
  const lookup = fs.readFileSync(B('engines/aqk2k/aqk2k_lnx/aq_dic/lookup.bin'));

  function bootK2K(exportsObject, prefix, allocName, freeName) {
    const heap = new Heap(exportsObject, allocName, freeName);
    exportsObject[`${prefix}init`]();
    const lookupPointer = heap.putBytes(lookup);
    const rc = exportsObject[`${prefix}set_lookup`](lookupPointer, lookup.length);
    assert.equal(rc, 0, `${prefix}set_lookup`);
    const sys = heap.putBytes(dictionary);
    const user = heap.putBytes(userDictionary);
    const err = heap.alloc(4);
    heap.i32().setInt32(err, 0, true);
    const handle = exportsObject[`${prefix}create`](sys, user, err);
    assert.ok(handle, `${prefix}create`);
    assert.equal(heap.i32().getInt32(err, true), 0, `${prefix}create error code`);
    const input = heap.alloc(1 << 16);
    const output = heap.alloc(1 << 18);
    return { heap, handle, input, output, capacity: 1 << 18, prefix };
  }

  function convert(state, text, roman) {
    const bytes = encoder.encode(text);
    state.heap.bytes().set(bytes, state.input);
    state.heap.bytes()[state.input + bytes.length] = 0;
    const rc = state.heap.exports[`${state.prefix}${roman ? 'conv_roman' : 'convert'}`](
      state.handle, state.input, state.output, state.capacity);
    return { rc, text: rc === 0 ? state.heap.readCString(state.output) : '' };
  }

  const oldHeap = await load('engines/aqk2k/port/build-wasm32/aqk2k32.wasm');
  const oldState = bootK2K(oldHeap, 'aq_', 'aq_alloc', 'aq_free');
  const newState = bootK2K(bundle, 'aqk2k_', 'aqk2k_alloc', 'aqk2k_free');
  let cases = 0;
  let same = 0;
  for (const text of K2K_TEXTS) {
    for (const roman of [false, true]) {
      const expected = convert(oldState, text, roman);
      const actual = convert(newState, text, roman);
      cases++;
      if (expected.rc === actual.rc && expected.text === actual.text) {
        same++;
      } else {
        fail(`K2K ${roman ? 'roman' : 'kana'} ${text}: ${JSON.stringify(expected)} vs ${JSON.stringify(actual)}`);
      }
    }
  }
  assert.equal(same, cases, `AqKanji2Koe parity ${same}/${cases}`);
  note(`AqKanji2Koe: ${same}/${cases} conversions identical`);
} else {
  note('AqKanji2Koe: dictionary or standalone wasm missing, skipped');
}

/* ------------------------------------------------------------------ */
/* AqUsrDic                                                            */
/* ------------------------------------------------------------------ */

const USER_CASES = 'engines/aqk2k/port_usr/tests/check_cases.json';
const USER_EXPECTED = 'engines/aqk2k/port_usr/tests/check_expected.json';
const USER_SAMPLE = 'engines/aqk2k/port_usr/tests/sample.csv';

if (exists('engines/aqk2k/port_usr/build-wasm32/aqusr.wasm') &&
    exists('engines/aqk2k/aqk2k_lnx/aq_dic/aqdic.bin') &&
    exists(USER_CASES) && exists(USER_SAMPLE)) {
  const systemDictionary = fs.readFileSync(B('engines/aqk2k/aqk2k_lnx/aq_dic/aqdic.bin'));
  const cases = JSON.parse(fs.readFileSync(B(USER_CASES), 'utf8'));
  const expectedResults = JSON.parse(fs.readFileSync(B(USER_EXPECTED), 'utf8'));
  const csv = fs.readFileSync(B(USER_SAMPLE), 'utf8');

  function bootUser(exportsObject, prefix, allocName, freeName) {
    const heap = new Heap(exportsObject, allocName, freeName);
    exportsObject[`${prefix}init`]();
    const system = heap.putBytes(systemDictionary);
    const rc = exportsObject[`${prefix}set_system_dic`](system, systemDictionary.length);
    assert.equal(rc, 0, `${prefix}set_system_dic`);
    const capacity = 1 << 20;
    return {
      heap, capacity, prefix,
      output: heap.alloc(capacity),
      outputLength: heap.alloc(4),
      exported: heap.alloc(capacity),
      exportedLength: heap.alloc(4),
    };
  }

  const oldExports = await load('engines/aqk2k/port_usr/build-wasm32/aqusr.wasm');
  const oldState = bootUser(oldExports, 'aus_', 'aq_alloc', 'aq_free');
  const newState = bootUser(bundle, 'aqusr_', 'aqusr_alloc', 'aqusr_free');

  let casesRun = 0;
  let same = 0;
  for (let index = 0; index < cases.length; index++) {
    const item = cases[index];
    const oldSurface = oldState.heap.putString(item.surface);
    const oldYomi = oldState.heap.putString(item.yomi);
    const newSurface = newState.heap.putString(item.surface);
    const newYomi = newState.heap.putString(item.yomi);
    const expectedRc = oldExports.aus_check(oldSurface, oldYomi, item.pos);
    const actualRc = bundle.aqusr_check(newSurface, newYomi, item.pos);
    casesRun++;
    if (expectedRc === actualRc) {
      same++;
    } else {
      fail(`AqUsrDic check ${index}: ${expectedRc} vs ${actualRc}`);
    }
    oldState.heap.free(oldSurface);
    oldState.heap.free(oldYomi);
    newState.heap.free(newSurface);
    newState.heap.free(newYomi);
    assert.equal(actualRc, expectedResults[index].rc, `AqUsrDic expected ${index}`);
  }
  assert.equal(same, casesRun, `AqUsrDic parity ${same}/${casesRun}`);

  function importExport(exportsObject, state) {
    const heap = state.heap;
    const csvPointer = heap.putString(csv);
    const rc = exportsObject[`${state.prefix}import`](
      csvPointer, encoder.encode(csv).length,
      state.output, state.capacity, state.outputLength);
    assert.equal(rc, 0, 'import');
    const length = heap.i32().getUint32(state.outputLength, true);
    const dic = Buffer.from(new Uint8Array(heap.memory.buffer, state.output, length));
    const dicPointer = heap.putBytes(dic);
    const rc2 = exportsObject[`${state.prefix}export`](
      dicPointer, length, state.exported, state.capacity, state.exportedLength);
    assert.equal(rc2, 0, 'export');
    const exportedLength = heap.i32().getUint32(state.exportedLength, true);
    return {
      length,
      text: decoder.decode(new Uint8Array(heap.memory.buffer, state.exported, exportedLength)),
    };
  }

  const oldResult = importExport(oldExports, oldState);
  const newResult = importExport(bundle, newState);
  assert.equal(oldResult.length, newResult.length, 'imported dictionary length');
  assert.equal(oldResult.text, newResult.text, 'exported dictionary text');
  note(`AqUsrDic: ${same}/${casesRun} checks + ${newResult.length}-byte import/export identical`);
} else {
  note('AqUsrDic: dictionary or standalone wasm missing, skipped');
}

/* ------------------------------------------------------------------ */

if (failures.length) {
  console.error(`\n${failures.length} reloc parity failure(s)`);
  process.exit(1);
}
console.log('\nsingle-memory bundle parity: OK');
