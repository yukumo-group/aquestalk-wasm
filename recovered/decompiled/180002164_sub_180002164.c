__int64 __fastcall sub_180002164(__int64 a1, char *a2, unsigned __int16 a3)
{
  unsigned int v4; // r10d
  __int64 result; // rax
  int v6; // r8d
  char *v7; // rbx
  __int64 v8; // r11
  __int16 v9; // cx
  char v11; // al

  v4 = a3;
  if ( *(_DWORD *)(a1 + 12) <= *(_DWORD *)(a1 + 8) )
    return 0xFFFFFFFFLL;
  v6 = 2;
  v7 = (char *)(*(_QWORD *)a1 + 4LL * *(int *)(a1 + 8));
  v8 = v7 - a2;
  v9 = 0;
  do
  {
    if ( !v6-- )
      break;
    v11 = *a2;
    a2[v8 + 2] = *a2;
    ++a2;
  }
  while ( v11 );
  if ( (_WORD)v4 )
    v9 = 0x3E8000 / v4;
  *(_WORD *)v7 = v9;
  result = *(unsigned int *)(a1 + 8);
  *(_DWORD *)(a1 + 8) = result + 1;
  return result;
}