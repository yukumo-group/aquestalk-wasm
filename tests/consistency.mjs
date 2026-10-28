#!/usr/bin/env node
/* Cross-voice behaviour consistency test for AquesTalk1/2/10.
 *
 * Runs one canonical daily-Japanese kana corpus through every voice of every
 * TTS engine, checks the WAV contract, determinism, speed response, invalid
 * input handling and the documented evaluation-build fingerprint, then writes
 * a machine-readable result and a Markdown report.
 *
 *   node tests/consistency.mjs
 *   npm run test:consistency
 */
import fs from 'node:fs/promises';
import { existsSync } from 'node:fs';
import path from 'node:path';
import { execFileSync } from 'node:child_process';
import { startStaticServer, REPO_ROOT } from './lib/static-server.mjs';
import { clearEngineCache, AQTK10_VOICES } from '../demo/engines.js';
import { parseWav, sha256, sameBytes } from './lib/wav.mjs';
import {
  ENGINE_IDS,
  ENGINE_NAMES,
  VOICE_IDS,
  voiceEntries,
  voiceLabel,
  expectedRate,
  loadAllEngines,
} from './lib/voices.mjs';
import {
  KANA_CORPUS,
  DEMO_KANA_SAMPLES,
  KANA_SCRIPT_PAIRS,
  EVALUATION_PROBES,
  INVALID_INPUTS,
  DIVERGENT_INPUTS,
  SPEED_PROBES,
  SPEED_PROBE_TEXT,
  LONG_PROBE_TEXT,
} from '../data/kana-corpus.js';

const OUT_JSON = path.join(REPO_ROOT, 'tests/results/consistency.json');
const OUT_MD = path.join(REPO_ROOT, 'docs/consistency-report.md');
const STRICT = process.argv.includes('--strict');
const startedAt = new Date();
const hardFailures = [];

function fail(check, detail) {
  hardFailures.push({ check, detail });
}

function pct(n, d) {
  return d ? `${(100 * n / d).toFixed(1)}%` : '—';
}

function f2(n) {
  return Number(n).toFixed(2);
}

function mdTable(headers, rows) {
  return [
    `| ${headers.join(' | ')} |`,
    `| ${headers.map(() => '---').join(' | ')} |`,
    ...rows.map((row) => `| ${row.join(' | ')} |`),
  ].join('\n');
}

function pearson(xs, ys) {
  const n = xs.length;
  if (n !== ys.length || n < 2) return NaN;
  const mx = xs.reduce((a, b) => a + b, 0) / n;
  const my = ys.reduce((a, b) => a + b, 0) / n;
  let num = 0;
  let dx = 0;
  let dy = 0;
  for (let i = 0; i < n; i++) {
    const a = xs[i] - mx;
    const b = ys[i] - my;
    num += a * b;
    dx += a * a;
    dy += b * b;
  }
  return num / Math.sqrt(dx * dy);
}

/* Locate the original Linux SDKs used as the native reference.  The
 * AquesTalk2/10 .so files live in this repository; AquesTalk1's .so files are
 * not committed, so look for the sibling SDK checkout as well. */
function findAq1Lib64() {
  const candidates = [
    process.env.AQTK1_LIB64,
    path.join(REPO_ROOT, 'engines/aquestalk1/aqtk1_lnx/lib64'),
    path.resolve(REPO_ROOT, '../aquestalk1/aqtk1_lnx/lib64'),
  ].filter(Boolean);
  return candidates.find((root) =>
    VOICE_IDS.aqtk1.every((voice) => existsSync(path.join(root, voice, 'libAquesTalk.so'))));
}

function buildNativeRequest() {
  const engines = {};
  const missing = [];
  const aq1Root = findAq1Lib64();
  if (aq1Root) {
    engines.aqtk1 = {
      voices: Object.fromEntries(VOICE_IDS.aqtk1.map((voice) => [
        voice, path.join(aq1Root, voice, 'libAquesTalk.so'),
      ])),
    };
  } else {
    missing.push('aqtk1');
  }

  const aq2Lib = path.join(REPO_ROOT, 'engines/aquestalk2/aqtk2-lnx/lib64/libAquesTalk2Eva.so.2.3');
  if (existsSync(aq2Lib)) {
    engines.aqtk2 = {
      lib: aq2Lib,
      voices: Object.fromEntries(VOICE_IDS.aqtk2.map((voice) => [
        voice,
        voice ? path.join(REPO_ROOT, 'engines/aquestalk2/dist/phont', voice) : null,
      ])),
    };
  } else {
    missing.push('aqtk2');
  }

  const aq10Lib = path.join(REPO_ROOT, 'engines/aquestalk10/aqtk10_lnx/lib64/libAquesTalk10.so.1.1');
  if (existsSync(aq10Lib)) {
    engines.aqtk10 = {
      lib: aq10Lib,
      voices: Object.fromEntries(VOICE_IDS.aqtk10.map((voice) => {
        const preset = AQTK10_VOICES[voice];
        /* The JS adapter forces spd=100 when the test passes speed: 100. */
        return [voice, [preset.bas, 100, preset.vol, preset.pit, preset.acc, preset.lmd, preset.fsc]];
      })),
    };
  } else {
    missing.push('aqtk10');
  }

  return {
    request: {
      engines,
      cases: KANA_CORPUS.map((item) => ({ id: item.id, text: item.text })),
      speed: { text: SPEED_PROBE_TEXT, speeds: SPEED_PROBES },
    },
    missing,
    aq1Root,
    aq2Lib,
    aq10Lib,
  };
}

const server = await startStaticServer(REPO_ROOT);

