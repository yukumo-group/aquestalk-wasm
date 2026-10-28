#!/bin/sh
# Native build: engine objects + the Linux parity tools.
set -e
cd "$(dirname "$0")/../../.."
CC=${CC:-gcc}
CFLAGS=${CFLAGS:--O2}
mkdir -p build/obj build/tools

OBJS=""
for f in recovered/src/api/*.c recovered/src/text/*.c recovered/src/audio/*.c \
         recovered/src/synth/*.c recovered/src/data/*.c recovered/src/f3/*.c recovered/f3port/src/*.c; do
    [ -f "$f" ] || continue
    o="build/obj/$(basename "${f%.c}").o"
    EXTRA=""
    case "$f" in
        recovered/f3port/src/decomp.c) EXTRA="-fpermissive -Wno-int-conversion -Wno-incompatible-pointer-types" ;;
    esac
    $CC -std=c11 -D_GNU_SOURCE -D__stdcall= $CFLAGS $EXTRA -Irecovered/include -Irecovered/f3port/include -c "$f" -o "$o"
    OBJS="$OBJS $o"
done
for t in kana_bench dump; do
    $CC -std=c11 -D_GNU_SOURCE -D__stdcall= $CFLAGS -Irecovered/include -Irecovered/f3port/include -o "build/tools/$t" \
        "recovered/tools/linux/$t.c" $OBJS -lm -ldl
done
echo "built build/tools/kana_bench build/tools/dump"
