__int64 __fastcall sub_180001C04(__int64 a1, int a2)
{
  __int16 v2; // r8

  v2 = a2;
  if ( a2 == -1 )
    v2 = *(unsigned __int8 *)(a1 + 3) - 1;
  if ( *(_BYTE *)(a1 + 2) == 1 )
    return (unsigned __int16)(*(_WORD *)(a1 + 4) + v2);
  if ( *(_BYTE *)(a1 + 2) == 3 )
    return *(unsigned __int16 *)(a1 + 4);
  return 0;
}