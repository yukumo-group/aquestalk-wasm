void __fastcall sub_180001A40(__int64 *a1, int a2)
{
  __int64 v2; // r8
  int v4; // ebx
  __int64 v5; // r9
  __int64 v6; // rcx
  int v7; // ebx
  int v8; // r11d
  __int64 v9; // rcx
  int v10; // ecx
  __int64 v11; // rax
  __int64 v12; // rdx
  unsigned int v13; // r11d
  __int64 v14; // rax

  v2 = *((__int16 *)a1 + 4);
  v4 = v2 - 1;
  if ( (int)v2 - 1 >= 0 )
  {
    v5 = *a1;
    v6 = v4;
    while ( (unsigned __int8)(*(_BYTE *)(v6 + v5) - 3) > 6u )
    {
      --v4;
      if ( --v6 < 0 )
        return;
    }
    v7 = v4 + 1;
    if ( v7 >= 0 )
    {
      v8 = v7 - 2;
      if ( v7 - 2 >= 0 && v8 < (int)v2 )
      {
        v9 = v8;
        while ( (unsigned __int8)(*(_BYTE *)(v9 + v5) - 3) > 6u )
        {
          --v8;
          if ( --v9 < 0 )
            goto LABEL_14;
        }
        if ( v8 + 1 < 0 )
          return;
LABEL_14:
        if ( a2 != 1 )
          goto LABEL_22;
        v10 = v7;
        if ( v7 >= (int)v2 )
          goto LABEL_21;
        v11 = v7;
        while ( *(_BYTE *)(v5 + v11) != 1 )
        {
          ++v10;
          if ( ++v11 >= v2 )
            goto LABEL_21;
        }
        if ( v10 < 0 )
        {
LABEL_21:
          v12 = (unsigned int)(v7 - 1);
        }
        else
        {
LABEL_22:
          sub_180001B2C(a1, (unsigned int)(v7 - 1));
          if ( (int)v13 >= v7 )
          {
LABEL_26:
            v13 = -1;
          }
          else
          {
            v14 = v13;
            while ( *(_BYTE *)(*a1 + v14) != 1 )
            {
              ++v13;
              if ( ++v14 >= v7 )
                goto LABEL_26;
            }
          }
          v12 = v13;
        }
        sub_180001B2C(a1, v12);
      }
    }
  }
}