__int64 __fastcall sub_1800037F0(__int64 a1, __int64 a2)
{
  int v4; // ebx
  __int64 i; // rax
  __int64 v6; // r11
  char v7; // al
  bool v8; // zf
  unsigned __int8 v9; // r8
  unsigned __int8 v10; // dl
  unsigned __int64 v11; // r10
  int v12; // r9d
  __int64 v13; // rsi
  __int64 v14; // rax
  int v15; // ecx
  _WORD *v16; // rbx
  unsigned int v17; // ebp
  _WORD *v18; // r14
  __int64 v19; // r9

  *(_QWORD *)(a2 + 20) = 0;
  v4 = 1024;
  for ( i = sub_1800022C0(a2); ; i = sub_1800022C0(a2) )
  {
    v11 = i;
    if ( !i )
      break;
    if ( v6 )
    {
      v7 = *(_BYTE *)(v6 + 1) & 0xF;
      if ( v7 == 3 )
      {
        v8 = (*(_BYTE *)(v11 + 1) & 0xF0) == 48;
        goto LABEL_9;
      }
      if ( v7 == 4 && (*(_BYTE *)(v11 + 1) & 0xF0) == 0x40 && !*(_WORD *)(v6 + 4) )
      {
        v8 = *(_WORD *)(v11 + 4) == 1;
LABEL_9:
        if ( v8 )
          goto LABEL_21;
      }
    }
    v9 = *(_BYTE *)(v11 + 1) >> 4;
    if ( *(_BYTE *)v11 == 0xAB && v11 >= *(_QWORD *)(a2 + 8) && v11 < *(_QWORD *)(a2 + 8) + *(int *)(a2 + 16) )
    {
      v10 = *(_BYTE *)(v11 + 1) & 0xF;
      if ( v10 == 3 )
        v10 = sub_1800022F8(a2, v11 + 4 * (*(unsigned __int16 *)(v11 + 2) + 2LL));
    }
    else
    {
      v10 = 8;
    }
    v12 = v4;
    v4 = word_18002CF90[7 * v9 - 24 + v10];
    if ( v6 && !*(_WORD *)(v6 + 4) && v9 == 4 && v4 < 8 * v12 / 10 )
      v4 = 8 * v12 / 10;
LABEL_21:
    *(_WORD *)(v11 + 6) = v4;
  }
  *(_QWORD *)(a2 + 20) = 0;
  v13 = sub_1800022C0(a2);
  if ( v13 )
  {
    while ( 1 )
    {
      v14 = sub_1800022C0(a2);
      LOWORD(v15) = *(_WORD *)(v13 + 2);
      v16 = (_WORD *)v14;
      v17 = 0;
      if ( (_WORD)v15 )
      {
        v18 = (_WORD *)(v13 + 8);
        do
        {
          if ( !*v18 )
          {
            v19 = 0;
            if ( v16 )
              v19 = (unsigned __int16)v16[2];
            *v18 = sub_180003A1C(a1, v17, v13, v19) + 13248;
          }
          v15 = *(unsigned __int16 *)(v13 + 2);
          ++v17;
          v18 += 2;
        }
        while ( (int)v17 < v15 );
      }
      if ( !v16 )
        break;
      if ( v16[1] >= 2u && *(_DWORD *)(v16 + 1) != 65538 && ((*(_BYTE *)(v13 + 1) & 0xF) != 5 || v16[2] != 1) )
        v16[4] = sub_180003A1C(a1, (unsigned __int16)v15, v13, (unsigned __int16)v16[2]) + 13248;
      v13 = (__int64)v16;
    }
    *(_WORD *)a2 = sub_180003A1C(a1, (unsigned __int16)v15, v13, 0) + 13248;
  }
  sub_180003C68(a1, a2);
  return 0;
}