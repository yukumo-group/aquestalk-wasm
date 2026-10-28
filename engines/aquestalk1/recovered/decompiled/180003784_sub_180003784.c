char __fastcall sub_180003784(__int64 a1, int a2)
{
  __int64 v2; // rcx
  __int64 v4; // rcx

  if ( (unsigned __int8)(a2 - 66) <= 0x32u )
  {
    v2 = 0x4422700044625LL;
    if ( _bittest64(&v2, (unsigned int)(a2 - 66)) )
      return 107;
  }
  if ( (unsigned __int8)(a2 - 72) <= 0x2Bu )
  {
    v4 = 0x80140000801LL;
    if ( _bittest64(&v4, (unsigned int)(a2 - 72)) )
      return 115;
  }
  if ( (((_BYTE)a2 - 77) & 0xDE) == 0 )
    return 110;
  if ( (((_BYTE)a2 - 82) & 0xDF) == 0 )
    return 114;
  if ( (((_BYTE)a2 - 106) & 0xEF) == 0 )
    return 122;
  if ( (((_BYTE)a2 - 86) & 0xDF) != 0 )
    return (((_BYTE)a2 - 119) & 0xFD) == 0 ? 0x79 : 0;
  return 118;
}