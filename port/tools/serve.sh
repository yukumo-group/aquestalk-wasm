#!/usr/bin/env bash
# Serve the built demo on http://localhost:8000/
set -euo pipefail
cd "$(dirname "$0")/../../dist"
exec python3 -m http.server "${1:-8000}"
