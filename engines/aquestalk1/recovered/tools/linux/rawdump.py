#!/usr/bin/env python3
"""rawdump.py -- dump the voice tables out of the Linux libAquesTalk.so builds
into plain C arrays, so the engine no longer needs the OTPR preset files.

The first eight builds share one .rodata layout; f3 is a different build with
its own table addresses.  Addresses below come from the Ghidra dumps in
build/decomp-f2 and build/decomp-f3 (decompiler address - 0x100000).
"""
import os, struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
LIB = os.path.join(ROOT, "aqtk1_lnx/lib64")
OUT = os.path.join(ROOT, "recovered/src/data")

# classic layout
FORMANT, SYMBOLS, PHONEME = 0x127a0, 0x122a0, 0x1eec0
PERIOD, PULSE, DSCALE, DKEY, DVAL = 0x1f200, 0x21de0, 0x21d60, 0x21222, 0x21400

# (dur_base, M, pulse_len, q_tail, render_mode)
CLASSIC = {
    "f1":  (13248, 163, 597, 6400, 0),
    "f2":  (10624, 130, 597, 5120, 0),
    "m1":  (3968,   49, 2171, 1856, 0),
    "m2":  (5952,   74, 2171, 2816, 0),
    "r1":  (2624,   33, 597, 1216, 0),
    "imd1": (6400,  130, 597, 3072, 0),
    "jgr": (8960,  210, 597, 4288, 2),
    "dvd": (3840,   10, 2171, 1792, 1),
}
F3 = dict(formant=0x127a0, formant_n=25584, symbols=0x122a0, symbol_n=211,
          phoneme=0x1ef80, phoneme_n=328, period=0x1f240, pulse=0x21e60, pulse_n=597,
          dscale=0x21de0, dkey=0x212a2, dval=0x21480,
          dur_base=14592, mul=152, q_tail=6400, mode=0)

def i16(d, off, n):
    return list(struct.unpack_from("<%dh" % n, d, off))

def u16(d, off, n):
    return list(struct.unpack_from("<%dH" % n, d, off))

def scale_engine(d, off):
    """The .so indexes dur_scale by (h-3)*7+(l-3); the engine's 121-entry
    table is indexed by 7*h+l, i.e. the same values shifted by 24 entries."""
    true = i16(d, off, 60)
    arr = [1024] * 121
    for h in range(3, 10):
        for l in range(3, 10):
            arr[7 * h + l] = true[(h - 3) * 7 + (l - 3)]
    return arr

def marks(sym):
    has_dot = has_dash = has_semi = False
    for i in range(len(sym) // 6):
        a, b = sym[i * 6], sym[i * 6 + 1]
        if a == ord('a') and b == ord('.'):
            has_dot = True
        if a == ord('a') and b == ord('-'):
            has_dash = True
        if a == ord(';') and b == ord('a'):
            has_semi = True
    vowel = ord('.') if (has_dot and not has_dash) else ord('-')
    boundary = ord('.') if (has_dot and not has_semi) else ord(';')
    return vowel, boundary

def c_array(name, typ, vals, width=12):
    out = ["static const %s %s[] = {" % (typ, name)]
    for i in range(0, len(vals), width):
        out.append("    " + ", ".join(str(v) for v in vals[i:i + width]) + ",")
    out.append("};")
    return "\n".join(out)

def emit_voice(name, data, desc):
    sym = u16(data, desc["symbols"], desc["symbol_n"] * 3)
    sym_bytes = bytearray()
    for i in range(desc["symbol_n"]):
        a, b, cls, cnt, idx = struct.unpack_from("<BBBBH", data, desc["symbols"] + i * 6)
        sym_bytes += struct.pack("<BBBBH", a, b, cls, cnt, idx)
    vowel, boundary = marks(sym_bytes)
    parts = [
        '#include "ot_voice.h"',
        "",
        "/* raw dump of aqtk1_lnx/lib64/%s/libAquesTalk.so */" % name,
        c_array("formant", "int16_t", i16(data, desc["formant"], desc["formant_n"]), 10),
        c_array("symbols", "uint8_t", list(sym_bytes), 12),
        c_array("phoneme_word", "int16_t", i16(data, desc["phoneme"], desc["phoneme_n"])),
        c_array("period", "int16_t", i16(data, desc["period"], 4096)),
        c_array("pulse", "int16_t", i16(data, desc["pulse"], desc["pulse_n"])),
        c_array("dur_scale", "int16_t", scale_engine(data, desc["dscale"])),
        c_array("dur_key", "int16_t", i16(data, desc["dkey"], 240)),
        c_array("dur_val", "int16_t", i16(data, desc["dval"], 1200)),
        "",
        "const OtVoice *ot_voice_%s(void)" % name,
        "{",
        "    static const OtVoice v = {",
        "        (const OtSymbol *)symbols, %d," % desc["symbol_n"],
        "        phoneme_word, %d," % desc["phoneme_n"],
        "        formant, %d, 11," % desc["formant_n"],
        "        period, pulse, dur_scale, dur_key, dur_val,",
        "        %d, 4096000 / %d, %d, %d," % (desc["pulse_n"], desc["dur_base"], desc["q_tail"], desc["mode"]),
        "        '%s', '%s', %d, %d, %d" % (chr(vowel), chr(boundary), desc["dur_base"],
                                           desc["mul"], desc["engine"]),
        "    };",
        "    return &v;",
        "}",
        "",
    ]
    open(os.path.join(OUT, "voice_%s.c" % name), "w").write("\n".join(parts))

def main():
    for name, (dur_base, mul, pulse_len, q_tail, mode) in CLASSIC.items():
        data = open(os.path.join(LIB, name, "libAquesTalk.so"), "rb").read()
        emit_voice(name, data, dict(formant=FORMANT, formant_n=25476, symbols=SYMBOLS,
                                    symbol_n=209, phoneme=PHONEME, phoneme_n=392,
                                    period=PERIOD, pulse=PULSE, pulse_n=pulse_len,
                                    dscale=DSCALE, dkey=DKEY, dval=DVAL,
                                    dur_base=dur_base, mul=mul, q_tail=q_tail,
                                    mode=mode, engine=0))
        print("voice_%s.c" % name)
    data = open(os.path.join(LIB, "f3", "libAquesTalk.so"), "rb").read()
    emit_voice("f3", data, dict(F3, engine=1))
    print("voice_f3.c")

if __name__ == "__main__":
    main()
