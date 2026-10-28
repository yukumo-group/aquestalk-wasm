#!/bin/sh
# Headless tests: every engine, the kanji converter, the cross-voice corpus
# and the 音声記号列仕様書 conformance suite.
set -eu
cd "$(dirname "$0")/.."
node tests/smoke.mjs
node tests/consistency.mjs
node tests/notation.mjs
