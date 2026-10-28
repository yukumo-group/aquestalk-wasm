__int64 __fastcall sub_180003010(__int64 a1, __int64 a2, __int64 a3)
{
  char v5; // di
  __int64 v6; // rbx
  int v7; // r10d
  int v8; // edx
  __int64 v9; // rsi
  int v10; // r13d
  _BYTE *v11; // rcx
  unsigned __int8 *v12; // r8
  unsigned __int16 *v13; // r15
  __int64 v14; // rbp
  int v15; // eax
  char *v16; // rdx
  int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // r8d
  int v21; // eax
  unsigned __int8 *v22; // r8
  __int16 *v23; // rdx
  int v24; // edx
  int v25; // ecx
  int v26; // r8d
  char v27; // cl
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  int v31; // r8d
  __int16 v32; // ax
  unsigned __int8 *v34; // [rsp+30h] [rbp-48h]
  __int16 *v35; // [rsp+88h] [rbp+10h]
  __int64 v36; // [rsp+98h] [rbp+20h]

  *(_QWORD *)(a2 + 20) = 0;
  v5 = 8;
  v6 = sub_1800022C0(a2);
  if ( !v6 )
    return 0;
  do
  {
    v8 = *(unsigned __int16 *)(v6 + 2);
    v9 = v6;
    v10 = v7;
    if ( (unsigned __int16)v7 < (unsigned __int16)v8 )
    {
      v11 = (_BYTE *)(v6 + 10);
      v36 = v6 + 10;
      v12 = (unsigned __int8 *)(v6 + 14);
      v35 = (__int16 *)(v6 + 12);
      v34 = (unsigned __int8 *)(v6 + 14);
      v13 = (unsigned __int16 *)(v6 + 8);
      while ( 1 )
      {
        LOBYTE(v14) = *v11;
        if ( *v11 != 0xA0 )
          break;
        v15 = (unsigned __int16)v8;
        v16 = (char *)&unk_180030040;
        if ( v10 + 1 == v15 )
        {
          if ( ((unk_18002FD90 - 83) & 0xDF) == 0 )
            v16 = (char *)&unk_18003003C;
          v17 = sub_180002164(a3, v16, *v13);
LABEL_16:
          LOWORD(v7) = 0;
          if ( v17 < 0 )
            return 201;
          v22 = v34;
          v23 = v35;
          goto LABEL_18;
        }
        v14 = *v12;
        if ( ((*(_BYTE *)*(&off_18001B8C8 + 3 * v14) - 83) & 0xDF) == 0 )
          v16 = (char *)&unk_18003003C;
        if ( (int)sub_180002164(a3, v16, *v13) < 0 )
          return 201;
        LOBYTE(v20) = v14;
        LOBYTE(v18) = -96;
        v21 = sub_180003440(v19, v18, v20, a3, *v35);
        LOWORD(v7) = 0;
        if ( v21 < 0 )
          return 201;
        v22 = v34 + 4;
        v36 += 4;
        v23 = v35 + 2;
        ++v10;
        v13 += 2;
LABEL_18:
        v27 = v14;
        if ( (_BYTE)v14 == 0xA1 )
          v27 = v5;
        v28 = *(unsigned __int16 *)(v6 + 2);
        v5 = v27;
        v12 = v22 + 4;
        v11 = (_BYTE *)(v36 + 4);
        v35 = v23 + 2;
        ++v10;
        v36 += 4;
        v13 += 2;
        v34 = v12;
        v8 = (unsigned __int16)v28;
        if ( v10 >= v28 )
          goto LABEL_21;
      }
      LOBYTE(v12) = *v11;
      LOBYTE(v8) = v5;
      if ( (int)sub_1800034F0((_DWORD)v11, v8, (_DWORD)v12, a3, v7) < 0 )
        return 201;
      LOBYTE(v26) = v14;
      LOBYTE(v24) = v5;
      v17 = sub_180003440(v25, v24, v26, a3, *v13);
      goto LABEL_16;
    }
LABEL_21:
    v6 = sub_1800022C0(a2);
  }
  while ( v6 );
  v32 = v7;
  LOBYTE(v31) = *(_BYTE *)(v9 + 1) & 0xF;
  if ( (_BYTE)v31 == 9 && *(_WORD *)(v9 + 2) > (unsigned __int16)v7 )
  {
    v32 = *(_WORD *)(v9 + 4LL * *(unsigned __int16 *)(v9 + 2) + 4);
    if ( v32 )
    {
      v30 = 6400;
      v32 += 6400;
    }
  }
  LOBYTE(v29) = v5;
  if ( (int)sub_1800034F0(v30, v29, v31, a3, v32) < 0 )
    return 201;
  return 0;
}