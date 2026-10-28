/* Unified browser demo for AquesTalk1 / AquesTalk2 / AquesTalk10 / AqKanji2Koe.
 *
 * The UI is based on the AquesTalk2 demo (voice picker, speed, waveform,
 * WAV download) and adds an engine switcher plus the AqKanji2Koe text
 * front-end.  Engine-specific details live in engines.js.
 */

import {
  ENGINES,
  getEngineInfo,
  loadEngine,
  loadKanji2Koe,
  EngineError,
  AQTK10_VOICES,
} from './engines.js';

const $ = (id) => document.getElementById(id);

const textEl = $('text');
const voiceEl = $('voice');
const speedEl = $('speed');
const speedOut = $('speedOut');
const synthBtn = $('synth');
const stopBtn = $('stop');
const dlBtn = $('download');
const statusEl = $('status');
const audio = $('audio');
const wave = $('wave');
const metaSize = $('metaSize');
const metaTime = $('metaTime');
const metaVoice = $('metaVoice');
const k2kPre = $('k2kPre');
const k2kChip = $('k2kState');
const kanaBox = $('kanaBox');
const kanaPreview = $('kanaPreview');
const k2kPanel = $('k2kPanel');
const k2kOut = $('k2kOut');
const k2kConvert = $('k2kConvert');
const k2kRoman = $('k2kRoman');
const k2kPlay = $('k2kPlay');
const k2kCopy = $('k2kCopy');

const tabs = [...document.querySelectorAll('.tab')];
const ADV_KEYS = ['vol', 'pit', 'acc', 'lmd', 'fsc'];

const state = {
  engineId: 'aqtk2',
  text: 'こんにちは、せかい。',
  voice: { aqtk1: 'f1', aqtk2: '', aqtk10: 'F1' },
  speed: { aqtk1: 100, aqtk2: 100, aqtk10: 100 },
  params: { bas: 0, vol: 100, pit: 100, acc: 100, lmd: 100, fsc: 100 },
  k2kPre: false,
  k2k: null,
  k2kLoading: null,
  k2kError: null,
  lastWav: null,
  lastUrl: null,
  lastKana: '',
  k2kShown: '',
  k2kShownKind: '',
  lastLabel: '',
  busy: false,
};

/* ------------------------------------------------------------------ */
/* status helpers                                                      */
/* ------------------------------------------------------------------ */

function setStatus(msg, kind = '') {
  statusEl.textContent = msg;
  statusEl.className = 'status' + (kind ? ' ' + kind : '');
}

function formatError(e) {
  if (e instanceof EngineError) return e.message;
  return e?.message ? e.message : String(e);
}

/* ------------------------------------------------------------------ */
/* WAV helpers                                                         */
/* ------------------------------------------------------------------ */

function parseWav(bytes) {
  if (!(bytes instanceof Uint8Array) || bytes.length < 44) return null;
  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  if (dv.getUint32(0, false) !== 0x52494646) return null; // 'RIFF'
  let off = 12;
  let fmt = null;
  let data = null;
  while (off + 8 <= bytes.length) {
    const id = dv.getUint32(off, false);
    const size = dv.getUint32(off + 4, true);
    const body = off + 8;
    if (id === 0x666d7420) { // 'fmt '
      if (body + 16 > bytes.length) return null;
      fmt = {
        format: dv.getUint16(body, true),
        channels: dv.getUint16(body + 2, true),
        rate: dv.getUint32(body + 4, true),
        bits: dv.getUint16(body + 14, true),
      };
    } else if (id === 0x64617461) { // 'data'
      data = { offset: body, size: Math.min(size, bytes.length - body) };
      break;
    }
    off = body + size + (size & 1);
  }
  if (!fmt || !data) return null;
  return { fmt, data };
}

