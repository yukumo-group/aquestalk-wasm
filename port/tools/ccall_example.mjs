// Raw C ABI example: call the exported AquesTalk2_Synthe_Utf8 through ccall,
// without embind wrappers.
//   node port/tools/ccall_example.mjs out.wav
import createModule from '../../dist/aquestalk2.js';
import fs from 'node:fs';

const out = process.argv[2] ?? 'out.wav';
const m = await createModule();

const text = new TextEncoder().encode('こんにちは');
const koe = m._malloc(text.length + 1);
m.HEAPU8.set(text, koe);
m.HEAPU8[koe + text.length] = 0;

const sizePtr = m._malloc(4);
const wavPtr = m._AquesTalk2_Synthe_Utf8(koe, 100, sizePtr, 0);
if (!wavPtr) {
  console.error('error', m.HEAP32[sizePtr >> 2]);
  process.exit(1);
}
const size = m.HEAP32[sizePtr >> 2];
fs.writeFileSync(out, m.HEAPU8.slice(wavPtr, wavPtr + size));
console.log(out, size, 'bytes');

m._AquesTalk2_FreeWave(wavPtr);
m._free(koe);
m._free(sizePtr);
