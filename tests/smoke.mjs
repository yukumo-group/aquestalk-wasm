#!/usr/bin/env node
/* Headless smoke test for the unified engine adapters.
 *
 * Serves the repository over a tiny HTTP server (the adapters use fetch),
 * synthesizes with every engine from the shared kana corpus, and runs the
 * AqKanji2Koe converter.
 *
 *   npm test
 */
import fs from 'node:fs';
import path from 'node:path';
import assert from 'node:assert/strict';

import {
  ENGINES,
  setEngineRoot,
  loadEngine,
  loadKanji2Koe,
} from '../demo/engines.js';
import { startStaticServer, REPO_ROOT } from './lib/static-server.mjs';
import { parseWav } from './lib/wav.mjs';
import { expectedRate } from './lib/voices.mjs';
import { DEMO_KANA_SAMPLES, KANA_CORPUS } from '../data/kana-corpus.js';

const server = await startStaticServer(REPO_ROOT);
setEngineRoot(`${server.url}/engines/`);

const results = [];

function wavInfo(bytes) {
  const info = parseWav(bytes);
  assert.ok(info.seconds > 0.3, 'WAV too short');
  return info;
}

async function testTts(id, voice, speed, params, label) {
  const info = ENGINES.find((e) => e.id === id);
  const engine = await loadEngine(id);
  const text = DEMO_KANA_SAMPLES[0];
  const wav = await engine.synth(text, { voice, speed, params });
  const wavInfoResult = wavInfo(wav);
  assert.equal(wavInfoResult.rate, expectedRate(id, voice), 'sample rate');
  results.push(
    `${info.name}${label ? ` (${label})` : ''}: ${wav.length} B, ` +
    `${wavInfoResult.rate} Hz, ${wavInfoResult.seconds.toFixed(2)} s`,
  );
  return wav;
}

try {
  assert.ok(KANA_CORPUS.length >= 100, 'shared corpus should be broad');
  assert.equal(DEMO_KANA_SAMPLES.length, 8, 'demo samples come from the corpus');

  await testTts('aqtk1', 'f1', 100, undefined, 'f1');
  await testTts('aqtk1', 'f3', 100, undefined, 'f3');
  await testTts('aqtk2', '', 100, undefined, 'built-in phont');
  await testTts('aqtk2', 'aq_rm.phont', 100, undefined, 'aq_rm.phont');
  await testTts('aqtk10', 'F1', 100, undefined, 'F1');
  await testTts('aqtk10', 'F3', 120, undefined, 'F3 @120');

  const dic = path.join(REPO_ROOT, 'engines/aqk2k/aqk2k_lnx/aq_dic');
  const hasDict = ['aqdic.bin', 'lookup.bin', 'aq_user.dic']
    .every((f) => fs.existsSync(path.join(dic, f)));

  if (hasDict) {
    const k2k = await loadKanji2Koe();
    const kana = await k2k.convert('音声合成テスト。東京は日本の首都です。');
    assert.match(kana, /オンセー/);
    assert.match(kana, /トーキョー/);

    const roman = await k2k.convertRoman('音声合成テスト。');
    assert.equal(roman, "onnse-go-se-te'_suto.");

    // Long session: one wasm instance and one dictionary load, no periodic
    // arena rebuild.  The runtime recycles freed blocks.
    for (let i = 0; i < 200; i++) {
      const out = await k2k.convert('明日の天気は晴れでしょう。');
      assert.match(out, /テ.ンキ/);
    }

    // NUMK tags and sentence-final punctuation now match the original.
    assert.equal(await k2k.convert('100円'), '<NUMK VAL="100" COUNTER="エン">。');
    assert.equal(await k2k.convert('一人'), '<NUMK VAL="1" COUNTER="にん">。');
    assert.equal(await k2k.convert('こんにちは。'), "コンヌチワ'。");

    // A single large passage should also complete without truncation.
    const longText = '東京は日本の首都です。明日の天気は晴れでしょう。'.repeat(500);
    const longOut = await k2k.convert(longText);
    assert.ok(longOut.length > 20000, 'long conversion output');
    assert.match(longOut, /トーキョー/);

    const tts = await loadEngine('aqtk2');
    const wav = await tts.synth(kana, { voice: '', speed: 100 });
    const info = wavInfo(wav);
    assert.ok(info.seconds > 1);

    results.push(`AqKanji2Koe: "${kana}"`);
    results.push(`AqKanji2Koe roman: "${roman}"`);
    results.push(`pipeline k2k -> AquesTalk2: ${wav.length} B, ${info.seconds.toFixed(2)} s`);
  } else {
    results.push('AqKanji2Koe: skipped (aqdic.bin / lookup.bin not present)');
  }

  console.log('PASS');
  for (const line of results) console.log('  ' + line);
} finally {
  await server.close();
}
