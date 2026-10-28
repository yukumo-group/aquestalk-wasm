#!/usr/bin/env python3
"""Generate the C translation unit for libAqUsrDic.so.4.1."""
import os, re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
DECOMP = os.path.join(ROOT, 'decomp_usr', 'all.c')
DATATSV = os.path.join(ROOT, 'decomp_usr', 'data.tsv')
OUT = os.path.join(ROOT, 'port_usr', 'src', 'decomp.c')

API_EXCLUDE = {'AqUsrDic_Check', 'AqUsrDic_Export', 'AqUsrDic_Import',
               'AqUsrDic_GetLastError'}


def read_funcs(path):
    src = open(path, encoding='utf-8').read()
    parts = re.split(r'//===== (.*?) @ ([0-9a-f]+) size=(\d+) =====\n', src)
    out = []
    for i in range(1, len(parts), 4):
        out.append({'name': parts[i], 'addr': int(parts[i + 1], 16),
                    'size': int(parts[i + 2]), 'body': parts[i + 3]})
    return out


def load_datatypes(path):
    types = {}
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        addr, name, typ, length = line.split('\t')
        types[name] = (typ, int(length))
    return types


def split_sig(body):
    idx = body.find('\n{')
    if idx < 0:
        raise RuntimeError('no body for ' + body[:60])
    return body[:idx].strip()


def normalize(name, text):
    text = re.sub(r'\bthunk_(FUN_[0-9a-f]+)\b', r'\1', text)
    text = text.replace('std::__cxx11::string::_M_append', 'aqstr_append')
    text = text.replace('std::__cxx11::string::_M_replace_aux', 'aqstr_replace_aux')
    text = text.replace('std::__cxx11::string::_M_replace', 'aqstr_replace')
    text = text.replace('std::__cxx11::string::_M_create', 'aqstr_create')
    text = text.replace('std::__cxx11::string::_M_construct', 'aqstr_construct')
    text = text.replace('std::__throw_length_error', 'aq_throw_length_error')
    text = text.replace('std::__throw_logic_error', 'aq_throw_logic_error')
    text = text.replace('std::__throw_out_of_range_fmt', 'aq_throw_out_of_range_fmt')
    text = text.replace('std::__throw_bad_alloc', 'aq_throw_bad_alloc')
    text = text.replace('std::__throw_bad_array_new_length', 'aq_throw_bad_array_new_length')
    text = text.replace('std::exception::~exception', 'aq_exception_dtor')
    text = re.sub(r'\boperator_new__\b', 'aq_new_array', text)
    text = re.sub(r'\boperator_delete__\b', 'aq_delete_array', text)
    text = re.sub(r'\boperator_new___\b', 'aq_new_array', text)
    text = re.sub(r'\boperator_delete___\b', 'aq_delete_array', text)
    text = re.sub(r'\boperator_new\b', 'operator_new', text)
    text = re.sub(r'\boperator_delete\b', 'operator_delete', text)
    # stack canary
    text = re.sub(r'^\s*long in_FS_OFFSET;\s*$', '', text, flags=re.M)
    # 16-byte zero compound literals
    text = re.sub(r'^(\s*)([^\n;]+?) = \(undefined1\s+\[16\]\)0x0;\s*$',
                  lambda m: m.group(1) + 'memset((void *)(%s), 0, 16);' % m.group(2).strip(),
                  text, flags=re.M)
    # bit fields
    def bf(m):
        base, off, width = m.group(1), int(m.group(2)), int(m.group(3))
        if width == 7:
            return '((unsigned long long)(%s) >> 8)' % base
        if width == 6:
            return '((unsigned long long)(%s) >> 16)' % base
        typ = {1: 'undefined1', 2: 'undefined2', 4: 'undefined4', 8: 'undefined8'}[width]
        return '(*(%s *)((char *)&(%s) + %d))' % (typ, base, off)
    text = re.sub(r'([A-Za-z_][A-Za-z0-9_]*(?:\[[^\]]*\])?)\._(\d+)_(\d+)_', bf, text)
    text = re.sub(r'\bundefined1 (auVar\d+) \[16\];', r'aq_v16 \1;', text)
    text = re.sub(r'\bstat64\s*\*', 'aq_stat64 *', text)
    text = text.replace('std::istream::read', 'aq_istream_read')
    text = text.replace('std::ostream::write', 'aq_ostream_write')
    text = text.replace('FUN_0010f700();', 'FUN_0010f700(param_1);')
    text = text.replace('FUN_001107f0();', 'FUN_001107f0(param_1);')
    text = text.replace('FUN_00110d30();', 'FUN_00110d30(param_1);')
    text = text.replace('FUN_001114e0();', 'FUN_001114e0(param_1,param_2);')
    text = text.replace('FUN_001220d0();', 'FUN_001220d0(param_1);')
    text = text.replace('FUN_00112ae0();', 'FUN_00112ae0(*(long *)(param_1 + 1000));')
    text = text.replace('FUN_00122860();', 'FUN_00122860(param_1,param_2);')
    text = text.replace('FUN_00124bd0(param_1 + 0x1a0);', 'FUN_00124bd0(param_1 + 0x1a0,uVar5);')
    text = re.sub(r'\bstat64 (local_[A-Za-z0-9_]+)', r'aq_stat64 \1', text)
    text = re.sub(r'(\w+) = SUB1614\(\(undefined1\s+\[16\]\)0x0,(\d+)\);',
                  r'memset(\1, 0, \2);', text)
    text = re.sub(r'(\w+) = pshuflw\(\1,\1,0x1b\);', r'\1 = aq_pshuflw(\1);', text)
    return text