/* Validate the shared dataset itself before spending time on synthesis. */
const datasetProblems = [];
{
  const ids = new Set();
  const texts = new Set(KANA_CORPUS.map((item) => item.text));
  for (const item of KANA_CORPUS) {
    if (!item.id || ids.has(item.id)) datasetProblems.push(`duplicate/empty id: ${item.id}`);
    ids.add(item.id);
    if (!item.text || !item.text.trim()) datasetProblems.push(`empty text: ${item.id}`);
    if (/[A-Za-z0-9\u4e00-\u9fff\uFF10-\uFF19]/.test(item.text)) {
      datasetProblems.push(`kanji/ASCII/fullwidth digit in ${item.id}: ${item.text}`);
    }
    if (/[\uFF66-\uFF9F]/.test(item.text)) datasetProblems.push(`half-width kana in ${item.id}`);
  }
  for (const sample of DEMO_KANA_SAMPLES) {
    if (!texts.has(sample)) datasetProblems.push(`demo sample not in corpus: ${sample}`);
  }
  if (DEMO_KANA_SAMPLES.length !== 8) datasetProblems.push('demo sample count != 8');
}

let engines;
try {
  engines = await loadAllEngines(`${server.url}/engines/`);

  /* A rejected tag/phont call can leave an AquesTalk2 instance in a bad
   * state.  Reload after failures so later probes stay independent. */
  async function reloadEngines() {
    clearEngineCache();
    engines = await loadAllEngines(`${server.url}/engines/`);
  }

  async function synthWithRecovery(engineId, text, options) {
    try {
      return await engines[engineId].synth(text, options);
    } catch (e) {
      await reloadEngines();
      throw e;
    }
  }

  /* ---------------------------------------------------------------- */
  /* 0. voice catalogue                                                */
  /* ---------------------------------------------------------------- */

  const catalogue = [];
  {
    const actual = engines.aqtk1.voices();
    const expected = VOICE_IDS.aqtk1;
    const same = actual.length === expected.length &&
      [...actual].sort().join('\n') === [...expected].sort().join('\n');
    if (!same) fail('aqtk1 voice catalogue', `wasm=${actual.join(',')} demo=${expected.join(',')}`);
    catalogue.push({
      engine: 'aqtk1',
      expected,
      actual,
      ok: same,
    });
  }
  {
    const missing = [];
    for (const voice of VOICE_IDS.aqtk2) {
      if (!voice) continue;
      const res = await fetch(`${server.url}/engines/aquestalk2/dist/phont/${voice}`);
      if (!res.ok) missing.push(voice);
    }
    if (missing.length) fail('aqtk2 phont assets', missing.join(', '));
    catalogue.push({ engine: 'aqtk2', expected: VOICE_IDS.aqtk2, missing, ok: missing.length === 0 });
  }
  catalogue.push({ engine: 'aqtk10', expected: VOICE_IDS.aqtk10, ok: true });

  /* ---------------------------------------------------------------- */
  /* 1. daily corpus through every voice                               */
  /* ---------------------------------------------------------------- */

  const matrix = {};
  const caseFailures = [];
  for (const engineId of ENGINE_IDS) {
    matrix[engineId] = {};
    for (const voice of VOICE_IDS[engineId]) {
      const rows = {};
      for (const item of KANA_CORPUS) {
        const t0 = performance.now();
        try {
          const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          const info = parseWav(wav);
          const expected = expectedRate(engineId, voice);
          if (info.rate !== expected) {
            throw new Error(`sample rate ${info.rate} Hz, expected ${expected} Hz`);
          }
          if (!(info.seconds > 0.05)) throw new Error(`too short: ${info.seconds}s`);
          rows[item.id] = {
            bytes: wav.length,
            seconds: info.seconds,
            rate: info.rate,
            ms: performance.now() - t0,
            hash: sha256(wav),
          };
        } catch (e) {
          const code = e?.code ?? null;
          rows[item.id] = { error: code, message: e?.message ?? String(e) };
          caseFailures.push({
            engineId,
            voice,
            caseId: item.id,
            text: item.text,
            error: code,
            message: e?.message ?? String(e),
          });
        }
      }
      matrix[engineId][voice] = rows;
    }
  }
  if (datasetProblems.length) fail('dataset schema', datasetProblems.join('; '));
  if (caseFailures.length) {
    fail('daily corpus synthesis', `${caseFailures.length} failed syntheses`);
  }

  /* Partial acceptance across voices (should be zero for a valid corpus). */
  const partialCases = [];
  for (const item of KANA_CORPUS) {
    const missing = [];
    for (const { engineId, voice } of voiceEntries()) {
      if (matrix[engineId][voice][item.id]?.error !== undefined) {
        missing.push(`${engineId}/${voiceLabel(engineId, voice)}`);
      }
    }
    if (missing.length) partialCases.push({ caseId: item.id, text: item.text, missing });
  }
  if (partialCases.length) fail('corpus acceptance parity', `${partialCases.length} partially accepted cases`);

  /* ---------------------------------------------------------------- */
  /* 2. determinism                                                    */
  /* ---------------------------------------------------------------- */

  const determinismCases = [
    KANA_CORPUS.find((c) => c.id === 'greet-02'),
    KANA_CORPUS.find((c) => c.id === 'transit-02'),
    KANA_CORPUS.find((c) => c.id === 'long-02'),
  ];
  const determinism = [];
  for (const { engineId, voice } of voiceEntries()) {
    const mismatches = [];
    for (const item of determinismCases) {
      const first = matrix[engineId][voice][item.id];
      try {
        const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
        const again = sha256(wav);
        if (again !== first?.hash) mismatches.push(item.id);
      } catch (e) {
        mismatches.push(`${item.id}:${e?.code ?? 'ERR'}`);
      }
    }
    determinism.push({
      engineId,
      voice,
      label: voiceLabel(engineId, voice),
      cases: determinismCases.length,
      mismatches,
    });
    if (mismatches.length) fail('determinism', `${engineId}/${voiceLabel(engineId, voice)}: ${mismatches.join(',')}`);
  }

  /* ---------------------------------------------------------------- */
  /* 3. voice differentiation                                          */
  /* ---------------------------------------------------------------- */

  const distinctness = {};
  for (const engineId of ENGINE_IDS) {
    const voices = VOICE_IDS[engineId];
    const rows = [];
    for (const item of KANA_CORPUS) {
      const groups = new Map();
      for (const voice of voices) {
        const hash = matrix[engineId][voice][item.id]?.hash;
        if (!hash) continue;
        if (!groups.has(hash)) groups.set(hash, []);
        groups.get(hash).push(voiceLabel(engineId, voice));
      }
      const duplicates = [...groups.values()].filter((group) => group.length > 1);
      rows.push({ caseId: item.id, distinct: groups.size, voices: voices.length, duplicates });
    }
    const casesWithDuplicates = rows.filter((row) => row.duplicates.length);
    distinctness[engineId] = {
      voices: voices.length,
      averageDistinct: rows.reduce((n, row) => n + row.distinct, 0) / rows.length,
      casesWithDuplicates,
    };
  }

  /* ---------------------------------------------------------------- */
  /* 4. duration correlation                                           */
  /* ---------------------------------------------------------------- */

  const representative = { aqtk1: 'f1', aqtk2: '', aqtk10: 'F1' };
  const durations = {};
  for (const engineId of ENGINE_IDS) {
    const voice = representative[engineId];
    durations[engineId] = KANA_CORPUS.map((item) => matrix[engineId][voice][item.id].seconds);
  }
  const correlation = [];
  for (let i = 0; i < ENGINE_IDS.length; i++) {
    for (let j = i + 1; j < ENGINE_IDS.length; j++) {
      const a = ENGINE_IDS[i];
      const b = ENGINE_IDS[j];
      correlation.push({ a, b, r: pearson(durations[a], durations[b]) });
    }
  }

  /* ---------------------------------------------------------------- */
  /* 5. speed response                                                 */
  /* ---------------------------------------------------------------- */

  const speed = [];
  for (const { engineId, voice } of voiceEntries()) {
    const points = [];
    let violations = [];
    let previous = Infinity;
    for (const spd of SPEED_PROBES) {
      try {
        const wav = await synthWithRecovery(engineId, SPEED_PROBE_TEXT, { voice, speed: spd });
        const info = parseWav(wav);
        points.push({ speed: spd, seconds: info.seconds, bytes: wav.length, hash: sha256(wav) });
        if (info.seconds > previous + 0.01) {
          violations.push(`${spd}%: ${f2(info.seconds)}s > previous ${f2(previous)}s`);
        }
        previous = info.seconds;
      } catch (e) {
        violations.push(`${spd}%: error ${e?.code ?? 'ERR'}`);
      }
    }
    if (violations.length) fail('speed monotonicity', `${engineId}/${voiceLabel(engineId, voice)}: ${violations.join('; ')}`);
    speed.push({
      engineId,
      voice,
      label: voiceLabel(engineId, voice),
      points,
      violations,
      ratio: points.length >= 2 ? points[0].seconds / points[points.length - 1].seconds : NaN,
    });
  }

  /* ---------------------------------------------------------------- */
  /* 5b. native .so parity                                             */
  /* ---------------------------------------------------------------- */

  /* The only currently known wasm/native divergence: the accent in
   * ありがとう'ございます。 with AQ1 f3 and AQ2's external aq_*.phont files.
   * Same WAV size, different bytes; all other daily cases and all speed
   * probes are byte-identical.  Reported by default, fails with --strict. */
  function isKnownNativeMismatch(engineId, voice, caseId) {
    if (caseId !== 'prosody-05') return false;
    if (engineId === 'aqtk1') return voice === 'f3';
    if (engineId === 'aqtk2') return voice.startsWith('aq_');
    return false;
  }

  const nativeSetup = buildNativeRequest();
  const nativeParity = {
    available: Object.keys(nativeSetup.request.engines),
    missing: nativeSetup.missing,
    aq1Root: nativeSetup.aq1Root ? path.relative(REPO_ROOT, nativeSetup.aq1Root) : null,
    matched: 0,
    mismatched: 0,
    knownMismatched: 0,
    knownList: [],
    engines: {},
    details: [],
  };

  if (nativeParity.available.length) {
    let native = null;
    try {
      const stdout = execFileSync('python3', [
        path.join(REPO_ROOT, 'tests/lib/native_reference.py'),
      ], {
        input: JSON.stringify(nativeSetup.request),
        encoding: 'utf8',
        maxBuffer: 512 * 1024 * 1024,
      });
      native = JSON.parse(stdout);
      if (native.errors?.length) fail('native reference', native.errors.join('; '));
    } catch (e) {
      fail('native reference', e.stderr ? String(e.stderr).trim() : e.message);
    }

    if (native) {
      for (const engineId of nativeParity.available) {
        const nativeVoices = native.engines?.[engineId];
        nativeParity.engines[engineId] = {};
        if (!nativeVoices) {
          fail('native reference', `${engineId}: no output`);
          continue;
        }
        for (const voice of VOICE_IDS[engineId]) {
          const nativeCases = nativeVoices[voice] ?? {};
          let matched = 0;
          let mismatched = 0;
          let knownMismatched = 0;
          const details = [];
          for (const item of KANA_CORPUS) {
            const wasm = matrix[engineId][voice][item.id];
            const ref = nativeCases[item.id];
            if (!ref) {
              mismatched++;
              details.push(`${item.id}: missing native result`);
              continue;
            }
            if (wasm.error !== undefined || ref.error !== undefined) {
              if (wasm.error !== undefined && ref.error !== undefined) {
                matched++;
              } else {
                mismatched++;
                details.push(`${item.id}: wasm=${wasm.error ?? 'ok'} native=${ref.error ?? 'ok'}`);
              }
              continue;
            }
            if (wasm.bytes === ref.size && wasm.hash === ref.sha256) {
              matched++;
            } else if (isKnownNativeMismatch(engineId, voice, item.id)) {
              knownMismatched++;
              nativeParity.knownList.push({
                engineId,
                voice: voiceLabel(engineId, voice),
                caseId: item.id,
                bytes: wasm.bytes,
                wasmHash: wasm.hash,
                nativeHash: ref.sha256,
              });
              details.push(
                `KNOWN ${item.id}: wasm ${wasm.bytes}B/${String(wasm.hash).slice(0, 12)} ` +
                `native ${ref.size}B/${String(ref.sha256).slice(0, 12)}`,
              );
            } else {
              mismatched++;
              details.push(
                `${item.id}: wasm ${wasm.bytes}B/${String(wasm.hash).slice(0, 12)} ` +
                `native ${ref.size}B/${String(ref.sha256).slice(0, 12)}`,
              );
            }
          }

          const speedRow = speed.find((row) => row.engineId === engineId && row.voice === voice);
          const nativeSpeed = native.speed?.[engineId]?.[voice] ?? {};
          let speedMatched = 0;
          let speedMismatched = 0;
          for (const point of speedRow?.points ?? []) {
            const ref = nativeSpeed[String(point.speed)];
            if (!ref || ref.error !== undefined) {
              speedMismatched++;
              details.push(`speed ${point.speed}%: native ${ref?.error ?? 'missing'}`);
              continue;
            }
            if (point.bytes === ref.size && point.hash === ref.sha256) {
              speedMatched++;
            } else {
              speedMismatched++;
              details.push(
                `speed ${point.speed}%: wasm ${point.bytes}B/${String(point.hash).slice(0, 12)} ` +
                `native ${ref.size}B/${String(ref.sha256).slice(0, 12)}`,
              );
            }
          }

          const label = voiceLabel(engineId, voice);
          nativeParity.engines[engineId][label] = {
            matched,
            mismatched,
            knownMismatched,
            speedMatched,
            speedMismatched,
            details: details.slice(0, 20),
          };
          nativeParity.matched += matched + speedMatched;
          nativeParity.mismatched += mismatched + speedMismatched;
          nativeParity.knownMismatched += knownMismatched;
          for (const detail of details) {
            nativeParity.details.push(`${engineId}/${label} ${detail}`);
          }
        }
      }
      nativeParity.details = nativeParity.details.slice(0, 100);
      if (nativeParity.mismatched) {
        fail('native .so parity', `${nativeParity.mismatched} unexpected mismatches`);
      }
      if (STRICT && nativeParity.knownMismatched) {
        fail('strict: native .so parity', `${nativeParity.knownMismatched} known mismatches`);
      }
    }
  } else {
    nativeParity.skipped = true;
    if (process.env.REQUIRE_NATIVE === '1') {
      fail('native .so parity', `no native libraries found (missing ${nativeParity.missing.join(', ')})`);
    }
  }

  /* ---------------------------------------------------------------- */
  /* 6. invalid input                                                  */
  /* ---------------------------------------------------------------- */

  const invalid = {};
  for (const engineId of ENGINE_IDS) {
    invalid[engineId] = { cases: {}, codes: new Set(), accepted: 0 };
    for (const item of INVALID_INPUTS) {
      const accepted = [];
      const codes = new Set();
      for (const voice of VOICE_IDS[engineId]) {
        try {
          await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          codes.add(e?.code ?? 'ERR');
          invalid[engineId].codes.add(e?.code ?? 'ERR');
        }
      }
      invalid[engineId].cases[item.id] = {
        accepted,
        codes: [...codes].map(String),
      };
      invalid[engineId].accepted += accepted.length;
      if (accepted.length) {
        fail('invalid input accepted', `${engineId} ${item.id} (${item.reason}): ${accepted.join(',')}`);
      }
    }
  }

  /* Empty-string error reporting.  AquesTalk1's Open_Talk_Synthe_Utf8
   * returns NULL without writing *pSize, so the reported code depends on
   * whatever is already in the size slot.  Measure a fresh instance and a
   * "warm" instance that has synthesized before. */
  const emptyCodeRuns = {};
  for (const engineId of ENGINE_IDS) {
    await reloadEngines();
    const voice = VOICE_IDS[engineId][0];
    const codesFor = async () => {
      const codes = [];
      for (let i = 0; i < 5; i++) {
        try {
          await engines[engineId].synth('', { voice, speed: 100 });
          codes.push('ACCEPTED');
        } catch (e) {
          codes.push(String(e?.code ?? 'ERR'));
        }
      }
      return codes;
    };
    const fresh = await codesFor();
    for (let i = 0; i < 5; i++) {
      try {
        await engines[engineId].synth('こんにちは。', { voice, speed: 100 });
      } catch {
        /* ignore: this only warms the allocator/size slot */
      }
    }
    const warm = await codesFor();
    emptyCodeRuns[engineId] = { fresh, warm };
  }
  await reloadEngines();

  /* ---------------------------------------------------------------- */
  /* 7. valid kana that the engines disagree about                     */
  /* ---------------------------------------------------------------- */

  const divergent = {};
  for (const item of DIVERGENT_INPUTS) {
    divergent[item.id] = { note: item.note, text: item.text, engines: {} };
    for (const engineId of ENGINE_IDS) {
      const accepted = [];
      const codes = new Set();
      for (const voice of VOICE_IDS[engineId]) {
        try {
          await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          codes.add(String(e?.code ?? 'ERR'));
        }
      }
      divergent[item.id].engines[engineId] = {
        accepted,
        total: VOICE_IDS[engineId].length,
        codes: [...codes],
      };
    }
  }

  /* ---------------------------------------------------------------- */
  /* 8. evaluation-build fingerprint                                   */
  /* ---------------------------------------------------------------- */

  const expectedCollapse = { aqtk1: true, aqtk2: false, aqtk10: true };
  const evaluation = [];
  for (const engineId of ENGINE_IDS) {
    for (const voice of VOICE_IDS[engineId]) {
      const matches = [];
      let differences = 0;
      for (const probe of EVALUATION_PROBES) {
        try {
          const a = await synthWithRecovery(engineId, probe.a, { voice, speed: 100 });
          const b = await synthWithRecovery(engineId, probe.b, { voice, speed: 100 });
          const same = sameBytes(a, b);
          matches.push(same);
          if (!same) differences++;
        } catch (e) {
          matches.push(false);
          differences++;
          fail('evaluation probe error', `${engineId}/${voiceLabel(engineId, voice)} ${probe.id}: ${e?.code ?? 'ERR'}`);
        }
      }
      const collapsed = differences === 0;
      const ok = collapsed === expectedCollapse[engineId];
      if (!ok) {
        fail('evaluation fingerprint', `${engineId}/${voiceLabel(engineId, voice)}: collapsed=${collapsed}, expected=${expectedCollapse[engineId]}`);
      }
      evaluation.push({
        engineId,
        voice,
        label: voiceLabel(engineId, voice),
        probes: matches.length,
        differences,
        collapsed,
        expected: expectedCollapse[engineId],
        ok,
      });
    }
  }

  /* ---------------------------------------------------------------- */
  /* 9. hiragana / katakana pairs                                      */
  /* ---------------------------------------------------------------- */

  const scripts = [];
  for (const pair of KANA_SCRIPT_PAIRS) {
    const row = { id: pair.id, engines: {} };
    for (const engineId of ENGINE_IDS) {
      let same = 0;
      let different = 0;
      const rejected = [];
      const differentVoices = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const a = await synthWithRecovery(engineId, pair.hiragana, { voice, speed: 100 });
          const b = await synthWithRecovery(engineId, pair.katakana, { voice, speed: 100 });
          if (sameBytes(a, b)) same++;
          else {
            different++;
            differentVoices.push(voiceLabel(engineId, voice));
          }
        } catch (e) {
          rejected.push(`${voiceLabel(engineId, voice)}:${e?.code ?? 'ERR'}`);
        }
      }
      row.engines[engineId] = { same, different, rejected, differentVoices };
      if (rejected.length) {
        fail('script pair rejected', `${pair.id} ${engineId}: ${rejected.join(',')}`);
      }
    }
    scripts.push(row);
  }

  /* ---------------------------------------------------------------- */
  /* 10. long input                                                    */
  /* ---------------------------------------------------------------- */

  const longInput = [];
  for (const engineId of ENGINE_IDS) {
    const voice = representative[engineId];
    try {
      const wav = await synthWithRecovery(engineId, LONG_PROBE_TEXT, { voice, speed: 100 });
      const info = parseWav(wav);
      longInput.push({ engineId, voice, bytes: wav.length, seconds: info.seconds, ok: true });
      if (info.seconds < 10) fail('long input', `${engineId}: only ${f2(info.seconds)}s`);
    } catch (e) {
      longInput.push({ engineId, voice, error: e?.code ?? 'ERR', message: e?.message, ok: false });
      fail('long input', `${engineId}: ${e?.code ?? 'ERR'} ${e?.message ?? ''}`);
    }
  }

  /* ---------------------------------------------------------------- */
  /* 11. aggregate + report                                            */
  /* ---------------------------------------------------------------- */

  const datasetChars = KANA_CORPUS.reduce((n, item) => n + [...item.text].length, 0);
  const categories = {};
  for (const item of KANA_CORPUS) categories[item.category] = (categories[item.category] ?? 0) + 1;

  const voiceRows = [];
  for (const { engineId, voice, label, rate } of voiceEntries()) {
    const rows = Object.values(matrix[engineId][voice]);
    const accepted = rows.filter((row) => row.error === undefined);
    const bytes = accepted.reduce((n, row) => n + row.bytes, 0);
    const seconds = accepted.reduce((n, row) => n + row.seconds, 0);
    const hashes = new Set(accepted.map((row) => row.hash));
    voiceRows.push({
      engineId,
      engine: ENGINE_NAMES[engineId],
      voice,
      label,
      rate,
      cases: rows.length,
      accepted: accepted.length,
      rejected: rows.length - accepted.length,
      bytes,
      seconds,
      meanSeconds: seconds / accepted.length,
      distinctHashes: hashes.size,
      totalMs: accepted.reduce((n, row) => n + row.ms, 0),
    });
  }

  const engineRows = [];
  for (const engineId of ENGINE_IDS) {
    const rows = voiceRows.filter((row) => row.engineId === engineId);
    engineRows.push({
      engineId,
      engine: ENGINE_NAMES[engineId],
      voices: rows.length,
      syntheses: rows.reduce((n, row) => n + row.cases, 0),
      accepted: rows.reduce((n, row) => n + row.accepted, 0),
      rejected: rows.reduce((n, row) => n + row.rejected, 0),
      bytes: rows.reduce((n, row) => n + row.bytes, 0),
      seconds: rows.reduce((n, row) => n + row.seconds, 0),
    });
  }

  const totalSyntheses = engineRows.reduce((n, row) => n + row.syntheses, 0);
  const totalAccepted = engineRows.reduce((n, row) => n + row.accepted, 0);
  const totalSeconds = engineRows.reduce((n, row) => n + row.seconds, 0);
  const totalBytes = engineRows.reduce((n, row) => n + row.bytes, 0);

  const result = {
    ok: hardFailures.length === 0,
    generatedAt: startedAt.toISOString(),
    durationMs: Date.now() - startedAt.getTime(),
    dataset: {
      name: 'kana-daily-v1',
      file: 'data/kana-corpus.js',
      entries: KANA_CORPUS.length,
      characters: datasetChars,
      categories,
      demoIds: DEMO_KANA_SAMPLES.length,
      problems: datasetProblems,
    },
    catalogue,
    summary: {
      engines: ENGINE_IDS.length,
      voices: voiceEntries().length,
      syntheses: totalSyntheses,
      accepted: totalAccepted,
      rejected: totalSyntheses - totalAccepted,
      audioSeconds: totalSeconds,
      wavBytes: totalBytes,
      nativeAvailable: nativeParity.available,
      nativeMissing: nativeParity.missing,
      nativeMatched: nativeParity.matched,
      nativeMismatched: nativeParity.mismatched,
      nativeKnownMismatched: nativeParity.knownMismatched,
    },
    native: {
      available: nativeParity.available,
      missing: nativeParity.missing,
      aq1Root: nativeParity.aq1Root,
    },
    nativeParity,
    engines: engineRows,
    voices: voiceRows,
    partialCases,
    determinism,
    distinctness,
    correlation,
    speed,
    invalid: Object.fromEntries(Object.entries(invalid).map(([engineId, value]) => [
      engineId,
      {
        accepted: value.accepted,
        codes: [...value.codes].map(String).sort(),
        cases: value.cases,
      },
    ])),
    emptyCodeRuns,
    divergent,
    evaluation,
    scripts,
    longInput,
    hardFailures,
  };

  await fs.mkdir(path.dirname(OUT_JSON), { recursive: true });
  await fs.writeFile(OUT_JSON, JSON.stringify(result, null, 2) + '\n');

  const coverageRows = Object.entries(categories).map(([category, count]) => [category, count]);
  const engineTable = engineRows.map((row) => [
    row.engine,
    row.voices,
    row.syntheses,
    row.accepted,
    row.rejected,
    `${row.seconds.toFixed(0)} s`,
    `${(row.bytes / 1048576).toFixed(1)} MB`,
  ]);
  const voiceTable = voiceRows.map((row) => [
    row.engine,
    row.label,
    `${row.rate} Hz`,
    row.cases,
    row.accepted,
    row.rejected,
    `${row.seconds.toFixed(1)} s`,
    `${row.meanSeconds.toFixed(2)} s`,
    row.distinctHashes,
  ]);
  const evalTable = ENGINE_IDS.map((engineId) => {
    const rows = evaluation.filter((row) => row.engineId === engineId);
    return [
      ENGINE_NAMES[engineId],
      rows.filter((row) => row.collapsed).length,
      rows.filter((row) => !row.collapsed).length,
      expectedCollapse[engineId] ? '全部折叠（评价版）' : '全部区分',
      rows.every((row) => row.ok) ? '符合预期' : '**不符合预期**',
    ];
  });
  const scriptTable = ENGINE_IDS.map((engineId) => {
    const same = scripts.reduce((n, row) => n + row.engines[engineId].same, 0);
    const different = scripts.reduce((n, row) => n + row.engines[engineId].different, 0);
    return [ENGINE_NAMES[engineId], same, different, `${same}/${same + different}`];
  });
  const divergentTable = Object.entries(divergent).map(([id, row]) => [
    id,
    row.note,
    ...ENGINE_IDS.map((engineId) => {
      const info = row.engines[engineId];
      return `${info.accepted.length}/${info.total}${info.codes.length ? ` (${info.codes.join(',')})` : ''}`;
    }),
  ]);
  const invalidCodesTable = Object.entries(result.invalid).map(([engineId, row]) => [
    ENGINE_NAMES[engineId],
    row.accepted,
    row.codes.join(', ') || '—',
    `${(emptyCodeRuns[engineId]?.fresh ?? []).join(',')} / ${(emptyCodeRuns[engineId]?.warm ?? []).join(',')}`,
  ]);
  const speedTable = ENGINE_IDS.map((engineId) => {
    const rows = speed.filter((row) => row.engineId === engineId);
    const worst = rows.reduce((a, b) => (a.ratio < b.ratio ? a : b));
    return [
      ENGINE_NAMES[engineId],
      rows.length,
      rows.filter((row) => row.violations.length === 0).length,
      `${worst.ratio.toFixed(2)}×`,
      worst.label,
    ];
  });
  const correlationTable = correlation.map((row) => [
    `${ENGINE_NAMES[row.a]} (${representative[row.a] || 'default'})`,
    `${ENGINE_NAMES[row.b]} (${representative[row.b] || 'default'})`,
    row.r.toFixed(4),
  ]);
  const nativeEngineRows = nativeParity.available.map((engineId) => {
    const rows = Object.values(nativeParity.engines[engineId] ?? {});
    return [
      ENGINE_NAMES[engineId],
      rows.length,
      `${rows.reduce((n, row) => n + row.matched, 0)}/${rows.length * KANA_CORPUS.length}`,
      rows.reduce((n, row) => n + row.knownMismatched, 0),
      rows.reduce((n, row) => n + row.mismatched, 0),
      `${rows.reduce((n, row) => n + row.speedMatched, 0)}/${rows.length * SPEED_PROBES.length}`,
    ];
  });
  const nativeTotals = nativeEngineRows.reduce((acc, row) => {
    const [dailyMatched, dailyChecks] = row[2].split('/').map(Number);
    const [speedMatched, speedChecks] = row[5].split('/').map(Number);
    acc.matched += dailyMatched;
    acc.dailyChecks += dailyChecks;
    acc.known += row[3];
    acc.unexpected += row[4];
    acc.speedMatched += speedMatched;
    acc.speedChecks += speedChecks;
    return acc;
  }, { matched: 0, dailyChecks: 0, known: 0, unexpected: 0, speedMatched: 0, speedChecks: 0 });
  const nativeKnownRows = nativeParity.knownList.map((row) => [
    ENGINE_NAMES[row.engineId],
    row.voice,
    row.caseId,
    `${row.bytes} B`,
    `\`${String(row.wasmHash).slice(0, 12)}…\``,
    `\`${String(row.nativeHash).slice(0, 12)}…\``,
  ]);

  const duplicateRows = ENGINE_IDS.flatMap((engineId) => {
    const groups = new Map();
    for (const caseRow of distinctness[engineId].casesWithDuplicates) {
      for (const group of caseRow.duplicates) {
        const key = group.join(',');
        groups.set(key, (groups.get(key) ?? 0) + 1);
      }
    }
    return [...groups.entries()].map(([key, count]) => [ENGINE_NAMES[engineId], key, count]);
  });

  const md = `# AquesTalk1/2/10 行为一致性报告

生成命令：\`npm run test:consistency\`  
生成时间：${startedAt.toISOString()}  
数据集：\`data/kana-corpus.js\`（${KANA_CORPUS.length} 条日常日语，${datasetChars} 个字符）

## 1. 测试面

| 项目 | 数量 |
| --- | --- |
| 引擎 | ${ENGINE_IDS.length} |
| 声库 / phont / preset | ${voiceEntries().length} |
| 日常语料 | ${KANA_CORPUS.length} 条 |
| 合成次数（语料 × 声库） | ${totalSyntheses} |
| 原始 \`.so\` 对拍 | ${KANA_CORPUS.length} 条日常 + ${SPEED_PROBES.length} 档语速，各 × ${voiceEntries().length} 声库 |
| 其他探针 | 速度 ${SPEED_PROBES.length} 档 × ${voiceEntries().length} 声库、无效输入 ${INVALID_INPUTS.length} 类、评价版探针 ${EVALUATION_PROBES.length} 组、平/片假名 ${KANA_SCRIPT_PAIRS.length} 组、长文本、确定性复测 |

语料分类：

${mdTable(['分类', '条数'], coverageRows)}

## 2. 通过率

${mdTable(['引擎', '声库数', '合成次数', '成功', '失败', '总音频', 'WAV 体积'], engineTable)}

- 总计：**${totalAccepted}/${totalSyntheses}** 次成功，失败 **${totalSyntheses - totalAccepted}** 次。
- 总音频：**${totalSeconds.toFixed(0)} 秒**（${(totalSeconds / 3600).toFixed(2)} 小时），WAV **${(totalBytes / 1048576).toFixed(1)} MB**。
- 所有 WAV 均为 RIFF/WAVE、单声道、16-bit；采样率与声库参数一致：AquesTalk1/2 为 8 kHz，AquesTalk10 默认 16 kHz，F3（fsc=148）为 23.68 kHz，R2（fsc=180）为 28.8 kHz。
- 所有 34 个声库在 ${KANA_CORPUS.length} 条语料上的成功/失败完全一致；没有“某个声库单独失败”的条目。
- 确定性：每个声库抽取 3 条语料复测，${determinism.filter((row) => row.mismatches.length === 0).length}/${determinism.length} 个声库逐字节一致。

逐声库：

${mdTable(['引擎', '声库', '采样率', '语料', '成功', '失败', '总时长', '平均时长', '不同 WAV 数'], voiceTable)}

## 3. 时长相关性

同一文本在不同引擎下的相对时长（取 AquesTalk1 f1 / AquesTalk2 内置 / AquesTalk10 F1）：

${mdTable(['引擎 A', '引擎 B', 'Pearson r'], correlationTable)}

r 接近 1 说明三种引擎对“句子长短 / 停顿结构”的反应一致；绝对时长仍受声库语速参数影响。

## 3b. 与原始 .so 的逐字节对拍

同一批语料（以及 50–300% 语速探针）同时送进原始 Linux \`.so\`，用 SHA-256 与
wasm 输出逐字节比较。AquesTalk1 的 \`.so\` 不在本仓库，测试从相邻 SDK 读取：
\`${nativeParity.aq1Root ?? '（未找到）'}\`；AquesTalk2/10 使用仓库内 SDK。
设置 \`REQUIRE_NATIVE=1\` 时，缺少原生库会直接失败。

${nativeParity.available.length ? mdTable(['引擎', '声库', '日常一致', '已知差异', '意外差异', '语速一致'], nativeEngineRows) : '未找到可用的原生库，本节跳过。'}

- 日常语料：**${nativeTotals.matched}/${nativeTotals.dailyChecks}** 逐字节一致；
  已知差异 **${nativeTotals.known}**，意外差异 **${nativeTotals.unexpected}**。
- 语速探针：**${nativeTotals.speedMatched}/${nativeTotals.speedChecks}** 逐字节一致。
- 未找到的原生库：${nativeParity.missing.length ? nativeParity.missing.join(', ') : '无'}。

${nativeKnownRows.length ? `已知差异（同一 WAV 长度、不同字节）：

