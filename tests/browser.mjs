/* Optional browser smoke test (requires Playwright + Chromium).
 *
 *   npm install --no-save playwright
 *   PLAYWRIGHT_BROWSERS_PATH="$PWD/.playwright-browsers" \
 *     ./node_modules/.bin/playwright install chromium
 *   ./scripts/serve.sh &          # or: python3 -m http.server 8765
 *   node tests/browser.mjs http://127.0.0.1:8765/demo/
 */
import { chromium } from 'playwright';
import { mkdir } from 'node:fs/promises';

const url = process.argv[2] || 'http://127.0.0.1:8000/demo/';
const outDir = new URL('../.test-artifacts/', import.meta.url);
await mkdir(outDir, { recursive: true });

const browser = await chromium.launch();
const page = await browser.newPage({ viewport: { width: 1200, height: 1500 } });

const errors = [];
page.on('pageerror', (e) => errors.push(String(e)));
page.on('console', (m) => {
  if (m.type() === 'error') errors.push(m.text());
});

// Headless containers frequently have no audio device; don't make the test
// depend on real playback.
await page.addInitScript(() => {
  HTMLMediaElement.prototype.play = function play() {
    this.dispatchEvent(new Event('playing'));
    return Promise.resolve();
  };
});

async function waitSynth(label) {
  const status = await page.locator('#status').textContent();
  if (/エラー|失敗/.test(status)) throw new Error(`${label}: ${status}`);
  await page.waitForFunction(() => {
    const el = document.getElementById('metaSize');
    return el && el.textContent.trim().length > 0;
  }, { timeout: 30000 });
  const meta = await page.locator('#metaSize').textContent();
  console.log(`${label}: ${status.trim()} | ${meta.trim()}`);
}

await page.goto(url, { waitUntil: 'networkidle' });
await page.waitForTimeout(300);
await page.screenshot({ path: new URL('01-aqtk2.png', outDir).pathname, fullPage: true });

// AquesTalk2 (default)
await page.click('#synth');
await waitSynth('AquesTalk2');

// AquesTalk1
await page.click('[data-engine="aqtk1"]');
await page.click('#synth');
await waitSynth('AquesTalk1');

// AquesTalk10 + a non-default preset & speed
await page.click('[data-engine="aqtk10"]');
await page.selectOption('#voice', 'F3');
await page.fill('#speed', '120');
await page.dispatchEvent('#speed', 'input');
await page.click('#synth');
await waitSynth('AquesTalk10');
await page.screenshot({ path: new URL('02-aqtk10.png', outDir).pathname, fullPage: true });

// AqKanji2Koe
await page.click('[data-engine="k2k"]');
await page.waitForFunction(() =>
  document.getElementById('k2kState').textContent.includes('読込済'), { timeout: 30000 });
await page.click('#k2kConvert');
await page.waitForFunction(() =>
  !document.getElementById('k2kOut').textContent.includes('まだ'), { timeout: 30000 });
const kana = await page.locator('#k2kOut').textContent();
console.log('AqKanji2Koe:', kana.trim());

// Roman output is display-only; the play button must be disabled for it.
await page.click('#k2kRoman');
await page.waitForFunction(() => {
  const t = document.getElementById('k2kOut').textContent.trim();
  return t.length > 0 && /^[\x20-\x7e]+$/.test(t);
}, { timeout: 30000 });
const roman = await page.locator('#k2kOut').textContent();
console.log('AqKanji2Koe roman:', roman.trim());
if (!(await page.locator('#k2kPlay').isDisabled())) {
  throw new Error('k2kPlay should be disabled for roman output');
}
await page.click('#k2kConvert');
await page.waitForFunction(() => /[ぁ-ヿ]/.test(document.getElementById('k2kOut').textContent), { timeout: 30000 });

await page.click('#k2kPlay');
await waitSynth('AqKanji2Koe -> AquesTalk2');
await page.screenshot({ path: new URL('03-k2k.png', outDir).pathname, fullPage: true });

// AquesTalk2 with the kanji preprocessor
await page.click('[data-engine="aqtk2"]');
await page.check('#k2kPre');
await page.fill('#text', '明日の天気は晴れでしょう。');
await page.dispatchEvent('#text', 'input');
await page.click('#synth');
await waitSynth('AquesTalk2 + k2k');
const preview = await page.locator('#kanaPreview').textContent();
console.log('k2k 読み:', preview.trim());
await page.screenshot({ path: new URL('04-pipeline.png', outDir).pathname, fullPage: true });

if (errors.length) {
  console.error('page errors:', errors);
  process.exitCode = 1;
}
await browser.close();
console.log('browser smoke test passed');
