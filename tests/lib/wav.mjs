/* WAV parsing / hashing helpers shared by the headless tests. */
import crypto from 'node:crypto';

/**
 * Parse a complete RIFF/WAVE file produced by an AquesTalk engine.
 * Throws on malformed input so every test gets the same diagnostics.
 */
export function parseWav(bytes) {
  if (!(bytes instanceof Uint8Array) || bytes.length < 44) {
    throw new Error(`not a WAV: ${bytes?.constructor?.name} ${bytes?.length ?? 0} bytes`);
  }
  const text = (start, end) => Buffer.from(bytes.buffer, bytes.byteOffset + start, end - start).toString('latin1');
  if (text(0, 4) !== 'RIFF' || text(8, 12) !== 'WAVE') {
    throw new Error('not a RIFF/WAVE file');
  }

  const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  let offset = 12;
  let fmt = null;
  let dataBytes = 0;
  while (offset + 8 <= bytes.length) {
    const id = text(offset, offset + 4);
    const size = dv.getUint32(offset + 4, true);
    const body = offset + 8;
    if (id === 'fmt ') {
      if (body + 16 > bytes.length) throw new Error('truncated fmt chunk');
      fmt = {
        format: dv.getUint16(body, true),
        channels: dv.getUint16(body + 2, true),
        rate: dv.getUint32(body + 4, true),
        bits: dv.getUint16(body + 14, true),
      };
    } else if (id === 'data') {
      dataBytes = Math.min(size, bytes.length - body);
      break;
    }
    offset = body + size + (size & 1);
  }
  if (!fmt) throw new Error('missing fmt chunk');
  if (!dataBytes) throw new Error('missing/empty data chunk');
  if (fmt.format !== 1) throw new Error(`unsupported WAV format ${fmt.format}`);
  if (fmt.channels !== 1) throw new Error(`expected mono, got ${fmt.channels} channels`);
  if (fmt.bits !== 16) throw new Error(`expected 16-bit, got ${fmt.bits}`);

  return {
    ...fmt,
    dataBytes,
    seconds: dataBytes / (fmt.rate * fmt.channels * (fmt.bits / 8)),
  };
}

export function sha256(bytes) {
  return crypto.createHash('sha256').update(bytes).digest('hex');
}

export function sameBytes(a, b) {
  return Buffer.compare(
    Buffer.from(a.buffer, a.byteOffset, a.byteLength),
    Buffer.from(b.buffer, b.byteOffset, b.byteLength),
  ) === 0;
}

export function summarizeWav(bytes) {
  const info = parseWav(bytes);
  return { ...info, bytes: bytes.length };
}