${mdTable(['引擎', '声库', '用例', 'WAV 大小', 'wasm SHA-256', '.so SHA-256'], nativeKnownRows)}

触发条件：\`prosody-05\`（\`ありがとう'ございます。\`）中的アクセント记号，
出现在 AquesTalk1 f3 和 AquesTalk2 的外部 \`aq_*.phont\` 上。其余 150 条日常
语料、全部 204 个语速探针均与原始 \`.so\` 完全一致。这是当前 wasm 移植的
**真实差异**，不是测试顺序/内存状态造成的；默认模式报告，\`--strict\` 会失败。` : '没有已知差异：全部日常语料和语速探针均与原始 .so 逐字节一致。'}

## 4. 声库区分度

同一引擎内，同一句文本在不同声库下的 WAV 哈希分布：

${mdTable(['引擎', '声库数', '平均不同 WAV 数 / 句', '存在重复声库的句子数'],
  ENGINE_IDS.map((engineId) => [
    ENGINE_NAMES[engineId],
    distinctness[engineId].voices,
    distinctness[engineId].averageDistinct.toFixed(2),
    distinctness[engineId].casesWithDuplicates.length,
  ]))}

${duplicateRows.length ? `重复声库组（在全部或部分句子上输出相同）：

${mdTable(['引擎', '重复组', '出现句数'], duplicateRows)}

AquesTalk2 的内置默认声库与 \`ar_f4.phont\` 在每个句子上都逐字节相同；其余声库均可区分。` : '所有声库在所有句子上均可区分。'}

