__int64 __fastcall sub_180004CA0(int a1, __int64 a2, int a3, __int64 a4, __int64 a5, int a6)
{
  int v6; // r13d
  const char *v8; // rbp
  __int64 v9; // r12
  int v10; // r9d
  int v11; // edi
  __int64 v12; // rcx
  char *v13; // rbx
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  BOOL v17; // esi
  __int64 result; // rax
  int v19; // ecx
  int v20; // r14d
  __int64 v21; // rcx
  __int64 v22; // rdx
  int v23; // ecx
  char v24; // [rsp+20h] [rbp-78h]
  unsigned int v26; // [rsp+A8h] [rbp+10h] BYREF
  int v27; // [rsp+B0h] [rbp+18h] BYREF
  int v28; // [rsp+B8h] [rbp+20h] BYREF

  v6 = a2;
  v8 = 0;
  v9 = a3 % 4;
  v10 = *(char *)(3 - a3 % 4 + a2) - 48;
  if ( a3 )
  {
    if ( a3 >= 4 )
      v11 = a3 / 4 + 12;
    else
      v11 = a3 + 9;
  }
  else
  {
    v11 = *(char *)(a2 + 3) - 48;
  }
  v12 = 16 * (v10 + 10LL * (a3 % 4));
  v13 = &aRe[v12];
  v14 = *(_DWORD *)((char *)dword_18002EBCC + v12);
  if ( a6 && v11 >= 13 && (_DWORD)v9 == 3 && *(_BYTE *)(3 - a3 % 4 + a2) == 49 )
  {
    v13 = &aRe[160 * v9];
    if ( v11 == 15 )
    {
      v14 = 0;
LABEL_28:
      v8 = "co--";
      goto LABEL_29;
    }
    v14 = dword_18002EBCC[40 * v9];
  }
  else if ( v11 == 15 )
  {
    if ( (_DWORD)v9 )
    {
      if ( (_DWORD)v9 == 1 )
      {
        v12 = (__int64)&unk_18002EEF0;
        v13 = (char *)&unk_18002EEF0 + 9 * v10;
      }
    }
    else
    {
      v13 = (char *)qword_18002E4F0[v10];
      if ( !v13 )
        v13 = off_18002E370[v10];
    }
    goto LABEL_28;
  }
  v12 = (__int64)v13;
  if ( v11 == 13 )
  {
    v8 = "maxx";
    v15 = 0;
    if ( *v13 )
    {
      do
      {
        ++v12;
        ++v15;
      }
      while ( *(_BYTE *)v12 );
    }
    v14 = (v15 >> 1) + 1;
  }
  else if ( v11 == 14 )
  {
    v8 = "ooku";
    v16 = 0;
    if ( *v13 )
    {
      do
      {
        ++v12;
        ++v16;
      }
      while ( *(_BYTE *)v12 );
    }
    v14 = v16 >> 1;
  }
LABEL_29:
  v17 = 0;
  if ( !a4 )
    return sub_18000521C(a1, (_DWORD)v13, (_DWORD)v8, a4, v24, v14, v17);
  result = sub_180005170(v12, a4, &a6);
  if ( !(_DWORD)result )
  {
    v20 = a6;
    result = sub_18000541C(v19, a4, a6, a5, (__int64)&v27, (__int64)&v26, (__int64)&v28);
    if ( !(_DWORD)result )
    {
      if ( v27 && v11 <= 11 )
      {
        v21 = 3LL * v27;
        if ( v11 >= 10 )
        {
          v21 = 96LL * v27;
          if ( v11 == 10 )
            LOBYTE(v17) = *(char **)((char *)off_18002E3C0 + v21) != 0;
          else
            v17 = *(char **)((char *)&off_18002E3C8 + v21) != 0;
        }
        else
        {
          v22 = v11 + 12LL * v27;
          if ( off_18002E370[v22] )
            v13 = off_18002E370[v22];
        }
      }
      sub_180005514(v21, a4, (unsigned int)v11, v26);
      v14 = sub_1800055DC(v23, v6, v9, v11, (__int64)v13, (__int64)v8, a4, v28, v20);
      return sub_18000521C(a1, (_DWORD)v13, (_DWORD)v8, a4, v24, v14, v17);
    }
  }
  return result;
}