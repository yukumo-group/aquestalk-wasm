__int16 *__fastcall sub_180001B74(__int64 a1, __int16 *a2, int a3)
{
  int v3; // r9d
  __int16 v4; // ax
  __int64 v5; // rax

  v3 = a3;
  if ( a3 == -1 )
    v3 = *(unsigned __int8 *)(a1 + 3) - 1;
  switch ( *(_BYTE *)(a1 + 2) )
  {
    case 1:
      v5 = v3 + *(unsigned __int16 *)(a1 + 4);
      goto LABEL_14;
    case 2:
LABEL_12:
      v4 = word_18001E090[v3 + *(unsigned __int16 *)(a1 + 4)];
      goto LABEL_15;
    case 3:
      v5 = *(unsigned __int16 *)(a1 + 4);
LABEL_14:
      v4 = *((_WORD *)&unk_18001E3A0 + 11 * v5);
      goto LABEL_15;
    case 4:
    case 5:
    case 6:
    case 0xB:
      goto LABEL_12;
  }
  v4 = -12222;
LABEL_15:
  *a2 = v4;
  return a2;
}