def fix_usr_specifics(fname, body):
    # Trie write-size helper: return the serialized size computed by
    # FUN_00112ae0 instead of the lost void call.
    if fname == 'FUN_0010ead0':
        body = body.replace('void FUN_0010ead0(long *param_1)',
                            'long FUN_0010ead0(long *param_1)')
        body = body.replace('    FUN_00112ae0();\n    return;',
                            '    return FUN_00112ae0(*param_1);')
    # Trie search helper: pass the trie to the common-prefix search.
    if fname == 'FUN_0010e980':
        body = body.replace('void FUN_0010e980(long *param_1,long param_2)',
                            'uint FUN_0010e980(long *param_1,long param_2)')
        body = body.replace('    FUN_00115790();\n    return;',
                            '    return FUN_00115790(*param_1,param_2);')
        body = body.replace('  FUN_00115790(*param_1,param_2);\n  return;\n}',
                            '  return FUN_00115790(*param_1,param_2);\n}')
    # Callers where Ghidra lost arguments.
    if fname == 'FUN_0010fea0':
        body = body.replace('FUN_0010f700();', 'FUN_0010f700(param_1);')
    if fname == 'FUN_0010ff30':
        body = body.replace('FUN_0010fea0();',
                            'FUN_0010fea0(param_1,(ulong)*(uint *)(param_2 + 1));')
    if fname == 'FUN_001101b0':
        body = body.replace('FUN_0010ffd0();',
                            'FUN_0010ffd0(0,param_1,param_2,lVar3);')
    if fname in ('FUN_00110420', 'FUN_00110490'):
        body = body.replace('FUN_00110350();', 'FUN_00110350(param_1);')
    # Missing register arguments in MARISA writer/search internals.  The
    # values are only exercised on malformed dictionaries or cold paths; the
    # normal reader/writer paths pass them explicitly.
    body = body.replace('FUN_001143e0(*(long *)(param_1 + 1000),param_2)',
                        'FUN_001143e0(*(long *)(param_1 + 1000),param_2,0)')
    body = body.replace('FUN_00122380(param_1 + 0x2e8,param_2)',
                        'FUN_00122380(param_1 + 0x2e8,param_2,0)')
    body = body.replace('FUN_00114ab0(*(long *)(param_1 + 1000),param_2)',
                        'FUN_00114ab0(*(long *)(param_1 + 1000),param_2,0)')
    body = body.replace('FUN_00124f80(param_1)', 'FUN_00124f80(param_1,0)')
    body = body.replace('FUN_00124d20(param_1)', 'FUN_00124d20(param_1,0)')
    body = body.replace('FUN_00124bd0(param_1 + 0xd0)',
                        'FUN_00124bd0(param_1 + 0xd0,0)')
    body = body.replace('FUN_00124bd0(param_1 + 0x1a0,uVar5)',
                        'FUN_00124bd0(param_1 + 0x1a0,uVar14)')
    body = body.replace('FUN_00110fb0(param_2);',
                        'FUN_00110fb0(param_2,0,0);')
    if fname == 'FUN_0010afa0':
        body = body.replace('FUN_0010e980(local_150)',
                            'FUN_0010e980(local_150,local_148)')
        body = body.replace('FUN_0010cbe0(&local_f8,pbVar19,pbVar18[5] & 0x1f)',
                            'FUN_0010cbe0(&local_f8,pbVar19,pbVar18[5] & 0x1f,pbVar18[6] & 0x3f)')
    if fname == 'FUN_0010bb70':
        body = body.replace('FUN_0010ac50(param_1,param_2,0)',
                            'FUN_0010ac50(param_1,param_2,0,0,0)')
    if fname == 'FUN_0010c010':
        body = body.replace('FUN_0010ffd0(local_a8,*puVar1,(long)*(int *)(puVar1 + 1) * 2)',
                            'FUN_0010ffd0(0,local_a8,*puVar1,(long)*(int *)(puVar1 + 1) * 2)')
    if fname == 'FUN_0010cbe0':
        body = body.replace('FUN_0010cdd0(param_1,uVar5,0)',
                            'FUN_0010cdd0(param_1,uVar5,0,0,0)')
        body = body.replace('FUN_0010cdd0(param_1,uVar7,0,&DAT_00127718)',
                            'FUN_0010cdd0(param_1,uVar7,0,&DAT_00127718,1)')
    body = body.replace("aqstr_replace_aux((ulong)param_1,uVar5,0,'\\x01')",
                        "aqstr_replace_aux((ulong)param_1,uVar5,0,1,'\\x01')")
    # Recursive MARISA reader calls where Ghidra lost the arguments.
    body = body.replace('FUN_001150f0();', 'FUN_001150f0(*param_1,param_2);')
    body = body.replace('FUN_00114730();', 'FUN_00114730(*param_1,param_2);')
    body = body.replace('FUN_00114d90();', 'FUN_00114d90(*param_1,param_2);')
    body = body.replace('FUN_001129f0();', 'FUN_001129f0(*(long *)(param_1 + 1000));')
    # CSV field normaliser calls.
    if fname == 'FUN_0010ddc0':
        body = body.replace('FUN_0010d310();', 'FUN_0010d310(local_498,local_4b8);', 1)
        body = body.replace('FUN_0010d310(&local_4d8);', 'FUN_0010d310(local_478,&local_4d8);', 1)
    return body


