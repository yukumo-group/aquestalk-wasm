#!/usr/bin/env node
/* Headless smoke test for the unified engine adapters.
 *
 * Serves the repository over a tiny HTTP server (the adapters use fetch),
 * then synthesizes with every engine and runs the AqKanji2Koe converter.
 *
 *   npm test
 */
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import assert from 'node:assert/strict';
import { fileURLToPath } from 'node:url';

import {
  ENGINES,
  setEngineRoot,
  loadEngine,
  loadKanji2Koe,
} from '../demo/engines.js';

const ROOT = path.resolve(fileURLToPath(new URL('..', import.meta.url)));
const MIME = {
  '.html': 'text/html; charset=utf-8',
  '.js': 'text/javascript; charset=utf-8',
  '.css': 'text/css; charset=utf-8',
  '.wasm': 'application/wasm',
  '.json': 'application/json',
  '.phont': 'application/octet-stream',
  '.bin': 'application/octet-stream',
  '.dic': 'application/octet-stream',
};

const server = http.createServer((req, res) => {
  const url = new URL(req.url, 'http://127.0.0.1');
  const file = path.join(ROOT, decodeURIComponent(url.pathname));
  if (!file.startsWith(ROOT + path.sep)) {
    res.writeHead(403).end();
    return;
  }
  fs.readFile(file, (err, data) => {
    if (err) {
      res.writeHead(404).end('not found');
      return;
    }
    res.writeHead(200, { 'content-type': MIME[path.extname(file)] || 'application/octet-stream' });
    res.end(data);
  });
});

await new Promise((resolve) => server.listen(0, '127.0.0.1', resolve));
const { port } = server.address();
setEngineRoot(`http://127.0.0.1:${port}/engines/`);

function wavInfo(bytes) {
  assert.ok(bytes instanceof Uint8Array, 'WAV must be a Uint8Array');
  assert.equal(new TextDecoder().decode(bytes.subarray(0, 4)), 'RIFF');
  assert.equal(new TextDecoder().decode(bytes.subarray(8, 12)), 'WAVE');
  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  let off = 12;
  let fmt = null;
  let data = 0;
  while (off + 8 <= bytes.length) {
    const id = new TextDecoder().decode(bytes.subarray(off, off + 4));
    const size = dv.getUint32(off + 4, true);
    if (id === 'fmt ') {
      fmt = {
        channels: dv.getUint16(off + 10, true),
        rate: dv.getUint32(off + 12, true),
        bits: dv.getUint16(off + 22, true),
      };
    } else if (id === 'data') {
      data = Math.min(size, bytes.length - off - 8);
      break;
    }
    off += 8 + size + (size & 1);
  }
  assert.ok(fmt, 'fmt chunk');
  assert.ok(data > 0, 'data chunk');
  const seconds = data / (fmt.rate * fmt.channels * (fmt.bits / 8));
  return { ...fmt, data, seconds };
}

const results = [];

async function testTts(id, voice, speed, params, label) {
  const info = ENGINES.find((e) => e.id === id);
  const engine = await loadEngine(id);
  const wav = await engine.synth('こんにちは、せかい。', { voice, speed, params });
  const infoWav = wavInfo(wav);
  assert.ok(infoWav.seconds > 0.3, `${id}: too short`);
  results.push(`${info.name}${label ? ` (${label})` : ''}: ${wav.length} B, ${infoWav.rate} Hz, ${infoWav.seconds.toFixed(2)} s`);
  return wav;
}

try {
  await testTts('aqtk1', 'f1', 100, undefined, 'f1');
  await testTts('aqtk1', 'f3', 100, undefined, 'f3');
  await testTts('aqtk2', '', 100, undefined, 'built-in phont');
  await testTts('aqtk2', 'aq_rm.phont', 100, undefined, 'aq_rm.phont');
  await testTts('aqtk10', 'F1', 100, undefined, 'F1');
  await testTts('aqtk10', 'F3', 120, undefined, 'F3 @120');

  const dic = path.join(ROOT, 'engines/aqk2k/aqk2k_lnx/aq_dic');
  const hasDict = ['aqdic.bin', 'lookup.bin', 'aq_user.dic']
    .every((f) => fs.existsSync(path.join(dic, f)));

  if (hasDict) {
    const k2k = await loadKanji2Koe();
    const kana = await k2k.convert('音声合成テスト。東京は日本の首都です。');
    assert.match(kana, /オンセー/);
    assert.match(kana, /トーキョー/);

    const roman = await k2k.convertRoman('音声合成テスト。');
    assert.equal(roman, "onnse-go-se-te'_suto.");

    // Exercise the arena-reload path (every 32 conversions).
    for (let i = 0; i < 40; i++) {
      const out = await k2k.convert('明日の天気は晴れでしょう。');
      assert.match(out, /テ.ンキ/);
    }

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
  server.close();
}
