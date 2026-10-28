__int64 __fastcall sub_180002358(__int64 a1, __int16 a2, unsigned int a3)
{
  __int64 v4; // rdi
  void *v6; // rax
  unsigned __int64 v7; // r8
  unsigned int v8; // eax
  void *v9; // rax
  void *v10; // rsi
  __int64 v11; // rdx

  v4 = a3;
  if ( !*(_QWORD *)a1 )
  {
    *(_DWORD *)(a1 + 8) = 0x8000;
    v6 = j__malloc_base(0x8000u);
    *(_QWORD *)a1 = v6;
    if ( !v6 )
      return 101;
    *(_DWORD *)(a1 + 12) = 44;
  }
  v7 = *(unsigned int *)(a1 + 8);
  if ( (unsigned __int64)*(unsigned int *)(a1 + 12) + 2LL * (int)v4 >= v7 )
  {
    v8 = v7 + ((2 * (int)v4 / 0x8000 + 1) << 15);
    *(_DWORD *)(a1 + 8) = v8;
    v9 = j__malloc_base(v8);
    v10 = v9;
    if ( v9 )
    {
      memmove(v9, *(const void **)a1, *(unsigned int *)(a1 + 12));
      free(*(void **)a1);
      *(_QWORD *)a1 = v10;
      goto LABEL_7;
    }
    return 101;
  }
LABEL_7:
  if ( (int)v4 > 0 )
  {
    v11 = v4;
    do
    {
      *(_WORD *)(*(unsigned int *)(a1 + 12) + *(_QWORD *)a1) = a2;
      *(_DWORD *)(a1 + 12) += 2;
      --v11;
    }
    while ( v11 );
  }
  return 0;
}