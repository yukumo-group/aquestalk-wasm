__int64 __fastcall sub_180005170(__int64 a1, _BYTE *a2, _DWORD *a3)
{
  int v3; // esi
  _BYTE *v5; // rdi
  _BYTE *v6; // rbx
  unsigned __int8 v7; // al
  _BYTE *v8; // rax
  __int64 v10; // [rsp+30h] [rbp+8h] BYREF

  v10 = a1;
  v3 = 0;
  *a3 = 0;
  v5 = a2;
  v6 = a2;
  if ( *a2 )
  {
    while ( 1 )
    {
      v7 = sub_1800017EC(a1, v5, &v10);
      if ( !v7 )
        return 106;
      if ( v7 == 1 )
      {
        *a3 = v3;
      }
      else
      {
        a1 = 3LL * v7;
        v8 = *(&off_18001B8C8 + 3 * v7);
        LOBYTE(a1) = *v8;
        *v6 = *v8;
        v6[1] = v8[1];
        v6 += 2;
        if ( (_BYTE)a1 == 103 )
        {
          *(v6 - 2) = 118;
        }
        else if ( (_BYTE)a1 == 71 )
        {
          *(v6 - 2) = 86;
        }
      }
      ++v3;
      v5 += (int)v10;
      if ( !*v5 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    *v6 = 0;
    return 0;
  }
}