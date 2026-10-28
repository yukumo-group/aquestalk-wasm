__int64 __fastcall sub_180001B2C(__int64 a1, int a2)
{
  int v2; // r8d
  __int16 v3; // r8
  __int64 result; // rax
  __int64 v5; // r8

  if ( a2 >= 0 )
  {
    v2 = *(__int16 *)(a1 + 8);
    if ( a2 < v2 )
    {
      v3 = v2 - 1;
      result = (unsigned int)v3;
      *(_WORD *)(a1 + 8) = v3;
      if ( a2 < (int)result )
      {
        v5 = a2;
        do
        {
          ++a2;
          *(_BYTE *)(*(_QWORD *)a1 + v5) = *(_BYTE *)(*(_QWORD *)a1 + v5 + 1);
          ++v5;
          result = (unsigned int)*(__int16 *)(a1 + 8);
        }
        while ( a2 < (int)result );
      }
    }
  }
  return result;
}