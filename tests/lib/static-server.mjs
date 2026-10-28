/* Tiny static HTTP server used by the headless tests.
 *
 * The engine adapters use fetch()/WebAssembly.instantiateStreaming(), so the
 * tests cannot load the wasm modules straight from the filesystem.  Each test
 * starts this server on an ephemeral loopback port and points the adapters at
 * <url>/engines/.
 */
import http from 'node:http';
import fs from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

export const REPO_ROOT = path.resolve(fileURLToPath(new URL('../..', import.meta.url)));

const MIME = {
  '.html': 'text/html; charset=utf-8',
  '.js': 'text/javascript; charset=utf-8',
  '.mjs': 'text/javascript; charset=utf-8',
  '.css': 'text/css; charset=utf-8',
  '.json': 'application/json; charset=utf-8',
  '.wasm': 'application/wasm',
  '.phont': 'application/octet-stream',
  '.bin': 'application/octet-stream',
  '.dic': 'application/octet-stream',
  '.png': 'image/png',
};

export async function startStaticServer(root = REPO_ROOT) {
  const server = http.createServer(async (req, res) => {
    try {
      const url = new URL(req.url, 'http://127.0.0.1');
      const file = path.join(root, decodeURIComponent(url.pathname));
      if (file !== root && !file.startsWith(root + path.sep)) {
        res.writeHead(403).end('forbidden');
        return;
      }
      const data = await fs.readFile(file);
      res.writeHead(200, {
        'content-type': MIME[path.extname(file).toLowerCase()] || 'application/octet-stream',
        'cache-control': 'no-store',
      });
      res.end(data);
    } catch {
      res.writeHead(404).end('not found');
    }
  });

  await new Promise((resolve) => server.listen(0, '127.0.0.1', resolve));
  const { port } = server.address();
  return {
    url: `http://127.0.0.1:${port}`,
    port,
    close: () => new Promise((resolve, reject) =>
      server.close((err) => (err ? reject(err) : resolve()))),
  };
}
