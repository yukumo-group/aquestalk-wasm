/* Node driver for the raw WebAssembly build.
 * usage: node wasm_run.mjs <enc> <speed> <in> <out> [phont]
 */
import { createAquesTalk2 } from '../../dist/aquestalk2.js';
import fs from 'node:fs';

const [enc, speedStr, inPath, outPath, phontPath] = process.argv.slice(2);
const speed = Number(speedStr);
const buf = fs.readFileSync(inPath);
const phont = phontPath ? new Uint8Array(fs.readFileSync(phontPath)) : null;

const aq = await createAquesTalk2(new URL('../../dist/aquestalk2-core.wasm', import.meta.url));

let wav;
if (enc === 'utf16') {
  const units = new Uint16Array(Math.floor(buf.length / 2));
  for (let i = 0; i < units.length; i++)
    units[i] = buf.readUInt16LE(i * 2);
  wav = aq.syntheUtf16(units, speed, phont);
} else if (enc === 'sjis') {
  wav = aq.syntheSjis(new Uint8Array(buf), speed, phont);
} else if (enc === 'euc') {
  wav = aq.syntheEuc(new Uint8Array(buf), speed, phont);
} else if (enc === 'roman') {
  wav = aq.syntheRoman(buf.toString('latin1'), speed, phont);
} else {
  wav = phont ? aq.syntheWithPhont(buf.toString('utf8'), speed, phont)
              : aq.synthe(buf.toString('utf8'), speed);
}

if (!wav) {
  console.log('ERR', aq.lastError());
  process.exit(3);
}
fs.writeFileSync(outPath, wav);
console.log('OK', wav.length);
