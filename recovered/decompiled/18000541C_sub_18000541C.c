__int64 __fastcall sub_18000541C(
        __int64 a1,
        char *a2,
        int a3,
        char *a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int *a7)
{
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v13; // ebx
  _DWORD *v14; // rdi
  __int64 v15; // rcx

  *a7 = 0;
  *a6 = 0;
  *a5 = 0;
  if ( a4 )
  {
    v9 = *a4 - 65;
    *a5 = v9;
    if ( v9 > 0x13 )
      return 106;
    v10 = a4[1] - 97;
    *a6 = v10;
    if ( v10 > 0xF )
      return 106;
    v11 = a4[2] - 65;
    *a7 = v11;
    if ( v11 > 0xF )
      return 106;
  }
  else
  {
    v13 = 0;
    v14 = &unk_18002E088;
    do
    {
      if ( a3 == *v14 && !(unsigned int)sub_180001348(a2, &aNexx[28 * v13]) )
        break;
      ++v13;
      v14 += 7;
    }
    while ( v13 < 0x1B );
    if ( v13 < 0x1B )
    {
      v15 = 28LL * v13;
      *a5 = *(_DWORD *)&aNexx[v15 + 12];
      *a6 = *(_DWORD *)&aNexx[v15 + 16];
      *a7 = *(_DWORD *)&aNexx[v15 + 20];
    }
  }
  return 0;
}