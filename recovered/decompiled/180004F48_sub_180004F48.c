__int64 __fastcall sub_180004F48(__int64 **a1, __int64 a2, int a3, __int64 a4, __int64 a5, int a6)
{
  int v8; // ecx
  int v11; // edx
  __int64 v12; // rax
  int v13; // r14d
  __int64 v14; // r15
  __int64 v15; // rdi
  int v16; // ebp
  __int64 result; // rax
  __int64 *v18; // rdx
  __int64 *v19; // r11
  int v20; // r8d
  int v21; // ebx
  __int64 v22; // rcx
  int v23; // ebx
  int v24; // edx
  _BYTE *v25; // rax
  __int64 v26; // r11
  int v27; // eax
  __int64 v28; // rdx
  __int64 v29; // r8
  __int64 v30; // rcx

  v8 = 4;
  v11 = 3;
  v12 = 3;
  while ( *(_BYTE *)(v12 + a2) == 48 )
  {
    --v11;
    if ( --v12 < 0 )
      goto LABEL_6;
  }
  v8 = v11;
LABEL_6:
  v13 = 0;
  v14 = v8;
  v15 = 0;
  v16 = 3;
  while ( v15 != v14 )
  {
    if ( *(_BYTE *)(v15 + a2) != 48 )
    {
      result = sub_180004CA0((int)a1, a2, v16, 0, 0, 0);
      if ( (_DWORD)result )
        return result;
      v18 = *a1;
      if ( *((__int16 *)*a1 + 4) >= 2047 )
        return 200;
      *(_BYTE *)((__int16)(*((_WORD *)v18 + 4))++ + *v18) = 4;
    }
    ++v13;
    --v16;
    if ( ++v15 >= 4 )
      goto LABEL_16;
  }
  result = sub_180004CA0((int)a1, a2, a3 - v13 + 3, a4, a5, a6);
  if ( (_DWORD)result )
    return result;
LABEL_16:
  if ( a3 || a4 || *(_BYTE *)(a2 + 2) != 49 || *(_BYTE *)(a2 + 3) != 53 )
  {
    if ( *(_BYTE *)(a2 + 2) <= 0x38u )
    {
      v30 = 0x162000000000000LL;
      if ( _bittest64(&v30, *(char *)(a2 + 2)) )
      {
        if ( *(_BYTE *)(a2 + 3) != 48 )
          sub_180001A40(*a1, *(_BYTE *)(a2 + 2) == 49);
      }
    }
  }
  else
  {
    sub_180001A40(*a1, 1);
    v19 = *a1;
    v20 = *((__int16 *)*a1 + 4);
    v21 = v20 - 2;
    if ( v20 - 2 >= 0 )
    {
      v22 = v21;
      while ( (unsigned __int8)(*(_BYTE *)(v22 + *v19) - 3) > 6u )
      {
        --v21;
        if ( --v22 < 0 )
        {
          v23 = 0;
          v24 = 0;
          goto LABEL_27;
        }
      }
      v23 = v21 + 1;
      if ( v23 < 0 )
        return 0;
      v24 = v23;
      if ( v23 >= v20 )
      {
LABEL_30:
        v24 = -1;
        goto LABEL_31;
      }
LABEL_27:
      v25 = (_BYTE *)(*v19 + (unsigned int)v23);
      while ( *v25 != 1 )
      {
        ++v24;
        ++v25;
        if ( v24 >= v20 )
          goto LABEL_30;
      }
LABEL_31:
      sub_180001B2C((__int64)*a1, v24);
      if ( v23 + 1 >= 0 )
      {
        v27 = *(__int16 *)(v26 + 8);
        if ( v23 + 1 <= v27 )
        {
          v28 = v27 - 1;
          v29 = v23 + 1LL;
          while ( v28 >= v29 )
          {
            *(_BYTE *)(*(_QWORD *)v26 + v28 + 1) = *(_BYTE *)(*(_QWORD *)v26 + v28);
            --v28;
          }
          *(_BYTE *)(v29 + *(_QWORD *)v26) = 1;
          ++*(_WORD *)(v26 + 8);
        }
      }
    }
  }
  return 0;
}