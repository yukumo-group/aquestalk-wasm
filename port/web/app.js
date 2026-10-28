/* Browser demo for the WebAssembly build.
 *
 * Uses the embind surface:
 *   synthe(text, speed)                  -> Uint8Array | null
 *   syntheWithPhont(text, speed, phont)  -> Uint8Array | null
 *   lastError()                          -> error code of the last call
 */
import createModule from './aquestalk2.js';

const VOICES = [
  ['', '内蔵デフォルト (aq_defo1)'],
  ['aq_defo1.phont', 'デフォルト (phont ファイル)'],
  ['aq_rm.phont', '女声 (aq_rm)'],
  ['aq_f1c.phont', '女声 (aq_f1c)'],
  ['aq_f3a.phont', '女声 (aq_f3a)'],
  ['aq_m4b.phont', '男声 (aq_m4b)'],
  ['aq_mf1.phont', '男声 (aq_mf1)'],
  ['aq_momo1.phont', 'もも (aq_momo1)'],
  ['aq_huskey.phont', 'ハスキー (aq_huskey)'],
  ['aq_rb2.phont', 'ロボット (aq_rb2)'],
  ['aq_rb3.phont', 'ロボット (aq_rb3)'],
  ['aq_robo.phont', 'ロボット (aq_robo)'],
  ['aq_teto1.phont', 'テト (aq_teto1)'],
  ['aq_yukkuri.phont', 'ゆっくり (aq_yukkuri)'],
  ['ar_f4.phont', 'ar_f4'],
  ['ar_m5.phont', 'ar_m5'],
  ['ar_mf2.phont', 'ar_mf2'],
  ['ar_rm3.phont', 'ar_rm3'],
];

const SAMPLES = [
  'こんにちは、せかい。',
  'おはようございます',
  'ありがとう',
  'きょうは いい てんき ですね',
  'すもももももももものうち',
  'えっ？そうなんですか！',
  'おかあさん、おねえさん、おおきいとおい',
  'なにぬねの まみむめも',
];

const $ = (id) => document.getElementById(id);
const textEl = $('text');
const voiceEl = $('voice');
const speedEl = $('speed');
const speedOut = $('speedOut');
const playBtn = $('play');
const stopBtn = $('stop');
const dlBtn = $('download');
const statusEl = $('status');
const audio = $('audio');
const canvas = $('wave');
const metaSize = $('metaSize');
const metaTime = $('metaTime');
const metaVoice = $('metaVoice');

let modulePromise = null;
let lastWav = null;
let lastUrl = null;
const phontCache = new Map();

function setStatus(msg, kind = '') {
  statusEl.textContent = msg;
  statusEl.className = 'status ' + kind;
}

function getModule() {
  if (!modulePromise) {
    setStatus('WebAssembly モジュールを読み込み中…');
    modulePromise = createModule().then((m) => {
      setStatus('準備完了');
      return m;
    }).catch((e) => {
      modulePromise = null;
      throw e;
    });
  }
  return modulePromise;
}

async function loadPhont(name) {
  if (!name) return null;
  if (phontCache.has(name)) return phontCache.get(name);
  setStatus(`声質ファイル ${name} を読み込み中…`);
  const res = await fetch('./phont/' + name);
  if (!res.ok) throw new Error(`phont の取得に失敗: ${res.status}`);
  const bytes = new Uint8Array(await res.arrayBuffer());
  phontCache.set(name, bytes);
  return bytes;
}

/* --- WAV helpers ------------------------------------------------------ */
function parseWav(bytes) {
  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  if (dv.getUint32(0, false) !== 0x52494646) return null; // 'RIFF'
  let off = 12;
  let fmt = null;
  let data = null;
  while (off + 8 <= bytes.length) {
    const id = dv.getUint32(off, false);
    const size = dv.getUint32(off + 4, true);
    if (id === 0x666d7420) { // 'fmt '
      fmt = {
        channels: dv.getUint16(off + 10, true),
        rate: dv.getUint32(off + 12, true),
        bits: dv.getUint16(off + 22, true),
      };
    } else if (id === 0x64617461) { // 'data'
      data = { offset: off + 8, size: Math.min(size, bytes.length - off - 8) };
      break;
    }
    off += 8 + size + (size & 1);
  }
  if (!fmt || !data) return null;
  return { fmt, data };
}

