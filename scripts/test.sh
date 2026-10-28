#!/bin/sh
# Headless smoke test: every engine, the kanji converter, and the pipeline.
set -eu
cd "$(dirname "$0")/.."
exec node tests/smoke.mjs
