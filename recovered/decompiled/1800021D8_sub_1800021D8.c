__int64 __fastcall sub_1800021D8(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // rcx
  int v4; // r10d
  char v5; // r9
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v9; // rax
  __int64 v10; // rdx
  int v11; // r9d

  if ( a2 == 2 )
    return 0;
  v3 = *(int *)(a1 + 20);
  v4 = *(_DWORD *)(a1 + 16);
  if ( (_DWORD)v3 != v4 )
    goto LABEL_7;
  if ( (unsigned __int8)(a2 - 2) > 7u )
  {
    v5 = *(_BYTE *)(a1 + 2);
    *(_DWORD *)(a1 + 16) = v4 + 8;
    if ( v4 + 8 > 26624 )
      return 200;
    v6 = *(_QWORD *)(a1 + 8) + v3;
    *(_BYTE *)v6 = -85;
    *(_DWORD *)(v6 + 2) = 0;
    *(_BYTE *)(v6 + 1) = (16 * v5) | 8;
    *(_WORD *)(v6 + 6) = 1024;
    LODWORD(v3) = *(_DWORD *)(a1 + 20);
LABEL_7:
    v7 = *(_QWORD *)(a1 + 8) + (int)v3;
    if ( a2 <= 9u )
    {
      if ( a2 == 1 )
      {
        *(_WORD *)(v7 + 4) = *(_WORD *)(v7 + 2);
      }
      else
      {
        *(_BYTE *)(v7 + 1) &= 0xF0u;
        *(_BYTE *)(v7 + 1) |= a2;
        v9 = *(_QWORD *)(a1 + 8);
        *(_BYTE *)(a1 + 2) = a2;
        v10 = *(int *)(a1 + 20);
        v11 = *(unsigned __int16 *)(v10 + v9 + 2);
        if ( (_WORD)v11 )
        {
          *(_DWORD *)(a1 + 24) = 0;
          *(_DWORD *)(a1 + 20) = v10 + 8 + 4 * v11;
        }
        else
        {
          *(_DWORD *)(a1 + 16) = v10;
        }
      }
      return 0;
    }
    *(_DWORD *)(a1 + 16) += 4;
    if ( *(int *)(a1 + 16) <= 26624 )
    {
      *(_BYTE *)(v7 + 4LL * *(unsigned __int16 *)(v7 + 2) + 10) = a2;
      *(_WORD *)(v7 + 4LL * (unsigned __int16)(*(_WORD *)(v7 + 2))++ + 8) = 0;
      return 0;
    }
    return 200;
  }
  *(_BYTE *)(a1 + 2) = a2;
  return 0;
}