def main():
    funcs = read_funcs(DECOMP)
    datatypes = load_datatypes(DATATSV)
    out = []
    stubbed = []
    for f in funcs:
        a = f['addr']
        if a < 0x104720 or a >= 0x130000:  # PLT / EXTERNAL block
            continue
        if f['name'] in API_EXCLUDE:
            continue
        if f['name'].startswith(('_INIT_', '_FINI_', '_DT_', 'thunk_')):
            continue
        body = normalize(f['name'], f['body'])
        # Ghidra's exception landing pads / cold throw helpers capture raw
        # stack slots and registers; they are never on the normal path.
        if any(x in body for x in ('in_stack_', 'stack0x', 'unaff_', 'in_XMM', '_Unwind_Resume', 'std::ios_base')):
            stubbed.append(f['name'])
            continue
        body = fix_usr_specifics(f['name'], body)
        out.append((f['name'], body))

    alltext = '\n'.join(b for _, b in out)
    syms = set(re.findall(r'\b(DAT_[0-9a-f]+|_DAT_[0-9a-f]+|PTR_DAT_[0-9a-f]+|'
                          r'PTR_FUN_[0-9a-f]+|PTR_vtable_[0-9a-f]+|'
                          r'PTR_nothrow_[0-9a-f]+|PTR_[0-9a-f]+|'
                          r'PTR_stderr_[0-9a-f]+|_UNK_[0-9a-f]+)\b', alltext))
    strings = set(re.findall(r'\b(s_[A-Za-z0-9_]+_[0-9a-f]+)\b', alltext))

    defs = ['/* data symbols backed by the relocated original image */']
    for s in sorted(strings):
        addr = int(s.rsplit('_', 1)[1], 16) - 0x100000
        defs.append('#define %s ((unsigned char *)(aq_image + 0x%x))' % (s, addr))
    for s in sorted(syms):
        addr = int(s.rsplit('_', 1)[1], 16) - 0x100000
        typ, length = datatypes.get(s, ('undefined1', 1))
        if typ.startswith('pointer') or typ.endswith(' *'):
            defs.append('#define %s (*(undefined **)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined8':
            defs.append('#define %s (*(undefined8 *)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined4':
            defs.append('#define %s (*(undefined4 *)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined2':
            defs.append('#define %s (*(undefined2 *)(aq_image + 0x%x))' % (s, addr))
        else:
            defs.append('#define %s (*(undefined1 *)(aq_image + 0x%x))' % (s, addr))

    protos = [split_sig(b) + ';' for _, b in out]
    protos += ['void *%s();' % n for n in stubbed]
    with open(OUT, 'w', encoding='utf-8') as f:
        f.write('/* Generated by tools/gen_decomp.py -- do not edit. */\n')
        f.write('#include "shim.h"\n\n')
        f.write('\n'.join(defs) + '\n\n')
        f.write('/* forward declarations */\n')
        f.write('\n'.join(protos) + '\n\n')
        for name in stubbed:
            f.write('/* cold stub: %s */\n' % name)
            f.write('void *%s() { return (void *)0; }\n\n' % name)
        for name, body in out:
            f.write('/* %s */\n' % name)
            f.write(body)
            if not body.endswith('\n'):
                f.write('\n')
            f.write('\n')
    print('wrote', OUT, 'functions', len(out), 'stubbed', len(stubbed), 'symbols', len(syms))


if __name__ == '__main__':
    main()
