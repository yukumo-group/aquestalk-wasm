_BYTE *__fastcall sub_180001380(_BYTE *a1, __int64 a2, _BYTE **a3)
{
  _BYTE *v3; // rdx
  char v6; // al
  int v7; // r9d
  _BYTE *v8; // r8
  const char *v9; // r11
  char v10; // r10
  _BYTE *v11; // rcx
  _BYTE *v12; // rax
  char v13; // r8
  const char *v14; // r10
  char v15; // r9

  v3 = 0;
  if ( !a1 )
  {
    a1 = *a3;
    if ( !*a3 )
      return 0;
  }
  v6 = *a1;
  v7 = 0;
  v8 = a1;
  while ( v6 )
  {
    v9 = " =>\t\n";
    v10 = 32;
    while ( v6 != v10 )
    {
      v10 = *++v9;
      if ( !*v9 )
        goto LABEL_11;
    }
    ++v7;
    v6 = *++v8;
  }
LABEL_11:
  v11 = &a1[v7];
  v12 = v11;
  v13 = *v11;
LABEL_16:
  if ( v13 )
  {
    v14 = " =>\t\n";
    v15 = 32;
    while ( v13 != v15 )
    {
      v15 = *++v14;
      if ( !*v14 )
      {
        v13 = *++v12;
        goto LABEL_16;
      }
    }
    if ( v12 )
    {
      *v12 = 0;
      v3 = v12 + 1;
    }
  }
  *a3 = v3;
  return v11;
}