function drawWave(bytes) {
  const ctx = wave.getContext('2d');
  const w = wave.width;
  const h = wave.height;
  const dpr = 1;
  const mid = h / 2;
  const pad = 12;

  ctx.clearRect(0, 0, w, h);
  ctx.fillStyle = '#0b0f16';
  ctx.fillRect(0, 0, w, h);

  // faint grid
  ctx.strokeStyle = '#172033';
  ctx.lineWidth = 1 * dpr;
  ctx.beginPath();
  for (let i = 1; i < 8; i++) {
    const x = Math.round((w * i) / 8) + 0.5;
    ctx.moveTo(x, 0);
    ctx.lineTo(x, h);
  }
  ctx.stroke();
  ctx.strokeStyle = '#243149';
  ctx.beginPath();
  ctx.moveTo(0, mid + 0.5);
  ctx.lineTo(w, mid + 0.5);
  ctx.stroke();

  const info = parseWav(bytes);
  if (!info) {
    ctx.fillStyle = '#56657f';
    ctx.font = '13px ui-sans-serif, system-ui, sans-serif';
    ctx.fillText('no waveform', 14, mid + 5);
    return;
  }

  const { fmt, data } = info;
  const bytesPerSample = Math.max(1, Math.floor(fmt.bits / 8));
  const total = Math.floor(data.size / bytesPerSample);
  if (!total) return;

  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  const sample = (offset) => {
    if (fmt.bits === 16) return dv.getInt16(offset, true) / 32768;
    if (fmt.bits === 8) return (dv.getUint8(offset) - 128) / 128;
    if (fmt.bits === 24) {
      const v = dv.getUint8(offset) | (dv.getUint8(offset + 1) << 8) |
                (dv.getInt8(offset + 2) << 16);
      return v / 8388608;
    }
    if (fmt.bits === 32) return dv.getInt32(offset, true) / 2147483648;
    return 0;
  };

  const tops = new Float32Array(w);
  const bots = new Float32Array(w);
  const perCol = total / w;
  const scale = (h / 2 - pad);

  for (let x = 0; x < w; x++) {
    const start = Math.floor(x * perCol);
    const end = Math.max(start + 1, Math.min(total, Math.ceil((x + 1) * perCol)));
    let lo = 0;
    let hi = 0;
    for (let i = start; i < end; i++) {
      const v = sample(data.offset + i * bytesPerSample);
      if (v < lo) lo = v;
      if (v > hi) hi = v;
    }
    tops[x] = mid - hi * scale;
    bots[x] = mid - lo * scale;
  }

  const grad = ctx.createLinearGradient(0, 0, 0, h);
  grad.addColorStop(0, 'rgba(157, 123, 255, 0.75)');
  grad.addColorStop(0.5, 'rgba(110, 168, 255, 0.55)');
  grad.addColorStop(1, 'rgba(110, 168, 255, 0.25)');

  ctx.beginPath();
  ctx.moveTo(0, tops[0]);
  for (let x = 1; x < w; x++) ctx.lineTo(x, tops[x]);
  for (let x = w - 1; x >= 0; x--) ctx.lineTo(x, bots[x]);
  ctx.closePath();
  ctx.fillStyle = 'rgba(110, 168, 255, 0.10)';
  ctx.fill();

  ctx.strokeStyle = grad;
  ctx.lineWidth = 1.2;
  ctx.beginPath();
  for (let x = 0; x < w; x++) {
    if (x === 0) ctx.moveTo(x, tops[x]);
    else ctx.lineTo(x, tops[x]);
  }
  ctx.stroke();
  ctx.beginPath();
  for (let x = 0; x < w; x++) {
    if (x === 0) ctx.moveTo(x, bots[x]);
    else ctx.lineTo(x, bots[x]);
  }
  ctx.stroke();

  // duration labels
  const seconds = total / fmt.rate;
  ctx.fillStyle = '#4a5a78';
  ctx.font = '11px ui-monospace, Menlo, monospace';
  ctx.fillText('0.0 s', 10, h - 10);
  const label = `${seconds.toFixed(2)} s · ${(fmt.rate / 1000).toFixed(1)} kHz`;
  const tw = ctx.measureText(label).width;
  ctx.fillText(label, w - tw - 10, h - 10);
}

/* ------------------------------------------------------------------ */
/* playback                                                            */
/* ------------------------------------------------------------------ */

function stopPlayback() {
  audio.onended = null;
  audio.onerror = null;
  audio.pause();
  audio.removeAttribute('src');
  audio.load();
  if (state.lastUrl) {
    URL.revokeObjectURL(state.lastUrl);
    state.lastUrl = null;
  }
  stopBtn.disabled = true;
}

