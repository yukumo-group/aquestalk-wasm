__int64 __fastcall sub_180004288(__int64 *a1, __int64 a2, _DWORD *a3)
{
  unsigned int v3; // ebx
  _BYTE *v4; // r9
  BOOL v7; // ecx
  int i; // r8d
  _BYTE *v9; // rdx
  char *v10; // r14
  int v11; // edi
  __int64 v12; // rsi
  _BYTE *v13; // rax
  _BYTE *v14; // rax
  char v15; // al
  int v16; // r9d
  const char *v17; // r10
  char v18; // r8
  _BYTE *v19; // rcx
  _BYTE *v20; // rcx
  const char *v21; // r9
  char v22; // r8
  char *v23; // rcx
  __int64 v24; // rax
  _BYTE *v25; // r8
  char *v27; // rcx
  _BYTE *v28; // r15
  int v29; // ecx
  _BYTE *v30; // r14
  int v31; // ecx
  int v32; // r9d
  char v33; // al
  __int64 v34; // rdi
  _BYTE *v35; // rsi
  unsigned int v36; // eax
  char v37; // cl
  char *v38; // rax
  __int64 v39; // rcx
  char v40; // al
  int v41; // ecx
  _BYTE *v42; // rax
  _BYTE *v43; // [rsp+30h] [rbp-39h] BYREF
  _QWORD v44[4]; // [rsp+38h] [rbp-31h] BYREF
  _QWORD v45[4]; // [rsp+58h] [rbp-11h] BYREF
  int v46; // [rsp+78h] [rbp+Fh] BYREF

  v3 = 0;
  v4 = (_BYTE *)(a2 + 1);
  v7 = 0;
  for ( i = 1; ; ++i )
  {
    if ( *v4 == 34 )
    {
      v7 = !v7;
      goto LABEL_7;
    }
    if ( *v4 == 62 && !v7 )
      break;
    if ( !*v4 )
      return 107;
LABEL_7:
    ++v4;
  }
  *(_BYTE *)(i + a2) = 0;
  *a3 = i + 1;
  v10 = sub_180001380((_BYTE *)(a2 + 1), a2, &v43);
  if ( !v10 )
    return 106;
  v11 = 0;
  v12 = 0;
  while ( 2 )
  {
    v13 = sub_180001380(0, (__int64)v9, &v43);
    v45[v12] = v13;
    if ( v13 && *v13 )
    {
      if ( !v43 )
      {
        v14 = 0;
        goto LABEL_36;
      }
      v15 = *v43;
      v16 = 0;
      v9 = v43;
      while ( v15 )
      {
        v17 = " =>\t\n";
        v18 = 32;
        while ( v15 != v18 )
        {
          v18 = *++v17;
          if ( !*v17 )
            goto LABEL_21;
        }
        ++v16;
        v15 = *++v9;
      }
LABEL_21:
      v14 = &v43[v16];
      LOBYTE(v9) = *v14;
      if ( *v14 == 34 )
      {
        v19 = ++v14;
        LOBYTE(v9) = *v14;
        while ( (_BYTE)v9 != 34 )
        {
          if ( !(_BYTE)v9 )
            goto LABEL_34;
          LOBYTE(v9) = *++v19;
        }
        goto LABEL_26;
      }
      v19 = &v43[v16];
LABEL_33:
      if ( !(_BYTE)v9 )
        goto LABEL_34;
      v21 = " =>\t\n";
      v22 = 32;
      while ( (_BYTE)v9 != v22 )
      {
        v22 = *++v21;
        if ( !*v21 )
        {
          LOBYTE(v9) = *++v19;
          goto LABEL_33;
        }
      }
LABEL_26:
      if ( v19 )
      {
        *v19 = 0;
        v20 = v19 + 1;
      }
      else
      {
LABEL_34:
        v20 = 0;
      }
      v43 = v20;
LABEL_36:
      v44[v12] = v14;
      if ( !v14 )
        return 106;
      ++v11;
      ++v12;
      if ( v11 >= 4 )
        break;
      continue;
    }
    break;
  }
  if ( !(unsigned int)sub_180001348(v10, "NUM") )
  {
    v24 = sub_180004660((_DWORD)v23, (unsigned int)&unk_18001B8B8, (unsigned int)v45, (unsigned int)v44, v11);
    if ( v24 )
    {
      v25 = (_BYTE *)*a1;
      v43 = 0;
      return sub_180004704(&v43, v24, v25);
    }
    return 106;
  }
  if ( !(unsigned int)sub_180001348(v23, "NUMK") )
  {
    v28 = (_BYTE *)sub_180004660((_DWORD)v27, (unsigned int)&unk_18001B8B8, (unsigned int)v45, (unsigned int)v44, v11);
    v30 = (_BYTE *)sub_180004660(v29, (unsigned int)"COUNTER", (unsigned int)v45, (unsigned int)v44, v11);
    v32 = sub_180004660(v31, (unsigned int)"MODE", (unsigned int)v45, (unsigned int)v44, v11);
    if ( !v28 )
      return 106;
    v33 = *v28;
    v34 = *a1;
    if ( *v28 )
    {
      v43 = (_BYTE *)*a1;
      v35 = v28;
      if ( v33 == 46 )
      {
LABEL_49:
        *v35 = 0;
        v37 = -126;
        v38 = (char *)&v46;
        do
        {
          *v38++ = v37;
          v37 = v38[&unk_1800300FC - (_UNKNOWN *)&v46];
        }
        while ( v37 );
        *v38 = 0;
        if ( *v28 )
          v36 = sub_1800047D0((unsigned int)&v43, (_DWORD)v28, (unsigned int)&v46, (unsigned int)&unk_180030104, v34);
        else
          v36 = sub_180004CA0(
                  (unsigned int)&v43,
                  (unsigned int)"0000",
                  0,
                  (unsigned int)&v46,
                  (__int64)&unk_180030104,
                  0);
        if ( v36 )
          return v36;
        if ( *(__int16 *)(v34 + 8) < 2047 )
        {
          *(_BYTE *)((__int16)(*(_WORD *)(v34 + 8))++ + *(_QWORD *)v34) = 5;
          v36 = sub_180004704(&v43, v35 + 1, v34);
          if ( v36 )
            return v36;
          if ( v30 )
          {
            while ( *v30 )
            {
              v40 = sub_1800017EC(v39, v30, &v46);
              if ( !v40 )
                return 105;
              if ( *(__int16 *)(v34 + 8) >= 2047 )
                return 200;
              v39 = *(_QWORD *)v34;
              *(_BYTE *)((__int16)(*(_WORD *)(v34 + 8))++ + *(_QWORD *)v34) = v40;
              v30 += v46;
            }
          }
        }
        else
        {
          return 200;
        }
      }
      else
      {
        while ( v33 )
        {
          v33 = *++v35;
          if ( *v35 == 46 )
          {
            if ( v35 )
              goto LABEL_49;
            return (unsigned int)sub_1800047D0((unsigned int)&v43, (_DWORD)v28, (_DWORD)v30, v32, v34);
          }
        }
        return (unsigned int)sub_1800047D0((unsigned int)&v43, (_DWORD)v28, (_DWORD)v30, v32, v34);
      }
    }
    return v3;
  }
  if ( (unsigned int)sub_180001348(v27, "ALPHA") )
    return 106;
  v42 = (_BYTE *)sub_180004660(v41, (unsigned int)&unk_18001B8B8, (unsigned int)v45, (unsigned int)v44, v11);
  if ( !v42 )
    return 106;
  return sub_180001000(v42, *a1);
}