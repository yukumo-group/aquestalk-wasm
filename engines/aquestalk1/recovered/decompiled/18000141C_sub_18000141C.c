__int64 __fastcall sub_18000141C(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // rax
  int v4; // esi
  __int64 result; // rax
  __int128 *v7; // rdi
  int v8; // ebx
  unsigned __int16 v9; // r15
  BOOL v10; // ecx
  _BYTE *v11; // rcx
  int v12; // eax
  _BYTE *v13; // rcx
  int v14; // r14d
  int v15; // ebx
  unsigned __int16 v16; // r13
  _WORD *v17; // rdi
  __int64 v18; // rax
  unsigned __int8 v19; // cf
  __int64 i; // rcx
  _BYTE *v21; // rdi
  __int16 v22; // cx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  _QWORD v26[2]; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v27; // [rsp+30h] [rbp-D0h]
  __int64 v28; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v29; // [rsp+40h] [rbp-C0h] BYREF
  _BYTE *v30; // [rsp+48h] [rbp-B8h]
  __int64 v31; // [rsp+50h] [rbp-B0h]
  __int64 v32; // [rsp+58h] [rbp-A8h] BYREF
  __int128 v33; // [rsp+60h] [rbp-A0h]
  __int64 v34; // [rsp+70h] [rbp-90h]
  __int64 v35; // [rsp+78h] [rbp-88h] BYREF
  int v36; // [rsp+80h] [rbp-80h]
  int v37; // [rsp+84h] [rbp-7Ch]
  __int128 *v38; // [rsp+88h] [rbp-78h]
  __int128 v39; // [rsp+90h] [rbp-70h] BYREF
  _BYTE *v40; // [rsp+A0h] [rbp-60h] BYREF
  int v41; // [rsp+A8h] [rbp-58h]
  int v42; // [rsp+ACh] [rbp-54h]
  _QWORD v43[4]; // [rsp+B0h] [rbp-50h] BYREF
  _QWORD v44[12]; // [rsp+D0h] [rbp-30h] BYREF

  v3 = *(_BYTE **)a1;
  v4 = 0;
  v27 = a3;
  v28 = 0;
  v39 = (unsigned __int64)v3;
  *v3 = 0;
  result = sub_180003F3C(&v28, a2, &v39);
  if ( (_DWORD)result )
    return result;
  v7 = &v39;
  v35 = 2048;
  v8 = 0;
  v38 = &v39;
  v36 = 0;
  v9 = -1;
  v37 = 0;
  while ( 1 )
  {
    if ( v7 )
      v10 = v8 >= *((__int16 *)v7 + 4);
    else
      v10 = 1;
    if ( v10 )
      return 0;
    v11 = *(_BYTE **)a1;
    v43[2] = 0;
    v42 = 1024;
    v41 = 0;
    v43[0] = 0;
    v40 = v11 + 2048;
    v43[1] = v11 + 6144;
    v43[3] = 0;
    result = sub_180002DC0(&v35, v43, &v40, &v28, v26[0]);
    if ( (_DWORD)result )
      return result;
    v12 = *(_DWORD *)(a1 + 8) * v28;
    v13 = *(_BYTE **)a1;
    v29 = 0xFFFFFFFFLL;
    v32 = 256;
    v30 = v13 + 6144;
    v14 = v12 / 256;
    LODWORD(v28) = v12 / 256;
    v34 = 0;
    v31 = 0;
    v33 = 0;
    result = sub_18000242C(v13 + 6144, &v40, &v29);
    if ( (_DWORD)result )
      return result;
    v15 = *(_DWORD *)(a1 + 8);
    LODWORD(v29) = -1;
    LODWORD(v32) = v15;
    LODWORD(v31) = 0;
    v16 = -1;
    memset(v44, 0, 0x58u);
    v17 = &v44[6];
    HIDWORD(v44[1]) = 39125589;
    v18 = qword_180034C10;
    v19 = _bittest64(&v18, v35 & 0x3F);
    LODWORD(v44[2]) = 39125589;
    HIWORD(v44[3]) = 0;
    HIDWORD(v44[8]) = 0;
    for ( i = 10; i; --i )
      *v17++ = 0;
    v44[9] = 0;
    WORD1(v44[0]) = word_180034C1C & 0xFFF;
    LODWORD(v44[10]) = 1024;
    LOBYTE(v44[4]) = v19;
    while ( v4 < SHIDWORD(v31) )
    {
      v21 = &v30[v4];
      v22 = *((_WORD *)v21 + 2);
      v23 = v22 & 0xC000;
      if ( (v22 & 0xC000) != 0 )
      {
        if ( v23 == 0x4000 )
        {
          v24 = 200 * v15;
        }
        else if ( v23 == 0x8000 )
        {
          v24 = 240 * v15;
        }
        else
        {
          v24 = 280 * v15;
        }
        v25 = v24 / 1024;
      }
      else
      {
        v25 = 40 * v15 / 256;
      }
      LOWORD(v26[0]) = v25;
      v4 = 0;
      WORD2(v26[0]) = *((_WORD *)v21 + 1);
      WORD1(v26[0]) = v22 & 0x3FFF;
      if ( *v21 )
      {
        if ( *v21 == 1 )
        {
          LOWORD(v29) = v9;
          WORD1(v29) = *((_WORD *)v21 + 3);
          sub_180001D74(&v29, v9, WORD1(v29), (unsigned __int8)v21[1], v26[0]);
          goto LABEL_29;
        }
        if ( *v21 == 2 )
        {
          LOWORD(v29) = *((_WORD *)v21 + 3);
          WORD1(v29) = *((_WORD *)v21 + 3);
          sub_180001E20((unsigned __int16)v29, (char *)&unk_18001E3A2 + 22 * (unsigned __int16)v29, (char *)&v32 + 4);
LABEL_29:
          LODWORD(v31) = v31 + 8;
          goto LABEL_31;
        }
        if ( *v21 != 3 )
          goto LABEL_34;
        LODWORD(v29) = *(_DWORD *)(v21 + 6);
        sub_180001D74(&v29, (unsigned __int16)v29, WORD1(v29), (unsigned __int8)v21[1], v26[0]);
        LODWORD(v31) = v31 + 10;
      }
      else
      {
        sub_180001D74(&v29, v16, v9, (unsigned __int8)v21[1], v26[0]);
        LODWORD(v31) = v31 + 6;
      }
LABEL_31:
      v26[1] = (char *)&v32 + 4;
      result = sub_1800059B4(v44, v26, v27);
      if ( (_DWORD)result )
        return result;
      v15 = v32;
      v4 = v31;
      v9 = WORD1(v29);
      v16 = v29;
    }
    v4 = 0;
LABEL_34:
    v7 = v38;
    v8 = v36;
    if ( *(int *)(a1 + 12) >= 0 && (!v38 || v36 >= *((__int16 *)v38 + 4)) )
    {
      v14 = *(_DWORD *)(a1 + 12);
      LODWORD(v28) = v14;
    }
    v9 = -1;
    if ( v14 > 0 )
    {
      result = sub_180002358(v27, 0, (unsigned int)v14);
      if ( (_DWORD)result )
        return result;
    }
  }
}