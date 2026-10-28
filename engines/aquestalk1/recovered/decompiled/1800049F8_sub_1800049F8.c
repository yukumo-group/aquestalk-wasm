__int64 __fastcall sub_1800049F8(int a1, _BYTE *a2)
{
  int v2; // r8d
  _BYTE *i; // rax
  int v5; // r9d
  __int64 v6; // rcx
  int v7; // ebx
  int v8; // eax
  _BYTE *v9; // rcx
  int v10; // r8d
  int v11; // r9d
  __int64 result; // rax
  int v13; // r8d
  int v14; // edx
  unsigned int v15; // [rsp+48h] [rbp+18h] BYREF

  v2 = 0;
  for ( i = a2; *i; ++v2 )
    ++i;
  v5 = v2;
  if ( v2 <= 0 )
  {
LABEL_7:
    v7 = 0;
    while ( 1 )
    {
      v8 = 0;
      v9 = a2;
      if ( !*a2 )
        break;
      do
      {
        ++v9;
        ++v8;
      }
      while ( *v9 );
      if ( v8 < 4 )
        break;
      LOBYTE(v5) = 4;
      if ( v8 == 4 )
      {
        v13 = sub_180004B24(a1, 2, (_DWORD)a2, v5, (__int64)&v15);
        v14 = 2;
        goto LABEL_21;
      }
      if ( v8 == 5 )
      {
        v13 = sub_180004B24(a1, 2, (_DWORD)a2, v5, (__int64)&v15);
        v14 = 3;
        goto LABEL_21;
      }
      v10 = sub_180004B24(a1, 2, (_DWORD)a2, v5, (__int64)&v15);
      result = v15;
      if ( v15 )
        return result;
      LOBYTE(v11) = 7;
      a2 = (_BYTE *)sub_180004B24(a1, 2, v10, v11, (__int64)&v15);
      result = v15;
      if ( v15 )
        return result;
      if ( ++v7 >= 20 )
        return 100;
    }
    v13 = (int)a2;
    v14 = v8;
LABEL_21:
    sub_180004B24(a1, v14, v13, 0, (__int64)&v15);
    return v15;
  }
  else
  {
    v6 = 0;
    while ( (unsigned __int8)(a2[v6] - 48) <= 9u )
    {
      if ( ++v6 >= v2 )
        goto LABEL_7;
    }
    return 108;
  }
}