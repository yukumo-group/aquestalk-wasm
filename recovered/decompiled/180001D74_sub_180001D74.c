__int64 __fastcall sub_180001D74(__int64 a1, unsigned __int16 a2, unsigned __int16 a3, unsigned __int16 a4)
{
  int v4; // r11d
  __int64 v5; // r9
  unsigned __int64 v7; // rcx
  __int16 *v8; // r10
  char *v9; // rdx
  int v10; // edi
  __int64 v11; // rbx
  __int64 v12; // r9
  _BYTE *v13; // r11
  __int64 v14; // kr00_8
  _BYTE v16[24]; // [rsp+20h] [rbp-28h] BYREF

  v4 = a4;
  v5 = a3;
  v7 = (unsigned __int64)&unk_18001E3A2;
  v8 = (__int16 *)((char *)&unk_18001E3A2 + 22 * a2);
  if ( (_WORD)v4 )
  {
    v10 = v4;
    v11 = 10;
    v12 = 22 * v5 - 22LL * a2;
    v13 = (_BYTE *)(v16 - (_BYTE *)v8);
    do
    {
      v7 = (unsigned int)*v8;
      v14 = v10 * (*(__int16 *)((char *)v8 + v12) - (int)v7);
      *(__int16 *)((char *)v8 + (_QWORD)v13) = *v8 + ((BYTE4(v14) + (int)v14) >> 8);
      ++v8;
      --v11;
    }
    while ( v11 );
    v9 = v16;
  }
  else
  {
    v9 = (char *)&unk_18001E3A2 + 22 * a2;
  }
  return sub_180001E20(v7, v9, a1 + 28);
}