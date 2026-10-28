import { readFileSync, writeFileSync } from 'node:fs';
import { createDict } from '../../bakak2k/src/index.js';
const [,, dicPath, outPath] = process.argv;
const d = createDict(readFileSync(dicPath));
const m = d.bySurface;
const keys = [...m.keys()];
keys.sort();
const enc = new TextEncoder();
const chunks = [];
// header: magic, count
const head = Buffer.alloc(12); head.write('K2KL',0,'latin1'); head.writeUInt32LE(keys.length,4); head.writeUInt32LE(0,8);
chunks.push(head);
for (const k of keys) {
  const arr = m.get(k);
  const id = arr[0].id;
  const u16 = Buffer.from(k, 'utf16le');
  const b = Buffer.alloc(8); b.writeUInt32LE(u16.length/2,0); b.writeUInt32LE(id,4);
  chunks.push(b, u16);
}
writeFileSync(outPath, Buffer.concat(chunks));
console.log('keys', keys.length, 'bytes', chunks.reduce((a,b)=>a+b.length,0));
