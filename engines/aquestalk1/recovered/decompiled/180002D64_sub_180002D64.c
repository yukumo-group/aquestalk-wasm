_BYTE *__fastcall sub_180002D64(__int64 a1, _BYTE *a2, unsigned __int8 *a3, unsigned __int8 *a4, unsigned __int8 *a5)
{
  unsigned int v5; // r10d
  unsigned int v6; // eax

  LOBYTE(v5) = 0;
  if ( *a4 )
    v6 = *a5 * (unsigned int)*a3 / *a4;
  else
    LOBYTE(v6) = 0;
  *a2 = v6;
  if ( a4[1] )
    v5 = a5[1] * (unsigned int)a3[1] / a4[1];
  a2[1] = v5;
  return a2;
}