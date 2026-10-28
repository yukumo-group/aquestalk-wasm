__int64 __fastcall sub_180004660(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  int v5; // r11d
  __int64 v9; // r10
  char *v10; // rdi
  __int64 v11; // r9
  char v12; // dl
  char v13; // r8
  char v14; // al

  v5 = 0;
  if ( a5 <= 0 )
    return 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = *(char **)(a3 + 8 * v9);
    v11 = a2 - (_QWORD)v10;
    do
    {
      v12 = v10[v11];
      v13 = v12 + 32;
      if ( (unsigned __int8)(v12 - 65) > 0x19u )
        v13 = v10[v11];
      v14 = *v10 + 32;
      if ( (unsigned __int8)(*v10 - 65) > 0x19u )
        v14 = *v10;
      ++v10;
    }
    while ( v13 && v13 == v14 );
    if ( v13 == v14 )
      break;
    ++v5;
    if ( ++v9 >= a5 )
      return 0;
  }
  return *(_QWORD *)(a4 + 8LL * v5);
}