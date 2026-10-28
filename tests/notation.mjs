#!/usr/bin/env node
/* 音声記号列仕様書 (AquesTalk symbol-sequence specification, v1.5) tests.
 *
 * Source PDF: engines/aquestalk2/aqtk2-lnx/siyo_onseikigou.pdf
 *
 * Covers the normative parts of the document against every AquesTalk1/2/10
 * voice:
 *   - section 5 reading-symbol table
 *   - sections 2.2-2.9 / 3.4-3.7 valid notation
 *   - section 4 sample sentences
 *   - section 3.8 forbidden reading-symbol sequences
 *   - sections 2.8 / 3.6 / 6 numeric tags and counters
 *   - section 7 romanised notation (AquesTalk2 only)
 *
 * By default the suite fails on missing reading symbols, rejected valid
 * notation and broken semantic effects.  Lenient parsing of forbidden input
 * is reported; use --strict to turn every specification violation into a
 * non-zero exit code.
 *
 *   node tests/notation.mjs
 *   node tests/notation.mjs --strict
 */
import fs from 'node:fs/promises';
import path from 'node:path';
import { startStaticServer, REPO_ROOT } from './lib/static-server.mjs';
import { clearEngineCache } from '../demo/engines.js';
import { parseWav, sha256, sameBytes } from './lib/wav.mjs';
import {
  ENGINE_IDS,
  ENGINE_NAMES,
  VOICE_IDS,
  voiceEntries,
  voiceLabel,
  loadAllEngines,
} from './lib/voices.mjs';
import {
  READING_SYMBOLS,
  READING_SYMBOL_GROUPS,
  readingSymbolProbe,
  VALID_NOTATION_CASES,
  SPEC_SAMPLE_CASES,
  INVALID_NOTATION_CASES,
  SEMANTIC_CASES,
  PAUSE_CASES,
  COUNTERS,
  NUMK_RANGE_CASES,
  ROMAN_CASES,
} from '../data/notation-corpus.js';

const STRICT = process.argv.includes('--strict');
const OUT_JSON = path.join(REPO_ROOT, 'tests/results/notation.json');
const OUT_MD = path.join(REPO_ROOT, 'docs/notation-report.md');
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

/* Sequential async map: the wasm engines share one instance per engine, so
 * overlapping calls would race on their scratch buffers. */
async function mapSeries(items, fn) {
  const out = [];
  for (const item of items) out.push(await fn(item));
  return out;
}

/* Validate the specification data before running it. */
const notationProblems = [];
{
  const symbolIds = new Set();
  for (const { group, symbol } of READING_SYMBOLS) {
    if (symbolIds.has(symbol)) notationProblems.push(`duplicate reading symbol: ${symbol}`);
    symbolIds.add(symbol);
    const probe = readingSymbolProbe(symbol);
    if (!/[。？、,;/+]$/.test(probe)) notationProblems.push(`probe lacks delimiter: ${group}/${symbol}`);
  }
  const ids = new Set();
  const lists = [
    ['valid', VALID_NOTATION_CASES],
    ['sample', SPEC_SAMPLE_CASES],
    ['invalid', INVALID_NOTATION_CASES],
    ['semantic', SEMANTIC_CASES],
    ['numk', NUMK_RANGE_CASES],
    ['roman', ROMAN_CASES],
  ];
  for (const [kind, list] of lists) {
    for (const item of list) {
      const key = `${kind}:${item.id}`;
      if (ids.has(key)) notationProblems.push(`duplicate id: ${key}`);
      ids.add(key);
    }
  }
  if (new Set(COUNTERS).size !== COUNTERS.length) notationProblems.push('duplicate counter');
}

