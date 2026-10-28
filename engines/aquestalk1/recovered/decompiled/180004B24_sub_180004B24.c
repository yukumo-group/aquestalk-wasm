char *__fastcall sub_180004B24(__int64 *a1, int a2, char *a3, char a4, _DWORD *a5)
{
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // r11
  __int64 v11; // rdi
  __int64 v12; // rcx
  bool v13; // zf
  char *v14; // rdx
  int v15; // eax
  _DWORD *v16; // r11
  int v17; // eax
  int v19; // eax
  _DWORD *v20; // r11
  int v21; // eax
  _DWORD *v22; // r11
  int v23; // eax
  __int64 v24; // rax

  *a5 = 0;
  if ( !a2 )
    return a3;
  v8 = *a3 - 48;
  if ( a2 != 1 )
  {
    v11 = 2;
    v12 = *a1;
    v13 = a2 == 2;
    v14 = &byte_18002EEC8[3 * v8];
    if ( v13 )
    {
      v15 = sub_1800019F8(v12, v14);
      *v16 = v15;
      if ( !v15 )
      {
        v17 = sub_1800019F8(*a1, &byte_18002DFF8[4 * a3[1] - 192]);
        *v10 = v17;
        if ( !v17 )
          goto LABEL_13;
      }
    }
    else
    {
      v19 = sub_1800019F8(v12, v14);
      *v20 = v19;
      if ( !v19 )
      {
        v21 = sub_1800019F8(*a1, &byte_18002DFF8[4 * a3[1] - 192]);
        *v22 = v21;
        if ( !v21 )
        {
          v23 = sub_1800019F8(*a1, &byte_18002EEC8[3 * a3[2] - 144]);
          *v10 = v23;
          if ( !v23 )
          {
            v11 = 3;
            goto LABEL_13;
          }
        }
      }
    }
    return a3;
  }
  v9 = sub_1800019F8(*a1, (char *)(0x180000000LL + 4LL * v8 + 188448));
  *v10 = v9;
  if ( v9 )
    return a3;
  v11 = 1;
LABEL_13:
  if ( a4 )
  {
    v24 = *a1;
    if ( *(__int16 *)(*a1 + 8) < 2047 )
    {
      *(_BYTE *)((__int16)(*(_WORD *)(v24 + 8))++ + *(_QWORD *)v24) = a4;
      *v10 = 0;
    }
    else
    {
      *v10 = 200;
    }
  }
  return &a3[v11];
}