// Minimal Node example: synthesise one phrase and write a WAV file.
//   node port/tools/example.mjs "こんにちは" 100 out.wav
import { createAquesTalk2 } from '../../dist/aquestalk2.js';
import fs from 'node:fs';

const [text = 'こんにちは', speed = '100', out = 'out.wav'] = process.argv.slice(2);
const aq = await createAquesTalk2();
const wav = aq.synthe(text, Number(speed));
if (!wav) {
  console.error('synthesis failed, code', aq.lastError());
  process.exit(1);
}
fs.writeFileSync(out, wav);
console.log(`${out}: ${wav.length} bytes`);
