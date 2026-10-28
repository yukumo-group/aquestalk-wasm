char *__fastcall sub_180001C38(_BYTE *a1)
{
  _BYTE *v1; // rdx
  int v2; // r8d

  v1 = &unk_18002AAA0;
  v2 = 0;
  while ( *v1 != *a1 || v1[1] != a1[1] )
  {
    ++v2;
    v1 += 6;
    if ( (__int64)v1 >= (__int64)byte_18002AF86 )
      return 0;
  }
  return (char *)&unk_18002AAA0 + 6 * v2;
}