function drawWave(bytes) {
  const ctx = canvas.getContext('2d');
  const w = canvas.width, h = canvas.height;
  ctx.clearRect(0, 0, w, h);
  ctx.fillStyle = '#0b0f16';
  ctx.fillRect(0, 0, w, h);

  const info = parseWav(bytes);
  if (!info) return;
  const { data, fmt } = info;
  const n = data.size / (fmt.bits / 8);
  const step = Math.max(1, Math.floor(n / w));
  const mid = h / 2;

  ctx.strokeStyle = '#1c2740';
  ctx.beginPath();
  ctx.moveTo(0, mid);
  ctx.lineTo(w, mid);
  ctx.stroke();

  const grad = ctx.createLinearGradient(0, 0, 0, h);
  grad.addColorStop(0, '#9d7bff');
  grad.addColorStop(1, '#6ea8ff');
  ctx.strokeStyle = grad;
  ctx.lineWidth = 1.5;
  ctx.beginPath();
  for (let x = 0; x < w; x++) {
    const start = data.offset + x * step * 2;
    let peak = 0;
    for (let i = 0; i < step && start + i * 2 + 1 < bytes.length; i++) {
      const v = (bytes[start + i * 2] | (bytes[start + i * 2 + 1] << 8));
      const s = (v << 16) >> 16;
      peak = Math.max(peak, Math.abs(s) / 32768);
    }
    const y = mid - peak * (h / 2 - 4);
    if (x === 0) ctx.moveTo(0, y);
    else ctx.lineTo(x, y);
  }
  ctx.stroke();

  ctx.strokeStyle = 'rgba(157,123,255,0.35)';
  ctx.beginPath();
  for (let x = 0; x < w; x++) {
    const start = data.offset + x * step * 2;
    let peak = 0;
    for (let i = 0; i < step && start + i * 2 + 1 < bytes.length; i++) {
      const v = (bytes[start + i * 2] | (bytes[start + i * 2 + 1] << 8));
      const s = (v << 16) >> 16;
      peak = Math.max(peak, Math.abs(s) / 32768);
    }
    const y = mid + peak * (h / 2 - 4);
    if (x === 0) ctx.moveTo(0, y);
    else ctx.lineTo(x, y);
  }
  ctx.stroke();
}

function stopPlayback() {
  audio.pause();
  audio.currentTime = 0;
  if (lastUrl) {
    URL.revokeObjectURL(lastUrl);
    lastUrl = null;
  }
  stopBtn.disabled = true;
}

async function synthesizeAndPlay() {
  playBtn.disabled = true;
  try {
    const text = textEl.value.trim();
    if (!text) {
      setStatus('音声記号列を入力してください。', 'err');
      return;
    }
    const speed = Number(speedEl.value);
    const mod = await getModule();
    const phont = await loadPhont(voiceEl.value);

    setStatus('合成中…');
    const t0 = performance.now();
    const wav = phont
      ? mod.syntheWithPhont(text, speed, phont)
      : mod.synthe(text, speed);
    const ms = performance.now() - t0;

    if (!wav) {
      const code = mod.lastError();
      setStatus(`合成エラー: コード ${code}（音声記号列を確認してください）`, 'err');
      lastWav = null;
      dlBtn.disabled = true;
      return;
    }

    lastWav = wav;
    const info = parseWav(wav);
    const seconds = info ? info.data.size / (info.fmt.rate * info.fmt.channels * 2) : 0;
    metaSize.textContent = `${wav.length.toLocaleString()} bytes`;
    metaTime.textContent = `${seconds.toFixed(2)} s · ${ms.toFixed(1)} ms で合成`;
    metaVoice.textContent = VOICES.find((v) => v[0] === voiceEl.value)?.[1] ?? '';

    drawWave(wav);
    dlBtn.disabled = false;
    setStatus('再生中…', 'ok');

    stopPlayback();
    const blob = new Blob([wav], { type: 'audio/wav' });
    lastUrl = URL.createObjectURL(blob);
    audio.src = lastUrl;
    stopBtn.disabled = false;
    audio.onended = () => setStatus('完了', 'ok');
    await audio.play();
  } catch (e) {
    console.error(e);
    setStatus('エラー: ' + (e?.message ?? e), 'err');
  } finally {
    playBtn.disabled = false;
  }
}

function downloadWav() {
  if (!lastWav) return;
  const blob = new Blob([lastWav], { type: 'audio/wav' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  const d = new Date();
  const stamp = d.toISOString().replace(/[-:T]/g, '').slice(0, 14);
  a.href = url;
  a.download = `aquestalk2_${stamp}.wav`;
  a.click();
  setTimeout(() => URL.revokeObjectURL(url), 1000);
}

/* --- wire up ---------------------------------------------------------- */
for (const [value, label] of VOICES) {
  const opt = document.createElement('option');
  opt.value = value;
  opt.textContent = label;
  voiceEl.appendChild(opt);
}

for (const s of SAMPLES) {
  const b = document.createElement('button');
  b.type = 'button';
  b.textContent = s;
  b.addEventListener('click', () => {
    textEl.value = s;
    synthesizeAndPlay();
  });
  $('samples').appendChild(b);
}

speedEl.addEventListener('input', () => { speedOut.textContent = speedEl.value; });
playBtn.addEventListener('click', synthesizeAndPlay);
stopBtn.addEventListener('click', () => { stopPlayback(); setStatus('停止', ''); });
dlBtn.addEventListener('click', downloadWav);
audio.addEventListener('ended', () => { stopBtn.disabled = true; });

// Warm up the module so the first click is instant (best effort).
getModule().catch(() => {});
