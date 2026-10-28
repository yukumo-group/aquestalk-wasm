#!/usr/bin/env python3
"""Native reference renderer for the AquesTalk wasm parity tests.

Reads a JSON request on stdin, calls the *original* Linux shared libraries via
ctypes, and writes SHA-256/size (or the native error code) for every case on
stdout.  The Node consistency test compares those values with the wasm
outputs.  The libraries are never modified; AquesTalk1 is loaded from the
sibling SDK checkout because its .so files are not committed here.

Request shape::

    {
      "engines": {
        "aqtk1": {"voices": {"f1": "/path/libAquesTalk.so", ...}},
        "aqtk2": {"lib": "/path/libAquesTalk2Eva.so.2.3",
                  "voices": {"": null, "aq_rm.phont": "/path/aq_rm.phont"}},
        "aqtk10": {"lib": "/path/libAquesTalk10.so.1.1",
                   "voices": {"F1": [0,100,100,100,100,100,100], ...}}
      },
      "cases": [{"id": "...", "text": "..."}],
      "speed": {"text": "...", "speeds": [50, ...]}
    }
"""
import ctypes
import hashlib
import json
import sys
from pathlib import Path


def preload_runtime():
    """The Linux SDKs are C++ builds; load the C++ runtime globally first."""
    for name in ("libstdc++.so.6", "libm.so.6"):
        try:
            ctypes.CDLL(name, mode=ctypes.RTLD_GLOBAL)
        except OSError:
            pass


def load_aq1(path):
    lib = ctypes.CDLL(path)
    fn = lib.AquesTalk_Synthe_Utf8
    fn.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
    fn.restype = ctypes.c_void_p
    free = lib.AquesTalk_FreeWave
    free.argtypes = [ctypes.c_void_p]
    free.restype = None
    return fn, free


def load_aq2(path):
    lib = ctypes.CDLL(path)
    fn = lib.AquesTalk2_Synthe_Utf8
    fn.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_void_p]
    fn.restype = ctypes.c_void_p
    free = lib.AquesTalk2_FreeWave
    free.argtypes = [ctypes.c_void_p]
    free.restype = None
    return fn, free


def load_aq10(path):
    lib = ctypes.CDLL(path)
    fn = lib.AquesTalk_Synthe_Utf8
    fn.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_char_p, ctypes.POINTER(ctypes.c_int)]
    fn.restype = ctypes.c_void_p
    free = lib.AquesTalk_FreeWave
    free.argtypes = [ctypes.c_void_p]
    free.restype = None
    return fn, free


def render_aq1(fn, free, text, speed):
    size = ctypes.c_int(0)
    ptr = fn(text.encode("utf-8"), int(speed), ctypes.byref(size))
    if not ptr:
        return {"error": int(size.value), "size": 0}
    data = ctypes.string_at(ptr, size.value)
    free(ptr)
    return {"size": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def render_aq2(fn, free, phont_bytes, text, speed):
    size = ctypes.c_int(0)
    buffer = ctypes.create_string_buffer(phont_bytes) if phont_bytes else None
    ptr = fn(
        text.encode("utf-8"),
        int(speed),
        ctypes.byref(size),
        ctypes.cast(buffer, ctypes.c_void_p) if buffer else None,
    )
    if not ptr:
        return {"error": int(size.value), "size": 0}
    data = ctypes.string_at(ptr, size.value)
    free(ptr)
    return {"size": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def render_aq10(fn, free, params, text, speed):
    size = ctypes.c_int(0)
    voice = (ctypes.c_int * 7)(*[int(value) for value in params])
    ptr = fn(voice, text.encode("utf-8"), ctypes.byref(size))
    if not ptr:
        return {"error": int(size.value), "size": 0}
    data = ctypes.string_at(ptr, size.value)
    free(ptr)
    return {"size": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def main():
    request = json.load(sys.stdin)
    result = {"engines": {}, "speed": {}, "errors": []}
    cases = request.get("cases", [])
    speed_spec = request.get("speed")

    for engine, config in request.get("engines", {}).items():
        try:
            if engine == "aqtk1":
                loaded = {}
                for voice, path in config["voices"].items():
                    loaded[voice] = load_aq1(path)
                result["engines"][engine] = {
                    voice: {
                        case["id"]: render_aq1(fn, free, case["text"], 100)
                        for case in cases
                    }
                    for voice, (fn, free) in loaded.items()
                }
                if speed_spec:
                    result["speed"][engine] = {
                        voice: {
                            str(rate): render_aq1(fn, free, speed_spec["text"], rate)
                            for rate in speed_spec["speeds"]
                        }
                        for voice, (fn, free) in loaded.items()
                    }
            elif engine == "aqtk2":
                fn, free = load_aq2(config["lib"])
                voices = {}
                for voice, phont_path in config["voices"].items():
                    phont = Path(phont_path).read_bytes() if phont_path else None
                    voices[voice] = phont
                result["engines"][engine] = {
                    voice: {
                        case["id"]: render_aq2(fn, free, phont, case["text"], 100)
                        for case in cases
                    }
                    for voice, phont in voices.items()
                }
                if speed_spec:
                    result["speed"][engine] = {
                        voice: {
                            str(rate): render_aq2(fn, free, phont, speed_spec["text"], rate)
                            for rate in speed_spec["speeds"]
                        }
                        for voice, phont in voices.items()
                    }
            elif engine == "aqtk10":
                fn, free = load_aq10(config["lib"])
                result["engines"][engine] = {
                    voice: {
                        case["id"]: render_aq10(fn, free, params, case["text"], 100)
                        for case in cases
                    }
                    for voice, params in config["voices"].items()
                }
                if speed_spec:
                    result["speed"][engine] = {
                        voice: {
                            str(rate): render_aq10(
                                fn, free,
                                [params[0], rate, *params[2:]],
                                speed_spec["text"], rate)
                            for rate in speed_spec["speeds"]
                        }
                        for voice, params in config["voices"].items()
                    }
            else:
                result["errors"].append(f"unknown engine: {engine}")
        except Exception as exc:  # keep the other engines usable
            result["errors"].append(f"{engine}: {type(exc).__name__}: {exc}")
    json.dump(result, sys.stdout, ensure_ascii=False)


if __name__ == "__main__":
    preload_runtime()
    main()
