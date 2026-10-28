__int64 __fastcall sub_180003C68(__int64 a1, unsigned __int16 *a2)
{
  unsigned int v2; // ebx
  unsigned __int16 *v3; // rsi
  __int64 v4; // rcx
  __int64 v5; // rbp
  __int64 v6; // r14
  _WORD *v7; // r13
  int v8; // r12d
  __int64 v9; // rax
  __int64 v10; // rdi
  unsigned __int8 *v11; // r15
  int v12; // r12d
  unsigned __int8 *v13; // r15
  __int16 v14; // ax
  __int16 v15; // ax
  char v16; // cl
  int v17; // r15d
  _WORD *v18; // r12
  int v19; // r9d
  __int16 v20; // ax
  int v21; // edx
  __int64 v22; // r15
  unsigned __int16 v23; // r10
  int v24; // edx
  __int64 v25; // r11
  _WORD *v26; // r8
  unsigned __int16 *v27; // r9
  _WORD *v28; // r8
  int v29; // ecx
  int v33; // [rsp+70h] [rbp+18h]

  v2 = 0;
  v3 = a2;
  *(_QWORD *)(a2 + 10) = 0;
  v4 = (__int64)a2;
  while ( 1 )
  {
    v5 = sub_1800022C0(v4);
    v6 = sub_1800022C0((__int64)v3);
    if ( !v6 )
      return v2;
    if ( (*(_BYTE *)(v5 + 1) & 0xF) != 3 )
      goto LABEL_42;
    v7 = (_WORD *)sub_1800022C0((__int64)v3);
    v8 = 0;
    v33 = *((_DWORD *)v3 + 5);
    v9 = *((int *)v3 + 4);
    *((_DWORD *)v3 + 5) = v9;
    v10 = *((_QWORD *)v3 + 1) + v9;
    if ( *(_WORD *)(v5 + 2) )
    {
      v11 = (unsigned __int8 *)(v5 + 10);
      while ( !(unsigned int)sub_1800021D8((__int64)v3, *v11) )
      {
        ++v8;
        v11 += 4;
        if ( v8 >= *(unsigned __int16 *)(v5 + 2) )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      v12 = 0;
      if ( !*(_WORD *)(v6 + 2) )
      {
LABEL_12:
        v14 = *(_WORD *)(v5 + 4);
        if ( !v14 )
        {
          v15 = *(_WORD *)(v6 + 4);
          if ( v15 )
            v14 = *(_WORD *)(v5 + 2) + v15;
          else
            v14 = 0;
        }
        *(_WORD *)(v10 + 4) = v14;
        *(_WORD *)(v10 + 6) = *(_WORD *)(v5 + 6);
        v16 = *(_BYTE *)(v5 + 1) ^ (*(_BYTE *)(v10 + 1) ^ *(_BYTE *)(v5 + 1)) & 0xF;
        *(_BYTE *)(v10 + 1) = v16;
        *(_BYTE *)(v10 + 1) = v16 ^ (*(_BYTE *)(v6 + 1) ^ v16) & 0xF;
        goto LABEL_18;
      }
      v13 = (unsigned __int8 *)(v6 + 10);
      while ( !(unsigned int)sub_1800021D8((__int64)v3, *v13) )
      {
        ++v12;
        v13 += 4;
        if ( v12 >= *(unsigned __int16 *)(v6 + 2) )
          goto LABEL_12;
      }
    }
    v10 = 0;
LABEL_18:
    *((_DWORD *)v3 + 5) = v33;
    if ( !v10 )
      return 202;
    v17 = 2;
    *(_WORD *)(v10 + 8) = *(_WORD *)(v5 + 8);
    *(_WORD *)(v10 + 12) = *(_WORD *)(v5 + 12);
    if ( *(_WORD *)(v10 + 2) > 2u )
    {
      v18 = (_WORD *)(v10 + 16);
      do
      {
        v19 = 0;
        if ( v7 )
          v19 = (unsigned __int16)v7[2];
        v20 = sub_180003A1C(a1, v17++, v10, v19);
        *v18 = v20 + 13248;
        v18 += 2;
      }
      while ( v17 < *(unsigned __int16 *)(v10 + 2) );
      v3 = a2;
    }
    if ( v7 )
    {
      v22 = a1;
    }
    else
    {
      v21 = v17;
      v22 = a1;
      *v3 = (*v3 + (unsigned int)(unsigned __int16)(sub_180003A1C(a1, v21, v10, 0) + 13248)) >> 1;
    }
    v23 = 0;
    if ( (unsigned __int8)((*(_BYTE *)(v10 + 1) & 0xF) - 6) > 3u && v7 && (v7[1] != 2 || v7[2] != 1) )
      v23 = sub_180003A1C(v22, *(unsigned __int16 *)(v10 + 2), v10, (unsigned __int16)v7[2]) + 13248;
    v24 = 2;
    v25 = 2;
    if ( *(_WORD *)(v5 + 2) > 2u )
    {
      v26 = (_WORD *)(v5 + 16);
      do
      {
        ++v24;
        ++v25;
        *v26 = ((unsigned __int16)*v26 + (unsigned int)*(unsigned __int16 *)((char *)v26 + v10 - v5)) >> 1;
        v26 += 2;
      }
      while ( v24 < *(unsigned __int16 *)(v5 + 2) );
    }
    if ( v24 < *(unsigned __int16 *)(v10 + 2) )
    {
      v27 = (unsigned __int16 *)(v10 + 4 * (v25 + 2));
      v28 = (_WORD *)(v6 + 8);
      do
      {
        ++v24;
        v29 = *v27;
        v27 += 2;
        *v28 = ((unsigned int)(unsigned __int16)*v28 + v29) >> 1;
        v28 += 2;
      }
      while ( v24 < *(unsigned __int16 *)(v10 + 2) );
    }
    if ( v23 )
      v7[4] = (v23 + (unsigned int)(unsigned __int16)v7[4]) >> 1;
    *((_DWORD *)v3 + 4) = v10 - *((_DWORD *)v3 + 2);
LABEL_42:
    v4 = (__int64)v3;
    *((_DWORD *)v3 + 5) = v6 - *((_DWORD *)v3 + 2);
  }
}