__int16 __fastcall sub_180003A1C(__int64 a1, int a2, __int64 a3, int a4)
{
  unsigned int v4; // esi
  __int64 v5; // r10
  int v9; // eax
  int v10; // edx
  __int16 v11; // ax
  __int64 v12; // r9
  __int64 v13; // rdx
  char v14; // cl
  unsigned int v15; // ecx
  __int64 v16; // rdi
  int v17; // eax
  int v18; // r14d
  int v19; // r15d
  __int16 *v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // r11
  int v23; // ecx
  __int64 v24; // rcx
  int v25; // r8d
  char v27; // [rsp+20h] [rbp-28h] BYREF
  char v28; // [rsp+21h] [rbp-27h]
  __int16 v29; // [rsp+22h] [rbp-26h]
  __int16 v30; // [rsp+24h] [rbp-24h]
  __int16 v31; // [rsp+26h] [rbp-22h]

  v4 = *(unsigned __int16 *)(a3 + 2);
  v5 = a2;
  if ( (unsigned __int16)v4 < 2u )
  {
    if ( *(_WORD *)(a3 + 4) )
      LOWORD(v9) = 5 * *(_WORD *)(a3 + 6);
    else
      LOWORD(v9) = 0;
    return v9;
  }
  if ( v4 >= 7 )
  {
    v10 = *(unsigned __int16 *)(a3 + 4);
    if ( (unsigned int)v10 >= 4 )
    {
      if ( (int)v5 >= v10 )
      {
        v30 = 1;
        v14 = (*(_BYTE *)(a3 + 1) ^ v28) & 0xF ^ v28;
        v29 = v4 - v10 + 1;
        v11 = *(_WORD *)(a3 + 6);
        v28 = v14;
        v12 = (unsigned int)a4;
        v13 = (unsigned int)(v5 - v10 + 1);
      }
      else
      {
        v30 = 0;
        v28 = v28 & 0xF0 | 3;
        v11 = *(_WORD *)(a3 + 6);
        v12 = 1;
        v29 = v10 - 1;
        v13 = (unsigned int)v5;
      }
      v31 = v11;
      LOWORD(v9) = sub_180003A1C(a1, v13, &v27, v12);
      return v9;
    }
  }
  v15 = 0;
  switch ( *(_BYTE *)(a3 + 1) & 0xF )
  {
    case 6:
    case 7:
      a4 = 0;
      break;
    case 8:
      a4 = 1;
      break;
    case 9:
      a4 = 2;
      break;
    default:
      v16 = 0;
      goto LABEL_20;
  }
  v16 = 60;
LABEL_20:
  v17 = *(unsigned __int16 *)(a3 + 4);
  v18 = *(unsigned __int16 *)(a3 + 2);
  if ( v4 > 6 )
    v18 = 6;
  v19 = 0;
  if ( (unsigned __int16)v17 > 5u )
    v17 = 5;
  if ( v18 != v17 )
    v19 = v17;
  if ( a4 >= 0 )
  {
    if ( a4 > 2 )
      a4 = 2;
  }
  else
  {
    a4 = 0;
  }
  v20 = (__int16 *)&unk_18002D964;
  while ( *(v20 - 1) != v18 || *v20 != v19 || v20[1] != a4 )
  {
    ++v15;
    v20 += 4;
    if ( v15 >= 0x3C )
    {
      v15 = -1;
      break;
    }
  }
  v21 = v16 + (int)v15;
  v22 = 10 * v21;
  if ( v4 <= 6 || (v24 = word_18002D000[10 * v21 + 1], (int)v5 <= (int)v24) )
  {
    LOWORD(v23) = word_18002D000[v22 + 2 + v5];
  }
  else if ( (int)v5 > (int)(v24 + v4 - 6) )
  {
    LOWORD(v23) = word_18002D000[v22 + 8 + (int)(v5 - v4)];
  }
  else
  {
    v25 = word_18002D000[v22 + 2 + v24];
    v23 = v25 + ((int)v5 - (int)v24) * (word_18002D000[v22 + 3 + v24] - v25) / (__int16)(v4 - 5);
  }
  return (__int16)v23 * *(__int16 *)(a3 + 6) / 1024;
}