__int64 __fastcall Open_Talk_Synthe(char *a1, unsigned int a2, _DWORD *a3)
{
  __int64 v3; // rbx
  char *v6; // rdi
  int v7; // eax
  size_t v8; // rcx
  _BYTE *v9; // rax
  void *v10; // rsi
  char v11; // cl
  __int64 v12; // rdi

  v3 = 0;
  v6 = a1;
  v7 = 0;
  if ( *a1 )
  {
    do
    {
      ++a1;
      ++v7;
    }
    while ( *a1 );
    if ( v7 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( v7 == -1 )
        v8 = -1;
      v9 = j__malloc_base(v8);
      v10 = v9;
      if ( v9 )
      {
        v11 = *v6;
        if ( *v6 )
        {
          v12 = v6 - v9;
          do
          {
            *v9++ = v11;
            v11 = v9[v12];
          }
          while ( v11 );
        }
        *v9 = 0;
        v3 = sub_180005F54(v10, a2, a3);
        free(v10);
      }
      else
      {
        *a3 = 101;
      }
    }
  }
  return v3;
}