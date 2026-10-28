#!/bin/sh
# Serve the repository root so that /demo/ can load engines/<name>/... assets.
set -eu
cd "$(dirname "$0")/.."
HOST="${HOST:-127.0.0.1}"
PORT="${PORT:-8000}"
echo "AquesTalk unified demo: http://${HOST}:${PORT}/demo/"
echo "Press Ctrl+C to stop."
exec python3 -m http.server "$PORT" --bind "$HOST"
