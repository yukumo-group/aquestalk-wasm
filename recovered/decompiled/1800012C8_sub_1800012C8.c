unsigned __int64 __fastcall sub_1800012C8(__int64 a1)
{
  unsigned __int64 v1; // rdx
  unsigned __int16 i; // r10
  char v3; // r8
  __int64 j; // rcx
  char v5; // al

  v1 = a1 ^ 0xD271BA9DF61EED07uLL;
  for ( i = 0; i < 0x56Fu; ++i )
  {
    v3 = 0;
    for ( j = 0; j < 7; ++j )
    {
      if ( byte_18001B808[j] == v1 >> 61 )
        break;
      ++v3;
    }
    v5 = i;
    v1 = (8 * v1) | (v3 - v5 - 2) & 7;
  }
  return v1;
}