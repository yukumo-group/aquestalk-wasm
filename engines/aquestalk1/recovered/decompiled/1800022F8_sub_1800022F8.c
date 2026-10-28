char __fastcall sub_1800022F8(__int64 a1, unsigned __int64 a2)
{
  char result; // al

  for ( ; a2; a2 += 4LL * *(unsigned __int16 *)(a2 + 2) + 8 )
  {
    if ( *(_BYTE *)a2 != 0xAB || a2 < *(_QWORD *)(a1 + 8) || a2 >= *(_QWORD *)(a1 + 8) + *(int *)(a1 + 16) )
      break;
    result = *(_BYTE *)(a2 + 1) & 0xF;
    if ( result != 3 )
      return result;
  }
  return 8;
}