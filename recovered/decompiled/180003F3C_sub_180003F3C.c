__int64 __fastcall sub_180003F3C(_QWORD *a1, unsigned __int8 *a2, __int64 a3)
{
  _BYTE *v3; // rax
  unsigned __int8 *v5; // rbx
  _QWORD *v6; // rsi
  unsigned __int8 i; // al
  __int64 result; // rax
  char v9; // al
  __int64 v10; // rcx
  char v11; // r8
  int v12; // r10d
  __int64 v13; // r9
  int v14; // edx
  char v15; // r9
  int v16; // ebx
  int v17; // esi
  int v18; // r11d
  __int64 v19; // r10
  unsigned __int8 v20; // dl
  __int64 v21; // r8
  int v22; // r9d
  bool v23; // zf
  char v24; // al
  int v25; // r8d
  __int64 v26; // rdx
  unsigned __int8 v27; // r9
  __int16 v28; // ax
  int v29; // [rsp+40h] [rbp+8h] BYREF

  *a1 = a3;
  v3 = *(_BYTE **)a3;
  *(_WORD *)(a3 + 8) = 0;
  v5 = a2;
  v6 = a1;
  v29 = 0;
  *v3 = 0;
  for ( i = *a2; i >= 0x20u; i = *v5 )
  {
    if ( i == 60 )
    {
      result = sub_180004288(v6, v5, &v29);
      if ( (_DWORD)result )
        return result;
    }
    else
    {
      v9 = sub_1800017EC((__int64)a1, v5, &v29);
      if ( !v9 )
        return 105;
      if ( *(__int16 *)(a3 + 8) >= 2047 )
        return 200;
      a1 = *(_QWORD **)a3;
      *(_BYTE *)((__int16)(*(_WORD *)(a3 + 8))++ + *(_QWORD *)a3) = v9;
    }
    v5 += v29;
  }
  v10 = *(unsigned __int16 *)(a3 + 8);
  v11 = 8;
  v12 = 0;
  if ( (__int16)v10 > 0 )
  {
    v13 = 0;
    do
    {
      if ( v13 < 0 || v12 >= (__int16)v10 )
      {
        LOBYTE(v14) = 0;
      }
      else
      {
        v14 = *(unsigned __int8 *)(v13 + *(_QWORD *)a3);
        if ( (unsigned __int8)(v14 + 60) <= 8u )
        {
          if ( (unsigned __int8)(v11 - 2) > 7u )
          {
            switch ( v14 )
            {
              case 196:
                LOBYTE(v14) = 49;
                break;
              case 197:
                LOBYTE(v14) = 50;
                break;
              case 198:
                LOBYTE(v14) = 51;
                break;
              case 199:
                LOBYTE(v14) = 52;
                break;
              case 200:
                LOBYTE(v14) = 53;
                break;
              case 201:
                LOBYTE(v14) = 113;
                break;
              case 202:
                LOBYTE(v14) = 114;
                break;
              case 203:
                LOBYTE(v14) = 115;
                break;
              case 204:
                LOBYTE(v14) = 116;
                break;
            }
          }
          else
          {
            switch ( v14 )
            {
              case 196:
                LOBYTE(v14) = 54;
                break;
              case 197:
                LOBYTE(v14) = 55;
                break;
              case 198:
                LOBYTE(v14) = 56;
                break;
              case 199:
                LOBYTE(v14) = 57;
                break;
              case 200:
                LOBYTE(v14) = 58;
                break;
              case 201:
                LOBYTE(v14) = 117;
                break;
              case 202:
                LOBYTE(v14) = 118;
                break;
              case 203:
                LOBYTE(v14) = 119;
                break;
              case 204:
                LOBYTE(v14) = 120;
                break;
            }
          }
          if ( v12 < *(__int16 *)(a3 + 8) )
            *(_BYTE *)(v13 + *(_QWORD *)a3) = v14;
        }
      }
      v10 = (unsigned int)*(__int16 *)(a3 + 8);
      ++v12;
      ++v13;
      v11 = v14;
    }
    while ( v12 < (int)v10 );
  }
  v15 = 8;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( (__int16)v10 > 0 )
  {
    v19 = 0;
    while ( 1 )
    {
      if ( v19 < 0 || v18 >= (__int16)v10 )
      {
        v20 = 0;
        goto LABEL_67;
      }
      v20 = *(_BYTE *)(v19 + *(_QWORD *)a3);
      if ( v20 != 1 )
        break;
      v17 = v16;
LABEL_94:
      v10 = (unsigned int)*(__int16 *)(a3 + 8);
      ++v18;
      ++v19;
      if ( v18 >= (int)v10 )
        goto LABEL_95;
    }
    if ( (unsigned __int8)(v20 - 2) <= 7u )
    {
      v16 = 0;
      v17 = 0;
LABEL_93:
      v15 = v20;
      goto LABEL_94;
    }
LABEL_67:
    if ( (unsigned __int8)(v20 + 77) > 0x10u )
    {
LABEL_92:
      ++v16;
      goto LABEL_93;
    }
    v21 = v19 + 1;
    if ( v19 + 1 < 0 || (v10 = (unsigned int)(v18 + 1), (int)v10 >= *(__int16 *)(a3 + 8)) )
      LOBYTE(v10) = 0;
    else
      LOBYTE(v10) = *(_BYTE *)(v21 + *(_QWORD *)a3);
    if ( (unsigned __int8)(v15 + 94) <= 0x10u || (unsigned __int8)(v10 - 6) <= 1u )
      goto LABEL_88;
    if ( (unsigned __int8)(v10 - 8) <= 1u )
    {
      if ( !v16 )
        goto LABEL_88;
      v23 = v17 == 0;
    }
    else
    {
      if ( (_BYTE)v10 )
      {
        v22 = v18 + 1;
        do
        {
          if ( (unsigned __int8)v10 > 9u )
            break;
          LOBYTE(v10) = v21 < 0 || v22++ >= *(__int16 *)(a3 + 8) ? 0 : *(_BYTE *)(v21 + *(_QWORD *)a3);
          ++v21;
        }
        while ( (_BYTE)v10 );
      }
      v10 = 3LL * (unsigned __int8)v10;
      v23 = dword_18001B8D0[2 * v10] == 0;
    }
    if ( !v23 )
    {
      v24 = sub_1800018C0(v10, v20);
LABEL_89:
      v20 = v24;
      if ( v19 >= 0 && v18 < *(__int16 *)(a3 + 8) )
        *(_BYTE *)(v19 + *(_QWORD *)a3) = v24;
      goto LABEL_92;
    }
LABEL_88:
    v24 = sub_18000195C(v10, v20);
    goto LABEL_89;
  }
LABEL_95:
  if ( word_180034C18 != 22614 )
  {
    v25 = 0;
    if ( (__int16)v10 > 0 )
    {
      v26 = 0;
      do
      {
        if ( v26 < 0 || v25 >= (__int16)v10 )
        {
          v28 = v10;
        }
        else
        {
          v27 = *(_BYTE *)(v26 + *(_QWORD *)a3);
          if ( (unsigned __int8)(v27 - 30) <= 4u || (v28 = v10, v27 >= 0x27u) && v27 <= 0x2Bu )
          {
            *(_BYTE *)(v26 + *(_QWORD *)a3) = 32;
            v28 = *(_WORD *)(a3 + 8);
          }
        }
        LOWORD(v10) = v28;
        ++v25;
        ++v26;
      }
      while ( v25 < v28 );
    }
  }
  return 0;
}