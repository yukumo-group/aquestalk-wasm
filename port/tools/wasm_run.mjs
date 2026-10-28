/* Node driver for the WebAssembly build.
 * usage: node wasm_run.mjs <enc> <speed> <in> <out> [phont]
 */
import createModule from '../../dist/aquestalk2.js';
import fs from 'node:fs';

const [enc, speedStr, inPath, outPath, phontPath] = process.argv.slice(2);
const speed = Number(speedStr);
const buf = fs.readFileSync(inPath);
const phont = phontPath ? new Uint8Array(fs.readFileSync(phontPath)) : null;

const m = await createModule();

function fail(msg) {
  console.log(msg);
  process.exit(3);
}

try {
  let u8;
  if (enc === 'utf16') {
    const u16 = new Uint16Array(Math.floor(buf.length / 2));
    for (let i = 0; i < u16.length; i++)
      u16[i] = buf.readUInt16LE(i * 2);
    u8 = m.syntheUtf16(u16, speed, phont);
  } else if (enc === 'sjis') {
    u8 = m.syntheSjis(new Uint8Array(buf), speed, phont);
  } else if (enc === 'euc') {
    u8 = m.syntheEuc(new Uint8Array(buf), speed, phont);
  } else if (enc === 'roman') {
    u8 = m.syntheRoman(buf.toString('latin1'), speed, phont);
  } else {
    u8 = phont ? m.syntheWithPhont(buf.toString('utf8'), speed, phont)
               : m.synthe(buf.toString('utf8'), speed);
  }
  if (u8 === null || u8 === undefined) {
    fail('ERR ' + m.lastError());
  }
  fs.writeFileSync(outPath, u8);
  console.log('OK', u8.length);
} catch (e) {
  fail(e.message ?? e);
}
