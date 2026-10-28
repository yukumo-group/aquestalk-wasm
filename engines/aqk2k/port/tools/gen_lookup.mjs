// Generate lookup.bin: surface -> trie-id tables for the master dictionary
// (MSTD) and the single-character reading dictionary (MCGD).
//
// The original library searches the MARISA tries directly.  The port replaces
// that search with a hash table because the decompiled MARISA code depends on
// LP64 pointer arithmetic.  Both tries must be represented: MSTD supplies the
// word segmentation, MCGD supplies readings for punctuation/kana/Latin tokens
// that are not in MSTD.
import { readFileSync, writeFileSync } from 'node:fs';
import { createDict } from '../../bakak2k/src/index.js';
import { Marisa } from '../../bakak2k/src/marisa.js';

const [,, dicPath, outPath] = process.argv;
if (!dicPath || !outPath) {
  console.error('usage: gen_lookup.mjs <aqdic.bin> <lookup.bin>');
  process.exit(2);
}

const bytes = readFileSync(dicPath);
const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
const u32 = (o) => dv.getUint32(o, true);

// Walk the top-level sections.  UNKD is a container whose payload starts with
// the UNK1 table; POSD and MCGD follow it.
function sections() {
  const out = new Map();
  let o = 0;
  while (o + 8 <= bytes.length) {
    const name = bytes.toString('latin1', o, o + 4);
    const size = u32(o + 4);
    if (size === 0 || o + 8 + size > bytes.length) break;
    out.set(name, { off: o, size, data: o + 8 });
    o += 8 + size;
  }
  return out;
}

const sec = sections();
const mstd = sec.get('MSTD');
const mcgd = sec.get('MCGD');
if (!mstd || !mcgd) {
  console.error('dictionary is missing MSTD/MCGD sections');
  process.exit(1);
}

// MSTD: createDict gives us the parsed trie (and all keys in id order).
const dict = createDict(bytes);
const mstdKeys = dict.trie.allKeys();

// MCGD: decode its HDR1/TRI1 wrapper and enumerate the MARISA trie.
function trieKeys(section) {
  const base = section.data;
  if (bytes.toString('latin1', base, base + 4) !== 'HDR1') {
    console.error('bad section header for', section);
    process.exit(1);
  }
  const hdrSize = u32(base + 4);
  const tri = base + 8 + hdrSize;
  if (bytes.toString('latin1', tri, tri + 4) !== 'TRI1') {
    console.error('missing TRI1');
    process.exit(1);
  }
  const dataSize = u32(tri + 8);
  const marisa = new Marisa(bytes.subarray(tri + 12, tri + 12 + dataSize));
  return marisa.trie.allKeys();
}
const mcgdKeys = trieKeys(mcgd);

const chunks = [];
const head = Buffer.alloc(12);
head.write('K2K2', 0, 'latin1');
head.writeUInt32LE(mstdKeys.length, 4);
head.writeUInt32LE(mcgdKeys.length, 8);
chunks.push(head);

function emit(keys) {
  for (let id = 0; id < keys.length; id++) {
    const u16 = Buffer.from(keys[id], 'utf16le');
    const b = Buffer.alloc(8);
    b.writeUInt32LE(u16.length / 2, 0);
    b.writeUInt32LE(id, 4);
    chunks.push(b, u16);
  }
}
emit(mstdKeys);
emit(mcgdKeys);

const out = Buffer.concat(chunks);
writeFileSync(outPath, out);
console.log('mstd keys', mstdKeys.length, 'mcgd keys', mcgdKeys.length,
            'bytes', out.length);