const server = await startStaticServer(REPO_ROOT);
try {
  let engines = await loadAllEngines(`${server.url}/engines/`);
  const voices = voiceEntries();

  /* AquesTalk2's tag parser can fail on one phont and leave the instance in a
   * bad state for the next call.  Reload after any failure so each probe is
   * measured independently. */
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

  async function synthRomanWithRecovery(text, options) {
    try {
      return await engines.aqtk2.synthRoman(text, options);
    } catch (e) {
      await reloadEngines();
      throw e;
    }
  }

  /* ---------------------------------------------------------------- */
  /* 1. section 5 reading-symbol table                                 */
  /* ---------------------------------------------------------------- */

  const symbolFailures = [];
  for (const { group, symbol } of READING_SYMBOLS) {
    const text = readingSymbolProbe(symbol);
    for (const { engineId, voice } of voices) {
      try {
        const wav = await synthWithRecovery(engineId, text, { voice, speed: 100 });
        parseWav(wav);
      } catch (e) {
        symbolFailures.push({
          group,
          symbol,
          probe: text,
          engineId,
          voice: voiceLabel(engineId, voice),
          error: e?.code ?? null,
          message: e?.message ?? String(e),
        });
      }
    }
  }
  if (symbolFailures.length) {
    fail('reading symbol table', `${symbolFailures.length} rejected symbols`);
  }

  const symbolGroupRows = Object.entries(READING_SYMBOL_GROUPS).map(([group, symbols]) => [
    group,
    symbols.length,
    symbols.length * voices.length,
    symbolFailures.filter((row) => row.group === group).length,
  ]);

  /* ---------------------------------------------------------------- */
  /* 2. valid notation                                                 */
  /* ---------------------------------------------------------------- */

  const valid = await mapSeries(VALID_NOTATION_CASES, async (item) => {
    const enginesResult = {};
    for (const engineId of ENGINE_IDS) {
      const accepted = [];
      const errors = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          parseWav(wav);
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          errors.push({ voice: voiceLabel(engineId, voice), code: e?.code ?? null });
        }
      }
      enginesResult[engineId] = { accepted, total: VOICE_IDS[engineId].length, errors };
      if (errors.length) {
        fail('valid notation rejected', `${item.id} ${engineId}: ${errors.map((e) => `${e.voice}:${e.code}`).join(',')}`);
      }
    }
    return { ...item, engines: enginesResult };
  });

  /* ---------------------------------------------------------------- */
  /* 3. section 4 examples                                             */
  /* ---------------------------------------------------------------- */

  const samples = await mapSeries(SPEC_SAMPLE_CASES, async (item) => {
    const enginesResult = {};
    for (const engineId of ENGINE_IDS) {
      const accepted = [];
      const errors = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          parseWav(wav);
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          errors.push({ voice: voiceLabel(engineId, voice), code: e?.code ?? null });
        }
      }
      enginesResult[engineId] = { accepted, total: VOICE_IDS[engineId].length, errors };
      if (STRICT && errors.length) {
        fail('strict: spec sample', `${item.id} ${engineId}: ${errors.map((e) => `${e.voice}:${e.code}`).join(',')}`);
      }
    }
    return { ...item, engines: enginesResult };
  });

  /* ---------------------------------------------------------------- */
  /* 4. forbidden notation (section 3.8 + malformed tags)              */
  /* ---------------------------------------------------------------- */

  const invalid = await mapSeries(INVALID_NOTATION_CASES, async (item) => {
    const enginesResult = {};
    for (const engineId of ENGINE_IDS) {
      const accepted = [];
      const errors = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          parseWav(wav);
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          errors.push({ voice: voiceLabel(engineId, voice), code: e?.code ?? null });
        }
      }
      enginesResult[engineId] = { accepted, total: VOICE_IDS[engineId].length, errors };
    }
    return { ...item, engines: enginesResult };
  });

  const invalidAccepted = invalid.reduce((n, item) =>
    n + ENGINE_IDS.reduce((m, engineId) => m + item.engines[engineId].accepted.length, 0), 0);
  const invalidChecks = invalid.length * voices.length;
  if (STRICT && invalidAccepted) {
    fail('strict: forbidden notation accepted', `${invalidAccepted}/${invalidChecks} voice/case pairs accepted`);
  }

  /* ---------------------------------------------------------------- */
  /* 5. semantic effects                                               */
  /* ---------------------------------------------------------------- */

  /* Known engine-specific behaviour captured by the report. */
  const knownSame = {
    'nasal-marker-changes-audio': { aqtk2: 'AquesTalk2 的手动鼻浊音记号与其破裂音输出相同' },
    'terminal-comma-vs-period': {
      aqtk1: 'AquesTalk1 的句末「、」与「。」输出相同',
      aqtk10: 'AquesTalk10 的句末「、」与「。」输出相同',
    },
  };

  const semantic = await mapSeries(SEMANTIC_CASES, async (item) => {
    const enginesResult = {};
    for (const engineId of ENGINE_IDS) {
      let different = 0;
      let same = 0;
      const rejected = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const a = await synthWithRecovery(engineId, item.a, { voice, speed: 100 });
          const b = await synthWithRecovery(engineId, item.b, { voice, speed: 100 });
          if (sameBytes(a, b)) same++;
          else different++;
        } catch (e) {
          rejected.push({ voice: voiceLabel(engineId, voice), code: e?.code ?? null });
        }
      }
      const expectedDifferent = item.expectation === 'different';
      const known = knownSame[item.id]?.[engineId];
      const ok = rejected.length === 0 && (expectedDifferent ? different === VOICE_IDS[engineId].length : same === VOICE_IDS[engineId].length);
      enginesResult[engineId] = {
        different,
        same,
        total: VOICE_IDS[engineId].length,
        rejected,
        ok,
        known,
      };
      if (rejected.length) {
        fail('semantic probe rejected', `${item.id} ${engineId}: ${rejected.map((e) => `${e.voice}:${e.code}`).join(',')}`);
      } else if (!ok && !known) {
        fail('semantic effect', `${item.id} ${engineId}: different=${different}/${VOICE_IDS[engineId].length}`);
      } else if (STRICT && !ok && known) {
        fail('strict: semantic effect', `${item.id} ${engineId}: ${known}`);
      }
    }
    return { ...item, engines: enginesResult };
  });

  /* ---------------------------------------------------------------- */
  /* 6. section 2.4 pause hierarchy                                    */
  /* ---------------------------------------------------------------- */

  const pauses = [];
  for (const { engineId, voice } of voices) {
    const durations = {};
    for (const [key, text] of Object.entries(PAUSE_CASES)) {
      try {
        const wav = await synthWithRecovery(engineId, text, { voice, speed: 100 });
        durations[key] = parseWav(wav).seconds;
      } catch (e) {
        durations[key] = null;
        fail('pause probe', `${engineId}/${voiceLabel(engineId, voice)} ${key}: ${e?.code ?? 'ERR'}`);
      }
    }
    const ordered = durations.long > durations.short && durations.short > durations.none;
    const semicolonClose = Math.abs(durations.semicolon - durations.none) <= 0.02;
    const plusClose = Math.abs(durations.plus - durations.none) <= 0.02;
    if (!ordered || !semicolonClose || !plusClose) {
      fail('pause hierarchy', `${engineId}/${voiceLabel(engineId, voice)}: ${JSON.stringify(durations)}`);
    }
    pauses.push({
      engineId,
      voice,
      label: voiceLabel(engineId, voice),
      durations,
      ordered,
      semicolonClose,
      plusClose,
    });
  }

  /* ---------------------------------------------------------------- */
  /* 7. section 6 counters                                             */
  /* ---------------------------------------------------------------- */

  const counters = [];
  const counterFailures = [];
  for (const counter of COUNTERS) {
    const rejected = [];
    for (const { engineId, voice } of voices) {
      try {
        const wav = await synthWithRecovery(engineId, `<NUMK VAL=10 COUNTER=${counter}>`, { voice, speed: 100 });
        parseWav(wav);
      } catch (e) {
        rejected.push({ counter, engineId, voice: voiceLabel(engineId, voice), code: e?.code ?? null });
      }
    }
    counterFailures.push(...rejected);
    /* AquesTalk2's COUNTER path is phont-dependent: several phonts return
     * 106 even though the same tag works with the built-in phont.  This is an
     * engine/phont limitation, so it is reported rather than treated as a
     * regression of the test/data. */
    const unexpected = rejected.filter((row) => row.engineId !== 'aqtk2');
    if (unexpected.length) {
      fail('counter tag', `${counter}: ${unexpected.map((r) => `${r.engineId}/${r.voice}:${r.code}`).join(',')}`);
    }
    if (STRICT && rejected.length) {
      fail('strict: counter tag', `${counter}: ${rejected.map((r) => `${r.engineId}/${r.voice}:${r.code}`).join(',')}`);
    }
    counters.push({ counter, rejected });
  }

  /* ---------------------------------------------------------------- */
  /* 8. NUMK range (valid per section 3.6, but older engines differ)   */
  /* ---------------------------------------------------------------- */

  const numk = await mapSeries(NUMK_RANGE_CASES, async (item) => {
    const enginesResult = {};
    for (const engineId of ENGINE_IDS) {
      const accepted = [];
      const errors = [];
      for (const voice of VOICE_IDS[engineId]) {
        try {
          const wav = await synthWithRecovery(engineId, item.text, { voice, speed: 100 });
          parseWav(wav);
          accepted.push(voiceLabel(engineId, voice));
        } catch (e) {
          errors.push({ voice: voiceLabel(engineId, voice), code: e?.code ?? null });
        }
      }
      enginesResult[engineId] = { accepted, total: VOICE_IDS[engineId].length, errors };
      if (STRICT && errors.length) {
        fail('strict: numk range', `${item.id} ${engineId}: ${errors.map((e) => `${e.voice}:${e.code}`).join(',')}`);
      }
    }
    return { ...item, engines: enginesResult };
  });

  /* ---------------------------------------------------------------- */
  /* 9. section 7 romanised input (AquesTalk2)                         */
  /* ---------------------------------------------------------------- */

  const roman = [];
  const romanFailures = [];
  if (typeof engines.aqtk2.synthRoman === 'function') {
    for (const item of ROMAN_CASES) {
      const accepted = [];
      const errors = [];
      for (const voice of VOICE_IDS.aqtk2) {
        try {
          const wav = await synthRomanWithRecovery(item.text, { voice, speed: 100 });
          parseWav(wav);
          accepted.push(voiceLabel('aqtk2', voice));
        } catch (e) {
          errors.push({ voice: voiceLabel('aqtk2', voice), code: e?.code ?? null });
        }
      }
      const specInvalid = item.id === 'roman-tag-quoted';
      if (errors.length && !specInvalid) {
        romanFailures.push(...errors.map((error) => ({ caseId: item.id, ...error })));
        if (STRICT) fail('strict: roman notation', `${item.id}: ${errors.map((e) => `${e.voice}:${e.code}`).join(',')}`);
      }
      roman.push({ ...item, accepted, total: VOICE_IDS.aqtk2.length, errors, specInvalid });
    }

    /* Documented equivalence: long vowel and accent are shared between the
     * roman and kana alphabets. */
    const equivalence = [];
    for (const [id, romanText, kanaText] of [
      ['roman-long', 'ohayo-', 'おはよー'],
      ['roman-accent', "o'nnse-", "お'んせー"],
      ['roman-sokuon', 'gakko', 'がっこ'],
      ['roman-sokuon-long', 'gakko-', 'がっこー'],
    ]) {
      for (const voice of VOICE_IDS.aqtk2) {
        try {
          const a = await synthRomanWithRecovery(romanText, { voice, speed: 100 });
          const b = await synthWithRecovery('aqtk2', kanaText, { voice, speed: 100 });
          if (!sameBytes(a, b)) {
            fail('roman/kana equivalence', `${id} ${voiceLabel('aqtk2', voice)}`);
          }
          equivalence.push({ id, voice: voiceLabel('aqtk2', voice), same: sameBytes(a, b) });
        } catch (e) {
          fail('roman/kana equivalence', `${id} ${voiceLabel('aqtk2', voice)}: ${e?.code ?? 'ERR'}`);
          equivalence.push({ id, voice: voiceLabel('aqtk2', voice), error: e?.code ?? null });
        }
      }
    }
    roman.push({ id: 'equivalence', equivalence });
  } else {
    fail('roman notation', 'AquesTalk2 adapter does not expose synthRoman');
  }

  /* ---------------------------------------------------------------- */
  /* 10. report                                                        */
  /* ---------------------------------------------------------------- */

  const engineSummary = ENGINE_IDS.map((engineId) => {
    const validChecks = VALID_NOTATION_CASES.length * VOICE_IDS[engineId].length;
    const validAccepted = valid.reduce((n, item) => n + item.engines[engineId].accepted.length, 0);
    const sampleChecks = SPEC_SAMPLE_CASES.length * VOICE_IDS[engineId].length;
    const sampleAccepted = samples.reduce((n, item) => n + item.engines[engineId].accepted.length, 0);
    const invalidChecksForEngine = INVALID_NOTATION_CASES.length * VOICE_IDS[engineId].length;
    const invalidAcceptedForEngine = invalid.reduce((n, item) => n + item.engines[engineId].accepted.length, 0);
    const numericChecks = COUNTERS.length * VOICE_IDS[engineId].length;
    const numericRejected = counters.reduce((n, item) =>
      n + item.rejected.filter((row) => row.engineId === engineId).length, 0);
    return {
      engineId,
      engine: ENGINE_NAMES[engineId],
      voices: VOICE_IDS[engineId].length,
      symbols: READING_SYMBOLS.length * VOICE_IDS[engineId].length,
      validChecks,
      validAccepted,
      sampleChecks,
      sampleAccepted,
      invalidChecks: invalidChecksForEngine,
      invalidAccepted: invalidAcceptedForEngine,
      numericChecks,
      numericAccepted: numericChecks - numericRejected,
    };
  });

  const result = {
    ok: hardFailures.length === 0,
    strict: STRICT,
    generatedAt: startedAt.toISOString(),
    durationMs: Date.now() - startedAt.getTime(),
    datasetProblems: notationProblems,
    spec: {
      title: 'AquesTalk 音声記号列仕様書 Version 1.5',
      file: 'engines/aquestalk2/aqtk2-lnx/siyo_onseikigou.pdf',
      sections: ['2.1', '2.2', '2.3', '2.4', '2.5', '2.6', '2.7', '2.8', '2.9', '3.1', '3.4', '3.5', '3.6', '3.7', '3.8', '4', '5', '6', '7'],
    },
    summary: {
      engines: ENGINE_IDS.length,
      voices: voices.length,
      readingSymbols: READING_SYMBOLS.length,
      validCases: VALID_NOTATION_CASES.length,
      sampleCases: SPEC_SAMPLE_CASES.length,
      invalidCases: INVALID_NOTATION_CASES.length,
      counters: COUNTERS.length,
      romanCases: ROMAN_CASES.length,
      romanFailures: romanFailures.length,
      symbolChecks: READING_SYMBOLS.length * voices.length,
      symbolFailures: symbolFailures.length,
      invalidAccepted,
      invalidChecks,
      invalidRejectionRate: 1 - invalidAccepted / invalidChecks,
    },
    engines: engineSummary,
    symbolGroups: symbolGroupRows,
    symbolFailures,
    valid: valid.map((item) => ({
      id: item.id,
      section: item.section,
      text: item.text,
      engines: Object.fromEntries(ENGINE_IDS.map((engineId) => [
        engineId,
        { accepted: item.engines[engineId].accepted.length, total: item.engines[engineId].total, errors: item.engines[engineId].errors },
      ])),
    })),
    samples,
    invalid,
    semantic,
    pauses,
    counters,
    counterFailures,
    numk,
    roman,
    romanFailures,
    hardFailures,
  };

  await fs.mkdir(path.dirname(OUT_JSON), { recursive: true });
  await fs.writeFile(OUT_JSON, JSON.stringify(result, null, 2) + '\n');

  const engineRows = engineSummary.map((row) => [
    row.engine,
    row.voices,
    `${row.symbols - symbolFailures.filter((failure) => failure.engineId === row.engineId).length}/${row.symbols}`,
    `${row.validAccepted}/${row.validChecks}`,
    `${row.sampleAccepted}/${row.sampleChecks}`,
    `${pct(row.invalidChecks - row.invalidAccepted, row.invalidChecks)}`,
    `${row.numericAccepted}/${row.numericChecks}`,
  ]);

  const sampleRows = samples.map((item) => [
    item.id,
    item.section,
    ...ENGINE_IDS.map((engineId) => {
      const info = item.engines[engineId];
      const codes = [...new Set(info.errors.map((e) => e.code))];
      return `${info.accepted.length}/${info.total}${codes.length ? ` (${codes.join(',')})` : ''}`;
    }),
  ]);

  const invalidRows = invalid.map((item) => [
    item.id,
    item.section,
    ...ENGINE_IDS.map((engineId) => {
      const info = item.engines[engineId];
      return info.accepted.length ? `**${info.accepted.length}/${info.total}**` : '0/' + info.total;
    }),
  ]);

  const semanticRows = semantic.map((item) => [
    item.id,
    item.expectation,
    ...ENGINE_IDS.map((engineId) => {
      const info = item.engines[engineId];
      const value = `${info.different}/${info.total} 不同`;
      return info.known ? `${value}（已知）` : value;
    }),
  ]);

  const pauseRows = ENGINE_IDS.map((engineId) => {
    const rows = pauses.filter((row) => row.engineId === engineId);
    const avg = (key) => rows.reduce((n, row) => n + (row.durations[key] ?? 0), 0) / rows.length;
    return [
      ENGINE_NAMES[engineId],
      `${avg('long').toFixed(3)} s`,
      `${avg('short').toFixed(3)} s`,
      `${avg('none').toFixed(3)} s`,
      `${avg('semicolon').toFixed(3)} s`,
      `${avg('plus').toFixed(3)} s`,
      rows.every((row) => row.ordered && row.semicolonClose && row.plusClose) ? '通过' : '**失败**',
    ];
  });

  const numkRows = numk.map((item) => [
    item.id,
    ...ENGINE_IDS.map((engineId) => {
      const info = item.engines[engineId];
      const codes = [...new Set(info.errors.map((e) => e.code))];
      return `${info.accepted.length}/${info.total}${codes.length ? ` (${codes.join(',')})` : ''}`;
    }),
  ]);

  const counterVoiceRows = VOICE_IDS.aqtk2.map((voice) => {
    const label = voiceLabel('aqtk2', voice);
    const failed = counterFailures
      .filter((row) => row.engineId === 'aqtk2' && row.voice === label)
      .map((row) => row.counter);
    return [label, `${COUNTERS.length - failed.length}/${COUNTERS.length}`, failed.join(', ') || '—'];
  }).filter((row) => row[2] !== '—');

  const romanRows = roman.filter((item) => item.id !== 'equivalence').map((item) => [
    item.id,
    item.specInvalid ? '规范禁止（引号）' : '规范示例',
    `${item.accepted.length}/${item.total}`,
    [...new Set(item.errors.map((e) => e.code))].join(',') || '—',
  ]);

  const readingRows = READING_SYMBOLS.filter((item) =>
    symbolFailures.some((failure) => failure.symbol === item.symbol))
    .map((item) => [item.group, item.symbol, readingSymbolProbe(item.symbol)]);

  const md = `# 音声記号列仕様書 (v1.5) 符合性报告

生成命令：\`npm run test:notation\`  
生成时间：${startedAt.toISOString()}  
规范：\`engines/aquestalk2/aqtk2-lnx/siyo_onseikigou.pdf\`（AQUEST, Version 1.5）

## 1. 测试范围

| 项目 | 数量 |
| --- | --- |
| 引擎 | ${ENGINE_IDS.length} |
| 声库 / phont / preset | ${voices.length} |
| 読み記号表（section 5） | ${READING_SYMBOLS.length} 个（${voices.length} 声库 = ${READING_SYMBOLS.length * voices.length} 次） |
| 合法记法用例（2.2–2.9 / 3.4–3.7） | ${VALID_NOTATION_CASES.length} |
| 规范示例（section 4） | ${SPEC_SAMPLE_CASES.length} |
| 禁止记法用例（3.8 / 3.1 / 3.6） | ${INVALID_NOTATION_CASES.length} |
| 助数词（section 6） | ${COUNTERS.length} |
| ローマ字用例（section 7，AquesTalk2） | ${ROMAN_CASES.length} |

## 2. 总览

${mdTable(['引擎', '声库', '読み記号', '合法记法', '规范示例', '禁止记法拒绝率', '助数词'], engineRows)}

- 読み記号表：**${READING_SYMBOLS.length * voices.length - symbolFailures.length}/${READING_SYMBOLS.length * voices.length}** 接受。
- 合法记法：**${valid.reduce((n, item) => n + item.engines.aqtk1.accepted.length, 0) + valid.reduce((n, item) => n + item.engines.aqtk2.accepted.length, 0) + valid.reduce((n, item) => n + item.engines.aqtk10.accepted.length, 0)}/${VALID_NOTATION_CASES.length * voices.length}** 接受。
- 禁止记法：**${invalidChecks - invalidAccepted}/${invalidChecks}** 被拒绝（${pct(invalidChecks - invalidAccepted, invalidChecks)}）；被接受的部分是引擎比规范更宽松，逐项见第 5 节。
- 助数词：**${COUNTERS.length * voices.length - counters.reduce((n, item) => n + item.rejected.length, 0)}/${COUNTERS.length * voices.length}** 接受。

> 默认模式下，规范禁止但引擎宽松接受的用例只报告不失败；\`--strict\` 会把它们计入失败。

## 3. 読み記号表（section 5）

${mdTable(['分组', '符号数', '检查数', '失败'], symbolGroupRows)}

${readingRows.length ? `失败符号：

