__int64 __fastcall Open_Talk_Synthe_Utf8(_BYTE *a1, unsigned int a2, int *a3)
{
  __int64 v3; // rsi
  int v4; // ebx
  _BYTE *v8; // rax
  size_t v9; // rcx
  void *v10; // rax
  void *v11; // rdi
  int v12; // ebx

  v3 = 0;
  v4 = 0;
  v8 = a1;
  if ( *a1 )
  {
    do
    {
      ++v8;
      ++v4;
    }
    while ( *v8 );
    if ( v4 )
    {
      v9 = (unsigned int)(v4 + 1);
      if ( v4 == -1 )
        v9 = -1;
      v10 = j__malloc_base(v9);
      v11 = v10;
      if ( !v10 )
      {
        v12 = 101;
LABEL_11:
        *a3 = v12;
        return v3;
      }
      v12 = sub_1800061B8(a1, v10, (unsigned int)(v4 + 1));
      if ( !v12 )
        v3 = sub_180005F54(v11, a2, a3);
      free(v11);
      if ( v12 )
        goto LABEL_11;
    }
  }
  return v3;
}