__int64 __fastcall sub_1800052DC(__int64 *a1, _BYTE *a2, int a3, _DWORD *a4)
{
  _BYTE *v6; // r10
  int v8; // r8d
  _BYTE *v9; // rdx
  int v10; // ecx
  __int64 v11; // rbx
  int v12; // r9d
  __int64 v13; // rdx
  __int64 v14; // rdx

  v6 = a2;
  if ( !a2 || !*a2 )
    return 0;
  while ( 1 )
  {
    v8 = 204;
    while ( 2 )
    {
      v9 = *(&off_18001B8C8 + 3 * v8);
      v10 = 0;
      v11 = v6 - v9;
      while ( 1 )
      {
        v12 = (char)v9[v11] - (char)*v9;
        if ( v12 || !v9[v11] || !*v9 )
          break;
        ++v9;
        if ( ++v10 >= 2 )
          goto LABEL_9;
      }
      if ( v12 )
      {
        if ( --v8 >= 0 )
          continue;
        return 100;
      }
      break;
    }
LABEL_9:
    if ( !(_BYTE)v8 )
      return 100;
    if ( ++*a4 == a3 )
      break;
LABEL_20:
    v14 = *a1;
    if ( *(__int16 *)(*a1 + 8) >= 2047 )
      return 200;
    *(_BYTE *)(*(__int16 *)(v14 + 8) + *(_QWORD *)v14) = v8;
LABEL_22:
    ++*(_WORD *)(v14 + 8);
    v6 += 2;
    if ( !*v6 )
      return 0;
  }
  v13 = *a1;
  if ( (unsigned __int8)(v8 + 97) <= 2u )
  {
    if ( *(__int16 *)(v13 + 8) >= 2047 )
      return 200;
    *(_BYTE *)((__int16)(*(_WORD *)(v13 + 8))++ + *(_QWORD *)v13) = 1;
    goto LABEL_20;
  }
  if ( *(__int16 *)(v13 + 8) < 2047 )
  {
    *(_BYTE *)((__int16)(*(_WORD *)(v13 + 8))++ + *(_QWORD *)v13) = v8;
    v14 = *a1;
    if ( *(__int16 *)(*a1 + 8) < 2047 )
    {
      *(_BYTE *)(*(__int16 *)(v14 + 8) + *(_QWORD *)v14) = 1;
      goto LABEL_22;
    }
  }
  return 200;
}