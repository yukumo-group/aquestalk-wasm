__int64 __fastcall sub_1800059B4(unsigned __int16 *a1, unsigned __int16 *a2, __int64 a3)
{
  unsigned __int16 v4; // cx
  int v7; // r14d
  __int16 *v8; // rsi
  __int64 i; // r10
  unsigned __int16 v10; // r8
  int v11; // r11d
  int v12; // ebp
  unsigned __int16 *v13; // r8
  __int64 v14; // r9
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // cx
  unsigned __int16 v17; // cx
  unsigned __int16 v18; // ax
  char *v19; // r10
  char *v20; // rdx
  int v21; // r8d
  int v22; // r8d
  __int64 v23; // rbp
  int v24; // r8d
  __int16 *j; // r9
  int v26; // ecx
  signed __int64 v27; // r10
  int v28; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // ecx
  __int64 result; // rax

  *a1 = *((unsigned __int8 *)a2 + 4);
  v4 = a2[1];
  a1[2] = *((unsigned __int8 *)a2 + 5);
  if ( !v4 )
    a1[15] = 1;
  a1[3] = v4;
  v7 = 0;
  *((_QWORD *)a1 + 5) = *((_QWORD *)a2 + 1);
  if ( !*a2 )
    return 0;
  v8 = (__int16 *)(a1 + 34);
  for ( i = 4; ; i = 4 )
  {
    v10 = a1[1];
    if ( v10 >= 0x1000u )
      v10 = 0;
    v11 = 0;
    v12 = *a1 * word_18002AF90[v10] / 128;
    a1[1] = v10 + 1;
    v13 = a1 + 6;
    do
    {
      v14 = *v13;
      if ( (unsigned __int16)v14 < 0x255u )
      {
        v11 += v13[4] * word_18002DB40[v14] / 128;
        *v13 = v14 + 8;
      }
      ++v13;
      --i;
    }
    while ( i );
    if ( a1[15] )
    {
      a1[a1[5] + 10] = a1[2];
      a1[a1[5]++ + 6] = 0;
      if ( a1[5] >= 4u )
        a1[5] = 0;
      a1[15] = 0;
    }
    else
    {
      v15 = a1[3];
      if ( v15 )
      {
        a1[4] += 8;
        v16 = a1[4];
        if ( v15 <= v16 )
        {
          v17 = v16 - v15;
          v18 = a1[2];
          a1[4] = v17;
          a1[a1[5] + 10] = v18;
          a1[a1[5]++ + 6] = a1[4];
          if ( a1[5] >= 4u )
            a1[5] = 0;
        }
      }
    }
    v19 = (char *)*((_QWORD *)a1 + 5);
    v20 = (char *)(a1 + 24);
    v21 = -v11;
    if ( !*((_BYTE *)a1 + 32) )
      v21 = v11;
    v22 = v12 + v21;
    v23 = *(int *)v8;
    v24 = *(__int16 *)v19 * v22;
    for ( j = (__int16 *)&v19[2 * (10 - v23)]; j <= (__int16 *)v19 + 10; ++j )
    {
      v26 = *j;
      v24 -= *(__int16 *)v20 * v26;
      v20 += 2;
    }
    if ( v20 < (char *)v8 )
    {
      v27 = v19 - v20;
      do
      {
        v28 = *(__int16 *)&v20[v27 + 2];
        v29 = *(__int16 *)v20;
        v20 += 2;
        v24 -= v29 * v28;
      }
      while ( v20 < (char *)v8 );
    }
    if ( v24 < 0x7FFFFFF )
    {
      if ( v24 > -134217727 )
        v30 = (v24 + 2048) >> 12;
      else
        LOWORD(v30) = 0x8000;
    }
    else
    {
      LOWORD(v30) = 0x7FFF;
    }
    a1[v23 + 24] = v30;
    v31 = *(_DWORD *)v8 ? *(_DWORD *)v8 - 1 : 9;
    *(_DWORD *)v8 = v31;
    result = sub_180002358(a3, v30, 1u);
    if ( (_DWORD)result )
      break;
    if ( ++v7 >= *a2 )
      return 0;
  }
  return result;
}