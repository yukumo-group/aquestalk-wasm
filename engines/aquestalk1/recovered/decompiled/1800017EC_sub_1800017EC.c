char __fastcall sub_1800017EC(__int64 a1, _BYTE *a2, _DWORD *a3)
{
  unsigned int v5; // ecx
  char **i; // r9
  char *v7; // rax
  int v8; // r8d
  char *v9; // rdx
  char v10; // bp
  int v11; // ebx
  char *v12; // r11
  __int64 v13; // rsi
  int v14; // edi
  int v15; // eax

  if ( !a2 || !*a2 )
    return 0;
  v5 = 328;
  for ( i = (char **)&off_18001E080; ; i -= 2 )
  {
    v7 = *i;
    v8 = 0;
    v9 = *i;
    v10 = **i;
    if ( v10 )
    {
      do
      {
        ++v7;
        ++v8;
      }
      while ( *v7 );
    }
    v11 = 0;
    v12 = *i;
    if ( v8 <= 0 )
      break;
    v13 = a2 - *i;
    while ( 1 )
    {
      v14 = v12[v13] - *v12;
      if ( v14 || !v12[v13] || !*v12 )
        break;
      ++v12;
      if ( ++v11 >= v8 )
        goto LABEL_12;
    }
    if ( !v14 )
      break;
    if ( (--v5 & 0x80000000) != 0 )
      return 0;
  }
LABEL_12:
  v15 = 0;
  if ( v10 )
  {
    do
    {
      ++v9;
      ++v15;
    }
    while ( *v9 );
  }
  *a3 = v15;
  return *((_BYTE *)&unk_18001CC08 + 16 * v5);
}