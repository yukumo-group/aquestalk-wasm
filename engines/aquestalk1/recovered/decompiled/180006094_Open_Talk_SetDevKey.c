__int64 __fastcall Open_Talk_SetDevKey(_BYTE *a1)
{
  unsigned int v1; // ebx
  __int64 v2; // rax
  unsigned __int64 v3; // rax

  v1 = 0;
  word_180034C18 = 0;
  v2 = sub_180001274(a1);
  v3 = sub_1800012C8(v2);
  if ( (_BYTE)v3 == 110 && BYTE1(v3) >= 0x14u && BYTE6(v3) == 86 )
    word_180034C18 = HIWORD(v3);
  else
    return 1;
  return v1;
}