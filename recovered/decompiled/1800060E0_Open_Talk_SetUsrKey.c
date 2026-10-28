__int64 __fastcall Open_Talk_SetUsrKey(_BYTE *a1)
{
  unsigned int v1; // ebx
  __int64 v2; // rbp
  signed __int64 v3; // rax
  __int64 v4; // rdi
  unsigned int v5; // ecx
  signed __int64 v7; // [rsp+20h] [rbp-18h]

  v1 = 0;
  word_180034C1C = 0;
  qword_180034C10 = 0;
  v2 = sub_180001274(a1);
  v3 = sub_1800012C8(v2);
  v7 = v3;
  if ( ((_BYTE)v3 == 110 || (_BYTE)v3 == 0xFF)
    && BYTE1(v3) >= 0x14u
    && (v4 = v3 >> 48, BYTE6(v3) == 23)
    && ((_BYTE)v3 != 0xFF
     || (v5 = (unsigned __int16)(time64(0) / 86400), (int)v5 >= WORD1(v7) - 31) && v5 <= (unsigned int)WORD1(v7) + 396) )
  {
    if ( (_WORD)v4 == 1303 )
    {
      word_180034C1C = WORD2(v7);
      qword_180034C10 = v2;
    }
  }
  else
  {
    return 1;
  }
  return v1;
}