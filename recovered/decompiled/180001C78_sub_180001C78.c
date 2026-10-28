__int64 __fastcall sub_180001C78(__int64 a1, __int16 a2, __int16 a3, _WORD *a4, char a5, __int16 a6, __int16 a7)
{
  __int64 v8; // rcx
  __int64 v11; // rcx
  _WORD *v12; // rdx
  __int16 v13; // r8
  __int16 v14; // ax

  v8 = *(int *)(a1 + 20);
  if ( (int)v8 + 10 > 26624 )
    return 204;
  v11 = *(_QWORD *)(a1 + 8) + v8;
  v12 = (_WORD *)(a1 + 2);
  if ( *(_WORD *)a1 == a6 && *v12 == a7 )
  {
    *(_BYTE *)(v11 + 1) = a5;
    *(_BYTE *)v11 = 0;
    *(_WORD *)(v11 + 2) = *a4;
    *(_WORD *)(v11 + 4) = a2 | a3 & 0x3FFF;
    *(_DWORD *)(a1 + 20) += 6;
  }
  else
  {
    v13 = a2 | a3 & 0x3FFF;
    if ( *v12 == a6 )
    {
      *(_BYTE *)(v11 + 1) = a5;
      *(_BYTE *)v11 = 1;
      v14 = *a4;
      *(_WORD *)(v11 + 6) = a7;
    }
    else
    {
      if ( a6 != a7 )
      {
        *(_BYTE *)(v11 + 1) = a5;
        *(_BYTE *)v11 = 3;
        *(_WORD *)(v11 + 2) = *a4;
        *(_WORD *)(v11 + 4) = v13;
        *(_WORD *)(v11 + 6) = a6;
        *(_WORD *)(v11 + 8) = a7;
        *(_DWORD *)(a1 + 20) += 10;
        goto LABEL_12;
      }
      *(_WORD *)v11 = 2;
      v14 = *a4;
      *(_WORD *)(v11 + 6) = a6;
    }
    *(_WORD *)(v11 + 4) = v13;
    *(_WORD *)(v11 + 2) = v14;
    *(_DWORD *)(a1 + 20) += 8;
  }
LABEL_12:
  *(_WORD *)a1 = a6;
  *v12 = a7;
  return 0;
}