__int16 __fastcall sub_180001E20(__int64 a1, __int64 a2, _WORD *a3)
{
  __int64 v5; // rcx
  __int64 v6; // r9
  __int64 i; // rcx
  _WORD *v8; // rdx
  _WORD *v9; // r8
  __int64 v10; // r11
  int v11; // ebx
  int v12; // r10d
  int v13; // ecx
  int v14; // r10d
  int v15; // eax
  _BYTE v17[24]; // [rsp+20h] [rbp-48h] BYREF
  _BYTE v18[24]; // [rsp+38h] [rbp-30h] BYREF

  sub_180001F00(a1, a2, v18);
  sub_180001F00(v5, a2 + 2, v17);
  v6 = 0;
  for ( i = 0; i > -20; i -= 4 )
  {
    *(_DWORD *)&v18[i + 20] += *(_DWORD *)&v18[i + 16];
    *(_DWORD *)&v17[i + 20] -= *(_DWORD *)&v17[i + 16];
  }
  v8 = a3 + 10;
  *a3 = 4096;
  v9 = a3 + 1;
  v10 = 5;
  do
  {
    v11 = *(_DWORD *)&v17[v6 + 4];
    v12 = *(_DWORD *)&v18[v6 + 4];
    v13 = (v12 + v11) >> 13;
    *v9 = v13;
    if ( (((_WORD)v12 + (_WORD)v11) & 0x1000) != 0 )
      *v9 = v13 + 1;
    v14 = v12 - v11;
    v15 = v14 >> 13;
    *v8 = v14 >> 13;
    if ( (v14 & 0x1000) != 0 )
    {
      LOWORD(v15) = v15 + 1;
      *v8 = v15;
    }
    v6 += 4;
    ++v9;
    --v8;
    --v10;
  }
  while ( v10 );
  return v15;
}