async function playWav(wav, label, ms) {
  const info = parseWav(wav);
  if (!info) throw new Error('生成された WAV を解析できません');

  state.lastWav = wav;
  state.lastLabel = label;

  const seconds = info.data.size / (info.fmt.rate * info.fmt.channels * (info.fmt.bits / 8));
  metaSize.textContent = `${wav.length.toLocaleString()} bytes · ${(wav.length / 1024).toFixed(1)} KiB`;
  metaTime.textContent = `${seconds.toFixed(2)} s · ${(info.fmt.rate / 1000).toFixed(1)} kHz · ${ms.toFixed(1)} ms`;
  metaVoice.textContent = label;
  dlBtn.disabled = false;

  drawWave(wav);
  stopPlayback();

  const blob = new Blob([wav], { type: 'audio/wav' });
  state.lastUrl = URL.createObjectURL(blob);
  audio.src = state.lastUrl;
  stopBtn.disabled = false;
  audio.onended = () => {
    stopBtn.disabled = true;
    setStatus('完了', 'ok');
  };
  audio.onerror = () => setStatus('音声の再生に失敗しました', 'err');

  try {
    await audio.play();
    setStatus('再生中…', 'ok');
  } catch (e) {
    setStatus('再生できませんでした: ' + e.message, 'err');
  }
}

