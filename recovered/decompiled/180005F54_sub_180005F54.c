// Hidden C++ exception states: #wind=1
_DWORD *__fastcall sub_180005F54(__int64 a1, int a2, _DWORD *a3)
{
  _DWORD *v6; // rbx
  _DWORD *result; // rax
  void *v8; // rsi
  int v9; // ecx
  int v10; // r14d
  int v11; // ecx
  unsigned __int64 v12; // rax
  __int128 v13; // [rsp+20h] [rbp-30h] BYREF
  _DWORD *v14; // [rsp+30h] [rbp-20h] BYREF
  int v15; // [rsp+38h] [rbp-18h]
  int v16; // [rsp+3Ch] [rbp-14h]

  v6 = 0;
  result = j__malloc_base(0x8000u);
  v8 = result;
  if ( result )
  {
    v14 = result;
    v13 = 0u;
    v9 = 50;
    if ( a2 >= 50 )
      v9 = a2;
    if ( v9 > 300 )
      v9 = 300;
    v15 = 25600 / v9;
    v16 = 256;
    v10 = sub_18000141C((__int64)&v14, a1, (__int64)&v13);
    if ( !v10 )
    {
      v11 = HIDWORD(v13);
      v12 = ((unsigned __int64)HIDWORD(v13) - 44) >> 1;
      v6 = (_DWORD *)v13;
      *(_DWORD *)v13 = 1179011410;
      v6[2] = 1163280727;
      v6[3] = 544501094;
      v6[9] = 1635017060;
      v6[4] = 16;
      v6[5] = 65537;
      v6[8] = 1048578;
      v6[6] = 8000;
      v6[7] = 16000;
      LODWORD(v12) = 2 * v12;
      v6[10] = v12;
      v6[1] = v12 + 36;
      *a3 = v11;
      v13 = 0u;
    }
    free(v8);
    if ( v10 )
      *a3 = v10;
    sub_180002330((__int64)&v13);
    return v6;
  }
  else
  {
    *a3 = 203;
  }
  return result;
}