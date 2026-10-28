__int64 __fastcall sub_180002DC0(__int64 a1, __int64 a2, __int64 *a3, _DWORD *a4)
{
  __int64 v4; // rax
  unsigned int v5; // ebx
  char v10; // al
  __int64 v11; // rdx
  int v12; // ecx
  unsigned __int8 v13; // bp
  __int64 result; // rax
  unsigned int v15; // eax
  __int64 v16; // rcx
  __int64 v17; // rcx
  __int64 v18; // r8
  __int64 v19; // rax
  __int64 v20; // rdx
  __int64 v21; // rax
  int v22; // r9d
  char v23; // al
  __int64 v24; // rdx
  int i; // ecx
  unsigned __int8 v26; // dl
  _BYTE v27[8]; // [rsp+20h] [rbp-48h] BYREF

  v4 = *(_QWORD *)(a1 + 16);
  v5 = 0;
  if ( !v4 || *(_DWORD *)(a1 + 8) >= *(__int16 *)(v4 + 8) )
    return 100;
  v10 = *(_BYTE *)(a1 + 1);
  *(_BYTE *)a1 = 0;
  *(_BYTE *)(a2 + 2) = v10;
  *(_QWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_WORD *)a2 = 0;
  v11 = *(_QWORD *)(a1 + 16);
  v12 = *(_DWORD *)(a1 + 8);
  if ( v12 >= *(__int16 *)(v11 + 8) )
  {
LABEL_24:
    if ( v12 >= *(__int16 *)(v11 + 8) )
    {
LABEL_11:
      *(_BYTE *)(a1 + 1) = 5;
      *a4 = 0;
    }
    else
    {
      *a4 = 0;
      v24 = *(_QWORD *)(a1 + 16);
      for ( i = *(_DWORD *)(a1 + 8); i < *(__int16 *)(v24 + 8); v24 = *(_QWORD *)(a1 + 16) )
      {
        if ( i >= 0 && i < *(__int16 *)(v24 + 8) )
        {
          v26 = *(_BYTE *)(i + *(_QWORD *)v24);
          if ( v26 > 9u )
            break;
          if ( v26 >= 2u )
          {
            *(_BYTE *)(a1 + 1) = v26;
            switch ( v26 )
            {
              case 6u:
                *a4 += 666;
                break;
              case 7u:
                *a4 += 2000;
                break;
              case 8u:
              case 9u:
                *a4 += 4000;
                break;
            }
          }
        }
        i = *(_DWORD *)(a1 + 8) + 1;
        *(_DWORD *)(a1 + 8) = i;
      }
    }
    v15 = sub_1800037F0(v27, a2);
    if ( v15 )
      return v15;
    v15 = sub_180003010(v16, a2, a3);
    if ( v15 )
    {
      return v15;
    }
    else
    {
      v18 = *((int *)a3 + 2);
      if ( (int)v18 >= 2 )
      {
        v19 = *a3;
        *(_WORD *)(v19 + 4 * v18 - 4) &= 0x3FFFu;
        *(_WORD *)(v19 + 4 * v18 - 4) |= 0x8000u;
        v21 = *a3;
        *(_WORD *)(v21 + 4 * v18 - 8) &= 0x3FFFu;
        *(_WORD *)(v21 + 4 * v18 - 8) |= 0x8000u;
        v20 = *a3;
        LOBYTE(v21) = *(_BYTE *)(*a3 + 4 * v18 - 5);
        if ( (_BYTE)v21 != 45 )
        {
          if ( *(_BYTE *)(v20 + 4 * v18 - 6) != 43
            || (LOBYTE(v21) = v21 - 97, (unsigned __int8)v21 > 0x17u)
            || (v22 = 9453841, !_bittest(&v22, v21)) )
          {
            if ( (int)v18 - 3 >= 0 )
            {
              v23 = *(_BYTE *)(v20 + 4 * v18 - 9);
              if ( v23 != 59 )
              {
                *(_WORD *)(v20 + 4 * v18 - 12) &= 0x3FFFu;
                if ( ((v23 - 81) & 0xDF) != 0 )
                  *(_WORD *)(v20 + 4 * v18 - 12) |= 0x8000u;
                else
                  *(_WORD *)(v20 + 4 * v18 - 12) |= 0x4000u;
              }
            }
          }
        }
      }
      sub_180003290(v17, a3);
    }
    return v5;
  }
  else
  {
    while ( 1 )
    {
      v13 = v12 < 0 || v12 >= *(__int16 *)(v11 + 8) ? 0 : *(_BYTE *)(v12 + *(_QWORD *)v11);
      *(_BYTE *)a1 += v13;
      result = sub_1800021D8(a2, v13);
      if ( (_DWORD)result )
        break;
      v12 = *(_DWORD *)(a1 + 8);
      if ( (unsigned __int8)(v13 - 6) <= 3u )
      {
        v11 = *(_QWORD *)(a1 + 16);
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 8) = ++v12;
      v11 = *(_QWORD *)(a1 + 16);
      if ( v12 >= *(__int16 *)(v11 + 8) )
        goto LABEL_11;
    }
  }
  return result;
}