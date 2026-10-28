/*
 * Node verification: wasm output must equal the native engine (which in turn
 * equals libAquesTalk.so for f1..dvd).  Usage:
 *   node recovered/wasm/verify.mjs
 */
import { readFileSync, writeFileSync } from 'node:fs';
import { execFileSync } from 'node:child_process';
import { AquesTalk1 } from './aquestalk1.js';

const cases = [
    ['f1', 'ア'], ['f1', 'アイ'], ['f1', 'アカ'], ['f1', 'アイウエオ'],
    ['f1', 'ガッコウ'], ['f1', 'フュージョン'], ['f1', 'ア、イ、ウ、エ、オ。'],
    ['f2', 'アイ'], ['f2', 'アカ'], ['f2', 'グォ'], ['f2', 'クヮ'],
    ['m1', 'カキクケコ'], ['m2', 'ニッポン'], ['r1', 'シャッ'],
    ['imd1', 'ウィー'], ['jgr', 'アカサタナ。'], ['dvd', 'アカサタナ'],
    ['f3', 'ア'], ['f3', 'カ']
];

const buffer = readFileSync(new URL('../../dist/aquestalk1.wasm', import.meta.url));
const aq = await AquesTalk1.loadFile(buffer);

let ok = 0, bad = 0;
for (const [voice, text] of cases) {
    aq.select(voice);
    const wav = aq.synthe(text, 100);
    const native = `/tmp/native_${voice}.wav`;
    try {
        execFileSync('./build/dump', [`aqtk1_lnx/lib64/${voice}/libAquesTalk.so`, voice, text, native],
                     { stdio: 'ignore' });
    } catch (e) {
        console.log(`${voice} ${text}: native failed`);
        bad++;
        continue;
    }
    const ref = readFileSync(native);
    if (!wav) {
        console.log(`${voice} ${text}: wasm returned null (${aq.lastError}), native ${ref.length} bytes`);
        bad++;
        continue;
    }
    if (Buffer.compare(Buffer.from(wav), ref) === 0) {
        ok++;
    } else {
        bad++;
        console.log(`${voice} ${text}: MISMATCH wasm ${wav.length} native ${ref.length}`);
    }
}
console.log(`wasm vs native: ${ok} identical, ${bad} failed`);
process.exit(bad ? 1 : 0);
