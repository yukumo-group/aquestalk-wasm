__int64 __fastcall sub_180004704(__int64 *a1, _BYTE *a2, __int64 a3)
{
  __int64 result; // rax
  _BYTE *v6; // rbx
  char i; // al

  if ( !a2 )
    return 100;
  if ( !*a2 )
    return 0;
  *a1 = a3;
  v6 = a2;
  for ( i = *a2; *v6; i = *++v6 )
  {
    if ( i == 46 )
    {
      *v6 = 0;
      result = sub_1800049F8(a1);
      if ( (_DWORD)result )
        return result;
      result = sub_1800019F8(a3, byte_18002EF54);
      if ( (_DWORD)result )
        return result;
    }
    else if ( i == 45 )
    {
      *v6 = 0;
      result = sub_1800049F8(a1);
      if ( (_DWORD)result )
        return result;
      if ( *(__int16 *)(a3 + 8) >= 2047 )
        return 200;
      *(_BYTE *)((__int16)(*(_WORD *)(a3 + 8))++ + *(_QWORD *)a3) = 7;
    }
  }
  return sub_1800049F8(a1);
}