__int64 __fastcall sub_1800019F8(__int64 a1, char *a2)
{
  char v2; // r9
  __int16 v3; // ax

  v2 = *a2;
  if ( !*a2 )
    return 0;
  v3 = *(_WORD *)(a1 + 8);
  while ( v3 < 2047 )
  {
    ++a2;
    *(_BYTE *)(v3 + *(_QWORD *)a1) = v2;
    ++*(_WORD *)(a1 + 8);
    v2 = *a2;
    v3 = *(_WORD *)(a1 + 8);
    if ( !*a2 )
      return 0;
  }
  return 200;
}