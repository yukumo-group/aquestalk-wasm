__int64 __fastcall Open_Talk_Synthe_Utf16(_WORD *a1, unsigned int a2, int *a3)
{
  __int64 v6; // rbp
  int v7; // eax
  _WORD *v8; // r9
  int v9; // esi
  int v10; // ebx
  size_t v11; // rcx
  _BYTE *v12; // rax
  _BYTE *v13; // r14
  int v14; // esi
  __int16 v15; // ax
  int v16; // r10d
  unsigned __int16 *v17; // rdx
  unsigned __int16 v18; // r9
  _BYTE *v19; // r8
  int v20; // eax
  unsigned int v21; // eax
  _WORD *v22; // rcx
  __int64 v23; // rdx
  char *v24; // r9

  v6 = 0;
  v7 = 0;
  if ( *a1 )
  {
    v8 = a1;
    do
    {
      ++v7;
      ++v8;
    }
    while ( *v8 );
    if ( v7 )
    {
      v9 = 2 * v7;
      v10 = -1;
      v11 = (unsigned int)(2 * v7 + 1);
      if ( 2 * v7 == -1 )
        v11 = -1;
      v12 = j__malloc_base(v11);
      v13 = v12;
      if ( !v12 )
      {
        v10 = 101;
LABEL_33:
        *a3 = v10;
        return v6;
      }
      v14 = v9 + 1;
      if ( *a1 && v14 > 1 )
      {
        *v12 = 0;
        v15 = *a1;
        v16 = 0;
        if ( *a1 == 0xFEFF )
          v15 = a1[1];
        v17 = a1 + 1;
        if ( *a1 != 0xFEFF )
          v17 = a1;
        if ( v15 )
        {
          v18 = *v17;
          v19 = v13;
          do
          {
            if ( v18 >= 0x80u )
            {
              v21 = 0;
              v22 = &unk_18002EF68;
              while ( v18 != *v22 )
              {
                ++v21;
                v22 += 5;
                if ( v21 >= 0xA2 )
                  goto LABEL_23;
              }
              v24 = (char *)&unk_18002EF60 + 10 * (int)v21;
              if ( !v24 )
              {
LABEL_23:
                v23 = v17 - a1;
                v10 = v23 + 1;
                if ( (_DWORD)v23 != -1 )
                  goto LABEL_32;
                goto LABEL_30;
              }
              if ( v16 + 3 > v14 )
                goto LABEL_32;
              *v19 = *v24;
              v19[1] = v24[1];
              v19 += 2;
              v20 = 2;
            }
            else
            {
              if ( v16 + 2 > v14 )
                goto LABEL_32;
              *v19++ = *(_BYTE *)v17;
              v20 = 1;
            }
            ++v17;
            *v19 = 0;
            v16 += v20;
            v18 = *v17;
          }
          while ( *v17 );
        }
        v10 = 0;
LABEL_30:
        v6 = sub_180005F54(v13, a2, a3);
      }
      else
      {
        v10 = -2;
      }
LABEL_32:
      free(v13);
      if ( v10 )
        goto LABEL_33;
    }
  }
  return v6;
}