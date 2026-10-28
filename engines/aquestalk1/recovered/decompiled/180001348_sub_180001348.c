__int64 __fastcall sub_180001348(char *a1, char *a2)
{
  char v2; // r10
  int v3; // r9d
  unsigned int v4; // r8d
  __int64 v5; // r11

  v2 = *a1;
  v3 = *a2;
  v4 = *a1 - v3;
  if ( !v4 )
  {
    v5 = a1 - a2;
    do
    {
      if ( !v2 )
        break;
      if ( !(_BYTE)v3 )
        break;
      ++a2;
      v2 = a2[v5];
      v3 = *a2;
      v4 = v2 - v3;
    }
    while ( !v4 );
  }
  return v4;
}