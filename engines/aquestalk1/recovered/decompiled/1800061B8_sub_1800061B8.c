__int64 __fastcall sub_1800061B8(char *a1, _BYTE *a2, int a3)
{
  char *v4; // r9
  int v5; // r11d
  int v6; // edi
  bool i; // zf
  char v8; // r8
  __int64 v9; // rax
  int v10; // ecx
  int v11; // r10d
  _BYTE *j; // rcx
  char *v14; // r8

  v4 = a1;
  if ( !a1 || !*a1 || !a2 || a3 <= 1 )
    return 4294967294LL;
  v5 = 0;
  v6 = (int)a1;
  *a2 = 0;
  for ( i = *a1 == 0; !i; i = *v4 == 0 )
  {
    v8 = *v4;
    if ( (unsigned __int8)*v4 >= 0x80u )
    {
      v11 = 0;
      for ( j = &unk_18002EF65; v8 != *(j - 1) || v4[1] != *j || v4[2] != j[1]; j += 10 )
      {
        if ( (unsigned int)++v11 >= 0xA2 )
          return (unsigned int)((_DWORD)v4 - v6 + 1);
      }
      v14 = (char *)&unk_18002EF60 + 10 * v11;
      if ( !v14 )
        return (unsigned int)((_DWORD)v4 - v6 + 1);
      if ( v5 + 3 > a3 )
        return 0xFFFFFFFFLL;
      *a2 = *v14;
      a2[1] = v14[1];
      v9 = 3;
      a2 += 2;
      v10 = 2;
    }
    else
    {
      if ( v5 + 2 > a3 )
        return 0xFFFFFFFFLL;
      v9 = 1;
      *a2 = v8;
      v10 = 1;
      ++a2;
    }
    v4 += v9;
    *a2 = 0;
    v5 += v10;
  }
  return 0;
}