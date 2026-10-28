__int64 __fastcall sub_180001274(_BYTE *a1)
{
  __int64 v1; // rdx
  int v3; // r9d
  int v4; // eax

  v1 = 0;
  v3 = 0;
  do
  {
    if ( !*a1 )
      break;
    if ( *a1 != 45 )
    {
      if ( (unsigned __int8)(*a1 - 48) > 9u )
      {
        if ( (unsigned __int8)(*a1 - 65) > 5u )
          v4 = 0;
        else
          v4 = (char)*a1 - 55;
      }
      else
      {
        v4 = (char)*a1 - 48;
      }
      v1 = v4 + 16 * v1;
      ++v3;
    }
    ++a1;
  }
  while ( v3 < 16 );
  return v1;
}