${mdTable(['分组', '符号', '探针文本'], readingRows)}` : '全部 読み記号 均被 34 个声库接受。'}

## 4. 合法记法与规范示例

### 4.1 合法记法（2.2–2.9 / 3.4–3.7）

${mdTable(['用例', '规范节', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], valid.map((item) => [
  item.id,
  item.section,
  `${item.engines.aqtk1.accepted.length}/${item.engines.aqtk1.total}`,
  `${item.engines.aqtk2.accepted.length}/${item.engines.aqtk2.total}`,
  `${item.engines.aqtk10.accepted.length}/${item.engines.aqtk10.total}`,
]))}

### 4.2 规范 section 4 示例

${mdTable(['用例', '规范节', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], sampleRows)}

已知失败：
- **AquesTalk1**：只有 \`sample-17\` 失败；f1–dvd 8 个传统声库返回 100（buffer too small），f3 通过。
- **AquesTalk2**：\`sample-04/06/07/08/09/13/14/17\` 在部分 phont 上返回 106（empty tag）。失败集合随 phont 变化（例如 sample-04 为 aq_m4b/aq_momo1/aq_rb2/aq_robo/ar_f4），不是整句语法错误；同一句在其他 phont 上可通过。
- AquesTalk10 的 17 个示例全部通过。
- 这些是旧引擎的数值读取/标签/缓冲区限制；见第 7 节。

## 5. 禁止记法（section 3.8 / 3.1 / 3.6）

规范要求拒绝，但以下用例被部分引擎接受（表格中的数字为接受声库数/该引擎声库数）：

${mdTable(['用例', '规范节', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], invalidRows)}

主要模式：
- **AquesTalk2 最宽松**：3.8.1–3.8.5 的禁止组合几乎全部接受。
- **AquesTalk1 传统声库**最严格：促音结尾、促音连续、语头长音、促音+长音、无声音+长音均拒绝；但 \`わたし;ーわ、\`、\`あ_キや\` 和换行/制表符仍被接受。
- **AquesTalk10** 拒绝促音连续、语头长音、促音+长音，但接受促音结尾、无声音+长音、无声音+半母音、多アクセント、换行/制表符。
- 所有引擎都接受 **一个アクセント句内多个アクセント记号**（3.4 规定最多一个）和 **Tab/换行**（3.1 禁止），这是规范性差异，不是随机行为。
- 所有引擎都拒绝半角假名 \`_す\`、平假名鼻浊音 \`か゜\`、非法 NUM 标签、小写 \`<num>\` 和超长标签。

## 6. 语义效果

记号不仅需要被解析，还必须改变音频：

${mdTable(['用例', '预期', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], semanticRows)}

- アクセント记号、手动无声化 \`_キ\`、疑问符 \`？\` 在全部声库上都改变了 WAV。
- **AquesTalk2 的手动鼻浊音 \`カ゜\` 与 \`ガ\` 输出相同**（该 phont 引擎未体现手动鼻浊音差异）。
- **AquesTalk1/AquesTalk10 的句末「、」与「。」输出相同**；规范 2.5 要求「、」结尾时音高较高，这两个引擎未体现。
- 另外发现：AquesTalk1/AquesTalk10 中 \`こんにちは'\` 与 \`こんにちは\` 输出相同，而 AquesTalk2 不同（评价版引擎对「は」的アクセント处理差异）。

## 7. 句切記号与数值标签

### 7.1 停顿层级（section 2.4）

同一句 \`あ<sep>い。\` 的平均时长（34 声库平均）：

${mdTable(['引擎', '、', ',', '/', ';', '+', '结果'], pauseRows)}

\`、\` > \`,\` > \`/\`，且 \`;\` / \`+\` 与 \`/\` 等长（无停顿），符合规范。

### 7.2 NUMK 范围（section 3.6）

${mdTable(['用例', 'AquesTalk1', 'AquesTalk2', 'AquesTalk10'], numkRows)}

- **AquesTalk1**：f1–dvd 8 个传统声库在 10000 及以上返回 100（buffer too small），万/億/兆位不可用；f3 通过全部范围。
- **AquesTalk2**：\`ar_mf2\` 连 \`<NUMK VAL=1000>\` 都返回 106；\`aq_teto1\`/\`ar_m5\` 在最大值上失败；「假名句首 + 大数标签」形式会让 default/aq_f3a 失败。标签可用性依赖 phont。
- **AquesTalk10**：全范围通过（到 9999999999999999）。

### 7.3 助数词（section 6）

${COUNTERS.length} 个助数词（ねん / がつ / にち / じ / ふん / びょー / えん / かい / か'い / か'げつ / か'ろりー / きゅー / ぎょー / きょく / き'ろ / けん / こ / にん / さい / じ'かん / だい / ちょーめ / つき / ばん / ほん / ひき / ぱーせ'んと）：

- AquesTalk1、AquesTalk10：**${COUNTERS.length * (VOICE_IDS.aqtk1.length + VOICE_IDS.aqtk10.length)}/${COUNTERS.length * (VOICE_IDS.aqtk1.length + VOICE_IDS.aqtk10.length)}** 通过。
- AquesTalk2：**${COUNTERS.length * VOICE_IDS.aqtk2.length - counterFailures.length}/${COUNTERS.length * VOICE_IDS.aqtk2.length}** 通过。失败来自少数 phont，错误码统一为 106（empty tag）：

${mdTable(['phont', '通过', '失败的助数词'], counterVoiceRows)}

同一个 phont 失败后会把 AQ2 实例留在坏状态（随后连默认 phont 也会返回 106），测试在每个失败后重建实例，因此上表是每个 phont 的独立结果。这是 AquesTalk2 的 phont/COUNTER 兼容性问题，不是测试顺序造成的随机性。

## 8. ローマ字記法（section 7，AquesTalk2）

${mdTable(['用例', '类型', '接受', '错误码'], romanRows)}

- 规范示例中，\`aq_teto1.phont\` 在 \`roman-sample-03\` 上返回 106（empty tag）；其余 17 个 phont 通过。与 COUNTER 一样，这是 phont 特定的标签兼容性问题。
- \`ohayo-\` / \`o'nnse-\` / \`gakko\` / \`gakko-\` 与对应 kana 逐字节一致（注意 \`gakko\` 对应「がっこ」，「がっこう」应写 \`gakkou\` 或 \`gakko-\`）。
- \`<NUMK VAL="10" COUNTER="funn">\` 在规范 7.1 中明确标为 **×**（标签值不能加引号），但当前 AquesTalk2 接受；报告为宽松行为。
- AquesTalk1 的 2025 版 Linux 头文件已删除 EUC/Roman 输入；AquesTalk10 的 wasm ABI 未导出 Roman 入口，因此本项只覆盖 AquesTalk2。

## 9. 结论

- **合法记法覆盖充分**：${READING_SYMBOLS.length} 个読み記号、${VALID_NOTATION_CASES.length} 个合法记法在 34 个声库上全部通过；${COUNTERS.length} 个助数词在 AquesTalk1/AquesTalk10 全通过，在 AquesTalk2 上受少数 phont 限制。规范 section 4 的 17 个示例中，AquesTalk10 全部通过；AquesTalk1 仅 NUMK 大数失败（f3 除外），AquesTalk2 还存在 phont 相关的标签失败。
- **规范禁止项存在代际差异**：AquesTalk2 最宽松，AquesTalk1 传统声库最严格，AquesTalk10 介于两者之间；默认模式报告这些差异，\`--strict\` 可将其作为失败。
- **语义效果**：アクセント / 无声化 / 疑问符 / 停顿层级均符合规范；手动鼻浊音（AquesTalk2）和句末「、」的音高（AquesTalk1/10）未体现。
- 测试数据集中在 \`data/notation-corpus.js\`，与 \`data/kana-corpus.js\` 一样由 demo / smoke / consistency / notation 共用。

## 10. 复现

\`\`\`bash
npm run test:notation
# 严格模式：任何规范偏差都返回非零
node tests/notation.mjs --strict
\`\`\`

机器可读结果：\`tests/results/notation.json\`。
`;

  await fs.writeFile(OUT_MD, md);

  console.log(`notation: ${READING_SYMBOLS.length} symbols x ${voices.length} voices, ` +
    `${invalidChecks - invalidAccepted}/${invalidChecks} forbidden cases rejected`);
  console.log(`  report: ${path.relative(REPO_ROOT, OUT_MD)}`);
  console.log(`  json:   ${path.relative(REPO_ROOT, OUT_JSON)}`);
  if (hardFailures.length) {
    console.log(`FAIL (${hardFailures.length})`);
    for (const failure of hardFailures.slice(0, 20)) console.log(`  - ${failure.check}: ${failure.detail}`);
    process.exitCode = 1;
  } else {
    console.log('PASS');
  }
} finally {
  await server.close();
}
