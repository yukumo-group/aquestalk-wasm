__int64 __fastcall sub_1800047D0(_QWORD *a1, _BYTE *a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v6; // r10d
  int v8; // r14d
  __int64 result; // rax
  bool v10; // zf
  _BYTE *v11; // rdx
  int v12; // eax
  int v13; // edx
  int v14; // ebx
  __int64 v15; // rcx
  __int64 v16; // rcx
  int v17; // esi
  __int64 v18; // r8
  int v19; // r12d
  __int64 v20; // r15
  __int64 v21; // rbp
  __int64 v22; // rcx
  int v23; // edx
  char v24; // al
  int v25; // [rsp+30h] [rbp-78h]
  __int64 v26; // [rsp+40h] [rbp-68h]
  unsigned int v27; // [rsp+48h] [rbp-60h] BYREF
  char v28; // [rsp+4Ch] [rbp-5Ch]

  v25 = a3;
  v6 = a3;
  v8 = (int)a1;
  if ( !a2 )
    return 100;
  if ( !*a2 )
    return 0;
  *a1 = a5;
  if ( !a4 )
  {
    v10 = (unsigned int)sub_180005774(a1, a2, a3, &v27) == 0;
    result = v27;
    if ( !v10 || v27 )
      return result;
    v6 = v25;
  }
  v11 = a2;
  v12 = 0;
  if ( !*a2 )
    goto LABEL_13;
  do
  {
    ++v11;
    ++v12;
  }
  while ( *v11 );
  if ( v12 == 1 && *a2 == 48 )
    return sub_180004CA0(v8, (unsigned int)"0000", 0, v6, a4, 0);
LABEL_13:
  v13 = v12 - 1;
  v14 = 0;
  v15 = v12 - 1;
  if ( v12 - 1 >= 0 )
  {
    while ( a2[v15] == 48 )
    {
      --v13;
      if ( --v15 < 0 )
        goto LABEL_18;
    }
    v14 = v12 - v13 - 1;
  }
LABEL_18:
  v16 = v12;
  v17 = 12;
  v26 = v12;
  v18 = v14;
  v19 = v12 - 16;
  v20 = v12 - (_QWORD)&v27 - 12LL;
  v21 = 12;
  while ( v16 <= v21 )
  {
LABEL_32:
    v19 += 4;
    v21 -= 4;
    v20 += 4;
    v17 -= 4;
    if ( v17 < 0 )
      return 0;
  }
  v28 = 0;
  v22 = 0;
  v23 = v19;
  do
  {
    if ( v23 >= 0 )
      v24 = a2[v20 + v22 + (_QWORD)&v26 + 4];
    else
      v24 = 48;
    *((_BYTE *)&v27 + v22) = v24;
    if ( v24 < 48 || v24 > 57 )
      return 108;
    ++v23;
    ++v22;
  }
  while ( v22 < 4 );
  if ( v21 <= v18 && v14 < v17 + 4 )
    return sub_180004F48(v8, (unsigned int)&v27, v17, v25, a4, 1);
  result = sub_180004F48(v8, (unsigned int)&v27, v17, 0, 0, 0);
  if ( (_DWORD)result )
    return result;
  if ( *(__int16 *)(a5 + 8) < 2047 )
  {
    *(_BYTE *)((__int16)(*(_WORD *)(a5 + 8))++ + *(_QWORD *)a5) = 7;
    v16 = v26;
    v18 = v14;
    goto LABEL_32;
  }
  return 200;
}