function downloadWav() {
  if (!state.lastWav) return;
  const blob = new Blob([state.lastWav], { type: 'audio/wav' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  const d = new Date();
  const stamp = d.toISOString().replace(/[-:T]/g, '').slice(0, 14);
  const safe = state.lastLabel.replace(/[^\w.-]+/g, '_').replace(/^_+|_+$/g, '');
  a.href = url;
  a.download = `aquestalk_${state.engineId}_${safe || 'wav'}_${stamp}.wav`;
  a.click();
  setTimeout(() => URL.revokeObjectURL(url), 1000);
}

/* ------------------------------------------------------------------ */
/* AqKanji2Koe                                                         */
/* ------------------------------------------------------------------ */

function updateK2kChip() {
  if (state.k2k) {
    k2kChip.className = 'chip ok';
    k2kChip.textContent = '辞書読込済';
    k2kChip.title = 'AqKanji2Koe の辞書は読み込み済みです';
  } else if (state.k2kLoading) {
    k2kChip.className = 'chip busy';
    k2kChip.textContent = '読込中…';
    k2kChip.title = '辞書（約 15 MB）を読み込み中です';
  } else if (state.k2kError) {
    k2kChip.className = 'chip err';
    k2kChip.textContent = '辞書なし';
    k2kChip.title = formatError(state.k2kError);
  } else {
    k2kChip.className = 'chip';
    k2kChip.textContent = '未読込';
    k2kChip.title = 'チェックすると辞書を読み込みます';
  }
}

function ensureK2k() {
  if (state.k2k) return Promise.resolve(state.k2k);
  if (state.k2kLoading) return state.k2kLoading;

  state.k2kError = null;
  setStatus('AqKanji2Koe の辞書（約 15 MB）を読み込み中…', 'busy');
  state.k2kLoading = loadKanji2Koe().then(
    (k2k) => {
      state.k2k = k2k;
      state.k2kLoading = null;
      updateK2kChip();
      setStatus('AqKanji2Koe 準備完了', 'ok');
      return k2k;
    },
    (e) => {
      state.k2kError = e;
      state.k2kLoading = null;
      updateK2kChip();
      setStatus(formatError(e), 'err');
      throw e;
    },
  );
  updateK2kChip();
  return state.k2kLoading;
}

async function convertCurrent(roman = false) {
  const text = textEl.value.trim();
  if (!text) {
    setStatus('テキストを入力してください。', 'err');
    return;
  }
  if (state.busy) return;

  state.busy = true;
  setBusy(true);
  try {
    const k2k = await ensureK2k();
    setStatus(roman ? 'ローマ字に変換中…' : 'かなに変換中…', 'busy');
    const t0 = performance.now();
    const out = roman ? await k2k.convertRoman(text) : await k2k.convert(text);
    const ms = performance.now() - t0;

    state.k2kShown = out;
    state.k2kShownKind = roman ? 'roman' : 'kana';
    k2kOut.textContent = out || '（空）';
    k2kCopy.disabled = !out;
    if (!roman) state.lastKana = out;
    k2kPlay.disabled = roman || !state.lastKana;
    if (roman && out) {
      setStatus(`変換完了 — ${out.length} 文字, ${ms.toFixed(1)} ms（ローマ字は AquesTalk2 では再生できません）`, 'ok');
    } else {
      setStatus(`変換完了 — ${out.length} 文字, ${ms.toFixed(1)} ms`, 'ok');
    }
  } catch (e) {
    console.error(e);
    setStatus(formatError(e), 'err');
  } finally {
    state.busy = false;
    setBusy(false);
  }
}

async function playKana() {
  const kana = state.lastKana;
  if (!kana || state.busy) return;

  state.busy = true;
  setBusy(true);
  try {
    const engine = await loadEngine('aqtk2');
    setStatus('AquesTalk2 で合成中…', 'busy');
    const t0 = performance.now();
    const wav = await engine.synth(kana, { voice: '', speed: 100 });
    const ms = performance.now() - t0;
    await playWav(wav, 'AqKanji2Koe → AquesTalk2', ms);
  } catch (e) {
    console.error(e);
    setStatus(formatError(e), 'err');
  } finally {
    state.busy = false;
    setBusy(false);
  }
}

/* ------------------------------------------------------------------ */
/* synthesis                                                           */
/* ------------------------------------------------------------------ */

async function synthesize() {
  const info = getEngineInfo(state.engineId);
  if (info.kind !== 'tts' || state.busy) return;

  const text = textEl.value.trim();
  if (!text) {
    setStatus('音声記号列を入力してください。', 'err');
    return;
  }

  state.busy = true;
  setBusy(true);
  try {
    let koe = text;
    if (state.k2kPre) {
      const k2k = await ensureK2k();
      setStatus('AqKanji2Koe で変換中…', 'busy');
      koe = await k2k.convert(text);
      state.lastKana = koe;
      state.k2kShown = koe;
      state.k2kShownKind = 'kana';
      kanaPreview.textContent = koe || '（空）';
      kanaBox.hidden = false;
      if (!koe) throw new Error('AqKanji2Koe の変換結果が空です');
    }

    const engine = await loadEngine(state.engineId);
    const speed = Number(speedEl.value);
    const voice = voiceEl.value;
    const params = info.advanced ? { ...state.params } : undefined;

    setStatus('合成中…', 'busy');
    const t0 = performance.now();
    const wav = await engine.synth(koe, { voice, speed, params });
    const ms = performance.now() - t0;

    const voiceLabel = voiceEl.selectedOptions[0]?.textContent || voice;
    await playWav(wav, `${info.name} / ${voiceLabel}`, ms);
  } catch (e) {
    console.error(e);
    setStatus(formatError(e), 'err');
  } finally {
    state.busy = false;
    setBusy(false);
  }
}

function setBusy(busy) {
  synthBtn.disabled = busy;
  k2kConvert.disabled = busy;
  k2kRoman.disabled = busy;
  k2kPlay.disabled = busy || state.k2kShownKind !== 'kana' || !state.lastKana;
}

/* ------------------------------------------------------------------ */
/* UI wiring                                                           */
/* ------------------------------------------------------------------ */

function renderSamples(info) {
  const box = $('samples');
  box.replaceChildren();
  for (const s of info.samples) {
    const b = document.createElement('button');
    b.type = 'button';
    b.textContent = s;
    b.addEventListener('click', () => {
      textEl.value = s;
      if (info.kind === 'converter') convertCurrent(false);
      else synthesize();
    });
    box.appendChild(b);
  }
}

function renderVoices(info) {
  voiceEl.replaceChildren();
  for (const v of info.voices) {
    const opt = document.createElement('option');
    opt.value = v.id;
    opt.textContent = v.label;
    voiceEl.appendChild(opt);
  }
  voiceEl.value = state.voice[info.id] ?? info.defaultVoice;
}

function syncAdvanced() {
  $('bas').value = String(state.params.bas);
  for (const k of ADV_KEYS) {
    $(k).value = state.params[k];
    $(`${k}Out`).textContent = state.params[k];
  }
}

function applyAqtk10Preset() {
  const preset = AQTK10_VOICES[voiceEl.value] || AQTK10_VOICES.F1;
  state.params = {
    bas: preset.bas,
    vol: preset.vol,
    pit: preset.pit,
    acc: preset.acc,
    lmd: preset.lmd,
    fsc: preset.fsc,
  };
  state.speed.aqtk10 = preset.spd;
  speedEl.value = String(preset.spd);
  speedOut.textContent = String(preset.spd);
  syncAdvanced();
}

function selectEngine(id, { updateHash = true } = {}) {
  const info = getEngineInfo(id);
  state.engineId = id;

  for (const tab of tabs) {
    const on = tab.dataset.engine === id;
    tab.setAttribute('aria-selected', String(on));
    tab.tabIndex = on ? 0 : -1;
  }
  $('panel').setAttribute('aria-labelledby', `tab-${id}`);

  $('engineTitle').textContent = info.name;
  $('engineDesc').textContent = info.description;
  $('engineBadge').textContent = info.badge;
  $('textLabel').textContent = info.textLabel;
  $('voiceLabel').textContent = info.voiceLabel;

  const isTts = info.kind === 'tts';
  $('ttsControls').hidden = !isTts;
  $('advanced').hidden = !(isTts && info.advanced);
  $('ttsActions').hidden = !isTts;
  $('k2kRow').hidden = !isTts;
  $('k2kPanel').hidden = isTts;

  renderVoices(info);
  renderSamples(info);

  if (isTts) {
    speedEl.value = String(state.speed[id] ?? 100);
    speedOut.textContent = speedEl.value;
    if (info.advanced) syncAdvanced();
    kanaBox.hidden = !(state.k2kPre && state.lastKana);
    setStatus('「合成して再生」を押すと wasm を読み込みます。');
    loadEngine(id).catch(() => {});
  } else {
    kanaBox.hidden = true;
    k2kOut.textContent = state.k2kShown || '（まだ変換していません）';
    k2kCopy.disabled = !state.k2kShown;
    k2kPlay.disabled = state.k2kShownKind !== 'kana' || !state.lastKana;
    setStatus('「かなに変換」を押すと辞書を読み込みます。');
    ensureK2k().catch(() => {});
  }

  updateK2kChip();
  if (updateHash) {
    history.replaceState(null, '', `#${id}`);
  }
}

/* ------------------------------------------------------------------ */
/* events                                                              */
/* ------------------------------------------------------------------ */

for (const tab of tabs) {
  tab.addEventListener('click', () => selectEngine(tab.dataset.engine));
  tab.addEventListener('keydown', (e) => {
    const i = tabs.indexOf(tab);
    let next = null;
    if (e.key === 'ArrowRight') next = tabs[(i + 1) % tabs.length];
    else if (e.key === 'ArrowLeft') next = tabs[(i - 1 + tabs.length) % tabs.length];
    else if (e.key === 'Home') next = tabs[0];
    else if (e.key === 'End') next = tabs[tabs.length - 1];
    if (next) {
      e.preventDefault();
      next.focus();
      selectEngine(next.dataset.engine);
    }
  });
}

textEl.addEventListener('input', () => { state.text = textEl.value; });
textEl.addEventListener('keydown', (e) => {
  if ((e.ctrlKey || e.metaKey) && e.key === 'Enter') {
    e.preventDefault();
    if (getEngineInfo(state.engineId).kind === 'converter') convertCurrent(false);
    else synthesize();
  }
});

voiceEl.addEventListener('change', () => {
  const id = state.engineId;
  state.voice[id] = voiceEl.value;
  if (id === 'aqtk10') applyAqtk10Preset();
});

speedEl.addEventListener('input', () => {
  speedOut.textContent = speedEl.value;
  state.speed[state.engineId] = Number(speedEl.value);
});

for (const key of ADV_KEYS) {
  $(key).addEventListener('input', () => {
    state.params[key] = Number($(key).value);
    $(`${key}Out`).textContent = $(key).value;
  });
}
$('bas').addEventListener('change', () => {
  state.params.bas = Number($('bas').value);
});

k2kPre.addEventListener('change', async () => {
  state.k2kPre = k2kPre.checked;
  if (state.k2kPre) {
    kanaBox.hidden = !state.lastKana;
    try {
      await ensureK2k();
    } catch (_) {
      k2kPre.checked = false;
      state.k2kPre = false;
      kanaBox.hidden = true;
    }
  } else {
    kanaBox.hidden = true;
  }
});

synthBtn.addEventListener('click', synthesize);
stopBtn.addEventListener('click', () => {
  stopPlayback();
  setStatus('停止', '');
});
dlBtn.addEventListener('click', downloadWav);

k2kConvert.addEventListener('click', () => convertCurrent(false));
k2kRoman.addEventListener('click', () => convertCurrent(true));
k2kPlay.addEventListener('click', playKana);
k2kCopy.addEventListener('click', async () => {
  try {
    await navigator.clipboard.writeText(k2kOut.textContent);
    setStatus('クリップボードにコピーしました', 'ok');
  } catch (e) {
    setStatus('コピーできませんでした: ' + e.message, 'err');
  }
});

/* ------------------------------------------------------------------ */
/* boot                                                                */
/* ------------------------------------------------------------------ */

const initial = location.hash.replace(/^#/, '');
selectEngine(ENGINES.some((e) => e.id === initial) ? initial : 'aqtk2', {
  updateHash: false,
});
updateK2kChip();
