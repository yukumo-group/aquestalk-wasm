__int64 __fastcall sub_1800055DC(__int64 a1, char *a2, int a3, int a4, _BYTE *a5, _BYTE *a6, _BYTE *a7, int a8, int a9)
{
  int v9; // r10d
  _BYTE *v10; // rcx
  int v11; // eax
  _BYTE *v12; // rcx
  int v13; // edx
  __int64 v15; // r11
  int v16; // r8d
  int v17; // edx
  _BYTE *v18; // rcx
  int v19; // eax
  _BYTE *v20; // rcx
  int v21; // edx
  _BYTE *v22; // rcx
  int v23; // edx
  _BYTE *v24; // rcx
  int v25; // eax
  _BYTE *v26; // rcx
  int v27; // edx

  v9 = 0;
  if ( !a8 )
  {
    if ( a9 )
    {
      v10 = a5;
      v11 = 0;
      while ( *v10 )
      {
        ++v10;
        ++v11;
      }
      v12 = a6;
      if ( a6 )
      {
        v13 = 0;
        while ( *v12 )
        {
          ++v12;
          ++v13;
        }
        v11 += v13;
      }
      return (unsigned int)(a9 + v11 / 2);
    }
    return 0;
  }
  v15 = a2[3 - a3];
  if ( a4 >= 10 )
  {
    if ( a4 > 11 )
    {
      v16 = 12;
      if ( a4 != 12 )
      {
        if ( (a2[2] != 49 || a2[3] == 48)
          && ((unsigned __int8)(a2[2] - 48) <= 1u || a2[3] != 48)
          && (*a2 <= 48 || a2[1] != 48 || a2[2] != 48 || a2[3] != 48) )
        {
          return 0;
        }
        v24 = a5;
        v25 = 0;
        while ( *v24 )
        {
          ++v24;
          ++v25;
        }
        v26 = a6;
        if ( a6 )
        {
          v27 = 0;
          while ( *v26 )
          {
            ++v26;
            ++v27;
          }
          v25 += v27;
        }
        return (unsigned int)(v25 / 2 - 1);
      }
      if ( (_BYTE)v15 != 49 )
        return 0;
    }
    else
    {
      v16 = ((_BYTE)v15 != 49) + 10;
    }
  }
  else
  {
    v16 = a4;
  }
  v17 = byte_18002EAF0[13 * a8 + v16];
  if ( v17 == -1 )
  {
    v18 = a5;
    v19 = 0;
    while ( *v18 )
    {
      ++v18;
      ++v19;
    }
    v20 = a6;
    if ( a6 )
    {
      v21 = 0;
      while ( *v20 )
      {
        ++v20;
        ++v21;
      }
      v19 += v21;
    }
    v22 = a7;
    if ( a7 )
    {
      v23 = 0;
      while ( *v22 )
      {
        ++v22;
        ++v23;
      }
      v19 += v23;
    }
    return (unsigned int)(v19 / 2);
  }
  else
  {
    if ( !byte_18002EAF0[13 * a8 + v16] )
      return 0;
    if ( (unsigned int)(a4 - 10) <= 2 && (_BYTE)v15 != 49 )
      v9 = dword_18002DF88[v15];
    return (unsigned int)(v9 + v17);
  }
}