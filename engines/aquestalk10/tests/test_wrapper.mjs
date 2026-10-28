import fs from 'fs';
import crypto from 'crypto';
import { AquesTalk10, VOICES, AquesTalkError } from '../port/web/aqtk10.js';

const at = await AquesTalk10.fromBytes(fs.readFileSync(new URL('../port/web/aqtk10.wasm', import.meta.url)));
const cases = JSON.parse(fs.readFileSync(new URL('./cases.json', import.meta.url), 'utf8'));
const sha = b => crypto.createHash('sha256').update(b).digest('hex');
let ok = 0, bad = 0;
for (const c of cases.slice(0, 20)) {
  for (const [mode, fn] of [
    ['utf8', () => at.synthe(c.text, c.voice)],
    ['sjis', () => at.syntheSjis(Buffer.from(c.sjis, 'base64'), c.voice)],
    ['utf16', () => at.syntheUtf16(c.text, c.voice)],
  ]) {
    const wav = fn();
    if (wav.length !== c.size || sha(wav) !== c.sha256) { console.log('FAIL', c.name, mode); bad++; }
    else ok++;
  }
}
console.log('wrapper corpus sample:', ok, 'ok', bad, 'bad');
try { at.synthe('', VOICES.F1); console.log('empty: NO ERROR'); }
catch (e) { console.log('empty throws', e instanceof AquesTalkError, e.code); }
console.log('devkey invalid =', at.setDevKey('xxx'));
console.log('mem MB', (at.memory.buffer.byteLength / 1048576).toFixed(1));
if (bad) process.exit(1);