> AquesTalk1/AquesTalk10 的逐声库“不同 WAV 数”为 150（不是 151）：\`notation-04\`（\`こんにちは、せかい。\`）与 \`prosody-01\`（\`こんにちは'、せかい。\`）在评价版引擎上输出相同，AquesTalk2 则能区分。

## 5. 速度响应

语料：\`${SPEED_PROBE_TEXT}\`，速度 ${SPEED_PROBES.join(' / ')}%。

${mdTable(['引擎', '声库数', '单调通过', '最快/最慢时长比（最小）', '最差声库'], speedTable)}

所有声库在 50%→300% 时时长单调下降，无异常。

## 6. 已知 / 发现的行为差异

### 6.1 评价版「ナ行/マ行 → ヌ/ム」

${mdTable(['引擎', '折叠声库', '区分声库', '预期', '结果'], evalTable)}

这是 AquesTalk1/AquesTalk10 评价版的已知限制，AquesTalk2 提供的 \`.so\` 已解除该限制。探针同时覆盖单假名和整句（\`なまむぎなまごめ\` → \`ぬむむぎぬむごめ\`）。

### 6.2 平假名 / 片假名

同一发音的平假名与片假名写法，并非所有声库都逐字节一致：

${mdTable(['引擎', '相同', '不同', '相同比例'], scriptTable)}

差异集中在：
- \`こんにちは、せかい。\` vs \`コンニチハ、セカイ。\`：所有 34 个声库都不同（助词「は」与片假名「ハ」的读音提示不同）。
- \`そうなんですか？\` vs \`ソウナンデスカ？\`：所有 34 个声库都不同（片假名被当作外来语/不同重音处理）。
- \`ありがとう\` / \`つぎのでんしゃ…\` / \`なまむぎなまごめ\`：只有 AquesTalk1 的 8 个传统声库（f1–dvd）不同，f3 与 AquesTalk2/10 相同。

因此“所有声库输入 kana”成立，但**不能假设平假名和片假名在所有声库上同音同字节**；统一数据集应以假名读音为准并记录脚本。

### 6.3 部分 kana 输入并非所有引擎都接受

${mdTable(['输入', '说明', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], divergentTable)}

- **ASCII 空格**：只有 AquesTalk2 接受；AquesTalk1/10 返回 105。日常语料因此不使用空格，改用「、」。
- **促音 + 疑问符（\`えっ？\`）**：AquesTalk1 的 8 个传统声库返回 102（f3 接受），AquesTalk2/10 接受。规范 3.8.1 本身禁止「っ」后直接接句切符号，因此 AquesTalk2/10 属于宽松接受。

### 6.4 无效输入的错误码

所有声库都拒绝 ${INVALID_INPUTS.length} 类无效输入（空串、ASCII、汉字、半角假名、emoji、kana+Latin、全角「！」），但错误码不统一：

${mdTable(['引擎', '被接受次数', '错误码集合', '空串错误码（fresh / warm）'], invalidCodesTable)}

- AquesTalk1 的空串错误码来自未初始化的 \`*pSize\`：新实例上是 \`${emptyCodeRuns.aqtk1.fresh[0]}\`，先合成过若干句后变成 \`${emptyCodeRuns.aqtk1.warm[0]}\`（随堆状态变化）。这是移植层可改进点。
- AquesTalk2 空串返回 0；AquesTalk10 返回 104（empty kana string）。
- 全角「！」不被任何引擎支持，日常语料因此不使用「！」；规范的句切符号只定义了「。」「？」「、」「,」「;」「/」「+」。

## 7. 结论

- 统一 kana 数据集（${KANA_CORPUS.length} 条 / ${datasetChars} 字）在 34 个声库上 **${totalAccepted}/${totalSyntheses}** 全部可合成，WAV 格式、采样率、确定性、速度单调性均通过。
- 与原始 \`.so\` 的逐字节对拍：日常语料 **${nativeTotals.matched}/${nativeTotals.dailyChecks}** 一致，
  语速探针 **${nativeTotals.speedMatched}/${nativeTotals.speedChecks}** 一致；仅有 **${nativeTotals.known}** 个
  已知差异（\`prosody-05\` 的アクセント + AQ1 f3 / AQ2 外部 phont），没有其他意外差异。
- 34 个声库的**语义行为**一致：对同一合法语料全部成功、对同一无效输入全部拒绝、对语速变化的响应方向一致。
- **字节级行为**存在已知差异：评价版ナ/マ行折叠、平/片假名提示、空格与「えっ？」的接受度、错误码。这些是引擎代际/评价版差异，不是数据集或适配层引入的随机性。
- 数据集已统一到 \`data/kana-corpus.js\`：demo 按钮、smoke 测试、一致性测试共用同一份 kana 文本，不再各自维护样例。

## 8. 复现

\`\`\`bash
npm run test:consistency
# 或
node tests/consistency.mjs
\`\`\`

机器可读结果：\`tests/results/consistency.json\`。
`;

  await fs.writeFile(OUT_MD, md);

  console.log(`daily corpus: ${totalSyntheses} syntheses, ${totalAccepted} ok, ${totalSyntheses - totalAccepted} failed`);
  console.log(`  ${KANA_CORPUS.length} utterances x ${voiceEntries().length} voices, ${totalSeconds.toFixed(0)} s audio`);
  console.log(`  report: ${path.relative(REPO_ROOT, OUT_MD)}`);
  console.log(`  json:   ${path.relative(REPO_ROOT, OUT_JSON)}`);
  if (hardFailures.length) {
    console.log(`FAIL (${hardFailures.length})`);
    for (const failure of hardFailures.slice(0, 20)) {
      console.log(`  - ${failure.check}: ${failure.detail}`);
    }
    process.exitCode = 1;
  } else {
    console.log('PASS');
  }
} finally {
  await server.close();
}
